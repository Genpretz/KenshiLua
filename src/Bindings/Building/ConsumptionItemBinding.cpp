#include "pch.h"
#include <kenshi/Building/StorageBuilding.h>
#include "ConsumptionItemBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/InventorySectionBinding.h"

namespace KenshiLua
{
typedef StorageBuilding::ConsumptionItem ConsumptionItem;

static ConsumptionItem* getInstance(lua_State* L, int idx)
{
    return checkObject<ConsumptionItem>(L, idx, ConsumptionItemBinding::getMetatableName());
}

// --- Getters for ConsumptionItem ---
static int ConsumptionItem_get_amount(lua_State* L)
{
    ConsumptionItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConsumptionItem is nil");
    lua_pushnumber(L, instance->amount);
    return 1;
}

static int ConsumptionItem_get_rate(lua_State* L)
{
    ConsumptionItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConsumptionItem is nil");
    lua_pushnumber(L, instance->rate);
    return 1;
}

static int ConsumptionItem_get_maxCapacity(lua_State* L)
{
    ConsumptionItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConsumptionItem is nil");
    lua_pushinteger(L, instance->maxCapacity);
    return 1;
}

static int ConsumptionItem_get_item(lua_State* L)
{
    ConsumptionItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConsumptionItem is nil");
    return pushObject<GameData>(L, instance->item, GameDataBinding::getMetatableName());
}

static int ConsumptionItem_get_inventorySection(lua_State* L)
{
    ConsumptionItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConsumptionItem is nil");
    return pushObject<InventorySection>(L, instance->inventorySection, InventorySectionBinding::getMetatableName());
}

// --- Setters for ConsumptionItem ---
static int ConsumptionItem_set_amount(lua_State* L)
{
    ConsumptionItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConsumptionItem is nil");
    instance->amount = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ConsumptionItem_set_rate(lua_State* L)
{
    ConsumptionItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConsumptionItem is nil");
    instance->rate = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ConsumptionItem_set_maxCapacity(lua_State* L)
{
    ConsumptionItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConsumptionItem is nil");
    instance->maxCapacity = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int ConsumptionItem_set_item(lua_State* L)
{
    ConsumptionItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConsumptionItem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for item");
}

static int ConsumptionItem_set_inventorySection(lua_State* L)
{
    ConsumptionItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConsumptionItem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for inventorySection");
}

int ConsumptionItemBinding::isFull(lua_State* L)
{
    ConsumptionItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConsumptionItem is nil");

    bool result = instance->isFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ConsumptionItemBinding::isEmpty(lua_State* L)
{
    ConsumptionItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ConsumptionItem is nil");

    bool result = instance->isEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 35: ConsumptionItem* _CONSTRUCTOR(...) - overloaded method
  line 37: ConsumptionItem* _CONSTRUCTOR(...) - overloaded method
*/

int ConsumptionItemBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ConsumptionItemBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ConsumptionItem object");
    return 1;
}

void ConsumptionItemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ConsumptionItemBinding::gc },
        { "__tostring", ConsumptionItemBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "isFull", ConsumptionItemBinding::isFull },
        { "isEmpty", ConsumptionItemBinding::isEmpty },
        { 0, 0 }
    };

    registerClass(
        L, 
        ConsumptionItemBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ConsumptionItemBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, ConsumptionItem_get_amount);
    lua_setfield(L, -2, "amount");
    lua_pushcfunction(L, ConsumptionItem_get_rate);
    lua_setfield(L, -2, "rate");
    lua_pushcfunction(L, ConsumptionItem_get_maxCapacity);
    lua_setfield(L, -2, "maxCapacity");
    lua_pushcfunction(L, ConsumptionItem_get_item);
    lua_setfield(L, -2, "item");
    lua_pushcfunction(L, ConsumptionItem_get_inventorySection);
    lua_setfield(L, -2, "inventorySection");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, ConsumptionItem_set_amount);
    lua_setfield(L, -2, "amount");
    lua_pushcfunction(L, ConsumptionItem_set_rate);
    lua_setfield(L, -2, "rate");
    lua_pushcfunction(L, ConsumptionItem_set_maxCapacity);
    lua_setfield(L, -2, "maxCapacity");
    lua_pushcfunction(L, ConsumptionItem_set_item);
    lua_setfield(L, -2, "item");
    lua_pushcfunction(L, ConsumptionItem_set_inventorySection);
    lua_setfield(L, -2, "inventorySection");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua