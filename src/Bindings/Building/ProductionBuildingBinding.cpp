#include "pch.h"
#include <kenshi/Building/ProductionBuilding.h>
#include "ProductionBuildingBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/InventorySectionBinding.h"
#include "Bindings/Building/StorageBuildingBinding.h"

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
    // TODO: Unsupported type for consumptionItems (lektor<StorageBuilding::ConsumptionItem>)
    return luaL_error(L, "Unsupported property 'consumptionItems' (type: lektor<StorageBuilding::ConsumptionItem>)");
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
    return luaL_error(L, "Read-only or unsupported setter type for outSection");
}

static int ProductionBuilding_set_consumptionItems(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for consumptionItems");
}

int ProductionBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    instance->_DESTRUCTOR();
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
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ProductionBuildingBinding::_NV_createInventoryLayout(lua_State* L)
{
    ProductionBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProductionBuilding is nil");

    InventoryLayout* result = instance->_NV_createInventoryLayout();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
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

/*
Skipped methods needing manual binding:
  line 72: ProductionBuilding* _CONSTRUCTOR(...) - unsupported arg type
  line 83: void operate(...) - unsupported arg type
  line 84: void _NV_operate(...) - unsupported arg type
  line 85: void getGUIData(...) - unsupported arg type
  line 86: void _NV_getGUIData(...) - unsupported arg type
  line 87: void getGUIToolTipForGroundResourceEfficiency(...) - unsupported arg type
  line 88: void _NV_getGUIToolTipForGroundResourceEfficiency(...) - unsupported arg type
  line 89: GameSaveState serialise(...) - unsupported return type
  line 90: GameSaveState _NV_serialise(...) - unsupported return type
  line 91: void loadFromSerialise(...) - unsupported arg type
  line 92: void _NV_loadFromSerialise(...) - unsupported arg type
  line 105: float getInputValue(...) - unsupported arg type
  line 106: float _NV_getInputValue(...) - unsupported arg type
  line 107: void getResourcesNeededBecauseEmpty(...) - unsupported arg type
  line 108: void _NV_getResourcesNeededBecauseEmpty(...) - unsupported arg type
  line 109: void getResourcesNeededBecauseNotFull(...) - unsupported arg type
  line 110: void _NV_getResourcesNeededBecauseNotFull(...) - unsupported arg type
  line 121: bool canHaveSomeOfThese(...) - unsupported arg type
  line 122: bool _NV_canHaveSomeOfThese(...) - unsupported arg type
  line 125: void getItemsWeWantRidOf(...) - unsupported arg type
  line 126: void _NV_getItemsWeWantRidOf(...) - unsupported arg type
  line 132: void setProductionItem(...) - unsupported arg type
  line 133: void _NV_setProductionItem(...) - unsupported arg type
  line 143: bool limitInputsOutputRate(...) - non-string reference arg
  line 144: bool _NV_limitInputsOutputRate(...) - non-string reference arg
  line 145: void getGUIFertility(...) - unsupported arg type
  line 146: void _NV_getGUIFertility(...) - unsupported arg type
  line 147: void getGUIState(...) - unsupported arg type
  line 148: void _NV_getGUIState(...) - unsupported arg type
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
        { "_DESTRUCTOR", ProductionBuildingBinding::_DESTRUCTOR },
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
    lua_pushcfunction(L, ProductionBuilding_get_productionState);
    lua_setfield(L, -2, "productionState");
    lua_pushcfunction(L, ProductionBuilding_get__resourceMiningLevel);
    lua_setfield(L, -2, "_resourceMiningLevel");
    lua_pushcfunction(L, ProductionBuilding_get_outSection);
    lua_setfield(L, -2, "outSection");
    lua_pushcfunction(L, ProductionBuilding_get_consumptionItems);
    lua_setfield(L, -2, "consumptionItems");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, ProductionBuilding_set_productionState);
    lua_setfield(L, -2, "productionState");
    lua_pushcfunction(L, ProductionBuilding_set__resourceMiningLevel);
    lua_setfield(L, -2, "_resourceMiningLevel");
    lua_pushcfunction(L, ProductionBuilding_set_outSection);
    lua_setfield(L, -2, "outSection");
    lua_pushcfunction(L, ProductionBuilding_set_consumptionItems);
    lua_setfield(L, -2, "consumptionItems");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to StorageBuilding
    setMetatableParent(L, ProductionBuildingBinding::getMetatableName(), StorageBuildingBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua