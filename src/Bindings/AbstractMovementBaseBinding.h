#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class AbstractMovementBaseBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AbstractMovementBase"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int create(lua_State* L);
    static int _setPositionAndTeleport(lua_State* L);
    static int _NV__setPositionAndTeleport(lua_State* L);
    static int _setPositionSimple(lua_State* L);
    static int _NV__setPositionSimple(lua_State* L);
    static int faceDirection(lua_State* L);
    static int _NV_faceDirection(lua_State* L);
    static int lookatPosition(lua_State* L);
    static int _NV_lookatPosition(lua_State* L);
    static int getDestination(lua_State* L);
    static int isProbablyStuck(lua_State* L);
    static int pathOk(lua_State* L);
    static int _NV_pathOk(lua_State* L);
    static int pathFailed(lua_State* L);
    static int _NV_pathFailed(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int isDestinationReached(lua_State* L);
    static int _NV_isDestinationReached(lua_State* L);
    static int amInsideTownWalls(lua_State* L);
    static int _NV_amInsideTownWalls(lua_State* L);
    static int manualMovement(lua_State* L);
    static int _NV_manualMovement(lua_State* L);
    static int halt(lua_State* L);
    static int _NV_halt(lua_State* L);
    static int setRoadDestination(lua_State* L);
    static int setRoadPreference(lua_State* L);
    static int setDestination(lua_State* L);
    static int _NV_setDestination(lua_State* L);
    static int setDesiredSpeed(lua_State* L);
    static int setDesiredSpeedOrders(lua_State* L);
    static int _NV_setDesiredSpeed(lua_State* L);
    static int setStandardWalkSpeed(lua_State* L);
    static int getStandardWalkSpeed(lua_State* L);
    static int restoreDesiredSpeed(lua_State* L);
    static int setMaxSpeed(lua_State* L);
    static int getMaxSpeed(lua_State* L);
    static int isCurrentlyMoving(lua_State* L);
    static int getCurrentSpeed(lua_State* L);
    static int getCurrentMotion(lua_State* L);
    static int getCurrentSpeedRelativeToMax01(lua_State* L);
    static int getSpeedOrders(lua_State* L);
    static int leaveSpeedGroup(lua_State* L);
};
}