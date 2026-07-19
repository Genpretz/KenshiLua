#include "pch.h"
#include "kenshi\Dialogue.h"
#include "DialogStateBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static Dialogue::RepetitionCounter::DialogState* getB(lua_State* L, int idx)
{
    return checkObject<Dialogue::RepetitionCounter::DialogState>(L, idx, DialogStateBinding::getMetatableName());
}

// --- Getters for DialogState ---
static int DialogState_get_count(lua_State* L)
{
    Dialogue::RepetitionCounter::DialogState* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogState is nil");
    lua_pushinteger(L, b->count);
    return 1;
}

static int DialogState_get_lastTimeStamp(lua_State* L)
{
    Dialogue::RepetitionCounter::DialogState* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogState is nil");
    lua_pushnumber(L, b->lastTimeStamp);
    return 1;
}

static int DialogState_get_resetTime(lua_State* L)
{
    Dialogue::RepetitionCounter::DialogState* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogState is nil");
    lua_pushnumber(L, b->resetTime);
    return 1;
}

// --- Setters for DialogState ---
static int DialogState_set_count(lua_State* L)
{
    Dialogue::RepetitionCounter::DialogState* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogState is nil");
    b->count = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int DialogState_set_lastTimeStamp(lua_State* L)
{
    Dialogue::RepetitionCounter::DialogState* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogState is nil");
    b->lastTimeStamp = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DialogState_set_resetTime(lua_State* L)
{
    Dialogue::RepetitionCounter::DialogState* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogState is nil");
    b->resetTime = (float)luaL_checknumber(L, 2);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 290: DialogState* _CONSTRUCTOR(...) - unsupported return type
*/

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
    lua_pushcfunction(L, DialogState_get_count);
    lua_setfield(L, -2, "count");
    lua_pushcfunction(L, DialogState_get_lastTimeStamp);
    lua_setfield(L, -2, "lastTimeStamp");
    lua_pushcfunction(L, DialogState_get_resetTime);
    lua_setfield(L, -2, "resetTime");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, DialogState_set_count);
    lua_setfield(L, -2, "count");
    lua_pushcfunction(L, DialogState_set_lastTimeStamp);
    lua_setfield(L, -2, "lastTimeStamp");
    lua_pushcfunction(L, DialogState_set_resetTime);
    lua_setfield(L, -2, "resetTime");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
