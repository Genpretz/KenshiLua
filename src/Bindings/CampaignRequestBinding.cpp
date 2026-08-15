#include "pch.h"
#include "kenshi/FactionWarMgr.h"
#include "CampaignRequestBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/Util/TimeOfDayBinding.h"

namespace KenshiLua
{

typedef FactionWarMgr::CampaignRequest CampaignRequest;

static CampaignRequest* getInstance(lua_State* L, int idx)
{
    return checkObject<CampaignRequest>(L, idx, CampaignRequestBinding::getMetatableName());
}

// --- Getters for CampaignRequest ---
static int CampaignRequest_get_timeToStart(lua_State* L)
{
    CampaignRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignRequest is nil");
    return pushObject<TimeOfDay>(L, &instance->timeToStart, TimeOfDayBinding::getMetatableName());
}

static int CampaignRequest_get_data(lua_State* L)
{
    CampaignRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignRequest is nil");
    lua_pushlightuserdata(L, (void*)instance->data);
    return 1;
}

static int CampaignRequest_get_target(lua_State* L)
{
    CampaignRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignRequest is nil");
    return HandBinding::push(L, instance->target);
}

static int CampaignRequest_get_homeBase(lua_State* L)
{
    CampaignRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignRequest is nil");
    return HandBinding::push(L, instance->homeBase);
}

static int CampaignRequest_get_enemy(lua_State* L)
{
    CampaignRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignRequest is nil");
    return pushObject<Faction>(L, instance->enemy, FactionBinding::getMetatableName());
}

static int CampaignRequest_get_numAttempts(lua_State* L)
{
    CampaignRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignRequest is nil");
    lua_pushinteger(L, instance->numAttempts);
    return 1;
}

// --- Setters for CampaignRequest ---
static int CampaignRequest_set_timeToStart(lua_State* L)
{
    CampaignRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignRequest is nil");
    instance->timeToStart = *checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    return 0;
}

static int CampaignRequest_set_target(lua_State* L)
{
    CampaignRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignRequest is nil");
    instance->target = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int CampaignRequest_set_homeBase(lua_State* L)
{
    CampaignRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignRequest is nil");
    instance->homeBase = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int CampaignRequest_set_enemy(lua_State* L)
{
    CampaignRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignRequest is nil");
    instance->enemy = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

static int CampaignRequest_set_numAttempts(lua_State* L)
{
    CampaignRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignRequest is nil");
    instance->numAttempts = (int)luaL_checkinteger(L, 2);
    return 0;
}

int CampaignRequestBinding::tryToChangeTarget(lua_State* L)
{
    CampaignRequest* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignRequest is nil");

    bool result = instance->tryToChangeTarget();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CampaignRequestBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CampaignRequestBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CampaignRequest object");
    return 1;
}

void CampaignRequestBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CampaignRequestBinding::gc },
        { "__tostring", CampaignRequestBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "tryToChangeTarget", CampaignRequestBinding::tryToChangeTarget },
        { 0, 0 }
    };

    registerClass(
        L, 
        CampaignRequestBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CampaignRequestBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, CampaignRequest_get_timeToStart);
    lua_setfield(L, -2, "timeToStart");
    lua_pushcfunction(L, CampaignRequest_get_data);
    lua_setfield(L, -2, "data");
    lua_pushcfunction(L, CampaignRequest_get_target);
    lua_setfield(L, -2, "target");
    lua_pushcfunction(L, CampaignRequest_get_homeBase);
    lua_setfield(L, -2, "homeBase");
    lua_pushcfunction(L, CampaignRequest_get_enemy);
    lua_setfield(L, -2, "enemy");
    lua_pushcfunction(L, CampaignRequest_get_numAttempts);
    lua_setfield(L, -2, "numAttempts");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, CampaignRequest_set_timeToStart);
    lua_setfield(L, -2, "timeToStart");
    lua_pushcfunction(L, CampaignRequest_set_target);
    lua_setfield(L, -2, "target");
    lua_pushcfunction(L, CampaignRequest_set_homeBase);
    lua_setfield(L, -2, "homeBase");
    lua_pushcfunction(L, CampaignRequest_set_enemy);
    lua_setfield(L, -2, "enemy");
    lua_pushcfunction(L, CampaignRequest_set_numAttempts);
    lua_setfield(L, -2, "numAttempts");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua