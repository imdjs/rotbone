// #include <cstdio>
// #include<stdio.h>
// #define _MSC_VER  
// #define UNICODE
// #include<windows.h>

// #include<E:\Visual Studio 2017\VC\Microsoft SDKs\Windows\v7.1A\Include\Windows.h>
#define NOPOPUP

#include<E:\Godot\Godot_example\GDNative-demos-master\GDNative_rotbone\src_english\GodotLib\GodotLib.h>
// #include<Windows.h>
// #include"IMDJS.cpp"
// #include<include\include_math.h>

#include"rotbone.h"
#include"plugin_rotbone.cpp"


extern"C" void __declspec(dllexport)   __declspec(dllexport)  godot_gdnative_init(godot_gdnative_init_options *o) {
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
/* EXC DWORD __unLoadDll(PVOID param)
    {  
    PRINT1("__unLoadDll",param);
    // MessageBox(NULL, TEXT("Press ok To unload me."),  TEXT("MsgBox in dll"), MB_OK);  
    // FreeLibrary(hmSelfG);  
    FreeLibraryAndExitThread(hmSelfG, 0); 
    // oops!  
    return 0;
    }
    
EXC __forceinline void  _unLoadDll()
    {//PRINT1("",i引用计数G);
    // For(i引用计数G,i)
    // while(1)
        {
        // if(hmSelfG==NULL)return;
        CloseHandle( CreateThread(NULL, 0, __unLoadDll, NULL, 0, NULL) ); 
        // HANDLE hThread=CreateThread(NULL, 0, __unLoadDll, NULL, 0, NULL) ; CloseHandle(hThread);
        // cout<<"▲hThread"<<hThread<<endl;
        // if(hmSelfG==NULL)return;
        }
    } */

/* BOOL DllMain(HINSTANCE hinstDLL, DWORD fdwReason, PVOID lpvReserved)  
    {
    switch (fdwReason)
        {
        case  DLL_PROCESS_ATTACH:
            {  PRINT0(▼▼ PulsPuls Main64.dll 已进入目标进程。); 
            hmSelfG = (HMODULE)hinstDLL;  //++i引用计数G;
            break;
            }
        case DLL_PROCESS_DETACH:
            {hmSelfG=NULL;//i引用计数G=0;
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
 */


