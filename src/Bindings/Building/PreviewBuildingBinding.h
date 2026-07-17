#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class PreviewBuildingBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.PreviewBuilding"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int type(lua_State* L);
    static int _NV_type(lua_State* L);
    static int checkProspectingIsNotZero(lua_State* L);
    static int _NV_checkProspectingIsNotZero(lua_State* L);
    static int isASnapToBuilding(lua_State* L);
    static int _NV_isASnapToBuilding(lua_State* L);
    static int isACeilingBuilding(lua_State* L);
    static int _NV_isACeilingBuilding(lua_State* L);
    static int snappingOk(lua_State* L);
    static int _NV_snappingOk(lua_State* L);
    static int isInteriorBuilding(lua_State* L);
    static int _NV_isInteriorBuilding(lua_State* L);
    static int isCurrent(lua_State* L);
    static int setup(lua_State* L);
    static int _NV_setup(lua_State* L);
    static int _destroyEnts(lua_State* L);
    static int _NV__destroyEnts(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int figureOutWhichTown(lua_State* L);
    static int setVisualPosition(lua_State* L);
    static int _NV_setVisualPosition(lua_State* L);
    static int yawBy(lua_State* L);
    static int yawSet(lua_State* L);
    static int rotateBy(lua_State* L);
    static int tilt(lua_State* L);
    static int roll(lua_State* L);
    static int setRotation(lua_State* L);
    static int allFootprintsWantBelowGround(lua_State* L);
    static int allFootprintsWantAboveGround(lua_State* L);
    static int updateFootprintHeights(lua_State* L);
    static int isCollisionOK(lua_State* L);
    static int _NV_isCollisionOK(lua_State* L);
    static int isFloorOk(lua_State* L);
    static int _NV_isFloorOk(lua_State* L);
    static int isIndoorsOk(lua_State* L);
    static int _NV_isIndoorsOk(lua_State* L);
    static int isNodesOk(lua_State* L);
    static int _NV_isNodesOk(lua_State* L);
    static int isBlockingBuildingsNodes(lua_State* L);
    static int _NV_isBlockingBuildingsNodes(lua_State* L);
    static int isGoodAboveAndBelow(lua_State* L);
    static int _NV_isGoodAboveAndBelow(lua_State* L);
    static int isOnValidGround(lua_State* L);
    static int _NV_isOnValidGround(lua_State* L);
    static int isLinked(lua_State* L);
    static int _NV_isLinked(lua_State* L);
    static int moveHeightOffset(lua_State* L);
    static int resetHeightOffset(lua_State* L);
    static int getFootprintShift(lua_State* L);
    static int setOrientation(lua_State* L);
    static int getPosition(lua_State* L);
    static int getFloor(lua_State* L);
    static int setStartPosition(lua_State* L);
    static int _NV_setStartPosition(lua_State* L);
    static int setEndPosition(lua_State* L);
    static int _NV_setEndPosition(lua_State* L);
    static int getEndPos(lua_State* L);
    static int _NV_getEndPos(lua_State* L);
    static int placeFinalPreviewBuilding(lua_State* L);
    static int _NV_placeFinalPreviewBuilding(lua_State* L);
    static int insideBuilding(lua_State* L);
    static int placementVerification(lua_State* L);
    static int _NV_placementVerification(lua_State* L);
    static int getGameData(lua_State* L);
    static int noAltitude(lua_State* L);
    static int _NV_noAltitude(lua_State* L);
    static int noPathfindingNeeded(lua_State* L);
    static int _NV_noPathfindingNeeded(lua_State* L);
    static int placePreview(lua_State* L);
    static int _NV_placePreview(lua_State* L);
    static int resetUseageNodes(lua_State* L);
    static int calculateRotationsAndStuff(lua_State* L);
    static int _NV_calculateRotationsAndStuff(lua_State* L);
    static int placementVerification_recurse(lua_State* L);
    static int getTerrainHeightAtCenter(lua_State* L);
    static int _NV_getTerrainHeightAtCenter(lua_State* L);
    static int recalculateWorldAABB(lua_State* L);
    static int validateUsageNodes(lua_State* L);
};
}