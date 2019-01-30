

#ifndef __MATQUATVEC2_CPP__
    #define __MATQUATVEC2_CPP__
#include <cmath>

#include"MatQuatVec.h "

////////////////////////////////////////////
// _Vector_ vgetv3(Vector3&v3)
    // {vPrintG.x=v3.x;vPrintG.y=v3.y;vPrintG.z=v3.z;return vPrintG;}

template<typename T>
__forceinline void v_v(const Vector3&v3,_Vector_&v__)
    {v__.x=v3.x;v__.y=v3.y;v__.z=v3.z;}
    
template<typename T>
__forceinline void v_v(const _Vector_&v3,Vector3&v__)
    {v__.x=v3.x;v__.y=v3.y;v__.z=v3.z;}
    
//====_Vector3_==========================
// struct _Vector3_ ;
extern struct _Vector3_ vg__;
Vector3 v3TransG;
    
typedef struct _Vector3_ :public _Vector_
    {
    _Vector3_():_Vector_(){}
    _Vector3_(const _Vector_&v3){this->x=v3.x;this->y=v3.y;this->z=v3.z;}
    _Vector3_(const Vector3&v3){this->x=v3.x;this->y=v3.y;this->z=v3.z;}//复制构造函数
    
    _Vector3_ _Normalize(cbool& bCheckLen=false)const//不改变自身
        {
        if(bCheckLen&&this->isZero()){PRINT1("★ _Vector3_::_Normalize()const",this->isZero());return _Vector3_();}
        _Vector3_ v__;
        float oneDlen = (float)(1 / sqrt(x*x + y*y + z*z));
        if(oneDlen!=1)
            {v__.x=x*oneDlen;v__.y=y*oneDlen;v__.z=z*oneDlen;}
        else
            return *this;
        return v__;
        }   
    
    //------------------------------
    // _Vector3_&operator = (const _Vector3_&v3){this->x=v3.x;this->y=v3.y;this->z=v3.z;return*this;}
    _Vector3_&operator = (const Vector3&v3){this->x=v3.x;this->y=v3.y;this->z=v3.z;return*this;}
    _Vector3_&operator = (const Vector2&v3){this->x=v3.x;this->y=v3.y;return*this;}
    _Vector3_&operator = (const _Vector_&v3){this->x=v3.x;this->y=v3.y;this->z=v3.z;return*this;}
    //----------------------------------------
    void To(Vector3 &v3)
        {
        v3.x=this->x;v3.y=this->y;v3.z=this->z;
        }
    Vector3& v3()const 
        {
        v3TransG.x=this->x;v3TransG.y=this->y;v3TransG.z=this->z;
        return v3TransG;
        }        
    //---- Puls --------------------------
    _Vector3_ operator+(const Vector3 &v3)const 
        {  
        vg__.x=v3.x+this->x;vg__.y=v3.y+this->y;vg__.z=v3.z+this->z;
        return vg__;
        }
    _Vector3_ operator+(const Vector2 &v3)const 
        {  
        vg__.x=v3.x+this->x;vg__.y=v3.y+this->y;
        return vg__;
        }
    _Vector3_ operator+(const _Vector3_ &v3)const 
        {   
        vg__.x=v3.x+this->x;vg__.y=v3.y+this->y;vg__.z=v3.z+this->z;
        return vg__;
        }
    //---- Minus --------------------------
    _Vector3_ operator-(const Vector3 &v3)const 
        {  
        vg__.x=this->x - v3.x;vg__.y=this->y - v3.y;vg__.z=this->z - v3.z;
        return vg__;
        }
    _Vector3_ operator-(const Vector2 &v3)const 
        {  
        vg__.x=this->x - v3.x;vg__.y=this->y - v3.y;
        return vg__;
        }
    _Vector3_ operator-(const _Vector3_ &v3)const 
        {  
        vg__.x=this->x - v3.x;vg__.y=this->y - v3.y;vg__.z=this->z - v3.z;
        return vg__;
        }
    //------------------------------
    _Vector3_ operator*(const float &f)const 
        {  
        vg__.x=this->x*f;vg__.y=this->y*f;vg__.z=this->z*f;
        return vg__;
        }
        
    //----friend--------------------------
    friend _Vector3_ operator + (const Vector3&f3,const _Vector3_&p);//f3+ v
    friend _Vector3_ operator - (const Vector3&f3,const _Vector3_&p);
    friend _Vector3_ operator*(cfloat& f,const _Vector3_&p);
    // friend _Vector3_ operator * (Vector3&f3,const _Vector3_&p);
    // friend _Vector3_ operator * (const 卍Matrix3&f33,const _Vector3_&p);
    
    }_Vector3_;
    
//----friend--------------------------
_Vector_ v3PulsG,v3一G,v3MulltiG;
_Vector3_ operator - (const Vector3&f3,const _Vector3_&p)
    {
    // ASSERT1("operator+ ",f3==NULL);
    v3PulsG.x=f3.x-p.x;v3PulsG.y=f3.y-p.y;v3PulsG.z=f3.z-p.z;    
    return v3PulsG;
    } 
_Vector3_ operator*(cfloat&f,const _Vector3_&p)
    {//PRINT0("2");
    v3MulltiG.x=p.x*f;v3MulltiG.y=p.y*f;v3MulltiG.z=p.z*f;    
    return v3MulltiG;
    } 
_Vector3_ operator + (const Vector3&f3,const _Vector3_&p)
    {
    // ASSERT1("operator+ ",f3==NULL);
    v3PulsG.x=p.x+f3.x;v3PulsG.y=p.y+f3.y;v3PulsG.z=p.z+f3.z;    
    return v3PulsG;
    }   
//------------------------------    
__forceinline Vector3 X(const Basis&basis){return Vector3(basis.elements[0].x,basis.elements[1].x,basis.elements[2].x);}
__forceinline Vector3 Y(const Basis&basis){return Vector3(basis.elements[0].y,basis.elements[1].y,basis.elements[2].y);}
__forceinline Vector3 Z(const Basis&basis){return Vector3(basis.elements[0].z,basis.elements[1].z,basis.elements[2].z);}
/* _Vector3_ operator * (const 卍Matrix3&f33,const _Vector3_&vec)
    {
    // ASSERT1("operator f33* ",f33==NULL);
	v3MulltiG.x = f33[0][0]*vec.x +f33[1][0]*vec.y + f33[2][0];
	v3MulltiG.y = f33[0][1]*vec.x +f33[1][1]*vec.y + f33[2][1];
	v3MulltiG.z = f33[0][2]*vec.x +f33[1][2]*vec.y + f33[2][2];
    return v3MulltiG;
    } 
_Vector3_ operator * (卍Matrix4 f44[4][4],匚卍Vector3 vec)
    {
    ASSERT1("operator f44* ",f44==NULL);
	v3MulltiG.x = f44[0][0]*vec.x + f44[1][0]*vec.y + f44[2][0]*vec.z + f44[3][0];
	v3MulltiG.y = f44[0][1]*vec.x + f44[1][1]*vec.y + f44[2][1]*vec.z + f44[3][1];
	v3MulltiG.z = f44[0][2]*vec.x + f44[1][2]*vec.y + f44[2][2]*vec.z + f44[3][2];
    return v3MulltiG;
    } */
    
_Vector3_ vg__;
//====卍Matrix4====================================
#define gM4MulltiF44(thisTo,t,__trued)    \
    const Basis&basis=t.basis;const Vector3&origin=t.origin;\
    __trued Xx = thisTo Xx*basis.elements[0][0] + thisTo Yx*basis.elements[0][1] + thisTo Zx*basis.elements[0][2];\
    __trued Xy = thisTo Xy*basis.elements[0][0] + thisTo Yy*basis.elements[0][1] + thisTo Zy*basis.elements[0][2];\
    __trued Xz = thisTo Xz*basis.elements[0][0] + thisTo Yz*basis.elements[0][1] + thisTo Zz*basis.elements[0][2];\
    /* __trued M03  = thisTo M03*basis.elements[0][0] + thisTo M13*basis.elements[0][1] + thisTo M23*basis.elements[0][2]  + thisTo M33*basis.elements[0][3]; */\
    __trued Yx = thisTo Xx*basis.elements[1][0] + thisTo Yx*basis.elements[1][1] + thisTo Zx*basis.elements[1][2];\
    __trued Yy = thisTo Xy*basis.elements[1][0] + thisTo Yy*basis.elements[1][1] + thisTo Zy*basis.elements[1][2];\
    __trued Yz = thisTo Xz*basis.elements[1][0] + thisTo Yz*basis.elements[1][1] + thisTo Zz*basis.elements[1][2];\
    /* __trued M13  = thisTo M03*basis.elements[1][0]+ thisTo M13*basis.elements[1][1] + thisTo M23*basis.elements[1][2] + thisTo M33*basis.elements[1][3]; */\
    __trued Zx = thisTo Xx*basis.elements[2][0] + thisTo Yx*basis.elements[2][1] + thisTo Zx*basis.elements[2][2];\
    __trued Zy = thisTo Xy*basis.elements[2][0] + thisTo Yy*basis.elements[2][1] + thisTo Zy*basis.elements[2][2];\
    __trued Zz = thisTo Xz*basis.elements[2][0] + thisTo Yz*basis.elements[2][1] + thisTo Zz*basis.elements[2][2];\
    /* __trued M23  = thisTo M03*basis.elements[2][0]+ thisTo M13*basis.elements[2][1] + thisTo M23*basis.elements[2][2] + thisTo M33*basis.elements[2][3]; */ \
    __trued Lx  = thisTo Xx*origin.x + thisTo Yx*origin.y + thisTo Zx*origin.z + thisTo Lx*1;\
    __trued Ly  = thisTo Xy*origin.x + thisTo Yy*origin.y + thisTo Zy*origin.z + thisTo Ly*1;\
    __trued Lz  = thisTo Xz*origin.x + thisTo Yz*origin.y + thisTo Zz*origin.z + thisTo Lz*1
    /* __trued M33 =  thisTo M03*basis.elements[3][0] + thisTo M13*basis.elements[3][1] + thisTo M23*basis.elements[3][2] + thisTo M33*M[3][3] */
    
#define BASIS_M  \
        this->Xx=basis.elements[0][0];this->Xy=basis.elements[1][0];this->Xz=basis.elements[2][0];\
        this->Yx=basis.elements[0][1];this->Yy=basis.elements[1][1];this->Yz=basis.elements[2][1];\
        this->Zx=basis.elements[0][2];this->Zy=basis.elements[1][2];this->Zz=basis.elements[2][2];
#define M_BASIS \
        basis.elements[0][0]=this->Xx;basis.elements[1][0]=this->Xy;basis.elements[2][0]=this->Xz;\
        basis.elements[0][1]=this->Yx;basis.elements[1][1]=this->Yy;basis.elements[2][1]=this->Yz;\
        basis.elements[0][2]=this->Zx;basis.elements[1][2]=this->Zy;basis.elements[2][2]=this->Zz;
typedef struct 卍Matrix4 :public _Matrix_
    {
    卍Matrix4():_Matrix_(){}
    explicit 卍Matrix4(Spatial*&sp)//explicit 防止其它类型传参
        {
        Transform m =sp->get_global_transform();Basis&basis=m.basis;
        BASIS_M
        this->Lx=m.origin.x;this->Ly=m.origin.y;this->Lz=m.origin.z;this->M33=1;   
        }
    卍Matrix4(Transform&m )//explicit 防止其它类型传参
        {
        Basis&basis=m.basis;
        BASIS_M
        this->Lx=m.origin.x;this->Ly=m.origin.y;this->Lz=m.origin.z;this->M33=1;   
        }
    //------------------------------
    卍Matrix4&operator = (Transform&m)
        {
        Basis&basis=m.basis;
        BASIS_M
        this->Lx=m.origin.x;this->Ly=m.origin.y;this->Lz=m.origin.z;this->M33=1;
        return*this;
        }
    //------------------------------
    卍Matrix4 operator*(const Transform &t)const 
        {  
        卍Matrix4 M__;
        gM4MulltiF44(this->,t,M__.);
        return M__;
        }
    //----------------------------------------
    void To(Transform &m)
        {
        Basis&basis=m.basis;
        BASIS_M
        m.origin.x=this->Lx;m.origin.y=this->Ly;m.origin.z=this->Lz; 
        }

    }卍Matrix4;
    
//====卍Matrix3====================================
typedef struct 卍Matrix3 :public _Matrix33_
    {
    卍Matrix3():_Matrix33_(){}
    
    explicit 卍Matrix3(Spatial*&sp)//explicit 防止其它类型传参
        {
        Transform m =sp->get_global_transform();Basis&basis=m.basis;
        BASIS_M
        }
    卍Matrix3(Transform&m )//explicit 防止其它类型传参
        {
        Basis&basis=m.basis;
        BASIS_M
        }
    //------------------------------
    卍Matrix3&operator = (Transform&m)
        {
        Basis&basis=m.basis;
        BASIS_M
        return*this;
        }
    //------------------------------
    // 卍Matrix3 operator*(const Transform &t)const 
        // {  
        // 卍Matrix3 M__;
        // M3MulltiF33(this->,t,M__.);
        // return M__;
        // }
    //----------------------------------------
    void To(Transform &m)
        {
        Basis&basis=m.basis;
        M_BASIS
        }
    }卍Matrix3;
    
////////////////////////////////////////////
__forceinline void v_v(_Vector3_*&p,Vector3&v3__)
    {
    if(p!=NULL)p->To(v3__);
    }

    
////END////END////END////END////END////END////END////END////
#endif 

