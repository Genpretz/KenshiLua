#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class InventoryGUIBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.InventoryGUI"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int show(lua_State* L);
    static int _NV_show(lua_State* L);
    static int setPositionReal(lua_State* L);
    static int _NV_setPositionReal(lua_State* L);
    static int isVisible(lua_State* L);
    static int _NV_isVisible(lua_State* L);
    static int _NV_refreshSection(lua_State* L);
    static int showBackpack(lua_State* L);
    static int getBackpack(lua_State* L);
    static int getInventory(lua_State* L);
    static int _NV_getInventory(lua_State* L);
    static int hasSameOwner(lua_State* L);
    static int getCallbackCharacter(lua_State* L);
    static int _NV_getCallbackCharacter(lua_State* L);
    static int getCallbackObject(lua_State* L);
    static int _NV_getCallbackObject(lua_State* L);
    static int getSelectedItem(lua_State* L);
    static int stealingGUIInfoUpdate(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int pickupItemToMouse(lua_State* L);
    static int getMouseItem(lua_State* L);
    static int takeCertainAmountFrom(lua_State* L);
    static int RClickAutoTrade(lua_State* L);
    static int RClickAutoTradeAll(lua_State* L);
    static int isTradingForMoney(lua_State* L);
    static int isStealing(lua_State* L);
    static int isWithinRangeToTrade(lua_State* L);
    static int setItemToPlayerPortrait(lua_State* L);
    static int playSound(lua_State* L);
    static int fencingConfirmationCallback(lua_State* L);
    static int getPlayerTradeCharacter(lua_State* L);
    static int refreshAllSections(lua_State* L);
    static int updateDatapanel(lua_State* L);
    static int rightClickAutoEquipping(lua_State* L);
    static int tryToEquip(lua_State* L);
    static int returnItem(lua_State* L);
    static int hasMouse(lua_State* L);
    static int getSectionWithMouseLocal(lua_State* L);
    static int getSlotWithMouse(lua_State* L);
};
}