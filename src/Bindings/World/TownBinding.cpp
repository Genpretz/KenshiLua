#include "pch.h"
#include "Bindings/World/TownBinding.h"
#include "Bindings/World/FactionBinding.h"
#include "Bindings/Utility/HandBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Core/RootObjectBinding.h"

#include <kenshi/Town.h>
#include <kenshi/Faction.h>
#include <kenshi/Platoon.h>

#include <ogre/OgreVector3.h>

#include <cstdio>

namespace KenshiLua
{

// -----------------------------------------------------------------------------
// TownBaseBinding
// -----------------------------------------------------------------------------

static TownBase* getTB(lua_State* L, int idx)
{
    return TownBaseBinding::checkTownBase(L, idx);
}

int TownBaseBinding::pushTownBase(lua_State* L, TownBase* t)
{
    if (t == nullptr)
    {
        lua_pushnil(L);
        return 1;
    }
    Town* realTown = t->isTown();
    if (realTown)
    {
        return TownBinding::pushTown(L, realTown);
    }
    return pushObject<TownBase>(L, t, TownBaseBinding::getMetatableName());
}

TownBase* TownBaseBinding::getTownBase(lua_State* L, int idx)
{
    TownBase* t = testObject<TownBase>(L, idx, TownBaseBinding::getMetatableName());
    if (t) return t;
    return TownBinding::getTown(L, idx);
}

TownBase* TownBaseBinding::checkTownBase(lua_State* L, int idx)
{
    TownBase* t = getTownBase(L, idx);
    if (!t)
    {
        luaL_argerror(L, idx, "TownBase");
    }
    return t;
}

int TownBaseBinding::gc(lua_State* L)       { return noopGc(L); }

int TownBaseBinding::tostring(lua_State* L)
{
    TownBase* t = getTB(L, 1);
    if (!t) { lua_pushstring(L, "TownBase:nil"); return 1; }
    char buf[160];
    _snprintf(buf, sizeof(buf), "TownBase:%s(%p)", t->getKnownName().c_str(), (void*)t);
    lua_pushstring(L, buf);
    return 1;
}

int TownBaseBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, TownBaseBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;   // found a method - return it
    lua_pop(L, 2);  // pop nil result + metatable

    TownBase* t = getTB(L, 1);
    if (!t) { lua_pushnil(L); return 1; }

    // --- boolean members ---
    if (strcmp(key, "isActive") == 0) { lua_pushboolean(L, t->isActive() ? 1 : 0); return 1; }
    if (strcmp(key, "isDead") == 0) { lua_pushboolean(L, t->isDead() ? 1 : 0); return 1; }
    if (strcmp(key, "isOutpost") == 0) { lua_pushboolean(L, t->isOutpost() ? 1 : 0); return 1; }
    if (strcmp(key, "isPublic") == 0) { lua_pushboolean(L, t->isPublic() ? 1 : 0); return 1; }
    if (strcmp(key, "hasGates") == 0) { lua_pushboolean(L, t->hasGates() ? 1 : 0); return 1; }
    if (strcmp(key, "isValid") == 0) { lua_pushboolean(L, t->isValid() ? 1 : 0); return 1; }
    if (strcmp(key, "isNotFriendly") == 0) { lua_pushboolean(L, t->isNotFriendly() ? 1 : 0); return 1; }

    // --- integer/enum members ---
    if (strcmp(key, "alarmState") == 0) { lua_pushinteger(L, (int)t->getAlarmState()); return 1; }
    if (strcmp(key, "townType") == 0) { lua_pushinteger(L, (int)t->townType); return 1; }

    // --- string members ---
    if (strcmp(key, "name") == 0) { lua_pushstring(L, t->getKnownName().c_str()); return 1; }
    if (strcmp(key, "unexploredName") == 0) { lua_pushstring(L, t->unexploredName.c_str()); return 1; }

    // --- boolean members extra ---
    if (strcmp(key, "discovered") == 0) { lua_pushboolean(L, t->discovered ? 1 : 0); return 1; }
    if (strcmp(key, "explored") == 0) { lua_pushboolean(L, t->explored ? 1 : 0); return 1; }

