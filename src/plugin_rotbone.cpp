
// #define __PRINT__



// HMODULE hm罒()
// {
	// MEMORY_BASIC_INFORMATION mbi;
	
	// return ((::VirtualQuery(hm罒, &mbi, sizeof(mbi)) != 0) 
	      // ? (HMODULE) mbi.AllocationBase : NULL);
// }

HMODULE hm自身G=NULL;int i引用计数G=0;
HINSTANCE hs自身G=NULL;
EXC DWORD iΔ卸载自身(PVOID param);
EXC __forceinline void  Δ卸载自身();
////////////////////////////////////////////
class __RotBones__ : public EditorPlugin //EditorPlugin
    {
    GODOT_CLASS(__RotBones__,EditorPlugin)//不能用中文
private:
    ImmediateGeometry*ig=NULL;
    SpatialMaterial *sm=NULL;
public:
    static void _register_methods();

    __RotBones__();
    ~__RotBones__(){}//if(ig){ delete ig;delete sm;}
    void __on_pressed(const Texture*texIconG,const Texture*texIcon2G);
    void __LoadDll();
    bool __UnloadDll();
    //------------------------------
    void _init(){printf("●● __RotBones__._init= \n");};//●●一定要有这个函数,不然会crash
    void _input(const InputEventKey*ie);
    void _process(float delta);
    void _ready()
        {printf("●● _ready= \n");
        if(osG==NULL)
            {osG=OS::get_singleton();}
        PRINT5("□ready",osG->get_screen_count(),osG->get_current_screen(),osG->get_screen_size(osG->get_current_screen()),osG->get_real_window_size(),osG->get_window_size());
        }
    void _enter_tree();
    void _exit_tree(); 
    //----虚函数--------------------------
    Skeleton* handles(Object *object);
    void forward_spatial_gui_input(Camera*camera,InputEventMouseButton*ie);
    void edit();
    void clear(){PRINT0(〇 clear--------------------------);}
    };

////cpp////////////////////////////////////////
void __RotBones__::_register_methods() 
    {
    注册函数(__RotBones__,handles);
    注册函数(__RotBones__,_enter_tree);
    注册函数(__RotBones__,_exit_tree);
    注册函数(__RotBones__,_ready);注册函数(__RotBones__,edit);
    注册函数(__RotBones__,forward_spatial_gui_input);注册函数(__RotBones__,_input);
    注册函数(__RotBones__,__on_pressed);注册函数(__RotBones__,__LoadDll);注册函数(__RotBones__,__UnloadDll);
    注册函数(__RotBones__,clear);
    }

__RotBones__::__RotBones__() 
    {
    }


////////////////////////////////////////////
/* */
void __RotBones__::_enter_tree()
    {{
    // hbcToolbarG=hbc十十(self,"res://icon.png","__on_pressed");
    // for o in hbcToolbarG.get_children():
        // if(o is ToolButton):
            // tbG=o;break;
    // osG=OS::get_singleton();PRINT_1("_enter_tree",osG,d);//●●这个为NULL
    b激活插件G=true;
    }}
//========================================
void __RotBones__::_exit_tree()
    {{return ;
    b激活插件G=false;
    __UnloadDll();
    }}
  
//========================================
void __RotBones__::__LoadDll()
    {{
    PRINT0("Θ __LoadDll ");
    // if(hDLLbone==NULL)hDLLbone=LoadLibrary(sDLL);

    }}
    
bool __RotBones__::__UnloadDll()
    {{
    PRINT0("Θ __UnloadDll ");// terminate();
// return false;
    // hm自身G=GetModuleHandle("main64.dl");
    
    if(hm自身G)
        {PRINT2(,hm自身G,hs自身G);
        Δ卸载自身();
        }
    return (hm自身G==NULL)  ?  true  :  false;

    }}

void __RotBones__::__on_pressed(const Texture*texIconG,const Texture*texIcon2G)
    {{
#ifdef PRINT_HEAD
    printf("『『『 %s \n",s巜charU(__func__));
#endif
    b激活插件G=!b激活插件G;
    // else
        {__UnloadDll();}

    }}
    

