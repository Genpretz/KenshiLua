#include "pch.h"
#include <kenshi/Building/StorageBuilding.h>
#include "StorageBuildingBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "ConsumptionItemBinding.h"
#include "Bindings/Kenshi/Building/UseableStuffBinding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"

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
    return pushObject<StorageBuilding::ConsumptionItem>(L, instance->productionItem, ConsumptionItemBinding::getMetatableName());
}

static int StorageBuilding_get_manyLimitItems(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");
    return pushObject<lektor<StorageBuilding::ConsumptionItem*>>(L, &instance->manyLimitItems, LektorPtrBinding<StorageBuilding::ConsumptionItem*>::metaName);
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
    instance->productionItem = lua_isnoneornil(L, 2) ? nullptr : checkObject<StorageBuilding::ConsumptionItem>(L, 2, ConsumptionItemBinding::getMetatableName());
    return 0;
}

static int StorageBuilding_set_manyLimitItems(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");
    auto* val = LektorPtrBinding<StorageBuilding::ConsumptionItem*>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'manyLimitItems' must be lektor<StorageBuilding::ConsumptionItem*>");
    instance->manyLimitItems = *val;
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

int StorageBuildingBinding::getItemsWeWantRidOf(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");
    lektor<GameData*>* out = LektorPtrBinding<GameData*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to getItemsWeWantRidOf must be lektor<GameData*>");
    bool forceLooting = lua_toboolean(L, 3) != 0;
    instance->getItemsWeWantRidOf(*out, forceLooting);
    return 0;
}

int StorageBuildingBinding::_NV_getItemsWeWantRidOf(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");
    lektor<GameData*>* out = LektorPtrBinding<GameData*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to _NV_getItemsWeWantRidOf must be lektor<GameData*>");
    bool forceLooting = lua_toboolean(L, 3) != 0;
    instance->_NV_getItemsWeWantRidOf(*out, forceLooting);
    return 0;
}

int StorageBuildingBinding::canHaveSomeOfThese(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");
    GameData* input = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->canHaveSomeOfThese(input);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StorageBuildingBinding::_NV_canHaveSomeOfThese(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");
    GameData* input = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->_NV_canHaveSomeOfThese(input);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StorageBuildingBinding::getResourcesNeededBecauseEmpty(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");
    lektor<GameData*>* out = LektorPtrBinding<GameData*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to getResourcesNeededBecauseEmpty must be lektor<GameData*>");
    instance->getResourcesNeededBecauseEmpty(*out);
    return 0;
}

int StorageBuildingBinding::_NV_getResourcesNeededBecauseEmpty(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");
    lektor<GameData*>* out = LektorPtrBinding<GameData*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to _NV_getResourcesNeededBecauseEmpty must be lektor<GameData*>");
    instance->_NV_getResourcesNeededBecauseEmpty(*out);
    return 0;
}

int StorageBuildingBinding::getResourcesNeededBecauseNotFull(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");
    lektor<GameData*>* out = LektorPtrBinding<GameData*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to getResourcesNeededBecauseNotFull must be lektor<GameData*>");
    instance->getResourcesNeededBecauseNotFull(*out);
    return 0;
}

int StorageBuildingBinding::_NV_getResourcesNeededBecauseNotFull(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");
    lektor<GameData*>* out = LektorPtrBinding<GameData*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to _NV_getResourcesNeededBecauseNotFull must be lektor<GameData*>");
    instance->_NV_getResourcesNeededBecauseNotFull(*out);
    return 0;
}

int StorageBuildingBinding::getConsumtionItems_inStock(lua_State* L)
{
    StorageBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StorageBuilding is nil");
    auto* out = LektorPtrBinding<StorageBuilding::ConsumptionItem*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to getConsumtionItems_inStock must be lektor<StorageBuilding::ConsumptionItem*>");
    instance->getConsumtionItems_inStock(*out);
    return 0;
}

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
        { "getItemsWeWantRidOf", StorageBuildingBinding::getItemsWeWantRidOf },
        { "_NV_getItemsWeWantRidOf", StorageBuildingBinding::_NV_getItemsWeWantRidOf },
        { "canHaveSomeOfThese", StorageBuildingBinding::canHaveSomeOfThese },
        { "_NV_canHaveSomeOfThese", StorageBuildingBinding::_NV_canHaveSomeOfThese },
        { "getResourcesNeededBecauseEmpty", StorageBuildingBinding::getResourcesNeededBecauseEmpty },
        { "_NV_getResourcesNeededBecauseEmpty", StorageBuildingBinding::_NV_getResourcesNeededBecauseEmpty },
        { "getResourcesNeededBecauseNotFull", StorageBuildingBinding::getResourcesNeededBecauseNotFull },
        { "_NV_getResourcesNeededBecauseNotFull", StorageBuildingBinding::_NV_getResourcesNeededBecauseNotFull },
        { "getConsumtionItems_inStock", StorageBuildingBinding::getConsumtionItems_inStock },
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
    registerGetter(L, "specialItemTypesOnly", StorageBuilding_get_specialItemTypesOnly);
    registerGetter(L, "endOfTheLine", StorageBuilding_get_endOfTheLine);
    registerGetter(L, "productionItem", StorageBuilding_get_productionItem);
    registerGetter(L, "manyLimitItems", StorageBuilding_get_manyLimitItems);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "specialItemTypesOnly", StorageBuilding_set_specialItemTypesOnly);
    registerSetter(L, "endOfTheLine", StorageBuilding_set_endOfTheLine);
    registerSetter(L, "productionItem", StorageBuilding_set_productionItem);
    registerSetter(L, "manyLimitItems", StorageBuilding_set_manyLimitItems);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to UseableStuff
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, StorageBuildingBinding::getMetatableName(), UseableStuffBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack

    LektorPtrBinding<StorageBuilding::ConsumptionItem*>::registerBinding(L, "lektor<StorageBuilding::ConsumptionItem*>", ConsumptionItemBinding::getMetatableName());
}

} // namespace KenshiLua