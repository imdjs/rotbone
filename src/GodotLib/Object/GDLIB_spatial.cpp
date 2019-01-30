
#ifndef GDLIB_SPATIAL_CPP
    #define GDLIB_SPATIAL_CPP





void Spatial::_update_local_transform() const 
    {
    data.local_transform.basis.set_euler_scale(data.rotation, data.scale);

    data.dirty &= ~DIRTY_LOCAL;
    }




Transform Spatial::get_global_transform() const
    {

    ERR_FAIL_COND_V(!is_inside_tree(), Transform());

    if (data.dirty & DIRTY_GLOBAL) 
        {

        if (data.dirty & DIRTY_LOCAL) 
            {

            _update_local_transform();
            }

        if (data.parent && !data.toplevel_active) 
            {

            data.global_transform = data.parent->get_global_transform() * data.local_transform;
            }
        else 
            {

            data.global_transform = data.local_transform;
            }

        if (data.disable_scale) 
            {
            data.global_transform.basis.orthonormalize();
            }

        data.dirty &= ~DIRTY_GLOBAL;
        }

    return data.global_transform;
    }
    
    
    
    
    
    
////END////END////END////END////END////END////END////END////
#endif

