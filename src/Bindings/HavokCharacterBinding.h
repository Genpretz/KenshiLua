#pragma once

#include "kenshi/HavokCharacter.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class HavokCharacterBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.HavokCharacter"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int setPosition(lua_State* L);
    static int getPosition(lua_State* L);
    static int setVelocity(lua_State* L);
    static int getVelocity(lua_State* L);
    static int getWaypointDirection(lua_State* L);
    static int getDirectionMoved(lua_State* L);
    static int setWaterModifier(lua_State* L);
    static int setManualMode(lua_State* L);
    static int setDesiredSpeed(lua_State* L);
    static int getState(lua_State* L);
    static int getPathState(lua_State* L);
    static int isOnNavmesh(lua_State* L);
    static int getClosestPoint(lua_State* L);
    static int requestPath(lua_State* L);
    static int clearPath(lua_State* L);
    static int update(lua_State* L);
    static int moveAlongPath(lua_State* L);
    static int handleCollision(lua_State* L);
    static int invalidate(lua_State* L);
    static int _getFaceKey(lua_State* L);
    static int pullThroughVertex(lua_State* L);
    static int updateNextEdge(lua_State* L);
    static int resolveProblems(lua_State* L);
    static int atGoal(lua_State* L);
    static int getCollidedCharacter(lua_State* L);
    static int setHandle(lua_State* L);
    static int calculateFuturePosition(lua_State* L);
};
}