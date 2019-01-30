#ifndef __MATQUATVEC_H__
    #define __MATQUATVEC_H__

#include <cmath>
#include <string>

#include<vector>//initializer_list
#include<iostream>

#include"..\GDLIB_define.h"
// #include "DJS_typedef.h" 

static float f3This[3],f3ThisN[3],f3VerticalFootTo[3],f3VerticalToOther[3],f3VerticalToOtherR[3];

__forceinline void f44_q(cfloat m[4][4],float q[4]);//math\DJS_math.h
//==============================
#define M4MulltiM4_M4(thisTo,m2,M__)    \
    M__ Xx = thisTo Xx*m2 Xx + thisTo Yx*m2 Xy + thisTo Zx*m2 Xz + thisTo Lx*m2 M03;\
    M__ Xy = thisTo Xy*m2 Xx + thisTo Yy*m2 Xy + thisTo Zy*m2 Xz + thisTo Ly*m2 M03;\
    M__ Xz = thisTo Xz*m2 Xx + thisTo Yz*m2 Xy + thisTo Zz*m2 Xz + thisTo Lz*m2 M03;\
    M__ M03 = thisTo M03*m2 Xx + thisTo M13*m2 Xy + thisTo M23*m2 Xz + thisTo M33*m2 M03;\
    M__ Yx = thisTo Xx*m2 Yx + thisTo Yx*m2 Yy + thisTo Zx*m2 Yz + thisTo Lx*m2 M13;\
    M__ Yy = thisTo Xy*m2 Yx + thisTo Yy*m2 Yy + thisTo Zy*m2 Yz + thisTo Ly*m2 M13;\
    M__ Yz = thisTo Xz*m2 Yx + thisTo Yz*m2 Yy + thisTo Zz*m2 Yz + thisTo Lz*m2 M13;\
    M__ M13 = thisTo M03*m2 Yx + thisTo M13*m2 Yy + thisTo M23*m2 Yz +thisTo M33*m2 M13;\
    M__ Zx = thisTo Xx*m2 Zx + thisTo Yx*m2 Zy  + thisTo Zx*m2 Zz +  thisTo Lx*m2 M23;\
    M__ Zy = thisTo Xy*m2 Zx + thisTo Yy*m2 Zy  + thisTo Zy*m2 Zz +  thisTo Ly*m2 M23;\
    M__ Zz = thisTo Xz*m2 Zx + thisTo Yz*m2 Zy  + thisTo Zz*m2 Zz +  thisTo Lz*m2 M23;\
    M__ M23 = thisTo M03*m2 Zx + thisTo M13*m2 Zy + thisTo M23*m2 Zz + thisTo M33*m2 M23;\
    M__ Lx  = thisTo Xx*m2 Lx + thisTo Yx*m2 Ly + thisTo Zx*m2 Lz + thisTo Lx*m2 M33;\
    M__ Ly  = thisTo Xy*m2 Lx + thisTo Yy*m2 Ly + thisTo Zy*m2 Lz + thisTo Ly*m2 M33;\
    M__ Lz  = thisTo Xz*m2 Lx + thisTo Yz*m2 Ly + thisTo Zz*m2 Lz + thisTo Lz*m2 M33;\
    M__ M33 = thisTo M03*m2 Lx + thisTo M13*m2 Ly + thisTo M23*m2 Lz + thisTo M33*m2 M33


#define M4MulltiF44_M4(thisTo,m1,M__)    \
    M__ Xx = thisTo Xx*m1[0][0] + thisTo Yx*m1[0][1] + thisTo Zx*m1[0][2] + thisTo Lx*m1[0][3];\
    M__ Xy = thisTo Xy*m1[0][0] + thisTo Yy*m1[0][1] + thisTo Zy*m1[0][2] + thisTo Ly*m1[0][3];\
    M__ Xz = thisTo Xz*m1[0][0] + thisTo Yz*m1[0][1] + thisTo Zz*m1[0][2] + thisTo Lz*m1[0][3];\
    M__ M03  = thisTo M03*m1[0][0] + thisTo M13*m1[0][1] + thisTo M23*m1[0][2]  + thisTo M33*m1[0][3];\
    M__ Yx = thisTo Xx*m1[1][0] + thisTo Yx*m1[1][1] + thisTo Zx*m1[1][2]  + thisTo Lx*m1[1][3];\
    M__ Yy = thisTo Xy*m1[1][0] + thisTo Yy*m1[1][1] + thisTo Zy*m1[1][2]  + thisTo Ly*m1[1][3];\
    M__ Yz = thisTo Xz*m1[1][0] + thisTo Yz*m1[1][1] + thisTo Zz*m1[1][2]  + thisTo Lz*m1[1][3];\
    M__ M13  = thisTo M03*m1[1][0]+ thisTo M13*m1[1][1] + thisTo M23*m1[1][2] + thisTo M33*m1[1][3];\
    M__ Zx = thisTo Xx*m1[2][0] + thisTo Yx*m1[2][1] + thisTo Zx*m1[2][2] + thisTo Lx*m1[2][3];\
    M__ Zy = thisTo Xy*m1[2][0] + thisTo Yy*m1[2][1] + thisTo Zy*m1[2][2] + thisTo Ly*m1[2][3];\
    M__ Zz = thisTo Xz*m1[2][0] + thisTo Yz*m1[2][1] + thisTo Zz*m1[2][2] + thisTo Lz*m1[2][3];\
    M__ M23  = thisTo M03*m1[2][0]+ thisTo M13*m1[2][1] + thisTo M23*m1[2][2] + thisTo M33*m1[2][3];\
    M__ Lx  = thisTo Xx*m1[3][0] + thisTo Yx*m1[3][1] + thisTo Zx*m1[3][2]+ thisTo Lx*m1[3][3];\
    M__ Ly  = thisTo Xy*m1[3][0] + thisTo Yy*m1[3][1] + thisTo Zy*m1[3][2]+ thisTo Ly*m1[3][3];\
    M__ Lz  = thisTo Xz*m1[3][0] + thisTo Yz*m1[3][1] + thisTo Zz*m1[3][2]+ thisTo Lz*m1[3][3];\
    M__ M33 =  thisTo M03*m1[3][0] + thisTo M13*m1[3][1] + thisTo M23*m1[3][2] + thisTo M33*m1[3][3]

#define F44MulltiM4_M4(m0,m2,M__)    \
    M__ Xx =m0[0][0]*m2 Xx + m0[1][0]*m2 Xy + m0[2][0]*m2 Xz + m0[3][0]*m2 M03;\
    M__ Xy =m0[0][1]*m2 Xx + m0[1][1]*m2 Xy + m0[2][1]*m2 Xz + m0[3][1]*m2 M03;\
    M__ Xz =m0[0][2]*m2 Xx + m0[1][2]*m2 Xy + m0[2][2]*m2 Xz + m0[3][2]*m2 M03;\
    M__ M03=m0[0][3]*m2 Xx + m0[1][3]*m2 Xy + m0[2][3]*m2 Xz + m0[3][3]*m2 M03;\
    M__ Yx =m0[0][0]*m2 Yx + m0[1][0]*m2 Yy + m0[2][0]*m2 Yz + m0[3][0]*m2 M13;\
    M__ Yy =m0[0][1]*m2 Yx + m0[1][1]*m2 Yy + m0[2][1]*m2 Yz + m0[3][1]*m2 M13;\
    M__ Yz =m0[0][2]*m2 Yx + m0[1][2]*m2 Yy + m0[2][2]*m2 Yz + m0[3][2]*m2 M13;\
    M__ M13=m0[0][3]*m2 Yx + m0[1][3]*m2 Yy + m0[2][3]*m2 Yz + m0[3][3]*m2 M13;\
    M__ Zx =m0[0][0]*m2 Zx + m0[1][0]*m2 Zy + m0[2][0]*m2 Zz + m0[3][0]*m2 M23;\
    M__ Zy =m0[0][1]*m2 Zx + m0[1][1]*m2 Zy + m0[2][1]*m2 Zz + m0[3][1]*m2 M23;\
    M__ Zz =m0[0][2]*m2 Zx + m0[1][2]*m2 Zy + m0[2][2]*m2 Zz + m0[3][2]*m2 M23;\
    M__ M23=m0[0][3]*m2 Zx + m0[1][3]*m2 Zy + m0[2][3]*m2 Zz + m0[3][3]*m2 M23;\
    M__ Lx =m0[0][0]*m2 Lx + m0[1][0]*m2 Ly + m0[2][0]*m2 Lz + m0[3][0]*m2 M33;\
    M__ Ly =m0[0][1]*m2 Lx + m0[1][1]*m2 Ly + m0[2][1]*m2 Lz + m0[3][1]*m2 M33;\
    M__ Lz =m0[0][2]*m2 Lx + m0[1][2]*m2 Ly + m0[2][2]*m2 Lz + m0[3][2]*m2 M33;\
    M__ M33=m0[0][3]*m2 Lx + m0[1][3]*m2 Ly + m0[2][3]*m2 Lz + m0[3][3]*m2 M33
    
