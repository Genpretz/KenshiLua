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
    static int _getBountyFaction(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
    static int getPercievedBounty(lua_State* L);
    static int getActualBounty(lua_State* L);
    static int notifyPlayerClaimBounty(lua_State* L);
    static int bountyAlreadyBeenClaimedByPlayer(lua_State* L);
    static int assignBountyForCrimes(lua_State* L);
    static int unfairAddToBounty(lua_State* L);
    static int clearBounty(lua_State* L);
    static int load(lua_State* L);
    static int save(lua_State* L);
    static int setCrime(lua_State* L);
    static int notifyCrimeWitnessed(lua_State* L);
    static int notifyStartPrisonSentence(lua_State* L);
    static int hasAccessPass(lua_State* L);
    static int giveAccessPass(lua_State* L);
    static int crimeToStr(lua_State* L);
    static int getBountyForCrime(lua_State* L);
    static int getPrisonSentenceInHours(lua_State* L);
    static int getBountyExpirationTime(lua_State* L);
};
}
