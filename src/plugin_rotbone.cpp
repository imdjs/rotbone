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
        PRINT5("□ready", osG->get_screen_count(), osG->get_current_screen(), osG->get_screen_size(osG->get_current_screen()), osG->get_real_window_size(), osG->get_window_size());
    }
    void _enter_tree();
    void _exit_tree();
    Skeleton *handles(Object *object);
    void forward_spatial_gui_input(Camera *camera, InputEventMouseButton *ie);
    void edit();
    void clear() { PRINT0(〇 clear-- ------------------------); }
};

void RotateBones::_register_methods()
{
    注册函数(RotateBones, handles);
    注册函数(RotateBones, _enter_tree);
    注册函数(RotateBones, _exit_tree);
    注册函数(RotateBones, _ready);
    注册函数(RotateBones, edit);
    注册函数(RotateBones, forward_spatial_gui_input);
    注册函数(RotateBones, _input);
    注册函数(RotateBones, __on_pressed);
    注册函数(RotateBones, __LoadDll);
    注册函数(RotateBones, __UnloadDll);
    注册函数(RotateBones, clear);
}

RotateBones::RotateBones()
{
}

void RotateBones::_enter_tree()
{
    b激活插件G = true;
}
void RotateBones::_exit_tree()
{
}

void RotateBones::__LoadDll()
{
    PRINT0("Θ __LoadDll ");
}

bool RotateBones::__UnloadDll()
{
    PRINT0("Θ __UnloadDll ");
    if (hm自身G)
    {
        PRINT2(, hm自身G, hs自身G);
        Δ卸载自身();
    }
    return (hm自身G == NULL) ? true : false;
}

void RotateBones::__on_pressed(const Texture *texIconG, const Texture *texIcon2G)
{
    b激活插件G = !b激活插件G;
    {
        __UnloadDll();
    }
}

static __forceinline void ΔUpdatePoseΘ(卍Bone &boneA)
{
    for (const auto &ξ : boneA.Vξ子)
    {
        V丅BoneG[ξ] = armG->get_bone_global_pose(ξ).origin;
        ΔUpdatePoseΘ(VboneG[ξ]);
    }
}

Skeleton *RotateBones::handles(Object *object)
{
    oAG = object;
    PRINT2("  handles ", sType(object), nameO(object), object->get_instance_id(), oAG->has_method("get_class"), oAG->is_queued_for_deletion());
    if (oAG)
    {
        if (n场景G == NULL)
        {
            寻根(oAG, n场景G);
            PRINT1("罒", n场景G, (int)vpG);
        }
        if (in(sType(oAG), {"MeshInstance", "Skeleton"}))
        {
            Transform m = cast_to<Spatial>(oAG)->get_global_transform();
            PRINT1("", m);
        }
        if (卩二二(sType(oAG), "Skeleton"))
        {
            armG = cast_to<Skeleton>(oAG);
            if (armG)
            {
                PRINT1("亖", armG->get_bone_count());
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
    PRINT5("□", osG->get_screen_count(), osG->get_current_screen(), osG->get_screen_size(osG->get_current_screen()), osG->get_real_window_size(), osG->get_window_size());
    冖屏幕宽G = osG->get_window_size().x;
    if (armG)
    {
        PRINT0("■■ edit ", armG->name, armG);
        float 冖per = 0;
        int iCount = 5;
        卍Matrix4 m = armG->get_global_transform();
        i骨数G = armG->get_bone_count();
        PRINT2(, i骨数G, i骨数preG);
        {
            arm上次G = armG;
            V丅BoneG.resize(i骨数G);
            i骨数preG = i骨数G;
            VboneG.resize(i骨数G);
            For(i骨数G, i)
            {
                V丅BoneG[i] = (m * armG->get_bone_global_pose(i)).丅();
                VboneG[i] = 卍Bone();
                VboneG[i].ξSelf = i;
                VboneG[i].ξ父 = armG->get_bone_parent(i);
                if (VboneG[i].ξ父 > -1)
                {
                    卍Bone &boneP = VboneG[VboneG[i].ξ父];
                    boneP.ξ子 = i;
                    if (罒Vector(i, boneP.Vξ子) == false)
                    {
                        boneP.Vξ子.push_back(i);
                    }
                    boneP.冖 = (V丅BoneG[i] - V丅BoneG[VboneG[i].ξ父]).冖();
                    if (iCount > 0)
                    {
                        冖per += boneP.冖;
                        --iCount;
                    }
                }
            }
            冖BoneG = 冖per = 冖per / (5 - iCount); //PRINT1(,冖per);
            For(i骨数G, i)
            {
                if (VboneG[i].ξ子 == -1)
                {
                    VboneG[i].冖 = 冖per;
                }
                PRINT2("无子", i, VboneG[i].冖);
            }
        }
    }
}

void RotateBones::_input(const InputEventKey *ie)
{
    if (armG == NULL) {
        return;
    }
    if (bType(ie, "InputEventKey"))
    {
        if (卩按下键盘(ie, KEY_R))
        {
            b按下rG = true;
        }
        else if (ie->get_scancode_with_modifiers() == 67108946)
        {
            armG->set_bone_pose(ξAG, t0G);
            b按下完成G = b按下rG = false;
            i按下xyzG = -1;
            Ψ丅鼠标PreG = NULL;
            卍Bone &boneA = VboneG[ξAG];
            ΔUpdatePoseΘ(boneA);
        }
        if (b按下rG)
        {

            if (卩按下键盘(ie, KEY_X))
            {
                i按下xyzG = 0;
                armG->set_bone_global_pose(ξAG, t骨初始G);
                Z轴G = X(t骨初始G.basis);
                丅鼠深PreG = 丅鼠深G = v2鼠屏G;
            }
            else if (卩按下键盘(ie, KEY_Y))
            {
                i按下xyzG = 1;
                armG->set_bone_global_pose(ξAG, t骨初始G);
                Z轴G = Y(t骨初始G.basis);
                丅鼠深PreG = 丅鼠深G = v2鼠屏G;
            }
            else if (卩按下键盘(ie, KEY_Z))
            {
                i按下xyzG = 2;
                armG->set_bone_global_pose(ξAG, t骨初始G);
                Z轴G = Z(t骨初始G.basis);
                丅鼠深PreG = 丅鼠深G = v2鼠屏G;
            }
            if (i按下xyzG != -1)
                画画ig(n场景G, this, this->ig, this->sm, &卍Vector3(t骨初始G.origin), &卍Vector3(t骨初始G.origin - Z(t骨初始G.basis)), &卍Vector3(t骨初始G.origin + Z轴G), &卍Vector3(t骨初始G.origin - Z轴G));
        }
    }
}

void RotateBones::forward_spatial_gui_input(Camera *camera, InputEventMouseButton *ie)
{
    if (armG == NULL)
        return; //b激活插件G==false or
    if (bType(ie, "InputEventMouseButton"))
    {
        if (卩按下鼠标(ie, BUTTON_MIDDLE))
        {
            PRINT0("BUTTON_MIDDLE");
            Vector2 v2鼠屏G = ie->get_position();
            丅鼠深G = camera->project_ray_normal(v2鼠屏G); //PRINT1("",丅鼠深G);
            ㄥG = 0;
            ㄥ小G = ㄥ180;
            ξAG = -1;
            丅CamG = camera->get_camera_transform().origin; //卍Vector3 乛镜Z=camera->get_global_transform().basis.z;
            For(i骨数G, i)
            {
                丅BoneG = V丅BoneG[i];
                镜乛boneG = 丅BoneG - 丅CamG;
                ㄥG = 丅鼠深G.Λ(镜乛boneG);
                if (ㄥG < ㄥ小G)
                {
                    ㄥ小G = ㄥG;
                    /
                        ξAG = i;
                    镜乛bone小G = 镜乛boneG;
                }
            }
            if (ξAG != -1)
                镜冖骨G = 镜乛bone小G.冖();
            else
                镜冖骨G = 0;
            PRINT3("●", ξAG, ㄥ小G, armG->get_bone_name(ξAG));
            Transform t骨 = armG->get_bone_global_pose(ξAG);
            画画ig(n场景G, this, this->ig, this->sm, &卍Vector3(t骨.origin), &卍Vector3(t骨.origin - Z(t骨.basis)));
            PRINT2("draw", 镜乛bone小G, (int)this->ig, nameO(this->ig));
        }
        else if (卩按下鼠标(ie, BUTTON_LEFT))
        {
            b按下完成G = true;
            PRINT1("", b按下完成G);
            if (b按下rG && b按下完成G)
            {
                {
                    b按下完成G = b按下rG = false;
                    i按下xyzG = -1;
                    Ψ丅鼠标PreG = NULL;
                    卍Bone &boneA = VboneG[ξAG];
                    ΔUpdatePoseΘ(boneA);
                    PRINT1("→→→ie==", ie);
                    return;
                }
            }
        }
    }
    else if (bType(ie, "InputEventMouseMotion"))
    {
        if (b按下rG == true)
        {
            v2鼠屏G = ie->get_position();
            卍Vector3 vΓ;
            Transform t骨, t骨子;
            if (i按下xyzG == -1)
            {
                丅鼠深G = camera->project_ray_normal(v2鼠屏G);
                丅鼠深G = 丅鼠深G._工() * 镜冖骨G + camera->get_translation();
                if (Ψ丅鼠标PreG == NULL)
                {
                    丅鼠深PreG = 丅鼠深G;
                    Ψ丅鼠标PreG = &丅鼠深PreG;
                    t骨初始G = armG->get_bone_global_pose(ξAG);
                    if (VboneG[ξAG].ξ子 != -1)
                    {
                        t骨子 = armG->get_bone_global_pose(VboneG[ξAG].ξ子);
                        Z轴G = t骨初始G.origin - t骨子.origin;
                    }
                    else
                    {
                        if (VboneG[ξAG].ξ父 != -1)
                        {
                            Z轴G = armG->get_bone_global_pose(VboneG[ξAG].ξ父).origin - t骨初始G.origin;
                        }

                        else
                        {
                            Z轴G = Z(t骨子.basis) + t骨子.origin;
                        }
                    }
                    PRINT2("Z", Z轴G, VboneG[ξAG].ξ父);
                    return;
                }
                乛乛G = 丅鼠深G - 丅鼠深PreG;
                PRINT1("鼠", 乛乛G);
                vΓ = -Z轴G.Γ(乛乛G)._工();
                const float &冖A = VboneG[ξAG].冖, 冖一乛 = 乛乛G.冖();
                if (冖一乛 < 0.008)
                    return;
                float ㄥC = ㄥ厶2(冖A, 冖一乛, 乛乛G.Λ(Z轴G));
                PRINT5("冖", ξAG, 冖A, 冖一乛, 乛乛G.Λ(Z轴G), ㄥC);
                t骨 = t骨初始G;
                t骨.rotate_basis(vΓ.v3(), ㄥC);
            }
            else
            {
                丅鼠深G = v2鼠屏G;
                if (Ψ丅鼠标PreG == NULL)
                {
                    丅鼠深PreG = 丅鼠深G;
                    Ψ丅鼠标PreG = &丅鼠深PreG;

                    return;
                }
                乛乛G = 丅鼠深G - 丅鼠深PreG;
                丅鼠深PreG = 丅鼠深G;
                int iLR = (乛乛G.x > 0) ? -1 : 1;
                float 冖 = 乛乛G.冖() * iLR;
                if (冖 == 0)
                    return;
                float ㄥC = 冖 / 冖屏幕宽G * 10;
                t骨 = armG->get_bone_global_pose(ξAG);
                t骨.rotate_basis(Z轴G.v3(), ㄥC);
            }
            armG->set_bone_global_pose(ξAG, t骨);
        }
    }
    return;
}
