#ifndef __GDN_KEY_H__
    #define __GDN_KEY_H__


#define __bPressKey(ie,KEY_R)    ie->get_scancode() == KEY_R&&ie->is_pressed()
#define __bReleaseKey(ie,KEY_R)    ie->get_scancode() == KEY_R&&ie->is_pressed() == false
#define __bPressMouse(ie,BUTTON_MIDDLE)    ie->get_button_index() == BUTTON_MIDDLE && ie->is_pressed()
#define __bReleaseMouse(ie,BUTTON_MIDDLE)    ie->get_button_index() == BUTTON_MIDDLE && ie->is_pressed()==false
////END////END////END////END////END////END////END////
#endif    