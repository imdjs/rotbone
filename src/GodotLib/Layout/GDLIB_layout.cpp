#ifndef __GDN_LAYOUT_CPP__
    #define __GDN_LAYOUT_CPP__


static HBoxContainer*hbcPulsPuls(EditorPlugin*ep,const Texture*texIcon,const String __on_pressed)//●●static 可以让gd 不用instance就应用
    {
    if(texIcon==NULL||ep==NULL)
        {
        PRINT1("★ hbcPulsPuls==",(int)texIcon,ep);
        return NULL;
        }
    HBoxContainer* hbcToolbar =hbcG->_new();//头按钮
    ep->add_control_to_container(EditorPlugin->CONTAINER_SPATIAL_EDITOR_MENU, hbcToolbar);#添加头按钮
    ToolButton*tb = tbG->_new();
    tb->set_button_icon(Ref<Texture>(texIcon));

    tb->connect("pressed", ep,__on_pressed );
    hbcToolbar->add_child(vsG->_new());
    hbcToolbar->add_child(tb);
    return hbcToolbar;
    }
    
    
static void 一一hbc(EditorPlugin*ep,HBoxContainer* hbcToolbar)//●●static 可以让gd 不用instance就应用
    {
    if( hbcToolbar==NULL||ep==NULL)
        {
        PRINT1("★ 一一hbc==",(int)texIcon,ep);
        return NULL;
        }

    ep->remove_control_from_container(EditorPlugin->CONTAINER_SPATIAL_EDITOR_MENU, hbcToolbar);//添加头按钮
/*     ToolButton*tb = tbG->_new();
    tb->icon=load(sIcon);
    tb->connect("pressed", ep,__on_pressed );
    hbcToolbar->add_child(vsG->_new());
    hbcToolbar->add_child(tb);
    return hbcToolbar; */
    }
    
    
////END////END////END////END////END////END////END////
#endif    