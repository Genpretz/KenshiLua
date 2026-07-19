#include "pch.h"
#include "kenshi\ResourceLoader.h"
#include "MeshLoadDataBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
typedef ResourceLoader::MeshLoadData MeshLoadData;

static MeshLoadData* getInstance(lua_State* L, int idx)
{
    return checkObject<MeshLoadData>(L, idx, MeshLoadDataBinding::getMetatableName());
}

// --- Getters for MeshLoadData ---
static int MeshLoadData_get_skeletonName(lua_State* L)
{
    MeshLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MeshLoadData is nil");
    lua_pushstring(L, instance->skeletonName.c_str());
    return 1;
}

static int MeshLoadData_get_materialName(lua_State* L)
{
    MeshLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MeshLoadData is nil");
    lua_pushstring(L, instance->materialName.c_str());
    return 1;
}

static int MeshLoadData_get_renderQueue(lua_State* L)
{
    MeshLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MeshLoadData is nil");
    lua_pushinteger(L, instance->renderQueue);
    return 1;
}

// --- Setters for MeshLoadData ---
static int MeshLoadData_set_skeletonName(lua_State* L)
{
    MeshLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MeshLoadData is nil");
    instance->skeletonName = luaL_checkstring(L, 2);
    return 0;
}

static int MeshLoadData_set_materialName(lua_State* L)
{
    MeshLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MeshLoadData is nil");
    instance->materialName = luaL_checkstring(L, 2);
    return 0;
}

static int MeshLoadData_set_renderQueue(lua_State* L)
{
    MeshLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MeshLoadData is nil");
    instance->renderQueue = (unsigned char)luaL_checkinteger(L, 2);
    return 0;
}

int MeshLoadDataBinding::_DESTRUCTOR(lua_State* L)
{
    MeshLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MeshLoadData is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 43: MeshLoadData* _CONSTRUCTOR(...) - overloaded method
  line 45: MeshLoadData* _CONSTRUCTOR(...) - overloaded method
*/

/*
Skipped properties needing manual binding:
  line 48: material (Ogre::SharedPtr<Ogre::Material>) - unsupported type
*/

int MeshLoadDataBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int MeshLoadDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MeshLoadData object");
    return 1;
}

void MeshLoadDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       MeshLoadDataBinding::gc },
        { "__tostring", MeshLoadDataBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", MeshLoadDataBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        MeshLoadDataBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, MeshLoadDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, MeshLoadData_get_skeletonName);
    lua_setfield(L, -2, "skeletonName");
    lua_pushcfunction(L, MeshLoadData_get_materialName);
    lua_setfield(L, -2, "materialName");
    lua_pushcfunction(L, MeshLoadData_get_renderQueue);
    lua_setfield(L, -2, "renderQueue");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, MeshLoadData_set_skeletonName);
    lua_setfield(L, -2, "skeletonName");
    lua_pushcfunction(L, MeshLoadData_set_materialName);
    lua_setfield(L, -2, "materialName");
    lua_pushcfunction(L, MeshLoadData_set_renderQueue);
    lua_setfield(L, -2, "renderQueue");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
