#ifndef __MATQUATVEC_CPP__
    #define __MATQUATVEC_CPP__
#include <cmath>

#include"MatQuatVec.h "

////G////////////////////////////////////////
static inline void Minus(cfloat a[3], cfloat b[3],_Vector_ &f3R__)
    {f3R__.x = a[0] - b[0];f3R__.y= a[1] - b[1]; f3R__.z = a[2] - b[2]; } 
static inline void Puls(cfloat a[3], cfloat b[3],_Vector_& f3R__)
    { f3R__.x = a[0] + b[0];f3R__.y= a[1] + b[1]; f3R__.z = a[2] + b[2]; }
    
bool f44Invert_f44(cfloat f44[4][4],float f44__[4][4])
    {
	int i, j, k;
	double temp;
	float tempmat[4][4];
	float max;
	int maxj;
    
    //if(b是self==false)assert(f44__ != f44);

    f44_f44(f44,tempmat);
   
	/*Set f44__ to identity*/
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			f44__[i][j] = 0;
	for (i = 0; i < 4; ++i)
		f44__[i][i] = 1;

	for (i = 0; i < 4; ++i)
        {
		/*Look for row with max pivot*/
		max = fabsf(tempmat[i][i]);
		maxj = i;
		for (j = i + 1; j < 4; ++j)
            {
			if (fabsf(tempmat[j][i]) > max)
                {
				max = fabsf(tempmat[j][i]);
				maxj = j;
                }
            }
		/*Swap rows if necessary*/
		if (maxj != i)
            {
			for (k = 0; k < 4; k++)
                {
				Swap( tempmat[i][k], tempmat[maxj][k]);
				Swap( f44__[i][k], f44__[maxj][k]);
                }
            }

		if (tempmat[i][i] == 0.0f)
            {
			return false;  /*No non-o pivot*/
            }
		temp = (double)tempmat[i][i];
		for (k = 0; k < 4; k++)
            {
			tempmat[i][k] = (float)((double)tempmat[i][k] / temp);
			f44__[i][k] = (float)((double)f44__[i][k] / temp);
            }
		for (j = 0; j < 4; ++j)
            {
			if (j != i)
                {
				temp = tempmat[j][i];
				for (k = 0; k < 4; k++)
                    {
					tempmat[j][k] -= (float)((double)tempmat[i][k]*temp);
					f44__[j][k] -= (float)((double)f44__[i][k]*temp);
                    }
                }
            }
        }
	return true;
    }
    
static inline _Vector_ vgetf44Mulltiv(cfloat f44[4][4],const _Vector_& vec)//==m*v
    {
    _Vector_ v__;
	v__.x = f44[0][0]*vec.x + f44[1][0]*vec.y + f44[2][0]*vec.z + f44[3][0];
	v__.y = f44[0][1]*vec.x + f44[1][1]*vec.y + f44[2][1]*vec.z + f44[3][1];
	v__.z = f44[0][2]*vec.x + f44[1][2]*vec.y + f44[2][2]*vec.z + f44[3][2];//PRINT2("",vec[2] ,z);
    return v__;
    }   
    
////_Matrix_////////////////////////////////////////

_Matrix_:: _Matrix_(const _Matrix33_&f44From)
    {
    this->Xx=f44From.Xx;this->Xy=f44From.Xy;this->Xz=f44From.Xz;
    this->Yx=f44From.Yx;this->Yy=f44From.Yy;this->Yz=f44From.Yz;
    this->Zx=f44From.Zx ;this->Zy=f44From.Zy;this->Zz=f44From. Zz;
    }
        
_Matrix_:: _Matrix_(const _Vector_& vAsix,cfloat& angle)
    {
    float fXX = vAsix.x*vAsix.x;
    float fYY = vAsix.y*vAsix.y;
    float fZZ = vAsix.z*vAsix.z;
    float fXY = vAsix.x*vAsix.y;
    float fXZ = vAsix.x*vAsix.z;
    float fYZ = vAsix.y*vAsix.z;
    float angleSin = sin(angle);
    float f1一cos = 1 - cos(angle);
    this->Xx = 1 + f1一cos*(fXX - 1);
    this->Yx = -vAsix.z*angleSin + f1一cos*fXY;
    this->Zx = vAsix.y*angleSin + f1一cos*fXZ;
    this->Lx = 0;
    this->Xy = vAsix.z*angleSin + f1一cos*fXY;
    this->Yy = 1 + f1一cos*(fYY - 1);
    this->Zy = -vAsix.x*angleSin + f1一cos*fYZ;
    this->Ly = 0;
    this->Xz = -vAsix.y*angleSin + f1一cos*fXZ;
    this->Yz = vAsix.x*angleSin + f1一cos*fYZ;
    this->Zz = 1 + f1一cos*(fZZ - 1);
    this->Lz = 0;
    this->M03 = 0;
    this->M13 = 0;
    this->M23 = 0;
    this->M33 = 1;
    }
//-------------------------------------------------------------------------
void _Matrix_::Unit()//改变自身
    {
    this->Xx=1;this->Xy=0;this->Xz=0;this->M03=0;
    this->Yx=0;this->Yy=1;this->Yz=0;this->M13=0;
    this->Zx=0;this->Zy=0;this->Zz=1;this->M23=0;
    this->Lx=0;this->Ly=0;this->Lz=0;this->M33=1;
    }
/* bool _Matrix_::卩正(char*c名,int i行,const char*s文件=NULL)//改变自身
    {
    const _Vector_& X=this->X(),Y=this->Y(),Z=this->Z();
    if(X.dot(Y)>f00001 ||Y.dot(Z)>f00001 ||Z.dot(X)>f00001)
        {
        printf(" ★★ _Matrix_::卩正----c名:%s------------行:%d",c名,i行);
        if(s文件)printf("-------文件:%s",s卝('\\',s文件,false,false,true));
        printf(":X.dot(Y)=%f,Y.dot(Z)=%f,Z.dot(X)=%f \n",X.dot(Y),Y.dot(Z),Z.dot(X));
        ASSERT1R(c名,X.dot(Y)!=0,true);ASSERT1R(c名,Y.dot(Z)!=0,true);ASSERT1R(c名,Z.dot(X)!=0,true);
        }
    return false;
    } */
    
void  _Matrix_::Zero()//改变自身
    {
    this->Xx=0;this->Xy=0;this->Xz=0;this->M03=0;
    this->Yx=0;this->Yy=0;this->Yz=0;this->M13=0;
    this->Zx=0;this->Zy=0;this->Zz=0;this->M23=0;
    this->Lx=0;this->Ly=0;this->Lz=0;this->M33=0;
    //return *this;
    }
    
bool _Matrix_::isZero()const //改变自身
    {
    if(M33==0)return true;
    return false;
    }
    
_Matrix33_ _Matrix_::to33()const 
    {
    _Matrix33_ f33;
    f33.Xx=this->Xx;f33.Xy=this->Xy;f33.Xz=this->Xz;
    f33.Yx=this->Yx;f33.Yy=this->Yy;f33.Yz=this->Yz; 
    f33.Zx=this->Zx;f33.Zy=this->Zy;f33.Zz=this->Zz; 
    return f33;
    }
    
_Vector_ _Matrix_::X()const 
    {
    return _Vector_(Xx,Xy,Xz);
    }
    
void _Matrix_::getX(const _Vector_& X)
    {
    Xx=X.x;Xy=X.y;Xz=X.z;
    }
    
_Vector_ _Matrix_::Y()const 
    {
    return _Vector_(Yx,Yy,Yz);
    }    
    
void _Matrix_::getY(const _Vector_& Y)
    {
    Yx=Y.x;Yy=Y.y;Yz=Y.z;
    }
    
_Vector_ _Matrix_::Z()const 
    {
    return _Vector_(Zx,Zy,Zz);
    }  
    
void _Matrix_::getZ(const _Vector_& Z)
    {
    Zx=Z.x;Zy=Z.y;Zz=Z.z;
    }
    
void _Matrix_::getXYZ(const _Vector_& X,const _Vector_& Y,const _Vector_& Z)
    {
    this->Xx=X.x;this->Xy=X.y;this->Xz=X.z;
    this->Yx=Y.x;this->Yy=Y.y;this->Yz=Y.z;
    this->Zx=Z.x;this->Zy=Z.y;this->Zz=Z.z;
    }

_Vector_ _Matrix_::Loc()
    {
    return _Vector_(Lx,Ly,Lz);
    }  
_Vector_ _Matrix_::size()
    {
    _Vector_ vSize;float f3X[3]={Xx,Xy,Xz},f3Y[3]={Yx,Yy,Yz},f3Z[3]={Zx,Zy,Zz};
    vSize.x=len1(f3X);vSize.y=len1(f3Y);vSize.z=len1(f3Z);//PRINT3("", vSize.x,Xx,Xy);
    return vSize;
    }      
void _Matrix_::getLoc(const _Vector_& vLoc)//改变自身
    {
    Lx=vLoc.x;Ly=vLoc.y;Lz=vLoc.z;

    }  
void _Matrix_::getLoc(cfloat f3Loc[3])//改变自身
    {
    Lx=f3Loc[0];Ly=f3Loc[1];Lz=f3Loc[2];

    }  
    
_Matrix_ _Matrix_::scaled(const _Vector_& vSize)
    {
    float f3_[3];_Matrix_ mSize_;
    float fXLen=this->X().len(),fYLen=this->Y().len(),fZLen=this->Z().len();
    if(fXLen!=vSize.x)
        {
        (this->X()*(1.0f/ fXLen)).To(f3_);mSize_.Xx=f3_[0]*vSize.x;mSize_.Xy=f3_[1]*vSize.y;mSize_.Xz=f3_[2]*vSize.x;
        }
    if(fYLen!=vSize.y)
        {
        (this->Y()*(1.0f/ fXLen)).To(f3_);mSize_.Yx=f3_[0]*vSize.y;mSize_.Yy=f3_[1]*vSize.y;mSize_.Yz=f3_[2]*vSize.y;
        }     
    if(fZLen!=vSize.z)
        {
        (this->Z()*(1.0f/ fXLen)).To(f3_);mSize_.Zx=f3_[0]*vSize.z;mSize_.Zy=f3_[1]*vSize.z;mSize_.Zz=f3_[2]*vSize.z;
        }   
    
    return mSize_;
    }
    
void _Matrix_::getSize(const _Vector_& vSize)//改变自身
    {
    float f3_[3];
    float fXLen=this->X().len(),fYLen=this->Y().len(),fZLen=this->Z().len();
    if(fXLen!=vSize.x)
        {
        (this->X()*(1.0f/ fXLen)).To(f3_);Xx=f3_[0]*vSize.x;Xy=f3_[1]*vSize.y;Xz=f3_[2]*vSize.x;
        }
    if(fYLen!=vSize.y)
        {
        (this->Y()*(1.0f/ fXLen)).To(f3_);Yx=f3_[0]*vSize.y;Yy=f3_[1]*vSize.y;Yz=f3_[2]*vSize.y;
        }     
    if(fZLen!=vSize.z)
        {
        (this->Z()*(1.0f/ fXLen)).To(f3_);Zx=f3_[0]*vSize.z;Zy=f3_[1]*vSize.z;Zz=f3_[2]*vSize.z;
        }     
        
    }  
    
void _Matrix_::getSize(cfloat f3Size[3])//改变自身
    {
    float f3一倍大_[3];
    float fXLen=this->X().len(),fYLen=this->Y().len(),fZLen=this->Z().len();
    if(fXLen!=f3Size[0])
        {
        (this->X()*(1.0f/ fXLen)).To(f3一倍大_);Xx=f3一倍大_[0]*f3Size[0];Xy=f3一倍大_[1]*f3Size[1];Xz=f3一倍大_[2]*f3Size[0];
        }
    if(fYLen!=f3Size[1])
        {
        (this->Y()*(1.0f/ fXLen)).To(f3一倍大_);Yx=f3一倍大_[0]*f3Size[1];Yy=f3一倍大_[1]*f3Size[1];Yz=f3一倍大_[2]*f3Size[1];
   }     
    if(fZLen!=f3Size[2])
        {
        (this->Z()*(1.0f/ fXLen)).To(f3一倍大_);Zx=f3一倍大_[0]*f3Size[2];Zy=f3一倍大_[1]*f3Size[2];Zz=f3一倍大_[2]*f3Size[2];
   }  

    }  
    
void _Matrix_::getSize(cfloat&  fSize)//改变自身
    {
    float f3一倍大_[3];
    float fXLen=this->X().len(),fYLen=this->Y().len(),fZLen=this->Z().len();

    (this->X()*(1.0f/ fXLen)).To(f3一倍大_);Xx=f3一倍大_[0]*fSize;Xy=f3一倍大_[1]*fSize;Xz=f3一倍大_[2]*fSize;

    (this->Y()*(1.0f/ fXLen)).To(f3一倍大_);Yx=f3一倍大_[0]*fSize;Yy=f3一倍大_[1]*fSize;Yz=f3一倍大_[2]*fSize;

    (this->Z()*(1.0f/ fXLen)).To(f3一倍大_);Zx=f3一倍大_[0]*fSize;Zy=f3一倍大_[1]*fSize;Zz=f3一倍大_[2]*fSize;
    //float Size__[3];printf("fSize= %f\n",fSize);this->ToSize(Size__);printf("fSize 2= %f\n",Size__[0]);
    }  
    
void _Matrix_::getEuler(const _Vector_& vEuler)//改变自身
    {
	double ci, cj, S, si, sj, sh, cc, cs, sc, ss;

	ci = cos(vEuler.x);si = sin(vEuler.x);
	cj = cos(vEuler.y);sj = sin(vEuler.y);
	S = cos(vEuler.z);sh = sin(vEuler.z);

	cc = ci*S;
	cs = ci*sh;
	sc = si*S;
	ss = si*sh;

	Xx= (float)(cj*S);        Xy= (float)(cj*sh);        Xz= (float)-sj;
	Yx= (float)(sj*sc - cs);Yy= (float)(sj*ss + cc);Yz= (float)(cj*si);
	Zx= (float)(sj*cc + ss);Zy= (float)(sj*cs - sc);Zz= (float)(cj*ci);
    
    M33=1.0f;

    }
    
void _Matrix_::getEuler(cfloat euler[3])//改变自身
    {
	double ci, cj, S, si, sj, sh, cc, cs, sc, ss;

	ci = cos(euler[0]);si = sin(euler[0]);
	cj = cos(euler[1]);sj = sin(euler[1]);
	S = cos(euler[2]);sh = sin(euler[2]);

	cc = ci*S;
	cs = ci*sh;
	sc = si*S;
	ss = si*sh;

	Xx= (float)(cj*S);        Xy= (float)(cj*sh);        Xz= (float)-sj;
	Yx= (float)(sj*sc - cs);Yy= (float)(sj*ss + cc);Yz= (float)(cj*si);
	Zx= (float)(sj*cc + ss);Zy= (float)(sj*cs - sc);Zz= (float)(cj*ci);
    
    M33=1.0f;
    }

