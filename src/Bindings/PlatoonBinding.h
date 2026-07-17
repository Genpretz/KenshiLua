#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class PlatoonBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Platoon"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int setCharacterCount(lua_State* L);
    static int isUnconcious(lua_State* L);
    static int _NV_isUnconcious(lua_State* L);
    static int getSquadType(lua_State* L);
    static int setSquadType(lua_State* L);
    static int iBuyIllegalGoods(lua_State* L);
    static int getPlatoonStringID(lua_State* L);
    static int getDataType(lua_State* L);
    static int _NV_getDataType(lua_State* L);
    static int erasePlatoonFile(lua_State* L);
    static int showDebugMarker(lua_State* L);
    static int setDataFilename(lua_State* L);
    static int isIntact(lua_State* L);
    static int notifyMissionEnded(lua_State* L);
    static int _NV_notifyMissionEnded(lua_State* L);
    static int activate(lua_State* L);
    static int declareDead(lua_State* L);
    static int undeclareDead(lua_State* L);
    static int isFullyLoaded(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int periodicUpdate_active(lua_State* L);
    static int _NV_periodicUpdate_active(lua_State* L);
    static int periodicUpdate_unloaded(lua_State* L);
    static int _NV_periodicUpdate_unloaded(lua_State* L);
    static int setupPatrolSettings(lua_State* L);
    static int isPersistentSquad(lua_State* L);
    static int setPersistentSquad(lua_State* L);
    static int getOwnerships(lua_State* L);
    static int _NV_getOwnerships(lua_State* L);
    static int getNearestActiveCharacter(lua_State* L);
    static int getSquadLeader(lua_State* L);
    static int getCharacterCount(lua_State* L);
    static int getCharacterCount_Original(lua_State* L);
    static int needsNewCharacters(lua_State* L);
    static int reCheckPersistenceOnUnload(lua_State* L);
    static int _NV_reCheckPersistenceOnUnload(lua_State* L);
};
}