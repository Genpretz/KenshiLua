#pragma once

#include "kenshi/Building/ProductionBuilding.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ProductionBuildingBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ProductionBuilding"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getProductionBuilding(lua_State* L);
    static int _NV_getProductionBuilding(lua_State* L);
    static int createInventoryLayout(lua_State* L);
    static int _NV_createInventoryLayout(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int needsUpdate(lua_State* L);
    static int _NV_needsUpdate(lua_State* L);
    static int getProductionMult(lua_State* L);
    static int _NV_getProductionMult(lua_State* L);
    static int getProductionMultForGUI(lua_State* L);
    static int _NV_getProductionMultForGUI(lua_State* L);
    static int setupMiningResourceLevel(lua_State* L);
    static int _NV_setupMiningResourceLevel(lua_State* L);
    static int getMiningResourceLevel(lua_State* L);
    static int _NV_getMiningResourceLevel(lua_State* L);
    static int getMouseCursor(lua_State* L);
    static int _NV_getMouseCursor(lua_State* L);
    static int getDefaultTask(lua_State* L);
    static int _NV_getDefaultTask(lua_State* L);
    static int isAnyInputsEmpty(lua_State* L);
    static int _NV_isAnyInputsEmpty(lua_State* L);
    static int isAnyInputsInvalidType(lua_State* L);
    static int _NV_isAnyInputsInvalidType(lua_State* L);
    static int isAnyInputsFull(lua_State* L);
    static int _NV_isAnyInputsFull(lua_State* L);
    static int isProductionFull(lua_State* L);
    static int _NV_isProductionFull(lua_State* L);
    static int isProductionEmpty(lua_State* L);
    static int _NV_isProductionEmpty(lua_State* L);
    static int getOutputBasedRotationSpeedMult(lua_State* L);
    static int _NV_getOutputBasedRotationSpeedMult(lua_State* L);
    static int getOutput(lua_State* L);
    static int getNumConsumtionItems(lua_State* L);
    static int _NV_getNumConsumtionItems(lua_State* L);
    static int getConsumtionItems(lua_State* L);
    static int _NV_getConsumtionItems(lua_State* L);
    static int setupFromData(lua_State* L);
    static int _NV_setupFromData(lua_State* L);
    static int updateInventoryWindow(lua_State* L);
    static int _NV_updateInventoryWindow(lua_State* L);
    static int updateInputs(lua_State* L);
    static int _NV_updateInputs(lua_State* L);
    static int updateOutput(lua_State* L);
    static int _NV_updateOutput(lua_State* L);
    static int serialise(lua_State* L);
    static int _NV_serialise(lua_State* L);
    static int limitInputsOutputRate(lua_State* L);
    static int _NV_limitInputsOutputRate(lua_State* L);
    static int operate(lua_State* L);
    static int _NV_operate(lua_State* L);
    static int getGUIData(lua_State* L);
    static int _NV_getGUIData(lua_State* L);
    static int getGUIToolTipForGroundResourceEfficiency(lua_State* L);
    static int _NV_getGUIToolTipForGroundResourceEfficiency(lua_State* L);
    static int loadFromSerialise(lua_State* L);
    static int _NV_loadFromSerialise(lua_State* L);
    static int getInputValue(lua_State* L);
    static int _NV_getInputValue(lua_State* L);
    static int getResourcesNeededBecauseEmpty(lua_State* L);
    static int _NV_getResourcesNeededBecauseEmpty(lua_State* L);
    static int getResourcesNeededBecauseNotFull(lua_State* L);
    static int _NV_getResourcesNeededBecauseNotFull(lua_State* L);
    static int canHaveSomeOfThese(lua_State* L);
    static int _NV_canHaveSomeOfThese(lua_State* L);
    static int getItemsWeWantRidOf(lua_State* L);
    static int _NV_getItemsWeWantRidOf(lua_State* L);
    static int setProductionItem(lua_State* L);
    static int _NV_setProductionItem(lua_State* L);
    static int getGUIFertility(lua_State* L);
    static int _NV_getGUIFertility(lua_State* L);
    static int getGUIState(lua_State* L);
    static int _NV_getGUIState(lua_State* L);
};
}