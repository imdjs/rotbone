
#ifndef __ROTBONE_H__
    #define __ROTBONE_H__
#include<vector>
#include<deque>
using namespace std;
Skeleton*armG=NULL,*armPreG=NULL;
int iBoneNumG=-1,iBoneNumPreG=-1,idxAG;
Vector2 v2WindowG,v2MouseLocG; 
_Vector3_  vMouseDepthG,vMouseDepthPreG,*vpMousePreG=NULL,ZaxisG,v3MoveG;
_Vector3_ vCam_boneG,vCam_bone2G,vBoneLocG,vCamLocG;
float __boneG,fCam__boneG,angleG,angle2G,__ScreenG=0;
bool bActivePluginG=false,bPressRG=false,bPressFinishG=false;int iPressXyzG=-1;//0 x,1y,2z
const Transform t0G(1,0,0,0,1,0,0,0,1,0,0,0);
Transform tBoneInitG;
Texture texIconG,texIcon2G;
Node*nSceneG=NULL;Spatial*spMouseG=NULL;
OS*osG=NULL;Viewport*vpG=NULL;//CanvasItem*ciG=NULL;

typedef struct symbol_bone
    {
    int iSelf= -1;
    int iParent= -2;
    int iChild=-1;//第一个子
    float len=0.0f;
    deque<int> child_arr;
    // symbol_bone(){}
    }symbol_bone;
    

vector<symbol_bone>VboneG;vector<_Vector3_>VboneLocG;
// ImmediateGeometry *igImmediateGeometryG=NULL;//★★? void __cdecl _err_print_error









////END////END////END////END////END////END////END////END////
#endif


