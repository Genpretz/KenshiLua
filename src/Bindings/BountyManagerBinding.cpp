#include "pch.h"
#include "KENSHI\BountyManager.h"
#include "BountyManagerBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/BountyBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"
#include "Bindings/Util/StringPairBinding.h"
#include "Bindings/Util/TimeOfDayBinding.h"
#include "Bindings/Util/HandBinding.h"

namespace KenshiLua
{

typedef OgreUnorderedMapBinding<Faction*, Bounty> BountiesMapBinding;

static BountyManager* getInstance(lua_State* L, int idx)
{
    return checkObject<BountyManager>(L, idx, BountyManagerBinding::getMetatableName());
}

// --- Getters for BountyManager ---
static int BountyManager_get_bounties(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance ) return luaL_error(L, "BountyManager is nil");
    return pushObject<ogre_unordered_map<Faction*, Bounty>::type>(L, &instance->bounties, "KenshiLua.BountiesMap");
}

static int BountyManager_get_me(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");
    return pushObject<Character>(L, instance->me, CharacterBinding::getMetatableName());
}

static int BountyManager_get__hasAccessPass(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");
    return pushObject<Faction>(L, instance->_hasAccessPass, FactionBinding::getMetatableName());
}

static int BountyManager_get_accessPassExpirationTime(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");
    return pushObject<TimeOfDay>(L, &instance->accessPassExpirationTime, TimeOfDayBinding::getMetatableName());
}

static int BountyManager_get_committingCrime(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance ) return luaL_error(L, "BountyManager is nil");
    lua_pushinteger(L, (int)instance->committingCrime);
    return 1;
}

static int BountyManager_get_crimeAgainstFaction(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");
    return pushObject<Faction>(L, instance->crimeAgainstFaction, FactionBinding::getMetatableName());
}

static int BountyManager_get_usingTrainingEquipmentOf(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");
    return pushObject<Faction>(L, instance->usingTrainingEquipmentOf, FactionBinding::getMetatableName());
}

static int BountyManager_get_crimeAgainst(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");
    return HandBinding::push(L, instance->crimeAgainst);
}

static int BountyManager_get_crimeExpiry(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");
    lua_pushnumber(L, instance->crimeExpiry);
    return 1;
}

static int BountyManager_get_prisonSentenceBeganTime(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");
    return pushObject<TimeOfDay>(L, &instance->prisonSentenceBeganTime, TimeOfDayBinding::getMetatableName());
}

static int BountyManager_get_prisonSentenceToServe(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");
    lua_pushnumber(L, instance->prisonSentenceToServe);
    return 1;
}

static int BountyManager_get__hadABountyAssignedForCurrentCrime(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");
    lua_pushboolean(L, instance->_hadABountyAssignedForCurrentCrime ? 1 : 0);
    return 1;
}

// --- Setters for BountyManager ---
static int BountyManager_set_bounties(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance ) return luaL_error(L, "BountyManager is nil");
    auto* val = BountiesMapBinding::get(L, 2);
    if (!val) return luaL_error(L, "Expected BountiesMap object");
    instance->bounties = *val;
    return 0;
}

static int BountyManager_set_me(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");
    instance->me = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int BountyManager_set__hasAccessPass(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");
    instance->_hasAccessPass = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

static int BountyManager_set_accessPassExpirationTime(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");
    instance->accessPassExpirationTime = *checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    return 0;
}

static int BountyManager_set_committingCrime(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance ) return luaL_error(L, "BountyManager is nil");
    instance->committingCrime = (CrimeEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int BountyManager_set_crimeAgainstFaction(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");
    instance->crimeAgainstFaction = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

static int BountyManager_set_usingTrainingEquipmentOf(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");
    instance->usingTrainingEquipmentOf = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

static int BountyManager_set_crimeAgainst(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");
    instance->crimeAgainst = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int BountyManager_set_crimeExpiry(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");
    instance->crimeExpiry = (float)luaL_checknumber(L, 2);
    return 0;
}

static int BountyManager_set_prisonSentenceBeganTime(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");
    instance->prisonSentenceBeganTime = *checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    return 0;
}

static int BountyManager_set_prisonSentenceToServe(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");
    instance->prisonSentenceToServe = (float)luaL_checknumber(L, 2);
    return 0;
}

static int BountyManager_set__hadABountyAssignedForCurrentCrime(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");
    instance->_hadABountyAssignedForCurrentCrime = lua_toboolean(L, 2) != 0;
    return 0;
}

int BountyManagerBinding::_getBountyFaction(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");

    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    Faction* result = instance->_getBountyFaction(f);
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int BountyManagerBinding::_getHighestBountyFaction(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");

    Faction* result = instance->_getHighestBountyFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int BountyManagerBinding::_CONSTRUCTOR(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    BountyManager* result = instance->_CONSTRUCTOR(c);
    return pushObject<BountyManager>(L, result, BountyManagerBinding::getMetatableName());
}

int BountyManagerBinding::getPercievedBounty(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");

    Character* whosLooking = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    int result = instance->getPercievedBounty(whosLooking);
    lua_pushinteger(L, result);
    return 1;
}

int BountyManagerBinding::getActualBounty(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");

    Faction* whosLooking = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    int result = instance->getActualBounty(whosLooking);
    lua_pushinteger(L, result);
    return 1;
}

int BountyManagerBinding::notifyPlayerClaimBounty(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");

    Faction* whosLooking = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    instance->notifyPlayerClaimBounty(whosLooking);
    return 0;
}

int BountyManagerBinding::bountyAlreadyBeenClaimedByPlayer(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");

    Faction* whosLooking = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    bool result = instance->bountyAlreadyBeenClaimedByPlayer(whosLooking);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BountyManagerBinding::assignBountyForCrimes(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");

    Faction* enforcer = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    instance->assignBountyForCrimes(enforcer);
    return 0;
}

int BountyManagerBinding::unfairAddToBounty(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");

    Faction* enforcer = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    int amount = (int)luaL_checkinteger(L, 3);
    instance->unfairAddToBounty(enforcer, amount);
    return 0;
}

int BountyManagerBinding::getBountyRecognitionThreshold(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");

    int result = instance->getBountyRecognitionThreshold();
    lua_pushinteger(L, result);
    return 1;
}

int BountyManagerBinding::clearBounty(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");

    Faction* enforcer = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    instance->clearBounty(enforcer);
    return 0;
}

int BountyManagerBinding::getTotalBounty(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");

    int result = instance->getTotalBounty();
    lua_pushinteger(L, result);
    return 1;
}

int BountyManagerBinding::update(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");

    float frameTime = (float)luaL_checknumber(L, 2);
    instance->update(frameTime);
    return 0;
}

int BountyManagerBinding::getBountyExpiryStringForGUI(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");

    std::string result = instance->getBountyExpiryStringForGUI();
    lua_pushstring(L, result.c_str());
    return 1;
}

int BountyManagerBinding::load(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->load(state);
    return 0;
}

int BountyManagerBinding::save(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->save(state);
    return 0;
}

int BountyManagerBinding::notifyPossibleCrimeWitnessed(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->notifyPossibleCrimeWitnessed(time);
    return 0;
}

int BountyManagerBinding::isCommittingCrime(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");

    bool result = instance->isCommittingCrime();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BountyManagerBinding::notifyStartPrisonSentence(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");

    Faction* law = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    instance->notifyStartPrisonSentence(law);
    return 0;
}

int BountyManagerBinding::hasAccessPass(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");

    Faction* forFac = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    bool result = instance->hasAccessPass(forFac);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BountyManagerBinding::giveAccessPass(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");

    Faction* who = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    float minutes = (float)luaL_checknumber(L, 3);
    instance->giveAccessPass(who, minutes);
    return 0;
}

int BountyManagerBinding::_DESTRUCTOR(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BountyManager is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int BountyManagerBinding::setCrime(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance ) return luaL_error(L, "BountyManager is nil");
    CrimeEnum crime = (CrimeEnum)luaL_checkinteger(L, 2);
    Faction* against = checkObject<Faction>(L, 3, FactionBinding::getMetatableName());
    hand* agnst = checkObject<hand>(L, 4, HandBinding::getMetatableName());
    bool result = instance->setCrime(crime, against, *agnst);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int BountyManagerBinding::notifyCrimeWitnessed(lua_State* L)
{
    BountyManager* instance = getInstance(L, 1);
    if (!instance ) return luaL_error(L, "BountyManager is nil");
    Faction* against = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    hand* againstWho = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    int expirytime = (int)luaL_checkinteger(L, 4);
    CrimeEnum what = (CrimeEnum)luaL_checkinteger(L, 5);
    instance->notifyCrimeWitnessed(against, *againstWho, expirytime, what);
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


// Skipped methods needing manual binding:
// line 35: StringPair getGUIData(...) - unsupported arg type
// line 36: void getGUIDataForAppend(...) - unsupported arg type


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
    registerGetter(L, "bounties", BountyManager_get_bounties);
    registerGetter(L, "me", BountyManager_get_me);
    registerGetter(L, "_hasAccessPass", BountyManager_get__hasAccessPass);
    registerGetter(L, "accessPassExpirationTime", BountyManager_get_accessPassExpirationTime);
    registerGetter(L, "committingCrime", BountyManager_get_committingCrime);
    registerGetter(L, "crimeAgainstFaction", BountyManager_get_crimeAgainstFaction);
    registerGetter(L, "usingTrainingEquipmentOf", BountyManager_get_usingTrainingEquipmentOf);
    registerGetter(L, "crimeAgainst", BountyManager_get_crimeAgainst);
    registerGetter(L, "crimeExpiry", BountyManager_get_crimeExpiry);
    registerGetter(L, "prisonSentenceBeganTime", BountyManager_get_prisonSentenceBeganTime);
    registerGetter(L, "prisonSentenceToServe", BountyManager_get_prisonSentenceToServe);
    registerGetter(L, "_hadABountyAssignedForCurrentCrime", BountyManager_get__hadABountyAssignedForCurrentCrime);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "bounties", BountyManager_set_bounties);
    registerSetter(L, "me", BountyManager_set_me);
    registerSetter(L, "_hasAccessPass", BountyManager_set__hasAccessPass);
    registerSetter(L, "accessPassExpirationTime", BountyManager_set_accessPassExpirationTime);
    registerSetter(L, "committingCrime", BountyManager_set_committingCrime);
    registerSetter(L, "crimeAgainstFaction", BountyManager_set_crimeAgainstFaction);
    registerSetter(L, "usingTrainingEquipmentOf", BountyManager_set_usingTrainingEquipmentOf);
    registerSetter(L, "crimeAgainst", BountyManager_set_crimeAgainst);
    registerSetter(L, "crimeExpiry", BountyManager_set_crimeExpiry);
    registerSetter(L, "prisonSentenceBeganTime", BountyManager_set_prisonSentenceBeganTime);
    registerSetter(L, "prisonSentenceToServe", BountyManager_set_prisonSentenceToServe);
    registerSetter(L, "_hadABountyAssignedForCurrentCrime", BountyManager_set__hadABountyAssignedForCurrentCrime);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua