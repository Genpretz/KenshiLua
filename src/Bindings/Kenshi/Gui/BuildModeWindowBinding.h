#pragma once

#include "kenshi/gui/BuildModeWindow.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class BuildModeWindowBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.BuildModeWindow"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int setMessage(lua_State* L);
    static int getBuildingListWidget(lua_State* L);
    static int setVisible(lua_State* L);
    static int setupData(lua_State* L);
    static int listCategories(lua_State* L);
    static int listBuildingGroups(lua_State* L);
    static int updateBuildingUI(lua_State* L);
    static int build(lua_State* L);
    static int showBuildingStats(lua_State* L);
    static int update(lua_State* L);
    static int changeCurrentIndex(lua_State* L);
    static int compareBuildMaterials(lua_State* L);
    static int categorySelected(lua_State* L);
    static int buildingSelected(lua_State* L);
    static int confirm(lua_State* L);
    static int undo(lua_State* L);
    static int close(lua_State* L);
    static int buildingTypePrev(lua_State* L);
    static int buildingTypeNext(lua_State* L);
    static int changeFloorButtonUp(lua_State* L);
    static int changeFloorButtonDown(lua_State* L);
};
}