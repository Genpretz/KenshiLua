#include "pch.h"
#include "kenshi\ResourceLoader.h"
#include "ResourceLoadRequestMeshBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
typedef ResourceLoader::ResourceLoadRequestMesh ResourceLoadRequestMesh;
typedef ResourceLoader::MeshLoadData MeshLoadData;

static ResourceLoadRequestMesh* getInstance(lua_State* L, int idx)
{
    return checkObject<ResourceLoadRequestMesh>(L, idx, ResourceLoadRequestMeshBinding::getMetatableName());
}

// --- Getters for ResourceLoadRequestMesh ---
static int ResourceLoadRequestMesh_get_entity(lua_State* L)
{
    ResourceLoadRequestMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResourceLoadRequestMesh is nil");
    lua_pushlightuserdata(L, (void*)instance->entity);
    return 1;
}

// --- Setters for ResourceLoadRequestMesh ---
int ResourceLoadRequestMeshBinding::_DESTRUCTOR(lua_State* L)
{
    ResourceLoadRequestMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResourceLoadRequestMesh is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ResourceLoadRequestMeshBinding::finish(lua_State* L)
{
    ResourceLoadRequestMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResourceLoadRequestMesh is nil");

    instance->finish();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 60: boost::function<void __cdecl(...) - unsupported return type
  line 65: ResourceLoadRequestMesh* _CONSTRUCTOR(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 59: requestId (unsigned __int64) - unsupported type
  line 61: data (MeshLoadData) - unsupported type
*/

int ResourceLoadRequestMeshBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ResourceLoadRequestMeshBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ResourceLoadRequestMesh object");
    return 1;
}

void ResourceLoadRequestMeshBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ResourceLoadRequestMeshBinding::gc },
        { "__tostring", ResourceLoadRequestMeshBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", ResourceLoadRequestMeshBinding::_DESTRUCTOR },
        { "finish", ResourceLoadRequestMeshBinding::finish },
        { 0, 0 }
    };

    registerClass(
        L, 
        ResourceLoadRequestMeshBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ResourceLoadRequestMeshBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, ResourceLoadRequestMesh_get_entity);
    lua_setfield(L, -2, "entity");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
