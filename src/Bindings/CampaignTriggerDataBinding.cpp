#include "pch.h"
#include "kenshi\dialogue.h"
#include "CampaignTriggerDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{

static CampaignTriggerData* getInstance(lua_State* L, int idx)
{
    return checkObject<CampaignTriggerData>(L, idx, CampaignTriggerDataBinding::getMetatableName());
}

// --- Getters for CampaignTriggerData ---
static int CampaignTriggerData_get_what(lua_State* L)
{
    CampaignTriggerData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignTriggerData is nil");
    return pushObject<GameData>(L, instance->what, GameDataBinding::getMetatableName());
}

static int CampaignTriggerData_get_minTime(lua_State* L)
{
    CampaignTriggerData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignTriggerData is nil");
    lua_pushinteger(L, instance->minTime);
    return 1;
}

static int CampaignTriggerData_get_maxTime(lua_State* L)
{
    CampaignTriggerData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignTriggerData is nil");
    lua_pushinteger(L, instance->maxTime);
    return 1;
}

static int CampaignTriggerData_get_chance(lua_State* L)
{
    CampaignTriggerData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignTriggerData is nil");
    lua_pushnumber(L, instance->chance);
    return 1;
}

// --- Setters for CampaignTriggerData ---
static int CampaignTriggerData_set_what(lua_State* L)
{
    CampaignTriggerData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignTriggerData is nil");
    instance->what = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int CampaignTriggerData_set_minTime(lua_State* L)
{
    CampaignTriggerData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignTriggerData is nil");
    instance->minTime = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CampaignTriggerData_set_maxTime(lua_State* L)
{
    CampaignTriggerData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignTriggerData is nil");
    instance->maxTime = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CampaignTriggerData_set_chance(lua_State* L)
{
    CampaignTriggerData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CampaignTriggerData is nil");
    instance->chance = (float)luaL_checknumber(L, 2);
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
    registerGetter(L, "what", CampaignTriggerData_get_what);
    registerGetter(L, "minTime", CampaignTriggerData_get_minTime);
    registerGetter(L, "maxTime", CampaignTriggerData_get_maxTime);
    registerGetter(L, "chance", CampaignTriggerData_get_chance);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "what", CampaignTriggerData_set_what);
    registerSetter(L, "minTime", CampaignTriggerData_set_minTime);
    registerSetter(L, "maxTime", CampaignTriggerData_set_maxTime);
    registerSetter(L, "chance", CampaignTriggerData_set_chance);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua