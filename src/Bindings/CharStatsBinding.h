#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class CharStatsBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CharStats"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getWeatherProtection(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
    static int unarmedEncumbrancePenalty(lua_State* L);
    static int skillBonusUnarmed_forGUI(lua_State* L);
    static int skillBonusAttack_melee(lua_State* L);
    static int skillBonusAttack_unarmed(lua_State* L);
    static int skillBonusDefence(lua_State* L);
    static int _randomiseStats(lua_State* L);
    static int getGUIStatsDisplayMode(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int _NV_periodicUpdate(lua_State* L);
    static int calculateStumbleThresholdDamageAmount(lua_State* L);
    static int setEquipmentStatBonuses(lua_State* L);
    static int getOverallSkillLevel_0_100(lua_State* L);
    static int getStat(lua_State* L);
    static int getStatMultiplier(lua_State* L);
    static int getStatMultiplierForGUI(lua_State* L);
    static int getStatPenaltiesTotalForGUI(lua_State* L);
    static int xpStat_timeBased(lua_State* L);
    static int xpStat_eventBased(lua_State* L);
    static int xpDodgeEvent(lua_State* L);
    static int strengthActual(lua_State* L); //original
    static int strengthBase(lua_State* L); //original
    static int _NV_strengthBase(lua_State* L);
    static int dexterityBase(lua_State* L); //original
    static int dexterityActual(lua_State* L); //original
    static int toughness(lua_State* L); //original
    static int getStrength(lua_State* L); //alias
    static int getStrengthBase(lua_State* L); //alias
    static int getDexterity(lua_State* L); //alias
    static int getDexterityBase(lua_State* L); //alias
    static int getToughness(lua_State* L); //alias
    static int getPerception(lua_State* L); //alias
    static int getAthletics(lua_State* L); //alias
    static int getThieving(lua_State* L); //alias
    static int getToughnessMult(lua_State* L);
    static int getRangedFriendlyFireAvoidanceChance(lua_State* L);
    static int getRangedAccuracyMult(lua_State* L);
    static int getReloadSkill(lua_State* L);
    static int animalRecruitReduceStats(lua_State* L);
    static int getMeleeDefence(lua_State* L);
    static int getDodge(lua_State* L);
    static int getDodgePenalty_encumbrance(lua_State* L);
    static int getDodgePenalty_injuries(lua_State* L);
    static int getDodgePenalty_gear(lua_State* L);
    static int getMeleeDefence_melee(lua_State* L);
    static int getMeleeAttack(lua_State* L);
    static int getMeleeAttack_unarmed(lua_State* L);
    static int getMeleeAttack_melee(lua_State* L);
    static int _getMeleeAttackBase(lua_State* L);
    static int isDefensiveMode(lua_State* L);
    static int holdPositionMode(lua_State* L);
    static int setHoldLocation(lua_State* L);
    static int clearHoldLocation(lua_State* L);
    static int calculateStumbleBlockTimer(lua_State* L);
    static int calculateTechniqueInegrityCheckTimer(lua_State* L);
    static int calculateToughnessDamageResistanceMult(lua_State* L);
    static int calculateToughnessWoundDegenerationRate(lua_State* L);
    static int getAttackChance(lua_State* L);
    static int getAttackCuttingDamage(lua_State* L);
    static int getAttackBluntPower(lua_State* L);
    static int getAttackBleedDamageMult(lua_State* L);
    static int getAttackPierceDamage(lua_State* L);
    static int getEquippedWeaponSkill(lua_State* L);
    static int _NV_getEquippedWeaponSkill(lua_State* L);
    static int getSkillDifferenceRatio(lua_State* L);
    static int calculateDeadTime(lua_State* L);
    static int xpToughness_RagdollEvent(lua_State* L);
    static int xpToughness_GetUpEvent(lua_State* L);
    static int xpToughness_PunchSomething(lua_State* L);
    static int xpRunning(lua_State* L);
    static int xpStealthHearCheckEvent(lua_State* L);
    static int xpMassCombat(lua_State* L);
    static int xpEngineering(lua_State* L);
    static int xpLockpicking(lua_State* L);
    static int xpGeneral(lua_State* L);
    static int calculateAthleticsXPMult(lua_State* L);
    static int calculateStrengthXPMultFromWalking(lua_State* L);
    static int isUnarmed(lua_State* L);
    static int getWeaponWeightXPBonus(lua_State* L);
    static int getAttackSpeed(lua_State* L);
    static int getBlockSpeed(lua_State* L);
    static int getMaxRunSpeed(lua_State* L);
    static int getCurrentWeaponLength(lua_State* L);
    static int getStealthSkill01(lua_State* L);
    static int getAttackSuccessChanceSkill(lua_State* L);
    static int getEncumbranceMult(lua_State* L);
    static int calculateHungerMult(lua_State* L);
    static int calculateTheoreticalIdealMaxRunSpeed(lua_State* L);
    static int calculateWeaponWeightXPMult(lua_State* L);
    static int hasWeapon(lua_State* L);
    static int calculateMaxStealthSpeed(lua_State* L);
    static int _calculateMaxSwimSpeed(lua_State* L);
    static int calculateSwimSpeed(lua_State* L);
    static int calculateDodgeChance(lua_State* L);
    static int calculateMaxRunSpeed(lua_State* L);
    static int _calculateEncumberanceMult(lua_State* L);
    static int _calculateWeaponWeightSpeedMultiplier(lua_State* L);
    static int currentWeaponHand(lua_State* L);
    static int calculateAttackOrBlockSpeed(lua_State* L);
    static int _calculateBlockChance(lua_State* L);
    static int _recalculateStats(lua_State* L);
    static int _NV__recalculateStats(lua_State* L);
    static int setEquippedWeaponSkill(lua_State* L);
    static int _NV_setEquippedWeaponSkill(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int serialise(lua_State* L);
    static int updateStats(lua_State* L);
    static int init(lua_State* L);
    static int _NV_init(lua_State* L);
    static int getGUIData(lua_State* L);
    static int printStealthStats(lua_State* L);
    static int printRunSpeedStatMax(lua_State* L);
    static int getGUIDataForMainInfo(lua_State* L);
    static int formatWholeStatStringWithBonuses(lua_State* L);
    static int getStatRef(lua_State* L);
    static int getStatName(lua_State* L);
    static int getMeleeAttackRef(lua_State* L);
    static int getMaxHealAmount(lua_State* L);
    static int getBashAnimation(lua_State* L);
    static int chooseAttack(lua_State* L);
    static int chooseBlock(lua_State* L);
    static int getPainAnim(lua_State* L);
    static int xpMelee(lua_State* L);
    static int xpFirstAid(lua_State* L);
    static int xpStealth(lua_State* L);
    static int setWeapon(lua_State* L);
    static int _convertWeaponWeightToBluntMultiplier(lua_State* L);
    static int _convertBluntMultiplierToWeaponWeight(lua_State* L);
    static int setupCombatTechniques(lua_State* L);
    static int getAttacks(lua_State* L);
    static int getBlocks(lua_State* L);
    static int getStealthTooltip(lua_State* L);
    static int getAthleticsTooltip(lua_State* L);
    static int getStatPenaltiesForGUI(lua_State* L);
    static int _chooseAttacks(lua_State* L);
    static int stealthXPMultForGUI(lua_State* L);
    static int printExertionHungerMultTooltip(lua_State* L);
};
}