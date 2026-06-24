#include "pch.h"
#include "kenshi\Tasker.h"
#include "TaskStateDataBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static TaskStateData* getB(lua_State* L, int idx)
{
    return checkObject<TaskStateData>(L, idx, TaskStateDataBinding::getMetatableName());
}

// --- Getters for TaskStateData ---
static int TaskStateData_get_key(lua_State* L)
{
    TaskStateData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskStateData is nil");
    // TODO: Unsupported type for key (StateType)
    lua_pushnil(L);
    return 1;
}

static int TaskStateData_get_val(lua_State* L)
{
    TaskStateData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskStateData is nil");
    lua_pushboolean(L, b->val ? 1 : 0);
    return 1;
}

static int TaskStateData_get_progressionOnly(lua_State* L)
{
    TaskStateData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskStateData is nil");
    lua_pushboolean(L, b->progressionOnly ? 1 : 0);
    return 1;
}

// --- Setters for TaskStateData ---
static int TaskStateData_set_key(lua_State* L)
{
    TaskStateData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskStateData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for key");
}

static int TaskStateData_set_val(lua_State* L)
{
    TaskStateData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskStateData is nil");
    b->val = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskStateData_set_progressionOnly(lua_State* L)
{
    TaskStateData* b = getB(L, 1);
    if (!b) return luaL_error(L, "TaskStateData is nil");
    b->progressionOnly = lua_toboolean(L, 2) != 0;
    return 0;
}

/*
Skipped methods needing manual binding:
  line 201: TaskStateData* _CONSTRUCTOR(...) - overloaded method
  line 203: TaskStateData* _CONSTRUCTOR(...) - overloaded method
*/

int TaskStateDataBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TaskStateDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TaskStateData object");
    return 1;
}

void TaskStateDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TaskStateDataBinding::gc },
        { "__tostring", TaskStateDataBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        TaskStateDataBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TaskStateDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, TaskStateData_get_key);
    lua_setfield(L, -2, "key");
    lua_pushcfunction(L, TaskStateData_get_val);
    lua_setfield(L, -2, "val");
    lua_pushcfunction(L, TaskStateData_get_progressionOnly);
    lua_setfield(L, -2, "progressionOnly");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, TaskStateData_set_key);
    lua_setfield(L, -2, "key");
    lua_pushcfunction(L, TaskStateData_set_val);
    lua_setfield(L, -2, "val");
    lua_pushcfunction(L, TaskStateData_set_progressionOnly);
    lua_setfield(L, -2, "progressionOnly");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua