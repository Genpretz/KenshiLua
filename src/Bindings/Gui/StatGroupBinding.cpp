#include "pch.h"
#include <kenshi/gui/CharacterStatsWindow.h>
#include "StatGroupBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
    typedef CharacterStatsWindow::StatGroup StatGroup;

static StatGroup* getInstance(lua_State* L, int idx)
{
    return checkObject<StatGroup>(L, idx, StatGroupBinding::getMetatableName());
}

// --- Getters for StatGroup ---
static int StatGroup_get_group(lua_State* L)
{
    StatGroup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StatGroup is nil");
    lua_pushinteger(L, (lua_Integer)instance->group);
    return 1;
}

static int StatGroup_get_name(lua_State* L)
{
    StatGroup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StatGroup is nil");
    lua_pushstring(L, instance->name.c_str());
    return 1;
}

// --- Setters for StatGroup ---
static int StatGroup_set_group(lua_State* L)
{
    StatGroup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StatGroup is nil");
    instance->group = (CharacterStatsWindow::StatGroup::Group)luaL_checkinteger(L, 2);
    return 0;
}

static int StatGroup_set_name(lua_State* L)
{
    StatGroup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StatGroup is nil");
    instance->name = luaL_checkstring(L, 2);
    return 0;
}

int StatGroupBinding::_DESTRUCTOR(lua_State* L)
{
    StatGroup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StatGroup is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 51: StatGroup* _CONSTRUCTOR(...) - overloaded method
  line 53: StatGroup* _CONSTRUCTOR(...) - overloaded method
  line 55: StatGroup* _CONSTRUCTOR(...) - overloaded method
*/

int StatGroupBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int StatGroupBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.StatGroup object");
    return 1;
}

void StatGroupBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       StatGroupBinding::gc },
        { "__tostring", StatGroupBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", StatGroupBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        StatGroupBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, StatGroupBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, StatGroup_get_group);
    lua_setfield(L, -2, "group");
    lua_pushcfunction(L, StatGroup_get_name);
    lua_setfield(L, -2, "name");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, StatGroup_set_group);
    lua_setfield(L, -2, "group");
    lua_pushcfunction(L, StatGroup_set_name);
    lua_setfield(L, -2, "name");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua