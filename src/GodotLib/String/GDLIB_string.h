

#ifndef __GDN_STRING_H__
    #define __GDN_STRING_H__
    
#include"E:\Godot\Godot_example\GDNative-demos-master\GDNative_rotbone\src_english\GodotLib\Print\GDLIB_print.h"
#include"E:\Godot\GDNative\include\gen\Node.hpp"
using namespace godot;
// char*nameG[128];
// template<typename T>
// char* nameO(T*o)
char* nameO(const gd Node*o)
    {
    ASSERTR(o==NULL,NULL);ASSERT1R("",&o->get_name()==NULL,NULL);
        return o->get_name().alloc_c_string();
    
    }

char* nameO(const gd Object*o)
    {
    ASSERTR(o==NULL,NULL);
    gd Node*n=(Node*)o;ASSERT1R("",&n->get_name()==NULL,NULL);
    return n->get_name().alloc_c_string();
    }
template<typename T>
char*sType(T o)
    {
    ASSERTR(o==NULL,NULL);
    return o->get_class().alloc_c_string();
    }

template<typename T>
bool bType(T o,char*s类型)
    {
    ASSERTR(o==NULL,false);
    return strcmp(sType(o),s类型)==0;
    }

////END////END////END////END////END////END////END////
#endif


