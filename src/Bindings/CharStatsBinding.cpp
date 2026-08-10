#include "pch.h"
#include "kenshi\CharStats.h"
#include "CharStatsBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/CombatTechniqueDataBinding.h"
#include "Bindings/DamagesBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/MedicalSystemBinding.h"
#include "Bindings/Util/StringPairBinding.h"
#include "Bindings/WeaponBinding.h"
#include "Bindings/Util/YesNoMaybeBinding.h"
#include "Bindings/EnumBinding.h"
#include "Bindings/FitnessSelectorBinding.h"
#include "Bindings/Util/BoostUnorderedBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/Util/StdMapBinding.h"

namespace KenshiLua
{

typedef StdMapBinding<WeatherAffecting, float> WeatherProtectionsMapBinding;
typedef StdMapBinding<GameData*, float> BonusRacesMapBinding;

static CharStats* getInstance(lua_State* L, int idx)
{
    return checkObject<CharStats>(L, idx, CharStatsBinding::getMetatableName());
}

// --- Getters for CharStats ---
static int CharStats_get_medical(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    return pushObject<MedicalSystem>(L, instance->medical, MedicalSystemBinding::getMetatableName());
}

static int CharStats_get_me(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    return pushObject<Character>(L, instance->me, CharacterBinding::getMetatableName());
}

static int CharStats_get_athleticsMultiplier(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->athleticsMultiplier);
    return 1;
}

static int CharStats_get_combatSpeedMultiplier(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->combatSpeedMultiplier);
    return 1;
}

static int CharStats_get__skillBonusAttack(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushinteger(L, instance->_skillBonusAttack);
    return 1;
}

static int CharStats_get__skillBonusDefence(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushinteger(L, instance->_skillBonusDefence);
    return 1;
}

static int CharStats_get_skillBonusIndoors(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushinteger(L, instance->skillBonusIndoors);
    return 1;
}

static int CharStats_get_skillBonusUnarmed(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushinteger(L, instance->skillBonusUnarmed);
    return 1;
}

static int CharStats_get_skillBonusPerception(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushinteger(L, instance->skillBonusPerception);
    return 1;
}

static int CharStats_get_ageMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->ageMult);
    return 1;
}

static int CharStats_get_skillMultDodge(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->skillMultDodge);
    return 1;
}

static int CharStats_get_skillMultStealth(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->skillMultStealth);
    return 1;
}

static int CharStats_get_skillMultAssassin(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->skillMultAssassin);
    return 1;
}

static int CharStats_get_skillMultDexterity(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->skillMultDexterity);
    return 1;
}

static int CharStats_get_skillMultDamage(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->skillMultDamage);
    return 1;
}

static int CharStats_get_fistInjuryEquipmentMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->fistInjuryEquipmentMult);
    return 1;
}

static int CharStats_get_skillMultRanged(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->skillMultRanged);
    return 1;
}

static int CharStats_get__strength(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->_strength);
    return 1;
}

static int CharStats_get_fitness(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->fitness);
    return 1;
}

static int CharStats_get__dexterity(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->_dexterity);
    return 1;
}

static int CharStats_get_perception(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->perception);
    return 1;
}

static int CharStats_get__toughness(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->_toughness);
    return 1;
}

static int CharStats_get__athletics(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->_athletics);
    return 1;
}

static int CharStats_get_medic(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->medic);
    return 1;
}

static int CharStats_get_massCombat(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->massCombat);
    return 1;
}

static int CharStats_get_arrowDefence(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->arrowDefence);
    return 1;
}

static int CharStats_get_stealth(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->stealth);
    return 1;
}

static int CharStats_get_swimming(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->swimming);
    return 1;
}

static int CharStats_get_thieving(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->thieving);
    return 1;
}

static int CharStats_get_lockpicking(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->lockpicking);
    return 1;
}

static int CharStats_get_bluff(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->bluff);
    return 1;
}

static int CharStats_get_assassin(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->assassin);
    return 1;
}

static int CharStats_get_survival(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->survival);
    return 1;
}

static int CharStats_get_tracking(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->tracking);
    return 1;
}

static int CharStats_get_climbing(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->climbing);
    return 1;
}

static int CharStats_get_doctor(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->doctor);
    return 1;
}

static int CharStats_get_engineer(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->engineer);
    return 1;
}

static int CharStats_get_weaponSmith(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->weaponSmith);
    return 1;
}

static int CharStats_get_armourSmith(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->armourSmith);
    return 1;
}

static int CharStats_get_bowSmith(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->bowSmith);
    return 1;
}

static int CharStats_get_robotics(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->robotics);
    return 1;
}

static int CharStats_get_science(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->science);
    return 1;
}

static int CharStats_get_labouring(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->labouring);
    return 1;
}

static int CharStats_get_farming(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->farming);
    return 1;
}

static int CharStats_get_cooking(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->cooking);
    return 1;
}

static int CharStats_get_dodging(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->dodging);
    return 1;
}

static int CharStats_get_friendlyFire(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->friendlyFire);
    return 1;
}

static int CharStats_get_katanas(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->katanas);
    return 1;
}

static int CharStats_get_sabres(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->sabres);
    return 1;
}

static int CharStats_get_hackers(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->hackers);
    return 1;
}

static int CharStats_get_blunt(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->blunt);
    return 1;
}

static int CharStats_get_heavyWeapons(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->heavyWeapons);
    return 1;
}

static int CharStats_get_unarmed(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->unarmed);
    return 1;
}

static int CharStats_get_bows(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->bows);
    return 1;
}

static int CharStats_get_turrets(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->turrets);
    return 1;
}

static int CharStats_get_polearms(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->polearms);
    return 1;
}

static int CharStats_get_currentItemMaximumJuryRig(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->currentItemMaximumJuryRig);
    return 1;
}

static int CharStats_get___meleeAttack(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->__meleeAttack);
    return 1;
}

static int CharStats_get__meleeDefence(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->_meleeDefence);
    return 1;
}

static int CharStats_get__defensiveMode(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushboolean(L, instance->_defensiveMode ? 1 : 0);
    return 1;
}

static int CharStats_get_rangedMode(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushboolean(L, instance->rangedMode ? 1 : 0);
    return 1;
}

static int CharStats_get_tauntMode(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushboolean(L, instance->tauntMode ? 1 : 0);
    return 1;
}

static int CharStats_get__holdPositionMode(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushboolean(L, instance->_holdPositionMode ? 1 : 0);
    return 1;
}

static int CharStats_get_passiveCombatMode(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushboolean(L, instance->passiveCombatMode ? 1 : 0);
    return 1;
}

static int CharStats_get_holdLocation(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    pushVector3(L, instance->holdLocation);
    return 1;
}

static int CharStats_get_warriorSpirit(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->warriorSpirit);
    return 1;
}

static int CharStats_get_derivedSpirit(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->derivedSpirit);
    return 1;
}

static int CharStats_get_aggression(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->aggression);
    return 1;
}

static int CharStats_get_goodness(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->goodness);
    return 1;
}

static int CharStats_get_evilness(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->evilness);
    return 1;
}

static int CharStats_get_longestReachingAttack(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->longestReachingAttack);
    return 1;
}

static int CharStats_get_STUBBOURNESS(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->STUBBOURNESS);
    return 1;
}

static int CharStats_get_PROFESSIONALNESS(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->PROFESSIONALNESS);
    return 1;
}

static int CharStats_get_HOLDING_POSITION(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->HOLDING_POSITION);
    return 1;
}

static int CharStats_get_IMMEDIACY(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->IMMEDIACY);
    return 1;
}

static int CharStats_get_IMMEDIACY_MAX_RANGE(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->IMMEDIACY_MAX_RANGE);
    return 1;
}

static int CharStats_get_MANLINESS(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->MANLINESS);
    return 1;
}

static int CharStats_get_MURDEROUS(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->MURDEROUS);
    return 1;
}

static int CharStats_get__stealthXPMultForGUI(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->_stealthXPMultForGUI);
    return 1;
}

static int CharStats_get_stealthXPTooManyCooksPenalty(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->stealthXPTooManyCooksPenalty);
    return 1;
}

static int CharStats_get_currentOperatingMachineHungerRate(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->currentOperatingMachineHungerRate);
    return 1;
}

static int CharStats_get_moveSpeed(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->moveSpeed);
    return 1;
}

static int CharStats_get_weaponWeightSpeedMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->weaponWeightSpeedMult);
    return 1;
}

static int CharStats_get_weaponWeightXPMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->weaponWeightXPMult);
    return 1;
}

static int CharStats_get_attackSpeed(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->attackSpeed);
    return 1;
}

static int CharStats_get_blockSpeed(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->blockSpeed);
    return 1;
}

static int CharStats_get_encumbranceMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->encumbranceMult);
    return 1;
}

static int CharStats_get_xp(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->xp);
    return 1;
}

static int CharStats_get_freeAttributePoints(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushinteger(L, instance->freeAttributePoints);
    return 1;
}

static int CharStats_get_cutDamageMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->cutDamageMult);
    return 1;
}

static int CharStats_get_bluntDamageMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->bluntDamageMult);
    return 1;
}

static int CharStats_get_bleedDamageMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->bleedDamageMult);
    return 1;
}

static int CharStats_get_pierceDamageMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->pierceDamageMult);
    return 1;
}

static int CharStats_get_cutDamageMin(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->cutDamageMin);
    return 1;
}

static int CharStats_get_bluntDamageMin(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->bluntDamageMin);
    return 1;
}

static int CharStats_get_bonusRobots(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->bonusRobots);
    return 1;
}

static int CharStats_get_bonusHumans(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->bonusHumans);
    return 1;
}

static int CharStats_get_bonusAnimals(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->bonusAnimals);
    return 1;
}

static int CharStats_get_bonusArmourPenetration(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->bonusArmourPenetration);
    return 1;
}

static int CharStats_get_currentWeaponType(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushinteger(L, (lua_Integer)instance->currentWeaponType);
    return 1;
}

static int CharStats_get_pCurrentWeaponSkill(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushlightuserdata(L, (void*)instance->pCurrentWeaponSkill);
    return 1;
}

static int CharStats_get_currentWeaponLength(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->currentWeaponLength);
    return 1;
}

static int CharStats_get_weapon(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    return HandBinding::push(L, instance->weapon);
}

static int CharStats_get_weaponWeight(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->weaponWeight);
    return 1;
}

// --- Setters for CharStats ---
static int CharStats_set_medical(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->medical = lua_isnoneornil(L, 2) ? nullptr : checkObject<MedicalSystem>(L, 2, MedicalSystemBinding::getMetatableName());
    return 0;
}

