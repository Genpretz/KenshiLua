#include "pch.h"
class CraftingItem {};
#include <kenshi/Building/CraftingBuilding.h>
#include "GameDataGroupBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{

static GameDataGroup* getInstance(lua_State* L, int idx)
{
    return checkObject<GameDataGroup>(L, idx, GameDataGroupBinding::getMetatableName());
}

// --- Getters for GameDataGroup ---
static int GameDataGroup_get_g1(lua_State* L)
{
    GameDataGroup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataGroup is nil");
    return pushObject<GameData>(L, instance->g1, GameDataBinding::getMetatableName());
}

static int GameDataGroup_get_g2(lua_State* L)
{
    GameDataGroup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataGroup is nil");
    return pushObject<GameData>(L, instance->g2, GameDataBinding::getMetatableName());
}

// --- Setters for GameDataGroup ---
static int GameDataGroup_set_g1(lua_State* L)
{
    GameDataGroup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataGroup is nil");
    return luaL_error(L, "Read-only or unsupported setter type for g1");
}

static int GameDataGroup_set_g2(lua_State* L)
{
    GameDataGroup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataGroup is nil");
    return luaL_error(L, "Read-only or unsupported setter type for g2");
}

int GameDataGroupBinding::_CONSTRUCTOR(lua_State* L)
{
    GameDataGroup* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataGroup is nil");

    GameDataGroup* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int GameDataGroupBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int GameDataGroupBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.GameDataGroup object");
    return 1;
}

void GameDataGroupBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GameDataGroupBinding::gc },
        { "__tostring", GameDataGroupBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", GameDataGroupBinding::_CONSTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        GameDataGroupBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GameDataGroupBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, GameDataGroup_get_g1);
    lua_setfield(L, -2, "g1");
    lua_pushcfunction(L, GameDataGroup_get_g2);
    lua_setfield(L, -2, "g2");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, GameDataGroup_set_g1);
    lua_setfield(L, -2, "g1");
    lua_pushcfunction(L, GameDataGroup_set_g2);
    lua_setfield(L, -2, "g2");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua