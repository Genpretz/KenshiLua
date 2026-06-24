#include "pch.h"
#include "kenshi\Dialogue.h"
#include "FlagConditionBinding.h"
#include "Lua/BindingHelpers.h"

typedef DialogLineData::FlagCondition FlagCondition;

namespace KenshiLua
{

static FlagCondition* getB(lua_State* L, int idx)
{
    return checkObject<FlagCondition>(L, idx, FlagConditionBinding::getMetatableName());
}

// --- Getters for FlagCondition ---
static int FlagCondition_get_key(lua_State* L)
{
    FlagCondition* b = getB(L, 1);
    if (!b) return luaL_error(L, "FlagCondition is nil");
    lua_pushinteger(L, (lua_Integer)b->key);
    return 1;
}

static int FlagCondition_get_want(lua_State* L)
{
    FlagCondition* b = getB(L, 1);
    if (!b) return luaL_error(L, "FlagCondition is nil");
    lua_pushboolean(L, b->want ? 1 : 0);
    return 1;
}

static int FlagCondition_get_flags(lua_State* L)
{
    FlagCondition* b = getB(L, 1);
    if (!b) return luaL_error(L, "FlagCondition is nil");
    lua_pushinteger(L, b->flags);
    return 1;
}

// --- Setters for FlagCondition ---
static int FlagCondition_set_key(lua_State* L)
{
    FlagCondition* b = getB(L, 1);
    if (!b) return luaL_error(L, "FlagCondition is nil");
    b->key = (DialogConditionEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int FlagCondition_set_want(lua_State* L)
{
    FlagCondition* b = getB(L, 1);
    if (!b) return luaL_error(L, "FlagCondition is nil");
    b->want = lua_toboolean(L, 2) != 0;
    return 0;
}

static int FlagCondition_set_flags(lua_State* L)
{
    FlagCondition* b = getB(L, 1);
    if (!b) return luaL_error(L, "FlagCondition is nil");
    b->flags = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}



int FlagConditionBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int FlagConditionBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FlagCondition object");
    return 1;
}

void FlagConditionBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FlagConditionBinding::gc },
        { "__tostring", FlagConditionBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        FlagConditionBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FlagConditionBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, FlagCondition_get_key);
    lua_setfield(L, -2, "key");
    lua_pushcfunction(L, FlagCondition_get_want);
    lua_setfield(L, -2, "want");
    lua_pushcfunction(L, FlagCondition_get_flags);
    lua_setfield(L, -2, "flags");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, FlagCondition_set_key);
    lua_setfield(L, -2, "key");
    lua_pushcfunction(L, FlagCondition_set_want);
    lua_setfield(L, -2, "want");
    lua_pushcfunction(L, FlagCondition_set_flags);
    lua_setfield(L, -2, "flags");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua