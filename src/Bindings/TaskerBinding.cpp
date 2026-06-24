#include "pch.h"
#include "kenshi\Tasker.h"
#include "TaskerBinding.h"
#include "TaskDataBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static Tasker* getB(lua_State* L, int idx)
{
    return checkObject<Tasker>(L, idx, TaskerBinding::getMetatableName());
}

// --- Getters for Tasker ---
static int Tasker_get_priority(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    // TODO: Unsupported type for priority (taskPriority)
    lua_pushnil(L);
    return 1;
}

static int Tasker_get_resetsWhenDone(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    lua_pushboolean(L, b->resetsWhenDone ? 1 : 0);
    return 1;
}

static int Tasker_get_subject(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    // TODO: Unsupported type for subject (hand)
    lua_pushnil(L);
    return 1;
}

static int Tasker_get_weight(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    lua_pushnumber(L, b->weight);
    return 1;
}

static int Tasker_get_currentSubTarget(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    // TODO: Unsupported type for currentSubTarget (hand)
    lua_pushnil(L);
    return 1;
}

static int Tasker_get_location(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    pushVector3(L, b->location);
    return 1;
}

static int Tasker_get_startTime(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    lua_pushinteger(L, b->startTime);
    return 1;
}

static int Tasker_get_endTime(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    lua_pushinteger(L, b->endTime);
    return 1;
}

static int Tasker_get_taskData(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    return pushObject<TaskData>(L, b->taskData, TaskDataBinding::getMetatableName());
}

// --- Setters for Tasker ---
static int Tasker_set_priority(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    return luaL_error(L, "Read-only or unsupported setter type for priority");
}

static int Tasker_set_resetsWhenDone(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    b->resetsWhenDone = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Tasker_set_subject(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    return luaL_error(L, "Read-only or unsupported setter type for subject");
}

static int Tasker_set_weight(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    b->weight = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Tasker_set_currentSubTarget(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    return luaL_error(L, "Read-only or unsupported setter type for currentSubTarget");
}

static int Tasker_set_location(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    readVector3(L, 2, b->location);
    return 0;
}

static int Tasker_set_startTime(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    b->startTime = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Tasker_set_endTime(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    b->endTime = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Tasker_set_taskData(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    return luaL_error(L, "Read-only or unsupported setter type for taskData");
}

int TaskerBinding::_DESTRUCTOR(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");

    b->_DESTRUCTOR();
    return 0;
}

int TaskerBinding::checkTimeOfDay(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");

    bool result = b->checkTimeOfDay();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskerBinding::key(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");

    TaskType result = b->key();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TaskerBinding::unSkippableJob(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");

    bool result = b->unSkippableJob();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskerBinding::getLocation(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");

    Ogre::Vector3 result = b->getLocation();
    pushVector3(L, result);
    return 1;
}

int TaskerBinding::setLocation(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");

    Ogre::Vector3 loc;
    readVector3(L, 2, loc);
    b->setLocation(loc);
    return 0;
}

int TaskerBinding::hasActionFunc(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");

    bool result = b->hasActionFunc();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskerBinding::isSubTasker(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");

    bool result = b->isSubTasker();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskerBinding::isInfiniteGoal(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");

    bool result = b->isInfiniteGoal();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskerBinding::needsSubjectOrLocation(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");

    bool result = b->needsSubjectOrLocation();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskerBinding::getTaskData(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");

    const TaskData* result = b->getTaskData();
    return pushObject<TaskData>(L, const_cast<TaskData*>(result), TaskDataBinding::getMetatableName());
}

/*
Skipped methods needing manual binding:
  line 307: Tasker* _CONSTRUCTOR(...) - unsupported return type
  line 311: float getFrameTime(...) - unsupported arg type
  line 325: bool sameAs(...) - unsupported arg type
  line 326: const std::string& getDescription(...) - reference return type
  line 328: float score(...) - unsupported arg type
  line 329: bool isResultsComplete(...) - unsupported arg type
  line 330: bool isResultsComplete_ignoreSubtasker(...) - unsupported arg type
  line 332: bool isRequirementsComplete(...) - unsupported arg type
  line 333: std::string getRequirementComplaint(...) - unsupported arg type
  line 337: hand getNextSubTarget(...) - unsupported return type
  line 339: TaskStateData* getSubTask(...) - unsupported return type
  line 341: bool isSubTaskerTargetFinishedWith(...) - unsupported arg type
  line 348: void startAction(...) - unsupported arg type
  line 349: void _NV_startAction(...) - unsupported arg type
  line 350: void runAction(...) - unsupported arg type
  line 351: void endAction(...) - unsupported arg type
  line 352: void _NV_endAction(...) - unsupported arg type
  line 353: bool taskSaysItsFinished(...) - unsupported arg type
  line 354: bool _NV_taskSaysItsFinished(...) - unsupported arg type
  line 358: float findTarget(...) - unsupported arg type
  line 359: bool _targetsRemaining(...) - unsupported arg type
  line 360: bool isSubTaskerComplete(...) - unsupported arg type
*/

int TaskerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TaskerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Tasker object");
    return 1;
}

void TaskerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TaskerBinding::gc },
        { "__tostring", TaskerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", TaskerBinding::_DESTRUCTOR },
        { "checkTimeOfDay", TaskerBinding::checkTimeOfDay },
        { "key", TaskerBinding::key },
        { "unSkippableJob", TaskerBinding::unSkippableJob },
        { "getLocation", TaskerBinding::getLocation },
        { "setLocation", TaskerBinding::setLocation },
        { "hasActionFunc", TaskerBinding::hasActionFunc },
        { "isSubTasker", TaskerBinding::isSubTasker },
        { "isInfiniteGoal", TaskerBinding::isInfiniteGoal },
        { "needsSubjectOrLocation", TaskerBinding::needsSubjectOrLocation },
        { "getTaskData", TaskerBinding::getTaskData },
        { 0, 0 }
    };

    registerClass(
        L, 
        TaskerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TaskerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, Tasker_get_priority);
    lua_setfield(L, -2, "priority");
    lua_pushcfunction(L, Tasker_get_resetsWhenDone);
    lua_setfield(L, -2, "resetsWhenDone");
    lua_pushcfunction(L, Tasker_get_subject);
    lua_setfield(L, -2, "subject");
    lua_pushcfunction(L, Tasker_get_weight);
    lua_setfield(L, -2, "weight");
    lua_pushcfunction(L, Tasker_get_currentSubTarget);
    lua_setfield(L, -2, "currentSubTarget");
    lua_pushcfunction(L, Tasker_get_location);
    lua_setfield(L, -2, "location");
    lua_pushcfunction(L, Tasker_get_startTime);
    lua_setfield(L, -2, "startTime");
    lua_pushcfunction(L, Tasker_get_endTime);
    lua_setfield(L, -2, "endTime");
    lua_pushcfunction(L, Tasker_get_taskData);
    lua_setfield(L, -2, "taskData");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, Tasker_set_priority);
    lua_setfield(L, -2, "priority");
    lua_pushcfunction(L, Tasker_set_resetsWhenDone);
    lua_setfield(L, -2, "resetsWhenDone");
    lua_pushcfunction(L, Tasker_set_subject);
    lua_setfield(L, -2, "subject");
    lua_pushcfunction(L, Tasker_set_weight);
    lua_setfield(L, -2, "weight");
    lua_pushcfunction(L, Tasker_set_currentSubTarget);
    lua_setfield(L, -2, "currentSubTarget");
    lua_pushcfunction(L, Tasker_set_location);
    lua_setfield(L, -2, "location");
    lua_pushcfunction(L, Tasker_set_startTime);
    lua_setfield(L, -2, "startTime");
    lua_pushcfunction(L, Tasker_set_endTime);
    lua_setfield(L, -2, "endTime");
    lua_pushcfunction(L, Tasker_set_taskData);
    lua_setfield(L, -2, "taskData");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua