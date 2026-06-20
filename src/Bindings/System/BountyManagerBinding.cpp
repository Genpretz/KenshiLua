#include "pch.h"
#include "Bindings/System/BountyManagerBinding.h"
#include "Bindings/Character/CharacterBinding.h"
#include "Bindings/World/FactionBinding.h"
#include "Bindings/Core/GameDataBinding.h"
#include "Bindings/Utility/HandBinding.h"
#include "Bindings/System/BountyBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/BountyManager.h>
#include <kenshi/Character.h>
#include <kenshi/Faction.h>
#include <kenshi/GameData.h>
#include <kenshi/util/OgreUnordered.h>

#include <cstdio>
#include <cstring>

namespace KenshiLua
{

static BountyManager* getBM(lua_State* L, int idx)
{
    return checkObject<BountyManager>(L, idx, BountyManagerBinding::getMetatableName());
}

int BountyManagerBinding::gc(lua_State* L) { return noopGc(L); }

int BountyManagerBinding::tostring(lua_State* L)
{
    BountyManager* bm = getBM(L, 1);
    if (bm == 0) { lua_pushstring(L, "BountyManager:nil"); return 1; }
    char buf[160];
    _snprintf(buf, sizeof(buf), "BountyManager(%p)", (void*)bm);
    lua_pushstring(L, buf);
    return 1;
}

int BountyManagerBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, BountyManagerBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    BountyManager* bm = getBM(L, 1);
    if (bm == 0) { lua_pushnil(L); return 1; }

    // --- map members ---
    if (strcmp(key, "bounties") == 0)
    {
        lua_createtable(L, 0, (int)bm->bounties.size());
        for (ogre_unordered_map<Faction*, Bounty>::type::const_iterator it = bm->bounties.begin(); it != bm->bounties.end(); ++it)
        {
            pushObject<Faction>(L, it->first, FactionBinding::getMetatableName());
            BountyBinding::pushBounty(L, it->second);
            lua_settable(L, -3);
        }
        return 1;
    }

    // --- boolean members ---
    if (strcmp(key, "isCommittingCrime") == 0) { lua_pushboolean(L, bm->isCommittingCrime() ? 1 : 0); return 1; }
    if (strcmp(key, "_hadABountyAssignedForCurrentCrime") == 0 || strcmp(key, "hadABountyAssignedForCurrentCrime") == 0)
    {
        lua_pushboolean(L, bm->_hadABountyAssignedForCurrentCrime ? 1 : 0);
        return 1;
    }

    // --- float members ---
    if (strcmp(key, "crimeExpiry") == 0) { lua_pushnumber(L, bm->crimeExpiry); return 1; }
    if (strcmp(key, "prisonSentenceToServe") == 0) { lua_pushnumber(L, bm->prisonSentenceToServe); return 1; }

    // --- integer/enum members ---
    if (strcmp(key, "committingCrime") == 0) { lua_pushinteger(L, (int)bm->committingCrime); return 1; }
    if (strcmp(key, "totalBounty") == 0) { lua_pushinteger(L, bm->getTotalBounty()); return 1; }

    // --- unique object members ---
    if (strcmp(key, "me") == 0)
    {
        return pushObject<Character>(L, bm->me, CharacterBinding::getMetatableName());
    }
    if (strcmp(key, "_hasAccessPass") == 0 || strcmp(key, "hasAccessPass") == 0)
    {
        return pushObject<Faction>(L, bm->_hasAccessPass, FactionBinding::getMetatableName());
    }
    if (strcmp(key, "crimeAgainstFaction") == 0)
    {
        return pushObject<Faction>(L, bm->crimeAgainstFaction, FactionBinding::getMetatableName());
    }
    if (strcmp(key, "usingTrainingEquipmentOf") == 0)
    {
        return pushObject<Faction>(L, bm->usingTrainingEquipmentOf, FactionBinding::getMetatableName());
    }
    if (strcmp(key, "crimeAgainst") == 0)
    {
        return HandBinding::pushHand(L, bm->crimeAgainst);
    }

    // --- TimeOfDay members (pushed as double hours) ---
    if (strcmp(key, "accessPassExpirationTime") == 0)
    {
        lua_pushnumber(L, bm->accessPassExpirationTime.time);
        return 1;
    }
    if (strcmp(key, "prisonSentenceBeganTime") == 0)
    {
        lua_pushnumber(L, bm->prisonSentenceBeganTime.time);
        return 1;
    }

