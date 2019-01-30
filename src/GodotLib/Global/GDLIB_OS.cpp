
// #include "OS.h"
#ifndef __GDLIB_OS_CPP__
    #define __GDLIB_OS_CPP__
    
static godot_object *___static_object_OS=nullptr;

static inline void OS_singleton_init() {
	if (___static_object_OS == nullptr) {
		___static_object_OS = api->godot_global_get_singleton((char *) "OS");
	}
}

int64_t OS_get_ticks_msec() {
	OS_singleton_init();
	static godot_method_bind *mb = NULL;
	if (mb == NULL) {
		mb = api->godot_method_bind_get_method("_OS", "get_ticks_msec");
	}
	return ___godot_icall_int(mb, (godot_object *) ___static_object_OS);
}

Vector2 OS_get_screen_size(const int64_t screen) 
    {
	OS_singleton_init();
	static godot_method_bind *mb = NULL;
	if (mb == NULL)
        {
		mb = api->godot_method_bind_get_method("_OS", "get_screen_size");
        }
	return ___godot_icall_Vector2_int(mb, (godot_object *) ___static_object_OS, screen);
    }








////END////END////END////END////END////END////END////END////
#endif







