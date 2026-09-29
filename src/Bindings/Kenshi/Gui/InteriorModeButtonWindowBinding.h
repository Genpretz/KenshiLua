#pragma once

#include "kenshi/gui/InteriorModeButtonWindow.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class InteriorModeButtonWindowBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.InteriorModeButtonWindow"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int toggleInteriorMode(lua_State* L);
    static int setVisible(lua_State* L);
    static int wantExteriorsInvisible(lua_State* L);
    static int setSelectedBuilding(lua_State* L);
    static int getSelectedBuilding(lua_State* L);
    static int updateUsageNodes(lua_State* L);
    static int refresh(lua_State* L);
    static int activateInteriorMode(lua_State* L);
    static int confirmDeleteInteriorLayout(lua_State* L);
    static int confirmDeleteExteriorLayout(lua_State* L);
    static int setInteriorLayout(lua_State* L);
    static int setExteriorLayout(lua_State* L);
    static int recheckOutsideFurniture(lua_State* L);
    static int wasTheInteriorLoadedFromASave(lua_State* L);
    static int interiorModePressed(lua_State* L);
    static int interiorModeButtonUpdate(lua_State* L);
    static int interiorModeButtonUpdate2(lua_State* L);
    static int deleteButtonPressed(lua_State* L);
    static int deleteButtonPressed2(lua_State* L);
    static int closeWindow(lua_State* L);
    static int toggleVisButtonPressed(lua_State* L);
    static int notifyEditTextChange(lua_State* L);
    static int centerButtonPressed(lua_State* L);
    static int saveButtonPressed(lua_State* L);
    static int clearNodes(lua_State* L);
    static int clearAll(lua_State* L);
    static int listItemSelected(lua_State* L);
    static int saveButtonPressed2(lua_State* L);
    static int listItemSelected2(lua_State* L);
    static int notifyEditTextChange2(lua_State* L);
};
}