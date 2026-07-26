#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class SensoryDataBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.SensoryData"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int periodicUpdate_KOed(lua_State* L);
    static int getVisionRange(lua_State* L);
    static int update(lua_State* L);
    static int notifyKO(lua_State* L);
    static int getIterator(lua_State* L);
    static int getNearestEnemyDistanceSq(lua_State* L);
    static int canISeeThisGuy(lua_State* L);
    static int canIHearThisGuy(lua_State* L);
    static int amIAwareOfThisGuy(lua_State* L);
    static int getLastKnownPositionOf(lua_State* L);
    static int getDataFor(lua_State* L);
    static int getFactionRelation(lua_State* L);
    static int getStateBroadcast(lua_State* L);
    static int getGUIData(lua_State* L);
    static int _calculateFOVScore(lua_State* L);
    static int _traceLineOfSightCheck(lua_State* L);
    static int getCharacter(lua_State* L);
    static int dialogAssessmentUpdate(lua_State* L);
    static int noticeThisPerson(lua_State* L);
    static int add(lua_State* L);
    static int remove(lua_State* L);
    static int decay(lua_State* L);
    static int canSee(lua_State* L);
    static int canHear(lua_State* L);
    static int disguiseMods(lua_State* L);
    static int assessCrimes(lua_State* L);
    static int assessKidnapping(lua_State* L);
    static int processKillList(lua_State* L);
    static int assessNeutral(lua_State* L);
    static int updateMyProgressBar(lua_State* L);
    static int canISeeThisGuyDoinSneakingOrSomething(lua_State* L);
    static int isIntruder_Base(lua_State* L);
    static int isIntruder_Building(lua_State* L);
    static int isInMyPrivate_Building(lua_State* L);
    static int isEscapee(lua_State* L);
    static int reassess(lua_State* L);
    static int addToThreatsAndFlockingList(lua_State* L);
    static int buildingSpotterUpdate(lua_State* L);
};
}