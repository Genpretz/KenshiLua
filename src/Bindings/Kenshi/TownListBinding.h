#pragma once
#include "kenshi/Town.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TownListBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TownList"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int addActiveObject(lua_State* L);
    static int _NV_addActiveObject(lua_State* L);
    static int updateTownCoverage(lua_State* L);
    static int _clearAll(lua_State* L);
    static int _resetGame(lua_State* L);
    static int destroyAllTheNests(lua_State* L);
    static int destroy(lua_State* L);
    static int getTown(lua_State* L);
    static int getTownBySID(lua_State* L);
    static int getNearestPlayerTown(lua_State* L);
    static int getNearestTown(lua_State* L);
    static int getNearestTownWithBuildingDesignation(lua_State* L);
    static int getNearestNest(lua_State* L);
    static int getNearest(lua_State* L);
    static int getNearestWithinItsRadius(lua_State* L);
    static int getRetreatTown(lua_State* L);
    static int createNewPlayerTown(lua_State* L);
    static int getDistToNearestTown(lua_State* L);
    static int getSquaredDistToNearestTown(lua_State* L);
    static int getNearishTown(lua_State* L);
    static int getAllTowns(lua_State* L);
    static int getNullTown(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int updateTownsDiscovery(lua_State* L);
    static int setAllTownsDebugVisible(lua_State* L);
    static int saveToDisk(lua_State* L);
    static int _NV_saveToDisk(lua_State* L);
    static int loadFromDisk(lua_State* L);
    static int _NV_loadFromDisk(lua_State* L);
    static int saveState(lua_State* L);
    static int loadState(lua_State* L);
    static int loadStateDiscovery(lua_State* L);
    static int loadLevelData(lua_State* L);
    static int _saveLevelData(lua_State* L);
    static int saveUniqueTownsAndNests(lua_State* L);
    static int listUniqueTownsFromPlayerOwnership(lua_State* L);
    static int loadAllTowns_worldInit(lua_State* L);
    static int addNest(lua_State* L);
    static int reassessTownPositions(lua_State* L);
    static int mergePlayerTowns(lua_State* L);
};
}
