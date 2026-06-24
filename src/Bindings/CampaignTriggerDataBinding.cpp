#include "pch.h"
#include "kenshi\Dialogue.h"
#include "CampaignTriggerDataBinding.h"
#include "GameDataBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static CampaignTriggerData* getB(lua_State* L, int idx)
{
    return checkObject<CampaignTriggerData>(L, idx, CampaignTriggerDataBinding::getMetatableName());
}

// --- Getters for CampaignTriggerData ---
static int CampaignTriggerData_get_what(lua_State* L)
{
    CampaignTriggerData* b = getB(L, 1);
    if (!b) return luaL_error(L, "CampaignTriggerData is nil");
    return pushObject<GameData>(L, b->what, GameDataBinding::getMetatableName());
}

static int CampaignTriggerData_get_minTime(lua_State* L)
{
    CampaignTriggerData* b = getB(L, 1);
    if (!b) return luaL_error(L, "CampaignTriggerData is nil");
    lua_pushinteger(L, b->minTime);
    return 1;
}

static int CampaignTriggerData_get_maxTime(lua_State* L)
{
    CampaignTriggerData* b = getB(L, 1);
    if (!b) return luaL_error(L, "CampaignTriggerData is nil");
    lua_pushinteger(L, b->maxTime);
    return 1;
}

static int CampaignTriggerData_get_chance(lua_State* L)
{
    CampaignTriggerData* b = getB(L, 1);
    if (!b) return luaL_error(L, "CampaignTriggerData is nil");
    lua_pushnumber(L, b->chance);
    return 1;
}

// --- Setters for CampaignTriggerData ---
static int CampaignTriggerData_set_what(lua_State* L)
{
    CampaignTriggerData* b = getB(L, 1);
    if (!b) return luaL_error(L, "CampaignTriggerData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for what");
}

static int CampaignTriggerData_set_minTime(lua_State* L)
{
    CampaignTriggerData* b = getB(L, 1);
    if (!b) return luaL_error(L, "CampaignTriggerData is nil");
    b->minTime = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CampaignTriggerData_set_maxTime(lua_State* L)
{
    CampaignTriggerData* b = getB(L, 1);
    if (!b) return luaL_error(L, "CampaignTriggerData is nil");
    b->maxTime = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CampaignTriggerData_set_chance(lua_State* L)
{
    CampaignTriggerData* b = getB(L, 1);
    if (!b) return luaL_error(L, "CampaignTriggerData is nil");
    b->chance = (float)luaL_checknumber(L, 2);
    return 0;
}



int CampaignTriggerDataBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CampaignTriggerDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CampaignTriggerData object");
    return 1;
}

void CampaignTriggerDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CampaignTriggerDataBinding::gc },
        { "__tostring", CampaignTriggerDataBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        CampaignTriggerDataBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CampaignTriggerDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, CampaignTriggerData_get_what);
    lua_setfield(L, -2, "what");
    lua_pushcfunction(L, CampaignTriggerData_get_minTime);
    lua_setfield(L, -2, "minTime");
    lua_pushcfunction(L, CampaignTriggerData_get_maxTime);
    lua_setfield(L, -2, "maxTime");
    lua_pushcfunction(L, CampaignTriggerData_get_chance);
    lua_setfield(L, -2, "chance");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, CampaignTriggerData_set_what);
    lua_setfield(L, -2, "what");
    lua_pushcfunction(L, CampaignTriggerData_set_minTime);
    lua_setfield(L, -2, "minTime");
    lua_pushcfunction(L, CampaignTriggerData_set_maxTime);
    lua_setfield(L, -2, "maxTime");
    lua_pushcfunction(L, CampaignTriggerData_set_chance);
    lua_setfield(L, -2, "chance");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua