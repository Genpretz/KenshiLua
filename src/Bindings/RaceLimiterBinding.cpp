#include "pch.h"
#include "kenshi\Item.h"
#include "RaceLimiterBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static RaceLimiter* getB(lua_State* L, int idx)
{
    return checkObject<RaceLimiter>(L, idx, RaceLimiterBinding::getMetatableName());
}

// --- Getters for RaceLimiter ---
static int RaceLimiter_get_limits(lua_State* L)
{
    RaceLimiter* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceLimiter is nil");
    // TODO: Unsupported type for limits (ogre_unordered_map<GameData*, RaceLimiter::Limiter>::type)
    lua_pushnil(L);
    return 1;
}

// --- Setters for RaceLimiter ---
static int RaceLimiter_set_limits(lua_State* L)
{
    RaceLimiter* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceLimiter is nil");
    return luaL_error(L, "Read-only or unsupported setter type for limits");
}

int RaceLimiterBinding::_DESTRUCTOR(lua_State* L)
{
    RaceLimiter* b = getB(L, 1);
    if (!b) return luaL_error(L, "RaceLimiter is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 242: RaceLimiter* getSingleton(...) - static method
  line 243: void addLimit(...) - unsupported arg type
  line 244: bool canEquip(...) - overloaded method
  line 245: bool _NV_canEquip(...) - overloaded method
  line 246: bool canEquip(...) - overloaded method
  line 247: bool _NV_canEquip(...) - overloaded method
  line 250: RaceLimiter* _CONSTRUCTOR(...) - unsupported return type
*/

int RaceLimiterBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int RaceLimiterBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.RaceLimiter object");
    return 1;
}

void RaceLimiterBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RaceLimiterBinding::gc },
        { "__tostring", RaceLimiterBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", RaceLimiterBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        RaceLimiterBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, RaceLimiterBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, RaceLimiter_get_limits);
    lua_setfield(L, -2, "limits");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, RaceLimiter_set_limits);
    lua_setfield(L, -2, "limits");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua