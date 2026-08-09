#include "pch.h"
#include "Bindings/NavMeshGenerator_TaskBinding.h"
#include "Bindings/ZoneMapBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static NavMeshGenerator::Task* getInstance(lua_State* L, int idx)
{
    return checkObject<NavMeshGenerator::Task>(L, idx, NavMeshGenerator_TaskBinding::getMetatableName());
}

static int Task_get_zone(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMeshGenerator::Task is nil");
    return pushObject<ZoneMap>(L, inst->zone, ZoneMapBinding::getMetatableName());
}

static int Task_get_buildings(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMeshGenerator::Task is nil");
    return pushObject<lektor<hand>>(L, &inst->buildings, "lektor<hand>");
}

static int Task_get_hash(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMeshGenerator::Task is nil");
    lua_pushinteger(L, inst->hash);
    return 1;
}

static int Task_get_offset(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMeshGenerator::Task is nil");
    pushVector3(L, inst->offset);
    return 1;
}

static int Task_get_bounds(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMeshGenerator::Task is nil");
    lua_pushlightuserdata(L, (void*)&inst->bounds);
    return 1;
}

static int Task_get_mesh(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMeshGenerator::Task is nil");
    if (inst->mesh) lua_pushlightuserdata(L, (void*)inst->mesh);
    else lua_pushnil(L);
    return 1;
}

static int Task_get_output(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMeshGenerator::Task is nil");
    if (inst->output) lua_pushlightuserdata(L, (void*)inst->output);
    else lua_pushnil(L);
    return 1;
}

static int Task_get_flags(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMeshGenerator::Task is nil");
    lua_pushinteger(L, inst->flags);
    return 1;
}

static int Task_get_next(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMeshGenerator::Task is nil");
    return pushObject<NavMeshGenerator::Task>(L, inst->next, NavMeshGenerator_TaskBinding::getMetatableName());
}

static int Task_set_zone(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMeshGenerator::Task is nil");
    inst->zone = lua_isnoneornil(L, 2) ? nullptr : checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    return 0;
}

static int Task_set_buildings(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMeshGenerator::Task is nil");
    lektor<hand>* val = checkObject<lektor<hand>>(L, 2, "lektor<hand>");
    if (val) inst->buildings = *val;
    return 0;
}

static int Task_set_hash(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMeshGenerator::Task is nil");
    inst->hash = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int Task_set_offset(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMeshGenerator::Task is nil");
    readVector3(L, 2, inst->offset);
    return 0;
}

static int Task_set_bounds(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMeshGenerator::Task is nil");
    inst->bounds = *(Ogre::Aabb*)lua_touserdata(L, 2);
    return 0;
}

static int Task_set_mesh(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMeshGenerator::Task is nil");
    inst->mesh = (hkaiNavMesh*)lua_touserdata(L, 2);
    return 0;
}

static int Task_set_output(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMeshGenerator::Task is nil");
    inst->output = (NavInstance*)lua_touserdata(L, 2);
    return 0;
}

static int Task_set_flags(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMeshGenerator::Task is nil");
    inst->flags = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Task_set_next(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMeshGenerator::Task is nil");
    inst->next = lua_isnoneornil(L, 2) ? nullptr : checkObject<NavMeshGenerator::Task>(L, 2, NavMeshGenerator_TaskBinding::getMetatableName());
    return 0;
}

int NavMeshGenerator_TaskBinding::_CONSTRUCTOR(lua_State* L)
{
    auto* obj = (NavMeshGenerator::Task*)::operator new(sizeof(NavMeshGenerator::Task));
    ::new ((void*)obj) NavMeshGenerator::Task();
    return pushObject<NavMeshGenerator::Task>(L, obj, getMetatableName());
}

int NavMeshGenerator_TaskBinding::_DESTRUCTOR(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMeshGenerator::Task is nil");
    inst->~Task();
    return 0;
}

int NavMeshGenerator_TaskBinding::gc(lua_State* L)
{
    return 0;
}

int NavMeshGenerator_TaskBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.NavMeshGenerator_Task object");
    return 1;
}

int NavMeshGenerator_TaskBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a == b) ? 1 : 0);
    return 1;
}

void NavMeshGenerator_TaskBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       operator_eq },
        { "__gc",       gc },
        { "__tostring", tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", _CONSTRUCTOR },
        { "_DESTRUCTOR",  _DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L); // __getters
    registerGetter(L, "zone", Task_get_zone);
    registerGetter(L, "buildings", Task_get_buildings);
    registerGetter(L, "hash", Task_get_hash);
    registerGetter(L, "offset", Task_get_offset);
    registerGetter(L, "bounds", Task_get_bounds);
    registerGetter(L, "mesh", Task_get_mesh);
    registerGetter(L, "output", Task_get_output);
    registerGetter(L, "flags", Task_get_flags);
    registerGetter(L, "next", Task_get_next);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "zone", Task_set_zone);
    registerSetter(L, "buildings", Task_set_buildings);
    registerSetter(L, "hash", Task_set_hash);
    registerSetter(L, "offset", Task_set_offset);
    registerSetter(L, "bounds", Task_set_bounds);
    registerSetter(L, "mesh", Task_set_mesh);
    registerSetter(L, "output", Task_set_output);
    registerSetter(L, "flags", Task_set_flags);
    registerSetter(L, "next", Task_set_next);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
