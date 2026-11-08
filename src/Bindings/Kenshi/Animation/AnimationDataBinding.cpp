#include "pch.h"
#include "kenshi/Animation/AnimationClass.h"
#include "AnimationDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Animation/AnimationRequirementBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/Util/OgreUnorderedBinding.h"
#include "Bindings/Kenshi/Util/YesNoMaybeBinding.h"

namespace KenshiLua
{

// Offsets confirmed against the AnimationData constructor (RVA 0x5B9B00).
static_assert(offsetof(AnimationData, _rawData) == 0x58, "AnimationData::_rawData offset does not match the game");
static_assert(offsetof(AnimationData, slave) == 0xA8, "AnimationData::slave offset does not match the game");
static_assert(offsetof(AnimationData, events) == 0xF8, "AnimationData::events offset does not match the game");
static_assert(offsetof(AnimationData, stumbleBodyParts) == 0x108, "AnimationData::stumbleBodyParts offset does not match the game");
static_assert(offsetof(AnimationData, stumbleOrigination) == 0x148, "AnimationData::stumbleOrigination offset does not match the game");
static_assert(offsetof(AnimationData, stumbleRarityMult) == 0x150, "AnimationData::stumbleRarityMult offset does not match the game");

static AnimationData* getInstance(lua_State* L, int idx)
{
    return checkObject<AnimationData>(L, idx, AnimationDataBinding::getMetatableName());
}

// --- Getters for AnimationData ---
static int AnimationData_get_category(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushinteger(L, (lua_Integer)instance->category);
    return 1;
}

static int AnimationData_get_dataName(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushstring(L, instance->dataName.c_str());
    return 1;
}

static int AnimationData_get_animName(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushstring(L, instance->animName.c_str());
    return 1;
}

static int AnimationData_get__rawData(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    return pushObject<GameData>(L, instance->_rawData, GameDataBinding::getMetatableName());
}

static int AnimationData_get_layername(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushinteger(L, (lua_Integer)instance->layername);
    return 1;
}

static int AnimationData_get_weatherType(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushinteger(L, (lua_Integer)instance->weatherType);
    return 1;
}

static int AnimationData_get_idealMoveSpeed(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushnumber(L, instance->idealMoveSpeed);
    return 1;
}

static int AnimationData_get_maxMoveSpeed(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushnumber(L, instance->maxMoveSpeed);
    return 1;
}

static int AnimationData_get_minMoveSpeed(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushnumber(L, instance->minMoveSpeed);
    return 1;
}

static int AnimationData_get_playSpeed(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushnumber(L, instance->playSpeed);
    return 1;
}

static int AnimationData_get_holdingWeaponL(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    return pushObject<YesNoMaybe>(L, &instance->holdingWeaponL, YesNoMaybeBinding::getMetatableName());
}

static int AnimationData_get_holdingWeaponR(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    return pushObject<YesNoMaybe>(L, &instance->holdingWeaponR, YesNoMaybeBinding::getMetatableName());
}

static int AnimationData_get_isCombatMode(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    return pushObject<YesNoMaybe>(L, &instance->isCombatMode, YesNoMaybeBinding::getMetatableName());
}

static int AnimationData_get_isStealthMode(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    return pushObject<YesNoMaybe>(L, &instance->isStealthMode, YesNoMaybeBinding::getMetatableName());
}

static int AnimationData_get_relocates(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushboolean(L, instance->relocates ? 1 : 0);
    return 1;
}

static int AnimationData_get_restrictsMovementOrders(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushboolean(L, instance->restrictsMovementOrders ? 1 : 0);
    return 1;
}

static int AnimationData_get_looped(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushboolean(L, instance->looped ? 1 : 0);
    return 1;
}

static int AnimationData_get_wholeBodyAllLayer(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushboolean(L, instance->wholeBodyAllLayer ? 1 : 0);
    return 1;
}

static int AnimationData_get_synched(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushboolean(L, instance->synched ? 1 : 0);
    return 1;
}

static int AnimationData_get_isAction(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushboolean(L, instance->isAction ? 1 : 0);
    return 1;
}

static int AnimationData_get_synchOffset(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushnumber(L, instance->synchOffset);
    return 1;
}

static int AnimationData_get_normalise(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushboolean(L, instance->normalise ? 1 : 0);
    return 1;
}

static int AnimationData_get_possibleEndingPosition(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushnumber(L, instance->possibleEndingPosition);
    return 1;
}

static int AnimationData_get_crouched(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushboolean(L, instance->crouched ? 1 : 0);
    return 1;
}

static int AnimationData_get_prone(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushboolean(L, instance->prone ? 1 : 0);
    return 1;
}

static int AnimationData_get_usesRightArm(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushboolean(L, instance->usesRightArm ? 1 : 0);
    return 1;
}

static int AnimationData_get_usesLeftArm(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushboolean(L, instance->usesLeftArm ? 1 : 0);
    return 1;
}

static int AnimationData_get_carryingLeft(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushboolean(L, instance->carryingLeft ? 1 : 0);
    return 1;
}

static int AnimationData_get_carryingRight(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushboolean(L, instance->carryingRight ? 1 : 0);
    return 1;
}

static int AnimationData_get_carried(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushboolean(L, instance->carried ? 1 : 0);
    return 1;
}

static int AnimationData_get_slave(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushstring(L, instance->slave.c_str());
    return 1;
}

static int AnimationData_get_legDamageRmin(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushnumber(L, instance->legDamageRmin);
    return 1;
}

static int AnimationData_get_legDamageRmax(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushnumber(L, instance->legDamageRmax);
    return 1;
}

static int AnimationData_get_legDamageLmin(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushnumber(L, instance->legDamageLmin);
    return 1;
}

static int AnimationData_get_legDamageLmax(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushnumber(L, instance->legDamageLmax);
    return 1;
}

static int AnimationData_get_legDamageLIdeal(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushnumber(L, instance->legDamageLIdeal);
    return 1;
}

static int AnimationData_get_legDamageRIdeal(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushnumber(L, instance->legDamageRIdeal);
    return 1;
}

static int AnimationData_get_idleTimeMin(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushnumber(L, instance->idleTimeMin);
    return 1;
}

static int AnimationData_get_idleTimeMax(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushnumber(L, instance->idleTimeMax);
    return 1;
}

static int AnimationData_get_idleChance(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushnumber(L, instance->idleChance);
    return 1;
}

static int AnimationData_get_weaponTypeFlags(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushinteger(L, (lua_Integer)instance->weaponTypeFlags);
    return 1;
}

static int AnimationData_get_stumbleBodyParts(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    return pushObject<ogre_unordered_set<GameData*>::type>(L, &instance->stumbleBodyParts, OgreUnorderedSetBinding<GameData*>::getMetatableName());
}

static int AnimationData_get_stumbleOrigination(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushinteger(L, (lua_Integer)instance->stumbleOrigination);
    return 1;
}

static int AnimationData_get_bigStumble(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushboolean(L, instance->bigStumble ? 1 : 0);
    return 1;
}

static int AnimationData_get_stumbleRarityMult(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    lua_pushnumber(L, instance->stumbleRarityMult);
    return 1;
}

// --- Setters for AnimationData ---
static int AnimationData_set_category(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->category = (CharacterAnimCategory)luaL_checkinteger(L, 2);
    return 0;
}

static int AnimationData_set_dataName(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->dataName = luaL_checkstring(L, 2);
    return 0;
}

static int AnimationData_set_animName(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->animName = luaL_checkstring(L, 2);
    return 0;
}

// Set from the source record by the constructor and never null.
static int AnimationData_set__rawData(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->_rawData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int AnimationData_set_layername(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->layername = (AnimationLayerEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int AnimationData_set_weatherType(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->weatherType = (WeatherAffecting)luaL_checkinteger(L, 2);
    return 0;
}

static int AnimationData_set_idealMoveSpeed(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->idealMoveSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationData_set_maxMoveSpeed(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->maxMoveSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationData_set_minMoveSpeed(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->minMoveSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationData_set_playSpeed(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->playSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationData_set_holdingWeaponL(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->holdingWeaponL = *checkObject<YesNoMaybe>(L, 2, YesNoMaybeBinding::getMetatableName());
    return 0;
}

static int AnimationData_set_holdingWeaponR(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->holdingWeaponR = *checkObject<YesNoMaybe>(L, 2, YesNoMaybeBinding::getMetatableName());
    return 0;
}

static int AnimationData_set_isCombatMode(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->isCombatMode = *checkObject<YesNoMaybe>(L, 2, YesNoMaybeBinding::getMetatableName());
    return 0;
}

static int AnimationData_set_isStealthMode(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->isStealthMode = *checkObject<YesNoMaybe>(L, 2, YesNoMaybeBinding::getMetatableName());
    return 0;
}

static int AnimationData_set_relocates(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->relocates = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationData_set_restrictsMovementOrders(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->restrictsMovementOrders = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationData_set_looped(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->looped = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationData_set_wholeBodyAllLayer(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->wholeBodyAllLayer = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationData_set_synched(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->synched = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationData_set_isAction(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->isAction = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationData_set_synchOffset(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->synchOffset = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationData_set_normalise(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->normalise = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationData_set_possibleEndingPosition(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->possibleEndingPosition = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationData_set_crouched(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->crouched = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationData_set_prone(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->prone = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationData_set_usesRightArm(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->usesRightArm = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationData_set_usesLeftArm(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->usesLeftArm = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationData_set_carryingLeft(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->carryingLeft = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationData_set_carryingRight(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->carryingRight = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationData_set_carried(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->carried = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationData_set_slave(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->slave = luaL_checkstring(L, 2);
    return 0;
}

static int AnimationData_set_legDamageRmin(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->legDamageRmin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationData_set_legDamageRmax(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->legDamageRmax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationData_set_legDamageLmin(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->legDamageLmin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationData_set_legDamageLmax(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->legDamageLmax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationData_set_legDamageLIdeal(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->legDamageLIdeal = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationData_set_legDamageRIdeal(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->legDamageRIdeal = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationData_set_idleTimeMin(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->idleTimeMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationData_set_idleTimeMax(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->idleTimeMax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationData_set_idleChance(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->idleChance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AnimationData_set_weaponTypeFlags(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->weaponTypeFlags = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int AnimationData_set_stumbleBodyParts(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    ogre_unordered_set<GameData*>::type* val = OgreUnorderedSetBinding<GameData*>::getInstance(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'stumbleBodyParts' must be ogre_unordered_set<GameData*>");
    instance->stumbleBodyParts = *val;
    return 0;
}

static int AnimationData_set_stumbleOrigination(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->stumbleOrigination = (CutOrigination)luaL_checkinteger(L, 2);
    return 0;
}

static int AnimationData_set_bigStumble(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->bigStumble = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AnimationData_set_stumbleRarityMult(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    instance->stumbleRarityMult = (float)luaL_checknumber(L, 2);
    return 0;
}

int AnimationDataBinding::checkWeaponArms(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    AnimationRequirement* requirements = checkObject<AnimationRequirement>(L, 2, AnimationRequirementBinding::getMetatableName());
    bool result = instance->checkWeaponArms(*requirements);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationDataBinding::checkModes(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    AnimationRequirement* requirements = checkObject<AnimationRequirement>(L, 2, AnimationRequirementBinding::getMetatableName());
    bool result = instance->checkModes(*requirements);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AnimationDataBinding::scoreInjury(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    AnimationRequirement* requirements = checkObject<AnimationRequirement>(L, 2, AnimationRequirementBinding::getMetatableName());
    float result = instance->scoreInjury(*requirements);
    lua_pushnumber(L, result);
    return 1;
}

int AnimationDataBinding::scoreSpeed(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    AnimationRequirement* requirements = checkObject<AnimationRequirement>(L, 2, AnimationRequirementBinding::getMetatableName());
    float speedAgeMultiplier = (float)luaL_checknumber(L, 3);
    float result = instance->scoreSpeed(*requirements, speedAgeMultiplier);
    lua_pushnumber(L, result);
    return 1;
}

int AnimationDataBinding::scoreCarryMode(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    AnimationRequirement* requirements = checkObject<AnimationRequirement>(L, 2, AnimationRequirementBinding::getMetatableName());
    float result = instance->scoreCarryMode(*requirements);
    lua_pushnumber(L, result);
    return 1;
}

int AnimationDataBinding::scoreWeaponType(lua_State* L)
{
    AnimationData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationData is nil");
    AnimationRequirement* requirements = checkObject<AnimationRequirement>(L, 2, AnimationRequirementBinding::getMetatableName());
    float result = instance->scoreWeaponType(*requirements);
    lua_pushnumber(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 589: AnimationData(GameData*) - constructor; AnimsListsManager builds every AnimationData
  line 590: _CONSTRUCTOR(GameData*) - constructor; AnimsListsManager builds every AnimationData
*/

/*
Skipped properties needing manual binding:
  line 631: events (const Ogre::vector<GameDataReference>::type*) - the constructor leaves it unset for COMBAT_TECHNIQUE records, so it can hold a garbage pointer; read _rawData's "events" reference list instead
*/

int AnimationDataBinding::gc(lua_State* L)
{
    // Borrowed from AnimsListsManager, whose animation lists live for the whole session
    return 0;
}

int AnimationDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AnimationData object");
    return 1;
}

void AnimationDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AnimationDataBinding::gc },
        { "__tostring", AnimationDataBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "checkWeaponArms", AnimationDataBinding::checkWeaponArms },
        { "checkModes", AnimationDataBinding::checkModes },
        { "scoreInjury", AnimationDataBinding::scoreInjury },
        { "scoreSpeed", AnimationDataBinding::scoreSpeed },
        { "scoreCarryMode", AnimationDataBinding::scoreCarryMode },
        { "scoreWeaponType", AnimationDataBinding::scoreWeaponType },
        { 0, 0 }
    };

    registerClass(
        L,
        AnimationDataBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AnimationDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "category", AnimationData_get_category);
    registerGetter(L, "dataName", AnimationData_get_dataName);
    registerGetter(L, "animName", AnimationData_get_animName);
    registerGetter(L, "_rawData", AnimationData_get__rawData);
    registerGetter(L, "layername", AnimationData_get_layername);
    registerGetter(L, "weatherType", AnimationData_get_weatherType);
    registerGetter(L, "idealMoveSpeed", AnimationData_get_idealMoveSpeed);
    registerGetter(L, "maxMoveSpeed", AnimationData_get_maxMoveSpeed);
    registerGetter(L, "minMoveSpeed", AnimationData_get_minMoveSpeed);
    registerGetter(L, "playSpeed", AnimationData_get_playSpeed);
    registerGetter(L, "holdingWeaponL", AnimationData_get_holdingWeaponL);
    registerGetter(L, "holdingWeaponR", AnimationData_get_holdingWeaponR);
    registerGetter(L, "isCombatMode", AnimationData_get_isCombatMode);
    registerGetter(L, "isStealthMode", AnimationData_get_isStealthMode);
    registerGetter(L, "relocates", AnimationData_get_relocates);
    registerGetter(L, "restrictsMovementOrders", AnimationData_get_restrictsMovementOrders);
    registerGetter(L, "looped", AnimationData_get_looped);
    registerGetter(L, "wholeBodyAllLayer", AnimationData_get_wholeBodyAllLayer);
    registerGetter(L, "synched", AnimationData_get_synched);
    registerGetter(L, "isAction", AnimationData_get_isAction);
    registerGetter(L, "synchOffset", AnimationData_get_synchOffset);
    registerGetter(L, "normalise", AnimationData_get_normalise);
    registerGetter(L, "possibleEndingPosition", AnimationData_get_possibleEndingPosition);
    registerGetter(L, "crouched", AnimationData_get_crouched);
    registerGetter(L, "prone", AnimationData_get_prone);
    registerGetter(L, "usesRightArm", AnimationData_get_usesRightArm);
    registerGetter(L, "usesLeftArm", AnimationData_get_usesLeftArm);
    registerGetter(L, "carryingLeft", AnimationData_get_carryingLeft);
    registerGetter(L, "carryingRight", AnimationData_get_carryingRight);
    registerGetter(L, "carried", AnimationData_get_carried);
    registerGetter(L, "slave", AnimationData_get_slave);
    registerGetter(L, "legDamageRmin", AnimationData_get_legDamageRmin);
    registerGetter(L, "legDamageRmax", AnimationData_get_legDamageRmax);
    registerGetter(L, "legDamageLmin", AnimationData_get_legDamageLmin);
    registerGetter(L, "legDamageLmax", AnimationData_get_legDamageLmax);
    registerGetter(L, "legDamageLIdeal", AnimationData_get_legDamageLIdeal);
    registerGetter(L, "legDamageRIdeal", AnimationData_get_legDamageRIdeal);
    registerGetter(L, "idleTimeMin", AnimationData_get_idleTimeMin);
    registerGetter(L, "idleTimeMax", AnimationData_get_idleTimeMax);
    registerGetter(L, "idleChance", AnimationData_get_idleChance);
    registerGetter(L, "weaponTypeFlags", AnimationData_get_weaponTypeFlags);
    registerGetter(L, "stumbleBodyParts", AnimationData_get_stumbleBodyParts);
    registerGetter(L, "stumbleOrigination", AnimationData_get_stumbleOrigination);
    registerGetter(L, "bigStumble", AnimationData_get_bigStumble);
    registerGetter(L, "stumbleRarityMult", AnimationData_get_stumbleRarityMult);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "category", AnimationData_set_category);
    registerSetter(L, "dataName", AnimationData_set_dataName);
    registerSetter(L, "animName", AnimationData_set_animName);
    registerSetter(L, "_rawData", AnimationData_set__rawData);
    registerSetter(L, "layername", AnimationData_set_layername);
    registerSetter(L, "weatherType", AnimationData_set_weatherType);
    registerSetter(L, "idealMoveSpeed", AnimationData_set_idealMoveSpeed);
    registerSetter(L, "maxMoveSpeed", AnimationData_set_maxMoveSpeed);
    registerSetter(L, "minMoveSpeed", AnimationData_set_minMoveSpeed);
    registerSetter(L, "playSpeed", AnimationData_set_playSpeed);
    registerSetter(L, "holdingWeaponL", AnimationData_set_holdingWeaponL);
    registerSetter(L, "holdingWeaponR", AnimationData_set_holdingWeaponR);
    registerSetter(L, "isCombatMode", AnimationData_set_isCombatMode);
    registerSetter(L, "isStealthMode", AnimationData_set_isStealthMode);
    registerSetter(L, "relocates", AnimationData_set_relocates);
    registerSetter(L, "restrictsMovementOrders", AnimationData_set_restrictsMovementOrders);
    registerSetter(L, "looped", AnimationData_set_looped);
    registerSetter(L, "wholeBodyAllLayer", AnimationData_set_wholeBodyAllLayer);
    registerSetter(L, "synched", AnimationData_set_synched);
    registerSetter(L, "isAction", AnimationData_set_isAction);
    registerSetter(L, "synchOffset", AnimationData_set_synchOffset);
    registerSetter(L, "normalise", AnimationData_set_normalise);
    registerSetter(L, "possibleEndingPosition", AnimationData_set_possibleEndingPosition);
    registerSetter(L, "crouched", AnimationData_set_crouched);
    registerSetter(L, "prone", AnimationData_set_prone);
    registerSetter(L, "usesRightArm", AnimationData_set_usesRightArm);
    registerSetter(L, "usesLeftArm", AnimationData_set_usesLeftArm);
    registerSetter(L, "carryingLeft", AnimationData_set_carryingLeft);
    registerSetter(L, "carryingRight", AnimationData_set_carryingRight);
    registerSetter(L, "carried", AnimationData_set_carried);
    registerSetter(L, "slave", AnimationData_set_slave);
    registerSetter(L, "legDamageRmin", AnimationData_set_legDamageRmin);
    registerSetter(L, "legDamageRmax", AnimationData_set_legDamageRmax);
    registerSetter(L, "legDamageLmin", AnimationData_set_legDamageLmin);
    registerSetter(L, "legDamageLmax", AnimationData_set_legDamageLmax);
    registerSetter(L, "legDamageLIdeal", AnimationData_set_legDamageLIdeal);
    registerSetter(L, "legDamageRIdeal", AnimationData_set_legDamageRIdeal);
    registerSetter(L, "idleTimeMin", AnimationData_set_idleTimeMin);
    registerSetter(L, "idleTimeMax", AnimationData_set_idleTimeMax);
    registerSetter(L, "idleChance", AnimationData_set_idleChance);
    registerSetter(L, "weaponTypeFlags", AnimationData_set_weaponTypeFlags);
    registerSetter(L, "stumbleBodyParts", AnimationData_set_stumbleBodyParts);
    registerSetter(L, "stumbleOrigination", AnimationData_set_stumbleOrigination);
    registerSetter(L, "bigStumble", AnimationData_set_bigStumble);
    registerSetter(L, "stumbleRarityMult", AnimationData_set_stumbleRarityMult);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
