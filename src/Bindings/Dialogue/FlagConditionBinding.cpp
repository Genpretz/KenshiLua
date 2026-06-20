#include "pch.h"
#include "Bindings/Dialogue/FlagConditionBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Dialogue.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static FlagCondition* getS(lua_State* L, int idx)
{
    return checkObject<FlagCondition>(L, idx, FlagConditionBinding::getMetatableName());
}

int FlagConditionBinding::gc(lua_State* L) { return noopGc(L); }

int FlagConditionBinding::tostring(lua_State* L)
{
    FlagCondition* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int FlagConditionBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, FlagConditionBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    FlagCondition* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    // TODO DialogConditionEnum key; unsupported __index type from header line 171
    if (strcmp(key, "want") == 0) { lua_pushboolean(L, s->want ? 1 : 0); return 1; }
    if (strcmp(key, "flags") == 0) { lua_pushinteger(L, s->flags); return 1; }

    lua_pushnil(L);
    return 1;
}

int FlagConditionBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    FlagCondition* s = getS(L, 1);
    if (!s) return luaL_error(L, "FlagCondition is nil");

    // TODO DialogConditionEnum key; unsupported __newindex type from header line 171
    if (strcmp(key, "want") == 0) { s->want = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "flags") == 0) { s->flags = (unsigned int)luaL_checkinteger(L, 3); return 0; }

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

void FlagConditionBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FlagConditionBinding::gc },
        { "__tostring", FlagConditionBinding::tostring },
        { "__index",    FlagConditionBinding::index },
        { "__newindex", FlagConditionBinding::newindex },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { 0, 0 }
    };
    registerClass(L, FlagConditionBinding::getMetatableName(), meta, methods);
}

} // namespace KenshiLua