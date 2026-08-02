#include "pch.h"
#include "KENSHI\Bounty.h"
#include "BountyBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Util/TimeOfDayBinding.h"

namespace KenshiLua
{

static Bounty* getInstance(lua_State* L, int idx)
{
    return checkObject<Bounty>(L, idx, BountyBinding::getMetatableName());
}

// --- Getters for Bounty ---
static int Bounty_get_amount(lua_State* L)
{
    Bounty* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Bounty is nil");
    lua_pushinteger(L, instance->amount);
    return 1;
}

static int Bounty_get_crimes(lua_State* L)
{
    Bounty* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Bounty is nil");
    lua_pushinteger(L, instance->crimes);
    return 1;
}

static int Bounty_get_bountyHasBeenClaimedOnce(lua_State* L)
{
    Bounty* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Bounty is nil");
    lua_pushboolean(L, instance->bountyHasBeenClaimedOnce ? 1 : 0);
    return 1;
}

static int Bounty_get_bountyAssignmentStartedTime(lua_State* L)
{
    Bounty* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Bounty is nil");
    return pushObject<TimeOfDay>(L, &instance->bountyAssignmentStartedTime, TimeOfDayBinding::getMetatableName());
}

// --- Setters for Bounty ---
static int Bounty_set_amount(lua_State* L)
{
    Bounty* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Bounty is nil");
    instance->amount = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Bounty_set_crimes(lua_State* L)
{
    Bounty* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Bounty is nil");
    instance->crimes = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int Bounty_set_bountyHasBeenClaimedOnce(lua_State* L)
{
    Bounty* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Bounty is nil");
    instance->bountyHasBeenClaimedOnce = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Bounty_set_bountyAssignmentStartedTime(lua_State* L)
{
    Bounty* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Bounty is nil");
    instance->bountyAssignmentStartedTime = *checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    return 0;
}

int BountyBinding::_CONSTRUCTOR(lua_State* L)
{
    Bounty* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Bounty is nil");

    Bounty* result = instance->_CONSTRUCTOR();
    return pushObject<Bounty>(L, result, BountyBinding::getMetatableName());
}

int BountyBinding::addCrime(lua_State* L)
{
    Bounty* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Bounty is nil");
    
    CrimeEnum crime = (CrimeEnum)luaL_checkinteger(L, 2);
    instance->addCrime(crime);
    return 0;
}

int BountyBinding::hasCrime(lua_State* L)
{
    Bounty* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Bounty is nil");
    
    CrimeEnum crime = (CrimeEnum)luaL_checkinteger(L, 2);
    lua_pushboolean(L, instance->hasCrime(crime) ? 1 : 0);
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
    registerGetter(L, "amount", Bounty_get_amount);
    registerGetter(L, "crimes", Bounty_get_crimes);
    registerGetter(L, "bountyHasBeenClaimedOnce", Bounty_get_bountyHasBeenClaimedOnce);
    registerGetter(L, "bountyAssignmentStartedTime", Bounty_get_bountyAssignmentStartedTime);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "amount", Bounty_set_amount);
    registerSetter(L, "crimes", Bounty_set_crimes);
    registerSetter(L, "bountyHasBeenClaimedOnce", Bounty_set_bountyHasBeenClaimedOnce);
    registerSetter(L, "bountyAssignmentStartedTime", Bounty_set_bountyAssignmentStartedTime);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua