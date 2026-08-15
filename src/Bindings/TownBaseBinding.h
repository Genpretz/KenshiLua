#pragma once

#include "kenshi/Town.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    typedef TownBase::ResidentData ResidentData;

class TownBaseBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TownBase"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int _NV__nestUpThisSpot(lua_State* L);
    static int _NV__reset(lua_State* L);
    static int _NV_activate(lua_State* L);
    static int _NV_allBuildingsDoorsOpen(lua_State* L);
    static int _NV_createPhysical(lua_State* L);
    static int _NV_destroyPhysical(lua_State* L);
    static int _NV_findAllBuildingsOfType(lua_State* L);
    static int _NV_findAllBuildingsWithFunction(lua_State* L);
    static int _NV_gatesAllClosed(lua_State* L);
    static int _NV_getAlarmMgr(lua_State* L);
    static int _NV_getBiome(lua_State* L);
    static int _NV_getCurrentTownLocation(lua_State* L);
    static int _NV_getDataType(lua_State* L);
    static int _NV_getGUIData(lua_State* L);
    static int _NV_getGearArtifactsMaxValue(lua_State* L);
    static int _NV_getGearArtifactsMinValue(lua_State* L);
    static int _NV_getItemArtifactsMaxValue(lua_State* L);
    static int _NV_getItemArtifactsMinValue(lua_State* L);
    static int _NV_getMapMarker(lua_State* L);
    static int _NV_getMapMarkerZoomLevel(lua_State* L);
    static int _NV_getNearestGate(lua_State* L);
    static int _NV_getPosition(lua_State* L);
    static int _NV_getPositionForWaypoint(lua_State* L);
    static int _NV_getPositionOutsideTownGates(lua_State* L);
    static int _NV_getRadius(lua_State* L);
    static int _NV_hasGates(lua_State* L);
    static int _NV_hasResidentHQ(lua_State* L);
    static int _NV_isActive(lua_State* L);
    static int _NV_isDead(lua_State* L);
    static int _NV_isDiscovered(lua_State* L);
    static int _NV_isExplored(lua_State* L);
    static int _NV_isIllegal(lua_State* L);
    static int _NV_isNotFriendly(lua_State* L);
    static int _NV_isPhysical(lua_State* L);
    static int _NV_isPublic(lua_State* L);
    static int _NV_isRecentlyDiscovered(lua_State* L);
    static int _NV_isTown(lua_State* L);
    static int _NV_loadFromSerialise(lua_State* L);
    static int _NV_loadState(lua_State* L);
    static int _NV_nestUpThisSpot(lua_State* L);
    static int _NV_periodicUpdate(lua_State* L);
    static int _NV_reassessTownPosition(lua_State* L);
    static int _NV_saveState(lua_State* L);
    static int _NV_setDead(lua_State* L);
    static int _NV_setDiscovered(lua_State* L);
    static int _NV_setExplored(lua_State* L);
    static int _NV_setFaction(lua_State* L);
    static int _NV_setRecentlyDiscovered(lua_State* L);
    static int _NV_setVisible(lua_State* L);
    static int _NV_setup(lua_State* L);
    static int _NV_update(lua_State* L);
    static int _NV_updatePowerGrid(lua_State* L);
    static int _nestUpThisSpot(lua_State* L);
    static int _reset(lua_State* L);
    static int activate(lua_State* L);
    static int allBuildingsDoorsOpen(lua_State* L);
    static int createPhysical(lua_State* L);
    static int destroyPhysical(lua_State* L);
    static int distanceTo(lua_State* L);
    static int distributeArtifacts(lua_State* L);
    static int findAllBuildingsOfType(lua_State* L);
    static int findAllBuildingsWithFunction(lua_State* L);
    static int gatesAllClosed(lua_State* L);
    static int getAlarmMgr(lua_State* L);
    static int getBiome(lua_State* L);
    static int getBuildingFloorVisibility(lua_State* L);
    static int getBuildingsManager(lua_State* L);
    static int getCurrentTownLocation(lua_State* L);
    static int getDataType(lua_State* L);
    static int getGUIData(lua_State* L);
    static int getGearArtifactsMaxValue(lua_State* L);
    static int getGearArtifactsMinValue(lua_State* L);
    static int getItemArtifactsMaxValue(lua_State* L);
    static int getItemArtifactsMinValue(lua_State* L);
    static int getKnownName(lua_State* L);
    static int getMapMarker(lua_State* L);
    static int getMapMarkerZoomLevel(lua_State* L);
    static int getNearestGate(lua_State* L);
    static int getPosition(lua_State* L);
    static int getPositionForWaypoint(lua_State* L);
    static int getPositionOutsideTownGates(lua_State* L);
    static int getRadius(lua_State* L);
    static int getTownFloorVisiblity(lua_State* L);
    static int hasGates(lua_State* L);
    static int hasResidentHQ(lua_State* L);
    static int isActive(lua_State* L);
    static int isDead(lua_State* L);
    static int isDiscovered(lua_State* L);
    static int isExplored(lua_State* L);
    static int isIllegal(lua_State* L);
    static int isNest(lua_State* L);
    static int isNotFriendly(lua_State* L);
    static int isOccupied(lua_State* L);
    static int isOutpost(lua_State* L);
    static int isPhysical(lua_State* L);
    static int isPublic(lua_State* L);
    static int isRecentlyDiscovered(lua_State* L);
    static int isTown(lua_State* L);
    static int loadFromSerialise(lua_State* L);
    static int loadState(lua_State* L);
    static int nestUpThisSpot(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int reassessTownPosition(lua_State* L);
    static int resetBuildingsFloorVisibility(lua_State* L);
    static int resetTownFloorVisibility(lua_State* L);
    static int saveState(lua_State* L);
    static int setBuildingsFloorVisibility(lua_State* L);
    static int setDead(lua_State* L);
    static int setDiscovered(lua_State* L);
    static int setExplored(lua_State* L);
    static int setFaction(lua_State* L);
    static int setRecentlyDiscovered(lua_State* L);
    static int setTownFloorVisiblity(lua_State* L);
    static int setVisible(lua_State* L);
    static int setZonePopulated(lua_State* L);
    static int setup(lua_State* L);
    static int squaredDistanceTo(lua_State* L);
    static int update(lua_State* L);
    static int updatePowerGrid(lua_State* L);
    static int withinBordersRange(lua_State* L);
    static int withinDiscoveryRange(lua_State* L);
    static int addGate(lua_State* L);
    static int _NV_addGate(lua_State* L);
    static int addOccupier(lua_State* L);
    static int removeOccupier(lua_State* L);
    static int getAlarmState(lua_State* L);
    static int _NV_getAlarmState(lua_State* L);
    static int setAlarmState(lua_State* L);
    static int _NV_setAlarmState(lua_State* L);
    static int setHandle(lua_State* L);
    static int _NV_setHandle(lua_State* L);
    static int getUnexploredName(lua_State* L);
    static int _NV_getUnexploredName(lua_State* L);
    static int serialise(lua_State* L);
    static int _NV_serialise(lua_State* L);
    static int delayedSpawningChecks(lua_State* L);
    static int clearDelayedItemLoadingMessages(lua_State* L);
    static int getZonesCoverage(lua_State* L);
    static int spawnDebris(lua_State* L);
};
}
