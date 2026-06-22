#include "pch.h"
#include "Bindings/Dialogue/DialogStateBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Dialogue.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static DialogState* getS(lua_State* L, int idx)
{
    return checkObject<DialogState>(L, idx, DialogStateBinding::getMetatableName());
}

int DialogStateBinding::gc(lua_State* L) { return noopGc(L); }

int DialogStateBinding::tostring(lua_State* L)
{
    DialogState* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int DialogStateBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, DialogStateBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    DialogState* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "count") == 0) { lua_pushinteger(L, s->count); return 1; }
    if (strcmp(key, "lastTimeStamp") == 0) { lua_pushnumber(L, s->lastTimeStamp); return 1; }
    if (strcmp(key, "resetTime") == 0) { lua_pushnumber(L, s->resetTime); return 1; }

    lua_pushnil(L);
    return 1;
}

int DialogStateBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    DialogState* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogState is nil");

    if (strcmp(key, "count") == 0) { s->count = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "lastTimeStamp") == 0) { s->lastTimeStamp = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "resetTime") == 0) { s->resetTime = (float)luaL_checknumber(L, 3); return 0; }

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

/*
Skipped methods needing manual binding:
  line 290: DialogState* _CONSTRUCTOR(...) - unsupported return type
*/

void DialogStateBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DialogStateBinding::gc },
        { "__tostring", DialogStateBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { 0, 0 }
    };
    registerClass(L, DialogStateBinding::getMetatableName(), meta, methods, DialogStateBinding::index, DialogStateBinding::newindex);
}

} // namespace KenshiLua