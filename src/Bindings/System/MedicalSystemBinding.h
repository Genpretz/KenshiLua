#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    class MedicalSystemEnumBinding
    {
    public:
        static void registerBinding(lua_State* L);
    private:
        static void registerLimbState(lua_State* L);
        static void registerRobotLimbs(lua_State* L);
        static void registerAttackDirection(lua_State* L);
        static void registerHealthPartStatus(lua_State* L);
        static void registerCollapseStage(lua_State* L);
};

    class MedicalSystemBinding
    {
    public:
        static const char* getMetatableName() { return "KenshiLua.MedicalSystem"; }
        static void registerBinding(lua_State* L);

        static int gc(lua_State* L);
        static int tostring(lua_State* L);
        static int index(lua_State* L);
        static int newindex(lua_State* L);

        // State reads
        static int getBlood(lua_State* L);
        static int getMaxBlood(lua_State* L);
        static int getHunger(lua_State* L);
        static int isFed(lua_State* L);
        static int isReallyHungry(lua_State* L);
        static int getKnockoutTimer(lua_State* L);
        static int getOverallHealthRating(lua_State* L);
        static int getStealthHinderance(lua_State* L);
        static int getToughnessXPBonus(lua_State* L);
        static int getMissingArmPenalty(lua_State* L);
        static int getHungerSpeedModifer(lua_State* L);
        static int getWeatherStatPenalty(lua_State* L);

        // Bool reads
        static int isUnconcious(lua_State* L);
        static int isCrippled(lua_State* L);
        static int isDead(lua_State* L);
        static int isInBloodlossTrauma(lua_State* L);
        static int isLeftArmOk(lua_State* L);
        static int isRightArmOk(lua_State* L);
        static int hasRobotics(lua_State* L);
        static int hasFreshlySeveredALimb(lua_State* L);
        static int isProbablyDying(lua_State* L);
        static int isFullyRested(lua_State* L);

        // Mutators
        static int knockoutForceTimer(lua_State* L);
        static int gettingBurnt(lua_State* L);
        static int gettingGassed(lua_State* L);
        static int gettingEaten(lua_State* L);
        static int gettingAcidRain(lua_State* L);
        static int gettingAcidWater(lua_State* L);
        static int gettingAcidFeet(lua_State* L);
        static int gettingWindyFace(lua_State* L);
        static int setHealth(lua_State* L);
    };
}