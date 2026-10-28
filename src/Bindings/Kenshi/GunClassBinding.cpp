#include "pch.h"
#include "kenshi/GunClass.h"
#include "GunClassBinding.h"
#include "GunClassPersonalBinding.h"
#include "GunClassTurretBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/Gui/DatapanelGUIBinding.h"
#include "Bindings/Kenshi/RootObjectBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"

namespace KenshiLua
{

static_assert(offsetof(GunClass, maxRange) == 0x8, "GunClass::maxRange offset mismatch");
static_assert(offsetof(GunClass, user) == 0x30, "GunClass::user offset mismatch");
static_assert(offsetof(GunClass, active) == 0x60, "GunClass::active offset mismatch");
static_assert(offsetof(GunClass, gunData) == 0x68, "GunClass::gunData offset mismatch");
static_assert(offsetof(GunClass, position) == 0xE4, "GunClass::position offset mismatch");

static GunClass* getInstance(lua_State* L, int idx)
{
    return checkObject<GunClass>(L, idx, GunClassBinding::getMetatableName());
}

static int GunClass_get_maxRange(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushnumber(L, instance->maxRange);
    return 1;
}

static int GunClass_set_maxRange(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    instance->maxRange = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GunClass_get_accuracySkillRequired(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushnumber(L, instance->accuracySkillRequired);
    return 1;
}

static int GunClass_set_accuracySkillRequired(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    instance->accuracySkillRequired = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GunClass_get_accuracyDeviationBase(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushnumber(L, instance->accuracyDeviationBase);
    return 1;
}

static int GunClass_set_accuracyDeviationBase(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    instance->accuracyDeviationBase = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GunClass_get_aimSpeed(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushnumber(L, instance->aimSpeed);
    return 1;
}

static int GunClass_set_aimSpeed(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    instance->aimSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GunClass_get_shotSpeed(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushnumber(L, instance->shotSpeed);
    return 1;
}

static int GunClass_set_shotSpeed(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    instance->shotSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GunClass_get_numShotsMax(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushinteger(L, instance->numShotsMax);
    return 1;
}

static int GunClass_set_numShotsMax(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    instance->numShotsMax = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int GunClass_get_numShotsCurrent(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushinteger(L, instance->numShotsCurrent);
    return 1;
}

static int GunClass_set_numShotsCurrent(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    instance->numShotsCurrent = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int GunClass_get_reloadTimeMin(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushnumber(L, instance->reloadTimeMin);
    return 1;
}

static int GunClass_set_reloadTimeMin(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    instance->reloadTimeMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GunClass_get_reloadTimeMax(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushnumber(L, instance->reloadTimeMax);
    return 1;
}

static int GunClass_set_reloadTimeMax(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    instance->reloadTimeMax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GunClass_get_userSkill01(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushnumber(L, instance->userSkill01);
    return 1;
}

static int GunClass_set_userSkill01(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    instance->userSkill01 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GunClass_get_user(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    return HandBinding::push(L, instance->user);
}

static int GunClass_set_user(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (h) instance->user = *h;
    return 0;
}

static int GunClass_get_reloadAnimation(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    if (!instance->reloadAnimation) { lua_pushnil(L); return 1; }
    return pushObject<GameData>(L, instance->reloadAnimation, GameDataBinding::getMetatableName());
}

static int GunClass_set_reloadAnimation(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    instance->reloadAnimation = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int GunClass_get_ammoType(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    if (!instance->ammoType) { lua_pushnil(L); return 1; }
    return pushObject<GameData>(L, instance->ammoType, GameDataBinding::getMetatableName());
}

static int GunClass_set_ammoType(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    instance->ammoType = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int GunClass_get_active(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushboolean(L, instance->active ? 1 : 0);
    return 1;
}

static int GunClass_set_active(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    instance->active = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GunClass_get_visible(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushboolean(L, instance->visible ? 1 : 0);
    return 1;
}

static int GunClass_set_visible(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    instance->visible = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GunClass_get_gunData(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    if (!instance->gunData) { lua_pushnil(L); return 1; }
    return pushObject<GameData>(L, instance->gunData, GameDataBinding::getMetatableName());
}

static int GunClass_set_gunData(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    instance->gunData = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int GunClass_get_gunBarrelOffsetPos(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    pushVector3(L, instance->gunBarrelOffsetPos);
    return 1;
}

static int GunClass_set_gunBarrelOffsetPos(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    readVector3(L, 2, instance->gunBarrelOffsetPos);
    return 0;
}

static int GunClass_get_reloadState(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushnumber(L, instance->reloadState);
    return 1;
}

static int GunClass_set_reloadState(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    instance->reloadState = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GunClass_get_position(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    pushVector3(L, instance->position);
    return 1;
}

static int GunClass_set_position(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    readVector3(L, 2, instance->position);
    return 0;
}

static int GunClass_get_orientation(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    pushQuaternion(L, instance->orientation);
    return 1;
}

static int GunClass_set_orientation(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    readQuaternion(L, 2, instance->orientation);
    return 0;
}

int GunClassBinding::setVisible(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    bool value = lua_toboolean(L, 2) != 0;
    instance->setVisible(value);
    return 0;
}

int GunClassBinding::_NV_setVisible(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    bool value = lua_toboolean(L, 2) != 0;
    instance->_NV_setVisible(value);
    return 0;
}

int GunClassBinding::update(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    Ogre::Vector3 fallback;
    if (!readVector3(L, 2, fallback)) return luaL_argerror(L, 2, "Vector3 expected");
    instance->update(fallback);
    return 0;
}

int GunClassBinding::_NV_update(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    Ogre::Vector3 fallback;
    if (!readVector3(L, 2, fallback)) return luaL_argerror(L, 2, "Vector3 expected");
    instance->_NV_update(fallback);
    return 0;
}

int GunClassBinding::reloadAmmo(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    float frameTime = (float)luaL_checknumber(L, 2);
    instance->reloadAmmo(frameTime);
    return 0;
}

int GunClassBinding::shoot(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    Character* me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    RootObject* target = checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    StatsEnumerated stat = (StatsEnumerated)luaL_checkinteger(L, 4);
    Ogre::Vector3 aimpos;
    if (!readVector3(L, 5, aimpos)) return luaL_argerror(L, 5, "Vector3 expected");
    instance->shoot(me, target, stat, aimpos);
    return 0;
}

int GunClassBinding::destroyPhysical(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    instance->destroyPhysical();
    return 0;
}

int GunClassBinding::_NV_destroyPhysical(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    instance->_NV_destroyPhysical();
    return 0;
}

int GunClassBinding::aimAt(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    Ogre::Vector3 who;
    if (!readVector3(L, 2, who)) return luaL_argerror(L, 2, "Vector3 expected");
    instance->aimAt(who);
    return 0;
}

int GunClassBinding::_NV_aimAt(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    Ogre::Vector3 who;
    if (!readVector3(L, 2, who)) return luaL_argerror(L, 2, "Vector3 expected");
    instance->_NV_aimAt(who);
    return 0;
}

int GunClassBinding::isAnimationReadyToShoot(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushboolean(L, instance->isAnimationReadyToShoot() ? 1 : 0);
    return 1;
}

int GunClassBinding::_NV_isAnimationReadyToShoot(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushboolean(L, instance->_NV_isAnimationReadyToShoot() ? 1 : 0);
    return 1;
}

int GunClassBinding::setAnimationReadyToShoot(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    bool on = lua_toboolean(L, 2) != 0;
    instance->setAnimationReadyToShoot(on);
    return 0;
}

int GunClassBinding::_NV_setAnimationReadyToShoot(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_setAnimationReadyToShoot(on);
    return 0;
}

int GunClassBinding::getBarrelPos(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    pushVector3(L, instance->getBarrelPos());
    return 1;
}

int GunClassBinding::_NV_getBarrelPos(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    pushVector3(L, instance->_NV_getBarrelPos());
    return 1;
}

int GunClassBinding::getBarrelPosForTrace(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    float dist = (float)luaL_checknumber(L, 2);
    pushVector3(L, instance->getBarrelPosForTrace(dist));
    return 1;
}

int GunClassBinding::_NV_getBarrelPosForTrace(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    float dist = (float)luaL_checknumber(L, 2);
    pushVector3(L, instance->_NV_getBarrelPosForTrace(dist));
    return 1;
}

int GunClassBinding::getRelativeBarrelPos(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    pushVector3(L, instance->getRelativeBarrelPos());
    return 1;
}

int GunClassBinding::getAimDir(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    Ogre::Vector3 target;
    if (!readVector3(L, 2, target)) return luaL_argerror(L, 2, "Vector3 expected");
    pushVector3(L, instance->getAimDir(target));
    return 1;
}

int GunClassBinding::_NV_getAimDir(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    Ogre::Vector3 target;
    if (!readVector3(L, 2, target)) return luaL_argerror(L, 2, "Vector3 expected");
    pushVector3(L, instance->_NV_getAimDir(target));
    return 1;
}

int GunClassBinding::getAimCloseness(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushnumber(L, instance->getAimCloseness());
    return 1;
}

int GunClassBinding::getGUIData(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIData(panel, category);
    return 0;
}

int GunClassBinding::_NV_getGUIData(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIData(panel, category);
    return 0;
}

int GunClassBinding::setStateForGUI(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    float progress = (float)luaL_checknumber(L, 2);
    instance->setStateForGUI(progress);
    return 0;
}

int GunClassBinding::_NV_setStateForGUI(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    float progress = (float)luaL_checknumber(L, 2);
    instance->_NV_setStateForGUI(progress);
    return 0;
}

int GunClassBinding::calculateHeightBonus(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    Ogre::Vector3 barrelPos, target;
    if (!readVector3(L, 2, barrelPos)) return luaL_argerror(L, 2, "Vector3 expected");
    if (!readVector3(L, 3, target)) return luaL_argerror(L, 3, "Vector3 expected");
    lua_pushnumber(L, instance->calculateHeightBonus(barrelPos, target));
    return 1;
}

int GunClassBinding::calculateWallBonusMult(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushnumber(L, instance->calculateWallBonusMult());
    return 1;
}

int GunClassBinding::_NV_calculateWallBonusMult(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushnumber(L, instance->_NV_calculateWallBonusMult());
    return 1;
}

int GunClassBinding::getPowerEfficiencyMult(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushnumber(L, instance->getPowerEfficiencyMult());
    return 1;
}

int GunClassBinding::_NV_getPowerEfficiencyMult(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushnumber(L, instance->_NV_getPowerEfficiencyMult());
    return 1;
}

int GunClassBinding::isReloading(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushboolean(L, instance->isReloading() ? 1 : 0);
    return 1;
}

int GunClassBinding::isActive(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushboolean(L, instance->isActive() ? 1 : 0);
    return 1;
}

int GunClassBinding::calculateAccuracyDeviationAngle(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    float stat01 = (float)luaL_checknumber(L, 2);
    lua_pushnumber(L, instance->calculateAccuracyDeviationAngle(stat01));
    return 1;
}

int GunClassBinding::calculateReloadTime(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    float stat01 = (float)luaL_checknumber(L, 2);
    lua_pushnumber(L, instance->calculateReloadTime(stat01));
    return 1;
}

int GunClassBinding::serialise(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->serialise(state);
    return 0;
}

int GunClassBinding::_NV_serialise(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_NV_serialise(state);
    return 0;
}

int GunClassBinding::loadFromSerialise(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->loadFromSerialise(state);
    return 0;
}

int GunClassBinding::_NV_loadFromSerialise(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_NV_loadFromSerialise(state);
    return 0;
}

int GunClassBinding::getDamageMin(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushinteger(L, instance->getDamageMin());
    return 1;
}

int GunClassBinding::getDamageMax(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushinteger(L, instance->getDamageMax());
    return 1;
}

int GunClassBinding::getARandomDamage(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    lua_pushnumber(L, instance->getARandomDamage());
    return 1;
}

int GunClassBinding::isPersonalCrossbow(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    GunClassPersonal* result = instance->isPersonalCrossbow();
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<GunClassPersonal>(L, result, GunClassPersonalBinding::getMetatableName());
}

int GunClassBinding::_NV_isPersonalCrossbow(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    GunClassPersonal* result = instance->_NV_isPersonalCrossbow();
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<GunClassPersonal>(L, result, GunClassPersonalBinding::getMetatableName());
}

int GunClassBinding::isTurret(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    GunClassTurret* result = instance->isTurret();
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<GunClassTurret>(L, result, GunClassTurretBinding::getMetatableName());
}

int GunClassBinding::_NV_isTurret(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    GunClassTurret* result = instance->_NV_isTurret();
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<GunClassTurret>(L, result, GunClassTurretBinding::getMetatableName());
}

int GunClassBinding::getReloadStateForGUI(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    bool divide = lua_toboolean(L, 2) != 0;
    lua_pushnumber(L, instance->getReloadStateForGUI(divide));
    return 1;
}

int GunClassBinding::reactivationCheck(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    instance->reactivationCheck();
    return 0;
}

int GunClassBinding::updatePartVisibilities(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    instance->updatePartVisibilities();
    return 0;
}

int GunClassBinding::setCharacter(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    instance->setCharacter(h ? *h : hand());
    return 0;
}

int GunClassBinding::_NV_setCharacter(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GunClass is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    instance->_NV_setCharacter(h ? *h : hand());
    return 0;
}

int GunClassBinding::gc(lua_State* L)
{
    return noopGc(L);
}

int GunClassBinding::tostring(lua_State* L)
{
    GunClass* instance = getInstance(L, 1);
    if (!instance) {
        lua_pushstring(L, "GunClass(nil)");
    } else {
        lua_pushfstring(L, "GunClass(%p)", instance);
    }
    return 1;
}

void GunClassBinding::registerBinding(lua_State* L)
{
    luaL_Reg meta[] = {
        { "__gc", GunClassBinding::gc },
        { "__tostring", GunClassBinding::tostring },
        { 0, 0 }
    };

    luaL_Reg methods[] = {
        { "setVisible", GunClassBinding::setVisible },
        { "_NV_setVisible", GunClassBinding::_NV_setVisible },
        { "update", GunClassBinding::update },
        { "_NV_update", GunClassBinding::_NV_update },
        { "reloadAmmo", GunClassBinding::reloadAmmo },
        { "shoot", GunClassBinding::shoot },
        { "destroyPhysical", GunClassBinding::destroyPhysical },
        { "_NV_destroyPhysical", GunClassBinding::_NV_destroyPhysical },
        { "aimAt", GunClassBinding::aimAt },
        { "_NV_aimAt", GunClassBinding::_NV_aimAt },
        { "isAnimationReadyToShoot", GunClassBinding::isAnimationReadyToShoot },
        { "_NV_isAnimationReadyToShoot", GunClassBinding::_NV_isAnimationReadyToShoot },
        { "setAnimationReadyToShoot", GunClassBinding::setAnimationReadyToShoot },
        { "_NV_setAnimationReadyToShoot", GunClassBinding::_NV_setAnimationReadyToShoot },
        { "getBarrelPos", GunClassBinding::getBarrelPos },
        { "_NV_getBarrelPos", GunClassBinding::_NV_getBarrelPos },
        { "getBarrelPosForTrace", GunClassBinding::getBarrelPosForTrace },
        { "_NV_getBarrelPosForTrace", GunClassBinding::_NV_getBarrelPosForTrace },
        { "getRelativeBarrelPos", GunClassBinding::getRelativeBarrelPos },
        { "getAimDir", GunClassBinding::getAimDir },
        { "_NV_getAimDir", GunClassBinding::_NV_getAimDir },
        { "getAimCloseness", GunClassBinding::getAimCloseness },
        { "getGUIData", GunClassBinding::getGUIData },
        { "_NV_getGUIData", GunClassBinding::_NV_getGUIData },
        { "setStateForGUI", GunClassBinding::setStateForGUI },
        { "_NV_setStateForGUI", GunClassBinding::_NV_setStateForGUI },
        { "calculateHeightBonus", GunClassBinding::calculateHeightBonus },
        { "calculateWallBonusMult", GunClassBinding::calculateWallBonusMult },
        { "_NV_calculateWallBonusMult", GunClassBinding::_NV_calculateWallBonusMult },
        { "getPowerEfficiencyMult", GunClassBinding::getPowerEfficiencyMult },
        { "_NV_getPowerEfficiencyMult", GunClassBinding::_NV_getPowerEfficiencyMult },
        { "isReloading", GunClassBinding::isReloading },
        { "isActive", GunClassBinding::isActive },
        { "calculateAccuracyDeviationAngle", GunClassBinding::calculateAccuracyDeviationAngle },
        { "calculateReloadTime", GunClassBinding::calculateReloadTime },
        { "serialise", GunClassBinding::serialise },
        { "_NV_serialise", GunClassBinding::_NV_serialise },
        { "loadFromSerialise", GunClassBinding::loadFromSerialise },
        { "_NV_loadFromSerialise", GunClassBinding::_NV_loadFromSerialise },
        { "getDamageMin", GunClassBinding::getDamageMin },
        { "getDamageMax", GunClassBinding::getDamageMax },
        { "getARandomDamage", GunClassBinding::getARandomDamage },
        { "isPersonalCrossbow", GunClassBinding::isPersonalCrossbow },
        { "_NV_isPersonalCrossbow", GunClassBinding::_NV_isPersonalCrossbow },
        { "isTurret", GunClassBinding::isTurret },
        { "_NV_isTurret", GunClassBinding::_NV_isTurret },
        { "getReloadStateForGUI", GunClassBinding::getReloadStateForGUI },
        { "reactivationCheck", GunClassBinding::reactivationCheck },
        { "updatePartVisibilities", GunClassBinding::updatePartVisibilities },
        { "setCharacter", GunClassBinding::setCharacter },
        { "_NV_setCharacter", GunClassBinding::_NV_setCharacter },
        { 0, 0 }
    };

    registerClass(
        L,
        GunClassBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GunClassBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "maxRange", GunClass_get_maxRange);
    registerGetter(L, "accuracySkillRequired", GunClass_get_accuracySkillRequired);
    registerGetter(L, "accuracyDeviationBase", GunClass_get_accuracyDeviationBase);
    registerGetter(L, "aimSpeed", GunClass_get_aimSpeed);
    registerGetter(L, "shotSpeed", GunClass_get_shotSpeed);
    registerGetter(L, "numShotsMax", GunClass_get_numShotsMax);
    registerGetter(L, "numShotsCurrent", GunClass_get_numShotsCurrent);
    registerGetter(L, "reloadTimeMin", GunClass_get_reloadTimeMin);
    registerGetter(L, "reloadTimeMax", GunClass_get_reloadTimeMax);
    registerGetter(L, "userSkill01", GunClass_get_userSkill01);
    registerGetter(L, "user", GunClass_get_user);
    registerGetter(L, "reloadAnimation", GunClass_get_reloadAnimation);
    registerGetter(L, "ammoType", GunClass_get_ammoType);
    registerGetter(L, "active", GunClass_get_active);
    registerGetter(L, "visible", GunClass_get_visible);
    registerGetter(L, "gunData", GunClass_get_gunData);
    registerGetter(L, "gunBarrelOffsetPos", GunClass_get_gunBarrelOffsetPos);
    registerGetter(L, "reloadState", GunClass_get_reloadState);
    registerGetter(L, "position", GunClass_get_position);
    registerGetter(L, "orientation", GunClass_get_orientation);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "maxRange", GunClass_set_maxRange);
    registerSetter(L, "accuracySkillRequired", GunClass_set_accuracySkillRequired);
    registerSetter(L, "accuracyDeviationBase", GunClass_set_accuracyDeviationBase);
    registerSetter(L, "aimSpeed", GunClass_set_aimSpeed);
    registerSetter(L, "shotSpeed", GunClass_set_shotSpeed);
    registerSetter(L, "numShotsMax", GunClass_set_numShotsMax);
    registerSetter(L, "numShotsCurrent", GunClass_set_numShotsCurrent);
    registerSetter(L, "reloadTimeMin", GunClass_set_reloadTimeMin);
    registerSetter(L, "reloadTimeMax", GunClass_set_reloadTimeMax);
    registerSetter(L, "userSkill01", GunClass_set_userSkill01);
    registerSetter(L, "user", GunClass_set_user);
    registerSetter(L, "reloadAnimation", GunClass_set_reloadAnimation);
    registerSetter(L, "ammoType", GunClass_set_ammoType);
    registerSetter(L, "active", GunClass_set_active);
    registerSetter(L, "visible", GunClass_set_visible);
    registerSetter(L, "gunData", GunClass_set_gunData);
    registerSetter(L, "gunBarrelOffsetPos", GunClass_set_gunBarrelOffsetPos);
    registerSetter(L, "reloadState", GunClass_set_reloadState);
    registerSetter(L, "position", GunClass_set_position);
    registerSetter(L, "orientation", GunClass_set_orientation);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
