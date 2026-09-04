#include "pch.h"
#include "GameDataBinding.h"
#include "kenshi\GlobalConstants.h"
#include "GlobalConstantsBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static GlobalConstants* getInstance(lua_State* L, int idx)
{
    return checkObject<GlobalConstants>(L, idx, GlobalConstantsBinding::getMetatableName());
}

// --- Getters for GlobalConstants ---
static int GlobalConstants_get_EXTRA_BLEED_FROM_BODYPARTS_MULTIPLIER(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->EXTRA_BLEED_FROM_BODYPARTS_MULTIPLIER);
    return 1;
}

static int GlobalConstants_get_BLEED_RATE_MULTIPLIER(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->BLEED_RATE_MULTIPLIER);
    return 1;
}

static int GlobalConstants_get_INITIAL_BLEED_LOSS_MULTIPLIER(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->INITIAL_BLEED_LOSS_MULTIPLIER);
    return 1;
}

static int GlobalConstants_get_BLEED_CLOT_RATE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->BLEED_CLOT_RATE);
    return 1;
}

static int GlobalConstants_get_BLUNT_DAMAGE_1(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->BLUNT_DAMAGE_1);
    return 1;
}

static int GlobalConstants_get_BLUNT_DAMAGE_99(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->BLUNT_DAMAGE_99);
    return 1;
}

static int GlobalConstants_get_CUT_DAMAGE_1(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->CUT_DAMAGE_1);
    return 1;
}

static int GlobalConstants_get_CUT_DAMAGE_99(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->CUT_DAMAGE_99);
    return 1;
}

static int GlobalConstants_get_BOW_DAMAGE_0(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->BOW_DAMAGE_0);
    return 1;
}

static int GlobalConstants_get_BOW_DAMAGE_99(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->BOW_DAMAGE_99);
    return 1;
}

static int GlobalConstants_get_PIERCE_MULTIPLIER(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->PIERCE_MULTIPLIER);
    return 1;
}

static int GlobalConstants_get_MIN_STUMBLE_DAMAGE_MAX(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->MIN_STUMBLE_DAMAGE_MAX);
    return 1;
}

static int GlobalConstants_get_DAMAGE_RESISTANCE_MIN(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->DAMAGE_RESISTANCE_MIN);
    return 1;
}

static int GlobalConstants_get_DAMAGE_RESISTANCE_MAX(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->DAMAGE_RESISTANCE_MAX);
    return 1;
}

static int GlobalConstants_get_STUN_RECOVERY_RATE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->STUN_RECOVERY_RATE);
    return 1;
}

static int GlobalConstants_get_BLOOD_RECOVERY_RATE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->BLOOD_RECOVERY_RATE);
    return 1;
}

static int GlobalConstants_get_ATTACK_CHANCE_SKILL_DIFFERENCE_FACTOR(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->ATTACK_CHANCE_SKILL_DIFFERENCE_FACTOR);
    return 1;
}

static int GlobalConstants_get_BASE_BLOCK_CHANCE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->BASE_BLOCK_CHANCE);
    return 1;
}

static int GlobalConstants_get_BLOCK_CHANCE_REDUCTION(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->BLOCK_CHANCE_REDUCTION);
    return 1;
}

static int GlobalConstants_get_BLOCK_CHANCE_INCREASE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->BLOCK_CHANCE_INCREASE);
    return 1;
}

static int GlobalConstants_get_DEGENERATION_MULT_1(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->DEGENERATION_MULT_1);
    return 1;
}

static int GlobalConstants_get_DEGENERATION_MULT_99(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->DEGENERATION_MULT_99);
    return 1;
}

static int GlobalConstants_get_MEDIC_SPEED_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->MEDIC_SPEED_MULT);
    return 1;
}

static int GlobalConstants_get_KNOCKOUT_MULT_1(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->KNOCKOUT_MULT_1);
    return 1;
}

static int GlobalConstants_get_KNOCKOUT_MULT_99(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->KNOCKOUT_MULT_99);
    return 1;
}

static int GlobalConstants_get_KNOCKOUT_BASE_TIME(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->KNOCKOUT_BASE_TIME);
    return 1;
}

static int GlobalConstants_get_BODYPART_DEGENERATE_RATE_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->BODYPART_DEGENERATE_RATE_MULT);
    return 1;
}

static int GlobalConstants_get_BODYPART_HEAL_RATE_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->BODYPART_HEAL_RATE_MULT);
    return 1;
}

static int GlobalConstants_get_BODYPART_HEAL_RATE_MULT_RESTING(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->BODYPART_HEAL_RATE_MULT_RESTING);
    return 1;
}

static int GlobalConstants_get_XP_MEDIC_1(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->XP_MEDIC_1);
    return 1;
}

static int GlobalConstants_get_XP_MEDIC_99(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->XP_MEDIC_99);
    return 1;
}

static int GlobalConstants_get_MEDKIT_DRAIN_1(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->MEDKIT_DRAIN_1);
    return 1;
}

static int GlobalConstants_get_MEDKIT_DRAIN_99(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->MEDKIT_DRAIN_99);
    return 1;
}

static int GlobalConstants_get_ROBOT_WEAR_RATE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->ROBOT_WEAR_RATE);
    return 1;
}

static int GlobalConstants_get_ROBOT_FIRST_AID_SPEED(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->ROBOT_FIRST_AID_SPEED);
    return 1;
}

static int GlobalConstants_get_STARVATION_TIME_HRS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->STARVATION_TIME_HRS);
    return 1;
}

static int GlobalConstants_get_FED_RECOVERY_RATE_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->FED_RECOVERY_RATE_MULT);
    return 1;
}

static int GlobalConstants_get_BED_HUNGER_RATE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->BED_HUNGER_RATE);
    return 1;
}

static int GlobalConstants_get_ENCUMBRANCE_HUNGER_RATE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->ENCUMBRANCE_HUNGER_RATE);
    return 1;
}

static int GlobalConstants_get_FOOD_QUALITY_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->FOOD_QUALITY_MULT);
    return 1;
}

static int GlobalConstants_get_FOOD_PRICE_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->FOOD_PRICE_MULT);
    return 1;
}

static int GlobalConstants_get_SKILL_DIFFERENCE_XP_RATIO_MULT_BONUS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->SKILL_DIFFERENCE_XP_RATIO_MULT_BONUS);
    return 1;
}

static int GlobalConstants_get_SKILL_DIFFERENCE_XP_RATIO_MULT_PENALTY(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->SKILL_DIFFERENCE_XP_RATIO_MULT_PENALTY);
    return 1;
}

static int GlobalConstants_get_XP_HIT_THEM(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->XP_HIT_THEM);
    return 1;
}

static int GlobalConstants_get_XP_HIT_ME(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->XP_HIT_ME);
    return 1;
}

static int GlobalConstants_get_XP_BLOCKED_THEM(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->XP_BLOCKED_THEM);
    return 1;
}

static int GlobalConstants_get_XP_BLOCKED_ME(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->XP_BLOCKED_ME);
    return 1;
}

static int GlobalConstants_get_XP_FIRSTAID(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->XP_FIRSTAID);
    return 1;
}

static int GlobalConstants_get_XP_FITNESS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->XP_FITNESS);
    return 1;
}

static int GlobalConstants_get_XP_TOUGHNESS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->XP_TOUGHNESS);
    return 1;
}

static int GlobalConstants_get_PRICE_ROBOTICS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->PRICE_ROBOTICS);
    return 1;
}

static int GlobalConstants_get_PRICE_CROSSBOWS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->PRICE_CROSSBOWS);
    return 1;
}

static int GlobalConstants_get_PRICE_ARMOUR(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->PRICE_ARMOUR);
    return 1;
}

static int GlobalConstants_get_PRICE_SWORDS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->PRICE_SWORDS);
    return 1;
}

static int GlobalConstants_get_PRICE_TRADE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->PRICE_TRADE);
    return 1;
}

static int GlobalConstants_get_PRICE_GLOBAL_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->PRICE_GLOBAL_MULT);
    return 1;
}

static int GlobalConstants_get_PRICE_CLOTHING(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->PRICE_CLOTHING);
    return 1;
}

static int GlobalConstants_get_TRADE_PROFIT_MARGINS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->TRADE_PROFIT_MARGINS);
    return 1;
}

static int GlobalConstants_get_PRICE_LOOT_GEAR(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->PRICE_LOOT_GEAR);
    return 1;
}

static int GlobalConstants_get_PRICE_LOOT_ITEMS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->PRICE_LOOT_ITEMS);
    return 1;
}

static int GlobalConstants_get_PRICE_LOOT_PLAYER_CRAFTED_ARMOUR(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->PRICE_LOOT_PLAYER_CRAFTED_ARMOUR);
    return 1;
}

static int GlobalConstants_get_PRICE_LOOT_PLAYER_CRAFTED_WEAPONS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->PRICE_LOOT_PLAYER_CRAFTED_WEAPONS);
    return 1;
}

static int GlobalConstants_get_BLUEPRINT_COST_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->BLUEPRINT_COST_MULT);
    return 1;
}

static int GlobalConstants_get_UNIFORM_PRICE_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->UNIFORM_PRICE_MULT);
    return 1;
}

static int GlobalConstants_get_BLUNT_PERMANENT_DAMAGE_RATIO(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->BLUNT_PERMANENT_DAMAGE_RATIO);
    return 1;
}

static int GlobalConstants_get_UNARMED_DAMAGE_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->UNARMED_DAMAGE_MULT);
    return 1;
}

static int GlobalConstants_get_MAX_NUM_ATTACK_SLOTS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushinteger(L, instance->MAX_NUM_ATTACK_SLOTS);
    return 1;
}

static int GlobalConstants_get_MINIMUM_STRENGTH_XP_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->MINIMUM_STRENGTH_XP_MULT);
    return 1;
}

static int GlobalConstants_get_WEIGHT_STR_DIFF_1X(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->WEIGHT_STR_DIFF_1X);
    return 1;
}

static int GlobalConstants_get_WEIGHT_STR_DIFF_MAX(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->WEIGHT_STR_DIFF_MAX);
    return 1;
}

static int GlobalConstants_get_WEAPON_INVENTORY_WEIGHT_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->WEAPON_INVENTORY_WEIGHT_MULT);
    return 1;
}

static int GlobalConstants_get_STRENGTH_XP_RATE_FROM_WALKING(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->STRENGTH_XP_RATE_FROM_WALKING);
    return 1;
}

static int GlobalConstants_get_STRENGTH_XP_RATE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->STRENGTH_XP_RATE);
    return 1;
}

static int GlobalConstants_get_ATHLETICS_XP_RATE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->ATHLETICS_XP_RATE);
    return 1;
}

static int GlobalConstants_get_ENCUMBRANCE_BASE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->ENCUMBRANCE_BASE);
    return 1;
}

static int GlobalConstants_get_CARRY_WEIGHT_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->CARRY_WEIGHT_MULT);
    return 1;
}

static int GlobalConstants_get_CARRY_PERSON_WEIGHT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->CARRY_PERSON_WEIGHT);
    return 1;
}

static int GlobalConstants_get_MIN_MATS_FROM_DISMANTLE_01(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->MIN_MATS_FROM_DISMANTLE_01);
    return 1;
}

static int GlobalConstants_get_EXPERIENCE_GAIN(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->EXPERIENCE_GAIN);
    return 1;
}

static int GlobalConstants_get_EXPERIENCE_GAIN_1(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->EXPERIENCE_GAIN_1);
    return 1;
}

static int GlobalConstants_get_EXPERIENCE_GAIN_99(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->EXPERIENCE_GAIN_99);
    return 1;
}

static int GlobalConstants_get_RESEARCH_LEVEL_INCREASE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->RESEARCH_LEVEL_INCREASE);
    return 1;
}

static int GlobalConstants_get_RESEARCH_RATE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->RESEARCH_RATE);
    return 1;
}

static int GlobalConstants_get_LOCKPICK_CHANCE_MINIMUM(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->LOCKPICK_CHANCE_MINIMUM);
    return 1;
}

static int GlobalConstants_get_EXPERIENCE_CURVE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->EXPERIENCE_CURVE);
    return 1;
}

static int GlobalConstants_get_ANIMATION_BLEND_RATE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->ANIMATION_BLEND_RATE);
    return 1;
}

static int GlobalConstants_get_PRODUCTION_MULTIPLIER(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->PRODUCTION_MULTIPLIER);
    return 1;
}

static int GlobalConstants_get_BUILD_SPEED_MULTIPLIER(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->BUILD_SPEED_MULTIPLIER);
    return 1;
}

static int GlobalConstants_get_PRISON_TIME_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->PRISON_TIME_MULT);
    return 1;
}

static int GlobalConstants_get_TOUGHNESS_KO_POINT_MIN(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->TOUGHNESS_KO_POINT_MIN);
    return 1;
}

static int GlobalConstants_get_TOUGHNESS_KO_POINT_MAX(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->TOUGHNESS_KO_POINT_MAX);
    return 1;
}

static int GlobalConstants_get_MAX_SQUAD_SIZE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushinteger(L, instance->MAX_SQUAD_SIZE);
    return 1;
}

static int GlobalConstants_get_MAX_SQUADS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushinteger(L, instance->MAX_SQUADS);
    return 1;
}

static int GlobalConstants_get_MAX_FACTION_SIZE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushinteger(L, instance->MAX_FACTION_SIZE);
    return 1;
}

static int GlobalConstants_get_attackDiplomats(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushboolean(L, instance->attackDiplomats ? 1 : 0);
    return 1;
}

static int GlobalConstants_get_settings(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    return pushObject<GameData>(L, instance->settings, GameDataBinding::getMetatableName());
}

static int GlobalConstants_get_APPEARANCE_RANDOM_DEVIATION(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->APPEARANCE_RANDOM_DEVIATION);
    return 1;
}

static int GlobalConstants_get_fogDistMax(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->fogDistMax);
    return 1;
}

static int GlobalConstants_get_fogDistMin(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    lua_pushnumber(L, instance->fogDistMin);
    return 1;
}

