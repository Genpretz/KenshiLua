#include "pch.h"
#include "kenshi\Tasker.h"
#include "TaskStateDataBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static TaskStateData* getInstance(lua_State* L, int idx)
{
    return checkObject<TaskStateData>(L, idx, TaskStateDataBinding::getMetatableName());
}

// --- Getters for TaskStateData ---
static int TaskStateData_get_val(lua_State* L)
{
    TaskStateData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskStateData is nil");
    lua_pushboolean(L, instance->val ? 1 : 0);
    return 1;
}

static int TaskStateData_get_progressionOnly(lua_State* L)
{
    TaskStateData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskStateData is nil");
    lua_pushboolean(L, instance->progressionOnly ? 1 : 0);
    return 1;
}

// --- Setters for TaskStateData ---
static int TaskStateData_set_val(lua_State* L)
{
    TaskStateData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskStateData is nil");
    instance->val = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TaskStateData_set_progressionOnly(lua_State* L)
{
    TaskStateData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskStateData is nil");
    instance->progressionOnly = lua_toboolean(L, 2) != 0;
    return 0;
}

/*
Skipped methods needing manual binding:
  line 201: TaskStateData* _CONSTRUCTOR(...) - overloaded method
  line 203: TaskStateData* _CONSTRUCTOR(...) - overloaded method
*/

/*
Skipped properties needing manual binding:
  line 205: key (StateType) - unsupported type
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



static int TaskStateData_get_key(lua_State* L)
{
    TaskStateData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskStateData is nil");
    // TODO: Unsupported type for key (StateType)
    return luaL_error(L, "Unsupported property 'key' (type: StateType)");
}


static int TaskStateData_set_key(lua_State* L)
{
    TaskStateData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TaskStateData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for key");
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
    registerGetter(L, "val", TaskStateData_get_val);
    registerGetter(L, "progressionOnly", TaskStateData_get_progressionOnly);
        registerGetter(L, "key", TaskStateData_get_key);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "val", TaskStateData_set_val);
    registerSetter(L, "progressionOnly", TaskStateData_set_progressionOnly);
        registerSetter(L, "key", TaskStateData_set_key);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua