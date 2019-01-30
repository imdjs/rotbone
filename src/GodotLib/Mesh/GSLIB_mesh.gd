
const O= preload("E:/godot/Godot3/GdscriptLib/GSLIB_object.gd");

static func amAdd(pv3aPos,Lidx,name=""):#●●static 可以让gd 不用instance就应用
    var arrays = [];
    arrays.resize(Mesh.ARRAY_MAX);#9
    arrays[Mesh.ARRAY_VERTEX] = pv3aPos;#0
    arrays[Mesh.ARRAY_INDEX] = Lidx;#8
    #----new--------------------------
    var am = ArrayMesh.new();
    am.add_surface_from_arrays(Mesh.PRIMITIVE_TRIANGLES, arrays);
    #print("++▲ am.add_surface_from_arrays==",Mesh.ARRAY_MAX,Mesh.ARRAY_VERTEX,Mesh.ARRAY_INDEX);#●只执行一次 =908
    return am;
    
    
    
    
    


#==============================
var default_material = SpatialMaterial.new()
onready var meshG = Mesh.new();
func meshAdd(name,tscnScene):
    if(meshG==null):
        meshG = Mesh.new();
    print("meshAdd",meshG);
    # default_material.set_parameter(SpatialMaterial.PARAM_DIFFUSE, Color(1, 1, 0))
    
    var o=O.spAdd(name,tscnScene,1);
    o.mesh=meshG;#MeshInstance
    
    __create_cube(Vector3(0, 0, 0), Vector3(1, 1, 1))
    # default_material = SpatialMaterial.new()
    # default_material.set_parameter(SpatialMaterial.PARAM_DIFFUSE, Color(1, 0, 1))
    __create_cube(Vector3(2, 2, 2), Vector3(3, 3, 4))
    
    print(meshG.get_surface_count())

func __create_cube(c1, c2):
    # Base positions
    var xyz = Vector3(c1.x, c1.y, c1.z)
    var xyZ = Vector3(c1.x, c1.y, c2.z)
    var xYz = Vector3(c1.x, c2.y, c1.z)
    var xYZ = Vector3(c1.x, c2.y, c2.z)
    var Xyz = Vector3(c2.x, c1.y, c1.z)
    var XyZ = Vector3(c2.x, c1.y, c2.z)
    var XYz = Vector3(c2.x, c2.y, c1.z)
    var XYZ = Vector3(c2.x, c2.y, c2.z)
    
    # Front
    __create_quad(xyZ, xYZ, XYZ, XyZ);#四个点成面
    # Left
    __create_quad(Xyz, XyZ, XYZ, XYz)
    # Back
    __create_quad(xyz, Xyz, XYz, xYz)
    # Right
    __create_quad(xyz, xYz, xYZ, xyZ)
    # Top
    __create_quad(xYz, XYz, XYZ, xYZ)
    # Bottom
    __create_quad(xyz, xyZ, XyZ, Xyz)

func __create_quad(v1, v2, v3, v4):
    print("__create_quad")
    var surftool = SurfaceTool.new();
    surftool.begin(Mesh.PRIMITIVE_TRIANGLES)
    surftool.add_vertex(v1)
    surftool.add_vertex(v2)
    surftool.add_vertex(v3)
    
    surftool.add_vertex(v1)
    surftool.add_vertex(v3)
    surftool.add_vertex(v4)
    surftool.generate_normals()
    surftool.set_material(default_material)
    
    surftool.commit(meshG);#Returns a constructed ArrayMesh from current information passed in. If an existing ArrayMesh is passed in as an argument, will add an extra surface to the existing ArrayMesh.
    
    
    
    
    
    