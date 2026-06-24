#include "pch.h"
#include "kenshi\Dialogue.h"
#include "GameDataValuePairBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static GameDataValuePair* getB(lua_State* L, int idx)
{
    return checkObject<GameDataValuePair>(L, idx, GameDataValuePairBinding::getMetatableName());
}

// --- Getters for GameDataValuePair ---
static int GameDataValuePair_get_data(lua_State* L)
{
    GameDataValuePair* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataValuePair is nil");
    return pushObject<GameData>(L, b->data, GameDataBinding::getMetatableName());
}

static int GameDataValuePair_get_val0(lua_State* L)
{
    GameDataValuePair* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataValuePair is nil");
    lua_pushinteger(L, b->val0);
    return 1;
}

// --- Setters for GameDataValuePair ---
static int GameDataValuePair_set_data(lua_State* L)
{
    GameDataValuePair* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataValuePair is nil");
    return luaL_error(L, "Read-only or unsupported setter type for data");
}

static int GameDataValuePair_set_val0(lua_State* L)
{
    GameDataValuePair* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataValuePair is nil");
    b->val0 = (int)luaL_checkinteger(L, 2);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 142: GameDataValuePair* _CONSTRUCTOR(...) - overloaded method
  line 144: GameDataValuePair* _CONSTRUCTOR(...) - overloaded method
*/

int GameDataValuePairBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int GameDataValuePairBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.GameDataValuePair object");
    return 1;
}

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

    registerClass(
        L, 
        GameDataValuePairBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GameDataValuePairBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, GameDataValuePair_get_data);
    lua_setfield(L, -2, "data");
    lua_pushcfunction(L, GameDataValuePair_get_val0);
    lua_setfield(L, -2, "val0");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, GameDataValuePair_set_data);
    lua_setfield(L, -2, "data");
    lua_pushcfunction(L, GameDataValuePair_set_val0);
    lua_setfield(L, -2, "val0");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua