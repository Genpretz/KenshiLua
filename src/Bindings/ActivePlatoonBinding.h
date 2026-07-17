#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ActivePlatoonBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ActivePlatoon"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _recalculateIsIntact(lua_State* L);
    static int isAnyoneCaptured(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int swapCharacters(lua_State* L);
    static int emptySquadCheck(lua_State* L);
    static int clearAllTheUniqueNPCStates(lua_State* L);
    static int isIntact(lua_State* L);
    static int getSquadLeader_theRealOne(lua_State* L);
    static int getNearestActiveCharacter(lua_State* L);
    static int getSquadLeader(lua_State* L);
    static int getSquadSize(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int refreshInventory(lua_State* L);
    static int _forceRefreshInventory(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int _NV_periodicUpdate(lua_State* L);
    static int serialiseEverythingToDisk(lua_State* L);
    static int isWholeSquadDown(lua_State* L);
    static int setDataFilename(lua_State* L);
    static int setupLeaderDialogues(lua_State* L);
    static int isLoaded(lua_State* L);
    static int teleport(lua_State* L);
    static int setName(lua_State* L);
    static int getIsTrader(lua_State* L);
    static int getHasVendorList(lua_State* L);
    static int getHasSpecialItemsList(lua_State* L);
    static int setupTraderBuildings(lua_State* L);
    static int putTheSpecialCharactersInNewSquads_captured(lua_State* L);
    static int checkForCharactersBeingCarried(lua_State* L);
    static int restoreSquad(lua_State* L);
    static int unloadCheck(lua_State* L);
    static int destroyCharacters(lua_State* L);
    static int serialiseCharacterData(lua_State* L);
    static int saveToDisk(lua_State* L);
    static int calculateCurrentPos(lua_State* L);
    static int _checkForUniqueCharactersOnUnload(lua_State* L);
};
}