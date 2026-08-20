#include "pch.h"
#include <kenshi\util\YesNoMaybe.h>
#include "YesNoMaybeBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static YesNoMaybe* getInstance(lua_State* L, int idx)
{
    return checkObject<YesNoMaybe>(L, idx, YesNoMaybeBinding::getMetatableName());
}

// --- Getters for YesNoMaybe ---
static int YesNoMaybe_get_key(lua_State* L)
{
    YesNoMaybe* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "YesNoMaybe is nil");
    lua_pushinteger(L, (lua_Integer)instance->key);
    return 1;
}

// --- Setters for YesNoMaybe ---
static int YesNoMaybe_set_key(lua_State* L)
{
    YesNoMaybe* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "YesNoMaybe is nil");
    instance->key = (YesNoMaybe::ynm)luaL_checkinteger(L, 2);
    return 0;
}

int YesNoMaybeBinding::toInt(lua_State* L)
{
    YesNoMaybe* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "YesNoMaybe is nil");

    int result = instance->toInt();
    lua_pushinteger(L, result);
    return 1;
}

int YesNoMaybeBinding::isValid(lua_State* L)
{
    YesNoMaybe* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "YesNoMaybe is nil");

    bool result = instance->operator bool();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int YesNoMaybeBinding::eq(lua_State* L)
{
    YesNoMaybe* a = getInstance(L, 1);
    if (!a) return luaL_error(L, "YesNoMaybe is nil");

    if (YesNoMaybe* b = testObject<YesNoMaybe>(L, 2, YesNoMaybeBinding::getMetatableName()))
    {
        lua_pushboolean(L, (*a == *b) ? 1 : 0);
        return 1;
    }
    else if (lua_isnumber(L, 2))
    {
        YesNoMaybe::ynm val = (YesNoMaybe::ynm)luaL_checkinteger(L, 2);
        lua_pushboolean(L, (*a == val) ? 1 : 0);
        return 1;
    }
    lua_pushboolean(L, 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 24: operator YesNoMaybe::ynm(...) - unsupported return type
  line 28: bool operator!=(...) - operator
  line 29: bool operator!=(...) - operator
  line 30: bool operator!=(...) - operator
*/

int YesNoMaybeBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int YesNoMaybeBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.YesNoMaybe object");
    return 1;
}

void YesNoMaybeBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       YesNoMaybeBinding::gc },
        { "__tostring", YesNoMaybeBinding::tostring },
        { "__eq",       YesNoMaybeBinding::eq },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "toInt", YesNoMaybeBinding::toInt },
        { "isValid", YesNoMaybeBinding::isValid },
        { 0, 0 }
    };

    registerClass(
        L, 
        YesNoMaybeBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, YesNoMaybeBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, YesNoMaybe_get_key);
    lua_setfield(L, -2, "key");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, YesNoMaybe_set_key);
    lua_setfield(L, -2, "key");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua