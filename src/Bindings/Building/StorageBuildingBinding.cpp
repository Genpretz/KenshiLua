#include "pch.h"
#include <kenshi/Building/StorageBuilding.h>
#include "StorageBuildingBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Building/UseableStuffBinding.h"

namespace KenshiLua
{

static StorageBuilding* getInstance(lua_State* L, int idx)
{
    return checkObject<StorageBuilding>(L, idx, StorageBuildingBinding::getMetatableName());
}

// --- Getters for StorageBuilding ---
static int StorageBuilding_get_specialItemTypesOnly(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");
    lua_pushinteger(L, (lua_Integer)instance->specialItemTypesOnly);
    return 1;
}

static int StorageBuilding_get_endOfTheLine(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");
    lua_pushboolean(L, instance->endOfTheLine ? 1 : 0);
    return 1;
}

static int StorageBuilding_get_productionItem(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");
    lua_pushlightuserdata(L, (void*)instance->productionItem);
    return 1;
}

static int StorageBuilding_get_manyLimitItems(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");
    // TODO: Unsupported type for manyLimitItems (lektor<StorageBuilding::ConsumptionItem*>)
    return luaL_error(L, "Unsupported property 'manyLimitItems' (type: lektor<StorageBuilding::ConsumptionItem*>)");
}

// --- Setters for StorageBuilding ---
static int StorageBuilding_set_specialItemTypesOnly(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");
    instance->specialItemTypesOnly = (itemType)luaL_checkinteger(L, 2);
    return 0;
}

static int StorageBuilding_set_endOfTheLine(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");
    instance->endOfTheLine = lua_toboolean(L, 2) != 0;
    return 0;
}

static int StorageBuilding_set_productionItem(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for productionItem");
}

static int StorageBuilding_set_manyLimitItems(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for manyLimitItems");
}

int StorageBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int StorageBuildingBinding::getFunctionStuff(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    StorageBuilding* result = instance->getFunctionStuff();
    return pushObject<StorageBuilding>(L, result, StorageBuildingBinding::getMetatableName());
}

int StorageBuildingBinding::_NV_getFunctionStuff(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    StorageBuilding* result = instance->_NV_getFunctionStuff();
    return pushObject<StorageBuilding>(L, result, StorageBuildingBinding::getMetatableName());
}

int StorageBuildingBinding::getUseableStuff(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    UseableStuff* result = instance->getUseableStuff();
    return pushObject<UseableStuff>(L, result, UseableStuffBinding::getMetatableName());
}

int StorageBuildingBinding::_NV_getUseableStuff(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    UseableStuff* result = instance->_NV_getUseableStuff();
    return pushObject<UseableStuff>(L, result, UseableStuffBinding::getMetatableName());
}

int StorageBuildingBinding::update(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    instance->update();
    return 0;
}

int StorageBuildingBinding::_NV_update(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    instance->_NV_update();
    return 0;
}

int StorageBuildingBinding::getDefaultTask(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    TaskType result = instance->getDefaultTask();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int StorageBuildingBinding::_NV_getDefaultTask(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    TaskType result = instance->_NV_getDefaultTask();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int StorageBuildingBinding::getProductionItemData(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    GameData* result = instance->getProductionItemData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int StorageBuildingBinding::_NV_getProductionItemData(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    GameData* result = instance->_NV_getProductionItemData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int StorageBuildingBinding::getProductionItem(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    StorageBuilding::ConsumptionItem* result = instance->getProductionItem();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int StorageBuildingBinding::getCurrentProductionQuantity(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    int result = instance->getCurrentProductionQuantity();
    lua_pushinteger(L, result);
    return 1;
}

int StorageBuildingBinding::_NV_getCurrentProductionQuantity(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    int result = instance->_NV_getCurrentProductionQuantity();
    lua_pushinteger(L, result);
    return 1;
}

int StorageBuildingBinding::isAnyInputsEmpty(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    bool result = instance->isAnyInputsEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StorageBuildingBinding::_NV_isAnyInputsEmpty(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    bool result = instance->_NV_isAnyInputsEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StorageBuildingBinding::isAnyInputsFull(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    bool result = instance->isAnyInputsFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StorageBuildingBinding::_NV_isAnyInputsFull(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    bool result = instance->_NV_isAnyInputsFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StorageBuildingBinding::isProductionFull(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    bool result = instance->isProductionFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StorageBuildingBinding::_NV_isProductionFull(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    bool result = instance->_NV_isProductionFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StorageBuildingBinding::isProductionEmpty(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    bool result = instance->isProductionEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StorageBuildingBinding::_NV_isProductionEmpty(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    bool result = instance->_NV_isProductionEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StorageBuildingBinding::getNumConsumtionItems(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    int result = instance->getNumConsumtionItems();
    lua_pushinteger(L, result);
    return 1;
}

int StorageBuildingBinding::_NV_getNumConsumtionItems(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    int result = instance->_NV_getNumConsumtionItems();
    lua_pushinteger(L, result);
    return 1;
}

int StorageBuildingBinding::getConsumtionItems(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    int id = (int)luaL_checkinteger(L, 2);
    StorageBuilding::ConsumptionItem* result = instance->getConsumtionItems(id);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int StorageBuildingBinding::_NV_getConsumtionItems(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    int id = (int)luaL_checkinteger(L, 2);
    StorageBuilding::ConsumptionItem* result = instance->_NV_getConsumtionItems(id);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int StorageBuildingBinding::limitedByType(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    bool result = instance->limitedByType();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StorageBuildingBinding::updateInventoryWindow(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    instance->updateInventoryWindow();
    return 0;
}

int StorageBuildingBinding::_NV_updateInventoryWindow(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");

    instance->_NV_updateInventoryWindow();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 48: StorageBuilding* _CONSTRUCTOR(...) - unsupported arg type
  line 59: void getItemsWeWantRidOf(...) - unsupported arg type
  line 60: void _NV_getItemsWeWantRidOf(...) - unsupported arg type
  line 66: bool canHaveSomeOfThese(...) - unsupported arg type
  line 67: bool _NV_canHaveSomeOfThese(...) - unsupported arg type
  line 68: void getResourcesNeededBecauseEmpty(...) - unsupported arg type
  line 69: void _NV_getResourcesNeededBecauseEmpty(...) - unsupported arg type
  line 70: void getResourcesNeededBecauseNotFull(...) - unsupported arg type
  line 71: void _NV_getResourcesNeededBecauseNotFull(...) - unsupported arg type
  line 84: void getConsumtionItems_inStock(...) - unsupported arg type
*/

int StorageBuildingBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int StorageBuildingBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.StorageBuilding object");
    return 1;
}

void StorageBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       StorageBuildingBinding::gc },
        { "__tostring", StorageBuildingBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", StorageBuildingBinding::_DESTRUCTOR },
        { "getFunctionStuff", StorageBuildingBinding::getFunctionStuff },
        { "_NV_getFunctionStuff", StorageBuildingBinding::_NV_getFunctionStuff },
        { "getUseableStuff", StorageBuildingBinding::getUseableStuff },
        { "_NV_getUseableStuff", StorageBuildingBinding::_NV_getUseableStuff },
        { "update", StorageBuildingBinding::update },
        { "_NV_update", StorageBuildingBinding::_NV_update },
        { "getDefaultTask", StorageBuildingBinding::getDefaultTask },
        { "_NV_getDefaultTask", StorageBuildingBinding::_NV_getDefaultTask },
        { "getProductionItemData", StorageBuildingBinding::getProductionItemData },
        { "_NV_getProductionItemData", StorageBuildingBinding::_NV_getProductionItemData },
        { "getProductionItem", StorageBuildingBinding::getProductionItem },
        { "getCurrentProductionQuantity", StorageBuildingBinding::getCurrentProductionQuantity },
        { "_NV_getCurrentProductionQuantity", StorageBuildingBinding::_NV_getCurrentProductionQuantity },
        { "isAnyInputsEmpty", StorageBuildingBinding::isAnyInputsEmpty },
        { "_NV_isAnyInputsEmpty", StorageBuildingBinding::_NV_isAnyInputsEmpty },
        { "isAnyInputsFull", StorageBuildingBinding::isAnyInputsFull },
        { "_NV_isAnyInputsFull", StorageBuildingBinding::_NV_isAnyInputsFull },
        { "isProductionFull", StorageBuildingBinding::isProductionFull },
        { "_NV_isProductionFull", StorageBuildingBinding::_NV_isProductionFull },
        { "isProductionEmpty", StorageBuildingBinding::isProductionEmpty },
        { "_NV_isProductionEmpty", StorageBuildingBinding::_NV_isProductionEmpty },
        { "getNumConsumtionItems", StorageBuildingBinding::getNumConsumtionItems },
        { "_NV_getNumConsumtionItems", StorageBuildingBinding::_NV_getNumConsumtionItems },
        { "getConsumtionItems", StorageBuildingBinding::getConsumtionItems },
        { "_NV_getConsumtionItems", StorageBuildingBinding::_NV_getConsumtionItems },
        { "limitedByType", StorageBuildingBinding::limitedByType },
        { "updateInventoryWindow", StorageBuildingBinding::updateInventoryWindow },
        { "_NV_updateInventoryWindow", StorageBuildingBinding::_NV_updateInventoryWindow },
        { 0, 0 }
    };

    registerClass(
        L, 
        StorageBuildingBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, StorageBuildingBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, StorageBuilding_get_specialItemTypesOnly);
    lua_setfield(L, -2, "specialItemTypesOnly");
    lua_pushcfunction(L, StorageBuilding_get_endOfTheLine);
    lua_setfield(L, -2, "endOfTheLine");
    lua_pushcfunction(L, StorageBuilding_get_productionItem);
    lua_setfield(L, -2, "productionItem");
    lua_pushcfunction(L, StorageBuilding_get_manyLimitItems);
    lua_setfield(L, -2, "manyLimitItems");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, StorageBuilding_set_specialItemTypesOnly);
    lua_setfield(L, -2, "specialItemTypesOnly");
    lua_pushcfunction(L, StorageBuilding_set_endOfTheLine);
    lua_setfield(L, -2, "endOfTheLine");
    lua_pushcfunction(L, StorageBuilding_set_productionItem);
    lua_setfield(L, -2, "productionItem");
    lua_pushcfunction(L, StorageBuilding_set_manyLimitItems);
    lua_setfield(L, -2, "manyLimitItems");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to UseableStuff
    // setMetatableParent(L, StorageBuildingBinding::getMetatableName(), UseableStuffBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
