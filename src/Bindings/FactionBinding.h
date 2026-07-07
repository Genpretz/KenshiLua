#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class FactionBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Faction"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int getProsperityMultiplier(lua_State* L);
    static int clearAndDestroy(lua_State* L);
    static int setup2(lua_State* L);
    static int setup3(lua_State* L);
    static int getNewPlatoonID(lua_State* L);
    static int resetPlatoonID(lua_State* L);
    static int createReplacementPlatoonForPlayerWhenSavegameIsCorrupt(lua_State* L);
    static int resetSquadPositions(lua_State* L);
    static int getData(lua_State* L);
    static int getDefaultDivision(lua_State* L);
    static int getFactionColorScheme(lua_State* L);
    static int _activateUnloadedPlatoons(lua_State* L);
    static int processKillList(lua_State* L);
    static int _NV_processKillList(lua_State* L);
    static int getFactionSize(lua_State* L);
    static int update(lua_State* L);
    static int periodicUpdateThreaded(lua_State* L);
    static int periodicUpdateMT(lua_State* L);
    static int isThePlayer(lua_State* L);
    static int isNotARealFaction(lua_State* L);
    static int getRoadPreference(lua_State* L);
    static int isAntiSlavery(lua_State* L);
    static int getLawEnforcementFaction(lua_State* L);
    static int setName(lua_State* L);
    static int updateUnloadedPlatoons(lua_State* L);
    static int updateActivePlatoons(lua_State* L);
    static int spawnSquadMissionsUpdate(lua_State* L);
    static int _spawnASquad(lua_State* L);

    static int getFundamentalNPCType(lua_State* L);
    static int setup(lua_State* L);
    static int createNewEmptyUnloadedPlatoon(lua_State* L);
    static int createNewEmptyActivePlatoon(lua_State* L);
    static int createPlatoonUnloaded(lua_State* L);
    static int createPlatoonAuto(lua_State* L);
    static int createPlatoonsAuto(lua_State* L);
    static int restorePlatoon(lua_State* L);
    static int countPopulation(lua_State* L);
    static int countNumSquads(lua_State* L);
    static int destroyPlatoon(lua_State* L);
    static int removePlatoon(lua_State* L);
    static int getRandomLockLevel(lua_State* L);
    static int getGUIData(lua_State* L);
    static int loadState(lua_State* L);
    static int saveState(lua_State* L);
    static int getCharactersInArea(lua_State* L);
    static int _NV_getCharactersInArea(lua_State* L);
    static int getSelectedObjects(lua_State* L);
    static int _NV_getSelectedObjects(lua_State* L);
    static int removeObject(lua_State* L);
    static int _NV_removeObject(lua_State* L);
    static int destroyObject(lua_State* L);
    static int _NV_destroyObject(lua_State* L);
    static int addActiveObject(lua_State* L);
    static int _NV_addActiveObject(lua_State* L);
    static int choosePlatoon(lua_State* L);
    static int getName(lua_State* L);
    static int getNumPlatoons(lua_State* L);
    static int getAllSquadsThatOwn(lua_State* L);
    static int chooseARace(lua_State* L);
    static int getBuildingReplacement(lua_State* L);
    static int _switchToUnloadedPlatoon(lua_State* L);
    static int _newPlatoon(lua_State* L);
    static int _addActivePlatoonToList(lua_State* L);
    static int addPlatoon(lua_State* L);
    static int changePlatoonIndex(lua_State* L);
    static int deactivatePlatoon(lua_State* L);
    static int activatePlatoon(lua_State* L);
};
}