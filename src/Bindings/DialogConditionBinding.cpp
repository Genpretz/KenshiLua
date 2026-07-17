#include "pch.h"
#include "kenshi\Dialogue.h"
#include "DialogConditionBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static DialogLineData::DialogCondition* getB(lua_State* L, int idx)
{
    return checkObject<DialogLineData::DialogCondition>(L, idx, DialogConditionBinding::getMetatableName());
}

// --- Getters for DialogCondition ---
static int DialogCondition_get_key(lua_State* L)
{
    DialogLineData::DialogCondition* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogCondition is nil");
    lua_pushinteger(L, (lua_Integer)b->key);
    return 1;
}

static int DialogCondition_get_compareBy(lua_State* L)
{
    DialogLineData::DialogCondition* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogCondition is nil");
    lua_pushinteger(L, (lua_Integer)b->compareBy);
    return 1;
}

static int DialogCondition_get_who(lua_State* L)
{
    DialogLineData::DialogCondition* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogCondition is nil");
    lua_pushinteger(L, (lua_Integer)b->who);
    return 1;
}

static int DialogCondition_get_value(lua_State* L)
{
    DialogLineData::DialogCondition* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogCondition is nil");
    lua_pushinteger(L, b->value);
    return 1;
}

// --- Setters for DialogCondition ---
static int DialogCondition_set_key(lua_State* L)
{
    DialogLineData::DialogCondition* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogCondition is nil");
    b->key = (DialogConditionEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogCondition_set_compareBy(lua_State* L)
{
    DialogLineData::DialogCondition* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogCondition is nil");
    b->compareBy = (ComparisonEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogCondition_set_who(lua_State* L)
{
    DialogLineData::DialogCondition* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogCondition is nil");
    b->who = (TalkerEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogCondition_set_value(lua_State* L)
{
    DialogLineData::DialogCondition* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogCondition is nil");
    b->value = (int)luaL_checkinteger(L, 2);
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
    lua_pushcfunction(L, DialogCondition_get_key);
    lua_setfield(L, -2, "key");
    lua_pushcfunction(L, DialogCondition_get_compareBy);
    lua_setfield(L, -2, "compareBy");
    lua_pushcfunction(L, DialogCondition_get_who);
    lua_setfield(L, -2, "who");
    lua_pushcfunction(L, DialogCondition_get_value);
    lua_setfield(L, -2, "value");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, DialogCondition_set_key);
    lua_setfield(L, -2, "key");
    lua_pushcfunction(L, DialogCondition_set_compareBy);
    lua_setfield(L, -2, "compareBy");
    lua_pushcfunction(L, DialogCondition_set_who);
    lua_setfield(L, -2, "who");
    lua_pushcfunction(L, DialogCondition_set_value);
    lua_setfield(L, -2, "value");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua