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

/*
Skipped methods needing manual binding:
  line 15: YesNoMaybe* _CONSTRUCTOR(...) - overloaded method
  line 17: YesNoMaybe* _CONSTRUCTOR(...) - overloaded method
  line 19: YesNoMaybe* _CONSTRUCTOR(...) - overloaded method
  line 21: YesNoMaybe* _CONSTRUCTOR(...) - overloaded method
  line 23: operator bool(...) - unsupported return type
  line 24: operator YesNoMaybe::ynm(...) - unsupported return type
  line 26: bool operator==(...) - operator
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
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "toInt", YesNoMaybeBinding::toInt },
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