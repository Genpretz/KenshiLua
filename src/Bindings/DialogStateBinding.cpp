#include "pch.h"
#include "kenshi/Dialogue.h"
#include "DialogStateBinding.h"
#include "Lua/BindingHelpers.h"

typedef Dialogue::RepetitionCounter::DialogState DialogState;

namespace KenshiLua
{

static DialogState* getInstance(lua_State* L, int idx)
{
    return checkObject<DialogState>(L, idx, DialogStateBinding::getMetatableName());
}

// --- Getters for DialogState ---
static int DialogState_get_count(lua_State* L)
{
    DialogState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogState is nil");
    lua_pushinteger(L, instance->count);
    return 1;
}

static int DialogState_get_lastTimeStamp(lua_State* L)
{
    DialogState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogState is nil");
    lua_pushnumber(L, instance->lastTimeStamp);
    return 1;
}

static int DialogState_get_resetTime(lua_State* L)
{
    DialogState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogState is nil");
    lua_pushnumber(L, instance->resetTime);
    return 1;
}

// --- Setters for DialogState ---
static int DialogState_set_count(lua_State* L)
{
    DialogState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogState is nil");
    instance->count = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogState_set_lastTimeStamp(lua_State* L)
{
    DialogState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogState is nil");
    instance->lastTimeStamp = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DialogState_set_resetTime(lua_State* L)
{
    DialogState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogState is nil");
    instance->resetTime = (float)luaL_checknumber(L, 2);
    return 0;
}

int DialogStateBinding::_CONSTRUCTOR(lua_State* L)
{
    DialogState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogState is nil");

    DialogState* result = instance->_CONSTRUCTOR();
    return pushObject<DialogState>(L, result, DialogStateBinding::getMetatableName());
}

int DialogStateBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DialogStateBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DialogState object");
    return 1;
}

void DialogStateBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DialogStateBinding::gc },
        { "__tostring", DialogStateBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", DialogStateBinding::_CONSTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        DialogStateBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DialogStateBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "count", DialogState_get_count);
    registerGetter(L, "lastTimeStamp", DialogState_get_lastTimeStamp);
    registerGetter(L, "resetTime", DialogState_get_resetTime);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "count", DialogState_set_count);
    registerSetter(L, "lastTimeStamp", DialogState_set_lastTimeStamp);
    registerSetter(L, "resetTime", DialogState_set_resetTime);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua