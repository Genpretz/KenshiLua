#include "pch.h"
#include "kenshi\CharStats.h"
#include "CharStatsBinding.h"
#include "kenshi/MedicalSystem.h"
#include "MedicalSystemBinding.h"
#include "Lua/BindingHelpers.h"
#include "DamagesBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/MedicalSystemBinding.h"
#include "Bindings/HandBinding.h"

namespace KenshiLua
{

static CharStats* getB(lua_State* L, int idx)
{
    return checkObject<CharStats>(L, idx, CharStatsBinding::getMetatableName());
}

// --- Getters for CharStats ---
static int CharStats_get_medical(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    return pushObject<MedicalSystem>(L, b->medical, MedicalSystemBinding::getMetatableName());
}

static int CharStats_get_me(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    return pushObject<Character>(L, b->me, CharacterBinding::getMetatableName());
}

static int CharStats_get_athleticsMultiplier(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->athleticsMultiplier);
    return 1;
}

static int CharStats_get_combatSpeedMultiplier(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->combatSpeedMultiplier);
    return 1;
}

static int CharStats_get__skillBonusAttack(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushinteger(L, b->_skillBonusAttack);
    return 1;
}

static int CharStats_get__skillBonusDefence(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushinteger(L, b->_skillBonusDefence);
    return 1;
}

static int CharStats_get_skillBonusIndoors(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushinteger(L, b->skillBonusIndoors);
    return 1;
}

static int CharStats_get_skillBonusUnarmed(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushinteger(L, b->skillBonusUnarmed);
    return 1;
}

static int CharStats_get_skillBonusPerception(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushinteger(L, b->skillBonusPerception);
    return 1;
}

static int CharStats_get_ageMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->ageMult);
    return 1;
}

static int CharStats_get_skillMultDodge(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->skillMultDodge);
    return 1;
}

static int CharStats_get_skillMultStealth(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->skillMultStealth);
    return 1;
}

static int CharStats_get_skillMultAssassin(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->skillMultAssassin);
    return 1;
}

static int CharStats_get_skillMultDexterity(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->skillMultDexterity);
    return 1;
}

static int CharStats_get_skillMultDamage(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->skillMultDamage);
    return 1;
}

static int CharStats_get_fistInjuryEquipmentMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->fistInjuryEquipmentMult);
    return 1;
}

static int CharStats_get_skillMultRanged(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->skillMultRanged);
    return 1;
}

static int CharStats_get__weatherProtections(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    // TODO: Unsupported type for _weatherProtections (std::map<WeatherAffecting, float, std::less<WeatherAffecting>, Ogre::STLAllocator<std::pair<WeatherAffecting const, float>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property '_weatherProtections' (type: std::map<WeatherAffecting, float, std::less<WeatherAffecting>, Ogre::STLAllocator<std::pair<WeatherAffecting const, float>, Ogre::GeneralAllocPolicy > >)");
}

static int CharStats_get__strength(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->_strength);
    return 1;
}

static int CharStats_get_fitness(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->fitness);
    return 1;
}

static int CharStats_get__dexterity(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->_dexterity);
    return 1;
}

static int CharStats_get_perception(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->perception);
    return 1;
}

static int CharStats_get__toughness(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->_toughness);
    return 1;
}

static int CharStats_get__athletics(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->_athletics);
    return 1;
}

static int CharStats_get_medic(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->medic);
    return 1;
}

static int CharStats_get_massCombat(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->massCombat);
    return 1;
}

static int CharStats_get_arrowDefence(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->arrowDefence);
    return 1;
}

static int CharStats_get_stealth(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->stealth);
    return 1;
}

static int CharStats_get_swimming(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->swimming);
    return 1;
}

static int CharStats_get_thieving(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->thieving);
    return 1;
}

static int CharStats_get_lockpicking(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->lockpicking);
    return 1;
}

static int CharStats_get_bluff(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->bluff);
    return 1;
}

static int CharStats_get_assassin(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->assassin);
    return 1;
}

static int CharStats_get_survival(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->survival);
    return 1;
}

static int CharStats_get_tracking(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->tracking);
    return 1;
}

static int CharStats_get_climbing(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->climbing);
    return 1;
}

static int CharStats_get_doctor(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->doctor);
    return 1;
}

static int CharStats_get_engineer(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->engineer);
    return 1;
}

static int CharStats_get_weaponSmith(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->weaponSmith);
    return 1;
}

static int CharStats_get_armourSmith(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->armourSmith);
    return 1;
}

static int CharStats_get_bowSmith(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->bowSmith);
    return 1;
}

static int CharStats_get_robotics(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->robotics);
    return 1;
}

static int CharStats_get_science(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->science);
    return 1;
}

static int CharStats_get_labouring(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->labouring);
    return 1;
}

static int CharStats_get_farming(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->farming);
    return 1;
}

static int CharStats_get_cooking(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->cooking);
    return 1;
}

static int CharStats_get_dodging(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->dodging);
    return 1;
}

static int CharStats_get_friendlyFire(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->friendlyFire);
    return 1;
}

static int CharStats_get_katanas(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->katanas);
    return 1;
}

static int CharStats_get_sabres(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->sabres);
    return 1;
}

static int CharStats_get_hackers(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->hackers);
    return 1;
}

static int CharStats_get_blunt(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->blunt);
    return 1;
}

static int CharStats_get_heavyWeapons(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->heavyWeapons);
    return 1;
}

static int CharStats_get_unarmed(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->unarmed);
    return 1;
}

static int CharStats_get_bows(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->bows);
    return 1;
}

static int CharStats_get_turrets(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->turrets);
    return 1;
}

static int CharStats_get_polearms(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->polearms);
    return 1;
}

static int CharStats_get_currentItemMaximumJuryRig(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->currentItemMaximumJuryRig);
    return 1;
}

static int CharStats_get___meleeAttack(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->__meleeAttack);
    return 1;
}

static int CharStats_get__meleeDefence(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->_meleeDefence);
    return 1;
}

static int CharStats_get__defensiveMode(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushboolean(L, b->_defensiveMode ? 1 : 0);
    return 1;
}

static int CharStats_get_rangedMode(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushboolean(L, b->rangedMode ? 1 : 0);
    return 1;
}

static int CharStats_get_tauntMode(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushboolean(L, b->tauntMode ? 1 : 0);
    return 1;
}

static int CharStats_get__holdPositionMode(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushboolean(L, b->_holdPositionMode ? 1 : 0);
    return 1;
}

static int CharStats_get_passiveCombatMode(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushboolean(L, b->passiveCombatMode ? 1 : 0);
    return 1;
}

static int CharStats_get_holdLocation(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    pushVector3(L, b->holdLocation);
    return 1;
}

static int CharStats_get_warriorSpirit(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->warriorSpirit);
    return 1;
}

static int CharStats_get_derivedSpirit(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->derivedSpirit);
    return 1;
}

static int CharStats_get_aggression(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->aggression);
    return 1;
}

static int CharStats_get_goodness(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->goodness);
    return 1;
}

static int CharStats_get_evilness(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->evilness);
    return 1;
}

static int CharStats_get_longestReachingAttack(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->longestReachingAttack);
    return 1;
}

static int CharStats_get_STUBBOURNESS(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->STUBBOURNESS);
    return 1;
}

static int CharStats_get_PROFESSIONALNESS(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->PROFESSIONALNESS);
    return 1;
}

static int CharStats_get_HOLDING_POSITION(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->HOLDING_POSITION);
    return 1;
}

static int CharStats_get_IMMEDIACY(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->IMMEDIACY);
    return 1;
}

static int CharStats_get_IMMEDIACY_MAX_RANGE(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->IMMEDIACY_MAX_RANGE);
    return 1;
}

static int CharStats_get_MANLINESS(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->MANLINESS);
    return 1;
}

static int CharStats_get_MURDEROUS(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->MURDEROUS);
    return 1;
}

static int CharStats_get__stealthXPMultForGUI(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->_stealthXPMultForGUI);
    return 1;
}

static int CharStats_get_stealthXPTooManyCooksPenalty(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->stealthXPTooManyCooksPenalty);
    return 1;
}

static int CharStats_get_currentOperatingMachineHungerRate(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->currentOperatingMachineHungerRate);
    return 1;
}

static int CharStats_get_moveSpeed(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->moveSpeed);
    return 1;
}

static int CharStats_get_weaponWeightSpeedMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->weaponWeightSpeedMult);
    return 1;
}

static int CharStats_get_weaponWeightXPMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->weaponWeightXPMult);
    return 1;
}

static int CharStats_get_attackSpeed(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->attackSpeed);
    return 1;
}

static int CharStats_get_blockSpeed(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->blockSpeed);
    return 1;
}

static int CharStats_get_encumbranceMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->encumbranceMult);
    return 1;
}

static int CharStats_get_xp(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->xp);
    return 1;
}

static int CharStats_get_freeAttributePoints(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushinteger(L, b->freeAttributePoints);
    return 1;
}

static int CharStats_get_cutDamageMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->cutDamageMult);
    return 1;
}

static int CharStats_get_bluntDamageMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->bluntDamageMult);
    return 1;
}

static int CharStats_get_bleedDamageMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->bleedDamageMult);
    return 1;
}

static int CharStats_get_pierceDamageMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->pierceDamageMult);
    return 1;
}

static int CharStats_get_cutDamageMin(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->cutDamageMin);
    return 1;
}

static int CharStats_get_bluntDamageMin(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->bluntDamageMin);
    return 1;
}

static int CharStats_get_bonusRobots(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->bonusRobots);
    return 1;
}

static int CharStats_get_bonusHumans(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->bonusHumans);
    return 1;
}

static int CharStats_get_bonusAnimals(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->bonusAnimals);
    return 1;
}

static int CharStats_get_bonusArmourPenetration(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->bonusArmourPenetration);
    return 1;
}

static int CharStats_get_bonusRaces(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    // TODO: Unsupported type for bonusRaces (std::map<GameData*, float, std::less<GameData*>, Ogre::STLAllocator<std::pair<GameData*const, float>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'bonusRaces' (type: std::map<GameData*, float, std::less<GameData*>, Ogre::STLAllocator<std::pair<GameData*const, float>, Ogre::GeneralAllocPolicy > >)");
}

static int CharStats_get_currentWeaponType(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushinteger(L, (lua_Integer)b->currentWeaponType);
    return 1;
}

static int CharStats_get_pCurrentWeaponSkill(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->pCurrentWeaponSkill ? *b->pCurrentWeaponSkill : 0.0f);
    return 1;
}

static int CharStats_get_currentWeaponLength(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->currentWeaponLength);
    return 1;
}

static int CharStats_get_weapon(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    return handBinding::push(L, b->weapon);
}

static int CharStats_get_weaponWeight(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->weaponWeight);
    return 1;
}

// --- Setters for CharStats ---
static int CharStats_set_medical(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    return luaL_error(L, "Read-only or unsupported setter type for medical");
}

static int CharStats_set_me(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    return luaL_error(L, "Read-only or unsupported setter type for me");
}

static int CharStats_set_athleticsMultiplier(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->athleticsMultiplier = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_combatSpeedMultiplier(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->combatSpeedMultiplier = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set__skillBonusAttack(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->_skillBonusAttack = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CharStats_set__skillBonusDefence(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->_skillBonusDefence = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CharStats_set_skillBonusIndoors(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->skillBonusIndoors = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CharStats_set_skillBonusUnarmed(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->skillBonusUnarmed = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CharStats_set_skillBonusPerception(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->skillBonusPerception = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CharStats_set_ageMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->ageMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_skillMultDodge(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->skillMultDodge = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_skillMultStealth(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->skillMultStealth = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_skillMultAssassin(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->skillMultAssassin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_skillMultDexterity(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->skillMultDexterity = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_skillMultDamage(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->skillMultDamage = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_fistInjuryEquipmentMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->fistInjuryEquipmentMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_skillMultRanged(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->skillMultRanged = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set__weatherProtections(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    return luaL_error(L, "Read-only or unsupported setter type for _weatherProtections");
}

static int CharStats_set__strength(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->_strength = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_fitness(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->fitness = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set__dexterity(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->_dexterity = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_perception(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->perception = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set__toughness(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->_toughness = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set__athletics(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->_athletics = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_medic(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->medic = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_massCombat(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->massCombat = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_arrowDefence(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->arrowDefence = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_stealth(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->stealth = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_swimming(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->swimming = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_thieving(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->thieving = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_lockpicking(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->lockpicking = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_bluff(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->bluff = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_assassin(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->assassin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_survival(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->survival = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_tracking(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->tracking = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_climbing(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->climbing = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_doctor(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->doctor = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_engineer(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->engineer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_weaponSmith(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->weaponSmith = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_armourSmith(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->armourSmith = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_bowSmith(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->bowSmith = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_robotics(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->robotics = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_science(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->science = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_labouring(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->labouring = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_farming(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->farming = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_cooking(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->cooking = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_dodging(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->dodging = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_friendlyFire(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->friendlyFire = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_katanas(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->katanas = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_sabres(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->sabres = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_hackers(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->hackers = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_blunt(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->blunt = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_heavyWeapons(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->heavyWeapons = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_unarmed(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->unarmed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_bows(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->bows = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_turrets(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->turrets = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_polearms(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->polearms = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_currentItemMaximumJuryRig(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->currentItemMaximumJuryRig = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set___meleeAttack(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->__meleeAttack = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set__meleeDefence(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->_meleeDefence = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set__defensiveMode(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->_defensiveMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharStats_set_rangedMode(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->rangedMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharStats_set_tauntMode(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->tauntMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharStats_set__holdPositionMode(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->_holdPositionMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharStats_set_passiveCombatMode(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->passiveCombatMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharStats_set_holdLocation(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    readVector3(L, 2, b->holdLocation);
    return 0;
}

static int CharStats_set_warriorSpirit(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->warriorSpirit = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_derivedSpirit(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->derivedSpirit = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_aggression(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->aggression = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_goodness(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->goodness = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_evilness(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->evilness = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_longestReachingAttack(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->longestReachingAttack = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_STUBBOURNESS(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->STUBBOURNESS = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_PROFESSIONALNESS(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->PROFESSIONALNESS = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_HOLDING_POSITION(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->HOLDING_POSITION = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_IMMEDIACY(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->IMMEDIACY = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_IMMEDIACY_MAX_RANGE(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->IMMEDIACY_MAX_RANGE = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_MANLINESS(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->MANLINESS = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_MURDEROUS(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->MURDEROUS = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set__stealthXPMultForGUI(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->_stealthXPMultForGUI = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_stealthXPTooManyCooksPenalty(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->stealthXPTooManyCooksPenalty = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_currentOperatingMachineHungerRate(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->currentOperatingMachineHungerRate = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_moveSpeed(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->moveSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_weaponWeightSpeedMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->weaponWeightSpeedMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_weaponWeightXPMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->weaponWeightXPMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_attackSpeed(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->attackSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_blockSpeed(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->blockSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_encumbranceMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->encumbranceMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_xp(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->xp = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_freeAttributePoints(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->freeAttributePoints = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CharStats_set_cutDamageMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->cutDamageMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_bluntDamageMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->bluntDamageMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_bleedDamageMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->bleedDamageMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_pierceDamageMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->pierceDamageMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_cutDamageMin(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->cutDamageMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_bluntDamageMin(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->bluntDamageMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_bonusRobots(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->bonusRobots = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_bonusHumans(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->bonusHumans = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_bonusAnimals(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->bonusAnimals = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_bonusArmourPenetration(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->bonusArmourPenetration = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_bonusRaces(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    return luaL_error(L, "Read-only or unsupported setter type for bonusRaces");
}

static int CharStats_set_currentWeaponType(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->currentWeaponType = (WeaponCategory)luaL_checkinteger(L, 2);
    return 0;
}

static int CharStats_set_pCurrentWeaponSkill(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    return luaL_error(L, "Read-only or unsupported setter type for pCurrentWeaponSkill");
}

static int CharStats_set_currentWeaponLength(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->currentWeaponLength = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_weapon(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->weapon = *val;
    return 0;
}

static int CharStats_set_weaponWeight(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    b->weaponWeight = (float)luaL_checknumber(L, 2);
    return 0;
}

int CharStatsBinding::getWeatherProtection(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    WeatherAffecting w = (WeatherAffecting)luaL_checkinteger(L, 2);
    float result = b->getWeatherProtection(w);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::_CONSTRUCTOR(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    CharStats* result = b->_CONSTRUCTOR();
    return pushObject<CharStats>(L, result, CharStatsBinding::getMetatableName());
}

int CharStatsBinding::unarmedEncumbrancePenalty(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    int result = b->unarmedEncumbrancePenalty();
    lua_pushinteger(L, result);
    return 1;
}

int CharStatsBinding::skillBonusUnarmed_forGUI(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    bool factorEnvironment = lua_toboolean(L, 2) != 0;
    int result = b->skillBonusUnarmed_forGUI(factorEnvironment);
    lua_pushinteger(L, result);
    return 1;
}

int CharStatsBinding::skillBonusAttack_melee(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    bool factorEnvironment = lua_toboolean(L, 2) != 0;
    int result = b->skillBonusAttack_melee(factorEnvironment);
    lua_pushinteger(L, result);
    return 1;
}

int CharStatsBinding::skillBonusAttack_unarmed(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    bool factorEnvironment = lua_toboolean(L, 2) != 0;
    int result = b->skillBonusAttack_unarmed(factorEnvironment);
    lua_pushinteger(L, result);
    return 1;
}

int CharStatsBinding::skillBonusDefence(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    bool factorEnvironment = lua_toboolean(L, 2) != 0;
    int result = b->skillBonusDefence(factorEnvironment);
    lua_pushinteger(L, result);
    return 1;
}

int CharStatsBinding::_randomiseStats(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float amount = (float)luaL_checknumber(L, 2);
    b->_randomiseStats(amount);
    return 0;
}

int CharStatsBinding::getGUIStatsDisplayMode(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    CharStats::GUIStatsDisplayMode result = b->getGUIStatsDisplayMode();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharStatsBinding::periodicUpdate(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    b->periodicUpdate();
    return 0;
}

int CharStatsBinding::_NV_periodicUpdate(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    b->_NV_periodicUpdate();
    return 0;
}

int CharStatsBinding::calculateStumbleThresholdDamageAmount(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->calculateStumbleThresholdDamageAmount();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::setEquipmentStatBonuses(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float athlet = (float)luaL_checknumber(L, 2);
    float combatSpd = (float)luaL_checknumber(L, 3);
    int attack = (int)luaL_checkinteger(L, 4);
    int def = (int)luaL_checkinteger(L, 5);
    float _stealth = (float)luaL_checknumber(L, 6);
    int _unarmed = (int)luaL_checkinteger(L, 7);
    float _dodge = (float)luaL_checknumber(L, 8);
    float fistdamage = (float)luaL_checknumber(L, 9);
    int perception = (int)luaL_checkinteger(L, 10);
    float ranged = (float)luaL_checknumber(L, 11);
    float dexmult = (float)luaL_checknumber(L, 12);
    float assmult = (float)luaL_checknumber(L, 13);
    float damagemult = (float)luaL_checknumber(L, 14);
    b->setEquipmentStatBonuses(athlet, combatSpd, attack, def, _stealth, _unarmed, _dodge, fistdamage, perception, ranged, dexmult, assmult, damagemult);
    return 0;
}

int CharStatsBinding::getOverallSkillLevel_0_100(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->getOverallSkillLevel_0_100();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getStat(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    StatsEnumerated what = (StatsEnumerated)luaL_checkinteger(L, 2);
    bool unmodified = lua_toboolean(L, 3) != 0;
    float result = b->getStat(what, unmodified);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getStatMultiplier(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    StatsEnumerated st = (StatsEnumerated)luaL_checkinteger(L, 2);
    float result = b->getStatMultiplier(st);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getStatMultiplierForGUI(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    StatsEnumerated st = (StatsEnumerated)luaL_checkinteger(L, 2);
    std::string result = b->getStatMultiplierForGUI(st);
    lua_pushstring(L, result.c_str());
    return 1;
}

int CharStatsBinding::getStatPenaltiesTotalForGUI(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    std::string statName = luaL_checkstring(L, 2);
    StatsEnumerated stat = (StatsEnumerated)luaL_checkinteger(L, 3);
    int result = b->getStatPenaltiesTotalForGUI(statName, stat);
    lua_pushinteger(L, result);
    return 1;
}

int CharStatsBinding::xpStat_timeBased(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    StatsEnumerated st = (StatsEnumerated)luaL_checkinteger(L, 2);
    b->xpStat_timeBased(st);
    return 0;
}

int CharStatsBinding::xpStat_eventBased(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    StatsEnumerated st = (StatsEnumerated)luaL_checkinteger(L, 2);
    float amount = (float)luaL_checknumber(L, 3);
    b->xpStat_eventBased(st, amount);
    return 0;
}

int CharStatsBinding::xpDodgeEvent(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float enemySkill = (float)luaL_checknumber(L, 2);
    bool successful = lua_toboolean(L, 3) != 0;
    b->xpDodgeEvent(enemySkill, successful);
    return 0;
}

int CharStatsBinding::strengthActual(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->strengthActual();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::strengthBase(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->strengthBase();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::_NV_strengthBase(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->_NV_strengthBase();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::dexterityBase(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->dexterityBase();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::dexterityActual(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->dexterityActual();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::toughness(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->toughness();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getStrength(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->strengthActual());
    return 1;
}

int CharStatsBinding::getStrengthBase(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->strengthBase());
    return 1;
}

int CharStatsBinding::getDexterity(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->dexterityActual());
    return 1;
}

int CharStatsBinding::getDexterityBase(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->dexterityBase());
    return 1;
}

int CharStatsBinding::getToughness(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->toughness());
    return 1;
}

int CharStatsBinding::getPerception(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->perception);
    return 1;
}

int CharStatsBinding::getAthletics(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->_athletics);
    return 1;
}

int CharStatsBinding::getThieving(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, b->thieving);
    return 1;
}

int CharStatsBinding::getToughnessMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->getToughnessMult();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getRangedFriendlyFireAvoidanceChance(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->getRangedFriendlyFireAvoidanceChance();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getRangedAccuracyMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    StatsEnumerated stat = (StatsEnumerated)luaL_checkinteger(L, 2);
    float result = b->getRangedAccuracyMult(stat);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getReloadSkill(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    StatsEnumerated stat = (StatsEnumerated)luaL_checkinteger(L, 2);
    float result = b->getReloadSkill(stat);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::animalRecruitReduceStats(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    b->animalRecruitReduceStats();
    return 0;
}

int CharStatsBinding::getMeleeDefence(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    bool includeDefensiveMode = lua_toboolean(L, 2) != 0;
    float result = b->getMeleeDefence(includeDefensiveMode);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getDodge(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    bool bonuses = lua_toboolean(L, 2) != 0;
    float result = b->getDodge(bonuses);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getDodgePenalty_encumbrance(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->getDodgePenalty_encumbrance();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getDodgePenalty_injuries(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->getDodgePenalty_injuries();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getDodgePenalty_gear(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->getDodgePenalty_gear();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getMeleeDefence_melee(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    bool includeDefensiveMode = lua_toboolean(L, 2) != 0;
    float result = b->getMeleeDefence_melee(includeDefensiveMode);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getMeleeAttack(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->getMeleeAttack();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getMeleeAttack_unarmed(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    bool bonuses = lua_toboolean(L, 2) != 0;
    float result = b->getMeleeAttack_unarmed(bonuses);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getMeleeAttack_melee(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->getMeleeAttack_melee();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::_getMeleeAttackBase(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->_getMeleeAttackBase();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::isDefensiveMode(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    bool result = b->isDefensiveMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharStatsBinding::holdPositionMode(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    bool result = b->holdPositionMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharStatsBinding::setHoldLocation(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    Ogre::Vector3 v;
    readVector3(L, 2, v);
    b->setHoldLocation(v);
    return 0;
}

int CharStatsBinding::clearHoldLocation(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    b->clearHoldLocation();
    return 0;
}

int CharStatsBinding::calculateStumbleBlockTimer(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float stumbleForce = (float)luaL_checknumber(L, 2);
    float result = b->calculateStumbleBlockTimer(stumbleForce);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::calculateTechniqueInegrityCheckTimer(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->calculateTechniqueInegrityCheckTimer();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::calculateToughnessDamageResistanceMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->calculateToughnessDamageResistanceMult();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::calculateToughnessWoundDegenerationRate(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->calculateToughnessWoundDegenerationRate();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getAttackChance(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->getAttackChance();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getAttackCuttingDamage(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->getAttackCuttingDamage();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getAttackBluntPower(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->getAttackBluntPower();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getAttackBleedDamageMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->getAttackBleedDamageMult();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getAttackPierceDamage(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->getAttackPierceDamage();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getEquippedWeaponSkill(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->getEquippedWeaponSkill();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::_NV_getEquippedWeaponSkill(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->_NV_getEquippedWeaponSkill();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getSkillDifferenceRatio(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float mine = (float)luaL_checknumber(L, 2);
    float his = (float)luaL_checknumber(L, 3);
    float result = b->getSkillDifferenceRatio(mine, his);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::calculateDeadTime(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    CharStats::DeadTimeState state = (CharStats::DeadTimeState)luaL_checkinteger(L, 2);
    float result = b->calculateDeadTime(state);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::xpToughness_RagdollEvent(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    b->xpToughness_RagdollEvent();
    return 0;
}

int CharStatsBinding::xpToughness_GetUpEvent(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    b->xpToughness_GetUpEvent();
    return 0;
}

int CharStatsBinding::xpToughness_PunchSomething(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    HitMaterialType mat = (HitMaterialType)luaL_checkinteger(L, 2);
    b->xpToughness_PunchSomething(mat);
    return 0;
}

int CharStatsBinding::xpRunning(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float time = (float)luaL_checknumber(L, 2);
    float speed = (float)luaL_checknumber(L, 3);
    b->xpRunning(time, speed);
    return 0;
}

int CharStatsBinding::xpStealthHearCheckEvent(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    bool enemiesAbout = lua_toboolean(L, 2) != 0;
    bool trespassing = lua_toboolean(L, 3) != 0;
    bool seen = lua_toboolean(L, 4) != 0;
    b->xpStealthHearCheckEvent(enemiesAbout, trespassing, seen);
    return 0;
}

int CharStatsBinding::xpMassCombat(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    b->xpMassCombat();
    return 0;
}

int CharStatsBinding::xpEngineering(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float time = (float)luaL_checknumber(L, 2);
    b->xpEngineering(time);
    return 0;
}

int CharStatsBinding::xpLockpicking(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    int lockLevel = (int)luaL_checkinteger(L, 2);
    bool success = lua_toboolean(L, 3) != 0;
    b->xpLockpicking(lockLevel, success);
    return 0;
}

int CharStatsBinding::xpGeneral(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float time = (float)luaL_checknumber(L, 2);
    float mult = (float)luaL_checknumber(L, 3);
    StatsEnumerated what = (StatsEnumerated)luaL_checkinteger(L, 4);
    b->xpGeneral(time, mult, what);
    return 0;
}

int CharStatsBinding::calculateAthleticsXPMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float speed = (float)luaL_checknumber(L, 2);
    float result = b->calculateAthleticsXPMult(speed);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::calculateStrengthXPMultFromWalking(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->calculateStrengthXPMultFromWalking();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::isUnarmed(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    bool result = b->isUnarmed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharStatsBinding::getWeaponWeightXPBonus(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->getWeaponWeightXPBonus();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getAttackSpeed(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->getAttackSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getBlockSpeed(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->getBlockSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getMaxRunSpeed(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->getMaxRunSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getCurrentWeaponLength(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->getCurrentWeaponLength();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getStealthSkill01(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    bool modded = lua_toboolean(L, 2) != 0;
    float result = b->getStealthSkill01(modded);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getAttackSuccessChanceSkill(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->getAttackSuccessChanceSkill();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getEncumbranceMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->getEncumbranceMult();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::calculateHungerMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->calculateHungerMult();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::calculateTheoreticalIdealMaxRunSpeed(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->calculateTheoreticalIdealMaxRunSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::calculateWeaponWeightXPMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float weaponWeight = (float)luaL_checknumber(L, 2);
    float result = b->calculateWeaponWeightXPMult(weaponWeight);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::hasWeapon(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    bool result = b->hasWeapon();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharStatsBinding::calculateMaxStealthSpeed(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->calculateMaxStealthSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::_calculateMaxSwimSpeed(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->_calculateMaxSwimSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::calculateSwimSpeed(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->calculateSwimSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::calculateDodgeChance(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float versus = (float)luaL_checknumber(L, 2);
    bool stumbling = lua_toboolean(L, 3) != 0;
    float result = b->calculateDodgeChance(versus, stumbling);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::calculateMaxRunSpeed(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    b->calculateMaxRunSpeed();
    return 0;
}

int CharStatsBinding::_calculateEncumberanceMult(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float result = b->_calculateEncumberanceMult();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::_calculateWeaponWeightSpeedMultiplier(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float weaponWeight = (float)luaL_checknumber(L, 2);
    b->_calculateWeaponWeightSpeedMultiplier(weaponWeight);
    return 0;
}

int CharStatsBinding::currentWeaponHand(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    LeftRight result = b->currentWeaponHand();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharStatsBinding::calculateAttackOrBlockSpeed(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float weaponWeightSpeedMult = (float)luaL_checknumber(L, 2);
    float attackOrBlockSkill = (float)luaL_checknumber(L, 3);
    bool isBlock = lua_toboolean(L, 4) != 0;
    float result = b->calculateAttackOrBlockSpeed(weaponWeightSpeedMult, attackOrBlockSkill, isBlock);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::_calculateBlockChance(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float versus = (float)luaL_checknumber(L, 2);
    float result = b->_calculateBlockChance(versus);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::_recalculateStats(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    b->_recalculateStats();
    return 0;
}

int CharStatsBinding::_NV__recalculateStats(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    b->_NV__recalculateStats();
    return 0;
}

int CharStatsBinding::setEquippedWeaponSkill(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float v = (float)luaL_checknumber(L, 2);
    b->setEquippedWeaponSkill(v);
    return 0;
}

int CharStatsBinding::_NV_setEquippedWeaponSkill(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    float v = (float)luaL_checknumber(L, 2);
    b->_NV_setEquippedWeaponSkill(v);
    return 0;
}

int CharStatsBinding::_DESTRUCTOR(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 54: void serialise(...) - unsupported arg type
  line 55: void updateStats(...) - unsupported arg type
  line 56: void init(...) - unsupported arg type
  line 57: void _NV_init(...) - unsupported arg type
  line 59: void getGUIData(...) - unsupported arg type
  line 60: void printStealthStats(...) - non-string reference arg
  line 61: void getStealthTooltip(...) - unsupported arg type
  line 62: void printRunSpeedStatMax(...) - non-string reference arg
  line 63: void getAthleticsTooltip(...) - unsupported arg type
  line 64: void getGUIDataForMainInfo(...) - unsupported arg type
  line 65: std::string formatWholeStatStringWithBonuses(...) - overloaded method
  line 66: std::string formatWholeStatStringWithBonuses(...) - overloaded method
  line 80: float& getStatRef(...) - reference return type
  line 82: std::string getStatName(...) - static method
  line 85: bool getStatPenaltiesForGUI(...) - unsupported arg type
  line 143: float& getMeleeAttackRef(...) - reference return type
  line 144: void _chooseAttacks(...) - unsupported arg type
  line 155: float getMaxHealAmount(...) - unsupported arg type
  line 172: CombatTechniqueData* getBashAnimation(...) - unsupported return type
  line 173: CombatTechniqueData* chooseAttack(...) - unsupported return type
  line 175: CombatTechniqueData* chooseBlock(...) - unsupported return type
  line 177: const std::string& getPainAnim(...) - reference return type
  line 186: Damages getTotalAttackDamageFor(...) - unsupported return type
  line 209: void xpMelee(...) - unsupported arg type
  line 213: void xpFirstAid(...) - unsupported arg type
  line 215: void xpStealth(...) - unsupported arg type
  line 217: StringPair stealthXPMultForGUI(...) - unsupported return type
  line 223: void xpTraining(...) - non-string reference arg
  line 227: void setWeapon(...) - unsupported arg type
  line 237: float _convertWeaponWeightToBluntMultiplier(...) - static method
  line 238: float _convertBluntMultiplierToWeaponWeight(...) - static method
  line 241: void printExertionHungerMultTooltip(...) - unsupported arg type
  line 265: void setupCombatTechniques(...) - static method
*/
static int CharStats_getTotalAttackDamageFor(lua_State* L)
{
    CharStats* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharStats is nil");
    Character* target = nullptr;
    if (lua_gettop(L) >= 2 && !lua_isnil(L, 2)) {
        target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    }
    Damages result = b->getTotalAttackDamageFor(target);
    void* mem = ::operator new(sizeof(Damages));
    Damages* heapD = ::new(mem) Damages(result);
    return pushObject<Damages>(L, heapD, DamagesBinding::getMetatableName());
}

int CharStatsBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CharStatsBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CharStats object");
    return 1;
}

void CharStatsBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CharStatsBinding::gc },
        { "__tostring", CharStatsBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getWeatherProtection", CharStatsBinding::getWeatherProtection },
        { "_CONSTRUCTOR", CharStatsBinding::_CONSTRUCTOR },
        { "unarmedEncumbrancePenalty", CharStatsBinding::unarmedEncumbrancePenalty },
        { "skillBonusUnarmed_forGUI", CharStatsBinding::skillBonusUnarmed_forGUI },
        { "skillBonusAttack_melee", CharStatsBinding::skillBonusAttack_melee },
        { "skillBonusAttack_unarmed", CharStatsBinding::skillBonusAttack_unarmed },
        { "skillBonusDefence", CharStatsBinding::skillBonusDefence },
        { "_randomiseStats", CharStatsBinding::_randomiseStats },
        { "getGUIStatsDisplayMode", CharStatsBinding::getGUIStatsDisplayMode },
        { "periodicUpdate", CharStatsBinding::periodicUpdate },
        { "_NV_periodicUpdate", CharStatsBinding::_NV_periodicUpdate },
        { "calculateStumbleThresholdDamageAmount", CharStatsBinding::calculateStumbleThresholdDamageAmount },
        { "setEquipmentStatBonuses", CharStatsBinding::setEquipmentStatBonuses },
        { "getOverallSkillLevel_0_100", CharStatsBinding::getOverallSkillLevel_0_100 },
        { "getStat", CharStatsBinding::getStat },
        { "getStatMultiplier", CharStatsBinding::getStatMultiplier },
        { "getStatMultiplierForGUI", CharStatsBinding::getStatMultiplierForGUI },
        { "getStatPenaltiesTotalForGUI", CharStatsBinding::getStatPenaltiesTotalForGUI },
        { "xpStat_timeBased", CharStatsBinding::xpStat_timeBased },
        { "xpStat_eventBased", CharStatsBinding::xpStat_eventBased },
        { "xpDodgeEvent", CharStatsBinding::xpDodgeEvent },
        { "strengthActual", CharStatsBinding::strengthActual }, //original
        { "strengthBase", CharStatsBinding::strengthBase }, //original
        { "_NV_strengthBase", CharStatsBinding::_NV_strengthBase }, //original
        { "dexterityBase", CharStatsBinding::dexterityBase }, //original
        { "dexterityActual", CharStatsBinding::dexterityActual }, //original
        { "toughness", CharStatsBinding::toughness }, //original
        { "getStrength", CharStatsBinding::getStrength }, //alias
        { "getStrengthRaw", CharStatsBinding::getStrengthBase }, //alias
        { "getDexterity", CharStatsBinding::getDexterity }, //alias
        { "getDexterityRaw", CharStatsBinding::getDexterityBase }, //alias
        { "getToughness", CharStatsBinding::getToughness }, //alias
        { "getPerception", CharStatsBinding::getPerception }, //alias
        { "getAthletics", CharStatsBinding::getAthletics }, //alias
        { "getThieving", CharStatsBinding::getThieving }, //alias
        { "getToughnessMult", CharStatsBinding::getToughnessMult },
        { "getRangedFriendlyFireAvoidanceChance", CharStatsBinding::getRangedFriendlyFireAvoidanceChance },
        { "getRangedAccuracyMult", CharStatsBinding::getRangedAccuracyMult },
        { "getReloadSkill", CharStatsBinding::getReloadSkill },
        { "animalRecruitReduceStats", CharStatsBinding::animalRecruitReduceStats },
        { "getMeleeDefence", CharStatsBinding::getMeleeDefence },
        { "getDodge", CharStatsBinding::getDodge },
        { "getDodgePenalty_encumbrance", CharStatsBinding::getDodgePenalty_encumbrance },
        { "getDodgePenalty_injuries", CharStatsBinding::getDodgePenalty_injuries },
        { "getDodgePenalty_gear", CharStatsBinding::getDodgePenalty_gear },
        { "getMeleeDefence_melee", CharStatsBinding::getMeleeDefence_melee },
        { "getMeleeAttack", CharStatsBinding::getMeleeAttack },
        { "getMeleeAttack_unarmed", CharStatsBinding::getMeleeAttack_unarmed },
        { "getMeleeAttack_melee", CharStatsBinding::getMeleeAttack_melee },
        { "_getMeleeAttackBase", CharStatsBinding::_getMeleeAttackBase },
        { "isDefensiveMode", CharStatsBinding::isDefensiveMode },
        { "holdPositionMode", CharStatsBinding::holdPositionMode },
        { "setHoldLocation", CharStatsBinding::setHoldLocation },
        { "clearHoldLocation", CharStatsBinding::clearHoldLocation },
        { "calculateStumbleBlockTimer", CharStatsBinding::calculateStumbleBlockTimer },
        { "calculateTechniqueInegrityCheckTimer", CharStatsBinding::calculateTechniqueInegrityCheckTimer },
        { "calculateToughnessDamageResistanceMult", CharStatsBinding::calculateToughnessDamageResistanceMult },
        { "calculateToughnessWoundDegenerationRate", CharStatsBinding::calculateToughnessWoundDegenerationRate },
        { "getAttackChance", CharStatsBinding::getAttackChance },
        { "getAttackCuttingDamage", CharStatsBinding::getAttackCuttingDamage },
        { "getAttackBluntPower", CharStatsBinding::getAttackBluntPower },
        { "getAttackBleedDamageMult", CharStatsBinding::getAttackBleedDamageMult },
        { "getAttackPierceDamage", CharStatsBinding::getAttackPierceDamage },
        { "getEquippedWeaponSkill", CharStatsBinding::getEquippedWeaponSkill },
        { "_NV_getEquippedWeaponSkill", CharStatsBinding::_NV_getEquippedWeaponSkill },
        { "getSkillDifferenceRatio", CharStatsBinding::getSkillDifferenceRatio },
        { "calculateDeadTime", CharStatsBinding::calculateDeadTime },
        { "xpToughness_RagdollEvent", CharStatsBinding::xpToughness_RagdollEvent },
        { "xpToughness_GetUpEvent", CharStatsBinding::xpToughness_GetUpEvent },
        { "xpToughness_PunchSomething", CharStatsBinding::xpToughness_PunchSomething },
        { "xpRunning", CharStatsBinding::xpRunning },
        { "xpStealthHearCheckEvent", CharStatsBinding::xpStealthHearCheckEvent },
        { "xpMassCombat", CharStatsBinding::xpMassCombat },
        { "xpEngineering", CharStatsBinding::xpEngineering },
        { "xpLockpicking", CharStatsBinding::xpLockpicking },
        { "xpGeneral", CharStatsBinding::xpGeneral },
        { "calculateAthleticsXPMult", CharStatsBinding::calculateAthleticsXPMult },
        { "calculateStrengthXPMultFromWalking", CharStatsBinding::calculateStrengthXPMultFromWalking },
        { "isUnarmed", CharStatsBinding::isUnarmed },
        { "getWeaponWeightXPBonus", CharStatsBinding::getWeaponWeightXPBonus },
        { "getAttackSpeed", CharStatsBinding::getAttackSpeed },
        { "getBlockSpeed", CharStatsBinding::getBlockSpeed },
        { "getMaxRunSpeed", CharStatsBinding::getMaxRunSpeed },
        { "getCurrentWeaponLength", CharStatsBinding::getCurrentWeaponLength },
        { "getStealthSkill01", CharStatsBinding::getStealthSkill01 },
        { "getAttackSuccessChanceSkill", CharStatsBinding::getAttackSuccessChanceSkill },
        { "getEncumbranceMult", CharStatsBinding::getEncumbranceMult },
        { "calculateHungerMult", CharStatsBinding::calculateHungerMult },
        { "calculateTheoreticalIdealMaxRunSpeed", CharStatsBinding::calculateTheoreticalIdealMaxRunSpeed },
        { "calculateWeaponWeightXPMult", CharStatsBinding::calculateWeaponWeightXPMult },
        { "hasWeapon", CharStatsBinding::hasWeapon },
        { "calculateMaxStealthSpeed", CharStatsBinding::calculateMaxStealthSpeed },
        { "_calculateMaxSwimSpeed", CharStatsBinding::_calculateMaxSwimSpeed },
        { "calculateSwimSpeed", CharStatsBinding::calculateSwimSpeed },
        { "calculateDodgeChance", CharStatsBinding::calculateDodgeChance },
        { "calculateMaxRunSpeed", CharStatsBinding::calculateMaxRunSpeed },
        { "_calculateEncumberanceMult", CharStatsBinding::_calculateEncumberanceMult },
        { "_calculateWeaponWeightSpeedMultiplier", CharStatsBinding::_calculateWeaponWeightSpeedMultiplier },
        { "currentWeaponHand", CharStatsBinding::currentWeaponHand },
        { "calculateAttackOrBlockSpeed", CharStatsBinding::calculateAttackOrBlockSpeed },
        { "_calculateBlockChance", CharStatsBinding::_calculateBlockChance },
        { "_recalculateStats", CharStatsBinding::_recalculateStats },
        { "_NV__recalculateStats", CharStatsBinding::_NV__recalculateStats },
        { "setEquippedWeaponSkill", CharStatsBinding::setEquippedWeaponSkill },
        { "_NV_setEquippedWeaponSkill", CharStatsBinding::_NV_setEquippedWeaponSkill },
        { "_DESTRUCTOR", CharStatsBinding::_DESTRUCTOR },
        { "getTotalAttackDamageFor", CharStats_getTotalAttackDamageFor },
        { 0, 0 }
    };

    registerClass(
        L, 
        CharStatsBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CharStatsBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, CharStats_get_medical);
    lua_setfield(L, -2, "medical");
    lua_pushcfunction(L, CharStats_get_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, CharStats_get_athleticsMultiplier);
    lua_setfield(L, -2, "athleticsMultiplier");
    lua_pushcfunction(L, CharStats_get_combatSpeedMultiplier);
    lua_setfield(L, -2, "combatSpeedMultiplier");
    lua_pushcfunction(L, CharStats_get__skillBonusAttack);
    lua_setfield(L, -2, "_skillBonusAttack");
    lua_pushcfunction(L, CharStats_get__skillBonusDefence);
    lua_setfield(L, -2, "_skillBonusDefence");
    lua_pushcfunction(L, CharStats_get_skillBonusIndoors);
    lua_setfield(L, -2, "skillBonusIndoors");
    lua_pushcfunction(L, CharStats_get_skillBonusUnarmed);
    lua_setfield(L, -2, "skillBonusUnarmed");
    lua_pushcfunction(L, CharStats_get_skillBonusPerception);
    lua_setfield(L, -2, "skillBonusPerception");
    lua_pushcfunction(L, CharStats_get_ageMult);
    lua_setfield(L, -2, "ageMult");
    lua_pushcfunction(L, CharStats_get_skillMultDodge);
    lua_setfield(L, -2, "skillMultDodge");
    lua_pushcfunction(L, CharStats_get_skillMultStealth);
    lua_setfield(L, -2, "skillMultStealth");
    lua_pushcfunction(L, CharStats_get_skillMultAssassin);
    lua_setfield(L, -2, "skillMultAssassin");
    lua_pushcfunction(L, CharStats_get_skillMultDexterity);
    lua_setfield(L, -2, "skillMultDexterity");
    lua_pushcfunction(L, CharStats_get_skillMultDamage);
    lua_setfield(L, -2, "skillMultDamage");
    lua_pushcfunction(L, CharStats_get_fistInjuryEquipmentMult);
    lua_setfield(L, -2, "fistInjuryEquipmentMult");
    lua_pushcfunction(L, CharStats_get_skillMultRanged);
    lua_setfield(L, -2, "skillMultRanged");
    lua_pushcfunction(L, CharStats_get__weatherProtections);
    lua_setfield(L, -2, "_weatherProtections");
    lua_pushcfunction(L, CharStats_get__strength);
    lua_setfield(L, -2, "_strength");
    lua_pushcfunction(L, CharStats_get_fitness);
    lua_setfield(L, -2, "fitness");
    lua_pushcfunction(L, CharStats_get__dexterity);
    lua_setfield(L, -2, "_dexterity");
    lua_pushcfunction(L, CharStats_get_perception);
    lua_setfield(L, -2, "perception");
    lua_pushcfunction(L, CharStats_get__toughness);
    lua_setfield(L, -2, "_toughness");
    lua_pushcfunction(L, CharStats_get__athletics);
    lua_setfield(L, -2, "_athletics");
    lua_pushcfunction(L, CharStats_get_medic);
    lua_setfield(L, -2, "medic");
    lua_pushcfunction(L, CharStats_get_massCombat);
    lua_setfield(L, -2, "massCombat");
    lua_pushcfunction(L, CharStats_get_arrowDefence);
    lua_setfield(L, -2, "arrowDefence");
    lua_pushcfunction(L, CharStats_get_stealth);
    lua_setfield(L, -2, "stealth");
    lua_pushcfunction(L, CharStats_get_swimming);
    lua_setfield(L, -2, "swimming");
    lua_pushcfunction(L, CharStats_get_thieving);
    lua_setfield(L, -2, "thieving");
    lua_pushcfunction(L, CharStats_get_lockpicking);
    lua_setfield(L, -2, "lockpicking");
    lua_pushcfunction(L, CharStats_get_bluff);
    lua_setfield(L, -2, "bluff");
    lua_pushcfunction(L, CharStats_get_assassin);
    lua_setfield(L, -2, "assassin");
    lua_pushcfunction(L, CharStats_get_survival);
    lua_setfield(L, -2, "survival");
    lua_pushcfunction(L, CharStats_get_tracking);
    lua_setfield(L, -2, "tracking");
    lua_pushcfunction(L, CharStats_get_climbing);
    lua_setfield(L, -2, "climbing");
    lua_pushcfunction(L, CharStats_get_doctor);
    lua_setfield(L, -2, "doctor");
    lua_pushcfunction(L, CharStats_get_engineer);
    lua_setfield(L, -2, "engineer");
    lua_pushcfunction(L, CharStats_get_weaponSmith);
    lua_setfield(L, -2, "weaponSmith");
    lua_pushcfunction(L, CharStats_get_armourSmith);
    lua_setfield(L, -2, "armourSmith");
    lua_pushcfunction(L, CharStats_get_bowSmith);
    lua_setfield(L, -2, "bowSmith");
    lua_pushcfunction(L, CharStats_get_robotics);
    lua_setfield(L, -2, "robotics");
    lua_pushcfunction(L, CharStats_get_science);
    lua_setfield(L, -2, "science");
    lua_pushcfunction(L, CharStats_get_labouring);
    lua_setfield(L, -2, "labouring");
    lua_pushcfunction(L, CharStats_get_farming);
    lua_setfield(L, -2, "farming");
    lua_pushcfunction(L, CharStats_get_cooking);
    lua_setfield(L, -2, "cooking");
    lua_pushcfunction(L, CharStats_get_dodging);
    lua_setfield(L, -2, "dodging");
    lua_pushcfunction(L, CharStats_get_friendlyFire);
    lua_setfield(L, -2, "friendlyFire");
    lua_pushcfunction(L, CharStats_get_katanas);
    lua_setfield(L, -2, "katanas");
    lua_pushcfunction(L, CharStats_get_sabres);
    lua_setfield(L, -2, "sabres");
    lua_pushcfunction(L, CharStats_get_hackers);
    lua_setfield(L, -2, "hackers");
    lua_pushcfunction(L, CharStats_get_blunt);
    lua_setfield(L, -2, "blunt");
    lua_pushcfunction(L, CharStats_get_heavyWeapons);
    lua_setfield(L, -2, "heavyWeapons");
    lua_pushcfunction(L, CharStats_get_unarmed);
    lua_setfield(L, -2, "unarmed");
    lua_pushcfunction(L, CharStats_get_bows);
    lua_setfield(L, -2, "bows");
    lua_pushcfunction(L, CharStats_get_turrets);
    lua_setfield(L, -2, "turrets");
    lua_pushcfunction(L, CharStats_get_polearms);
    lua_setfield(L, -2, "polearms");
    lua_pushcfunction(L, CharStats_get_currentItemMaximumJuryRig);
    lua_setfield(L, -2, "currentItemMaximumJuryRig");
    lua_pushcfunction(L, CharStats_get___meleeAttack);
    lua_setfield(L, -2, "__meleeAttack");
    lua_pushcfunction(L, CharStats_get__meleeDefence);
    lua_setfield(L, -2, "_meleeDefence");
    lua_pushcfunction(L, CharStats_get__defensiveMode);
    lua_setfield(L, -2, "_defensiveMode");
    lua_pushcfunction(L, CharStats_get_rangedMode);
    lua_setfield(L, -2, "rangedMode");
    lua_pushcfunction(L, CharStats_get_tauntMode);
    lua_setfield(L, -2, "tauntMode");
    lua_pushcfunction(L, CharStats_get__holdPositionMode);
    lua_setfield(L, -2, "_holdPositionMode");
    lua_pushcfunction(L, CharStats_get_passiveCombatMode);
    lua_setfield(L, -2, "passiveCombatMode");
    lua_pushcfunction(L, CharStats_get_holdLocation);
    lua_setfield(L, -2, "holdLocation");
    lua_pushcfunction(L, CharStats_get_warriorSpirit);
    lua_setfield(L, -2, "warriorSpirit");
    lua_pushcfunction(L, CharStats_get_derivedSpirit);
    lua_setfield(L, -2, "derivedSpirit");
    lua_pushcfunction(L, CharStats_get_aggression);
    lua_setfield(L, -2, "aggression");
    lua_pushcfunction(L, CharStats_get_goodness);
    lua_setfield(L, -2, "goodness");
    lua_pushcfunction(L, CharStats_get_evilness);
    lua_setfield(L, -2, "evilness");
    lua_pushcfunction(L, CharStats_get_longestReachingAttack);
    lua_setfield(L, -2, "longestReachingAttack");
    lua_pushcfunction(L, CharStats_get_STUBBOURNESS);
    lua_setfield(L, -2, "STUBBOURNESS");
    lua_pushcfunction(L, CharStats_get_PROFESSIONALNESS);
    lua_setfield(L, -2, "PROFESSIONALNESS");
    lua_pushcfunction(L, CharStats_get_HOLDING_POSITION);
    lua_setfield(L, -2, "HOLDING_POSITION");
    lua_pushcfunction(L, CharStats_get_IMMEDIACY);
    lua_setfield(L, -2, "IMMEDIACY");
    lua_pushcfunction(L, CharStats_get_IMMEDIACY_MAX_RANGE);
    lua_setfield(L, -2, "IMMEDIACY_MAX_RANGE");
    lua_pushcfunction(L, CharStats_get_MANLINESS);
    lua_setfield(L, -2, "MANLINESS");
    lua_pushcfunction(L, CharStats_get_MURDEROUS);
    lua_setfield(L, -2, "MURDEROUS");
    lua_pushcfunction(L, CharStats_get__stealthXPMultForGUI);
    lua_setfield(L, -2, "_stealthXPMultForGUI");
    lua_pushcfunction(L, CharStats_get_stealthXPTooManyCooksPenalty);
    lua_setfield(L, -2, "stealthXPTooManyCooksPenalty");
    lua_pushcfunction(L, CharStats_get_currentOperatingMachineHungerRate);
    lua_setfield(L, -2, "currentOperatingMachineHungerRate");
    lua_pushcfunction(L, CharStats_get_moveSpeed);
    lua_setfield(L, -2, "moveSpeed");
    lua_pushcfunction(L, CharStats_get_weaponWeightSpeedMult);
    lua_setfield(L, -2, "weaponWeightSpeedMult");
    lua_pushcfunction(L, CharStats_get_weaponWeightXPMult);
    lua_setfield(L, -2, "weaponWeightXPMult");
    lua_pushcfunction(L, CharStats_get_attackSpeed);
    lua_setfield(L, -2, "attackSpeed");
    lua_pushcfunction(L, CharStats_get_blockSpeed);
    lua_setfield(L, -2, "blockSpeed");
    lua_pushcfunction(L, CharStats_get_encumbranceMult);
    lua_setfield(L, -2, "encumbranceMult");
    lua_pushcfunction(L, CharStats_get_xp);
    lua_setfield(L, -2, "xp");
    lua_pushcfunction(L, CharStats_get_freeAttributePoints);
    lua_setfield(L, -2, "freeAttributePoints");
    lua_pushcfunction(L, CharStats_get_cutDamageMult);
    lua_setfield(L, -2, "cutDamageMult");
    lua_pushcfunction(L, CharStats_get_bluntDamageMult);
    lua_setfield(L, -2, "bluntDamageMult");
    lua_pushcfunction(L, CharStats_get_bleedDamageMult);
    lua_setfield(L, -2, "bleedDamageMult");
    lua_pushcfunction(L, CharStats_get_pierceDamageMult);
    lua_setfield(L, -2, "pierceDamageMult");
    lua_pushcfunction(L, CharStats_get_cutDamageMin);
    lua_setfield(L, -2, "cutDamageMin");
    lua_pushcfunction(L, CharStats_get_bluntDamageMin);
    lua_setfield(L, -2, "bluntDamageMin");
    lua_pushcfunction(L, CharStats_get_bonusRobots);
    lua_setfield(L, -2, "bonusRobots");
    lua_pushcfunction(L, CharStats_get_bonusHumans);
    lua_setfield(L, -2, "bonusHumans");
    lua_pushcfunction(L, CharStats_get_bonusAnimals);
    lua_setfield(L, -2, "bonusAnimals");
    lua_pushcfunction(L, CharStats_get_bonusArmourPenetration);
    lua_setfield(L, -2, "bonusArmourPenetration");
    lua_pushcfunction(L, CharStats_get_bonusRaces);
    lua_setfield(L, -2, "bonusRaces");
    lua_pushcfunction(L, CharStats_get_currentWeaponType);
    lua_setfield(L, -2, "currentWeaponType");
    lua_pushcfunction(L, CharStats_get_pCurrentWeaponSkill);
    lua_setfield(L, -2, "pCurrentWeaponSkill");
    lua_pushcfunction(L, CharStats_get_currentWeaponLength);
    lua_setfield(L, -2, "currentWeaponLength");
    lua_pushcfunction(L, CharStats_get_weapon);
    lua_setfield(L, -2, "weapon");
    lua_pushcfunction(L, CharStats_get_weaponWeight);
    lua_setfield(L, -2, "weaponWeight");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, CharStats_set_medical);
    lua_setfield(L, -2, "medical");
    lua_pushcfunction(L, CharStats_set_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, CharStats_set_athleticsMultiplier);
    lua_setfield(L, -2, "athleticsMultiplier");
    lua_pushcfunction(L, CharStats_set_combatSpeedMultiplier);
    lua_setfield(L, -2, "combatSpeedMultiplier");
    lua_pushcfunction(L, CharStats_set__skillBonusAttack);
    lua_setfield(L, -2, "_skillBonusAttack");
    lua_pushcfunction(L, CharStats_set__skillBonusDefence);
    lua_setfield(L, -2, "_skillBonusDefence");
    lua_pushcfunction(L, CharStats_set_skillBonusIndoors);
    lua_setfield(L, -2, "skillBonusIndoors");
    lua_pushcfunction(L, CharStats_set_skillBonusUnarmed);
    lua_setfield(L, -2, "skillBonusUnarmed");
    lua_pushcfunction(L, CharStats_set_skillBonusPerception);
    lua_setfield(L, -2, "skillBonusPerception");
    lua_pushcfunction(L, CharStats_set_ageMult);
    lua_setfield(L, -2, "ageMult");
    lua_pushcfunction(L, CharStats_set_skillMultDodge);
    lua_setfield(L, -2, "skillMultDodge");
    lua_pushcfunction(L, CharStats_set_skillMultStealth);
    lua_setfield(L, -2, "skillMultStealth");
    lua_pushcfunction(L, CharStats_set_skillMultAssassin);
    lua_setfield(L, -2, "skillMultAssassin");
    lua_pushcfunction(L, CharStats_set_skillMultDexterity);
    lua_setfield(L, -2, "skillMultDexterity");
    lua_pushcfunction(L, CharStats_set_skillMultDamage);
    lua_setfield(L, -2, "skillMultDamage");
    lua_pushcfunction(L, CharStats_set_fistInjuryEquipmentMult);
    lua_setfield(L, -2, "fistInjuryEquipmentMult");
    lua_pushcfunction(L, CharStats_set_skillMultRanged);
    lua_setfield(L, -2, "skillMultRanged");
    lua_pushcfunction(L, CharStats_set__weatherProtections);
    lua_setfield(L, -2, "_weatherProtections");
    lua_pushcfunction(L, CharStats_set__strength);
    lua_setfield(L, -2, "_strength");
    lua_pushcfunction(L, CharStats_set_fitness);
    lua_setfield(L, -2, "fitness");
    lua_pushcfunction(L, CharStats_set__dexterity);
    lua_setfield(L, -2, "_dexterity");
    lua_pushcfunction(L, CharStats_set_perception);
    lua_setfield(L, -2, "perception");
    lua_pushcfunction(L, CharStats_set__toughness);
    lua_setfield(L, -2, "_toughness");
    lua_pushcfunction(L, CharStats_set__athletics);
    lua_setfield(L, -2, "_athletics");
    lua_pushcfunction(L, CharStats_set_medic);
    lua_setfield(L, -2, "medic");
    lua_pushcfunction(L, CharStats_set_massCombat);
    lua_setfield(L, -2, "massCombat");
    lua_pushcfunction(L, CharStats_set_arrowDefence);
    lua_setfield(L, -2, "arrowDefence");
    lua_pushcfunction(L, CharStats_set_stealth);
    lua_setfield(L, -2, "stealth");
    lua_pushcfunction(L, CharStats_set_swimming);
    lua_setfield(L, -2, "swimming");
    lua_pushcfunction(L, CharStats_set_thieving);
    lua_setfield(L, -2, "thieving");
    lua_pushcfunction(L, CharStats_set_lockpicking);
    lua_setfield(L, -2, "lockpicking");
    lua_pushcfunction(L, CharStats_set_bluff);
    lua_setfield(L, -2, "bluff");
    lua_pushcfunction(L, CharStats_set_assassin);
    lua_setfield(L, -2, "assassin");
    lua_pushcfunction(L, CharStats_set_survival);
    lua_setfield(L, -2, "survival");
    lua_pushcfunction(L, CharStats_set_tracking);
    lua_setfield(L, -2, "tracking");
    lua_pushcfunction(L, CharStats_set_climbing);
    lua_setfield(L, -2, "climbing");
    lua_pushcfunction(L, CharStats_set_doctor);
    lua_setfield(L, -2, "doctor");
    lua_pushcfunction(L, CharStats_set_engineer);
    lua_setfield(L, -2, "engineer");
    lua_pushcfunction(L, CharStats_set_weaponSmith);
    lua_setfield(L, -2, "weaponSmith");
    lua_pushcfunction(L, CharStats_set_armourSmith);
    lua_setfield(L, -2, "armourSmith");
    lua_pushcfunction(L, CharStats_set_bowSmith);
    lua_setfield(L, -2, "bowSmith");
    lua_pushcfunction(L, CharStats_set_robotics);
    lua_setfield(L, -2, "robotics");
    lua_pushcfunction(L, CharStats_set_science);
    lua_setfield(L, -2, "science");
    lua_pushcfunction(L, CharStats_set_labouring);
    lua_setfield(L, -2, "labouring");
    lua_pushcfunction(L, CharStats_set_farming);
    lua_setfield(L, -2, "farming");
    lua_pushcfunction(L, CharStats_set_cooking);
    lua_setfield(L, -2, "cooking");
    lua_pushcfunction(L, CharStats_set_dodging);
    lua_setfield(L, -2, "dodging");
    lua_pushcfunction(L, CharStats_set_friendlyFire);
    lua_setfield(L, -2, "friendlyFire");
    lua_pushcfunction(L, CharStats_set_katanas);
    lua_setfield(L, -2, "katanas");
    lua_pushcfunction(L, CharStats_set_sabres);
    lua_setfield(L, -2, "sabres");
    lua_pushcfunction(L, CharStats_set_hackers);
    lua_setfield(L, -2, "hackers");
    lua_pushcfunction(L, CharStats_set_blunt);
    lua_setfield(L, -2, "blunt");
    lua_pushcfunction(L, CharStats_set_heavyWeapons);
    lua_setfield(L, -2, "heavyWeapons");
    lua_pushcfunction(L, CharStats_set_unarmed);
    lua_setfield(L, -2, "unarmed");
    lua_pushcfunction(L, CharStats_set_bows);
    lua_setfield(L, -2, "bows");
    lua_pushcfunction(L, CharStats_set_turrets);
    lua_setfield(L, -2, "turrets");
    lua_pushcfunction(L, CharStats_set_polearms);
    lua_setfield(L, -2, "polearms");
    lua_pushcfunction(L, CharStats_set_currentItemMaximumJuryRig);
    lua_setfield(L, -2, "currentItemMaximumJuryRig");
    lua_pushcfunction(L, CharStats_set___meleeAttack);
    lua_setfield(L, -2, "__meleeAttack");
    lua_pushcfunction(L, CharStats_set__meleeDefence);
    lua_setfield(L, -2, "_meleeDefence");
    lua_pushcfunction(L, CharStats_set__defensiveMode);
    lua_setfield(L, -2, "_defensiveMode");
    lua_pushcfunction(L, CharStats_set_rangedMode);
    lua_setfield(L, -2, "rangedMode");
    lua_pushcfunction(L, CharStats_set_tauntMode);
    lua_setfield(L, -2, "tauntMode");
    lua_pushcfunction(L, CharStats_set__holdPositionMode);
    lua_setfield(L, -2, "_holdPositionMode");
    lua_pushcfunction(L, CharStats_set_passiveCombatMode);
    lua_setfield(L, -2, "passiveCombatMode");
    lua_pushcfunction(L, CharStats_set_holdLocation);
    lua_setfield(L, -2, "holdLocation");
    lua_pushcfunction(L, CharStats_set_warriorSpirit);
    lua_setfield(L, -2, "warriorSpirit");
    lua_pushcfunction(L, CharStats_set_derivedSpirit);
    lua_setfield(L, -2, "derivedSpirit");
    lua_pushcfunction(L, CharStats_set_aggression);
    lua_setfield(L, -2, "aggression");
    lua_pushcfunction(L, CharStats_set_goodness);
    lua_setfield(L, -2, "goodness");
    lua_pushcfunction(L, CharStats_set_evilness);
    lua_setfield(L, -2, "evilness");
    lua_pushcfunction(L, CharStats_set_longestReachingAttack);
    lua_setfield(L, -2, "longestReachingAttack");
    lua_pushcfunction(L, CharStats_set_STUBBOURNESS);
    lua_setfield(L, -2, "STUBBOURNESS");
    lua_pushcfunction(L, CharStats_set_PROFESSIONALNESS);
    lua_setfield(L, -2, "PROFESSIONALNESS");
    lua_pushcfunction(L, CharStats_set_HOLDING_POSITION);
    lua_setfield(L, -2, "HOLDING_POSITION");
    lua_pushcfunction(L, CharStats_set_IMMEDIACY);
    lua_setfield(L, -2, "IMMEDIACY");
    lua_pushcfunction(L, CharStats_set_IMMEDIACY_MAX_RANGE);
    lua_setfield(L, -2, "IMMEDIACY_MAX_RANGE");
    lua_pushcfunction(L, CharStats_set_MANLINESS);
    lua_setfield(L, -2, "MANLINESS");
    lua_pushcfunction(L, CharStats_set_MURDEROUS);
    lua_setfield(L, -2, "MURDEROUS");
    lua_pushcfunction(L, CharStats_set__stealthXPMultForGUI);
    lua_setfield(L, -2, "_stealthXPMultForGUI");
    lua_pushcfunction(L, CharStats_set_stealthXPTooManyCooksPenalty);
    lua_setfield(L, -2, "stealthXPTooManyCooksPenalty");
    lua_pushcfunction(L, CharStats_set_currentOperatingMachineHungerRate);
    lua_setfield(L, -2, "currentOperatingMachineHungerRate");
    lua_pushcfunction(L, CharStats_set_moveSpeed);
    lua_setfield(L, -2, "moveSpeed");
    lua_pushcfunction(L, CharStats_set_weaponWeightSpeedMult);
    lua_setfield(L, -2, "weaponWeightSpeedMult");
    lua_pushcfunction(L, CharStats_set_weaponWeightXPMult);
    lua_setfield(L, -2, "weaponWeightXPMult");
    lua_pushcfunction(L, CharStats_set_attackSpeed);
    lua_setfield(L, -2, "attackSpeed");
    lua_pushcfunction(L, CharStats_set_blockSpeed);
    lua_setfield(L, -2, "blockSpeed");
    lua_pushcfunction(L, CharStats_set_encumbranceMult);
    lua_setfield(L, -2, "encumbranceMult");
    lua_pushcfunction(L, CharStats_set_xp);
    lua_setfield(L, -2, "xp");
    lua_pushcfunction(L, CharStats_set_freeAttributePoints);
    lua_setfield(L, -2, "freeAttributePoints");
    lua_pushcfunction(L, CharStats_set_cutDamageMult);
    lua_setfield(L, -2, "cutDamageMult");
    lua_pushcfunction(L, CharStats_set_bluntDamageMult);
    lua_setfield(L, -2, "bluntDamageMult");
    lua_pushcfunction(L, CharStats_set_bleedDamageMult);
    lua_setfield(L, -2, "bleedDamageMult");
    lua_pushcfunction(L, CharStats_set_pierceDamageMult);
    lua_setfield(L, -2, "pierceDamageMult");
    lua_pushcfunction(L, CharStats_set_cutDamageMin);
    lua_setfield(L, -2, "cutDamageMin");
    lua_pushcfunction(L, CharStats_set_bluntDamageMin);
    lua_setfield(L, -2, "bluntDamageMin");
    lua_pushcfunction(L, CharStats_set_bonusRobots);
    lua_setfield(L, -2, "bonusRobots");
    lua_pushcfunction(L, CharStats_set_bonusHumans);
    lua_setfield(L, -2, "bonusHumans");
    lua_pushcfunction(L, CharStats_set_bonusAnimals);
    lua_setfield(L, -2, "bonusAnimals");
    lua_pushcfunction(L, CharStats_set_bonusArmourPenetration);
    lua_setfield(L, -2, "bonusArmourPenetration");
    lua_pushcfunction(L, CharStats_set_bonusRaces);
    lua_setfield(L, -2, "bonusRaces");
    lua_pushcfunction(L, CharStats_set_currentWeaponType);
    lua_setfield(L, -2, "currentWeaponType");
    lua_pushcfunction(L, CharStats_set_pCurrentWeaponSkill);
    lua_setfield(L, -2, "pCurrentWeaponSkill");
    lua_pushcfunction(L, CharStats_set_currentWeaponLength);
    lua_setfield(L, -2, "currentWeaponLength");
    lua_pushcfunction(L, CharStats_set_weapon);
    lua_setfield(L, -2, "weapon");
    lua_pushcfunction(L, CharStats_set_weaponWeight);
    lua_setfield(L, -2, "weaponWeight");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua