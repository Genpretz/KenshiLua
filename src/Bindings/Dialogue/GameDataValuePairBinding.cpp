#include "pch.h"
#include "Bindings/Dialogue/GameDataValuePairBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Dialogue.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static GameDataValuePair* getS(lua_State* L, int idx)
{
    return checkObject<GameDataValuePair>(L, idx, GameDataValuePairBinding::getMetatableName());
}

int GameDataValuePairBinding::gc(lua_State* L) { return noopGc(L); }

int GameDataValuePairBinding::tostring(lua_State* L)
{
    GameDataValuePair* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int GameDataValuePairBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, GameDataValuePairBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    GameDataValuePair* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "data") == 0) { return pushObject<GameData>(L, s->data, GameDataBinding::getMetatableName()); }
    if (strcmp(key, "val0") == 0) { lua_pushinteger(L, s->val0); return 1; }

    lua_pushnil(L);
    return 1;
}

int GameDataValuePairBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    GameDataValuePair* s = getS(L, 1);
    if (!s) return luaL_error(L, "GameDataValuePair is nil");

    // TODO GameData* data; unsupported __newindex type from header line 145
    if (strcmp(key, "val0") == 0) { s->val0 = (int)luaL_checkinteger(L, 3); return 0; }

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

/*
Skipped methods needing manual binding:
  line 142: GameDataValuePair* _CONSTRUCTOR(...) - overloaded method
  line 144: GameDataValuePair* _CONSTRUCTOR(...) - overloaded method
*/

void GameDataValuePairBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GameDataValuePairBinding::gc },
        { "__tostring", GameDataValuePairBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { 0, 0 }
    };
    registerClass(L, GameDataValuePairBinding::getMetatableName(), meta, methods, GameDataValuePairBinding::index, GameDataValuePairBinding::newindex);
}

} // namespace KenshiLua