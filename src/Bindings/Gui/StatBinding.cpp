#include "pch.h"
#include "kenshi\gui\CharacterStatsWindow.h"
#include "StatBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

typedef CharacterStatsWindow::Stat Stat;

static Stat* getInstance(lua_State* L, int idx)
{
    return checkObject<Stat>(L, idx, StatBinding::getMetatableName());
}

// --- Getters for Stat ---
static int Stat_get_type(lua_State* L)
{
    Stat* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Stat is nil");
    lua_pushinteger(L, (lua_Integer)instance->type);
    return 1;
}

static int Stat_get_id(lua_State* L)
{
    Stat* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Stat is nil");
    lua_pushstring(L, instance->id.c_str());
    return 1;
}

static int Stat_get_name(lua_State* L)
{
    Stat* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Stat is nil");
    lua_pushstring(L, instance->name.c_str());
    return 1;
}

static int Stat_get_description(lua_State* L)
{
    Stat* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Stat is nil");
    lua_pushstring(L, instance->description.c_str());
    return 1;
}

static int Stat_get_active(lua_State* L)
{
    Stat* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Stat is nil");
    lua_pushboolean(L, instance->active ? 1 : 0);
    return 1;
}

// --- Setters for Stat ---
static int Stat_set_type(lua_State* L)
{
    Stat* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Stat is nil");
    instance->type = (StatsEnumerated)luaL_checkinteger(L, 2);
    return 0;
}

static int Stat_set_id(lua_State* L)
{
    Stat* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Stat is nil");
    instance->id = luaL_checkstring(L, 2);
    return 0;
}

static int Stat_set_name(lua_State* L)
{
    Stat* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Stat is nil");
    instance->name = luaL_checkstring(L, 2);
    return 0;
}

static int Stat_set_description(lua_State* L)
{
    Stat* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Stat is nil");
    instance->description = luaL_checkstring(L, 2);
    return 0;
}

static int Stat_set_active(lua_State* L)
{
    Stat* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Stat is nil");
    instance->active = lua_toboolean(L, 2) != 0;
    return 0;
}

/*
Skipped methods needing manual binding:
  line 32: CharacterStatsWindow::Stat& operator=(...) - operator
*/

int StatBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int StatBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Stat object");
    return 1;
}

void StatBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       StatBinding::gc },
        { "__tostring", StatBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        StatBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, StatBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "type", Stat_get_type);
    registerGetter(L, "id", Stat_get_id);
    registerGetter(L, "name", Stat_get_name);
    registerGetter(L, "description", Stat_get_description);
    registerGetter(L, "active", Stat_get_active);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "type", Stat_set_type);
    registerSetter(L, "id", Stat_set_id);
    registerSetter(L, "name", Stat_set_name);
    registerSetter(L, "description", Stat_set_description);
    registerSetter(L, "active", Stat_set_active);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua