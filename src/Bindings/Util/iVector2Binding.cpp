#include "pch.h"
#include <kenshi\util\iVector2.h>
#include "iVector2Binding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static iVector2* getInstance(lua_State* L, int idx)
{
    return checkObject<iVector2>(L, idx, iVector2Binding::getMetatableName());
}

// --- Getters for iVector2 ---
static int iVector2_get_x(lua_State* L)
{
    iVector2* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "iVector2 is nil");
    lua_pushinteger(L, instance->x);
    return 1;
}

static int iVector2_get_y(lua_State* L)
{
    iVector2* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "iVector2 is nil");
    lua_pushinteger(L, instance->y);
    return 1;
}

// --- Setters for iVector2 ---
static int iVector2_set_x(lua_State* L)
{
    iVector2* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "iVector2 is nil");
    instance->x = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int iVector2_set_y(lua_State* L)
{
    iVector2* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "iVector2 is nil");
    instance->y = (int)luaL_checkinteger(L, 2);
    return 0;
}

int iVector2Binding::getLinearValue(lua_State* L)
{
    iVector2* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "iVector2 is nil");

    int result = instance->getLinearValue();
    lua_pushinteger(L, result);
    return 1;
}

int iVector2Binding::getAsString(lua_State* L)
{
    iVector2* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "iVector2 is nil");

    std::string result = instance->getAsString();
    lua_pushstring(L, result.c_str());
    return 1;
}

/*
Skipped methods needing manual binding:
  line 9: iVector2* _CONSTRUCTOR(...) - overloaded method
  line 11: iVector2* _CONSTRUCTOR(...) - overloaded method
  line 14: bool operator==(...) - operator
  line 15: bool operator!=(...) - operator
  line 17: bool operator<(...) - operator
  line 19: iVector2 operator+(...) - operator
*/

int iVector2Binding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int iVector2Binding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.iVector2 object");
    return 1;
}

void iVector2Binding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       iVector2Binding::gc },
        { "__tostring", iVector2Binding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getLinearValue", iVector2Binding::getLinearValue },
        { "getAsString", iVector2Binding::getAsString },
        { 0, 0 }
    };

    registerClass(
        L, 
        iVector2Binding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, iVector2Binding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, iVector2_get_x);
    lua_setfield(L, -2, "x");
    lua_pushcfunction(L, iVector2_get_y);
    lua_setfield(L, -2, "y");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, iVector2_set_x);
    lua_setfield(L, -2, "x");
    lua_pushcfunction(L, iVector2_set_y);
    lua_setfield(L, -2, "y");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua