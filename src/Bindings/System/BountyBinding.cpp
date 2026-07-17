#include "pch.h"
<<<<<<< HEAD:src/Bindings/System/BountyBinding.cpp
#include "Bindings/System/BountyBinding.h"
=======
#include "kenshi\Bounty.h"
#include "BountyBinding.h"
#include "EnumBinding.h"
#include "Bindings/Util/TimeOfDayBinding.h"
>>>>>>> main:src/Bindings/BountyBinding.cpp
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static Bounty* getB(lua_State* L, int idx)
{
    return checkObject<Bounty>(L, idx, BountyBinding::getMetatableName());
}

// --- Getters for Bounty ---
static int Bounty_get_amount(lua_State* L)
{
    Bounty* b = getB(L, 1);
    if (!b) return luaL_error(L, "Bounty is nil");
    lua_pushinteger(L, b->amount);
    return 1;
}

static int Bounty_get_crimes(lua_State* L)
{
    Bounty* b = getB(L, 1);
    if (!b) return luaL_error(L, "Bounty is nil");
    lua_pushinteger(L, b->crimes);
    return 1;
}

static int Bounty_get_bountyHasBeenClaimedOnce(lua_State* L)
{
    Bounty* b = getB(L, 1);
    if (!b) return luaL_error(L, "Bounty is nil");
    lua_pushboolean(L, b->bountyHasBeenClaimedOnce ? 1 : 0);
    return 1;
}

static int Bounty_get_bountyAssignmentStartedTime(lua_State* L)
{
    Bounty* b = getB(L, 1);
    if (!b) return luaL_error(L, "Bounty is nil");
    return pushObject<TimeOfDay>(L, &b->bountyAssignmentStartedTime, TimeOfDayBinding::getMetatableName());
}

// --- Setters for Bounty ---
static int Bounty_set_amount(lua_State* L)
{
    Bounty* b = getB(L, 1);
    if (!b) return luaL_error(L, "Bounty is nil");
    b->amount = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Bounty_set_crimes(lua_State* L)
{
    Bounty* b = getB(L, 1);
    if (!b) return luaL_error(L, "Bounty is nil");
    b->crimes = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int Bounty_set_bountyHasBeenClaimedOnce(lua_State* L)
{
    Bounty* b = getB(L, 1);
    if (!b) return luaL_error(L, "Bounty is nil");
    b->bountyHasBeenClaimedOnce = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Bounty_set_bountyAssignmentStartedTime(lua_State* L)
{
    Bounty* b = getB(L, 1);
    if (!b) return luaL_error(L, "Bounty is nil");
    TimeOfDay* val = checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    if (!val) return luaL_error(L, "Expected TimeOfDay object");
    b->bountyAssignmentStartedTime = *val;
    return 0;
}

int BountyBinding::_CONSTRUCTOR(lua_State* L)
{
    Bounty* b = getB(L, 1);
    if (!b) return luaL_error(L, "Bounty is nil");

    Bounty* result = b->_CONSTRUCTOR();
    return pushObject<Bounty>(L, result, BountyBinding::getMetatableName());
}

int BountyBinding::addCrime(lua_State* L)
{
    Bounty* b = getB(L, 1);
    if (!b) return luaL_error(L, "Bounty is nil");
    
    CrimeEnum crime = (CrimeEnum)luaL_checkinteger(L, 2);
    b->addCrime(crime);
    return 0;
}

int BountyBinding::hasCrime(lua_State* L)
{
    Bounty* b = getB(L, 1);
    if (!b) return luaL_error(L, "Bounty is nil");
    
    CrimeEnum crime = (CrimeEnum)luaL_checkinteger(L, 2);
    lua_pushboolean(L, b->hasCrime(crime) ? 1 : 0);
    return 1;
}

int BountyBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int BountyBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Bounty object");
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
        { "_CONSTRUCTOR", BountyBinding::_CONSTRUCTOR },
        { "addCrime", BountyBinding::addCrime },
        { "hasCrime", BountyBinding::hasCrime },
        { 0, 0 }
    };

    registerClass(
        L, 
        BountyBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, BountyBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, Bounty_get_amount);
    lua_setfield(L, -2, "amount");
    lua_pushcfunction(L, Bounty_get_crimes);
    lua_setfield(L, -2, "crimes");
    lua_pushcfunction(L, Bounty_get_bountyHasBeenClaimedOnce);
    lua_setfield(L, -2, "bountyHasBeenClaimedOnce");
    lua_pushcfunction(L, Bounty_get_bountyAssignmentStartedTime);
    lua_setfield(L, -2, "bountyAssignmentStartedTime");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, Bounty_set_amount);
    lua_setfield(L, -2, "amount");
    lua_pushcfunction(L, Bounty_set_crimes);
    lua_setfield(L, -2, "crimes");
    lua_pushcfunction(L, Bounty_set_bountyHasBeenClaimedOnce);
    lua_setfield(L, -2, "bountyHasBeenClaimedOnce");
    lua_pushcfunction(L, Bounty_set_bountyAssignmentStartedTime);
    lua_setfield(L, -2, "bountyAssignmentStartedTime");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua