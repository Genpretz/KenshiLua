#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class MedicalSystemBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MedicalSystem"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int precalculateFirstAidNeedScore(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int updateStats(lua_State* L);
    static int _NV_updateStats(lua_State* L);
    static int medicalUpdate(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int _NV_periodicUpdate(lua_State* L);
    static int scoreFirstAidNeed(lua_State* L);
    static int scoreJuryRigNeed(lua_State* L);
    static int isFullyRested(lua_State* L);
    static int _setHealth(lua_State* L);
    static int validateHealthValues(lua_State* L);
    static int amputate(lua_State* L);
    static int crushLimb(lua_State* L);
    static int isUselessNoLimbGuy(lua_State* L);
    static int recalculateStealthHinderance(lua_State* L);
    static int getPartCount(lua_State* L);
    static int hasRobotics(lua_State* L);
    static int isFed(lua_State* L);
    static int getMaxBlood(lua_State* L);
    static int startKnockoutTimer(lua_State* L);
    static int knockout(lua_State* L);
    static int knockoutForceTimer(lua_State* L);
    static int pointOfCollapseBloodloss(lua_State* L);
    static int pointOfNoReturn(lua_State* L);
    static int pointOfNoReturn_Hunger01(lua_State* L);
    static int isHungerKO(lua_State* L);
    static int getToughnessXpBonus(lua_State* L);
    static int getHungerSpeedModifier(lua_State* L);
    static int getHealthStatModifier(lua_State* L);
    static int _getRoboticsStatMult(lua_State* L);
    static int getMissingArmPenaltyMult(lua_State* L);
    static int getDerivedHeadHealth(lua_State* L);
    static int calculateDesiredPainAnimations(lua_State* L);
    static int getMovementSpeedInjuryMultiplier(lua_State* L);
    static int getStatRoboticsMultiplier(lua_State* L);
    static int getMovementSwimSpeedInjuryMultiplier(lua_State* L);
    static int gettingEaten(lua_State* L);
    static int gettingAcidRain(lua_State* L);
    static int gettingAcidWater(lua_State* L);
    static int gettingAcidFeet(lua_State* L);
    static int gettingGassed(lua_State* L);
    static int gettingWindyface(lua_State* L);
    static int gettingBurnt(lua_State* L);
    static int reassessCollapseMode(lua_State* L);
    static int isUnconcious(lua_State* L);
    static int isCrippled(lua_State* L);
    static int isDead(lua_State* L);
    static int hasAnArmToFightWith(lua_State* L);
    static int hasFreshlySeveredALimb(lua_State* L);
    static int isReallyHungry(lua_State* L);
    static int isProbablyDying(lua_State* L);
    static int getOverallHealthRating(lua_State* L);
    static int canGetUpWakeUp(lua_State* L);
    static int _reassessRagdollPartsAssumingWeJustClearedTheEntireRagdoll(lua_State* L);
    static int isRightArmOk(lua_State* L);
    static int isLeftArmOk(lua_State* L);
    static int canIkick(lua_State* L);
    static int isInBloodlossTrauma(lua_State* L);
    static int clearWeatherEffects(lua_State* L);
    static int getWeatherStatPenaltyMult(lua_State* L);
    static int getWeatherStatPenalty(lua_State* L);
    static int calculateBleedRateForFX(lua_State* L);
    static int bloodlossUpdate(lua_State* L);
    static int updateDamageState(lua_State* L);
};
}