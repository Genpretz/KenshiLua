#pragma once

#include "kenshi/gui/InventoryGUI.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class InventoryLayoutBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.InventoryLayout"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getWindow(lua_State* L);
    static int getWidget(lua_State* L);
    static int getDatapanel(lua_State* L);
    static int _NV_getDatapanel(lua_State* L);
    static int setupDataPanelInfos(lua_State* L);
    static int createSectionGUI(lua_State* L);
    static int setSectionGUIDisabled(lua_State* L);
    static int notifyCellSizeChanged(lua_State* L);
    static int resizeSection(lua_State* L);
    static int resizeSectionWidget(lua_State* L);
    // CellSize is intentionally not bound: its static storage address is
    // game-version-specific and has not been verified for the Steam build.
};
}