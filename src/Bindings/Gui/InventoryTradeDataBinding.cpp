#include "pch.h"
#include "kenshi\gui\InventoryGUI.h"
#include "InventoryTradeDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/InventoryGUIBinding.h"

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
    return pushObject<InventoryGUI>(L, instance->inventory, InventoryGUIBinding::getMetatableName());
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

static int InventoryTradeData_get_owner(lua_State* L)
{
    InventoryTradeData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTradeData is nil");
    return HandBinding::push(L, instance->owner);
}

// --- Setters for InventoryTradeData ---
static int InventoryTradeData_set_inventory(lua_State* L)
{
    InventoryTradeData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTradeData is nil");
    instance->inventory = lua_isnoneornil(L, 2) ? nullptr : checkObject<InventoryGUI>(L, 2, InventoryGUIBinding::getMetatableName());
    return 0;
}

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

static int InventoryTradeData_set_owner(lua_State* L)
{
    InventoryTradeData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTradeData is nil");
    instance->owner = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
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
  line 115: InventoryGUI::InventoryTradeData& operator=(...) - operator
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
    registerGetter(L, "inventory", InventoryTradeData_get_inventory);
    registerGetter(L, "paymentRequired", InventoryTradeData_get_paymentRequired);
    registerGetter(L, "canDropItems", InventoryTradeData_get_canDropItems);
    registerGetter(L, "isPlayer", InventoryTradeData_get_isPlayer);
    registerGetter(L, "owner", InventoryTradeData_get_owner);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "inventory", InventoryTradeData_set_inventory);
    registerSetter(L, "paymentRequired", InventoryTradeData_set_paymentRequired);
    registerSetter(L, "canDropItems", InventoryTradeData_set_canDropItems);
    registerSetter(L, "isPlayer", InventoryTradeData_set_isPlayer);
    registerSetter(L, "owner", InventoryTradeData_set_owner);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua