
static func spAdd( name,tscnScene,iType=0):#●●static 可以让gd 不用instance就应用
    var oNew=null;

    match iType:
        0:oNew=Position3D.new();
        1:oNew=MeshInstance.new();
        _:oNew=Spatial.new();
       
    oNew.name=name;
    tscnScene.add_child(oNew);oNew.set_owner(tscnScene);print("++",tscnScene.name,oNew.name);
    return oNew;
    
    
    
    
    
    
    
    
    
    