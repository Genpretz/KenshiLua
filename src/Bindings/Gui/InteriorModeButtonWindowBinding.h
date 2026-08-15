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
};
}