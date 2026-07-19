#include "pch.h"
#include "kenshi\SensoryData.h"
#include "VisibleObjectInfoBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static VisibleObjectInfo* getB(lua_State* L, int idx)
{
    return checkObject<VisibleObjectInfo>(L, idx, VisibleObjectInfoBinding::getMetatableName());
}

// --- Getters for VisibleObjectInfo ---
static int VisibleObjectInfo_get_handle(lua_State* L)
{
    VisibleObjectInfo* b = getB(L, 1);
    if (!b) return luaL_error(L, "VisibleObjectInfo is nil");
    // TODO: Unsupported type for handle (hand)
    return luaL_error(L, "Unsupported property 'handle' (type: hand)");
}

static int VisibleObjectInfo_get_range(lua_State* L)
{
    VisibleObjectInfo* b = getB(L, 1);
    if (!b) return luaL_error(L, "VisibleObjectInfo is nil");
    lua_pushnumber(L, b->range);
    return 1;
}

static int VisibleObjectInfo_get_isEnemy(lua_State* L)
{
    VisibleObjectInfo* b = getB(L, 1);
    if (!b) return luaL_error(L, "VisibleObjectInfo is nil");
    lua_pushboolean(L, b->isEnemy ? 1 : 0);
    return 1;
}

// --- Setters for VisibleObjectInfo ---
static int VisibleObjectInfo_set_handle(lua_State* L)
{
    VisibleObjectInfo* b = getB(L, 1);
    if (!b) return luaL_error(L, "VisibleObjectInfo is nil");
    return luaL_error(L, "Read-only or unsupported setter type for handle");
}

static int VisibleObjectInfo_set_range(lua_State* L)
{
    VisibleObjectInfo* b = getB(L, 1);
    if (!b) return luaL_error(L, "VisibleObjectInfo is nil");
    b->range = (float)luaL_checknumber(L, 2);
    return 0;
}

static int VisibleObjectInfo_set_isEnemy(lua_State* L)
{
    VisibleObjectInfo* b = getB(L, 1);
    if (!b) return luaL_error(L, "VisibleObjectInfo is nil");
    b->isEnemy = lua_toboolean(L, 2) != 0;
    return 0;
}

/*
Skipped methods needing manual binding:
  line 85: VisibleObjectInfo* _CONSTRUCTOR(...) - overloaded method
  line 88: VisibleObjectInfo* _CONSTRUCTOR(...) - overloaded method
  line 93: VisibleObjectInfo& operator=(...) - operator
*/

int VisibleObjectInfoBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int VisibleObjectInfoBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.VisibleObjectInfo object");
    return 1;
}

void VisibleObjectInfoBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       VisibleObjectInfoBinding::gc },
        { "__tostring", VisibleObjectInfoBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        VisibleObjectInfoBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, VisibleObjectInfoBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, VisibleObjectInfo_get_handle);
    lua_setfield(L, -2, "handle");
    lua_pushcfunction(L, VisibleObjectInfo_get_range);
    lua_setfield(L, -2, "range");
    lua_pushcfunction(L, VisibleObjectInfo_get_isEnemy);
    lua_setfield(L, -2, "isEnemy");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, VisibleObjectInfo_set_handle);
    lua_setfield(L, -2, "handle");
    lua_pushcfunction(L, VisibleObjectInfo_set_range);
    lua_setfield(L, -2, "range");
    lua_pushcfunction(L, VisibleObjectInfo_set_isEnemy);
    lua_setfield(L, -2, "isEnemy");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
