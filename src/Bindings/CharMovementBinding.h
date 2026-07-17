#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class CharMovementBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CharMovement"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int _setPositionAndTeleport(lua_State* L);
    static int _NV__setPositionAndTeleport(lua_State* L);
    static int _setPositionDirectionAndTeleport(lua_State* L);
    static int _NV__setPositionDirectionAndTeleport(lua_State* L);
    static int _setPositionSimple(lua_State* L);
    static int _NV__setPositionSimple(lua_State* L);
    static int isRunning(lua_State* L);
    static int isRunningAway(lua_State* L);
    static int trackAnimationMovement(lua_State* L);
    static int handleChanged(lua_State* L);
    static int _NV_handleChanged(lua_State* L);
    static int getRadius(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int pausedUpdate(lua_State* L);
    static int twoFrameUpdate(lua_State* L);
    static int postAnimationUpdate(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int predictNextPosition(lua_State* L);
    static int getMaximumPossibleMovement(lua_State* L);
    static int faceDirection(lua_State* L);
    static int _NV_faceDirection(lua_State* L);
    static int lookatPosition(lua_State* L);
    static int _NV_lookatPosition(lua_State* L);
    static int pathOk(lua_State* L);
    static int _NV_pathOk(lua_State* L);
    static int pathFailed(lua_State* L);
    static int _NV_pathFailed(lua_State* L);
    static int isDestinationReached(lua_State* L);
    static int _NV_isDestinationReached(lua_State* L);
    static int isIdle(lua_State* L);
    static int _NV_isIdle(lua_State* L);
    static int playerMoveOrderWhileInCombatMode(lua_State* L);
    static int _NV_playerMoveOrderWhileInCombatMode(lua_State* L);
    static int halt(lua_State* L);
    static int _NV_halt(lua_State* L);
    static int invalidatePath(lua_State* L);
    static int movedBy(lua_State* L);
    static int isCombatMovementBlockedByCharacters(lua_State* L);
    static int destroy(lua_State* L);
    static int restore(lua_State* L);
    static int refreshClickHull(lua_State* L);
    static int teleportCollisionHull(lua_State* L);
    static int getCurrentFloor(lua_State* L);
    static int isIndoorsHideMeCheck(lua_State* L);
    static int isIndoors(lua_State* L);
    static int manualMovement(lua_State* L);
    static int _NV_manualMovement(lua_State* L);
    static int isInsideBuildingLoadedInterior(lua_State* L);
    static int hasClickHull(lua_State* L);
    static int isTrackingAnimationMode(lua_State* L);
    static int isWaypointMoveMode(lua_State* L);
    static int setDirectMovement(lua_State* L);
    static int getCharacter(lua_State* L);
    static int toGround(lua_State* L);
    static int updateGroundMaterial(lua_State* L);
    static int getCombatMoveSpeedMult(lua_State* L);
};
}