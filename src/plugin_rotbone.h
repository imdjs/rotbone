#ifndef __ROTBONE_H__
#define __ROTBONE_H__

Skeleton *armG = NULL, *arm上次G = NULL;
int i骨数G = -1, i骨数preG = -1, ξAG;
Vector2 v2窗口G, v2鼠屏G;
卍Vector3 丅鼠深G, 丅鼠深PreG, *Ψ丅鼠标PreG = NULL, Z轴G, 乛乛G;
卍Vector3 镜乛boneG, 镜乛bone小G, 丅BoneG, 丅CamG;
float 冖BoneG, 镜冖骨G, ㄥG, ㄥ小G, 冖屏幕宽G = 0;
bool b激活插件G = false, b按下rG = false, b按下完成G = false;
int i按下xyzG = -1;
const Transform t0G(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0);
Transform xform;
Texture texIconG, texIcon2G;
Node *node_g = NULL;
Spatial *spatial_mouse = NULL;
OS *osG = NULL;
Viewport *vpG = NULL;
CanvasItem *ciG = NULL;

typedef struct symbol_bone
{
	int self = -1;
	int parent = -2;
	int child = -1;
	float 冖 = 0.0f;
	deque<int> child_arr;
} symbol_bone;

VECTOR(symbol_bone, VboneG);
VECTOR(卍Vector3, V丅BoneG);
#endif