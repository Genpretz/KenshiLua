#pragma once

#include "kenshi/FactionWarMgr.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class FactionWarMgrBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.FactionWarMgr"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int reset(lua_State* L);
    static int save(lua_State* L);
    static int load(lua_State* L);
    static int removePlatoon(lua_State* L);
    static int addPlatoon(lua_State* L);
    static int getGUIData(lua_State* L);
    static int areAnyHostileCampaignsRunning(lua_State* L);
    static int endCampaign(lua_State* L);
    static int getAllTheForces(lua_State* L);
    static int _generateForcesForTown(lua_State* L);
    static int canGenerateThisManyForces(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int debugButton(lua_State* L);
    static int triggerCampaign(lua_State* L);
    static int getCurrentCampaign(lua_State* L);
    static int getAITarget(lua_State* L);
    static int getMyUnloadedAI(lua_State* L);
    static int isBiomeHomeTerritory(lua_State* L);
    static int getNearestTown(lua_State* L);
    static int getTownsInBiome(lua_State* L);
    static int getMyTownsWithEnoughFreePopulation(lua_State* L);
    static int getActiveCampaign(lua_State* L);
    static int setup(lua_State* L);
    static int _createCampaignData(lua_State* L);
};
}