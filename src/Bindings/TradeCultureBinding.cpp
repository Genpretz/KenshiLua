#include "pch.h"
#include <kenshi/TradeCulture.h>
#include "TradeCultureBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/Util/StdSetBinding.h"
#include "Bindings/Util/StdMapBinding.h"

namespace KenshiLua
{

static TradeCulture* getInstance(lua_State* L, int idx)
{
    return checkObject<TradeCulture>(L, idx, TradeCultureBinding::getMetatableName());
}

// --- Getters for TradeCulture ---
static int TradeCulture_get_forbiddenItems(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");
    return pushObject<lektor<GameData*>>(L, &instance->forbiddenItems, LektorPtrBinding<GameData*>::metaName);
}

static int TradeCulture_get_illegalBuildings(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");
    return pushObject<StdSetBinding<GameData*>::SetType>(L, &instance->illegalBuildings, StdSetBinding<GameData*>::metaName);
}

static int TradeCulture_get_happyBuildings(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");
    return pushObject<StdSetBinding<GameData*>::SetType>(L, &instance->happyBuildings, StdSetBinding<GameData*>::metaName);
}

static int TradeCulture_get_illegalItems(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");
    return pushObject<StdSetBinding<GameData*>::SetType>(L, &instance->illegalItems, StdSetBinding<GameData*>::metaName);
}

static int TradeCulture_get_tradeGoodsMults(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");
    return pushObject<StdMapBinding<GameData*, float>::MapType>(L, &instance->tradeGoodsMults, StdMapBinding<GameData*, float>::metaName);
}

// --- Setters for TradeCulture ---
static int TradeCulture_set_forbiddenItems(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");
    lektor<GameData*>* val = LektorPtrBinding<GameData*>::get(L, 2);
    if (!val) return luaL_error(L, "Expected lektor<GameData*>");
    instance->forbiddenItems = *val;
    return 0;
}

static int TradeCulture_set_illegalBuildings(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");
    StdSetBinding<GameData*>::SetType* val = StdSetBinding<GameData*>::get(L, 2);
    if (!val) return luaL_error(L, "Expected std::set<GameData*>");
    instance->illegalBuildings = *val;
    return 0;
}

static int TradeCulture_set_happyBuildings(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");
    StdSetBinding<GameData*>::SetType* val = StdSetBinding<GameData*>::get(L, 2);
    if (!val) return luaL_error(L, "Expected std::set<GameData*>");
    instance->happyBuildings = *val;
    return 0;
}

static int TradeCulture_set_illegalItems(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");
    StdSetBinding<GameData*>::SetType* val = StdSetBinding<GameData*>::get(L, 2);
    if (!val) return luaL_error(L, "Expected std::set<GameData*>");
    instance->illegalItems = *val;
    return 0;
}

static int TradeCulture_set_tradeGoodsMults(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");
    StdMapBinding<GameData*, float>::MapType* val = StdMapBinding<GameData*, float>::get(L, 2);
    if (!val) return luaL_error(L, "Expected OgreMap<GameData*, float>");
    instance->tradeGoodsMults = *val;
    return 0;
}

int TradeCultureBinding::reset(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");

    instance->reset();
    return 0;
}

int TradeCultureBinding::getAllIllegalItems(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");

    return pushObject<StdSetBinding<GameData*>::SetType>(L, (StdSetBinding<GameData*>::SetType*)instance->getAllIllegalItems(), StdSetBinding<GameData*>::metaName);
}

int TradeCultureBinding::isItemIllegal(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    if (!item) return luaL_error(L, "Expected GameData");
    bool result = instance->isItemIllegal(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TradeCultureBinding::getTradePriceMultiplier(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    if (!item) return luaL_error(L, "Expected GameData");
    float result = instance->getTradePriceMultiplier(item);
    lua_pushnumber(L, result);
    return 1;
}

int TradeCultureBinding::hasTradePriceMultiplier(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    if (!item) return luaL_error(L, "Expected GameData");
    bool result = instance->hasTradePriceMultiplier(item);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TradeCultureBinding::getForbiddenItemsList(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");

    return pushObject<lektor<GameData*>>(L, (lektor<GameData*>*)&instance->getForbiddenItemsList(), LektorPtrBinding<GameData*>::metaName);
}

int TradeCultureBinding::_CONSTRUCTOR(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");

    TradeCulture* result = instance->_CONSTRUCTOR();
    return pushObject<TradeCulture>(L, result, TradeCultureBinding::getMetatableName());
}

int TradeCultureBinding::_DESTRUCTOR(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int TradeCultureBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TradeCultureBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TradeCulture object");
    return 1;
}

void TradeCultureBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TradeCultureBinding::gc },
        { "__tostring", TradeCultureBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "reset", TradeCultureBinding::reset },
        { "getAllIllegalItems", TradeCultureBinding::getAllIllegalItems },
        { "isItemIllegal", TradeCultureBinding::isItemIllegal },
        { "getTradePriceMultiplier", TradeCultureBinding::getTradePriceMultiplier },
        { "hasTradePriceMultiplier", TradeCultureBinding::hasTradePriceMultiplier },
        { "getForbiddenItemsList", TradeCultureBinding::getForbiddenItemsList },
        { "_CONSTRUCTOR", TradeCultureBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", TradeCultureBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        TradeCultureBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TradeCultureBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, TradeCulture_get_forbiddenItems);
    lua_setfield(L, -2, "forbiddenItems");
    lua_pushcfunction(L, TradeCulture_get_illegalBuildings);
    lua_setfield(L, -2, "illegalBuildings");
    lua_pushcfunction(L, TradeCulture_get_happyBuildings);
    lua_setfield(L, -2, "happyBuildings");
    lua_pushcfunction(L, TradeCulture_get_illegalItems);
    lua_setfield(L, -2, "illegalItems");
    lua_pushcfunction(L, TradeCulture_get_tradeGoodsMults);
    lua_setfield(L, -2, "tradeGoodsMults");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, TradeCulture_set_forbiddenItems);
    lua_setfield(L, -2, "forbiddenItems");
    lua_pushcfunction(L, TradeCulture_set_illegalBuildings);
    lua_setfield(L, -2, "illegalBuildings");
    lua_pushcfunction(L, TradeCulture_set_happyBuildings);
    lua_setfield(L, -2, "happyBuildings");
    lua_pushcfunction(L, TradeCulture_set_illegalItems);
    lua_setfield(L, -2, "illegalItems");
    lua_pushcfunction(L, TradeCulture_set_tradeGoodsMults);
    lua_setfield(L, -2, "tradeGoodsMults");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
