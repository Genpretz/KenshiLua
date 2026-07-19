#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TaskDataBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TaskData"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int setCharacteristics(lua_State* L);
    static int setInfrequentGoalChecks(lua_State* L);
    static int setAlertnessMult(lua_State* L);
    static int setRequirementsCantEndActionPrematurely(lua_State* L);
    static int setCopyMeInfluence(lua_State* L);
    static int setFollowMeWeight(lua_State* L);
    static int setSelfRegulation(lua_State* L);
    static int setDurationBased(lua_State* L);
    static int hasInfrequentGoalChecks(lua_State* L);
    static int getRequirementsCantEndActionPrematurely(lua_State* L);
    static int isPermaJob(lua_State* L);
    static int isPermaJobFixedTarget(lua_State* L);
    static int getPermaJobAssociation(lua_State* L);
    static int getPermaJobAssociation_secondary(lua_State* L);
    static int isTargetFinder(lua_State* L);
    static int setDialogueDeliveryTag(lua_State* L);
};
}
