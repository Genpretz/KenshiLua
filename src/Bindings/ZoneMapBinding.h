#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ZoneMapBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ZoneMap"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int initialise(lua_State* L);
    static int threadedUpdate(lua_State* L);
    static int update(lua_State* L);
    static int selectBiomes(lua_State* L);
    static int getBiomeCount(lua_State* L);
    static int getBiomeData(lua_State* L);
    static int getOverlay(lua_State* L);
    static int getAreaSector(lua_State* L);
    static int getTerrainHeight(lua_State* L);
    static int getTerrainHeightWithNormal(lua_State* L);
    static int getTerrainSlope(lua_State* L);
    static int isWithinBoundsMinusUnloadedEdges(lua_State* L);
    static int getCornerPos(lua_State* L);
    static int getTerrainSector(lua_State* L);
    static int isActive(lua_State* L);
    static int getDeactivationCountdown(lua_State* L);
    static int isLoadedBT(lua_State* L);
    static int isBeingLoadedBT(lua_State* L);
    static int isLoadedMT(lua_State* L);
    static int isBeingLoadedMT(lua_State* L);
    static int isTerrainCollisionLoaded(lua_State* L);
    static int _makeSureTerrainHeightmapLoaded(lua_State* L);
    static int _dactivateMT(lua_State* L);
    static int generateNavMeshes(lua_State* L);
    static int updateBuildingUsageNodes(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}