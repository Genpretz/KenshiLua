#pragma once

// Blackboard.h and AIPackage.h both define BlackboardSignalFunctions, so binding
// headers leave them out; include one of them in the .cpp that needs it.

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class BlackboardBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Blackboard"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int createNewPackage(lua_State* L);
    static int _setContractJob(lua_State* L);
    static int _addPackage(lua_State* L);
    static int clearAllPackages(lua_State* L);
    static int _activateCurrentPackage(lua_State* L);
    static int _addFromData(lua_State* L);
    static int getPackage(lua_State* L);
    static int getPackageList(lua_State* L);
    static int periodicPackageCheck(lua_State* L);
    static int dialogEventsCheck(lua_State* L);
    static int setContractJob(lua_State* L);
    static int endContractJob(lua_State* L);
    static int isMissionComplete(lua_State* L);
    static int isTargetMarkedForDeath(lua_State* L);
    static int update(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int addPackages(lua_State* L);
    static int addFallbackPackages(lua_State* L);
    static int replaceAIPackage(lua_State* L);
    static int getCurrentAIPackageName(lua_State* L);
    static int getCurrentAIPackageGUIData(lua_State* L);
    static int assessNeutral(lua_State* L);
    static int assessEnemy(lua_State* L);
    static int getCurrentPackage(lua_State* L);
    static int getFormationPositionOffset(lua_State* L);
    static int nodifyFormationUpdate(lua_State* L);
    static int getOwnerships(lua_State* L);
    static int notifyGoalStart(lua_State* L);
    static int notifyGoalEnd(lua_State* L);
    static int notifySubTarget(lua_State* L);
    static int howManyGuysDoingThisGoal(lua_State* L);
    static int howManyGuysWorkingOnThisSubTarget(lua_State* L);
    static int isMySubTarget(lua_State* L);
    static int getSubTarget(lua_State* L);
    static int addRequest(lua_State* L);
    static int removeRequest(lua_State* L);
    static int notifyJobCompleted(lua_State* L);
    static int addSquadJob(lua_State* L);
    static int getUnloadedPlatoonJob(lua_State* L);
    static int clearAllTheJobs(lua_State* L);
    static int serialise(lua_State* L);
    static int load(lua_State* L);
    static int stateUpdate(lua_State* L);
    static int notifyMissionTargetPathfindImpossible(lua_State* L);
    static int getMissionTown(lua_State* L);
    static int getMissionGiver(lua_State* L);
    static int getCurrentTownLocation(lua_State* L);
    static int getTimeSpentInTown_inGameHours(lua_State* L);
    static int setMyHomeIsLocked(lua_State* L);
    static int getMyHomeIsLocked(lua_State* L);
    static int getHomeGate(lua_State* L);
    static int hasContractJob(lua_State* L);
    static int getContractExpiryTime(lua_State* L);
    static int contractJobNotifyBetrayal(lua_State* L);
    static int contractJobWasBetrayal(lua_State* L);
    static int showEndedMessage(lua_State* L);
    static int _NV_showEndedMessage(lua_State* L);
    static int _setupJobFromData(lua_State* L);
    static int countCharacters(lua_State* L);
    static int runAwayCheck(lua_State* L);
    static int runAway(lua_State* L);
    static int buildFormation(lua_State* L);
    static int getGridPositions(lua_State* L);
};
}
