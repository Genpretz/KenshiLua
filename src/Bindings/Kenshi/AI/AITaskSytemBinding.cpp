#include "pch.h"
#include "kenshi/Tasker.h"
#include "kenshi/AI/AITaskSystem.h"
#include "AITaskSytemBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/AI/AITaskSytem_ActionsListMgrBinding.h"
#include "Bindings/Kenshi/AI/TaskMatchBinding.h"
#include "Bindings/Kenshi/Util/StdMapBinding.h"
#include "Bindings/Kenshi/CharBodyBinding.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/Gui/DatapanelGUIBinding.h"
#include "Bindings/Kenshi/StateBroadcastDataBinding.h"
#include "Bindings/Kenshi/AI/TaskMatchBinding.h"
#include "Bindings/Kenshi/TaskerBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"
#include "Bindings/Kenshi/Util/OgreUnorderedBinding.h"
#include "Bindings/Kenshi/Util/StdMapBinding.h"
#include "Bindings/Kenshi/Util/TimeOfDayBinding.h"

namespace KenshiLua
{

static_assert(offsetof(AITaskSytem, pathFailures) == 0x218, "AITaskSytem::pathFailures offset does not match the game");
static_assert(offsetof(AITaskSytem, body) == 0x270, "AITaskSytem::body offset does not match the game");
static_assert(offsetof(AITaskSytem, actions) == 0x300, "AITaskSytem::actions offset does not match the game");
static_assert(offsetof(AITaskSytem, pos) == 0x398, "AITaskSytem::pos offset does not match the game");
static_assert(offsetof(AITaskSytem, taskRecursionLast) == 0x3B4, "AITaskSytem::taskRecursionLast offset does not match the game");

typedef LektorPtrBinding<Tasker*> TaskerLektorBinding;
typedef OgreUnorderedMapBinding<hand, float> HandFloatMapBinding;
typedef StdMapBinding<float, Tasker*> OrderedGoalsMapBinding;

static AITaskSytem* getInstance(lua_State* L, int idx)
{
    return checkObject<AITaskSytem>(L, idx, AITaskSytemBinding::getMetatableName());
}

// --- Getters for AITaskSytem ---
static int AITaskSytem_get_infrequentTimeStamp(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    lua_pushnumber(L, instance->infrequentTimeStamp);
    return 1;
}

static int AITaskSytem_get_pathFailures(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    return pushObject<HandFloatMapBinding::MapType>(L, &instance->pathFailures, HandFloatMapBinding::getMetatableName());
}

static int AITaskSytem_get__debugBreak(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    lua_pushboolean(L, instance->_debugBreak ? 1 : 0);
    return 1;
}

static int AITaskSytem_get__squadMemberType(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    lua_pushinteger(L, (lua_Integer)instance->_squadMemberType);
    return 1;
}

static int AITaskSytem_get_debugCount(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    lua_pushinteger(L, instance->debugCount);
    return 1;
}

static int AITaskSytem_get_currentDialogueDelivery(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    lua_pushinteger(L, (lua_Integer)instance->currentDialogueDelivery);
    return 1;
}

static int AITaskSytem_get__currentDialogueEnumQuery(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    lua_pushinteger(L, (lua_Integer)instance->_currentDialogueEnumQuery);
    return 1;
}

static int AITaskSytem_get__taskCompletedFlag(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    lua_pushboolean(L, instance->_taskCompletedFlag ? 1 : 0);
    return 1;
}

static int AITaskSytem_get__taskImpossibleFlag(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    lua_pushboolean(L, instance->_taskImpossibleFlag ? 1 : 0);
    return 1;
}

static int AITaskSytem_get_body(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    return pushObject<CharBody>(L, instance->body, CharBodyBinding::getMetatableName());
}

static int AITaskSytem_get_character(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    return pushObject<Character>(L, instance->character, CharacterBinding::getMetatableName());
}

static int AITaskSytem_get_currentGoalExpiryTime(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    return pushObject<TimeOfDay>(L, &instance->currentGoalExpiryTime, TimeOfDayBinding::getMetatableName());
}

static int AITaskSytem_get_currentTaskExpiryTime(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    return pushObject<TimeOfDay>(L, &instance->currentTaskExpiryTime, TimeOfDayBinding::getMetatableName());
}

static int AITaskSytem_get_autoSleepTask(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    return pushObject<Tasker>(L, instance->autoSleepTask, TaskerBinding::getMetatableName());
}

static int AITaskSytem_get_autoGetupTask(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    return pushObject<Tasker>(L, instance->autoGetupTask, TaskerBinding::getMetatableName());
}

static int AITaskSytem_get_autoDitchTask(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    return pushObject<Tasker>(L, instance->autoDitchTask, TaskerBinding::getMetatableName());
}

static int AITaskSytem_get_autoSitTask(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    return pushObject<Tasker>(L, instance->autoSitTask, TaskerBinding::getMetatableName());
}

static int AITaskSytem_get_autoEjectEnemiesTask1(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    return pushObject<Tasker>(L, instance->autoEjectEnemiesTask1, TaskerBinding::getMetatableName());
}

static int AITaskSytem_get_autoEjectEnemiesTask2(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    return pushObject<Tasker>(L, instance->autoEjectEnemiesTask2, TaskerBinding::getMetatableName());
}

static int AITaskSytem_get_orderedGoals(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    return pushObject<OrderedGoalsMapBinding::MapType>(L, &instance->orderedGoals, OrderedGoalsMapBinding::getMetatableName());
}

static int AITaskSytem_get_requestsList(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    return pushObject<lektor<Tasker*> >(L, &instance->requestsList, TaskerLektorBinding::getMetatableName());
}

static int AITaskSytem_get_actions(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    return pushObject<AITaskSytem::ActionsListMgr>(L, &instance->actions, AITaskSytem_ActionsListMgrBinding::getMetatableName());
}

static int AITaskSytem_get_actionsTryList(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    return pushObject<AITaskSytem::ActionsListMgr>(L, &instance->actionsTryList, AITaskSytem_ActionsListMgrBinding::getMetatableName());
}

static int AITaskSytem_get_failedGOAPGoalDebugString(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    lua_pushlstring(L, instance->failedGOAPGoalDebugString.c_str(), instance->failedGOAPGoalDebugString.size());
    return 1;
}

static int AITaskSytem_get_pos(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    pushVector3(L, instance->pos);
    return 1;
}

static int AITaskSytem_get_currentlySubTasking(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    return pushObject<Tasker>(L, instance->currentlySubTasking, TaskerBinding::getMetatableName());
}

static int AITaskSytem_get_setTaskRecursionCounter(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    lua_pushinteger(L, instance->setTaskRecursionCounter);
    return 1;
}

static int AITaskSytem_get_taskRecursionLast(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    lua_pushinteger(L, (lua_Integer)instance->taskRecursionLast);
    return 1;
}

// --- Setters for AITaskSytem ---
static int AITaskSytem_set_infrequentTimeStamp(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    instance->infrequentTimeStamp = luaL_checknumber(L, 2);
    return 0;
}

static int AITaskSytem_set__debugBreak(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    instance->_debugBreak = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AITaskSytem_set__squadMemberType(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    instance->_squadMemberType = (SquadMemberType)luaL_checkinteger(L, 2);
    return 0;
}

static int AITaskSytem_set_debugCount(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    instance->debugCount = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int AITaskSytem_set_currentDialogueDelivery(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    instance->currentDialogueDelivery = (EventTriggerEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int AITaskSytem_set__currentDialogueEnumQuery(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    instance->_currentDialogueEnumQuery = (EventTriggerEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int AITaskSytem_set__taskCompletedFlag(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    instance->_taskCompletedFlag = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AITaskSytem_set__taskImpossibleFlag(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    instance->_taskImpossibleFlag = lua_toboolean(L, 2) != 0;
    return 0;
}

// The constructor stores the owning CharBody and Character; owner pointers reject nil.
static int AITaskSytem_set_body(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    instance->body = checkObject<CharBody>(L, 2, CharBodyBinding::getMetatableName());
    return 0;
}

static int AITaskSytem_set_character(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    instance->character = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int AITaskSytem_set_currentGoalExpiryTime(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    instance->currentGoalExpiryTime = *checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    return 0;
}

static int AITaskSytem_set_currentTaskExpiryTime(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    instance->currentTaskExpiryTime = *checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    return 0;
}

// The constructor leaves the automatic tasks and currentlySubTasking null, and ~AITaskSytem does not delete them.
static int AITaskSytem_set_autoSleepTask(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    instance->autoSleepTask = lua_isnoneornil(L, 2) ? nullptr : checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    return 0;
}

static int AITaskSytem_set_autoGetupTask(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    instance->autoGetupTask = lua_isnoneornil(L, 2) ? nullptr : checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    return 0;
}

static int AITaskSytem_set_autoDitchTask(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    instance->autoDitchTask = lua_isnoneornil(L, 2) ? nullptr : checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    return 0;
}

static int AITaskSytem_set_autoSitTask(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    instance->autoSitTask = lua_isnoneornil(L, 2) ? nullptr : checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    return 0;
}

static int AITaskSytem_set_autoEjectEnemiesTask1(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    instance->autoEjectEnemiesTask1 = lua_isnoneornil(L, 2) ? nullptr : checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    return 0;
}

static int AITaskSytem_set_autoEjectEnemiesTask2(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    instance->autoEjectEnemiesTask2 = lua_isnoneornil(L, 2) ? nullptr : checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    return 0;
}

static int AITaskSytem_set_orderedGoals(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    OrderedGoalsMapBinding::MapType* value = OrderedGoalsMapBinding::getInstance(L, 2);
    if (!value) return luaL_argerror(L, 2, "std::map<float, Tasker*> expected");
    instance->orderedGoals = *value;
    return 0;
}

static int AITaskSytem_set_failedGOAPGoalDebugString(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    instance->failedGOAPGoalDebugString = luaL_checkstring(L, 2);
    return 0;
}

static int AITaskSytem_set_pos(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    Ogre::Vector3 value;
    if (!readVector3(L, 2, value)) return luaL_argerror(L, 2, "Vector3 table expected");
    instance->pos = value;
    return 0;
}

static int AITaskSytem_set_currentlySubTasking(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    instance->currentlySubTasking = lua_isnoneornil(L, 2) ? nullptr : checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    return 0;
}

static int AITaskSytem_set_setTaskRecursionCounter(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    instance->setTaskRecursionCounter = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int AITaskSytem_set_taskRecursionLast(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");
    instance->taskRecursionLast = (TaskType)luaL_checkinteger(L, 2);
    return 0;
}

int AITaskSytemBinding::canIDoTheInfrequents(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    bool result = instance->canIDoTheInfrequents();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AITaskSytemBinding::infrequentsStampCheck(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    instance->infrequentsStampCheck();
    return 0;
}

int AITaskSytemBinding::currentActionChecks(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    instance->currentActionChecks();
    return 0;
}

int AITaskSytemBinding::_logTheAI(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    instance->_logTheAI();
    return 0;
}

int AITaskSytemBinding::serialise(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->serialise(data);
    return 0;
}

int AITaskSytemBinding::_NV_serialise(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_NV_serialise(data);
    return 0;
}

int AITaskSytemBinding::loadFromSerialise(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->loadFromSerialise(data);
    return 0;
}

int AITaskSytemBinding::_NV_loadFromSerialise(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_NV_loadFromSerialise(data);
    return 0;
}

int AITaskSytemBinding::getHandle(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    hand result = instance->getHandle();
    return HandBinding::push(L, result);
}

int AITaskSytemBinding::notifyPathImpossible(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    hand* target = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    Ogre::Vector3 dest;
    if (!readVector3(L, 3, dest)) return luaL_argerror(L, 3, "Vector3 table expected");
    instance->notifyPathImpossible(*target, dest);
    return 0;
}

int AITaskSytemBinding::isPathImpossible(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    hand* target = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool result = instance->isPathImpossible(*target);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AITaskSytemBinding::update(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    Ogre::Vector3 position;
    if (!readVector3(L, 2, position)) return luaL_argerror(L, 2, "Vector3 table expected");
    float time = (float)luaL_checknumber(L, 3);
    instance->update(position, time);
    return 0;
}

int AITaskSytemBinding::update4Frame(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    Ogre::Vector3 position;
    if (!readVector3(L, 2, position)) return luaL_argerror(L, 2, "Vector3 table expected");
    float time = (float)luaL_checknumber(L, 3);
    instance->update4Frame(position, time);
    return 0;
}

int AITaskSytemBinding::periodicUpdate(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->periodicUpdate(time);
    return 0;
}

int AITaskSytemBinding::taskImpossible(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    instance->taskImpossible();
    return 0;
}

int AITaskSytemBinding::_notifyBodyTaskComplete(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    instance->_notifyBodyTaskComplete();
    return 0;
}

int AITaskSytemBinding::_forcedSetCurrentAction(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    Tasker* t = checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    float score = (float)luaL_checknumber(L, 3);
    instance->_forcedSetCurrentAction(t, score);
    return 0;
}

int AITaskSytemBinding::setTaskExpiryTimer(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    instance->setTaskExpiryTimer();
    return 0;
}

int AITaskSytemBinding::isGoalExpired(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    bool result = instance->isGoalExpired();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AITaskSytemBinding::isTaskExpired(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    bool result = instance->isTaskExpired();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AITaskSytemBinding::getGOalExpiryTimeRemaining(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    float result = instance->getGOalExpiryTimeRemaining();
    lua_pushnumber(L, result);
    return 1;
}

int AITaskSytemBinding::tryAndRerunGOAP(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    Tasker* theRerun = checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    bool result = instance->tryAndRerunGOAP(theRerun);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

// setCurrentGoal reads t's TaskData without a null check.
int AITaskSytemBinding::setCurrentGoal(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    Tasker* t = checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    float score = (float)luaL_checknumber(L, 3);
    taskPriority pri = (taskPriority)luaL_checkinteger(L, 4);
    instance->setCurrentGoal(t, score, pri);
    return 0;
}

int AITaskSytemBinding::_NV_setCurrentGoal(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    Tasker* t = checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    float score = (float)luaL_checknumber(L, 3);
    taskPriority pri = (taskPriority)luaL_checkinteger(L, 4);
    instance->_NV_setCurrentGoal(t, score, pri);
    return 0;
}

int AITaskSytemBinding::callForUpdate(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    bool superUrgent = lua_toboolean(L, 2) != 0;
    instance->callForUpdate(superUrgent);
    return 0;
}

int AITaskSytemBinding::getGUIData(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    instance->getGUIData(datapanel);
    return 0;
}

int AITaskSytemBinding::getCurrentGoalString(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    std::string result = instance->getCurrentGoalString();
    lua_pushlstring(L, result.c_str(), result.size());
    return 1;
}

int AITaskSytemBinding::intendsToAttackTarget(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->intendsToAttackTarget(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AITaskSytemBinding::updateStateBroadcast(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    StateBroadcastData* stateBroadcast = checkObject<StateBroadcastData>(L, 2, StateBroadcastDataBinding::getMetatableName());
    instance->updateStateBroadcast(stateBroadcast);
    return 0;
}

int AITaskSytemBinding::clearAllTasks(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    instance->clearAllTasks();
    return 0;
}

int AITaskSytemBinding::debugTargetInfo(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    const char* task = luaL_checkstring(L, 2);
    hand* target = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    std::string info = luaL_checkstring(L, 4);
    bool isChosenTarget = lua_toboolean(L, 5) != 0;
    instance->debugTargetInfo(task, *target, info, isChosenTarget);
    return 0;
}

int AITaskSytemBinding::setNeedGOAP(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    instance->setNeedGOAP();
    return 0;
}

int AITaskSytemBinding::_NV_setNeedGOAP(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    instance->_NV_setNeedGOAP();
    return 0;
}

int AITaskSytemBinding::setDialogueDeliveryTag(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    EventTriggerEnum d = (EventTriggerEnum)luaL_checkinteger(L, 2);
    instance->setDialogueDeliveryTag(d);
    return 0;
}

int AITaskSytemBinding::getCurrentDurationTimedTask(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    Tasker* result = instance->getCurrentDurationTimedTask();
    return pushObject<Tasker>(L, result, TaskerBinding::getMetatableName());
}

int AITaskSytemBinding::_taskImpossible(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    instance->_taskImpossible();
    return 0;
}

int AITaskSytemBinding::isThePlayer(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    bool result = instance->isThePlayer();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AITaskSytemBinding::checkOrders(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    bool result = instance->checkOrders();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AITaskSytemBinding::chooseGoal(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    bool timedLockOnCurrentGoal = lua_toboolean(L, 2) != 0;
    instance->chooseGoal(timedLockOnCurrentGoal);
    return 0;
}

int AITaskSytemBinding::_chooseGoal(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    taskPriority priority = (taskPriority)luaL_checkinteger(L, 2);
    SquadMemberType squadMemberType = (SquadMemberType)luaL_checkinteger(L, 3);
    bool result = instance->_chooseGoal(priority, squadMemberType);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AITaskSytemBinding::setupParametersForCurrentGoal(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    instance->setupParametersForCurrentGoal();
    return 0;
}

int AITaskSytemBinding::clearRequestsList(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    instance->clearRequestsList();
    return 0;
}

int AITaskSytemBinding::bodyTaskComplete(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    instance->bodyTaskComplete();
    return 0;
}

int AITaskSytemBinding::popFromOrders(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    Tasker* what = checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    instance->popFromOrders(what);
    return 0;
}

int AITaskSytemBinding::setCurrentTask(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    AITaskSytem::ActionsListMgr* from = checkObject<AITaskSytem::ActionsListMgr>(L, 2, AITaskSytem_ActionsListMgrBinding::getMetatableName());
    bool result = instance->setCurrentTask(from);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AITaskSytemBinding::runGOAP(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    Tasker* task = checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    bool _a2 = lua_toboolean(L, 3) != 0;
    bool playerOrder = lua_toboolean(L, 4) != 0;
    float result = instance->runGOAP(task, _a2, playerOrder);
    lua_pushnumber(L, result);
    return 1;
}

int AITaskSytemBinding::chooseGoalFrom(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    OrderedGoalsMapBinding::MapType* orderedGoals = OrderedGoalsMapBinding::getInstance(L, 2);
    TaskMatch* alreadyHasGoal = checkObject<TaskMatch>(L, 3, TaskMatchBinding::getMetatableName());
    lektor<Tasker*>* goalListIn = TaskerLektorBinding::getInstance(L, 4);
    if (!orderedGoals) return luaL_error(L, "orderedGoals is nil");
    if (!alreadyHasGoal) return luaL_error(L, "alreadyHasGoal is nil");
    if (!goalListIn) return luaL_error(L, "goalListIn is nil");
    bool theseAreBlackboard = lua_toboolean(L, 5) != 0;
    instance->chooseGoalFrom(*orderedGoals, *alreadyHasGoal, *goalListIn, theseAreBlackboard);
    return 0;
}

int AITaskSytemBinding::choosePermaJob(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    OrderedGoalsMapBinding::MapType* orderedGoals = OrderedGoalsMapBinding::getInstance(L, 2);
    TaskMatch* alreadyHasGoal = checkObject<TaskMatch>(L, 3, TaskMatchBinding::getMetatableName());
    if (!orderedGoals) return luaL_error(L, "orderedGoals is nil");
    if (!alreadyHasGoal) return luaL_error(L, "alreadyHasGoal is nil");
    bool urgentOnes = lua_toboolean(L, 4) != 0;
    bool jobsEnabled = lua_toboolean(L, 5) != 0;
    instance->choosePermaJob(*orderedGoals, *alreadyHasGoal, urgentOnes, jobsEnabled);
    return 0;
}

int AITaskSytemBinding::runGoals(lua_State* L)
{
    AITaskSytem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AITaskSytem is nil");

    OrderedGoalsMapBinding::MapType* orderedGoals = OrderedGoalsMapBinding::getInstance(L, 2);
    if (!orderedGoals) return luaL_error(L, "orderedGoals is nil");
    bool playerOrder = lua_toboolean(L, 3) != 0;
    bool result = instance->runGoals(*orderedGoals, playerOrder);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 221-224: AITaskSytem(AI*, CharBody*, Character*), _CONSTRUCTOR, ~AITaskSytem, _DESTRUCTOR - owned by AI (AI::taskSystemAI, deleted by ~AI)

Read-only properties:
  pathFailures, requestsList - containers are edited in place; whole-container assignment is not bound
  actions, actionsTryList - ~AITaskSytem deletes their tasks, so replacing a list would free them twice
*/

int AITaskSytemBinding::gc(lua_State* L)
{
    // Borrowed from the owning AI
    return 0;
}

int AITaskSytemBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AITaskSytem object");
    return 1;
}

void AITaskSytemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AITaskSytemBinding::gc },
        { "__tostring", AITaskSytemBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "canIDoTheInfrequents", AITaskSytemBinding::canIDoTheInfrequents },
        { "infrequentsStampCheck", AITaskSytemBinding::infrequentsStampCheck },
        { "currentActionChecks", AITaskSytemBinding::currentActionChecks },
        { "_logTheAI", AITaskSytemBinding::_logTheAI },
        { "serialise", AITaskSytemBinding::serialise },
        { "_NV_serialise", AITaskSytemBinding::_NV_serialise },
        { "loadFromSerialise", AITaskSytemBinding::loadFromSerialise },
        { "_NV_loadFromSerialise", AITaskSytemBinding::_NV_loadFromSerialise },
        { "getHandle", AITaskSytemBinding::getHandle },
        { "notifyPathImpossible", AITaskSytemBinding::notifyPathImpossible },
        { "isPathImpossible", AITaskSytemBinding::isPathImpossible },
        { "update", AITaskSytemBinding::update },
        { "update4Frame", AITaskSytemBinding::update4Frame },
        { "periodicUpdate", AITaskSytemBinding::periodicUpdate },
        { "taskImpossible", AITaskSytemBinding::taskImpossible },
        { "_notifyBodyTaskComplete", AITaskSytemBinding::_notifyBodyTaskComplete },
        { "_forcedSetCurrentAction", AITaskSytemBinding::_forcedSetCurrentAction },
        { "setTaskExpiryTimer", AITaskSytemBinding::setTaskExpiryTimer },
        { "isGoalExpired", AITaskSytemBinding::isGoalExpired },
        { "isTaskExpired", AITaskSytemBinding::isTaskExpired },
        { "getGOalExpiryTimeRemaining", AITaskSytemBinding::getGOalExpiryTimeRemaining },
        { "tryAndRerunGOAP", AITaskSytemBinding::tryAndRerunGOAP },
        { "setCurrentGoal", AITaskSytemBinding::setCurrentGoal },
        { "_NV_setCurrentGoal", AITaskSytemBinding::_NV_setCurrentGoal },
        { "callForUpdate", AITaskSytemBinding::callForUpdate },
        { "getGUIData", AITaskSytemBinding::getGUIData },
        { "getCurrentGoalString", AITaskSytemBinding::getCurrentGoalString },
        { "intendsToAttackTarget", AITaskSytemBinding::intendsToAttackTarget },
        { "updateStateBroadcast", AITaskSytemBinding::updateStateBroadcast },
        { "clearAllTasks", AITaskSytemBinding::clearAllTasks },
        { "debugTargetInfo", AITaskSytemBinding::debugTargetInfo },
        { "setNeedGOAP", AITaskSytemBinding::setNeedGOAP },
        { "_NV_setNeedGOAP", AITaskSytemBinding::_NV_setNeedGOAP },
        { "setDialogueDeliveryTag", AITaskSytemBinding::setDialogueDeliveryTag },
        { "getCurrentDurationTimedTask", AITaskSytemBinding::getCurrentDurationTimedTask },
        { "_taskImpossible", AITaskSytemBinding::_taskImpossible },
        { "isThePlayer", AITaskSytemBinding::isThePlayer },
        { "checkOrders", AITaskSytemBinding::checkOrders },
        { "chooseGoal", AITaskSytemBinding::chooseGoal },
        { "_chooseGoal", AITaskSytemBinding::_chooseGoal },
        { "chooseGoalFrom", AITaskSytemBinding::chooseGoalFrom },
        { "choosePermaJob", AITaskSytemBinding::choosePermaJob },
        { "setupParametersForCurrentGoal", AITaskSytemBinding::setupParametersForCurrentGoal },
        { "runGoals", AITaskSytemBinding::runGoals },
        { "clearRequestsList", AITaskSytemBinding::clearRequestsList },
        { "bodyTaskComplete", AITaskSytemBinding::bodyTaskComplete },
        { "popFromOrders", AITaskSytemBinding::popFromOrders },
        { "setCurrentTask", AITaskSytemBinding::setCurrentTask },
        { "runGOAP", AITaskSytemBinding::runGOAP },
        { 0, 0 }
    };

    registerClass(
        L,
        AITaskSytemBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AITaskSytemBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "infrequentTimeStamp", AITaskSytem_get_infrequentTimeStamp);
    registerGetter(L, "pathFailures", AITaskSytem_get_pathFailures);
    registerGetter(L, "_debugBreak", AITaskSytem_get__debugBreak);
    registerGetter(L, "_squadMemberType", AITaskSytem_get__squadMemberType);
    registerGetter(L, "debugCount", AITaskSytem_get_debugCount);
    registerGetter(L, "currentDialogueDelivery", AITaskSytem_get_currentDialogueDelivery);
    registerGetter(L, "_currentDialogueEnumQuery", AITaskSytem_get__currentDialogueEnumQuery);
    registerGetter(L, "_taskCompletedFlag", AITaskSytem_get__taskCompletedFlag);
    registerGetter(L, "_taskImpossibleFlag", AITaskSytem_get__taskImpossibleFlag);
    registerGetter(L, "body", AITaskSytem_get_body);
    registerGetter(L, "character", AITaskSytem_get_character);
    registerGetter(L, "currentGoalExpiryTime", AITaskSytem_get_currentGoalExpiryTime);
    registerGetter(L, "currentTaskExpiryTime", AITaskSytem_get_currentTaskExpiryTime);
    registerGetter(L, "autoSleepTask", AITaskSytem_get_autoSleepTask);
    registerGetter(L, "autoGetupTask", AITaskSytem_get_autoGetupTask);
    registerGetter(L, "autoDitchTask", AITaskSytem_get_autoDitchTask);
    registerGetter(L, "autoSitTask", AITaskSytem_get_autoSitTask);
    registerGetter(L, "autoEjectEnemiesTask1", AITaskSytem_get_autoEjectEnemiesTask1);
    registerGetter(L, "autoEjectEnemiesTask2", AITaskSytem_get_autoEjectEnemiesTask2);
    registerGetter(L, "orderedGoals", AITaskSytem_get_orderedGoals);
    registerGetter(L, "requestsList", AITaskSytem_get_requestsList);
    registerGetter(L, "actions", AITaskSytem_get_actions);
    registerGetter(L, "actionsTryList", AITaskSytem_get_actionsTryList);
    registerGetter(L, "failedGOAPGoalDebugString", AITaskSytem_get_failedGOAPGoalDebugString);
    registerGetter(L, "pos", AITaskSytem_get_pos);
    registerGetter(L, "currentlySubTasking", AITaskSytem_get_currentlySubTasking);
    registerGetter(L, "setTaskRecursionCounter", AITaskSytem_get_setTaskRecursionCounter);
    registerGetter(L, "taskRecursionLast", AITaskSytem_get_taskRecursionLast);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "infrequentTimeStamp", AITaskSytem_set_infrequentTimeStamp);
    registerSetter(L, "_debugBreak", AITaskSytem_set__debugBreak);
    registerSetter(L, "_squadMemberType", AITaskSytem_set__squadMemberType);
    registerSetter(L, "debugCount", AITaskSytem_set_debugCount);
    registerSetter(L, "currentDialogueDelivery", AITaskSytem_set_currentDialogueDelivery);
    registerSetter(L, "_currentDialogueEnumQuery", AITaskSytem_set__currentDialogueEnumQuery);
    registerSetter(L, "_taskCompletedFlag", AITaskSytem_set__taskCompletedFlag);
    registerSetter(L, "_taskImpossibleFlag", AITaskSytem_set__taskImpossibleFlag);
    registerSetter(L, "body", AITaskSytem_set_body);
    registerSetter(L, "character", AITaskSytem_set_character);
    registerSetter(L, "currentGoalExpiryTime", AITaskSytem_set_currentGoalExpiryTime);
    registerSetter(L, "currentTaskExpiryTime", AITaskSytem_set_currentTaskExpiryTime);
    registerSetter(L, "autoSleepTask", AITaskSytem_set_autoSleepTask);
    registerSetter(L, "autoGetupTask", AITaskSytem_set_autoGetupTask);
    registerSetter(L, "autoDitchTask", AITaskSytem_set_autoDitchTask);
    registerSetter(L, "autoSitTask", AITaskSytem_set_autoSitTask);
    registerSetter(L, "autoEjectEnemiesTask1", AITaskSytem_set_autoEjectEnemiesTask1);
    registerSetter(L, "autoEjectEnemiesTask2", AITaskSytem_set_autoEjectEnemiesTask2);
    registerSetter(L, "orderedGoals", AITaskSytem_set_orderedGoals);
    registerSetter(L, "failedGOAPGoalDebugString", AITaskSytem_set_failedGOAPGoalDebugString);
    registerSetter(L, "pos", AITaskSytem_set_pos);
    registerSetter(L, "currentlySubTasking", AITaskSytem_set_currentlySubTasking);
    registerSetter(L, "setTaskRecursionCounter", AITaskSytem_set_setTaskRecursionCounter);
    registerSetter(L, "taskRecursionLast", AITaskSytem_set_taskRecursionLast);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
