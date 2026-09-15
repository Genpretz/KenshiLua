#include "pch.h"
#include <kenshi/Building/ProductionBuilding.h>
#include <kenshi/GameSaveState.h>
#include "ProductionBuildingBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/InventorySectionBinding.h"
#include "Bindings/Gui/InventoryLayoutBinding.h"
#include "Bindings/Building/StorageBuildingBinding.h"
#include "Bindings/Building/ConsumptionItemBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/Util/StringPairBinding.h"

namespace KenshiLua
{

static ProductionBuilding* getInstance(lua_State* L, int idx)
{
    return checkObject<ProductionBuilding>(L, idx, ProductionBuildingBinding::getMetatableName());
}

// --- Getters for ProductionBuilding ---
static int ProductionBuilding_get_productionState(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    lua_pushinteger(L, (lua_Integer)instance->productionState);
    return 1;
}

static int ProductionBuilding_get__resourceMiningLevel(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    lua_pushnumber(L, instance->_resourceMiningLevel);
    return 1;
}

static int ProductionBuilding_get_outSection(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    return pushObject<InventorySection>(L, instance->outSection, InventorySectionBinding::getMetatableName());
}

static int ProductionBuilding_get_consumptionItems(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    return pushObject<lektor<StorageBuilding::ConsumptionItem>>(L, &instance->consumptionItems, "lektor<StorageBuilding::ConsumptionItem>");
}

// --- Setters for ProductionBuilding ---
static int ProductionBuilding_set_productionState(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    instance->productionState = (ProductionBuilding::ProductionState)luaL_checkinteger(L, 2);
    return 0;
}

static int ProductionBuilding_set__resourceMiningLevel(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    instance->_resourceMiningLevel = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ProductionBuilding_set_outSection(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    instance->outSection = lua_isnoneornil(L, 2) ? nullptr : checkObject<InventorySection>(L, 2, InventorySectionBinding::getMetatableName());
    return 0;
}

static int ProductionBuilding_set_consumptionItems(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    auto* val = LektorValueBinding<StorageBuilding::ConsumptionItem>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'consumptionItems' must be lektor<Building::ConsumptionItem>");
    instance->consumptionItems = *val;
    return 0;
}

int ProductionBuildingBinding::getProductionBuilding(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    ProductionBuilding* result = instance->getProductionBuilding();
    return pushObject<ProductionBuilding>(L, result, ProductionBuildingBinding::getMetatableName());
}

int ProductionBuildingBinding::_NV_getProductionBuilding(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    ProductionBuilding* result = instance->_NV_getProductionBuilding();
    return pushObject<ProductionBuilding>(L, result, ProductionBuildingBinding::getMetatableName());
}

int ProductionBuildingBinding::createInventoryLayout(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    InventoryLayout* result = instance->createInventoryLayout();
    return pushObject<InventoryLayout>(L, result, InventoryLayoutBinding::getMetatableName());
}

int ProductionBuildingBinding::_NV_createInventoryLayout(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    InventoryLayout* result = instance->_NV_createInventoryLayout();
    return pushObject<InventoryLayout>(L, result, InventoryLayoutBinding::getMetatableName());
}

int ProductionBuildingBinding::update(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    instance->update();
    return 0;
}

int ProductionBuildingBinding::_NV_update(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    instance->_NV_update();
    return 0;
}

int ProductionBuildingBinding::needsUpdate(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    bool result = instance->needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::_NV_needsUpdate(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    bool result = instance->_NV_needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::getProductionMult(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    float result = instance->getProductionMult();
    lua_pushnumber(L, result);
    return 1;
}

int ProductionBuildingBinding::_NV_getProductionMult(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    float result = instance->_NV_getProductionMult();
    lua_pushnumber(L, result);
    return 1;
}

int ProductionBuildingBinding::getProductionMultForGUI(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    float result = instance->getProductionMultForGUI();
    lua_pushnumber(L, result);
    return 1;
}

int ProductionBuildingBinding::_NV_getProductionMultForGUI(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    float result = instance->_NV_getProductionMultForGUI();
    lua_pushnumber(L, result);
    return 1;
}

int ProductionBuildingBinding::setupMiningResourceLevel(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    instance->setupMiningResourceLevel();
    return 0;
}

int ProductionBuildingBinding::_NV_setupMiningResourceLevel(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    instance->_NV_setupMiningResourceLevel();
    return 0;
}

int ProductionBuildingBinding::getMiningResourceLevel(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    float result = instance->getMiningResourceLevel();
    lua_pushnumber(L, result);
    return 1;
}

int ProductionBuildingBinding::_NV_getMiningResourceLevel(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    float result = instance->_NV_getMiningResourceLevel();
    lua_pushnumber(L, result);
    return 1;
}

int ProductionBuildingBinding::getMouseCursor(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    CursorType result = instance->getMouseCursor();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ProductionBuildingBinding::_NV_getMouseCursor(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    CursorType result = instance->_NV_getMouseCursor();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ProductionBuildingBinding::getDefaultTask(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    TaskType result = instance->getDefaultTask();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ProductionBuildingBinding::_NV_getDefaultTask(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    TaskType result = instance->_NV_getDefaultTask();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ProductionBuildingBinding::isAnyInputsEmpty(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    bool result = instance->isAnyInputsEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::_NV_isAnyInputsEmpty(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    bool result = instance->_NV_isAnyInputsEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::isAnyInputsInvalidType(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    bool result = instance->isAnyInputsInvalidType();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::_NV_isAnyInputsInvalidType(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    bool result = instance->_NV_isAnyInputsInvalidType();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::isAnyInputsFull(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    bool result = instance->isAnyInputsFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::_NV_isAnyInputsFull(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    bool result = instance->_NV_isAnyInputsFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::isProductionFull(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    bool result = instance->isProductionFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::_NV_isProductionFull(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    bool result = instance->_NV_isProductionFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::isProductionEmpty(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    bool result = instance->isProductionEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::_NV_isProductionEmpty(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    bool result = instance->_NV_isProductionEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::getOutputBasedRotationSpeedMult(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    float result = instance->getOutputBasedRotationSpeedMult();
    lua_pushnumber(L, result);
    return 1;
}

int ProductionBuildingBinding::_NV_getOutputBasedRotationSpeedMult(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    float result = instance->_NV_getOutputBasedRotationSpeedMult();
    lua_pushnumber(L, result);
    return 1;
}

int ProductionBuildingBinding::getOutput(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    float result = instance->getOutput();
    lua_pushnumber(L, result);
    return 1;
}

int ProductionBuildingBinding::getNumConsumtionItems(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    int result = instance->getNumConsumtionItems();
    lua_pushinteger(L, result);
    return 1;
}

int ProductionBuildingBinding::_NV_getNumConsumtionItems(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    int result = instance->_NV_getNumConsumtionItems();
    lua_pushinteger(L, result);
    return 1;
}

int ProductionBuildingBinding::getConsumtionItems(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    int id = (int)luaL_checkinteger(L, 2);
    StorageBuilding::ConsumptionItem* result = instance->getConsumtionItems(id);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ProductionBuildingBinding::_NV_getConsumtionItems(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    int id = (int)luaL_checkinteger(L, 2);
    StorageBuilding::ConsumptionItem* result = instance->_NV_getConsumtionItems(id);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ProductionBuildingBinding::setupFromData(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    instance->setupFromData();
    return 0;
}

int ProductionBuildingBinding::_NV_setupFromData(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    instance->_NV_setupFromData();
    return 0;
}

int ProductionBuildingBinding::updateInventoryWindow(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    instance->updateInventoryWindow();
    return 0;
}

int ProductionBuildingBinding::_NV_updateInventoryWindow(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    instance->_NV_updateInventoryWindow();
    return 0;
}

int ProductionBuildingBinding::updateInputs(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    instance->updateInputs(rate);
    return 0;
}

int ProductionBuildingBinding::_NV_updateInputs(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    instance->_NV_updateInputs(rate);
    return 0;
}

int ProductionBuildingBinding::updateOutput(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    instance->updateOutput(rate);
    return 0;
}

int ProductionBuildingBinding::_NV_updateOutput(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    instance->_NV_updateOutput(rate);
    return 0;
}

int ProductionBuildingBinding::limitInputsOutputRate(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    bool result = instance->limitInputsOutputRate(rate);
    lua_pushboolean(L, result ? 1 : 0);
    lua_pushnumber(L, rate);
    return 2;
}

int ProductionBuildingBinding::_NV_limitInputsOutputRate(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    bool result = instance->_NV_limitInputsOutputRate(rate);
    lua_pushboolean(L, result ? 1 : 0);
    lua_pushnumber(L, rate);
    return 2;
}

int ProductionBuildingBinding::operate(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float amount = (float)luaL_checknumber(L, 3);
    instance->operate(who, amount);
    return 0;
}

int ProductionBuildingBinding::_NV_operate(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float amount = (float)luaL_checknumber(L, 3);
    instance->_NV_operate(who, amount);
    return 0;
}

int ProductionBuildingBinding::getGUIData(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIData(datapanel, category);
    return 0;
}

int ProductionBuildingBinding::_NV_getGUIData(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIData(datapanel, category);
    return 0;
}

int ProductionBuildingBinding::getGUIToolTipForGroundResourceEfficiency(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    lektor<StringPair>* out = LektorValueBinding<StringPair>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 must be lektor<StringPair>");
    instance->getGUIToolTipForGroundResourceEfficiency(*out);
    return 0;
}

int ProductionBuildingBinding::_NV_getGUIToolTipForGroundResourceEfficiency(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    lektor<StringPair>* out = LektorValueBinding<StringPair>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 must be lektor<StringPair>");
    instance->_NV_getGUIToolTipForGroundResourceEfficiency(*out);
    return 0;
}

int ProductionBuildingBinding::loadFromSerialise(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->loadFromSerialise(state);
    return 0;
}

int ProductionBuildingBinding::_NV_loadFromSerialise(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->_NV_loadFromSerialise(state);
    return 0;
}

int ProductionBuildingBinding::getInputValue(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    float result = instance->getInputValue(item);
    lua_pushnumber(L, result);
    return 1;
}

int ProductionBuildingBinding::_NV_getInputValue(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    float result = instance->_NV_getInputValue(item);
    lua_pushnumber(L, result);
    return 1;
}

int ProductionBuildingBinding::getResourcesNeededBecauseEmpty(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    lektor<GameData*>* out = LektorPtrBinding<GameData*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to getResourcesNeededBecauseEmpty must be lektor<GameData*>");
    instance->getResourcesNeededBecauseEmpty(*out);
    return 0;
}

int ProductionBuildingBinding::_NV_getResourcesNeededBecauseEmpty(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    lektor<GameData*>* out = LektorPtrBinding<GameData*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to _NV_getResourcesNeededBecauseEmpty must be lektor<GameData*>");
    instance->_NV_getResourcesNeededBecauseEmpty(*out);
    return 0;
}

int ProductionBuildingBinding::getResourcesNeededBecauseNotFull(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    lektor<GameData*>* out = LektorPtrBinding<GameData*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to getResourcesNeededBecauseNotFull must be lektor<GameData*>");
    instance->getResourcesNeededBecauseNotFull(*out);
    return 0;
}

int ProductionBuildingBinding::_NV_getResourcesNeededBecauseNotFull(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    lektor<GameData*>* out = LektorPtrBinding<GameData*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to _NV_getResourcesNeededBecauseNotFull must be lektor<GameData*>");
    instance->_NV_getResourcesNeededBecauseNotFull(*out);
    return 0;
}

int ProductionBuildingBinding::canHaveSomeOfThese(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    GameData* these = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->canHaveSomeOfThese(these);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::_NV_canHaveSomeOfThese(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    GameData* these = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->_NV_canHaveSomeOfThese(these);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::getItemsWeWantRidOf(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    lektor<GameData*>* out = LektorPtrBinding<GameData*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to getItemsWeWantRidOf must be lektor<GameData*>");
    bool loot = lua_toboolean(L, 3) != 0;
    instance->getItemsWeWantRidOf(*out, loot);
    return 0;
}

int ProductionBuildingBinding::_NV_getItemsWeWantRidOf(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    lektor<GameData*>* out = LektorPtrBinding<GameData*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to _NV_getItemsWeWantRidOf must be lektor<GameData*>");
    bool loot = lua_toboolean(L, 3) != 0;
    instance->_NV_getItemsWeWantRidOf(*out, loot);
    return 0;
}

int ProductionBuildingBinding::setProductionItem(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    GameData* itemData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int stack = (int)luaL_checkinteger(L, 3);
    float progress = (float)luaL_checknumber(L, 4);
    instance->setProductionItem(itemData, stack, progress);
    return 0;
}

int ProductionBuildingBinding::_NV_setProductionItem(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    GameData* itemData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int stack = (int)luaL_checkinteger(L, 3);
    float progress = (float)luaL_checknumber(L, 4);
    instance->_NV_setProductionItem(itemData, stack, progress);
    return 0;
}

int ProductionBuildingBinding::getGUIFertility(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIFertility(datapanel, category);
    return 0;
}

int ProductionBuildingBinding::_NV_getGUIFertility(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIFertility(datapanel, category);
    return 0;
}

int ProductionBuildingBinding::getGUIState(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIState(datapanel, category);
    return 0;
}

int ProductionBuildingBinding::_NV_getGUIState(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIState(datapanel, category);
    return 0;
}

int ProductionBuildingBinding::serialise(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* refList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    PosRotPair* offset = (PosRotPair*)lua_touserdata(L, 4);
    GameSaveState result = instance->serialise(container, refList, offset);
    return pushValue<GameSaveState>(L, result, GameSaveStateBinding::getMetatableName());
}

int ProductionBuildingBinding::_NV_serialise(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* refList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    PosRotPair* offset = (PosRotPair*)lua_touserdata(L, 4);
    GameSaveState result = instance->_NV_serialise(container, refList, offset);
    return pushValue<GameSaveState>(L, result, GameSaveStateBinding::getMetatableName());
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - ProductionBuildingBinding::serialise / _NV_serialise: PosRotPair* (unbound pointer)
*/

int ProductionBuildingBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ProductionBuildingBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ProductionBuilding object");
    return 1;
}

void ProductionBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ProductionBuildingBinding::gc },
        { "__tostring", ProductionBuildingBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getProductionBuilding", ProductionBuildingBinding::getProductionBuilding },
        { "_NV_getProductionBuilding", ProductionBuildingBinding::_NV_getProductionBuilding },
        { "createInventoryLayout", ProductionBuildingBinding::createInventoryLayout },
        { "_NV_createInventoryLayout", ProductionBuildingBinding::_NV_createInventoryLayout },
        { "update", ProductionBuildingBinding::update },
        { "_NV_update", ProductionBuildingBinding::_NV_update },
        { "needsUpdate", ProductionBuildingBinding::needsUpdate },
        { "_NV_needsUpdate", ProductionBuildingBinding::_NV_needsUpdate },
        { "getProductionMult", ProductionBuildingBinding::getProductionMult },
        { "_NV_getProductionMult", ProductionBuildingBinding::_NV_getProductionMult },
        { "getProductionMultForGUI", ProductionBuildingBinding::getProductionMultForGUI },
        { "_NV_getProductionMultForGUI", ProductionBuildingBinding::_NV_getProductionMultForGUI },
        { "setupMiningResourceLevel", ProductionBuildingBinding::setupMiningResourceLevel },
        { "_NV_setupMiningResourceLevel", ProductionBuildingBinding::_NV_setupMiningResourceLevel },
        { "getMiningResourceLevel", ProductionBuildingBinding::getMiningResourceLevel },
        { "_NV_getMiningResourceLevel", ProductionBuildingBinding::_NV_getMiningResourceLevel },
        { "getMouseCursor", ProductionBuildingBinding::getMouseCursor },
        { "_NV_getMouseCursor", ProductionBuildingBinding::_NV_getMouseCursor },
        { "getDefaultTask", ProductionBuildingBinding::getDefaultTask },
        { "_NV_getDefaultTask", ProductionBuildingBinding::_NV_getDefaultTask },
        { "isAnyInputsEmpty", ProductionBuildingBinding::isAnyInputsEmpty },
        { "_NV_isAnyInputsEmpty", ProductionBuildingBinding::_NV_isAnyInputsEmpty },
        { "isAnyInputsInvalidType", ProductionBuildingBinding::isAnyInputsInvalidType },
        { "_NV_isAnyInputsInvalidType", ProductionBuildingBinding::_NV_isAnyInputsInvalidType },
        { "isAnyInputsFull", ProductionBuildingBinding::isAnyInputsFull },
        { "_NV_isAnyInputsFull", ProductionBuildingBinding::_NV_isAnyInputsFull },
        { "isProductionFull", ProductionBuildingBinding::isProductionFull },
        { "_NV_isProductionFull", ProductionBuildingBinding::_NV_isProductionFull },
        { "isProductionEmpty", ProductionBuildingBinding::isProductionEmpty },
        { "_NV_isProductionEmpty", ProductionBuildingBinding::_NV_isProductionEmpty },
        { "getOutputBasedRotationSpeedMult", ProductionBuildingBinding::getOutputBasedRotationSpeedMult },
        { "_NV_getOutputBasedRotationSpeedMult", ProductionBuildingBinding::_NV_getOutputBasedRotationSpeedMult },
        { "getOutput", ProductionBuildingBinding::getOutput },
        { "getNumConsumtionItems", ProductionBuildingBinding::getNumConsumtionItems },
        { "_NV_getNumConsumtionItems", ProductionBuildingBinding::_NV_getNumConsumtionItems },
        { "getConsumtionItems", ProductionBuildingBinding::getConsumtionItems },
        { "_NV_getConsumtionItems", ProductionBuildingBinding::_NV_getConsumtionItems },
        { "setupFromData", ProductionBuildingBinding::setupFromData },
        { "_NV_setupFromData", ProductionBuildingBinding::_NV_setupFromData },
        { "updateInventoryWindow", ProductionBuildingBinding::updateInventoryWindow },
        { "_NV_updateInventoryWindow", ProductionBuildingBinding::_NV_updateInventoryWindow },
        { "updateInputs", ProductionBuildingBinding::updateInputs },
        { "_NV_updateInputs", ProductionBuildingBinding::_NV_updateInputs },
        { "updateOutput", ProductionBuildingBinding::updateOutput },
        { "_NV_updateOutput", ProductionBuildingBinding::_NV_updateOutput },
        { "serialise", ProductionBuildingBinding::serialise },
        { "_NV_serialise", ProductionBuildingBinding::_NV_serialise },
        { "limitInputsOutputRate", ProductionBuildingBinding::limitInputsOutputRate },
        { "_NV_limitInputsOutputRate", ProductionBuildingBinding::_NV_limitInputsOutputRate },
        { "operate", ProductionBuildingBinding::operate },
        { "_NV_operate", ProductionBuildingBinding::_NV_operate },
        { "getGUIData", ProductionBuildingBinding::getGUIData },
        { "_NV_getGUIData", ProductionBuildingBinding::_NV_getGUIData },
        { "getGUIToolTipForGroundResourceEfficiency", ProductionBuildingBinding::getGUIToolTipForGroundResourceEfficiency },
        { "_NV_getGUIToolTipForGroundResourceEfficiency", ProductionBuildingBinding::_NV_getGUIToolTipForGroundResourceEfficiency },
        { "loadFromSerialise", ProductionBuildingBinding::loadFromSerialise },
        { "_NV_loadFromSerialise", ProductionBuildingBinding::_NV_loadFromSerialise },
        { "getInputValue", ProductionBuildingBinding::getInputValue },
        { "_NV_getInputValue", ProductionBuildingBinding::_NV_getInputValue },
        { "getResourcesNeededBecauseEmpty", ProductionBuildingBinding::getResourcesNeededBecauseEmpty },
        { "_NV_getResourcesNeededBecauseEmpty", ProductionBuildingBinding::_NV_getResourcesNeededBecauseEmpty },
        { "getResourcesNeededBecauseNotFull", ProductionBuildingBinding::getResourcesNeededBecauseNotFull },
        { "_NV_getResourcesNeededBecauseNotFull", ProductionBuildingBinding::_NV_getResourcesNeededBecauseNotFull },
        { "canHaveSomeOfThese", ProductionBuildingBinding::canHaveSomeOfThese },
        { "_NV_canHaveSomeOfThese", ProductionBuildingBinding::_NV_canHaveSomeOfThese },
        { "getItemsWeWantRidOf", ProductionBuildingBinding::getItemsWeWantRidOf },
        { "_NV_getItemsWeWantRidOf", ProductionBuildingBinding::_NV_getItemsWeWantRidOf },
        { "setProductionItem", ProductionBuildingBinding::setProductionItem },
        { "_NV_setProductionItem", ProductionBuildingBinding::_NV_setProductionItem },
        { "getGUIFertility", ProductionBuildingBinding::getGUIFertility },
        { "_NV_getGUIFertility", ProductionBuildingBinding::_NV_getGUIFertility },
        { "getGUIState", ProductionBuildingBinding::getGUIState },
        { "_NV_getGUIState", ProductionBuildingBinding::_NV_getGUIState },
        { 0, 0 }
    };

    registerClass(
        L, 
        ProductionBuildingBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ProductionBuildingBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "productionState", ProductionBuilding_get_productionState);
    registerGetter(L, "_resourceMiningLevel", ProductionBuilding_get__resourceMiningLevel);
    registerGetter(L, "outSection", ProductionBuilding_get_outSection);
    registerGetter(L, "consumptionItems", ProductionBuilding_get_consumptionItems);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "productionState", ProductionBuilding_set_productionState);
    registerSetter(L, "_resourceMiningLevel", ProductionBuilding_set__resourceMiningLevel);
    registerSetter(L, "outSection", ProductionBuilding_set_outSection);
    registerSetter(L, "consumptionItems", ProductionBuilding_set_consumptionItems);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to StorageBuilding
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, ProductionBuildingBinding::getMetatableName(), StorageBuildingBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack

    LektorValueBinding<StorageBuilding::ConsumptionItem>::registerBinding(L, "lektor<Building::ConsumptionItem>", ConsumptionItemBinding::getMetatableName());
}

} // namespace KenshiLua