//========================================
static __forceinline void  ΔUpdatePoseΘ(卍Bone&boneA)
    {
    // FOR(boneA.Vξ子,SIZE,i)
    for(const auto&ξ:boneA.Vξ子)
        {
        V丅BoneG[ξ]=armG->get_bone_global_pose(ξ).origin;
        ΔUpdatePoseΘ(VboneG[ξ]);
        }
    }
    
 
//====激活物====================================
Skeleton* __RotBones__:: handles(Object*object) 
    {{
    oAG=object;PRINT2("  handles ",sType(object),nameO(object),object->get_instance_id(),oAG->has_method("get_class"),oAG->is_queued_for_deletion());
    if(oAG)// &&(卩二二(sType(oAG),"MeshInstance") 
        {
        if(n场景G==NULL)
            {
            寻根(oAG,n场景G);//,vpG,ciG
            PRINT1("罒",n场景G,(int)vpG);
            }
        if(in(sType(oAG),{"MeshInstance","Skeleton"}))
            {
            Transform m = cast_to<Spatial>(oAG)->get_global_transform();
            PRINT1("",m);
            }
        // Basis*basis=&((Spatial*)object)->get_global_transform().basis;
        // PRINT1("",((Spatial*)object)->get_translation(),basis->x,basis->y,basis->z);
        // PRINT1("",((Spatial*)object)->data.global_transform);
        // PRINT1("?",卩二二(sType(oAG),"Skeleton"));
        if(卩二二(sType(oAG),"Skeleton"))
            {
            // armG=(Skeleton*)oAG;//★★crash
            armG=cast_to<Skeleton>(oAG);
            if(armG)
                {
                // Transform m=armG->get_global_transform();
                //PRINT1("",armG->get_global_transform().get_origin());
                PRINT1("亖",armG->get_bone_count());
                // return NULL;
                // if(n场景G==NULL)
                    // {
                    // n场景G =tscn.get_local_scene();
                    // PRINT1("++n场景G==",n场景G);
                    // }
                }
            return armG;
            }
        }
        
    return NULL;
    }}
    
//========================================
void __RotBones__::edit()
    {{ 
    if(osG==NULL)
        {osG=OS::get_singleton();}
    PRINT5("□",osG->get_screen_count(),osG->get_current_screen(),osG->get_screen_size(osG->get_current_screen()),osG->get_real_window_size(),osG->get_window_size());
    冖屏幕宽G=osG->get_window_size().x;
    // v2窗口G=osG->get_window_size();PRINT2("",v2窗口G.x,v2窗口G.y);,osG->get_window_safe_area()
    // if(vpG)
        // {PRINT3("",vpG->get_size(),vpG->get_visible_rect(),vpG->get_size_override());}
    // if(ciG)
        // {PRINT3("",ciG->get_viewport_rect(),ciG->get_local_mouse_position(),ciG->get_global_mouse_position());}
    if(armG)
        {
        PRINT0("■■ edit ", armG->name,armG);
        //if(i骨数G!=oAG->get_bone_count() and sNameSKG!=oAG->name)//不同骨骼
        float 冖per=0;int  iCount=5;
        卍Matrix4 m=armG->get_global_transform();//PRINT1("●",m);//m.origin=armG->get_translation();
        // PRINT3("◆",armG->data.global_transform,armG->data.rotation,armG->data.scale,armG->get_global_transform().get_origin(),armG->get_translation());
        i骨数G=armG->get_bone_count();PRINT2(,i骨数G,i骨数preG);
        //----如果改变选骨--------------------------
        // if(i骨数G>1 and arm上次G!=armG and i骨数preG!=i骨数G)
            {
            arm上次G=armG;V丅BoneG.resize(i骨数G);i骨数preG=i骨数G;
            VboneG.resize(i骨数G);
            For(i骨数G,i)
                {
                V丅BoneG[i]=( m*armG->get_bone_global_pose(i) ).丅();
                // PRINT2("■",armG->get_bone_global_pose(i),V丅BoneG[i]);//PRINT1("■",armG->get_bone_pose(i));//PRINT1("■",armG->get_bone_custom_pose(i));PRINT1("■",armG->get_bone_transform(i));
                // PRINT1("2",armG->get_bone_global_pose(i));
                VboneG[i]=卍Bone();
                VboneG[i].ξSelf=i;VboneG[i].ξ父=armG->get_bone_parent(i);//PRINT1("parent==",armG->get_bone_name(i),VboneG[i].ξ父);//●●如果没有parent 返回-1;
                // VboneG[i].Vξ子=armG->get_bound_child_nodes_to_bone(i);PRINT1("child==",VboneG[i].Vξ子);//●●这个无效
                //----有父--------------------------
                if(VboneG[i].ξ父>-1)
                    {
                    卍Bone&boneP=VboneG[VboneG[i].ξ父];
                    boneP.ξ子=i;//自己成为child 
                    if(罒Vector(i,boneP.Vξ子)==false)
                        {boneP.Vξ子.push_back(i);//PRINT1("boneP.Vξ子=",boneP.Vξ子);
                        }
                    boneP.冖=(V丅BoneG[i]-V丅BoneG[VboneG[i].ξ父]).冖();
                    //PRINT3("child=",armG->get_bone_name(VboneG[i].ξ父).alloc_c_string(),armG->get_bone_name(i),boneP.冖);
                    if(iCount>0)
                        {
                        冖per+=boneP.冖;
                        --iCount;//4,3,2,1,0;
                        }
                    }
                }
                
                // if(VboneG[i].Vξ子.size()>0)
                    // VboneG[i].ξ子=VboneG[i].Vξ子[0];
                //get_bone_pose get_bone_transform get_bone_global_pose get_bone_custom_pose  get_bone_rest
            //----查找无子bone--------------------------
            冖BoneG=冖per=冖per/(5-iCount);//PRINT1(,冖per);
            For(i骨数G,i)
                {
                if(VboneG[i].ξ子==-1)
                    {VboneG[i].冖=冖per;}PRINT2("无子",i,VboneG[i].冖);
                }
            //PTvector亖亖(V丅BoneG);
            }
        }
        
    }}

//========================================
void __RotBones__::_input(const InputEventKey*ie)
    {{
    if(armG==NULL)return ;//PRINT1("▲ _input==",b激活插件G,ie);b激活插件G==false or 
    // PRINT1("_input",sType(ie));
    // return ;
    if (bType(ie,"InputEventKey"))
        {//PRINT2("_input",b按下rG,b按下完成G);
        //----正在按R--------------------------
        if(卩按下键盘(ie,KEY_R))
            {
            b按下rG = true;

            }
        //----归零pose --------------------------
        else if(ie->get_scancode_with_modifiers ( )==67108946)// and ie->get_scancode() == ALT+R and ie->is_pressed(
            {
            //if(ie->get_scancode() == KEY_R)
            armG->set_bone_pose(ξAG,t0G);
            b按下完成G=b按下rG=false;i按下xyzG=-1;Ψ丅鼠标PreG=NULL;
            //----更新子记录位置--------------------------
            卍Bone& boneA=VboneG[ξAG];
            ΔUpdatePoseΘ(boneA);
            // PRINT2("KEY_R==",ie->echo , ie->get_scancode());
            }
        //------------------------------
        if(b按下rG)
            {
            
            if(卩按下键盘(ie,KEY_X))
                {i按下xyzG=0;armG->set_bone_global_pose(ξAG,t骨初始G);Z轴G=X(t骨初始G.basis);丅鼠深PreG= 丅鼠深G=v2鼠屏G;}
            else if(卩按下键盘(ie,KEY_Y))
                {i按下xyzG=1;armG->set_bone_global_pose(ξAG,t骨初始G);Z轴G=Y(t骨初始G.basis);丅鼠深PreG= 丅鼠深G=v2鼠屏G;}                
            else if(卩按下键盘(ie,KEY_Z))
                {i按下xyzG=2;armG->set_bone_global_pose(ξAG,t骨初始G);Z轴G=Z(t骨初始G.basis);丅鼠深PreG= 丅鼠深G=v2鼠屏G;}       
            if(i按下xyzG!=-1)
                画画ig(n场景G,this,this->ig,this->sm,&卍Vector3(t骨初始G.origin),&卍Vector3(t骨初始G.origin- Z(t骨初始G.basis)) \
                                                                                                  ,&卍Vector3(t骨初始G.origin+Z轴G),&卍Vector3(t骨初始G.origin-Z轴G));
            }
        }
        
    }}

//==================================================
void __RotBones__::forward_spatial_gui_input(Camera*camera,InputEventMouseButton*ie)
    {{
    //PRINT1("==",b激活插件G,armG);
    if( armG==NULL)return;//b激活插件G==false or
    // PRINT1("",sType(ie));
    //---- 鼠标按键 ------------------------------------
    if(bType(ie,"InputEventMouseButton"))
        {
        //----中键--------------------------
        if(卩按下鼠标(ie,BUTTON_MIDDLE))
            {
            PRINT0("BUTTON_MIDDLE");
            Vector2 v2鼠屏G = ie->get_position();
            //var v3Origin = camera->project_ray_origin(v2鼠屏G);//这是镜头 位置
            丅鼠深G = camera->project_ray_normal(v2鼠屏G);//PRINT1("",丅鼠深G);
            //----计算夹角--------------------------
            ㄥG=0;ㄥ小G=ㄥ180;
            ξAG=-1;丅CamG=camera->get_camera_transform().origin;//卍Vector3 乛镜Z=camera->get_global_transform().basis.z;
            For(i骨数G,i)
                {
                丅BoneG=V丅BoneG[i];
                镜乛boneG=丅BoneG-丅CamG;//PRINT1("镜乛boneG==",丅BoneG,镜乛boneG);
                ㄥG=丅鼠深G.Λ(镜乛boneG);//PRINT2("",ㄥG,armG->get_bone_name(i));
                if(ㄥG<ㄥ小G)
                    {
                    ㄥ小G=ㄥG;//fAngleMin>>>
                    ξAG=i;镜乛bone小G=镜乛boneG;
                    }
                }
            if(ξAG!=-1)
                镜冖骨G=镜乛bone小G.冖();
            else
                镜冖骨G=0;
            PRINT3("●",ξAG,ㄥ小G,armG->get_bone_name(ξAG));
            Transform t骨=armG->get_bone_global_pose(ξAG);
            // Vector3 乛骨y=(t骨.basis.y - t骨.origin ).normalized()*冖BoneG;
            // 卍Vector3 丅骨尾=t骨.origin + 乛骨y;
            //----draw--------------------------
            画画ig(n场景G,this,this->ig,this->sm,&卍Vector3(t骨.origin),&卍Vector3(t骨.origin- Z(t骨.basis)));
            // 画画ig(armG,this,this->ig,this->sm,&卍Vector3(t骨.origin),&卍Vector3(V丅BoneG[VboneG[ξAG].ξ子]+t骨.origin));
            // 画画ig(armG,this,this->ig,this->sm,&卍Vector3(t骨.origin),&卍Vector3(t骨.origin-t骨.basis.elements[2]));//丅骨尾,&丅CamG,&(丅CamG+丅鼠深G*100)
            // 画画ig(armG,this,this->ig,this->sm,&丅CamG,&(丅CamG+丅鼠深G*300),&丅CamG,&(丅CamG+镜乛bone小G));//
            PRINT2("draw",镜乛bone小G,(int)this->ig,nameO(this->ig));
            //----add object------------------------------------
            // if(sp鼠G==NULL&&n场景G)
                // {
                // sp鼠G = cast_to<Spatial>(n场景G->get_node("oMouse"));
                // if(sp鼠G==NULL) 
                    // sp鼠G = sp十(String("oMouse"),n场景G,0);
                // }
                
            }
        //----确认 键--------------------------
        else if(卩按下鼠标(ie,BUTTON_LEFT) )        
            {
            b按下完成G=true;PRINT1("",b按下完成G);
            //----已经按下R,并且再按下左键--------------------------
            if(b按下rG && b按下完成G)
            // if (ie->get_scancode() == KEY_R)//or ie->get_button_index() == BUTTON_RIGHT
                {
                // if (ie->is_pressed() == false)//释放按键
                    {
                    b按下完成G=b按下rG=false;i按下xyzG=-1;Ψ丅鼠标PreG=NULL;//PRINT1("↑release==");
                    //----更新子记录位置--------------------------
                    卍Bone& boneA=VboneG[ξAG];
                    ΔUpdatePoseΘ(boneA);
                    // PTvector亖亖(V丅BoneG);
                    PRINT1("→→→ie==",ie);
                    return;
                    }
                // else
                    ////PRINT1("KEY_R",KEY_R);
                }
            }
        }
    //----移动 鼠标------------------------------------
    else if(bType(ie,"InputEventMouseMotion"))
        {
        if(b按下rG==true)
            {
            v2鼠屏G = ie->get_position();卍Vector3 vΓ;Transform t骨,t骨子;
            if(i按下xyzG==-1)
                {
                丅鼠深G = camera->project_ray_normal(v2鼠屏G);//乛
                丅鼠深G =丅鼠深G._工()*镜冖骨G  +  camera->get_translation();//长度与 镜头到选骨一样
                // PRINT1("",丅鼠深G);//return;
                //☐☐┆\fMoveG ,乛乛G
                //☐a  │☐↘
                //☐┆☐┄☐
                //☐┄─v3TurnG☐☐
                //☐☐☐☐☐☐应该在按下R后就固定鼠标初始位置 直到释放按键
                //----已经按下 R --------------------------
                if(Ψ丅鼠标PreG==NULL)
                    {
                    丅鼠深PreG= 丅鼠深G;Ψ丅鼠标PreG=&丅鼠深PreG;//固定位置,直到 释放
                    t骨初始G=armG->get_bone_global_pose(ξAG);
                    if(VboneG[ξAG].ξ子!=-1)
                        {
                        t骨子=armG->get_bone_global_pose(VboneG[ξAG].ξ子);
                        Z轴G= t骨初始G.origin  - t骨子.origin;//z轴不变
                        }
                    else//无子
                        {
                        if(VboneG[ξAG].ξ父!=-1)
                            {Z轴G=armG->get_bone_global_pose(VboneG[ξAG].ξ父).origin -t骨初始G.origin; }
                        
                        else
                            {Z轴G= Z(t骨子.basis)  + t骨子.origin;}
                        }PRINT2("Z",Z轴G,VboneG[ξAG].ξ父);
                    return;
                    }
                //----------------------------------------
                乛乛G=丅鼠深G-丅鼠深PreG;PRINT1("鼠",乛乛G);
                // 丅鼠深PreG=丅鼠深G;
                vΓ=-Z轴G.Γ(乛乛G)._工();
                //----------------------------------------
                const float&冖A=VboneG[ξAG].冖,冖一乛=乛乛G.冖();
                if(冖一乛<0.008)
                    return;
                float ㄥC=ㄥ厶2(冖A,冖一乛,乛乛G.Λ(Z轴G));PRINT5("冖",ξAG,冖A,冖一乛,乛乛G.Λ(Z轴G),ㄥC);
                // 卍Vector3 v3Child=armG->get_bone_global_pose(VboneG[ξAG].ξ子).origin;
                // 画画ig(self,this->ig,v3Child,v3Child+乛乛G);
                t骨=t骨初始G;
                t骨.rotate_basis(vΓ.v3(),ㄥC);//V丅BoneG[ξAG].乛(t骨.origin);
                }
            //----按下XYZ----------------------------------------------
            else
                {
                丅鼠深G=v2鼠屏G;
                if(Ψ丅鼠标PreG==NULL)
                    {
                    丅鼠深PreG= 丅鼠深G;Ψ丅鼠标PreG=&丅鼠深PreG;
                    
                    return ;
                    }
                乛乛G=丅鼠深G-丅鼠深PreG;丅鼠深PreG=丅鼠深G;//delta
                int iLR=(乛乛G.x>0)  ?  -1  :  1;
                float 冖=乛乛G.冖()*iLR;if(冖==0)return ;
                float ㄥC=冖/冖屏幕宽G*10;
                t骨=armG->get_bone_global_pose(ξAG);
                t骨.rotate_basis(Z轴G.v3(),ㄥC);

                }
            armG->set_bone_global_pose(ξAG,t骨);//set_bone_pose
            // sp鼠G->set_translation(丅鼠深G.v3());
            }
        }
    return;
    }}

////END////END////END////END////END////END////END////END////


