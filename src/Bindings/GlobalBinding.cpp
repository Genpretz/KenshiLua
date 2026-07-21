#include "pch.h"
#include "Bindings/GlobalBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/GameWorldBinding.h"
#include "Bindings/PlayerInterfaceBinding.h"
#include "Bindings/InputHandlerBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/RootObjectFactoryBinding.h"
#include "Bindings/GlobalConstantsBinding.h"
#include "Bindings/OptionsHolderBinding.h"
#include "Bindings/Gui/ForgottenGUIBinding.h"
#include <kenshi/RootObjectFactory.h>
#include <kenshi/GlobalConstants.h>
#include <kenshi/OptionsHolder.h>
#include <kenshi/gui/ForgottenGUI.h>

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

    static int luaGetPlayerInterface(lua_State* L)
    {
        if (::ou && ::ou->player) {
            pushObject<PlayerInterface>(L, ::ou->player, PlayerInterfaceBinding::getMetatableName());
        } else {
            lua_pushnil(L);
        }
        return 1;
    }

    static int luaGetInputHandler(lua_State* L)
    {
        if (::key) {
            pushObject<InputHandler>(L, ::key, InputHandlerBinding::getMetatableName());
        } else {
            lua_pushnil(L);
        }
        return 1;
    }

    static int luaGetSelectedCharacter(lua_State* L)
    {
        if (::ou && ::ou->player && ::ou->player->selectedCharacter.getCharacter()) {
            pushObject<Character>(L, ::ou->player->selectedCharacter.getCharacter(), CharacterBinding::getMetatableName());
        } else {
            lua_pushnil(L);
        }
        return 1;
    }

    static int luaGetRootObjectFactory(lua_State* L)
    {
        if (::ou && ::ou->theFactory) {
            pushObject<RootObjectFactory>(L, ::ou->theFactory, RootObjectFactoryBinding::getMetatableName());
        } else {
            lua_pushnil(L);
        }
        return 1;
    }

    static int luaGetGlobalConstants(lua_State* L)
    {
        if (::con) {
            pushObject<GlobalConstants>(L, ::con, GlobalConstantsBinding::getMetatableName());
        } else {
            lua_pushnil(L);
        }
        return 1;
    }

    static int luaGetOptionsHolder(lua_State* L)
    {
        if (::options) {
            pushObject<OptionsHolder>(L, ::options, OptionsHolderBinding::getMetatableName());
        } else {
            lua_pushnil(L);
        }
        return 1;
    }

    static int luaGetForgottenGUI(lua_State* L)
    {
        if (::gui) {
            pushObject<ForgottenGUI>(L, ::gui, ForgottenGUIBinding::getMetatableName());
        } else {
            lua_pushnil(L);
        }
        return 1;
    }

    void registerGlobals(lua_State* L)
    {
        lua_pushcfunction(L, luaGetGameWorld);
        lua_setglobal(L, "getGameWorld");
        lua_pushcfunction(L, luaGetPlayerInterface);
        lua_setglobal(L, "getPlayerInterface");
        lua_pushcfunction(L, luaGetInputHandler);
        lua_setglobal(L, "getInputHandler");
        lua_pushcfunction(L, luaGetSelectedCharacter);
        lua_setglobal(L, "getSelectedCharacter");
        lua_pushcfunction(L, luaGetRootObjectFactory);
        lua_setglobal(L, "getRootObjectFactory");
        lua_pushcfunction(L, luaGetGlobalConstants);
        lua_setglobal(L, "getGlobalConstants");
        lua_pushcfunction(L, luaGetOptionsHolder);
        lua_setglobal(L, "getOptionsHolder");
        lua_pushcfunction(L, luaGetForgottenGUI);
        lua_setglobal(L, "getForgottenGUI");

        // GameWorld
        if (::ou) {
            pushObject<GameWorld>(L, ::ou, GameWorldBinding::getMetatableName());
            lua_setglobal(L, "ou");
            pushObject<GameWorld>(L, ::ou, GameWorldBinding::getMetatableName());
            lua_setglobal(L, "GameWorld");
        }

        // PlayerInterface
        if (::ou && ::ou->player) {
            pushObject<PlayerInterface>(L, ::ou->player, PlayerInterfaceBinding::getMetatableName());
            lua_setglobal(L, "player");
            pushObject<PlayerInterface>(L, ::ou->player, PlayerInterfaceBinding::getMetatableName());
            lua_setglobal(L, "PlayerInterface");
        }

        // InputHandler
        if (::key) {
            pushObject<InputHandler>(L, ::key, InputHandlerBinding::getMetatableName());
            lua_setglobal(L, "key");
            pushObject<InputHandler>(L, ::key, InputHandlerBinding::getMetatableName());
            lua_setglobal(L, "InputHandler");
        }

        // RootObjectFactory
        if (::ou && ::ou->theFactory) {
            pushObject<RootObjectFactory>(L, ::ou->theFactory, RootObjectFactoryBinding::getMetatableName());
            lua_setglobal(L, "root");
            // pushObject<RootObjectFactory>(L, ::ou->theFactory, RootObjectFactoryBinding::getMetatableName());
            // lua_setglobal(L, "RootObjectFactory");
        }

        // GlobalConstants
        if (::con)     { 
            pushObject<GlobalConstants>(L, ::con, GlobalConstantsBinding::getMetatableName()); 
            lua_setglobal(L, "con"); 
            pushObject<GlobalConstants>(L, ::con, GlobalConstantsBinding::getMetatableName()); 
            lua_setglobal(L, "GlobalConstants");
        }

        // OptionsHolder
        if (::options) { 
            pushObject<OptionsHolder>(L, ::options, OptionsHolderBinding::getMetatableName()); 
            lua_setglobal(L, "options"); 
            pushObject<OptionsHolder>(L, ::options, OptionsHolderBinding::getMetatableName()); 
            lua_setglobal(L, "OptionsHolder"); 
        }

        // ForgottenGUI
        if (::gui)     { 
            pushObject<ForgottenGUI>(L, ::gui, ForgottenGUIBinding::getMetatableName()); 
            lua_setglobal(L, "gui"); 
            pushObject<ForgottenGUI>(L, ::gui, ForgottenGUIBinding::getMetatableName()); 
            lua_setglobal(L, "ForgottenGUI");
        }
    }

} // namespace KenshiLua