// --- Setters for GlobalConstants ---
static int GlobalConstants_set_EXTRA_BLEED_FROM_BODYPARTS_MULTIPLIER(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->EXTRA_BLEED_FROM_BODYPARTS_MULTIPLIER = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_BLEED_RATE_MULTIPLIER(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->BLEED_RATE_MULTIPLIER = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_INITIAL_BLEED_LOSS_MULTIPLIER(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->INITIAL_BLEED_LOSS_MULTIPLIER = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_BLEED_CLOT_RATE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->BLEED_CLOT_RATE = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_BLUNT_DAMAGE_1(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->BLUNT_DAMAGE_1 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_BLUNT_DAMAGE_99(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->BLUNT_DAMAGE_99 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_CUT_DAMAGE_1(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->CUT_DAMAGE_1 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_CUT_DAMAGE_99(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->CUT_DAMAGE_99 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_BOW_DAMAGE_0(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->BOW_DAMAGE_0 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_BOW_DAMAGE_99(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->BOW_DAMAGE_99 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_PIERCE_MULTIPLIER(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->PIERCE_MULTIPLIER = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_MIN_STUMBLE_DAMAGE_MAX(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->MIN_STUMBLE_DAMAGE_MAX = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_DAMAGE_RESISTANCE_MIN(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->DAMAGE_RESISTANCE_MIN = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_DAMAGE_RESISTANCE_MAX(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->DAMAGE_RESISTANCE_MAX = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_STUN_RECOVERY_RATE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->STUN_RECOVERY_RATE = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_BLOOD_RECOVERY_RATE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->BLOOD_RECOVERY_RATE = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_ATTACK_CHANCE_SKILL_DIFFERENCE_FACTOR(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->ATTACK_CHANCE_SKILL_DIFFERENCE_FACTOR = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_BASE_BLOCK_CHANCE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->BASE_BLOCK_CHANCE = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_BLOCK_CHANCE_REDUCTION(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->BLOCK_CHANCE_REDUCTION = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_BLOCK_CHANCE_INCREASE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->BLOCK_CHANCE_INCREASE = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_DEGENERATION_MULT_1(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->DEGENERATION_MULT_1 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_DEGENERATION_MULT_99(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->DEGENERATION_MULT_99 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_MEDIC_SPEED_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->MEDIC_SPEED_MULT = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_KNOCKOUT_MULT_1(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->KNOCKOUT_MULT_1 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_KNOCKOUT_MULT_99(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->KNOCKOUT_MULT_99 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_KNOCKOUT_BASE_TIME(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->KNOCKOUT_BASE_TIME = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_BODYPART_DEGENERATE_RATE_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->BODYPART_DEGENERATE_RATE_MULT = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_BODYPART_HEAL_RATE_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->BODYPART_HEAL_RATE_MULT = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_BODYPART_HEAL_RATE_MULT_RESTING(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->BODYPART_HEAL_RATE_MULT_RESTING = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_XP_MEDIC_1(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->XP_MEDIC_1 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_XP_MEDIC_99(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->XP_MEDIC_99 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_MEDKIT_DRAIN_1(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->MEDKIT_DRAIN_1 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_MEDKIT_DRAIN_99(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->MEDKIT_DRAIN_99 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_ROBOT_WEAR_RATE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->ROBOT_WEAR_RATE = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_ROBOT_FIRST_AID_SPEED(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->ROBOT_FIRST_AID_SPEED = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_STARVATION_TIME_HRS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->STARVATION_TIME_HRS = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_FED_RECOVERY_RATE_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->FED_RECOVERY_RATE_MULT = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_BED_HUNGER_RATE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->BED_HUNGER_RATE = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_ENCUMBRANCE_HUNGER_RATE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->ENCUMBRANCE_HUNGER_RATE = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_FOOD_QUALITY_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->FOOD_QUALITY_MULT = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_FOOD_PRICE_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->FOOD_PRICE_MULT = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_SKILL_DIFFERENCE_XP_RATIO_MULT_BONUS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->SKILL_DIFFERENCE_XP_RATIO_MULT_BONUS = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_SKILL_DIFFERENCE_XP_RATIO_MULT_PENALTY(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->SKILL_DIFFERENCE_XP_RATIO_MULT_PENALTY = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_XP_HIT_THEM(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->XP_HIT_THEM = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_XP_HIT_ME(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->XP_HIT_ME = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_XP_BLOCKED_THEM(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->XP_BLOCKED_THEM = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_XP_BLOCKED_ME(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->XP_BLOCKED_ME = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_XP_FIRSTAID(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->XP_FIRSTAID = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_XP_FITNESS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->XP_FITNESS = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_XP_TOUGHNESS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->XP_TOUGHNESS = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_PRICE_ROBOTICS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->PRICE_ROBOTICS = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_PRICE_CROSSBOWS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->PRICE_CROSSBOWS = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_PRICE_ARMOUR(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->PRICE_ARMOUR = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_PRICE_SWORDS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->PRICE_SWORDS = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_PRICE_TRADE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->PRICE_TRADE = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_PRICE_GLOBAL_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->PRICE_GLOBAL_MULT = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_PRICE_CLOTHING(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->PRICE_CLOTHING = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_TRADE_PROFIT_MARGINS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->TRADE_PROFIT_MARGINS = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_PRICE_LOOT_GEAR(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->PRICE_LOOT_GEAR = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_PRICE_LOOT_ITEMS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->PRICE_LOOT_ITEMS = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_PRICE_LOOT_PLAYER_CRAFTED_ARMOUR(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->PRICE_LOOT_PLAYER_CRAFTED_ARMOUR = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_PRICE_LOOT_PLAYER_CRAFTED_WEAPONS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->PRICE_LOOT_PLAYER_CRAFTED_WEAPONS = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_BLUEPRINT_COST_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->BLUEPRINT_COST_MULT = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_UNIFORM_PRICE_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->UNIFORM_PRICE_MULT = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_BLUNT_PERMANENT_DAMAGE_RATIO(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->BLUNT_PERMANENT_DAMAGE_RATIO = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_UNARMED_DAMAGE_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->UNARMED_DAMAGE_MULT = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_MAX_NUM_ATTACK_SLOTS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->MAX_NUM_ATTACK_SLOTS = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int GlobalConstants_set_MINIMUM_STRENGTH_XP_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->MINIMUM_STRENGTH_XP_MULT = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_WEIGHT_STR_DIFF_1X(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->WEIGHT_STR_DIFF_1X = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_WEIGHT_STR_DIFF_MAX(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->WEIGHT_STR_DIFF_MAX = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_WEAPON_INVENTORY_WEIGHT_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->WEAPON_INVENTORY_WEIGHT_MULT = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_STRENGTH_XP_RATE_FROM_WALKING(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->STRENGTH_XP_RATE_FROM_WALKING = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_STRENGTH_XP_RATE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->STRENGTH_XP_RATE = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_ATHLETICS_XP_RATE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->ATHLETICS_XP_RATE = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_ENCUMBRANCE_BASE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->ENCUMBRANCE_BASE = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_CARRY_WEIGHT_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->CARRY_WEIGHT_MULT = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_CARRY_PERSON_WEIGHT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->CARRY_PERSON_WEIGHT = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_MIN_MATS_FROM_DISMANTLE_01(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->MIN_MATS_FROM_DISMANTLE_01 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_EXPERIENCE_GAIN(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->EXPERIENCE_GAIN = (double)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_EXPERIENCE_GAIN_1(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->EXPERIENCE_GAIN_1 = (double)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_EXPERIENCE_GAIN_99(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->EXPERIENCE_GAIN_99 = (double)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_RESEARCH_LEVEL_INCREASE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->RESEARCH_LEVEL_INCREASE = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_RESEARCH_RATE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->RESEARCH_RATE = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_LOCKPICK_CHANCE_MINIMUM(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->LOCKPICK_CHANCE_MINIMUM = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_EXPERIENCE_CURVE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->EXPERIENCE_CURVE = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_ANIMATION_BLEND_RATE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->ANIMATION_BLEND_RATE = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_PRODUCTION_MULTIPLIER(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->PRODUCTION_MULTIPLIER = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_BUILD_SPEED_MULTIPLIER(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->BUILD_SPEED_MULTIPLIER = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_PRISON_TIME_MULT(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->PRISON_TIME_MULT = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_TOUGHNESS_KO_POINT_MIN(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->TOUGHNESS_KO_POINT_MIN = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_TOUGHNESS_KO_POINT_MAX(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->TOUGHNESS_KO_POINT_MAX = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_MAX_SQUAD_SIZE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->MAX_SQUAD_SIZE = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int GlobalConstants_set_MAX_SQUADS(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->MAX_SQUADS = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int GlobalConstants_set_MAX_FACTION_SIZE(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->MAX_FACTION_SIZE = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int GlobalConstants_set_attackDiplomats(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->attackDiplomats = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GlobalConstants_set_APPEARANCE_RANDOM_DEVIATION(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->APPEARANCE_RANDOM_DEVIATION = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_fogDistMax(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->fogDistMax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int GlobalConstants_set_fogDistMin(lua_State* L)
{
    GlobalConstants* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GlobalConstants is nil");
    instance->fogDistMin = (float)luaL_checknumber(L, 2);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 7: void setup(...) - unsupported arg type
*/

int GlobalConstantsBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int GlobalConstantsBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.GlobalConstants object");
    return 1;
}

void GlobalConstantsBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GlobalConstantsBinding::gc },
        { "__tostring", GlobalConstantsBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        GlobalConstantsBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GlobalConstantsBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "EXTRA_BLEED_FROM_BODYPARTS_MULTIPLIER", GlobalConstants_get_EXTRA_BLEED_FROM_BODYPARTS_MULTIPLIER);
    registerGetter(L, "BLEED_RATE_MULTIPLIER", GlobalConstants_get_BLEED_RATE_MULTIPLIER);
    registerGetter(L, "INITIAL_BLEED_LOSS_MULTIPLIER", GlobalConstants_get_INITIAL_BLEED_LOSS_MULTIPLIER);
    registerGetter(L, "BLEED_CLOT_RATE", GlobalConstants_get_BLEED_CLOT_RATE);
    registerGetter(L, "BLUNT_DAMAGE_1", GlobalConstants_get_BLUNT_DAMAGE_1);
    registerGetter(L, "BLUNT_DAMAGE_99", GlobalConstants_get_BLUNT_DAMAGE_99);
    registerGetter(L, "CUT_DAMAGE_1", GlobalConstants_get_CUT_DAMAGE_1);
    registerGetter(L, "CUT_DAMAGE_99", GlobalConstants_get_CUT_DAMAGE_99);
    registerGetter(L, "BOW_DAMAGE_0", GlobalConstants_get_BOW_DAMAGE_0);
    registerGetter(L, "BOW_DAMAGE_99", GlobalConstants_get_BOW_DAMAGE_99);
    registerGetter(L, "PIERCE_MULTIPLIER", GlobalConstants_get_PIERCE_MULTIPLIER);
    registerGetter(L, "MIN_STUMBLE_DAMAGE_MAX", GlobalConstants_get_MIN_STUMBLE_DAMAGE_MAX);
    registerGetter(L, "DAMAGE_RESISTANCE_MIN", GlobalConstants_get_DAMAGE_RESISTANCE_MIN);
    registerGetter(L, "DAMAGE_RESISTANCE_MAX", GlobalConstants_get_DAMAGE_RESISTANCE_MAX);
    registerGetter(L, "STUN_RECOVERY_RATE", GlobalConstants_get_STUN_RECOVERY_RATE);
    registerGetter(L, "BLOOD_RECOVERY_RATE", GlobalConstants_get_BLOOD_RECOVERY_RATE);
    registerGetter(L, "ATTACK_CHANCE_SKILL_DIFFERENCE_FACTOR", GlobalConstants_get_ATTACK_CHANCE_SKILL_DIFFERENCE_FACTOR);
    registerGetter(L, "BASE_BLOCK_CHANCE", GlobalConstants_get_BASE_BLOCK_CHANCE);
    registerGetter(L, "BLOCK_CHANCE_REDUCTION", GlobalConstants_get_BLOCK_CHANCE_REDUCTION);
    registerGetter(L, "BLOCK_CHANCE_INCREASE", GlobalConstants_get_BLOCK_CHANCE_INCREASE);
    registerGetter(L, "DEGENERATION_MULT_1", GlobalConstants_get_DEGENERATION_MULT_1);
    registerGetter(L, "DEGENERATION_MULT_99", GlobalConstants_get_DEGENERATION_MULT_99);
    registerGetter(L, "MEDIC_SPEED_MULT", GlobalConstants_get_MEDIC_SPEED_MULT);
    registerGetter(L, "KNOCKOUT_MULT_1", GlobalConstants_get_KNOCKOUT_MULT_1);
    registerGetter(L, "KNOCKOUT_MULT_99", GlobalConstants_get_KNOCKOUT_MULT_99);
    registerGetter(L, "KNOCKOUT_BASE_TIME", GlobalConstants_get_KNOCKOUT_BASE_TIME);
    registerGetter(L, "BODYPART_DEGENERATE_RATE_MULT", GlobalConstants_get_BODYPART_DEGENERATE_RATE_MULT);
    registerGetter(L, "BODYPART_HEAL_RATE_MULT", GlobalConstants_get_BODYPART_HEAL_RATE_MULT);
    registerGetter(L, "BODYPART_HEAL_RATE_MULT_RESTING", GlobalConstants_get_BODYPART_HEAL_RATE_MULT_RESTING);
    registerGetter(L, "XP_MEDIC_1", GlobalConstants_get_XP_MEDIC_1);
    registerGetter(L, "XP_MEDIC_99", GlobalConstants_get_XP_MEDIC_99);
    registerGetter(L, "MEDKIT_DRAIN_1", GlobalConstants_get_MEDKIT_DRAIN_1);
    registerGetter(L, "MEDKIT_DRAIN_99", GlobalConstants_get_MEDKIT_DRAIN_99);
    registerGetter(L, "ROBOT_WEAR_RATE", GlobalConstants_get_ROBOT_WEAR_RATE);
    registerGetter(L, "ROBOT_FIRST_AID_SPEED", GlobalConstants_get_ROBOT_FIRST_AID_SPEED);
    registerGetter(L, "STARVATION_TIME_HRS", GlobalConstants_get_STARVATION_TIME_HRS);
    registerGetter(L, "FED_RECOVERY_RATE_MULT", GlobalConstants_get_FED_RECOVERY_RATE_MULT);
    registerGetter(L, "BED_HUNGER_RATE", GlobalConstants_get_BED_HUNGER_RATE);
    registerGetter(L, "ENCUMBRANCE_HUNGER_RATE", GlobalConstants_get_ENCUMBRANCE_HUNGER_RATE);
    registerGetter(L, "FOOD_QUALITY_MULT", GlobalConstants_get_FOOD_QUALITY_MULT);
    registerGetter(L, "FOOD_PRICE_MULT", GlobalConstants_get_FOOD_PRICE_MULT);
    registerGetter(L, "SKILL_DIFFERENCE_XP_RATIO_MULT_BONUS", GlobalConstants_get_SKILL_DIFFERENCE_XP_RATIO_MULT_BONUS);
    registerGetter(L, "SKILL_DIFFERENCE_XP_RATIO_MULT_PENALTY", GlobalConstants_get_SKILL_DIFFERENCE_XP_RATIO_MULT_PENALTY);
    registerGetter(L, "XP_HIT_THEM", GlobalConstants_get_XP_HIT_THEM);
    registerGetter(L, "XP_HIT_ME", GlobalConstants_get_XP_HIT_ME);
    registerGetter(L, "XP_BLOCKED_THEM", GlobalConstants_get_XP_BLOCKED_THEM);
    registerGetter(L, "XP_BLOCKED_ME", GlobalConstants_get_XP_BLOCKED_ME);
    registerGetter(L, "XP_FIRSTAID", GlobalConstants_get_XP_FIRSTAID);
    registerGetter(L, "XP_FITNESS", GlobalConstants_get_XP_FITNESS);
    registerGetter(L, "XP_TOUGHNESS", GlobalConstants_get_XP_TOUGHNESS);
    registerGetter(L, "PRICE_ROBOTICS", GlobalConstants_get_PRICE_ROBOTICS);
    registerGetter(L, "PRICE_CROSSBOWS", GlobalConstants_get_PRICE_CROSSBOWS);
    registerGetter(L, "PRICE_ARMOUR", GlobalConstants_get_PRICE_ARMOUR);
    registerGetter(L, "PRICE_SWORDS", GlobalConstants_get_PRICE_SWORDS);
    registerGetter(L, "PRICE_TRADE", GlobalConstants_get_PRICE_TRADE);
    registerGetter(L, "PRICE_GLOBAL_MULT", GlobalConstants_get_PRICE_GLOBAL_MULT);
    registerGetter(L, "PRICE_CLOTHING", GlobalConstants_get_PRICE_CLOTHING);
    registerGetter(L, "TRADE_PROFIT_MARGINS", GlobalConstants_get_TRADE_PROFIT_MARGINS);
    registerGetter(L, "PRICE_LOOT_GEAR", GlobalConstants_get_PRICE_LOOT_GEAR);
    registerGetter(L, "PRICE_LOOT_ITEMS", GlobalConstants_get_PRICE_LOOT_ITEMS);
    registerGetter(L, "PRICE_LOOT_PLAYER_CRAFTED_ARMOUR", GlobalConstants_get_PRICE_LOOT_PLAYER_CRAFTED_ARMOUR);
    registerGetter(L, "PRICE_LOOT_PLAYER_CRAFTED_WEAPONS", GlobalConstants_get_PRICE_LOOT_PLAYER_CRAFTED_WEAPONS);
    registerGetter(L, "BLUEPRINT_COST_MULT", GlobalConstants_get_BLUEPRINT_COST_MULT);
    registerGetter(L, "UNIFORM_PRICE_MULT", GlobalConstants_get_UNIFORM_PRICE_MULT);
    registerGetter(L, "BLUNT_PERMANENT_DAMAGE_RATIO", GlobalConstants_get_BLUNT_PERMANENT_DAMAGE_RATIO);
    registerGetter(L, "UNARMED_DAMAGE_MULT", GlobalConstants_get_UNARMED_DAMAGE_MULT);
    registerGetter(L, "MAX_NUM_ATTACK_SLOTS", GlobalConstants_get_MAX_NUM_ATTACK_SLOTS);
    registerGetter(L, "MINIMUM_STRENGTH_XP_MULT", GlobalConstants_get_MINIMUM_STRENGTH_XP_MULT);
    registerGetter(L, "WEIGHT_STR_DIFF_1X", GlobalConstants_get_WEIGHT_STR_DIFF_1X);
    registerGetter(L, "WEIGHT_STR_DIFF_MAX", GlobalConstants_get_WEIGHT_STR_DIFF_MAX);
    registerGetter(L, "WEAPON_INVENTORY_WEIGHT_MULT", GlobalConstants_get_WEAPON_INVENTORY_WEIGHT_MULT);
    registerGetter(L, "STRENGTH_XP_RATE_FROM_WALKING", GlobalConstants_get_STRENGTH_XP_RATE_FROM_WALKING);
    registerGetter(L, "STRENGTH_XP_RATE", GlobalConstants_get_STRENGTH_XP_RATE);
    registerGetter(L, "ATHLETICS_XP_RATE", GlobalConstants_get_ATHLETICS_XP_RATE);
    registerGetter(L, "ENCUMBRANCE_BASE", GlobalConstants_get_ENCUMBRANCE_BASE);
    registerGetter(L, "CARRY_WEIGHT_MULT", GlobalConstants_get_CARRY_WEIGHT_MULT);
    registerGetter(L, "CARRY_PERSON_WEIGHT", GlobalConstants_get_CARRY_PERSON_WEIGHT);
    registerGetter(L, "MIN_MATS_FROM_DISMANTLE_01", GlobalConstants_get_MIN_MATS_FROM_DISMANTLE_01);
    registerGetter(L, "EXPERIENCE_GAIN", GlobalConstants_get_EXPERIENCE_GAIN);
    registerGetter(L, "EXPERIENCE_GAIN_1", GlobalConstants_get_EXPERIENCE_GAIN_1);
    registerGetter(L, "EXPERIENCE_GAIN_99", GlobalConstants_get_EXPERIENCE_GAIN_99);
    registerGetter(L, "RESEARCH_LEVEL_INCREASE", GlobalConstants_get_RESEARCH_LEVEL_INCREASE);
    registerGetter(L, "RESEARCH_RATE", GlobalConstants_get_RESEARCH_RATE);
    registerGetter(L, "LOCKPICK_CHANCE_MINIMUM", GlobalConstants_get_LOCKPICK_CHANCE_MINIMUM);
    registerGetter(L, "EXPERIENCE_CURVE", GlobalConstants_get_EXPERIENCE_CURVE);
    registerGetter(L, "ANIMATION_BLEND_RATE", GlobalConstants_get_ANIMATION_BLEND_RATE);
    registerGetter(L, "PRODUCTION_MULTIPLIER", GlobalConstants_get_PRODUCTION_MULTIPLIER);
    registerGetter(L, "BUILD_SPEED_MULTIPLIER", GlobalConstants_get_BUILD_SPEED_MULTIPLIER);
    registerGetter(L, "PRISON_TIME_MULT", GlobalConstants_get_PRISON_TIME_MULT);
    registerGetter(L, "TOUGHNESS_KO_POINT_MIN", GlobalConstants_get_TOUGHNESS_KO_POINT_MIN);
    registerGetter(L, "TOUGHNESS_KO_POINT_MAX", GlobalConstants_get_TOUGHNESS_KO_POINT_MAX);
    registerGetter(L, "MAX_SQUAD_SIZE", GlobalConstants_get_MAX_SQUAD_SIZE);
    registerGetter(L, "MAX_SQUADS", GlobalConstants_get_MAX_SQUADS);
    registerGetter(L, "MAX_FACTION_SIZE", GlobalConstants_get_MAX_FACTION_SIZE);
    registerGetter(L, "attackDiplomats", GlobalConstants_get_attackDiplomats);
    registerGetter(L, "settings", GlobalConstants_get_settings);
    registerGetter(L, "APPEARANCE_RANDOM_DEVIATION", GlobalConstants_get_APPEARANCE_RANDOM_DEVIATION);
    registerGetter(L, "fogDistMax", GlobalConstants_get_fogDistMax);
    registerGetter(L, "fogDistMin", GlobalConstants_get_fogDistMin);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "EXTRA_BLEED_FROM_BODYPARTS_MULTIPLIER", GlobalConstants_set_EXTRA_BLEED_FROM_BODYPARTS_MULTIPLIER);
    registerSetter(L, "BLEED_RATE_MULTIPLIER", GlobalConstants_set_BLEED_RATE_MULTIPLIER);
    registerSetter(L, "INITIAL_BLEED_LOSS_MULTIPLIER", GlobalConstants_set_INITIAL_BLEED_LOSS_MULTIPLIER);
    registerSetter(L, "BLEED_CLOT_RATE", GlobalConstants_set_BLEED_CLOT_RATE);
    registerSetter(L, "BLUNT_DAMAGE_1", GlobalConstants_set_BLUNT_DAMAGE_1);
    registerSetter(L, "BLUNT_DAMAGE_99", GlobalConstants_set_BLUNT_DAMAGE_99);
    registerSetter(L, "CUT_DAMAGE_1", GlobalConstants_set_CUT_DAMAGE_1);
    registerSetter(L, "CUT_DAMAGE_99", GlobalConstants_set_CUT_DAMAGE_99);
    registerSetter(L, "BOW_DAMAGE_0", GlobalConstants_set_BOW_DAMAGE_0);
    registerSetter(L, "BOW_DAMAGE_99", GlobalConstants_set_BOW_DAMAGE_99);
    registerSetter(L, "PIERCE_MULTIPLIER", GlobalConstants_set_PIERCE_MULTIPLIER);
    registerSetter(L, "MIN_STUMBLE_DAMAGE_MAX", GlobalConstants_set_MIN_STUMBLE_DAMAGE_MAX);
    registerSetter(L, "DAMAGE_RESISTANCE_MIN", GlobalConstants_set_DAMAGE_RESISTANCE_MIN);
    registerSetter(L, "DAMAGE_RESISTANCE_MAX", GlobalConstants_set_DAMAGE_RESISTANCE_MAX);
    registerSetter(L, "STUN_RECOVERY_RATE", GlobalConstants_set_STUN_RECOVERY_RATE);
    registerSetter(L, "BLOOD_RECOVERY_RATE", GlobalConstants_set_BLOOD_RECOVERY_RATE);
    registerSetter(L, "ATTACK_CHANCE_SKILL_DIFFERENCE_FACTOR", GlobalConstants_set_ATTACK_CHANCE_SKILL_DIFFERENCE_FACTOR);
    registerSetter(L, "BASE_BLOCK_CHANCE", GlobalConstants_set_BASE_BLOCK_CHANCE);
    registerSetter(L, "BLOCK_CHANCE_REDUCTION", GlobalConstants_set_BLOCK_CHANCE_REDUCTION);
    registerSetter(L, "BLOCK_CHANCE_INCREASE", GlobalConstants_set_BLOCK_CHANCE_INCREASE);
    registerSetter(L, "DEGENERATION_MULT_1", GlobalConstants_set_DEGENERATION_MULT_1);
    registerSetter(L, "DEGENERATION_MULT_99", GlobalConstants_set_DEGENERATION_MULT_99);
    registerSetter(L, "MEDIC_SPEED_MULT", GlobalConstants_set_MEDIC_SPEED_MULT);
    registerSetter(L, "KNOCKOUT_MULT_1", GlobalConstants_set_KNOCKOUT_MULT_1);
    registerSetter(L, "KNOCKOUT_MULT_99", GlobalConstants_set_KNOCKOUT_MULT_99);
    registerSetter(L, "KNOCKOUT_BASE_TIME", GlobalConstants_set_KNOCKOUT_BASE_TIME);
    registerSetter(L, "BODYPART_DEGENERATE_RATE_MULT", GlobalConstants_set_BODYPART_DEGENERATE_RATE_MULT);
    registerSetter(L, "BODYPART_HEAL_RATE_MULT", GlobalConstants_set_BODYPART_HEAL_RATE_MULT);
    registerSetter(L, "BODYPART_HEAL_RATE_MULT_RESTING", GlobalConstants_set_BODYPART_HEAL_RATE_MULT_RESTING);
    registerSetter(L, "XP_MEDIC_1", GlobalConstants_set_XP_MEDIC_1);
    registerSetter(L, "XP_MEDIC_99", GlobalConstants_set_XP_MEDIC_99);
    registerSetter(L, "MEDKIT_DRAIN_1", GlobalConstants_set_MEDKIT_DRAIN_1);
    registerSetter(L, "MEDKIT_DRAIN_99", GlobalConstants_set_MEDKIT_DRAIN_99);
    registerSetter(L, "ROBOT_WEAR_RATE", GlobalConstants_set_ROBOT_WEAR_RATE);
    registerSetter(L, "ROBOT_FIRST_AID_SPEED", GlobalConstants_set_ROBOT_FIRST_AID_SPEED);
    registerSetter(L, "STARVATION_TIME_HRS", GlobalConstants_set_STARVATION_TIME_HRS);
    registerSetter(L, "FED_RECOVERY_RATE_MULT", GlobalConstants_set_FED_RECOVERY_RATE_MULT);
    registerSetter(L, "BED_HUNGER_RATE", GlobalConstants_set_BED_HUNGER_RATE);
    registerSetter(L, "ENCUMBRANCE_HUNGER_RATE", GlobalConstants_set_ENCUMBRANCE_HUNGER_RATE);
    registerSetter(L, "FOOD_QUALITY_MULT", GlobalConstants_set_FOOD_QUALITY_MULT);
    registerSetter(L, "FOOD_PRICE_MULT", GlobalConstants_set_FOOD_PRICE_MULT);
    registerSetter(L, "SKILL_DIFFERENCE_XP_RATIO_MULT_BONUS", GlobalConstants_set_SKILL_DIFFERENCE_XP_RATIO_MULT_BONUS);
    registerSetter(L, "SKILL_DIFFERENCE_XP_RATIO_MULT_PENALTY", GlobalConstants_set_SKILL_DIFFERENCE_XP_RATIO_MULT_PENALTY);
    registerSetter(L, "XP_HIT_THEM", GlobalConstants_set_XP_HIT_THEM);
    registerSetter(L, "XP_HIT_ME", GlobalConstants_set_XP_HIT_ME);
    registerSetter(L, "XP_BLOCKED_THEM", GlobalConstants_set_XP_BLOCKED_THEM);
    registerSetter(L, "XP_BLOCKED_ME", GlobalConstants_set_XP_BLOCKED_ME);
    registerSetter(L, "XP_FIRSTAID", GlobalConstants_set_XP_FIRSTAID);
    registerSetter(L, "XP_FITNESS", GlobalConstants_set_XP_FITNESS);
    registerSetter(L, "XP_TOUGHNESS", GlobalConstants_set_XP_TOUGHNESS);
    registerSetter(L, "PRICE_ROBOTICS", GlobalConstants_set_PRICE_ROBOTICS);
    registerSetter(L, "PRICE_CROSSBOWS", GlobalConstants_set_PRICE_CROSSBOWS);
    registerSetter(L, "PRICE_ARMOUR", GlobalConstants_set_PRICE_ARMOUR);
    registerSetter(L, "PRICE_SWORDS", GlobalConstants_set_PRICE_SWORDS);
    registerSetter(L, "PRICE_TRADE", GlobalConstants_set_PRICE_TRADE);
    registerSetter(L, "PRICE_GLOBAL_MULT", GlobalConstants_set_PRICE_GLOBAL_MULT);
    registerSetter(L, "PRICE_CLOTHING", GlobalConstants_set_PRICE_CLOTHING);
    registerSetter(L, "TRADE_PROFIT_MARGINS", GlobalConstants_set_TRADE_PROFIT_MARGINS);
    registerSetter(L, "PRICE_LOOT_GEAR", GlobalConstants_set_PRICE_LOOT_GEAR);
    registerSetter(L, "PRICE_LOOT_ITEMS", GlobalConstants_set_PRICE_LOOT_ITEMS);
    registerSetter(L, "PRICE_LOOT_PLAYER_CRAFTED_ARMOUR", GlobalConstants_set_PRICE_LOOT_PLAYER_CRAFTED_ARMOUR);
    registerSetter(L, "PRICE_LOOT_PLAYER_CRAFTED_WEAPONS", GlobalConstants_set_PRICE_LOOT_PLAYER_CRAFTED_WEAPONS);
    registerSetter(L, "BLUEPRINT_COST_MULT", GlobalConstants_set_BLUEPRINT_COST_MULT);
    registerSetter(L, "UNIFORM_PRICE_MULT", GlobalConstants_set_UNIFORM_PRICE_MULT);
    registerSetter(L, "BLUNT_PERMANENT_DAMAGE_RATIO", GlobalConstants_set_BLUNT_PERMANENT_DAMAGE_RATIO);
    registerSetter(L, "UNARMED_DAMAGE_MULT", GlobalConstants_set_UNARMED_DAMAGE_MULT);
    registerSetter(L, "MAX_NUM_ATTACK_SLOTS", GlobalConstants_set_MAX_NUM_ATTACK_SLOTS);
    registerSetter(L, "MINIMUM_STRENGTH_XP_MULT", GlobalConstants_set_MINIMUM_STRENGTH_XP_MULT);
    registerSetter(L, "WEIGHT_STR_DIFF_1X", GlobalConstants_set_WEIGHT_STR_DIFF_1X);
    registerSetter(L, "WEIGHT_STR_DIFF_MAX", GlobalConstants_set_WEIGHT_STR_DIFF_MAX);
    registerSetter(L, "WEAPON_INVENTORY_WEIGHT_MULT", GlobalConstants_set_WEAPON_INVENTORY_WEIGHT_MULT);
    registerSetter(L, "STRENGTH_XP_RATE_FROM_WALKING", GlobalConstants_set_STRENGTH_XP_RATE_FROM_WALKING);
    registerSetter(L, "STRENGTH_XP_RATE", GlobalConstants_set_STRENGTH_XP_RATE);
    registerSetter(L, "ATHLETICS_XP_RATE", GlobalConstants_set_ATHLETICS_XP_RATE);
    registerSetter(L, "ENCUMBRANCE_BASE", GlobalConstants_set_ENCUMBRANCE_BASE);
    registerSetter(L, "CARRY_WEIGHT_MULT", GlobalConstants_set_CARRY_WEIGHT_MULT);
    registerSetter(L, "CARRY_PERSON_WEIGHT", GlobalConstants_set_CARRY_PERSON_WEIGHT);
    registerSetter(L, "MIN_MATS_FROM_DISMANTLE_01", GlobalConstants_set_MIN_MATS_FROM_DISMANTLE_01);
    registerSetter(L, "EXPERIENCE_GAIN", GlobalConstants_set_EXPERIENCE_GAIN);
    registerSetter(L, "EXPERIENCE_GAIN_1", GlobalConstants_set_EXPERIENCE_GAIN_1);
    registerSetter(L, "EXPERIENCE_GAIN_99", GlobalConstants_set_EXPERIENCE_GAIN_99);
    registerSetter(L, "RESEARCH_LEVEL_INCREASE", GlobalConstants_set_RESEARCH_LEVEL_INCREASE);
    registerSetter(L, "RESEARCH_RATE", GlobalConstants_set_RESEARCH_RATE);
    registerSetter(L, "LOCKPICK_CHANCE_MINIMUM", GlobalConstants_set_LOCKPICK_CHANCE_MINIMUM);
    registerSetter(L, "EXPERIENCE_CURVE", GlobalConstants_set_EXPERIENCE_CURVE);
    registerSetter(L, "ANIMATION_BLEND_RATE", GlobalConstants_set_ANIMATION_BLEND_RATE);
    registerSetter(L, "PRODUCTION_MULTIPLIER", GlobalConstants_set_PRODUCTION_MULTIPLIER);
    registerSetter(L, "BUILD_SPEED_MULTIPLIER", GlobalConstants_set_BUILD_SPEED_MULTIPLIER);
    registerSetter(L, "PRISON_TIME_MULT", GlobalConstants_set_PRISON_TIME_MULT);
    registerSetter(L, "TOUGHNESS_KO_POINT_MIN", GlobalConstants_set_TOUGHNESS_KO_POINT_MIN);
    registerSetter(L, "TOUGHNESS_KO_POINT_MAX", GlobalConstants_set_TOUGHNESS_KO_POINT_MAX);
    registerSetter(L, "MAX_SQUAD_SIZE", GlobalConstants_set_MAX_SQUAD_SIZE);
    registerSetter(L, "MAX_SQUADS", GlobalConstants_set_MAX_SQUADS);
    registerSetter(L, "MAX_FACTION_SIZE", GlobalConstants_set_MAX_FACTION_SIZE);
    registerSetter(L, "attackDiplomats", GlobalConstants_set_attackDiplomats);
    registerSetter(L, "APPEARANCE_RANDOM_DEVIATION", GlobalConstants_set_APPEARANCE_RANDOM_DEVIATION);
    registerSetter(L, "fogDistMax", GlobalConstants_set_fogDistMax);
    registerSetter(L, "fogDistMin", GlobalConstants_set_fogDistMin);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
