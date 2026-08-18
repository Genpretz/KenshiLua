#include "pch.h"
#include "kenshi\Tasker.h"
#include "TaskerBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharBodyBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/TaskDataBinding.h"
#include "Bindings/TaskStateDataBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "TaskDataBinding.h"

namespace KenshiLua
{

static Tasker* getInstance(lua_State* L, int idx)
{
    return checkObject<Tasker>(L, idx, TaskerBinding::getMetatableName());
}

// --- Getters for Tasker ---
static int Tasker_get_resetsWhenDone(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    lua_pushboolean(L, instance->resetsWhenDone ? 1 : 0);
    return 1;
}

static int Tasker_get_subject(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    return HandBinding::push(L, instance->subject);
}

static int Tasker_get_weight(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    lua_pushnumber(L, instance->weight);
    return 1;
}

static int Tasker_get_currentSubTarget(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    return HandBinding::push(L, instance->currentSubTarget);
}

static int Tasker_get_location(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    pushVector3(L, instance->location);
    return 1;
}

static int Tasker_get_startTime(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    lua_pushinteger(L, instance->startTime);
    return 1;
}

static int Tasker_get_endTime(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    lua_pushinteger(L, instance->endTime);
    return 1;
}

static int Tasker_get_taskData(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    return pushObject<TaskData>(L, instance->taskData, TaskDataBinding::getMetatableName());
}

// --- Setters for Tasker ---
static int Tasker_set_resetsWhenDone(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    instance->resetsWhenDone = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Tasker_set_subject(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    instance->subject = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int Tasker_set_weight(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    instance->weight = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Tasker_set_currentSubTarget(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    instance->currentSubTarget = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int Tasker_set_location(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    readVector3(L, 2, instance->location);
    return 0;
}

static int Tasker_set_startTime(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    instance->startTime = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Tasker_set_endTime(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    instance->endTime = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Tasker_set_taskData(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    instance->taskData = lua_isnoneornil(L, 2) ? nullptr : checkObject<TaskData>(L, 2, TaskDataBinding::getMetatableName());
    return 0;
}

int TaskerBinding::checkTimeOfDay(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");

    bool result = instance->checkTimeOfDay();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskerBinding::getFrameTime(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");

    CharBody* b = checkObject<CharBody>(L, 2, CharBodyBinding::getMetatableName());
    float result = instance->getFrameTime(b);
    lua_pushnumber(L, result);
    return 1;
}

int TaskerBinding::key(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");

    TaskType result = instance->key();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TaskerBinding::unSkippableJob(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");

    bool result = instance->unSkippableJob();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskerBinding::getLocation(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");

    Ogre::Vector3 result = instance->getLocation();
    pushVector3(L, result);
    return 1;
}

int TaskerBinding::setLocation(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");

    Ogre::Vector3 loc;
    readVector3(L, 2, loc);
    instance->setLocation(loc);
    return 0;
}

int TaskerBinding::sameAs(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");

    Tasker* t = checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    bool result = instance->sameAs(t);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskerBinding::hasActionFunc(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");

    bool result = instance->hasActionFunc();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskerBinding::isSubTasker(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");

    bool result = instance->isSubTasker();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskerBinding::getSubTask(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");

    TaskStateData* result = instance->getSubTask();
    return pushObject<TaskStateData>(L, result, TaskStateDataBinding::getMetatableName());
}

int TaskerBinding::isInfiniteGoal(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");

    bool result = instance->isInfiniteGoal();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskerBinding::needsSubjectOrLocation(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");

    bool result = instance->needsSubjectOrLocation();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskerBinding::getTaskData(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");

    const TaskData*const result = instance->getTaskData();
    return pushObject<TaskData>(L, const_cast<TaskData*>(result), TaskDataBinding::getMetatableName());
}

int TaskerBinding::startAction(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");

    CharBody* _a1 = checkObject<CharBody>(L, 2, CharBodyBinding::getMetatableName());
    instance->startAction(_a1);
    return 0;
}

int TaskerBinding::_NV_startAction(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");

    CharBody* _a1 = checkObject<CharBody>(L, 2, CharBodyBinding::getMetatableName());
    instance->_NV_startAction(_a1);
    return 0;
}

int TaskerBinding::runAction(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");

    CharBody* _a1 = checkObject<CharBody>(L, 2, CharBodyBinding::getMetatableName());
    instance->runAction(_a1);
    return 0;
}

int TaskerBinding::endAction(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");

    CharBody* _a1 = checkObject<CharBody>(L, 2, CharBodyBinding::getMetatableName());
    instance->endAction(_a1);
    return 0;
}

int TaskerBinding::_NV_endAction(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");

    CharBody* _a1 = checkObject<CharBody>(L, 2, CharBodyBinding::getMetatableName());
    instance->_NV_endAction(_a1);
    return 0;
}

int TaskerBinding::taskSaysItsFinished(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");

    Character* me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->taskSaysItsFinished(me);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskerBinding::_NV_taskSaysItsFinished(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");

    Character* me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->_NV_taskSaysItsFinished(me);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 326: const std::string& getDescription(...) - reference return type
  line 341: bool isSubTaskerTargetFinishedWith(...) - unsupported arg type
  line 358: float findTarget(...) - unsupported arg type
  line 359: bool _targetsRemaining(...) - unsupported arg type
  line 360: bool isSubTaskerComplete(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 319: priority (taskPriority) - unsupported type
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



static int Tasker_get_priority(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    lua_pushinteger(L, (lua_Integer)instance->priority);
    return 1;
}


static int Tasker_set_priority(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    instance->priority = (taskPriority)luaL_checkinteger(L, 2);
    return 0;
}


int TaskerBinding::getNextSubTarget(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    AI* ai = (AI*)lua_touserdata(L, 2);
    hand res = instance->getNextSubTarget(ai);
    return pushObject<hand>(L, new hand(res), HandBinding::getMetatableName());
}


int TaskerBinding::getRequirementComplaint(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    AI* ai = (AI*)lua_touserdata(L, 2);
    bool autoTargetFinder = lua_toboolean(L, 3) != 0;
    std::string res = instance->getRequirementComplaint(ai, autoTargetFinder);
    lua_pushstring(L, res.c_str());
    return 1;
}


int TaskerBinding::isRequirementsComplete(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    AI* ai = (AI*)lua_touserdata(L, 2);
    bool autoTargetFinder = lua_toboolean(L, 3) != 0;
    bool res = instance->isRequirementsComplete(ai, autoTargetFinder);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}


int TaskerBinding::isResultsComplete(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    AI* ai = (AI*)lua_touserdata(L, 2);
    bool res = instance->isResultsComplete(ai);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}


int TaskerBinding::isResultsComplete_ignoreSubtasker(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    AI* ai = (AI*)lua_touserdata(L, 2);
    bool res = instance->isResultsComplete_ignoreSubtasker(ai);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}


int TaskerBinding::score(lua_State* L)
{
    Tasker* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Tasker is nil");
    AI* ai = (AI*)lua_touserdata(L, 2);
    float res = instance->score(ai);
    lua_pushnumber(L, res);
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
        { "checkTimeOfDay", TaskerBinding::checkTimeOfDay },
        { "getFrameTime", TaskerBinding::getFrameTime },
        { "key", TaskerBinding::key },
        { "unSkippableJob", TaskerBinding::unSkippableJob },
        { "getLocation", TaskerBinding::getLocation },
        { "setLocation", TaskerBinding::setLocation },
        { "sameAs", TaskerBinding::sameAs },
        { "hasActionFunc", TaskerBinding::hasActionFunc },
        { "isSubTasker", TaskerBinding::isSubTasker },
        { "getSubTask", TaskerBinding::getSubTask },
        { "isInfiniteGoal", TaskerBinding::isInfiniteGoal },
        { "needsSubjectOrLocation", TaskerBinding::needsSubjectOrLocation },
        { "getTaskData", TaskerBinding::getTaskData },
        { "startAction", TaskerBinding::startAction },
        { "_NV_startAction", TaskerBinding::_NV_startAction },
        { "runAction", TaskerBinding::runAction },
        { "endAction", TaskerBinding::endAction },
        { "_NV_endAction", TaskerBinding::_NV_endAction },
        { "taskSaysItsFinished", TaskerBinding::taskSaysItsFinished },
        { "_NV_taskSaysItsFinished", TaskerBinding::_NV_taskSaysItsFinished },
                { "score", TaskerBinding::score },
        { "isResultsComplete", TaskerBinding::isResultsComplete },
        { "isResultsComplete_ignoreSubtasker", TaskerBinding::isResultsComplete_ignoreSubtasker },
        { "isRequirementsComplete", TaskerBinding::isRequirementsComplete },
        { "getRequirementComplaint", TaskerBinding::getRequirementComplaint },
        { "getNextSubTarget", TaskerBinding::getNextSubTarget },
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
    registerGetter(L, "resetsWhenDone", Tasker_get_resetsWhenDone);
    registerGetter(L, "subject", Tasker_get_subject);
    registerGetter(L, "weight", Tasker_get_weight);
    registerGetter(L, "currentSubTarget", Tasker_get_currentSubTarget);
    registerGetter(L, "location", Tasker_get_location);
    registerGetter(L, "startTime", Tasker_get_startTime);
    registerGetter(L, "endTime", Tasker_get_endTime);
    registerGetter(L, "taskData", Tasker_get_taskData);
        registerGetter(L, "priority", Tasker_get_priority);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "resetsWhenDone", Tasker_set_resetsWhenDone);
    registerSetter(L, "subject", Tasker_set_subject);
    registerSetter(L, "weight", Tasker_set_weight);
    registerSetter(L, "currentSubTarget", Tasker_set_currentSubTarget);
    registerSetter(L, "location", Tasker_set_location);
    registerSetter(L, "startTime", Tasker_set_startTime);
    registerSetter(L, "endTime", Tasker_set_endTime);
    registerSetter(L, "taskData", Tasker_set_taskData);
        registerSetter(L, "priority", Tasker_set_priority);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, TaskerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