void _Matrix_::ToEuler(float euler__[3])const 
    {
    //assert(isf44otationMatrix(f44));
    float sy = pow2(Xx* Xx +  Xy* Xy);

    bool singular = sy < 1e-6; // If

    if (!singular)
        {
        euler__[0] = atan2(Yz,Zz);
        euler__[1] = atan2(-Xz, sy);
        euler__[2] = atan2(Xy, Xx );
        }
    else
        {
        euler__[0]= atan2(-Zy, Yy);
        euler__[1]= atan2(-Xz, sy);
        euler__[2]= 0;
        }
    }

void _Matrix_::ToLoc(float loc__[3])const 
    {
    loc__[0]=Lx;loc__[1]=Ly;loc__[2]=Lz;
    }

void _Matrix_::ToSize(float Size__[3])const 
    {
    float f3X[3]={Xx,Xy,Xz},f3Y[3]={Yx,Yy,Yz},f3Z[3]={Zx,Zy,Zz};
    Size__[0]=len1(f3X);Size__[1]=len1(f3Y);Size__[2]=len1(f3Z);
    }
    
//========================================
void _Matrix_::To(float f33__[][3])const 
    {
    f33__[0][0]=this->Xx;f33__[0][1]=this->Xy;f33__[0][2]=this->Xz;
    f33__[1][0]=this->Yx;f33__[1][1]=this->Yy;f33__[1][2]=this->Yz;
    f33__[2][0]=this->Zx;f33__[2][1]=this->Zy;f33__[2][2]=this->Zz;
    }    
    
void _Matrix_::To(float f44__[][4])const //这个不会改变自身
    {
   f44__[0][0]=this->Xx;f44__[0][1]=this->Xy;f44__[0][2]=this->Xz;f44__[0][3]=this->M03;
   f44__[1][0]=this->Yx;f44__[1][1]=this->Yy;f44__[1][2]=this->Yz;f44__[1][3]=this->M13;
   f44__[2][0]=this->Zx;f44__[2][1]=this->Zy;f44__[2][2]=this->Zz;f44__[2][3]=this->M23;
   f44__[3][0]=this->Lx;f44__[3][1]=this->Ly;f44__[3][2]=this->Lz;f44__[3][3]=this->M33;
    }
void _Matrix_::To(float f16__[16])const //这个不会改变自身
    {
   f16__[0]=this->Xx;f16__[1]=this->Xy;f16__[2]=this->Xz;f16__[3]=this->M03;
   f16__[4]=this->Yx;f16__[5]=this->Yy;f16__[6]=this->Yz;f16__[7]=this->M13;
   f16__[8]=this->Zx;f16__[9] =this->Zy;f16__[10]=this->Zz;f16__[11]=this->M23;
   f16__[12]=this->Lx;f16__[13]=this->Ly;f16__[14]=this->Lz;f16__[15]=this->M33;
    }
void _Matrix_::Tof44bl(float f44[][4])const 
    {
    f44[0][0]=this->Xx;f44[1][0]=this->Xy;f44[2][0]=this->Xz;f44[3][0]=this->M03;
    f44[0][1]=this->Yx;f44[1][1]=this->Yy;f44[2][1]=this->Yz;f44[3][1]=this->M13;
    f44[0][2]=this->Zx;f44[1][2]=this->Zy;f44[2][2]=this->Zz;f44[3][2]=this->M23;
    f44[0][3]=this->Lx;f44[1][3]=this->Ly;f44[2][3]=this->Lz;f44[3][3]=this->M33;
    }
    
    
float _Matrix_::fDeterminant()
    {
    float det1 = Zz*M33 - M23*Lz;
    float det2 = Zy*M33 - M23*Ly;
    float det3 = Zy*Lz - Zz*Ly;
    float det4 = Zx*M33 - M23*Lx;
    float det5 = Zx*Lz - Zz*Lx;
    float det6 = Zx*Ly - Zy*Lx;
    return
        (Xx*((Yy*det1 - Yz*det2) + M13*det3)) -
        (Xy*((Yx*det1 - Yz*det4) + M13*det5)) +
        (Xz*((Yx*det2 - Yy*det4) + M13*det6)) -
        (M03*((Yx*det3 - Yy*det5) + Yz*det6));
    }

//-------------------------------------------------------------------------
static _Matrix_ mZeroG(0.0f);
_Matrix_& _Matrix_::Invert()//改变自已
{//float f44[4][4],f44__[4][4];this->To(f44);f44Invert_f44(f44,f44__);*this=f44__;return *this;
//------------------------------
	int i, j, k;
	double dTemp;
	float f44Temp[4][4], f44Invert__[4][4];
	float fMax;
	int iMax;

	//assert(f44Invert__ != m原始);

	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			f44Invert__[i][j] = 0.0f;
	for (i = 0; i < 4; ++i)
		f44Invert__[i][i] = 1.0f;
      
    this->To(f44Temp);//不会改变自身
    
	for (i = 0; i < 4; ++i) 
        {
		fMax = fabsf(f44Temp[i][i]);
		iMax = i;
		for (j = i + 1; j < 4; ++j)
            {
			if (fabsf(f44Temp[j][i]) > fMax) 
                {
				fMax = fabsf(f44Temp[j][i]);
				iMax = j;
                }
            }

		if (iMax != i) 
            {
			for (k = 0; k < 4; k++)
                {
				Swap( f44Temp[i][k], f44Temp[iMax][k]);
				Swap( f44Invert__[i][k], f44Invert__[iMax][k]);
                }
            }

		if (f44Temp[i][i] == 0.0f) 
            {
			return mZeroG;  
            }
		dTemp = (double)f44Temp[i][i];
		for (k = 0; k < 4; k++) 
            {
			f44Temp[i][k] = (float)((double)f44Temp[i][k] / dTemp);
			f44Invert__[i][k] = (float)((double)f44Invert__[i][k] / dTemp);
            }
		for (j = 0; j < 4; ++j)
            {
			if (j != i) 
                {
				dTemp = f44Temp[j][i];
				for (k = 0; k < 4; k++)
                    {
					f44Temp[j][k] -= (float)((double)f44Temp[i][k]*dTemp);
					f44Invert__[j][k] -= (float)((double)f44Invert__[i][k]*dTemp);
                    }
                }
            }
        }
    //-------------------------------------------------------------------------
   *this=f44Invert__;return *this;
    //return true;
    }
//-------------------------------------------------------------------------
static _Matrix_ mInvertG;
_Matrix_ _Matrix_::_Invert() const //不改变自身//已在py验证正确
    {
    mInvertG=*this;mInvertG.Invert();//这样初始化数才不会出错
    return mInvertG;
    }    
    
void  _Matrix_::Normailze( )//改变自已
    {
    float f3_[3];
    float fXLen=this->X().len(),fYLen=this->Y().len(),fZLen=this->Z().len();
    if(fXLen!=1)
        {(this->X()*(1.0f/ fXLen)).To(f3_);Xx=f3_[0];Xy=f3_[1];Xz=f3_[2];}
    if(fYLen!=1)
        {(this->Y()*(1.0f/ fXLen)).To(f3_);Yx=f3_[0];Yy=f3_[1];Yz=f3_[2];}
    if(fZLen!=1)
        {(this->Z()*(1.0f/ fXLen)).To(f3_);Zx=f3_[0];Zy=f3_[1];Zz=f3_[2];}
    }      
const _Matrix_&  _Matrix_::Normalize_( )//改变自已
    {
    float f3_[3];
    float fXLen=this->X().len(),fYLen=this->Y().len(),fZLen=this->Z().len();
    if(fXLen!=1)
        {(this->X()*(1.0f/ fXLen)).To(f3_);Xx=f3_[0];Xy=f3_[1];Xz=f3_[2];}
    if(fYLen!=1)
        {(this->Y()*(1.0f/ fXLen)).To(f3_);Yx=f3_[0];Yy=f3_[1];Yz=f3_[2];}
    if(fZLen!=1)
        {(this->Z()*(1.0f/ fXLen)).To(f3_);Zx=f3_[0];Zy=f3_[1];Zz=f3_[2];}
    return *this;
    }    
_Matrix_ _Matrix_::_Normalize()const //不改变自身
    {
    float f3_[3];_Matrix_ m;
    float fXLen=this->X().len(),fYLen=this->Y().len(),fZLen=this->Z().len();
    if(fXLen!=1)
        {(this->X()*(1.0f/ fXLen)).To(f3_);m.Xx=f3_[0];m.Xy=f3_[1];m.Xz=f3_[2];}
    else
        {m.Xx=this->Xx;m.Xy=this->Xy;m.Xz=this->Xz;}
    if(fYLen!=1)
        {(this->Y()*(1.0f/ fXLen)).To(f3_);m.Yx=f3_[0];m.Yy=f3_[1];m.Yz=f3_[2];}
    else
        {m.Yx=this->Yx;m.Yy=this->Yy;m.Yz=this->Yz;}
    if(fZLen!=1)
        { (this->Z()*(1.0f/ fXLen)).To(f3_);m.Zx=f3_[0];m.Zy=f3_[1];m.Zz=f3_[2];}
    else
        {m.Zx=this->Zx;m.Zy=this->Zy;m.Zz=this->Zz;}
    return m;
    }
    
static _Matrix_ mPulsG,mMinusG,mMulltiG;

_Matrix_ _Matrix_::operator*(const _Matrix_ &M)const //m一为Coord旋转m二给m三  Scale跟随
    {  
    M4MulltiM4_M4(this->,M.,mMulltiG.);
    return mMulltiG;
    }
    

_Matrix_ _Matrix_::operator*(cfloat  M[4][4])const //m一为Coord旋转m二给m三  Scale跟随
    {  
    M4MulltiF44_M4(this->,M,mMulltiG.);
    return mMulltiG;
    }
    
//----friend--------------------------
_Matrix_ operator*(cfloat S[4][4],const _Matrix_&m) //m一为Coord旋转m二给m三  Scale跟随
    {  
    F44MulltiM4_M4(S,m.,mMulltiG.);
    return mMulltiG;
    }
    


const _Matrix_&  _Matrix_::operator*= (const _Matrix_ &M) //m一为Coord旋转m二给m三  Scale跟随
    {  
    M4MulltiM4_M4(this->,M.,float);
    this->Xx = Xx;         this->Yx = Yx;            this->Zx = Zx;            this->Lx = Lx;
    this->Xy = Xy;         this->Yy = Yy;            this->Zy = Zy;            this->Ly = Ly;
    this->Xz = Xz;         this->Yz = Yz;            this->Zz = Zz;            this->Lz = Lz;
    this->M03 = M03;this->M13 = M13;   this->M23 = M23;   this->M33 = M33;

    return*this;
    } 
//-------------------------------------------------------------------------
_Matrix33_ _Matrix_::operator*(const _Matrix33_ &M)const 
    {  
    _Matrix33_ f33__;
    M3MulltiM3_M3(this->,M.,f33__.);
    return f33__;
    }   
    
const _Matrix_&  _Matrix_::operator*= (const _Matrix33_ &M) 
    {  
    M3MulltiM3_M3(this->,M.,float);
    Xx=M.Xx;Xy=M.Xy;Xz=M.Xz;   Yx=M.Yx;Yy=M.Yy;Yz=M.Yz;   Zx=M.Zx;Zy=M.Zy;Zz=M.Zz;
    return*this;
    }      
//-------------------------------------------------------------------------
_Vector_  _Matrix_::operator*(const _Vector_& v)const 
    {
    _Vector_ v__;
    v__.x=this->Xx*v.x+this->Yx*v.y+this->Zx*v.z+this->Lx;
    v__.y=this->Xy*v.x+this->Yy*v.y+this->Zy*v.z+this->Ly;   
    v__.z=this->Xz*v.x+this->Yz*v.y+this->Zz*v.z+this->Lz;    
    
    return v__;
    }

//-------------------------------------------------------------------------
_Matrix_ _Matrix_::operator*(cfloat& fScale)const 
    {
    _Matrix_ M__;
    if(fScale!=1.0)
        {
        M__.Xx=this->Xx*fScale;M__.Yx=this->Yx*fScale;M__.Zx=this->Zx*fScale;
        M__.Xy=this->Xy*fScale;M__.Yy=this->Yy*fScale;M__.Zy=this->Zy*fScale;
        M__.Xz=this->Xz*fScale;M__.Yz=this->Yz*fScale;M__.Zz=this->Zz*fScale;
        }
    return M__;
    }
const _Matrix_ &_Matrix_::operator*= (cfloat& fScale) 
    {

    if(fScale!=1.0)
        {
        this->Xx*=fScale;this->Yx*=fScale;this->Zx*=fScale;
        this->Xy*=fScale;this->Yy*=fScale;this->Zy*=fScale;
        this->Xz*=fScale;this->Yz*=fScale;this->Zz*=fScale;
        }
    return*this;
    }    

_Matrix_ _Matrix_::operator/(const _Matrix_ &M)const //S 减 去 M 后的 矩阵
    {  
    // PRINT4("",M,M._Invert(),*this,_Invert()*(*this));
    return M._Invert()*(*this);
    }
    
//=============================================================
_Matrix_ _Matrix_::operator + (const _Vector_& vLoc)const //加位移
    {
    _Matrix_ m__;
    m__.Xx=this->Xx;m__.Xy=this->Xy;m__.Xz=this->Xz;m__.M03=this->M03;
    m__.Yx=this->Yx;m__.Yy=this->Yy;m__.Yz=this->Yz;m__.M13=this->M13;  
    m__.Zx=this->Zx;m__.Zy=this->Zy;m__.Zz=this-> Zz;m__.M23=this->M23;
    
    m__.Lx=this->Lx+vLoc.x;m__.Ly=this->Ly+vLoc.y;m__.Lz=this->Lz+vLoc.z;m__.M33=this->M33;
    
    return m__;
    }
//=============================================================
_Matrix_ _Matrix_::operator - (const _Vector_& vLoc)const //减位移
    {
    _Matrix_ m__;
    m__.Xx=this->Xx;m__.Xy=this->Xy;m__.Xz=this->Xz;m__.M03=this->M03;
    m__.Yx=this->Yx;m__.Yy=this->Yy;m__.Yz=this->Yz;m__.M13=this->M13;  
    m__.Zx=this->Zx;m__.Zy=this->Zy;m__.Zz=this-> Zz;m__.M23=this->M23;
    
    m__.Lx=this->Lx-vLoc.x;m__.Ly=this->Ly-vLoc.y;m__.Lz=this->Lz-vLoc.z;m__.M33=this->M33;
    
    return m__;
    }    
    
_Matrix_ _Matrix_::operator-(const _Matrix_ &M)const 
    {  
    _Matrix_ M3__;_Matrix_ MInv=M._Invert();
    M3MulltiM3_M3(this->,MInv.,M3__.);
    return M3__;
    }   
  
//=============================================================
bool _Matrix_::operator == (const  _Matrix_ &m)const //比较  
    {
    if(this->Xx==m.Xx && this->Xy==m.Xy && this->Xz==m.Xz && this->M03==m.M03 &&
        this->Yx==m.Yx && this->Yy==m.Yy && this->Yz==m.Yz &&this->M13==m.M13 &&
        this->Zx==m.Zx && this->Zy==m.Zy && this->Zz==m.Zz &&this->M23==m.M23 &&
        this->Lx==m.Lx && this->Ly==m.Ly && this->Lz==m.Lz &&this->M33==m.M33 
        ) return true;
    else
        return false;
    
    }
    
//=============================================================
bool _Matrix_::  operator != (const  _Matrix_ &m)const //比较  
    {
    if(this->Xx==m.Xx && this->Xy==m.Xy && this->Xz==m.Xz && this->M03==m.M03 &&
        this->Yx==m.Yx && this->Yy==m.Yy && this->Yz==m.Yz &&this->M13==m.M13 &&
        this->Zx==m.Zx && this->Zy==m.Zy && this->Zz==m.Zz &&this->M23==m.M23 &&
        this->Lx==m.Lx && this->Ly==m.Ly && this->Lz==m.Lz &&this->M33==m.M33 
        ) return false;
    else 
        return true;
    
    }    
    
const _Matrix_ & _Matrix_::  operator = (const  _Quaternion_ &q)
    { 
    float XX = 2*q.x*q.x;
    float YY = 2*q.y*q.y;
    float ZZ = 2*q.z*q.z;
    float XY = 2*q.x*q.y;
    float XZ = 2*q.x*q.z;
    float XW = 2*q.x*q.w;
    float YZ = 2*q.y*q.z;
    float YW = 2*q.y*q.w;
    float ZW = 2*q.z*q.w;
   this->Xx = 1 - YY - ZZ;
   this->Yx = XY - ZW;
   this->Zx = XZ + YW;
   this->Xy = XY + ZW;
   this->Yy = 1 - XX - ZZ;
   this->Zy = YZ - XW;
   this->Xz = XZ - YW;
   this->Yz = YZ + XW;
   this->Zz = 1 - XX - YY;
   return*this;
    }
    
//-------------------------------------------------------------------------－
const _Matrix_&   _Matrix_::  operator = (const   _Matrix_ &m)
    {
    if(this==&m) return*this;
    //this->Xx=f44.Xx;this->Xy=f44.Xy;this->Xz=f44.Xz;
    //this->Yx=f44.Yx;this->Yy=f44.Yy;this->Yz=f44.Yz;
    //this->Zx=f44.Zx;this->Zy=f44.Zy;this->Zz=f44.Zz;
    memcpy(this,&m,sizeof(_Matrix_));
    return*this;
    }

const _Matrix_&   _Matrix_::  operator = (const   _Matrix33_ &f33)
    {
    //this->Xx=f44.Xx;this->Xy=f44.Xy;this->Xz=f44.Xz;
    //this->Yx=f44.Yx;this->Yy=f44.Yy;this->Yz=f44.Yz;
    //this->Zx=f44.Zx;this->Zy=f44.Zy;this->Zz=f44.Zz;
    memcpy(this,&f33,sizeof(_Matrix33_));
    return*this;
    }    
    
const _Matrix_&  _Matrix_::operator = (cfloat f33[3][3])
    {
    this->Xx=f33[0][0];this->Xy=f33[0][1];this->Xz=f33[0][2];
    this->Yx=f33[1][0];this->Yy=f33[1][1];this->Yz=f33[1][2];  
    this->Zx=f33[2][0];this->Zy =f33[2][1];this->Zz=f33[2][2];    
    
    return*this;
    }

const _Matrix_&  _Matrix_::operator = (cfloat f44[4][4])
    {
    this->Xx=f44[0][0];this->Xy=f44[0][1];this->Xz=f44[0][2];this->M03=f44[0][3];
    this->Yx=f44[1][0];this->Yy=f44[1][1];this->Yz=f44[1][2];this->M13=f44[1][3];  
    this->Zx=f44[2][0];this->Zy =f44[2][1];this->Zz=f44[2][2];this->M23=f44[2][3];
                                                                                                                                                                                           
    this->Lx=f44[3][0];this->Ly =f44[3][1];this->Lz=f44[3][2];this-> M33=f44[3][3];
    return*this;
    }    
const _Matrix_&  _Matrix_::operator = (cfloat f16[16])
    {
    this->Xx=f16[0];this->Xy=f16[1];this->Xz=f16[2];this->M03=f16[3];
    this->Yx=f16[4];this->Yy=f16[5];this->Yz=f16[6];this->M13=f16[7];  
    this->Zx=f16[8];this->Zy =f16[9];this->Zz=f16[10];this->M23=f16[11];
                                                                                                                                                                                           
    this->Lx=f16[12];this->Ly =f16[13];this->Lz=f16[14];this-> M33=f16[15];
    return*this;
    }    
    
_Matrix_  _Matrix_ :: copy()
    {
    _Matrix_ m=_Matrix_();
    if(this==NULL) return*this;
    memcpy(&m,this,sizeof(_Matrix_));
    return m;
    }   
//----按旋Asix的Invert时针旋--------------------------
_Matrix_& _Matrix_::Rot_(_Vector_ &vAsix,cfloat& angleR \
                                                                                                     ,cbool& bNormAsix)
    {
    if(angleR==0)return *this;
    if(bNormAsix)vAsix.Normalize_();

    _Vector_ X=this->X(),Y=this->Y(),Z=this->Z();

    X.Rotate(vAsix,angleR,false);Y.Rotate(vAsix,angleR,false);Z.Rotate(vAsix,angleR,false);
    this->getXYZ(X,Y,Z);//PRINT1("",len1(X));
    return *this;
    }
    
void _Matrix_::Rotate(_Vector_ &vAsix,cfloat& angleR \
                                                                                                     ,cbool& bNormAsix)
    {
    if(angleR==0)return;
    if(bNormAsix)vAsix.Normalize_();

    _Vector_ X=this->X(),Y=this->Y(),Z=this->Z();

    X.Rotate(vAsix,angleR,false);Y.Rotate(vAsix,angleR,false);Z.Rotate(vAsix,angleR,false);
    this->getXYZ(X,Y,Z);//PRINT1("",len1(X));
    }

////_Matrix33_//////////////////////////////////
//-------------------------------------------------------------------------
void _Matrix33_::Unit()//改变自身
    {
    this->Xx=1;this->Xy=0;this->Xz=0;
    this->Yx=0;this->Yy=1;this->Yz=0;
    this->Zx=0;this->Zy=0;this->Zz=1;
    }
/* bool _Matrix33_::卩正(char*c名,int i行,const char*s文件=NULL)//改变自身
    {
    const _Vector_& X=this->X(),Y=this->Y(),Z=this->Z();
    if(X.dot(Y)>f00001 ||Y.dot(Z)>f00001 ||Z.dot(X)>f00001)
        {
        printf(" ★★ _Matrix_::卩正----c名:%s------------行:%d",c名,i行);
        if(s文件)printf("-------文件:%s",s卝('\\',s文件,false,false,true));
        printf(":X.dot(Y)=%f,Y.dot(Z)=%f,Z.dot(X)=%f\n",X.dot(Y),Y.dot(Z),Z.dot(X));
        ASSERT1R(c名,X.dot(Y)!=0,true);ASSERT1R(c名,Y.dot(Z)!=0,true);ASSERT1R(c名,Z.dot(X)!=0,true);
        }
    return false;
    } */
    
void  _Matrix33_::Zero()//改变自身
    {
    this->Xx=0;this->Xy=0;this->Xz=0;
    this->Yx=0;this->Yy=0;this->Yz=0;
    this->Zx=0;this->Zy=0;this->Zz=0;
    //return *this;
    }

bool _Matrix33_::isZero()const //改变自身
    {
    if(Xx==0&&Xy==0&&Xz==0)
        if(Yx==0&&Yy==0&&Yz==0)
            if(Zx==0&&Zy==0&&Zz==0)
                return true;
    return false;
    }
    
    
_Matrix33_  _Matrix33_ :: copy()
    {
    _Matrix33_ f33=_Matrix33_();
    if(this==NULL) return*this;
    memcpy(&f33,this,sizeof(_Matrix33_));
    return f33;
    }
_Matrix33_::_Matrix33_(const _Vector_& vAsix,cfloat& angle)
    {
    const _Vector_& vAsixNorm=vAsix._Normalize();
    
#define THETA_THRESHOLD_NEGY 1.0e-9f
#define THETA_THRESHOLD_NEGY_CLOSE 1.0e-5f

	float theta;
	_Matrix33_ f33r_, bMatrix;

	theta = 1.0f + vAsixNorm.y;

	if (theta > THETA_THRESHOLD_NEGY_CLOSE || ((vAsixNorm.x || vAsixNorm.z) && theta > THETA_THRESHOLD_NEGY)) {
		/*vAsixNorm is*not*-Y.
		*We got these values for free... so be happy with it... ;)
		*/
		bMatrix.Xy = -vAsixNorm.x;
		bMatrix.Yx = vAsixNorm.x;
		bMatrix.Yy = vAsixNorm.y;
		bMatrix.Yz = vAsixNorm.z;
		bMatrix.Zy = -vAsixNorm.z;
		if (theta > THETA_THRESHOLD_NEGY_CLOSE) 
            {
			/*If vAsixNorm is far enough from -Y, apply the general case.*/
			bMatrix.Xx = 1 - vAsixNorm.x*vAsixNorm.x / theta;
			bMatrix.Zz = 1 - vAsixNorm.z*vAsixNorm.z / theta;
			bMatrix.Zx = bMatrix.Xz = -vAsixNorm.x*vAsixNorm.z / theta;
		    }
		else
            {
			/*If vAsixNorm is too close To -Y, apply the special case.*/
			theta = vAsixNorm.x*vAsixNorm.x + vAsixNorm.z*vAsixNorm.z;
			bMatrix.Xx= (vAsixNorm.x + vAsixNorm.z)*(vAsixNorm.x - vAsixNorm.z) / -theta;
			bMatrix.Zz= -bMatrix.Xx;
			bMatrix.Zx= bMatrix.Xz = 2.0f*vAsixNorm.x*vAsixNorm.z / theta;
		    }
	    }
	else 
        {
		/*If vAsixNorm is -Y, simple symmetry by Z vAsixNorm.*/
		bMatrix.Unit();
		bMatrix.Xx = bMatrix.Yy = -1.0;
	    }
        
    //----Make Roll matrix----------------------------------------------
	float  ico;_Vector_ nsi;
	float n_00, n_01, n_11, n_02, n_12, n_22,angle_sin=sinf(angle),angle_cos=cosf(angle);

	// BLI_ASSERT_UNIT_V(vAsixNorm);

	//now convert this To a 3x3 matrix
	ico = (1.0f - angle_cos);
	nsi.x = vAsixNorm.x*angle_sin;
	nsi.y = vAsixNorm.y*angle_sin;
	nsi.z = vAsixNorm.z*angle_sin;

	n_00 = (vAsixNorm.x*vAsixNorm.x)*ico;
	n_01 = (vAsixNorm.x*vAsixNorm.y)*ico;
	n_11 = (vAsixNorm.y*vAsixNorm.y)*ico;
	n_02 = (vAsixNorm.x*vAsixNorm.z)*ico;
	n_12 = (vAsixNorm.y*vAsixNorm.z)*ico;
	n_22 = (vAsixNorm.z*vAsixNorm.z)*ico;

	f33r_.Xx= n_00 + angle_cos;
	f33r_.Xy = n_01 + nsi.z;
	f33r_.Xz= n_02 - nsi.y;
	f33r_.Yx = n_01 - nsi.z;
	f33r_.Yy = n_11 + angle_cos;
	f33r_.Yz = n_12 + nsi.x;
	f33r_.Zx = n_02 + nsi.y;
	f33r_.Zy = n_12 - nsi.x;
	f33r_.Zz = n_22 + angle_cos;

	/*Combine && output result_*/
    *this=f33r_*bMatrix;
    
#undef THETA_THRESHOLD_NEGY
#undef THETA_THRESHOLD_NEGY_CLOSE

    } 

//-------------------------------------------------------------------------
void _Matrix33_::Puls(_Matrix33_ &f33Coord, _Matrix33_ &vTwo, _Matrix33_ &result)//传递Scale给m三
    {
    float Xx = f33Coord.Xx + vTwo.Xx;
    float Xy = f33Coord.Xy + vTwo.Xy;
    float Xz = f33Coord.Xz + vTwo.Xz;
    
    float Yx = f33Coord.Yx + vTwo.Yx;
    float Yy = f33Coord.Yy + vTwo.Yy;
    float Yz = f33Coord.Yz + vTwo.Yz;
    
    float Zx = f33Coord.Zx + vTwo.Zx;
    float Zy = f33Coord.Zy + vTwo.Zy;
    float Zz = f33Coord.Zz + vTwo.Zz;
    
    result.Xx = Xx;
    result.Xy = Xy;
    result.Xz = Xz;

    result.Yx = Yx;
    result.Yy = Yy;
    result.Yz = Yz;

    result.Zx = Zx;
    result.Zy = Zy;
    result.Zz = Zz;
    }
void _Matrix33_::Puls(_Matrix_ &f33Coord, _Matrix33_ &vTwo, _Matrix33_ &result)//传递Scale给m三
    {
    float Xx = f33Coord.Xx + vTwo.Xx;
    float Xy = f33Coord.Xy + vTwo.Xy;
    float Xz = f33Coord.Xz + vTwo.Xz;
    
    float Yx = f33Coord.Yx + vTwo.Yx;
    float Yy = f33Coord.Yy + vTwo.Yy;
    float Yz = f33Coord.Yz + vTwo.Yz;
    
    float Zx = f33Coord.Zx + vTwo.Zx;
    float Zy = f33Coord.Zy + vTwo.Zy;
    float Zz = f33Coord.Zz + vTwo.Zz;
    
    result.Xx = Xx;
    result.Xy = Xy;
    result.Xz = Xz;

    result.Yx = Yx;
    result.Yy = Yy;
    result.Yz = Yz;

    result.Zx = Zx;
    result.Zy = Zy;
    result.Zz = Zz;
    }
void _Matrix33_::Puls(_Matrix33_ &f33Coord, _Matrix_ &vTwo, _Matrix33_ &result)//传递Scale给m三
    {
    float Xx= f33Coord.Xx + vTwo.Xx;
    float Xy= f33Coord.Xy + vTwo.Xy;
    float Xz= f33Coord.Xz + vTwo.Xz;
    
    float Yx= f33Coord.Yx + vTwo.Yx;
    float Yy= f33Coord.Yy + vTwo.Yy;
    float Yz= f33Coord.Yz + vTwo.Yz;
    
    float Zx= f33Coord.Zx + vTwo.Zx;
    float Zy= f33Coord.Zy + vTwo.Zy;
    float Zz= f33Coord.Zz + vTwo.Zz;
    
    result.Xx = Xx;
    result.Xy = Xy;
    result.Xz = Xz;

    result.Yx = Yx;
    result.Yy = Yy;
    result.Yz = Yz;

    result.Zx = Zx;
    result.Zy = Zy;
    result.Zz = Zz;
    }
