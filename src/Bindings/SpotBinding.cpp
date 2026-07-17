#include "pch.h"
#include "kenshi\SensoryData.h"
#include "SpotBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

typedef SensoryData::SpottingPeopleMgr::Spot Spot;

static Spot* getB(lua_State* L, int idx)
{
    return checkObject<Spot>(L, idx, SpotBinding::getMetatableName());
}

// --- Getters for Spot ---
static int Spot_get_timeSoFar(lua_State* L)
{
    Spot* b = getB(L, 1);
    if (!b) return luaL_error(L, "Spot is nil");
    lua_pushnumber(L, b->timeSoFar);
    return 1;
}

static int Spot_get_timeLimitMax(lua_State* L)
{
    Spot* b = getB(L, 1);
    if (!b) return luaL_error(L, "Spot is nil");
    lua_pushnumber(L, b->timeLimitMax);
    return 1;
}

static int Spot_get_stillSeen(lua_State* L)
{
    Spot* b = getB(L, 1);
    if (!b) return luaL_error(L, "Spot is nil");
    lua_pushboolean(L, b->stillSeen ? 1 : 0);
    return 1;
}

// --- Setters for Spot ---
static int Spot_set_timeSoFar(lua_State* L)
{
    Spot* b = getB(L, 1);
    if (!b) return luaL_error(L, "Spot is nil");
    b->timeSoFar = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Spot_set_timeLimitMax(lua_State* L)
{
    Spot* b = getB(L, 1);
    if (!b) return luaL_error(L, "Spot is nil");
    b->timeLimitMax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Spot_set_stillSeen(lua_State* L)
{
    Spot* b = getB(L, 1);
    if (!b) return luaL_error(L, "Spot is nil");
    b->stillSeen = lua_toboolean(L, 2) != 0;
    return 0;
}

/*
Skipped methods needing manual binding:
  line 175: Spot* _CONSTRUCTOR(...) - unsupported return type
*/

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
    lua_pushcfunction(L, Spot_get_timeSoFar);
    lua_setfield(L, -2, "timeSoFar");
    lua_pushcfunction(L, Spot_get_timeLimitMax);
    lua_setfield(L, -2, "timeLimitMax");
    lua_pushcfunction(L, Spot_get_stillSeen);
    lua_setfield(L, -2, "stillSeen");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, Spot_set_timeSoFar);
    lua_setfield(L, -2, "timeSoFar");
    lua_pushcfunction(L, Spot_set_timeLimitMax);
    lua_setfield(L, -2, "timeLimitMax");
    lua_pushcfunction(L, Spot_set_stillSeen);
    lua_setfield(L, -2, "stillSeen");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua