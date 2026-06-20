#include "pch.h"
#include "Bindings/StatBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/CharacterStatsWindow.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static Stat* getS(lua_State* L, int idx)
{
    return checkObject<Stat>(L, idx, StatBinding::getMetatableName());
}

int StatBinding::gc(lua_State* L) { return noopGc(L); }

int StatBinding::tostring(lua_State* L)
{
    Stat* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int StatBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, StatBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    Stat* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    // TODO StatsEnumerated type; unsupported __index type from header line 25
    if (strcmp(key, "id") == 0) { lua_pushstring(L, s->id.c_str()); return 1; }
    if (strcmp(key, "name") == 0) { lua_pushstring(L, s->name.c_str()); return 1; }
    if (strcmp(key, "description") == 0) { lua_pushstring(L, s->description.c_str()); return 1; }
    if (strcmp(key, "active") == 0) { lua_pushboolean(L, s->active ? 1 : 0); return 1; }

    lua_pushnil(L);
    return 1;
}

int StatBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    Stat* s = getS(L, 1);
    if (!s) return luaL_error(L, "Stat is nil");

    // TODO StatsEnumerated type; unsupported __newindex type from header line 25
    if (strcmp(key, "id") == 0) { s->id = luaL_checkstring(L, 3); return 0; }
    if (strcmp(key, "name") == 0) { s->name = luaL_checkstring(L, 3); return 0; }
    if (strcmp(key, "description") == 0) { s->description = luaL_checkstring(L, 3); return 0; }
    if (strcmp(key, "active") == 0) { s->active = lua_toboolean(L, 3) != 0; return 0; }

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int StatBinding::_DESTRUCTOR(lua_State* L)
{
    Stat* s = getS(L, 1);
    if (!s) return luaL_error(L, "Stat is nil");

    s->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 20: Stat* _CONSTRUCTOR(...) - overloaded method
  line 22: Stat* _CONSTRUCTOR(...) - overloaded method
  line 24: Stat* _CONSTRUCTOR(...) - overloaded method
  line 32: CharacterStatsWindow::Stat& operator=(...) - operator
*/

void StatBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       StatBinding::gc },
        { "__tostring", StatBinding::tostring },
        { "__index",    StatBinding::index },
        { "__newindex", StatBinding::newindex },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", StatBinding::_DESTRUCTOR },
        { 0, 0 }
    };
    registerClass(L, StatBinding::getMetatableName(), meta, methods);
}

} // namespace KenshiLua