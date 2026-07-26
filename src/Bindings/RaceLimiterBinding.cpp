#include "pch.h"
#include "kenshi\Item.h"
#include "RaceLimiterBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/RaceDataBinding.h"
#include "Bindings/RootObjectBinding.h"

namespace KenshiLua
{

static RaceLimiter* getInstance(lua_State* L, int idx)
{
    return checkObject<RaceLimiter>(L, idx, RaceLimiterBinding::getMetatableName());
}

// --- Getters for RaceLimiter ---
// --- Setters for RaceLimiter ---
int RaceLimiterBinding::addLimit(lua_State* L)
{
    RaceLimiter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceLimiter is nil");

    GameData* dat = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->addLimit(dat);
    return 0;
}

int RaceLimiterBinding::_CONSTRUCTOR(lua_State* L)
{
    RaceLimiter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceLimiter is nil");

    RaceLimiter* result = instance->_CONSTRUCTOR();
    return pushObject<RaceLimiter>(L, result, RaceLimiterBinding::getMetatableName());
}

int RaceLimiterBinding::_DESTRUCTOR(lua_State* L)
{
    RaceLimiter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceLimiter is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 242: RaceLimiter* getSingleton(...) - static method
  line 244: bool canEquip(...) - overloaded method
  line 245: bool _NV_canEquip(...) - overloaded method
  line 246: bool canEquip(...) - overloaded method
  line 247: bool _NV_canEquip(...) - overloaded method
*/

/*
Skipped properties needing manual binding:
  line 241: limits (ogre_unordered_map<GameData*, RaceLimiter::Limiter>::type) - unsupported type
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



static int RaceLimiter_get_limits(lua_State* L)
{
    RaceLimiter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceLimiter is nil");
    // TODO: Unsupported type for limits (ogre_unordered_map<GameData*, RaceLimiter::Limiter>::type)
    return luaL_error(L, "Unsupported property 'limits' (type: ogre_unordered_map<GameData*, RaceLimiter::Limiter>::type)");
}


static int RaceLimiter_set_limits(lua_State* L)
{
    RaceLimiter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceLimiter is nil");
    return luaL_error(L, "Read-only or unsupported setter type for limits");
}


void RaceLimiterBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RaceLimiterBinding::gc },
        { "__tostring", RaceLimiterBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "addLimit", RaceLimiterBinding::addLimit },
        { "_CONSTRUCTOR", RaceLimiterBinding::_CONSTRUCTOR },
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
        registerGetter(L, "limits", RaceLimiter_get_limits);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
        registerSetter(L, "limits", RaceLimiter_set_limits);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua