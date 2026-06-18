#include "pch.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/TownBinding.h"
#include "Lua/BindingHelpers.h"
#include <kenshi/Platoon.h>

#include <kenshi/Faction.h>
#include <kenshi/FactionRelations.h>

#include <cstdio>

namespace KenshiLua
{

Faction* getFactionFromLua(lua_State* L, int idx)
{
    return checkObject<Faction>(L, idx, FactionBinding::getMetatableName());
}

int FactionBinding::gc(lua_State* L)       { return noopGc(L); }

int FactionBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    // 1. Check the metatable first so obj:method() syntax continues to work.
    luaL_getmetatable(L, FactionBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;   // found a method - return it
    lua_pop(L, 2);  // pop nil result + metatable

    // 2. Fall through to raw member variable access.
    Faction* f = getFactionFromLua(L, 1);
    if (!f) { lua_pushnil(L); return 1; }

    // --- boolean members ---
    if (strcmp(key, "isThePlayer") == 0) { lua_pushboolean(L, f->isThePlayer() ? 1 : 0); return 1; }
    if (strcmp(key, "isNotARealFaction") == 0 || strcmp(key, "notARealFaction") == 0) { lua_pushboolean(L, f->isNotARealFaction() ? 1 : 0); return 1; }
    if (strcmp(key, "isAntiSlavery") == 0) { lua_pushboolean(L, f->isAntiSlavery() ? 1 : 0); return 1; }
    if (strcmp(key, "isALawEnforcementFaction") == 0) { lua_pushboolean(L, f->isALawEnforcementFaction ? 1 : 0); return 1; }

    // --- float members ---
    if (strcmp(key, "prosperityMultiplier") == 0) { lua_pushnumber(L, f->getProsperityMultiplier()); return 1; }
    if (strcmp(key, "roadPreference") == 0) { lua_pushnumber(L, f->getRoadPreference()); return 1; }

    // --- integer members ---
    if (strcmp(key, "factionSize") == 0) { lua_pushinteger(L, f->getFactionSize()); return 1; }

    // --- string members ---
    if (strcmp(key, "name") == 0) { lua_pushstring(L, f->name.c_str()); return 1; }

    // --- boolean members extra ---
    if (strcmp(key, "allowSlavesWeapons") == 0) { lua_pushboolean(L, f->allowSlavesWeapons ? 1 : 0); return 1; }

    // --- integer/enum members ---
    if (strcmp(key, "diplomatTimeStamp") == 0) { lua_pushinteger(L, f->diplomatTimeStamp); return 1; }
    if (strcmp(key, "fundamentalNPCType") == 0) { lua_pushinteger(L, (int)f->fundamentalNPCType); return 1; }

    // --- unique object members ---
    if (strcmp(key, "lawEnforcementFaction") == 0 || strcmp(key, "myLawEnforcementFaction") == 0) {
        return pushObject<Faction>(L, f->getLawEnforcementFaction(), FactionBinding::getMetatableName());
    }
    if (strcmp(key, "ranks") == 0) {
        lua_createtable(L, f->ranks.size(), 0);
        for (uint32_t i = 0; i < f->ranks.size(); ++i) {
            lua_pushstring(L, f->ranks[i].c_str());
            lua_rawseti(L, -2, i + 1);
        }
        return 1;
    }
    if (strcmp(key, "activePlatoons") == 0) {
        lua_createtable(L, f->activePlatoons.size(), 0);
        for (uint32_t i = 0; i < f->activePlatoons.size(); ++i) {
            Platoon* p = f->activePlatoons[i];
            if (p && p->activePlatoon) {
                pushObject<ActivePlatoon>(L, p->activePlatoon, PlatoonBinding::getMetatableName());
            } else {
                pushObject<Platoon>(L, p, PlatoonBinding::getMetatableName());
            }
            lua_rawseti(L, -2, i + 1);
        }
        return 1;
    }
    if (strcmp(key, "unloadedPlatoons") == 0) {
        lua_createtable(L, f->unloadedPlatoons.size(), 0);
        for (uint32_t i = 0; i < f->unloadedPlatoons.size(); ++i) {
            pushObject<Platoon>(L, f->unloadedPlatoons[i], PlatoonBinding::getMetatableName());
            lua_rawseti(L, -2, i + 1);
        }
        return 1;
    }

    lua_pushnil(L);
    return 1;
}

int FactionBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    Faction* f = getFactionFromLua(L, 1);
    if (!f) return luaL_error(L, "Faction is nil");

    // --- writable string members ---
    if (strcmp(key, "name") == 0) {
        f->setName(luaL_checkstring(L, 3));
        return 0;
    }
    if (strcmp(key, "allowSlavesWeapons") == 0) {
        f->allowSlavesWeapons = (lua_toboolean(L, 3) != 0);
        return 0;
    }
    if (strcmp(key, "diplomatTimeStamp") == 0) {
        f->diplomatTimeStamp = (int)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "fundamentalNPCType") == 0) {
        f->fundamentalNPCType = (CharacterTypeEnum)luaL_checkinteger(L, 3);
        return 0;
    }

    if (strcmp(key, "ranks") == 0) return luaL_error(L, "Faction: ranks is read-only");
    if (strcmp(key, "activePlatoons") == 0) return luaL_error(L, "Faction: activePlatoons is read-only");
    if (strcmp(key, "unloadedPlatoons") == 0) return luaL_error(L, "Faction: unloadedPlatoons is read-only");

    return luaL_error(L, "Faction: field '%s' is read-only or does not exist", key);
}

int FactionBinding::tostring(lua_State* L)
{
    Faction* f = getFactionFromLua(L, 1);
    if (!f) { lua_pushstring(L, "Faction:nil"); return 1; }
    char buf[160];
    _snprintf(buf, sizeof(buf), "Faction:%s(%p)", f->name.c_str(), (void*)f);
    lua_pushstring(L, buf);
    return 1;
}

int FactionBinding::getName(lua_State* L)
{
    Faction* f = getFactionFromLua(L, 1);
    if (f) lua_pushstring(L, f->name.c_str()); else lua_pushnil(L);
    return 1;
}

int FactionBinding::setName(lua_State* L)
{
    Faction* f = getFactionFromLua(L, 1);
    if (!f) return luaL_error(L, "Faction is nil");
    f->setName(luaL_checkstring(L, 2));
    return 0;
}

int FactionBinding::isThePlayer(lua_State* L)              { Faction* f = getFactionFromLua(L, 1); lua_pushboolean(L, f && f->isThePlayer() ? 1 : 0); return 1; }
int FactionBinding::isNotARealFaction(lua_State* L)        { Faction* f = getFactionFromLua(L, 1); lua_pushboolean(L, f && f->isNotARealFaction() ? 1 : 0); return 1; }
int FactionBinding::isAntiSlavery(lua_State* L)            { Faction* f = getFactionFromLua(L, 1); lua_pushboolean(L, f && f->isAntiSlavery() ? 1 : 0); return 1; }
int FactionBinding::isALawEnforcementFaction(lua_State* L) { Faction* f = getFactionFromLua(L, 1); lua_pushboolean(L, f && f->isALawEnforcementFaction ? 1 : 0); return 1; }

int FactionBinding::getLawEnforcementFaction(lua_State* L)
{
    Faction* f = getFactionFromLua(L, 1);
    if (!f) { lua_pushnil(L); return 1; }
    return pushObject<Faction>(L, f->getLawEnforcementFaction(), FactionBinding::getMetatableName());
}

int FactionBinding::getFactionSize(lua_State* L)
{
    Faction* f = getFactionFromLua(L, 1);
    if (f) lua_pushinteger(L, f->getFactionSize()); else lua_pushinteger(L, 0);
    return 1;
}

int FactionBinding::getNumPlatoons(lua_State* L)
{
    Faction* f = getFactionFromLua(L, 1);
    if (!f) { lua_pushinteger(L, 0); return 1; }
    GameData* tmpl = (GameData*)lua_touserdata(L, 2);
    bool tempsOnly = lua_toboolean(L, 3) != 0;
    TownBase* home = TownBaseBinding::getTownBase(L, 4);
    lua_pushinteger(L, f->getNumPlatoons(tmpl, tempsOnly, home));
    return 1;
}

int FactionBinding::getProsperityMultiplier(lua_State* L)
{
    Faction* f = getFactionFromLua(L, 1);
    if (f) lua_pushnumber(L, f->getProsperityMultiplier()); else lua_pushnumber(L, 0.0);
    return 1;
}

int FactionBinding::getRoadPreference(lua_State* L)
{
    Faction* f = getFactionFromLua(L, 1);
    if (f) lua_pushnumber(L, f->getRoadPreference()); else lua_pushnumber(L, 0.0);
    return 1;
}

int FactionBinding::getRelation(lua_State* L)
{
    Faction* f = getFactionFromLua(L, 1);
    Faction* other = getFactionFromLua(L, 2);
    if (!f || !other || !f->relations) { lua_pushnumber(L, 0); return 1; }
    lua_pushnumber(L, f->relations->getFactionRelation(other));
    return 1;
}

int FactionBinding::setRelation(lua_State* L)
{
    Faction* f = getFactionFromLua(L, 1);
    if (!f) return luaL_error(L, "Faction is nil");
    Faction* other = getFactionFromLua(L, 2);
    if (!other) return luaL_error(L, "Target faction is nil");
    float rel = (float)luaL_checknumber(L, 3);
    if (f->relations) f->relations->setRelation(other, rel);
    return 0;
}

int FactionBinding::declareWar(lua_State* L)
{
    Faction* f = getFactionFromLua(L, 1);
    if (!f) return luaL_error(L, "Faction is nil");
    Faction* other = getFactionFromLua(L, 2);
    if (!other) return luaL_error(L, "declareWar: expected Faction userdata as argument 2");
    if (f->relations) f->relations->declareWar(other);
    return 0;
}

int FactionBinding::declarePeace(lua_State* L)
{
    Faction* f = getFactionFromLua(L, 1);
    if (!f) return luaL_error(L, "Faction is nil");
    Faction* other = getFactionFromLua(L, 2);
    if (!other) return luaL_error(L, "declarePeace: expected Faction userdata as argument 2");
    if (f->relations) f->relations->setNoLongerEnemies(other);
    return 0;
}

int FactionBinding::createPlatoon(lua_State* L)
{
    Faction* f = getFactionFromLua(L, 1);
    if (!f) return luaL_error(L, "Faction is nil");
    GameData* squadTemplate = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    if (!squadTemplate) return luaL_error(L, "createPlatoon: expected GameData userdata as argument 2");
    Ogre::Vector3 pos(0.0f, 0.0f, 0.0f);
    if (!readVector3(L, 3, pos)) return luaL_error(L, "createPlatoon: expected Vector3 table as argument 3");
    bool persistent = lua_toboolean(L, 4) != 0;
    
    Platoon* p = f->createNewEmptyUnloadedPlatoon(squadTemplate, pos, NULL, persistent);
    if (!p) { lua_pushnil(L); return 1; }
    
    if (p->activePlatoon) {
        return pushObject<ActivePlatoon>(L, p->activePlatoon, PlatoonBinding::getMetatableName());
    }
    return pushObject<Platoon>(L, p, PlatoonBinding::getMetatableName());
}

void FactionBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FactionBinding::gc },
        { "__tostring", FactionBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getName",                   FactionBinding::getName },
        { "setName",                   FactionBinding::setName },
        { "isThePlayer",               FactionBinding::isThePlayer },
        { "isNotARealFaction",         FactionBinding::isNotARealFaction },
        { "isAntiSlavery",             FactionBinding::isAntiSlavery },
        { "isALawEnforcementFaction",  FactionBinding::isALawEnforcementFaction },
        { "getLawEnforcementFaction",  FactionBinding::getLawEnforcementFaction },
        { "getFactionSize",            FactionBinding::getFactionSize },
        { "getNumPlatoons",            FactionBinding::getNumPlatoons },
        { "getProsperityMultiplier",   FactionBinding::getProsperityMultiplier },
        { "getRoadPreference",         FactionBinding::getRoadPreference },
        { "getRelation",               FactionBinding::getRelation },
        { "setRelation",               FactionBinding::setRelation },
        { "declareWar",                FactionBinding::declareWar },
        { "declarePeace",              FactionBinding::declarePeace },
        { "createPlatoon",             FactionBinding::createPlatoon },
        { 0, 0 }
    };
    registerClass(L, FactionBinding::getMetatableName(), meta, methods, FactionBinding::index, FactionBinding::newindex);
}

} // namespace KenshiLua
