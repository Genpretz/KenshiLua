#pragma once

#include "kenshi/gui/MainBarGUI.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class MainBarGUIBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MainBarGUI"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int clear(lua_State* L);
    static int _NV_clear(lua_State* L);
    static int show(lua_State* L);
    static int _NV_show(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int speedChanged(lua_State* L);
    static int updateBountyPanelVisibility(lua_State* L);
    static int _NV_updateBountyPanelVisibility(lua_State* L);
    static int setLevelEditMode(lua_State* L);
    static int setLevelEditInteriorMode(lua_State* L);
    static int pressedKey(lua_State* L);
    static int platoonUpdated(lua_State* L);
    static int updatePotraitsPlatoon(lua_State* L);
    static int updatePortraits(lua_State* L);
    static int refreshPortraitTabs(lua_State* L);
    static int updatePortraitSize(lua_State* L);
    static int getPausePanel(lua_State* L);
    static int getLoadingPanel(lua_State* L);
    static int getMedicalPanel(lua_State* L);
    static int ordersPanelClear(lua_State* L);
    static int getToolTip(lua_State* L);
    static int _NV_getToolTip(lua_State* L);
    static int getDatapanel(lua_State* L);
    static int setMessagePosition(lua_State* L);
    static int serialise(lua_State* L);
    static int loadFromSerialise(lua_State* L);
    static int setExtendInfoPanelEnabled(lua_State* L);
    static int _getWidget(lua_State* L);
    static int autoChangeSelectedObject(lua_State* L);
    static int _NV_autoChangeSelectedObject(lua_State* L);
    static int getPortrait(lua_State* L);
    static int updatePortrait(lua_State* L);
    static int closeMapWindow(lua_State* L);
    static int toggleMapWindow(lua_State* L);
    static int toggleFactionWindow(lua_State* L);
    static int toggleTechWindow(lua_State* L);
    static int toggleCraftWindow(lua_State* L);
    static int toggleSquadWindow(lua_State* L);
    static int changeFloorButtonUp(lua_State* L);
    static int changeFloorButtonDown(lua_State* L);
    static int ordersPanelFill(lua_State* L);
    static int getBuildingInventoryPosition(lua_State* L);
    static int getTabPlatoonPortrait(lua_State* L);
    static int extendInfoPanel(lua_State* L);
    static int toggleInventory(lua_State* L);
    static int toggleStatsWindow(lua_State* L);
    static int toggleHelpWindow(lua_State* L);
    static int changeSpeed(lua_State* L);
    static int buildButton(lua_State* L);
};
}