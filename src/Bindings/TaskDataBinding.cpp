#include "pch.h"
#include "kenshi\Tasker.h"
#include "TaskDataBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static TaskData* getB(lua_State* L, int idx)
{
    return checkObject<TaskData>(L, idx, TaskDataBinding::getMetatableName());
}

// --- Getters for TaskData ---
static int TaskData_get_infrequentGoalChecks(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, b->infrequentGoalChecks ? 1 : 0);
    return 1;
}

static int TaskData_get_permaJob(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    // TODO: Unsupported type for permaJob (PermajobType)
    return luaL_error(L, "Unsupported property 'permaJob' (type: PermajobType)");
}

static int TaskData_get_permaJob_FixedTarget(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, b->permaJob_FixedTarget ? 1 : 0);
    return 1;
}

static int TaskData_get_permaJob_Associated(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushinteger(L, (lua_Integer)b->permaJob_Associated);
    return 1;
}

static int TaskData_get_permaJob_Associated_Secondary(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushinteger(L, (lua_Integer)b->permaJob_Associated_Secondary);
    return 1;
}

static int TaskData_get_requirementsAlwaysFalse(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, b->requirementsAlwaysFalse ? 1 : 0);
    return 1;
}

static int TaskData_get__resultsAlwaysFalse(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, b->_resultsAlwaysFalse ? 1 : 0);
    return 1;
}

static int TaskData_get__requirementsCantEndActionPrematurely(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, b->_requirementsCantEndActionPrematurely ? 1 : 0);
    return 1;
}

static int TaskData_get_durationMin(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushnumber(L, b->durationMin);
    return 1;
}

static int TaskData_get_durationFuzz(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushnumber(L, b->durationFuzz);
    return 1;
}

static int TaskData_get_isDurationBased(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, b->isDurationBased ? 1 : 0);
    return 1;
}

static int TaskData_get_endsAfterTime(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, b->endsAfterTime ? 1 : 0);
    return 1;
}

static int TaskData_get_isUnstoppableTask(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, b->isUnstoppableTask ? 1 : 0);
    return 1;
}

static int TaskData_get_canDoTaskInStages(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, b->canDoTaskInStages ? 1 : 0);
    return 1;
}

static int TaskData_get_aggressionLevel(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushnumber(L, b->aggressionLevel);
    return 1;
}

static int TaskData_get_noisyness(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushnumber(L, b->noisyness);
    return 1;
}

static int TaskData_get_aidLevel(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushnumber(L, b->aidLevel);
    return 1;
}

static int TaskData_get_followMeWeight(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushnumber(L, b->followMeWeight);
    return 1;
}

static int TaskData_get_copyMeInfluence(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushnumber(L, b->copyMeInfluence);
    return 1;
}

static int TaskData_get_normallyLeadsToSomething(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, b->normallyLeadsToSomething ? 1 : 0);
    return 1;
}

static int TaskData_get_alertnessMult(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushnumber(L, b->alertnessMult);
    return 1;
}

static int TaskData_get_forDirectPlayerOrdersOnly(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, b->forDirectPlayerOrdersOnly ? 1 : 0);
    return 1;
}

static int TaskData_get_forFulfillPlayerOrdersOrNPCOnly(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, b->forFulfillPlayerOrdersOrNPCOnly ? 1 : 0);
    return 1;
}

static int TaskData_get_key(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushinteger(L, (lua_Integer)b->key);
    return 1;
}

static int TaskData_get_needsTarget(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, b->needsTarget ? 1 : 0);
    return 1;
}

static int TaskData_get_numResults(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushinteger(L, b->numResults);
    return 1;
}

static int TaskData_get_results(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    // TODO: Unsupported type for results (TaskStateData)
    return luaL_error(L, "Unsupported property 'results' (type: TaskStateData)");
}

static int TaskData_get_numRequirements(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushinteger(L, b->numRequirements);
    return 1;
}

static int TaskData_get_requirements(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    // TODO: Unsupported type for requirements (TaskStateData)
    return luaL_error(L, "Unsupported property 'requirements' (type: TaskStateData)");
}

static int TaskData_get_scoreFunction(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    // TODO: Unsupported type for scoreFunction (function*)
    return luaL_error(L, "Unsupported property 'scoreFunction' (type: function*)");
}

static int TaskData_get_justDoOneTarget(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, b->justDoOneTarget ? 1 : 0);
    return 1;
}

static int TaskData_get_subTask(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    // TODO: Unsupported type for subTask (TaskStateData*)
    return luaL_error(L, "Unsupported property 'subTask' (type: TaskStateData*)");
}

static int TaskData_get_dialogueDelivery(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushinteger(L, (lua_Integer)b->dialogueDelivery);
    return 1;
}

static int TaskData_get_hasAction(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushboolean(L, b->hasAction ? 1 : 0);
    return 1;
}

static int TaskData_get_description(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    lua_pushstring(L, b->description.c_str());
    return 1;
}

static int TaskData_get__findTarget(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    // TODO: Unsupported type for _findTarget (function*)
    return luaL_error(L, "Unsupported property '_findTarget' (type: function*)");
}

// --- Setters for TaskData ---
static int TaskData_set_infrequentGoalChecks(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->infrequentGoalChecks = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_permaJob(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for permaJob");
}

static int TaskData_set_permaJob_FixedTarget(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->permaJob_FixedTarget = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_permaJob_Associated(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->permaJob_Associated = (TaskType)luaL_checkinteger(L, 2);
    return 0;
}

static int TaskData_set_permaJob_Associated_Secondary(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->permaJob_Associated_Secondary = (TaskType)luaL_checkinteger(L, 2);
    return 0;
}

static int TaskData_set_requirementsAlwaysFalse(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->requirementsAlwaysFalse = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set__resultsAlwaysFalse(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->_resultsAlwaysFalse = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set__requirementsCantEndActionPrematurely(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->_requirementsCantEndActionPrematurely = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_durationMin(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->durationMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TaskData_set_durationFuzz(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->durationFuzz = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TaskData_set_isDurationBased(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->isDurationBased = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_endsAfterTime(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->endsAfterTime = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_isUnstoppableTask(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->isUnstoppableTask = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_canDoTaskInStages(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->canDoTaskInStages = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_aggressionLevel(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->aggressionLevel = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TaskData_set_noisyness(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->noisyness = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TaskData_set_aidLevel(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->aidLevel = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TaskData_set_followMeWeight(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->followMeWeight = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TaskData_set_copyMeInfluence(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->copyMeInfluence = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TaskData_set_normallyLeadsToSomething(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->normallyLeadsToSomething = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_alertnessMult(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->alertnessMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TaskData_set_forDirectPlayerOrdersOnly(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->forDirectPlayerOrdersOnly = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_forFulfillPlayerOrdersOrNPCOnly(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->forFulfillPlayerOrdersOrNPCOnly = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_key(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->key = (TaskType)luaL_checkinteger(L, 2);
    return 0;
}

static int TaskData_set_needsTarget(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->needsTarget = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_numResults(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->numResults = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int TaskData_set_results(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for results");
}

static int TaskData_set_numRequirements(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->numRequirements = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int TaskData_set_requirements(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for requirements");
}

static int TaskData_set_scoreFunction(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for scoreFunction");
}

static int TaskData_set_justDoOneTarget(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->justDoOneTarget = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_subTask(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for subTask");
}

static int TaskData_set_dialogueDelivery(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->dialogueDelivery = (EventTriggerEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int TaskData_set_hasAction(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->hasAction = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskData_set_description(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    b->description = luaL_checkstring(L, 2);
    return 0;
}

static int TaskData_set__findTarget(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for _findTarget");
}

int TaskDataBinding::setCharacteristics(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");

    float _aid = (float)luaL_checknumber(L, 2);
    float _aggressionLevel = (float)luaL_checknumber(L, 3);
    float noise = (float)luaL_checknumber(L, 4);
    bool leadsSomewhere = lua_toboolean(L, 5) != 0;
    b->setCharacteristics(_aid, _aggressionLevel, noise, leadsSomewhere);
    return 0;
}

int TaskDataBinding::setInfrequentGoalChecks(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");

    b->setInfrequentGoalChecks();
    return 0;
}

int TaskDataBinding::setAlertnessMult(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");

    float a = (float)luaL_checknumber(L, 2);
    b->setAlertnessMult(a);
    return 0;
}

int TaskDataBinding::setRequirementsCantEndActionPrematurely(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->setRequirementsCantEndActionPrematurely(on);
    return 0;
}

int TaskDataBinding::setCopyMeInfluence(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");

    float weight = (float)luaL_checknumber(L, 2);
    b->setCopyMeInfluence(weight);
    return 0;
}

int TaskDataBinding::setFollowMeWeight(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");

    float weight = (float)luaL_checknumber(L, 2);
    b->setFollowMeWeight(weight);
    return 0;
}

int TaskDataBinding::setSelfRegulation(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");

    bool requirements = lua_toboolean(L, 2) != 0;
    bool results = lua_toboolean(L, 3) != 0;
    b->setSelfRegulation(requirements, results);
    return 0;
}

int TaskDataBinding::setDurationBased(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");

    float mintime = (float)luaL_checknumber(L, 2);
    float fuzz = (float)luaL_checknumber(L, 3);
    bool _endsAfterTime = lua_toboolean(L, 4) != 0;
    b->setDurationBased(mintime, fuzz, _endsAfterTime);
    return 0;
}

int TaskDataBinding::hasInfrequentGoalChecks(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");

    bool result = b->hasInfrequentGoalChecks();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskDataBinding::getRequirementsCantEndActionPrematurely(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");

    bool result = b->getRequirementsCantEndActionPrematurely();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskDataBinding::isPermaJob(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");

    bool result = b->isPermaJob();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskDataBinding::isPermaJobFixedTarget(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");

    bool result = b->isPermaJobFixedTarget();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskDataBinding::getPermaJobAssociation(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");

    TaskType result = b->getPermaJobAssociation();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TaskDataBinding::getPermaJobAssociation_secondary(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");

    TaskType result = b->getPermaJobAssociation_secondary();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TaskDataBinding::isTargetFinder(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");

    bool result = b->isTargetFinder();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskDataBinding::setDialogueDeliveryTag(lua_State* L)
{
    TaskData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskData is nil");

    EventTriggerEnum d = (EventTriggerEnum)luaL_checkinteger(L, 2);
    b->setDialogueDeliveryTag(d);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 227: TaskData* _CONSTRUCTOR(...) - unsupported arg type
  line 228: void addResult(...) - unsupported arg type
  line 229: void addRequirement(...) - unsupported arg type
  line 254: void setPermaJob(...) - unsupported arg type
  line 255: PermajobType getPermaJobType(...) - unsupported return type
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
    lua_pushcfunction(L, TaskData_get_infrequentGoalChecks);
    lua_setfield(L, -2, "infrequentGoalChecks");
    lua_pushcfunction(L, TaskData_get_permaJob);
    lua_setfield(L, -2, "permaJob");
    lua_pushcfunction(L, TaskData_get_permaJob_FixedTarget);
    lua_setfield(L, -2, "permaJob_FixedTarget");
    lua_pushcfunction(L, TaskData_get_permaJob_Associated);
    lua_setfield(L, -2, "permaJob_Associated");
    lua_pushcfunction(L, TaskData_get_permaJob_Associated_Secondary);
    lua_setfield(L, -2, "permaJob_Associated_Secondary");
    lua_pushcfunction(L, TaskData_get_requirementsAlwaysFalse);
    lua_setfield(L, -2, "requirementsAlwaysFalse");
    lua_pushcfunction(L, TaskData_get__resultsAlwaysFalse);
    lua_setfield(L, -2, "_resultsAlwaysFalse");
    lua_pushcfunction(L, TaskData_get__requirementsCantEndActionPrematurely);
    lua_setfield(L, -2, "_requirementsCantEndActionPrematurely");
    lua_pushcfunction(L, TaskData_get_durationMin);
    lua_setfield(L, -2, "durationMin");
    lua_pushcfunction(L, TaskData_get_durationFuzz);
    lua_setfield(L, -2, "durationFuzz");
    lua_pushcfunction(L, TaskData_get_isDurationBased);
    lua_setfield(L, -2, "isDurationBased");
    lua_pushcfunction(L, TaskData_get_endsAfterTime);
    lua_setfield(L, -2, "endsAfterTime");
    lua_pushcfunction(L, TaskData_get_isUnstoppableTask);
    lua_setfield(L, -2, "isUnstoppableTask");
    lua_pushcfunction(L, TaskData_get_canDoTaskInStages);
    lua_setfield(L, -2, "canDoTaskInStages");
    lua_pushcfunction(L, TaskData_get_aggressionLevel);
    lua_setfield(L, -2, "aggressionLevel");
    lua_pushcfunction(L, TaskData_get_noisyness);
    lua_setfield(L, -2, "noisyness");
    lua_pushcfunction(L, TaskData_get_aidLevel);
    lua_setfield(L, -2, "aidLevel");
    lua_pushcfunction(L, TaskData_get_followMeWeight);
    lua_setfield(L, -2, "followMeWeight");
    lua_pushcfunction(L, TaskData_get_copyMeInfluence);
    lua_setfield(L, -2, "copyMeInfluence");
    lua_pushcfunction(L, TaskData_get_normallyLeadsToSomething);
    lua_setfield(L, -2, "normallyLeadsToSomething");
    lua_pushcfunction(L, TaskData_get_alertnessMult);
    lua_setfield(L, -2, "alertnessMult");
    lua_pushcfunction(L, TaskData_get_forDirectPlayerOrdersOnly);
    lua_setfield(L, -2, "forDirectPlayerOrdersOnly");
    lua_pushcfunction(L, TaskData_get_forFulfillPlayerOrdersOrNPCOnly);
    lua_setfield(L, -2, "forFulfillPlayerOrdersOrNPCOnly");
    lua_pushcfunction(L, TaskData_get_key);
    lua_setfield(L, -2, "key");
    lua_pushcfunction(L, TaskData_get_needsTarget);
    lua_setfield(L, -2, "needsTarget");
    lua_pushcfunction(L, TaskData_get_numResults);
    lua_setfield(L, -2, "numResults");
    lua_pushcfunction(L, TaskData_get_results);
    lua_setfield(L, -2, "results");
    lua_pushcfunction(L, TaskData_get_numRequirements);
    lua_setfield(L, -2, "numRequirements");
    lua_pushcfunction(L, TaskData_get_requirements);
    lua_setfield(L, -2, "requirements");
    lua_pushcfunction(L, TaskData_get_scoreFunction);
    lua_setfield(L, -2, "scoreFunction");
    lua_pushcfunction(L, TaskData_get_justDoOneTarget);
    lua_setfield(L, -2, "justDoOneTarget");
    lua_pushcfunction(L, TaskData_get_subTask);
    lua_setfield(L, -2, "subTask");
    lua_pushcfunction(L, TaskData_get_dialogueDelivery);
    lua_setfield(L, -2, "dialogueDelivery");
    lua_pushcfunction(L, TaskData_get_hasAction);
    lua_setfield(L, -2, "hasAction");
    lua_pushcfunction(L, TaskData_get_description);
    lua_setfield(L, -2, "description");
    lua_pushcfunction(L, TaskData_get__findTarget);
    lua_setfield(L, -2, "_findTarget");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, TaskData_set_infrequentGoalChecks);
    lua_setfield(L, -2, "infrequentGoalChecks");
    lua_pushcfunction(L, TaskData_set_permaJob);
    lua_setfield(L, -2, "permaJob");
    lua_pushcfunction(L, TaskData_set_permaJob_FixedTarget);
    lua_setfield(L, -2, "permaJob_FixedTarget");
    lua_pushcfunction(L, TaskData_set_permaJob_Associated);
    lua_setfield(L, -2, "permaJob_Associated");
    lua_pushcfunction(L, TaskData_set_permaJob_Associated_Secondary);
    lua_setfield(L, -2, "permaJob_Associated_Secondary");
    lua_pushcfunction(L, TaskData_set_requirementsAlwaysFalse);
    lua_setfield(L, -2, "requirementsAlwaysFalse");
    lua_pushcfunction(L, TaskData_set__resultsAlwaysFalse);
    lua_setfield(L, -2, "_resultsAlwaysFalse");
    lua_pushcfunction(L, TaskData_set__requirementsCantEndActionPrematurely);
    lua_setfield(L, -2, "_requirementsCantEndActionPrematurely");
    lua_pushcfunction(L, TaskData_set_durationMin);
    lua_setfield(L, -2, "durationMin");
    lua_pushcfunction(L, TaskData_set_durationFuzz);
    lua_setfield(L, -2, "durationFuzz");
    lua_pushcfunction(L, TaskData_set_isDurationBased);
    lua_setfield(L, -2, "isDurationBased");
    lua_pushcfunction(L, TaskData_set_endsAfterTime);
    lua_setfield(L, -2, "endsAfterTime");
    lua_pushcfunction(L, TaskData_set_isUnstoppableTask);
    lua_setfield(L, -2, "isUnstoppableTask");
    lua_pushcfunction(L, TaskData_set_canDoTaskInStages);
    lua_setfield(L, -2, "canDoTaskInStages");
    lua_pushcfunction(L, TaskData_set_aggressionLevel);
    lua_setfield(L, -2, "aggressionLevel");
    lua_pushcfunction(L, TaskData_set_noisyness);
    lua_setfield(L, -2, "noisyness");
    lua_pushcfunction(L, TaskData_set_aidLevel);
    lua_setfield(L, -2, "aidLevel");
    lua_pushcfunction(L, TaskData_set_followMeWeight);
    lua_setfield(L, -2, "followMeWeight");
    lua_pushcfunction(L, TaskData_set_copyMeInfluence);
    lua_setfield(L, -2, "copyMeInfluence");
    lua_pushcfunction(L, TaskData_set_normallyLeadsToSomething);
    lua_setfield(L, -2, "normallyLeadsToSomething");
    lua_pushcfunction(L, TaskData_set_alertnessMult);
    lua_setfield(L, -2, "alertnessMult");
    lua_pushcfunction(L, TaskData_set_forDirectPlayerOrdersOnly);
    lua_setfield(L, -2, "forDirectPlayerOrdersOnly");
    lua_pushcfunction(L, TaskData_set_forFulfillPlayerOrdersOrNPCOnly);
    lua_setfield(L, -2, "forFulfillPlayerOrdersOrNPCOnly");
    lua_pushcfunction(L, TaskData_set_key);
    lua_setfield(L, -2, "key");
    lua_pushcfunction(L, TaskData_set_needsTarget);
    lua_setfield(L, -2, "needsTarget");
    lua_pushcfunction(L, TaskData_set_numResults);
    lua_setfield(L, -2, "numResults");
    lua_pushcfunction(L, TaskData_set_results);
    lua_setfield(L, -2, "results");
    lua_pushcfunction(L, TaskData_set_numRequirements);
    lua_setfield(L, -2, "numRequirements");
    lua_pushcfunction(L, TaskData_set_requirements);
    lua_setfield(L, -2, "requirements");
    lua_pushcfunction(L, TaskData_set_scoreFunction);
    lua_setfield(L, -2, "scoreFunction");
    lua_pushcfunction(L, TaskData_set_justDoOneTarget);
    lua_setfield(L, -2, "justDoOneTarget");
    lua_pushcfunction(L, TaskData_set_subTask);
    lua_setfield(L, -2, "subTask");
    lua_pushcfunction(L, TaskData_set_dialogueDelivery);
    lua_setfield(L, -2, "dialogueDelivery");
    lua_pushcfunction(L, TaskData_set_hasAction);
    lua_setfield(L, -2, "hasAction");
    lua_pushcfunction(L, TaskData_set_description);
    lua_setfield(L, -2, "description");
    lua_pushcfunction(L, TaskData_set__findTarget);
    lua_setfield(L, -2, "_findTarget");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua