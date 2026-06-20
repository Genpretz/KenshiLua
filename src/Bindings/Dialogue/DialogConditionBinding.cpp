#include "pch.h"
#include "Bindings/Dialogue/DialogConditionBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Dialogue.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static DialogCondition* getS(lua_State* L, int idx)
{
    return checkObject<DialogCondition>(L, idx, DialogConditionBinding::getMetatableName());
}

int DialogConditionBinding::gc(lua_State* L) { return noopGc(L); }

int DialogConditionBinding::tostring(lua_State* L)
{
    DialogCondition* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int DialogConditionBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, DialogConditionBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    DialogCondition* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    // TODO DialogConditionEnum key; unsupported __index type from header line 162
    // TODO ComparisonEnum compareBy; unsupported __index type from header line 163
    // TODO TalkerEnum who; unsupported __index type from header line 164
    if (strcmp(key, "value") == 0) { lua_pushinteger(L, s->value); return 1; }

    lua_pushnil(L);
    return 1;
}

int DialogConditionBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    DialogCondition* s = getS(L, 1);
    if (!s) return luaL_error(L, "DialogCondition is nil");

    // TODO DialogConditionEnum key; unsupported __newindex type from header line 162
    // TODO ComparisonEnum compareBy; unsupported __newindex type from header line 163
    // TODO TalkerEnum who; unsupported __newindex type from header line 164
    if (strcmp(key, "value") == 0) { s->value = (int)luaL_checkinteger(L, 3); return 0; }

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

void DialogConditionBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DialogConditionBinding::gc },
        { "__tostring", DialogConditionBinding::tostring },
        { "__index",    DialogConditionBinding::index },
        { "__newindex", DialogConditionBinding::newindex },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { 0, 0 }
    };
    registerClass(L, DialogConditionBinding::getMetatableName(), meta, methods);
}

} // namespace KenshiLua