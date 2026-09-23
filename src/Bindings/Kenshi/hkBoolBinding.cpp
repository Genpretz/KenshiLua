#include "pch.h"
#include "kenshi\havok.h"
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

/*
Skipped methods needing manual binding:
  line 143: operator bool(...) - unsupported return type
  line 144: hkBool operator==(...) - operator
  line 145: hkBool operator!=(...) - operator
*/
int hkBoolBinding::eq(lua_State* L)
{
    hkBool* a = getInstance(L, 1);
    if (!a) return 0;
    if (lua_isboolean(L, 2))
    {
        bool b = lua_toboolean(L, 2) != 0;
        lua_pushboolean(L, a->operator==(b) ? 1 : 0);
        return 1;
    }
    hkBool* b = checkObject<hkBool>(L, 2, hkBoolBinding::getMetatableName());
    if (!b) return 0;
    lua_pushboolean(L, a->m_bool == b->m_bool ? 1 : 0);
    return 1;
}

int hkBoolBinding::isValid(lua_State* L)
{
    hkBool* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkBool is nil");

    bool result = instance->operator bool();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int hkBoolBinding::get(lua_State* L)
{
    hkBool* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkBool is nil");

    lua_pushboolean(L, instance->operator bool() ? 1 : 0);
    return 1;
}

int hkBoolBinding::set(lua_State* L)
{
    hkBool* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkBool is nil");

    instance->m_bool = lua_toboolean(L, 2) ? 1 : 0;
    return 0;
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
        { "isValid", hkBoolBinding::isValid },
        { "get",     hkBoolBinding::get },
        { "set",     hkBoolBinding::set },
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