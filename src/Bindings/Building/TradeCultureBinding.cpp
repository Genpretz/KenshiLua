#include "pch.h"
#include <kenshi/TradeCulture.h>
#include "TradeCultureBinding.h"
#include "Lua/BindingHelpers.h"

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
    // TODO: Unsupported type for forbiddenItems (lektor<GameData*>)
    lua_pushnil(L);
    return 1;
}

static int TradeCulture_get_illegalBuildings(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");
    // TODO: Unsupported type for illegalBuildings (std::set<GameData*, std::less<GameData*>, Ogre::STLAllocator<GameData*, Ogre::GeneralAllocPolicy > >)
    lua_pushnil(L);
    return 1;
}

static int TradeCulture_get_happyBuildings(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");
    // TODO: Unsupported type for happyBuildings (std::set<GameData*, std::less<GameData*>, Ogre::STLAllocator<GameData*, Ogre::GeneralAllocPolicy > >)
    lua_pushnil(L);
    return 1;
}

static int TradeCulture_get_illegalItems(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");
    // TODO: Unsupported type for illegalItems (std::set<GameData*, std::less<GameData*>, Ogre::STLAllocator<GameData*, Ogre::GeneralAllocPolicy > >)
    lua_pushnil(L);
    return 1;
}

static int TradeCulture_get_tradeGoodsMults(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");
    // TODO: Unsupported type for tradeGoodsMults (std::map<GameData*, float, std::less<GameData*>, Ogre::STLAllocator<std::pair<GameData*const, float>, Ogre::GeneralAllocPolicy > >)
    lua_pushnil(L);
    return 1;
}

// --- Setters for TradeCulture ---
static int TradeCulture_set_forbiddenItems(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");
    return luaL_error(L, "Read-only or unsupported setter type for forbiddenItems");
}

static int TradeCulture_set_illegalBuildings(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");
    return luaL_error(L, "Read-only or unsupported setter type for illegalBuildings");
}

static int TradeCulture_set_happyBuildings(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");
    return luaL_error(L, "Read-only or unsupported setter type for happyBuildings");
}

static int TradeCulture_set_illegalItems(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");
    return luaL_error(L, "Read-only or unsupported setter type for illegalItems");
}

static int TradeCulture_set_tradeGoodsMults(lua_State* L)
{
    TradeCulture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeCulture is nil");
    return luaL_error(L, "Read-only or unsupported setter type for tradeGoodsMults");
}

// --- Methods for TradeCulture ---
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

    const std::set<GameData*, std::less<GameData*>, Ogre::STLAllocator<GameData*, Ogre::GeneralAllocPolicy > >* result = instance->getAllIllegalItems();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
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

/*
Skipped methods needing manual binding:
  line 12: void setupTradeCulture(...) - unsupported arg type
  line 18: const lektor<GameData*>& getForbiddenItemsList(...) - reference return type
  line 19: bool isItemIllegal(...) - unsupported arg type
  line 21: float getTradePriceMultiplier(...) - unsupported arg type
  line 22: bool hasTradePriceMultiplier(...) - unsupported arg type
*/

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