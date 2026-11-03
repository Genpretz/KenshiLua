#include "pch.h"
#include "kenshi/combat/RangedCombatClass.h"
#include "RangedCombatClassBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/Building/TurretBuildingBinding.h"
#include "Bindings/Kenshi/GunClassBinding.h"
#include "Bindings/Kenshi/Gui/DatapanelGUIBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"

namespace KenshiLua
{

static_assert(offsetof(RangedCombatClass, state) == 0x0, "RangedCombatClass::state offset mismatch");
static_assert(offsetof(RangedCombatClass, _lastAimAheadAmount) == 0x4, "RangedCombatClass::_lastAimAheadAmount offset mismatch");
static_assert(offsetof(RangedCombatClass, turret) == 0x8, "RangedCombatClass::turret offset mismatch");
static_assert(offsetof(RangedCombatClass, gun) == 0x28, "RangedCombatClass::gun offset mismatch");
static_assert(offsetof(RangedCombatClass, currentStat) == 0x30, "RangedCombatClass::currentStat offset mismatch");
static_assert(offsetof(RangedCombatClass, updateNeededMsg) == 0x34, "RangedCombatClass::updateNeededMsg offset mismatch");

static RangedCombatClass* getInstance(lua_State* L, int idx)
{
    return checkObject<RangedCombatClass>(L, idx, RangedCombatClassBinding::getMetatableName());
}

static int RangedCombatClass_get_state(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RangedCombatClass is nil");
    lua_pushinteger(L, (lua_Integer)instance->state);
    return 1;
}

static int RangedCombatClass_set_state(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RangedCombatClass is nil");
    instance->state = (RangedCombatClass::RangedState)luaL_checkinteger(L, 2);
    return 0;
}

static int RangedCombatClass_get__lastAimAheadAmount(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RangedCombatClass is nil");
    lua_pushnumber(L, instance->_lastAimAheadAmount);
    return 1;
}

static int RangedCombatClass_set__lastAimAheadAmount(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RangedCombatClass is nil");
    instance->_lastAimAheadAmount = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RangedCombatClass_get_turret(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RangedCombatClass is nil");
    return HandBinding::push(L, instance->turret);
}

static int RangedCombatClass_set_turret(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RangedCombatClass is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (h) instance->turret = *h;
    return 0;
}

static int RangedCombatClass_get_gun(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RangedCombatClass is nil");
    if (!instance->gun) { lua_pushnil(L); return 1; }
    return pushObject<GunClass>(L, instance->gun, GunClassBinding::getMetatableName());
}

static int RangedCombatClass_set_gun(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RangedCombatClass is nil");
    instance->gun = lua_isnoneornil(L, 2) ? nullptr : checkObject<GunClass>(L, 2, GunClassBinding::getMetatableName());
    return 0;
}

static int RangedCombatClass_get_currentStat(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RangedCombatClass is nil");
    lua_pushinteger(L, (lua_Integer)instance->currentStat);
    return 1;
}

static int RangedCombatClass_set_currentStat(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RangedCombatClass is nil");
    instance->currentStat = (StatsEnumerated)luaL_checkinteger(L, 2);
    return 0;
}

static int RangedCombatClass_get_updateNeededMsg(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RangedCombatClass is nil");
    lua_pushboolean(L, instance->updateNeededMsg ? 1 : 0);
    return 1;
}

static int RangedCombatClass_set_updateNeededMsg(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RangedCombatClass is nil");
    instance->updateNeededMsg = lua_toboolean(L, 2) != 0;
    return 0;
}

int RangedCombatClassBinding::setState(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RangedCombatClass is nil");
    RangedCombatClass::RangedState s = (RangedCombatClass::RangedState)luaL_checkinteger(L, 2);
    instance->setState(s);
    return 0;
}

int RangedCombatClassBinding::setup(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RangedCombatClass is nil");
    TurretBuilding* turret = lua_isnoneornil(L, 2) ? nullptr : checkObject<TurretBuilding>(L, 2, TurretBuildingBinding::getMetatableName());
    StatsEnumerated stat = (StatsEnumerated)luaL_checkinteger(L, 3);
    instance->setup(turret, stat);
    return 0;
}

int RangedCombatClassBinding::getGun(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RangedCombatClass is nil");
    GunClass* result = instance->getGun();
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<GunClass>(L, result, GunClassBinding::getMetatableName());
}

int RangedCombatClassBinding::isInRangedCombatMode(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RangedCombatClass is nil");
    lua_pushboolean(L, instance->isInRangedCombatMode() ? 1 : 0);
    return 1;
}

int RangedCombatClassBinding::updateT(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RangedCombatClass is nil");
    float frameTime = (float)luaL_checknumber(L, 2);
    hand* designated = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    hand* suggested = checkObject<hand>(L, 4, HandBinding::getMetatableName());
    instance->updateT(frameTime, designated ? *designated : hand(), suggested ? *suggested : hand());
    return 0;
}

int RangedCombatClassBinding::updateMT(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RangedCombatClass is nil");
    float frameTime = (float)luaL_checknumber(L, 2);
    instance->updateMT(frameTime);
    return 0;
}

int RangedCombatClassBinding::end(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RangedCombatClass is nil");
    instance->end();
    return 0;
}

int RangedCombatClassBinding::_getAttackTarget(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RangedCombatClass is nil");
    hand result = instance->_getAttackTarget();
    return HandBinding::push(L, result);
}

int RangedCombatClassBinding::scoreTargetRange(lua_State* L)
{
    Ogre::Vector3 from, target;
    if (!readVector3(L, 1, from)) return luaL_argerror(L, 1, "Vector3 expected");
    if (!readVector3(L, 2, target)) return luaL_argerror(L, 2, "Vector3 expected");
    float maxRange = (float)luaL_checknumber(L, 3);
    float minRange = (float)luaL_checknumber(L, 4);
    float result = RangedCombatClass::scoreTargetRange(from, target, maxRange, minRange);
    lua_pushnumber(L, result);
    return 1;
}

int RangedCombatClassBinding::printGUIState(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RangedCombatClass is nil");
    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->printGUIState(panel, category);
    return 0;
}

int RangedCombatClassBinding::isInRange(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RangedCombatClass is nil");
    Ogre::Vector3 v;
    if (!readVector3(L, 2, v)) return luaL_argerror(L, 2, "Vector3 expected");
    lua_pushboolean(L, instance->isInRange(v) ? 1 : 0);
    return 1;
}

int RangedCombatClassBinding::getGunRange(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RangedCombatClass is nil");
    Ogre::Vector3 v;
    if (!readVector3(L, 2, v)) return luaL_argerror(L, 2, "Vector3 expected");
    lua_pushnumber(L, instance->getGunRange(v));
    return 1;
}

int RangedCombatClassBinding::gc(lua_State* L)
{
    return noopGc(L);
}

int RangedCombatClassBinding::tostring(lua_State* L)
{
    RangedCombatClass* instance = getInstance(L, 1);
    if (!instance) {
        lua_pushstring(L, "RangedCombatClass(nil)");
    } else {
        lua_pushfstring(L, "RangedCombatClass(%p)", instance);
    }
    return 1;
}

void RangedCombatClassBinding::registerBinding(lua_State* L)
{
    luaL_Reg meta[] = {
        { "__gc", RangedCombatClassBinding::gc },
        { "__tostring", RangedCombatClassBinding::tostring },
        { 0, 0 }
    };

    luaL_Reg methods[] = {
        { "setState", RangedCombatClassBinding::setState },
        { "setup", RangedCombatClassBinding::setup },
        { "getGun", RangedCombatClassBinding::getGun },
        { "isInRangedCombatMode", RangedCombatClassBinding::isInRangedCombatMode },
        { "updateT", RangedCombatClassBinding::updateT },
        { "updateMT", RangedCombatClassBinding::updateMT },
        { "end", RangedCombatClassBinding::end },
        { "_getAttackTarget", RangedCombatClassBinding::_getAttackTarget },
        { "scoreTargetRange", RangedCombatClassBinding::scoreTargetRange },
        { "printGUIState", RangedCombatClassBinding::printGUIState },
        { "isInRange", RangedCombatClassBinding::isInRange },
        { "getGunRange", RangedCombatClassBinding::getGunRange },
        { 0, 0 }
    };

    registerClass(
        L,
        RangedCombatClassBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, RangedCombatClassBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "state", RangedCombatClass_get_state);
    registerGetter(L, "_lastAimAheadAmount", RangedCombatClass_get__lastAimAheadAmount);
    registerGetter(L, "turret", RangedCombatClass_get_turret);
    registerGetter(L, "gun", RangedCombatClass_get_gun);
    registerGetter(L, "currentStat", RangedCombatClass_get_currentStat);
    registerGetter(L, "updateNeededMsg", RangedCombatClass_get_updateNeededMsg);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "state", RangedCombatClass_set_state);
    registerSetter(L, "_lastAimAheadAmount", RangedCombatClass_set__lastAimAheadAmount);
    registerSetter(L, "turret", RangedCombatClass_set_turret);
    registerSetter(L, "gun", RangedCombatClass_set_gun);
    registerSetter(L, "currentStat", RangedCombatClass_set_currentStat);
    registerSetter(L, "updateNeededMsg", RangedCombatClass_set_updateNeededMsg);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
