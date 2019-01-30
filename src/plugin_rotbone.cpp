
// #define __PRINT__



// HMODULE hm罒()
// {
	// MEMORY_BASIC_INFORMATION mbi;
	
	// return ((::VirtualQuery(hm罒, &mbi, sizeof(mbi)) != 0) 
	      // ? (HMODULE) mbi.AllocationBase : NULL);
// }

// HMODULE hmSelfG=NULL;//int i引用计数G=0;
// HINSTANCE hsSelfG=NULL;
// EXC DWORD __unLoadDll(PVOID param);
// EXC __forceinline void  _unLoadDll();
////////////////////////////////////////////
class __RotBones__ : public EditorPlugin //EditorPlugin
    {
    GODOT_CLASS(__RotBones__,EditorPlugin)//不能用中文
private:
    ImmediateGeometry*ig=NULL;
    SpatialMaterial *sm=NULL;
public:
    static void _register_methods();

    __RotBones__(){}
    ~__RotBones__(){}//if(ig){ delete ig;delete sm;}
    void __on_pressed(const Texture*texIconG,const Texture*texIcon2G);
    // void __LoadDll();
    // bool __UnloadDll();
    //------------------------------
    void _init(){printf("●● __RotBones__._init= \n");};//●●一定要有这个函数,不然会crash
    void _input(const InputEventKey*ie);
    // void _process(float delta);
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
    void clear(){//PRINT0(Zero clear--------------------------);
                            }
    };

////cpPoint////////////////////////////////////////
void __RotBones__::_register_methods() 
    {
    register_method("handles", &__RotBones__::handles);
    register_method("_enter_tree", &__RotBones__::_enter_tree);
    register_method("_exit_tree", &__RotBones__::_exit_tree);
    register_method("_ready", &__RotBones__::_ready);
    register_method("edit", &__RotBones__::edit);
    register_method("forward_spatial_gui_input", &__RotBones__::forward_spatial_gui_input);
    register_method("_input", &__RotBones__::_input);
    register_method("__on_pressed", &__RotBones__::__on_pressed);
    // register_method("__LoadDll", &__RotBones__::__LoadDll);
    // register_method("__UnloadDll", &__RotBones__::__UnloadDll);
    register_method("clear", &__RotBones__::clear);
    }


////////////////////////////////////////////
void __RotBones__::_enter_tree()
    {
    // hbcToolbarG=hbcPulsPuls(iSelf,"res://icon.png","__on_pressed");
    // for o in hbcToolbarG.get_children():
        // if(o is ToolButton):
            // tbG=o;break;
    // osG=OS::get_singleton();PRINT_1("_enter_tree",osG,d);//●●这个为NULL
    bActivePluginG=true;
    }
//========================================
void __RotBones__::_exit_tree()
    {return ;
    bActivePluginG=false;
    // __UnloadDll();
    }
  
//========================================
/* void __RotBones__::__LoadDll()
    {{
    PRINT0("Θ __LoadDll ");
    // if(hDLLbone==NULL)hDLLbone=LoadLibrary(sDLL);

    }}
     */
/* bool __RotBones__::__UnloadDll()
    {{
    PRINT0("Θ __UnloadDll ");// terminate();
// return false;
    // hmSelfG=GetModuleHandle("main64.dl");
    
    if(hmSelfG)
        {PRINT2(,hmSelfG,hsSelfG);
        _unLoadDll();
        }
    return (hmSelfG==NULL)  ?  true  :  false;

    }} */

void __RotBones__::__on_pressed(const Texture*texIconG,const Texture*texIcon2G)
    {{
#ifdef PRINT_HEAD
    //printf("『『『 %s \n",sgetcharU(__func__));
#endif
    bActivePluginG=!bActivePluginG;
    // else
        // {__UnloadDll();}

    }}
    

//========================================
static __forceinline void  __UpdatePose(symbol_bone&boneA)
    {
    // FOR(boneA.child_arr,SIZE,i)
    for(const auto&ξ:boneA.child_arr)
        {
        VboneLocG[ξ]=armG->get_bone_global_pose(ξ).origin;
        __UpdatePose(VboneG[ξ]);
        }
    }
    
 
//====激活物====================================
Skeleton* __RotBones__:: handles(Object*object) 
    {{
    oAG=object;PRINT2("  handles ",sType(object),nameO(object),object->get_instance_id(),oAG->has_method("get_class"),oAG->is_queued_for_deletion());
    if(oAG)// &&(卩二二(sType(oAG),"MeshInstance") 
        {
        if(nSceneG==NULL)
            {
            FindRoot(oAG,nSceneG);//,vpG,ciG
            PRINT1("罒",nSceneG,(int)vpG);
            }
        if(strcmp(sType(oAG),"MeshInstance") || strcmp(sType(oAG),"Skeleton"))
            {
            Transform m = cast_to<Spatial>(oAG)->get_global_transform();
            PRINT1("",m);
            }
        // Basis*basis=&((Spatial*)object)->get_global_transform().basis;
        // PRINT1("",((Spatial*)object)->get_translation(),basis->x,basis->y,basis->z);
        // PRINT1("",((Spatial*)object)->data.global_transform);
        // PRINT1("?",卩二二(sType(oAG),"Skeleton"));
        if(strcmp(sType(oAG),"Skeleton")==0)
            {
            // armG=(Skeleton*)oAG;//★★crash
            armG=cast_to<Skeleton>(oAG);
            if(armG)
                {
                // Transform m=armG->get_global_transform();
                //PRINT1("",armG->get_global_transform().get_origin());
                PRINT1("亖",armG->get_bone_count());
                // return NULL;
                // if(nSceneG==NULL)
                    // {
                    // nSceneG =tscn.get_local_scene();
                    // PRINT1("++nSceneG==",nSceneG);
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
    // PRINT5("□",osG->get_screen_count(),osG->get_current_screen(),osG->get_screen_size(osG->get_current_screen()),osG->get_real_window_size(),osG->get_window_size());
    __ScreenG=osG->get_window_size().x;
    // v2WindowG=osG->get_window_size();PRINT2("",v2WindowG.x,v2WindowG.y);,osG->get_window_safe_area()
    // if(vpG)
        // {PRINT3("",vpG->get_size(),vpG->get_visible_rect(),vpG->get_size_override());}
    // if(ciG)
        // {PRINT3("",ciG->get_viewport_rect(),ciG->get_local_mouse_position(),ciG->get_global_mouse_position());}
    if(armG)
        {
        // PRINT0("■■ edit ", armG->name,armG);
        //if(iBoneNumG!=oAG->get_bone_count() && sNameSKG!=oAG->name)//不同骨骼
        float __per=0;int  iCount=5;
        卍Matrix4 m=armG->get_global_transform();//PRINT1("●",m);//m.origin=armG->get_translation();
        // PRINT3("◆",armG->data.global_transform,armG->data.rotation,armG->data.scale,armG->get_global_transform().get_origin(),armG->get_translation());
        iBoneNumG=armG->get_bone_count();//PRINT2(,iBoneNumG,iBoneNumPreG);
        //----如果改变选骨--------------------------
        // if(iBoneNumG>1 && armPreG!=armG && iBoneNumPreG!=iBoneNumG)
            {
            armPreG=armG;VboneLocG.resize(iBoneNumG);iBoneNumPreG=iBoneNumG;
            VboneG.resize(iBoneNumG);
            For(iBoneNumG,i)
                {
                VboneLocG[i]=( m*armG->get_bone_global_pose(i) ).Loc();
                // PRINT2("■",armG->get_bone_global_pose(i),VboneLocG[i]);//PRINT1("■",armG->get_bone_pose(i));//PRINT1("■",armG->get_bone_custom_pose(i));PRINT1("■",armG->get_bone_transform(i));
                // PRINT1("2",armG->get_bone_global_pose(i));
                VboneG[i]=symbol_bone();
                VboneG[i].iSelf=i;VboneG[i].iParent=armG->get_bone_parent(i);//PRINT1("iParent==",armG->get_bone_name(i),VboneG[i].iParent);//●●如果没有parent 返回-1;
                // VboneG[i].child_arr=armG->get_bound_child_nodes_to_bone(i);PRINT1("child==",VboneG[i].child_arr);//●●这个无效
                //----有父--------------------------
                if(VboneG[i].iParent>-1)
                    {
                    symbol_bone&boneP=VboneG[VboneG[i].iParent];
                    boneP.iChild=i;//自己成为child 
                    if(inVector(i,boneP.child_arr)==false)
                        {boneP.child_arr.push_back(i);//PRINT1("boneP.child_arr=",boneP.child_arr);
                        }
                    boneP.len=(VboneLocG[i]-VboneLocG[VboneG[i].iParent]).len();
                    //PRINT3("child=",armG->get_bone_name(VboneG[i].iParent).alloc_c_string(),armG->get_bone_name(i),boneP.len);
                    if(iCount>0)
                        {
                        __per+=boneP.len;
                        --iCount;//4,3,2,1,0;
                        }
                    }
                }
                
                // if(VboneG[i].child_arr.size()>0)
                    // VboneG[i].iChild=VboneG[i].child_arr[0];
                //get_bone_pose get_bone_transform get_bone_global_pose get_bone_custom_pose  get_bone_rest
            //----查找无子bone--------------------------
            __boneG=__per=__per/(5-iCount);//PRINT1(,__per);
            For(iBoneNumG,i)
                {
                if(VboneG[i].iChild==-1)
                    {VboneG[i].len=__per;}//PRINT2("无子",i,VboneG[i].len);
                }
            //PTvector亖亖(VboneLocG);
            }
        }
        
    }}

//========================================
void __RotBones__::_input(const InputEventKey*ie)
    {{
    if(armG==NULL)return ;//PRINT1("▲ _input==",bActivePluginG,ie);bActivePluginG==false || 
    // PRINT1("_input",sType(ie));
    // return ;
    if (bType(ie,"InputEventKey"))
        {//PRINT2("_input",bPressRG,bPressFinishG);
        //----正在按R--------------------------
        if(__bPressKey(ie,KEY_R))
            {
            bPressRG = true;

            }
        //----归零pose --------------------------
        else if(ie->get_scancode_with_modifiers ( )==67108946)// && ie->get_scancode() == ALT+R && ie->is_pressed(
            {
            //if(ie->get_scancode() == KEY_R)
            armG->set_bone_pose(idxAG,t0G);
            bPressFinishG=bPressRG=false;iPressXyzG=-1;vpMousePreG=NULL;
            //----更New子记录位置--------------------------
            symbol_bone& boneA=VboneG[idxAG];
            __UpdatePose(boneA);
            // PRINT2("KEY_R==",ie->echo , ie->get_scancode());
            }
        //------------------------------
        if(bPressRG)
            {
            
            if(__bPressKey(ie,KEY_X))
                {iPressXyzG=0;armG->set_bone_global_pose(idxAG,tBoneInitG);ZaxisG=X(tBoneInitG.basis);vMouseDepthPreG= vMouseDepthG=v2MouseLocG;}
            else if(__bPressKey(ie,KEY_Y))
                {iPressXyzG=1;armG->set_bone_global_pose(idxAG,tBoneInitG);ZaxisG=Y(tBoneInitG.basis);vMouseDepthPreG= vMouseDepthG=v2MouseLocG;}                
            else if(__bPressKey(ie,KEY_Z))
                {iPressXyzG=2;armG->set_bone_global_pose(idxAG,tBoneInitG);ZaxisG=Z(tBoneInitG.basis);vMouseDepthPreG= vMouseDepthG=v2MouseLocG;}       
            if(iPressXyzG!=-1)
                __DRAWig(nSceneG,this,this->ig,this->sm,&_Vector3_(tBoneInitG.origin),&_Vector3_(tBoneInitG.origin- Z(tBoneInitG.basis)) \
                                                                                                  ,&_Vector3_(tBoneInitG.origin+ZaxisG),&_Vector3_(tBoneInitG.origin-ZaxisG));
            }
        }
        
    }}

//==================================================
void __RotBones__::forward_spatial_gui_input(Camera*camera,InputEventMouseButton*ie)
    {{
    //PRINT1("==",bActivePluginG,armG);
    if( armG==NULL)return;//bActivePluginG==false ||
    // PRINT1("",sType(ie));
    //---- 鼠标按键 ------------------------------------
    if(bType(ie,"InputEventMouseButton"))
        {
        //----中键--------------------------
        if(__bPressMouse(ie,BUTTON_MIDDLE))
            {
            PRINT0("BUTTON_MIDDLE");
            Vector2 v2MouseLocG = ie->get_position();
            //var v3Origin = camera->project_ray_origin(v2MouseLocG);//这是镜头 位置
            vMouseDepthG = camera->project_ray_normal(v2MouseLocG);//PRINT1("",vMouseDepthG);
            //----计算夹角--------------------------
            angleG=0;angle2G=ang180;
            idxAG=-1;vCamLocG=camera->get_camera_transform().origin;//_Vector3_ To镜Z=camera->get_global_transform().basis.z;
            For(iBoneNumG,i)
                {
                vBoneLocG=VboneLocG[i];
                vCam_boneG=vBoneLocG-vCamLocG;//PRINT1("vCam_boneG==",vBoneLocG,vCam_boneG);
                angleG=vMouseDepthG.angle(vCam_boneG);//PRINT2("",angleG,armG->get_bone_name(i));
                if(angleG<angle2G)
                    {
                    angle2G=angleG;//fAngleMin>>>
                    idxAG=i;vCam_bone2G=vCam_boneG;
                    }
                }
            if(idxAG!=-1)
                fCam__boneG=vCam_bone2G.len();
            else
                fCam__boneG=0;
            PRINT3("●",idxAG,angle2G,armG->get_bone_name(idxAG));
            Transform tBone=armG->get_bone_global_pose(idxAG);
            // Vector3 To骨y=(tBone.basis.y - tBone.origin ).normalized()*__boneG;
            // _Vector3_ Loc骨尾=tBone.origin + To骨y;
            //----draw--------------------------
            __DRAWig(nSceneG,this,this->ig,this->sm,&_Vector3_(tBone.origin),&_Vector3_(tBone.origin- Z(tBone.basis)));
            // __DRAWig(armG,this,this->ig,this->sm,&_Vector3_(tBone.origin),&_Vector3_(VboneLocG[VboneG[idxAG].iChild]+tBone.origin));
            // __DRAWig(armG,this,this->ig,this->sm,&_Vector3_(tBone.origin),&_Vector3_(tBone.origin-tBone.basis.elements[2]));//Loc骨尾,&vCamLocG,&(vCamLocG+vMouseDepthG*100)
            // __DRAWig(armG,this,this->ig,this->sm,&vCamLocG,&(vCamLocG+vMouseDepthG*300),&vCamLocG,&(vCamLocG+vCam_bone2G));//
            PRINT2("draw",vCam_bone2G,(int)this->ig,nameO(this->ig));
            //----add object------------------------------------
            // if(spMouseG==NULL&&nSceneG)
                // {
                // spMouseG = cast_to<Spatial>(nSceneG->get_node("oMouse"));
                // if(spMouseG==NULL) 
                    // spMouseG = spPuls(String("oMouse"),nSceneG,0);
                // }
                
            }
        //----确认 键--------------------------
        else if(__bPressMouse(ie,BUTTON_LEFT) )        
            {
            bPressFinishG=true;PRINT1("",bPressFinishG);
            //----已经按下R,并且再按下左键--------------------------
            if(bPressRG && bPressFinishG)
            // if (ie->get_scancode() == KEY_R)//|| ie->get_button_index() == BUTTON_RIGHT
                {
                // if (ie->is_pressed() == false)//释放按键
                    {
                    bPressFinishG=bPressRG=false;iPressXyzG=-1;vpMousePreG=NULL;//PRINT1("↑release==");
                    //----更New子记录位置--------------------------
                    symbol_bone& boneA=VboneG[idxAG];
                    __UpdatePose(boneA);
                    // PTvector亖亖(VboneLocG);
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
        if(bPressRG==true)
            {
            v2MouseLocG = ie->get_position();_Vector3_ vCross;Transform tBone,tBoneChild;
            if(iPressXyzG==-1)
                {
                vMouseDepthG = camera->project_ray_normal(v2MouseLocG);//To
                vMouseDepthG =vMouseDepthG._Normalize()*fCam__boneG  +  camera->get_translation();//Len度与 镜头到选骨一样
                // PRINT1("",vMouseDepthG);//return;
                //☐☐┆\fMoveG ,v3MoveG
                //☐a  │☐↘
                //☐┆☐┄☐
                //☐┄─v3TurnG☐☐
                //☐☐☐☐☐☐应该在按下R后就固定鼠标初始位置 直到释放按键
                //----已经按下 R --------------------------
                if(vpMousePreG==NULL)
                    {
                    vMouseDepthPreG= vMouseDepthG;vpMousePreG=&vMouseDepthPreG;//固定位置,直到 释放
                    tBoneInitG=armG->get_bone_global_pose(idxAG);
                    if(VboneG[idxAG].iChild!=-1)
                        {
                        tBoneChild=armG->get_bone_global_pose(VboneG[idxAG].iChild);
                        ZaxisG= tBoneInitG.origin  - tBoneChild.origin;//z轴不变
                        }
                    else//无子
                        {
                        if(VboneG[idxAG].iParent!=-1)
                            {ZaxisG=armG->get_bone_global_pose(VboneG[idxAG].iParent).origin -tBoneInitG.origin; }
                        
                        else
                            {ZaxisG= Z(tBoneChild.basis)  + tBoneChild.origin;}
                        }PRINT2("Z",ZaxisG,VboneG[idxAG].iParent);
                    return;
                    }
                //----------------------------------------
                v3MoveG=vMouseDepthG-vMouseDepthPreG;PRINT1("鼠",v3MoveG);
                // vMouseDepthPreG=vMouseDepthG;
                vCross=-ZaxisG.cross(v3MoveG)._Normalize();
                //----------------------------------------
                const float&__A=VboneG[idxAG].len,fMoveG=v3MoveG.len();
                if(fMoveG<0.008)
                    return;
                float angleC=getAngleOfTri2(__A,fMoveG,v3MoveG.angle(ZaxisG));PRINT5("len",idxAG,__A,fMoveG,v3MoveG.angle(ZaxisG),angleC);
                // _Vector3_ v3Child=armG->get_bone_global_pose(VboneG[idxAG].iChild).origin;
                // __DRAWig(iSelf,this->ig,v3Child,v3Child+v3MoveG);
                tBone=tBoneInitG;
                tBone.rotate_basis(vCross.v3(),angleC);//VboneLocG[idxAG].To(tBone.origin);
                }
            //----按下XYZ----------------------------------------------
            else
                {
                vMouseDepthG=v2MouseLocG;
                if(vpMousePreG==NULL)
                    {
                    vMouseDepthPreG= vMouseDepthG;vpMousePreG=&vMouseDepthPreG;
                    
                    return ;
                    }
                v3MoveG=vMouseDepthG-vMouseDepthPreG;vMouseDepthPreG=vMouseDepthG;//delta
                int iLR=(v3MoveG.x>0)  ?  -1  :  1;
                float len=v3MoveG.len()*iLR;if(len==0)return ;
                float angleC=len/__ScreenG*10;
                tBone=armG->get_bone_global_pose(idxAG);
                tBone.rotate_basis(ZaxisG.v3(),angleC);

                }
            armG->set_bone_global_pose(idxAG,tBone);//set_bone_pose
            // spMouseG->set_translation(vMouseDepthG.v3());
            }
        }
    return;
    }}

////END////END////END////END////END////END////END////END////


