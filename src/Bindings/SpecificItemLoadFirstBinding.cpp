#include "pch.h"
#include "kenshi\RootObject.h"
#include "SpecificItemLoadFirstBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

typedef RootObjectContainer::SpecificItemLoadFirst SpecificItemLoadFirst;

static SpecificItemLoadFirst* getB(lua_State* L, int idx)
{
    return checkObject<SpecificItemLoadFirst>(L, idx, SpecificItemLoadFirstBinding::getMetatableName());
}

// --- Getters for SpecificItemLoadFirst ---
static int SpecificItemLoadFirst_get_baseTypes(lua_State* L)
{
    SpecificItemLoadFirst* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpecificItemLoadFirst is nil");
    lua_pushinteger(L, (lua_Integer)b->baseTypes);
    return 1;
}

static int SpecificItemLoadFirst_get_stateEnum(lua_State* L)
{
    SpecificItemLoadFirst* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpecificItemLoadFirst is nil");
    lua_pushinteger(L, (lua_Integer)b->stateEnum);
    return 1;
}

static int SpecificItemLoadFirst_get_specificProperty(lua_State* L)
{
    SpecificItemLoadFirst* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpecificItemLoadFirst is nil");
    lua_pushstring(L, b->specificProperty.c_str());
    return 1;
}

static int SpecificItemLoadFirst_get_desiredSpecificProperty(lua_State* L)
{
    SpecificItemLoadFirst* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpecificItemLoadFirst is nil");
    lua_pushboolean(L, b->desiredSpecificProperty ? 1 : 0);
    return 1;
}

// --- Setters for SpecificItemLoadFirst ---
static int SpecificItemLoadFirst_set_baseTypes(lua_State* L)
{
    SpecificItemLoadFirst* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpecificItemLoadFirst is nil");
    b->baseTypes = (itemType)luaL_checkinteger(L, 2);
    return 0;
}

static int SpecificItemLoadFirst_set_stateEnum(lua_State* L)
{
    SpecificItemLoadFirst* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpecificItemLoadFirst is nil");
    b->stateEnum = (itemType)luaL_checkinteger(L, 2);
    return 0;
}

static int SpecificItemLoadFirst_set_specificProperty(lua_State* L)
{
    SpecificItemLoadFirst* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpecificItemLoadFirst is nil");
    b->specificProperty = luaL_checkstring(L, 2);
    return 0;
}

static int SpecificItemLoadFirst_set_desiredSpecificProperty(lua_State* L)
{
    SpecificItemLoadFirst* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpecificItemLoadFirst is nil");
    b->desiredSpecificProperty = lua_toboolean(L, 2) != 0;
    return 0;
}

int SpecificItemLoadFirstBinding::flip(lua_State* L)
{
    SpecificItemLoadFirst* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpecificItemLoadFirst is nil");

    b->flip();
    return 0;
}

int SpecificItemLoadFirstBinding::_DESTRUCTOR(lua_State* L)
{
    SpecificItemLoadFirst* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpecificItemLoadFirst is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 208: SpecificItemLoadFirst* _CONSTRUCTOR(...) - unsupported return type
  line 214: bool shouldSkip(...) - unsupported arg type
  line 215: bool _NV_shouldSkip(...) - unsupported arg type
*/

int SpecificItemLoadFirstBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SpecificItemLoadFirstBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SpecificItemLoadFirst object");
    return 1;
}

void SpecificItemLoadFirstBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SpecificItemLoadFirstBinding::gc },
        { "__tostring", SpecificItemLoadFirstBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "flip", SpecificItemLoadFirstBinding::flip },
        { "_DESTRUCTOR", SpecificItemLoadFirstBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        SpecificItemLoadFirstBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SpecificItemLoadFirstBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, SpecificItemLoadFirst_get_baseTypes);
    lua_setfield(L, -2, "baseTypes");
    lua_pushcfunction(L, SpecificItemLoadFirst_get_stateEnum);
    lua_setfield(L, -2, "stateEnum");
    lua_pushcfunction(L, SpecificItemLoadFirst_get_specificProperty);
    lua_setfield(L, -2, "specificProperty");
    lua_pushcfunction(L, SpecificItemLoadFirst_get_desiredSpecificProperty);
    lua_setfield(L, -2, "desiredSpecificProperty");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, SpecificItemLoadFirst_set_baseTypes);
    lua_setfield(L, -2, "baseTypes");
    lua_pushcfunction(L, SpecificItemLoadFirst_set_stateEnum);
    lua_setfield(L, -2, "stateEnum");
    lua_pushcfunction(L, SpecificItemLoadFirst_set_specificProperty);
    lua_setfield(L, -2, "specificProperty");
    lua_pushcfunction(L, SpecificItemLoadFirst_set_desiredSpecificProperty);
    lua_setfield(L, -2, "desiredSpecificProperty");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
