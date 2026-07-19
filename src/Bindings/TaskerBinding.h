#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TaskerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Tasker"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int checkTimeOfDay(lua_State* L);
    static int key(lua_State* L);
    static int unSkippableJob(lua_State* L);
    static int getLocation(lua_State* L);
    static int setLocation(lua_State* L);
    static int hasActionFunc(lua_State* L);
    static int isSubTasker(lua_State* L);
    static int isInfiniteGoal(lua_State* L);
    static int needsSubjectOrLocation(lua_State* L);
    static int getTaskData(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int getFrameTime(lua_State* L);
    static int sameAs(lua_State* L);
    static int score(lua_State* L);
    static int isResultsComplete(lua_State* L);
    static int isResultsComplete_ignoreSubtasker(lua_State* L);
    static int isRequirementsComplete(lua_State* L);
    static int getRequirementComplaint(lua_State* L);
    static int getNextSubTarget(lua_State* L);
    static int getSubTask(lua_State* L);
};
}
