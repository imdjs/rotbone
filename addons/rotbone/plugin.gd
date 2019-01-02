tool
extends EditorPlugin
  
# const O= preload("E:/godot/Godot3/GdscriptLib/GSLIB_object.gd");
# const DR= preload("E:/godot/Godot3/GdscriptLib/GSLIB_draw.gd");
const LAY= preload("E:/godot/Godot3/GdscriptLib/GSLIB_layout.gd");
# const MATH= preload("E:/godot/Godot3/GdscriptLib/GSLIB_math.gd");
# const DRW= preload("res://addons/rotbone/GSLIB_layout.gd").new();
#----骨骼--------------------------
const  tscn = preload("res://骨骼.tscn");var tscnG=null;
var armG = null;var iAG=-1; var v3CamG =null;
var iNumG=-1;var iNumPreG=-1;var sNamePreG="";
var hbcToolbarG=null;var tbG=null;var bActiveG=false;
const texIconG=preload("res://addons/rotbone/icon.png");const texIcon2G=preload("res://addons/rotbone/icon2.png");
#----bone--------------------------
var fLenBoneG=0.0;var Lv3BoneG=[];var v3TurnG=null;

var tO=null;#[[1,0,0],[0,1,0],[0,0,1],[0,0,0]];

#====gdnative==========================
const gdnBone = preload("res://__rotbone__.gdns")#null#
onready var GDN=gdnBone.new();#Reference null;# null#

func _enter_tree():
    hbcToolbarG=LAY.hbcAdd(self,"res://addons/rotbone/icon.png","__on_pressed");
    # hbcToolbarG=LAY.hbcAdd(self,"res://addons/rotbone/imdjs 175.png","__on_pressed");
    #GDN._enter_tree();
    #----draw--------------------------
    #if(self is Position3D):

    print("◣_enter_tree==",GDN);
func _exit_tree():
    print("_exit_tree");sNamePreG="";iNumPreG=-1;iAG=-1;
    self.remove_control_from_container(EditorPlugin.CONTAINER_SPATIAL_EDITOR_MENU,hbcToolbarG);
    #GDN._exit_tree();
    #GDN.free();GDN=null;#★★可能引起crash
    
func clear():
    print("〇〇 clear");
    # self.remove_control_from_container(EditorPlugin.CONTAINER_SPATIAL_EDITOR_MENU,hbcToolbarG);

#----激活物--------------------------
func handles(object):
    # print("handles==",object.name,object,object.get_class());#object.mesh,
    # print("GDN==",GDN);
    # return ;
    if(GDN):
        armG=GDN.handles(object);print("armG=", armG);

        
    if(object is Skeleton):#Position3D
        return true;
    else:
        return false;
      
var v=null;
func edit(object):#●只有handle返回true 时 才执行
    #print("■edit ", object.name);
    GDN.edit();
    v=armG;var ci=null;
    while(v ):#and (not o is Viewport)
        v=v.get_parent();#print("o==",o,o.name);
        # if(v is Viewport):
            # print("VIew==",v.get_visible_rect(),v.get_size_override ( ),v.size);
            # break;
        if(v is CanvasItem):
            print("CanvasItem==",v);
            # DRW=v;
            break;        
    # DRW.draw_line(Vector2(0,0),Vector2(911,222),Color(1,1,0.5,1));
    print("OS==",OS.get_real_window_size ( ) ,OS.get_screen_dpi(),OS.get_screen_position(),OS.get_screen_size(),OS.window_position,OS.window_size);
    pass;
# func make_visible(visible):#●●make_visible可能是关键字
    # print("Θ make_visible==",visible);
    #if(hbcToolbarG):
        #hbcToolbarG.set_visible(visible);
        
func _draw():
    if(v is CanvasItem):
        v.draw_line(Vector2(0,0),Vector2(911,222),Color(1,1,0.5,1));
    print("_draw==",v);
#==================================================
func forward_spatial_gui_input(camera, ie):
    # if (not camEditorG): camEditorG = camera;
    # return ;
    if(armG):
        GDN.forward_spatial_gui_input(camera, ie);
        #----------------------------------------
        if (ie is InputEventMouseButton):
            #----中键--------------------------
            if(ie.button_index == BUTTON_MIDDLE and ie.is_pressed()):
                # v3CamG=camera.global_transform.origin;
                #DR.__draw(ig,v3CamG,v3CamG-camera.global_transform.basis[2]*300);
                # print("ig==",ig);
                # var iNum=armG.get_bone_count()
                # for i in range(iNum):
                    # var tBone=armG.get_bone_global_pose(i);
                    # print("tBone==",tBone);
                    # print("tBone2==",tBone.basis.x,tBone.basis.y,tBone.basis.z);
                return true;
                
    pass;
#------------------------------
func _ready ( ) :
    GDN._ready();
        
    
func _input(event):
    #print("_input",event);
    #emit_signal('input', event)
    # return ;
    if(armG):
        GDN._input(event);#●●卸载dll后会崩溃
    return;
    
#========================================
func __on_pressed():
    #GDN.free();GDN=null;return ;
    #print("Θ __on_pressed ",texIconG,texIcon2G);#print("Scene Root==",get_owner());
    armG=null;#●为了停止_input与forward_spatial_gui_input
    #if(GDN):
        # OS.kill(OS.get_process_id());
        # return ;
        #GDN.terminate();
        #var B=GDN.__on_pressed(texIconG,texIcon2G);print("B==",B);
        # if(B):
            # GDN.free();GDN=null;#gdnBone.free();
        
    pass;
    
    
    
    
    
    
    
    
    
    
    
