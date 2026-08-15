#include "pch.h"
#include "Bindings/NavInstanceBinding.h"
#include "Lua/BindingHelpers.h"
#include <kenshi/NavInstance.h>

namespace KenshiLua
{

static NavInstance* getInstance(lua_State* L, int idx)
{
    return checkObject<NavInstance>(L, idx, NavInstanceBinding::getMetatableName());
}

static int NavInstance_get_mesh(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavInstance is nil");
    if (inst->mesh) lua_pushlightuserdata(L, (void*)inst->mesh);
    else lua_pushnil(L);
    return 1;
}

static int NavInstance_get_graph(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavInstance is nil");
    if (inst->graph) lua_pushlightuserdata(L, (void*)inst->graph);
    else lua_pushnil(L);
    return 1;
}

static int NavInstance_get_graphInstance(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavInstance is nil");
    if (inst->graphInstance) lua_pushlightuserdata(L, (void*)inst->graphInstance);
    else lua_pushnil(L);
    return 1;
}

static int NavInstance_get_mediator(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavInstance is nil");
    if (inst->mediator) lua_pushlightuserdata(L, (void*)inst->mediator);
    else lua_pushnil(L);
    return 1;
}

static int NavInstance_get_instance(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavInstance is nil");
    if (inst->instance) lua_pushlightuserdata(L, (void*)inst->instance);
    else lua_pushnil(L);
    return 1;
}

static int NavInstance_get_offset(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavInstance is nil");
    pushVector3(L, inst->offset);
    return 1;
}

static int NavInstance_set_mesh(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavInstance is nil");
    inst->mesh = (hkaiNavMesh*)lua_touserdata(L, 2);
    return 0;
}

static int NavInstance_set_graph(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavInstance is nil");
    inst->graph = (hkaiDirectedGraphExplicitCost*)lua_touserdata(L, 2);
    return 0;
}

static int NavInstance_set_graphInstance(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavInstance is nil");
    inst->graphInstance = (hkaiDirectedGraphInstance*)lua_touserdata(L, 2);
    return 0;
}

static int NavInstance_set_mediator(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavInstance is nil");
    inst->mediator = (hkaiNavMeshQueryMediator*)lua_touserdata(L, 2);
    return 0;
}

static int NavInstance_set_instance(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavInstance is nil");
    inst->instance = (hkaiNavMeshInstance*)lua_touserdata(L, 2);
    return 0;
}

static int NavInstance_set_offset(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "NavInstance is nil");
    readVector3(L, 2, inst->offset);
    return 0;
}

int NavInstanceBinding::gc(lua_State* L)
{
    return 0;
}

int NavInstanceBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.NavInstance object");
    return 1;
}

int NavInstanceBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a == b) ? 1 : 0);
    return 1;
}

void NavInstanceBinding::registerBinding(lua_State* L)
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
    registerGetter(L, "mesh", NavInstance_get_mesh);
    registerGetter(L, "graph", NavInstance_get_graph);
    registerGetter(L, "graphInstance", NavInstance_get_graphInstance);
    registerGetter(L, "mediator", NavInstance_get_mediator);
    registerGetter(L, "instance", NavInstance_get_instance);
    registerGetter(L, "offset", NavInstance_get_offset);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "mesh", NavInstance_set_mesh);
    registerSetter(L, "graph", NavInstance_set_graph);
    registerSetter(L, "graphInstance", NavInstance_set_graphInstance);
    registerSetter(L, "mediator", NavInstance_set_mediator);
    registerSetter(L, "instance", NavInstance_set_instance);
    registerSetter(L, "offset", NavInstance_set_offset);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
