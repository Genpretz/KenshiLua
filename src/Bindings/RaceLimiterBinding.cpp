#include "pch.h"
#include "kenshi\Item.h"
#include "RaceLimiterBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/RaceDataBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/LimiterBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"

namespace KenshiLua
{

static RaceLimiter* getInstance(lua_State* L, int idx)
{
    return checkObject<RaceLimiter>(L, idx, RaceLimiterBinding::getMetatableName());
}

// --- Getters for RaceLimiter ---
static int RaceLimiter_get_limits(lua_State* L)
{
    RaceLimiter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceLimiter is nil");
    return pushObject<OgreUnorderedMapBinding<GameData*, RaceLimiter::Limiter>::MapType>(L, &instance->limits, "ogre_unordered_map<GameData*, RaceLimiter::Limiter>");
}

// --- Setters for RaceLimiter ---
static int RaceLimiter_set_limits(lua_State* L)
{
    RaceLimiter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceLimiter is nil");
    auto* val = OgreUnorderedMapBinding<GameData*, RaceLimiter::Limiter>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'limits' must be ogre_unordered_map<GameData*, RaceLimiter::Limiter>");
    instance->limits = *val;
    return 0;
}

int RaceLimiterBinding::addLimit(lua_State* L)
{
    RaceLimiter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceLimiter is nil");

    GameData* dat = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->addLimit(dat);
    return 0;
}

int RaceLimiterBinding::getSingleton(lua_State* L)
{
    RaceLimiter* result = RaceLimiter::getSingleton();
    return pushObject<RaceLimiter>(L, result, RaceLimiterBinding::getMetatableName());
}

int RaceLimiterBinding::canEquip(lua_State* L)
{
    RaceLimiter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceLimiter is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    if (lua_isuserdata(L, 3))
    {
        RootObject* who = (RootObject*)luaL_testudata(L, 3, RootObjectBinding::getMetatableName());
        if (who)
        {
            bool result = instance->canEquip(item, who);
            lua_pushboolean(L, result ? 1 : 0);
            return 1;
        }
        RaceData* race = checkObject<RaceData>(L, 3, RaceDataBinding::getMetatableName());
        bool isAnimal = lua_toboolean(L, 4) != 0;
        bool result = instance->canEquip(item, race, isAnimal);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }
    return luaL_error(L, "Argument 3 to canEquip must be RootObject or RaceData");
}

int RaceLimiterBinding::_NV_canEquip(lua_State* L)
{
    RaceLimiter* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceLimiter is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    if (lua_isuserdata(L, 3))
    {
        RootObject* who = (RootObject*)luaL_testudata(L, 3, RootObjectBinding::getMetatableName());
        if (who)
        {
            bool result = instance->_NV_canEquip(item, who);
            lua_pushboolean(L, result ? 1 : 0);
            return 1;
        }
        RaceData* race = checkObject<RaceData>(L, 3, RaceDataBinding::getMetatableName());
        bool isAnimal = lua_toboolean(L, 4) != 0;
        bool result = instance->_NV_canEquip(item, race, isAnimal);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }
    return luaL_error(L, "Argument 3 to _NV_canEquip must be RootObject or RaceData");
}

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
        { "addLimit", RaceLimiterBinding::addLimit },
        { "getSingleton", RaceLimiterBinding::getSingleton },
        { "canEquip", RaceLimiterBinding::canEquip },
        { "_NV_canEquip", RaceLimiterBinding::_NV_canEquip },
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

    OgreUnorderedMapBinding<GameData*, RaceLimiter::Limiter>::registerBinding(
        L, 
        "ogre_unordered_map<GameData*, RaceLimiter::Limiter>", 
        GameDataBinding::getMetatableName(), 
        LimiterBinding::getMetatableName()
    );

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "getSingleton", RaceLimiterBinding::getSingleton);
    lua_setglobal(L, "RaceLimiter");
}

} // namespace KenshiLua