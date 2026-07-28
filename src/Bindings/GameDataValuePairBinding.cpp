#include "pch.h"
#include "kenshi\dialogue.h"
#include "GameDataValuePairBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{

static GameDataValuePair* getInstance(lua_State* L, int idx)
{
    return checkObject<GameDataValuePair>(L, idx, GameDataValuePairBinding::getMetatableName());
}

// --- Getters for GameDataValuePair ---
static int GameDataValuePair_get_data(lua_State* L)
{
    GameDataValuePair* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataValuePair is nil");
    return pushObject<GameData>(L, instance->data, GameDataBinding::getMetatableName());
}

static int GameDataValuePair_get_val0(lua_State* L)
{
    GameDataValuePair* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataValuePair is nil");
    lua_pushinteger(L, instance->val0);
    return 1;
}

// --- Setters for GameDataValuePair ---
static int GameDataValuePair_set_data(lua_State* L)
{
    GameDataValuePair* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataValuePair is nil");
    instance->data = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int GameDataValuePair_set_val0(lua_State* L)
{
    GameDataValuePair* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataValuePair is nil");
    instance->val0 = (int)luaL_checkinteger(L, 2);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 142: GameDataValuePair* _CONSTRUCTOR(...) - overloaded method
  line 144: GameDataValuePair* _CONSTRUCTOR(...) - overloaded method
*/

int GameDataValuePairBinding::_CONSTRUCTOR(lua_State* L)
{
    GameDataValuePair* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataValuePair is nil");

    if (lua_gettop(L) >= 3) {
        GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
        int v = (int)luaL_checkinteger(L, 3);
        GameDataValuePair* result = instance->_CONSTRUCTOR(d, v);
        return pushObject<GameDataValuePair>(L, result, GameDataValuePairBinding::getMetatableName());
    } else {
        GameDataValuePair* result = instance->_CONSTRUCTOR();
        return pushObject<GameDataValuePair>(L, result, GameDataValuePairBinding::getMetatableName());
    }
}

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
        { "_CONSTRUCTOR", GameDataValuePairBinding::_CONSTRUCTOR },
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
    registerGetter(L, "data", GameDataValuePair_get_data);
    registerGetter(L, "val0", GameDataValuePair_get_val0);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "data", GameDataValuePair_set_data);
    registerSetter(L, "val0", GameDataValuePair_set_val0);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua