#include "pch.h"
#include "kenshi\Item.h"
#include "LimiterBinding.h"
#include "Lua/BindingHelpers.h"

typedef RaceLimiter::Limiter Limiter;

namespace KenshiLua
{

static Limiter* getB(lua_State* L, int idx)
{
    return checkObject<Limiter>(L, idx, LimiterBinding::getMetatableName());
}

// --- Getters for Limiter ---
static int Limiter_get_racesExclude(lua_State* L)
{
    Limiter* b = getB(L, 1);
    if (!b) return luaL_error(L, "Limiter is nil");
    // TODO: Unsupported type for racesExclude (std::set<RaceData*, std::less<RaceData*>, Ogre::STLAllocator<RaceData*, Ogre::GeneralAllocPolicy > >)
    lua_pushnil(L);
    return 1;
}

static int Limiter_get_racesInclude(lua_State* L)
{
    Limiter* b = getB(L, 1);
    if (!b) return luaL_error(L, "Limiter is nil");
    // TODO: Unsupported type for racesInclude (std::set<RaceData*, std::less<RaceData*>, Ogre::STLAllocator<RaceData*, Ogre::GeneralAllocPolicy > >)
    lua_pushnil(L);
    return 1;
}

// --- Setters for Limiter ---
static int Limiter_set_racesExclude(lua_State* L)
{
    Limiter* b = getB(L, 1);
    if (!b) return luaL_error(L, "Limiter is nil");
    return luaL_error(L, "Read-only or unsupported setter type for racesExclude");
}

static int Limiter_set_racesInclude(lua_State* L)
{
    Limiter* b = getB(L, 1);
    if (!b) return luaL_error(L, "Limiter is nil");
    return luaL_error(L, "Read-only or unsupported setter type for racesInclude");
}

int LimiterBinding::_DESTRUCTOR(lua_State* L)
{
    Limiter* b = getB(L, 1);
    if (!b) return luaL_error(L, "Limiter is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 231: bool canEquip(...) - unsupported arg type
  line 232: bool _NV_canEquip(...) - unsupported arg type
  line 235: Limiter* _CONSTRUCTOR(...) - unsupported return type
*/

int LimiterBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int LimiterBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Limiter object");
    return 1;
}

void LimiterBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       LimiterBinding::gc },
        { "__tostring", LimiterBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", LimiterBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        LimiterBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, LimiterBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, Limiter_get_racesExclude);
    lua_setfield(L, -2, "racesExclude");
    lua_pushcfunction(L, Limiter_get_racesInclude);
    lua_setfield(L, -2, "racesInclude");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, Limiter_set_racesExclude);
    lua_setfield(L, -2, "racesExclude");
    lua_pushcfunction(L, Limiter_set_racesInclude);
    lua_setfield(L, -2, "racesInclude");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua