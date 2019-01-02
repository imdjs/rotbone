// #include <cstdio>
// #include<stdio.h>
// #define _MSC_VER  
// #define UNICODE

// #include<E:\Visual Studio 2017\VC\Microsoft SDKs\Windows\v7.1A\Include\Windows.h>
#define NOPOPUP
#include<GodotLib.h>
// #include<Windows.h>

#include<include\include_math.h>
// #include"test3d.cpp"
// #include"test_Spatial.cpp"
#include"rotbone.h"
#include"plugin_rotbone.cpp"
// #include"test_MeshInstance.cpp"


EXGD  __declspec(dllexport)  godot_gdnative_init(godot_gdnative_init_options *o) {
    Godot::gdnative_init(o); //printf("● gdnative_init初始化= ");
}

EXGD godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
    Godot::gdnative_terminate(o);//printf("● godot_gdnative_terminate结束= ");
}

EXGD godot_nativescript_init(void *handle) 
    {
    Godot::nativescript_init(handle);

    // register_class<__RotBones__>();
    register_tool_class<__RotBones__>();//●●注册名必须与test3d.gdns 一致,不然会出错 
    // register_tool_class<gd __RotBones__>();//●注册后 在界面里不断运行 _process 
    // register_tool_class<__RotBones__>();
    // register_tool_class<__testMeshInstance__>();
    //printf("● register_tool_class 注册= ");
    }


//====卸载自身====================================
EXC DWORD iΔ卸载自身(PVOID param)
    {  
    PRINT1("iΔ卸载自身",param);
    // MessageBox(NULL, TEXT("Press ok to unload me."),  TEXT("MsgBox in dll"), MB_OK);  
    // FreeLibrary(hm自身G);  
    FreeLibraryAndExitThread(hm自身G, 0); 
    // oops!  
    return 0;
    }
    
EXC __forceinline void  Δ卸载自身()
    {//PRINT1("",i引用计数G);
    // For(i引用计数G,i)
    // while(1)
        {
        // if(hm自身G==NULL)return;
        CloseHandle( CreateThread(NULL, 0, iΔ卸载自身, NULL, 0, NULL) ); 
        // HANDLE hThread=CreateThread(NULL, 0, iΔ卸载自身, NULL, 0, NULL) ; CloseHandle(hThread);
        // cout<<"▲hThread"<<hThread<<endl;
        // if(hm自身G==NULL)return;
        }
    }

BOOL DllMain(HINSTANCE hinstDLL, DWORD fdwReason, PVOID lpvReserved)  
    {
    switch (fdwReason)
        {
        case  DLL_PROCESS_ATTACH:
            {  PRINT0(▼▼ 十十 Main64.dll 已进入目标进程。); 
            hm自身G = (HMODULE)hinstDLL;  //++i引用计数G;
            break;
            }
        case DLL_PROCESS_DETACH:
            {hm自身G=NULL;//i引用计数G=0;
            PRINT0(▼▼ 一一一 Main64.dll 已从目标进程卸载);
            // ASSERT1("▼▼ 一一一 Main64.dll 已从目标进程卸载",true);
            //MessageBox( NULL, "√√DLL已从目标进程卸载。", "信息", MB_ICONINFORMATION );
            break;
            }
        // case DLL_THREAD_ATTACH:{PRINT0(▼▼+DLL_THREAD_ATTACH);++i引用计数G;break;}
        case DLL_THREAD_DETACH:
            {//--i引用计数G;
            PRINT0(▼▼ ~~DLL_THREAD_DETACH);
            break;
            }
        }
    return TRUE;  
    }  