    // --- unique object members ---
    if (strcmp(key, "faction") == 0) {
        return pushObject<Faction>(L, t->getFaction(), FactionBinding::getMetatableName());
    }
    if (strcmp(key, "position") == 0) { pushVector3(L, t->getPosition()); return 1; }

    // Fall back to RootObject index
    return RootObjectBinding::index(L);
}

int TownBaseBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    TownBase* t = getTB(L, 1);
    if (!t) return luaL_error(L, "TownBase is nil");

    // --- writable properties ---
    if (strcmp(key, "faction") == 0) {
        Faction* f = checkObject<Faction>(L, 3, FactionBinding::getMetatableName());
        if (!f) return luaL_error(L, "expected Faction userdata");
        t->setFaction(f, 0);
        return 0;
    }
    if (strcmp(key, "alarmState") == 0) {
        t->setAlarmState((TownAlarmState)luaL_checkinteger(L, 3));
        return 0;
    }
    if (strcmp(key, "visible") == 0) {
        t->setVisible(lua_toboolean(L, 3) != 0);
        return 0;
    }
    if (strcmp(key, "recentlyDiscovered") == 0) {
        t->setRecentlyDiscovered(lua_toboolean(L, 3) != 0);
        return 0;
    }
    if (strcmp(key, "discovered") == 0) {
        t->discovered = (lua_toboolean(L, 3) != 0);
        return 0;
    }
    if (strcmp(key, "explored") == 0) {
        t->explored = (lua_toboolean(L, 3) != 0);
        return 0;
    }
    if (strcmp(key, "unexploredName") == 0) {
        t->unexploredName = luaL_checkstring(L, 3);
        return 0;
    }
    if (strcmp(key, "townType") == 0) {
        t->townType = (TownType)luaL_checkinteger(L, 3);
        return 0;
    }

    // Fall back to RootObject newindex
    return RootObjectBinding::newindex(L);
}

int TownBaseBinding::getName(lua_State* L)
{
    TownBase* t = getTB(L, 1);
    if (t) lua_pushstring(L, t->getKnownName().c_str()); else lua_pushnil(L);
    return 1;
}

int TownBaseBinding::getPosition(lua_State* L)
{
    TownBase* t = getTB(L, 1);
    if (!t) { lua_pushnil(L); return 1; }
    Ogre::Vector3 p = t->getPosition();
    pushVector3(L, p);
    return 1;
}

int TownBaseBinding::getFaction(lua_State* L)
{
    TownBase* t = getTB(L, 1);
    if (!t) { lua_pushnil(L); return 1; }
    return pushObject<Faction>(L, t->getFaction(), FactionBinding::getMetatableName());
}

int TownBaseBinding::setFaction(lua_State* L)
{
    TownBase* t = getTB(L, 1);
    if (!t) return luaL_error(L, "TownBase is nil");
    Faction* f = getFactionFromLua(L, 2);
    if (!f) return luaL_error(L, "setFaction: expected Faction userdata");
    t->setFaction(f, 0);
    return 0;
}

int TownBaseBinding::getAlarmState(lua_State* L)
{
    TownBase* t = getTB(L, 1);
    if (t) lua_pushinteger(L, (int)t->getAlarmState()); else lua_pushnil(L);
    return 1;
}

int TownBaseBinding::setAlarmState(lua_State* L)
{
    TownBase* t = getTB(L, 1);
    if (!t) return luaL_error(L, "TownBase is nil");
    int s = (int)luaL_checkinteger(L, 2);
    t->setAlarmState((TownAlarmState)s);
    return 0;
}

