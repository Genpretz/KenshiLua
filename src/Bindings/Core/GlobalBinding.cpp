#include "pch.h"
#include "Bindings/Core/GlobalBinding.h"
#include "Bindings/Character/CharacterBinding.h"
#include "Bindings/World/GameWorldBinding.h"
#include "Bindings/Core/PlayerInterfaceBinding.h"
#include "Bindings/Core/InputHandlerBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Globals.h>
#include <kenshi/GameWorld.h>
#include <kenshi/PlayerInterface.h>
#include <kenshi/InputHandler.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

static int luaGetGameWorld(lua_State* L)
{
    if (::ou) {
        pushObject<GameWorld>(L, ::ou, GameWorldBinding::getMetatableName());
    } else {
        lua_pushnil(L);
    }
    return 1;
}
//static int luaGetPlayerInterface(lua_State* L)
//{
//    if (::ou && ::ou->player) {
//        pushObject<PlayerInterface>(L, ::ou->player, PlayerInterfaceBinding::getMetatableName());
//    } else {
//        lua_pushnil(L);
//    }
//    return 1;
//}
//static int luaGetInputHandler(lua_State* L)
//{
//    if (::key) {
//        pushObject<InputHandler>(L, ::key, InputHandlerBinding::getMetatableName());
//    } else {
//        lua_pushnil(L);
//    }
//    return 1;
//}
//
//static int luaGetSelectedCharacter(lua_State* L)
//{
//    if (::ou && ::ou->player && ::ou->player->selectedCharacter.getCharacter()) {
//        pushObject<Character>(L, ::ou->player->selectedCharacter.getCharacter(), CharacterBinding::getMetatableName());
//    } else {
//        lua_pushnil(L);
//    }
//    return 1;
//}

void registerGlobals(lua_State* L)
{
    // getGameWorld global function
    lua_pushcfunction(L, luaGetGameWorld);
    lua_setglobal(L, "getGameWorld");
    //lua_pushcfunction(L, luaGetPlayerInterface);
    //lua_setglobal(L, "getPlayerInterface");
    //lua_pushcfunction(L, luaGetInputHandler);
    //lua_setglobal(L, "getInputHandler");
    //lua_pushcfunction(L, luaGetSelectedCharacter);
    //lua_setglobal(L, "getSelectedCharacter");

    // GameWorld
    if (::ou) {
        pushObject<GameWorld>(L, ::ou, GameWorldBinding::getMetatableName());
        lua_setglobal(L, "ou");
        // Also expose under the conventional name `GameWorld` so docs match.
        pushObject<GameWorld>(L, ::ou, GameWorldBinding::getMetatableName());
        lua_setglobal(L, "GameWorld");
    }

    // PlayerInterface
    if (::ou && ::ou->player) {
        pushObject<PlayerInterface>(L, ::ou->player, PlayerInterfaceBinding::getMetatableName());
        lua_setglobal(L, "player");
        //pushObject<PlayerInterface>(L, ::ou->player, PlayerInterfaceBinding::getMetatableName());
        //lua_setglobal(L, "PlayerInterface");
    }

    // InputHandler
    if (::key) {
        pushObject<InputHandler>(L, ::key, InputHandlerBinding::getMetatableName());
        lua_setglobal(L, "key");
        //pushObject<InputHandler>(L, ::key, InputHandlerBinding::getMetatableName());
        //lua_setglobal(L, "InputHandler");
    }

    // The remaining engine singletons don't have dedicated bindings yet;
    // expose them as lightuserdata for advanced scripts that know the ABI.
    if (::con)     { lua_pushlightuserdata(L, (void*)::con);     lua_setglobal(L, "con"); }
    if (::options) { lua_pushlightuserdata(L, (void*)::options); lua_setglobal(L, "options"); }
    if (::gui)     { lua_pushlightuserdata(L, (void*)::gui);     lua_setglobal(L, "gui"); }
}

} // namespace KenshiLua