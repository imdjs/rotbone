
#include<vector>
#include<deque>

Skeleton *armG = NULL, *armPreG = NULL;
int iBoneNumG = -1, iBoneNumPreG = -1, idxAG;
Vector2 v2WindowG, v2MouseLocG;
_Vector3_ vMouseDepthG, vMouseDepthPreG, *vpMousePreG = NULL, ZaxisG, v3MoveG;
_Vector3_ vCam_boneG, vCam_bone2G, vBoneLocG, vCamLocG;
float __boneG, fCam__boneG, angleG, angle2G, __ScreenG = 0;
bool bActivePluginG = false, bPressRG = false, bPressFinishG = false;
int iPressXyzG = -1;
const Transform t0G(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0);
Transform tBoneInitG;
Texture texIconG, texIcon2G;
Node *nSceneG = NULL;
Spatial *spMouseG = NULL;
OS *osG = NULL;
Viewport *vpG = NULL;
// CanvasItem *ciG = NULL;

typedef struct symbol_bone
{
    int iSelf = -1;
    int iParent = -2;
    int iChild = -1;
    float len = 0.0f;
    deque<int> child_arr;
} symbol_bone;

vector<symbol_bone>VboneG;vector<_Vector3_>VboneLocG;

class RotateBones : public EditorPlugin
{
    GODOT_CLASS(RotateBones, EditorPlugin)
  private:
    ImmediateGeometry *ig = NULL;
    SpatialMaterial *sm = NULL;

  public:
    static void _register_methods();

    RotateBones();
    ~RotateBones() {}
    void __on_pressed(const Texture *texIconG, const Texture *texIcon2G);
    void __LoadDll();
    bool __UnloadDll();
    void _init() { printf("●● __RotBones__._init= \n"); };
    void _input(const InputEventKey *ie);
    void _process(float delta);
    void _ready()
    {
        printf("●● _ready= \n");
        if (osG == NULL)
        {
            osG = OS::get_singleton();
        }
        // PRINT5("□ready", osG->get_screen_count(), osG->get_current_screen(), osG->get_screen_size(osG->get_current_screen()), osG->get_real_window_size(), osG->get_window_size());
    }
    void _enter_tree();
    void _exit_tree();
    Skeleton *handles(Object *object);
    void forward_spatial_gui_input(Camera *camera, InputEventMouseButton *ie);
    void edit();
    void clear() {  }
};

void RotateBones::_register_methods()
{
    ClassDB::bind_method(D_METHOD("handles", &RotateBones::handles);
    ClassDB::bind_method(D_METHOD("_enter_tree", &RotateBones::_enter_tree);
    ClassDB::bind_method(D_METHOD("_exit_tree", &RotateBones::_exit_tree);
    ClassDB::bind_method(D_METHOD("_ready", &RotateBones::_ready);
    ClassDB::bind_method(D_METHOD("edit", &RotateBones::edit);
    ClassDB::bind_method(D_METHOD("forward_spatial_gui_input", &RotateBones::forward_spatial_gui_input);
    ClassDB::bind_method(D_METHOD("_input", &RotateBones::_input);
    ClassDB::bind_method(D_METHOD("__on_pressed", &RotateBones::__on_pressed);
    // ClassDB::bind_method(D_METHOD("__LoadDll", &RotateBones::__LoadDll);
    // ClassDB::bind_method(D_METHOD("__UnloadDll", &RotateBones::__UnloadDll);
    ClassDB::bind_method(D_METHOD("clear", &RotateBones::clear);
}

RotateBones::RotateBones()
{
}

void RotateBones::_enter_tree()
{
    bActivePluginG = true;
}
void RotateBones::_exit_tree()
{
}

/* void RotateBones::__LoadDll()
{
    PRINT0("Θ __LoadDll ");
} */

/* bool RotateBones::__UnloadDll()
{
    PRINT0("Θ __UnloadDll ");
    if (hmSelfG)
    {
        PRINT2(, hmSelfG, hsSelfG);
        _unLoadDll();
    }
    return (hmSelfG == NULL) ? true : false;
} */

void RotateBones::__on_pressed(const Texture *texIconG, const Texture *texIcon2G)
{
    bActivePluginG = !bActivePluginG;
    {
        __UnloadDll();
    }
}

static __forceinline void __UpdatePose(symbol_bone &boneA)
{
    for (const auto &ξ : boneA.child_arr)
    {
        VboneLocG[ξ] = armG->get_bone_global_pose(ξ).origin;
        __UpdatePose(VboneG[ξ]);
    }
}

Skeleton *RotateBones::handles(Object *object)
{
    oAG = object;
    // PRINT2("  handles ", sType(object), nameO(object), object->get_instance_id(), oAG->has_method("get_class"), oAG->is_queued_for_deletion());
    if (oAG)
    {
        if (nSceneG == NULL)
        {
            FindRoot(oAG, nSceneG);
            // PRINT1("罒", nSceneG, (int)vpG);
        }
        if (in(sType(oAG), {"MeshInstance", "Skeleton"}))
        {
            Transform m = cast_to<Spatial>(oAG)->get_global_transform();
            // PRINT1("", m);
        }
        if (卩二二(sType(oAG), "Skeleton"))
        {
            armG = cast_to<Skeleton>(oAG);
            if (armG)
            {
                // PRINT1("亖", armG->get_bone_count());
            }
            return armG;
        }
    }

    return NULL;
}

void RotateBones::edit()
{
    if (osG == NULL)
    {
        osG = OS::get_singleton();
    }
    // PRINT5("□", osG->get_screen_count(), osG->get_current_screen(), osG->get_screen_size(osG->get_current_screen()), osG->get_real_window_size(), osG->get_window_size());
    __ScreenG = osG->get_window_size().x;
    if (armG)
    {
        // PRINT0("■■ edit ", armG->name, armG);
        float __per = 0;
        int iCount = 5;
        卍Matrix4 m = armG->get_global_transform();
        iBoneNumG = armG->get_bone_count();
        // PRINT2(, iBoneNumG, iBoneNumPreG);
        {
            armPreG = armG;
            VboneLocG.resize(iBoneNumG);
            iBoneNumPreG = iBoneNumG;
            VboneG.resize(iBoneNumG);
            For(iBoneNumG, i)
            {
                VboneLocG[i] = (m * armG->get_bone_global_pose(i)).Loc();
                VboneG[i] = symbol_bone();
                VboneG[i].iSelf = i;
                VboneG[i].iParent = armG->get_bone_parent(i);
                if (VboneG[i].iParent > -1)
                {
                    symbol_bone &boneP = VboneG[VboneG[i].iParent];
                    boneP.iChild = i;
                    if (inVector(i, boneP.child_arr) == false)
                    {
                        boneP.child_arr.push_back(i);
                    }
                    boneP.len = (VboneLocG[i] - VboneLocG[VboneG[i].iParent]).len();
                    if (iCount > 0)
                    {
                        __per += boneP.len;
                        --iCount;
                    }
                }
            }
            __boneG = __per = __per / (5 - iCount); //PRINT1(,__per);
            For(iBoneNumG, i)
            {
                if (VboneG[i].iChild == -1)
                {
                    VboneG[i].len = __per;
                }
                // PRINT2("无子", i, VboneG[i].len);
            }
        }
    }
}

void RotateBones::_input(const InputEventKey *ie)
{
    if (armG == NULL)
    {
        return;
    }
    if (bType(ie, "InputEventKey"))
    {
        if (__bPressKey(ie, KEY_R))
        {
            bPressRG = true;
        }
        else if (ie->get_scancode_with_modifiers() == 67108946)
        {
            armG->set_bone_pose(idxAG, t0G);
            bPressFinishG = bPressRG = false;
            iPressXyzG = -1;
            vpMousePreG = NULL;
            symbol_bone &boneA = VboneG[idxAG];
            __UpdatePose(boneA);
        }
        if (bPressRG)
        {

            if (__bPressKey(ie, KEY_X))
            {
                iPressXyzG = 0;
                armG->set_bone_global_pose(idxAG, tBoneInitG);
                ZaxisG = X(tBoneInitG.basis);
                vMouseDepthPreG = vMouseDepthG = v2MouseLocG;
            }
            else if (__bPressKey(ie, KEY_Y))
            {
                iPressXyzG = 1;
                armG->set_bone_global_pose(idxAG, tBoneInitG);
                ZaxisG = Y(tBoneInitG.basis);
                vMouseDepthPreG = vMouseDepthG = v2MouseLocG;
            }
            else if (__bPressKey(ie, KEY_Z))
            {
                iPressXyzG = 2;
                armG->set_bone_global_pose(idxAG, tBoneInitG);
                ZaxisG = Z(tBoneInitG.basis);
                vMouseDepthPreG = vMouseDepthG = v2MouseLocG;
            }
            if (iPressXyzG != -1)
                __DRAWig(nSceneG, this, this->ig, this->sm, &_Vector3_(tBoneInitG.origin), &_Vector3_(tBoneInitG.origin - Z(tBoneInitG.basis)), &_Vector3_(tBoneInitG.origin + ZaxisG), &_Vector3_(tBoneInitG.origin - ZaxisG));
        }
    }
}

void RotateBones::forward_spatial_gui_input(Camera *camera, InputEventMouseButton *ie)
{
    if (armG == NULL)
    {
        return;
    }
    if (bType(ie, "InputEventMouseButton"))
    {
        if (__bPressMouse(ie, BUTTON_MIDDLE))
        {
            // PRINT0("BUTTON_MIDDLE");
            Vector2 v2MouseLocG = ie->get_position();
            vMouseDepthG = camera->project_ray_normal(v2MouseLocG); //PRINT1("",vMouseDepthG);
            angleG = 0;
            angle2G = ㄥ180;
            idxAG = -1;
            vCamLocG = camera->get_camera_transform().origin; //_Vector3_ To镜Z=camera->get_global_transform().basis.z;
            For(iBoneNumG, i)
            {
                vBoneLocG = VboneLocG[i];
                vCam_boneG = vBoneLocG - vCamLocG;
                angleG = vMouseDepthG.angle(vCam_boneG);
                if (angleG < angle2G)
                {
                    angle2G = angleG;
                    idxAG = i;
                    vCam_bone2G = vCam_boneG;
                }
            }
            if (idxAG != -1)
            {
                fCam__boneG = vCam_bone2G.len();
            }
            else
            {

                fCam__boneG = 0;
            }
            // PRINT3("●", idxAG, angle2G, armG->get_bone_name(idxAG));
            Transform tBone = armG->get_bone_global_pose(idxAG);
            __DRAWig(nSceneG, this, this->ig, this->sm, &_Vector3_(tBone.origin), &_Vector3_(tBone.origin - Z(tBone.basis)));
            // PRINT2("draw", vCam_bone2G, (int)this->ig, nameO(this->ig));
        }
        else if (__bPressMouse(ie, BUTTON_LEFT))
        {
            bPressFinishG = true;
            // PRINT1("", bPressFinishG);
            if (bPressRG && bPressFinishG)
            {
                {
                    bPressFinishG = bPressRG = false;
                    iPressXyzG = -1;
                    vpMousePreG = NULL;
                    symbol_bone &boneA = VboneG[idxAG];
                    __UpdatePose(boneA);
                    // PRINT1("→→→ie==", ie);
                    return;
                }
            }
        }
    }
    else if (bType(ie, "InputEventMouseMotion"))
    {
        if (bPressRG == true)
        {
            v2MouseLocG = ie->get_position();
            _Vector3_ vCross;
            Transform tBone, tBoneChild;
            if (iPressXyzG == -1)
            {
                vMouseDepthG = camera->project_ray_normal(v2MouseLocG);
                vMouseDepthG = vMouseDepthG._Normalize() * fCam__boneG + camera->get_translation();
                if (vpMousePreG == NULL)
                {
                    vMouseDepthPreG = vMouseDepthG;
                    vpMousePreG = &vMouseDepthPreG;
                    tBoneInitG = armG->get_bone_global_pose(idxAG);
                    if (VboneG[idxAG].iChild != -1)
                    {
                        tBoneChild = armG->get_bone_global_pose(VboneG[idxAG].iChild);
                        ZaxisG = tBoneInitG.origin - tBoneChild.origin;
                    }
                    else
                    {
                        if (VboneG[idxAG].iParent != -1)
                        {
                            ZaxisG = armG->get_bone_global_pose(VboneG[idxAG].iParent).origin - tBoneInitG.origin;
                        }

                        else
                        {
                            ZaxisG = Z(tBoneChild.basis) + tBoneChild.origin;
                        }
                    }
                    // PRINT2("Z", ZaxisG, VboneG[idxAG].iParent);
                    return;
                }
                v3MoveG = vMouseDepthG - vMouseDepthPreG;
                // PRINT1("鼠", v3MoveG);
                vCross = -ZaxisG.cross(v3MoveG)._Normalize();
                const float &__A = VboneG[idxAG].len, fMoveG = v3MoveG.len();
                if (fMoveG < 0.008)
                {

                    return;
                }
                float angleC = ㄥ厶2(__A, fMoveG, v3MoveG.angle(ZaxisG));
                // PRINT5("len", idxAG, __A, fMoveG, v3MoveG.angle(ZaxisG), angleC);
                tBone = tBoneInitG;
                tBone.rotate_basis(vCross.v3(), angleC);
            }
            else
            {
                vMouseDepthG = v2MouseLocG;
                if (vpMousePreG == NULL)
                {
                    vMouseDepthPreG = vMouseDepthG;
                    vpMousePreG = &vMouseDepthPreG;

                    return;
                }
                v3MoveG = vMouseDepthG - vMouseDepthPreG;
                vMouseDepthPreG = vMouseDepthG;
                int iLR = (v3MoveG.x > 0) ? -1 : 1;
                float len = v3MoveG.len() * iLR;
                if (len == 0)
                {

                    return;
                }
                float angleC = len / __ScreenG * 10;
                tBone = armG->get_bone_global_pose(idxAG);
                tBone.rotate_basis(ZaxisG.v3(), angleC);
            }
            armG->set_bone_global_pose(idxAG, tBone);
        }
    }
    return;
}