int TownBaseBinding::isActive(lua_State* L)       { TownBase* t = getTB(L, 1); lua_pushboolean(L, t && t->isActive() ? 1 : 0); return 1; }
int TownBaseBinding::isDead(lua_State* L)         { TownBase* t = getTB(L, 1); lua_pushboolean(L, t && t->isDead() ? 1 : 0); return 1; }
int TownBaseBinding::isOutpost(lua_State* L)      { TownBase* t = getTB(L, 1); lua_pushboolean(L, t && t->isOutpost() ? 1 : 0); return 1; }
int TownBaseBinding::isPublic(lua_State* L)       { TownBase* t = getTB(L, 1); lua_pushboolean(L, t && t->isPublic() ? 1 : 0); return 1; }
int TownBaseBinding::hasGates(lua_State* L)       { TownBase* t = getTB(L, 1); lua_pushboolean(L, t && t->hasGates() ? 1 : 0); return 1; }
int TownBaseBinding::isValid(lua_State* L)        { TownBase* t = getTB(L, 1); lua_pushboolean(L, t && t->isValid() ? 1 : 0); return 1; }
int TownBaseBinding::isNotFriendly(lua_State* L)  { TownBase* t = getTB(L, 1); lua_pushboolean(L, t && t->isNotFriendly() ? 1 : 0); return 1; }

int TownBaseBinding::setVisible(lua_State* L)
{
    TownBase* t = getTB(L, 1);
    if (!t) return luaL_error(L, "TownBase is nil");
    t->setVisible(lua_toboolean(L, 2) != 0);
    return 0;
}

int TownBaseBinding::setRecentlyDiscovered(lua_State* L)
{
    TownBase* t = getTB(L, 1);
    if (!t) return luaL_error(L, "TownBase is nil");
    t->setRecentlyDiscovered(lua_toboolean(L, 2) != 0);
    return 0;
}

int TownBaseBinding::distanceTo(lua_State* L)
{
    TownBase* t = getTB(L, 1);
    if (!t) { lua_pushnumber(L, 0.0); return 1; }
    Ogre::Vector3 p(0.0f, 0.0f, 0.0f);
    if (!readVector3(L, 2, p)) return luaL_error(L, "distanceTo: expected {x,y,z}");
    lua_pushnumber(L, t->distanceTo(p));
    return 1;
}

int TownBaseBinding::withinBordersRange(lua_State* L)
{
    TownBase* t = getTB(L, 1);
    if (!t) { lua_pushboolean(L, 0); return 1; }
    Ogre::Vector3 p(0.0f, 0.0f, 0.0f);
    if (!readVector3(L, 2, p)) return luaL_error(L, "withinBordersRange: expected {x,y,z}");
    float mult = (float)luaL_optnumber(L, 3, 1.0);
    lua_pushboolean(L, t->withinBordersRange(p, mult) ? 1 : 0);
    return 1;
}

int TownBaseBinding::isMyTown(lua_State* L)
{
    TownBase* t = getTB(L, 1);
    if (!t) return luaL_error(L, "TownBase is nil");
    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    if (!f) return luaL_error(L, "isMyTown: expected Faction userdata");
    
    bool myTown = false;
    if (f->factionOwnerships) {
        myTown = f->factionOwnerships->isMyTown(t);
    }
    if (!myTown && t->getFaction() == f) {
        myTown = true;
    }
    lua_pushboolean(L, myTown ? 1 : 0);
    return 1;
}

void TownBaseBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TownBaseBinding::gc },
        { "__tostring", TownBaseBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getName",                TownBaseBinding::getName },
        { "getPosition",            TownBaseBinding::getPosition },
        { "getFaction",             TownBaseBinding::getFaction },
        { "setFaction",             TownBaseBinding::setFaction },
        { "getAlarmState",          TownBaseBinding::getAlarmState },
        { "setAlarmState",          TownBaseBinding::setAlarmState },
        { "isActive",               TownBaseBinding::isActive },
        { "isDead",                 TownBaseBinding::isDead },
        { "isOutpost",              TownBaseBinding::isOutpost },
        { "isPublic",               TownBaseBinding::isPublic },
        { "hasGates",               TownBaseBinding::hasGates },
        { "isValid",                TownBaseBinding::isValid },
        { "isNotFriendly",          TownBaseBinding::isNotFriendly },
        { "setVisible",             TownBaseBinding::setVisible },
        { "setRecentlyDiscovered",  TownBaseBinding::setRecentlyDiscovered },
        { "distanceTo",             TownBaseBinding::distanceTo },
        { "withinBordersRange",     TownBaseBinding::withinBordersRange },
        { "isMyTown",               TownBaseBinding::isMyTown },
        { 0, 0 }
    };
    registerClass(L, TownBaseBinding::getMetatableName(), meta, methods, TownBaseBinding::index, TownBaseBinding::newindex);
}


// -----------------------------------------------------------------------------
// TownBinding
// -----------------------------------------------------------------------------

static Town* getT(lua_State* L, int idx)
{
    return TownBinding::checkTown(L, idx);
}

int TownBinding::pushTown(lua_State* L, Town* t)
{
    return pushObject<Town>(L, t, TownBinding::getMetatableName());
}

Town* TownBinding::getTown(lua_State* L, int idx)
{
    return testObject<Town>(L, idx, TownBinding::getMetatableName());
}

Town* TownBinding::checkTown(lua_State* L, int idx)
{
    Town* t = getTown(L, idx);
    if (!t)
    {
        luaL_argerror(L, idx, "Town");
    }
    return t;
}

int TownBinding::gc(lua_State* L)       { return noopGc(L); }

int TownBinding::tostring(lua_State* L)
{
    Town* t = getT(L, 1);
    if (!t) { lua_pushstring(L, "Town:nil"); return 1; }
    char buf[160];
    _snprintf(buf, sizeof(buf), "Town:%s(%p)", t->getKnownName().c_str(), (void*)t);
    lua_pushstring(L, buf);
    return 1;
}

int TownBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, TownBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;   // found a method - return it
    lua_pop(L, 2);  // pop nil result + metatable

    Town* t = getT(L, 1);
    if (!t) { lua_pushnil(L); return 1; }

    // --- Town specific members ---
    if (strcmp(key, "playerTownLevel") == 0) { lua_pushinteger(L, t->playerTownLevel); return 1; }
    if (strcmp(key, "openToPublic") == 0) { lua_pushboolean(L, t->openToPublic ? 1 : 0); return 1; }
    if (strcmp(key, "power_Stat") == 0) { lua_pushnumber(L, t->power_Stat); return 1; }
    if (strcmp(key, "maxPower_Stat") == 0) { lua_pushnumber(L, t->maxPower_Stat); return 1; }
    if (strcmp(key, "townRangeMultiplier") == 0) { lua_pushnumber(L, t->townRangeMultiplier); return 1; }
    if (strcmp(key, "gates") == 0) {
        lua_newtable(L);
        int idx = 1;
        for (ogre_unordered_set<hand>::type::iterator it = t->gates.begin(); it != t->gates.end(); ++it) {
            HandBinding::pushHand(L, *it);
            lua_rawseti(L, -2, idx++);
        }
        return 1;
    }

    // Fall back to TownBase index
    return TownBaseBinding::index(L);
}

int TownBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    Town* t = getT(L, 1);
    if (!t) return luaL_error(L, "Town is nil");

    // --- Town specific writable properties ---
    if (strcmp(key, "openToPublic") == 0) {
        t->openToPublic = (lua_toboolean(L, 3) != 0);
        return 0;
    }
    if (strcmp(key, "playerTownLevel") == 0) {
        t->playerTownLevel = (int)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "power_Stat") == 0) {
        t->power_Stat = (float)luaL_checknumber(L, 3);
        return 0;
    }
    if (strcmp(key, "maxPower_Stat") == 0) {
        t->maxPower_Stat = (float)luaL_checknumber(L, 3);
        return 0;
    }
    if (strcmp(key, "townRangeMultiplier") == 0) {
        t->townRangeMultiplier = (float)luaL_checknumber(L, 3);
        return 0;
    }
    if (strcmp(key, "gates") == 0) return luaL_error(L, "Town: gates is read-only");

    // Fall back to TownBase newindex
    return TownBaseBinding::newindex(L);
}

int TownBinding::getPowerStats(lua_State* L)
{
    Town* t = getT(L, 1);
    if (!t) return luaL_error(L, "Town is nil");
    lua_pushnumber(L, t->power_Stat);
    lua_pushnumber(L, t->maxPower_Stat);
    return 2;
}

void TownBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TownBinding::gc },
        { "__tostring", TownBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getPowerStats",          TownBinding::getPowerStats },
        { 0, 0 }
    };
    registerClass(L, TownBinding::getMetatableName(), meta, methods, TownBinding::index, TownBinding::newindex);
}

} // namespace KenshiLua