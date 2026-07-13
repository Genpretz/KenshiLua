#include "pch.h"
#include "kenshi\BountyManager.h"
#include "BountyManagerBinding.h"
#include "CharacterBinding.h"
#include "FactionBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/BountyBinding.h"
#include "Bindings/Templates/OgreUnorderedBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{

template <>
struct LuaCodec<Bounty>
{
    static void push(lua_State* L, const Bounty& val, const char* meta)
    {
        pushObject<Bounty>(L, const_cast<Bounty*>(&val), meta);
    }

    static Bounty read(lua_State* L, int idx, const char* meta)
    {
        Bounty* b = checkObject<Bounty>(L, idx, meta);
        return b ? *b : Bounty();
    }
};

typedef OgreUnorderedMapBinding<Faction*, Bounty> BountiesMapBinding;

static BountyManager* getB(lua_State* L, int idx)
{
    return checkObject<BountyManager>(L, idx, BountyManagerBinding::getMetatableName());
}

// --- Getters for BountyManager ---
static int BountyManager_get_bounties(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    return pushObject<ogre_unordered_map<Faction*, Bounty>::type>(L, &b->bounties, "KenshiLua.BountiesMap");
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
    lua_pushinteger(L, (int)b->committingCrime);
    return 1;
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

int BountyManagerBinding::_getBountyFaction(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    Faction* result = b->_getBountyFaction(f);
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int BountyManagerBinding::_CONSTRUCTOR(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    BountyManager* result = b->_CONSTRUCTOR(c);
    return pushObject<BountyManager>(L, result, BountyManagerBinding::getMetatableName());
}

int BountyManagerBinding::getPercievedBounty(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    Character* whosLooking = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    int result = b->getPercievedBounty(whosLooking);
    lua_pushinteger(L, result);
    return 1;
}

int BountyManagerBinding::getActualBounty(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    Faction* whosLooking = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    int result = b->getActualBounty(whosLooking);
    lua_pushinteger(L, result);
    return 1;
}

int BountyManagerBinding::notifyPlayerClaimBounty(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    Faction* whosLooking = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    b->notifyPlayerClaimBounty(whosLooking);
    return 0;
}

int BountyManagerBinding::bountyAlreadyBeenClaimedByPlayer(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    Faction* whosLooking = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    bool result = b->bountyAlreadyBeenClaimedByPlayer(whosLooking);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BountyManagerBinding::assignBountyForCrimes(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    Faction* enforcer = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    b->assignBountyForCrimes(enforcer);
    return 0;
}

int BountyManagerBinding::unfairAddToBounty(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    Faction* enforcer = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    int amount = (int)luaL_checkinteger(L, 3);
    b->unfairAddToBounty(enforcer, amount);
    return 0;
}

int BountyManagerBinding::clearBounty(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    Faction* enforcer = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    b->clearBounty(enforcer);
    return 0;
}

int BountyManagerBinding::load(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    b->load(state);
    return 0;
}

int BountyManagerBinding::save(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    b->save(state);
    return 0;
}

int BountyManagerBinding::setCrime(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    CrimeEnum crime = (CrimeEnum)luaL_checkinteger(L, 2);
    Faction* against = checkObject<Faction>(L, 3, FactionBinding::getMetatableName());
    hand* agnst = checkObject<hand>(L, 4, handBinding::getMetatableName());
    bool result = b->setCrime(crime, against, *agnst);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BountyManagerBinding::notifyCrimeWitnessed(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    Faction* against = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    hand* againstWho = checkObject<hand>(L, 3, handBinding::getMetatableName());
    int expirytime = (int)luaL_checkinteger(L, 4);
    CrimeEnum what = (CrimeEnum)luaL_checkinteger(L, 5);
    b->notifyCrimeWitnessed(against, *againstWho, expirytime, what);
    return 0;
}

int BountyManagerBinding::notifyStartPrisonSentence(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    Faction* law = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    b->notifyStartPrisonSentence(law);
    return 0;
}

int BountyManagerBinding::hasAccessPass(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    Faction* forFac = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    bool result = b->hasAccessPass(forFac);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BountyManagerBinding::giveAccessPass(lua_State* L)
{
    BountyManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "BountyManager is nil");
    Faction* who = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    float minutes = (float)luaL_checknumber(L, 3);
    b->giveAccessPass(who, minutes);
    return 0;
}

int BountyManagerBinding::crimeToStr(lua_State* L)
{
    int idx = 1;
    if (lua_isuserdata(L, 1)) idx = 2;
    CrimeEnum c = (CrimeEnum)luaL_checkinteger(L, idx);
    std::string result = BountyManager::crimeToStr(c);
    lua_pushstring(L, result.c_str());
    return 1;
}

int BountyManagerBinding::getBountyForCrime(lua_State* L)
{
    int idx = 1;
    if (lua_isuserdata(L, 1)) idx = 2;
    CrimeEnum c = (CrimeEnum)luaL_checkinteger(L, idx);
    int result = BountyManager::getBountyForCrime(c);
    lua_pushinteger(L, result);
    return 1;
}

int BountyManagerBinding::getPrisonSentenceInHours(lua_State* L)
{
    int idx = 1;
    if (lua_isuserdata(L, 1)) idx = 2;
    int bounty = (int)luaL_checkinteger(L, idx);
    int result = BountyManager::getPrisonSentenceInHours(bounty);
    lua_pushinteger(L, result);
    return 1;
}

int BountyManagerBinding::getBountyExpirationTime(lua_State* L)
{
    int idx = 1;
    if (lua_isuserdata(L, 1)) idx = 2;
    int bounty = (int)luaL_checkinteger(L, idx);
    float result = BountyManager::getBountyExpirationTime(bounty);
    lua_pushnumber(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 35: StringPair getGUIData(...) - unsupported return type (requires StringPair binding)
  line 36: void getGUIDataForAppend(...) - unsupported arg type (requires StringPair binding)
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
        { "_getBountyFaction", BountyManagerBinding::_getBountyFaction },
        { "_CONSTRUCTOR", BountyManagerBinding::_CONSTRUCTOR },
        { "getPercievedBounty", BountyManagerBinding::getPercievedBounty },
        { "getActualBounty", BountyManagerBinding::getActualBounty },
        { "notifyPlayerClaimBounty", BountyManagerBinding::notifyPlayerClaimBounty },
        { "bountyAlreadyBeenClaimedByPlayer", BountyManagerBinding::bountyAlreadyBeenClaimedByPlayer },
        { "assignBountyForCrimes", BountyManagerBinding::assignBountyForCrimes },
        { "unfairAddToBounty", BountyManagerBinding::unfairAddToBounty },
        { "clearBounty", BountyManagerBinding::clearBounty },
        { "load", BountyManagerBinding::load },
        { "save", BountyManagerBinding::save },
        { "setCrime", BountyManagerBinding::setCrime },
        { "notifyCrimeWitnessed", BountyManagerBinding::notifyCrimeWitnessed },
        { "notifyStartPrisonSentence", BountyManagerBinding::notifyStartPrisonSentence },
        { "hasAccessPass", BountyManagerBinding::hasAccessPass },
        { "giveAccessPass", BountyManagerBinding::giveAccessPass },
        { "crimeToStr", BountyManagerBinding::crimeToStr },
        { "getBountyForCrime", BountyManagerBinding::getBountyForCrime },
        { "getPrisonSentenceInHours", BountyManagerBinding::getPrisonSentenceInHours },
        { "getBountyExpirationTime", BountyManagerBinding::getBountyExpirationTime },
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

    BountiesMapBinding::registerBinding(L, "KenshiLua.BountiesMap", FactionBinding::getMetatableName(), BountyBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}   

} // namespace KenshiLua