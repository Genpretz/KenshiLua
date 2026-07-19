#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TownBaseBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TownBase"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int isActive(lua_State* L);
    static int _NV_isActive(lua_State* L);
    static int _reset(lua_State* L);
    static int _NV__reset(lua_State* L);
    static int getKnownName(lua_State* L);
    static int reassessTownPosition(lua_State* L);
    static int _NV_reassessTownPosition(lua_State* L);
    static int isNotFriendly(lua_State* L);
    static int _NV_isNotFriendly(lua_State* L);
    static int isPhysical(lua_State* L);
    static int _NV_isPhysical(lua_State* L);
    static int setVisible(lua_State* L);
    static int _NV_setVisible(lua_State* L);
    static int getDataType(lua_State* L);
    static int _NV_getDataType(lua_State* L);
    static int isTown(lua_State* L);
    static int _NV_isTown(lua_State* L);
    static int isOutpost(lua_State* L);
    static int withinBordersRange(lua_State* L);
    static int withinDiscoveryRange(lua_State* L);
    static int distanceTo(lua_State* L);
    static int squaredDistanceTo(lua_State* L);
    static int isDead(lua_State* L);
    static int _NV_isDead(lua_State* L);
    static int getPositionOutsideTownGates(lua_State* L);
    static int _NV_getPositionOutsideTownGates(lua_State* L);
    static int isPublic(lua_State* L);
    static int _NV_isPublic(lua_State* L);
    static int getRadius(lua_State* L);
    static int _NV_getRadius(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int _NV_periodicUpdate(lua_State* L);
    static int updatePowerGrid(lua_State* L);
    static int _NV_updatePowerGrid(lua_State* L);
    static int allBuildingsDoorsOpen(lua_State* L);
    static int _NV_allBuildingsDoorsOpen(lua_State* L);
    static int destroyPhysical(lua_State* L);
    static int _NV_destroyPhysical(lua_State* L);
    static int getPosition(lua_State* L);
    static int _NV_getPosition(lua_State* L);
    static int getPositionForWaypoint(lua_State* L);
    static int _NV_getPositionForWaypoint(lua_State* L);
    static int createPhysical(lua_State* L);
    static int _NV_createPhysical(lua_State* L);
    static int hasGates(lua_State* L);
    static int _NV_hasGates(lua_State* L);
    static int gatesAllClosed(lua_State* L);
    static int _NV_gatesAllClosed(lua_State* L);
    static int isRecentlyDiscovered(lua_State* L);
    static int _NV_isRecentlyDiscovered(lua_State* L);
    static int setRecentlyDiscovered(lua_State* L);
    static int _NV_setRecentlyDiscovered(lua_State* L);
    static int isDiscovered(lua_State* L);
    static int _NV_isDiscovered(lua_State* L);
    static int setDiscovered(lua_State* L);
    static int _NV_setDiscovered(lua_State* L);
    static int setDead(lua_State* L);
    static int _NV_setDead(lua_State* L);
    static int isExplored(lua_State* L);
    static int _NV_isExplored(lua_State* L);
    static int setExplored(lua_State* L);
    static int _NV_setExplored(lua_State* L);
    static int getItemArtifactsMinValue(lua_State* L);
    static int _NV_getItemArtifactsMinValue(lua_State* L);
    static int getItemArtifactsMaxValue(lua_State* L);
    static int _NV_getItemArtifactsMaxValue(lua_State* L);
    static int getGearArtifactsMinValue(lua_State* L);
    static int _NV_getGearArtifactsMinValue(lua_State* L);
    static int getGearArtifactsMaxValue(lua_State* L);
    static int _NV_getGearArtifactsMaxValue(lua_State* L);
    static int resetBuildingsFloorVisibility(lua_State* L);
    static int getTownFloorVisiblity(lua_State* L);
    static int setTownFloorVisiblity(lua_State* L);
    static int resetTownFloorVisibility(lua_State* L);
    static int getMapMarker(lua_State* L);
    static int _NV_getMapMarker(lua_State* L);
    static int getMapMarkerZoomLevel(lua_State* L);
    static int _NV_getMapMarkerZoomLevel(lua_State* L);
    static int isOccupied(lua_State* L);
    static int distributeArtifacts(lua_State* L);
};
}
