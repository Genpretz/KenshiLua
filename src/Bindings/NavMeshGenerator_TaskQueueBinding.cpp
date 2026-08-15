#include "pch.h"
#include "Bindings/NavMeshGenerator_TaskQueueBinding.h"
#include "Bindings/NavMeshGenerator_TaskBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static NavMeshGenerator::TaskQueue* getInstance(lua_State* L, int idx)
{
    return checkObject<NavMeshGenerator::TaskQueue>(L, idx, NavMeshGenerator_TaskQueueBinding::getMetatableName());
}

static int TaskQueue_get_front(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMeshGenerator::TaskQueue is nil");
    return pushObject<NavMeshGenerator::Task>(L, inst->front, NavMeshGenerator_TaskBinding::getMetatableName());
}

static int TaskQueue_set_front(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavMeshGenerator::TaskQueue is nil");
    inst->front = lua_isnoneornil(L, 2) ? nullptr : checkObject<NavMeshGenerator::Task>(L, 2, NavMeshGenerator_TaskBinding::getMetatableName());
    return 0;
}

int NavMeshGenerator_TaskQueueBinding::gc(lua_State* L)
{
    return 0;
}

int NavMeshGenerator_TaskQueueBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.NavMeshGenerator_TaskQueue object");
    return 1;
}

int NavMeshGenerator_TaskQueueBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a == b) ? 1 : 0);
    return 1;
}

void NavMeshGenerator_TaskQueueBinding::registerBinding(lua_State* L)
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
    registerGetter(L, "front", TaskQueue_get_front);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "front", TaskQueue_set_front);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
