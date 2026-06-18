#include "pch.h"
#include "Bindings/TownBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/HandBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Town.h>
#include <kenshi/Faction.h>
#include <kenshi/Platoon.h>

#include <ogre/OgreVector3.h>

#include <cstdio>

namespace KenshiLua
{

static TownBase* getT(lua_State* L, int idx)
{
    return checkObject<TownBase>(L, idx, TownBinding::getMetatableName());
}

int TownBinding::gc(lua_State* L)       { return noopGc(L); }

int TownBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    // 1. Check the metatable first so obj:method() syntax continues to work.
    luaL_getmetatable(L, TownBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;   // found a method - return it
    lua_pop(L, 2);  // pop nil result + metatable

    // 2. Fall through to raw member variable access.
    TownBase* t = getT(L, 1);
    if (!t) { lua_pushnil(L); return 1; }

    // --- boolean members ---
    if (strcmp(key, "isActive") == 0) { lua_pushboolean(L, t->isActive() ? 1 : 0); return 1; }
    if (strcmp(key, "isDead") == 0) { lua_pushboolean(L, t->isDead() ? 1 : 0); return 1; }
    if (strcmp(key, "isOutpost") == 0) { lua_pushboolean(L, t->isOutpost() ? 1 : 0); return 1; }
    if (strcmp(key, "isPublic") == 0) { lua_pushboolean(L, t->isPublic() ? 1 : 0); return 1; }
    if (strcmp(key, "hasGates") == 0) { lua_pushboolean(L, t->hasGates() ? 1 : 0); return 1; }
    if (strcmp(key, "isValid") == 0) { lua_pushboolean(L, t->isValid() ? 1 : 0); return 1; }
    if (strcmp(key, "isNotFriendly") == 0) { lua_pushboolean(L, t->isNotFriendly() ? 1 : 0); return 1; }

    Town* realTown = t->isTown();

    // --- integer/enum members ---
    if (strcmp(key, "alarmState") == 0) { lua_pushinteger(L, (int)t->getAlarmState()); return 1; }
    if (strcmp(key, "townType") == 0) { lua_pushinteger(L, (int)t->townType); return 1; }
    if (strcmp(key, "playerTownLevel") == 0) { lua_pushinteger(L, realTown ? realTown->playerTownLevel : 0); return 1; }

    // --- string members ---
    if (strcmp(key, "name") == 0) { lua_pushstring(L, t->getKnownName().c_str()); return 1; }
    if (strcmp(key, "unexploredName") == 0) { lua_pushstring(L, t->unexploredName.c_str()); return 1; }

    // --- boolean members extra ---
    if (strcmp(key, "discovered") == 0) { lua_pushboolean(L, t->discovered ? 1 : 0); return 1; }
    if (strcmp(key, "explored") == 0) { lua_pushboolean(L, t->explored ? 1 : 0); return 1; }
    if (strcmp(key, "openToPublic") == 0) { lua_pushboolean(L, realTown && realTown->openToPublic ? 1 : 0); return 1; }

    // --- float members ---
    if (strcmp(key, "power_Stat") == 0) { lua_pushnumber(L, realTown ? realTown->power_Stat : 0.0); return 1; }
    if (strcmp(key, "maxPower_Stat") == 0) { lua_pushnumber(L, realTown ? realTown->maxPower_Stat : 0.0); return 1; }
    if (strcmp(key, "townRangeMultiplier") == 0) { lua_pushnumber(L, realTown ? realTown->townRangeMultiplier : 1.0); return 1; }

    // --- unique object members ---
    if (strcmp(key, "faction") == 0) {
        return pushObject<Faction>(L, t->getFaction(), FactionBinding::getMetatableName());
    }
    if (strcmp(key, "position") == 0) { pushVector3(L, t->getPosition()); return 1; }
    if (strcmp(key, "gates") == 0) {
        lua_newtable(L);
        if (realTown) {
            int idx = 1;
            for (ogre_unordered_set<hand>::type::iterator it = realTown->gates.begin(); it != realTown->gates.end(); ++it) {
                HandBinding::pushHand(L, *it);
                lua_rawseti(L, -2, idx++);
            }
        }
        return 1;
    }

    lua_pushnil(L);
    return 1;
}

int TownBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    TownBase* t = getT(L, 1);
    if (!t) return luaL_error(L, "Town is nil");

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
    Town* realTown = t->isTown();

    if (strcmp(key, "openToPublic") == 0) {
        if (realTown) realTown->openToPublic = (lua_toboolean(L, 3) != 0);
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
    if (strcmp(key, "playerTownLevel") == 0) {
        if (realTown) realTown->playerTownLevel = (int)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "power_Stat") == 0) {
        if (realTown) realTown->power_Stat = (float)luaL_checknumber(L, 3);
        return 0;
    }
    if (strcmp(key, "maxPower_Stat") == 0) {
        if (realTown) realTown->maxPower_Stat = (float)luaL_checknumber(L, 3);
        return 0;
    }
    if (strcmp(key, "townRangeMultiplier") == 0) {
        if (realTown) realTown->townRangeMultiplier = (float)luaL_checknumber(L, 3);
        return 0;
    }

    if (strcmp(key, "gates") == 0) return luaL_error(L, "Town: gates is read-only");

    return luaL_error(L, "Town: field '%s' is read-only or does not exist", key);
}

int TownBinding::tostring(lua_State* L)
{
    TownBase* t = getT(L, 1);
    if (!t) { lua_pushstring(L, "Town:nil"); return 1; }
    char buf[160];
    _snprintf(buf, sizeof(buf), "Town:%s(%p)", t->getKnownName().c_str(), (void*)t);
    lua_pushstring(L, buf);
    return 1;
}

int TownBinding::getName(lua_State* L)
{
    TownBase* t = getT(L, 1);
    if (t) lua_pushstring(L, t->getKnownName().c_str()); else lua_pushnil(L);
    return 1;
}

int TownBinding::getPosition(lua_State* L)
{
    TownBase* t = getT(L, 1);
    if (!t) { lua_pushnil(L); return 1; }
    Ogre::Vector3 p = t->getPosition();
    pushVector3(L, p);
    return 1;
}

int TownBinding::getFaction(lua_State* L)
{
    TownBase* t = getT(L, 1);
    if (!t) { lua_pushnil(L); return 1; }
    return pushObject<Faction>(L, t->getFaction(), FactionBinding::getMetatableName());
}

int TownBinding::setFaction(lua_State* L)
{
    TownBase* t = getT(L, 1);
    if (!t) return luaL_error(L, "Town is nil");
    Faction* f = getFactionFromLua(L, 2);
    if (!f) return luaL_error(L, "setFaction: expected Faction userdata");
    t->setFaction(f, 0);
    return 0;
}

int TownBinding::getAlarmState(lua_State* L)
{
    TownBase* t = getT(L, 1);
    if (t) lua_pushinteger(L, (int)t->getAlarmState()); else lua_pushnil(L);
    return 1;
}

int TownBinding::setAlarmState(lua_State* L)
{
    TownBase* t = getT(L, 1);
    if (!t) return luaL_error(L, "Town is nil");
    int s = (int)luaL_checkinteger(L, 2);
    t->setAlarmState((TownAlarmState)s);
    return 0;
}

int TownBinding::isActive(lua_State* L)       { TownBase* t = getT(L, 1); lua_pushboolean(L, t && t->isActive() ? 1 : 0); return 1; }
int TownBinding::isDead(lua_State* L)         { TownBase* t = getT(L, 1); lua_pushboolean(L, t && t->isDead() ? 1 : 0); return 1; }
int TownBinding::isOutpost(lua_State* L)      { TownBase* t = getT(L, 1); lua_pushboolean(L, t && t->isOutpost() ? 1 : 0); return 1; }
int TownBinding::isPublic(lua_State* L)       { TownBase* t = getT(L, 1); lua_pushboolean(L, t && t->isPublic() ? 1 : 0); return 1; }
int TownBinding::hasGates(lua_State* L)       { TownBase* t = getT(L, 1); lua_pushboolean(L, t && t->hasGates() ? 1 : 0); return 1; }
int TownBinding::isValid(lua_State* L)        { TownBase* t = getT(L, 1); lua_pushboolean(L, t && t->isValid() ? 1 : 0); return 1; }
int TownBinding::isNotFriendly(lua_State* L)  { TownBase* t = getT(L, 1); lua_pushboolean(L, t && t->isNotFriendly() ? 1 : 0); return 1; }

int TownBinding::setVisible(lua_State* L)
{
    TownBase* t = getT(L, 1);
    if (!t) return luaL_error(L, "Town is nil");
    t->setVisible(lua_toboolean(L, 2) != 0);
    return 0;
}

int TownBinding::setRecentlyDiscovered(lua_State* L)
{
    TownBase* t = getT(L, 1);
    if (!t) return luaL_error(L, "Town is nil");
    t->setRecentlyDiscovered(lua_toboolean(L, 2) != 0);
    return 0;
}

int TownBinding::distanceTo(lua_State* L)
{
    TownBase* t = getT(L, 1);
    if (!t) { lua_pushnumber(L, 0.0); return 1; }
    Ogre::Vector3 p(0.0f, 0.0f, 0.0f);
    if (!readVector3(L, 2, p)) return luaL_error(L, "distanceTo: expected {x,y,z}");
    lua_pushnumber(L, t->distanceTo(p));
    return 1;
}

int TownBinding::withinBordersRange(lua_State* L)
{
    TownBase* t = getT(L, 1);
    if (!t) { lua_pushboolean(L, 0); return 1; }
    Ogre::Vector3 p(0.0f, 0.0f, 0.0f);
    if (!readVector3(L, 2, p)) return luaL_error(L, "withinBordersRange: expected {x,y,z}");
    float mult = (float)luaL_optnumber(L, 3, 1.0);
    lua_pushboolean(L, t->withinBordersRange(p, mult) ? 1 : 0);
    return 1;
}

int TownBinding::getPowerStats(lua_State* L)
{
    TownBase* t = getT(L, 1);
    if (!t) return luaL_error(L, "Town is nil");
    Town* realTown = t->isTown();
    if (realTown) {
        lua_pushnumber(L, realTown->power_Stat);
        lua_pushnumber(L, realTown->maxPower_Stat);
    } else {
        lua_pushnumber(L, 0.0);
        lua_pushnumber(L, 0.0);
    }
    return 2;
}

int TownBinding::isMyTown(lua_State* L)
{
    TownBase* t = getT(L, 1);
    if (!t) return luaL_error(L, "Town is nil");
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

void TownBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TownBinding::gc },
        { "__tostring", TownBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getName",                TownBinding::getName },
        { "getPosition",            TownBinding::getPosition },
        { "getFaction",             TownBinding::getFaction },
        { "setFaction",             TownBinding::setFaction },
        { "getAlarmState",          TownBinding::getAlarmState },
        { "setAlarmState",          TownBinding::setAlarmState },
        { "isActive",               TownBinding::isActive },
        { "isDead",                 TownBinding::isDead },
        { "isOutpost",              TownBinding::isOutpost },
        { "isPublic",               TownBinding::isPublic },
        { "hasGates",               TownBinding::hasGates },
        { "isValid",                TownBinding::isValid },
        { "isNotFriendly",          TownBinding::isNotFriendly },
        { "setVisible",             TownBinding::setVisible },
        { "setRecentlyDiscovered",  TownBinding::setRecentlyDiscovered },
        { "distanceTo",             TownBinding::distanceTo },
        { "withinBordersRange",     TownBinding::withinBordersRange },
        { "getPowerStats",          TownBinding::getPowerStats },
        { "isMyTown",               TownBinding::isMyTown },
        { 0, 0 }
    };
    registerClass(L, TownBinding::getMetatableName(), meta, methods, TownBinding::index, TownBinding::newindex);
}

} // namespace KenshiLua