#define F44MulltiF44_M4(m0,m1,M__)    \
    M__ Xx =m0[0][0] * m1[0][0] + m0[1][0]*m1[0][1] + m0[2][0]*m1[0][2] + m0[3][0]*m1[0][3];\
    M__ Xy =m0[0][1] * m1[0][0] + m0[1][1]*m1[0][1] + m0[2][1]*m1[0][2] + m0[3][1]*m1[0][3];\
    M__ Xz =m0[0][2] * m1[0][0] + m0[1][2]*m1[0][1] + m0[2][2]*m1[0][2] + m0[3][2]*m1[0][3];\
    M__ M03 =m0[0][3] * m1[0][0] + m0[1][3]*m1[0][1] + m0[2][3]*m1[0][2] + m0[3][3]*m1[0][3];\
    M__ Yx =m0[0][0] * m1[1][0] + m0[1][0]*m1[1][1] + m0[2][0]*m1[1][2] + m0[3][0]*m1[1][3];\
    M__ Yy =m0[0][1] * m1[1][0] + m0[1][1]*m1[1][1] + m0[2][1]*m1[1][2] + m0[3][1]*m1[1][3];\
    M__ Yz =m0[0][2] * m1[1][0] + m0[1][2]*m1[1][1] + m0[2][2]*m1[1][2] + m0[3][2]*m1[1][3];\
    M__ M13 =m0[0][3] * m1[1][0] + m0[1][3]*m1[1][1] + m0[2][3]*m1[1][2] + m0[3][3]*m1[1][3];\
    M__ Zx =m0[0][0] * m1[2][0] + m0[1][0]*m1[2][1] + m0[2][0]*m1[2][2] + m0[3][0]*m1[2][3];\
    M__ Zy =m0[0][1] * m1[2][0] + m0[1][1]*m1[2][1] + m0[2][1]*m1[2][2] + m0[3][1]*m1[2][3];\
    M__ Zz =m0[0][2] * m1[2][0] + m0[1][2]*m1[2][1] + m0[2][2]*m1[2][2] + m0[3][2]*m1[2][3];\
    M__ M23 =m0[0][3] * m1[2][0] + m0[1][3]*m1[2][1] + m0[2][3]*m1[2][2] + m0[3][3]*m1[2][3];\
    M__ Lx =m0[0][0] * m1[3][0] + m0[1][0]*m1[3][1] + m0[2][0]*m1[3][2] + m0[3][0]*m1[3][3];\
    M__ Ly =m0[0][1] * m1[3][0] + m0[1][1]*m1[3][1] + m0[2][1]*m1[3][2] + m0[3][1]*m1[3][3];\
    M__ Lz =m0[0][2] * m1[3][0] + m0[1][2]*m1[3][1] + m0[2][2]*m1[3][2] + m0[3][2]*m1[3][3];\
    M__ M33 =m0[0][3] * m1[3][0] + m0[1][3]*m1[3][1] + m0[2][3]*m1[3][2] + m0[3][3]*m1[3][3]
    
#define M3MulltiM3_M3(thisTo,m2,M__)    \
    M__ Xx = thisTo Xx*m2 Xx + thisTo Yx*m2 Xy + thisTo Zx*m2 Xz;\
    M__ Xy = thisTo Xy*m2 Xx + thisTo Yy*m2 Xy + thisTo Zy*m2 Xz;\
    M__ Xz = thisTo Xz*m2 Xx + thisTo Yz*m2 Xy + thisTo Zz*m2 Xz;\
    M__ Yx = thisTo Xx*m2 Yx + thisTo Yx*m2 Yy + thisTo Zx*m2 Yz;\
    M__ Yy = thisTo Xy*m2 Yx + thisTo Yy*m2 Yy + thisTo Zy*m2 Yz;\
    M__ Yz = thisTo Xz*m2 Yx + thisTo Yz*m2 Yy + thisTo Zz*m2 Yz;\
    M__ Zx = thisTo Xx*m2 Zx + thisTo Yx*m2 Zy  + thisTo Zx*m2 Zz ;\
    M__ Zy = thisTo Xy*m2 Zx + thisTo Yy*m2 Zy  + thisTo Zy*m2 Zz ;\
    M__ Zz = thisTo Xz*m2 Zx + thisTo Yz*m2 Zy  + thisTo Zz*m2 Zz 


#define M3MulltiF33_M3(thisTo,m1,M__)    \
    M__ Xx = thisTo Xx*m1[0][0] + thisTo Yx*m1[0][1] + thisTo Zx*m1[0][2];\
    M__ Xy = thisTo Xy*m1[0][0] + thisTo Yy*m1[0][1] + thisTo Zy*m1[0][2];\
    M__ Xz = thisTo Xz*m1[0][0] + thisTo Yz*m1[0][1] + thisTo Zz*m1[0][2];\
    M__ Yx = thisTo Xx*m1[1][0] + thisTo Yx*m1[1][1] + thisTo Zx*m1[1][2];\
    M__ Yy = thisTo Xy*m1[1][0] + thisTo Yy*m1[1][1] + thisTo Zy*m1[1][2];\
    M__ Yz = thisTo Xz*m1[1][0] + thisTo Yz*m1[1][1] + thisTo Zz*m1[1][2];\
    M__ Zx = thisTo Xx*m1[2][0] + thisTo Yx*m1[2][1] + thisTo Zx*m1[2][2];\
    M__ Zy = thisTo Xy*m1[2][0] + thisTo Yy*m1[2][1] + thisTo Zy*m1[2][2];\
    M__ Zz = thisTo Xz*m1[2][0] + thisTo Yz*m1[2][1] + thisTo Zz*m1[2][2]
    


struct _Vector_;struct _Matrix_;struct _Matrix33_;struct _Quaternion_;

