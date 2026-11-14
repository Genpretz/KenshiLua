#include "pch.h"
#include "Hooks_Common.h"

// ---------------------------------------------------------------------------
// Hooks for GameWorld.h
// ---------------------------------------------------------------------------

static void (*GameWorld_charsUpdate_orig)(GameWorld* thisptr) = NULL;
static void GameWorld_charsUpdate_hook(GameWorld* thisptr)
{
    GameWorld_charsUpdate_orig(thisptr);
    KenshiLua::WorldStateScriptBridgeUpdate();
    CallCharsUpdateCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_GameWorld_CharsUpdate,
    "GameWorld::charsUpdate",
    KenshiLib::GetRealAddress(&GameWorld::charsUpdate),
    GameWorld_charsUpdate_hook, GameWorld_charsUpdate_orig)

// Not a Lua event; installed at startup for the world state script bridge.
static void (*GameWorld_resetGame_orig)(GameWorld* thisptr) = NULL;
static void GameWorld_resetGame_hook(GameWorld* thisptr)
{
    GameWorld_resetGame_orig(thisptr);
    KenshiLua::WorldStateScriptBridgeReset();
}
DEFINE_HOOK_INSTALLER(InstallHook_GameWorld_resetGame,
    "GameWorld::resetGame",
    KenshiLib::GetRealAddress(&GameWorld::resetGame),
    GameWorld_resetGame_hook, GameWorld_resetGame_orig)

static GameWorld* (*GameWorld_CONSTRUCTOR_orig)(GameWorld*) = NULL;
static GameWorld* GameWorld_CONSTRUCTOR_hook(GameWorld* thisptr)
{
    GameWorld* res = GameWorld_CONSTRUCTOR_orig(thisptr);
    GameWorld* overrideRes = CallGameWorldConstructedCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_GameWorld_CONSTRUCTOR,
    "GameWorld::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&GameWorld::_CONSTRUCTOR),
    GameWorld_CONSTRUCTOR_hook, GameWorld_CONSTRUCTOR_orig)
