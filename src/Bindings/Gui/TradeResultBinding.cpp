#include "pch.h"
#include "kenshi\gui\InventoryGUI.h"
#include "TradeResultBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/EnumBinding.h"

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

int TradeResultBinding::showMessage(lua_State* L)
{
    TradeResult* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TradeResult is nil");

    instance->showMessage();
    return 0;
}

int TradeResultBinding::ShowMessage(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    TradeResult::Enum val = (TradeResult::Enum)luaL_checkinteger(L, idx);
    TradeResult::ShowMessage(val);
    return 0;
}

int TradeResultBinding::eq(lua_State* L)
{
    TradeResult* a = checkObject<TradeResult>(L, 1, TradeResultBinding::getMetatableName());
    TradeResult* b = checkObject<TradeResult>(L, 2, TradeResultBinding::getMetatableName());
    if (!a || !b) {
        lua_pushboolean(L, 0);
        return 1;
    }
    lua_pushboolean(L, (*a == *b) ? 1 : 0);
    return 1;
}

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
        { "__eq",       TradeResultBinding::eq },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "showMessage", TradeResultBinding::showMessage },
        { "ShowMessage", TradeResultBinding::ShowMessage },
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
    registerGetter(L, "value", TradeResult_get_value);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "value", TradeResult_set_value);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "ShowMessage", TradeResultBinding::ShowMessage);
    lua_setglobal(L, "TradeResult");
}

} // namespace KenshiLua