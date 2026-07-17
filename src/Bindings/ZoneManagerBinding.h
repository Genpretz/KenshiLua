#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ZoneManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ZoneManager"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int isZoneLoadedT(lua_State* L);
    static int _NV_isZoneLoadedT(lua_State* L);
    static int isZoneBeingLoadedT(lua_State* L);
    static int _NV_isZoneBeingLoadedT(lua_State* L);
    static int getNumActiveZones(lua_State* L);
    static int setup(lua_State* L);
    static int updateMainThread(lua_State* L);
    static int updateRendertimeThread(lua_State* L);
    static int updateGPUSafeThread(lua_State* L);
    static int spawnChecksUpdateThreaded(lua_State* L);
    static int levelEditorDeleteAllSelectedObjects(lua_State* L);
    static int getCurrentZoneMap(lua_State* L);
    static int playerActivate(lua_State* L);
    static int getBiome(lua_State* L);
    static int getBiomeCode(lua_State* L);
    static int getBiomeMap(lua_State* L);
    static int getGroundTypeIndex(lua_State* L);
    static int getGroundType(lua_State* L);
    static int shiftGroundEffects(lua_State* L);
    static int checkZoneFiles(lua_State* L);
    static int resetStates(lua_State* L);
    static int getResourceId(lua_State* L);
    static int getResourceName(lua_State* L);
    static int saveMapFeatures(lua_State* L);
    static int saveLevelData(lua_State* L);
    static int saveActiveZoneStates(lua_State* L);
    static int resetGame(lua_State* L);
    static int deactivateAllActiveZones(lua_State* L);
    static int activateAllActiveZones(lua_State* L);
    static int populateTownsForLevelEditor(lua_State* L);
    static int calculateIslands(lua_State* L);
    static int _reloadAllFoliage(lua_State* L);
    static int _reloadGroundTextures(lua_State* L);
    static int _unloadAllZones(lua_State* L);
    static int getCentralZone(lua_State* L);
    static int isLoading(lua_State* L);
    static int _calculateIslands(lua_State* L);
    static int loadFeatures(lua_State* L);
    static int loadDistantTowns(lua_State* L);
    static int processLoading(lua_State* L);
    static int loadPhase1(lua_State* L);
    static int loadPhase2(lua_State* L);
    static int loadPhase3(lua_State* L);
};
}