#include "pch.h"
#include "kenshi/GunClass.h"
#include "GunClassTurretBinding.h"
#include "GunClassBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Building/TurretBuildingBinding.h"

namespace KenshiLua
{

static_assert(offsetof(GunClassTurret, lastTarget) == 0x118, "GunClassTurret::lastTarget offset mismatch");
static_assert(offsetof(GunClassTurret, turretBuilding) == 0x128, "GunClassTurret::turretBuilding offset mismatch");

static GunClassTurret* getInstance(lua_State* L, int idx)
{
    return checkObject<GunClassTurret>(L, idx, GunClassTurretBinding::getMetatableName());
}

static int GunClassTurret_get_lastTarget(lua_State* L)
{
    GunClassTurret* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClassTurret is nil");
    pushVector3(L, instance->lastTarget);
    return 1;
}

static int GunClassTurret_set_lastTarget(lua_State* L)
{
    GunClassTurret* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClassTurret is nil");
    readVector3(L, 2, instance->lastTarget);
    return 0;
}

static int GunClassTurret_get_turretBuilding(lua_State* L)
{
    GunClassTurret* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClassTurret is nil");
    if (!instance->turretBuilding) { lua_pushnil(L); return 1; }
    return pushObject<TurretBuilding>(L, instance->turretBuilding, TurretBuildingBinding::getMetatableName());
}

static int GunClassTurret_set_turretBuilding(lua_State* L)
{
    GunClassTurret* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClassTurret is nil");
    instance->turretBuilding = lua_isnoneornil(L, 2) ? nullptr : checkObject<TurretBuilding>(L, 2, TurretBuildingBinding::getMetatableName());
    return 0;
}

int GunClassTurretBinding::isOutOfPower(lua_State* L)
{
    GunClassTurret* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClassTurret is nil");
    lua_pushboolean(L, instance->isOutOfPower() ? 1 : 0);
    return 1;
}

int GunClassTurretBinding::_NV_isOutOfPower(lua_State* L)
{
    GunClassTurret* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClassTurret is nil");
    lua_pushboolean(L, instance->_NV_isOutOfPower() ? 1 : 0);
    return 1;
}

int GunClassTurretBinding::clearEntitesPtr(lua_State* L)
{
    GunClassTurret* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClassTurret is nil");
    instance->clearEntitesPtr();
    return 0;
}

int GunClassTurretBinding::gc(lua_State* L)
{
    return noopGc(L);
}

int GunClassTurretBinding::tostring(lua_State* L)
{
    GunClassTurret* instance = getInstance(L, 1);
    if (!instance) {
        lua_pushstring(L, "GunClassTurret(nil)");
    } else {
        lua_pushfstring(L, "GunClassTurret(%p)", instance);
    }
    return 1;
}

void GunClassTurretBinding::registerBinding(lua_State* L)
{
    luaL_Reg meta[] = {
        { "__gc", GunClassTurretBinding::gc },
        { "__tostring", GunClassTurretBinding::tostring },
        { 0, 0 }
    };

    luaL_Reg methods[] = {
        { "isOutOfPower", GunClassTurretBinding::isOutOfPower },
        { "_NV_isOutOfPower", GunClassTurretBinding::_NV_isOutOfPower },
        { "clearEntitesPtr", GunClassTurretBinding::clearEntitesPtr },
        { 0, 0 }
    };

    registerClass(
        L,
        GunClassTurretBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GunClassTurretBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "lastTarget", GunClassTurret_get_lastTarget);
    registerGetter(L, "turretBuilding", GunClassTurret_get_turretBuilding);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "lastTarget", GunClassTurret_set_lastTarget);
    registerSetter(L, "turretBuilding", GunClassTurret_set_turretBuilding);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
