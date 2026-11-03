#include "pch.h"
#include "kenshi/Dialogue.h"
#include "DialogConditionBinding.h"
#include "Lua/BindingHelpers.h"

typedef DialogLineData::DialogCondition DialogCondition;

namespace KenshiLua
{

static DialogCondition* getInstance(lua_State* L, int idx)
{
    return checkObject<DialogCondition>(L, idx, DialogConditionBinding::getMetatableName());
}

// --- Getters for DialogCondition ---
static int DialogCondition_get_key(lua_State* L)
{
    DialogCondition* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogCondition is nil");
    lua_pushinteger(L, (lua_Integer)instance->key);
    return 1;
}

static int DialogCondition_get_compareBy(lua_State* L)
{
    DialogCondition* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogCondition is nil");
    lua_pushinteger(L, (lua_Integer)instance->compareBy);
    return 1;
}

static int DialogCondition_get_who(lua_State* L)
{
    DialogCondition* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogCondition is nil");
    lua_pushinteger(L, (lua_Integer)instance->who);
    return 1;
}

static int DialogCondition_get_value(lua_State* L)
{
    DialogCondition* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogCondition is nil");
    lua_pushinteger(L, instance->value);
    return 1;
}

// --- Setters for DialogCondition ---
static int DialogCondition_set_key(lua_State* L)
{
    DialogCondition* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogCondition is nil");
    instance->key = (DialogConditionEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogCondition_set_compareBy(lua_State* L)
{
    DialogCondition* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogCondition is nil");
    instance->compareBy = (ComparisonEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogCondition_set_who(lua_State* L)
{
    DialogCondition* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogCondition is nil");
    instance->who = (TalkerEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogCondition_set_value(lua_State* L)
{
    DialogCondition* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogCondition is nil");
    instance->value = (int)luaL_checkinteger(L, 2);
    return 0;
}



int DialogConditionBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DialogConditionBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DialogCondition object");
    return 1;
}

void DialogConditionBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DialogConditionBinding::gc },
        { "__tostring", DialogConditionBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        DialogConditionBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DialogConditionBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "key", DialogCondition_get_key);
    registerGetter(L, "compareBy", DialogCondition_get_compareBy);
    registerGetter(L, "who", DialogCondition_get_who);
    registerGetter(L, "value", DialogCondition_get_value);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "key", DialogCondition_set_key);
    registerSetter(L, "compareBy", DialogCondition_set_compareBy);
    registerSetter(L, "who", DialogCondition_set_who);
    registerSetter(L, "value", DialogCondition_set_value);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua