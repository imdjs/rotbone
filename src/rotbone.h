
#ifndef __ROTBONE_H__
    #define __ROTBONE_H__


Skeleton*armG=NULL,*arm上次G=NULL;
int i骨数G=-1,i骨数preG=-1,ξAG;
Vector2 v2窗口G,v2鼠屏G; 
卍Vector3  丅鼠深G,丅鼠深PreG,*Ψ丅鼠标PreG=NULL,Z轴G,乛乛G;
卍Vector3 镜乛boneG,镜乛bone小G,丅BoneG,丅CamG;
float 冖BoneG,镜冖骨G,ㄥG,ㄥ小G,冖屏幕宽G=0;
bool b激活插件G=false,b按下rG=false,b按下完成G=false;int i按下xyzG=-1;//0 x,1y,2z
const Transform t0G(1,0,0,0,1,0,0,0,1,0,0,0);
Transform t骨初始G;
Texture texIconG,texIcon2G;
Node*n场景G=NULL;Spatial*sp鼠G=NULL;
OS*osG=NULL;Viewport*vpG=NULL;CanvasItem*ciG=NULL;

typedef struct 卍Bone
    {
    int ξSelf= -1;
    int ξ父= -2;
    int ξ子=-1;//第一个子
    float 冖=0.0f;
    deque<int> Vξ子;
    // 卍Bone(){}
    }卍Bone;
    
VECTOR(卍Bone,VboneG);
VECTOR(卍Vector3,V丅BoneG);

// ImmediateGeometry *igImmediateGeometryG=NULL;//★★? void __cdecl _err_print_error









////END////END////END////END////END////END////END////END////
#endif


