#include "pch.h"
#include "kenshi\CharMovement.h"
#include "SpeedGroupBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static SpeedGroup* getB(lua_State* L, int idx)
{
    return checkObject<SpeedGroup>(L, idx, SpeedGroupBinding::getMetatableName());
}

// --- Getters for SpeedGroup ---
static int SpeedGroup_get_members(lua_State* L)
{
    SpeedGroup* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpeedGroup is nil");
    // TODO: Unsupported type for members (ogre_unordered_set<hand>::type)
    lua_pushnil(L);
    return 1;
}

static int SpeedGroup_get_position(lua_State* L)
{
    SpeedGroup* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpeedGroup is nil");
    pushVector3(L, b->position);
    return 1;
}

static int SpeedGroup_get_direction(lua_State* L)
{
    SpeedGroup* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpeedGroup is nil");
    pushVector3(L, b->direction);
    return 1;
}

static int SpeedGroup_get_speed(lua_State* L)
{
    SpeedGroup* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpeedGroup is nil");
    lua_pushnumber(L, b->speed);
    return 1;
}

static int SpeedGroup_get_last(lua_State* L)
{
    SpeedGroup* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpeedGroup is nil");
    lua_pushinteger(L, b->last);
    return 1;
}

// --- Setters for SpeedGroup ---
static int SpeedGroup_set_members(lua_State* L)
{
    SpeedGroup* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpeedGroup is nil");
    return luaL_error(L, "Read-only or unsupported setter type for members");
}

static int SpeedGroup_set_position(lua_State* L)
{
    SpeedGroup* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpeedGroup is nil");
    readVector3(L, 2, b->position);
    return 0;
}

static int SpeedGroup_set_direction(lua_State* L)
{
    SpeedGroup* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpeedGroup is nil");
    readVector3(L, 2, b->direction);
    return 0;
}

static int SpeedGroup_set_speed(lua_State* L)
{
    SpeedGroup* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpeedGroup is nil");
    b->speed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SpeedGroup_set_last(lua_State* L)
{
    SpeedGroup* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpeedGroup is nil");
    b->last = (unsigned long)luaL_checkinteger(L, 2);
    return 0;
}

int SpeedGroupBinding::_DESTRUCTOR(lua_State* L)
{
    SpeedGroup* b = getB(L, 1);
    if (!b) return luaL_error(L, "SpeedGroup is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 67: SpeedGroup* _CONSTRUCTOR(...) - unsupported return type
  line 68: void insert(...) - unsupported arg type
  line 69: void erase(...) - unsupported arg type
  line 70: float getSpeed(...) - unsupported arg type
*/

int SpeedGroupBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SpeedGroupBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SpeedGroup object");
    return 1;
}

void SpeedGroupBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SpeedGroupBinding::gc },
        { "__tostring", SpeedGroupBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", SpeedGroupBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        SpeedGroupBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SpeedGroupBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, SpeedGroup_get_members);
    lua_setfield(L, -2, "members");
    lua_pushcfunction(L, SpeedGroup_get_position);
    lua_setfield(L, -2, "position");
    lua_pushcfunction(L, SpeedGroup_get_direction);
    lua_setfield(L, -2, "direction");
    lua_pushcfunction(L, SpeedGroup_get_speed);
    lua_setfield(L, -2, "speed");
    lua_pushcfunction(L, SpeedGroup_get_last);
    lua_setfield(L, -2, "last");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, SpeedGroup_set_members);
    lua_setfield(L, -2, "members");
    lua_pushcfunction(L, SpeedGroup_set_position);
    lua_setfield(L, -2, "position");
    lua_pushcfunction(L, SpeedGroup_set_direction);
    lua_setfield(L, -2, "direction");
    lua_pushcfunction(L, SpeedGroup_set_speed);
    lua_setfield(L, -2, "speed");
    lua_pushcfunction(L, SpeedGroup_set_last);
    lua_setfield(L, -2, "last");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua