#pragma once
#include "kenshi/Research.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class Research_BuildingUpgradesBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Research_BuildingUpgrades"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
};
}
