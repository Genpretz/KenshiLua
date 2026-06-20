#include "pch.h"
#include "Bindings/System/MedicalSystemBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/MedicalSystem.h>

namespace KenshiLua
{

    void MedicalSystemEnumBinding::registerLimbState(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, LimbState::LIMB_ORIGINAL);
        lua_setfield(L, -2, "LIMB_ORIGINAL");
        lua_pushinteger(L, LimbState::LIMB_ORIGINAL);
        lua_setfield(L, -2, "ORIGINAL");

        lua_pushinteger(L, LimbState::LIMB_STUMP);
        lua_setfield(L, -2, "LIMB_STUMP");
        lua_pushinteger(L, LimbState::LIMB_STUMP);
        lua_setfield(L, -2, "STUMP");

        lua_pushinteger(L, LimbState::LIMB_REPLACED);
        lua_setfield(L, -2, "LIMB_REPLACED");
        lua_pushinteger(L, LimbState::LIMB_REPLACED);
        lua_setfield(L, -2, "REPLACED");

        lua_pushinteger(L, LimbState::LIMB_CRUSHED);
        lua_setfield(L, -2, "LIMB_CRUSHED");
        lua_pushinteger(L, LimbState::LIMB_CRUSHED);
        lua_setfield(L, -2, "CRUSHED");

        lua_setglobal(L, "LimbState");
    }

    void MedicalSystemEnumBinding::registerRobotLimbs(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, RobotLimbs::Limb::LEFT_ARM);
        lua_setfield(L, -2, "LEFT_ARM");

        lua_pushinteger(L, RobotLimbs::Limb::RIGHT_ARM);
        lua_setfield(L, -2, "RIGHT_ARM");

        lua_pushinteger(L, RobotLimbs::Limb::LEFT_LEG);
        lua_setfield(L, -2, "LEFT_LEG");

        lua_pushinteger(L, RobotLimbs::Limb::RIGHT_LEG);
        lua_setfield(L, -2, "RIGHT_LEG");

        lua_pushinteger(L, RobotLimbs::Limb::NULL_LIMB);
        lua_setfield(L, -2, "NULL_LIMB");

        lua_setglobal(L, "RobotLimbs");
    }

    void MedicalSystemEnumBinding::registerAttackDirection(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, AttackDirection::Enum::FRONT);
        lua_setfield(L, -2, "FRONT");

        lua_pushinteger(L, AttackDirection::Enum::BACK);
        lua_setfield(L, -2, "BACK");

        lua_pushinteger(L, AttackDirection::Enum::LEFT);
        lua_setfield(L, -2, "LEFT");

        lua_pushinteger(L, AttackDirection::Enum::RIGHT);
        lua_setfield(L, -2, "RIGHT");

        lua_pushinteger(L, AttackDirection::Enum::TOP);
        lua_setfield(L, -2, "TOP");

        lua_pushinteger(L, AttackDirection::Enum::BOTTOM);
        lua_setfield(L, -2, "BOTTOM");

        lua_setglobal(L, "AttackDirection");
    }

    void MedicalSystemEnumBinding::registerHealthPartStatus(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, MedicalSystem::HealthPartStatus::PART_TORSO);
        lua_setfield(L, -2, "PART_TORSO");
        lua_pushinteger(L, MedicalSystem::HealthPartStatus::PART_TORSO);
        lua_setfield(L, -2, "TORSO");

        lua_pushinteger(L, MedicalSystem::HealthPartStatus::PartType::PART_LEG);
        lua_setfield(L, -2, "PART_LEG");
        lua_pushinteger(L, MedicalSystem::HealthPartStatus::PartType::PART_LEG);
        lua_setfield(L, -2, "LEG");

        lua_pushinteger(L, MedicalSystem::HealthPartStatus::PartType::PART_ARM);
        lua_setfield(L, -2, "PART_ARM");
        lua_pushinteger(L, MedicalSystem::HealthPartStatus::PartType::PART_ARM);
        lua_setfield(L, -2, "ARM");

        lua_pushinteger(L, MedicalSystem::HealthPartStatus::PartType::PART_HEAD);
        lua_setfield(L, -2, "PART_HEAD");
        lua_pushinteger(L, MedicalSystem::HealthPartStatus::PartType::PART_HEAD);
        lua_setfield(L, -2, "HEAD");

        lua_setglobal(L, "HealthPartStatus");
    }

    void MedicalSystemEnumBinding::registerCollapseStage(lua_State* L)
    {
        lua_newtable(L);

        lua_pushinteger(L, MedicalSystem::CollapseStage::COLLAPSE_NONE);
        lua_setfield(L, -2, "COLLAPSE_NONE");
            lua_pushinteger(L, MedicalSystem::CollapseStage::COLLAPSE_NONE);
        lua_setfield(L, -2, "NONE");

        lua_pushinteger(L, MedicalSystem::CollapseStage::COLLAPSE_BUT_NO_RAGDOLL);
        lua_setfield(L, -2, "COLLAPSE_BUT_NO_RAGDOLL");
        lua_pushinteger(L, MedicalSystem::CollapseStage::COLLAPSE_BUT_NO_RAGDOLL);
        lua_setfield(L, -2, "BUT_NO_RAGDOLL");

        lua_pushinteger(L, MedicalSystem::CollapseStage::COLLAPSE_KO);
        lua_setfield(L, -2, "COLLAPSE_KO");
        lua_pushinteger(L, MedicalSystem::CollapseStage::COLLAPSE_KO);
        lua_setfield(L, -2, "KO");

        lua_setglobal(L, "CollapseStage");
    }

    void MedicalSystemEnumBinding::registerBinding(lua_State* L)
    {
        registerLimbState(L);
        registerRobotLimbs(L);
        registerAttackDirection(L);
        registerHealthPartStatus(L);
        registerCollapseStage(L);
    }

    static MedicalSystem* getM(lua_State* L, int idx)
    {
        return checkObject<MedicalSystem>(L, idx, MedicalSystemBinding::getMetatableName());
    }

    int MedicalSystemBinding::gc(lua_State* L) { return noopGc(L); }

    int MedicalSystemBinding::index(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);

        // 1. Check the metatable first so obj:method() syntax continues to work.
        luaL_getmetatable(L, MedicalSystemBinding::getMetatableName());
        lua_getfield(L, -1, key);
        if (!lua_isnil(L, -1))
            return 1;   // found a method - return it
        lua_pop(L, 2);  // pop nil result + metatable

        // 2. Fall through to raw member variable access.
        MedicalSystem* m = getM(L, 1);
        if (!m) { lua_pushnil(L); return 1; }

        // --- float members ---
        if (strcmp(key, "blood") == 0) { lua_pushnumber(L, m->blood); return 1; }
        if (strcmp(key, "hunger") == 0) { lua_pushnumber(L, m->hunger); return 1; }
        if (strcmp(key, "fed") == 0) { lua_pushnumber(L, m->fed); return 1; }
        // lua formatted aliases
        if (strcmp(key, "extra_bloodloss_from_bodyparts") == 0) { lua_pushnumber(L, m->extraBloodLossFromBodyparts); return 1; }
        if (strcmp(key, "current_bleed_rate") == 0) { lua_pushnumber(L, m->currentBleedRate); return 1; }
        if (strcmp(key, "knockout_timer") == 0) { lua_pushnumber(L, m->knockoutTimer); return 1; }
        if (strcmp(key, "worst_damage") == 0) { lua_pushnumber(L, m->worstDamage); return 1; }
        if (strcmp(key, "needs_firstaid_scoretotal_robot") == 0) { lua_pushnumber(L, m->needsFirstAidScoreTotal_robot); return 1; }
        if (strcmp(key, "needs_firstaid_scoretotal_fleshy") == 0) { lua_pushnumber(L, m->needsFirstAidScoreTotal_fleshy); return 1; }
        if (strcmp(key, "rested_state") == 0) { lua_pushnumber(L, m->restedState); return 1; }
        if (strcmp(key, "stealth_hinderance") == 0) { lua_pushnumber(L, m->stealthHinderance); return 1; }
        if (strcmp(key, "part_best_arm") == 0) { lua_pushnumber(L, m->partBestArm); return 1; }
        if (strcmp(key, "part_head") == 0) { lua_pushnumber(L, m->partHead); return 1; }
        if (strcmp(key, "part_worst_torso") == 0) { lua_pushnumber(L, m->partWorstTorso); return 1; }
        if (strcmp(key, "dazed_or_alert") == 0) { lua_pushnumber(L, m->dazedOrAlert); return 1; }
        if (strcmp(key, "current_weather_affect_strength") == 0) { lua_pushnumber(L, m->currentWeatherAffectStrength); return 1; }
        if (strcmp(key, "next_KO_time") == 0) { lua_pushnumber(L, m->nextKOTime); return 1; }
        // c++ original naming
        if (strcmp(key, "extraBloodLossFromBodyparts") == 0) { lua_pushnumber(L, m->extraBloodLossFromBodyparts); return 1; }
        if (strcmp(key, "currentBleedRate") == 0) { lua_pushnumber(L, m->currentBleedRate); return 1; }
        if (strcmp(key, "knockoutTimer") == 0) { lua_pushnumber(L, m->knockoutTimer); return 1; }
        if (strcmp(key, "worstDamage") == 0) { lua_pushnumber(L, m->worstDamage); return 1; }
        if (strcmp(key, "needsFirstAidScoreTotal_robot") == 0) { lua_pushnumber(L, m->needsFirstAidScoreTotal_robot); return 1; }
        if (strcmp(key, "needsFirstAidScoreTotal_fleshy") == 0) { lua_pushnumber(L, m->needsFirstAidScoreTotal_fleshy); return 1; }
        if (strcmp(key, "restedState") == 0) { lua_pushnumber(L, m->restedState); return 1; }
        if (strcmp(key, "stealthHinderance") == 0) { lua_pushnumber(L, m->stealthHinderance); return 1; }
        if (strcmp(key, "partBestArm") == 0) { lua_pushnumber(L, m->partBestArm); return 1; }
        if (strcmp(key, "partHead") == 0) { lua_pushnumber(L, m->partHead); return 1; }
        if (strcmp(key, "partWorstTorso") == 0) { lua_pushnumber(L, m->partWorstTorso); return 1; }
        if (strcmp(key, "dazedOrAlert") == 0) { lua_pushnumber(L, m->dazedOrAlert); return 1; }
        if (strcmp(key, "currentWeatherAffectStrength") == 0) { lua_pushnumber(L, m->currentWeatherAffectStrength); return 1; }
        if (strcmp(key, "nextKOTime") == 0) { lua_pushnumber(L, m->nextKOTime); return 1; }

        // --- int / enum members ---
        // lua formatted aliases
        if (strcmp(key, "eaten_death_delay") == 0) { lua_pushinteger(L, m->_eatenDeathDelay); return 1; }
        // c++ original naming
        if (strcmp(key, "_eatenDeathDelay") == 0) { lua_pushinteger(L, m->_eatenDeathDelay); return 1; }
        // c++ cleaned up naming
        if (strcmp(key, "eatenDeathDelay") == 0) { lua_pushinteger(L, m->_eatenDeathDelay); return 1; }
        

        // --- boolean members ---
        // lua formatted aliases
        if (strcmp(key, "is_bloodyness_changed") == 0) { lua_pushboolean(L, m->bloodynessChanged ? 1 : 0); return 1; }
        if (strcmp(key, "is_bloodyness_cleaned_up") == 0) { lua_pushboolean(L, m->bloodynessCleanedUp ? 1 : 0); return 1; }
        if (strcmp(key, "is_crippled") == 0) { lua_pushboolean(L, m->crippled ? 1 : 0); return 1; }
        if (strcmp(key, "is_unconcious") == 0) { lua_pushboolean(L, m->unconcious ? 1 : 0); return 1; }
        if (strcmp(key, "is_sub50_KO") == 0) { lua_pushboolean(L, m->sub50KO ? 1 : 0); return 1; }
        if (strcmp(key, "has_bloodloss_trauma") == 0) { lua_pushboolean(L, m->bloodlossTrauma ? 1 : 0); return 1; }
        if (strcmp(key, "is_dead") == 0) { lua_pushboolean(L, m->dead ? 1 : 0); return 1; }
        if (strcmp(key, "is_right_arm_ok") == 0) { lua_pushboolean(L, m->rightArmOk ? 1 : 0); return 1; }
        if (strcmp(key, "is_left_arm_ok") == 0) { lua_pushboolean(L, m->leftArmOk ? 1 : 0); return 1; }
        // c++ original naming
        if (strcmp(key, "bloodynessChanged") == 0) { lua_pushboolean(L, m->bloodynessChanged ? 1 : 0); return 1; }
        if (strcmp(key, "bloodynessCleanedUp") == 0) { lua_pushboolean(L, m->bloodynessCleanedUp ? 1 : 0); return 1; }
        if (strcmp(key, "crippled") == 0) { lua_pushboolean(L, m->crippled ? 1 : 0); return 1; }
        if (strcmp(key, "unconcious") == 0) { lua_pushboolean(L, m->unconcious ? 1 : 0); return 1; }
        if (strcmp(key, "sub50KO") == 0) { lua_pushboolean(L, m->sub50KO ? 1 : 0); return 1; }
        if (strcmp(key, "bloodlossTrauma") == 0) { lua_pushboolean(L, m->bloodlossTrauma ? 1 : 0); return 1; }
        if (strcmp(key, "dead") == 0) { lua_pushboolean(L, m->dead ? 1 : 0); return 1; }
        if (strcmp(key, "rightArmOk") == 0) { lua_pushboolean(L, m->rightArmOk ? 1 : 0); return 1; }
        if (strcmp(key, "leftArmOk") == 0) { lua_pushboolean(L, m->leftArmOk ? 1 : 0); return 1; }

        // Unknown key.
        lua_pushnil(L);
        return 1;
    }

    int MedicalSystemBinding::newindex(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);
        MedicalSystem* m = checkObject<MedicalSystem>(L, 1, MedicalSystemBinding::getMetatableName());
        if (!m) return luaL_error(L, "MedicalSystem is nil");

        // --- float members ---
        // lua formatted aliases
        if (strcmp(key, "blood") == 0) { m->blood = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "hunger") == 0) { m->hunger = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "fed") == 0) { m->fed = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "extra_bloodloss_from_bodyparts") == 0) { m->extraBloodLossFromBodyparts = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "current_bleed_rate") == 0) { m->currentBleedRate = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "knockout_timer") == 0) { m->knockoutTimer = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "worst_damage") == 0) { m->worstDamage = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "needs_firstaid_scoretotal_robot") == 0) { m->needsFirstAidScoreTotal_robot = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "needs_firstaid_scoretotal_fleshy") == 0) { m->needsFirstAidScoreTotal_fleshy = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "rested_state") == 0) { m->restedState = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "stealth_hinderance") == 0) { m->stealthHinderance = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "part_best_arm") == 0) { m->partBestArm = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "part_head") == 0) { m->partHead = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "part_worst_torso") == 0) { m->partWorstTorso = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "dazed_or_alert") == 0) { m->dazedOrAlert = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "current_weather_affect_strength") == 0) { m->currentWeatherAffectStrength = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "next_KO_time") == 0) { m->nextKOTime = (float)luaL_checknumber(L, 3); return 0; }
        // c++ original naming
        if (strcmp(key, "extraBloodLossFromBodyparts") == 0) { m->extraBloodLossFromBodyparts = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "currentBleedRate") == 0) { m->currentBleedRate = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "knockoutTimer") == 0) { m->knockoutTimer = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "worstDamage") == 0) { m->worstDamage = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "needsFirstAidScoreTotal_robot") == 0) { m->needsFirstAidScoreTotal_robot = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "needsFirstAidScoreTotal_fleshy") == 0) { m->needsFirstAidScoreTotal_fleshy = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "restedState") == 0) { m->restedState = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "stealthHinderance") == 0) { m->stealthHinderance = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "partBestArm") == 0) { m->partBestArm = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "partHead") == 0) { m->partHead = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "partWorstTorso") == 0) { m->partWorstTorso = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "dazedOrAlert") == 0) { m->dazedOrAlert = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "currentWeatherAffectStrength") == 0) { m->currentWeatherAffectStrength = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "nextKOTime") == 0) { m->nextKOTime = (float)luaL_checknumber(L, 3); return 0; }

        // --- int / enum members ---
        // lua formatted aliases
        if (strcmp(key, "eaten_death_delay") == 0) { m->_eatenDeathDelay = (int)luaL_checkinteger(L, 3); return 0; }
        // c++ original naming
        if (strcmp(key, "_eatenDeathDelay") == 0) { m->_eatenDeathDelay = (int)luaL_checkinteger(L, 3); return 0; }
        // c++ cleaned up naming
        if (strcmp(key, "eatenDeathDelay") == 0) { m->_eatenDeathDelay = (int)luaL_checkinteger(L, 3); return 0; }

        // --- boolean members ---
        // lua formatted aliases
        if (strcmp(key, "is_bloodyness_changed") == 0) { m->bloodynessChanged = (lua_toboolean(L, 3) != 0); return 0; }
        if (strcmp(key, "is_bloodyness_cleaned_up") == 0) { m->bloodynessCleanedUp = (lua_toboolean(L, 3) != 0); return 0; }
        if (strcmp(key, "is_crippled") == 0) { m->crippled = (lua_toboolean(L, 3) != 0); return 0; }
        if (strcmp(key, "is_unconcious") == 0) { m->unconcious = (lua_toboolean(L, 3) != 0); return 0; }
        if (strcmp(key, "is_sub50_KO") == 0) { m->sub50KO = (lua_toboolean(L, 3) != 0); return 0; }
        if (strcmp(key, "has_bloodloss_trauma") == 0) { m->bloodlossTrauma = (lua_toboolean(L, 3) != 0); return 0; }
        if (strcmp(key, "is_dead") == 0) { m->dead = (lua_toboolean(L, 3) != 0); return 0; }
        if (strcmp(key, "is_right_arm_ok") == 0) { m->rightArmOk = (lua_toboolean(L, 3) != 0); return 0; }
        if (strcmp(key, "is_left_arm_ok") == 0) { m->leftArmOk = (lua_toboolean(L, 3) != 0); return 0; }
        // c++ original naming
        if (strcmp(key, "bloodynessChanged") == 0) { m->bloodynessChanged = (lua_toboolean(L, 3) != 0); return 0; }
        if (strcmp(key, "bloodynessCleanedUp") == 0) { m->bloodynessCleanedUp = (lua_toboolean(L, 3) != 0); return 0; }
        if (strcmp(key, "crippled") == 0) { m->crippled = (lua_toboolean(L, 3) != 0); return 0; }
        if (strcmp(key, "unconcious") == 0) { m->unconcious = (lua_toboolean(L, 3) != 0); return 0; }
        if (strcmp(key, "sub50KO") == 0) { m->sub50KO = (lua_toboolean(L, 3) != 0); return 0; }
        if (strcmp(key, "bloodlossTrauma") == 0) { m->bloodlossTrauma = (lua_toboolean(L, 3) != 0); return 0; }
        if (strcmp(key, "dead") == 0) { m->dead = (lua_toboolean(L, 3) != 0); return 0; }
        if (strcmp(key, "rightArmOk") == 0) { m->rightArmOk = (lua_toboolean(L, 3) != 0); return 0; }
        if (strcmp(key, "leftArmOk") == 0) { m->leftArmOk = (lua_toboolean(L, 3) != 0); return 0; }

        return luaL_error(L, "MedicalSystem: field '%s' is read-only or does not exist", key);
    }

    int MedicalSystemBinding::tostring(lua_State* L) { return genericTostringPtr(L, "MedicalSystem", (void*)getM(L, 1)); }

    int MedicalSystemBinding::getBlood(lua_State* L) { MedicalSystem* m = getM(L, 1); if (m) lua_pushnumber(L, m->blood); else lua_pushnil(L); return 1; }
    int MedicalSystemBinding::getMaxBlood(lua_State* L) { MedicalSystem* m = getM(L, 1); if (m) lua_pushnumber(L, m->getMaxBlood()); else lua_pushnil(L); return 1; }
    int MedicalSystemBinding::getHunger(lua_State* L) { MedicalSystem* m = getM(L, 1); if (m) lua_pushnumber(L, m->hunger); else lua_pushnil(L); return 1; }
    int MedicalSystemBinding::isFed(lua_State* L) { MedicalSystem* m = getM(L, 1); lua_pushboolean(L, m && m->isFed() ? 1 : 0); return 1; }
    int MedicalSystemBinding::isReallyHungry(lua_State* L) { MedicalSystem* m = getM(L, 1); lua_pushboolean(L, m && m->isReallyHungry() ? 1 : 0); return 1; }
    int MedicalSystemBinding::getKnockoutTimer(lua_State* L) { MedicalSystem* m = getM(L, 1); if (m) lua_pushnumber(L, m->knockoutTimer); else lua_pushnil(L); return 1; }
    int MedicalSystemBinding::getOverallHealthRating(lua_State* L) { MedicalSystem* m = getM(L, 1); if (m) lua_pushnumber(L, m->getOverallHealthRating()); else lua_pushnil(L); return 1; }
    int MedicalSystemBinding::getStealthHinderance(lua_State* L) { MedicalSystem* m = getM(L, 1); if (m) lua_pushnumber(L, m->stealthHinderance); else lua_pushnil(L); return 1; }

    int MedicalSystemBinding::isUnconcious(lua_State* L) { MedicalSystem* m = getM(L, 1); lua_pushboolean(L, m && m->isUnconcious() ? 1 : 0); return 1; }
    int MedicalSystemBinding::isCrippled(lua_State* L) { MedicalSystem* m = getM(L, 1); lua_pushboolean(L, m && m->isCrippled() ? 1 : 0); return 1; }
    int MedicalSystemBinding::isDead(lua_State* L) { MedicalSystem* m = getM(L, 1); lua_pushboolean(L, m && m->isDead() ? 1 : 0); return 1; }
    int MedicalSystemBinding::isInBloodlossTrauma(lua_State* L) { MedicalSystem* m = getM(L, 1); lua_pushboolean(L, m && m->isInBloodlossTrauma() ? 1 : 0); return 1; }
    int MedicalSystemBinding::isLeftArmOk(lua_State* L) { MedicalSystem* m = getM(L, 1); lua_pushboolean(L, m && m->isLeftArmOk() ? 1 : 0); return 1; }
    int MedicalSystemBinding::isRightArmOk(lua_State* L) { MedicalSystem* m = getM(L, 1); lua_pushboolean(L, m && m->isRightArmOk() ? 1 : 0); return 1; }
    int MedicalSystemBinding::hasRobotics(lua_State* L) { MedicalSystem* m = getM(L, 1); lua_pushboolean(L, m && m->hasRobotics() ? 1 : 0); return 1; }
    int MedicalSystemBinding::hasFreshlySeveredALimb(lua_State* L) { MedicalSystem* m = getM(L, 1); lua_pushboolean(L, m && m->hasFreshlySeveredALimb() ? 1 : 0); return 1; }
    int MedicalSystemBinding::isProbablyDying(lua_State* L) { MedicalSystem* m = getM(L, 1); lua_pushboolean(L, m && m->isProbablyDying() ? 1 : 0); return 1; }
    int MedicalSystemBinding::isFullyRested(lua_State* L) { MedicalSystem* m = getM(L, 1); lua_pushboolean(L, m && m->isFullyRested() ? 1 : 0); return 1; }

    int MedicalSystemBinding::knockoutForceTimer(lua_State* L)
    {
        MedicalSystem* m = getM(L, 1);
        if (!m) return luaL_error(L, "MedicalSystem is nil");
        m->knockoutForceTimer((float)luaL_checknumber(L, 2));
        return 0;
    }

    int MedicalSystemBinding::gettingBurnt(lua_State* L)
    {
        MedicalSystem* m = getM(L, 1);
        if (!m) { lua_pushboolean(L, 0); return 1; }
        lua_pushboolean(L, m->gettingBurnt((float)luaL_checknumber(L, 2)) ? 1 : 0);
        return 1;
    }

    int MedicalSystemBinding::gettingGassed(lua_State* L)
    {
        MedicalSystem* m = getM(L, 1);
        if (!m) { lua_pushboolean(L, 0); return 1; }
        lua_pushboolean(L, m->gettingGassed((float)luaL_checknumber(L, 2)) ? 1 : 0);
        return 1;
    }

    int MedicalSystemBinding::gettingEaten(lua_State* L)
    {
        MedicalSystem* m = getM(L, 1);
        if (!m) { lua_pushboolean(L, 0); return 1; }
        // gettingEaten takes (float amount, bool vampire). The vampire parameter
        // defaults to false here; pass true as the optional second Lua argument
        // to trigger the vampire variant.
        bool vampire = lua_isboolean(L, 3) ? (lua_toboolean(L, 3) != 0) : false;
        lua_pushboolean(L, m->gettingEaten((float)luaL_checknumber(L, 2), vampire) ? 1 : 0);
        return 1;
    }

    int MedicalSystemBinding::gettingAcidRain(lua_State* L)
    {
        MedicalSystem* m = getM(L, 1);
        if (!m) { lua_pushboolean(L, 0); return 1; }
        lua_pushboolean(L, m->gettingAcidRain((float)luaL_checknumber(L, 2)) ? 1 : 0);
        return 1;
    }

    int MedicalSystemBinding::gettingAcidWater(lua_State* L)
    {
        MedicalSystem* m = getM(L, 1);
        if (!m) { lua_pushboolean(L, 0); return 1; }
        lua_pushboolean(L, m->gettingAcidWater((float)luaL_checknumber(L, 2)) ? 1 : 0);
        return 1;
    }

    int MedicalSystemBinding::gettingAcidFeet(lua_State* L)
    {
        MedicalSystem* m = getM(L, 1);
        if (!m) { lua_pushboolean(L, 0); return 1; }
        lua_pushboolean(L, m->gettingAcidFeet((float)luaL_checknumber(L, 2)) ? 1 : 0);
        return 1;
    }

    int MedicalSystemBinding::gettingWindyFace(lua_State* L)
    {
        MedicalSystem* m = getM(L, 1);
        if (!m) { lua_pushboolean(L, 0); return 1; }
        lua_pushboolean(L, m->gettingWindyface((float)luaL_checknumber(L, 2)) ? 1 : 0);
        return 1;
    }

    int MedicalSystemBinding::getToughnessXPBonus(lua_State* L)
    {
        MedicalSystem* m = getM(L, 1);
        if (!m) { lua_pushnumber(L, 0); return 1; }
        lua_pushnumber(L, m->getToughnessXpBonus());
        return 1;
    }

    int MedicalSystemBinding::getMissingArmPenalty(lua_State* L)
    {
        MedicalSystem* m = getM(L, 1);
        if (!m) { lua_pushnumber(L, 0); return 1; }
        lua_pushnumber(L, m->getMissingArmPenaltyMult());
        return 1;
    }

    int MedicalSystemBinding::getHungerSpeedModifer(lua_State* L)
    {
        MedicalSystem* m = getM(L, 1);
        if (!m) { lua_pushnumber(L, 0); return 1; }
        lua_pushnumber(L, m->getHungerSpeedModifier());
        return 1;
    }

    int MedicalSystemBinding::setHealth(lua_State* L)
    {
        MedicalSystem* m = getM(L, 1);
        if (!m) return luaL_error(L, "MedicalSystem is nil");
        const char* bodypart = luaL_checkstring(L, 2);
        float amount = (float)luaL_checknumber(L, 3);
        m->_setHealth(bodypart, amount);
        return 0;
    }

    int MedicalSystemBinding::getWeatherStatPenalty(lua_State* L)
    {
        MedicalSystem* m = getM(L, 1);
        if (!m) { lua_pushinteger(L, 0); return 1; }
        float mult = (float)luaL_checknumber(L, 2);
        lua_pushinteger(L, m->getWeatherStatPenalty(mult));
        return 1;
    }

    void MedicalSystemBinding::registerBinding(lua_State* L)
    {
        static const luaL_Reg metamethods[] = {
            { "__gc", MedicalSystemBinding::gc },
            { "__tostring", MedicalSystemBinding::tostring },
            { 0, 0 }
        };

        static const luaL_Reg methods[] = {
            { "getBlood",               MedicalSystemBinding::getBlood },
            { "getMaxBlood",            MedicalSystemBinding::getMaxBlood },
            { "getHunger",              MedicalSystemBinding::getHunger },
            { "isFed",                  MedicalSystemBinding::isFed },
            { "isReallyHungry",         MedicalSystemBinding::isReallyHungry },
            { "getKnockoutTimer",       MedicalSystemBinding::getKnockoutTimer },
            { "getOverallHealthRating", MedicalSystemBinding::getOverallHealthRating },
            { "getStealthHinderance",   MedicalSystemBinding::getStealthHinderance },
            { "isUnconcious",           MedicalSystemBinding::isUnconcious },
            { "isCrippled",             MedicalSystemBinding::isCrippled },
            { "isDead",                 MedicalSystemBinding::isDead },
            { "isInBloodlossTrauma",    MedicalSystemBinding::isInBloodlossTrauma },
            { "isLeftArmOk",            MedicalSystemBinding::isLeftArmOk },
            { "isRightArmOk",           MedicalSystemBinding::isRightArmOk },
            { "hasRobotics",            MedicalSystemBinding::hasRobotics },
            { "hasFreshlySeveredALimb", MedicalSystemBinding::hasFreshlySeveredALimb },
            { "isProbablyDying",        MedicalSystemBinding::isProbablyDying },
            { "isFullyRested",          MedicalSystemBinding::isFullyRested },
            { "knockoutForceTimer",     MedicalSystemBinding::knockoutForceTimer },
            { "gettingBurnt",           MedicalSystemBinding::gettingBurnt },
            { "gettingGassed",          MedicalSystemBinding::gettingGassed },
            { "gettingEaten",           MedicalSystemBinding::gettingEaten },
            { "gettingAcidRain",        MedicalSystemBinding::gettingAcidRain },
            { "gettingAcidWater",       MedicalSystemBinding::gettingAcidWater },
            { "gettingAcidFeet",        MedicalSystemBinding::gettingAcidFeet },
            { "gettingWindyFace",       MedicalSystemBinding::gettingWindyFace },
            { "getToughnessXPBonus",    MedicalSystemBinding::getToughnessXPBonus },
            { "getMissingArmPenalty",   MedicalSystemBinding::getMissingArmPenalty },
            { "getHungerSpeedModifier", MedicalSystemBinding::getHungerSpeedModifer },
            { "setHealth",              MedicalSystemBinding::setHealth },
            { "getWeatherStatPenalty",  MedicalSystemBinding::getWeatherStatPenalty },
            { 0, 0 }
        };

        registerClass(
            L,
            MedicalSystemBinding::getMetatableName(),
            metamethods,
            methods,
            MedicalSystemBinding::index,
            MedicalSystemBinding::newindex
        );
    }

} // namespace KenshiLua