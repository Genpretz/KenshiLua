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
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    // Core attributes (use *Actual() where available so equipment/age mods are
    // factored in; the raw fields remain reachable via getRaw*).
    static int getStrength(lua_State* L);
    static int getStrengthRaw(lua_State* L);
    static int getDexterity(lua_State* L);
    static int getDexterityRaw(lua_State* L);
    static int getToughness(lua_State* L);
    static int getToughnessRaw(lua_State* L);
    static int getPerception(lua_State* L);
    static int getAthletics(lua_State* L);

    // Combat skills
    static int getMeleeAttack(lua_State* L);
    static int getMeleeDefence(lua_State* L);
    static int getDodge(lua_State* L);
    static int getMassCombat(lua_State* L);
    static int getMartialArts(lua_State* L); 
    static int getKatanas(lua_State* L);
    static int getSabres(lua_State* L);
    static int getHackers(lua_State* L);
    static int getBlunt(lua_State* L);
    static int getHeavyWeapons(lua_State* L);
    static int getPolearms(lua_State* L);
    static int getBows(lua_State* L);
    static int getTurrets(lua_State* L);

    // Field / craft skills
    static int getStealth(lua_State* L);
    static int getThieving(lua_State* L);
    static int getLockpicking(lua_State* L);
    static int getAssassination(lua_State* L);
    static int getSurvival(lua_State* L);
    static int getTracking(lua_State* L);
    static int getClimbing(lua_State* L);
    static int getSwimming(lua_State* L);
    static int getBluff(lua_State* L);
    static int getFieldMedic(lua_State* L);
    static int getDoctor(lua_State* L);
    static int getScience(lua_State* L);
    static int getEngineer(lua_State* L);
    static int getRobotics(lua_State* L);
    static int getLabouring(lua_State* L);
    static int getFarming(lua_State* L);
    static int getCooking(lua_State* L);
    static int getWeaponSmith(lua_State* L);
    static int getArmourSmith(lua_State* L);
    static int getBowSmith(lua_State* L);

    // XP / status
    static int getXp(lua_State* L);
    static int getFreeAttributePoints(lua_State* L);
    static int getOverallSkillLevel(lua_State* L);
    static int isUnarmed(lua_State* L);
    static int isDefensiveMode(lua_State* L);
    static int isHoldPositionMode(lua_State* L);
    static int isRangedMode(lua_State* L);

    // Linkage
    static int getMedicalSystem(lua_State* L);
    static int getCharacter(lua_State* L);

    static int setEquippedWeaponSkill(lua_State* L);
    static int _NV_setEquippedWeaponSkill(lua_State* L);
    static int setEquipmentStatBonuses(lua_State* L);

};
}
