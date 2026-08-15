#pragma once

#include "kenshi/Platoon.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class FlockingToolsBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.FlockingTools"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int create(lua_State* L);
    static int getDistanceToClosestCharacter(lua_State* L);
    static int getOutOfTheWay(lua_State* L);
    static int setCurrentPosition(lua_State* L);
    static int getRepulsionMagnitude(lua_State* L);
    static int getRepulsionVector(lua_State* L);
    static int clampRepulsionVectorTo90Degrees(lua_State* L);
    static int calculateCurrentRepulsionVector(lua_State* L);
    static int getSensoryData(lua_State* L);
};
}