////_Vector_//////////////////////////////////////////
//template<typename T>
typedef struct _Vector_
    {
public:
    float x;    float y;    float z;//float len=0.0;
    float*xyz;
    float &x_=x;    float &y_=y;    float &z_=z;    
    
    _Vector_():x(0.0), y(0.0), z(0.0){}
    _Vector_(cfloat& X, cfloat& Y){x = X; y = Y;  z = 0; }
    template<typename T,typename T2,typename T3>
    _Vector_(T X, T2 Y,T3 Z){x = X; y = Y;  z = Z; }
    //_Vector_(cint& X, cint& Y,cint& Z){x = X; y = Y;  z = Z; }
    //_Vector_(cfloat& X, cfloat& Y, cfloat& Z){x = X; y = Y;  z = Z; }
    //explicit _Vector_(cdouble& X, cdouble& Y, cdouble& Z){x = X; y = Y;  z = Z; }
    //explicit _Vector_(float f3[3]){x = f3[0]; y =f3[1];  z = f3[2]; } 
    explicit _Vector_(float*f3){x = f3[0]; y =f3[1];  z = f3[2]; } 
    explicit _Vector_(cfloat f3[3]){x = f3[0]; y =f3[1];  z = f3[2]; } //●声明为explicit的构造函数不能在隐式转换中使用
    explicit _Vector_(cdouble f3[3]){x = f3[0]; y =f3[1];  z = f3[2]; } 
    explicit _Vector_(cint f3[3]){x = f3[0]; y =f3[1];  z = f3[2]; } 
    explicit _Vector_(cfloat&  f){x = f; y = f;  z = f; }//●●不能有这个函数,否则参数可以把float From为卍Vector
    explicit _Vector_(cint& f){x = f; y = f;  z = f; }
    explicit _Vector_(cdouble& f){x = f; y = f;  z = f; }
    //_Vector_(int f);//把int 转为 float
    //~_Vector_();
    //-------------------------------------------------------------------------
    bool isZero()const;
    void Zero();
    float len2()const;
    float len()const;
    float fCos(const _Vector_&vTwo)const;   //邻边Ξ对边  ●●不能 命名为cos
    float angle(const _Vector_&vTwo)const;
    float angle(const _Vector_&vTwo,cbool& bNormThis,cbool& bNormAsix)const;
    float angle(cfloat f3二[3])const;
    float angle(cfloat f3二[3],cbool& bNormThis,cbool& bNormAsix)const;
    void Normailze(cbool& bCheckLen=false);
    const _Vector_ &Normalize_(cbool& bCheckLen=false);
    _Vector_ _Normalize(cbool& bCheckLen=false)const;//不改变自身
    void _Normalize(float f3ThisN__[3],cbool& bCheckLen=false)const;//不改变自身
    //void dot(const _Vector_&v一,const  _Vector_ &vTwo, float &fProduct);
    const _Vector_& Rot_(_Vector_&AsixK,cfloat& angleR,cbool& bNormAsix=true); //改变自身
    void Rotate(_Vector_&AsixK,cfloat& angleR,cbool& bNormAsix=true);  //改变自身
    void Rotate(const _Vector_& AsixK,cfloat& angleR);  //改变自身
    void RotateTo(const _Vector_&vOther,cfloat& angleR);//改变自身
    void RotateTo(cfloat f3Other[3],cfloat& angleR);    //改变自身
    _Vector_ _Rotate(_Vector_&AsixK,cfloat& angleR,cbool& bNormAsix=true)const ;//kAsix的Invert时针旋转__    
    _Vector_ _Rotate(const _Vector_& AsixK,cfloat& angleR)const ;
    // static void Δ距离平方(_Vector_ &v一, _Vector_ &vTwo, float &fDistanceSquared);
    _Vector_ cross(const _Vector_&vTwo)const ;//●不能用const 结尾 因为要修改len
    _Vector_ cross(cfloat vTwo[3])const ;
    inline double dot(const _Vector_&vTwo)const;
    inline double dot(float f3[3])const;

    //-------------------------------------------------------------------------
    //float* To(float *&f3__)const;
    void To(float f3__[3])const;//自身不变
    //void To(float*Ψf3);
    void To(float f3[3],int idxOfArray)const;//自身不变
    void To(double d3[3])const;
    void To(int d3__[3])const;
    template<typename T>
    void  To(T&x__,T&y__,T&z__)const  {x__=x;y__=y;z__=z;}     
    void PulsTo(float f3[3])const;
    void PulsTo(float f3[3],int idxOfArray)const;//自身不变
    
    void getPuls(cfloat f3[3]); 
    void get (cfloat f2[2]);
    void get (cfloat f3[3] ,int idxOfArray);      
    bool operator== (const _Vector_&v)const;//比较
    bool operator== (cfloat f3[3])const;
    bool operator!= (const _Vector_&v)const;//比较    
    //----改变自身--------------------------
    _Vector_& operator--();//--v改变自身 返回引用
    const _Vector_ operator--(int);//v-- 改变自身 返回值
    const _Vector_&  operator+= (const _Vector_& v);//改变自身
    const _Vector_ & operator-= (const _Vector_&v);//改变自身
    const _Vector_&  operator*= (cint& i);    //改变自身
    const _Vector_ & operator*= (cfloat& f);//改变自身
    const _Vector_&  operator*= (cdouble& f);//改变自身
    const _Vector_& operator = (const _Vector_ &v);//传引用
    const _Vector_ & operator /= (cint& i);//改变自身
    const _Vector_&  operator /= (cfloat& f);    //改变自身
    const _Vector_&  operator /= (cdouble& f);    //改变自身
    const _Vector_&  operator = (cfloat f3[3]);    //改变自身
    const _Vector_&  operator = (cdouble d3[3]);    //改变自身
   // const _Vector_  operator= (initializer_list<T> il);
    // const _Vector_  operator = (const  initializer_list<int> il);    //改变自身    
    // const _Vector_  operator = (const  initializer_list<float>il);    //改变自身    
    // const _Vector_  operator = (const  initializer_list<double>il);
    _Vector_  copy();
    //const _Vector_  operator ?=(_Vector_  v);//传递值  不改变自身

    _Vector_ operator + (const _Vector_& v)const;//●●const 在反面表示 自身也是const
    _Vector_ operator + (cfloat  f3[3])const;
    _Vector_ operator - (const _Vector_ &v)const;
    _Vector_ operator - (cfloat  f3[3])const;
    _Vector_ operator - (cfloat f44[4][4])const;
    friend _Vector_ operator + (cfloat f3[3],const _Vector_& p);//f3+ v
    friend _Vector_ operator - (cfloat f3[3],const _Vector_ &p);
    friend _Vector_ operator*(cfloat& f,const _Vector_& p);
    friend _Vector_ operator * (cfloat f3[3][3],const _Vector_& p);
    friend _Vector_ operator * (cfloat f3[4][4],const _Vector_ &p);
    //void operator = (const _Vector_ p,float f3__[3]);//●●c++中 有四个操作符不能是全局域中的重载，这四个操作符是：=， ->， operator[ ]， operator()。
    _Vector_ operator*(cint& i)const;  

    _Vector_ operator*(cfloat& f)const;   
    _Vector_ operator*(cdouble& f)const;    
    _Vector_ operator / (cint& i)const;
    _Vector_ operator / (const  size_t i)const;    
    _Vector_ operator / (cfloat& f)const;
    _Vector_ operator / (cdouble& f)const;
    
    //-------------------------------------------------------------------------
    //float& operator [] (const  int&index);
    /*
    float & operator [] (cint& index)
        {
        if(index>3 || index<0)
        {    
        perror("_Vector_ 下标越界!");
        fprintf(stderr,"_Vector_ 下标越界!");
        assert(true);//断言判断From的下标是否在约定范围之内
        
        }
        //return*(xyz+index);

        switch (index)
            {
            //case 0:xyz=(&x);case 1:xyz=(&y);case 2:xyz=(&z);
            //case 0:(xyz+index)=(&x);case 1:(xyz+index)=(&y);case 2:(xyz+index)=(&z);
            //case 0:return this->x;case 1:return this->y;case 2:return this->z;default :return 0.0f;
           case 0:return this->x_;case 1:return this->y_;case 2:return this->z_;default :return 0.0f;
            //case 0:return*(&(this->x));case 1:return*(&(this->y));case 2:return*(&(this->z));default :return 0.0f;
            //case 0:return x;case 1:return y;case 2:return z;default :return 0.0f;
            }
        printf("in=     %f     V.y=%f  \n",*(xyz),y);
        return*(xyz);
        }
    */   
    
    //-------------------------------------------------------------------------
    cfloat&  operator [] (cint& index) const;
    
    //_Vector_& operator - ();//改变自身
    _Vector_ operator - ()const;//不改变自身
    _Vector_ operator ~();//不改变自身
    }_Vector_;
    
