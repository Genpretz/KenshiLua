#include "pch.h"
#include "kenshi/Dialogue.h"
#include "FlagConditionBinding.h"
#include "Lua/BindingHelpers.h"

typedef DialogLineData::FlagCondition FlagCondition;

namespace KenshiLua
{

static FlagCondition* getInstance(lua_State* L, int idx)
{
    return checkObject<FlagCondition>(L, idx, FlagConditionBinding::getMetatableName());
}

// --- Getters for FlagCondition ---
static int FlagCondition_get_key(lua_State* L)
{
    FlagCondition* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FlagCondition is nil");
    lua_pushinteger(L, (lua_Integer)instance->key);
    return 1;
}

static int FlagCondition_get_want(lua_State* L)
{
    FlagCondition* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FlagCondition is nil");
    lua_pushboolean(L, instance->want ? 1 : 0);
    return 1;
}

static int FlagCondition_get_flags(lua_State* L)
{
    FlagCondition* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FlagCondition is nil");
    lua_pushinteger(L, instance->flags);
    return 1;
}

// --- Setters for FlagCondition ---
static int FlagCondition_set_key(lua_State* L)
{
    FlagCondition* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FlagCondition is nil");
    instance->key = (DialogConditionEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int FlagCondition_set_want(lua_State* L)
{
    FlagCondition* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FlagCondition is nil");
    instance->want = lua_toboolean(L, 2) != 0;
    return 0;
}

static int FlagCondition_set_flags(lua_State* L)
{
    FlagCondition* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FlagCondition is nil");
    instance->flags = (unsigned int)luaL_checkinteger(L, 2);
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
    registerGetter(L, "key", FlagCondition_get_key);
    registerGetter(L, "want", FlagCondition_get_want);
    registerGetter(L, "flags", FlagCondition_get_flags);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "key", FlagCondition_set_key);
    registerSetter(L, "want", FlagCondition_set_want);
    registerSetter(L, "flags", FlagCondition_set_flags);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua