#include "pch.h"
#include "kenshi/Tasker.h"
#include "kenshi/AI/AITaskSystem.h"
#include "TaskRequestBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/TaskerBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"

namespace KenshiLua
{

// Blackboard's job lektors hold these by value, so element indexing depends on the game's size.
static_assert(sizeof(TaskRequest) == 0x88, "TaskRequest size does not match the game");
static_assert(offsetof(TaskRequest, subject) == 0x48, "TaskRequest::subject offset does not match the game");
static_assert(offsetof(TaskRequest, endEvent) == 0x80, "TaskRequest::endEvent offset does not match the game");

static TaskRequest* getInstance(lua_State* L, int idx)
{
    return checkObject<TaskRequest>(L, idx, TaskRequestBinding::getMetatableName());
}

// --- Getters for TaskRequest ---
static int TaskRequest_get_to(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");
    return HandBinding::push(L, instance->to);
}

static int TaskRequest_get_from(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");
    return HandBinding::push(L, instance->from);
}

static int TaskRequest_get_key(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");
    lua_pushinteger(L, (lua_Integer)instance->key);
    return 1;
}

static int TaskRequest_get_subject(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");
    return HandBinding::push(L, instance->subject);
}

static int TaskRequest_get_priority(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");
    lua_pushinteger(L, (lua_Integer)instance->priority);
    return 1;
}

static int TaskRequest_get_weight(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");
    lua_pushnumber(L, instance->weight);
    return 1;
}

static int TaskRequest_get_timeout(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");
    lua_pushnumber(L, instance->timeout);
    return 1;
}

static int TaskRequest_get_targeting(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");
    lua_pushinteger(L, (lua_Integer)instance->targeting);
    return 1;
}

static int TaskRequest_get_startTime(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");
    lua_pushinteger(L, instance->startTime);
    return 1;
}

static int TaskRequest_get_endTime(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");
    lua_pushinteger(L, instance->endTime);
    return 1;
}

static int TaskRequest_get_endEvent(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");
    lua_pushinteger(L, (lua_Integer)instance->endEvent);
    return 1;
}

// --- Setters for TaskRequest ---
static int TaskRequest_set_to(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");
    instance->to = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int TaskRequest_set_from(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");
    instance->from = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int TaskRequest_set_key(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");
    instance->key = (TaskType)luaL_checkinteger(L, 2);
    return 0;
}

static int TaskRequest_set_subject(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");
    instance->subject = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int TaskRequest_set_priority(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");
    instance->priority = (taskPriority)luaL_checkinteger(L, 2);
    return 0;
}

static int TaskRequest_set_weight(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");
    instance->weight = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TaskRequest_set_timeout(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");
    instance->timeout = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TaskRequest_set_targeting(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");
    instance->targeting = (TaskTargetType)luaL_checkinteger(L, 2);
    return 0;
}

static int TaskRequest_set_startTime(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");
    instance->startTime = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int TaskRequest_set_endTime(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");
    instance->endTime = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int TaskRequest_set_endEvent(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");
    instance->endEvent = (TaskEndEvent)luaL_checkinteger(L, 2);
    return 0;
}

// TaskRequest() or TaskRequest(const TaskRequest&).
int TaskRequestBinding::constructor(lua_State* L)
{
    int startIdx = lua_istable(L, 1) ? 2 : 1; // Called through the TaskRequest table's __call
    int numArgs = lua_gettop(L) - startIdx + 1;

    if (numArgs <= 0)
    {
        TaskRequest value;
        return pushValue<TaskRequest>(L, value, TaskRequestBinding::getMetatableName());
    }
    TaskRequest* other = getInstance(L, startIdx);
    return pushValue<TaskRequest>(L, *other, TaskRequestBinding::getMetatableName());
}

int TaskRequestBinding::sameAs(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");

    Tasker* t = checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    bool result = instance->sameAs(t);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskRequestBinding::operator_eq(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");

    TaskRequest* t = getInstance(L, 2);
    bool result = *instance == *t;
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

// operator=(const TaskRequest&); returns self.
int TaskRequestBinding::operator_assign(lua_State* L)
{
    TaskRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskRequest is nil");

    TaskRequest* other = getInstance(L, 2);
    *instance = *other;
    lua_settop(L, 1);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 199-202: _CONSTRUCTOR(...) - exposed through the TaskRequest(...) constructor instead
*/

int TaskRequestBinding::gc(lua_State* L)
{
    // Lua-created values use the owned metatable's __gc; others are borrowed from their Blackboard container
    return 0;
}

int TaskRequestBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TaskRequest object");
    return 1;
}

void TaskRequestBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TaskRequestBinding::gc },
        { "__tostring", TaskRequestBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "sameAs", TaskRequestBinding::sameAs },
        { "operator_eq", TaskRequestBinding::operator_eq },
        { "operator_assign", TaskRequestBinding::operator_assign },
        { 0, 0 }
    };

    registerClass(
        L,
        TaskRequestBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TaskRequestBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "to", TaskRequest_get_to);
    registerGetter(L, "from", TaskRequest_get_from);
    registerGetter(L, "key", TaskRequest_get_key);
    registerGetter(L, "subject", TaskRequest_get_subject);
    registerGetter(L, "priority", TaskRequest_get_priority);
    registerGetter(L, "weight", TaskRequest_get_weight);
    registerGetter(L, "timeout", TaskRequest_get_timeout);
    registerGetter(L, "targeting", TaskRequest_get_targeting);
    registerGetter(L, "startTime", TaskRequest_get_startTime);
    registerGetter(L, "endTime", TaskRequest_get_endTime);
    registerGetter(L, "endEvent", TaskRequest_get_endEvent);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "to", TaskRequest_set_to);
    registerSetter(L, "from", TaskRequest_set_from);
    registerSetter(L, "key", TaskRequest_set_key);
    registerSetter(L, "subject", TaskRequest_set_subject);
    registerSetter(L, "priority", TaskRequest_set_priority);
    registerSetter(L, "weight", TaskRequest_set_weight);
    registerSetter(L, "timeout", TaskRequest_set_timeout);
    registerSetter(L, "targeting", TaskRequest_set_targeting);
    registerSetter(L, "startTime", TaskRequest_set_startTime);
    registerSetter(L, "endTime", TaskRequest_set_endTime);
    registerSetter(L, "endEvent", TaskRequest_set_endEvent);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack

    pushGlobalTable(L, "TaskRequest");
    registerConstructor(L, TaskRequestBinding::constructor);
    lua_setglobal(L, "TaskRequest");
}

} // namespace KenshiLua
