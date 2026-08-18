#include "pch.h"
#include "kenshi\Tasker.h"
#include "TaskDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/TaskStateDataBinding.h"

namespace KenshiLua
{

static TaskData* getInstance(lua_State* L, int idx)
{
    return checkObject<TaskData>(L, idx, TaskDataBinding::getMetatableName());
}

// --- Getters for TaskData ---
static int TaskData_get_infrequentGoalChecks(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, instance->infrequentGoalChecks ? 1 : 0);
    return 1;
}

static int TaskData_get_permaJob_FixedTarget(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, instance->permaJob_FixedTarget ? 1 : 0);
    return 1;
}

static int TaskData_get_permaJob_Associated(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushinteger(L, (lua_Integer)instance->permaJob_Associated);
    return 1;
}

static int TaskData_get_permaJob_Associated_Secondary(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushinteger(L, (lua_Integer)instance->permaJob_Associated_Secondary);
    return 1;
}

static int TaskData_get_requirementsAlwaysFalse(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, instance->requirementsAlwaysFalse ? 1 : 0);
    return 1;
}

static int TaskData_get__resultsAlwaysFalse(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, instance->_resultsAlwaysFalse ? 1 : 0);
    return 1;
}

static int TaskData_get__requirementsCantEndActionPrematurely(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, instance->_requirementsCantEndActionPrematurely ? 1 : 0);
    return 1;
}

static int TaskData_get_durationMin(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushnumber(L, instance->durationMin);
    return 1;
}

static int TaskData_get_durationFuzz(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushnumber(L, instance->durationFuzz);
    return 1;
}

static int TaskData_get_isDurationBased(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, instance->isDurationBased ? 1 : 0);
    return 1;
}

static int TaskData_get_endsAfterTime(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, instance->endsAfterTime ? 1 : 0);
    return 1;
}

static int TaskData_get_isUnstoppableTask(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, instance->isUnstoppableTask ? 1 : 0);
    return 1;
}

static int TaskData_get_canDoTaskInStages(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, instance->canDoTaskInStages ? 1 : 0);
    return 1;
}

static int TaskData_get_aggressionLevel(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushnumber(L, instance->aggressionLevel);
    return 1;
}

static int TaskData_get_noisyness(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushnumber(L, instance->noisyness);
    return 1;
}

static int TaskData_get_aidLevel(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushnumber(L, instance->aidLevel);
    return 1;
}

static int TaskData_get_followMeWeight(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushnumber(L, instance->followMeWeight);
    return 1;
}

static int TaskData_get_copyMeInfluence(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushnumber(L, instance->copyMeInfluence);
    return 1;
}

static int TaskData_get_normallyLeadsToSomething(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, instance->normallyLeadsToSomething ? 1 : 0);
    return 1;
}

static int TaskData_get_alertnessMult(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushnumber(L, instance->alertnessMult);
    return 1;
}

static int TaskData_get_forDirectPlayerOrdersOnly(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, instance->forDirectPlayerOrdersOnly ? 1 : 0);
    return 1;
}

static int TaskData_get_forFulfillPlayerOrdersOrNPCOnly(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, instance->forFulfillPlayerOrdersOrNPCOnly ? 1 : 0);
    return 1;
}

static int TaskData_get_key(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushinteger(L, (lua_Integer)instance->key);
    return 1;
}

static int TaskData_get_needsTarget(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, instance->needsTarget ? 1 : 0);
    return 1;
}

static int TaskData_get_numResults(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushinteger(L, instance->numResults);
    return 1;
}

static int TaskData_get_results(lua_State* L) { return 0; }

static int TaskData_get_numRequirements(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushinteger(L, instance->numRequirements);
    return 1;
}

static int TaskData_get_requirements(lua_State* L) { return 0; }

static int TaskData_get_scoreFunction(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushlightuserdata(L, (void*)instance->scoreFunction);
    return 1;
}

static int TaskData_get_justDoOneTarget(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, instance->justDoOneTarget ? 1 : 0);
    return 1;
}

static int TaskData_get_subTask(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    return pushObject<TaskStateData>(L, instance->subTask, TaskStateDataBinding::getMetatableName());
}

static int TaskData_get_dialogueDelivery(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushinteger(L, (lua_Integer)instance->dialogueDelivery);
    return 1;
}

static int TaskData_get_hasAction(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, instance->hasAction ? 1 : 0);
    return 1;
}

static int TaskData_get_description(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushstring(L, instance->description.c_str());
    return 1;
}

static int TaskData_get__findTarget(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushlightuserdata(L, (void*)instance->_findTarget);
    return 1;
}

// --- Setters for TaskData ---
static int TaskData_set_infrequentGoalChecks(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->infrequentGoalChecks = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_permaJob_FixedTarget(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->permaJob_FixedTarget = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_permaJob_Associated(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->permaJob_Associated = (TaskType)luaL_checkinteger(L, 2);
    return 0;
}

static int TaskData_set_permaJob_Associated_Secondary(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->permaJob_Associated_Secondary = (TaskType)luaL_checkinteger(L, 2);
    return 0;
}

static int TaskData_set_requirementsAlwaysFalse(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->requirementsAlwaysFalse = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set__resultsAlwaysFalse(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->_resultsAlwaysFalse = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set__requirementsCantEndActionPrematurely(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->_requirementsCantEndActionPrematurely = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_durationMin(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->durationMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TaskData_set_durationFuzz(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->durationFuzz = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TaskData_set_isDurationBased(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->isDurationBased = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_endsAfterTime(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->endsAfterTime = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_isUnstoppableTask(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->isUnstoppableTask = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_canDoTaskInStages(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->canDoTaskInStages = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_aggressionLevel(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->aggressionLevel = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TaskData_set_noisyness(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->noisyness = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TaskData_set_aidLevel(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->aidLevel = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TaskData_set_followMeWeight(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->followMeWeight = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TaskData_set_copyMeInfluence(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->copyMeInfluence = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TaskData_set_normallyLeadsToSomething(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->normallyLeadsToSomething = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_alertnessMult(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->alertnessMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TaskData_set_forDirectPlayerOrdersOnly(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->forDirectPlayerOrdersOnly = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_forFulfillPlayerOrdersOrNPCOnly(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->forFulfillPlayerOrdersOrNPCOnly = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_key(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->key = (TaskType)luaL_checkinteger(L, 2);
    return 0;
}

static int TaskData_set_needsTarget(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->needsTarget = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_numResults(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->numResults = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int TaskData_set_results(lua_State* L) { return 0; }

static int TaskData_set_numRequirements(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->numRequirements = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int TaskData_set_requirements(lua_State* L) { return 0; }

static int TaskData_set_justDoOneTarget(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->justDoOneTarget = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_subTask(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->subTask = lua_isnoneornil(L, 2) ? nullptr : checkObject<TaskStateData>(L, 2, TaskStateDataBinding::getMetatableName());
    return 0;
}

static int TaskData_set_dialogueDelivery(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->dialogueDelivery = (EventTriggerEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int TaskData_set_hasAction(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->hasAction = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_description(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->description = luaL_checkstring(L, 2);
    return 0;
}

int TaskDataBinding::setCharacteristics(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");

    float _aid = (float)luaL_checknumber(L, 2);
    float _aggressionLevel = (float)luaL_checknumber(L, 3);
    float noise = (float)luaL_checknumber(L, 4);
    bool leadsSomewhere = lua_toboolean(L, 5) != 0;
    instance->setCharacteristics(_aid, _aggressionLevel, noise, leadsSomewhere);
    return 0;
}

int TaskDataBinding::setInfrequentGoalChecks(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");

    instance->setInfrequentGoalChecks();
    return 0;
}

int TaskDataBinding::setAlertnessMult(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");

    float a = (float)luaL_checknumber(L, 2);
    instance->setAlertnessMult(a);
    return 0;
}

int TaskDataBinding::setRequirementsCantEndActionPrematurely(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setRequirementsCantEndActionPrematurely(on);
    return 0;
}

int TaskDataBinding::setCopyMeInfluence(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");

    float weight = (float)luaL_checknumber(L, 2);
    instance->setCopyMeInfluence(weight);
    return 0;
}

int TaskDataBinding::setFollowMeWeight(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");

    float weight = (float)luaL_checknumber(L, 2);
    instance->setFollowMeWeight(weight);
    return 0;
}

int TaskDataBinding::setSelfRegulation(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");

    bool requirements = lua_toboolean(L, 2) != 0;
    bool results = lua_toboolean(L, 3) != 0;
    instance->setSelfRegulation(requirements, results);
    return 0;
}

int TaskDataBinding::setDurationBased(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");

    float mintime = (float)luaL_checknumber(L, 2);
    float fuzz = (float)luaL_checknumber(L, 3);
    bool _endsAfterTime = lua_toboolean(L, 4) != 0;
    instance->setDurationBased(mintime, fuzz, _endsAfterTime);
    return 0;
}

int TaskDataBinding::hasInfrequentGoalChecks(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");

    bool result = instance->hasInfrequentGoalChecks();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskDataBinding::getRequirementsCantEndActionPrematurely(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");

    bool result = instance->getRequirementsCantEndActionPrematurely();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskDataBinding::isPermaJob(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");

    bool result = instance->isPermaJob();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskDataBinding::isPermaJobFixedTarget(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");

    bool result = instance->isPermaJobFixedTarget();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskDataBinding::getPermaJobAssociation(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");

    TaskType result = instance->getPermaJobAssociation();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TaskDataBinding::getPermaJobAssociation_secondary(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");

    TaskType result = instance->getPermaJobAssociation_secondary();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TaskDataBinding::isTargetFinder(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");

    bool result = instance->isTargetFinder();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskDataBinding::setDialogueDeliveryTag(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");

    EventTriggerEnum d = (EventTriggerEnum)luaL_checkinteger(L, 2);
    instance->setDialogueDeliveryTag(d);
    return 0;
}

int TaskDataBinding::setPermaJob(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");

    PermajobType on = (PermajobType)luaL_checkinteger(L, 2);
    bool fixedTarget = lua_toboolean(L, 3) != 0;
    TaskType t = (TaskType)luaL_checkinteger(L, 4);
    TaskType secondary = (TaskType)luaL_checkinteger(L, 5);

    instance->setPermaJob(on, fixedTarget, t, secondary);
    return 0;
}

int TaskDataBinding::getPermaJobType(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");

    PermajobType result = instance->getPermaJobType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 228: void addResult(...) - unsupported arg type
  line 229: void addRequirement(...) - unsupported arg type
  line 278: bool isResultsComplete(...) - unsupported arg type
  line 279: bool isResultsComplete_ignoreSubtasker(...) - unsupported arg type
  line 280: void getRequirementComplaint(...) - non-string reference arg
  line 281: bool _isRequirementsComplete(...) - unsupported arg type
  line 282: bool isRequirementComplete(...) - unsupported arg type
  line 283: void setTargetingFunction(...) - unsupported arg type
  line 286: void setSubTask(...) - unsupported arg type
  line 292: float runTargetFind(...) - unsupported arg type
  line 293: bool _targetsRemaining(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - TaskData_get_scoreFunction: function* (unbound pointer)
  - TaskData_get__findTarget: function* (unbound pointer)
*/

int TaskDataBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TaskDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TaskData object");
    return 1;
}



static int TaskData_get_permaJob(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    lua_pushinteger(L, (lua_Integer)instance->permaJob);
    return 1;
}


static int TaskData_set__findTarget(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for _findTarget");
}


static int TaskData_set_permaJob(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    instance->permaJob = (PermajobType)luaL_checkinteger(L, 2);
    return 0;
}


static int TaskData_set_scoreFunction(lua_State* L)
{
    TaskData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for scoreFunction");
}


void TaskDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TaskDataBinding::gc },
        { "__tostring", TaskDataBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setCharacteristics", TaskDataBinding::setCharacteristics },
        { "setInfrequentGoalChecks", TaskDataBinding::setInfrequentGoalChecks },
        { "setAlertnessMult", TaskDataBinding::setAlertnessMult },
        { "setRequirementsCantEndActionPrematurely", TaskDataBinding::setRequirementsCantEndActionPrematurely },
        { "setCopyMeInfluence", TaskDataBinding::setCopyMeInfluence },
        { "setFollowMeWeight", TaskDataBinding::setFollowMeWeight },
        { "setSelfRegulation", TaskDataBinding::setSelfRegulation },
        { "setDurationBased", TaskDataBinding::setDurationBased },
        { "hasInfrequentGoalChecks", TaskDataBinding::hasInfrequentGoalChecks },
        { "getRequirementsCantEndActionPrematurely", TaskDataBinding::getRequirementsCantEndActionPrematurely },
        { "isPermaJob", TaskDataBinding::isPermaJob },
        { "isPermaJobFixedTarget", TaskDataBinding::isPermaJobFixedTarget },
        { "getPermaJobAssociation", TaskDataBinding::getPermaJobAssociation },
        { "getPermaJobAssociation_secondary", TaskDataBinding::getPermaJobAssociation_secondary },
        { "isTargetFinder", TaskDataBinding::isTargetFinder },
        { "setDialogueDeliveryTag", TaskDataBinding::setDialogueDeliveryTag },
        { "setPermaJob", TaskDataBinding::setPermaJob },
        { "getPermaJobType", TaskDataBinding::getPermaJobType },
        { 0, 0 }
    };

    registerClass(
        L, 
        TaskDataBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TaskDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "infrequentGoalChecks", TaskData_get_infrequentGoalChecks);
    registerGetter(L, "permaJob", TaskData_get_permaJob);
    registerGetter(L, "permaJob_FixedTarget", TaskData_get_permaJob_FixedTarget);
    registerGetter(L, "permaJob_Associated", TaskData_get_permaJob_Associated);
    registerGetter(L, "permaJob_Associated_Secondary", TaskData_get_permaJob_Associated_Secondary);
    registerGetter(L, "requirementsAlwaysFalse", TaskData_get_requirementsAlwaysFalse);
    registerGetter(L, "_resultsAlwaysFalse", TaskData_get__resultsAlwaysFalse);
    registerGetter(L, "_requirementsCantEndActionPrematurely", TaskData_get__requirementsCantEndActionPrematurely);
    registerGetter(L, "durationMin", TaskData_get_durationMin);
    registerGetter(L, "durationFuzz", TaskData_get_durationFuzz);
    registerGetter(L, "isDurationBased", TaskData_get_isDurationBased);
    registerGetter(L, "endsAfterTime", TaskData_get_endsAfterTime);
    registerGetter(L, "isUnstoppableTask", TaskData_get_isUnstoppableTask);
    registerGetter(L, "canDoTaskInStages", TaskData_get_canDoTaskInStages);
    registerGetter(L, "aggressionLevel", TaskData_get_aggressionLevel);
    registerGetter(L, "noisyness", TaskData_get_noisyness);
    registerGetter(L, "aidLevel", TaskData_get_aidLevel);
    registerGetter(L, "followMeWeight", TaskData_get_followMeWeight);
    registerGetter(L, "copyMeInfluence", TaskData_get_copyMeInfluence);
    registerGetter(L, "normallyLeadsToSomething", TaskData_get_normallyLeadsToSomething);
    registerGetter(L, "alertnessMult", TaskData_get_alertnessMult);
    registerGetter(L, "forDirectPlayerOrdersOnly", TaskData_get_forDirectPlayerOrdersOnly);
    registerGetter(L, "forFulfillPlayerOrdersOrNPCOnly", TaskData_get_forFulfillPlayerOrdersOrNPCOnly);
    registerGetter(L, "key", TaskData_get_key);
    registerGetter(L, "needsTarget", TaskData_get_needsTarget);
    registerGetter(L, "numResults", TaskData_get_numResults);
    registerGetter(L, "results", TaskData_get_results);
    registerGetter(L, "numRequirements", TaskData_get_numRequirements);
    registerGetter(L, "requirements", TaskData_get_requirements);
    registerGetter(L, "scoreFunction", TaskData_get_scoreFunction);
    registerGetter(L, "justDoOneTarget", TaskData_get_justDoOneTarget);
    registerGetter(L, "subTask", TaskData_get_subTask);
    registerGetter(L, "dialogueDelivery", TaskData_get_dialogueDelivery);
    registerGetter(L, "hasAction", TaskData_get_hasAction);
    registerGetter(L, "description", TaskData_get_description);
    registerGetter(L, "_findTarget", TaskData_get__findTarget);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "infrequentGoalChecks", TaskData_set_infrequentGoalChecks);
    registerSetter(L, "permaJob", TaskData_set_permaJob);
    registerSetter(L, "permaJob_FixedTarget", TaskData_set_permaJob_FixedTarget);
    registerSetter(L, "permaJob_Associated", TaskData_set_permaJob_Associated);
    registerSetter(L, "permaJob_Associated_Secondary", TaskData_set_permaJob_Associated_Secondary);
    registerSetter(L, "requirementsAlwaysFalse", TaskData_set_requirementsAlwaysFalse);
    registerSetter(L, "_resultsAlwaysFalse", TaskData_set__resultsAlwaysFalse);
    registerSetter(L, "_requirementsCantEndActionPrematurely", TaskData_set__requirementsCantEndActionPrematurely);
    registerSetter(L, "durationMin", TaskData_set_durationMin);
    registerSetter(L, "durationFuzz", TaskData_set_durationFuzz);
    registerSetter(L, "isDurationBased", TaskData_set_isDurationBased);
    registerSetter(L, "endsAfterTime", TaskData_set_endsAfterTime);
    registerSetter(L, "isUnstoppableTask", TaskData_set_isUnstoppableTask);
    registerSetter(L, "canDoTaskInStages", TaskData_set_canDoTaskInStages);
    registerSetter(L, "aggressionLevel", TaskData_set_aggressionLevel);
    registerSetter(L, "noisyness", TaskData_set_noisyness);
    registerSetter(L, "aidLevel", TaskData_set_aidLevel);
    registerSetter(L, "followMeWeight", TaskData_set_followMeWeight);
    registerSetter(L, "copyMeInfluence", TaskData_set_copyMeInfluence);
    registerSetter(L, "normallyLeadsToSomething", TaskData_set_normallyLeadsToSomething);
    registerSetter(L, "alertnessMult", TaskData_set_alertnessMult);
    registerSetter(L, "forDirectPlayerOrdersOnly", TaskData_set_forDirectPlayerOrdersOnly);
    registerSetter(L, "forFulfillPlayerOrdersOrNPCOnly", TaskData_set_forFulfillPlayerOrdersOrNPCOnly);
    registerSetter(L, "key", TaskData_set_key);
    registerSetter(L, "needsTarget", TaskData_set_needsTarget);
    registerSetter(L, "numResults", TaskData_set_numResults);
    registerSetter(L, "results", TaskData_set_results);
    registerSetter(L, "numRequirements", TaskData_set_numRequirements);
    registerSetter(L, "requirements", TaskData_set_requirements);
    registerSetter(L, "justDoOneTarget", TaskData_set_justDoOneTarget);
    registerSetter(L, "subTask", TaskData_set_subTask);
    registerSetter(L, "dialogueDelivery", TaskData_set_dialogueDelivery);
    registerSetter(L, "hasAction", TaskData_set_hasAction);
    registerSetter(L, "description", TaskData_set_description);
        registerSetter(L, "_findTarget", TaskData_set__findTarget);
        registerSetter(L, "scoreFunction", TaskData_set_scoreFunction);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, TaskDataBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua