#include "pch.h"
#include "kenshi\MedicalSystem.h"
#include "MedicalSystemBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/ArmourBinding.h"
#include "Bindings/CharStatsBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/CombatTechniqueDataBinding.h"
#include "Bindings/DamagesBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/HealthPartStatusBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/RobotLimbsBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/Util/StringPairBinding.h"
#include "Bindings/Util/TimeOfDayBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"

namespace KenshiLua
{

template <>
struct LuaCodec<MedicalSystem::HealthPartStatus>
{
    static int push(lua_State* L, const MedicalSystem::HealthPartStatus& val, const char* metaName)
    {
        return pushValue<MedicalSystem::HealthPartStatus>(L, val, metaName ? metaName : HealthPartStatusBinding::getMetatableName());
    }
    static MedicalSystem::HealthPartStatus read(lua_State* L, int idx, const char* metaName)
    {
        MedicalSystem::HealthPartStatus* obj = checkObject<MedicalSystem::HealthPartStatus>(L, idx, metaName ? metaName : HealthPartStatusBinding::getMetatableName());
        return obj ? *obj : MedicalSystem::HealthPartStatus();
    }
};

typedef OgreUnorderedMapBinding<GameData*, MedicalSystem::HealthPartStatus> HealthStatusMapBinding;

static MedicalSystem* getInstance(lua_State* L, int idx)
{
    return checkObject<MedicalSystem>(L, idx, MedicalSystemBinding::getMetatableName());
}

// --- Getters for MedicalSystem ---
static int MedicalSystem_get_status(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    return pushObject<ogre_unordered_map<GameData*, MedicalSystem::HealthPartStatus>::type>(L, &instance->status, "ogre_unordered_map<GameData*, HealthPartStatus>");
}

static int MedicalSystem_get_armourList(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    return pushObject<lektor<Armour*>>(L, &instance->armourList, LektorPtrBinding<Armour*>::getMetatableName());
}

static int MedicalSystem_get_hunger(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, instance->hunger);
    return 1;
}

static int MedicalSystem_get_fed(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, instance->fed);
    return 1;
}

static int MedicalSystem_get_lastPeriodicUpdate(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    return pushObject<TimeOfDay>(L, &instance->lastPeriodicUpdate, TimeOfDayBinding::getMetatableName());
}

static int MedicalSystem_get_blood(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, instance->blood);
    return 1;
}

static int MedicalSystem_get_extraBloodLossFromBodyparts(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, instance->extraBloodLossFromBodyparts);
    return 1;
}

static int MedicalSystem_get_currentBleedRate(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, instance->currentBleedRate);
    return 1;
}

static int MedicalSystem_get_leftLeg(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    return pushObject<MedicalSystem::HealthPartStatus>(L, instance->leftLeg, HealthPartStatusBinding::getMetatableName());
}

static int MedicalSystem_get_rightLeg(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    return pushObject<MedicalSystem::HealthPartStatus>(L, instance->rightLeg, HealthPartStatusBinding::getMetatableName());
}

static int MedicalSystem_get_leftArm(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    return pushObject<MedicalSystem::HealthPartStatus>(L, instance->leftArm, HealthPartStatusBinding::getMetatableName());
}

static int MedicalSystem_get_rightArm(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    return pushObject<MedicalSystem::HealthPartStatus>(L, instance->rightArm, HealthPartStatusBinding::getMetatableName());
}

static int MedicalSystem_get_knockoutTimer(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, instance->knockoutTimer);
    return 1;
}

static int MedicalSystem_get_worstDamage(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, instance->worstDamage);
    return 1;
}

static int MedicalSystem_get_needsFirstAidScoreTotal_robot(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, instance->needsFirstAidScoreTotal_robot);
    return 1;
}

static int MedicalSystem_get_needsFirstAidScoreTotal_fleshy(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, instance->needsFirstAidScoreTotal_fleshy);
    return 1;
}

static int MedicalSystem_get_restedState(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, instance->restedState);
    return 1;
}

static int MedicalSystem_get_stealthHinderance(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, instance->stealthHinderance);
    return 1;
}

static int MedicalSystem_get_partBestArm(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, instance->partBestArm);
    return 1;
}

static int MedicalSystem_get_partHead(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, instance->partHead);
    return 1;
}

static int MedicalSystem_get_partWorstTorso(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, instance->partWorstTorso);
    return 1;
}

static int MedicalSystem_get_dazedOrAlert(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, instance->dazedOrAlert);
    return 1;
}

static int MedicalSystem_get_robotLimbs(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    return pushObject<RobotLimbs>(L, instance->robotLimbs, RobotLimbsBinding::getMetatableName());
}

static int MedicalSystem_get_bloodynessChanged(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushboolean(L, instance->bloodynessChanged ? 1 : 0);
    return 1;
}

static int MedicalSystem_get_bloodynessCleanedUp(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushboolean(L, instance->bloodynessCleanedUp ? 1 : 0);
    return 1;
}

static int MedicalSystem_get_me(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    return pushObject<Character>(L, instance->me, CharacterBinding::getMetatableName());
}

static int MedicalSystem_get_weatherGUIfeedback(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    return pushObject<StringPair>(L, &instance->weatherGUIfeedback, StringPairBinding::getMetatableName());
}

static int MedicalSystem_get_currentWeatherAffect(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushinteger(L, (lua_Integer)instance->currentWeatherAffect);
    return 1;
}

static int MedicalSystem_get_currentWeatherAffectStrength(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, instance->currentWeatherAffectStrength);
    return 1;
}

static int MedicalSystem_get_lastHungerKO(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    return pushObject<TimeOfDay>(L, &instance->lastHungerKO, TimeOfDayBinding::getMetatableName());
}

static int MedicalSystem_get_nextKOTime(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushnumber(L, instance->nextKOTime);
    return 1;
}

static int MedicalSystem_get__eatenDeathDelay(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushinteger(L, instance->_eatenDeathDelay);
    return 1;
}

static int MedicalSystem_get_crippled(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushboolean(L, instance->crippled ? 1 : 0);
    return 1;
}

static int MedicalSystem_get_unconcious(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushboolean(L, instance->unconcious ? 1 : 0);
    return 1;
}

static int MedicalSystem_get_sub50KO(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushboolean(L, instance->sub50KO ? 1 : 0);
    return 1;
}

static int MedicalSystem_get_bloodlossTrauma(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushboolean(L, instance->bloodlossTrauma ? 1 : 0);
    return 1;
}

static int MedicalSystem_get_dead(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushboolean(L, instance->dead ? 1 : 0);
    return 1;
}

static int MedicalSystem_get_rightArmOk(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushboolean(L, instance->rightArmOk ? 1 : 0);
    return 1;
}

static int MedicalSystem_get_leftArmOk(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    lua_pushboolean(L, instance->leftArmOk ? 1 : 0);
    return 1;
}

static int MedicalSystem_get_lastBloodPosition(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    pushVector3(L, instance->lastBloodPosition);
    return 1;
}

static int MedicalSystem_get_anatomy(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    return pushObject<lektor<MedicalSystem::HealthPartStatus*>>(L, &instance->anatomy, LektorPtrBinding<MedicalSystem::HealthPartStatus*>::getMetatableName());
}

static int MedicalSystem_get_stats(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    return pushObject<CharStats>(L, instance->stats, CharStatsBinding::getMetatableName());
}

// --- Setters for MedicalSystem ---
static int MedicalSystem_set_status(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    auto* val = HealthStatusMapBinding::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'status' must be ogre_unordered_map<GameData*, HealthPartStatus>");
    instance->status = *val;
    return 0;
}

static int MedicalSystem_set_armourList(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    auto* val = LektorPtrBinding<Armour*>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'armourList' must be lektor<Armour*>");
    instance->armourList = *val;
    return 0;
}

static int MedicalSystem_set_hunger(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->hunger = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_fed(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->fed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_lastPeriodicUpdate(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    TimeOfDay* val = checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    if (val) instance->lastPeriodicUpdate = *val;
    return 0;
}

static int MedicalSystem_set_blood(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->blood = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_extraBloodLossFromBodyparts(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->extraBloodLossFromBodyparts = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_currentBleedRate(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->currentBleedRate = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_leftLeg(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->leftLeg = lua_isnoneornil(L, 2) ? nullptr : checkObject<MedicalSystem::HealthPartStatus>(L, 2, HealthPartStatusBinding::getMetatableName());
    return 0;
}

static int MedicalSystem_set_rightLeg(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->rightLeg = lua_isnoneornil(L, 2) ? nullptr : checkObject<MedicalSystem::HealthPartStatus>(L, 2, HealthPartStatusBinding::getMetatableName());
    return 0;
}

static int MedicalSystem_set_leftArm(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->leftArm = lua_isnoneornil(L, 2) ? nullptr : checkObject<MedicalSystem::HealthPartStatus>(L, 2, HealthPartStatusBinding::getMetatableName());
    return 0;
}

static int MedicalSystem_set_rightArm(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->rightArm = lua_isnoneornil(L, 2) ? nullptr : checkObject<MedicalSystem::HealthPartStatus>(L, 2, HealthPartStatusBinding::getMetatableName());
    return 0;
}

static int MedicalSystem_set_knockoutTimer(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->knockoutTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_worstDamage(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->worstDamage = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_needsFirstAidScoreTotal_robot(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->needsFirstAidScoreTotal_robot = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_needsFirstAidScoreTotal_fleshy(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->needsFirstAidScoreTotal_fleshy = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_restedState(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->restedState = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_stealthHinderance(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->stealthHinderance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_partBestArm(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->partBestArm = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_partHead(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->partHead = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_partWorstTorso(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->partWorstTorso = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_dazedOrAlert(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->dazedOrAlert = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_robotLimbs(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->robotLimbs = lua_isnoneornil(L, 2) ? nullptr : checkObject<RobotLimbs>(L, 2, RobotLimbsBinding::getMetatableName());
    return 0;
}

static int MedicalSystem_set_bloodynessChanged(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->bloodynessChanged = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MedicalSystem_set_bloodynessCleanedUp(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->bloodynessCleanedUp = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MedicalSystem_set_me(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->me = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int MedicalSystem_set_weatherGUIfeedback(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    StringPair* val = checkObject<StringPair>(L, 2, StringPairBinding::getMetatableName());
    if (val) instance->weatherGUIfeedback = *val;
    return 0;
}

static int MedicalSystem_set_currentWeatherAffect(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->currentWeatherAffect = (WeatherAffecting)luaL_checkinteger(L, 2);
    return 0;
}

static int MedicalSystem_set_currentWeatherAffectStrength(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->currentWeatherAffectStrength = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set_lastHungerKO(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    TimeOfDay* val = checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    if (val) instance->lastHungerKO = *val;
    return 0;
}

static int MedicalSystem_set_nextKOTime(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->nextKOTime = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MedicalSystem_set__eatenDeathDelay(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->_eatenDeathDelay = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int MedicalSystem_set_crippled(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->crippled = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MedicalSystem_set_unconcious(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->unconcious = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MedicalSystem_set_sub50KO(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->sub50KO = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MedicalSystem_set_bloodlossTrauma(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->bloodlossTrauma = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MedicalSystem_set_dead(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->dead = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MedicalSystem_set_rightArmOk(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->rightArmOk = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MedicalSystem_set_leftArmOk(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->leftArmOk = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MedicalSystem_set_lastBloodPosition(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    readVector3(L, 2, instance->lastBloodPosition);
    return 0;
}

static int MedicalSystem_set_anatomy(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    auto* val = LektorPtrBinding<MedicalSystem::HealthPartStatus*>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'anatomy' must be lektor<HealthPartStatus*>");
    instance->anatomy = *val;
    return 0;
}

static int MedicalSystem_set_stats(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");
    instance->stats = lua_isnoneornil(L, 2) ? nullptr : checkObject<CharStats>(L, 2, CharStatsBinding::getMetatableName());
    return 0;
}

int MedicalSystemBinding::precalculateFirstAidNeedScore(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    instance->precalculateFirstAidNeedScore();
    return 0;
}

int MedicalSystemBinding::scoreFirstAidNeed(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    bool robotAid = lua_toboolean(L, 2) != 0;
    float result = instance->scoreFirstAidNeed(robotAid);
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::scoreJuryRigNeed(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float skills = (float)luaL_checknumber(L, 2);
    float result = instance->scoreJuryRigNeed(skills);
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::isFullyRested(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    bool result = instance->isFullyRested();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::validateHealthValues(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    instance->validateHealthValues();
    return 0;
}

int MedicalSystemBinding::amputate(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    RobotLimbs::Limb limb = (RobotLimbs::Limb)luaL_checkinteger(L, 2);
    bool createSeveredItem = lua_toboolean(L, 3) != 0;
    Ogre::Vector3 force(0, 0, 0);
    readVector3(L, 4, force);
    instance->amputate(limb, createSeveredItem, force);
    return 0;
}

int MedicalSystemBinding::crushLimb(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    RobotLimbs::Limb limb = (RobotLimbs::Limb)luaL_checkinteger(L, 2);
    instance->crushLimb(limb);
    return 0;
}

int MedicalSystemBinding::isUselessNoLimbGuy(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    bool result = instance->isUselessNoLimbGuy();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::recalculateStealthHinderance(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float result = instance->recalculateStealthHinderance();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::getPartCount(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    int result = instance->getPartCount();
    lua_pushinteger(L, result);
    return 1;
}

int MedicalSystemBinding::hasRobotics(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    bool result = instance->hasRobotics();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::isFed(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    bool result = instance->isFed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::getMaxBlood(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float result = instance->getMaxBlood();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::startKnockoutTimer(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    instance->startKnockoutTimer();
    return 0;
}

int MedicalSystemBinding::knockout(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float skill = (float)luaL_checknumber(L, 2);
    instance->knockout(skill);
    return 0;
}

int MedicalSystemBinding::knockoutForceTimer(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float seconds = (float)luaL_checknumber(L, 2);
    instance->knockoutForceTimer(seconds);
    return 0;
}

int MedicalSystemBinding::pointOfCollapseBloodloss(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float result = instance->pointOfCollapseBloodloss();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::pointOfNoReturn(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float result = instance->pointOfNoReturn();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::isHungerKO(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    bool result = instance->isHungerKO();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::getToughnessXpBonus(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float result = instance->getToughnessXpBonus();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::getHungerSpeedModifier(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float result = instance->getHungerSpeedModifier();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::getMissingArmPenaltyMult(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float result = instance->getMissingArmPenaltyMult();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::getDerivedHeadHealth(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float result = instance->getDerivedHeadHealth();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::calculateDesiredPainAnimations(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    instance->calculateDesiredPainAnimations();
    return 0;
}

int MedicalSystemBinding::getMovementSpeedInjuryMultiplier(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float result = instance->getMovementSpeedInjuryMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::getMovementSwimSpeedInjuryMultiplier(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float result = instance->getMovementSwimSpeedInjuryMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::gettingEaten(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool vampire = lua_toboolean(L, 3) != 0;
    bool result = instance->gettingEaten(amount, vampire);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::gettingAcidRain(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool result = instance->gettingAcidRain(amount);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::gettingAcidWater(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool result = instance->gettingAcidWater(amount);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::gettingAcidFeet(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool result = instance->gettingAcidFeet(amount);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::gettingGassed(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool result = instance->gettingGassed(amount);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::gettingWindyface(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool result = instance->gettingWindyface(amount);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::gettingBurnt(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool result = instance->gettingBurnt(amount);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::reassessCollapseMode(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    bool medic = lua_toboolean(L, 2) != 0;
    bool agony = lua_toboolean(L, 3) != 0;
    instance->reassessCollapseMode(medic, agony);
    return 0;
}

int MedicalSystemBinding::isUnconcious(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    bool result = instance->isUnconcious();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::isCrippled(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    bool result = instance->isCrippled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::isDead(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    bool result = instance->isDead();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::hasAnArmToFightWith(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    bool result = instance->hasAnArmToFightWith();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::hasFreshlySeveredALimb(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    bool result = instance->hasFreshlySeveredALimb();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::isReallyHungry(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    bool result = instance->isReallyHungry();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::isProbablyDying(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    bool result = instance->isProbablyDying();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::getOverallHealthRating(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float result = instance->getOverallHealthRating();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::canGetUpWakeUp(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    bool result = instance->canGetUpWakeUp();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::isRightArmOk(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    bool result = instance->isRightArmOk();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::isLeftArmOk(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    bool result = instance->isLeftArmOk();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::canIkick(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    bool result = instance->canIkick();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::isInBloodlossTrauma(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    bool result = instance->isInBloodlossTrauma();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::clearWeatherEffects(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    instance->clearWeatherEffects();
    return 0;
}

int MedicalSystemBinding::getWeatherStatPenaltyMult(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float result = instance->getWeatherStatPenaltyMult();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::getWeatherStatPenalty(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float mult = (float)luaL_checknumber(L, 2);
    int result = instance->getWeatherStatPenalty(mult);
    lua_pushinteger(L, result);
    return 1;
}

int MedicalSystemBinding::calculateBleedRateForFX(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float result = instance->calculateBleedRateForFX();
    lua_pushnumber(L, result);
    return 1;
}

int MedicalSystemBinding::gc(lua_State* L)
{
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
        { "scoreFirstAidNeed", MedicalSystemBinding::scoreFirstAidNeed },
        { "scoreJuryRigNeed", MedicalSystemBinding::scoreJuryRigNeed },
        { "isFullyRested", MedicalSystemBinding::isFullyRested },
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
        { "isHungerKO", MedicalSystemBinding::isHungerKO },
        { "getToughnessXpBonus", MedicalSystemBinding::getToughnessXpBonus },
        { "getHungerSpeedModifier", MedicalSystemBinding::getHungerSpeedModifier },
        { "getMissingArmPenaltyMult", MedicalSystemBinding::getMissingArmPenaltyMult },
        { "getDerivedHeadHealth", MedicalSystemBinding::getDerivedHeadHealth },
        { "calculateDesiredPainAnimations", MedicalSystemBinding::calculateDesiredPainAnimations },
        { "getMovementSpeedInjuryMultiplier", MedicalSystemBinding::getMovementSpeedInjuryMultiplier },
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
        { "isRightArmOk", MedicalSystemBinding::isRightArmOk },
        { "isLeftArmOk", MedicalSystemBinding::isLeftArmOk },
        { "canIkick", MedicalSystemBinding::canIkick },
        { "isInBloodlossTrauma", MedicalSystemBinding::isInBloodlossTrauma },
        { "clearWeatherEffects", MedicalSystemBinding::clearWeatherEffects },
        { "getWeatherStatPenaltyMult", MedicalSystemBinding::getWeatherStatPenaltyMult },
        { "getWeatherStatPenalty", MedicalSystemBinding::getWeatherStatPenalty },
        { "calculateBleedRateForFX", MedicalSystemBinding::calculateBleedRateForFX },
        { "_setHealth", MedicalSystemBinding::_setHealth },
        { "getLimbState", MedicalSystemBinding::getLimbState },
        { "getPart", MedicalSystemBinding::getPart },
        { "addArmour", MedicalSystemBinding::addArmour },
        { "removeArmour", MedicalSystemBinding::removeArmour },
        { "wearingUniformOf", MedicalSystemBinding::wearingUniformOf },
        { "applyFirstAid", MedicalSystemBinding::applyFirstAid },
        { "applyDoctoring", MedicalSystemBinding::applyDoctoring },
        { "applyRigging", MedicalSystemBinding::applyRigging },
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
    registerGetter(L, "status", MedicalSystem_get_status);
    registerGetter(L, "armourList", MedicalSystem_get_armourList);
    registerGetter(L, "hunger", MedicalSystem_get_hunger);
    registerGetter(L, "fed", MedicalSystem_get_fed);
    registerGetter(L, "lastPeriodicUpdate", MedicalSystem_get_lastPeriodicUpdate);
    registerGetter(L, "blood", MedicalSystem_get_blood);
    registerGetter(L, "extraBloodLossFromBodyparts", MedicalSystem_get_extraBloodLossFromBodyparts);
    registerGetter(L, "currentBleedRate", MedicalSystem_get_currentBleedRate);
    registerGetter(L, "leftLeg", MedicalSystem_get_leftLeg);
    registerGetter(L, "rightLeg", MedicalSystem_get_rightLeg);
    registerGetter(L, "leftArm", MedicalSystem_get_leftArm);
    registerGetter(L, "rightArm", MedicalSystem_get_rightArm);
    registerGetter(L, "knockoutTimer", MedicalSystem_get_knockoutTimer);
    registerGetter(L, "worstDamage", MedicalSystem_get_worstDamage);
    registerGetter(L, "needsFirstAidScoreTotal_robot", MedicalSystem_get_needsFirstAidScoreTotal_robot);
    registerGetter(L, "needsFirstAidScoreTotal_fleshy", MedicalSystem_get_needsFirstAidScoreTotal_fleshy);
    registerGetter(L, "restedState", MedicalSystem_get_restedState);
    registerGetter(L, "stealthHinderance", MedicalSystem_get_stealthHinderance);
    registerGetter(L, "partBestArm", MedicalSystem_get_partBestArm);
    registerGetter(L, "partHead", MedicalSystem_get_partHead);
    registerGetter(L, "partWorstTorso", MedicalSystem_get_partWorstTorso);
    registerGetter(L, "dazedOrAlert", MedicalSystem_get_dazedOrAlert);
    registerGetter(L, "robotLimbs", MedicalSystem_get_robotLimbs);
    registerGetter(L, "bloodynessChanged", MedicalSystem_get_bloodynessChanged);
    registerGetter(L, "bloodynessCleanedUp", MedicalSystem_get_bloodynessCleanedUp);
    registerGetter(L, "me", MedicalSystem_get_me);
    registerGetter(L, "weatherGUIfeedback", MedicalSystem_get_weatherGUIfeedback);
    registerGetter(L, "currentWeatherAffect", MedicalSystem_get_currentWeatherAffect);
    registerGetter(L, "currentWeatherAffectStrength", MedicalSystem_get_currentWeatherAffectStrength);
    registerGetter(L, "lastHungerKO", MedicalSystem_get_lastHungerKO);
    registerGetter(L, "nextKOTime", MedicalSystem_get_nextKOTime);
    registerGetter(L, "_eatenDeathDelay", MedicalSystem_get__eatenDeathDelay);
    registerGetter(L, "crippled", MedicalSystem_get_crippled);
    registerGetter(L, "unconcious", MedicalSystem_get_unconcious);
    registerGetter(L, "sub50KO", MedicalSystem_get_sub50KO);
    registerGetter(L, "bloodlossTrauma", MedicalSystem_get_bloodlossTrauma);
    registerGetter(L, "dead", MedicalSystem_get_dead);
    registerGetter(L, "rightArmOk", MedicalSystem_get_rightArmOk);
    registerGetter(L, "leftArmOk", MedicalSystem_get_leftArmOk);
    registerGetter(L, "lastBloodPosition", MedicalSystem_get_lastBloodPosition);
    registerGetter(L, "anatomy", MedicalSystem_get_anatomy);
    registerGetter(L, "stats", MedicalSystem_get_stats);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "status", MedicalSystem_set_status);
    registerSetter(L, "armourList", MedicalSystem_set_armourList);
    registerSetter(L, "hunger", MedicalSystem_set_hunger);
    registerSetter(L, "fed", MedicalSystem_set_fed);
    registerSetter(L, "lastPeriodicUpdate", MedicalSystem_set_lastPeriodicUpdate);
    registerSetter(L, "blood", MedicalSystem_set_blood);
    registerSetter(L, "extraBloodLossFromBodyparts", MedicalSystem_set_extraBloodLossFromBodyparts);
    registerSetter(L, "currentBleedRate", MedicalSystem_set_currentBleedRate);
    registerSetter(L, "leftLeg", MedicalSystem_set_leftLeg);
    registerSetter(L, "rightLeg", MedicalSystem_set_rightLeg);
    registerSetter(L, "leftArm", MedicalSystem_set_leftArm);
    registerSetter(L, "rightArm", MedicalSystem_set_rightArm);
    registerSetter(L, "knockoutTimer", MedicalSystem_set_knockoutTimer);
    registerSetter(L, "worstDamage", MedicalSystem_set_worstDamage);
    registerSetter(L, "needsFirstAidScoreTotal_robot", MedicalSystem_set_needsFirstAidScoreTotal_robot);
    registerSetter(L, "needsFirstAidScoreTotal_fleshy", MedicalSystem_set_needsFirstAidScoreTotal_fleshy);
    registerSetter(L, "restedState", MedicalSystem_set_restedState);
    registerSetter(L, "stealthHinderance", MedicalSystem_set_stealthHinderance);
    registerSetter(L, "partBestArm", MedicalSystem_set_partBestArm);
    registerSetter(L, "partHead", MedicalSystem_set_partHead);
    registerSetter(L, "partWorstTorso", MedicalSystem_set_partWorstTorso);
    registerSetter(L, "dazedOrAlert", MedicalSystem_set_dazedOrAlert);
    registerSetter(L, "robotLimbs", MedicalSystem_set_robotLimbs);
    registerSetter(L, "bloodynessChanged", MedicalSystem_set_bloodynessChanged);
    registerSetter(L, "bloodynessCleanedUp", MedicalSystem_set_bloodynessCleanedUp);
    registerSetter(L, "me", MedicalSystem_set_me);
    registerSetter(L, "weatherGUIfeedback", MedicalSystem_set_weatherGUIfeedback);
    registerSetter(L, "currentWeatherAffect", MedicalSystem_set_currentWeatherAffect);
    registerSetter(L, "currentWeatherAffectStrength", MedicalSystem_set_currentWeatherAffectStrength);
    registerSetter(L, "lastHungerKO", MedicalSystem_set_lastHungerKO);
    registerSetter(L, "nextKOTime", MedicalSystem_set_nextKOTime);
    registerSetter(L, "_eatenDeathDelay", MedicalSystem_set__eatenDeathDelay);
    registerSetter(L, "crippled", MedicalSystem_set_crippled);
    registerSetter(L, "unconcious", MedicalSystem_set_unconcious);
    registerSetter(L, "sub50KO", MedicalSystem_set_sub50KO);
    registerSetter(L, "bloodlossTrauma", MedicalSystem_set_bloodlossTrauma);
    registerSetter(L, "dead", MedicalSystem_set_dead);
    registerSetter(L, "rightArmOk", MedicalSystem_set_rightArmOk);
    registerSetter(L, "leftArmOk", MedicalSystem_set_leftArmOk);
    registerSetter(L, "lastBloodPosition", MedicalSystem_set_lastBloodPosition);
    registerSetter(L, "anatomy", MedicalSystem_set_anatomy);
    registerSetter(L, "stats", MedicalSystem_set_stats);
    lua_setfield(L, -2, "__setters"); // Bind to metatable
    lua_pop(L, 1); // Pop the metatable off the stack

    HealthStatusMapBinding::registerBinding(
        L, 
        "ogre_unordered_map<GameData*, HealthPartStatus>", 
        GameDataBinding::getMetatableName(), 
        HealthPartStatusBinding::getMetatableName()
    );
    LektorPtrBinding<Armour*>::registerBinding(L, "lektor<Armour*>", ArmourBinding::getMetatableName());
    LektorPtrBinding<MedicalSystem::HealthPartStatus*>::registerBinding(L, "lektor<HealthPartStatus*>", HealthPartStatusBinding::getMetatableName());
}

// --- Static Methods ---

int MedicalSystemBinding::_setHealth(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    std::string bodypart = luaL_checkstring(L, 2);
    float amount = (float)luaL_checknumber(L, 3);
    instance->_setHealth(bodypart, amount);
    return 0;
}

int MedicalSystemBinding::getLimbState(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    RobotLimbs::Limb limb = (RobotLimbs::Limb)luaL_checkinteger(L, 2);
    LimbState result = instance->getLimbState(limb);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int MedicalSystemBinding::getPart(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    MedicalSystem::HealthPartStatus* part = nullptr;
    if (lua_isinteger(L, 2) || lua_isnumber(L, 2))
    {
        int arg = (int)luaL_checkinteger(L, 2);
        if (lua_gettop(L) >= 3)
        {
            MedicalSystem::HealthPartStatus::PartType ptype = (MedicalSystem::HealthPartStatus::PartType)arg;
            LeftRight side = (LeftRight)luaL_checkinteger(L, 3);
            part = instance->getPart(ptype, side);
        }
        else
        {
            RobotLimbs::Limb limb = (RobotLimbs::Limb)arg;
            part = instance->getPart(limb);
        }
    }
    return pushObject<MedicalSystem::HealthPartStatus>(L, part, HealthPartStatusBinding::getMetatableName());
}

int MedicalSystemBinding::addArmour(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    Armour* item = checkObject<Armour>(L, 2, ArmourBinding::getMetatableName());
    instance->addArmour(item);
    return 0;
}

int MedicalSystemBinding::removeArmour(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    instance->removeArmour(item);
    return 0;
}

int MedicalSystemBinding::wearingUniformOf(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    bool result = instance->wearingUniformOf(f);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::applyFirstAid(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float skill = (float)luaL_checknumber(L, 2);
    Item* equipment = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    float frameTIME = (float)luaL_checknumber(L, 4);
    Character* who = checkObject<Character>(L, 5, CharacterBinding::getMetatableName());
    bool result = instance->applyFirstAid(skill, equipment, frameTIME, who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::applyDoctoring(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float skill = (float)luaL_checknumber(L, 2);
    Item* equipment = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    float frameTIME = (float)luaL_checknumber(L, 4);
    Character* who = checkObject<Character>(L, 5, CharacterBinding::getMetatableName());
    bool result = instance->applyDoctoring(skill, equipment, frameTIME, who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MedicalSystemBinding::applyRigging(lua_State* L)
{
    MedicalSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MedicalSystem is nil");

    float skill = (float)luaL_checknumber(L, 2);
    Item* equipment = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    float frameTIME = (float)luaL_checknumber(L, 4);
    bool result = instance->applyRigging(skill, equipment, frameTIME);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

} // namespace KenshiLua
