#include "pch.h"
#include "Bindings/Building/ProductionBuildingBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Building/ProductionBuilding.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static ProductionBuilding* getS(lua_State* L, int idx)
{
    return checkObject<ProductionBuilding>(L, idx, ProductionBuildingBinding::getMetatableName());
}

int ProductionBuildingBinding::gc(lua_State* L) { return noopGc(L); }

int ProductionBuildingBinding::tostring(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int ProductionBuildingBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, ProductionBuildingBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    ProductionBuilding* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "productionState") == 0) { lua_pushinteger(L, (lua_Integer)s->productionState); return 1; }
    if (strcmp(key, "_resourceMiningLevel") == 0) { lua_pushnumber(L, s->_resourceMiningLevel); return 1; }
    if (strcmp(key, "outSection") == 0) { return pushObject<InventorySection>(L, s->outSection, InventorySectionBinding::getMetatableName()); }
    // TODO lektor<StorageBuilding::ConsumptionItem> consumptionItems; unsupported __index type from header line 151

    lua_pushnil(L);
    return 1;
}

int ProductionBuildingBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    if (strcmp(key, "productionState") == 0) { s->productionState = (ProductionBuilding::ProductionState)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "_resourceMiningLevel") == 0) { s->_resourceMiningLevel = (float)luaL_checknumber(L, 3); return 0; }
    // TODO InventorySection* outSection; unsupported __newindex type from header line 150
    // TODO lektor<StorageBuilding::ConsumptionItem> consumptionItems; unsupported __newindex type from header line 151

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int ProductionBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    s->_DESTRUCTOR();
    return 0;
}

int ProductionBuildingBinding::update(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    s->update();
    return 0;
}

int ProductionBuildingBinding::_NV_update(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    s->_NV_update();
    return 0;
}

int ProductionBuildingBinding::needsUpdate(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    bool result = s->needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::_NV_needsUpdate(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    bool result = s->_NV_needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::getProductionMult(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    float result = s->getProductionMult();
    lua_pushnumber(L, result);
    return 1;
}

int ProductionBuildingBinding::_NV_getProductionMult(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    float result = s->_NV_getProductionMult();
    lua_pushnumber(L, result);
    return 1;
}

int ProductionBuildingBinding::getProductionMultForGUI(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    float result = s->getProductionMultForGUI();
    lua_pushnumber(L, result);
    return 1;
}

int ProductionBuildingBinding::_NV_getProductionMultForGUI(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    float result = s->_NV_getProductionMultForGUI();
    lua_pushnumber(L, result);
    return 1;
}

int ProductionBuildingBinding::setupMiningResourceLevel(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    s->setupMiningResourceLevel();
    return 0;
}

int ProductionBuildingBinding::_NV_setupMiningResourceLevel(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    s->_NV_setupMiningResourceLevel();
    return 0;
}

int ProductionBuildingBinding::getMiningResourceLevel(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    float result = s->getMiningResourceLevel();
    lua_pushnumber(L, result);
    return 1;
}

int ProductionBuildingBinding::_NV_getMiningResourceLevel(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    float result = s->_NV_getMiningResourceLevel();
    lua_pushnumber(L, result);
    return 1;
}

int ProductionBuildingBinding::isAnyInputsEmpty(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    bool result = s->isAnyInputsEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::_NV_isAnyInputsEmpty(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    bool result = s->_NV_isAnyInputsEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::isAnyInputsInvalidType(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    bool result = s->isAnyInputsInvalidType();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::_NV_isAnyInputsInvalidType(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    bool result = s->_NV_isAnyInputsInvalidType();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::isAnyInputsFull(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    bool result = s->isAnyInputsFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::_NV_isAnyInputsFull(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    bool result = s->_NV_isAnyInputsFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::isProductionFull(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    bool result = s->isProductionFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::_NV_isProductionFull(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    bool result = s->_NV_isProductionFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::isProductionEmpty(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    bool result = s->isProductionEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::_NV_isProductionEmpty(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    bool result = s->_NV_isProductionEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProductionBuildingBinding::getOutputBasedRotationSpeedMult(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    float result = s->getOutputBasedRotationSpeedMult();
    lua_pushnumber(L, result);
    return 1;
}

int ProductionBuildingBinding::_NV_getOutputBasedRotationSpeedMult(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    float result = s->_NV_getOutputBasedRotationSpeedMult();
    lua_pushnumber(L, result);
    return 1;
}

int ProductionBuildingBinding::getOutput(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    float result = s->getOutput();
    lua_pushnumber(L, result);
    return 1;
}

int ProductionBuildingBinding::getNumConsumtionItems(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    int result = s->getNumConsumtionItems();
    lua_pushinteger(L, result);
    return 1;
}

int ProductionBuildingBinding::_NV_getNumConsumtionItems(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    int result = s->_NV_getNumConsumtionItems();
    lua_pushinteger(L, result);
    return 1;
}

int ProductionBuildingBinding::getConsumtionItems(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    int id = (int)luaL_checkinteger(L, 2);
    StorageBuilding::ConsumptionItem result = s->getConsumtionItems(id);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ProductionBuildingBinding::_NV_getConsumtionItems(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    int id = (int)luaL_checkinteger(L, 2);
    StorageBuilding::ConsumptionItem result = s->_NV_getConsumtionItems(id);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ProductionBuildingBinding::setupFromData(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    s->setupFromData();
    return 0;
}

int ProductionBuildingBinding::_NV_setupFromData(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    s->_NV_setupFromData();
    return 0;
}

int ProductionBuildingBinding::updateInventoryWindow(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    s->updateInventoryWindow();
    return 0;
}

int ProductionBuildingBinding::_NV_updateInventoryWindow(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    s->_NV_updateInventoryWindow();
    return 0;
}

int ProductionBuildingBinding::updateInputs(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    s->updateInputs(rate);
    return 0;
}

int ProductionBuildingBinding::_NV_updateInputs(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    s->_NV_updateInputs(rate);
    return 0;
}

int ProductionBuildingBinding::updateOutput(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    s->updateOutput(rate);
    return 0;
}

int ProductionBuildingBinding::_NV_updateOutput(lua_State* L)
{
    ProductionBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ProductionBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    s->_NV_updateOutput(rate);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 72: ProductionBuilding* _CONSTRUCTOR(...) - unsupported return type
  line 75: ProductionBuilding* getProductionBuilding(...) - unsupported return type
  line 76: ProductionBuilding* _NV_getProductionBuilding(...) - unsupported return type
  line 77: InventoryLayout* createInventoryLayout(...) - unsupported return type
  line 78: InventoryLayout* _NV_createInventoryLayout(...) - unsupported return type
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
  line 101: CursorType getMouseCursor(...) - unsupported return type
  line 102: CursorType _NV_getMouseCursor(...) - unsupported return type
  line 103: TaskType getDefaultTask(...) - unsupported return type
  line 104: TaskType _NV_getDefaultTask(...) - unsupported return type
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

void ProductionBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ProductionBuildingBinding::gc },
        { "__tostring", ProductionBuildingBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", ProductionBuildingBinding::_DESTRUCTOR },
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
    registerClass(L, ProductionBuildingBinding::getMetatableName(), meta, methods, ProductionBuildingBinding::index, ProductionBuildingBinding::newindex);
}

} // namespace KenshiLua