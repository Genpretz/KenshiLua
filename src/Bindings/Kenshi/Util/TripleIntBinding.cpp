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

int TripleIntBinding::operator_assign(lua_State* L)
{
    TripleInt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TripleInt is nil");

    TripleInt* other = testObject<TripleInt>(L, 2, TripleIntBinding::getMetatableName());
    if (other)
    {
        instance->operator=(*other);
    }
    else if (lua_istable(L, 2))
    {
        TripleInt temp;
        if (!readTripleInt(L, 2, temp))
            return luaL_error(L, "Argument 2 table must be {x, y, z}");
        instance->operator=(temp);
    }
    else
    {
        return luaL_error(L, "Argument 2 to operator_assign must be TripleInt or table {x, y, z}");
    }

    lua_pushvalue(L, 1);
    return 1;
}

int TripleIntBinding::operator_subscript(lua_State* L)
{
    TripleInt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TripleInt is nil");

    int i = (int)luaL_checkinteger(L, 2);
    if (i < 0 || i >= 3)
    {
        return luaL_error(L, "Index out of bounds: %d (expected 0..2)", i);
    }

    if (lua_gettop(L) >= 3)
    {
        int val = (int)luaL_checkinteger(L, 3);
        instance->operator[](i) = val;
        return 0;
    }
    else
    {
        int result = instance->operator[](i);
        lua_pushinteger(L, result);
        return 1;
    }
}

//custom index function
int TripleIntBinding::index(lua_State* L)
{
    if (lua_type(L, 2) == LUA_TNUMBER)
    {
        TripleInt* instance = getInstance(L, 1);
        if (!instance) return luaL_error(L, "TripleInt is nil");

        int idx = (int)lua_tointeger(L, 2);
        if (idx >= 1 && idx <= 3)
        {
            lua_pushinteger(L, instance->operator[](idx - 1));
            return 1;
        }
        lua_pushnil(L);
        return 1;
    }

    return genericPropertyIndex(L);
}
//custom new index function
int TripleIntBinding::newindex(lua_State* L)
{
    if (lua_type(L, 2) == LUA_TNUMBER)
    {
        TripleInt* instance = getInstance(L, 1);
        if (!instance) return luaL_error(L, "TripleInt is nil");

        int idx = (int)lua_tointeger(L, 2);
        if (idx >= 1 && idx <= 3)
        {
            int val = (int)luaL_checkinteger(L, 3);
            instance->operator[](idx - 1) = val;
            return 0;
        }
        return luaL_error(L, "TripleInt index out of bounds: %d (expected 1..3)", idx);
    }

    return genericPropertyNewIndex(L);
}

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
        { "operator_assign",    TripleIntBinding::operator_assign },
        { "operator_subscript", TripleIntBinding::operator_subscript },
        { "operator_index",     TripleIntBinding::operator_subscript },
        { 0, 0 }
    };

    registerClass(
        L, 
        TripleIntBinding::getMetatableName(), 
        meta, 
        methods, 
        TripleIntBinding::index, 
        TripleIntBinding::newindex
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