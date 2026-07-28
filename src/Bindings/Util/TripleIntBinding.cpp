#include "pch.h"
#include "kenshi\util\TripleInt.h"
#include "TripleIntBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static TripleInt* getInstance(lua_State* L, int idx)
{
    return checkObject<TripleInt>(L, idx, TripleIntBinding::getMetatableName());
}

// --- Getters for TripleInt ---
static int TripleInt_get_value(lua_State* L)
{
    TripleInt* instance = getInstance(L, 1);
    if (!instance)
        return luaL_error(L, "TripleInt is nil");

    pushTripleInt(L, *instance);
    return 1;
}

// --- Setters for TripleInt ---
static int TripleInt_set_value(lua_State* L)
{
    TripleInt* instance = getInstance(L, 1);
    if (!instance)
        return luaL_error(L, "TripleInt is nil");

    if (!readTripleInt(L, 2, *instance))
        return luaL_error(L, "Expected table {x, y, z}");

    return 0;
}

/*
Skipped methods needing manual binding:
  line 9: TripleInt* _CONSTRUCTOR(...) - overloaded method
  line 11: TripleInt* _CONSTRUCTOR(...) - overloaded method
  line 13: TripleInt* _CONSTRUCTOR(...) - overloaded method
  line 14: const TripleInt& operator=(...) - operator
  line 15: int operator[](...) - operator
  line 16: int& operator[](...) - operator
*/

int TripleIntBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TripleIntBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TripleInt object");
    return 1;
}

void TripleIntBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TripleIntBinding::gc },
        { "__tostring", TripleIntBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        TripleIntBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TripleIntBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "value", TripleInt_get_value);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "value", TripleInt_set_value);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua