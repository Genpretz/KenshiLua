#include "pch.h"
#include <kenshi/ZoneManager.h>
#include "StateTBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
    typedef ZoneMap::StateT StateT;

static StateT* getInstance(lua_State* L, int idx)
{
    return checkObject<StateT>(L, idx, StateTBinding::getMetatableName());
}

// --- Getters for StateT ---
static int StateT_get__zoneBeingLoaded(lua_State* L)
{
    StateT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateT is nil");
    lua_pushboolean(L, instance->_zoneBeingLoaded ? 1 : 0);
    return 1;
}

static int StateT_get__zoneIsLoaded(lua_State* L)
{
    StateT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateT is nil");
    lua_pushboolean(L, instance->_zoneIsLoaded ? 1 : 0);
    return 1;
}

// --- Setters for StateT ---
static int StateT_set__zoneBeingLoaded(lua_State* L)
{
    StateT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateT is nil");
    instance->_zoneBeingLoaded = lua_toboolean(L, 2) != 0;
    return 0;
}

static int StateT_set__zoneIsLoaded(lua_State* L)
{
    StateT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateT is nil");
    instance->_zoneIsLoaded = lua_toboolean(L, 2) != 0;
    return 0;
}

int StateTBinding::_CONSTRUCTOR(lua_State* L)
{
    StateT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateT is nil");

    StateT* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int StateTBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int StateTBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.StateT object");
    return 1;
}

void StateTBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       StateTBinding::gc },
        { "__tostring", StateTBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", StateTBinding::_CONSTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        StateTBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, StateTBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, StateT_get__zoneBeingLoaded);
    lua_setfield(L, -2, "_zoneBeingLoaded");
    lua_pushcfunction(L, StateT_get__zoneIsLoaded);
    lua_setfield(L, -2, "_zoneIsLoaded");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, StateT_set__zoneBeingLoaded);
    lua_setfield(L, -2, "_zoneBeingLoaded");
    lua_pushcfunction(L, StateT_set__zoneIsLoaded);
    lua_setfield(L, -2, "_zoneIsLoaded");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
