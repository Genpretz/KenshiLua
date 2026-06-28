#include "pch.h"
#include "kenshi\BountyManager.h"
#include "BountyManagerBinding.h"
#include "CharacterBinding.h"
#include "FactionBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/FactionBinding.h"

namespace KenshiLua
{

static BountyManager* getB(lua_State* L, int idx)
{
    return checkObject<BountyManager>(L, idx, BountyManagerBinding::getMetatableName());
}

// --- Getters for BountyManager ---
static int BountyManager_get_bounties(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    // TODO: Unsupported type for bounties (ogre_unordered_map<Faction*, Bounty>::type)
    return luaL_error(L, "Unsupported property 'bounties' (type: ogre_unordered_map<Faction*, Bounty>::type)");
}

static int BountyManager_get_me(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    return pushObject<Character>(L, b->me, CharacterBinding::getMetatableName());
}

static int BountyManager_get__hasAccessPass(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    return pushObject<Faction>(L, b->_hasAccessPass, FactionBinding::getMetatableName());
}

static int BountyManager_get_accessPassExpirationTime(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    // TODO: Unsupported type for accessPassExpirationTime (TimeOfDay)
    return luaL_error(L, "Unsupported property 'accessPassExpirationTime' (type: TimeOfDay)");
}

static int BountyManager_get_committingCrime(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    // TODO: Unsupported type for committingCrime (CrimeEnum)
    return luaL_error(L, "Unsupported property 'committingCrime' (type: CrimeEnum)");
}

static int BountyManager_get_crimeAgainstFaction(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    return pushObject<Faction>(L, b->crimeAgainstFaction, FactionBinding::getMetatableName());
}

static int BountyManager_get_usingTrainingEquipmentOf(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    return pushObject<Faction>(L, b->usingTrainingEquipmentOf, FactionBinding::getMetatableName());
}

static int BountyManager_get_crimeAgainst(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    // TODO: Unsupported type for crimeAgainst (hand)
    return luaL_error(L, "Unsupported property 'crimeAgainst' (type: hand)");
}

static int BountyManager_get_crimeExpiry(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    lua_pushnumber(L, b->crimeExpiry);
    return 1;
}

static int BountyManager_get_prisonSentenceBeganTime(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    // TODO: Unsupported type for prisonSentenceBeganTime (TimeOfDay)
    return luaL_error(L, "Unsupported property 'prisonSentenceBeganTime' (type: TimeOfDay)");
}

static int BountyManager_get_prisonSentenceToServe(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    lua_pushnumber(L, b->prisonSentenceToServe);
    return 1;
}

static int BountyManager_get__hadABountyAssignedForCurrentCrime(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    lua_pushboolean(L, b->_hadABountyAssignedForCurrentCrime ? 1 : 0);
    return 1;
}

// --- Setters for BountyManager ---
static int BountyManager_set_bounties(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    return luaL_error(L, "Read-only or unsupported setter type for bounties");
}

static int BountyManager_set_me(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    return luaL_error(L, "Read-only or unsupported setter type for me");
}

static int BountyManager_set__hasAccessPass(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    return luaL_error(L, "Read-only or unsupported setter type for _hasAccessPass");
}

static int BountyManager_set_accessPassExpirationTime(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    return luaL_error(L, "Read-only or unsupported setter type for accessPassExpirationTime");
}

static int BountyManager_set_committingCrime(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    return luaL_error(L, "Read-only or unsupported setter type for committingCrime");
}

static int BountyManager_set_crimeAgainstFaction(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    return luaL_error(L, "Read-only or unsupported setter type for crimeAgainstFaction");
}

static int BountyManager_set_usingTrainingEquipmentOf(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    return luaL_error(L, "Read-only or unsupported setter type for usingTrainingEquipmentOf");
}

static int BountyManager_set_crimeAgainst(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    return luaL_error(L, "Read-only or unsupported setter type for crimeAgainst");
}

static int BountyManager_set_crimeExpiry(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    b->crimeExpiry = (float)luaL_checknumber(L, 2);
    return 0;
}

static int BountyManager_set_prisonSentenceBeganTime(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    return luaL_error(L, "Read-only or unsupported setter type for prisonSentenceBeganTime");
}

static int BountyManager_set_prisonSentenceToServe(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    b->prisonSentenceToServe = (float)luaL_checknumber(L, 2);
    return 0;
}

static int BountyManager_set__hadABountyAssignedForCurrentCrime(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    b->_hadABountyAssignedForCurrentCrime = lua_toboolean(L, 2) != 0;
    return 0;
}

int BountyManagerBinding::_getHighestBountyFaction(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");

    Faction* result = b->_getHighestBountyFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int BountyManagerBinding::getBountyRecognitionThreshold(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");

    int result = b->getBountyRecognitionThreshold();
    lua_pushinteger(L, result);
    return 1;
}

int BountyManagerBinding::getTotalBounty(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");

    int result = b->getTotalBounty();
    lua_pushinteger(L, result);
    return 1;
}

int BountyManagerBinding::update(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");

    float frameTime = (float)luaL_checknumber(L, 2);
    b->update(frameTime);
    return 0;
}

int BountyManagerBinding::getBountyExpiryStringForGUI(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");

    std::string result = b->getBountyExpiryStringForGUI();
    lua_pushstring(L, result.c_str());
    return 1;
}

int BountyManagerBinding::notifyPossibleCrimeWitnessed(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");

    float time = (float)luaL_checknumber(L, 2);
    b->notifyPossibleCrimeWitnessed(time);
    return 0;
}

int BountyManagerBinding::isCommittingCrime(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");

    bool result = b->isCommittingCrime();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BountyManagerBinding::_DESTRUCTOR(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 18: Faction* _getBountyFaction(...) - unsupported arg type
  line 24: BountyManager* _CONSTRUCTOR(...) - unsupported arg type
  line 25: int getPercievedBounty(...) - unsupported arg type
  line 26: int getActualBounty(...) - unsupported arg type
  line 27: void notifyPlayerClaimBounty(...) - unsupported arg type
  line 28: bool bountyAlreadyBeenClaimedByPlayer(...) - unsupported arg type
  line 29: void assignBountyForCrimes(...) - unsupported arg type
  line 30: void unfairAddToBounty(...) - unsupported arg type
  line 32: void clearBounty(...) - unsupported arg type
  line 35: StringPair getGUIData(...) - unsupported return type
  line 36: void getGUIDataForAppend(...) - unsupported arg type
  line 38: void load(...) - unsupported arg type
  line 39: void save(...) - unsupported arg type
  line 40: bool setCrime(...) - unsupported arg type
  line 41: void notifyCrimeWitnessed(...) - unsupported arg type
  line 52: void notifyStartPrisonSentence(...) - unsupported arg type
  line 53: bool hasAccessPass(...) - unsupported arg type
  line 54: void giveAccessPass(...) - unsupported arg type
  line 55: std::string crimeToStr(...) - static method
  line 56: int getBountyForCrime(...) - static method
  line 57: int getPrisonSentenceInHours(...) - static method
  line 58: float getBountyExpirationTime(...) - static method
*/

int BountyManagerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int BountyManagerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.BountyManager object");
    return 1;
}

void BountyManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BountyManagerBinding::gc },
        { "__tostring", BountyManagerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_getHighestBountyFaction", BountyManagerBinding::_getHighestBountyFaction },
        { "getBountyRecognitionThreshold", BountyManagerBinding::getBountyRecognitionThreshold },
        { "getTotalBounty", BountyManagerBinding::getTotalBounty },
        { "update", BountyManagerBinding::update },
        { "getBountyExpiryStringForGUI", BountyManagerBinding::getBountyExpiryStringForGUI },
        { "notifyPossibleCrimeWitnessed", BountyManagerBinding::notifyPossibleCrimeWitnessed },
        { "isCommittingCrime", BountyManagerBinding::isCommittingCrime },
        { "_DESTRUCTOR", BountyManagerBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        BountyManagerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, BountyManagerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, BountyManager_get_bounties);
    lua_setfield(L, -2, "bounties");
    lua_pushcfunction(L, BountyManager_get_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, BountyManager_get__hasAccessPass);
    lua_setfield(L, -2, "_hasAccessPass");
    lua_pushcfunction(L, BountyManager_get_accessPassExpirationTime);
    lua_setfield(L, -2, "accessPassExpirationTime");
    lua_pushcfunction(L, BountyManager_get_committingCrime);
    lua_setfield(L, -2, "committingCrime");
    lua_pushcfunction(L, BountyManager_get_crimeAgainstFaction);
    lua_setfield(L, -2, "crimeAgainstFaction");
    lua_pushcfunction(L, BountyManager_get_usingTrainingEquipmentOf);
    lua_setfield(L, -2, "usingTrainingEquipmentOf");
    lua_pushcfunction(L, BountyManager_get_crimeAgainst);
    lua_setfield(L, -2, "crimeAgainst");
    lua_pushcfunction(L, BountyManager_get_crimeExpiry);
    lua_setfield(L, -2, "crimeExpiry");
    lua_pushcfunction(L, BountyManager_get_prisonSentenceBeganTime);
    lua_setfield(L, -2, "prisonSentenceBeganTime");
    lua_pushcfunction(L, BountyManager_get_prisonSentenceToServe);
    lua_setfield(L, -2, "prisonSentenceToServe");
    lua_pushcfunction(L, BountyManager_get__hadABountyAssignedForCurrentCrime);
    lua_setfield(L, -2, "_hadABountyAssignedForCurrentCrime");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, BountyManager_set_bounties);
    lua_setfield(L, -2, "bounties");
    lua_pushcfunction(L, BountyManager_set_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, BountyManager_set__hasAccessPass);
    lua_setfield(L, -2, "_hasAccessPass");
    lua_pushcfunction(L, BountyManager_set_accessPassExpirationTime);
    lua_setfield(L, -2, "accessPassExpirationTime");
    lua_pushcfunction(L, BountyManager_set_committingCrime);
    lua_setfield(L, -2, "committingCrime");
    lua_pushcfunction(L, BountyManager_set_crimeAgainstFaction);
    lua_setfield(L, -2, "crimeAgainstFaction");
    lua_pushcfunction(L, BountyManager_set_usingTrainingEquipmentOf);
    lua_setfield(L, -2, "usingTrainingEquipmentOf");
    lua_pushcfunction(L, BountyManager_set_crimeAgainst);
    lua_setfield(L, -2, "crimeAgainst");
    lua_pushcfunction(L, BountyManager_set_crimeExpiry);
    lua_setfield(L, -2, "crimeExpiry");
    lua_pushcfunction(L, BountyManager_set_prisonSentenceBeganTime);
    lua_setfield(L, -2, "prisonSentenceBeganTime");
    lua_pushcfunction(L, BountyManager_set_prisonSentenceToServe);
    lua_setfield(L, -2, "prisonSentenceToServe");
    lua_pushcfunction(L, BountyManager_set__hadABountyAssignedForCurrentCrime);
    lua_setfield(L, -2, "_hadABountyAssignedForCurrentCrime");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua