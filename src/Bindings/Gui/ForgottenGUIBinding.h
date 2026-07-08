#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ForgottenGUIBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ForgottenGUI"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int clearGUI(lua_State* L);
    static int shutDown(lua_State* L);
    static int restart(lua_State* L);
    static int setupGuiScaling(lua_State* L);
    static int init(lua_State* L);
    static int getTopOfScreenMessagePosition(lua_State* L);
    static int showLoadingMessage(lua_State* L);
    static int isLoadingMessageVisible(lua_State* L);
    static int showPauseMessage(lua_State* L);
    static int isLoading(lua_State* L);
    static int setLoading(lua_State* L);
    static int isPaused(lua_State* L);
    static int inDialogue(lua_State* L);
    static int hideMessageBox(lua_State* L);
    static int hasModalMessage(lua_State* L);
    static int showMainbar(lua_State* L);
    static int updateBountyPanelVisibility(lua_State* L);
    static int getInDialogue(lua_State* L);
    static int getToolTip(lua_State* L);
    static int isVisible(lua_State* L);
    static int toggle(lua_State* L);
    static int showNames(lua_State* L);
    static int showPrintOutput(lua_State* L);
    static int closeCharacterEditor(lua_State* L);
    static int isCharacterEditorMode(lua_State* L);
    static int closeAllCharacterStatsWindows(lua_State* L);
    static int isStatsWindowOpen(lua_State* L);
    static int characterStatsWindowVisible(lua_State* L);
    static int selectedObjectsChanged(lua_State* L);
    static int updateToOrdersPanel(lua_State* L);
    static int update(lua_State* L);
    static int closeTradeWindow(lua_State* L);
    static int closeInventoryBuilding(lua_State* L);
    static int closeAllInventories(lua_State* L);
    static int closeAllWindows(lua_State* L);
    static int getNumOpenInventoryWindows(lua_State* L);
    static int getInventoryWindowWithMouse(lua_State* L);
    static int isAnyInventoryWindowOpen(lua_State* L);
    static int toggleHelpWindow(lua_State* L);
    static int setMouseCursorVisible(lua_State* L);
    static int getGuiManager(lua_State* L);
    static int createPanel(lua_State* L);
    static int createPanelAbs(lua_State* L);
    static int createTabPanel(lua_State* L);
    static int createFloatingImage(lua_State* L);
    static int createFloatingImageAbs(lua_State* L);
    static int createFloatingProgressBar(lua_State* L);
    static int createScreenLabelD(lua_State* L);
};
}