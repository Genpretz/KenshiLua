#include "pch.h"
#include "kenshi\MedicalSystem.h"
#include "MedicalSystemBinding.h"
#include "RobotLimbsBinding.h"
#include "kenshi/Character.h"
#include "CharacterBinding.h"
#include "CharStatsBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharStatsBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/RobotLimbsBinding.h"

namespace KenshiLua
{

static MedicalSystem* getB(lua_State* L, int idx)
{
    return checkObject<MedicalSystem>(L, idx, MedicalSystemBinding::getMetatableName());
}

// --- Getters for MedicalSystem ---
static int MedicalSystem_get_status(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    // TODO: Unsupported type for status (ogre_unordered_map<GameData*, MedicalSystem::HealthPartStatus>::type)
    return luaL_error(L, "Unsupported property 'status' (type: ogre_unordered_map<GameData*, MedicalSystem::HealthPartStatus>::type)");
}

static int MedicalSystem_get_armourList(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    // TODO: Unsupported type for armourList (lektor<Armour*>)
    return luaL_error(L, "Unsupported property 'armourList' (type: lektor<Armour*>)");
}

static int MedicalSystem_get_hunger(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, b->hunger);
    return 1;
}

static int MedicalSystem_get_fed(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, b->fed);
    return 1;
}

static int MedicalSystem_get_lastPeriodicUpdate(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    // TODO: Unsupported type for lastPeriodicUpdate (TimeOfDay)
    return luaL_error(L, "Unsupported property 'lastPeriodicUpdate' (type: TimeOfDay)");
}

static int MedicalSystem_get_blood(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, b->blood);
    return 1;
}

static int MedicalSystem_get_extraBloodLossFromBodyparts(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, b->extraBloodLossFromBodyparts);
    return 1;
}

static int MedicalSystem_get_currentBleedRate(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, b->currentBleedRate);
    return 1;
}

static int MedicalSystem_get_leftLeg(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushinteger(L, (lua_Integer)b->leftLeg);
    return 1;
}

static int MedicalSystem_get_rightLeg(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushinteger(L, (lua_Integer)b->rightLeg);
    return 1;
}

static int MedicalSystem_get_leftArm(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushinteger(L, (lua_Integer)b->leftArm);
    return 1;
}

static int MedicalSystem_get_rightArm(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushinteger(L, (lua_Integer)b->rightArm);
    return 1;
}

static int MedicalSystem_get_knockoutTimer(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, b->knockoutTimer);
    return 1;
}

static int MedicalSystem_get_worstDamage(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, b->worstDamage);
    return 1;
}

static int MedicalSystem_get_needsFirstAidScoreTotal_robot(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, b->needsFirstAidScoreTotal_robot);
    return 1;
}

static int MedicalSystem_get_needsFirstAidScoreTotal_fleshy(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, b->needsFirstAidScoreTotal_fleshy);
    return 1;
}

static int MedicalSystem_get_restedState(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, b->restedState);
    return 1;
}

static int MedicalSystem_get_stealthHinderance(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, b->stealthHinderance);
    return 1;
}

static int MedicalSystem_get_partBestArm(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, b->partBestArm);
    return 1;
}

static int MedicalSystem_get_partHead(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, b->partHead);
    return 1;
}

static int MedicalSystem_get_partWorstTorso(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, b->partWorstTorso);
    return 1;
}

static int MedicalSystem_get_dazedOrAlert(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, b->dazedOrAlert);
    return 1;
}

static int MedicalSystem_get_robotLimbs(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    return pushObject<RobotLimbs>(L, b->robotLimbs, RobotLimbsBinding::getMetatableName());
}

static int MedicalSystem_get_bloodynessChanged(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushboolean(L, b->bloodynessChanged ? 1 : 0);
    return 1;
}

static int MedicalSystem_get_bloodynessCleanedUp(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushboolean(L, b->bloodynessCleanedUp ? 1 : 0);
    return 1;
}

static int MedicalSystem_get_animation(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    // TODO: Unsupported type for animation (AnimationClass*)
    return luaL_error(L, "Unsupported property 'animation' (type: AnimationClass*)");
}

static int MedicalSystem_get_me(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    return pushObject<Character>(L, b->me, CharacterBinding::getMetatableName());
}

static int MedicalSystem_get_weatherGUIfeedback(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    // TODO: Unsupported type for weatherGUIfeedback (StringPair)
    return luaL_error(L, "Unsupported property 'weatherGUIfeedback' (type: StringPair)");
}

static int MedicalSystem_get_currentWeatherAffect(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushinteger(L, (lua_Integer)b->currentWeatherAffect);
    return 1;
}

