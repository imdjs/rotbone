
#ifndef _DJS_MATH_V_H_ 
#define _DJS_MATH_V_H_ 
#include<vector>
#include<deque>
using namespace std;

template<typename T>
__forceinline float pow2(const T& f)
    {
    return pow(f,2);
    }
    
//====知3边,求角==========================
static __forceinline float getAngleOfTri(cfloat&a,cfloat&b,cfloat&c)
    {//cos C=(a^2+b^2-c^2)/2*a*b;
    return acos(  (pow2(a)+pow2(b)-pow2(c))/(2*a*b )  );//求C角
    }
//====知2边1角,求边==========================
static __forceinline float getLenOfTri(cfloat&a,cfloat&b,cfloat&angleC)
    {//c^2=a^2 + b^2 - 2*a*b*cos C;
    return sqrt(  pow2(a)+pow2(b) - 2*a*b*cos(angleC)  );//求cLen
    }    
//====知2边1角,求Other1角==========================
static __forceinline float getAngleOfTri2(cfloat&a,cfloat&b,cfloat&angleC)
    {
    float C=getLenOfTri(a,b,angleC);
    return asin( b/ (C/sin(angleC) ));//求B角
    }
    
template<typename T>inline
bool inVector(T t,const vector<T>&Vt)
    {
    if(Vt.empty())return false;
    vector<T>::const_iterator itEnd=Vt.end();
    if(find(Vt.begin(),itEnd,t)!=itEnd)//找到
        return true;
    return false;
    }
    
template<typename T>inline
bool inVector(T t,const deque<T>&Vt)
    {
    if(Vt.empty())return false;
    deque<T>::const_iterator itEnd=Vt.end();
    if(find(Vt.begin(),itEnd,t)!=itEnd)//找到
        return true;
    return false;
    }
    
//========================================
template<typename T>
bool in(const T&iFind,const vector<T>& Vi)
    {
    for(const auto&i:Vi)
        {
        // printf("i被找0= %s,%s,%d\n",iFind,i被找,iFind==i被找);//★★
        if(卩二二(iFind,i))
            return true;
        }
    return false;
    }
    
////VECTOR///////////////////////////////////////
template<typename T>
__forceinline T  len1(const T f3[3])
    {
    T f=sqrt(pow2(f3[0])+pow2(f3[1])+pow2(f3[2]));
    return f;
    }
template<typename T>
__forceinline T  len2(const T f3[2])
    {
    T f=sqrt(pow2(f3[0])+pow2(f3[1]));
    return f;
    }
    
template<typename T>
__forceinline void Swap(T &t1,T &t2)
    {
    T temp=t1;t1=t2;t2=temp;
    }
    
    
inline void Mullti(cfloat f3[3],float f,float f3R__[3])
    { f3R__[0] = f3[0]*f;f3R__[1]=f3[1]*f;f3R__[2] = f3[2]*f; }
inline void Mullti(cfloat v1[3], cfloat v2[3],float r__[3])
    {
	r__[0] = v1[0] * v2[0];r__[1] = v1[1] * v2[1];r__[2] = v1[2] * v2[2];
    }
inline void Mullti(cdouble v1[3], cdouble v2[3],double r__[3])
    {
	r__[0] = v1[0] * v2[0];r__[1] = v1[1] * v2[1];r__[2] = v1[2] * v2[2];
    }
    

static inline void Minus(cfloat a[3], cfloat b[3],float f3R__[3] )
    {f3R__[0] = a[0] - b[0];f3R__[1] = a[1] - b[1]; f3R__[2] = a[2] - b[2]; } 
static inline void Minus(cdouble a[3], cdouble b[3],float f3R__[3] )
    {f3R__[0] = a[0] - b[0];f3R__[1] = a[1] - b[1]; f3R__[2] = a[2] - b[2]; }
static inline void Minus2(cfloat a[2], cfloat b[2],float f2R__[2] )
    {f2R__[0] = a[0] - b[0];f2R__[1] = a[1] - b[1]; }
static inline void Minus2(cvector<double>&a,cvector<double>&b,float f2R__[2] )
    {f2R__[0] = a[0] - b[0];f2R__[1] = a[1] - b[1]; }
static inline void Puls2(cfloat a[2], cfloat b[2],float f2R__[2])
    { f2R__[0] = a[0] + b[0];f2R__[1] = a[1] + b[1]; }
static inline void Puls2(cvector<double>&a,cvector<double>&b,float f2R__[2])
    { f2R__[0] = a[0] + b[0];f2R__[1] = a[1] + b[1]; }    
static inline void Puls(cfloat a[3], cfloat b[3],float f3R__[3])
    { f3R__[0] = a[0] + b[0];f3R__[1] = a[1] + b[1]; f3R__[2] = a[2] + b[2]; }
static inline void Puls(cfloat a[3], cfloat b[3],cfloat c[3],float f3R__[3])
    { f3R__[0] = a[0] + b[0]+ c[0];f3R__[1] = a[1] + b[1]+ c[1]; f3R__[2] = a[2] + b[2]+c[2]; }

    
////END////END////END////END////END////END////END////END////
#endif 









