#ifndef GDLIB_DRAW_CPP
    #define GDLIB_DRAW_CPP


Vector3 p1,p2,p3,p4,p5,p6;

static void Δdraw(ImmediateGeometry*&ig,_Vector3_*pPoint1,_Vector3_*pPoint2 \
                                                    ,_Vector3_*pPoint3=NULL,_Vector3_*pPoint4=NULL,_Vector3_*pPoint5=NULL,_Vector3_*pPoint6=NULL)
    {{
#ifdef PRINT_HEAD
    //printf("『『『 %s \n",sgetcharU(__func__));
#endif
    ASSERTR(ig==NULL);
    ig->clear();//●清除原来的顶点
    //print("亖 Δdraw==",p1,p2);
    ig->begin(Mesh::PRIMITIVE_LINES);//PRIMITIVE_LINE_STRIP PRIMITIVE_TRIANGLE_STRIP PRIMITIVE_LINES PRIMITIVE_POINTS
    // PRINT1(str--------------------------,nameO(ig));
    v_v(pPoint1,p1);v_v(pPoint2,p2);
    ig->add_vertex(p1);ig->add_vertex(p2);PRINT2("",p1,p2);
    //----画第二条线--------------------------
    if(pPoint3 && pPoint4)
        {
        v_v(pPoint3,p3);v_v(pPoint4,p4);
        ig->add_vertex(p3);ig->add_vertex(p4);
        //set_color(Color(1.0,0.0,0.0));
        if(pPoint5 && pPoint6)
            {
            v_v(pPoint5,p5);v_v(pPoint6,p6);
            ig->add_vertex(p5);ig->add_vertex(p6);
            }        
        }
    ig->set_color(Color(0.1,0.9,1));
    ig->set_as_toplevel(true);
    ig->end();
#ifdef PRINT_HEAD
    //printf(" 』』%s \n",sgetcharU(__func__));
#endif
    }}

//========================================
static void __DRAWig(Node *&nScene,EditorPlugin*epPlugin,ImmediateGeometry*&igImmediateGeometry__,SpatialMaterial*&sm,_Vector3_*pPoint1,_Vector3_*pPoint2 \
                                               ,_Vector3_*pPoint3=NULL,_Vector3_*pPoint4=NULL,_Vector3_*pPoint5=NULL,_Vector3_*pPoint6=NULL)
    {{
#ifdef PRINT_HEAD
    //printf("『『『 %s \n",sgetcharU(__func__));
#endif
    //print("igImmediateGeometry__ ==",igImmediateGeometry__);
    // if(igImmediateGeometry__==NULL)
        {
        PRINT1("",(int)igImmediateGeometry__);
        igImmediateGeometry__=(ImmediateGeometry*)nScene->get_node("igDebug");
        if(igImmediateGeometry__==NULL)
            {
            igImmediateGeometry__ =ImmediateGeometry:: _new();
            nScene->add_child(igImmediateGeometry__);igImmediateGeometry__->set_owner(epPlugin);
            // nScene->add_child(igImmediateGeometry__);igImmediateGeometry__->set_owner(nScene);
            //●●成为插件子物,必须,不然会看不见,如果要在场景看到物体,set_owner必须是场景父级
            igImmediateGeometry__->set_name("igDebug");
            // PRINT2("PulsPuls ig",arm,nScene);
            //----mat--------------------------
            sm = SpatialMaterial::_new();
            sm->set_flag(SpatialMaterial::FLAG_UNSHADED, true);
            // sm->set_flag(SpatialMaterial::FLAG_ALBEDO_TEXTURE_FORCE_SRGB, true);
            sm->set_flag(SpatialMaterial::FLAG_USE_VERTEX_LIGHTING, true);
            sm->set_flag(SpatialMaterial::FLAG_SRGB_VERTEX_COLOR, true);
            sm->set_flag(SpatialMaterial::FLAG_USE_POINT_SIZE, true);
            sm->set_point_size(20);
            // sm->set_albedo(Color(1,0.5,0.1,1));
            sm->set_emission(Color(1,0.5,0.1,1));
            // sm->set_transmission(Color(1,0.5,0.1,1));
            //sm.flags_no_depth_test = true
            igImmediateGeometry__->set_material_override (sm); 
            }
        // printf("++.new()==",igImmediateGeometry__,p1_,p2_);
 
        }
    // PRINT_5("p",igImmediateGeometry__,pPoint1,pPoint2,pPoint3,pPoint4,d,d,d,d,d);
    Δdraw(igImmediateGeometry__,pPoint1,pPoint2,pPoint3,pPoint4,pPoint5,pPoint6);

    //print("〓DrawLIB==",igImmediateGeometry__.p1,igImmediateGeometry__.p2,p3_,p4_);
    }}
    
////END////END////END////END////END////END////END////END////
#endif     

    
    