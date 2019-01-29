
#define __PRINT__
using namespace godot;

#include <Godot.hpp>
#include <Sprite.hpp>

{
class __RotBones__ : public GodotScript<MeshInstance> 
    {
    GODOT_CLASS(__RotBones__)

private:
    float iTime;

public:
    static void _register_methods();

    __RotBones__();
    ~__RotBones__();
    void _process(float delta);
    void __press_button();
    };

}

void __RotBones__::_register_methods() 
    {
    register_method((char*)"_process",&__RotBones__::_process);
    register_method((char*)"__press_button",&__RotBones__::__press_button);
    }

__RotBones__::__RotBones__() 
    {
    iTime = 0.0;printf("▲ ++创建__test3d__=\n ");
    }

__RotBones__::~__RotBones__() 
    {
    printf("◆ ~注销__test3d__ iTime = %f ,get_class=%s \n",iTime,owner->get_class().alloc_c_string());//●●注销时>get_class()==Object
    PTtype(owner);
    }
    
//========================================
void __RotBones__::__press_button()
    {
    iTime += 1.52;
    Vector3 v3位 = Vector3(10.0 + (10.0 * sin(iTime * 2.0)), 10.0 + (10.0 * cos(iTime * 1.5)),10.0 + (10.0 * sin(iTime * 1.5)));
    owner->set_translation(v3位);
    printf("◆◆  __press_button iTime = %f ,owner=%s ,get_class=%s \n",iTime,owner->get_name().alloc_c_string(),owner->get_class().alloc_c_string());
    }
    
//====这个对于插件来说没用==========================
void __RotBones__::_process(float delta) 
    {
    iTime += delta;

    Vector3 v3位 = Vector3(10.0 + (10.0 * sin(iTime * 2.0)), 10.0 + (10.0 * cos(iTime * 1.5)),10.0 + (10.0 * sin(iTime * 1.5)));
    
    owner->set_translation(v3位);String name=owner->get_name();printf("▲  _process = %f ,owner=%s,get_class=%s \n",iTime,name.alloc_c_string(),owner->get_class().alloc_c_string());//●只有在_process 时get_class()==MeshInstance 

	}






