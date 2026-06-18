#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

class Platoon;

namespace KenshiLua
{
Platoon* getPlatoonFromLua(lua_State* L, int idx);

class PlatoonBinding
{
public:
    // Same metatable name handles both Platoon and ActivePlatoon wrappers.
    // We always store an ActivePlatoon* in the userdata; if you push a raw
    // Platoon*, callers will use the Platoon -> ActivePlatoon mapping.
    static const char* getMetatableName() { return "KenshiLua.Platoon"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int isValid(lua_State* L);
    static int getName(lua_State* L);
    static int getSquadSize(lua_State* L);
    static int getCharacterCount(lua_State* L);
    static int getSquadLeader(lua_State* L);
    static int getFaction(lua_State* L);
    static int isPersistentSquad(lua_State* L);
    static int setPersistent(lua_State* L);
    static int isLoaded(lua_State* L);
    static int isTrader(lua_State* L);
    static int teleport(lua_State* L);
    static int activate(lua_State* L);
    static int deactivate(lua_State* L);
    static int declareDead(lua_State* L);
    static int undeclareDead(lua_State* L);
    static int isFullyLoaded(lua_State* L);
    static int setupPatrolSettings(lua_State* L);
    static int swapCharacters(lua_State* L);
    static int clearAllTheUniqueNPCStates(lua_State* L);
    static int refreshInventory(lua_State* L);
};
}
