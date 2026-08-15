#pragma once

#include "kenshi/Town.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TownBuildingsManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TownBuildingsManager"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int clear(lua_State* L);
    static int moveBuildingsTo(lua_State* L);
    static int removeBuilding(lua_State* L);
    static int setFloorVisible(lua_State* L);
    static int setAllVisible(lua_State* L);
    static int resetAllVisible(lua_State* L);
    static int setSignsVisible(lua_State* L);
    static int factoryObjectCreatedCallback(lua_State* L);
    static int _NV_factoryObjectCreatedCallback(lua_State* L);
};
}