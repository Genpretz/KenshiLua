#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class CombatClassBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CombatClass"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int isAI(lua_State* L);
    static int _NV_isAI(lua_State* L);
    static int go(lua_State* L);
    static int _NV_go(lua_State* L);
    static int getCombatState(lua_State* L);
    static int getBlockStateEnum(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int _NV_periodicUpdate(lua_State* L);
    static int isStationary(lua_State* L);
    static int getCurrentTechnique(lua_State* L);
    static int getCurrentTechniqueSection(lua_State* L);
    static int getMeiMin(lua_State* L);
    static int areYouFightingAndInNeedOfHelp(lua_State* L);
    static int getNumOpponents(lua_State* L);
    static int getTotalRelativeStrengthOfAttackers(lua_State* L);
    static int _isInCombatMode(lua_State* L);
    static int checkForBadHandles(lua_State* L);
    static int getNumWaitingAttackers(lua_State* L);
    static int readyToFinishCombatMode(lua_State* L);
    static int getTimeSinceLastCombatModeInHours(lua_State* L);
    static int changeState(lua_State* L);
    static int getStateClass(lua_State* L);
    static int _NV_getStateClass(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int getMeiMax(lua_State* L);
    static int startupState(lua_State* L);
    static int _NV_startupState(lua_State* L);
    static int stumbleState(lua_State* L);
    static int _isAttackingUpdate(lua_State* L);
    static int canBlock(lua_State* L);
    static int attackState(lua_State* L);
    static int _NV_attackState(lua_State* L);
    static int checkForNeedBlock(lua_State* L);
    static int setCombatState(lua_State* L);
    static int initialiseBlock(lua_State* L);
    static int blockState(lua_State* L);
    static int _NV_blockState(lua_State* L);
    static int blockWaitingState(lua_State* L);
    static int attackImpactCheck(lua_State* L);
    static int calculateTargetsInAttackZone(lua_State* L);
    static int getNearestEnemyInAttackZone(lua_State* L);
    static int notifyBlockNeeded(lua_State* L);
    static int weaponReach(lua_State* L);
    static int packPtrsToHandles(lua_State* L);
    static int _NV_packPtrsToHandles(lua_State* L);
    static int unpackHandlesToPtrs(lua_State* L);
    static int _NV_unpackHandlesToPtrs(lua_State* L);
};
}
