#include "pch.h"
#include "Bindings/Dialogue/CampaignTriggerDataBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Dialogue.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static CampaignTriggerData* getS(lua_State* L, int idx)
{
    return checkObject<CampaignTriggerData>(L, idx, CampaignTriggerDataBinding::getMetatableName());
}

int CampaignTriggerDataBinding::gc(lua_State* L) { return noopGc(L); }

int CampaignTriggerDataBinding::tostring(lua_State* L)
{
    CampaignTriggerData* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int CampaignTriggerDataBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, CampaignTriggerDataBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    CampaignTriggerData* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "what") == 0) { return pushObject<GameData>(L, s->what, GameDataBinding::getMetatableName()); }
    if (strcmp(key, "minTime") == 0) { lua_pushinteger(L, s->minTime); return 1; }
    if (strcmp(key, "maxTime") == 0) { lua_pushinteger(L, s->maxTime); return 1; }
    if (strcmp(key, "chance") == 0) { lua_pushnumber(L, s->chance); return 1; }

    lua_pushnil(L);
    return 1;
}

int CampaignTriggerDataBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    CampaignTriggerData* s = getS(L, 1);
    if (!s) return luaL_error(L, "CampaignTriggerData is nil");

    // TODO GameData* what; unsupported __newindex type from header line 126
    if (strcmp(key, "minTime") == 0) { s->minTime = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "maxTime") == 0) { s->maxTime = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "chance") == 0) { s->chance = (float)luaL_checknumber(L, 3); return 0; }

    return luaL_error(L, "unknown or read-only field '%s'", key);
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
    registerClass(L, CampaignTriggerDataBinding::getMetatableName(), meta, methods, CampaignTriggerDataBinding::index, CampaignTriggerDataBinding::newindex);
}

} // namespace KenshiLua