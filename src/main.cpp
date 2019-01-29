#define NOPOPUP
#include<GodotLib.h>

#include<include\include_math.h>
#include"rotbone.h"
#include"plugin_rotbone.cpp"


EXGD  __declspec(dllexport)  godot_gdnative_init(godot_gdnative_init_options *o) {
    Godot::gdnative_init(o);
}

EXGD godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
    Godot::gdnative_terminate(o);
}

EXGD godot_nativescript_init(void *handle) 
    {
    Godot::nativescript_init(handle);

    register_tool_class<__RotBones__>();
    }

EXC DWORD iΔ卸载自身(PVOID param)
    {  
    PRINT1("iΔ卸载自身",param);
    FreeLibraryAndExitThread(hm自身G, 0);
    return 0;
    }
    
EXC __forceinline void  Δ卸载自身()
    {
        {
        CloseHandle( CreateThread(NULL, 0, iΔ卸载自身, NULL, 0, NULL) ); 
        }
    }

BOOL DllMain(HINSTANCE hinstDLL, DWORD fdwReason, PVOID lpvReserved)  
    {
    switch (fdwReason)
        {
        case  DLL_PROCESS_ATTACH:
            {  PRINT0(▼▼ 十十 Main64.dll 已进入目标进程。); 
            hm自身G = (HMODULE)hinstDLL;
            break;
            }
        case DLL_PROCESS_DETACH:
            {hm自身G=NULL;
            PRINT0(▼▼ 一一一 Main64.dll 已从目标进程卸载);
            break;
            }
        case DLL_THREAD_DETACH:
            {
            PRINT0(▼▼ ~~DLL_THREAD_DETACH);
            break;
            }
        }
    return TRUE;  
    }  



