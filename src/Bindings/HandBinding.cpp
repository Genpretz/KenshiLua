#include "pch.h"
#include "Bindings/HandBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/BuildingBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/TownBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/util/hand.h>
#include <kenshi/Character.h>
#include <kenshi/Platoon.h>
#include <kenshi/Item.h>
#include <kenshi/Town.h>

#include <new>
#include <cstdio>
#include <cstring>
#include <boost/functional/hash.hpp>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

std::size_t hash_value(const hand& h)
{
    std::size_t seed = 0;
    boost::hash_combine(seed, (int)h.type);
    boost::hash_combine(seed, h.container);
    boost::hash_combine(seed, h.containerSerial);
    boost::hash_combine(seed, h.index);
    boost::hash_combine(seed, h.serial);
    return seed;
}

namespace KenshiLua
{


static hand* checkHand(lua_State* L, int idx)
{
    return (hand*)luaL_checkudata(L, idx, HandBinding::getMetatableName());
}

int HandBinding::pushHand(lua_State* L, const hand& h)
{
    void* mem = lua_newuserdata(L, sizeof(hand));
    new (mem) hand(h);
    luaL_getmetatable(L, HandBinding::getMetatableName());
    lua_setmetatable(L, -2);
    return 1;
}

int HandBinding::gc(lua_State* L)
{
    hand* h = (hand*)luaL_checkudata(L, 1, getMetatableName());
    if (h) h->~hand();
    return 0;
}

int HandBinding::tostring(lua_State* L)
{
    hand* h = checkHand(L, 1);
    if (h) lua_pushstring(L, h->toString().c_str());
    else   lua_pushstring(L, "hand:nil");
    return 1;
}

int HandBinding::eq(lua_State* L)
{
    hand* a = checkHand(L, 1);
    hand* b = checkHand(L, 2);
    lua_pushboolean(L, (a && b && (*a == *b)) ? 1 : 0);
    return 1;
}

int HandBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    // 1. Check the metatable first so obj:method() syntax continues to work.
    luaL_getmetatable(L, HandBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;   // found a method - return it
    lua_pop(L, 2);  // pop nil result + metatable

    // 2. Fall through to raw member variable access.
    hand* h = checkHand(L, 1);
    if (!h) { lua_pushnil(L); return 1; }

    // --- boolean members ---
    if (strcmp(key, "isValid") == 0) { lua_pushboolean(L, h->isValid() ? 1 : 0); return 1; }
    if (strcmp(key, "isNull") == 0) { lua_pushboolean(L, h->isNull() ? 1 : 0); return 1; }

    // --- integer/enum members ---
    if (strcmp(key, "type") == 0) { lua_pushinteger(L, (int)h->type); return 1; }
    if (strcmp(key, "index") == 0) { lua_pushinteger(L, h->index); return 1; }
    if (strcmp(key, "serial") == 0) { lua_pushinteger(L, h->serial); return 1; }
    if (strcmp(key, "container") == 0) { lua_pushinteger(L, h->container); return 1; }
    if (strcmp(key, "containerSerial") == 0) { lua_pushinteger(L, h->containerSerial); return 1; }

    // --- unique object members ---
    if (strcmp(key, "character") == 0) {
        if (!h->isValid()) { lua_pushnil(L); return 1; }
        return pushObject<Character>(L, h->getCharacter(), CharacterBinding::getMetatableName());
    }
    if (strcmp(key, "platoon") == 0) {
        if (!h->isValid()) { lua_pushnil(L); return 1; }
        ActivePlatoon* ap = h->getActivePlatoon();
        if (ap) return pushObject<ActivePlatoon>(L, ap, PlatoonBinding::getMetatableName());
        Platoon* p = h->getPlatoon();
        return pushObject<Platoon>(L, p, PlatoonBinding::getMetatableName());
    }
    if (strcmp(key, "building") == 0) {
        if (!h->isValid()) { lua_pushnil(L); return 1; }
        return pushObject<Building>(L, h->getBuilding(), BuildingBinding::getMetatableName());
    }
    if (strcmp(key, "item") == 0) {
        if (!h->isValid()) { lua_pushnil(L); return 1; }
        return ItemBinding::pushItem(L, h->getItem());
    }
    if (strcmp(key, "town") == 0) {
        if (!h->isValid()) { lua_pushnil(L); return 1; }
        return TownBaseBinding::pushTownBase(L, h->getTown());
    }

    lua_pushnil(L);
    return 1;
}

int HandBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    hand* h = checkHand(L, 1);
    if (!h) return luaL_error(L, "hand is nil");

    // --- writable properties ---
    if (strcmp(key, "type") == 0) {
        h->type = (itemType)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "index") == 0) {
        h->index = (unsigned int)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "serial") == 0) {
        h->serial = (unsigned int)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "container") == 0) {
        h->container = (unsigned int)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "containerSerial") == 0) {
        h->containerSerial = (unsigned int)luaL_checkinteger(L, 3);
        return 0;
    }

    return luaL_error(L, "hand: field '%s' is read-only or does not exist", key);
}

int HandBinding::isValid(lua_State* L)           { hand* h = checkHand(L, 1); lua_pushboolean(L, h && h->isValid() ? 1 : 0); return 1; }
int HandBinding::isNull(lua_State* L)            { hand* h = checkHand(L, 1); lua_pushboolean(L, !h || h->isNull() ? 1 : 0); return 1; }
int HandBinding::getType(lua_State* L)           { hand* h = checkHand(L, 1); if (h) lua_pushinteger(L, (int)h->type); else lua_pushnil(L); return 1; }
int HandBinding::getIndex(lua_State* L)          { hand* h = checkHand(L, 1); if (h) lua_pushinteger(L, h->index); else lua_pushnil(L); return 1; }
int HandBinding::getSerial(lua_State* L)         { hand* h = checkHand(L, 1); if (h) lua_pushinteger(L, h->serial); else lua_pushnil(L); return 1; }
int HandBinding::getContainer(lua_State* L)      { hand* h = checkHand(L, 1); if (h) lua_pushinteger(L, h->container); else lua_pushnil(L); return 1; }
int HandBinding::getContainerSerial(lua_State* L){ hand* h = checkHand(L, 1); if (h) lua_pushinteger(L, h->containerSerial); else lua_pushnil(L); return 1; }

int HandBinding::getCharacter(lua_State* L)
{
    hand* h = checkHand(L, 1);
    if (!h || !h->isValid()) { lua_pushnil(L); return 1; }
    return pushObject<Character>(L, h->getCharacter(), CharacterBinding::getMetatableName());
}

int HandBinding::getPlatoon(lua_State* L)
{
    hand* h = checkHand(L, 1);
    if (!h || !h->isValid()) { lua_pushnil(L); return 1; }
    // Prefer ActivePlatoon since that's what active gameplay uses.
    ActivePlatoon* ap = h->getActivePlatoon();
    if (ap) return pushObject<ActivePlatoon>(L, ap, PlatoonBinding::getMetatableName());
    Platoon* p = h->getPlatoon();
    return pushObject<Platoon>(L, p, PlatoonBinding::getMetatableName());
}

int HandBinding::getBuilding(lua_State* L)
{
    hand* h = checkHand(L, 1);
    if (!h || !h->isValid()) { lua_pushnil(L); return 1; }
    return pushObject<Building>(L, h->getBuilding(), BuildingBinding::getMetatableName());
}

int HandBinding::getItem(lua_State* L)
{
    hand* h = checkHand(L, 1);
    if (!h || !h->isValid()) { lua_pushnil(L); return 1; }
    return ItemBinding::pushItem(L, h->getItem());
}

int HandBinding::getTown(lua_State* L)
{
    hand* h = checkHand(L, 1);
    if (!h || !h->isValid()) { lua_pushnil(L); return 1; }
    return TownBaseBinding::pushTownBase(L, h->getTown());
}

void HandBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg metamethods[] = {
        { "__gc",       HandBinding::gc },
        { "__tostring", HandBinding::tostring },
        { "__eq",       HandBinding::eq },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "isValid",            HandBinding::isValid },
        { "isNull",             HandBinding::isNull },
        { "getType",            HandBinding::getType },
        { "getIndex",           HandBinding::getIndex },
        { "getSerial",          HandBinding::getSerial },
        { "getContainer",       HandBinding::getContainer },
        { "getContainerSerial", HandBinding::getContainerSerial },
        { "getCharacter",       HandBinding::getCharacter },
        { "getPlatoon",         HandBinding::getPlatoon },
        { "getBuilding",        HandBinding::getBuilding },
        { "getItem",            HandBinding::getItem },
        { "getTown",            HandBinding::getTown },
        { 0, 0 }
    };
    registerClass(L, HandBinding::getMetatableName(), metamethods, methods, HandBinding::index, HandBinding::newindex);
}

} // namespace KenshiLua
