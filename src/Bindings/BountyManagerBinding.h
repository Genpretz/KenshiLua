#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class BountyManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.BountyManager"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _getHighestBountyFaction(lua_State* L);
    static int getBountyRecognitionThreshold(lua_State* L);
    static int getTotalBounty(lua_State* L);
    static int update(lua_State* L);
    static int getBountyExpiryStringForGUI(lua_State* L);
    static int notifyPossibleCrimeWitnessed(lua_State* L);
    static int isCommittingCrime(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}