static int CharStats_set_me(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->me = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int CharStats_set_athleticsMultiplier(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->athleticsMultiplier = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_combatSpeedMultiplier(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->combatSpeedMultiplier = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set__skillBonusAttack(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->_skillBonusAttack = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CharStats_set__skillBonusDefence(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->_skillBonusDefence = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CharStats_set_skillBonusIndoors(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->skillBonusIndoors = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CharStats_set_skillBonusUnarmed(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->skillBonusUnarmed = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CharStats_set_skillBonusPerception(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->skillBonusPerception = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CharStats_set_ageMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->ageMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_skillMultDodge(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->skillMultDodge = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_skillMultStealth(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->skillMultStealth = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_skillMultAssassin(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->skillMultAssassin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_skillMultDexterity(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->skillMultDexterity = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_skillMultDamage(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->skillMultDamage = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_fistInjuryEquipmentMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->fistInjuryEquipmentMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_skillMultRanged(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->skillMultRanged = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set__strength(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->_strength = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_fitness(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->fitness = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set__dexterity(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->_dexterity = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_perception(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->perception = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set__toughness(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->_toughness = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set__athletics(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->_athletics = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_medic(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->medic = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_massCombat(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->massCombat = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_arrowDefence(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->arrowDefence = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_stealth(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->stealth = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_swimming(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->swimming = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_thieving(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->thieving = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_lockpicking(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->lockpicking = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_bluff(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->bluff = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_assassin(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->assassin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_survival(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->survival = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_tracking(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->tracking = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_climbing(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->climbing = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_doctor(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->doctor = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_engineer(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->engineer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_weaponSmith(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->weaponSmith = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_armourSmith(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->armourSmith = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_bowSmith(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->bowSmith = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_robotics(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->robotics = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_science(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->science = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_labouring(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->labouring = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_farming(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->farming = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_cooking(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->cooking = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_dodging(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->dodging = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_friendlyFire(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->friendlyFire = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_katanas(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->katanas = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_sabres(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->sabres = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_hackers(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->hackers = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_blunt(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->blunt = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_heavyWeapons(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->heavyWeapons = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_unarmed(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->unarmed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_bows(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->bows = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_turrets(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->turrets = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_polearms(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->polearms = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_currentItemMaximumJuryRig(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->currentItemMaximumJuryRig = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set___meleeAttack(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->__meleeAttack = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set__meleeDefence(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->_meleeDefence = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set__defensiveMode(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->_defensiveMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharStats_set_rangedMode(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->rangedMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharStats_set_tauntMode(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->tauntMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharStats_set__holdPositionMode(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->_holdPositionMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharStats_set_passiveCombatMode(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->passiveCombatMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharStats_set_holdLocation(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    readVector3(L, 2, instance->holdLocation);
    return 0;
}

static int CharStats_set_warriorSpirit(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->warriorSpirit = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_derivedSpirit(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->derivedSpirit = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_aggression(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->aggression = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_goodness(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->goodness = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_evilness(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->evilness = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_longestReachingAttack(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->longestReachingAttack = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_STUBBOURNESS(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->STUBBOURNESS = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_PROFESSIONALNESS(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->PROFESSIONALNESS = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_HOLDING_POSITION(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->HOLDING_POSITION = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_IMMEDIACY(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->IMMEDIACY = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_IMMEDIACY_MAX_RANGE(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->IMMEDIACY_MAX_RANGE = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_MANLINESS(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->MANLINESS = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_MURDEROUS(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->MURDEROUS = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set__stealthXPMultForGUI(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->_stealthXPMultForGUI = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_stealthXPTooManyCooksPenalty(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->stealthXPTooManyCooksPenalty = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_currentOperatingMachineHungerRate(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->currentOperatingMachineHungerRate = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_moveSpeed(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->moveSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_weaponWeightSpeedMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->weaponWeightSpeedMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_weaponWeightXPMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->weaponWeightXPMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_attackSpeed(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->attackSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_blockSpeed(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->blockSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_encumbranceMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->encumbranceMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_xp(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->xp = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_freeAttributePoints(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->freeAttributePoints = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CharStats_set_cutDamageMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->cutDamageMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_bluntDamageMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->bluntDamageMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_bleedDamageMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->bleedDamageMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_pierceDamageMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->pierceDamageMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_cutDamageMin(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->cutDamageMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_bluntDamageMin(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->bluntDamageMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_bonusRobots(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->bonusRobots = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_bonusHumans(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->bonusHumans = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_bonusAnimals(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->bonusAnimals = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_bonusArmourPenetration(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->bonusArmourPenetration = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_currentWeaponType(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->currentWeaponType = (WeaponCategory)luaL_checkinteger(L, 2);
    return 0;
}

static int CharStats_set_currentWeaponLength(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->currentWeaponLength = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharStats_set_weapon(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->weapon = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int CharStats_set_weaponWeight(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    instance->weaponWeight = (float)luaL_checknumber(L, 2);
    return 0;
}

int CharStatsBinding::getWeatherProtection(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    WeatherAffecting w = (WeatherAffecting)luaL_checkinteger(L, 2);
    float result = instance->getWeatherProtection(w);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::_CONSTRUCTOR(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    CharStats* result = instance->_CONSTRUCTOR();
    return pushObject<CharStats>(L, result, CharStatsBinding::getMetatableName());
}

int CharStatsBinding::unarmedEncumbrancePenalty(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    int result = instance->unarmedEncumbrancePenalty();
    lua_pushinteger(L, result);
    return 1;
}

int CharStatsBinding::skillBonusUnarmed_forGUI(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    bool factorEnvironment = lua_toboolean(L, 2) != 0;
    int result = instance->skillBonusUnarmed_forGUI(factorEnvironment);
    lua_pushinteger(L, result);
    return 1;
}

int CharStatsBinding::skillBonusAttack_melee(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    bool factorEnvironment = lua_toboolean(L, 2) != 0;
    int result = instance->skillBonusAttack_melee(factorEnvironment);
    lua_pushinteger(L, result);
    return 1;
}

int CharStatsBinding::skillBonusAttack_unarmed(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    bool factorEnvironment = lua_toboolean(L, 2) != 0;
    int result = instance->skillBonusAttack_unarmed(factorEnvironment);
    lua_pushinteger(L, result);
    return 1;
}

int CharStatsBinding::skillBonusDefence(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    bool factorEnvironment = lua_toboolean(L, 2) != 0;
    int result = instance->skillBonusDefence(factorEnvironment);
    lua_pushinteger(L, result);
    return 1;
}

int CharStatsBinding::serialise(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->serialise(data);
    return 0;
}

int CharStatsBinding::updateStats(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    GameData* statData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->updateStats(statData);
    return 0;
}

int CharStatsBinding::init(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    MedicalSystem* _med = checkObject<MedicalSystem>(L, 3, MedicalSystemBinding::getMetatableName());
    Character* charact = checkObject<Character>(L, 4, CharacterBinding::getMetatableName());
    instance->init(data, _med, charact);
    return 0;
}

int CharStatsBinding::_NV_init(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    MedicalSystem* _med = checkObject<MedicalSystem>(L, 3, MedicalSystemBinding::getMetatableName());
    Character* charact = checkObject<Character>(L, 4, CharacterBinding::getMetatableName());
    instance->_NV_init(data, _med, charact);
    return 0;
}

int CharStatsBinding::_randomiseStats(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float amount = (float)luaL_checknumber(L, 2);
    instance->_randomiseStats(amount);
    return 0;
}

int CharStatsBinding::getGUIData(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIData(panel, category);
    return 0;
}

int CharStatsBinding::getGUIDataForMainInfo(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    bool combatMode = lua_toboolean(L, 4) != 0;
    instance->getGUIDataForMainInfo(datapanel, category, combatMode);
    return 0;
}

int CharStatsBinding::getGUIStatsDisplayMode(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    CharStats::GUIStatsDisplayMode result = instance->getGUIStatsDisplayMode();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharStatsBinding::periodicUpdate(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    instance->periodicUpdate();
    return 0;
}

int CharStatsBinding::_NV_periodicUpdate(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    instance->_NV_periodicUpdate();
    return 0;
}

int CharStatsBinding::calculateStumbleThresholdDamageAmount(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->calculateStumbleThresholdDamageAmount();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::setEquipmentStatBonuses(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

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
    instance->setEquipmentStatBonuses(athlet, combatSpd, attack, def, _stealth, _unarmed, _dodge, fistdamage, perception, ranged, dexmult, assmult, damagemult);
    return 0;
}

int CharStatsBinding::getOverallSkillLevel_0_100(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->getOverallSkillLevel_0_100();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getStat(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    StatsEnumerated what = (StatsEnumerated)luaL_checkinteger(L, 2);
    bool unmodified = lua_toboolean(L, 3) != 0;
    float result = instance->getStat(what, unmodified);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getStatMultiplier(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    StatsEnumerated st = (StatsEnumerated)luaL_checkinteger(L, 2);
    float result = instance->getStatMultiplier(st);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getStatMultiplierForGUI(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    StatsEnumerated st = (StatsEnumerated)luaL_checkinteger(L, 2);
    std::string result = instance->getStatMultiplierForGUI(st);
    lua_pushstring(L, result.c_str());
    return 1;
}

int CharStatsBinding::getStatPenaltiesTotalForGUI(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    const std::string statName = luaL_checkstring(L, 2);
    StatsEnumerated stat = (StatsEnumerated)luaL_checkinteger(L, 3);
    int result = instance->getStatPenaltiesTotalForGUI(statName, stat);
    lua_pushinteger(L, result);
    return 1;
}

int CharStatsBinding::xpStat_timeBased(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    StatsEnumerated st = (StatsEnumerated)luaL_checkinteger(L, 2);
    instance->xpStat_timeBased(st);
    return 0;
}

int CharStatsBinding::xpStat_eventBased(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    StatsEnumerated st = (StatsEnumerated)luaL_checkinteger(L, 2);
    float amount = (float)luaL_checknumber(L, 3);
    instance->xpStat_eventBased(st, amount);
    return 0;
}

int CharStatsBinding::xpDodgeEvent(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float enemySkill = (float)luaL_checknumber(L, 2);
    bool successful = lua_toboolean(L, 3) != 0;
    instance->xpDodgeEvent(enemySkill, successful);
    return 0;
}

int CharStatsBinding::strengthActual(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->strengthActual();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::strengthBase(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->strengthBase();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::_NV_strengthBase(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->_NV_strengthBase();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::dexterityBase(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->dexterityBase();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::dexterityActual(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->dexterityActual();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::toughness(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->toughness();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getToughnessMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->getToughnessMult();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getRangedFriendlyFireAvoidanceChance(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->getRangedFriendlyFireAvoidanceChance();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getRangedAccuracyMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    StatsEnumerated stat = (StatsEnumerated)luaL_checkinteger(L, 2);
    float result = instance->getRangedAccuracyMult(stat);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getReloadSkill(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    StatsEnumerated stat = (StatsEnumerated)luaL_checkinteger(L, 2);
    float result = instance->getReloadSkill(stat);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::animalRecruitReduceStats(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    instance->animalRecruitReduceStats();
    return 0;
}

int CharStatsBinding::getMeleeDefence(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    bool includeDefensiveMode = lua_toboolean(L, 2) != 0;
    float result = instance->getMeleeDefence(includeDefensiveMode);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getDodge(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    bool bonuses = lua_toboolean(L, 2) != 0;
    float result = instance->getDodge(bonuses);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getDodgePenalty_encumbrance(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->getDodgePenalty_encumbrance();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getDodgePenalty_injuries(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->getDodgePenalty_injuries();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getDodgePenalty_gear(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->getDodgePenalty_gear();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getMeleeDefence_melee(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    bool includeDefensiveMode = lua_toboolean(L, 2) != 0;
    float result = instance->getMeleeDefence_melee(includeDefensiveMode);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getMeleeAttack(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->getMeleeAttack();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getMeleeAttack_unarmed(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    bool bonuses = lua_toboolean(L, 2) != 0;
    float result = instance->getMeleeAttack_unarmed(bonuses);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getMeleeAttack_melee(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->getMeleeAttack_melee();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::_getMeleeAttackBase(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->_getMeleeAttackBase();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getMaxHealAmount(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    Item* equipment = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    Building* bed = checkObject<Building>(L, 3, BuildingBinding::getMetatableName());
    bool isRobot = lua_toboolean(L, 4) != 0;
    float result = instance->getMaxHealAmount(equipment, bed, isRobot);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::isDefensiveMode(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    bool result = instance->isDefensiveMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharStatsBinding::holdPositionMode(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    bool result = instance->holdPositionMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharStatsBinding::setHoldLocation(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    Ogre::Vector3 v;
    readVector3(L, 2, v);
    instance->setHoldLocation(v);
    return 0;
}

int CharStatsBinding::clearHoldLocation(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    instance->clearHoldLocation();
    return 0;
}

int CharStatsBinding::getBashAnimation(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float range = (float)luaL_checknumber(L, 2);
    CombatTechniqueData* result = instance->getBashAnimation(range);
    return pushObject<CombatTechniqueData>(L, result, CombatTechniqueDataBinding::getMetatableName());
}

int CharStatsBinding::chooseAttack(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float range = (float)luaL_checknumber(L, 2);
    float weaponReach = (float)luaL_checknumber(L, 3);
    CombatTechniqueData* lastAttack = checkObject<CombatTechniqueData>(L, 4, CombatTechniqueDataBinding::getMetatableName());
    bool opponentIsStationary = lua_toboolean(L, 5) != 0;
    CombatTechniqueData* result = instance->chooseAttack(range, weaponReach, lastAttack, opponentIsStationary);
    return pushObject<CombatTechniqueData>(L, result, CombatTechniqueDataBinding::getMetatableName());
}

int CharStatsBinding::chooseBlock(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    CutDirection dir = (CutDirection)luaL_checkinteger(L, 2);
    float opponentAttackSkill = (float)luaL_checknumber(L, 3);
    CutOrigination from = (CutOrigination)luaL_checkinteger(L, 4);
    Character* opponent = checkObject<Character>(L, 5, CharacterBinding::getMetatableName());
    CombatTechniqueData* result = instance->chooseBlock(dir, opponentAttackSkill, from, opponent);
    return pushObject<CombatTechniqueData>(L, result, CombatTechniqueDataBinding::getMetatableName());
}

int CharStatsBinding::calculateStumbleBlockTimer(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float stumbleForce = (float)luaL_checknumber(L, 2);
    float result = instance->calculateStumbleBlockTimer(stumbleForce);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::calculateTechniqueInegrityCheckTimer(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->calculateTechniqueInegrityCheckTimer();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::calculateToughnessDamageResistanceMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->calculateToughnessDamageResistanceMult();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::calculateToughnessWoundDegenerationRate(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->calculateToughnessWoundDegenerationRate();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getAttackChance(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->getAttackChance();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getAttackCuttingDamage(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->getAttackCuttingDamage();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getAttackBluntPower(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->getAttackBluntPower();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getAttackBleedDamageMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->getAttackBleedDamageMult();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getAttackPierceDamage(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->getAttackPierceDamage();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getTotalAttackDamageFor(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    Character* target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    Damages result = instance->getTotalAttackDamageFor(target);
    return pushValue<Damages>(L, result, DamagesBinding::getMetatableName());
}

int CharStatsBinding::getEquippedWeaponSkill(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->getEquippedWeaponSkill();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::_NV_getEquippedWeaponSkill(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->_NV_getEquippedWeaponSkill();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getSkillDifferenceRatio(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float mine = (float)luaL_checknumber(L, 2);
    float his = (float)luaL_checknumber(L, 3);
    float result = instance->getSkillDifferenceRatio(mine, his);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::calculateDeadTime(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    CharStats::DeadTimeState state = (CharStats::DeadTimeState)luaL_checkinteger(L, 2);
    float result = instance->calculateDeadTime(state);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::xpToughness_RagdollEvent(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    instance->xpToughness_RagdollEvent();
    return 0;
}

int CharStatsBinding::xpToughness_GetUpEvent(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    instance->xpToughness_GetUpEvent();
    return 0;
}

int CharStatsBinding::xpToughness_PunchSomething(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    HitMaterialType mat = (HitMaterialType)luaL_checkinteger(L, 2);
    instance->xpToughness_PunchSomething(mat);
    return 0;
}

int CharStatsBinding::xpFirstAid(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    Character* patient = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float time = (float)luaL_checknumber(L, 3);
    StatsEnumerated medicStat = (StatsEnumerated)luaL_checkinteger(L, 4);
    instance->xpFirstAid(patient, time, medicStat);
    return 0;
}

int CharStatsBinding::xpRunning(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float time = (float)luaL_checknumber(L, 2);
    float speed = (float)luaL_checknumber(L, 3);
    instance->xpRunning(time, speed);
    return 0;
}

int CharStatsBinding::xpStealth(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float time = (float)luaL_checknumber(L, 2);
    bool enemiesAbout = lua_toboolean(L, 3) != 0;
    YesNoMaybe seen = *checkObject<YesNoMaybe>(L, 4, YesNoMaybeBinding::getMetatableName());
    bool isMoving = lua_toboolean(L, 5) != 0;
    instance->xpStealth(time, enemiesAbout, seen, isMoving);
    return 0;
}

int CharStatsBinding::xpStealthHearCheckEvent(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    bool enemiesAbout = lua_toboolean(L, 2) != 0;
    bool trespassing = lua_toboolean(L, 3) != 0;
    bool seen = lua_toboolean(L, 4) != 0;
    instance->xpStealthHearCheckEvent(enemiesAbout, trespassing, seen);
    return 0;
}

int CharStatsBinding::stealthXPMultForGUI(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    StringPair result = instance->stealthXPMultForGUI();
    return pushValue<StringPair>(L, result, StringPairBinding::getMetatableName());
}

int CharStatsBinding::xpMassCombat(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    instance->xpMassCombat();
    return 0;
}

int CharStatsBinding::xpEngineering(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->xpEngineering(time);
    return 0;
}

int CharStatsBinding::xpLockpicking(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    int lockLevel = (int)luaL_checkinteger(L, 2);
    bool success = lua_toboolean(L, 3) != 0;
    instance->xpLockpicking(lockLevel, success);
    return 0;
}

int CharStatsBinding::xpGeneral(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float time = (float)luaL_checknumber(L, 2);
    float mult = (float)luaL_checknumber(L, 3);
    StatsEnumerated what = (StatsEnumerated)luaL_checkinteger(L, 4);
    instance->xpGeneral(time, mult, what);
    return 0;
}

int CharStatsBinding::calculateAthleticsXPMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float speed = (float)luaL_checknumber(L, 2);
    float result = instance->calculateAthleticsXPMult(speed);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::calculateStrengthXPMultFromWalking(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->calculateStrengthXPMultFromWalking();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::setWeapon(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    Weapon* _weapon = checkObject<Weapon>(L, 2, WeaponBinding::getMetatableName());
    instance->setWeapon(_weapon);
    return 0;
}

int CharStatsBinding::isUnarmed(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    bool result = instance->isUnarmed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharStatsBinding::getWeaponWeightXPBonus(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->getWeaponWeightXPBonus();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getAttackSpeed(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->getAttackSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getBlockSpeed(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->getBlockSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getMaxRunSpeed(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->getMaxRunSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getCurrentWeaponLength(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->getCurrentWeaponLength();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getStealthSkill01(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    bool modded = lua_toboolean(L, 2) != 0;
    float result = instance->getStealthSkill01(modded);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getAttackSuccessChanceSkill(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->getAttackSuccessChanceSkill();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::getEncumbranceMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->getEncumbranceMult();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::calculateHungerMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->calculateHungerMult();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::calculateTheoreticalIdealMaxRunSpeed(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->calculateTheoreticalIdealMaxRunSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::calculateWeaponWeightXPMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float weaponWeight = (float)luaL_checknumber(L, 2);
    float result = instance->calculateWeaponWeightXPMult(weaponWeight);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::hasWeapon(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    bool result = instance->hasWeapon();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharStatsBinding::calculateMaxStealthSpeed(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->calculateMaxStealthSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::_calculateMaxSwimSpeed(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->_calculateMaxSwimSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::calculateSwimSpeed(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->calculateSwimSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::calculateDodgeChance(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float versus = (float)luaL_checknumber(L, 2);
    bool stumbling = lua_toboolean(L, 3) != 0;
    float result = instance->calculateDodgeChance(versus, stumbling);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::calculateMaxRunSpeed(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    instance->calculateMaxRunSpeed();
    return 0;
}

int CharStatsBinding::_calculateEncumberanceMult(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float result = instance->_calculateEncumberanceMult();
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::_calculateWeaponWeightSpeedMultiplier(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float weaponWeight = (float)luaL_checknumber(L, 2);
    instance->_calculateWeaponWeightSpeedMultiplier(weaponWeight);
    return 0;
}

int CharStatsBinding::currentWeaponHand(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    LeftRight result = instance->currentWeaponHand();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int CharStatsBinding::calculateAttackOrBlockSpeed(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float weaponWeightSpeedMult = (float)luaL_checknumber(L, 2);
    float attackOrBlockSkill = (float)luaL_checknumber(L, 3);
    bool isBlock = lua_toboolean(L, 4) != 0;
    float result = instance->calculateAttackOrBlockSpeed(weaponWeightSpeedMult, attackOrBlockSkill, isBlock);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::_calculateBlockChance(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float versus = (float)luaL_checknumber(L, 2);
    float result = instance->_calculateBlockChance(versus);
    lua_pushnumber(L, result);
    return 1;
}

int CharStatsBinding::_recalculateStats(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    instance->_recalculateStats();
    return 0;
}

int CharStatsBinding::_NV__recalculateStats(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    instance->_NV__recalculateStats();
    return 0;
}

int CharStatsBinding::setEquippedWeaponSkill(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float v = (float)luaL_checknumber(L, 2);
    instance->setEquippedWeaponSkill(v);
    return 0;
}

int CharStatsBinding::_NV_setEquippedWeaponSkill(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    float v = (float)luaL_checknumber(L, 2);
    instance->_NV_setEquippedWeaponSkill(v);
    return 0;
}

int CharStatsBinding::_DESTRUCTOR(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 60: void printStealthStats(...) - non-string reference arg
  line 61: void getStealthTooltip(...) - unsupported arg type
  line 62: void printRunSpeedStatMax(...) - non-string reference arg
  line 63: void getAthleticsTooltip(...) - unsupported arg type
  line 65: std::string formatWholeStatStringWithBonuses(...) - overloaded method
  line 66: std::string formatWholeStatStringWithBonuses(...) - overloaded method
  line 80: float& getStatRef(...) - reference return type
  line 82: std::string getStatName(...) - static method
  line 85: bool getStatPenaltiesForGUI(...) - unsupported arg type
  line 143: float& getMeleeAttackRef(...) - reference return type
  line 144: void _chooseAttacks(...) - unsupported arg type
  line 177: const std::string& getPainAnim(...) - reference return type
  line 209: void xpMelee(...) - non-string reference arg
  line 223: void xpTraining(...) - non-string reference arg
  line 237: float _convertWeaponWeightToBluntMultiplier(...) - static method
  line 238: float _convertBluntMultiplierToWeaponWeight(...) - static method
  line 241: void printExertionHungerMultTooltip(...) - unsupported arg type
  line 265: void setupCombatTechniques(...) - static method
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - CharStats_get_pCurrentWeaponSkill: float* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 44: _weatherProtections (std::map<WeatherAffecting, float, std::less<WeatherAffecting>, Ogre::STLAllocator<std::pair<WeatherAffecting const, float>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 281: bonusRaces (std::map<GameData*, float, std::less<GameData*>, Ogre::STLAllocator<std::pair<GameData*const, float>, Ogre::GeneralAllocPolicy > >) - unsupported type
*/

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



static int CharStats_getTotalAttackDamageFor(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    Character* target = nullptr;
    if (lua_gettop(L) >= 2 && !lua_isnil(L, 2)) {
        target = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    }
    Damages result = instance->getTotalAttackDamageFor(target);
    return pushValue<Damages>(L, result, DamagesBinding::getMetatableName());
}


static int CharStats_get__weatherProtections(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    return pushObject<WeatherProtectionsMapBinding::MapType>(L, &instance->_weatherProtections, "std::map<WeatherAffecting, float>");
}


static int CharStats_get_bonusRaces(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    return pushObject<BonusRacesMapBinding::MapType>(L, &instance->bonusRaces, "std::map<GameData*, float>");
}


static int CharStats_set__weatherProtections(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    if (auto* other = testObject<WeatherProtectionsMapBinding::MapType>(L, 2, "std::map<WeatherAffecting, float>"))
    {
        instance->_weatherProtections = *other;
        return 0;
    }
    if (lua_istable(L, 2))
    {
        instance->_weatherProtections.clear();
        lua_pushnil(L);
        while (lua_next(L, 2) != 0)
        {
            WeatherAffecting key = (WeatherAffecting)luaL_checkinteger(L, -2);
            float val = (float)luaL_checknumber(L, -1);
            instance->_weatherProtections[key] = val;
            lua_pop(L, 1);
        }
        return 0;
    }
    return luaL_error(L, "Expected table or std::map<WeatherAffecting, float> for _weatherProtections");
}


static int CharStats_set_bonusRaces(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    if (auto* other = testObject<BonusRacesMapBinding::MapType>(L, 2, "std::map<GameData*, float>"))
    {
        instance->bonusRaces = *other;
        return 0;
    }
    if (lua_istable(L, 2))
    {
        instance->bonusRaces.clear();
        lua_pushnil(L);
        while (lua_next(L, 2) != 0)
        {
            GameData* key = checkObject<GameData>(L, -2, GameDataBinding::getMetatableName());
            float val = (float)luaL_checknumber(L, -1);
            instance->bonusRaces[key] = val;
            lua_pop(L, 1);
        }
        return 0;
    }
    return luaL_error(L, "Expected table or std::map<GameData*, float> for bonusRaces");
}


static int CharStats_set_pCurrentWeaponSkill(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    float val = (float)luaL_checknumber(L, 2);
    instance->pCurrentWeaponSkill = &val;
    return 0;
}


static int OwnedStringPair_gc(lua_State* L)
{
    void** ud = (void**)lua_touserdata(L, 1);
    if (ud && *ud)
    {
        delete (StringPair*)*ud;
        *ud = nullptr;
    }
    return 0;
}


int CharStatsBinding::_chooseAttacks(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    FitnessSelector<CombatTechniqueData*>* possibleAttacks = FitnessSelectorBinding<CombatTechniqueData*>::get(L, 2);
    if (!possibleAttacks) return luaL_error(L, "Expected FitnessSelector<CombatTechniqueData*>");
    float range = (float)luaL_checknumber(L, 3);
    float weaponReach = (float)luaL_checknumber(L, 4);
    CombatTechniqueData* lastAttack = nullptr;
    if (lua_gettop(L) >= 5 && !lua_isnil(L, 5)) {
        lastAttack = checkObject<CombatTechniqueData>(L, 5, CombatTechniqueDataBinding::getMetatableName());
    }
    bool opponentIsStationary = lua_toboolean(L, 6) != 0;
    bool skipMedicals = lua_toboolean(L, 7) != 0;
    WeaponCategory _weaponType = (WeaponCategory)luaL_checkinteger(L, 8);
    float _weaponSkill = (float)luaL_checknumber(L, 9);
    
    instance->_chooseAttacks(*possibleAttacks, range, weaponReach, lastAttack, opponentIsStationary, skipMedicals, _weaponType, _weaponSkill);
    return 0;
}


int CharStatsBinding::_convertBluntMultiplierToWeaponWeight(lua_State* L)
{
    int idx = 1;
    if (lua_isuserdata(L, 1)) idx = 2;
    float blunt = (float)luaL_checknumber(L, idx);
    float result = CharStats::_convertBluntMultiplierToWeaponWeight(blunt);
    lua_pushnumber(L, result);
    return 1;
}


int CharStatsBinding::_convertWeaponWeightToBluntMultiplier(lua_State* L)
{
    int idx = 1;
    if (lua_isuserdata(L, 1)) idx = 2;
    float weaponWeight = (float)luaL_checknumber(L, idx);
    float result = CharStats::_convertWeaponWeightToBluntMultiplier(weaponWeight);
    lua_pushnumber(L, result);
    return 1;
}


int CharStatsBinding::formatWholeStatStringWithBonuses(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    int top = lua_gettop(L);
    if (top >= 3) {
        int base = (int)luaL_checkinteger(L, 2);
        int current = (int)luaL_checkinteger(L, 3);
        std::string result = instance->formatWholeStatStringWithBonuses(base, current);
        lua_pushlstring(L, result.c_str(), result.size());
        return 1;
    } else {
        StatsEnumerated stat = (StatsEnumerated)luaL_checkinteger(L, 2);
        std::string result = instance->formatWholeStatStringWithBonuses(stat);
        lua_pushlstring(L, result.c_str(), result.size());
        return 1;
    }
}


int CharStatsBinding::getAthletics(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->_athletics);
    return 1;
}


int CharStatsBinding::getAthleticsTooltip(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lektor<StringPair>* dats = checkObject<lektor<StringPair>>(L, 2, LektorValueReadOnlyBinding<StringPair>::metaName);
    if (!dats) return luaL_error(L, "Expected lektor<StringPair>");
    instance->getAthleticsTooltip(dats);
    return 0;
}


int CharStatsBinding::getAttacks(lua_State* L)
{
    static lektor<CombatTechniqueData*>* pAttacks = (lektor<CombatTechniqueData*>*)( (char*)GetModuleHandleA(NULL) + 0x200EF78 );
    return pushObject<lektor<CombatTechniqueData*>>(L, pAttacks, "lektor<CombatTechniqueData*>");
}


int CharStatsBinding::getBlocks(lua_State* L)
{
    static lektor<CombatTechniqueData*>* pBlocks = (lektor<CombatTechniqueData*>*)( (char*)GetModuleHandleA(NULL) + 0x200EF90 );
    return pushObject<lektor<CombatTechniqueData*>>(L, pBlocks, "lektor<CombatTechniqueData*>");
}


int CharStatsBinding::getDexterity(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->dexterityActual());
    return 1;
}


int CharStatsBinding::getDexterityBase(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->dexterityBase());
    return 1;
}


int CharStatsBinding::getMeleeAttackRef(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    float& result = instance->getMeleeAttackRef();
    lua_pushnumber(L, result);
    return 1;
}


int CharStatsBinding::getPainAnim(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    GameData* anatomyHit = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    const std::string& result = instance->getPainAnim(anatomyHit);
    lua_pushlstring(L, result.c_str(), result.size());
    return 1;
}


int CharStatsBinding::getPerception(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->perception);
    return 1;
}


int CharStatsBinding::getStatName(lua_State* L)
{
    int idx = 1;
    if (lua_isuserdata(L, 1)) idx = 2;
    StatsEnumerated what = (StatsEnumerated)luaL_checkinteger(L, idx);
    std::string result = CharStats::getStatName(what);
    lua_pushlstring(L, result.c_str(), result.size());
    return 1;
}


int CharStatsBinding::getStatPenaltiesForGUI(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    std::string statName = luaL_checkstring(L, 2);
    StatsEnumerated stat = (StatsEnumerated)luaL_checkinteger(L, 3);
    lektor<StringPair>* dats = checkObject<lektor<StringPair>>(L, 4, LektorValueReadOnlyBinding<StringPair>::metaName);
    if (!dats) return luaL_error(L, "Expected lektor<StringPair>");
    bool result = instance->getStatPenaltiesForGUI(statName, stat, *dats);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}


int CharStatsBinding::getStatRef(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    StatsEnumerated what = (StatsEnumerated)luaL_checkinteger(L, 2);
    float& result = instance->getStatRef(what);
    lua_pushnumber(L, result);
    return 1;
}


int CharStatsBinding::getStealthTooltip(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lektor<StringPair>* dats = checkObject<lektor<StringPair>>(L, 2, LektorValueReadOnlyBinding<StringPair>::metaName);
    if (!dats) return luaL_error(L, "Expected lektor<StringPair>");
    instance->getStealthTooltip(dats);
    return 0;
}


int CharStatsBinding::getStrength(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->strengthActual());
    return 1;
}


int CharStatsBinding::getStrengthBase(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->strengthBase());
    return 1;
}


int CharStatsBinding::getThieving(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->thieving);
    return 1;
}


int CharStatsBinding::getToughness(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lua_pushnumber(L, instance->toughness());
    return 1;
}


int CharStatsBinding::printExertionHungerMultTooltip(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    lektor<StringPair>* dats = checkObject<lektor<StringPair>>(L, 2, LektorValueReadOnlyBinding<StringPair>::metaName);
    if (!dats) return luaL_error(L, "Expected lektor<StringPair>");
    instance->printExertionHungerMultTooltip(dats);
    return 0;
}


int CharStatsBinding::printRunSpeedStatMax(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    std::string out;
    instance->printRunSpeedStatMax(out);
    lua_pushlstring(L, out.c_str(), out.size());
    return 1;
}


int CharStatsBinding::printStealthStats(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    std::string out;
    instance->printStealthStats(out);
    lua_pushlstring(L, out.c_str(), out.size());
    return 1;
}


int CharStatsBinding::setupCombatTechniques(lua_State* L)
{
    CharStats::setupCombatTechniques();
    return 0;
}


int CharStatsBinding::xpMelee(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    CharStats::DeadTimeState what = (CharStats::DeadTimeState)luaL_checkinteger(L, 2);
    Character* target = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    Damages* damage = checkObject<Damages>(L, 4, DamagesBinding::getMetatableName());
    instance->xpMelee(what, target, *damage);
    return 0;
}


int CharStatsBinding::xpTraining(lua_State* L)
{
    CharStats* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharStats is nil");
    float time = (float)luaL_checknumber(L, 2);
    float mult = (float)luaL_checknumber(L, 3);
    float statVal = (float)luaL_checknumber(L, 4);
    float upperLimit = (float)luaL_checknumber(L, 5);
    StatsEnumerated whatStatIsIt = (StatsEnumerated)luaL_checkinteger(L, 6);
    instance->xpTraining(time, mult, statVal, upperLimit, whatStatIsIt);
    lua_pushnumber(L, statVal);
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
        { "serialise", CharStatsBinding::serialise },
        { "updateStats", CharStatsBinding::updateStats },
        { "init", CharStatsBinding::init },
        { "_NV_init", CharStatsBinding::_NV_init },
        { "_randomiseStats", CharStatsBinding::_randomiseStats },
        { "getGUIData", CharStatsBinding::getGUIData },
        { "getGUIDataForMainInfo", CharStatsBinding::getGUIDataForMainInfo },
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
        { "strengthActual", CharStatsBinding::strengthActual },
        { "strengthBase", CharStatsBinding::strengthBase },
        { "_NV_strengthBase", CharStatsBinding::_NV_strengthBase },
        { "dexterityBase", CharStatsBinding::dexterityBase },
        { "dexterityActual", CharStatsBinding::dexterityActual },
        { "toughness", CharStatsBinding::toughness },
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
        { "getMaxHealAmount", CharStatsBinding::getMaxHealAmount },
        { "isDefensiveMode", CharStatsBinding::isDefensiveMode },
        { "holdPositionMode", CharStatsBinding::holdPositionMode },
        { "setHoldLocation", CharStatsBinding::setHoldLocation },
        { "clearHoldLocation", CharStatsBinding::clearHoldLocation },
        { "getBashAnimation", CharStatsBinding::getBashAnimation },
        { "chooseAttack", CharStatsBinding::chooseAttack },
        { "chooseBlock", CharStatsBinding::chooseBlock },
        { "calculateStumbleBlockTimer", CharStatsBinding::calculateStumbleBlockTimer },
        { "calculateTechniqueInegrityCheckTimer", CharStatsBinding::calculateTechniqueInegrityCheckTimer },
        { "calculateToughnessDamageResistanceMult", CharStatsBinding::calculateToughnessDamageResistanceMult },
        { "calculateToughnessWoundDegenerationRate", CharStatsBinding::calculateToughnessWoundDegenerationRate },
        { "getAttackChance", CharStatsBinding::getAttackChance },
        { "getAttackCuttingDamage", CharStatsBinding::getAttackCuttingDamage },
        { "getAttackBluntPower", CharStatsBinding::getAttackBluntPower },
        { "getAttackBleedDamageMult", CharStatsBinding::getAttackBleedDamageMult },
        { "getAttackPierceDamage", CharStatsBinding::getAttackPierceDamage },
        { "getTotalAttackDamageFor", CharStatsBinding::getTotalAttackDamageFor },
        { "getEquippedWeaponSkill", CharStatsBinding::getEquippedWeaponSkill },
        { "_NV_getEquippedWeaponSkill", CharStatsBinding::_NV_getEquippedWeaponSkill },
        { "getSkillDifferenceRatio", CharStatsBinding::getSkillDifferenceRatio },
        { "calculateDeadTime", CharStatsBinding::calculateDeadTime },
        { "xpToughness_RagdollEvent", CharStatsBinding::xpToughness_RagdollEvent },
        { "xpToughness_GetUpEvent", CharStatsBinding::xpToughness_GetUpEvent },
        { "xpToughness_PunchSomething", CharStatsBinding::xpToughness_PunchSomething },
        { "xpFirstAid", CharStatsBinding::xpFirstAid },
        { "xpRunning", CharStatsBinding::xpRunning },
        { "xpStealth", CharStatsBinding::xpStealth },
        { "xpStealthHearCheckEvent", CharStatsBinding::xpStealthHearCheckEvent },
        { "stealthXPMultForGUI", CharStatsBinding::stealthXPMultForGUI },
        { "xpMassCombat", CharStatsBinding::xpMassCombat },
        { "xpEngineering", CharStatsBinding::xpEngineering },
        { "xpLockpicking", CharStatsBinding::xpLockpicking },
        { "xpGeneral", CharStatsBinding::xpGeneral },
        { "calculateAthleticsXPMult", CharStatsBinding::calculateAthleticsXPMult },
        { "calculateStrengthXPMultFromWalking", CharStatsBinding::calculateStrengthXPMultFromWalking },
        { "setWeapon", CharStatsBinding::setWeapon },
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
                { "getStrength", CharStatsBinding::getStrength },
        { "getStrengthRaw", CharStatsBinding::getStrengthBase },
        { "getDexterity", CharStatsBinding::getDexterity },
        { "getDexterityRaw", CharStatsBinding::getDexterityBase },
        { "getToughness", CharStatsBinding::getToughness },
        { "getPerception", CharStatsBinding::getPerception },
        { "getAthletics", CharStatsBinding::getAthletics },
        { "getThieving", CharStatsBinding::getThieving },
        { "printStealthStats", CharStatsBinding::printStealthStats },
        { "printRunSpeedStatMax", CharStatsBinding::printRunSpeedStatMax },
        { "formatWholeStatStringWithBonuses", CharStatsBinding::formatWholeStatStringWithBonuses },
        { "getStatRef", CharStatsBinding::getStatRef },
        { "getStatName", CharStatsBinding::getStatName },
        { "getMeleeAttackRef", CharStatsBinding::getMeleeAttackRef },
        { "getPainAnim", CharStatsBinding::getPainAnim },
        { "xpMelee", CharStatsBinding::xpMelee },
        { "convertWeaponWeightToBluntMultiplier", CharStatsBinding::_convertWeaponWeightToBluntMultiplier },
        { "convertBluntMultiplierToWeaponWeight", CharStatsBinding::_convertBluntMultiplierToWeaponWeight },
        { "setupCombatTechniques", CharStatsBinding::setupCombatTechniques },
        { "getStealthTooltip", CharStatsBinding::getStealthTooltip },
        { "getAthleticsTooltip", CharStatsBinding::getAthleticsTooltip },
        { "getStatPenaltiesForGUI", CharStatsBinding::getStatPenaltiesForGUI },
        { "chooseAttacks", CharStatsBinding::_chooseAttacks },
        { "printExertionHungerMultTooltip", CharStatsBinding::printExertionHungerMultTooltip },
        { "xpTraining", CharStatsBinding::xpTraining },
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
    registerGetter(L, "medical", CharStats_get_medical);
    registerGetter(L, "me", CharStats_get_me);
    registerGetter(L, "athleticsMultiplier", CharStats_get_athleticsMultiplier);
    registerGetter(L, "combatSpeedMultiplier", CharStats_get_combatSpeedMultiplier);
    registerGetter(L, "_skillBonusAttack", CharStats_get__skillBonusAttack);
    registerGetter(L, "_skillBonusDefence", CharStats_get__skillBonusDefence);
    registerGetter(L, "skillBonusIndoors", CharStats_get_skillBonusIndoors);
    registerGetter(L, "skillBonusUnarmed", CharStats_get_skillBonusUnarmed);
    registerGetter(L, "skillBonusPerception", CharStats_get_skillBonusPerception);
    registerGetter(L, "ageMult", CharStats_get_ageMult);
    registerGetter(L, "skillMultDodge", CharStats_get_skillMultDodge);
    registerGetter(L, "skillMultStealth", CharStats_get_skillMultStealth);
    registerGetter(L, "skillMultAssassin", CharStats_get_skillMultAssassin);
    registerGetter(L, "skillMultDexterity", CharStats_get_skillMultDexterity);
    registerGetter(L, "skillMultDamage", CharStats_get_skillMultDamage);
    registerGetter(L, "fistInjuryEquipmentMult", CharStats_get_fistInjuryEquipmentMult);
    registerGetter(L, "skillMultRanged", CharStats_get_skillMultRanged);
    registerGetter(L, "_strength", CharStats_get__strength);
    registerGetter(L, "fitness", CharStats_get_fitness);
    registerGetter(L, "_dexterity", CharStats_get__dexterity);
    registerGetter(L, "perception", CharStats_get_perception);
    registerGetter(L, "_toughness", CharStats_get__toughness);
    registerGetter(L, "_athletics", CharStats_get__athletics);
    registerGetter(L, "medic", CharStats_get_medic);
    registerGetter(L, "massCombat", CharStats_get_massCombat);
    registerGetter(L, "arrowDefence", CharStats_get_arrowDefence);
    registerGetter(L, "stealth", CharStats_get_stealth);
    registerGetter(L, "swimming", CharStats_get_swimming);
    registerGetter(L, "thieving", CharStats_get_thieving);
    registerGetter(L, "lockpicking", CharStats_get_lockpicking);
    registerGetter(L, "bluff", CharStats_get_bluff);
    registerGetter(L, "assassin", CharStats_get_assassin);
    registerGetter(L, "survival", CharStats_get_survival);
    registerGetter(L, "tracking", CharStats_get_tracking);
    registerGetter(L, "climbing", CharStats_get_climbing);
    registerGetter(L, "doctor", CharStats_get_doctor);
    registerGetter(L, "engineer", CharStats_get_engineer);
    registerGetter(L, "weaponSmith", CharStats_get_weaponSmith);
    registerGetter(L, "armourSmith", CharStats_get_armourSmith);
    registerGetter(L, "bowSmith", CharStats_get_bowSmith);
    registerGetter(L, "robotics", CharStats_get_robotics);
    registerGetter(L, "science", CharStats_get_science);
    registerGetter(L, "labouring", CharStats_get_labouring);
    registerGetter(L, "farming", CharStats_get_farming);
    registerGetter(L, "cooking", CharStats_get_cooking);
    registerGetter(L, "dodging", CharStats_get_dodging);
    registerGetter(L, "friendlyFire", CharStats_get_friendlyFire);
    registerGetter(L, "katanas", CharStats_get_katanas);
    registerGetter(L, "sabres", CharStats_get_sabres);
    registerGetter(L, "hackers", CharStats_get_hackers);
    registerGetter(L, "blunt", CharStats_get_blunt);
    registerGetter(L, "heavyWeapons", CharStats_get_heavyWeapons);
    registerGetter(L, "unarmed", CharStats_get_unarmed);
    registerGetter(L, "bows", CharStats_get_bows);
    registerGetter(L, "turrets", CharStats_get_turrets);
    registerGetter(L, "polearms", CharStats_get_polearms);
    registerGetter(L, "currentItemMaximumJuryRig", CharStats_get_currentItemMaximumJuryRig);
    registerGetter(L, "__meleeAttack", CharStats_get___meleeAttack);
    registerGetter(L, "_meleeDefence", CharStats_get__meleeDefence);
    registerGetter(L, "_defensiveMode", CharStats_get__defensiveMode);
    registerGetter(L, "rangedMode", CharStats_get_rangedMode);
    registerGetter(L, "tauntMode", CharStats_get_tauntMode);
    registerGetter(L, "_holdPositionMode", CharStats_get__holdPositionMode);
    registerGetter(L, "passiveCombatMode", CharStats_get_passiveCombatMode);
    registerGetter(L, "holdLocation", CharStats_get_holdLocation);
    registerGetter(L, "warriorSpirit", CharStats_get_warriorSpirit);
    registerGetter(L, "derivedSpirit", CharStats_get_derivedSpirit);
    registerGetter(L, "aggression", CharStats_get_aggression);
    registerGetter(L, "goodness", CharStats_get_goodness);
    registerGetter(L, "evilness", CharStats_get_evilness);
    registerGetter(L, "longestReachingAttack", CharStats_get_longestReachingAttack);
    registerGetter(L, "STUBBOURNESS", CharStats_get_STUBBOURNESS);
    registerGetter(L, "PROFESSIONALNESS", CharStats_get_PROFESSIONALNESS);
    registerGetter(L, "HOLDING_POSITION", CharStats_get_HOLDING_POSITION);
    registerGetter(L, "IMMEDIACY", CharStats_get_IMMEDIACY);
    registerGetter(L, "IMMEDIACY_MAX_RANGE", CharStats_get_IMMEDIACY_MAX_RANGE);
    registerGetter(L, "MANLINESS", CharStats_get_MANLINESS);
    registerGetter(L, "MURDEROUS", CharStats_get_MURDEROUS);
    registerGetter(L, "_stealthXPMultForGUI", CharStats_get__stealthXPMultForGUI);
    registerGetter(L, "stealthXPTooManyCooksPenalty", CharStats_get_stealthXPTooManyCooksPenalty);
    registerGetter(L, "currentOperatingMachineHungerRate", CharStats_get_currentOperatingMachineHungerRate);
    registerGetter(L, "moveSpeed", CharStats_get_moveSpeed);
    registerGetter(L, "weaponWeightSpeedMult", CharStats_get_weaponWeightSpeedMult);
    registerGetter(L, "weaponWeightXPMult", CharStats_get_weaponWeightXPMult);
    registerGetter(L, "attackSpeed", CharStats_get_attackSpeed);
    registerGetter(L, "blockSpeed", CharStats_get_blockSpeed);
    registerGetter(L, "encumbranceMult", CharStats_get_encumbranceMult);
    registerGetter(L, "xp", CharStats_get_xp);
    registerGetter(L, "freeAttributePoints", CharStats_get_freeAttributePoints);
    registerGetter(L, "cutDamageMult", CharStats_get_cutDamageMult);
    registerGetter(L, "bluntDamageMult", CharStats_get_bluntDamageMult);
    registerGetter(L, "bleedDamageMult", CharStats_get_bleedDamageMult);
    registerGetter(L, "pierceDamageMult", CharStats_get_pierceDamageMult);
    registerGetter(L, "cutDamageMin", CharStats_get_cutDamageMin);
    registerGetter(L, "bluntDamageMin", CharStats_get_bluntDamageMin);
    registerGetter(L, "bonusRobots", CharStats_get_bonusRobots);
    registerGetter(L, "bonusHumans", CharStats_get_bonusHumans);
    registerGetter(L, "bonusAnimals", CharStats_get_bonusAnimals);
    registerGetter(L, "bonusArmourPenetration", CharStats_get_bonusArmourPenetration);
    registerGetter(L, "currentWeaponType", CharStats_get_currentWeaponType);
    registerGetter(L, "pCurrentWeaponSkill", CharStats_get_pCurrentWeaponSkill);
    registerGetter(L, "currentWeaponLength", CharStats_get_currentWeaponLength);
    registerGetter(L, "weapon", CharStats_get_weapon);
    registerGetter(L, "weaponWeight", CharStats_get_weaponWeight);
    registerGetter(L, "_weatherProtections", CharStats_get__weatherProtections);
    registerGetter(L, "bonusRaces", CharStats_get_bonusRaces);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "medical", CharStats_set_medical);
    registerSetter(L, "me", CharStats_set_me);
    registerSetter(L, "athleticsMultiplier", CharStats_set_athleticsMultiplier);
    registerSetter(L, "combatSpeedMultiplier", CharStats_set_combatSpeedMultiplier);
    registerSetter(L, "_skillBonusAttack", CharStats_set__skillBonusAttack);
    registerSetter(L, "_skillBonusDefence", CharStats_set__skillBonusDefence);
    registerSetter(L, "skillBonusIndoors", CharStats_set_skillBonusIndoors);
    registerSetter(L, "skillBonusUnarmed", CharStats_set_skillBonusUnarmed);
    registerSetter(L, "skillBonusPerception", CharStats_set_skillBonusPerception);
    registerSetter(L, "ageMult", CharStats_set_ageMult);
    registerSetter(L, "skillMultDodge", CharStats_set_skillMultDodge);
    registerSetter(L, "skillMultStealth", CharStats_set_skillMultStealth);
    registerSetter(L, "skillMultAssassin", CharStats_set_skillMultAssassin);
    registerSetter(L, "skillMultDexterity", CharStats_set_skillMultDexterity);
    registerSetter(L, "skillMultDamage", CharStats_set_skillMultDamage);
    registerSetter(L, "fistInjuryEquipmentMult", CharStats_set_fistInjuryEquipmentMult);
    registerSetter(L, "skillMultRanged", CharStats_set_skillMultRanged);
    registerSetter(L, "_strength", CharStats_set__strength);
    registerSetter(L, "fitness", CharStats_set_fitness);
    registerSetter(L, "_dexterity", CharStats_set__dexterity);
    registerSetter(L, "perception", CharStats_set_perception);
    registerSetter(L, "_toughness", CharStats_set__toughness);
    registerSetter(L, "_athletics", CharStats_set__athletics);
    registerSetter(L, "medic", CharStats_set_medic);
    registerSetter(L, "massCombat", CharStats_set_massCombat);
    registerSetter(L, "arrowDefence", CharStats_set_arrowDefence);
    registerSetter(L, "stealth", CharStats_set_stealth);
    registerSetter(L, "swimming", CharStats_set_swimming);
    registerSetter(L, "thieving", CharStats_set_thieving);
    registerSetter(L, "lockpicking", CharStats_set_lockpicking);
    registerSetter(L, "bluff", CharStats_set_bluff);
    registerSetter(L, "assassin", CharStats_set_assassin);
    registerSetter(L, "survival", CharStats_set_survival);
    registerSetter(L, "tracking", CharStats_set_tracking);
    registerSetter(L, "climbing", CharStats_set_climbing);
    registerSetter(L, "doctor", CharStats_set_doctor);
    registerSetter(L, "engineer", CharStats_set_engineer);
    registerSetter(L, "weaponSmith", CharStats_set_weaponSmith);
    registerSetter(L, "armourSmith", CharStats_set_armourSmith);
    registerSetter(L, "bowSmith", CharStats_set_bowSmith);
    registerSetter(L, "robotics", CharStats_set_robotics);
    registerSetter(L, "science", CharStats_set_science);
    registerSetter(L, "labouring", CharStats_set_labouring);
    registerSetter(L, "farming", CharStats_set_farming);
    registerSetter(L, "cooking", CharStats_set_cooking);
    registerSetter(L, "dodging", CharStats_set_dodging);
    registerSetter(L, "friendlyFire", CharStats_set_friendlyFire);
    registerSetter(L, "katanas", CharStats_set_katanas);
    registerSetter(L, "sabres", CharStats_set_sabres);
    registerSetter(L, "hackers", CharStats_set_hackers);
    registerSetter(L, "blunt", CharStats_set_blunt);
    registerSetter(L, "heavyWeapons", CharStats_set_heavyWeapons);
    registerSetter(L, "unarmed", CharStats_set_unarmed);
    registerSetter(L, "bows", CharStats_set_bows);
    registerSetter(L, "turrets", CharStats_set_turrets);
    registerSetter(L, "polearms", CharStats_set_polearms);
    registerSetter(L, "currentItemMaximumJuryRig", CharStats_set_currentItemMaximumJuryRig);
    registerSetter(L, "__meleeAttack", CharStats_set___meleeAttack);
    registerSetter(L, "_meleeDefence", CharStats_set__meleeDefence);
    registerSetter(L, "_defensiveMode", CharStats_set__defensiveMode);
    registerSetter(L, "rangedMode", CharStats_set_rangedMode);
    registerSetter(L, "tauntMode", CharStats_set_tauntMode);
    registerSetter(L, "_holdPositionMode", CharStats_set__holdPositionMode);
    registerSetter(L, "passiveCombatMode", CharStats_set_passiveCombatMode);
    registerSetter(L, "holdLocation", CharStats_set_holdLocation);
    registerSetter(L, "warriorSpirit", CharStats_set_warriorSpirit);
    registerSetter(L, "derivedSpirit", CharStats_set_derivedSpirit);
    registerSetter(L, "aggression", CharStats_set_aggression);
    registerSetter(L, "goodness", CharStats_set_goodness);
    registerSetter(L, "evilness", CharStats_set_evilness);
    registerSetter(L, "longestReachingAttack", CharStats_set_longestReachingAttack);
    registerSetter(L, "STUBBOURNESS", CharStats_set_STUBBOURNESS);
    registerSetter(L, "PROFESSIONALNESS", CharStats_set_PROFESSIONALNESS);
    registerSetter(L, "HOLDING_POSITION", CharStats_set_HOLDING_POSITION);
    registerSetter(L, "IMMEDIACY", CharStats_set_IMMEDIACY);
    registerSetter(L, "IMMEDIACY_MAX_RANGE", CharStats_set_IMMEDIACY_MAX_RANGE);
    registerSetter(L, "MANLINESS", CharStats_set_MANLINESS);
    registerSetter(L, "MURDEROUS", CharStats_set_MURDEROUS);
    registerSetter(L, "_stealthXPMultForGUI", CharStats_set__stealthXPMultForGUI);
    registerSetter(L, "stealthXPTooManyCooksPenalty", CharStats_set_stealthXPTooManyCooksPenalty);
    registerSetter(L, "currentOperatingMachineHungerRate", CharStats_set_currentOperatingMachineHungerRate);
    registerSetter(L, "moveSpeed", CharStats_set_moveSpeed);
    registerSetter(L, "weaponWeightSpeedMult", CharStats_set_weaponWeightSpeedMult);
    registerSetter(L, "weaponWeightXPMult", CharStats_set_weaponWeightXPMult);
    registerSetter(L, "attackSpeed", CharStats_set_attackSpeed);
    registerSetter(L, "blockSpeed", CharStats_set_blockSpeed);
    registerSetter(L, "encumbranceMult", CharStats_set_encumbranceMult);
    registerSetter(L, "xp", CharStats_set_xp);
    registerSetter(L, "freeAttributePoints", CharStats_set_freeAttributePoints);
    registerSetter(L, "cutDamageMult", CharStats_set_cutDamageMult);
    registerSetter(L, "bluntDamageMult", CharStats_set_bluntDamageMult);
    registerSetter(L, "bleedDamageMult", CharStats_set_bleedDamageMult);
    registerSetter(L, "pierceDamageMult", CharStats_set_pierceDamageMult);
    registerSetter(L, "cutDamageMin", CharStats_set_cutDamageMin);
    registerSetter(L, "bluntDamageMin", CharStats_set_bluntDamageMin);
    registerSetter(L, "bonusRobots", CharStats_set_bonusRobots);
    registerSetter(L, "bonusHumans", CharStats_set_bonusHumans);
    registerSetter(L, "bonusAnimals", CharStats_set_bonusAnimals);
    registerSetter(L, "bonusArmourPenetration", CharStats_set_bonusArmourPenetration);
    registerSetter(L, "currentWeaponType", CharStats_set_currentWeaponType);
    registerSetter(L, "currentWeaponLength", CharStats_set_currentWeaponLength);
    registerSetter(L, "weapon", CharStats_set_weapon);
    registerSetter(L, "weaponWeight", CharStats_set_weaponWeight);
    registerSetter(L, "_weatherProtections", CharStats_set__weatherProtections);
    registerSetter(L, "bonusRaces", CharStats_set_bonusRaces);
    registerSetter(L, "pCurrentWeaponSkill", CharStats_set_pCurrentWeaponSkill);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, CharStatsBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua