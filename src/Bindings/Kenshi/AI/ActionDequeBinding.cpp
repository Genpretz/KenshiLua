#include "pch.h"
#include "kenshi/Tasker.h"
#include "kenshi/AI/AITaskSystem.h"
#include "ActionDequeBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/AI/TaskMatchBinding.h"
#include "Bindings/Kenshi/TaskerBinding.h"
#include "Bindings/Kenshi/Util/StdDequeBinding.h"

namespace KenshiLua
{

// OrdersReceiver and AITaskSytem embed these; the size places their later members.
static_assert(sizeof(ActionDeque) == 0x38, "ActionDeque size does not match the game");
static_assert(offsetof(ActionDeque, list) == 0x8, "ActionDeque::list offset does not match the game");

typedef StdDequePtrBinding<Tasker*> TaskerDequeBinding;

static ActionDeque* getInstance(lua_State* L, int idx)
{
    return checkObject<ActionDeque>(L, idx, ActionDequeBinding::getMetatableName());
}

// --- Getters for ActionDeque ---
static int ActionDeque_get_list(lua_State* L)
{
    ActionDeque* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActionDeque is nil");
    return pushObject<TaskerDequeBinding::DequeType>(L, &instance->list, TaskerDequeBinding::getMetatableName());
}

int ActionDequeBinding::getFirstTask(lua_State* L)
{
    ActionDeque* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActionDeque is nil");

    Tasker* result = instance->getFirstTask();
    return pushObject<Tasker>(L, result, TaskerBinding::getMetatableName());
}

int ActionDequeBinding::getSecondTask(lua_State* L)
{
    ActionDeque* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActionDeque is nil");

    Tasker* result = instance->getSecondTask();
    return pushObject<Tasker>(L, result, TaskerBinding::getMetatableName());
}

int ActionDequeBinding::getLastTask(lua_State* L)
{
    ActionDeque* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActionDeque is nil");

    Tasker* result = instance->getLastTask();
    return pushObject<Tasker>(L, result, TaskerBinding::getMetatableName());
}

int ActionDequeBinding::hasTask(lua_State* L)
{
    ActionDeque* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActionDeque is nil");

    TaskMatch* t = checkObject<TaskMatch>(L, 2, TaskMatchBinding::getMetatableName());
    bool result = instance->hasTask(*t);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

// The deque takes ownership: clearAndDelete and the owner's destructor delete its tasks.
int ActionDequeBinding::insertTask(lua_State* L)
{
    ActionDeque* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActionDeque is nil");

    Tasker* task = checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    instance->insertTask(task);
    return 0;
}

int ActionDequeBinding::addTask(lua_State* L)
{
    ActionDeque* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActionDeque is nil");

    Tasker* task = checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    instance->addTask(task);
    return 0;
}

int ActionDequeBinding::clearAndDelete(lua_State* L)
{
    ActionDeque* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActionDeque is nil");

    instance->clearAndDelete();
    return 0;
}

int ActionDequeBinding::clearOnly(lua_State* L)
{
    ActionDeque* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActionDeque is nil");

    instance->clearOnly();
    return 0;
}

int ActionDequeBinding::passOnCurrentTask(lua_State* L)
{
    ActionDeque* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActionDeque is nil");

    Tasker* result = instance->passOnCurrentTask();
    return pushObject<Tasker>(L, result, TaskerBinding::getMetatableName());
}

int ActionDequeBinding::isEmpty(lua_State* L)
{
    ActionDeque* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActionDeque is nil");

    lua_pushboolean(L, instance->isEmpty() ? 1 : 0);
    return 1;
}

int ActionDequeBinding::isOnlyOne(lua_State* L)
{
    ActionDeque* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ActionDeque is nil");

    lua_pushboolean(L, instance->isOnlyOne() ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 63-66: ActionDeque(), _CONSTRUCTOR, ~ActionDeque, _DESTRUCTOR - embedded in OrdersReceiver and AITaskSytem
  line 68: const getFirstTask() - same call as the non-const overload bound as getFirstTask

Read-only properties:
  list - the deque is edited in place; clearAndDelete and the owner's destructor delete its tasks, so replacing it would free them twice
*/

int ActionDequeBinding::gc(lua_State* L)
{
    // Borrowed from the owning OrdersReceiver or AITaskSytem
    return 0;
}

int ActionDequeBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ActionDeque object");
    return 1;
}

void ActionDequeBinding::registerBinding(lua_State* L)
{

    static const luaL_Reg meta[] = {
        { "__gc",       ActionDequeBinding::gc },
        { "__tostring", ActionDequeBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getFirstTask", ActionDequeBinding::getFirstTask },
        { "getSecondTask", ActionDequeBinding::getSecondTask },
        { "getLastTask", ActionDequeBinding::getLastTask },
        { "hasTask", ActionDequeBinding::hasTask },
        { "insertTask", ActionDequeBinding::insertTask },
        { "addTask", ActionDequeBinding::addTask },
        { "clearAndDelete", ActionDequeBinding::clearAndDelete },
        { "clearOnly", ActionDequeBinding::clearOnly },
        { "passOnCurrentTask", ActionDequeBinding::passOnCurrentTask },
        { "isEmpty", ActionDequeBinding::isEmpty },
        { "isOnlyOne", ActionDequeBinding::isOnlyOne },
        { 0, 0 }
    };

    registerClass(
        L,
        ActionDequeBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ActionDequeBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "list", ActionDeque_get_list);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
