#include "pch.h"
#include "Bindings/BountyBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Bounty.h>
#include <new>
#include <cstdio>
#include <cstring>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

void BountyEnumBinding::registerCrimeEnum(lua_State* L)
{
    lua_newtable(L);

    lua_pushinteger(L, CrimeEnum::CRIME_NONE);
    lua_setfield(L, -2, "CRIME_NONE");

    lua_pushinteger(L, CrimeEnum::CRIME_ENSLAVING);
    lua_setfield(L, -2, "CRIME_ENSLAVING");

    lua_pushinteger(L, CrimeEnum::CRIME_LOCKPICKING);
    lua_setfield(L, -2, "CRIME_LOCKPICKING");

    lua_pushinteger(L, CrimeEnum::CRIME_STEALING);
    lua_setfield(L, -2, "CRIME_STEALING");

    lua_pushinteger(L, CrimeEnum::CRIME_MURDER);
    lua_setfield(L, -2, "CRIME_MURDER");

    lua_pushinteger(L, CrimeEnum::CRIME_ASSAULT);
    lua_setfield(L, -2, "CRIME_ASSAULT");

    lua_pushinteger(L, CrimeEnum::CRIME_ASSAULT_VIP);
    lua_setfield(L, -2, "CRIME_ASSAULT_VIP");

    lua_pushinteger(L, CrimeEnum::CRIME_SLAVE_FREEING);
    lua_setfield(L, -2, "CRIME_SLAVE_FREEING");

    lua_pushinteger(L, CrimeEnum::CRIME_SMUGGLING);
    lua_setfield(L, -2, "CRIME_SMUGGLING");

    lua_pushinteger(L, CrimeEnum::CRIME_TERRORISM);
    lua_setfield(L, -2, "CRIME_TERRORISM");

    lua_pushinteger(L, CrimeEnum::CRIME_LOOTING);
    lua_setfield(L, -2, "CRIME_LOOTING");

    lua_pushinteger(L, CrimeEnum::CRIME_TRESSPASSING);
    lua_setfield(L, -2, "CRIME_TRESSPASSING");

    lua_pushinteger(L, CrimeEnum::CRIME_ESCAPE_PRISON);
    lua_setfield(L, -2, "CRIME_ESCAPE_PRISON");

    lua_pushinteger(L, CrimeEnum::CRIME_FENCING);
    lua_setfield(L, -2, "CRIME_FENCING");

    lua_pushinteger(L, CrimeEnum::CRIME_FARM_EATING);
    lua_setfield(L, -2, "CRIME_FARM_EATING");

    lua_pushinteger(L, CrimeEnum::CRIME_KIDNAPPING);
    lua_setfield(L, -2, "CRIME_KIDNAPPING");

    lua_pushinteger(L, CrimeEnum::CRIME_UNIFORM_THEFT);
    lua_setfield(L, -2, "CRIME_UNIFORM_THEFT");

    lua_pushinteger(L, CrimeEnum::CRIME_END);
    lua_setfield(L, -2, "CRIME_END");

    lua_setglobal(L, "CrimeEnum");
}

static Bounty* getB(lua_State* L, int idx)
{
    return (Bounty*)luaL_checkudata(L, idx, BountyBinding::getMetatableName());
}

int BountyBinding::pushBounty(lua_State* L, const Bounty& b)
{
    void* mem = lua_newuserdata(L, sizeof(Bounty));
    new (mem) Bounty(b);
    luaL_getmetatable(L, BountyBinding::getMetatableName());
    lua_setmetatable(L, -2);
    return 1;
}

int BountyBinding::gc(lua_State* L)
{
    Bounty* b = (Bounty*)luaL_checkudata(L, 1, getMetatableName());
    if (b != 0) b->~Bounty();
    return 0;
}

int BountyBinding::tostring(lua_State* L)
{
    Bounty* b = getB(L, 1);
    if (b == 0) { lua_pushstring(L, "Bounty:nil"); return 1; }
    char buf[160];
    _snprintf(buf, sizeof(buf), "Bounty(amount=%d, claimed=%s)", b->amount, b->bountyHasBeenClaimedOnce ? "true" : "false");
    lua_pushstring(L, buf);
    return 1;
}

int BountyBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, BountyBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    Bounty* b = getB(L, 1);
    if (b == 0) { lua_pushnil(L); return 1; }

    // --- integer members ---
    if (strcmp(key, "amount") == 0) { lua_pushinteger(L, b->amount); return 1; }
    if (strcmp(key, "crimes") == 0) { lua_pushinteger(L, b->crimes); return 1; }

    // --- boolean members ---
    if (strcmp(key, "bountyHasBeenClaimedOnce") == 0 || strcmp(key, "claimed") == 0) {
        lua_pushboolean(L, b->bountyHasBeenClaimedOnce ? 1 : 0);
        return 1;
    }

    lua_pushnil(L);
    return 1;
}

int BountyBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    Bounty* b = getB(L, 1);
    if (b == 0) return luaL_error(L, "Bounty is nil");

    // --- writable properties ---
    if (strcmp(key, "amount") == 0) {
        b->amount = (int)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "crimes") == 0) {
        b->crimes = (unsigned int)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "bountyHasBeenClaimedOnce") == 0 || strcmp(key, "claimed") == 0) {
        b->bountyHasBeenClaimedOnce = (lua_toboolean(L, 3) != 0);
        return 0;
    }

    return luaL_error(L, "Bounty: field '%s' is read-only or does not exist", key);
}

int BountyBinding::addCrime(lua_State* L)
{
    Bounty* b = getB(L, 1);
    if (b == 0) return luaL_error(L, "Bounty is nil");
    int crime = (int)luaL_checkinteger(L, 2);
    b->addCrime((CrimeEnum)crime);
    return 0;
}

int BountyBinding::hasCrime(lua_State* L)
{
    Bounty* b = getB(L, 1);
    if (b == 0) return luaL_error(L, "Bounty is nil");
    int crime = (int)luaL_checkinteger(L, 2);
    lua_pushboolean(L, b->hasCrime((CrimeEnum)crime) ? 1 : 0);
    return 1;
}

void BountyBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BountyBinding::gc },
        { "__tostring", BountyBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "addCrime", BountyBinding::addCrime },
        { "hasCrime", BountyBinding::hasCrime },
        { 0, 0 }
    };
    registerClass(L, BountyBinding::getMetatableName(), meta, methods, BountyBinding::index, BountyBinding::newindex);
}

} // namespace KenshiLua
