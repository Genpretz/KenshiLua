#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class FactionManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.FactionManager"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int clearAndDestroy(lua_State* L);
    static int activateUnloadedPlatoons(lua_State* L);
    static int getFactionByName(lua_State* L);
    static int getFactionByStringID(lua_State* L);
    static int getEmptyFaction(lua_State* L);
    static int setupAndLinkAllFactions(lua_State* L);
    static int areAnyHostileCampaignsRunning(lua_State* L);
    static int getNumTempPlatoons(lua_State* L);
    static int updateMT(lua_State* L);
    static int updateThreaded(lua_State* L);
    static int _showDebugPlatoonMarkers(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}
