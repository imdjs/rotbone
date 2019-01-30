
#ifndef GDLIB_OBJECT_CPP
    #define GDLIB_OBJECT_CPP


static Object*oPuls(const String name,Node*tscnScene,int iType=0)//●●static 可以让gd 不用instance就应用
    {
#ifdef PRINT_HEAD
    //printf("『『『 %s \n",sgetcharU(__func__));
#endif
    Object* oNew=NULL;Position3D*tmpP=NULL;MeshInstance*tmpM=NULL;Spatial*tmpS=NULL;
    
    switch (iType) 
        {
        case 0:tmpP=Position3D::_new();tmpP->set_name(name);tmpP->set_owner(tscnScene);oNew=Object::cast_to<Object>(tmpP);break;
        case 1:tmpM=MeshInstance::_new();tmpM->set_name(name);tmpM->set_owner(tscnScene);oNew=Object::cast_to<Object>(MeshInstance::_new());break;
        default:tmpS=Spatial::_new();tmpS->set_name(name);tmpS->set_owner(tscnScene);oNew=Object::cast_to<Object>(tmpS);break;
        }
       
    // oNew->set_name(name);
    tscnScene->add_child(oNew,true);//print("++",tscnScene.name,oNew.name);
    
    return oNew;
    }
    
////END////END////END////END////END////END////END////END////
#endif

