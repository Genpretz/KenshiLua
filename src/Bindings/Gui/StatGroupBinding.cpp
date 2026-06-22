#include "pch.h"
#include "Bindings/StatGroupBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/CharacterStatsWindow.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static StatGroup* getS(lua_State* L, int idx)
{
    return checkObject<StatGroup>(L, idx, StatGroupBinding::getMetatableName());
}

int StatGroupBinding::gc(lua_State* L) { return noopGc(L); }

int StatGroupBinding::tostring(lua_State* L)
{
    StatGroup* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int StatGroupBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, StatGroupBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    StatGroup* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "group") == 0) { lua_pushinteger(L, (lua_Integer)s->group); return 1; }
    if (strcmp(key, "name") == 0) { lua_pushstring(L, s->name.c_str()); return 1; }

    lua_pushnil(L);
    return 1;
}

int StatGroupBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    StatGroup* s = getS(L, 1);
    if (!s) return luaL_error(L, "StatGroup is nil");

    if (strcmp(key, "group") == 0) { s->group = (CharacterStatsWindow::StatGroup::Group)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "name") == 0) { s->name = luaL_checkstring(L, 3); return 0; }

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int StatGroupBinding::_DESTRUCTOR(lua_State* L)
{
    StatGroup* s = getS(L, 1);
    if (!s) return luaL_error(L, "StatGroup is nil");

    s->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 51: StatGroup* _CONSTRUCTOR(...) - overloaded method
  line 53: StatGroup* _CONSTRUCTOR(...) - overloaded method
  line 55: StatGroup* _CONSTRUCTOR(...) - overloaded method
*/

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
    registerClass(L, StatGroupBinding::getMetatableName(), meta, methods, StatGroupBinding::index, StatGroupBinding::newindex);
}

} // namespace KenshiLua