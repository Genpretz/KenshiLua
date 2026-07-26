#include "pch.h"
#include "kenshi\SensoryData.h"
#include "SpotBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static Spot* getInstance(lua_State* L, int idx)
{
    return checkObject<Spot>(L, idx, SpotBinding::getMetatableName());
}

// --- Getters for Spot ---
static int Spot_get_timeSoFar(lua_State* L)
{
    Spot* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Spot is nil");
    lua_pushnumber(L, instance->timeSoFar);
    return 1;
}

static int Spot_get_timeLimitMax(lua_State* L)
{
    Spot* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Spot is nil");
    lua_pushnumber(L, instance->timeLimitMax);
    return 1;
}

static int Spot_get_stillSeen(lua_State* L)
{
    Spot* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Spot is nil");
    lua_pushboolean(L, instance->stillSeen ? 1 : 0);
    return 1;
}

// --- Setters for Spot ---
static int Spot_set_timeSoFar(lua_State* L)
{
    Spot* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Spot is nil");
    instance->timeSoFar = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Spot_set_timeLimitMax(lua_State* L)
{
    Spot* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Spot is nil");
    instance->timeLimitMax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Spot_set_stillSeen(lua_State* L)
{
    Spot* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Spot is nil");
    instance->stillSeen = lua_toboolean(L, 2) != 0;
    return 0;
}

int SpotBinding::_CONSTRUCTOR(lua_State* L)
{
    Spot* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Spot is nil");

    Spot* result = instance->_CONSTRUCTOR();
    return pushObject<Spot>(L, result, SpotBinding::getMetatableName());
}

int SpotBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SpotBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Spot object");
    return 1;
}

void SpotBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SpotBinding::gc },
        { "__tostring", SpotBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", SpotBinding::_CONSTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        SpotBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SpotBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "timeSoFar", Spot_get_timeSoFar);
    registerGetter(L, "timeLimitMax", Spot_get_timeLimitMax);
    registerGetter(L, "stillSeen", Spot_get_stillSeen);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "timeSoFar", Spot_set_timeSoFar);
    registerSetter(L, "timeLimitMax", Spot_set_timeLimitMax);
    registerSetter(L, "stillSeen", Spot_set_stillSeen);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua