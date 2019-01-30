#ifndef __GDN_PRINT_H__
#define __GDN_PRINT_H__



/* static void PRINTa(Vector3&v3){printf(" [%f  %f  %f]",v3.x,v3.y,v3.z);}
static void PRINTa(_Vector3_&v3){printf(" [%f  %f  %f]",v3.x,v3.y,v3.z);}
static void PRINTa(Vector2&v3){printf(" [%f  %f]",v3.x,v3.y);}
static void PRINTa(Rect2&v3){printf(" pos[%f  %f],size[%f  %f]",v3.pos.x,v3.pos.y,v3.size.x,v3.size.y);}
// static void PRINTa(Vector3&v3){printf(" [%lf,%lf,%lf]",v3.x,v3.y,v3.z);}
// static void PRINTa(Transform &m){printf(" basis[%f  %f  %f][%f  %f  %f][%f  %f  %f]\n origin[%f  %f  %f]",m.basis.[0].x,m.basis[0].y,m.basis[0].z,m.basis[1].x,m.basis[1].y,m.basis[1].z,m.basis[2].x,m.basis[2].y,m.basis[2].z,m.origin.x,m.origin.y,m.origin.z);}
// static void PRINTa(Transform &m){printf(" basis[%f  %f  %f][%f  %f  %f][%f  %f  %f], Loc origin[%f  %f  %f]\n ",m.basis.x.x,m.basis.x.y,m.basis.x.z,m.basis.y.x,m.basis.y.y,m.basis.y.z,m.basis.z.x,m.basis.z.y,m.basis.z.z,m.origin.x,m.origin.y,m.origin.z);}//Mullti
static void PRINTa(Transform &m){printf(" basis[%f  %f  %f][%f  %f  %f][%f  %f  %f], Loc origin[%f  %f  %f]\n ",m.basis.elements[0].x,m.basis.elements[0].y,m.basis.elements[0].z,m.basis.elements[1].x,m.basis.elements[1].y,m.basis.elements[1].z,m.basis.elements[2].x,m.basis.elements[2].y,m.basis.elements[2].z,m.origin.x,m.origin.y,m.origin.z);}
static void PRINTa(卍Matrix4&m){printf("M4 basis[%f  %f  %f][%f  %f  %f][%f  %f  %f], Loc origin[%f  %f  %f]\n ",m.Xx,m.Xy,m.Xz,m.Yx,m.Yy,m.Yz,m.Zx,m.Zy,m.Zz,m.Lx,m.Ly,m.Lz);}

static void PRINTa(InputEventMouseButton*ie){ASSERTR(ie==NULL);  printf("%s",sType(ie));}
static void PRINTa(Node*node){ASSERTR(node==NULL);  printf("%s",node->get_name().alloc_c_string());}
static void PRINTa(Object*object){ASSERTR(object==NULL);  printf("%s",((Node*)object)->get_name().alloc_c_string());}
static void PRINTa(String*str){ASSERTR(str==NULL);  printf("%s",str->alloc_c_string());}
static void PRINTa(String&str){printf("%s",str.alloc_c_string());} */
#define PRINTIF
#define PRINT0
#define PRINT1
#define PRINT2
#define PRINT3
#define PRINT4
#define PRINT5
#define PRINT6
#define PRINT7
#define PRINT8

#define ASSERTR
#define ASSERT1R
/* #ifdef __PRINT__
    #ifdef __PRINT_GD__
        #undef PRINTIF
        #undef PRINT0
        #undef PRINT1
        #undef PRINT2
        #undef PRINT3
        #undef PRINT4
        #undef PRINT5
        #undef PRINT6
        #undef PRINT7
        #undef PRINT8
        //------------------------------
    #endif
#endif */

//==============================
/* static static void PTvector(const char s名称[],const vector<Vector3>&Vi,cint& i限制=-1,cint& i行=-1,const char*s文件=NULL)
    {int i,j;  
    if(s文件)
        printf("----vector %s -------(%d)-----------------行:%d -------文件:%s\n",s名称,Vi.size(),i行,s卝('\\',s文件,false,false,true));
    else
        printf("----vector %s -------(%d)-----------------行:%d \n",s名称,Vi.size(),i行);        
    for(i=0; i < Vi.size(); ++i )  
        {if(i限制>0&&i限制<i){printf(" \n\n");return ;}
        printf(" 〔 %f · %f · %f 〕",Vi[ i ].x,Vi[ i ].y,Vi[ i ].z);
        //PRINTa(Vi[ i ]);
        }
    if(Vi.empty())
        printf("  =[]");
    printf(" \n\n");
    } */





 // #include<print\DJS0_print.h>

////END////END////END////END////END////END////END////END////
#endif



