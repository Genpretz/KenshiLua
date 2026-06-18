#pragma once

extern "C" {
#include <lua.h>
}

class Character;

namespace KenshiLua
{
class CharacterBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Character"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
	static int index(lua_State* L);
    static int newindex(lua_State* L);

    // Identity / existence
    static int isValid(lua_State* L);
    static int isPlayerCharacter(lua_State* L);
    static int isUnique(lua_State* L);
    static int isFemale(lua_State* L);
    static int isDestroyed(lua_State* L);
    static int isDead(lua_State* L);

    // Naming / appearance
    static int getName(lua_State* L);
    static int setName(lua_State* L);
    static int setNameTagVisible(lua_State* L);
    static int getVisible(lua_State* L);
    static int setVisible(lua_State* L);

    // Position / movement
    static int getPosition(lua_State* L);
    static int getBoneWorldPosition(lua_State* L);
    static int getMovementSpeed(lua_State* L);
    static int getMovementDirection(lua_State* L);
    static int teleport(lua_State* L);
    static int setDestination(lua_State* L);

    // Faction / race / platoon
    static int getFaction(lua_State* L);
    static int setFaction(lua_State* L);
    static int getRace(lua_State* L);
    static int getPlatoon(lua_State* L);
    static int getSquadLeader(lua_State* L);

    // State checks
    static int isUnconcious(lua_State* L);
    static int isDown(lua_State* L);
    static int isRagdoll(lua_State* L);
    static int isCrippled(lua_State* L);
    static int isInCombatMode(lua_State* L);
    static int isInRangedCombatMode(lua_State* L);
    static int isFleeing(lua_State* L);
    static int isStealthMode(lua_State* L);
    static int isInjured(lua_State* L);
    static int isKidnapped(lua_State* L);
	static int getProneState(lua_State* L);
	static int setProneState(lua_State* L);

    // Relations
    static int isEnemy(lua_State* L);
    static int isAlly(lua_State* L);

    // Combat
    static int attackTarget(lua_State* L);
    static int endCombatMode(lua_State* L);
    static int getCurrentWeapon(lua_State* L);
    static int getAttackTarget(lua_State* L);
    static int healCompletely(lua_State* L);

    // Inventory / stats / medical
    static int getInventory(lua_State* L);
    static int getStats(lua_State* L);
    static int getMedical(lua_State* L);
    static int getMoney(lua_State* L);
    static int takeMoney(lua_State* L);
    static int hasItem(lua_State* L);
    static int hasRoomForItem(lua_State* L);

    // Dialogue
    static int sayALine(lua_State* L);
    static int say(lua_State* L);
    static int sendDialogEvent(lua_State* L);
    static int sendDialogEventOverride(lua_State* L);
    static int hasDialogue(lua_State* L);

    // Orders
    static int setStandingOrder(lua_State* L);
    static int getStandingOrder(lua_State* L);
    static int setStealthMode(lua_State* L);

    // Age
    static int getAge(lua_State* L);
    static int setAge(lua_State* L);
    static int setSquadMemberType(lua_State* L);
    static int rememberCharacter(lua_State* L);
    static int isImmuneToOffscreenMode(lua_State* L);
};
}
