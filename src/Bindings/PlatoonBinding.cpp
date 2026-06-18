#include "pch.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/HandBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Platoon.h>
#include <kenshi/Character.h>
#include <kenshi/Faction.h>
#include <kenshi/RootObjectBase.h>

#include <ogre/OgreVector3.h>

#include <cstdio>

namespace KenshiLua
{

// We store either ActivePlatoon* or Platoon* - dereference handling is by
// checking the type at the storage slot via runtime probing.  In practice
// CharacterBinding/HandBinding push ActivePlatoon*; legacy callers may push
// Platoon*.  Both have getCharacterCount, getSquadLeader, isPersistentSquad
// in their interfaces here.

static void* getRaw(lua_State* L, int idx)
{
    void** ud = (void**)luaL_checkudata(L, idx, PlatoonBinding::getMetatableName());
    return ud ? *ud : 0;
}

static bool isPointerActivePlatoon(void* ptr)
{
    if (!ptr) return false;
    __try {
        // ActivePlatoon::me is at offset 0x78 in KenshiLib
        Platoon* p = *(Platoon**)((char*)ptr + 0x78);
        if (p && ((uintptr_t)p > 0x10000) && !((uintptr_t)p & 3)) {
            // Platoon::activePlatoon is at offset 0x1D8 in KenshiLib
            ActivePlatoon* ap = *(ActivePlatoon**)((char*)p + 0x1D8);
            if (ap == ptr) {
                return true;
            }
        }
    } __except(1) {
    }
    return false;
}

static ActivePlatoon* getAP(lua_State* L, int idx)
{
    void* raw = getRaw(L, idx);
    if (isPointerActivePlatoon(raw))
        return (ActivePlatoon*)raw;
    return 0;
}

static Platoon* getP(lua_State* L, int idx)
{
    void* raw = getRaw(L, idx);
    if (!raw) return 0;
    if (isPointerActivePlatoon(raw))
        return ((ActivePlatoon*)raw)->me;
    return (Platoon*)raw;
}

Platoon* getPlatoonFromLua(lua_State* L, int idx)
{
    return getP(L, idx);
}

int PlatoonBinding::gc(lua_State* L)       { return noopGc(L); }

int PlatoonBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    // 1. Check the metatable first so obj:method() syntax continues to work.
    luaL_getmetatable(L, PlatoonBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;   // found a method - return it
    lua_pop(L, 2);  // pop nil result + metatable

    // 2. Fall through to raw member variable access.
    ActivePlatoon* ap = getAP(L, 1);
    Platoon* p = getP(L, 1);

    // --- string members ---
    if (strcmp(key, "name") == 0) {
        if (ap) lua_pushstring(L, ap->getName().c_str());
        else    lua_pushnil(L);
        return 1;
    }
    if (strcmp(key, "stringID") == 0) {
        if (p) lua_pushstring(L, p->stringID.c_str());
        else   lua_pushnil(L);
        return 1;
    }

    // --- integer members ---
    if (strcmp(key, "squadSize") == 0) { lua_pushinteger(L, ap ? ap->getSquadSize() : 0); return 1; }
    if (strcmp(key, "characterCount") == 0) { lua_pushinteger(L, p ? p->getCharacterCount() : 0); return 1; }
    if (strcmp(key, "characterCountCurrent") == 0) { lua_pushinteger(L, p ? p->_characterCountCurrent : 0); return 1; }
    if (strcmp(key, "characterCountOriginal") == 0) { lua_pushinteger(L, p ? p->_characterCountOriginal : 0); return 1; }
    if (strcmp(key, "squadType") == 0) { lua_pushinteger(L, p ? (int)p->squadType : 0); return 1; }
    if (strcmp(key, "hasUniques") == 0) { lua_pushinteger(L, p ? p->hasUniques.toInt() : 0); return 1; }
    if (strcmp(key, "speedOverride") == 0) { lua_pushinteger(L, p ? (int)p->speedOverride : 0); return 1; }
    if (strcmp(key, "messageOnActivation") == 0) { lua_pushinteger(L, p ? (int)p->messageOnActivation : 0); return 1; }
    if (strcmp(key, "index") == 0) { lua_pushinteger(L, p ? (int)p->index : 0); return 1; }

    // --- boolean members ---
    if (strcmp(key, "isValid") == 0) { lua_pushboolean(L, ap != 0 ? 1 : 0); return 1; }
    if (strcmp(key, "isPersistent") == 0 || strcmp(key, "persistent") == 0) { lua_pushboolean(L, p && p->isPersistentSquad() ? 1 : 0); return 1; }
    if (strcmp(key, "isLoaded") == 0) { lua_pushboolean(L, ap && ap->isLoaded() ? 1 : 0); return 1; }
    if (strcmp(key, "isTrader") == 0) { lua_pushboolean(L, ap && ap->getIsTrader() ? 1 : 0); return 1; }
    if (strcmp(key, "canRefresh") == 0) { lua_pushboolean(L, p && p->canRefresh ? 1 : 0); return 1; }
    if (strcmp(key, "regenerates") == 0) { lua_pushboolean(L, p && p->regenerates ? 1 : 0); return 1; }
    if (strcmp(key, "iBuyStolenGoods") == 0) { lua_pushboolean(L, p && p->_iBuyStolenGoods ? 1 : 0); return 1; }
    if (strcmp(key, "iBuyIllegalGoods") == 0) { lua_pushboolean(L, p && p->_iBuyIllegalGoods ? 1 : 0); return 1; }
    if (strcmp(key, "isIntact") == 0) { lua_pushboolean(L, p && p->_isIntact ? 1 : 0); return 1; }
    if (strcmp(key, "hasNeverBeenActivated") == 0) { lua_pushboolean(L, p && p->hasNeverBeenActivated ? 1 : 0); return 1; }
    if (strcmp(key, "isResidentSquad") == 0) { lua_pushboolean(L, p && p->isResidentSquad ? 1 : 0); return 1; }
    if (strcmp(key, "isDead") == 0) { lua_pushboolean(L, p && p->isDead ? 1 : 0); return 1; }
    if (strcmp(key, "imprisoned") == 0) { lua_pushboolean(L, p && p->imprisoned ? 1 : 0); return 1; }

    // --- float members ---
    if (strcmp(key, "priceMultWhenITrade") == 0) { lua_pushnumber(L, p ? p->priceMultWhenITrade : 1.0f); return 1; }
    if (strcmp(key, "malnourishedLevel") == 0) { lua_pushnumber(L, p ? p->malnourishedLevel : 0.0f); return 1; }
    if (strcmp(key, "traderInventoryRefreshTime") == 0) { lua_pushnumber(L, p ? p->traderInventoryRefreshTime.time : -1.0); return 1; }

    // --- unique object members ---
    if (strcmp(key, "squadLeader") == 0) {
        if (!ap) { lua_pushnil(L); return 1; }
        return pushObject<Character>(L, ap->getSquadLeader(), CharacterBinding::getMetatableName());
    }
    if (strcmp(key, "faction") == 0) {
        if (!p) { lua_pushnil(L); return 1; }
        return pushObject<Faction>(L, p->ownerships.faction, FactionBinding::getMetatableName());
    }
    if (strcmp(key, "squadTemplate") == 0) {
        if (!p) { lua_pushnil(L); return 1; }
        return pushObject<GameData>(L, p->squadTemplate, GameDataBinding::getMetatableName());
    }
    if (strcmp(key, "isSeparatedSquad") == 0) {
        if (!p) { lua_pushnil(L); return 1; }
        return HandBinding::pushHand(L, p->isSeparatedSquad);
    }
    if (strcmp(key, "squadleader") == 0) {
        if (!p) { lua_pushnil(L); return 1; }
        return HandBinding::pushHand(L, p->squadleader);
    }
    if (strcmp(key, "activePlatoon") == 0) {
        if (!p || !p->activePlatoon) { lua_pushnil(L); return 1; }
        return pushObject<ActivePlatoon>(L, p->activePlatoon, PlatoonBinding::getMetatableName());
    }
    if (strcmp(key, "unloadedPlatoon") == 0) {
        if (!p || !p->unloadedPlatoon) { lua_pushnil(L); return 1; }
        lua_pushlightuserdata(L, p->unloadedPlatoon);
        return 1;
    }

    lua_pushnil(L);
    return 1;
}

int PlatoonBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    Platoon* p = getP(L, 1);
    if (!p) return luaL_error(L, "Platoon is nil");

    // --- string members ---
    if (strcmp(key, "stringID") == 0) {
        p->stringID = luaL_checkstring(L, 3);
        return 0;
    }

    // --- boolean members ---
    if (strcmp(key, "isPersistent") == 0 || strcmp(key, "persistent") == 0) {
        p->setPersistentSquad(lua_toboolean(L, 3) != 0);
        return 0;
    }
    if (strcmp(key, "canRefresh") == 0) {
        p->canRefresh = (lua_toboolean(L, 3) != 0);
        return 0;
    }
    if (strcmp(key, "regenerates") == 0) {
        p->regenerates = (lua_toboolean(L, 3) != 0);
        return 0;
    }
    if (strcmp(key, "iBuyStolenGoods") == 0) {
        p->_iBuyStolenGoods = (lua_toboolean(L, 3) != 0);
        return 0;
    }
    if (strcmp(key, "iBuyIllegalGoods") == 0) {
        p->_iBuyIllegalGoods = (lua_toboolean(L, 3) != 0);
        return 0;
    }
    if (strcmp(key, "isIntact") == 0) {
        p->_isIntact = (lua_toboolean(L, 3) != 0);
        return 0;
    }
    if (strcmp(key, "hasNeverBeenActivated") == 0) {
        p->hasNeverBeenActivated = (lua_toboolean(L, 3) != 0);
        return 0;
    }
    if (strcmp(key, "isResidentSquad") == 0) {
        p->isResidentSquad = (lua_toboolean(L, 3) != 0);
        return 0;
    }
    if (strcmp(key, "isDead") == 0) {
        p->isDead = (lua_toboolean(L, 3) != 0);
        return 0;
    }
    if (strcmp(key, "imprisoned") == 0) {
        p->imprisoned = (lua_toboolean(L, 3) != 0);
        return 0;
    }

    // --- integer members ---
    if (strcmp(key, "characterCountCurrent") == 0) {
        p->_characterCountCurrent = (int)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "characterCountOriginal") == 0) {
        p->_characterCountOriginal = (int)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "squadType") == 0) {
        p->squadType = (SquadType)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "hasUniques") == 0) {
        p->hasUniques = YesNoMaybe((int)luaL_checkinteger(L, 3));
        return 0;
    }
    if (strcmp(key, "speedOverride") == 0) {
        p->speedOverride = (MoveSpeed)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "messageOnActivation") == 0) {
        p->messageOnActivation = (PlatoonCreationMessage)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "index") == 0) {
        p->index = (short)luaL_checkinteger(L, 3);
        return 0;
    }

    // --- float members ---
    if (strcmp(key, "priceMultWhenITrade") == 0) {
        p->priceMultWhenITrade = (float)luaL_checknumber(L, 3);
        return 0;
    }
    if (strcmp(key, "malnourishedLevel") == 0) {
        p->malnourishedLevel = (float)luaL_checknumber(L, 3);
        return 0;
    }
    if (strcmp(key, "traderInventoryRefreshTime") == 0) {
        p->traderInventoryRefreshTime.time = (double)luaL_checknumber(L, 3);
        return 0;
    }

    // --- unique object members ---
    if (strcmp(key, "isSeparatedSquad") == 0) {
        hand* h = (hand*)luaL_checkudata(L, 3, HandBinding::getMetatableName());
        if (!h) return luaL_error(L, "expected hand userdata");
        p->isSeparatedSquad = *h;
        return 0;
    }
    if (strcmp(key, "squadleader") == 0) {
        hand* h = (hand*)luaL_checkudata(L, 3, HandBinding::getMetatableName());
        if (!h) return luaL_error(L, "expected hand userdata");
        p->squadleader = *h;
        return 0;
    }

    if (strcmp(key, "squadLeader") == 0) return luaL_error(L, "Platoon: squadLeader is read-only");
    if (strcmp(key, "faction") == 0) return luaL_error(L, "Platoon: faction is read-only");
    if (strcmp(key, "squadTemplate") == 0) return luaL_error(L, "Platoon: squadTemplate is read-only");
    if (strcmp(key, "activePlatoon") == 0) return luaL_error(L, "Platoon: activePlatoon is read-only");
    if (strcmp(key, "unloadedPlatoon") == 0) return luaL_error(L, "Platoon: unloadedPlatoon is read-only");

    return luaL_error(L, "Platoon: field '%s' is read-only or does not exist", key);
}
int PlatoonBinding::tostring(lua_State* L) { return genericTostringPtr(L, "Platoon", getRaw(L, 1)); }

int PlatoonBinding::isValid(lua_State* L)
{
    ActivePlatoon* ap = getAP(L, 1);
    lua_pushboolean(L, ap != 0 ? 1 : 0);
    return 1;
}

int PlatoonBinding::getName(lua_State* L)
{
    ActivePlatoon* ap = getAP(L, 1);
    if (ap) lua_pushstring(L, ap->getName().c_str());
    else    lua_pushnil(L);
    return 1;
}

int PlatoonBinding::getSquadSize(lua_State* L)
{
    ActivePlatoon* ap = getAP(L, 1);
    if (ap) lua_pushinteger(L, ap->getSquadSize());
    else    lua_pushinteger(L, 0);
    return 1;
}

int PlatoonBinding::getCharacterCount(lua_State* L)
{
    Platoon* p = getP(L, 1);
    if (p) lua_pushinteger(L, p->getCharacterCount());
    else   lua_pushinteger(L, 0);
    return 1;
}

int PlatoonBinding::getSquadLeader(lua_State* L)
{
    ActivePlatoon* ap = getAP(L, 1);
    if (!ap) { lua_pushnil(L); return 1; }
    return pushObject<Character>(L, ap->getSquadLeader(), CharacterBinding::getMetatableName());
}

int PlatoonBinding::getFaction(lua_State* L)
{
    Platoon* p = getP(L, 1);
    if (!p) { lua_pushnil(L); return 1; }
    return pushObject<Faction>(L, p->ownerships.faction, FactionBinding::getMetatableName());
}

int PlatoonBinding::isPersistentSquad(lua_State* L)
{
    Platoon* p = getP(L, 1);
    lua_pushboolean(L, p && p->isPersistentSquad() ? 1 : 0);
    return 1;
}

int PlatoonBinding::setPersistent(lua_State* L)
{
    Platoon* p = getP(L, 1);
    if (!p) return luaL_error(L, "Platoon is nil");
    p->setPersistentSquad(lua_toboolean(L, 2) != 0);
    return 0;
}

int PlatoonBinding::isLoaded(lua_State* L)
{
    ActivePlatoon* ap = getAP(L, 1);
    lua_pushboolean(L, ap && ap->isLoaded() ? 1 : 0);
    return 1;
}

int PlatoonBinding::isTrader(lua_State* L)
{
    ActivePlatoon* ap = getAP(L, 1);
    lua_pushboolean(L, ap && ap->getIsTrader() ? 1 : 0);
    return 1;
}

int PlatoonBinding::teleport(lua_State* L)
{
    ActivePlatoon* ap = getAP(L, 1);
    if (!ap) return luaL_error(L, "Platoon is nil");
    Ogre::Vector3 p(0.0f, 0.0f, 0.0f);
    if (!readVector3(L, 2, p)) return luaL_error(L, "teleport: expected {x,y,z}");
    ap->teleport(p);
    return 0;
}

int PlatoonBinding::activate(lua_State* L)
{
    Platoon* p = getP(L, 1);
    if (p) p->activate();
    return 0;
}

int PlatoonBinding::deactivate(lua_State* L)
{
    Platoon* p = getP(L, 1);
    if (p) p->deactivate(NULL);
    return 0;
}

int PlatoonBinding::declareDead(lua_State* L)
{
    Platoon* p = getP(L, 1);
    if (p) p->declareDead();
    return 0;
}

int PlatoonBinding::undeclareDead(lua_State* L)
{
    Platoon* p = getP(L, 1);
    if (p) p->undeclareDead();
    return 0;
}

int PlatoonBinding::isFullyLoaded(lua_State* L)
{
    Platoon* p = getP(L, 1);
    lua_pushboolean(L, p && p->isFullyLoaded() ? 1 : 0);
    return 1;
}

int PlatoonBinding::setupPatrolSettings(lua_State* L)
{
    Platoon* p = getP(L, 1);
    if (p)
    {
        int minRange = (int)luaL_checkinteger(L, 2);
        int maxRange = (int)luaL_checkinteger(L, 3);
        p->setupPatrolSettings(minRange, maxRange);
    }
    return 0;
}

int PlatoonBinding::swapCharacters(lua_State* L)
{
    ActivePlatoon* ap = getAP(L, 1);
    if (ap)
    {
        int indexA = (int)luaL_checkinteger(L, 2);
        int indexB = (int)luaL_checkinteger(L, 3);
        ap->swapCharacters(indexA, indexB);
    }
    return 0;
}

int PlatoonBinding::clearAllTheUniqueNPCStates(lua_State* L)
{
    ActivePlatoon* ap = getAP(L, 1);
    if (ap) ap->clearAllTheUniqueNPCStates();
    return 0;
}

int PlatoonBinding::refreshInventory(lua_State* L)
{
    ActivePlatoon* ap = getAP(L, 1);
    if (ap)
    {
        bool firstTime = lua_toboolean(L, 2) != 0;
        ap->refreshInventory(firstTime);
    }
    return 0;
}

void PlatoonBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       PlatoonBinding::gc },
        { "__tostring", PlatoonBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "isValid",            PlatoonBinding::isValid },
        { "getName",            PlatoonBinding::getName },
        { "getSquadSize",       PlatoonBinding::getSquadSize },
        { "getCharacterCount",  PlatoonBinding::getCharacterCount },
        { "getSquadLeader",     PlatoonBinding::getSquadLeader },
        { "getFaction",         PlatoonBinding::getFaction },
        { "isPersistentSquad",  PlatoonBinding::isPersistentSquad },
        { "setPersistent",      PlatoonBinding::setPersistent },
        { "isLoaded",           PlatoonBinding::isLoaded },
        { "isTrader",           PlatoonBinding::isTrader },
        { "teleport",           PlatoonBinding::teleport },
        { "activate",           PlatoonBinding::activate },
        { "deactivate",         PlatoonBinding::deactivate },
        { "declareDead",        PlatoonBinding::declareDead },
        { "undeclareDead",      PlatoonBinding::undeclareDead },
        { "isFullyLoaded",      PlatoonBinding::isFullyLoaded },
        { "setupPatrolSettings", PlatoonBinding::setupPatrolSettings },
        { "swapCharacters",     PlatoonBinding::swapCharacters },
        { "clearAllTheUniqueNPCStates", PlatoonBinding::clearAllTheUniqueNPCStates },
        { "refreshInventory",   PlatoonBinding::refreshInventory },
        { 0, 0 }
    };
    registerClass(L, PlatoonBinding::getMetatableName(), meta, methods, PlatoonBinding::index, PlatoonBinding::newindex);
}

} // namespace KenshiLua
