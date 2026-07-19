#include "pch.h"
#include "kenshi\Tasker.h"
#include "TaskerBinding.h"
#include "TaskDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/TaskDataBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/CharBodyBinding.h"
#include "Bindings/TaskStateDataBinding.h"

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
    lua_pushinteger(L, (lua_Integer)b->priority);
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
    return handBinding::push(L, b->subject);
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
    return handBinding::push(L, b->currentSubTarget);
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
    b->priority = (taskPriority)luaL_checkinteger(L, 2);
    return 0;
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
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->subject = *val;
    return 0;
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
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->currentSubTarget = *val;
    return 0;
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
    b->taskData = lua_isnoneornil(L, 2) ? nullptr : checkObject<TaskData>(L, 2, TaskDataBinding::getMetatableName());
    return 0;
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

int TaskerBinding::_CONSTRUCTOR(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    Tasker* res = b->_CONSTRUCTOR();
    return pushObject<Tasker>(L, res, TaskerBinding::getMetatableName());
}

int TaskerBinding::getFrameTime(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    CharBody* body = checkObject<CharBody>(L, 2, CharBodyBinding::getMetatableName());
    float res = b->getFrameTime(body);
    lua_pushnumber(L, res);
    return 1;
}

int TaskerBinding::sameAs(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    Tasker* other = checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    bool res = b->sameAs(other);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int TaskerBinding::score(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    AI* ai = (AI*)lua_touserdata(L, 2);
    float res = b->score(ai);
    lua_pushnumber(L, res);
    return 1;
}

int TaskerBinding::isResultsComplete(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    AI* ai = (AI*)lua_touserdata(L, 2);
    bool res = b->isResultsComplete(ai);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int TaskerBinding::isResultsComplete_ignoreSubtasker(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    AI* ai = (AI*)lua_touserdata(L, 2);
    bool res = b->isResultsComplete_ignoreSubtasker(ai);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int TaskerBinding::isRequirementsComplete(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    AI* ai = (AI*)lua_touserdata(L, 2);
    bool autoTargetFinder = lua_toboolean(L, 3) != 0;
    bool res = b->isRequirementsComplete(ai, autoTargetFinder);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int TaskerBinding::getRequirementComplaint(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    AI* ai = (AI*)lua_touserdata(L, 2);
    bool autoTargetFinder = lua_toboolean(L, 3) != 0;
    std::string res = b->getRequirementComplaint(ai, autoTargetFinder);
    lua_pushstring(L, res.c_str());
    return 1;
}

int TaskerBinding::getNextSubTarget(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    AI* ai = (AI*)lua_touserdata(L, 2);
    hand res = b->getNextSubTarget(ai);
    return pushObject<hand>(L, new hand(res), handBinding::getMetatableName());
}

int TaskerBinding::getSubTask(lua_State* L)
{
    Tasker* b = getB(L, 1);
    if (!b) return luaL_error(L, "Tasker is nil");
    TaskStateData* res = b->getSubTask();
    return pushObject<TaskStateData>(L, res, TaskStateDataBinding::getMetatableName());
}

/*
Skipped methods needing manual binding:
  line 326: const std::string& getDescription(...) - reference return type
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
        { "_CONSTRUCTOR", TaskerBinding::_CONSTRUCTOR },
        { "getFrameTime", TaskerBinding::getFrameTime },
        { "sameAs", TaskerBinding::sameAs },
        { "score", TaskerBinding::score },
        { "isResultsComplete", TaskerBinding::isResultsComplete },
        { "isResultsComplete_ignoreSubtasker", TaskerBinding::isResultsComplete_ignoreSubtasker },
        { "isRequirementsComplete", TaskerBinding::isRequirementsComplete },
        { "getRequirementComplaint", TaskerBinding::getRequirementComplaint },
        { "getNextSubTarget", TaskerBinding::getNextSubTarget },
        { "getSubTask", TaskerBinding::getSubTask },
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
