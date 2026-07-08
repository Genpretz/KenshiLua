#include "pch.h"
#include <kenshi/gui/InventoryGUI.h>
#include "InventoryTradeDataBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
    typedef InventoryGUI::InventoryTradeData InventoryTradeData;

static InventoryTradeData* getInstance(lua_State* L, int idx)
{
    return checkObject<InventoryTradeData>(L, idx, InventoryTradeDataBinding::getMetatableName());
}

// --- Getters for InventoryTradeData ---
static int InventoryTradeData_get_inventory(lua_State* L)
{
    InventoryTradeData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTradeData is nil");
    lua_pushlightuserdata(L, (void*)instance->inventory);
    return 1;
}

static int InventoryTradeData_get_paymentRequired(lua_State* L)
{
    InventoryTradeData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTradeData is nil");
    lua_pushboolean(L, instance->paymentRequired ? 1 : 0);
    return 1;
}

static int InventoryTradeData_get_canDropItems(lua_State* L)
{
    InventoryTradeData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTradeData is nil");
    lua_pushboolean(L, instance->canDropItems ? 1 : 0);
    return 1;
}

static int InventoryTradeData_get_isPlayer(lua_State* L)
{
    InventoryTradeData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTradeData is nil");
    lua_pushboolean(L, instance->isPlayer ? 1 : 0);
    return 1;
}

// --- Setters for InventoryTradeData ---
static int InventoryTradeData_set_paymentRequired(lua_State* L)
{
    InventoryTradeData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTradeData is nil");
    instance->paymentRequired = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InventoryTradeData_set_canDropItems(lua_State* L)
{
    InventoryTradeData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTradeData is nil");
    instance->canDropItems = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InventoryTradeData_set_isPlayer(lua_State* L)
{
    InventoryTradeData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTradeData is nil");
    instance->isPlayer = lua_toboolean(L, 2) != 0;
    return 0;
}

int InventoryTradeDataBinding::isValid(lua_State* L)
{
    InventoryTradeData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTradeData is nil");

    bool result = instance->isValid();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 104: InventoryTradeData* _CONSTRUCTOR(...) - overloaded method
  line 106: InventoryTradeData* _CONSTRUCTOR(...) - overloaded method
  line 108: InventoryTradeData* _CONSTRUCTOR(...) - overloaded method
  line 115: InventoryGUI::InventoryTradeData& operator=(...) - operator
*/

/*
Skipped properties needing manual binding:
  line 114: owner (hand) - unsupported type
*/

int InventoryTradeDataBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int InventoryTradeDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.InventoryTradeData object");
    return 1;
}

void InventoryTradeDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       InventoryTradeDataBinding::gc },
        { "__tostring", InventoryTradeDataBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "isValid", InventoryTradeDataBinding::isValid },
        { 0, 0 }
    };

    registerClass(
        L, 
        InventoryTradeDataBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, InventoryTradeDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, InventoryTradeData_get_inventory);
    lua_setfield(L, -2, "inventory");
    lua_pushcfunction(L, InventoryTradeData_get_paymentRequired);
    lua_setfield(L, -2, "paymentRequired");
    lua_pushcfunction(L, InventoryTradeData_get_canDropItems);
    lua_setfield(L, -2, "canDropItems");
    lua_pushcfunction(L, InventoryTradeData_get_isPlayer);
    lua_setfield(L, -2, "isPlayer");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, InventoryTradeData_set_paymentRequired);
    lua_setfield(L, -2, "paymentRequired");
    lua_pushcfunction(L, InventoryTradeData_set_canDropItems);
    lua_setfield(L, -2, "canDropItems");
    lua_pushcfunction(L, InventoryTradeData_set_isPlayer);
    lua_setfield(L, -2, "isPlayer");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua