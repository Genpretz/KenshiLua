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
};
}