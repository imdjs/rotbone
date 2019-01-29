
#define __PRINT__
using namespace godot;

#include <Godot.hpp>
{
class __RotBones__ : public godot::GodotScript<godot::Spatial> 
    {
    GODOT_CLASS(__RotBones__)

private:
    float iTime;

public:
    static void _register_methods();

    __RotBones__();
    ~__RotBones__();
    void _init(){printf("●● _init= \n");};
    void _process(float delta);
    void _ready(){printf("● _ready= \n");};
    void __press_button();
    };

}


void __RotBones__::_register_methods() 
    {
    register_method((char*)"_process",&__RotBones__::_process);//注册自定义__test3d__ 类 的 _process 函数
    register_method((char*)"__press_button",&__RotBones__::__press_button);
    }

__RotBones__::__RotBones__() 
    {
    iTime = 0.0;printf("▲ ++创建 __RotBones__=\n ");
    }

__RotBones__::~__RotBones__() 
    {
    printf("◆ ~注销 __RotBones__ iTime = %f ,get_class=%s \n",iTime,owner->get_class().alloc_c_string());//●●注销时>get_class()==Object
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
    
void __RotBones__::_process(float delta) 
    {
    iTime += delta;

    Vector3 v3位 = Vector3(10.0 + (10.0 * sin(iTime * 2.0)), 10.0 + (10.0 * cos(iTime * 1.5)),10.0 + (10.0 * sin(iTime * 1.5)));
    
    owner->set_translation(v3位);//Spatial 
    String name=owner->get_name();
    printf("▲  _process = %f ,owner=%s,get_class=%s \n",iTime,name.alloc_c_string(),owner->get_class().alloc_c_string());//●只有在_process 时get_class()==MeshInstance 
    }






