#pragma once

#include "kenshi/AI/AITaskSystem.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class OrdersReceiverBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.OrdersReceiver"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int serialise(lua_State* L);
    static int _NV_serialise(lua_State* L);
    static int loadFromSerialise(lua_State* L);
    static int _NV_loadFromSerialise(lua_State* L);
    static int _forceOrderInsert(lua_State* L);
    static int addOrder(lua_State* L);
    static int addJob(lua_State* L);
    static int removeJob(lua_State* L);
    static int removePermajob(lua_State* L);
    static int movePermajob(lua_State* L);
    static int clearPermajobs(lua_State* L);
    static int getPermajobName(lua_State* L);
    static int getPermajob(lua_State* L);
    static int getPermajobData(lua_State* L);
    static int getPermajobCount(lua_State* L);
    static int hasPermajob(lua_State* L);
    static int addGoal(lua_State* L);
    static int removeGoal(lua_State* L);
    static int hasGoal(lua_State* L);
    static int updateLastOrder(lua_State* L);
    static int setNeedGOAP(lua_State* L);
    static int _NV_setNeedGOAP(lua_State* L);
    static int getFirstOrder(lua_State* L);
    static int clearOrders(lua_State* L);
    static int clearJobs(lua_State* L);
    static int _clearGoals(lua_State* L);
    static int getCurrentGoal(lua_State* L);
    static int setHoldPositionOrders(lua_State* L);
    static int _NV_setHoldPositionOrders(lua_State* L);
    static int hasPlayerOrders(lua_State* L);
    static int hasPlayerOrder(lua_State* L);
    static int isInChoosingGoalMode(lua_State* L);
    static int hasOrders(lua_State* L);
    static int clearSlaveJobs(lua_State* L);
    static int isJobsEnabled(lua_State* L);
    static int setJobsEnabled(lua_State* L);
    static int clearCurrentGoal(lua_State* L);
    static int tryToGetCurrentGoal(lua_State* L);
};
}
