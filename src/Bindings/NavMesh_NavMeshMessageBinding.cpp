#include "pch.h"
#include "Bindings/NavMesh_NavMeshMessageBinding.h"
#include "Bindings/NavMesh_BuildingInfoBinding.h"
#include "Bindings/ZoneMapBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static NavMesh::NavMeshMessage* getInstance(lua_State* L, int idx)
{
    return checkObject<NavMesh::NavMeshMessage>(L, idx, NavMesh_NavMeshMessageBinding::getMetatableName());
}

static int NavMeshMessage_get_message(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMesh::NavMeshMessage is nil");
    lua_pushinteger(L, (lua_Integer)inst->message);
    return 1;
}

static int NavMeshMessage_get_zone(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMesh::NavMeshMessage is nil");
    return pushObject<ZoneMap>(L, inst->zone, ZoneMapBinding::getMetatableName());
}

static int NavMeshMessage_get_handle(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMesh::NavMeshMessage is nil");
    return HandBinding::push(L, inst->handle);
}

static int NavMeshMessage_get_hash(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMesh::NavMeshMessage is nil");
    lua_pushinteger(L, inst->hash);
    return 1;
}

static int NavMeshMessage_get_bounds(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMesh::NavMeshMessage is nil");
    lua_pushlightuserdata(L, (void*)&inst->bounds);
    return 1;
}

static int NavMeshMessage_get_interiors(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMesh::NavMeshMessage is nil");
    return pushObject<lektor<NavMesh::BuildingInfo>>(L, &inst->interiors, "lektor<NavMesh::BuildingInfo>");
}

static int NavMeshMessage_get_next(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMesh::NavMeshMessage is nil");
    return pushObject<NavMesh::NavMeshMessage>(L, inst->next, NavMesh_NavMeshMessageBinding::getMetatableName());
}

static int NavMeshMessage_set_message(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMesh::NavMeshMessage is nil");
    inst->message = (NavMesh::MessageType)luaL_checkinteger(L, 2);
    return 0;
}

static int NavMeshMessage_set_zone(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMesh::NavMeshMessage is nil");
    inst->zone = lua_isnoneornil(L, 2) ? nullptr : checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    return 0;
}

static int NavMeshMessage_set_handle(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMesh::NavMeshMessage is nil");
    auto* val = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (val) inst->handle = *val;
    return 0;
}

static int NavMeshMessage_set_hash(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMesh::NavMeshMessage is nil");
    inst->hash = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int NavMeshMessage_set_bounds(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMesh::NavMeshMessage is nil");
    inst->bounds = *(Ogre::Aabb*)lua_touserdata(L, 2);
    return 0;
}

static int NavMeshMessage_set_interiors(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMesh::NavMeshMessage is nil");
    lektor<NavMesh::BuildingInfo>* val = checkObject<lektor<NavMesh::BuildingInfo>>(L, 2, "lektor<NavMesh::BuildingInfo>");
    if (val) inst->interiors = *val;
    return 0;
}

static int NavMeshMessage_set_next(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMesh::NavMeshMessage is nil");
    inst->next = lua_isnoneornil(L, 2) ? nullptr : checkObject<NavMesh::NavMeshMessage>(L, 2, NavMesh_NavMeshMessageBinding::getMetatableName());
    return 0;
}

int NavMesh_NavMeshMessageBinding::gc(lua_State* L)
{
    return 0;
}

int NavMesh_NavMeshMessageBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.NavMesh_NavMeshMessage object");
    return 1;
}

int NavMesh_NavMeshMessageBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a == b) ? 1 : 0);
    return 1;
}

void NavMesh_NavMeshMessageBinding::registerBinding(lua_State* L)
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
    registerGetter(L, "message", NavMeshMessage_get_message);
    registerGetter(L, "zone", NavMeshMessage_get_zone);
    registerGetter(L, "handle", NavMeshMessage_get_handle);
    registerGetter(L, "hash", NavMeshMessage_get_hash);
    registerGetter(L, "bounds", NavMeshMessage_get_bounds);
    registerGetter(L, "interiors", NavMeshMessage_get_interiors);
    registerGetter(L, "next", NavMeshMessage_get_next);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "message", NavMeshMessage_set_message);
    registerSetter(L, "zone", NavMeshMessage_set_zone);
    registerSetter(L, "handle", NavMeshMessage_set_handle);
    registerSetter(L, "hash", NavMeshMessage_set_hash);
    registerSetter(L, "bounds", NavMeshMessage_set_bounds);
    registerSetter(L, "interiors", NavMeshMessage_set_interiors);
    registerSetter(L, "next", NavMeshMessage_set_next);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
