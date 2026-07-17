#include "pch.h"
#include <kenshi\util\StringPair.h>
#include "StringPairBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static StringPair* getInstance(lua_State* L, int idx)
{
    return checkObject<StringPair>(L, idx, StringPairBinding::getMetatableName());
}

// --- Getters for StringPair ---
static int StringPair_get_s1(lua_State* L)
{
    StringPair* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StringPair is nil");
    lua_pushstring(L, instance->s1.c_str());
    return 1;
}

static int StringPair_get_s2(lua_State* L)
{
    StringPair* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StringPair is nil");
    lua_pushstring(L, instance->s2.c_str());
    return 1;
}

static int StringPair_get_val1(lua_State* L)
{
    StringPair* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StringPair is nil");
    lua_pushnumber(L, instance->val1);
    return 1;
}

// --- Setters for StringPair ---
static int StringPair_set_s1(lua_State* L)
{
    StringPair* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StringPair is nil");
    instance->s1 = luaL_checkstring(L, 2);
    return 0;
}

static int StringPair_set_s2(lua_State* L)
{
    StringPair* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StringPair is nil");
    instance->s2 = luaL_checkstring(L, 2);
    return 0;
}

static int StringPair_set_val1(lua_State* L)
{
    StringPair* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StringPair is nil");
    instance->val1 = (float)luaL_checknumber(L, 2);
    return 0;
}

int StringPairBinding::_DESTRUCTOR(lua_State* L)
{
    StringPair* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StringPair is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 12: StringPair* _CONSTRUCTOR(...) - overloaded method
  line 14: StringPair* _CONSTRUCTOR(...) - overloaded method
  line 16: StringPair* _CONSTRUCTOR(...) - overloaded method
  line 18: StringPair* _CONSTRUCTOR(...) - overloaded method
  line 24: const StringPair& operator=(...) - operator
  line 25: const StringPair& _NV_operator_assign(...) - reference return type
*/

int StringPairBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int StringPairBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.StringPair object");
    return 1;
}

void StringPairBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       StringPairBinding::gc },
        { "__tostring", StringPairBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", StringPairBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        StringPairBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, StringPairBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, StringPair_get_s1);
    lua_setfield(L, -2, "s1");
    lua_pushcfunction(L, StringPair_get_s2);
    lua_setfield(L, -2, "s2");
    lua_pushcfunction(L, StringPair_get_val1);
    lua_setfield(L, -2, "val1");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, StringPair_set_s1);
    lua_setfield(L, -2, "s1");
    lua_pushcfunction(L, StringPair_set_s2);
    lua_setfield(L, -2, "s2");
    lua_pushcfunction(L, StringPair_set_val1);
    lua_setfield(L, -2, "val1");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua