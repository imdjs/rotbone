
#pragma once
#ifndef __GDN_TRANSFROM_H__
#define __GDN_TRANSFROM_H__

// #include<E:\Godot\Godot_example\GDNative-demos-master\GDNative_rotbone\src_english\GodotLib\Math\MatQuatVec.h>

////////////////////////////////////////////
////吅/////////////////////////////////////////////
static inline void f44_f44(cfloat f44[4][4],float f44__[4][4])
    {
    memcpy(f44__, f44, 4*4*sizeof(float));
    }
    
static inline void f33_f33(cfloat m2[3][3],float f33__[3][3])//my
    {
    memcpy(&f33__[0], &m2[0], 9*sizeof(float));
    }
    
static inline void f33_f44(cfloat m2[3][3],float f33__[4][4]) 
    {
    f33__[0][0] = m2[0][0];f33__[0][1] = m2[0][1];f33__[0][2] = m2[0][2];
    f33__[1][0] = m2[1][0]; f33__[1][1] = m2[1][1]; f33__[1][2] = m2[1][2];
    f33__[2][0] = m2[2][0];f33__[2][1] = m2[2][1]; f33__[2][2] = m2[2][2];
    /*
    f33__[0][3] = 0.0F;f33__[1][3] = 0.0F; f33__[2][3] = 0.0F; 
    f33__[3][0] = 0.0F;f33__[3][1] = 0.0F;f33__[3][2] = 0.0F;f33__[3][3] = 1.0F;
   */
    }
static inline void f44_f33(cfloat f33[4][4],float f33__[3][3])
    {
    f33__[0][0] = f33[0][0];f33__[0][1] = f33[0][1];f33__[0][2] = f33[0][2];//XΦ
    f33__[1][0] = f33[1][0];f33__[1][1] = f33[1][1];f33__[1][2] = f33[1][2];//YΦ
    f33__[2][0] = f33[2][0];f33__[2][1] = f33[2][1];f33__[2][2] = f33[2][2];//ZΦ
    }
    

////END////END////END////END////END////END////END////END////
#endif 

