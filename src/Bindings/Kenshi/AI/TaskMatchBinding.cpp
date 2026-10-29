#include "pch.h"
#include "kenshi/Tasker.h"
#include "TaskMatchBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/TaskDataBinding.h"
#include "Bindings/Kenshi/TaskerBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"

namespace KenshiLua
{

// Lua owns every TaskMatch it holds; copies are made with the exported copy constructor.
static_assert(sizeof(TaskMatch) == 0x48, "TaskMatch size does not match the game");
static_assert(offsetof(TaskMatch, subtarget) == 0x28, "TaskMatch::subtarget offset does not match the game");

static TaskMatch* getInstance(lua_State* L, int idx)
{
    return checkObject<TaskMatch>(L, idx, TaskMatchBinding::getMetatableName());
}

// operator==, operator!=, sameAs, and operator=(Tasker*) accept a null Tasker.
static Tasker* optTasker(lua_State* L, int idx)
{
    return lua_isnoneornil(L, idx) ? nullptr : checkObject<Tasker>(L, idx, TaskerBinding::getMetatableName());
}

// --- Getters for TaskMatch ---
static int TaskMatch_get_taskData(lua_State* L)
{
    TaskMatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskMatch is nil");
    return pushObject<TaskData>(L, const_cast<TaskData*>(instance->taskData), TaskDataBinding::getMetatableName());
}

static int TaskMatch_get_subject(lua_State* L)
{
    TaskMatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskMatch is nil");
    return HandBinding::push(L, instance->subject);
}

static int TaskMatch_get_subtarget(lua_State* L)
{
    TaskMatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskMatch is nil");
    return HandBinding::push(L, instance->subtarget);
}

// --- Setters for TaskMatch ---
// The default constructor and operator=(int) leave taskData null, and key() checks for it.
static int TaskMatch_set_taskData(lua_State* L)
{
    TaskMatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskMatch is nil");
    instance->taskData = lua_isnoneornil(L, 2) ? nullptr : checkObject<TaskData>(L, 2, TaskDataBinding::getMetatableName());
    return 0;
}

static int TaskMatch_set_subject(lua_State* L)
{
    TaskMatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskMatch is nil");
    instance->subject = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int TaskMatch_set_subtarget(lua_State* L)
{
    TaskMatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskMatch is nil");
    instance->subtarget = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

// TaskMatch(), TaskMatch(const TaskMatch&), TaskMatch(Tasker*), TaskMatch(const TaskData*, const hand&, const hand&)
int TaskMatchBinding::constructor(lua_State* L)
{
    int startIdx = lua_istable(L, 1) ? 2 : 1; // Called through the TaskMatch table's __call
    int numArgs = lua_gettop(L) - startIdx + 1;

    if (numArgs <= 0)
    {
        TaskMatch value;
        return pushValue<TaskMatch>(L, value, TaskMatchBinding::getMetatableName());
    }
    if (numArgs == 1)
    {
        TaskMatch* other = testObject<TaskMatch>(L, startIdx, TaskMatchBinding::getMetatableName());
        if (other)
            return pushValue<TaskMatch>(L, *other, TaskMatchBinding::getMetatableName());
        Tasker* k = checkObject<Tasker>(L, startIdx, TaskerBinding::getMetatableName());
        TaskMatch value(k);
        return pushValue<TaskMatch>(L, value, TaskMatchBinding::getMetatableName());
    }

    const TaskData* k = lua_isnoneornil(L, startIdx) ? nullptr : checkObject<TaskData>(L, startIdx, TaskDataBinding::getMetatableName());
    hand* s = checkObject<hand>(L, startIdx + 1, HandBinding::getMetatableName());
    hand* sub = checkObject<hand>(L, startIdx + 2, HandBinding::getMetatableName());
    TaskMatch value(k, *s, *sub);
    return pushValue<TaskMatch>(L, value, TaskMatchBinding::getMetatableName());
}

int TaskMatchBinding::getTaskData(lua_State* L)
{
    TaskMatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskMatch is nil");

    const TaskData* result = instance->getTaskData();
    return pushObject<TaskData>(L, const_cast<TaskData*>(result), TaskDataBinding::getMetatableName());
}

int TaskMatchBinding::key(lua_State* L)
{
    TaskMatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskMatch is nil");

    TaskType result = instance->key();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

// operator=(Tasker*) and operator=(int); both return self.
int TaskMatchBinding::operator_assign(lua_State* L)
{
    TaskMatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskMatch is nil");

    if (lua_type(L, 2) == LUA_TNUMBER)
    {
        *instance = (int)luaL_checkinteger(L, 2);
    }
    else
    {
        *instance = optTasker(L, 2);
    }
    lua_settop(L, 1);
    return 1;
}

int TaskMatchBinding::reset(lua_State* L)
{
    TaskMatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskMatch is nil");

    instance->reset();
    return 0;
}

int TaskMatchBinding::operator_eq(lua_State* L)
{
    TaskMatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskMatch is nil");

    const Tasker* a = optTasker(L, 2);
    bool result = *instance == a;
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskMatchBinding::operator_ne(lua_State* L)
{
    TaskMatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskMatch is nil");

    const Tasker* a = optTasker(L, 2);
    bool result = *instance != a;
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskMatchBinding::sameAs(lua_State* L)
{
    TaskMatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskMatch is nil");

    const Tasker* t = optTasker(L, 2);
    bool result = instance->sameAs(t);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskMatchBinding::operator_lt(lua_State* L)
{
    TaskMatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskMatch is nil");

    TaskMatch* t = getInstance(L, 2);
    bool result = *instance < *t;
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TaskMatchBinding::operator_bool(lua_State* L)
{
    TaskMatch* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskMatch is nil");

    bool result = instance->operator bool();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 34-41: _CONSTRUCTOR(...) - exposed through the TaskMatch(...) constructor instead
*/

int TaskMatchBinding::gc(lua_State* L)
{
    // Lua-created values use the owned metatable's __gc
    return 0;
}

int TaskMatchBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TaskMatch object");
    return 1;
}

void TaskMatchBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TaskMatchBinding::gc },
        { "__tostring", TaskMatchBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getTaskData", TaskMatchBinding::getTaskData },
        { "key", TaskMatchBinding::key },
        { "operator_assign", TaskMatchBinding::operator_assign },
        { "reset", TaskMatchBinding::reset },
        { "operator_eq", TaskMatchBinding::operator_eq },
        { "operator_ne", TaskMatchBinding::operator_ne },
        { "sameAs", TaskMatchBinding::sameAs },
        { "operator_lt", TaskMatchBinding::operator_lt },
        { "operator_bool", TaskMatchBinding::operator_bool },
        { 0, 0 }
    };

    registerClass(
        L,
        TaskMatchBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TaskMatchBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "taskData", TaskMatch_get_taskData);
    registerGetter(L, "subject", TaskMatch_get_subject);
    registerGetter(L, "subtarget", TaskMatch_get_subtarget);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "taskData", TaskMatch_set_taskData);
    registerSetter(L, "subject", TaskMatch_set_subject);
    registerSetter(L, "subtarget", TaskMatch_set_subtarget);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack

    pushGlobalTable(L, "TaskMatch");
    registerConstructor(L, TaskMatchBinding::constructor);
    lua_setglobal(L, "TaskMatch");
}

} // namespace KenshiLua
