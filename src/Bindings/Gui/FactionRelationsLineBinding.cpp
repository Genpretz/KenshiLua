#include "pch.h"
#include "kenshi\gui\FactionsScreen.h"
#include "FactionRelationsLineBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/FactionBinding.h"

namespace KenshiLua
{

typedef FactionsScreen::FactionRelationsLine FactionRelationsLine;

static FactionRelationsLine* getInstance(lua_State* L, int idx)
{
    return checkObject<FactionRelationsLine>(L, idx, FactionRelationsLineBinding::getMetatableName());
}

// --- Getters for FactionRelationsLine ---
static int FactionRelationsLine_get_faction(lua_State* L)
{
    FactionRelationsLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelationsLine is nil");
    return pushObject<Faction>(L, instance->faction, FactionBinding::getMetatableName());
}

static int FactionRelationsLine_get_value(lua_State* L)
{
    FactionRelationsLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelationsLine is nil");
    lua_pushnumber(L, instance->value);
    return 1;
}

static int FactionRelationsLine_get_valueText(lua_State* L)
{
    FactionRelationsLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelationsLine is nil");
    lua_pushlightuserdata(L, (void*)instance->valueText);
    return 1;
}

static int FactionRelationsLine_get_leftBar(lua_State* L)
{
    FactionRelationsLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelationsLine is nil");
    lua_pushlightuserdata(L, (void*)instance->leftBar);
    return 1;
}

static int FactionRelationsLine_get_rightBar(lua_State* L)
{
    FactionRelationsLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelationsLine is nil");
    lua_pushlightuserdata(L, (void*)instance->rightBar);
    return 1;
}

// --- Setters for FactionRelationsLine ---
static int FactionRelationsLine_set_faction(lua_State* L)
{
    FactionRelationsLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelationsLine is nil");
    instance->faction = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

static int FactionRelationsLine_set_value(lua_State* L)
{
    FactionRelationsLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelationsLine is nil");
    instance->value = (float)luaL_checknumber(L, 2);
    return 0;
}

int FactionRelationsLineBinding::_CONSTRUCTOR(lua_State* L)
{
    FactionRelationsLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelationsLine is nil");

    Faction* faction = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    FactionRelationsLine* result = instance->_CONSTRUCTOR(faction);
    return pushObject<FactionRelationsLine>(L, result, FactionRelationsLineBinding::getMetatableName());
}

int FactionRelationsLineBinding::update(lua_State* L)
{
    FactionRelationsLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelationsLine is nil");

    instance->update();
    return 0;
}

int FactionRelationsLineBinding::_DESTRUCTOR(lua_State* L)
{
    FactionRelationsLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelationsLine is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 20: void attachToWidget(...) - unsupported arg type
*/

int FactionRelationsLineBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int FactionRelationsLineBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FactionRelationsLine object");
    return 1;
}

void FactionRelationsLineBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FactionRelationsLineBinding::gc },
        { "__tostring", FactionRelationsLineBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", FactionRelationsLineBinding::_CONSTRUCTOR },
        { "update", FactionRelationsLineBinding::update },
        { "_DESTRUCTOR", FactionRelationsLineBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        FactionRelationsLineBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FactionRelationsLineBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "faction", FactionRelationsLine_get_faction);
    registerGetter(L, "value", FactionRelationsLine_get_value);
    registerGetter(L, "valueText", FactionRelationsLine_get_valueText);
    registerGetter(L, "leftBar", FactionRelationsLine_get_leftBar);
    registerGetter(L, "rightBar", FactionRelationsLine_get_rightBar);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "faction", FactionRelationsLine_set_faction);
    registerSetter(L, "value", FactionRelationsLine_set_value);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseLayout
    // setMetatableParent(L, FactionRelationsLineBinding::getMetatableName(), wraps::BaseLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua