#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class GameWorldBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.GameWorld"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int startUpThreads(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int resetGame(lua_State* L);
    static int _clearAndDestroyGameWorldStuff(lua_State* L);
    static int initialisation(lua_State* L);
    static int initialisationGameData(lua_State* L);
    static int dailyUpdates(lua_State* L);
    static int errorToLogReleaseMode(lua_State* L);
    static int errorD(lua_State* L);
    static int logToSave(lua_State* L);
    static int log(lua_State* L);
    static int flushKillList(lua_State* L);
    static int allThreadQueuesAreClear(lua_State* L);
    static int initBaseMods(lua_State* L);
    static int initModsList(lua_State* L);
    static int getModIndex(lua_State* L);
    static int getLightLevel(lua_State* L);
    static int findValidSpawnPos(lua_State* L);
    static int togglePause(lua_State* L);
    static int getFrameSpeedMultiplier(lua_State* L);
    static int setFrameSpeedMultiplier(lua_State* L);
    static int setGameSpeed(lua_State* L);
    static int userPause(lua_State* L);
    static int isPaused(lua_State* L);
    static int getCameraCenter(lua_State* L);
    static int getCameraPos(lua_State* L);
    static int fixNaNPosition(lua_State* L);
    static int getWindSpeed(lua_State* L);
    static int isLoadingFromASaveGame(lua_State* L);
    static int hideContextMenu(lua_State* L);
    static int showPlayerAMessage_withLog(lua_State* L);
    static int showPlayerAMessage(lua_State* L);
    static int showPlayerAMessageD(lua_State* L);
    static int mainLoop_GPUSensitiveStuff(lua_State* L);
    static int _NV_mainLoop_GPUSensitiveStuff(lua_State* L);
    static int clearPortaitsUpdate(lua_State* L);
    static int processSysMessages(lua_State* L);
    static int destroyDeathParade(lua_State* L);
    static int processKeys(lua_State* L);
    static int processThreadMessages(lua_State* L);
    static int charsUpdate(lua_State* L);
    static int charsUpdateUT(lua_State* L);
    static int charsUpdatePaused(lua_State* L);
    static int charsUpdateDeathParade(lua_State* L);
    static int threadSafeRagdollUpdates(lua_State* L);
    static int processAttachmentsKillList(lua_State* L);
    static int processKillList(lua_State* L);
    static int processUpdateRemovalList(lua_State* L);
    static int loadAllPlatoons(lua_State* L);
    static int reCalculateFortificationInsideOutsideStateForAllCharacters(lua_State* L);
    static int getTimeStamp(lua_State* L);
    static int getTimeFromStamp_inGameHours(lua_State* L);
    static int getLengthOfHourInRealSeconds(lua_State* L);
};
}
