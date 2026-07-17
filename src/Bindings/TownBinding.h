#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TownBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Town"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int initialiseResidentData(lua_State* L);
    static int getGameData(lua_State* L);
    static int _NV_getGameData(lua_State* L);
    static int getOriginalGameData(lua_State* L);
    static int _reset(lua_State* L);
    static int _NV__reset(lua_State* L);
    static int getDataType(lua_State* L);
    static int _NV_getDataType(lua_State* L);
    static int reassessTownPosition(lua_State* L);
    static int _NV_reassessTownPosition(lua_State* L);
    static int showDistantTown(lua_State* L);
    static int isOutpost(lua_State* L);
    static int spawnTheBarFlies(lua_State* L);
    static int townLoadedEvent(lua_State* L);
    static int notifyUnloading(lua_State* L);
    static int getBuildingMaterial(lua_State* L);
    static int isTown(lua_State* L);
    static int _NV_isTown(lua_State* L);
    static int isPublic(lua_State* L);
    static int _NV_isPublic(lua_State* L);
    static int needsSaving(lua_State* L);
    static int _NV_needsSaving(lua_State* L);
    static int setPosition(lua_State* L);
    static int getRadius(lua_State* L);
    static int _NV_getRadius(lua_State* L);
    static int isActive(lua_State* L);
    static int _NV_isActive(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int _NV_periodicUpdate(lua_State* L);
    static int updatePowerGrid(lua_State* L);
    static int _NV_updatePowerGrid(lua_State* L);
    static int gatesAllClosed(lua_State* L);
    static int _NV_gatesAllClosed(lua_State* L);
    static int hasGates(lua_State* L);
    static int _NV_hasGates(lua_State* L);
    static int notifyAccesibility(lua_State* L);
    static int getPositionOutsideTownGates(lua_State* L);
    static int _NV_getPositionOutsideTownGates(lua_State* L);
    static int isPlayerBuildingsInThisTown(lua_State* L);
    static int setPlayerBuildingsInThisTown(lua_State* L);
    static int getRequiredPower(lua_State* L);
    static int getTotalPower(lua_State* L);
    static int hasSparePower(lua_State* L);
    static int getBatteryDrain(lua_State* L);
    static int getBatteryChargeMax(lua_State* L);
    static int getBatteryCharge(lua_State* L);
    static int getBatteryCharge01(lua_State* L);
    static int getBatteryChargingUpAmount(lua_State* L);
    static int getBatteryPowerTotal(lua_State* L);
    static int isBatteryMode(lua_State* L);
    static int clearNests(lua_State* L);
    static int getMapMarker(lua_State* L);
    static int _NV_getMapMarker(lua_State* L);
    static int getMapMarkerZoomLevel(lua_State* L);
    static int _NV_getMapMarkerZoomLevel(lua_State* L);
    static int recalculatePlayerTownLevel(lua_State* L);
    static int deActivationCheck(lua_State* L);
};
}