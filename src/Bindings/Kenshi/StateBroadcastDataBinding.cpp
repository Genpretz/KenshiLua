#include "pch.h"
#include "kenshi/StateBroadcastData.h"
#include "StateBroadcastDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/FactionBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/Util/TimeOfDayBinding.h"
#include "Bindings/Kenshi/TownBaseBinding.h"
#include "Bindings/Kenshi/Util/YesNoMaybeBinding.h"

namespace KenshiLua
{

static StateBroadcastData* getInstance(lua_State* L, int idx)
{
    return checkObject<StateBroadcastData>(L, idx, StateBroadcastDataBinding::getMetatableName());
}

// --- Getters for StateBroadcastData ---
static int StateBroadcastData_get__slaveState(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushinteger(L, (lua_Integer)instance->_slaveState);
    return 1;
}

static int StateBroadcastData_get__slaveStateChangedTime(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    return pushObject<TimeOfDay>(L, &instance->_slaveStateChangedTime, TimeOfDayBinding::getMetatableName());
}

static int StateBroadcastData_get_me(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    return pushObject<Character>(L, instance->me, CharacterBinding::getMetatableName());
}

static int StateBroadcastData_get_combatTargetsFaction(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    return pushObject<Faction>(L, instance->combatTargetsFaction, FactionBinding::getMetatableName());
}

static int StateBroadcastData_get_taskTarget(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    return HandBinding::push(L, instance->taskTarget);
}

static int StateBroadcastData_get_isAtHome(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushboolean(L, instance->isAtHome ? 1 : 0);
    return 1;
}

static int StateBroadcastData_get_unconcious(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushboolean(L, instance->unconcious ? 1 : 0);
    return 1;
}

static int StateBroadcastData_get_homeBuilding(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    return HandBinding::push(L, instance->homeBuilding);
}

static int StateBroadcastData_get_intendsToAttack(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    return HandBinding::push(L, instance->intendsToAttack);
}

static int StateBroadcastData_get_currentTownLocation(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    return pushObject<TownBase>(L, instance->currentTownLocation, TownBaseBinding::getMetatableName());
}

static int StateBroadcastData_get_apparentStrength(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushnumber(L, instance->apparentStrength);
    return 1;
}

static int StateBroadcastData_get_actualStrength(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushnumber(L, instance->actualStrength);
    return 1;
}

static int StateBroadcastData_get_distress(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushnumber(L, instance->distress);
    return 1;
}

static int StateBroadcastData_get_mobility(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushnumber(L, instance->mobility);
    return 1;
}

static int StateBroadcastData_get_aggressionTowardsTarget(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushnumber(L, instance->aggressionTowardsTarget);
    return 1;
}

static int StateBroadcastData_get_noise(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushnumber(L, instance->noise);
    return 1;
}

static int StateBroadcastData_get_followMe(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushnumber(L, instance->followMe);
    return 1;
}

static int StateBroadcastData_get_intendedAggression(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushnumber(L, instance->intendedAggression);
    return 1;
}

static int StateBroadcastData_get_intendedHelp(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushnumber(L, instance->intendedHelp);
    return 1;
}

static int StateBroadcastData_get_isSleeping(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    return pushObject<YesNoMaybe>(L, &instance->isSleeping, YesNoMaybeBinding::getMetatableName());
}

static int StateBroadcastData_get_isSitting(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushboolean(L, instance->isSitting ? 1 : 0);
    return 1;
}

static int StateBroadcastData_get_lastSlept(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    return pushObject<TimeOfDay>(L, &instance->lastSlept, TimeOfDayBinding::getMetatableName());
}

static int StateBroadcastData_get_pos(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    pushVector3(L, instance->pos);
    return 1;
}

static int StateBroadcastData_get_relativeAttackerStrength(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushnumber(L, instance->relativeAttackerStrength);
    return 1;
}

static int StateBroadcastData_get_myPersonality(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushinteger(L, (lua_Integer)instance->myPersonality);
    return 1;
}

static int StateBroadcastData_get_NPCType(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushinteger(L, (lua_Integer)instance->NPCType);
    return 1;
}

static int StateBroadcastData_get_isSlaveOf(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    return pushObject<Faction>(L, instance->isSlaveOf, FactionBinding::getMetatableName());
}

static int StateBroadcastData_get_isEscapedPrisoner(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushboolean(L, instance->isEscapedPrisoner ? 1 : 0);
    return 1;
}

static int StateBroadcastData_get_isKidnapped(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushboolean(L, instance->isKidnapped ? 1 : 0);
    return 1;
}

static int StateBroadcastData_get_isTemporaryNeutral(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushboolean(L, instance->isTemporaryNeutral ? 1 : 0);
    return 1;
}

static int StateBroadcastData_get_slaveGUI_min(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushinteger(L, instance->slaveGUI_min);
    return 1;
}

static int StateBroadcastData_get_slaveGUI_gear(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushnumber(L, instance->slaveGUI_gear);
    return 1;
}

static int StateBroadcastData_get_looksLike_escapedSlave(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushnumber(L, instance->looksLike_escapedSlave);
    return 1;
}

static int StateBroadcastData_get_looksLike_bounty(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushnumber(L, instance->looksLike_bounty);
    return 1;
}

static int StateBroadcastData_get_looksLike_intruder(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushnumber(L, instance->looksLike_intruder);
    return 1;
}

static int StateBroadcastData_get_disguiseQuality(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushnumber(L, instance->disguiseQuality);
    return 1;
}

static int StateBroadcastData_get_looksLike_clothingArchetype(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushinteger(L, (lua_Integer)instance->looksLike_clothingArchetype);
    return 1;
}

static int StateBroadcastData_get_disguiseFaction(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    return pushObject<Faction>(L, instance->disguiseFaction, FactionBinding::getMetatableName());
}

static int StateBroadcastData_get_disguiseBlown(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushnumber(L, instance->disguiseBlown);
    return 1;
}

static int StateBroadcastData_get_isAggressor(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    lua_pushboolean(L, instance->isAggressor ? 1 : 0);
    return 1;
}

// --- Setters for StateBroadcastData ---
static int StateBroadcastData_set__slaveState(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->_slaveState = (SlaveStateEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int StateBroadcastData_set__slaveStateChangedTime(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->_slaveStateChangedTime = *checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    return 0;
}

static int StateBroadcastData_set_me(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->me = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int StateBroadcastData_set_combatTargetsFaction(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->combatTargetsFaction = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

static int StateBroadcastData_set_taskTarget(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->taskTarget = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int StateBroadcastData_set_isAtHome(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->isAtHome = lua_toboolean(L, 2) != 0;
    return 0;
}

static int StateBroadcastData_set_unconcious(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->unconcious = lua_toboolean(L, 2) != 0;
    return 0;
}

static int StateBroadcastData_set_homeBuilding(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->homeBuilding = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int StateBroadcastData_set_intendsToAttack(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->intendsToAttack = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int StateBroadcastData_set_currentTownLocation(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->currentTownLocation = lua_isnoneornil(L, 2) ? nullptr : checkObject<TownBase>(L, 2, TownBaseBinding::getMetatableName());
    return 0;
}

static int StateBroadcastData_set_apparentStrength(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->apparentStrength = (float)luaL_checknumber(L, 2);
    return 0;
}

static int StateBroadcastData_set_actualStrength(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->actualStrength = (float)luaL_checknumber(L, 2);
    return 0;
}

static int StateBroadcastData_set_distress(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->distress = (float)luaL_checknumber(L, 2);
    return 0;
}

static int StateBroadcastData_set_mobility(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->mobility = (float)luaL_checknumber(L, 2);
    return 0;
}

static int StateBroadcastData_set_aggressionTowardsTarget(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->aggressionTowardsTarget = (float)luaL_checknumber(L, 2);
    return 0;
}

static int StateBroadcastData_set_noise(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->noise = (float)luaL_checknumber(L, 2);
    return 0;
}

static int StateBroadcastData_set_followMe(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->followMe = (float)luaL_checknumber(L, 2);
    return 0;
}

static int StateBroadcastData_set_intendedAggression(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->intendedAggression = (float)luaL_checknumber(L, 2);
    return 0;
}

static int StateBroadcastData_set_intendedHelp(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->intendedHelp = (float)luaL_checknumber(L, 2);
    return 0;
}

static int StateBroadcastData_set_isSleeping(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->isSleeping = *checkObject<YesNoMaybe>(L, 2, YesNoMaybeBinding::getMetatableName());
    return 0;
}

static int StateBroadcastData_set_isSitting(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->isSitting = lua_toboolean(L, 2) != 0;
    return 0;
}

static int StateBroadcastData_set_lastSlept(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->lastSlept = *checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    return 0;
}

static int StateBroadcastData_set_pos(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    if (!readVector3(L, 2, instance->pos)) return luaL_argerror(L, 2, "Vector3 table expected");
    return 0;
}

static int StateBroadcastData_set_relativeAttackerStrength(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->relativeAttackerStrength = (float)luaL_checknumber(L, 2);
    return 0;
}

static int StateBroadcastData_set_myPersonality(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->myPersonality = (PersonalityTags)luaL_checkinteger(L, 2);
    return 0;
}

static int StateBroadcastData_set_NPCType(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->NPCType = (CharacterTypeEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int StateBroadcastData_set_isSlaveOf(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->isSlaveOf = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

static int StateBroadcastData_set_isEscapedPrisoner(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->isEscapedPrisoner = lua_toboolean(L, 2) != 0;
    return 0;
}

static int StateBroadcastData_set_isKidnapped(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->isKidnapped = lua_toboolean(L, 2) != 0;
    return 0;
}

static int StateBroadcastData_set_isTemporaryNeutral(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->isTemporaryNeutral = lua_toboolean(L, 2) != 0;
    return 0;
}

static int StateBroadcastData_set_slaveGUI_min(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->slaveGUI_min = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int StateBroadcastData_set_slaveGUI_gear(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->slaveGUI_gear = (float)luaL_checknumber(L, 2);
    return 0;
}

static int StateBroadcastData_set_looksLike_escapedSlave(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->looksLike_escapedSlave = (float)luaL_checknumber(L, 2);
    return 0;
}

static int StateBroadcastData_set_looksLike_bounty(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->looksLike_bounty = (float)luaL_checknumber(L, 2);
    return 0;
}

static int StateBroadcastData_set_looksLike_intruder(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->looksLike_intruder = (float)luaL_checknumber(L, 2);
    return 0;
}

static int StateBroadcastData_set_disguiseQuality(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->disguiseQuality = (float)luaL_checknumber(L, 2);
    return 0;
}

static int StateBroadcastData_set_looksLike_clothingArchetype(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->looksLike_clothingArchetype = (CharacterTypeEnum)luaL_checkinteger(L, 2);
    return 0;
}

static int StateBroadcastData_set_disguiseFaction(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->disguiseFaction = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

static int StateBroadcastData_set_disguiseBlown(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->disguiseBlown = (float)luaL_checknumber(L, 2);
    return 0;
}

static int StateBroadcastData_set_isAggressor(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");
    instance->isAggressor = lua_toboolean(L, 2) != 0;
    return 0;
}

int StateBroadcastDataBinding::save(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->save(state);
    return 0;
}

int StateBroadcastDataBinding::load(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->load(state);
    return 0;
}

int StateBroadcastDataBinding::periodicUpdate(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");

    instance->periodicUpdate();
    return 0;
}

int StateBroadcastDataBinding::setSlaveState(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");

    SlaveStateEnum s = (SlaveStateEnum)luaL_checkinteger(L, 2);
    instance->setSlaveState(s);
    return 0;
}

int StateBroadcastDataBinding::getSlaveState(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");

    SlaveStateEnum result = instance->getSlaveState();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int StateBroadcastDataBinding::getSlaveStateHoursRemaining(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");

    int result = instance->getSlaveStateHoursRemaining();
    lua_pushinteger(L, result);
    return 1;
}

int StateBroadcastDataBinding::notifyDisguiseBlown(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");

    instance->notifyDisguiseBlown();
    return 0;
}

int StateBroadcastDataBinding::isDisguiseBlown(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");

    bool result = instance->isDisguiseBlown();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StateBroadcastDataBinding::isDisguised(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");

    Faction* result = instance->isDisguised();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int StateBroadcastDataBinding::isHiddenIdentitySlave(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");

    bool result = instance->isHiddenIdentitySlave();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StateBroadcastDataBinding::getApparentFaction(lua_State* L)
{
    StateBroadcastData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateBroadcastData is nil");

    Faction* result = instance->getApparentFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

/*
Skipped methods needing manual binding:
  line 39: StateBroadcastData(Character* _me) - constructor; instances are owned by their Character
  line 40: _CONSTRUCTOR(Character* _me) - constructor; instances are owned by their Character
*/

int StateBroadcastDataBinding::gc(lua_State* L)
{
    // Borrowed from the owning Character
    return 0;
}

int StateBroadcastDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.StateBroadcastData object");
    return 1;
}

void StateBroadcastDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       StateBroadcastDataBinding::gc },
        { "__tostring", StateBroadcastDataBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "save", StateBroadcastDataBinding::save },
        { "load", StateBroadcastDataBinding::load },
        { "periodicUpdate", StateBroadcastDataBinding::periodicUpdate },
        { "setSlaveState", StateBroadcastDataBinding::setSlaveState },
        { "getSlaveState", StateBroadcastDataBinding::getSlaveState },
        { "getSlaveStateHoursRemaining", StateBroadcastDataBinding::getSlaveStateHoursRemaining },
        { "notifyDisguiseBlown", StateBroadcastDataBinding::notifyDisguiseBlown },
        { "isDisguiseBlown", StateBroadcastDataBinding::isDisguiseBlown },
        { "isDisguised", StateBroadcastDataBinding::isDisguised },
        { "isHiddenIdentitySlave", StateBroadcastDataBinding::isHiddenIdentitySlave },
        { "getApparentFaction", StateBroadcastDataBinding::getApparentFaction },
        { 0, 0 }
    };

    registerClass(
        L,
        StateBroadcastDataBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, StateBroadcastDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "_slaveState", StateBroadcastData_get__slaveState);
    registerGetter(L, "_slaveStateChangedTime", StateBroadcastData_get__slaveStateChangedTime);
    registerGetter(L, "me", StateBroadcastData_get_me);
    registerGetter(L, "combatTargetsFaction", StateBroadcastData_get_combatTargetsFaction);
    registerGetter(L, "taskTarget", StateBroadcastData_get_taskTarget);
    registerGetter(L, "isAtHome", StateBroadcastData_get_isAtHome);
    registerGetter(L, "unconcious", StateBroadcastData_get_unconcious);
    registerGetter(L, "homeBuilding", StateBroadcastData_get_homeBuilding);
    registerGetter(L, "intendsToAttack", StateBroadcastData_get_intendsToAttack);
    registerGetter(L, "currentTownLocation", StateBroadcastData_get_currentTownLocation);
    registerGetter(L, "apparentStrength", StateBroadcastData_get_apparentStrength);
    registerGetter(L, "actualStrength", StateBroadcastData_get_actualStrength);
    registerGetter(L, "distress", StateBroadcastData_get_distress);
    registerGetter(L, "mobility", StateBroadcastData_get_mobility);
    registerGetter(L, "aggressionTowardsTarget", StateBroadcastData_get_aggressionTowardsTarget);
    registerGetter(L, "noise", StateBroadcastData_get_noise);
    registerGetter(L, "followMe", StateBroadcastData_get_followMe);
    registerGetter(L, "intendedAggression", StateBroadcastData_get_intendedAggression);
    registerGetter(L, "intendedHelp", StateBroadcastData_get_intendedHelp);
    registerGetter(L, "isSleeping", StateBroadcastData_get_isSleeping);
    registerGetter(L, "isSitting", StateBroadcastData_get_isSitting);
    registerGetter(L, "lastSlept", StateBroadcastData_get_lastSlept);
    registerGetter(L, "pos", StateBroadcastData_get_pos);
    registerGetter(L, "relativeAttackerStrength", StateBroadcastData_get_relativeAttackerStrength);
    registerGetter(L, "myPersonality", StateBroadcastData_get_myPersonality);
    registerGetter(L, "NPCType", StateBroadcastData_get_NPCType);
    registerGetter(L, "isSlaveOf", StateBroadcastData_get_isSlaveOf);
    registerGetter(L, "isEscapedPrisoner", StateBroadcastData_get_isEscapedPrisoner);
    registerGetter(L, "isKidnapped", StateBroadcastData_get_isKidnapped);
    registerGetter(L, "isTemporaryNeutral", StateBroadcastData_get_isTemporaryNeutral);
    registerGetter(L, "slaveGUI_min", StateBroadcastData_get_slaveGUI_min);
    registerGetter(L, "slaveGUI_gear", StateBroadcastData_get_slaveGUI_gear);
    registerGetter(L, "looksLike_escapedSlave", StateBroadcastData_get_looksLike_escapedSlave);
    registerGetter(L, "looksLike_bounty", StateBroadcastData_get_looksLike_bounty);
    registerGetter(L, "looksLike_intruder", StateBroadcastData_get_looksLike_intruder);
    registerGetter(L, "disguiseQuality", StateBroadcastData_get_disguiseQuality);
    registerGetter(L, "looksLike_clothingArchetype", StateBroadcastData_get_looksLike_clothingArchetype);
    registerGetter(L, "disguiseFaction", StateBroadcastData_get_disguiseFaction);
    registerGetter(L, "disguiseBlown", StateBroadcastData_get_disguiseBlown);
    registerGetter(L, "isAggressor", StateBroadcastData_get_isAggressor);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "_slaveState", StateBroadcastData_set__slaveState);
    registerSetter(L, "_slaveStateChangedTime", StateBroadcastData_set__slaveStateChangedTime);
    registerSetter(L, "me", StateBroadcastData_set_me);
    registerSetter(L, "combatTargetsFaction", StateBroadcastData_set_combatTargetsFaction);
    registerSetter(L, "taskTarget", StateBroadcastData_set_taskTarget);
    registerSetter(L, "isAtHome", StateBroadcastData_set_isAtHome);
    registerSetter(L, "unconcious", StateBroadcastData_set_unconcious);
    registerSetter(L, "homeBuilding", StateBroadcastData_set_homeBuilding);
    registerSetter(L, "intendsToAttack", StateBroadcastData_set_intendsToAttack);
    registerSetter(L, "currentTownLocation", StateBroadcastData_set_currentTownLocation);
    registerSetter(L, "apparentStrength", StateBroadcastData_set_apparentStrength);
    registerSetter(L, "actualStrength", StateBroadcastData_set_actualStrength);
    registerSetter(L, "distress", StateBroadcastData_set_distress);
    registerSetter(L, "mobility", StateBroadcastData_set_mobility);
    registerSetter(L, "aggressionTowardsTarget", StateBroadcastData_set_aggressionTowardsTarget);
    registerSetter(L, "noise", StateBroadcastData_set_noise);
    registerSetter(L, "followMe", StateBroadcastData_set_followMe);
    registerSetter(L, "intendedAggression", StateBroadcastData_set_intendedAggression);
    registerSetter(L, "intendedHelp", StateBroadcastData_set_intendedHelp);
    registerSetter(L, "isSleeping", StateBroadcastData_set_isSleeping);
    registerSetter(L, "isSitting", StateBroadcastData_set_isSitting);
    registerSetter(L, "lastSlept", StateBroadcastData_set_lastSlept);
    registerSetter(L, "pos", StateBroadcastData_set_pos);
    registerSetter(L, "relativeAttackerStrength", StateBroadcastData_set_relativeAttackerStrength);
    registerSetter(L, "myPersonality", StateBroadcastData_set_myPersonality);
    registerSetter(L, "NPCType", StateBroadcastData_set_NPCType);
    registerSetter(L, "isSlaveOf", StateBroadcastData_set_isSlaveOf);
    registerSetter(L, "isEscapedPrisoner", StateBroadcastData_set_isEscapedPrisoner);
    registerSetter(L, "isKidnapped", StateBroadcastData_set_isKidnapped);
    registerSetter(L, "isTemporaryNeutral", StateBroadcastData_set_isTemporaryNeutral);
    registerSetter(L, "slaveGUI_min", StateBroadcastData_set_slaveGUI_min);
    registerSetter(L, "slaveGUI_gear", StateBroadcastData_set_slaveGUI_gear);
    registerSetter(L, "looksLike_escapedSlave", StateBroadcastData_set_looksLike_escapedSlave);
    registerSetter(L, "looksLike_bounty", StateBroadcastData_set_looksLike_bounty);
    registerSetter(L, "looksLike_intruder", StateBroadcastData_set_looksLike_intruder);
    registerSetter(L, "disguiseQuality", StateBroadcastData_set_disguiseQuality);
    registerSetter(L, "looksLike_clothingArchetype", StateBroadcastData_set_looksLike_clothingArchetype);
    registerSetter(L, "disguiseFaction", StateBroadcastData_set_disguiseFaction);
    registerSetter(L, "disguiseBlown", StateBroadcastData_set_disguiseBlown);
    registerSetter(L, "isAggressor", StateBroadcastData_set_isAggressor);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
