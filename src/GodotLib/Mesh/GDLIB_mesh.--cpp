

#ifndef __GDLIB_MESH__
#define  __GDLIB_MESH__

Array ArrayMesh::surface_get_arrays(const int p_surface) const 
    {

    ERR_FAIL_INDEX_V(p_surface, surfaces.size(), Array());
    return VisualServer::get_singleton()->mesh_surface_get_arrays(mesh, p_surface);
    }

int ArrayMesh::surface_get_array_len(int p_idx) const 
    {

    ERR_FAIL_INDEX_V(p_idx, surfaces.size(), -1);
    return VisualServer::get_singleton()->mesh_surface_get_array_len(mesh, p_idx);
    }

int ArrayMesh::surface_get_array_index_len(int p_idx) const 
    {

    ERR_FAIL_INDEX_V(p_idx, surfaces.size(), -1);
    return VisualServer::get_singleton()->mesh_surface_get_array_index_len(mesh, p_idx);
    }

ArrayMesh::PrimitiveType ArrayMesh::surface_get_primitive_type(int p_idx) const 
    {

    ERR_FAIL_INDEX_V(p_idx, surfaces.size(), PRIMITIVE_LINES);
    return (PrimitiveType)VisualServer::get_singleton()->mesh_surface_get_primitive_type(mesh, p_idx);
    }
    
int ArrayMesh::get_surface_count() const 
    {

    return surfaces.size();
    }
    
////////////////////////////////////////////
Ref<TriangleMesh> Mesh::generate_triangle_mesh() const 
    {

    if (triangle_mesh.is_valid())
        return triangle_mesh;

    int facecount = 0;

    for (int i = 0; i < get_surface_count(); i++) 
        {

        if (surface_get_primitive_type(i) != PRIMITIVE_TRIANGLES)
            continue;

        if (surface_get_format(i) & ARRAY_FORMAT_INDEX) 
            {

            facecount += surface_get_array_index_len(i);
            }
        else 
            {

            facecount += surface_get_array_len(i);
            }
        }

    if (facecount == 0 || (facecount % 3) != 0)
        return triangle_mesh;

    PoolVector<Vector3> faces;
    faces.resize(facecount);
    PoolVector<Vector3>::Write facesw = faces.write();

    int widx = 0;

    for (int i = 0; i < get_surface_count(); i++) 
        {

        if (surface_get_primitive_type(i) != PRIMITIVE_TRIANGLES)
            continue;

        Array a = surface_get_arrays(i);

        int vc = surface_get_array_len(i);
        PoolVector<Vector3> vertices = a[ARRAY_VERTEX];
        PoolVector<Vector3>::Read vr = vertices.read();

        if (surface_get_format(i) & ARRAY_FORMAT_INDEX) 
            {

            int ic = surface_get_array_index_len(i);
            PoolVector<int> indices = a[ARRAY_INDEX];
            PoolVector<int>::Read ir = indices.read();

            for (int i = 0; i < ic; i++) 
                {
                int index = ir[i];
                facesw[widx++] = vr[index];
                }

            }
        else 
            {

            for (int i = 0; i < vc; i++)
                facesw[widx++] = vr[i];
            }
        }

    facesw = PoolVector<Vector3>::Write();

    triangle_mesh = Ref<TriangleMesh>(memnew(TriangleMesh));
    triangle_mesh->create(faces);

    return triangle_mesh;
    }
    
    
    
    
    
////END////END////END////END////END////END////END////END////
#endif



    