////_Matrix_/////////////////////////////////////////
typedef  struct _Matrix_
    {
    //struct _Vector_;
    public:
    float Xx;float Xy;float Xz;    float M03;//[0][0],[0][1],[0][2],┃[0][3];
    float Yx;float Yy;float Yz;    float M13;//[1][0],[1][1],[1][2],┃[1][3];
    float Zx;float Zy;float Zz;     float M23;//[2][0],[2][1],[2][2],┃[2][3];
                                                                            
    float Lx;float Ly;float Lz;    float M33;//[3][0],[3][1],[3][2],┃[3][3];
    //----构造函数-------------------------------------------------------------
    _Matrix_(
                    float m00, float m01, float m02,       float m03,
                    float m10, float m11, float m12,       float m13,
                    float m20, float m21, float m22,       float m23,
                    
                    float f330, float f331, float f332,       float f333
                    )
        {
        Xx=m00;Xy=m01;Xz=m02;M03=m03;
        Yx=m10;Yy=m11;Yz=m12;M13=m13;
        Zx=m20;Zy=m21;Zz=m22;M23=m23;
        
        Lx=f330;Ly=f331;Lz=f332;M33=f333;
        }
    _Matrix_() : Xx(1), Xy(0), Xz(0), M03(0),
                             Yx(0), Yy(1), Yz(0), M13(0),
                             Zx(0), Zy(0), Zz(1), M23(0),
                             Lx(0), Ly(0), Lz(0), M33(1)
                       {}
    // XAsix    [0][0],[0][1],[0][2],┃[0][3];
    // YAsix    [1][0],[1][1],[1][2],┃[1][3];
    // ZAsix    [2][0],[2][1],[2][2],┃[2][3];
    //                                                              ┃    
    // Loc       [3][0],[3][1],[3][2],┃[3][3];
    _Matrix_(cint& f) : Xx(f), Xy(0), Xz(0), M03(0),
                                           Yx(0), Yy(f), Yz(0), M13(0),
                                           Zx(0), Zy(0), Zz(f), M23(0),
                                           Lx(0), Ly(0), Lz(0), M33(f)
                       {}  
    _Matrix_(cfloat& f) : Xx(f), Xy(0), Xz(0), M03(0),
                                           Yx(0), Yy(f), Yz(0), M13(0),
                                           Zx(0), Zy(0), Zz(f), M23(0),
                                           Lx(0), Ly(0), Lz(0), M33(f)
                       {}    
    explicit _Matrix_(cfloat f44From[][4])//explicit 防止其它类型传参
        {
        this->Xx=f44From[0][0];this->Xy=f44From[0][1];this->Xz=f44From[0][2];this->M03=f44From[0][3];
        this->Yx=f44From[1][0];this->Yy=f44From[1][1];this->Yz=f44From[1][2];this->M13=f44From[1][3];
        this->Zx=f44From[2][0];this->Zy=f44From[2][1];this->Zz=f44From[2][2];this->M23=f44From[2][3];
        this->Lx=f44From[3][0];this->Ly=f44From[3][1];this->Lz=f44From[3][2];this->M33=f44From[3][3];    
        }
    _Matrix_(const _Matrix33_&f44From);

    explicit _Matrix_(const _Vector_*X,const _Vector_*Y,const _Vector_*Z)
        {
        if(X)
            {this->Xx=X->x;this->Xy=X->y;this->Xz=X->z;}
        if(Y)
            {this->Yx=Y->x;this->Yy=Y->y;this->Yz=Y->z;}
        if(Z)
            {this->Zx=Z->x;this->Zy=Z->y;this->Zz=Z->z;}
        }
    
    explicit _Matrix_(const _Vector_*vLOC)
        {
        if(vLOC)
            {this->Lx=vLOC->x;this->Ly=vLOC->y;this->Lz=vLOC->z;}
        }
    _Matrix_(const _Vector_& vAsix,cfloat& angle);
    void get(cfloat f44From[][4])//explicit 防止其它类型传参
        {
        this->Xx=f44From[0][0];this->Xy=f44From[0][1];this->Xz=f44From[0][2];this->M03=f44From[0][3];
        this->Yx=f44From[1][0];this->Yy=f44From[1][1];this->Yz=f44From[1][2];this->M13=f44From[1][3];
        this->Zx=f44From[2][0];this->Zy=f44From[2][1];this->Zz=f44From[2][2];this->M23=f44From[2][3];
        this->Lx=f44From[3][0];this->Ly=f44From[3][1];this->Lz=f44From[3][2];this->M33=f44From[3][3];    
        }    
    //-------------------------------------------------------------------------
    void Unit();
    void Zero();
    bool isZero()const;
    // bool 卩正(char*c名,int i行,\
                                        // const char*s文件);
    float fDeterminant();
    _Matrix_ _Normalize()const ;//不改变自身
    void Normailze();//改变自已
    const _Matrix_&  Normalize_( );//改变自已
    _Matrix_ _Invert() const;//不改变自身
    _Matrix_&Invert( );//改变自已  
    
    _Matrix_ operator*(const _Matrix_ &m二)const;   
    _Matrix_ operator*(cfloat  M[4][4])const;
    friend _Matrix_ operator*(cfloat S[4][4],const _Matrix_&m) ;
    const _Matrix_&  operator*= (const _Matrix_ &m二);   
    _Matrix33_ operator*(const _Matrix33_ &f33Two)const; 
    const _Matrix_&  operator*= (const _Matrix33_&f33Two); 
    _Vector_  operator*(const _Vector_& v) const;
    _Matrix_ operator*(cfloat& fScale)const;
    const _Matrix_&  operator*= (cfloat& fScale); 
    //_Matrix_ operator*(cfloat f3Scale[3]);    
    const _Matrix_&  operator*= (cfloat f3Scale[3]);
    _Matrix_ operator/(const _Matrix_ &M)const;
    
    _Matrix_ operator + (const _Vector_& vLoc)const;//加位移
    _Matrix_ operator - (const _Vector_& vLoc)const;
    _Matrix_ operator-(const _Matrix_ &M)const;
    bool operator == (const  _Matrix_ &m)const;    //比较  
    bool operator != (const  _Matrix_ &m)const;    //比较  
    const _Matrix_&  operator = (const _Quaternion_ &q);
    const _Matrix_&  operator = (const _Matrix_ &m);
    const _Matrix_&  operator = (const _Matrix33_ &f33);
    const _Matrix_&  operator = (cfloat f33[3][3]);
    const _Matrix_&  operator = (cfloat f44[4][4]);
    const _Matrix_&  operator = (cfloat f16[16]);
    _Matrix_ copy();
    _Matrix33_ to33()const;
    _Vector_ X()const;_Vector_ Y()const;_Vector_ Z()const;_Vector_ Loc();
    
    _Vector_ size();void getLoc(const _Vector_& vLoc);void getLoc(cfloat f3Loc[3]);//改变自身
    _Matrix_  scaled(const _Vector_& vSize);
    void getSize(const _Vector_& vSize);//改变自身
    void getSize(cfloat f3Size[3]);//改变自身
    void getSize(cfloat&  fSize);//改变自身
    void getX(const _Vector_& X);void getY(const _Vector_& Y);void getZ(const _Vector_& Z);//改变自身
    void getXYZ(const _Vector_& X,const _Vector_& Y,const _Vector_& Z);
    void getEuler(const _Vector_& vEuler);//改变自身
    void getEuler(cfloat euler[3]);//改变自身
    
    void ToLoc(float loc__[3])const;void ToSize(float Size__[3])const;void ToEuler(float euler__[3])const;
    void To(float f33__[][3])const;
    void To(float f44__[][4])const;
    void To(float f16__[16])const;
    void Tof44bl(float f44__[][4])const;    
    _Vector_  vΔ加位移(_Vector_ &v);
    //void Rot_(_Vector_ &v, _Matrix_ &matrix, _Vector_ &result);
    _Matrix_& Rot_(_Vector_ &vAsix,cfloat& angleR,cbool& bNormAsix=true);//改变自身
    void Rotate(_Vector_ &vAsix,cfloat& angleR,cbool& bNormAsix=true);

    }_Matrix_;
    
////_Matrix33_//////////////////////////////////////////
typedef struct _Matrix33_
    {
    float Xx;//00;
    float Xy;//01;
    float Xz;// 02;
    float Yx;//10;
    float Yy;//11;
    float Yz;// 12; 
    float Zx;//20;
    float Zy;//21;
    float Zz;// 22; 

    // XAsix    [0][0],[0][1],[0][2],┃[0][3];
    // YAsix    [1][0],[1][1],[1][2],┃[1][3];
    // ZAsix    [2][0],[2][1],[2][2],┃[2][3];
    _Matrix33_(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22)
        {
        Xx=m00;Xy=m01;Xz=m02;
        Yx=m10;Yy=m11;Yz=m12;
        Zx=m20;Zy=m21;Zz=m22;
       
        }
    _Matrix33_(): Xx(1.0), Xy(0), Xz(0), Yx(0), Yy(1.0), Yz(0), Zx(0), Zy(0), Zz(1.0){    }//构造函数
    _Matrix33_(cint& f) : Xx(f), Xy(0), Xz(0), Yx(0), Yy(f), Yz(0), Zx(0), Zy(0), Zz(f){    }
    _Matrix33_(cfloat& f) : Xx(f), Xy(0), Xz(0), Yx(0), Yy(f), Yz(0), Zx(0), Zy(0), Zz(f){    }
    _Matrix33_(cfloat f44From[][4])
        {
        this->Xx=f44From[0][0];this->Xy=f44From[0][1];this->Xz=f44From[0][2];
        this->Yx=f44From[1][0];this->Yy=f44From[1][1];this->Yz=f44From[1][2];
        this->Zx=f44From[2][0];this->Zy=f44From[2][1];this->Zz=f44From[2][2];
        }
    _Matrix33_(const _Matrix_&f44From)
        {
        this->Xx=f44From.Xx;this->Xy=f44From.Xy;this->Xz=f44From.Xz;
        this->Yx=f44From.Yx;this->Yy=f44From.Yy;this->Yz=f44From.Yz;
        this->Zx=f44From.Zx ;this->Zy=f44From.Zy;this->Zz=f44From. Zz;
        }
    _Matrix33_(const _Vector_*X,const _Vector_*Y,const _Vector_*Z)
        {
        if(X)
            {this->Xx=X->x;this->Xy=X->y;this->Xz=X->z;}
        if(Y)
            {this->Yx=Y->x;this->Yy=Y->y;this->Yz=Y->z;}
        if(Z)
            {this->Zx=Z->x;this->Zy=Z->y;this->Zz=Z->z;}
        }
    _Matrix33_(const _Vector_& vAsix,cfloat& angle);

    void get(cfloat f44From[][3])//explicit 防止其它类型传参
        {
        this->Xx=f44From[0][0];this->Xy=f44From[0][1];this->Xz=f44From[0][2];
        this->Yx=f44From[1][0];this->Yy=f44From[1][1];this->Yz=f44From[1][2];
        this->Zx=f44From[2][0];this->Zy=f44From[2][1];this->Zz=f44From[2][2];
        }  

    //--------------------------------------------------
    _Matrix33_  copy();
    void Unit();//改变自身
    void  Zero();//改变自身    
    bool isZero()const;//改变自身
    bool 卩正(char*c名,int i行,\
                                    const char*s文件);
    void Puls(_Matrix33_ &f33Coord, _Matrix33_ &vTwo, _Matrix33_ &f33__);
    void Puls(_Matrix_ &f33Coord, _Matrix33_ &vTwo, _Matrix33_ &f33__);
    void Puls(_Matrix33_ &f33Coord, _Matrix_ &vTwo, _Matrix33_ &f33__);
    void Puls(_Matrix_ &f33Coord, _Matrix_ &vTwo, _Matrix33_ &f33__);
    float fDeterminant();
    float fAdaptiveDeterminant(int &iSubMatrixCode);
    _Matrix33_ _Normalize()const ;//不改变自身
    void Normailze();//改变自已
    const _Matrix33_& Normalize_( );//改变自已
    _Matrix33_& Invert();//改变自已
    _Matrix33_ _Invert();

    void Mulltif33_f33(float f33M[3][3], float  f33__[3][3]);
    void Mulltif44_f33(float f44M[4][4], float  f33__[3][3]);
    void f44Mullti二f33(float f44S[4][4],float  f33__[3][3]);

   
    //----operator-------------------------------------------------------------
    _Matrix33_  operator + (const   _Matrix33_  &f33_)const;
    bool operator == (const  _Matrix33_ &f33)const;//比较  
    bool operator != (const  _Matrix33_ &f33)const;//比较  
    const _Matrix33_& operator = (const  _Quaternion_ &q_);
    const _Matrix33_&  operator = (const   _Matrix33_ &f33_); 
    const _Matrix33_&  operator = (cfloat f44From[4][4]); 
    const _Matrix33_&  operator = (cfloat f44From[3][3]);
    const _Matrix33_& operator = (cfloat f16[16]);
    _Vector_ operator*(const _Vector_ &v)const;
    _Matrix33_ operator*(const   _Matrix33_ &f33)const;   
    _Matrix33_ operator*(const   _Matrix_ &m)const;    
    _Matrix33_ operator*(cfloat&  fScale)const;  
    void scale(float fScale,float  f33__[3][3]);
    
    void Rot_(_Matrix33_ &f33Coord, _Matrix_ &vTwo);
    _Matrix33_& Rot_(_Vector_ &vAsix,cfloat& angleR,cbool& bNormAsix=true);//改变自身
    void Rotate(_Vector_ &vAsix,cfloat& angleR,cbool& bNormAsix=true);
    float  roll(float cAsix[3]=NULL);
    _Matrix_ To4x4();
    
    _Vector_ X()const;_Vector_ Y()const;_Vector_ Z()const;
    void getX(const _Vector_& X);void getY(const _Vector_& Y);void getZ(const _Vector_& Z);
    void getXYZ(const _Vector_& X,const _Vector_& Y,const _Vector_& Z);
    _Vector_ size();
    void getEuler(const _Vector_& vEuler);//改变自身
    void getEuler(cfloat euler[3]);//改变自身
    _Matrix33_ scaled(const _Vector_ &vSize);
    void getSize(const _Vector_& vSize);//改变自身
    void getSize(cfloat f3Size[3]);//改变自身
    void getSize(cfloat& fSize);//改变自身
    void ToSize(float Size__[3])const;void ToEuler(float euler__[3])const;
    void To(float f33__[][3])const;
    void To(float f44__[][4])const;
    //static void Δ积v一f33二给v三(_Vector_ &v, _Matrix33_ &f33, _Vector_ &f33__);
    //static void Rot_(_Vector_ &v, _Matrix_ &f44, _Vector_ &f33__);
    void CreateOuterProduct(_Vector_ &f33Coord, _Vector_ &vTwo, _Matrix33_ &f33__);
    //-------------------------------------------------------------------------
    void Tof44bl(float f44[4][4])const;

    //-------------------------------------------------------------------------
    }_Matrix33_;

////_Quaternion_/////////////////////////////////////////
typedef  struct _Quaternion_
    {
    float x;
    float y;
    float z;
    float w;
    template<typename T,typename T2,typename T3,typename T4>
    _Quaternion_(T X, T2 Y,T3 Z,T4 W){x = X; y = Y;  z = Z;w = W; }
    //_Quaternion_(cfloat X, cfloat Y, cfloat Z, cfloat W){x = X; y = Y; z = Z; w = W;}
    // _Quaternion_(cfloat q[4]):x(q[0]),y(q[1]),z(q[2]),w(q[3]){}
    _Quaternion_(cfloat q[4]):x(q[1]),y(q[2]),z(q[3]),w(q[0]){}//blender
    _Quaternion_(){}
    
    void To(float f4__[4])const;//自身不变
    void To(double f4__[4])const;
    static void Puls(_Quaternion_ &v一, _Quaternion_ &vTwo, _Quaternion_ &result);
    static void fSize(_Quaternion_ &q, float fScale, _Quaternion_ &result);
    static void Normalize_(_Quaternion_ &q, _Quaternion_ &q__);
    void Normailze();//改变自已
    const _Quaternion_& Normalize_();
    static void Rot_(_Vector_ &v, _Quaternion_ &qRotation, _Vector_ &result);
    //-------------------------------------------------------------------------－
    _Quaternion_ operator + (const   _Quaternion_  &q);
    _Quaternion_ operator * (const   _Quaternion_  &qBlocal);
    bool  operator == (const   _Quaternion_ &q);//比较
    bool  operator != (const   _Quaternion_ &q);//比较    
    const  _Quaternion_ & operator = (const  _Quaternion_ &q);
    const  _Quaternion_ & operator = (const  _Matrix33_ &f33);
    const  _Quaternion_ & operator = (cfloat f4[4]);
    const  _Quaternion_ & operator = (cdouble f4[4]);    
    _Quaternion_  copy();
    }_Quaternion_;
    

////#define ////////////////////////////////////
/* #ifdef __PRINT__
    #define 正(m)    m.卩正(#m,__LINE__,__FILE__)
    #else
        #define 正(m)
#endif */
////MatQuatVec_G.cpp////////////////////////////////
/* static inline _Matrix33_ m3getXYZ(const _Vector_*ΨvAsixX_,const _Vector_*ΨvAsixY_,const _Vector_*ΨvAsixZ_ \
                                                                                                                ,char c修正Asix =NULL);
static inline _Matrix33_ m3getXYZ(cfloat*Ψf3X,cfloat*Ψf3Y,cfloat*Ψf3Z \
                                                                                                                ,char c修正Asix __0d); */
////END////END////END////END////END////END////END////END////
#endif