    lua_pushnil(L);
    return 1;
}

int BountyManagerBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    BountyManager* bm = getBM(L, 1);
    if (bm == 0) return luaL_error(L, "BountyManager is nil");

    // --- map members ---
    if (strcmp(key, "bounties") == 0)
    {
        if (!lua_istable(L, 3))
            return luaL_error(L, "bounties: expected table of {Faction = Bounty}");
        bm->bounties.clear();
        lua_pushnil(L);
        while (lua_next(L, 3) != 0)
        {
            Faction* f = getFactionFromLua(L, -2);
            if (!f)
                return luaL_error(L, "bounties table: expected Faction userdata keys");
            Bounty* b = (Bounty*)luaL_checkudata(L, -1, BountyBinding::getMetatableName());
            if (!b)
                return luaL_error(L, "bounties table: expected Bounty values");
            bm->bounties[f] = *b;
            lua_pop(L, 1);
        }
        return 0;
    }

    // --- boolean members ---
    if (strcmp(key, "_hadABountyAssignedForCurrentCrime") == 0 || strcmp(key, "hadABountyAssignedForCurrentCrime") == 0)
    {
        bm->_hadABountyAssignedForCurrentCrime = (lua_toboolean(L, 3) != 0);
        return 0;
    }

    // --- float members ---
    if (strcmp(key, "crimeExpiry") == 0)
    {
        bm->crimeExpiry = (float)luaL_checknumber(L, 3);
        return 0;
    }
    if (strcmp(key, "prisonSentenceToServe") == 0)
    {
        bm->prisonSentenceToServe = (float)luaL_checknumber(L, 3);
        return 0;
    }

    // --- integer/enum members ---
    if (strcmp(key, "committingCrime") == 0)
    {
        bm->committingCrime = (CrimeEnum)luaL_checkinteger(L, 3);
        return 0;
    }

    // --- unique object members ---
    if (strcmp(key, "me") == 0)
    {
        bm->me = lua_isnil(L, 3) ? nullptr : checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
        return 0;
    }
    if (strcmp(key, "_hasAccessPass") == 0 || strcmp(key, "hasAccessPass") == 0)
    {
        bm->_hasAccessPass = lua_isnil(L, 3) ? nullptr : checkObject<Faction>(L, 3, FactionBinding::getMetatableName());
        return 0;
    }
    if (strcmp(key, "crimeAgainstFaction") == 0)
    {
        bm->crimeAgainstFaction = lua_isnil(L, 3) ? nullptr : checkObject<Faction>(L, 3, FactionBinding::getMetatableName());
        return 0;
    }
    if (strcmp(key, "usingTrainingEquipmentOf") == 0)
    {
        bm->usingTrainingEquipmentOf = lua_isnil(L, 3) ? nullptr : checkObject<Faction>(L, 3, FactionBinding::getMetatableName());
        return 0;
    }
    if (strcmp(key, "crimeAgainst") == 0)
    {
        if (lua_isnil(L, 3))
        {
            bm->crimeAgainst = hand();
        }
        else
        {
            hand* h = (hand*)luaL_checkudata(L, 3, HandBinding::getMetatableName());
            if (!h) return luaL_error(L, "crimeAgainst: expected hand userdata or nil");
            bm->crimeAgainst = *h;
        }
        return 0;
    }

    // --- TimeOfDay members (set as double hours) ---
    if (strcmp(key, "accessPassExpirationTime") == 0)
    {
        bm->accessPassExpirationTime.time = (double)luaL_checknumber(L, 3);
        return 0;
    }
    if (strcmp(key, "prisonSentenceBeganTime") == 0)
    {
        bm->prisonSentenceBeganTime.time = (double)luaL_checknumber(L, 3);
        return 0;
    }

    // --- read-only/computed properties ---
    if (strcmp(key, "isCommittingCrime") == 0) return luaL_error(L, "BountyManager: field 'isCommittingCrime' is read-only");
    if (strcmp(key, "totalBounty") == 0) return luaL_error(L, "BountyManager: field 'totalBounty' is read-only");

    return luaL_error(L, "BountyManager: field '%s' is read-only or does not exist", key);
}

