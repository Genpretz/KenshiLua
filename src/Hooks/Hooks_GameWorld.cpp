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

// Installed at startup for the world state script bridge, and also mapped to
// the "GameWorld::resetGame" Lua event.
static void (*GameWorld_resetGame_orig)(GameWorld* thisptr) = NULL;
static void GameWorld_resetGame_hook(GameWorld* thisptr)
{
    GameWorld_resetGame_orig(thisptr);
    KenshiLua::WorldStateScriptBridgeReset();
    CallGameWorldResetGameCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_GameWorld_resetGame,
    "GameWorld::resetGame",
    KenshiLib::GetRealAddress(&GameWorld::resetGame),
    GameWorld_resetGame_hook, GameWorld_resetGame_orig)

// The engine function body is empty; Kenshi calls it once per in-game day.
static void (*GameWorld_dailyUpdates_orig)(GameWorld* thisptr) = NULL;
static void GameWorld_dailyUpdates_hook(GameWorld* thisptr)
{
    GameWorld_dailyUpdates_orig(thisptr);
    CallGameWorldDailyUpdatesCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_GameWorld_dailyUpdates,
    "GameWorld::dailyUpdates",
    KenshiLib::GetRealAddress(&GameWorld::dailyUpdates),
    GameWorld_dailyUpdates_hook, GameWorld_dailyUpdates_orig)

static void (*GameWorld_initialiseNewGameWorld_orig)(GameWorld* thisptr, GameDataManager* datasrc) = NULL;
static void GameWorld_initialiseNewGameWorld_hook(GameWorld* thisptr, GameDataManager* datasrc)
{
    GameWorld_initialiseNewGameWorld_orig(thisptr, datasrc);
    CallGameWorldInitialiseNewGameWorldCallbacks(thisptr, datasrc);
}
DEFINE_HOOK_INSTALLER(InstallHook_GameWorld_initialiseNewGameWorld,
    "GameWorld::initialiseNewGameWorld",
    KenshiLib::GetRealAddress(&GameWorld::initialiseNewGameWorld),
    GameWorld_initialiseNewGameWorld_hook, GameWorld_initialiseNewGameWorld_orig)

// Handlers run before the original call so that obj is still valid.
static bool (*GameWorld_destroy_orig)(GameWorld* thisptr, RootObject* obj, bool justUnloaded, const char* debugInfo) = NULL;
static bool GameWorld_destroy_hook(GameWorld* thisptr, RootObject* obj, bool justUnloaded, const char* debugInfo)
{
    CallGameWorldDestroyCallbacks(thisptr, obj, justUnloaded, debugInfo);
    return GameWorld_destroy_orig(thisptr, obj, justUnloaded, debugInfo);
}
DEFINE_HOOK_INSTALLER(InstallHook_GameWorld_destroy,
    "GameWorld::destroy",
    KenshiLib::GetRealAddress(static_cast<bool (GameWorld::*)(RootObject*, bool, const char*)>(&GameWorld::destroy)),
    GameWorld_destroy_hook, GameWorld_destroy_orig)

static void (*GameWorld_userPause_orig)(GameWorld* thisptr, bool p) = NULL;
static void GameWorld_userPause_hook(GameWorld* thisptr, bool p)
{
    GameWorld_userPause_orig(thisptr, p);
    CallGameWorldUserPauseCallbacks(thisptr, p);
}
DEFINE_HOOK_INSTALLER(InstallHook_GameWorld_userPause,
    "GameWorld::userPause",
    KenshiLib::GetRealAddress(&GameWorld::userPause),
    GameWorld_userPause_hook, GameWorld_userPause_orig)

static void (*GameWorld_setGameSpeed_orig)(GameWorld* thisptr, float speed, bool click) = NULL;
static void GameWorld_setGameSpeed_hook(GameWorld* thisptr, float speed, bool click)
{
    GameWorld_setGameSpeed_orig(thisptr, speed, click);
    CallGameWorldSetGameSpeedCallbacks(thisptr, speed, click);
}
DEFINE_HOOK_INSTALLER(InstallHook_GameWorld_setGameSpeed,
    "GameWorld::setGameSpeed",
    KenshiLib::GetRealAddress(&GameWorld::setGameSpeed),
    GameWorld_setGameSpeed_hook, GameWorld_setGameSpeed_orig)

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
