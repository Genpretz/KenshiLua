#include "pch.h"
#include <kenshi/gui/InventoryGUI.h>
#include "TradeResultBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
    typedef InventoryGUI::TradeResult TradeResult;

static TradeResult* getInstance(lua_State* L, int idx)
{
    return checkObject<TradeResult>(L, idx, TradeResultBinding::getMetatableName());
}

// --- Getters for TradeResult ---
static int TradeResult_get_value(lua_State* L)
{
    TradeResult* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeResult is nil");
    lua_pushinteger(L, (lua_Integer)instance->value);
    return 1;
}

// --- Setters for TradeResult ---
static int TradeResult_set_value(lua_State* L)
{
    TradeResult* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeResult is nil");
    instance->value = (TradeResult::Enum)luaL_checkinteger(L, 2);
    return 0;
}

int TradeResultBinding::_CONSTRUCTOR(lua_State* L)
{
    TradeResult* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeResult is nil");

    TradeResult::Enum value = (TradeResult::Enum)luaL_checkinteger(L, 2);
    TradeResult* result = instance->_CONSTRUCTOR(value);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TradeResultBinding::showMessage(lua_State* L)
{
    TradeResult* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeResult is nil");

    instance->showMessage();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 94: bool operator==(...) - operator
  line 95: bool operator!=(...) - operator
  line 97: void ShowMessage(...) - static method
*/

int TradeResultBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TradeResultBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TradeResult object");
    return 1;
}

void TradeResultBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TradeResultBinding::gc },
        { "__tostring", TradeResultBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", TradeResultBinding::_CONSTRUCTOR },
        { "showMessage", TradeResultBinding::showMessage },
        { 0, 0 }
    };

    registerClass(
        L, 
        TradeResultBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TradeResultBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, TradeResult_get_value);
    lua_setfield(L, -2, "value");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, TradeResult_set_value);
    lua_setfield(L, -2, "value");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua