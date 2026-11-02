#include "pch.h"
#include "kenshi/Tasker.h"
#include "kenshi/AI/AITaskSystem.h"
#include "OrdersReceiverBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/AI/AIBinding.h"
#include "Bindings/Kenshi/AI/ActionDequeBinding.h"
#include "Bindings/Kenshi/AI/OrdersReceiver_TaskRequestSimpleBinding.h"
#include "Bindings/Kenshi/AI/TaskMatchBinding.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/TaskerBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"

namespace KenshiLua
{

// Field accessors index engine-owned receivers; AITaskSytem's members start at 0x210.
static_assert(sizeof(OrdersReceiver) == 0x210, "OrdersReceiver size does not match the game");
static_assert(offsetof(OrdersReceiver, orders) == 0x38, "OrdersReceiver::orders offset does not match the game");
static_assert(offsetof(OrdersReceiver, goals) == 0xA0, "OrdersReceiver::goals offset does not match the game");
static_assert(offsetof(OrdersReceiver, slaveJobs) == 0x198, "OrdersReceiver::slaveJobs offset does not match the game");
static_assert(offsetof(OrdersReceiver, currentGoal) == 0x1C0, "OrdersReceiver::currentGoal offset does not match the game");
static_assert(offsetof(OrdersReceiver, currentGoalPriority) == 0x20C, "OrdersReceiver::currentGoalPriority offset does not match the game");

typedef LektorPtrBinding<Tasker*> TaskerLektorBinding;
typedef LektorPtrBinding<OrdersReceiver::TaskRequestSimple*> TaskRequestSimpleLektorBinding;

static OrdersReceiver* getInstance(lua_State* L, int idx)
{
    return checkObject<OrdersReceiver>(L, idx, OrdersReceiverBinding::getMetatableName());
}

// --- Getters for OrdersReceiver ---
static int OrdersReceiver_get_me(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    return pushObject<Character>(L, instance->me, CharacterBinding::getMetatableName());
}

static int OrdersReceiver_get_mainGoalTarget(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    return HandBinding::push(L, instance->mainGoalTarget);
}

static int OrdersReceiver_get_aggroMode(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    lua_pushinteger(L, (lua_Integer)instance->aggroMode);
    return 1;
}

static int OrdersReceiver_get_superDefenseMode(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    lua_pushboolean(L, instance->superDefenseMode ? 1 : 0);
    return 1;
}

static int OrdersReceiver_get_doJobsEnabled(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    lua_pushboolean(L, instance->doJobsEnabled ? 1 : 0);
    return 1;
}

static int OrdersReceiver_get_orders(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    return pushObject<ActionDeque>(L, &instance->orders, ActionDequeBinding::getMetatableName());
}

static int OrdersReceiver_get_jobs(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    return pushObject<lektor<Tasker*> >(L, &instance->jobs, TaskerLektorBinding::getMetatableName());
}

static int OrdersReceiver_get_permajobs(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    return pushObject<lektor<Tasker*> >(L, &instance->permajobs, TaskerLektorBinding::getMetatableName());
}

static int OrdersReceiver_get_goals(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    const int count = (int)(sizeof(instance->goals) / sizeof(instance->goals[0]));
    lua_createtable(L, count, 0);
    for (int i = 0; i < count; ++i)
    {
        pushObject<lektor<Tasker*> >(L, &instance->goals[i], TaskerLektorBinding::getMetatableName());
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

static int OrdersReceiver_get_squadAIPackage(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    const int count = (int)(sizeof(instance->squadAIPackage) / sizeof(instance->squadAIPackage[0]));
    lua_createtable(L, count, 0);
    for (int i = 0; i < count; ++i)
    {
        pushObject<lektor<Tasker*> >(L, &instance->squadAIPackage[i], TaskerLektorBinding::getMetatableName());
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

static int OrdersReceiver_get_holdPositionOrders(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    return pushObject<Tasker>(L, instance->holdPositionOrders, TaskerBinding::getMetatableName());
}

static int OrdersReceiver_get_slaveJobs(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    return pushObject<lektor<OrdersReceiver::TaskRequestSimple*> >(L, &instance->slaveJobs, TaskRequestSimpleLektorBinding::getMetatableName());
}

static int OrdersReceiver_get_needGOAP(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    lua_pushboolean(L, instance->needGOAP ? 1 : 0);
    return 1;
}

static int OrdersReceiver_get_choosingGoalMode(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    lua_pushboolean(L, instance->choosingGoalMode ? 1 : 0);
    return 1;
}

static int OrdersReceiver_get_aiImplementation(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    return pushObject<AI>(L, instance->aiImplementation, AIBinding::getMetatableName());
}

static int OrdersReceiver_get_currentGoal(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    return pushObject<TaskMatch>(L, &instance->currentGoal, TaskMatchBinding::getMetatableName());
}

static int OrdersReceiver_get_currentGoalScore(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    lua_pushnumber(L, instance->currentGoalScore);
    return 1;
}

static int OrdersReceiver_get_currentGoalPriority(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    lua_pushinteger(L, (lua_Integer)instance->currentGoalPriority);
    return 1;
}

// --- Setters for OrdersReceiver ---
// Owner pointers reject nil.
static int OrdersReceiver_set_me(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    instance->me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int OrdersReceiver_set_mainGoalTarget(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    instance->mainGoalTarget = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int OrdersReceiver_set_aggroMode(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    instance->aggroMode = (OrdersReceiver::AggroType)luaL_checkinteger(L, 2);
    return 0;
}

static int OrdersReceiver_set_superDefenseMode(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    instance->superDefenseMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OrdersReceiver_set_doJobsEnabled(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    instance->doJobsEnabled = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OrdersReceiver_set_needGOAP(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    instance->needGOAP = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OrdersReceiver_set_choosingGoalMode(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    instance->choosingGoalMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OrdersReceiver_set_aiImplementation(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    instance->aiImplementation = checkObject<AI>(L, 2, AIBinding::getMetatableName());
    return 0;
}

static int OrdersReceiver_set_currentGoal(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    instance->currentGoal = *checkObject<TaskMatch>(L, 2, TaskMatchBinding::getMetatableName());
    return 0;
}

static int OrdersReceiver_set_currentGoalScore(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    instance->currentGoalScore = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OrdersReceiver_set_currentGoalPriority(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");
    instance->currentGoalPriority = (taskPriority)luaL_checkinteger(L, 2);
    return 0;
}

int OrdersReceiverBinding::serialise(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->serialise(data);
    return 0;
}

int OrdersReceiverBinding::_NV_serialise(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_NV_serialise(data);
    return 0;
}

int OrdersReceiverBinding::loadFromSerialise(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->loadFromSerialise(data);
    return 0;
}

int OrdersReceiverBinding::_NV_loadFromSerialise(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_NV_loadFromSerialise(data);
    return 0;
}

int OrdersReceiverBinding::_forceOrderInsert(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    TaskType t = (TaskType)luaL_checkinteger(L, 2);
    Tasker* result = instance->_forceOrderInsert(t);
    return pushObject<Tasker>(L, result, TaskerBinding::getMetatableName());
}

int OrdersReceiverBinding::addOrder(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    TaskType t = (TaskType)luaL_checkinteger(L, 2);
    hand* subject = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    Ogre::Vector3 location;
    if (!readVector3(L, 4, location)) return luaL_argerror(L, 4, "Vector3 table expected");
    bool clearOld = lua_toboolean(L, 5) != 0;
    bool shift = lua_toboolean(L, 6) != 0;
    instance->addOrder(t, *subject, location, clearOld, shift);
    return 0;
}

int OrdersReceiverBinding::addJob(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    TaskType t = (TaskType)luaL_checkinteger(L, 2);
    hand* subject = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    Ogre::Vector3 location;
    if (!readVector3(L, 4, location)) return luaL_argerror(L, 4, "Vector3 table expected");
    bool shift = lua_toboolean(L, 5) != 0;
    instance->addJob(t, *subject, location, shift);
    return 0;
}

int OrdersReceiverBinding::removeJob(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    TaskType typ = (TaskType)luaL_checkinteger(L, 2);
    instance->removeJob(typ);
    return 0;
}

int OrdersReceiverBinding::removePermajob(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    int typ = (int)luaL_checkinteger(L, 2);
    instance->removePermajob(typ);
    return 0;
}

int OrdersReceiverBinding::movePermajob(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    int taskIdx = (int)luaL_checkinteger(L, 2);
    int targetIdx = (int)luaL_checkinteger(L, 3);
    instance->movePermajob(taskIdx, targetIdx);
    return 0;
}

int OrdersReceiverBinding::clearPermajobs(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    instance->clearPermajobs();
    return 0;
}

int OrdersReceiverBinding::getPermajobName(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    int slot = (int)luaL_checkinteger(L, 2);
    const std::string& result = instance->getPermajobName(slot);
    lua_pushlstring(L, result.c_str(), result.size());
    return 1;
}

int OrdersReceiverBinding::getPermajob(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    int slot = (int)luaL_checkinteger(L, 2);
    TaskType result = instance->getPermajob(slot);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int OrdersReceiverBinding::getPermajobData(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    int slot = (int)luaL_checkinteger(L, 2);
    const Tasker* result = instance->getPermajobData(slot);
    return pushObject<Tasker>(L, const_cast<Tasker*>(result), TaskerBinding::getMetatableName());
}

int OrdersReceiverBinding::getPermajobCount(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    int result = instance->getPermajobCount();
    lua_pushinteger(L, result);
    return 1;
}

int OrdersReceiverBinding::hasPermajob(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    TaskType t = (TaskType)luaL_checkinteger(L, 2);
    bool result = instance->hasPermajob(t);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int OrdersReceiverBinding::addGoal(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    Tasker* task = checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    instance->addGoal(task);
    return 0;
}

int OrdersReceiverBinding::removeGoal(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    TaskType task = (TaskType)luaL_checkinteger(L, 2);
    instance->removeGoal(task);
    return 0;
}

int OrdersReceiverBinding::hasGoal(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    TaskType task = (TaskType)luaL_checkinteger(L, 2);
    bool result = instance->hasGoal(task);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int OrdersReceiverBinding::updateLastOrder(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    TaskType t = (TaskType)luaL_checkinteger(L, 2);
    hand* subject = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    Ogre::Vector3 location;
    if (!readVector3(L, 4, location)) return luaL_argerror(L, 4, "Vector3 table expected");
    instance->updateLastOrder(t, *subject, location);
    return 0;
}

int OrdersReceiverBinding::setNeedGOAP(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    instance->setNeedGOAP();
    return 0;
}

int OrdersReceiverBinding::_NV_setNeedGOAP(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    instance->_NV_setNeedGOAP();
    return 0;
}

int OrdersReceiverBinding::getFirstOrder(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    Tasker* result = instance->getFirstOrder();
    return pushObject<Tasker>(L, result, TaskerBinding::getMetatableName());
}

int OrdersReceiverBinding::clearOrders(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    instance->clearOrders();
    return 0;
}

int OrdersReceiverBinding::clearJobs(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    instance->clearJobs();
    return 0;
}

int OrdersReceiverBinding::_clearGoals(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    instance->_clearGoals();
    return 0;
}

// Returns the receiver's currentGoal, borrowed.
int OrdersReceiverBinding::getCurrentGoal(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    const TaskMatch& result = instance->getCurrentGoal();
    return pushObject<TaskMatch>(L, const_cast<TaskMatch*>(&result), TaskMatchBinding::getMetatableName());
}

// nil is valid: the engine then installs an idle task.
int OrdersReceiverBinding::setHoldPositionOrders(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    Tasker* t = lua_isnoneornil(L, 2) ? nullptr : checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    instance->setHoldPositionOrders(t);
    return 0;
}

int OrdersReceiverBinding::_NV_setHoldPositionOrders(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    Tasker* t = lua_isnoneornil(L, 2) ? nullptr : checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    instance->_NV_setHoldPositionOrders(t);
    return 0;
}

int OrdersReceiverBinding::hasPlayerOrders(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    bool result = instance->hasPlayerOrders();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int OrdersReceiverBinding::hasPlayerOrder(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    TaskType key = (TaskType)luaL_checkinteger(L, 2);
    bool result = instance->hasPlayerOrder(key);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int OrdersReceiverBinding::isInChoosingGoalMode(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    bool result = instance->isInChoosingGoalMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int OrdersReceiverBinding::hasOrders(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    bool result = instance->hasOrders();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int OrdersReceiverBinding::clearSlaveJobs(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    instance->clearSlaveJobs();
    return 0;
}

int OrdersReceiverBinding::isJobsEnabled(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    bool result = instance->isJobsEnabled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int OrdersReceiverBinding::setJobsEnabled(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setJobsEnabled(on);
    return 0;
}

int OrdersReceiverBinding::clearCurrentGoal(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    bool force = lua_toboolean(L, 2) != 0;
    instance->clearCurrentGoal(force);
    return 0;
}

int OrdersReceiverBinding::tryToGetCurrentGoal(lua_State* L)
{
    OrdersReceiver* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OrdersReceiver is nil");

    Tasker* result = instance->tryToGetCurrentGoal();
    return pushObject<Tasker>(L, result, TaskerBinding::getMetatableName());
}

/*
Skipped methods needing manual binding:
  line 93-96: OrdersReceiver(AI*, Character*), _CONSTRUCTOR, ~OrdersReceiver, _DESTRUCTOR - created as the AI's AITaskSytem and deleted by ~AI
  line 151: getSlaveJobs(lektor<Tasker*>&, TaskRepertoire*, const hand&) - TaskRepertoire is unbound

Read-only properties:
  orders, jobs, permajobs, goals, squadAIPackage, holdPositionOrders - ~OrdersReceiver deletes these tasks, so assigning another list or task would free it twice; use setHoldPositionOrders for the hold task
  slaveJobs - the lektor is edited in place; whole-container assignment is not bound
*/

int OrdersReceiverBinding::gc(lua_State* L)
{
    // Borrowed from the owning AI
    return 0;
}

int OrdersReceiverBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.OrdersReceiver object");
    return 1;
}

void OrdersReceiverBinding::registerBinding(lua_State* L)
{

    static const luaL_Reg meta[] = {
        { "__gc",       OrdersReceiverBinding::gc },
        { "__tostring", OrdersReceiverBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "serialise", OrdersReceiverBinding::serialise },
        { "_NV_serialise", OrdersReceiverBinding::_NV_serialise },
        { "loadFromSerialise", OrdersReceiverBinding::loadFromSerialise },
        { "_NV_loadFromSerialise", OrdersReceiverBinding::_NV_loadFromSerialise },
        { "_forceOrderInsert", OrdersReceiverBinding::_forceOrderInsert },
        { "addOrder", OrdersReceiverBinding::addOrder },
        { "addJob", OrdersReceiverBinding::addJob },
        { "removeJob", OrdersReceiverBinding::removeJob },
        { "removePermajob", OrdersReceiverBinding::removePermajob },
        { "movePermajob", OrdersReceiverBinding::movePermajob },
        { "clearPermajobs", OrdersReceiverBinding::clearPermajobs },
        { "getPermajobName", OrdersReceiverBinding::getPermajobName },
        { "getPermajob", OrdersReceiverBinding::getPermajob },
        { "getPermajobData", OrdersReceiverBinding::getPermajobData },
        { "getPermajobCount", OrdersReceiverBinding::getPermajobCount },
        { "hasPermajob", OrdersReceiverBinding::hasPermajob },
        { "addGoal", OrdersReceiverBinding::addGoal },
        { "removeGoal", OrdersReceiverBinding::removeGoal },
        { "hasGoal", OrdersReceiverBinding::hasGoal },
        { "updateLastOrder", OrdersReceiverBinding::updateLastOrder },
        { "setNeedGOAP", OrdersReceiverBinding::setNeedGOAP },
        { "_NV_setNeedGOAP", OrdersReceiverBinding::_NV_setNeedGOAP },
        { "getFirstOrder", OrdersReceiverBinding::getFirstOrder },
        { "clearOrders", OrdersReceiverBinding::clearOrders },
        { "clearJobs", OrdersReceiverBinding::clearJobs },
        { "_clearGoals", OrdersReceiverBinding::_clearGoals },
        { "getCurrentGoal", OrdersReceiverBinding::getCurrentGoal },
        { "setHoldPositionOrders", OrdersReceiverBinding::setHoldPositionOrders },
        { "_NV_setHoldPositionOrders", OrdersReceiverBinding::_NV_setHoldPositionOrders },
        { "hasPlayerOrders", OrdersReceiverBinding::hasPlayerOrders },
        { "hasPlayerOrder", OrdersReceiverBinding::hasPlayerOrder },
        { "isInChoosingGoalMode", OrdersReceiverBinding::isInChoosingGoalMode },
        { "hasOrders", OrdersReceiverBinding::hasOrders },
        { "clearSlaveJobs", OrdersReceiverBinding::clearSlaveJobs },
        { "isJobsEnabled", OrdersReceiverBinding::isJobsEnabled },
        { "setJobsEnabled", OrdersReceiverBinding::setJobsEnabled },
        { "clearCurrentGoal", OrdersReceiverBinding::clearCurrentGoal },
        { "tryToGetCurrentGoal", OrdersReceiverBinding::tryToGetCurrentGoal },
        { 0, 0 }
    };

    registerClass(
        L,
        OrdersReceiverBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, OrdersReceiverBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "me", OrdersReceiver_get_me);
    registerGetter(L, "mainGoalTarget", OrdersReceiver_get_mainGoalTarget);
    registerGetter(L, "aggroMode", OrdersReceiver_get_aggroMode);
    registerGetter(L, "superDefenseMode", OrdersReceiver_get_superDefenseMode);
    registerGetter(L, "doJobsEnabled", OrdersReceiver_get_doJobsEnabled);
    registerGetter(L, "orders", OrdersReceiver_get_orders);
    registerGetter(L, "jobs", OrdersReceiver_get_jobs);
    registerGetter(L, "permajobs", OrdersReceiver_get_permajobs);
    registerGetter(L, "goals", OrdersReceiver_get_goals);
    registerGetter(L, "squadAIPackage", OrdersReceiver_get_squadAIPackage);
    registerGetter(L, "holdPositionOrders", OrdersReceiver_get_holdPositionOrders);
    registerGetter(L, "slaveJobs", OrdersReceiver_get_slaveJobs);
    registerGetter(L, "needGOAP", OrdersReceiver_get_needGOAP);
    registerGetter(L, "choosingGoalMode", OrdersReceiver_get_choosingGoalMode);
    registerGetter(L, "aiImplementation", OrdersReceiver_get_aiImplementation);
    registerGetter(L, "currentGoal", OrdersReceiver_get_currentGoal);
    registerGetter(L, "currentGoalScore", OrdersReceiver_get_currentGoalScore);
    registerGetter(L, "currentGoalPriority", OrdersReceiver_get_currentGoalPriority);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "me", OrdersReceiver_set_me);
    registerSetter(L, "mainGoalTarget", OrdersReceiver_set_mainGoalTarget);
    registerSetter(L, "aggroMode", OrdersReceiver_set_aggroMode);
    registerSetter(L, "superDefenseMode", OrdersReceiver_set_superDefenseMode);
    registerSetter(L, "doJobsEnabled", OrdersReceiver_set_doJobsEnabled);
    registerSetter(L, "needGOAP", OrdersReceiver_set_needGOAP);
    registerSetter(L, "choosingGoalMode", OrdersReceiver_set_choosingGoalMode);
    registerSetter(L, "aiImplementation", OrdersReceiver_set_aiImplementation);
    registerSetter(L, "currentGoal", OrdersReceiver_set_currentGoal);
    registerSetter(L, "currentGoalScore", OrdersReceiver_set_currentGoalScore);
    registerSetter(L, "currentGoalPriority", OrdersReceiver_set_currentGoalPriority);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
