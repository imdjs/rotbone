
#define __PRINT__
using namespace godot;

#include <Godot.hpp>
// #include <Sprite.hpp>

// namespace godot
{
class __RotBones__ : public godot::GodotScript<godot::Spatial> 
    {
    GODOT_CLASS(__RotBones__)//不能用中文

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


////cpp////////////////////////////////////////
void __RotBones__::_register_methods() 
    {
    register_method((char*)"_process",&__RotBones__::_process);//注册自定义__test3d__ 类 的 _process 函数
    register_method((char*)"__press_button",&__RotBones__::__press_button);
    // printf("▲ _register_methods=\n ");
    }

__RotBones__::__RotBones__() 
    {
    // initialize any variables here
    iTime = 0.0;printf("▲ ++创建 __RotBones__=\n ");
    // PTtype(owner);
    }

__RotBones__::~__RotBones__() 
    {
    // add your cleanup here
    printf("◆ ~注销 __RotBones__ iTime = %f ,get_class=%s \n",iTime,owner->get_class().alloc_c_string());//●●注销时>get_class()==Object
    PTtype(owner);
    // Object*o=owner;
    // PoolStringArray psa=o->get_meta_list();printf("psa= %d\n",psa.size());
    }
    
//========================================
void __RotBones__::__press_button()
    {
    iTime += 1.52;
    Vector3 v3位 = Vector3(10.0 + (10.0 * sin(iTime * 2.0)), 10.0 + (10.0 * cos(iTime * 1.5)),10.0 + (10.0 * sin(iTime * 1.5)));
    owner->set_translation(v3位);
    printf("◆◆  __press_button iTime = %f ,owner=%s ,get_class=%s \n",iTime,owner->get_name().alloc_c_string(),owner->get_class().alloc_c_string());
    // printf("▲▲ __press_button= %f,%f,%f \n",v3位.x,v3位.y,v3位.z);
    }
    
//====这个对于插件来说没用==========================
void __RotBones__::_process(float delta) 
    {
    iTime += delta;

    Vector3 v3位 = Vector3(10.0 + (10.0 * sin(iTime * 2.0)), 10.0 + (10.0 * cos(iTime * 1.5)),10.0 + (10.0 * sin(iTime * 1.5)));
    
    owner->set_translation(v3位);//Spatial 
    // printf("▲ _process=%f,%f,%f ",v3位.x,v3位.y,v3位.z);
    
    // owner->data.local_transform.origin = v3位;
	// _propagate_transform_changed(this);
	// if (owner->data.notify_local_transform) {
		// notification(NOTIFICATION_LOCAL_TRANSFORM_CHANGED); 
    String name=owner->get_name();
    // printf("get_name= %s\n",name.alloc_c_string());//√
    // Object*o=owner;Variant var=o->get_meta(name);printf("var= %d\n",var);
    //if(var) printf("get_meta= %d\n",var.get_type());//
    printf("▲  _process = %f ,owner=%s,get_class=%s \n",iTime,name.alloc_c_string(),owner->get_class().alloc_c_string());//●只有在_process 时get_class()==MeshInstance 
    //PTtype(owner);
	}






