

#ifndef __GDLIB_VISUALINSTANCE__
#define  __GDLIB_VISUALINSTANCE__


//----E:\Godot\godot-master\drivers\gles3--------------------------
void RasterizerStorageGLES3::immediate_vertex(RID p_immediate, const Vector3 &p_vertex) {

	Immediate *im = immediate_owner.get(p_immediate);
	ERR_FAIL_COND(!im);
	ERR_FAIL_COND(!im->building);

	Immediate::Chunk *c = &im->chunks.back()->get();

	if (c->vertices.empty() && im->chunks.size() == 1) {

		im->aabb.position = p_vertex;
		im->aabb.size = Vector3();
	} else {
		im->aabb.expand_to(p_vertex);
	}

	if (im->mask & VS::ARRAY_FORMAT_NORMAL)
		c->normals.push_back(chunk_normal);
	if (im->mask & VS::ARRAY_FORMAT_TANGENT)
		c->tangents.push_back(chunk_tangent);
	if (im->mask & VS::ARRAY_FORMAT_COLOR)
		c->colors.push_back(chunk_color);
	if (im->mask & VS::ARRAY_FORMAT_TEX_UV)
		c->uvs.push_back(chunk_uv);
	if (im->mask & VS::ARRAY_FORMAT_TEX_UV2)
		c->uvs2.push_back(chunk_uv2);
	im->mask |= VS::ARRAY_FORMAT_VERTEX;
	c->vertices.push_back(p_vertex);
}
    
////END////END////END////END////END////END////END////END////
#endif



    