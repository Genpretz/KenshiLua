#include "pch.h"
#include "Bindings/Dialogue/DialogActionBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Dialogue.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static DialogAction* getS(lua_State* L, int idx)
{
    return checkObject<DialogAction>(L, idx, DialogActionBinding::getMetatableName());
}

int DialogActionBinding::gc(lua_State* L) { return noopGc(L); }

int DialogActionBinding::tostring(lua_State* L)
{
    DialogAction* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int DialogActionBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, DialogActionBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    DialogAction* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    // TODO DialogActionEnum key; unsupported __index type from header line 156
    if (strcmp(key, "value") == 0) { lua_pushinteger(L, s->value); return 1; }

    lua_pushnil(L);
    return 1;
}

int DialogActionBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    DialogAction* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogAction is nil");

    // TODO DialogActionEnum key; unsupported __newindex type from header line 156
    if (strcmp(key, "value") == 0) { s->value = (int)luaL_checkinteger(L, 3); return 0; }

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

void DialogActionBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DialogActionBinding::gc },
        { "__tostring", DialogActionBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { 0, 0 }
    };
    registerClass(L, DialogActionBinding::getMetatableName(), meta, methods, DialogActionBinding::index, DialogActionBinding::newindex);
}

} // namespace KenshiLua