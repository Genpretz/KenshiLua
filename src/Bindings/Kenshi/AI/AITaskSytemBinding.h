#pragma once

#include "kenshi/AI/AITaskSystem.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class AITaskSytemBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AITaskSytem"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int canIDoTheInfrequents(lua_State* L);
    static int infrequentsStampCheck(lua_State* L);
    static int currentActionChecks(lua_State* L);
    static int _logTheAI(lua_State* L);
    static int serialise(lua_State* L);
    static int _NV_serialise(lua_State* L);
    static int loadFromSerialise(lua_State* L);
    static int _NV_loadFromSerialise(lua_State* L);
    static int getHandle(lua_State* L);
    static int notifyPathImpossible(lua_State* L);
    static int isPathImpossible(lua_State* L);
    static int update(lua_State* L);
    static int update4Frame(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int taskImpossible(lua_State* L);
    static int _notifyBodyTaskComplete(lua_State* L);
    static int _forcedSetCurrentAction(lua_State* L);
    static int setTaskExpiryTimer(lua_State* L);
    static int isGoalExpired(lua_State* L);
    static int isTaskExpired(lua_State* L);
    static int getGOalExpiryTimeRemaining(lua_State* L);
    static int tryAndRerunGOAP(lua_State* L);
    static int setCurrentGoal(lua_State* L);
    static int _NV_setCurrentGoal(lua_State* L);
    static int callForUpdate(lua_State* L);
    static int getGUIData(lua_State* L);
    static int getCurrentGoalString(lua_State* L);
    static int intendsToAttackTarget(lua_State* L);
    static int updateStateBroadcast(lua_State* L);
    static int clearAllTasks(lua_State* L);
    static int debugTargetInfo(lua_State* L);
    static int setNeedGOAP(lua_State* L);
    static int _NV_setNeedGOAP(lua_State* L);
    static int setDialogueDeliveryTag(lua_State* L);
    static int getCurrentDurationTimedTask(lua_State* L);
    static int _taskImpossible(lua_State* L);
    static int isThePlayer(lua_State* L);
    static int checkOrders(lua_State* L);
    static int chooseGoal(lua_State* L);
    static int _chooseGoal(lua_State* L);
    static int chooseGoalFrom(lua_State* L);
    static int choosePermaJob(lua_State* L);
    static int setupParametersForCurrentGoal(lua_State* L);
    static int runGoals(lua_State* L);
    static int clearRequestsList(lua_State* L);
    static int bodyTaskComplete(lua_State* L);
    static int popFromOrders(lua_State* L);
    static int setCurrentTask(lua_State* L);
    static int runGOAP(lua_State* L);
    static int chooseGoalFrom(lua_State* L);
    static int choosePermaJob(lua_State* L);
    static int runGoals(lua_State* L);
};
}