static int MedicalSystem_get_currentWeatherAffectStrength(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, b->currentWeatherAffectStrength);
    return 1;
}

static int MedicalSystem_get_lastHungerKO(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    // TODO: Unsupported type for lastHungerKO (TimeOfDay)
    return luaL_error(L, "Unsupported property 'lastHungerKO' (type: TimeOfDay)");
}

static int MedicalSystem_get_nextKOTime(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, b->nextKOTime);
    return 1;
}

static int MedicalSystem_get__eatenDeathDelay(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushinteger(L, b->_eatenDeathDelay);
    return 1;
}

static int MedicalSystem_get_crippled(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushboolean(L, b->crippled ? 1 : 0);
    return 1;
}

static int MedicalSystem_get_unconcious(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushboolean(L, b->unconcious ? 1 : 0);
    return 1;
}

static int MedicalSystem_get_sub50KO(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushboolean(L, b->sub50KO ? 1 : 0);
    return 1;
}

static int MedicalSystem_get_bloodlossTrauma(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushboolean(L, b->bloodlossTrauma ? 1 : 0);
    return 1;
}

static int MedicalSystem_get_dead(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushboolean(L, b->dead ? 1 : 0);
    return 1;
}

static int MedicalSystem_get_rightArmOk(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushboolean(L, b->rightArmOk ? 1 : 0);
    return 1;
}

static int MedicalSystem_get_leftArmOk(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    lua_pushboolean(L, b->leftArmOk ? 1 : 0);
    return 1;
}

static int MedicalSystem_get_lastBloodPosition(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    pushVector3(L, b->lastBloodPosition);
    return 1;
}

static int MedicalSystem_get_wounds(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    // TODO: Unsupported type for wounds (Ogre::FastArray<Wound*>)
    return luaL_error(L, "Unsupported property 'wounds' (type: Ogre::FastArray<Wound*>)");
}

static int MedicalSystem_get_anatomy(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    // TODO: Unsupported type for anatomy (lektor<MedicalSystem::HealthPartStatus*>)
    return luaL_error(L, "Unsupported property 'anatomy' (type: lektor<MedicalSystem::HealthPartStatus*>)");
}

static int MedicalSystem_get_stats(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    return pushObject<CharStats>(L, b->stats, CharStatsBinding::getMetatableName());
}

// --- Setters for MedicalSystem ---
static int MedicalSystem_set_status(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for status");
}

static int MedicalSystem_set_armourList(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for armourList");
}

static int MedicalSystem_set_hunger(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->hunger = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_fed(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->fed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_lastPeriodicUpdate(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for lastPeriodicUpdate");
}

static int MedicalSystem_set_blood(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->blood = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_extraBloodLossFromBodyparts(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->extraBloodLossFromBodyparts = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_currentBleedRate(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->currentBleedRate = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_leftLeg(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for leftLeg");
}

static int MedicalSystem_set_rightLeg(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for rightLeg");
}

static int MedicalSystem_set_leftArm(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for leftArm");
}

static int MedicalSystem_set_rightArm(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for rightArm");
}

static int MedicalSystem_set_knockoutTimer(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->knockoutTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_worstDamage(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->worstDamage = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_needsFirstAidScoreTotal_robot(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->needsFirstAidScoreTotal_robot = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_needsFirstAidScoreTotal_fleshy(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->needsFirstAidScoreTotal_fleshy = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_restedState(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->restedState = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_stealthHinderance(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->stealthHinderance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_partBestArm(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->partBestArm = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_partHead(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->partHead = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_partWorstTorso(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->partWorstTorso = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_dazedOrAlert(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->dazedOrAlert = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_robotLimbs(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for robotLimbs");
}

static int MedicalSystem_set_bloodynessChanged(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->bloodynessChanged = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MedicalSystem_set_bloodynessCleanedUp(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->bloodynessCleanedUp = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MedicalSystem_set_animation(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for animation");
}

static int MedicalSystem_set_me(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for me");
}

static int MedicalSystem_set_weatherGUIfeedback(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for weatherGUIfeedback");
}

static int MedicalSystem_set_currentWeatherAffect(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->currentWeatherAffect = (WeatherAffecting)luaL_checkinteger(L, 2);
    return 0;
}

static int MedicalSystem_set_currentWeatherAffectStrength(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->currentWeatherAffectStrength = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_lastHungerKO(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for lastHungerKO");
}

static int MedicalSystem_set_nextKOTime(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->nextKOTime = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set__eatenDeathDelay(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->_eatenDeathDelay = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int MedicalSystem_set_crippled(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->crippled = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MedicalSystem_set_unconcious(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->unconcious = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MedicalSystem_set_sub50KO(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->sub50KO = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MedicalSystem_set_bloodlossTrauma(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->bloodlossTrauma = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MedicalSystem_set_dead(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->dead = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MedicalSystem_set_rightArmOk(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->rightArmOk = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MedicalSystem_set_leftArmOk(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    b->leftArmOk = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MedicalSystem_set_lastBloodPosition(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    readVector3(L, 2, b->lastBloodPosition);
    return 0;
}

static int MedicalSystem_set_wounds(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for wounds");
}

static int MedicalSystem_set_anatomy(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for anatomy");
}

static int MedicalSystem_set_stats(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");
    return luaL_error(L, "Read-only or unsupported setter type for stats");
}

int MedicalSystemBinding::precalculateFirstAidNeedScore(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    b->precalculateFirstAidNeedScore();
    return 0;
}

int MedicalSystemBinding::_CONSTRUCTOR(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    MedicalSystem* result = b->_CONSTRUCTOR();
    return pushObject<MedicalSystem>(L, result, MedicalSystemBinding::getMetatableName());
}

int MedicalSystemBinding::_DESTRUCTOR(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    b->_DESTRUCTOR();
    return 0;
}

int MedicalSystemBinding::updateStats(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    b->updateStats();
    return 0;
}

int MedicalSystemBinding::_NV_updateStats(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    b->_NV_updateStats();
    return 0;
}

int MedicalSystemBinding::medicalUpdate(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float frameTime = (float)luaL_checknumber(L, 2);
    b->medicalUpdate(frameTime);
    return 0;
}

int MedicalSystemBinding::periodicUpdate(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    b->periodicUpdate();
    return 0;
}

int MedicalSystemBinding::_NV_periodicUpdate(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    b->_NV_periodicUpdate();
    return 0;
}

int MedicalSystemBinding::scoreFirstAidNeed(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    bool robotAid = lua_toboolean(L, 2) != 0;
    float result = b->scoreFirstAidNeed(robotAid);
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::scoreJuryRigNeed(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float skills = (float)luaL_checknumber(L, 2);
    float result = b->scoreJuryRigNeed(skills);
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::isFullyRested(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    bool result = b->isFullyRested();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::_setHealth(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    std::string bodypart = luaL_checkstring(L, 2);
    float amount = (float)luaL_checknumber(L, 3);
    b->_setHealth(bodypart, amount);
    return 0;
}

int MedicalSystemBinding::validateHealthValues(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    b->validateHealthValues();
    return 0;
}

int MedicalSystemBinding::amputate(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    RobotLimbs::Limb limb = (RobotLimbs::Limb)luaL_checkinteger(L, 2);
    bool createSeveredItem = lua_toboolean(L, 3) != 0;
    Ogre::Vector3 force;
    readVector3(L, 4, force);
    b->amputate(limb, createSeveredItem, force);
    return 0;
}

int MedicalSystemBinding::crushLimb(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    RobotLimbs::Limb limb = (RobotLimbs::Limb)luaL_checkinteger(L, 2);
    b->crushLimb(limb);
    return 0;
}

int MedicalSystemBinding::isUselessNoLimbGuy(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    bool result = b->isUselessNoLimbGuy();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::recalculateStealthHinderance(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float result = b->recalculateStealthHinderance();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::getPartCount(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    int result = b->getPartCount();
    lua_pushinteger(L, result);
    return 1;
}

int MedicalSystemBinding::hasRobotics(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    bool result = b->hasRobotics();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::isFed(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    bool result = b->isFed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::getMaxBlood(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float result = b->getMaxBlood();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::startKnockoutTimer(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    b->startKnockoutTimer();
    return 0;
}

int MedicalSystemBinding::knockout(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float skill01 = (float)luaL_checknumber(L, 2);
    b->knockout(skill01);
    return 0;
}

int MedicalSystemBinding::knockoutForceTimer(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float seconds = (float)luaL_checknumber(L, 2);
    b->knockoutForceTimer(seconds);
    return 0;
}

int MedicalSystemBinding::pointOfCollapseBloodloss(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float result = b->pointOfCollapseBloodloss();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::pointOfNoReturn(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float result = b->pointOfNoReturn();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::pointOfNoReturn_Hunger01(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float mult = (float)luaL_checknumber(L, 2);
    float result = b->pointOfNoReturn_Hunger01(mult);
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::isHungerKO(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    bool result = b->isHungerKO();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::getToughnessXpBonus(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float result = b->getToughnessXpBonus();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::getHungerSpeedModifier(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float result = b->getHungerSpeedModifier();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::getHealthStatModifier(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    StatsEnumerated stat = (StatsEnumerated)luaL_checkinteger(L, 2);
    bool _hunger = lua_toboolean(L, 3) != 0;
    bool _wounds = lua_toboolean(L, 4) != 0;
    bool _darkness = lua_toboolean(L, 5) != 0;
    bool robotParts = lua_toboolean(L, 6) != 0;
    bool weather = lua_toboolean(L, 7) != 0;
    bool gear = lua_toboolean(L, 8) != 0;
    float result = b->getHealthStatModifier(stat, _hunger, _wounds, _darkness, robotParts, weather, gear);
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::_getRoboticsStatMult(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    StatsEnumerated stat = (StatsEnumerated)luaL_checkinteger(L, 2);
    float result = b->_getRoboticsStatMult(stat);
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::getMissingArmPenaltyMult(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float result = b->getMissingArmPenaltyMult();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::getDerivedHeadHealth(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float result = b->getDerivedHeadHealth();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::calculateDesiredPainAnimations(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    b->calculateDesiredPainAnimations();
    return 0;
}

int MedicalSystemBinding::getMovementSpeedInjuryMultiplier(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float result = b->getMovementSpeedInjuryMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::getStatRoboticsMultiplier(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    StatsEnumerated stat = (StatsEnumerated)luaL_checkinteger(L, 2);
    float result = b->getStatRoboticsMultiplier(stat);
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::getMovementSwimSpeedInjuryMultiplier(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float result = b->getMovementSwimSpeedInjuryMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::gettingEaten(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool vampire = lua_toboolean(L, 3) != 0;
    bool result = b->gettingEaten(amount, vampire);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::gettingAcidRain(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool result = b->gettingAcidRain(amount);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::gettingAcidWater(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool result = b->gettingAcidWater(amount);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::gettingAcidFeet(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool result = b->gettingAcidFeet(amount);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::gettingGassed(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool result = b->gettingGassed(amount);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::gettingWindyface(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool result = b->gettingWindyface(amount);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::gettingBurnt(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool result = b->gettingBurnt(amount);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::reassessCollapseMode(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    bool medic = lua_toboolean(L, 2) != 0;
    bool agony = lua_toboolean(L, 3) != 0;
    b->reassessCollapseMode(medic, agony);
    return 0;
}

int MedicalSystemBinding::isUnconcious(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    bool result = b->isUnconcious();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::isCrippled(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    bool result = b->isCrippled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::isDead(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    bool result = b->isDead();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::hasAnArmToFightWith(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    bool result = b->hasAnArmToFightWith();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::hasFreshlySeveredALimb(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    bool result = b->hasFreshlySeveredALimb();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::isReallyHungry(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    bool result = b->isReallyHungry();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::isProbablyDying(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    bool result = b->isProbablyDying();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::getOverallHealthRating(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float result = b->getOverallHealthRating();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::canGetUpWakeUp(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    bool result = b->canGetUpWakeUp();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::_reassessRagdollPartsAssumingWeJustClearedTheEntireRagdoll(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    b->_reassessRagdollPartsAssumingWeJustClearedTheEntireRagdoll();
    return 0;
}

int MedicalSystemBinding::isRightArmOk(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    bool result = b->isRightArmOk();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::isLeftArmOk(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    bool result = b->isLeftArmOk();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::canIkick(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    bool result = b->canIkick();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::isInBloodlossTrauma(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    bool result = b->isInBloodlossTrauma();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::clearWeatherEffects(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    b->clearWeatherEffects();
    return 0;
}

int MedicalSystemBinding::getWeatherStatPenaltyMult(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float result = b->getWeatherStatPenaltyMult();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::getWeatherStatPenalty(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float mult = (float)luaL_checknumber(L, 2);
    int result = b->getWeatherStatPenalty(mult);
    lua_pushinteger(L, result);
    return 1;
}

int MedicalSystemBinding::calculateBleedRateForFX(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float result = b->calculateBleedRateForFX();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::bloodlossUpdate(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    float frameTime = (float)luaL_checknumber(L, 2);
    b->bloodlossUpdate(frameTime);
    return 0;
}

int MedicalSystemBinding::updateDamageState(lua_State* L)
{
    MedicalSystem* b = getB(L, 1);
    if (!b) return luaL_error(L, "MedicalSystem is nil");

    b->updateDamageState();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 111: void init(...) - unsupported arg type
  line 114: void notifyRaceChange(...) - unsupported arg type
  line 123: LimbState getLimbState(...) - unsupported return type
  line 180: MedicalSystem::HealthPartStatus* getPart(...) - overloaded method
  line 181: MedicalSystem::HealthPartStatus* getPart(...) - overloaded method
  line 182: MedicalSystem::HealthPartStatus* getPart(...) - overloaded method
  line 185: void setRobotLimbItem(...) - unsupported arg type
  line 188: void addArmour(...) - unsupported arg type
  line 189: void removeArmour(...) - unsupported arg type
  line 190: bool wearingUniformOf(...) - unsupported arg type
  line 191: void serialise(...) - unsupported arg type
  line 192: void load(...) - unsupported arg type
  line 193: GameData* addWound(...) - unsupported arg type
  line 194: float punchSomething(...) - unsupported arg type
  line 195: const std::string& getBoneNameForBodypart(...) - static method
  line 230: bool isCollapse(...) - pointer arg
  line 238: MedicalSystem::CollapseStage getCollapseStage(...) - pointer arg
  line 250: bool applyFirstAid(...) - unsupported arg type
  line 251: bool applyDoctoring(...) - unsupported arg type
  line 252: bool applyRigging(...) - unsupported arg type
  line 260: float scoreTechnique(...) - unsupported arg type
  line 261: void getMedicalGUIData(...) - unsupported arg type
  line 271: void splatBlood(...) - unsupported arg type
  line 298: void drainMedkit(...) - unsupported arg type
  line 299: void applyDamage(...) - pointer arg
  line 300: void ragdollPartCollapse(...) - pointer arg
*/

int MedicalSystemBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int MedicalSystemBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MedicalSystem object");
    return 1;
}

void MedicalSystemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       MedicalSystemBinding::gc },
        { "__tostring", MedicalSystemBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "precalculateFirstAidNeedScore", MedicalSystemBinding::precalculateFirstAidNeedScore },
        { "_CONSTRUCTOR", MedicalSystemBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", MedicalSystemBinding::_DESTRUCTOR },
        { "updateStats", MedicalSystemBinding::updateStats },
        { "_NV_updateStats", MedicalSystemBinding::_NV_updateStats },
        { "medicalUpdate", MedicalSystemBinding::medicalUpdate },
        { "periodicUpdate", MedicalSystemBinding::periodicUpdate },
        { "_NV_periodicUpdate", MedicalSystemBinding::_NV_periodicUpdate },
        { "scoreFirstAidNeed", MedicalSystemBinding::scoreFirstAidNeed },
        { "scoreJuryRigNeed", MedicalSystemBinding::scoreJuryRigNeed },
        { "isFullyRested", MedicalSystemBinding::isFullyRested },
        { "_setHealth", MedicalSystemBinding::_setHealth },
        { "validateHealthValues", MedicalSystemBinding::validateHealthValues },
        { "amputate", MedicalSystemBinding::amputate },
        { "crushLimb", MedicalSystemBinding::crushLimb },
        { "isUselessNoLimbGuy", MedicalSystemBinding::isUselessNoLimbGuy },
        { "recalculateStealthHinderance", MedicalSystemBinding::recalculateStealthHinderance },
        { "getPartCount", MedicalSystemBinding::getPartCount },
        { "hasRobotics", MedicalSystemBinding::hasRobotics },
        { "isFed", MedicalSystemBinding::isFed },
        { "getMaxBlood", MedicalSystemBinding::getMaxBlood },
        { "startKnockoutTimer", MedicalSystemBinding::startKnockoutTimer },
        { "knockout", MedicalSystemBinding::knockout },
        { "knockoutForceTimer", MedicalSystemBinding::knockoutForceTimer },
        { "pointOfCollapseBloodloss", MedicalSystemBinding::pointOfCollapseBloodloss },
        { "pointOfNoReturn", MedicalSystemBinding::pointOfNoReturn },
        { "pointOfNoReturn_Hunger01", MedicalSystemBinding::pointOfNoReturn_Hunger01 },
        { "isHungerKO", MedicalSystemBinding::isHungerKO },
        { "getToughnessXpBonus", MedicalSystemBinding::getToughnessXpBonus },
        { "getHungerSpeedModifier", MedicalSystemBinding::getHungerSpeedModifier },
        { "getHealthStatModifier", MedicalSystemBinding::getHealthStatModifier },
        { "_getRoboticsStatMult", MedicalSystemBinding::_getRoboticsStatMult },
        { "getMissingArmPenaltyMult", MedicalSystemBinding::getMissingArmPenaltyMult },
        { "getDerivedHeadHealth", MedicalSystemBinding::getDerivedHeadHealth },
        { "calculateDesiredPainAnimations", MedicalSystemBinding::calculateDesiredPainAnimations },
        { "getMovementSpeedInjuryMultiplier", MedicalSystemBinding::getMovementSpeedInjuryMultiplier },
        { "getStatRoboticsMultiplier", MedicalSystemBinding::getStatRoboticsMultiplier },
        { "getMovementSwimSpeedInjuryMultiplier", MedicalSystemBinding::getMovementSwimSpeedInjuryMultiplier },
        { "gettingEaten", MedicalSystemBinding::gettingEaten },
        { "gettingAcidRain", MedicalSystemBinding::gettingAcidRain },
        { "gettingAcidWater", MedicalSystemBinding::gettingAcidWater },
        { "gettingAcidFeet", MedicalSystemBinding::gettingAcidFeet },
        { "gettingGassed", MedicalSystemBinding::gettingGassed },
        { "gettingWindyface", MedicalSystemBinding::gettingWindyface },
        { "gettingBurnt", MedicalSystemBinding::gettingBurnt },
        { "reassessCollapseMode", MedicalSystemBinding::reassessCollapseMode },
        { "isUnconcious", MedicalSystemBinding::isUnconcious },
        { "isCrippled", MedicalSystemBinding::isCrippled },
        { "isDead", MedicalSystemBinding::isDead },
        { "hasAnArmToFightWith", MedicalSystemBinding::hasAnArmToFightWith },
        { "hasFreshlySeveredALimb", MedicalSystemBinding::hasFreshlySeveredALimb },
        { "isReallyHungry", MedicalSystemBinding::isReallyHungry },
        { "isProbablyDying", MedicalSystemBinding::isProbablyDying },
        { "getOverallHealthRating", MedicalSystemBinding::getOverallHealthRating },
        { "canGetUpWakeUp", MedicalSystemBinding::canGetUpWakeUp },
        { "_reassessRagdollPartsAssumingWeJustClearedTheEntireRagdoll", MedicalSystemBinding::_reassessRagdollPartsAssumingWeJustClearedTheEntireRagdoll },
        { "isRightArmOk", MedicalSystemBinding::isRightArmOk },
        { "isLeftArmOk", MedicalSystemBinding::isLeftArmOk },
        { "canIkick", MedicalSystemBinding::canIkick },
        { "isInBloodlossTrauma", MedicalSystemBinding::isInBloodlossTrauma },
        { "clearWeatherEffects", MedicalSystemBinding::clearWeatherEffects },
        { "getWeatherStatPenaltyMult", MedicalSystemBinding::getWeatherStatPenaltyMult },
        { "getWeatherStatPenalty", MedicalSystemBinding::getWeatherStatPenalty },
        { "calculateBleedRateForFX", MedicalSystemBinding::calculateBleedRateForFX },
        { "bloodlossUpdate", MedicalSystemBinding::bloodlossUpdate },
        { "updateDamageState", MedicalSystemBinding::updateDamageState },
        { 0, 0 }
    };

    registerClass(
        L, 
        MedicalSystemBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, MedicalSystemBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, MedicalSystem_get_status);
    lua_setfield(L, -2, "status");
    lua_pushcfunction(L, MedicalSystem_get_armourList);
    lua_setfield(L, -2, "armourList");
    lua_pushcfunction(L, MedicalSystem_get_hunger);
    lua_setfield(L, -2, "hunger");
    lua_pushcfunction(L, MedicalSystem_get_fed);
    lua_setfield(L, -2, "fed");
    lua_pushcfunction(L, MedicalSystem_get_lastPeriodicUpdate);
    lua_setfield(L, -2, "lastPeriodicUpdate");
    lua_pushcfunction(L, MedicalSystem_get_blood);
    lua_setfield(L, -2, "blood");
    lua_pushcfunction(L, MedicalSystem_get_extraBloodLossFromBodyparts);
    lua_setfield(L, -2, "extraBloodLossFromBodyparts");
    lua_pushcfunction(L, MedicalSystem_get_currentBleedRate);
    lua_setfield(L, -2, "currentBleedRate");
    lua_pushcfunction(L, MedicalSystem_get_leftLeg);
    lua_setfield(L, -2, "leftLeg");
    lua_pushcfunction(L, MedicalSystem_get_rightLeg);
    lua_setfield(L, -2, "rightLeg");
    lua_pushcfunction(L, MedicalSystem_get_leftArm);
    lua_setfield(L, -2, "leftArm");
    lua_pushcfunction(L, MedicalSystem_get_rightArm);
    lua_setfield(L, -2, "rightArm");
    lua_pushcfunction(L, MedicalSystem_get_knockoutTimer);
    lua_setfield(L, -2, "knockoutTimer");
    lua_pushcfunction(L, MedicalSystem_get_worstDamage);
    lua_setfield(L, -2, "worstDamage");
    lua_pushcfunction(L, MedicalSystem_get_needsFirstAidScoreTotal_robot);
    lua_setfield(L, -2, "needsFirstAidScoreTotal_robot");
    lua_pushcfunction(L, MedicalSystem_get_needsFirstAidScoreTotal_fleshy);
    lua_setfield(L, -2, "needsFirstAidScoreTotal_fleshy");
    lua_pushcfunction(L, MedicalSystem_get_restedState);
    lua_setfield(L, -2, "restedState");
    lua_pushcfunction(L, MedicalSystem_get_stealthHinderance);
    lua_setfield(L, -2, "stealthHinderance");
    lua_pushcfunction(L, MedicalSystem_get_partBestArm);
    lua_setfield(L, -2, "partBestArm");
    lua_pushcfunction(L, MedicalSystem_get_partHead);
    lua_setfield(L, -2, "partHead");
    lua_pushcfunction(L, MedicalSystem_get_partWorstTorso);
    lua_setfield(L, -2, "partWorstTorso");
    lua_pushcfunction(L, MedicalSystem_get_dazedOrAlert);
    lua_setfield(L, -2, "dazedOrAlert");
    lua_pushcfunction(L, MedicalSystem_get_robotLimbs);
    lua_setfield(L, -2, "robotLimbs");
    lua_pushcfunction(L, MedicalSystem_get_bloodynessChanged);
    lua_setfield(L, -2, "bloodynessChanged");
    lua_pushcfunction(L, MedicalSystem_get_bloodynessCleanedUp);
    lua_setfield(L, -2, "bloodynessCleanedUp");
    lua_pushcfunction(L, MedicalSystem_get_animation);
    lua_setfield(L, -2, "animation");
    lua_pushcfunction(L, MedicalSystem_get_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, MedicalSystem_get_weatherGUIfeedback);
    lua_setfield(L, -2, "weatherGUIfeedback");
    lua_pushcfunction(L, MedicalSystem_get_currentWeatherAffect);
    lua_setfield(L, -2, "currentWeatherAffect");
    lua_pushcfunction(L, MedicalSystem_get_currentWeatherAffectStrength);
    lua_setfield(L, -2, "currentWeatherAffectStrength");
    lua_pushcfunction(L, MedicalSystem_get_lastHungerKO);
    lua_setfield(L, -2, "lastHungerKO");
    lua_pushcfunction(L, MedicalSystem_get_nextKOTime);
    lua_setfield(L, -2, "nextKOTime");
    lua_pushcfunction(L, MedicalSystem_get__eatenDeathDelay);
    lua_setfield(L, -2, "_eatenDeathDelay");
    lua_pushcfunction(L, MedicalSystem_get_crippled);
    lua_setfield(L, -2, "crippled");
    lua_pushcfunction(L, MedicalSystem_get_unconcious);
    lua_setfield(L, -2, "unconcious");
    lua_pushcfunction(L, MedicalSystem_get_sub50KO);
    lua_setfield(L, -2, "sub50KO");
    lua_pushcfunction(L, MedicalSystem_get_bloodlossTrauma);
    lua_setfield(L, -2, "bloodlossTrauma");
    lua_pushcfunction(L, MedicalSystem_get_dead);
    lua_setfield(L, -2, "dead");
    lua_pushcfunction(L, MedicalSystem_get_rightArmOk);
    lua_setfield(L, -2, "rightArmOk");
    lua_pushcfunction(L, MedicalSystem_get_leftArmOk);
    lua_setfield(L, -2, "leftArmOk");
    lua_pushcfunction(L, MedicalSystem_get_lastBloodPosition);
    lua_setfield(L, -2, "lastBloodPosition");
    lua_pushcfunction(L, MedicalSystem_get_wounds);
    lua_setfield(L, -2, "wounds");
    lua_pushcfunction(L, MedicalSystem_get_anatomy);
    lua_setfield(L, -2, "anatomy");
    lua_pushcfunction(L, MedicalSystem_get_stats);
    lua_setfield(L, -2, "stats");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, MedicalSystem_set_status);
    lua_setfield(L, -2, "status");
    lua_pushcfunction(L, MedicalSystem_set_armourList);
    lua_setfield(L, -2, "armourList");
    lua_pushcfunction(L, MedicalSystem_set_hunger);
    lua_setfield(L, -2, "hunger");
    lua_pushcfunction(L, MedicalSystem_set_fed);
    lua_setfield(L, -2, "fed");
    lua_pushcfunction(L, MedicalSystem_set_lastPeriodicUpdate);
    lua_setfield(L, -2, "lastPeriodicUpdate");
    lua_pushcfunction(L, MedicalSystem_set_blood);
    lua_setfield(L, -2, "blood");
    lua_pushcfunction(L, MedicalSystem_set_extraBloodLossFromBodyparts);
    lua_setfield(L, -2, "extraBloodLossFromBodyparts");
    lua_pushcfunction(L, MedicalSystem_set_currentBleedRate);
    lua_setfield(L, -2, "currentBleedRate");
    lua_pushcfunction(L, MedicalSystem_set_leftLeg);
    lua_setfield(L, -2, "leftLeg");
    lua_pushcfunction(L, MedicalSystem_set_rightLeg);
    lua_setfield(L, -2, "rightLeg");
    lua_pushcfunction(L, MedicalSystem_set_leftArm);
    lua_setfield(L, -2, "leftArm");
    lua_pushcfunction(L, MedicalSystem_set_rightArm);
    lua_setfield(L, -2, "rightArm");
    lua_pushcfunction(L, MedicalSystem_set_knockoutTimer);
    lua_setfield(L, -2, "knockoutTimer");
    lua_pushcfunction(L, MedicalSystem_set_worstDamage);
    lua_setfield(L, -2, "worstDamage");
    lua_pushcfunction(L, MedicalSystem_set_needsFirstAidScoreTotal_robot);
    lua_setfield(L, -2, "needsFirstAidScoreTotal_robot");
    lua_pushcfunction(L, MedicalSystem_set_needsFirstAidScoreTotal_fleshy);
    lua_setfield(L, -2, "needsFirstAidScoreTotal_fleshy");
    lua_pushcfunction(L, MedicalSystem_set_restedState);
    lua_setfield(L, -2, "restedState");
    lua_pushcfunction(L, MedicalSystem_set_stealthHinderance);
    lua_setfield(L, -2, "stealthHinderance");
    lua_pushcfunction(L, MedicalSystem_set_partBestArm);
    lua_setfield(L, -2, "partBestArm");
    lua_pushcfunction(L, MedicalSystem_set_partHead);
    lua_setfield(L, -2, "partHead");
    lua_pushcfunction(L, MedicalSystem_set_partWorstTorso);
    lua_setfield(L, -2, "partWorstTorso");
    lua_pushcfunction(L, MedicalSystem_set_dazedOrAlert);
    lua_setfield(L, -2, "dazedOrAlert");
    lua_pushcfunction(L, MedicalSystem_set_robotLimbs);
    lua_setfield(L, -2, "robotLimbs");
    lua_pushcfunction(L, MedicalSystem_set_bloodynessChanged);
    lua_setfield(L, -2, "bloodynessChanged");
    lua_pushcfunction(L, MedicalSystem_set_bloodynessCleanedUp);
    lua_setfield(L, -2, "bloodynessCleanedUp");
    lua_pushcfunction(L, MedicalSystem_set_animation);
    lua_setfield(L, -2, "animation");
    lua_pushcfunction(L, MedicalSystem_set_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, MedicalSystem_set_weatherGUIfeedback);
    lua_setfield(L, -2, "weatherGUIfeedback");
    lua_pushcfunction(L, MedicalSystem_set_currentWeatherAffect);
    lua_setfield(L, -2, "currentWeatherAffect");
    lua_pushcfunction(L, MedicalSystem_set_currentWeatherAffectStrength);
    lua_setfield(L, -2, "currentWeatherAffectStrength");
    lua_pushcfunction(L, MedicalSystem_set_lastHungerKO);
    lua_setfield(L, -2, "lastHungerKO");
    lua_pushcfunction(L, MedicalSystem_set_nextKOTime);
    lua_setfield(L, -2, "nextKOTime");
    lua_pushcfunction(L, MedicalSystem_set__eatenDeathDelay);
    lua_setfield(L, -2, "_eatenDeathDelay");
    lua_pushcfunction(L, MedicalSystem_set_crippled);
    lua_setfield(L, -2, "crippled");
    lua_pushcfunction(L, MedicalSystem_set_unconcious);
    lua_setfield(L, -2, "unconcious");
    lua_pushcfunction(L, MedicalSystem_set_sub50KO);
    lua_setfield(L, -2, "sub50KO");
    lua_pushcfunction(L, MedicalSystem_set_bloodlossTrauma);
    lua_setfield(L, -2, "bloodlossTrauma");
    lua_pushcfunction(L, MedicalSystem_set_dead);
    lua_setfield(L, -2, "dead");
    lua_pushcfunction(L, MedicalSystem_set_rightArmOk);
    lua_setfield(L, -2, "rightArmOk");
    lua_pushcfunction(L, MedicalSystem_set_leftArmOk);
    lua_setfield(L, -2, "leftArmOk");
    lua_pushcfunction(L, MedicalSystem_set_lastBloodPosition);
    lua_setfield(L, -2, "lastBloodPosition");
    lua_pushcfunction(L, MedicalSystem_set_wounds);
    lua_setfield(L, -2, "wounds");
    lua_pushcfunction(L, MedicalSystem_set_anatomy);
    lua_setfield(L, -2, "anatomy");
    lua_pushcfunction(L, MedicalSystem_set_stats);
    lua_setfield(L, -2, "stats");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua