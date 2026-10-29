#pragma once

// Tasker.h must come before AI.h (included by Campaign.h); see TaskDataBinding.cpp.
#include "kenshi/Tasker.h"
#include "kenshi/Campaign.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class CampaignInstanceBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CampaignInstance"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getData(lua_State* L);
    static int changePhase(lua_State* L);
    static int saveState(lua_State* L);
    static int loadState(lua_State* L);
    static int markOnMap(lua_State* L);
    static int _NV_markOnMap(lua_State* L);
    static int getDialogData(lua_State* L);
    static int hasSufficientManpower(lua_State* L);
    static int victoryEvent(lua_State* L);
    static int _NV_victoryEvent(lua_State* L);
    static int lossEvent(lua_State* L);
    static int _NV_lossEvent(lua_State* L);
    static int setLeader(lua_State* L);
    static int _NV_setLeader(lua_State* L);
    static int getLeader(lua_State* L);
    static int _NV_getLeader(lua_State* L);
    static int getLeaderPlatoon(lua_State* L);
    static int _NV_getLeaderPlatoon(lua_State* L);
    static int isEnemy(lua_State* L);
    static int _NV_isEnemy(lua_State* L);
    static int getName(lua_State* L);
    static int _NV_getName(lua_State* L);
    static int setup(lua_State* L);
    static int _NV_setup(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int _NV_periodicUpdate(lua_State* L);
    static int isEverybodyIdle(lua_State* L);
    static int _NV_isEverybodyIdle(lua_State* L);
    static int getUnloadedPlatoonBehavior(lua_State* L);
    static int _NV_getUnloadedPlatoonBehavior(lua_State* L);
    static int getAIPackage(lua_State* L);
    static int _NV_getAIPackage(lua_State* L);
    static int addToCampaign(lua_State* L);
    static int _NV_addToCampaign(lua_State* L);
    static int areForcesAllTogether(lua_State* L);
    static int _NV_areForcesAllTogether(lua_State* L);
    static int removeFromCampaign(lua_State* L);
    static int _NV_removeFromCampaign(lua_State* L);
    static int getAITarget(lua_State* L);
    static int _NV_getAITarget(lua_State* L);
    static int getMoveSpeedUnloaded(lua_State* L);
    static int _NV_getMoveSpeedUnloaded(lua_State* L);
    static int getMoveSpeedLoaded(lua_State* L);
    static int _NV_getMoveSpeedLoaded(lua_State* L);
    static int getTargetTown(lua_State* L);
    static int _NV_getTargetTown(lua_State* L);
    static int getFormationPosition(lua_State* L);
    static int getDestination(lua_State* L);
    static int _NV_getDestination(lua_State* L);
    static int isSuccessful(lua_State* L);
};
}
