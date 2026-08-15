#include "pch.h"
#include "Bindings/NavMesh_BuildingInfoBinding.h"
#include "Lua/BindingHelpers.h"

#include "Bindings/Util/HandBinding.h"

namespace KenshiLua
{

static NavMesh::BuildingInfo* getInstance(lua_State* L, int idx)
{
    return checkObject<NavMesh::BuildingInfo>(L, idx, NavMesh_BuildingInfoBinding::getMetatableName());
}

// --- Getters for BuildingInfo ---
static int BuildingInfo_get_handle(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMesh::BuildingInfo is nil");
    return HandBinding::push(L, inst->handle);
}

static int BuildingInfo_get_hash(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMesh::BuildingInfo is nil");
    lua_pushinteger(L, inst->hash);
    return 1;
}

static int BuildingInfo_get_bounds(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMesh::BuildingInfo is nil");
    lua_pushlightuserdata(L, (void*)&inst->bounds);

    return 1;
}

static int BuildingInfo_get_name(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMesh::BuildingInfo is nil");
    lua_pushstring(L, inst->name.c_str());

    return 1;
}

// --- Setters for BuildingInfo ---
static int BuildingInfo_set_handle(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMesh::BuildingInfo is nil");
    auto* val = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (val) inst->handle = *val;
    return 0;
}

static int BuildingInfo_set_hash(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMesh::BuildingInfo is nil");
    inst->hash = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int BuildingInfo_set_bounds(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMesh::BuildingInfo is nil");
    inst->bounds = *(Ogre::Aabb*)lua_touserdata(L, 2);
    return 0;
}

static int BuildingInfo_set_name(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMesh::BuildingInfo is nil");
    inst->name = luaL_checkstring(L, 2);
    return 0;
}

int NavMesh_BuildingInfoBinding::gc(lua_State* L)
{
    return 0;
}

int NavMesh_BuildingInfoBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.NavMesh_BuildingInfo object");
    return 1;
}

int NavMesh_BuildingInfoBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a->handle == b->handle && a->hash == b->hash && &a->bounds == &b->bounds && a->name == b->name)) ? 1 : 0);
    return 1;
}

void NavMesh_BuildingInfoBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       operator_eq },
        { "__gc",       gc },
        { "__tostring", tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L); // __getters
    registerGetter(L, "handle", BuildingInfo_get_handle);
    registerGetter(L, "hash", BuildingInfo_get_hash);
    registerGetter(L, "bounds", BuildingInfo_get_bounds);
    registerGetter(L, "name", BuildingInfo_get_name);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "handle", BuildingInfo_set_handle);
    registerSetter(L, "hash", BuildingInfo_set_hash);
    registerSetter(L, "bounds", BuildingInfo_set_bounds);
    registerSetter(L, "name", BuildingInfo_set_name);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
