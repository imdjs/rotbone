
#ifndef GDLIB_NODE_CPP
    #define GDLIB_NODE_CPP



__forceinline void FindRoot(Object*&oAG,Node*&n根__)//,Viewport*&vp__,CanvasItem*&ci__
    {
#ifdef PRINT_HEAD
    //printf("『『『 %s \n",sgetcharU(__func__));
#endif
    ASSERTR(oAG==NULL);
    Node*nPre=Object::cast_to<Node>(oAG);
    n根__=nPre->get_parent(); bool b找到根=false;
    while(n根__)
        {PRINT2("",sType(nPre),sType(n根__));
        if(b找到根==false&&bType(n根__,"Viewport"))
            {n根__=nPre;b找到根=true;break;}//vp__=Object::cast_to<Viewport>(n根__);
        // if(bType(n根__,"CanvasItem"))
            // {ci__=Object::cast_to<CanvasItem>(n根__);break;}//找到第二个Viewport
        nPre=n根__;
        n根__=n根__->get_parent();
        }
    }
    

    
static Spatial*spPuls(const String name,Node*tscnScene \
                                                                                ,int iType=0)//●●static 可以让gd 不用instance就应用
    {
#ifdef PRINT_HEAD
    //printf("『『『 %s \n",sgetcharU(__func__));
#endif
    Spatial* spNew=NULL;//PRINT1("",);
    
    switch (iType) 
        {
        case 0:spNew=Object::cast_to<Spatial>(Position3D::_new());break;
        case 1:spNew=Object::cast_to<Spatial>(MeshInstance::_new());break;
        default:spNew=Spatial::_new();break;
        }
       
    spNew->set_name(name);
    tscnScene->add_child(spNew);spNew->set_owner(tscnScene);PRINT2("++",tscnScene,spNew);
    
    return spNew;
    }
    
    
////成员函数扩展/////////////////////////////////////





////END////END////END////END////END////END////END////END////
#endif