int BountyManagerBinding::isCommittingCrime(lua_State* L)
{
    BountyManager* bm = getBM(L, 1);
    lua_pushboolean(L, bm && bm->isCommittingCrime() ? 1 : 0);
    return 1;
}

int BountyManagerBinding::getTotalBounty(lua_State* L)
{
    BountyManager* bm = getBM(L, 1);
    if (bm != 0) lua_pushinteger(L, bm->getTotalBounty()); else lua_pushinteger(L, 0);
    return 1;
}

int BountyManagerBinding::getPercievedBounty(lua_State* L)
{
    BountyManager* bm = getBM(L, 1);
    if (bm == 0) return luaL_error(L, "BountyManager is nil");
    Character* whosLooking = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    if (whosLooking == 0) return luaL_error(L, "getPercievedBounty: expected Character userdata");
    lua_pushinteger(L, bm->getPercievedBounty(whosLooking));
    return 1;
}

int BountyManagerBinding::getActualBounty(lua_State* L)
{
    BountyManager* bm = getBM(L, 1);
    if (bm == 0) return luaL_error(L, "BountyManager is nil");
    Faction* whosLooking = getFactionFromLua(L, 2);
    if (whosLooking == 0) return luaL_error(L, "getActualBounty: expected Faction userdata");
    lua_pushinteger(L, bm->getActualBounty(whosLooking));
    return 1;
}

int BountyManagerBinding::clearBounty(lua_State* L)
{
    BountyManager* bm = getBM(L, 1);
    if (bm == 0) return luaL_error(L, "BountyManager is nil");
    Faction* enforcer = getFactionFromLua(L, 2);
    if (enforcer == 0) return luaL_error(L, "clearBounty: expected Faction enforcer");
    bm->clearBounty(enforcer);
    return 0;
}

int BountyManagerBinding::unfairAddToBounty(lua_State* L)
{
    BountyManager* bm = getBM(L, 1);
    if (bm == 0) return luaL_error(L, "BountyManager is nil");
    Faction* enforcer = getFactionFromLua(L, 2);
    if (enforcer == 0) return luaL_error(L, "unfairAddToBounty: expected Faction enforcer");
    int amount = (int)luaL_checkinteger(L, 3);
    bm->unfairAddToBounty(enforcer, amount);
    return 0;
}

int BountyManagerBinding::hasAccessPass(lua_State* L)
{
    BountyManager* bm = getBM(L, 1);
    if (bm == 0) return luaL_error(L, "BountyManager is nil");
    Faction* forFac = getFactionFromLua(L, 2);
    if (forFac == 0) return luaL_error(L, "hasAccessPass: expected Faction userdata");
    lua_pushboolean(L, bm->hasAccessPass(forFac) ? 1 : 0);
    return 1;
}

int BountyManagerBinding::giveAccessPass(lua_State* L)
{
    BountyManager* bm = getBM(L, 1);
    if (bm == 0) return luaL_error(L, "BountyManager is nil");
    Faction* who = getFactionFromLua(L, 2);
    if (who == 0) return luaL_error(L, "giveAccessPass: expected Faction userdata");
    float minutes = (float)luaL_checknumber(L, 3);
    bm->giveAccessPass(who, minutes);
    return 0;
}

int BountyManagerBinding::notifyPlayerClaimBounty(lua_State* L)
{
    BountyManager* bm = getBM(L, 1);
    if (bm == 0) return luaL_error(L, "BountyManager is nil");
    Faction* whosLooking = getFactionFromLua(L, 2);
    if (whosLooking == 0) return luaL_error(L, "notifyPlayerClaimBounty: expected Faction userdata");
    bm->notifyPlayerClaimBounty(whosLooking);
    return 0;
}

int BountyManagerBinding::bountyAlreadyBeenClaimedByPlayer(lua_State* L)
{
    BountyManager* bm = getBM(L, 1);
    if (bm == 0) return luaL_error(L, "BountyManager is nil");
    Faction* whosLooking = getFactionFromLua(L, 2);
    if (whosLooking == 0) return luaL_error(L, "bountyAlreadyBeenClaimedByPlayer: expected Faction userdata");
    lua_pushboolean(L, bm->bountyAlreadyBeenClaimedByPlayer(whosLooking) ? 1 : 0);
    return 1;
}

int BountyManagerBinding::assignBountyForCrimes(lua_State* L)
{
    BountyManager* bm = getBM(L, 1);
    if (bm == 0) return luaL_error(L, "BountyManager is nil");
    Faction* enforcer = getFactionFromLua(L, 2);
    if (enforcer == 0) return luaL_error(L, "assignBountyForCrimes: expected Faction enforcer");
    bm->assignBountyForCrimes(enforcer);
    return 0;
}

int BountyManagerBinding::getBountyRecognitionThreshold(lua_State* L)
{
    BountyManager* bm = getBM(L, 1);
    if (bm == 0) return luaL_error(L, "BountyManager is nil");
    lua_pushinteger(L, bm->getBountyRecognitionThreshold());
    return 1;
}

int BountyManagerBinding::update(lua_State* L)
{
    BountyManager* bm = getBM(L, 1);
    if (bm == 0) return luaL_error(L, "BountyManager is nil");
    float frameTime = (float)luaL_checknumber(L, 2);
    bm->update(frameTime);
    return 0;
}

int BountyManagerBinding::getBountyExpiryStringForGUI(lua_State* L)
{
    BountyManager* bm = getBM(L, 1);
    if (bm == 0) return luaL_error(L, "BountyManager is nil");
    lua_pushstring(L, bm->getBountyExpiryStringForGUI().c_str());
    return 1;
}

int BountyManagerBinding::load(lua_State* L)
{
    BountyManager* bm = getBM(L, 1);
    if (bm == 0) return luaL_error(L, "BountyManager is nil");
    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    if (state == 0) return luaL_error(L, "load: expected GameData state");
    bm->load(state);
    return 0;
}

int BountyManagerBinding::save(lua_State* L)
{
    BountyManager* bm = getBM(L, 1);
    if (bm == 0) return luaL_error(L, "BountyManager is nil");
    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    if (state == 0) return luaL_error(L, "save: expected GameData state");
    bm->save(state);
    return 0;
}

int BountyManagerBinding::setCrime(lua_State* L)
{
    BountyManager* bm = getBM(L, 1);
    if (bm == 0) return luaL_error(L, "BountyManager is nil");
    int crime = (int)luaL_checkinteger(L, 2);
    Faction* against = lua_isnil(L, 3) ? NULL : getFactionFromLua(L, 3);
    hand* agnst = (hand*)luaL_checkudata(L, 4, HandBinding::getMetatableName());
    if (agnst == 0) return luaL_error(L, "setCrime: expected hand userdata for argument 4");
    lua_pushboolean(L, bm->setCrime((CrimeEnum)crime, against, *agnst) ? 1 : 0);
    return 1;
}

int BountyManagerBinding::notifyCrimeWitnessed(lua_State* L)
{
    BountyManager* bm = getBM(L, 1);
    if (bm == 0) return luaL_error(L, "BountyManager is nil");
    Faction* against = lua_isnil(L, 2) ? NULL : getFactionFromLua(L, 2);
    hand* againstWho = (hand*)luaL_checkudata(L, 3, HandBinding::getMetatableName());
    if (againstWho == 0) return luaL_error(L, "notifyCrimeWitnessed: expected hand userdata for argument 3");
    int expirytime = (int)luaL_checkinteger(L, 4);
    int what = (int)luaL_checkinteger(L, 5);
    bm->notifyCrimeWitnessed(against, *againstWho, expirytime, (CrimeEnum)what);
    return 0;
}

int BountyManagerBinding::notifyPossibleCrimeWitnessed(lua_State* L)
{
    BountyManager* bm = getBM(L, 1);
    if (bm == 0) return luaL_error(L, "BountyManager is nil");
    float time = (float)luaL_checknumber(L, 2);
    bm->notifyPossibleCrimeWitnessed(time);
    return 0;
}

int BountyManagerBinding::notifyStartPrisonSentence(lua_State* L)
{
    BountyManager* bm = getBM(L, 1);
    if (bm == 0) return luaL_error(L, "BountyManager is nil");
    Faction* law = getFactionFromLua(L, 2);
    if (law == 0) return luaL_error(L, "notifyStartPrisonSentence: expected Faction law");
    bm->notifyStartPrisonSentence(law);
    return 0;
}

int BountyManagerBinding::crimeToStr(lua_State* L)
{
    int idx = 1;
    if (lua_isuserdata(L, 1))
    {
        BountyManager* bm = (BountyManager*)testObject<BountyManager>(L, 1, getMetatableName());
        if (bm)
            idx = 2;
    }
    int crime = (int)luaL_checkinteger(L, idx);
    lua_pushstring(L, BountyManager::crimeToStr((CrimeEnum)crime).c_str());
    return 1;
}

int BountyManagerBinding::getBountyForCrime(lua_State* L)
{
    int idx = 1;
    if (lua_isuserdata(L, 1))
    {
        BountyManager* bm = (BountyManager*)testObject<BountyManager>(L, 1, getMetatableName());
        if (bm)
            idx = 2;
    }
    int crime = (int)luaL_checkinteger(L, idx);
    lua_pushinteger(L, BountyManager::getBountyForCrime((CrimeEnum)crime));
    return 1;
}

int BountyManagerBinding::getPrisonSentenceInHours(lua_State* L)
{
    int idx = 1;
    if (lua_isuserdata(L, 1))
    {
        BountyManager* bm = (BountyManager*)testObject<BountyManager>(L, 1, getMetatableName());
        if (bm)
            idx = 2;
    }
    int bounty = (int)luaL_checkinteger(L, idx);
    lua_pushinteger(L, BountyManager::getPrisonSentenceInHours(bounty));
    return 1;
}

int BountyManagerBinding::getBountyExpirationTime(lua_State* L)
{
    int idx = 1;
    if (lua_isuserdata(L, 1))
    {
        BountyManager* bm = (BountyManager*)testObject<BountyManager>(L, 1, getMetatableName());
        if (bm)
            idx = 2;
    }
    int bounty = (int)luaL_checkinteger(L, idx);
    lua_pushnumber(L, BountyManager::getBountyExpirationTime(bounty));
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
        { "isCommittingCrime",    BountyManagerBinding::isCommittingCrime },
        { "getTotalBounty",       BountyManagerBinding::getTotalBounty },
        { "getPercievedBounty",   BountyManagerBinding::getPercievedBounty },
        { "getActualBounty",      BountyManagerBinding::getActualBounty },
        { "clearBounty",          BountyManagerBinding::clearBounty },
        { "unfairAddToBounty",    BountyManagerBinding::unfairAddToBounty },
        { "hasAccessPass",        BountyManagerBinding::hasAccessPass },
        { "giveAccessPass",       BountyManagerBinding::giveAccessPass },
        { "notifyPlayerClaimBounty", BountyManagerBinding::notifyPlayerClaimBounty },
        { "bountyAlreadyBeenClaimedByPlayer", BountyManagerBinding::bountyAlreadyBeenClaimedByPlayer },
        { "assignBountyForCrimes", BountyManagerBinding::assignBountyForCrimes },
        { "getBountyRecognitionThreshold", BountyManagerBinding::getBountyRecognitionThreshold },
        { "update",               BountyManagerBinding::update },
        { "getBountyExpiryStringForGUI", BountyManagerBinding::getBountyExpiryStringForGUI },
        { "load",                 BountyManagerBinding::load },
        { "save",                 BountyManagerBinding::save },
        { "setCrime",             BountyManagerBinding::setCrime },
        { "notifyCrimeWitnessed",  BountyManagerBinding::notifyCrimeWitnessed },
        { "notifyPossibleCrimeWitnessed", BountyManagerBinding::notifyPossibleCrimeWitnessed },
        { "notifyStartPrisonSentence", BountyManagerBinding::notifyStartPrisonSentence },
        { "crimeToStr",           BountyManagerBinding::crimeToStr },
        { "getBountyForCrime",    BountyManagerBinding::getBountyForCrime },
        { "getPrisonSentenceInHours", BountyManagerBinding::getPrisonSentenceInHours },
        { "getBountyExpirationTime", BountyManagerBinding::getBountyExpirationTime },
        { 0, 0 }
    };
    registerClass(L, BountyManagerBinding::getMetatableName(), meta, methods, BountyManagerBinding::index, BountyManagerBinding::newindex);
}

} // namespace KenshiLua