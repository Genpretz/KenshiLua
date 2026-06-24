#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class BuildingPlacementGroundTypeBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.BuildingPlacementGroundType"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

};
}