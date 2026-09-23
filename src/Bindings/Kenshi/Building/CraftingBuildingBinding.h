#pragma once

#include "kenshi/Building/CraftingBuilding.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class CraftingBuildingBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CraftingBuilding"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int createInventoryLayout(lua_State* L);
    static int _NV_createInventoryLayout(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int operate(lua_State* L);
    static int _NV_operate(lua_State* L);
    static int givePower(lua_State* L);
    static int _NV_givePower(lua_State* L);
    static int getGUIData(lua_State* L);
    static int _NV_getGUIData(lua_State* L);
    static int serialise(lua_State* L);
    static int _NV_serialise(lua_State* L);
    static int loadFromSerialise(lua_State* L);
    static int _NV_loadFromSerialise(lua_State* L);
    static int hasCraftingQueued(lua_State* L);
    static int _NV_hasCraftingQueued(lua_State* L);
    static int isProductionFull(lua_State* L);
    static int _NV_isProductionFull(lua_State* L);
    static int getProductionItemData(lua_State* L);
    static int _NV_getProductionItemData(lua_State* L);
    static int getCurrentProductionQuantity(lua_State* L);
    static int _NV_getCurrentProductionQuantity(lua_State* L);
    static int isAnyInputsInvalidType(lua_State* L);
    static int _NV_isAnyInputsInvalidType(lua_State* L);
    static int newCraftingButton(lua_State* L);
    static int _NV_newCraftingButton(lua_State* L);
    static int addFinishedCraftItem(lua_State* L);
    static int notifyCraftFailiure(lua_State* L);
    static int tryOperate(lua_State* L);
    static int _NV_tryOperate(lua_State* L);
    static int playerManufacturerData(lua_State* L);
    static int getAvailableCrafts(lua_State* L);
    static int _addCraft(lua_State* L);
    static int _removeCraft(lua_State* L);
    static int getCraft(lua_State* L);
    static int destroyProductionItem(lua_State* L);
    static int predictCraftersBestWeapon(lua_State* L);
    static int calculateCriticalChance(lua_State* L);
    static int getCriticalSuccessWeapon(lua_State* L);
    static int getItemsWeWantRidOf(lua_State* L);
    static int _NV_getItemsWeWantRidOf(lua_State* L);
    static int canHaveSomeOfThese(lua_State* L);
    static int _NV_canHaveSomeOfThese(lua_State* L);
    static int setupFromData(lua_State* L);
    static int _NV_setupFromData(lua_State* L);
    static int updateOutput(lua_State* L);
    static int _NV_updateOutput(lua_State* L);
    static int getPlayerCraftedWeaponLevel(lua_State* L);
    static int getGUIState(lua_State* L);
    static int _NV_getGUIState(lua_State* L);
    static int updateInventoryWindow(lua_State* L);
    static int _NV_updateInventoryWindow(lua_State* L);
    static int setProductionItem(lua_State* L);
    static int _NV_setProductionItem(lua_State* L);
};
}