void _Matrix33_::Puls(_Matrix_ &f33Coord, _Matrix_ &vTwo, _Matrix33_ &result)//传递Scale给m三
    {
    float Xx = f33Coord.Xx + vTwo.Xx;
    float Xy = f33Coord.Xy + vTwo.Xy;
    float Xz = f33Coord.Xz + vTwo.Xz;
    
    float Yx = f33Coord.Yx + vTwo.Yx;
    float Yy = f33Coord.Yy + vTwo.Yy;
    float Yz = f33Coord.Yz + vTwo.Yz;
    
    float Zx = f33Coord.Zx + vTwo.Zx;
    float Zy = f33Coord.Zy + vTwo.Zy;
    float Zz = f33Coord.Zz + vTwo.Zz;
    
    result.Xx = Xx;
    result.Xy = Xy;
    result.Xz = Xz;

    result.Yx = Yx;
    result.Yy = Yy;
    result.Yz = Yz;

    result.Zx = Zx;
    result.Zy = Zy;
    result.Zz = Zz;
    }


_Matrix33_ _Matrix33_::_Normalize()const //不改变自身
    {
    float f3_[3];_Matrix33_ m;
    float fXLen=this->X().len(),fYLen=this->Y().len(),fZLen=this->Z().len();
    if(fXLen!=1)
        {(this->X()*(1.0f/ fXLen)).To(f3_);m.Xx=f3_[0];m.Xy=f3_[1];m.Xz=f3_[2];}
    else
        {m.Xx=this->Xx;m.Xy=this->Xy;m.Xz=this->Xz;}
    if(fYLen!=1)
        {(this->Y()*(1.0f/ fXLen)).To(f3_);m.Yx=f3_[0];m.Yy=f3_[1];m.Yz=f3_[2];}
    else
        {m.Yx=this->Yx;m.Yy=this->Yy;m.Yz=this->Yz;}
    if(fZLen!=1)
        { (this->Z()*(1.0f/ fXLen)).To(f3_);m.Zx=f3_[0];m.Zy=f3_[1];m.Zz=f3_[2];}
    else
        {m.Zx=this->Zx;m.Zy=this->Zy;m.Zz=this->Zz;}
    return m;
    
    }
void  _Matrix33_::Normailze( )
    {
    float f3_[3];
    float fXLen=this->X().len(),fYLen=this->Y().len(),fZLen=this->Z().len();
    if(fXLen!=1)
        {(this->X()*(1.0f/ fXLen)).To(f3_);Xx=f3_[0];Xy=f3_[1];Xz=f3_[2];}
    if(fYLen!=1)
        {(this->Y()*(1.0f/ fXLen)).To(f3_);Yx=f3_[0];Yy=f3_[1];Yz=f3_[2];}
    if(fZLen!=1)
        {(this->Z()*(1.0f/ fXLen)).To(f3_);Zx=f3_[0];Zy=f3_[1];Zz=f3_[2];}
    }
const _Matrix33_&  _Matrix33_::Normalize_( )//改变自已
    {
    float f3_[3];
    float fXLen=this->X().len(),fYLen=this->Y().len(),fZLen=this->Z().len();
    if(fXLen!=1)
        {(this->X()*(1.0f/ fXLen)).To(f3_);Xx=f3_[0];Xy=f3_[1];Xz=f3_[2];}
    if(fYLen!=1)
        {(this->Y()*(1.0f/ fXLen)).To(f3_);Yx=f3_[0];Yy=f3_[1];Yz=f3_[2];}
    if(fZLen!=1)
        {(this->Z()*(1.0f/ fXLen)).To(f3_);Zx=f3_[0];Zy=f3_[1];Zz=f3_[2];}
    return *this;
    }
    
_Matrix33_& _Matrix33_::Invert()//与原物 旋转 Scale相反如2与0.5
    {//float f44[3][3],f44__[3][3];this->To(f44);f33Invert_f33(f44,f44__);*this=f44__;return *this;
//------------------------------
    float determinantInverse = 1 /  this->fDeterminant();
    
    float Xx = (this->Yy*this->Zz - this->Yz*this->Zy)*determinantInverse;
    float Xy = (this->Xz*this->Zy - this->Zz*this->Xy)*determinantInverse;
    float Xz = (this->Xy*this->Yz - this->Yy*this->Xz)*determinantInverse;
    
    float Yx = (this->Yz*this->Zx - this->Yx*this->Zz)*determinantInverse;
    float Yy = (this->Xx*this->Zz - this->Xz*this->Zx)*determinantInverse;
    float Yz = (this->Xz*this->Yx - this->Xx*this->Yz)*determinantInverse;
    
    float Zx = (this->Yx*this->Zy - this->Yy*this->Zx)*determinantInverse;
    float Zy = (this->Xy*this->Zx - this->Xx*this->Zy)*determinantInverse;
    float Zz = (this->Xx*this->Yy - this->Xy*this->Yx)*determinantInverse;

    this->Xx=Xx;this->Xy=Xy;this->Xz=Xz;
    this->Yx=Yx;this->Yy=Yy;this->Yz=Yz;
    this->Zx=Zx;this->Zy=Zy;this->Zz=Zz;   
    return *this;
    }    
    
static _Matrix33_ m3InvertG;
_Matrix33_ _Matrix33_::_Invert()//与原物 旋转 Scale相反如2与0.5
    {
    m3InvertG=*this;m3InvertG.Invert();//这样初始化数才不会出错
    return m3InvertG;
    }    
    

//-------------------------------------------------------------------------
void _Matrix33_::Mulltif33_f33(float f33M[3][3], float  f33__[3][3])//三跟一与二相同旋转  Scale跟随//相当于m二以m一为Coord的本地matrix
    {//必须要有替身,不过直接赋值__,因为__的一点变化可能直接改变m三与m二 并影响m三__
    float Xx = this->Xx*f33M[0][0] + this->Xy*f33M[1][0]+ this->Xz*f33M[2][0];
    float Xy = this->Xx*f33M[0][1] + this->Xy*f33M[1][1]+ this->Xz*f33M[2][1];
    float Xz = this->Xx*f33M[0][2] + this->Xy*f33M[1][2]+ this->Xz*f33M[2][2];
    
    float Yx = this->Yx*f33M[0][0]  + this->Yy*f33M[1][0]+ this->Yz*f33M[2][0];
    float Yy = this->Yx*f33M[0][1]  + this->Yy*f33M[1][1]+ this->Yz*f33M[2][1];
    float Yz = this->Yx*f33M[0][2]  + this->Yy*f33M[1][2]+ this->Yz*f33M[2][2];
    
    float Zx = this->Zx*f33M[0][0] + this->Zy*f33M[1][0] + this->Zz*f33M[2][0];
    float Zy = this->Zx*f33M[0][1] + this->Zy*f33M[1][1] + this->Zz*f33M[2][1];
    float Zz = this->Zx*f33M[0][2] + this->Zy*f33M[1][2] + this->Zz*f33M[2][2];
    
    f33__[0][0] = Xx; f33__[1][0]= Yx; f33__[2][0]= Zx;
    f33__[0][1] = Xy; f33__[1][1]= Yy; f33__[2][1]= Zy;
    f33__[0][2] = Xz; f33__[1][2]= Yz; f33__[2][2]= Zz;
    //printf("result加＝＝＝＝%f\n",f33__.Xx +f33__.Xy +f33__.Xz);
   

    }

//-------------------------------------------------------------------------
void _Matrix33_::Mulltif44_f33(float f44M[4][4], float  f33__[3][3])
    {
    float Xx= this->Xx*f44M[0][0]+ this->Xy*f44M[1][0]  + this->Xz*f44M[2][0];
    float Xy= this->Xx*f44M[0][1]+ this->Xy*f44M[1][1]  + this->Xz*f44M[2][1];
    float Xz= this->Xx*f44M[0][2]+ this->Xy*f44M[1][2]  + this->Xz*f44M[2][2];
    
    float Yx= this->Yx*f44M[0][0] + this->Yy*f44M[1][0] + this->Yz*f44M[2][0];
    float Yy= this->Yx*f44M[0][1] + this->Yy*f44M[1][1] + this->Yz*f44M[2][1];
    float Yz= this->Yx*f44M[0][2] + this->Yy*f44M[1][2] + this->Yz*f44M[2][2];
    
    float Zx= this->Zx*f44M[0][0]  + this->Zy*f44M[1][0]+ this->Zz*f44M[2][0];
    float Zy= this->Zx*f44M[0][1]  + this->Zy*f44M[1][1]+ this->Zz*f44M[2][1];
    float Zz= this->Zx*f44M[0][2]  + this->Zy*f44M[1][2]+ this->Zz*f44M[2][2];

    f33__[0][0] = Xx; f33__[1][0]= Yx; f33__[2][0]= Zx;
    f33__[0][1] = Xy; f33__[1][1]= Yy; f33__[2][1]= Zy;
    f33__[0][2] = Xz; f33__[1][2]= Yz; f33__[2][2]= Zz;

    }

    
//-------------------------------------------------------------------------
void _Matrix33_::f44Mullti二f33(float f44S[4][4],float  f33__[3][3])
    {
    float Xx = f44S[0][0]*this->Xx + f44S[0][1]*this->Yx + f44S[0][2]*this->Zx;
    float Xy = f44S[0][0]*this->Xy + f44S[0][1]*this->Yy + f44S[0][2]*this->Zy;
    float Xz = f44S[0][0]*this->Xz + f44S[0][1]*this->Yz + f44S[0][2]*this->Zz;
                                                                                                                         
    float Yx = f44S[1][0]*this->Xx + f44S[1][1]*this->Yx + f44S[1][2]*this->Zx;
    float Yy = f44S[1][0]*this->Xy + f44S[1][1]*this->Yy + f44S[1][2]*this->Zy;
    float Yz = f44S[1][0]*this->Xz + f44S[1][1]*this->Yz + f44S[1][2]*this->Zz;
                                                                                                                         
    float Zx = f44S [2][0]*this->Xx + f44S[2][1]*this->Yx + f44S[2][2]*this->Zx;
    float Zy = f44S [2][0]*this->Xy + f44S[2][1]*this->Yy + f44S[2][2]*this->Zy;
    float Zz = f44S [2][0]*this->Xz + f44S[2][1]*this->Yz + f44S[2][2]*this->Zz;

    f33__[0][0] = Xx; f33__[1][0]= Yx; f33__[2][0]= Zx;
    f33__[0][1] = Xy; f33__[1][1]= Yy; f33__[2][1]= Zy;
    f33__[0][2] = Xz; f33__[1][2]= Yz; f33__[2][2]= Zz;

    }
    
 
//-------------------------------------------------------------------------
void _Matrix33_::scale(float fScale,float  f33__[3][3])
    {
    f33__[0][0]= this->Xx*fScale;f33__[1][0] = this->Yx*fScale;f33__[2][0] = this->Zx*fScale;
    f33__[0][1]= this->Xy*fScale;f33__[1][1] = this->Yy*fScale;f33__[2][1] = this->Zy*fScale;
    f33__[0][2]= this->Xz*fScale;f33__[1][2] = this->Yz*fScale;f33__[2][2] = this->Zz*fScale;

    }

//----按旋Asix的Invert时针旋--------------------------
_Matrix33_& _Matrix33_::Rot_(_Vector_ &vAsix,cfloat& angleR \
                                                                                                     ,cbool& bNormAsix)
    {
    if(angleR==0)return *this;
    if(bNormAsix)vAsix.Normalize_();

    _Vector_ X=this->X(),Y=this->Y(),Z=this->Z();

    X.Rotate(vAsix,angleR,false);Y.Rotate(vAsix,angleR,false);Z.Rotate(vAsix,angleR,false);
    this->getXYZ(X,Y,Z);//PRINT1("",len1(X));
    return *this;
    }
    
void _Matrix33_::Rotate(_Vector_ &vAsix,cfloat& angleR \
                                                                                                     ,cbool& bNormAsix)
    {
    if(angleR==0)return;
    if(bNormAsix)vAsix.Normalize_();

    _Vector_ X=this->X(),Y=this->Y(),Z=this->Z();

    X.Rotate(vAsix,angleR,false);Y.Rotate(vAsix,angleR,false);Z.Rotate(vAsix,angleR,false);
    this->getXYZ(X,Y,Z);//PRINT1("",len1(X));
    }
    
void _Matrix33_::Rot_(_Matrix33_ &f33Coord, _Matrix_ &vTwo)
    {//f33一转m二
    vTwo.Xx = f33Coord.Xx;
    vTwo.Xy = f33Coord.Xy;
    vTwo.Xz = f33Coord.Xz;
    vTwo.Yx = f33Coord.Yx;
    vTwo.Yy = f33Coord.Yy;
    vTwo.Yz = f33Coord.Yz;
    vTwo.Zx = f33Coord.Zx;
    vTwo.Zy = f33Coord.Zy;
    vTwo.Zz = f33Coord.Zz;
    vTwo.M33 = 1;
    vTwo.M03 = 0;
    vTwo.M13 = 0;
    vTwo.M23 = 0;
    vTwo.Lx = 0;
    vTwo.Ly = 0;
    vTwo.Lz = 0;
    }
float  _Matrix33_::roll(float Asix_[3])
    {
    float ang转角__;
    if(Asix_)
        this->Y().To(Asix_);
    _Matrix33_ vecmat轴Invert(this->Y(),0.0f), rollmat;

    vecmat轴Invert.Invert();//PTm亖亖(vecmat轴Invert);
    rollmat=vecmat轴Invert*(*this);//PTm亖亖(*this);PTm亖亖(rollmat);
    ang转角__ = atan2f(rollmat.Zx, rollmat.Zz);
    return ang转角__;
    }
    
    
//==============================
const _Matrix33_&   _Matrix33_::operator = (cfloat f44From[4][4])
    {
    this->Xx=f44From[0][0];this->Xy=f44From[0][1];this->Xz=f44From[0][2];
    this->Yx=f44From[1][0];this->Yy=f44From[1][1];this->Yz=f44From[1][2];
    this->Zx=f44From[2][0];this->Zy= f44From[2][1];this->Zz=f44From[2][2];
    return*this;
    }

const _Matrix33_&   _Matrix33_::operator = (cfloat f44From[3][3])
{
this->Xx=f44From[0][0];this->Xy=f44From[0][1];this->Xz=f44From[0][2];
this->Yx=f44From[1][0];this->Yy=f44From[1][1];this->Yz=f44From[1][2];
this->Zx=f44From[2][0];this->Zy= f44From[2][1];this->Zz=f44From[2][2];
return*this;
}
  
_Matrix_ _Matrix33_::To4x4()
    {
    _Matrix_ m;
    m.Xx=this->Xx;m.Xy=this->Xy;m.Xz=this->Xz;
    m.Yx=this->Yx;m.Yy=this->Yy;m.Yz=this->Yz;
    m.Zx=this->Zx;m.Zy=this->Zy;m.Zz=this->Zz;  
    return m;    
    }
_Vector_ _Matrix33_::X()const 
    {
    return _Vector_(Xx,Xy,Xz);
    }
_Vector_ _Matrix33_::Y()const 
    {
    return _Vector_(Yx,Yy,Yz);
    }    
_Vector_ _Matrix33_::Z()const 
    {
    return _Vector_(Zx,Zy,Zz);
    }    
    
void _Matrix33_::getX(const _Vector_& X)
    {
    Xx=X.x;Xy=X.y;Xz=X.z;
    }
        
void _Matrix33_::getY(const _Vector_& Y)
    {
    Yx=Y.x;Yy=Y.y;Yz=Y.z;
    }
        
void _Matrix33_::getZ(const _Vector_& Z)
    {
    Zx=Z.x;Yy=Z.y;Zz=Z.z;
    }    
    
void _Matrix33_::getXYZ(const _Vector_& X,const _Vector_& Y,const _Vector_& Z)
    {
    this->Xx=X.x;this->Xy=X.y;this->Xz=X.z;
    this->Yx=Y.x;this->Yy=Y.y;this->Yz=Y.z;
    this->Zx=Z.x;this->Zy=Z.y;this->Zz=Z.z;
    }
_Vector_ _Matrix33_::size()
    {
    _Vector_ vSize;float f3X[3]={Xx,Xy,Xz},f3Y[3]={Yx,Yy,Yz},f3Z[3]={Zx,Zy,Zz};
    vSize.x=len1(f3X);vSize.y=len1(f3Y);vSize.z=len1(f3Z);
    return vSize;
    }   
    
void _Matrix33_::getEuler(const _Vector_& vEuler)//改变自身
    {
	double ci, cj, S, si, sj, sh, cc, cs, sc, ss;

	ci = cos(vEuler.x);si = sin(vEuler.x);
	cj = cos(vEuler.y);sj = sin(vEuler.y);
	S = cos(vEuler.z);sh = sin(vEuler.z);

	cc = ci*S;
	cs = ci*sh;
	sc = si*S;
	ss = si*sh;

	Xx= (float)(cj*S);        Xy= (float)(cj*sh);        Xz= (float)-sj;
	Yx= (float)(sj*sc - cs);Yy= (float)(sj*ss + cc);Yz= (float)(cj*si);
	Zx= (float)(sj*cc + ss);Zy= (float)(sj*cs - sc);Zz= (float)(cj*ci);
    
    }
    
void _Matrix33_::getEuler(cfloat euler[3])//改变自身
    {
	double ci, cj, S, si, sj, sh, cc, cs, sc, ss;

	ci = cos(euler[0]);si = sin(euler[0]);
	cj = cos(euler[1]);sj = sin(euler[1]);
	S = cos(euler[2]);sh = sin(euler[2]);

	cc = ci*S;
	cs = ci*sh;
	sc = si*S;
	ss = si*sh;

	Xx= (float)(cj*S);        Xy= (float)(cj*sh);        Xz= (float)-sj;
	Yx= (float)(sj*sc - cs);Yy= (float)(sj*ss + cc);Yz= (float)(cj*si);
	Zx= (float)(sj*cc + ss);Zy= (float)(sj*cs - sc);Zz= (float)(cj*ci);
    
    }
    
void _Matrix33_::ToEuler(float euler__[3])const 
    {
    //assert(isf44otationMatrix(f44));
    float sy = pow2(Xx* Xx +  Yx* Yx );

    bool singular = sy < 1e-6; // If

    if (!singular)
        {
        euler__[0] = atan2(Zy,Zz);
        euler__[1]  = atan2(-Zx, sy);
        euler__[2] = atan2(Yx, Xx );
        }
    else
        {
        euler__[0]= atan2(-Yz, Yy);
        euler__[1]= atan2(-Zx, sy);
        euler__[2]= 0;
        }

    }

_Matrix33_ _Matrix33_::scaled(const _Vector_& vSize)
    {
    float f3_[3];_Matrix33_ mSize_;
    float fXLen=this->X().len(),fYLen=this->Y().len(),fZLen=this->Z().len();
    if(fXLen!=vSize.x)
        {
        (this->X()*(1.0f/ fXLen)).To(f3_);mSize_.Xx=f3_[0]*vSize.x;mSize_.Xy=f3_[1]*vSize.y;mSize_.Xz=f3_[2]*vSize.x;
        }
    if(fYLen!=vSize.y)
        {
        (this->Y()*(1.0f/ fXLen)).To(f3_);mSize_.Yx=f3_[0]*vSize.y;mSize_.Yy=f3_[1]*vSize.y;mSize_.Yz=f3_[2]*vSize.y;
        }     
    if(fZLen!=vSize.z)
        {
        (this->Z()*(1.0f/ fXLen)).To(f3_);mSize_.Zx=f3_[0]*vSize.z;mSize_.Zy=f3_[1]*vSize.z;mSize_.Zz=f3_[2]*vSize.z;
        }   
    
    return mSize_;
    }    
    
void _Matrix33_::getSize(const _Vector_& vSize)//改变自身
    {
    float f3_[3];
    float fXLen=this->X().len(),fYLen=this->Y().len(),fZLen=this->Z().len();
    if(fXLen!=vSize.x)
        {
        (this->X()*(1.0f/ fXLen)).To(f3_);Xx=f3_[0]*vSize.x;Xy=f3_[1]*vSize.y;Xz=f3_[2]*vSize.x;
        }
    if(fYLen!=vSize.y)
        {
        (this->Y()*(1.0f/ fXLen)).To(f3_);Yx=f3_[0]*vSize.y;Yy=f3_[1]*vSize.y;Yz=f3_[2]*vSize.y;
        }     
    if(fZLen!=vSize.z)
        {
        (this->Z()*(1.0f/ fXLen)).To(f3_);Zx=f3_[0]*vSize.z;Zy=f3_[1]*vSize.z;Zz=f3_[2]*vSize.z;
        }     
        
    }  
    
void _Matrix33_::getSize(cfloat f3Size[3])//改变自身
    {
    float f3_[3];
    float fXLen=this->X().len(),fYLen=this->Y().len(),fZLen=this->Z().len();
    if(fXLen!=f3Size[0])
        {
        (this->X()*(1.0f/ fXLen)).To(f3_);Xx=f3_[0]*f3Size[0];Xy=f3_[1]*f3Size[1];Xz=f3_[2]*f3Size[0];
        }
    if(fYLen!=f3Size[1])
        {
        (this->Y()*(1.0f/ fXLen)).To(f3_);Yx=f3_[0]*f3Size[1];Yy=f3_[1]*f3Size[1];Yz=f3_[2]*f3Size[1];
   }     
    if(fZLen!=f3Size[2])
        {
        (this->Z()*(1.0f/ fXLen)).To(f3_);Zx=f3_[0]*f3Size[2];Zy=f3_[1]*f3Size[2];Zz=f3_[2]*f3Size[2];
   }  
    }  
    
void _Matrix33_::getSize(cfloat&  fSize)//改变自身
    {
    float f3一倍大_[3];
    float fXLen=this->X().len(),fYLen=this->Y().len(),fZLen=this->Z().len();
    (this->X()*(1.0f/ fXLen)).To(f3一倍大_);Xx=f3一倍大_[0]*fSize;Xy=f3一倍大_[1]*fSize;Xz=f3一倍大_[2]*fSize;

    (this->Y()*(1.0f/ fXLen)).To(f3一倍大_);Yx=f3一倍大_[0]*fSize;Yy=f3一倍大_[1]*fSize;Yz=f3一倍大_[2]*fSize;

    (this->Z()*(1.0f/ fXLen)).To(f3一倍大_);Zx=f3一倍大_[0]*fSize;Zy=f3一倍大_[1]*fSize;Zz=f3一倍大_[2]*fSize;
    
    }  

void _Matrix33_::ToSize(float Size__[3])const 
    {
    float f3X[3]={Xx,Xy,Xz},f3Y[3]={Yx,Yy,Yz},f3Z[3]={Zx,Zy,Zz};
    Size__[0]=len1(f3X);Size__[1]=len1(f3Y);Size__[2]=len1(f3Z);
    }

//========================================   
void _Matrix33_::To(float f33__[][3])const 
    {
    f33__[0][0]=this->Xx;f33__[0][1]=this->Xy;f33__[0][2]=this->Xz;
    f33__[1][0]=this->Yx;f33__[1][1]=this->Yy;f33__[1][2]=this->Yz;
    f33__[2][0]=this->Zx;f33__[2][1]=this->Zy;f33__[2][2]=this->Zz;
    }
    
void _Matrix33_::To(float f44__[][4])const 
    {
    f44__[0][0]=this->Xx;f44__[0][1]=this->Xy;f44__[0][2]=this->Xz;
    f44__[1][0]=this->Yx;f44__[1][1]=this->Yy;f44__[1][2]=this->Yz;
    f44__[2][0]=this->Zx;f44__[2][1]=this->Zy;f44__[2][2]=this->Zz;
    }    
    
//======================================================   
float _Matrix33_::fDeterminant()
    {
    return Xx*Yy*Zz + Xy*Yz*Zx + Xz*Yx*Zy -Zx*Yy*Xz - Zy*Yz*Xx - Zz*Yx*Xy;
    }
//-------------------------------------------------------------------------
float _Matrix33_::fAdaptiveDeterminant(int &iSubMatrixCode)
    {
    float fDeterminant = Xx*Yy*Zz + Xy*Yz*Zx + Xz*Yx*Zy -
        Zx*Yy*Xz - Zy*Yz*Xx - Zz*Yx*Xy;//==fDeterminant();
    
    if (fDeterminant != 0) 
        {
        iSubMatrixCode = 0;
        return fDeterminant;
        }
    fDeterminant = Xx*Yy - Xy*Yx;
    if (fDeterminant != 0)
        {
        iSubMatrixCode = 1;
        return fDeterminant;
        }
    fDeterminant = Yy*Zz - Yz*Zy;
    if (fDeterminant != 0)
        {
        iSubMatrixCode = 2;
        return fDeterminant;
        }
    fDeterminant = Xx*Zz - Xz*Xy;
    if (fDeterminant != 0)
        {
        iSubMatrixCode = 3;
        return fDeterminant;
        }
    if (Xx != 0)
        {
        iSubMatrixCode = 4;
        return Xx;
        }
    if (Yy != 0)
        {
        iSubMatrixCode = 5;
        return Yy;
        }
    if (Zz != 0)
        {
        iSubMatrixCode = 6;
        return Zz;
        }
    iSubMatrixCode = -1;
    return 0;
    }
//-------------------------------------------------------------------------

void _Matrix33_::CreateOuterProduct(_Vector_ &f33Coord, _Vector_ &vTwo, _Matrix33_ &f33__)
    {
    f33__.Xx = f33Coord.x*vTwo.x;
    f33__.Xy = f33Coord.x*vTwo.y;
    f33__.Xz = f33Coord.x*vTwo.z;
    f33__.Yx = f33Coord.y*vTwo.x;
    f33__.Yy = f33Coord.y*vTwo.y;
    f33__.Yz = f33Coord.y*vTwo.z;
    f33__.Zx = f33Coord.z*vTwo.x;
    f33__.Zy = f33Coord.z*vTwo.y;
    f33__.Zz = f33Coord.z*vTwo.z;
    }

//====================================================== 
void _Matrix33_::Tof44bl(float f44[][4])const//这是以bl内置矩阵吅
    {
    f44[0][0]=this->Xx;f44[1][0]=this->Xy;f44[2][0]=this->Xz;f44[3][0]=0;
    f44[0][1]=this->Yx;f44[1][1]=this->Yy;f44[2][1]=this->Yz;f44[3][1]=0;
    f44[0][2]=this->Zx;f44[1][2]=this->Zy;f44[2][2]=this->Zz;f44[3][2]=0;
    //f44[0][3]=0;f44[1][3]=0;f44[2][3]=0;                             f44[3][3]=1;
    
    }
//====operator===================================================
_Matrix33_ _Matrix33_:: operator + (const   _Matrix33_  &f33_)const 
        {
        _Matrix33_  result;
        float Xx = this->Xx + f33_.Xx;
        float Xy = this->Xy + f33_.Xy;
        float Xz = this->Xz + f33_.Xz;

        float Yx = this->Yx + f33_.Yx;
        float Yy = this->Yy + f33_.Yy;
        float Yz = this->Yz + f33_.Yz;
        
        float Zx = this->Zx + f33_.Zx;
        float Zy = this->Zy + f33_.Zy;
        float Zz = this->Zz + f33_.Zz;
        
        result.Xx=Xx;result.Xy=Xy;result.Xz=Xz;   
        result.Yx=Yx;result.Yy=Yy;result.Yz=Yz;
        result.Zx=Zx;result.Zy=Zy;result.Zz=Zz;
        return result;
        }
//-------------------------------------------------------------------------－
bool _Matrix33_::  operator == (const  _Matrix33_ &f33)const //比较  
    {
    if(this->Xx==f33.Xx && this->Xy==f33.Xy && this->Xz==f33.Xz &&
        this->Yx==f33.Yx && this->Yy==f33.Yy && this->Yz==f33.Yz &&
        this->Zx==f33.Zx && this->Zy==f33.Zy && this->Zz==f33.Zz 
        ) return true;
    else
        return false;
    
    }
    
bool _Matrix33_::  operator != (const  _Matrix33_ &f33)const //比较  
    {
    if(this->Xx==f33.Xx && this->Xy==f33.Xy && this->Xz==f33.Xz &&
        this->Yx==f33.Yx && this->Yy==f33.Yy && this->Yz==f33.Yz &&
        this->Zx==f33.Zx && this->Zy==f33.Zy && this->Zz==f33.Zz 
        ) return false;
    else
        return true;
    
    }    
    
const _Matrix33_ & _Matrix33_:: operator = (const  _Quaternion_ &q_)
    { 
    float XX = 2*q_.x*q_.x;
    float YY = 2*q_.y*q_.y;
    float ZZ = 2*q_.z*q_.z;
    float XY = 2*q_.x*q_.y;
    float XZ = 2*q_.x*q_.z;
    float XW = 2*q_.x*q_.w;
    float YZ = 2*q_.y*q_.z;
    float YW = 2*q_.y*q_.w;
    float ZW = 2*q_.z*q_.w;
   this->Xx = 1 - YY - ZZ;
   this->Yx = XY - ZW;
   this->Zx = XZ + YW;
   this->Xy = XY + ZW;
   this->Yy = 1 - XX - ZZ;
   this->Zy = YZ - XW;
   this->Xz = XZ - YW;
   this->Yz = YZ + XW;
   this->Zz = 1 - XX - YY;
   return*this;
    }
    
//-------------------------------------------------------------------------－
const _Matrix33_&   _Matrix33_::  operator = (const   _Matrix33_ &f33_)
    {
    if(this==&f33_) return*this;
    memcpy(this,&f33_,sizeof(_Matrix33_));
    return*this;
    }
const _Matrix33_&   _Matrix33_::  operator = (cfloat f16[16])
    {
    this->Xx=f16[0];this->Xy=f16[1];this->Xz=f16[2];
    this->Yx=f16[4];this->Yy=f16[5];this->Yz=f16[6];  
    this->Zx=f16[8];this->Zy =f16[9];this->Zz=f16[10];
    return*this;
    }    
//-------------------------------------------------------------------------
_Vector_ _Matrix33_::operator*(const _Vector_ &v)const 
    {
    _Vector_ v__;
    v__.x=this->Xx*v.x+this->Yx*v.y+this->Zx*v.z;
    v__.y=this->Xy*v.x+this->Yy*v.y+this->Zy*v.z;   
    v__.z=this->Xz*v.x+this->Yz*v.y+this->Zz*v.z;    
    
    return v__;
    } 

_Matrix33_ _Matrix33_ :: operator*(const   _Matrix33_ &f33Two)const //三跟一与二相同旋转  Scale跟随//相当于m二以m一为Coord的本地matrix
    {//必须要有替身,不过直接赋值__,因为__的一点变化可能直接改变m三与m二 并影响m三__
    _Matrix33_ f33__;M3MulltiM3_M3(this->,f33Two.,f33__.);

    return f33__;
    
    }

_Matrix33_ _Matrix33_ :: operator*(const   _Matrix_ &MM)const 
    {
    _Matrix33_ f33__;
    f33__.Xx= this->Xx*MM.Xx + this->Xy*MM.Yx + this->Xz*MM.Zx;
    f33__.Xy= this->Xx*MM.Xy + this->Xy*MM.Yy + this->Xz*MM.Zy;
    f33__.Xz= this->Xx*MM.Xz + this->Xy*MM.Yz + this->Xz*MM.Zz;

    f33__.Yx= this->Yx*MM.Xx + this->Yy*MM.Yx + this->Yz*MM.Zx;
    f33__.Yy= this->Yx*MM.Xy + this->Yy*MM.Yy + this->Yz*MM.Zy;
    f33__.Yz= this->Yx*MM.Xz + this->Yy*MM.Yz + this->Yz*MM.Zz;

    f33__.Zx= this->Zx*MM.Xx + this->Zy*MM.Yx + this->Zz*MM.Zx;
    f33__.Zy= this->Zx*MM.Xy + this->Zy*MM.Yy + this->Zz*MM.Zy;
    f33__.Zz= this->Zx*MM.Xz + this->Zy*MM.Yz + this->Zz*MM.Zz;

    return f33__;
    
    }
  
_Matrix33_ _Matrix33_::operator*(cfloat& fScale)const 
    {
    _Matrix33_ f33__;
    f33__.Xx = this->Xx*fScale;
    f33__.Xy = this->Xy*fScale;
    f33__.Xz = this->Xz*fScale;
    f33__.Yx = this->Yx*fScale;
    f33__.Yy = this->Yy*fScale;
    f33__.Yz = this->Yz*fScale;
    f33__.Zx = this->Zx*fScale;
    f33__.Zy = this->Zy*fScale;
    f33__.Zz = this->Zz*fScale;
    return f33__;
    }    
    

////_Quaternion_///////////////////////////////////////
void _Quaternion_::To(float f4__[4])const
    {
    f4__[1]=this->x ;f4__[2]=this->y; f4__[3]=this->z;f4__[0]=this->w;
    }
void _Quaternion_::To(double f4__[4])const
    {
    f4__[1]=this->x ;f4__[2]=this->y; f4__[3]=this->z;f4__[0]=this->w;
    }
void _Quaternion_::Puls(_Quaternion_ &v一, _Quaternion_ &vTwo, _Quaternion_ &result)//线性插值 __等于两个相加的中间旋转角度
    {
    result.x = v一.x + vTwo.x;
    result.y = v一.y + vTwo.y;
    result.z = v一.z + vTwo.z;
    result.w = v一.w + vTwo.w;
    }

//-------------------------------------------------------------------------
void _Quaternion_::fSize(_Quaternion_ &q, float fScale, _Quaternion_ &result)
    {
    result.x = q.x*fScale;
    result.y = q.y*fScale;
    result.z = q.z*fScale;
    result.w = q.w*fScale;
    }
//-------------------------------------------------------------------------
void _Quaternion_::Normalize_(_Quaternion_ &q, _Quaternion_ &q__)
    {
    float fInverse = (float)(1 / pow2(q.x*q.x + q.y*q.y + q.z*q.z + q.w*q.w));
    q__.x = q.x*fInverse;
    q__.y = q.y*fInverse;
    q__.z = q.z*fInverse;
    q__.w = q.w*fInverse;

    }
//-------------------------------------------------------------------------
void _Quaternion_::Normailze()
    {
    float fInverse = (float)(1 / pow2(x*x + y*y + z*z + w*w));
    x*= fInverse;
    y*= fInverse;
    z*= fInverse;
    w*= fInverse;
    }
const _Quaternion_& _Quaternion_::Normalize_()
    {
    float fInverse = (float)(1 / pow2(x*x + y*y + z*z + w*w));
    x*= fInverse;
    y*= fInverse;
    z*= fInverse;
    w*= fInverse;return *this;
    }

//-------------------------------------------------------------------------
/* float _Quaternion_::fgetv(_Vector_*vAsix__)
    {
    this->Normalize_();
    float fS = sqrtf(1.0f- (w*w));     
    if (fabs(fS) < 0.0005f)     {fS = 1.0f; }    

    vAsix__->x = (x / fS);
    vAsix__->y = (y / fS);
    vAsix__->z = (z / fS);

    return acosf(w)*2.0f;//返回 f弧度
    } */


//------------------------------------------------------------------------
//☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐
//☐☐☐☐☐☐☐☐☐☐↗v三☐☐☐☐☐☐☐
//☐☐☐☐☐☐☐☐☐/☐↖☐☐☐☐☐☐☐☐
//☐☐☐☐☐☐☐☐/☐☐☐┊☐☐☐☐☐☐☐
//☐☐☐☐☐☐☐/☐☐☐☐┇☐☐☐☐☐☐☐
//☐☐☐☐☐☐/☐☐☐☐☐☐┊q二☐☐☐☐☐
//☐☐☐☐☐/☐☐☐☐☐☐☐┃☐☐☐☐☐☐
//☐☐☐☐/☐☐☐☐☐☐☐☐┃☐☐☐☐☐☐
//☐☐☐/☐☐☐☐☐☐☐☐☐┃☐☐☐☐☐☐
//☐☐●━━━━━━━━━━→v一☐☐☐☐☐
//☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐
//v一决定v三指向q二的方向,v三跟随q二旋转,q二旋转v一不变,v一与v三Len度相同如果q二为原始,v一＝v三

void _Quaternion_::Rot_(_Vector_ &v, _Quaternion_ &qRotation,_Vector_ &result)  
    {//v一旋q二为v三
    float fX2 = qRotation.x + qRotation.x;
    float fY2 = qRotation.y + qRotation.y;
    float fZ2 = qRotation.z + qRotation.z;
    float fXX2 = qRotation.x*fX2;
    float fXY2 = qRotation.x*fY2;
    float fXZ2 = qRotation.x*fZ2;
    float fYY2 = qRotation.y*fY2;
    float fYZ2 = qRotation.y*fZ2;
    float fZZ2 = qRotation.z*fZ2;
    float fWX2 = qRotation.w*fX2;
    float fWY2 = qRotation.w*fY2;
    float fWZ2 = qRotation.w*fZ2;
    float fTransformedX = v.x*((1.0f - fYY2) - fZZ2) + v.y*(fXY2 - fWZ2) + v.z*(fXZ2 + fWY2);
    float fTransformedY = v.x*(fXY2 + fWZ2) + v.y*((1.0f - fXX2) - fZZ2) + v.z*(fYZ2 - fWX2);
    float fTransformedZ = v.x*(fXZ2 - fWY2) + v.y*(fYZ2 + fWX2) + v.z*((1.0f - fXX2) - fYY2);
    result.x = fTransformedX;
    result.y = fTransformedY;
    result.z = fTransformedZ;
    }

//-------------------------------------------------------------------------
_Quaternion_ _Quaternion_:: operator + (const   _Quaternion_  &q)
    {
    _Quaternion_ q__;
    q__.x=this->x+q.x;q__.y=this->y+q.y;q__.z=this->z+q.z,q__.w=this->w+q.w;    
    
    return q__;
    }
//-------------------------------------------------------------------------
_Quaternion_ _Quaternion_:: operator * (const   _Quaternion_  &qBlocal)
    {
     _Quaternion_ result;
    float aX = x;
    float aY = y;
    float aZ = z;
    float aW = w;
    float bX = qBlocal.x;
    float bY = qBlocal.y;
    float bZ = qBlocal.z;
    float bW = qBlocal.w;
    result.x = aX*bW + bX*aW + aY*bZ - aZ*bY;
    result.y = aY*bW + bY*aW + aZ*bX - aX*bZ;
    result.z = aZ*bW + bZ*aW + aX*bY - aY*bX;
    result.w = aW*bW - aX*bX - aY*bY - aZ*bZ;
    return result;
    }    
    
    
//-------------------------------------------------------------------------－
/**/  
bool _Quaternion_:: operator == (const _Quaternion_& q)
    {
    if(this->x==q.x && this->y==q.y && this->z==q.z && this->w==q.w) return true;
    else
        return false;
    }
bool _Quaternion_:: operator != (const _Quaternion_& q)
    {
    if(this->x==q.x && this->y==q.y && this->z==q.z && this->w==q.w) return false;
    else
        return true;
    }  

const  _Quaternion_& _Quaternion_:: operator = (const  _Quaternion_ &q)
    {
    if(this==&q) return*this;
    memcpy(this,&q,sizeof(_Quaternion_));
    return*this;
    }
const  _Quaternion_& _Quaternion_:: operator = (const  _Matrix33_ &f33)
    {
    float trace = f33.Xx + f33.Yy + f33.Zz;
    if (trace >= 0)
        {
        float fS = (float)pow2(trace + 1.0)*2; 
        float fInverseS = 1 / fS;
        this->w = 0.25f*fS;
        this->x = (f33.Yz - f33.Zy)*fInverseS;
        this->y = (f33.Zx - f33.Xz)*fInverseS;
        this->z = (f33.Xy - f33.Yx)*fInverseS;
        }
    else if ((f33.Xx > f33.Yy) & (f33.Xx > f33.Zz))
        {
        float fS = (float)pow2(1.0 + f33.Xx - f33.Yy - f33.Zz)*2; 
        float fInverseS = 1 / fS;
        this->w = (f33.Yz - f33.Zy)*fInverseS;
        this->x = 0.25f*fS;
        this->y = (f33.Yx + f33.Xy)*fInverseS;
        this->z = (f33.Zx + f33.Xz)*fInverseS;
        }
    else if (f33.Yy > f33.Zz)
        {
        float fS = (float)pow2(1.0 + f33.Yy - f33.Xx - f33.Zz)*2; 
        float fInverseS = 1 / fS;
        this->w = (f33.Zx - f33.Xz)*fInverseS;
        this->x = (f33.Yx + f33.Xy)*fInverseS;
        this->y = 0.25f*fS;
        this->z = (f33.Zy + f33.Yz)*fInverseS;
        }
    else
        {
        float fS = (float)pow2(1.0 + f33.Zz - f33.Xx - f33.Yy)*2; 
        float fInverseS = 1 / fS;
        this->w = (f33.Xy - f33.Yx)*fInverseS;
        this->x = (f33.Zx + f33.Xz)*fInverseS;
        this->y = (f33.Zy + f33.Yz)*fInverseS;
        this->z = 0.25f*fS;
        }
    return*this;
    }
    
const  _Quaternion_& _Quaternion_:: operator = (cfloat f4[])
    {
    // this->x =f4[0];this->y=f4[1] ; this->z=f4[2] ;this->w=f4[3];
    this->x =f4[1];this->y=f4[2] ; this->z=f4[3] ;this->w=f4[0];//blender
    return*this;
    }
const  _Quaternion_& _Quaternion_:: operator = (cdouble f4[])
    {
    // this->x =f4[0];this->y=f4[1] ; this->z=f4[2] ;this->w=f4[3];
    this->x =f4[1];this->y=f4[2] ; this->z=f4[3] ;this->w=f4[0];//blender
    return*this;
    }    
_Quaternion_  _Quaternion_ :: copy()
    {
    _Quaternion_ q=_Quaternion_();
    if(this==NULL) return*this;
    q.x=this->x;q.y=this->y;q.z=this->z;q.w=this->w;
    //memcpy(this,&v,sizeof(_Vector_));

    return q;
    }

////////////////////////////////////////////////
bool  _Vector_::isZero() const 
    {
    //if((this->x<0.00001 && this->y<0.00001 )||(this->x<0.00001  && this->z<0.00001 ) ||(this->y<0.00001  && this->z<0.00001 ) )
    //cfloat& x,y=abs(this->y);
    //if(len>0.0)return False;
    //else
        {//if((x*x + y*y + z*z)<f0000001)PRINT6("",x,y,z,x*x,y*y,z*z);
        return  (x*x + y*y + z*z)<f0000001;
        }

    }    

void _Vector_::Zero()
    {this->x = 0.0;this->y = 0.0;this->z = 0.0; }
/*
float* _Vector_:: To(float *&f3__)const
    {f3__[0]=x;f3__[1]=y;f3__[2]=z;return f3__;     }
*/
void _Vector_:: To(float f3__[3])const
    {f3__[0]=x;f3__[1]=y;f3__[2]=z;     }
    
void  _Vector_:: To(float f3__[3],int idxOfArray)const
    {
    f3__[idxOfArray+0]=x;f3__[idxOfArray+1]=y;f3__[idxOfArray+2]=z;     }
void  _Vector_:: To(double d3__[3])const
    {d3__[0]=(double)x;d3__[1]=(double)y;d3__[2]=(double)z;} 
void  _Vector_:: To(int d3__[3])const
    {d3__[0]=x;d3__[1]=y;d3__[2]=z;}     
void  _Vector_:: PulsTo(float f3__[3])const
    {
    f3__[0]+=x;f3__[1]+=y;f3__[2]+=z;} 
void  _Vector_:: PulsTo(float f3__[3],int idxOfArray)const
    {
    f3__[idxOfArray+0]+=x;f3__[idxOfArray+1]+=y;f3__[idxOfArray+2]+=z;}     
void  _Vector_:: getPuls(cfloat f3[3])
    {
    ASSERT1("getPuls ",f3==NULL);
    x+=f3[0];y+=f3[1];z+=f3[2];}     
    
void _Vector_ :: get(cfloat f2[2])
    {
    ASSERT1("get ",f2==NULL);
    this->x=f2[0];this->y=f2[1];
    //memcpy(this,&v,sizeof(_Vector_));
    }       
        
void _Vector_ :: get(cfloat f3 [3],int idxOfArray)
    {
    ASSERT1("get ",f3==NULL);

    this->x=f3[idxOfArray+0];this->y=f3[idxOfArray+1];this->z=f3[idxOfArray+2];
    //memcpy(this,&v,sizeof(_Vector_));
    }       
    
    
//-------------------------------------------------------------------------  
float _Vector_::len2()const 
    {return x*x + y*y + z*z; }
float _Vector_::len()const 
    { 
    //if(len==0)
        //len=pow2(x*x + y*y + z*z);return len;
    return pow2(x*x + y*y + z*z);
    }

//=============================================================
float _Vector_::fCos(const _Vector_& vTwo)const 
    {
    _Vector_ vThis,v2;
    vThis=this->_Normalize(),v2=vTwo._Normalize();//一定要分开
    
    //PTvector亖亖("vThis",vThis);PTvector亖亖("v2",v2);
    float lenProject=vThis.dot(v2);//如果其中一边Len为零,就当它是90度,极少出现
    //printf("lenProject= %f○= %f\n",lenProject,acos((float)lenProject));
    if(lenProject<-1.0)lenProject=-1.0;else if(lenProject>1.0)lenProject=1.0;//●●防止__出现 -1.#IND00
    
    return lenProject;
    
    }    
  
float _Vector_::angle(const _Vector_& vTwo)const 
    {
    _Vector_ vThis=this->_Normalize(),  v2=vTwo._Normalize();
    //PTvector亖亖("vThis",vThis);PTvector亖亖("v2",v2);
    float lenProject=vThis.dot(v2);//如果其中一边Len为零,就当它是90度,极少出现
    //printf("lenProject= %f○= %f\n",lenProject,acos((float)lenProject));
    if(lenProject<-1.0)lenProject=-1.0;else if(lenProject>1.0)lenProject=1.0;//●●防止__出现 -1.#IND00
    return acos(lenProject);//● acos(必须 1>= x >=-1)//acos(邻边Ξ对边) 返回角cos值的弧度
    }    
float _Vector_::angle(const _Vector_& vTwo \
                                                        ,cbool& bNormThis,cbool& bNorm2)const
    {
    _Vector_ vThis=(bNormThis) ? this->_Normalize() : *this,  v2=(bNorm2) ? vTwo._Normalize() : vTwo;
    //PTvector亖亖("vThis",vThis);PTvector亖亖("v2",v2);
    float lenProject=vThis.dot(v2);//如果其中一边Len为零,就当它是90度,极少出现
    //printf("lenProject= %f○= %f\n",lenProject,acos((float)lenProject));
    if(lenProject<-1.0)lenProject=-1.0;else if(lenProject>1.0)lenProject=1.0;//●●防止__出现 -1.#IND00
    return acos(lenProject);//● acos(必须 1>= x >=-1)//acos(邻边Ξ对边) 返回角cos值的弧度
    }  
float _Vector_::angle(cfloat f3二[3])const //改变自身
    {
    _Vector_ vThis= this->_Normalize(),v2(f3二);v2.Normalize_() ;
    //PTvector亖亖("vThis",vThis);PTvector亖亖("v2",v2);
    float lenProject=vThis.dot(v2);//如果其中一边Len为零,就当它是90度,极少出现
    //printf(" dot= %f\n",lenProject);
    return acos(lenProject);
    }        
float _Vector_::angle(cfloat f3二[3]  \
                                                ,cbool& bNormThis,cbool& bNorm2)const
    {
    _Vector_ vThis=(bNormThis) ? this->_Normalize() : *this,v2(f3二);
    if(bNorm2) v2.Normailze() ;
    //PTvector亖亖("vThis",vThis);PTvector亖亖("v2",v2);
    float lenProject=vThis.dot(v2);//如果其中一边Len为零,就当它是90度,极少出现
    //printf(" dot= %f\n",lenProject);
    return acos(lenProject);
    }   
//----按旋Asix的Invert时针旋--------------------------
const _Vector_& _Vector_::Rot_(_Vector_&AsixK,cfloat& angleR \
                                                                                                           ,cbool& bNormAsix __trued) //改变自身
    {//this是要旋转的向量,vAsixK是旋转Asix,ang是旋转角度 vRot 是v的结果●●如果vAsixKLen度不是1,v1结果不保持Len度,否则保持Len度
    if(angleR==0)return *this;
    if(bNormAsix)AsixK.Normailze();
    cfloat& fCosAngleR=cos(angleR);
    *this=(*this)*fCosAngleR  +  AsixK.cross((*this))*sin(angleR)  +  AsixK*(1-fCosAngleR)*((*this).dot(AsixK));
    return *this;
    }
    
void _Vector_::Rotate(_Vector_&AsixK,cfloat& angleR \
                                                                                            ,cbool& bNormAsix __trued)//改变自身
    {//this是要旋转的向量,vAsixK是旋转Asix,ang是旋转角度 vRot 是v的结果●●如果vAsixKLen度不是1,v1结果不保持Len度,否则保持Len度
    if(angleR==0)return ;
    if(bNormAsix)AsixK.Normailze();
    cfloat& fCosAngleR=cos(angleR);
    *this=(*this)*fCosAngleR  +  AsixK.cross((*this))*sin(angleR)  +  AsixK*(1-fCosAngleR)*((*this).dot(AsixK));
    }  
    
void _Vector_::Rotate(const _Vector_& AsixK,cfloat& angleR)
    {
    if(angleR==0)return ;
    cfloat& fCosAngleR=cos(angleR);
    *this=(*this)*fCosAngleR  +  AsixK.cross((*this))*sin(angleR)  +  AsixK*(1-fCosAngleR)*((*this).dot(AsixK));
    }
_Vector_ _Vector_::_Rotate(_Vector_&AsixK,cfloat& angleR2 \
                                                                                                            ,cbool& bNormAsix __trued)const //bNormAsix=true
    {//this是要旋转的向量,vAsixK是旋转Asix,ang是旋转角度 vRot 是v的结果●●如果vAsixKLen度不是1,v1结果不保持Len度,否则保持Len度
    //●●如果Asix 是不同Len度 旋转相同角度 结果不同
    if(angleR2==0)return *this;
    if(bNormAsix)AsixK.Normailze();
    cdouble& fCosAngleR=cos(angleR2);
    double angleR=angleR2;
    return (*this)*fCosAngleR  +  AsixK.cross((*this))*sin(angleR)  +  AsixK*(1-fCosAngleR)*((*this).dot(AsixK));
    }    
_Vector_ _Vector_::_Rotate(const _Vector_& AsixK,cfloat& angleR2)const 
    {
    if(angleR2==0)return *this;
    cdouble& fCosAngleR=cos(angleR2);
    double angleR=angleR2;
    return (*this)*fCosAngleR  +  AsixK.cross((*this))*sin(angleR)  +  AsixK*(1-fCosAngleR)*((*this).dot(AsixK));
    }    

//========================================================
static _Vector_  vVerticalFoot,vThisN,vVerticalToOther;
void _Vector_::RotateTo(const _Vector_& vOther,cfloat& angleR)//改变自身,没有旋转Asix
    {
    if(angleR==0)return;
    //☐☐☐☐☐☐☐☐☐☐☐
    //☐☐☐☐vOther☐☐☐☐☐☐☐☐☐☐
    //☐☐☐☐│☐☐☐☐☐☐☐☐☐☐☐☐
    //☐☐☐┆↖☐☐☐☐☐△☐☐☐☐☐☐☐☐☐    
    //☐☐☐│☐┊☐☐┄─┃☐☐☐☐☐☐☐☐    
    //☐☐┆☐☐┇┄─☐☐┃☐☐☐☐☐☐☐☐☐    
    //☐☐│☐┄─┊☐☐☐┃☐☐☐☐☐☐    
    //☐┆┄─☐☐┇☐☐☐┃☐☐☐☐☐☐    
    //  fang━━━━━━━━━this     ☐☐☐
    //☐☐☐☐☐☐☐☐☐☐☐
    //☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐
    //☐☐☐☐☐☐☐☐☐☐   vOther━━━━━━vOther☐☐
    //☐☐☐☐☐☐☐☐☐☐/↑☐☐☐☐☐↗☐☐☐
    //☐☐☐☐☐☐☐☐☐/┄△━━━→△☐☐☐☐
    //☐☐☐☐☐☐☐☐//☐┃☐☐☐/☐☐☐☐
    //☐☐☐☐☐☐☐//☐☐┃angZ   /☐☐☐☐☐☐
    //☐☐☐☐☐☐//☐☐☐┃☐/☐☐☐☐☐☐☐
    //☐☐☐☐☐//☐☐☐☐┃/☐☐☐☐☐☐☐☐
    //☐☐☐    fang━━━━━━this ☐☐☐☐☐☐☐☐
    //☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐
    //☐☐☐☐☐☐☐☐☐vOther☐
    //☐☐☐☐☐☐☐☐┆☐☐☐☐☐☐☐☐☐☐☐☐
    //☐☐☐☐☐☐☐☐│☐☐△━━━━━→△☐☐
    //☐☐☐☐☐☐☐┆☐☐/┃☐☐☐☐┄/☐☐☐
    //☐☐☐☐☐☐☐│☐/☐┃☐☐┄─/☐☐☐☐
    //☐☐☐☐☐☐┆☐/☐☐┃┄─☐/☐☐☐☐
    //☐☐☐☐☐☐│/☐☐┄┃☐☐/thisTo△☐☐☐☐
    //☐☐☐☐☐┆/☐┄─☐┃angZ/☐☐☐☐☐☐☐
    //☐☐☐☐☐/┄─☐☐☐┃/☐☐☐☐☐☐☐☐
    //☐☐☐☐0ang━━━━━━this☐☐☐☐☐☐☐☐
    
    //☐☐☐☐vOther☐☐☐☐☐☐☐
    //☐☐☐☐│☐☐☐☐☐☐
    //☐☐☐┆↑↖☐☐☐☐☐    
    //☐☐☐│┃☐\☐△☐    
    //☐☐┆☐┃☐┄\☐☐☐    
    //☐☐│☐v交点☐☐\☐☐    
    //☐┆┄─↑☐☐☐☐\☐    
    //  0ang━━→━━━━━━this
    //☐☐☐☐VerticalFoot☐☐☐☐☐☐☐
    if(this->len()!=1.0f)
        this->Normailze();//vThisN=this->_Normalize();
    /*
    vMulltif_v(vOther.dot(*this),*this,vVerticalFoot);
    v一v_v(vOther,vVerticalFoot,vVerticalToOther);
    vPulsv_v(vVerticalFoot,(  vVerticalToOther * (vVerticalFoot.len()*tan(angleR)/vVerticalToOther.len())  ),*this);
    */
    //------------------------------------------------------------
    /**/
    float fdot=vOther.dot(*this);
    vVerticalFoot=(*this)*fdot;
    vVerticalToOther=vOther-vVerticalFoot;
    *this=vVerticalFoot+(  vVerticalToOther  *  (vVerticalFoot.len()*tan(angleR)/vVerticalToOther.len())  );//v交点
    
    //------------------------------------------------------------
    /*
    vVerticalToOther=vOther  -  (*this)  *  vOther.dot(*this);
    //vVerticalToOther.x=vOther.x-this->x*vOther.x*this->x  -  this->x*vOther.y*this->y  -  this->x*vOther.z*this->z;
    //vVerticalToOther.y=vOther.y-this->y*vOther.x*this->x  -  this->y*vOther.y*this->y  -  this->y*vOther.z*this->z;
    //vVerticalToOther.z=vOther.z-this->z*vOther.x*this->x  -  this->z*vOther.y*this->y  -  this->z*vOther.z*this->z;
    
    *this=*this+(  vVerticalToOther  *  (this->len()*tan(angleR)/vVerticalToOther.len())  );//v交点
    */
    }    
    
static inline float Dot(cfloat f3点X[3],cfloat f3PointY[3])
    {  return f3点X[0]*f3PointY[0]+f3点X[1]*f3PointY[1]+f3点X[2]*f3PointY[2]; }
    


void _Vector_::RotateTo(cfloat f3Other[3],cfloat& angleR )//改变自身,没有旋转Asix
    {

    this->_Normalize(f3This);
    Mullti( f3This,Dot(f3Other,f3This),f3VerticalFootTo  );
    Minus(f3Other,f3VerticalFootTo,f3VerticalToOther);
    //*this=f3VerticalFootTo+ (  f3VerticalToOther  *  (f3VerticalFootTo.len()*tan(angleR)/f3VerticalToOther.len())  );//v交点
    Mullti(f3VerticalToOther ,len1(f3VerticalFootTo)*tan(angleR)/len1(f3VerticalToOther),f3VerticalToOtherR);
    Puls(f3VerticalFootTo,f3VerticalToOtherR,*this);
    
    }    

void _Vector_::Normailze(cbool& bCheckLen)//改变自身 并返回自身
    {
    if(bCheckLen&&this->isZero()){PRINT1("★匚卍Vector _Vector_::Normalize_()",this->isZero());return ;}
    float oneDv = 1 / pow2(x*x + y*y + z*z);// oneDv
    if(oneDv!=1)
        {x*= oneDv;y*= oneDv;z*= oneDv;}
    }

const _Vector_& _Vector_::Normalize_(cbool& bCheckLen)//改变自身 并返回自身
    {
    if(bCheckLen&&this->isZero()){PRINT1("★匚卍Vector _Vector_::Normalize_()",this->isZero());return _Vector_();}
    float oneDv = 1 / pow2(x*x + y*y + z*z);// oneDv
    if(oneDv!=1)
        {x*= oneDv;y*= oneDv;z*= oneDv;}
    return*this;
    }
    
_Vector_ _Vector_::_Normalize(cbool& bCheckLen)const//不改变自身
    {
    if(bCheckLen&&this->isZero()){PRINT1("★卍Vector _Vector_::_Normalize()const",this->isZero());return _Vector_();}
    _Vector_ v__;
    float oneDv = (float)(1 / pow2(x*x + y*y + z*z));
    if(oneDv!=1)
        {v__.x=x*oneDv;v__.y=y*oneDv;v__.z=z*oneDv;}
    else
        return *this;
    return v__;
    }    

void _Vector_::_Normalize(float f3ThisN__[3],cbool& bCheckLen)const//不改变自身
    {
    if(bCheckLen&&this->isZero()){PRINT1("★匚卍Vector _Vector_::Normalize_()",this->isZero());return ;}
    float oneDv = (float)(1 / pow2(x*x + y*y + z*z));
    if(oneDv!=1)
        {f3ThisN__[0]=x*oneDv;f3ThisN__[1]=y*oneDv;f3ThisN__[2]=z*oneDv;}
    else
        this->To(f3ThisN__);

    }  
    

//-------------------------------------------------------------------------  
_Vector_ _Vector_::cross(const _Vector_& vTwo)const 
    {
    _Vector_  v__;
    if(this->len()==0)
        {//ASSERT(this->len()==0);
        PRINT2("★★cross ",this->len(),vTwo.len());return v__;}
        
    if(vTwo.len()==0)
        {//ASSERT(vTwo.len()==0);
        PRINT2("★★cross ",this->len(),vTwo.len());return v__;}
    v__.x= this->y*vTwo.z - this->z*vTwo.y;
    v__.y= this->z*vTwo.x - this->x*vTwo.z;
    v__.z= this->x*vTwo.y - this->y*vTwo.x;
    //if(v__.z==0)v__.z=1;//可能是精度问题 让结果等于0
    return v__;
    }    
_Vector_ _Vector_::cross(cfloat vTwo[3])const 
    {
    _Vector_  v__;
    if(this->len()==0)
        {//ASSERT(this->len()==0);
        PRINT2("★★cross ",this->len(),len1(vTwo));return v__;}
        
    if(len1(vTwo)==0)
        {//ASSERT(vTwo.len()==0);
        PRINT2("★★cross ",this->len(),len1(vTwo));return v__;}
    v__.x= this->y*vTwo[2] - this->z*vTwo[1];
    v__.y= this->z*vTwo[0] - this->x*vTwo[2];
    v__.z= this->x*vTwo[1]- this->y*vTwo[0];
    //if(v__.z==0)v__.z=1;//可能是精度问题 让结果等于0
    return v__;
    }    
double _Vector_::dot(const _Vector_& vTwo)const
    {
    //PTvector亖亖("this dot",*this);PTvector亖亖("v2 dot",vTwo);
    //printf("dot   %f\n",this->x*vTwo.x +  this->y*vTwo.y+this->z*vTwo.z);
    //cout<<"dot in  "<<this->x*vTwo.x<<"   " <<this->y*vTwo.y<<"   " <<this->z*vTwo.z<<endl;
    //float fAdd=this->x*vTwo.x +  this->y*vTwo.y;
    //cout<<"dot in +  "<<fAdd<<endl;cout<<"dot in +2  "<<fAdd+this->z*vTwo.z<<endl;
    //printf("dot=%f\n",this->x*vTwo.x+this->y*vTwo.y+this->z*vTwo.z);
    //PRINT6("",this->x,vTwo.x,this->y,vTwo.y,this->z,vTwo.z);
#ifdef __PRINT__
    //if(vTwo.len()==0){PRINT1("★★dot",vTwo.len());}    
#endif
    return this->x*vTwo.x+this->y*vTwo.y+this->z*vTwo.z;
    
    }       
    
double  _Vector_:: dot(float f3PointY[3])const
    {
#ifdef __PRINT__
    //if(len1(f3PointY)==0){PRINT1("★★dot",len1(f3PointY));}  
#endif

    return this->x*f3PointY[0]+this->y*f3PointY[1]+this->z*f3PointY[2];    }
    
//-------------------------------------------------------------------------
bool _Vector_ :: operator== (cfloat f3[3])const
    {
    if(this->x==f3[0] && this->y==f3[1] && this->z==f3[2] ) return true;
    else
        return false;
    }
    
bool _Vector_ :: operator== (const _Vector_& v)const
    {
    if(this->x==v.x && this->y==v.y && this->z==v.z) return true;
    else
        return false;
    }
    
bool _Vector_ :: operator!= (const _Vector_& v)const
    {
    
    /*
    PRINT3DB("",this->x==v.x ,this->y==v.y,this->z==v.z);
    PRINT3DB("",this->x-v.x ,this->y-v.y, this->z-v.z);
    PRINT6DB("",this->x,v.x ,this->y,v.y,this->z,v.z);
    PRINT3DB("",this->x-v.x ,this->y-v.y, this->z-v.z);  
    PRINT3DB("",this->x-v.x ==0.0, this->y-v.y==0.0, this->z-v.z==0.0);
    */
    
    float fCompare=0.001;
    //if(this->x==v.x && this->y==v.y && this->z==v.z) return false;//●●会出错??,可能是精度问题
    if(abs(this->x-v.x)<fCompare&& abs(this->y-v.y)<fCompare&& abs(this->z-v.z)<fCompare) return false;
    else
        return true;
    }
      
    
_Vector_  _Vector_ :: copy()
    {
    _Vector_ v=_Vector_();
    if(this==NULL) return*this;
    v.x=this->x;v.y=this->y;v.z=this->z;
    //memcpy(this,&v,sizeof(_Vector_));

    return v;
    }    
/*
const _Vector_&   _Vector_ ::  operator ?=(_Vector_  v)//按值传递
    {
    if(this==&v) return*this;
    else if(&v==NULL) return  v;
    //v果.x=v.x;v果.y=v.y;v果.z=v.z;
    this->x=v.x;this->y=v.y;this->z=v.z;
    //memcpy(this,&v,sizeof(_Vector_));

    return*this;
    }
*/

static _Vector_ vPulsG,vMinusG,vMulltiG,vDiviG;

_Vector_ _Vector_:: operator + (const _Vector_& v)const
    {
    vPulsG.x=this->x+v.x;vPulsG.y=this->y+v.y;vPulsG.z=this->z+v.z;    
    return vPulsG;
    }
_Vector_ _Vector_:: operator + (cfloat f3[3])const
    {
    ASSERT1("operator+ ",f3==NULL);
    vPulsG.x=this->x+f3[0];vPulsG.y=this->y+f3[1];vPulsG.z=this->z+f3[2];    
    return vPulsG;
    }    

_Vector_ _Vector_:: operator - (const _Vector_& v)const
    {
    vMinusG.x=this->x-v.x;vMinusG.y=this->y-v.y;vMinusG.z=this->z-v.z;    
    return vMinusG;
    }      
_Vector_ _Vector_:: operator - (cfloat f3[3])const
    {
    ASSERT1("operator-",f3==NULL);
    vMinusG.x=this->x-f3[0];vMinusG.y=this->y-f3[1];vMinusG.z=this->z-f3[2];    
    return vMinusG;
    }      
    
_Vector_ _Vector_:: operator - (cfloat f44[4][4])const
    {
    ASSERT1("operator f44-",f44==NULL);float f44Inv[4][4];f44Invert_f44 (f44,f44Inv);
    return vgetf44Mulltiv(f44Inv,(*this));

    }      
//----friend--------------------------
_Vector_ operator - (cfloat f3[3],const _Vector_& p)
    {
    ASSERT1("operator+ ",f3==NULL);
    vPulsG.x=f3[0]-p.x;vPulsG.y=f3[1]-p.y;vPulsG.z=f3[2]-p.z;    
    return vPulsG;
    } 
    
_Vector_ operator + (cfloat f3[3],const _Vector_& p)
    {
    ASSERT1("operator+ ",f3==NULL);
    vPulsG.x=p.x+f3[0];vPulsG.y=p.y+f3[1];vPulsG.z=p.z+f3[2];    
    return vPulsG;
    }   
    
_Vector_ operator * (cfloat f33[3][3],const _Vector_& vec)
    {
    ASSERT1("operator f33* ",f33==NULL);
	vMulltiG.x = f33[0][0]*vec.x +f33[1][0]*vec.y + f33[2][0];
	vMulltiG.y = f33[0][1]*vec.x +f33[1][1]*vec.y + f33[2][1];
	vMulltiG.z = f33[0][2]*vec.x +f33[1][2]*vec.y + f33[2][2];
    return vMulltiG;
    } 
_Vector_ operator * (cfloat f44[4][4],const _Vector_& vec)
    {
    ASSERT1("operator f44* ",f44==NULL);
	vMulltiG.x = f44[0][0]*vec.x + f44[1][0]*vec.y + f44[2][0]*vec.z + f44[3][0];
	vMulltiG.y = f44[0][1]*vec.x + f44[1][1]*vec.y + f44[2][1]*vec.z + f44[3][1];
	vMulltiG.z = f44[0][2]*vec.x + f44[1][2]*vec.y + f44[2][2]*vec.z + f44[3][2];
    return vMulltiG;
    } 
/*
void _Vector_:: operator = (const _Vector_& p,float f3__[3])
    {
    ASSERT1("operator+ ",f3==NULL);
    f3__[0]=p.x;f3__[1]=p.y;f3__[2]=p.z;    
    }  
*/
    
/*
const _Vector_& _Vector_:: operator - (const _Vector_& v)
    {
    _Vector_ vTwo;
    vTwo.x=this->x-v.x;vTwo.y=this->y-v.y;vTwo.z=this->z-v.z;    
    return vTwo;
    }    
*/    

_Vector_ _Vector_:: operator*(cint& i)const
    {
    vMulltiG.x=this->x*i;vMulltiG.y=this->y*i;vMulltiG.z=this->z*i;    
    return vMulltiG;
    }  
    

_Vector_ _Vector_:: operator*(cfloat& f)const
    {//PRINT0("1");
    vMulltiG.x=this->x*f;vMulltiG.y=this->y*f;vMulltiG.z=this->z*f;    
    return vMulltiG;
    }   
    
_Vector_ operator*(cfloat& f,const _Vector_& p)
    {//PRINT0("2");
    vMulltiG.x=p.x*f;vMulltiG.y=p.y*f;vMulltiG.z=p.z*f;    
    return vMulltiG;
    } 
_Vector_ _Vector_:: operator*(cdouble& f)const
    {//PRINT0("1");
    vMulltiG.x=this->x*f;vMulltiG.y=this->y*f;vMulltiG.z=this->z*f;    
    return vMulltiG;
    }   

_Vector_ _Vector_:: operator / (cint& f)const
    {
    if(f==0){vDiviG.Zero();}
    else
        {vDiviG.x=this->x/f;vDiviG.y=this->y/f;vDiviG.z=this->z/f; } 
    #ifdef PRINT_MQV
        //printf("MQV   %f   %f   %f   %d  \n",vDiviG.x,vDiviG.y,vDiviG.z,i);
    #endif
    return vDiviG;
    }      
_Vector_ _Vector_:: operator / (const  size_t f)const
    {
    if(f==0){vDiviG.Zero();}
    else
        {vDiviG.x=this->x/f;vDiviG.y=this->y/f;vDiviG.z=this->z/f; }   
    #ifdef PRINT_MQV
    #endif
    return vDiviG;
    }   
_Vector_ _Vector_:: operator / (cfloat& f)const
    {
    if(f==0){vDiviG.Zero();}
    else
        {vDiviG.x=this->x/f;vDiviG.y=this->y/f;vDiviG.z=this->z/f; } 
    #ifdef PRINT_MQV
        //printf("MQV   %f   %f   %f   %f  \n",vDiviG.x,vDiviG.y,vDiviG.z,f);
    #endif
    
    return vDiviG;
    }        
_Vector_ _Vector_:: operator / (cdouble& f)const
    {
    if(f==0){vDiviG.Zero();}
    else
        {vDiviG.x=this->x/f;vDiviG.y=this->y/f;vDiviG.z=this->z/f; }   
    #ifdef PRINT_MQV
        //printf("MQV   %f   %f   %f   %f  \n",vDiviG.x,vDiviG.y,vDiviG.z,f);
    #endif
    
    return vDiviG;
    }        
//----改变自身-------------------------------------------------------------
_Vector_&_Vector_ ::operator--()//前置自减  --v
    {
	this->x=-this->x;this->y=-this->y;this->z=-this->z;  
	return *this;
    }

const _Vector_ _Vector_ ::operator--(int)//后置自减  v--
    {
	this->x=-this->x;this->y=-this->y;this->z=-this->z;  
	return *this;
    }
    
const _Vector_& _Vector_ :: operator+= (const _Vector_& v)
    {
    this->x=this->x+v.x;this->y=this->y+v.y;this->z=this->z+v.z;    
    return*this;
    }  
    
const _Vector_& _Vector_ :: operator*= (cint& i)
    {
    this->x=this->x*i;this->y=this->y*i;this->z=this->z*i;    
    return*this;
    }    
const _Vector_& _Vector_ :: operator*= (cfloat& f)
    {
    this->x=this->x*f;this->y=this->y*f;this->z=this->z*f;    
    return*this;
    }       
const _Vector_& _Vector_ :: operator*= (cdouble& f)
    {
    this->x=this->x*f;this->y=this->y*f;this->z=this->z*f;    
    return*this;
    }         
const _Vector_& _Vector_ :: operator-= (const _Vector_& v)
    {
    this->x=this->x-v.x;this->y=this->y-v.y;this->z=this->z-v.z;    
    return*this;
    }      
    
const _Vector_& _Vector_ :: operator/= (cint& i)
    {
    this->x=this->x/(float)i;this->y=this->y/(float)i;this->z=this->z/(float)i;    
    return*this;
    }          
const _Vector_& _Vector_ :: operator/= (cfloat& f)
    {
    this->x=this->x/f;this->y=this->y/f;this->z=this->z/f;    
    return*this;
    }      
const _Vector_& _Vector_ :: operator/= (cdouble& f)
    {
    this->x=this->x/f;this->y=this->y/f;this->z=this->z/f;    
    return*this;
    }       

const _Vector_& _Vector_ ::  operator= (const _Vector_& v)//按引用传递
    {
    if(this==&v) return*this;
    else if(&v==NULL) return v;//返回NULL
    this->x=v.x;this->y=v.y;this->z=v.z;
    //memcpy(this,&v,sizeof(_Vector_));

    return*this;
    }

const _Vector_& _Vector_ :: operator= (cfloat  f3[3])
    {
    ASSERT1("operator= ",f3==NULL);
    this->x=f3[0];this->y=f3[1];this->z=f3[2];return*this;
    }

const _Vector_& _Vector_ :: operator= (const  double  d3[3])
    {
    ASSERT1("operator= ",d3==NULL);
    this->x=d3[0];this->y=d3[1];this->z=d3[2];
    return*this;
    }   
    
/*
const _Vector_& _Vector_ :: operator= (const initializer_list<int>il)
    {
    this->x=*(il.begin());this->y=*(il.begin()+1);this->z=*(il.begin()+2);
   
    return*this;
    }  
//template<typename T>
const _Vector_& _Vector_ :: operator= (const initializer_list<float>il)
    {

    this->x=*(il.begin());this->y=*(il.begin()+1);this->z=*(il.begin()+2);
   
    return*this;
    }   
const _Vector_& _Vector_ :: operator= (const initializer_list<double>il)
    {

    this->x=*(il.begin());this->y=*(il.begin()+1);this->z=*(il.begin()+2);
   
    return*this;
    }   
 */
// #include <assert.h>

static float f0G;
cfloat&   _Vector_:: operator [] (cint& index) const   
    {
    #ifdef PRINT_MQV
        if(index>3 || index<0)
            {    
            perror("_Vector_ 下标越界!");
            fprintf(stderr,"_Vector_ 下标越界!");
            // assert(true);//断言判断From的下标是否在约定范围之内
            
            }
    #endif
    f0G=0;
    switch (index)
        {
        //case 0:return x;case 1:return y;case 2:return z;default :return 0.0f;
        case 0:return this->x;case 1:return this->y;case 2:return this->z;default :return f0G;
        //case 0:return x;case 1:return y;case 2:return z;default :return 0.0f;
        }
        
    }
    
/*
_Vector_&  _Vector_:: operator - ()//改变变自身//-v;
    {  
    x = -x;    y = -y;    z = -z;
    return*this;
    }
*/
_Vector_  _Vector_:: operator - ()const 
    {  
    _Vector_ v;
    v.x = -x;    v.y = -y;    v.z = -z;
    return v;
    }

_Vector_  _Vector_:: operator ~()
    {  
    _Vector_ v;
    v.x = x;    v.y = y;    v.z = z;
    return v;
    }
    

    
////END////END////END////END////END////END////END////END////
#endif
