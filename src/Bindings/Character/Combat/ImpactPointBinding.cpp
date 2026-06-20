#include "pch.h"
#include "Bindings/Character/Combat/ImpactPointBinding.h"
#include "Bindings/Core/EnumBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/CombatTechniqueData.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static CombatTechniqueData::ImpactPoint* getIP(lua_State* L, int idx)
{
    return checkObject<CombatTechniqueData::ImpactPoint>(L, idx, ImpactPointBinding::getMetatableName());
}

int ImpactPointBinding::gc(lua_State* L) { return noopGc(L); }

int ImpactPointBinding::tostring(lua_State* L)
{
    CombatTechniqueData::ImpactPoint* ip = getIP(L, 1);
    return genericTostringPtr(L, "%s", ip);
}

int ImpactPointBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, ImpactPointBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    CombatTechniqueData::ImpactPoint* ip = getIP(L, 1);
    if (!ip) { lua_pushnil(L); return 1; }

    if (strcmp(key, "direction") == 0) { lua_pushinteger(L, (lua_Integer)ip->direction); return 1; }
    if (strcmp(key, "power") == 0) { lua_pushnumber(L, ip->power); return 1; }
    if (strcmp(key, "impactAnimationFrame") == 0) { lua_pushnumber(L, ip->impactAnimationFrame); return 1; }
    if (strcmp(key, "motionStopsAnimationFrame") == 0) { lua_pushnumber(L, ip->motionStopsAnimationFrame); return 1; }
    if (strcmp(key, "limb") == 0) { lua_pushinteger(L, (lua_Integer)ip->limb); return 1; }

    lua_pushnil(L);
    return 1;
}

int ImpactPointBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    CombatTechniqueData::ImpactPoint* ip = getIP(L, 1);
    if (!ip) return luaL_error(L, "ImpactPoint is nil");

    if (strcmp(key, "direction") == 0) { ip->direction = (CutDirection)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "power") == 0) { ip->power = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "impactAnimationFrame") == 0) { ip->impactAnimationFrame = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "motionStopsAnimationFrame") == 0) { ip->motionStopsAnimationFrame = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "limb") == 0) { ip->limb = (RobotLimbs::Limb)luaL_checkinteger(L, 3); return 0; }

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int ImpactPointBinding::__CONSTRUCTOR(lua_State* L)
{
    CombatTechniqueData::ImpactPoint* ip = (CombatTechniqueData::ImpactPoint*)malloc(sizeof(CombatTechniqueData::ImpactPoint));
    if (ip) {
        memset(ip, 0, sizeof(CombatTechniqueData::ImpactPoint));
        ip->power = 1.0f;
    }
    pushObject<CombatTechniqueData::ImpactPoint>(L, ip, ImpactPointBinding::getMetatableName());
    return 1;
}

int ImpactPointBinding::assign(lua_State* L)
{
    CombatTechniqueData::ImpactPoint* ip = getIP(L, 1);
    CombatTechniqueData::ImpactPoint* other = getIP(L, 2);
    if (ip && other) {
        ip->direction = other->direction;
        ip->power = other->power;
        ip->impactAnimationFrame = other->impactAnimationFrame;
        ip->motionStopsAnimationFrame = other->motionStopsAnimationFrame;
        ip->limb = other->limb;
    }
    return 0;
}

void ImpactPointBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ImpactPointBinding::gc },
        { "__tostring", ImpactPointBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "__constructor", ImpactPointBinding::__CONSTRUCTOR },
        { "operator=", ImpactPointBinding::assign },
        { 0, 0 }
    };
    registerClass(L, ImpactPointBinding::getMetatableName(), meta, methods, ImpactPointBinding::index, ImpactPointBinding::newindex);

    // Expose ImpactPoint metatable globally so scripts can call its constructor/methods
    luaL_getmetatable(L, ImpactPointBinding::getMetatableName());
    lua_setglobal(L, "ImpactPoint");
}

} // namespace KenshiLua