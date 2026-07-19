#include "pch.h"
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
    lua_pushcfunction(L, GlobalConstants_get_EXTRA_BLEED_FROM_BODYPARTS_MULTIPLIER);
    lua_setfield(L, -2, "EXTRA_BLEED_FROM_BODYPARTS_MULTIPLIER");
    lua_pushcfunction(L, GlobalConstants_get_BLEED_RATE_MULTIPLIER);
    lua_setfield(L, -2, "BLEED_RATE_MULTIPLIER");
    lua_pushcfunction(L, GlobalConstants_get_INITIAL_BLEED_LOSS_MULTIPLIER);
    lua_setfield(L, -2, "INITIAL_BLEED_LOSS_MULTIPLIER");
    lua_pushcfunction(L, GlobalConstants_get_BLEED_CLOT_RATE);
    lua_setfield(L, -2, "BLEED_CLOT_RATE");
    lua_pushcfunction(L, GlobalConstants_get_BLUNT_DAMAGE_1);
    lua_setfield(L, -2, "BLUNT_DAMAGE_1");
    lua_pushcfunction(L, GlobalConstants_get_BLUNT_DAMAGE_99);
    lua_setfield(L, -2, "BLUNT_DAMAGE_99");
    lua_pushcfunction(L, GlobalConstants_get_CUT_DAMAGE_1);
    lua_setfield(L, -2, "CUT_DAMAGE_1");
    lua_pushcfunction(L, GlobalConstants_get_CUT_DAMAGE_99);
    lua_setfield(L, -2, "CUT_DAMAGE_99");
    lua_pushcfunction(L, GlobalConstants_get_BOW_DAMAGE_0);
    lua_setfield(L, -2, "BOW_DAMAGE_0");
    lua_pushcfunction(L, GlobalConstants_get_BOW_DAMAGE_99);
    lua_setfield(L, -2, "BOW_DAMAGE_99");
    lua_pushcfunction(L, GlobalConstants_get_PIERCE_MULTIPLIER);
    lua_setfield(L, -2, "PIERCE_MULTIPLIER");
    lua_pushcfunction(L, GlobalConstants_get_MIN_STUMBLE_DAMAGE_MAX);
    lua_setfield(L, -2, "MIN_STUMBLE_DAMAGE_MAX");
    lua_pushcfunction(L, GlobalConstants_get_DAMAGE_RESISTANCE_MIN);
    lua_setfield(L, -2, "DAMAGE_RESISTANCE_MIN");
    lua_pushcfunction(L, GlobalConstants_get_DAMAGE_RESISTANCE_MAX);
    lua_setfield(L, -2, "DAMAGE_RESISTANCE_MAX");
    lua_pushcfunction(L, GlobalConstants_get_STUN_RECOVERY_RATE);
    lua_setfield(L, -2, "STUN_RECOVERY_RATE");
    lua_pushcfunction(L, GlobalConstants_get_BLOOD_RECOVERY_RATE);
    lua_setfield(L, -2, "BLOOD_RECOVERY_RATE");
    lua_pushcfunction(L, GlobalConstants_get_ATTACK_CHANCE_SKILL_DIFFERENCE_FACTOR);
    lua_setfield(L, -2, "ATTACK_CHANCE_SKILL_DIFFERENCE_FACTOR");
    lua_pushcfunction(L, GlobalConstants_get_BASE_BLOCK_CHANCE);
    lua_setfield(L, -2, "BASE_BLOCK_CHANCE");
    lua_pushcfunction(L, GlobalConstants_get_BLOCK_CHANCE_REDUCTION);
    lua_setfield(L, -2, "BLOCK_CHANCE_REDUCTION");
    lua_pushcfunction(L, GlobalConstants_get_BLOCK_CHANCE_INCREASE);
    lua_setfield(L, -2, "BLOCK_CHANCE_INCREASE");
    lua_pushcfunction(L, GlobalConstants_get_DEGENERATION_MULT_1);
    lua_setfield(L, -2, "DEGENERATION_MULT_1");
    lua_pushcfunction(L, GlobalConstants_get_DEGENERATION_MULT_99);
    lua_setfield(L, -2, "DEGENERATION_MULT_99");
    lua_pushcfunction(L, GlobalConstants_get_MEDIC_SPEED_MULT);
    lua_setfield(L, -2, "MEDIC_SPEED_MULT");
    lua_pushcfunction(L, GlobalConstants_get_KNOCKOUT_MULT_1);
    lua_setfield(L, -2, "KNOCKOUT_MULT_1");
    lua_pushcfunction(L, GlobalConstants_get_KNOCKOUT_MULT_99);
    lua_setfield(L, -2, "KNOCKOUT_MULT_99");
    lua_pushcfunction(L, GlobalConstants_get_KNOCKOUT_BASE_TIME);
    lua_setfield(L, -2, "KNOCKOUT_BASE_TIME");
    lua_pushcfunction(L, GlobalConstants_get_BODYPART_DEGENERATE_RATE_MULT);
    lua_setfield(L, -2, "BODYPART_DEGENERATE_RATE_MULT");
    lua_pushcfunction(L, GlobalConstants_get_BODYPART_HEAL_RATE_MULT);
    lua_setfield(L, -2, "BODYPART_HEAL_RATE_MULT");
    lua_pushcfunction(L, GlobalConstants_get_BODYPART_HEAL_RATE_MULT_RESTING);
    lua_setfield(L, -2, "BODYPART_HEAL_RATE_MULT_RESTING");
    lua_pushcfunction(L, GlobalConstants_get_XP_MEDIC_1);
    lua_setfield(L, -2, "XP_MEDIC_1");
    lua_pushcfunction(L, GlobalConstants_get_XP_MEDIC_99);
    lua_setfield(L, -2, "XP_MEDIC_99");
    lua_pushcfunction(L, GlobalConstants_get_MEDKIT_DRAIN_1);
    lua_setfield(L, -2, "MEDKIT_DRAIN_1");
    lua_pushcfunction(L, GlobalConstants_get_MEDKIT_DRAIN_99);
    lua_setfield(L, -2, "MEDKIT_DRAIN_99");
    lua_pushcfunction(L, GlobalConstants_get_ROBOT_WEAR_RATE);
    lua_setfield(L, -2, "ROBOT_WEAR_RATE");
    lua_pushcfunction(L, GlobalConstants_get_ROBOT_FIRST_AID_SPEED);
    lua_setfield(L, -2, "ROBOT_FIRST_AID_SPEED");
    lua_pushcfunction(L, GlobalConstants_get_STARVATION_TIME_HRS);
    lua_setfield(L, -2, "STARVATION_TIME_HRS");
    lua_pushcfunction(L, GlobalConstants_get_FED_RECOVERY_RATE_MULT);
    lua_setfield(L, -2, "FED_RECOVERY_RATE_MULT");
    lua_pushcfunction(L, GlobalConstants_get_BED_HUNGER_RATE);
    lua_setfield(L, -2, "BED_HUNGER_RATE");
    lua_pushcfunction(L, GlobalConstants_get_ENCUMBRANCE_HUNGER_RATE);
    lua_setfield(L, -2, "ENCUMBRANCE_HUNGER_RATE");
    lua_pushcfunction(L, GlobalConstants_get_FOOD_QUALITY_MULT);
    lua_setfield(L, -2, "FOOD_QUALITY_MULT");
    lua_pushcfunction(L, GlobalConstants_get_FOOD_PRICE_MULT);
    lua_setfield(L, -2, "FOOD_PRICE_MULT");
    lua_pushcfunction(L, GlobalConstants_get_SKILL_DIFFERENCE_XP_RATIO_MULT_BONUS);
    lua_setfield(L, -2, "SKILL_DIFFERENCE_XP_RATIO_MULT_BONUS");
    lua_pushcfunction(L, GlobalConstants_get_SKILL_DIFFERENCE_XP_RATIO_MULT_PENALTY);
    lua_setfield(L, -2, "SKILL_DIFFERENCE_XP_RATIO_MULT_PENALTY");
    lua_pushcfunction(L, GlobalConstants_get_XP_HIT_THEM);
    lua_setfield(L, -2, "XP_HIT_THEM");
    lua_pushcfunction(L, GlobalConstants_get_XP_HIT_ME);
    lua_setfield(L, -2, "XP_HIT_ME");
    lua_pushcfunction(L, GlobalConstants_get_XP_BLOCKED_THEM);
    lua_setfield(L, -2, "XP_BLOCKED_THEM");
    lua_pushcfunction(L, GlobalConstants_get_XP_BLOCKED_ME);
    lua_setfield(L, -2, "XP_BLOCKED_ME");
    lua_pushcfunction(L, GlobalConstants_get_XP_FIRSTAID);
    lua_setfield(L, -2, "XP_FIRSTAID");
    lua_pushcfunction(L, GlobalConstants_get_XP_FITNESS);
    lua_setfield(L, -2, "XP_FITNESS");
    lua_pushcfunction(L, GlobalConstants_get_XP_TOUGHNESS);
    lua_setfield(L, -2, "XP_TOUGHNESS");
    lua_pushcfunction(L, GlobalConstants_get_PRICE_ROBOTICS);
    lua_setfield(L, -2, "PRICE_ROBOTICS");
    lua_pushcfunction(L, GlobalConstants_get_PRICE_CROSSBOWS);
    lua_setfield(L, -2, "PRICE_CROSSBOWS");
    lua_pushcfunction(L, GlobalConstants_get_PRICE_ARMOUR);
    lua_setfield(L, -2, "PRICE_ARMOUR");
    lua_pushcfunction(L, GlobalConstants_get_PRICE_SWORDS);
    lua_setfield(L, -2, "PRICE_SWORDS");
    lua_pushcfunction(L, GlobalConstants_get_PRICE_TRADE);
    lua_setfield(L, -2, "PRICE_TRADE");
    lua_pushcfunction(L, GlobalConstants_get_PRICE_GLOBAL_MULT);
    lua_setfield(L, -2, "PRICE_GLOBAL_MULT");
    lua_pushcfunction(L, GlobalConstants_get_PRICE_CLOTHING);
    lua_setfield(L, -2, "PRICE_CLOTHING");
    lua_pushcfunction(L, GlobalConstants_get_TRADE_PROFIT_MARGINS);
    lua_setfield(L, -2, "TRADE_PROFIT_MARGINS");
    lua_pushcfunction(L, GlobalConstants_get_PRICE_LOOT_GEAR);
    lua_setfield(L, -2, "PRICE_LOOT_GEAR");
    lua_pushcfunction(L, GlobalConstants_get_PRICE_LOOT_ITEMS);
    lua_setfield(L, -2, "PRICE_LOOT_ITEMS");
    lua_pushcfunction(L, GlobalConstants_get_PRICE_LOOT_PLAYER_CRAFTED_ARMOUR);
    lua_setfield(L, -2, "PRICE_LOOT_PLAYER_CRAFTED_ARMOUR");
    lua_pushcfunction(L, GlobalConstants_get_PRICE_LOOT_PLAYER_CRAFTED_WEAPONS);
    lua_setfield(L, -2, "PRICE_LOOT_PLAYER_CRAFTED_WEAPONS");
    lua_pushcfunction(L, GlobalConstants_get_BLUEPRINT_COST_MULT);
    lua_setfield(L, -2, "BLUEPRINT_COST_MULT");
    lua_pushcfunction(L, GlobalConstants_get_UNIFORM_PRICE_MULT);
    lua_setfield(L, -2, "UNIFORM_PRICE_MULT");
    lua_pushcfunction(L, GlobalConstants_get_BLUNT_PERMANENT_DAMAGE_RATIO);
    lua_setfield(L, -2, "BLUNT_PERMANENT_DAMAGE_RATIO");
    lua_pushcfunction(L, GlobalConstants_get_UNARMED_DAMAGE_MULT);
    lua_setfield(L, -2, "UNARMED_DAMAGE_MULT");
    lua_pushcfunction(L, GlobalConstants_get_MAX_NUM_ATTACK_SLOTS);
    lua_setfield(L, -2, "MAX_NUM_ATTACK_SLOTS");
    lua_pushcfunction(L, GlobalConstants_get_MINIMUM_STRENGTH_XP_MULT);
    lua_setfield(L, -2, "MINIMUM_STRENGTH_XP_MULT");
    lua_pushcfunction(L, GlobalConstants_get_WEIGHT_STR_DIFF_1X);
    lua_setfield(L, -2, "WEIGHT_STR_DIFF_1X");
    lua_pushcfunction(L, GlobalConstants_get_WEIGHT_STR_DIFF_MAX);
    lua_setfield(L, -2, "WEIGHT_STR_DIFF_MAX");
    lua_pushcfunction(L, GlobalConstants_get_WEAPON_INVENTORY_WEIGHT_MULT);
    lua_setfield(L, -2, "WEAPON_INVENTORY_WEIGHT_MULT");
    lua_pushcfunction(L, GlobalConstants_get_STRENGTH_XP_RATE_FROM_WALKING);
    lua_setfield(L, -2, "STRENGTH_XP_RATE_FROM_WALKING");
    lua_pushcfunction(L, GlobalConstants_get_STRENGTH_XP_RATE);
    lua_setfield(L, -2, "STRENGTH_XP_RATE");
    lua_pushcfunction(L, GlobalConstants_get_ATHLETICS_XP_RATE);
    lua_setfield(L, -2, "ATHLETICS_XP_RATE");
    lua_pushcfunction(L, GlobalConstants_get_ENCUMBRANCE_BASE);
    lua_setfield(L, -2, "ENCUMBRANCE_BASE");
    lua_pushcfunction(L, GlobalConstants_get_CARRY_WEIGHT_MULT);
    lua_setfield(L, -2, "CARRY_WEIGHT_MULT");
    lua_pushcfunction(L, GlobalConstants_get_CARRY_PERSON_WEIGHT);
    lua_setfield(L, -2, "CARRY_PERSON_WEIGHT");
    lua_pushcfunction(L, GlobalConstants_get_MIN_MATS_FROM_DISMANTLE_01);
    lua_setfield(L, -2, "MIN_MATS_FROM_DISMANTLE_01");
    lua_pushcfunction(L, GlobalConstants_get_EXPERIENCE_GAIN);
    lua_setfield(L, -2, "EXPERIENCE_GAIN");
    lua_pushcfunction(L, GlobalConstants_get_EXPERIENCE_GAIN_1);
    lua_setfield(L, -2, "EXPERIENCE_GAIN_1");
    lua_pushcfunction(L, GlobalConstants_get_EXPERIENCE_GAIN_99);
    lua_setfield(L, -2, "EXPERIENCE_GAIN_99");
    lua_pushcfunction(L, GlobalConstants_get_RESEARCH_LEVEL_INCREASE);
    lua_setfield(L, -2, "RESEARCH_LEVEL_INCREASE");
    lua_pushcfunction(L, GlobalConstants_get_RESEARCH_RATE);
    lua_setfield(L, -2, "RESEARCH_RATE");
    lua_pushcfunction(L, GlobalConstants_get_LOCKPICK_CHANCE_MINIMUM);
    lua_setfield(L, -2, "LOCKPICK_CHANCE_MINIMUM");
    lua_pushcfunction(L, GlobalConstants_get_EXPERIENCE_CURVE);
    lua_setfield(L, -2, "EXPERIENCE_CURVE");
    lua_pushcfunction(L, GlobalConstants_get_ANIMATION_BLEND_RATE);
    lua_setfield(L, -2, "ANIMATION_BLEND_RATE");
    lua_pushcfunction(L, GlobalConstants_get_PRODUCTION_MULTIPLIER);
    lua_setfield(L, -2, "PRODUCTION_MULTIPLIER");
    lua_pushcfunction(L, GlobalConstants_get_BUILD_SPEED_MULTIPLIER);
    lua_setfield(L, -2, "BUILD_SPEED_MULTIPLIER");
    lua_pushcfunction(L, GlobalConstants_get_PRISON_TIME_MULT);
    lua_setfield(L, -2, "PRISON_TIME_MULT");
    lua_pushcfunction(L, GlobalConstants_get_TOUGHNESS_KO_POINT_MIN);
    lua_setfield(L, -2, "TOUGHNESS_KO_POINT_MIN");
    lua_pushcfunction(L, GlobalConstants_get_TOUGHNESS_KO_POINT_MAX);
    lua_setfield(L, -2, "TOUGHNESS_KO_POINT_MAX");
    lua_pushcfunction(L, GlobalConstants_get_MAX_SQUAD_SIZE);
    lua_setfield(L, -2, "MAX_SQUAD_SIZE");
    lua_pushcfunction(L, GlobalConstants_get_MAX_SQUADS);
    lua_setfield(L, -2, "MAX_SQUADS");
    lua_pushcfunction(L, GlobalConstants_get_MAX_FACTION_SIZE);
    lua_setfield(L, -2, "MAX_FACTION_SIZE");
    lua_pushcfunction(L, GlobalConstants_get_attackDiplomats);
    lua_setfield(L, -2, "attackDiplomats");
    lua_pushcfunction(L, GlobalConstants_get_settings);
    lua_setfield(L, -2, "settings");
    lua_pushcfunction(L, GlobalConstants_get_APPEARANCE_RANDOM_DEVIATION);
    lua_setfield(L, -2, "APPEARANCE_RANDOM_DEVIATION");
    lua_pushcfunction(L, GlobalConstants_get_fogDistMax);
    lua_setfield(L, -2, "fogDistMax");
    lua_pushcfunction(L, GlobalConstants_get_fogDistMin);
    lua_setfield(L, -2, "fogDistMin");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, GlobalConstants_set_EXTRA_BLEED_FROM_BODYPARTS_MULTIPLIER);
    lua_setfield(L, -2, "EXTRA_BLEED_FROM_BODYPARTS_MULTIPLIER");
    lua_pushcfunction(L, GlobalConstants_set_BLEED_RATE_MULTIPLIER);
    lua_setfield(L, -2, "BLEED_RATE_MULTIPLIER");
    lua_pushcfunction(L, GlobalConstants_set_INITIAL_BLEED_LOSS_MULTIPLIER);
    lua_setfield(L, -2, "INITIAL_BLEED_LOSS_MULTIPLIER");
    lua_pushcfunction(L, GlobalConstants_set_BLEED_CLOT_RATE);
    lua_setfield(L, -2, "BLEED_CLOT_RATE");
    lua_pushcfunction(L, GlobalConstants_set_BLUNT_DAMAGE_1);
    lua_setfield(L, -2, "BLUNT_DAMAGE_1");
    lua_pushcfunction(L, GlobalConstants_set_BLUNT_DAMAGE_99);
    lua_setfield(L, -2, "BLUNT_DAMAGE_99");
    lua_pushcfunction(L, GlobalConstants_set_CUT_DAMAGE_1);
    lua_setfield(L, -2, "CUT_DAMAGE_1");
    lua_pushcfunction(L, GlobalConstants_set_CUT_DAMAGE_99);
    lua_setfield(L, -2, "CUT_DAMAGE_99");
    lua_pushcfunction(L, GlobalConstants_set_BOW_DAMAGE_0);
    lua_setfield(L, -2, "BOW_DAMAGE_0");
    lua_pushcfunction(L, GlobalConstants_set_BOW_DAMAGE_99);
    lua_setfield(L, -2, "BOW_DAMAGE_99");
    lua_pushcfunction(L, GlobalConstants_set_PIERCE_MULTIPLIER);
    lua_setfield(L, -2, "PIERCE_MULTIPLIER");
    lua_pushcfunction(L, GlobalConstants_set_MIN_STUMBLE_DAMAGE_MAX);
    lua_setfield(L, -2, "MIN_STUMBLE_DAMAGE_MAX");
    lua_pushcfunction(L, GlobalConstants_set_DAMAGE_RESISTANCE_MIN);
    lua_setfield(L, -2, "DAMAGE_RESISTANCE_MIN");
    lua_pushcfunction(L, GlobalConstants_set_DAMAGE_RESISTANCE_MAX);
    lua_setfield(L, -2, "DAMAGE_RESISTANCE_MAX");
    lua_pushcfunction(L, GlobalConstants_set_STUN_RECOVERY_RATE);
    lua_setfield(L, -2, "STUN_RECOVERY_RATE");
    lua_pushcfunction(L, GlobalConstants_set_BLOOD_RECOVERY_RATE);
    lua_setfield(L, -2, "BLOOD_RECOVERY_RATE");
    lua_pushcfunction(L, GlobalConstants_set_ATTACK_CHANCE_SKILL_DIFFERENCE_FACTOR);
    lua_setfield(L, -2, "ATTACK_CHANCE_SKILL_DIFFERENCE_FACTOR");
    lua_pushcfunction(L, GlobalConstants_set_BASE_BLOCK_CHANCE);
    lua_setfield(L, -2, "BASE_BLOCK_CHANCE");
    lua_pushcfunction(L, GlobalConstants_set_BLOCK_CHANCE_REDUCTION);
    lua_setfield(L, -2, "BLOCK_CHANCE_REDUCTION");
    lua_pushcfunction(L, GlobalConstants_set_BLOCK_CHANCE_INCREASE);
    lua_setfield(L, -2, "BLOCK_CHANCE_INCREASE");
    lua_pushcfunction(L, GlobalConstants_set_DEGENERATION_MULT_1);
    lua_setfield(L, -2, "DEGENERATION_MULT_1");
    lua_pushcfunction(L, GlobalConstants_set_DEGENERATION_MULT_99);
    lua_setfield(L, -2, "DEGENERATION_MULT_99");
    lua_pushcfunction(L, GlobalConstants_set_MEDIC_SPEED_MULT);
    lua_setfield(L, -2, "MEDIC_SPEED_MULT");
    lua_pushcfunction(L, GlobalConstants_set_KNOCKOUT_MULT_1);
    lua_setfield(L, -2, "KNOCKOUT_MULT_1");
    lua_pushcfunction(L, GlobalConstants_set_KNOCKOUT_MULT_99);
    lua_setfield(L, -2, "KNOCKOUT_MULT_99");
    lua_pushcfunction(L, GlobalConstants_set_KNOCKOUT_BASE_TIME);
    lua_setfield(L, -2, "KNOCKOUT_BASE_TIME");
    lua_pushcfunction(L, GlobalConstants_set_BODYPART_DEGENERATE_RATE_MULT);
    lua_setfield(L, -2, "BODYPART_DEGENERATE_RATE_MULT");
    lua_pushcfunction(L, GlobalConstants_set_BODYPART_HEAL_RATE_MULT);
    lua_setfield(L, -2, "BODYPART_HEAL_RATE_MULT");
    lua_pushcfunction(L, GlobalConstants_set_BODYPART_HEAL_RATE_MULT_RESTING);
    lua_setfield(L, -2, "BODYPART_HEAL_RATE_MULT_RESTING");
    lua_pushcfunction(L, GlobalConstants_set_XP_MEDIC_1);
    lua_setfield(L, -2, "XP_MEDIC_1");
    lua_pushcfunction(L, GlobalConstants_set_XP_MEDIC_99);
    lua_setfield(L, -2, "XP_MEDIC_99");
    lua_pushcfunction(L, GlobalConstants_set_MEDKIT_DRAIN_1);
    lua_setfield(L, -2, "MEDKIT_DRAIN_1");
    lua_pushcfunction(L, GlobalConstants_set_MEDKIT_DRAIN_99);
    lua_setfield(L, -2, "MEDKIT_DRAIN_99");
    lua_pushcfunction(L, GlobalConstants_set_ROBOT_WEAR_RATE);
    lua_setfield(L, -2, "ROBOT_WEAR_RATE");
    lua_pushcfunction(L, GlobalConstants_set_ROBOT_FIRST_AID_SPEED);
    lua_setfield(L, -2, "ROBOT_FIRST_AID_SPEED");
    lua_pushcfunction(L, GlobalConstants_set_STARVATION_TIME_HRS);
    lua_setfield(L, -2, "STARVATION_TIME_HRS");
    lua_pushcfunction(L, GlobalConstants_set_FED_RECOVERY_RATE_MULT);
    lua_setfield(L, -2, "FED_RECOVERY_RATE_MULT");
    lua_pushcfunction(L, GlobalConstants_set_BED_HUNGER_RATE);
    lua_setfield(L, -2, "BED_HUNGER_RATE");
    lua_pushcfunction(L, GlobalConstants_set_ENCUMBRANCE_HUNGER_RATE);
    lua_setfield(L, -2, "ENCUMBRANCE_HUNGER_RATE");
    lua_pushcfunction(L, GlobalConstants_set_FOOD_QUALITY_MULT);
    lua_setfield(L, -2, "FOOD_QUALITY_MULT");
    lua_pushcfunction(L, GlobalConstants_set_FOOD_PRICE_MULT);
    lua_setfield(L, -2, "FOOD_PRICE_MULT");
    lua_pushcfunction(L, GlobalConstants_set_SKILL_DIFFERENCE_XP_RATIO_MULT_BONUS);
    lua_setfield(L, -2, "SKILL_DIFFERENCE_XP_RATIO_MULT_BONUS");
    lua_pushcfunction(L, GlobalConstants_set_SKILL_DIFFERENCE_XP_RATIO_MULT_PENALTY);
    lua_setfield(L, -2, "SKILL_DIFFERENCE_XP_RATIO_MULT_PENALTY");
    lua_pushcfunction(L, GlobalConstants_set_XP_HIT_THEM);
    lua_setfield(L, -2, "XP_HIT_THEM");
    lua_pushcfunction(L, GlobalConstants_set_XP_HIT_ME);
    lua_setfield(L, -2, "XP_HIT_ME");
    lua_pushcfunction(L, GlobalConstants_set_XP_BLOCKED_THEM);
    lua_setfield(L, -2, "XP_BLOCKED_THEM");
    lua_pushcfunction(L, GlobalConstants_set_XP_BLOCKED_ME);
    lua_setfield(L, -2, "XP_BLOCKED_ME");
    lua_pushcfunction(L, GlobalConstants_set_XP_FIRSTAID);
    lua_setfield(L, -2, "XP_FIRSTAID");
    lua_pushcfunction(L, GlobalConstants_set_XP_FITNESS);
    lua_setfield(L, -2, "XP_FITNESS");
    lua_pushcfunction(L, GlobalConstants_set_XP_TOUGHNESS);
    lua_setfield(L, -2, "XP_TOUGHNESS");
    lua_pushcfunction(L, GlobalConstants_set_PRICE_ROBOTICS);
    lua_setfield(L, -2, "PRICE_ROBOTICS");
    lua_pushcfunction(L, GlobalConstants_set_PRICE_CROSSBOWS);
    lua_setfield(L, -2, "PRICE_CROSSBOWS");
    lua_pushcfunction(L, GlobalConstants_set_PRICE_ARMOUR);
    lua_setfield(L, -2, "PRICE_ARMOUR");
    lua_pushcfunction(L, GlobalConstants_set_PRICE_SWORDS);
    lua_setfield(L, -2, "PRICE_SWORDS");
    lua_pushcfunction(L, GlobalConstants_set_PRICE_TRADE);
    lua_setfield(L, -2, "PRICE_TRADE");
    lua_pushcfunction(L, GlobalConstants_set_PRICE_GLOBAL_MULT);
    lua_setfield(L, -2, "PRICE_GLOBAL_MULT");
    lua_pushcfunction(L, GlobalConstants_set_PRICE_CLOTHING);
    lua_setfield(L, -2, "PRICE_CLOTHING");
    lua_pushcfunction(L, GlobalConstants_set_TRADE_PROFIT_MARGINS);
    lua_setfield(L, -2, "TRADE_PROFIT_MARGINS");
    lua_pushcfunction(L, GlobalConstants_set_PRICE_LOOT_GEAR);
    lua_setfield(L, -2, "PRICE_LOOT_GEAR");
    lua_pushcfunction(L, GlobalConstants_set_PRICE_LOOT_ITEMS);
    lua_setfield(L, -2, "PRICE_LOOT_ITEMS");
    lua_pushcfunction(L, GlobalConstants_set_PRICE_LOOT_PLAYER_CRAFTED_ARMOUR);
    lua_setfield(L, -2, "PRICE_LOOT_PLAYER_CRAFTED_ARMOUR");
    lua_pushcfunction(L, GlobalConstants_set_PRICE_LOOT_PLAYER_CRAFTED_WEAPONS);
    lua_setfield(L, -2, "PRICE_LOOT_PLAYER_CRAFTED_WEAPONS");
    lua_pushcfunction(L, GlobalConstants_set_BLUEPRINT_COST_MULT);
    lua_setfield(L, -2, "BLUEPRINT_COST_MULT");
    lua_pushcfunction(L, GlobalConstants_set_UNIFORM_PRICE_MULT);
    lua_setfield(L, -2, "UNIFORM_PRICE_MULT");
    lua_pushcfunction(L, GlobalConstants_set_BLUNT_PERMANENT_DAMAGE_RATIO);
    lua_setfield(L, -2, "BLUNT_PERMANENT_DAMAGE_RATIO");
    lua_pushcfunction(L, GlobalConstants_set_UNARMED_DAMAGE_MULT);
    lua_setfield(L, -2, "UNARMED_DAMAGE_MULT");
    lua_pushcfunction(L, GlobalConstants_set_MAX_NUM_ATTACK_SLOTS);
    lua_setfield(L, -2, "MAX_NUM_ATTACK_SLOTS");
    lua_pushcfunction(L, GlobalConstants_set_MINIMUM_STRENGTH_XP_MULT);
    lua_setfield(L, -2, "MINIMUM_STRENGTH_XP_MULT");
    lua_pushcfunction(L, GlobalConstants_set_WEIGHT_STR_DIFF_1X);
    lua_setfield(L, -2, "WEIGHT_STR_DIFF_1X");
    lua_pushcfunction(L, GlobalConstants_set_WEIGHT_STR_DIFF_MAX);
    lua_setfield(L, -2, "WEIGHT_STR_DIFF_MAX");
    lua_pushcfunction(L, GlobalConstants_set_WEAPON_INVENTORY_WEIGHT_MULT);
    lua_setfield(L, -2, "WEAPON_INVENTORY_WEIGHT_MULT");
    lua_pushcfunction(L, GlobalConstants_set_STRENGTH_XP_RATE_FROM_WALKING);
    lua_setfield(L, -2, "STRENGTH_XP_RATE_FROM_WALKING");
    lua_pushcfunction(L, GlobalConstants_set_STRENGTH_XP_RATE);
    lua_setfield(L, -2, "STRENGTH_XP_RATE");
    lua_pushcfunction(L, GlobalConstants_set_ATHLETICS_XP_RATE);
    lua_setfield(L, -2, "ATHLETICS_XP_RATE");
    lua_pushcfunction(L, GlobalConstants_set_ENCUMBRANCE_BASE);
    lua_setfield(L, -2, "ENCUMBRANCE_BASE");
    lua_pushcfunction(L, GlobalConstants_set_CARRY_WEIGHT_MULT);
    lua_setfield(L, -2, "CARRY_WEIGHT_MULT");
    lua_pushcfunction(L, GlobalConstants_set_CARRY_PERSON_WEIGHT);
    lua_setfield(L, -2, "CARRY_PERSON_WEIGHT");
    lua_pushcfunction(L, GlobalConstants_set_MIN_MATS_FROM_DISMANTLE_01);
    lua_setfield(L, -2, "MIN_MATS_FROM_DISMANTLE_01");
    lua_pushcfunction(L, GlobalConstants_set_EXPERIENCE_GAIN);
    lua_setfield(L, -2, "EXPERIENCE_GAIN");
    lua_pushcfunction(L, GlobalConstants_set_EXPERIENCE_GAIN_1);
    lua_setfield(L, -2, "EXPERIENCE_GAIN_1");
    lua_pushcfunction(L, GlobalConstants_set_EXPERIENCE_GAIN_99);
    lua_setfield(L, -2, "EXPERIENCE_GAIN_99");
    lua_pushcfunction(L, GlobalConstants_set_RESEARCH_LEVEL_INCREASE);
    lua_setfield(L, -2, "RESEARCH_LEVEL_INCREASE");
    lua_pushcfunction(L, GlobalConstants_set_RESEARCH_RATE);
    lua_setfield(L, -2, "RESEARCH_RATE");
    lua_pushcfunction(L, GlobalConstants_set_LOCKPICK_CHANCE_MINIMUM);
    lua_setfield(L, -2, "LOCKPICK_CHANCE_MINIMUM");
    lua_pushcfunction(L, GlobalConstants_set_EXPERIENCE_CURVE);
    lua_setfield(L, -2, "EXPERIENCE_CURVE");
    lua_pushcfunction(L, GlobalConstants_set_ANIMATION_BLEND_RATE);
    lua_setfield(L, -2, "ANIMATION_BLEND_RATE");
    lua_pushcfunction(L, GlobalConstants_set_PRODUCTION_MULTIPLIER);
    lua_setfield(L, -2, "PRODUCTION_MULTIPLIER");
    lua_pushcfunction(L, GlobalConstants_set_BUILD_SPEED_MULTIPLIER);
    lua_setfield(L, -2, "BUILD_SPEED_MULTIPLIER");
    lua_pushcfunction(L, GlobalConstants_set_PRISON_TIME_MULT);
    lua_setfield(L, -2, "PRISON_TIME_MULT");
    lua_pushcfunction(L, GlobalConstants_set_TOUGHNESS_KO_POINT_MIN);
    lua_setfield(L, -2, "TOUGHNESS_KO_POINT_MIN");
    lua_pushcfunction(L, GlobalConstants_set_TOUGHNESS_KO_POINT_MAX);
    lua_setfield(L, -2, "TOUGHNESS_KO_POINT_MAX");
    lua_pushcfunction(L, GlobalConstants_set_MAX_SQUAD_SIZE);
    lua_setfield(L, -2, "MAX_SQUAD_SIZE");
    lua_pushcfunction(L, GlobalConstants_set_MAX_SQUADS);
    lua_setfield(L, -2, "MAX_SQUADS");
    lua_pushcfunction(L, GlobalConstants_set_MAX_FACTION_SIZE);
    lua_setfield(L, -2, "MAX_FACTION_SIZE");
    lua_pushcfunction(L, GlobalConstants_set_attackDiplomats);
    lua_setfield(L, -2, "attackDiplomats");
    lua_pushcfunction(L, GlobalConstants_set_APPEARANCE_RANDOM_DEVIATION);
    lua_setfield(L, -2, "APPEARANCE_RANDOM_DEVIATION");
    lua_pushcfunction(L, GlobalConstants_set_fogDistMax);
    lua_setfield(L, -2, "fogDistMax");
    lua_pushcfunction(L, GlobalConstants_set_fogDistMin);
    lua_setfield(L, -2, "fogDistMin");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
