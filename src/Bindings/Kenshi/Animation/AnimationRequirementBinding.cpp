#include "pch.h"
#include "kenshi/Animation/AnimationClass.h"
#include "AnimationRequirementBinding.h"
#include "AnimationDataBinding.h"
#include "Bindings/Kenshi/Combat/CombatTechniqueDataBinding.h"
#include "Bindings/Kenshi/MedianFilterBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/YesNoMaybeBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(offsetof(AnimationRequirement, currentAnimCategory) == 0x0, "AnimationRequirement::currentAnimCategory offset mismatch");
static_assert(offsetof(AnimationRequirement, filterFW) == 0x8, "AnimationRequirement::filterFW offset mismatch");
static_assert(offsetof(AnimationRequirement, filterStrafe) == 0x48, "AnimationRequirement::filterStrafe offset mismatch");
static_assert(offsetof(AnimationRequirement, moveSpeed) == 0x88, "AnimationRequirement::moveSpeed offset mismatch");
static_assert(offsetof(AnimationRequirement, turnSpeed) == 0x8C, "AnimationRequirement::turnSpeed offset mismatch");
static_assert(offsetof(AnimationRequirement, smoothedMoveSpeed) == 0x90, "AnimationRequirement::smoothedMoveSpeed offset mismatch");
static_assert(offsetof(AnimationRequirement, strafeSpeed) == 0x94, "AnimationRequirement::strafeSpeed offset mismatch");
static_assert(offsetof(AnimationRequirement, lastStrafeWeight) == 0x98, "AnimationRequirement::lastStrafeWeight offset mismatch");
static_assert(offsetof(AnimationRequirement, isStrafeMode) == 0x9C, "AnimationRequirement::isStrafeMode offset mismatch");
static_assert(offsetof(AnimationRequirement, weaponL) == 0x9D, "AnimationRequirement::weaponL offset mismatch");
static_assert(offsetof(AnimationRequirement, weaponR) == 0x9E, "AnimationRequirement::weaponR offset mismatch");
static_assert(offsetof(AnimationRequirement, isAnimal) == 0x9F, "AnimationRequirement::isAnimal offset mismatch");
static_assert(offsetof(AnimationRequirement, doWeatherAnimation) == 0xA0, "AnimationRequirement::doWeatherAnimation offset mismatch");
static_assert(offsetof(AnimationRequirement, holdBreath) == 0xA1, "AnimationRequirement::holdBreath offset mismatch");
static_assert(offsetof(AnimationRequirement, stance) == 0xA4, "AnimationRequirement::stance offset mismatch");
static_assert(offsetof(AnimationRequirement, weatherType) == 0xA8, "AnimationRequirement::weatherType offset mismatch");
static_assert(offsetof(AnimationRequirement, maxSpeed) == 0xAC, "AnimationRequirement::maxSpeed offset mismatch");
static_assert(offsetof(AnimationRequirement, weatherStrength) == 0xB0, "AnimationRequirement::weatherStrength offset mismatch");
static_assert(offsetof(AnimationRequirement, actionSpeedMult) == 0xB4, "AnimationRequirement::actionSpeedMult offset mismatch");
static_assert(offsetof(AnimationRequirement, isActionSlave) == 0xB8, "AnimationRequirement::isActionSlave offset mismatch");
static_assert(offsetof(AnimationRequirement, attachRootToMastersBone) == 0xC0, "AnimationRequirement::attachRootToMastersBone offset mismatch");
static_assert(offsetof(AnimationRequirement, slaveSync) == 0xE8, "AnimationRequirement::slaveSync offset mismatch");
static_assert(offsetof(AnimationRequirement, slaveHandle) == 0xF0, "AnimationRequirement::slaveHandle offset mismatch");
static_assert(offsetof(AnimationRequirement, forcedSlaveLoop) == 0x110, "AnimationRequirement::forcedSlaveLoop offset mismatch");
static_assert(offsetof(AnimationRequirement, _currentCombatTechnique) == 0x118, "AnimationRequirement::_currentCombatTechnique offset mismatch");
static_assert(offsetof(AnimationRequirement, _currentAction) == 0x120, "AnimationRequirement::_currentAction offset mismatch");
static_assert(offsetof(AnimationRequirement, stateTimer) == 0x128, "AnimationRequirement::stateTimer offset mismatch");
static_assert(offsetof(AnimationRequirement, crouched) == 0x12C, "AnimationRequirement::crouched offset mismatch");
static_assert(offsetof(AnimationRequirement, prone) == 0x12D, "AnimationRequirement::prone offset mismatch");
static_assert(offsetof(AnimationRequirement, carryingLeft) == 0x12E, "AnimationRequirement::carryingLeft offset mismatch");
static_assert(offsetof(AnimationRequirement, carryingRight) == 0x12F, "AnimationRequirement::carryingRight offset mismatch");
static_assert(offsetof(AnimationRequirement, carried) == 0x130, "AnimationRequirement::carried offset mismatch");
static_assert(offsetof(AnimationRequirement, currentStumble) == 0x138, "AnimationRequirement::currentStumble offset mismatch");
static_assert(offsetof(AnimationRequirement, idle) == 0x140, "AnimationRequirement::idle offset mismatch");
static_assert(offsetof(AnimationRequirement, idleState) == 0x148, "AnimationRequirement::idleState offset mismatch");
static_assert(offsetof(AnimationRequirement, idleTimer) == 0x150, "AnimationRequirement::idleTimer offset mismatch");
static_assert(offsetof(AnimationRequirement, isCombatMode) == 0x154, "AnimationRequirement::isCombatMode offset mismatch");
static_assert(offsetof(AnimationRequirement, isStealthMode) == 0x158, "AnimationRequirement::isStealthMode offset mismatch");
static_assert(offsetof(AnimationRequirement, legsIdle) == 0x15C, "AnimationRequirement::legsIdle offset mismatch");
static_assert(offsetof(AnimationRequirement, upperIdle) == 0x15D, "AnimationRequirement::upperIdle offset mismatch");
static_assert(offsetof(AnimationRequirement, legDamageR) == 0x160, "AnimationRequirement::legDamageR offset mismatch");
static_assert(offsetof(AnimationRequirement, legDamageL) == 0x164, "AnimationRequirement::legDamageL offset mismatch");
static_assert(offsetof(AnimationRequirement, pos) == 0x168, "AnimationRequirement::pos offset mismatch");
static_assert(offsetof(AnimationRequirement, currentWeapon) == 0x174, "AnimationRequirement::currentWeapon offset mismatch");
static_assert(offsetof(AnimationRequirement, desiredPainOverlayAnimationOverride) == 0x1A0, "AnimationRequirement::desiredPainOverlayAnimationOverride offset mismatch");

static AnimationRequirement* getInstance(lua_State* L, int idx)
{
    return checkObject<AnimationRequirement>(L, idx, AnimationRequirementBinding::getMetatableName());
}

static int AnimationRequirement_get_currentAnimCategory(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushinteger(L, (lua_Integer)instance->currentAnimCategory);
    return 1;
}

static int AnimationRequirement_set_currentAnimCategory(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->currentAnimCategory = (CharacterAnimCategory)luaL_checkinteger(L, 2);
    return 0;
}

static int AnimationRequirement_get_filterFW(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    return pushObject<MedianFilter>(L, &instance->filterFW, MedianFilterBinding::getMetatableName());
}

static int AnimationRequirement_set_filterFW(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->filterFW = *checkObject<MedianFilter>(L, 2, MedianFilterBinding::getMetatableName());
    return 0;
}

static int AnimationRequirement_get_filterStrafe(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    return pushObject<MedianFilter>(L, &instance->filterStrafe, MedianFilterBinding::getMetatableName());
}

static int AnimationRequirement_set_filterStrafe(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->filterStrafe = *checkObject<MedianFilter>(L, 2, MedianFilterBinding::getMetatableName());
    return 0;
}

static int AnimationRequirement_get_moveSpeed(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushnumber(L, (lua_Number)instance->moveSpeed);
    return 1;
}

static int AnimationRequirement_set_moveSpeed(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->moveSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationRequirement_get_turnSpeed(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushnumber(L, (lua_Number)instance->turnSpeed);
    return 1;
}

static int AnimationRequirement_set_turnSpeed(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->turnSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationRequirement_get_smoothedMoveSpeed(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushnumber(L, (lua_Number)instance->smoothedMoveSpeed);
    return 1;
}

static int AnimationRequirement_set_smoothedMoveSpeed(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->smoothedMoveSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationRequirement_get_strafeSpeed(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushnumber(L, (lua_Number)instance->strafeSpeed);
    return 1;
}

static int AnimationRequirement_set_strafeSpeed(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->strafeSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationRequirement_get_lastStrafeWeight(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushnumber(L, (lua_Number)instance->lastStrafeWeight);
    return 1;
}

static int AnimationRequirement_set_lastStrafeWeight(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->lastStrafeWeight = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationRequirement_get_isStrafeMode(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushboolean(L, instance->isStrafeMode ? 1 : 0);
    return 1;
}

static int AnimationRequirement_set_isStrafeMode(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->isStrafeMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationRequirement_get_weaponL(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushboolean(L, instance->weaponL ? 1 : 0);
    return 1;
}

static int AnimationRequirement_set_weaponL(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->weaponL = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationRequirement_get_weaponR(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushboolean(L, instance->weaponR ? 1 : 0);
    return 1;
}

static int AnimationRequirement_set_weaponR(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->weaponR = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationRequirement_get_isAnimal(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushboolean(L, instance->isAnimal ? 1 : 0);
    return 1;
}

static int AnimationRequirement_set_isAnimal(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->isAnimal = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationRequirement_get_doWeatherAnimation(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushboolean(L, instance->doWeatherAnimation ? 1 : 0);
    return 1;
}

static int AnimationRequirement_set_doWeatherAnimation(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->doWeatherAnimation = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationRequirement_get_holdBreath(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushboolean(L, instance->holdBreath ? 1 : 0);
    return 1;
}

static int AnimationRequirement_set_holdBreath(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->holdBreath = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationRequirement_get_stance(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushinteger(L, (lua_Integer)instance->stance);
    return 1;
}

static int AnimationRequirement_set_stance(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->stance = (StanceEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int AnimationRequirement_get_weatherType(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushinteger(L, (lua_Integer)instance->weatherType);
    return 1;
}

static int AnimationRequirement_set_weatherType(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->weatherType = (WeatherAffecting)luaL_checkinteger(L, 2);
    return 0;
}

static int AnimationRequirement_get_maxSpeed(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushnumber(L, (lua_Number)instance->maxSpeed);
    return 1;
}

static int AnimationRequirement_set_maxSpeed(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->maxSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationRequirement_get_weatherStrength(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushnumber(L, (lua_Number)instance->weatherStrength);
    return 1;
}

static int AnimationRequirement_set_weatherStrength(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->weatherStrength = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationRequirement_get_actionSpeedMult(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushnumber(L, (lua_Number)instance->actionSpeedMult);
    return 1;
}

static int AnimationRequirement_set_actionSpeedMult(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->actionSpeedMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationRequirement_get_isActionSlave(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushboolean(L, instance->isActionSlave ? 1 : 0);
    return 1;
}

static int AnimationRequirement_set_isActionSlave(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->isActionSlave = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationRequirement_get_attachRootToMastersBone(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushstring(L, instance->attachRootToMastersBone.c_str());
    return 1;
}

static int AnimationRequirement_set_attachRootToMastersBone(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    const char* str = luaL_checkstring(L, 2);
    instance->attachRootToMastersBone = str ? str : "";
    return 0;
}

static int AnimationRequirement_get_slaveSync(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushnumber(L, (lua_Number)instance->slaveSync);
    return 1;
}

static int AnimationRequirement_set_slaveSync(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->slaveSync = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationRequirement_get_slaveHandle(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    return HandBinding::push(L, instance->slaveHandle);
}

static int AnimationRequirement_set_slaveHandle(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->slaveHandle = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int AnimationRequirement_get_forcedSlaveLoop(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    if (!instance->forcedSlaveLoop) { lua_pushnil(L); return 1; }
    return pushObject<AnimationData>(L, instance->forcedSlaveLoop, AnimationDataBinding::getMetatableName());
}

static int AnimationRequirement_set_forcedSlaveLoop(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->forcedSlaveLoop = lua_isnoneornil(L, 2) ? nullptr : checkObject<AnimationData>(L, 2, AnimationDataBinding::getMetatableName());
    return 0;
}

static int AnimationRequirement_get__currentCombatTechnique(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    if (!instance->_currentCombatTechnique) { lua_pushnil(L); return 1; }
    return pushObject<CombatTechniqueData>(L, instance->_currentCombatTechnique, CombatTechniqueDataBinding::getMetatableName());
}

static int AnimationRequirement_set__currentCombatTechnique(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->_currentCombatTechnique = lua_isnoneornil(L, 2) ? nullptr : checkObject<CombatTechniqueData>(L, 2, CombatTechniqueDataBinding::getMetatableName());
    return 0;
}

static int AnimationRequirement_get__currentAction(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    if (!instance->_currentAction) { lua_pushnil(L); return 1; }
    return pushObject<AnimationData>(L, instance->_currentAction, AnimationDataBinding::getMetatableName());
}

static int AnimationRequirement_set__currentAction(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->_currentAction = lua_isnoneornil(L, 2) ? nullptr : checkObject<AnimationData>(L, 2, AnimationDataBinding::getMetatableName());
    return 0;
}

static int AnimationRequirement_get_stateTimer(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushnumber(L, (lua_Number)instance->stateTimer);
    return 1;
}

static int AnimationRequirement_set_stateTimer(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->stateTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationRequirement_get_crouched(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushboolean(L, instance->crouched ? 1 : 0);
    return 1;
}

static int AnimationRequirement_set_crouched(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->crouched = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationRequirement_get_prone(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushboolean(L, instance->prone ? 1 : 0);
    return 1;
}

static int AnimationRequirement_set_prone(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->prone = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationRequirement_get_carryingLeft(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushboolean(L, instance->carryingLeft ? 1 : 0);
    return 1;
}

static int AnimationRequirement_set_carryingLeft(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->carryingLeft = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationRequirement_get_carryingRight(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushboolean(L, instance->carryingRight ? 1 : 0);
    return 1;
}

static int AnimationRequirement_set_carryingRight(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->carryingRight = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationRequirement_get_carried(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushboolean(L, instance->carried ? 1 : 0);
    return 1;
}

static int AnimationRequirement_set_carried(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->carried = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationRequirement_get_currentStumble(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    if (!instance->currentStumble) { lua_pushnil(L); return 1; }
    return pushObject<AnimationData>(L, instance->currentStumble, AnimationDataBinding::getMetatableName());
}

static int AnimationRequirement_set_currentStumble(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->currentStumble = lua_isnoneornil(L, 2) ? nullptr : checkObject<AnimationData>(L, 2, AnimationDataBinding::getMetatableName());
    return 0;
}

static int AnimationRequirement_get_idle(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushboolean(L, instance->idle ? 1 : 0);
    return 1;
}

static int AnimationRequirement_set_idle(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->idle = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationRequirement_get_idleState(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    if (!instance->idleState) { lua_pushnil(L); return 1; }
    return pushObject<AnimationData>(L, instance->idleState, AnimationDataBinding::getMetatableName());
}

static int AnimationRequirement_set_idleState(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->idleState = lua_isnoneornil(L, 2) ? nullptr : checkObject<AnimationData>(L, 2, AnimationDataBinding::getMetatableName());
    return 0;
}

static int AnimationRequirement_get_idleTimer(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushnumber(L, (lua_Number)instance->idleTimer);
    return 1;
}

static int AnimationRequirement_set_idleTimer(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->idleTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationRequirement_get_isCombatMode(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushinteger(L, (lua_Integer)instance->isCombatMode.key);
    return 1;
}

static int AnimationRequirement_set_isCombatMode(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->isCombatMode = YesNoMaybe((int)luaL_checkinteger(L, 2));
    return 0;
}

static int AnimationRequirement_get_isStealthMode(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushinteger(L, (lua_Integer)instance->isStealthMode.key);
    return 1;
}

static int AnimationRequirement_set_isStealthMode(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->isStealthMode = YesNoMaybe((int)luaL_checkinteger(L, 2));
    return 0;
}

static int AnimationRequirement_get_legsIdle(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushboolean(L, instance->legsIdle ? 1 : 0);
    return 1;
}

static int AnimationRequirement_set_legsIdle(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->legsIdle = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationRequirement_get_upperIdle(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushboolean(L, instance->upperIdle ? 1 : 0);
    return 1;
}

static int AnimationRequirement_set_upperIdle(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->upperIdle = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationRequirement_get_legDamageR(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushnumber(L, (lua_Number)instance->legDamageR);
    return 1;
}

static int AnimationRequirement_set_legDamageR(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->legDamageR = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationRequirement_get_legDamageL(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushnumber(L, (lua_Number)instance->legDamageL);
    return 1;
}

static int AnimationRequirement_set_legDamageL(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->legDamageL = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationRequirement_get_pos(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    pushVector3(L, instance->pos);
    return 1;
}

static int AnimationRequirement_set_pos(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    readVector3(L, 2, instance->pos);
    return 0;
}

static int AnimationRequirement_get_currentWeapon(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushinteger(L, (lua_Integer)instance->currentWeapon);
    return 1;
}

static int AnimationRequirement_set_currentWeapon(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->currentWeapon = (WeaponCategory)luaL_checkinteger(L, 2);
    return 0;
}

static int AnimationRequirement_get_desiredPainOverlayAnimationOverride(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    lua_pushstring(L, instance->desiredPainOverlayAnimationOverride.c_str());
    return 1;
}

static int AnimationRequirement_set_desiredPainOverlayAnimationOverride(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    const char* str = luaL_checkstring(L, 2);
    instance->desiredPainOverlayAnimationOverride = str ? str : "";
    return 0;
}

int AnimationRequirementBinding::isUpperBodyOnlyAction(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    bool result = instance->isUpperBodyOnlyAction();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationRequirementBinding::hasAction(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    bool result = instance->hasAction();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationRequirementBinding::clearAction(lua_State* L)
{
    AnimationRequirement* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationRequirement is nil");
    instance->clearAction();
    return 0;
}

int AnimationRequirementBinding::gc(lua_State* L)
{
    return 0;
}

int AnimationRequirementBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AnimationRequirement object");
    return 1;
}

void AnimationRequirementBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AnimationRequirementBinding::gc },
        { "__tostring", AnimationRequirementBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "isUpperBodyOnlyAction", AnimationRequirementBinding::isUpperBodyOnlyAction },
        { "hasAction", AnimationRequirementBinding::hasAction },
        { "clearAction", AnimationRequirementBinding::clearAction },
        { 0, 0 }
    };

    registerClass(
        L,
        AnimationRequirementBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AnimationRequirementBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "currentAnimCategory", AnimationRequirement_get_currentAnimCategory);
    registerGetter(L, "filterFW", AnimationRequirement_get_filterFW);
    registerGetter(L, "filterStrafe", AnimationRequirement_get_filterStrafe);
    registerGetter(L, "moveSpeed", AnimationRequirement_get_moveSpeed);
    registerGetter(L, "turnSpeed", AnimationRequirement_get_turnSpeed);
    registerGetter(L, "smoothedMoveSpeed", AnimationRequirement_get_smoothedMoveSpeed);
    registerGetter(L, "strafeSpeed", AnimationRequirement_get_strafeSpeed);
    registerGetter(L, "lastStrafeWeight", AnimationRequirement_get_lastStrafeWeight);
    registerGetter(L, "isStrafeMode", AnimationRequirement_get_isStrafeMode);
    registerGetter(L, "weaponL", AnimationRequirement_get_weaponL);
    registerGetter(L, "weaponR", AnimationRequirement_get_weaponR);
    registerGetter(L, "isAnimal", AnimationRequirement_get_isAnimal);
    registerGetter(L, "doWeatherAnimation", AnimationRequirement_get_doWeatherAnimation);
    registerGetter(L, "holdBreath", AnimationRequirement_get_holdBreath);
    registerGetter(L, "stance", AnimationRequirement_get_stance);
    registerGetter(L, "weatherType", AnimationRequirement_get_weatherType);
    registerGetter(L, "maxSpeed", AnimationRequirement_get_maxSpeed);
    registerGetter(L, "weatherStrength", AnimationRequirement_get_weatherStrength);
    registerGetter(L, "actionSpeedMult", AnimationRequirement_get_actionSpeedMult);
    registerGetter(L, "isActionSlave", AnimationRequirement_get_isActionSlave);
    registerGetter(L, "attachRootToMastersBone", AnimationRequirement_get_attachRootToMastersBone);
    registerGetter(L, "slaveSync", AnimationRequirement_get_slaveSync);
    registerGetter(L, "slaveHandle", AnimationRequirement_get_slaveHandle);
    registerGetter(L, "forcedSlaveLoop", AnimationRequirement_get_forcedSlaveLoop);
    registerGetter(L, "_currentCombatTechnique", AnimationRequirement_get__currentCombatTechnique);
    registerGetter(L, "_currentAction", AnimationRequirement_get__currentAction);
    registerGetter(L, "stateTimer", AnimationRequirement_get_stateTimer);
    registerGetter(L, "crouched", AnimationRequirement_get_crouched);
    registerGetter(L, "prone", AnimationRequirement_get_prone);
    registerGetter(L, "carryingLeft", AnimationRequirement_get_carryingLeft);
    registerGetter(L, "carryingRight", AnimationRequirement_get_carryingRight);
    registerGetter(L, "carried", AnimationRequirement_get_carried);
    registerGetter(L, "currentStumble", AnimationRequirement_get_currentStumble);
    registerGetter(L, "idle", AnimationRequirement_get_idle);
    registerGetter(L, "idleState", AnimationRequirement_get_idleState);
    registerGetter(L, "idleTimer", AnimationRequirement_get_idleTimer);
    registerGetter(L, "isCombatMode", AnimationRequirement_get_isCombatMode);
    registerGetter(L, "isStealthMode", AnimationRequirement_get_isStealthMode);
    registerGetter(L, "legsIdle", AnimationRequirement_get_legsIdle);
    registerGetter(L, "upperIdle", AnimationRequirement_get_upperIdle);
    registerGetter(L, "legDamageR", AnimationRequirement_get_legDamageR);
    registerGetter(L, "legDamageL", AnimationRequirement_get_legDamageL);
    registerGetter(L, "pos", AnimationRequirement_get_pos);
    registerGetter(L, "currentWeapon", AnimationRequirement_get_currentWeapon);
    registerGetter(L, "desiredPainOverlayAnimationOverride", AnimationRequirement_get_desiredPainOverlayAnimationOverride);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "currentAnimCategory", AnimationRequirement_set_currentAnimCategory);
    registerSetter(L, "filterFW", AnimationRequirement_set_filterFW);
    registerSetter(L, "filterStrafe", AnimationRequirement_set_filterStrafe);
    registerSetter(L, "moveSpeed", AnimationRequirement_set_moveSpeed);
    registerSetter(L, "turnSpeed", AnimationRequirement_set_turnSpeed);
    registerSetter(L, "smoothedMoveSpeed", AnimationRequirement_set_smoothedMoveSpeed);
    registerSetter(L, "strafeSpeed", AnimationRequirement_set_strafeSpeed);
    registerSetter(L, "lastStrafeWeight", AnimationRequirement_set_lastStrafeWeight);
    registerSetter(L, "isStrafeMode", AnimationRequirement_set_isStrafeMode);
    registerSetter(L, "weaponL", AnimationRequirement_set_weaponL);
    registerSetter(L, "weaponR", AnimationRequirement_set_weaponR);
    registerSetter(L, "isAnimal", AnimationRequirement_set_isAnimal);
    registerSetter(L, "doWeatherAnimation", AnimationRequirement_set_doWeatherAnimation);
    registerSetter(L, "holdBreath", AnimationRequirement_set_holdBreath);
    registerSetter(L, "stance", AnimationRequirement_set_stance);
    registerSetter(L, "weatherType", AnimationRequirement_set_weatherType);
    registerSetter(L, "maxSpeed", AnimationRequirement_set_maxSpeed);
    registerSetter(L, "weatherStrength", AnimationRequirement_set_weatherStrength);
    registerSetter(L, "actionSpeedMult", AnimationRequirement_set_actionSpeedMult);
    registerSetter(L, "isActionSlave", AnimationRequirement_set_isActionSlave);
    registerSetter(L, "attachRootToMastersBone", AnimationRequirement_set_attachRootToMastersBone);
    registerSetter(L, "slaveSync", AnimationRequirement_set_slaveSync);
    registerSetter(L, "slaveHandle", AnimationRequirement_set_slaveHandle);
    registerSetter(L, "forcedSlaveLoop", AnimationRequirement_set_forcedSlaveLoop);
    registerSetter(L, "_currentCombatTechnique", AnimationRequirement_set__currentCombatTechnique);
    registerSetter(L, "_currentAction", AnimationRequirement_set__currentAction);
    registerSetter(L, "stateTimer", AnimationRequirement_set_stateTimer);
    registerSetter(L, "crouched", AnimationRequirement_set_crouched);
    registerSetter(L, "prone", AnimationRequirement_set_prone);
    registerSetter(L, "carryingLeft", AnimationRequirement_set_carryingLeft);
    registerSetter(L, "carryingRight", AnimationRequirement_set_carryingRight);
    registerSetter(L, "carried", AnimationRequirement_set_carried);
    registerSetter(L, "currentStumble", AnimationRequirement_set_currentStumble);
    registerSetter(L, "idle", AnimationRequirement_set_idle);
    registerSetter(L, "idleState", AnimationRequirement_set_idleState);
    registerSetter(L, "idleTimer", AnimationRequirement_set_idleTimer);
    registerSetter(L, "isCombatMode", AnimationRequirement_set_isCombatMode);
    registerSetter(L, "isStealthMode", AnimationRequirement_set_isStealthMode);
    registerSetter(L, "legsIdle", AnimationRequirement_set_legsIdle);
    registerSetter(L, "upperIdle", AnimationRequirement_set_upperIdle);
    registerSetter(L, "legDamageR", AnimationRequirement_set_legDamageR);
    registerSetter(L, "legDamageL", AnimationRequirement_set_legDamageL);
    registerSetter(L, "pos", AnimationRequirement_set_pos);
    registerSetter(L, "currentWeapon", AnimationRequirement_set_currentWeapon);
    registerSetter(L, "desiredPainOverlayAnimationOverride", AnimationRequirement_set_desiredPainOverlayAnimationOverride);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua

