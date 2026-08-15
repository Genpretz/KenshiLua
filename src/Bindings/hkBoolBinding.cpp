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
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
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