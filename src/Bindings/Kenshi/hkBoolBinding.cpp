#include "pch.h"
#include "kenshi/Havok.h"
#include "hkBoolBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static hkBool* getInstance(lua_State* L, int idx)
{
    return checkObject<hkBool>(L, idx, hkBoolBinding::getMetatableName());
}

// --- Getters for hkBool ---
static int hkBool_get_m_bool(lua_State* L)
{
    hkBool* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkBool is nil");
    lua_pushinteger(L, instance->m_bool);
    return 1;
}

// --- Setters for hkBool ---
static int hkBool_set_m_bool(lua_State* L)
{
    hkBool* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkBool is nil");
    instance->m_bool = (char)luaL_checkinteger(L, 2);
    return 0;
}

int hkBoolBinding::eq(lua_State* L)
{
    hkBool* a = getInstance(L, 1);
    if (!a) return 0;
    if (lua_isboolean(L, 2))
    {
        bool b = lua_toboolean(L, 2) != 0;
        lua_pushboolean(L, a->operator==(b).operator bool() ? 1 : 0);
        return 1;
    }
    hkBool* b = checkObject<hkBool>(L, 2, hkBoolBinding::getMetatableName());
    if (!b) return 0;
    lua_pushboolean(L, a->m_bool == b->m_bool ? 1 : 0);
    return 1;
}

int hkBoolBinding::operator_eq(lua_State* L)
{
    if (lua_gettop(L) != 2)
        return luaL_error(L, "hkBool:operator_eq() expects exactly 1 argument (value)");
    hkBool* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkBool is nil");

    bool val = false;
    if (lua_isboolean(L, 2))
    {
        val = lua_toboolean(L, 2) != 0;
    }
    else if (hkBool* other = testObject<hkBool>(L, 2, hkBoolBinding::getMetatableName()))
    {
        val = other->operator bool();
    }
    else
    {
        return luaL_error(L, "Argument 1 to hkBool:operator_eq() must be a boolean or hkBool");
    }

    hkBool result = instance->operator==(val);
    lua_pushboolean(L, result.operator bool() ? 1 : 0);
    return 1;
}

int hkBoolBinding::operator_ne(lua_State* L)
{
    if (lua_gettop(L) != 2)
        return luaL_error(L, "hkBool:operator_ne() expects exactly 1 argument (value)");
    hkBool* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkBool is nil");

    bool val = false;
    if (lua_isboolean(L, 2))
    {
        val = lua_toboolean(L, 2) != 0;
    }
    else if (hkBool* other = testObject<hkBool>(L, 2, hkBoolBinding::getMetatableName()))
    {
        val = other->operator bool();
    }
    else
    {
        return luaL_error(L, "Argument 1 to hkBool:operator_ne() must be a boolean or hkBool");
    }

    hkBool result = instance->operator!=(val);
    lua_pushboolean(L, result.operator bool() ? 1 : 0);
    return 1;
}

int hkBoolBinding::operator_bool(lua_State* L)
{
    if (lua_gettop(L) != 1)
        return luaL_error(L, "hkBool:operator_bool() expects only self (no arguments)");
    hkBool* instance = getInstance(L, 1);
    bool result = instance->operator bool();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int hkBoolBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int hkBoolBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.hkBool object");
    return 1;
}

void hkBoolBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       hkBoolBinding::gc },
        { "__tostring", hkBoolBinding::tostring },
        { "__eq",       hkBoolBinding::eq },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "operator_bool", hkBoolBinding::operator_bool },
        { "operator_eq",   hkBoolBinding::operator_eq },
        { "operator_ne",   hkBoolBinding::operator_ne },
        { 0, 0 }
    };

    registerClass(
        L, 
        hkBoolBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, hkBoolBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "m_bool", hkBool_get_m_bool);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "m_bool", hkBool_set_m_bool);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
