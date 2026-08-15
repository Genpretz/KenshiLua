#include "pch.h"
#include "kenshi\GameData.h"
#include "GameDataCopyStandaloneBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{

static GameDataCopyStandalone* getInstance(lua_State* L, int idx)
{
    return checkObject<GameDataCopyStandalone>(L, idx, GameDataCopyStandaloneBinding::getMetatableName());
}

// --- Getters for GameDataCopyStandalone ---
// --- Setters for GameDataCopyStandalone ---
int GameDataCopyStandaloneBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int GameDataCopyStandaloneBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.GameDataCopyStandalone object");
    return 1;
}

void GameDataCopyStandaloneBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GameDataCopyStandaloneBinding::gc },
        { "__tostring", GameDataCopyStandaloneBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        GameDataCopyStandaloneBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GameDataCopyStandaloneBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, GameDataCopyStandaloneBinding::getMetatableName(), GameDataBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua