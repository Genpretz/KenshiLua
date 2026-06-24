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

    static int _DESTRUCTOR(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int periodicUpdate_KOed(lua_State* L);
    static int getVisionRange(lua_State* L);
    static int update(lua_State* L);
    static int notifyKO(lua_State* L);
    static int getNearestEnemyDistanceSq(lua_State* L);
    static int getCharacter(lua_State* L);
    static int dialogAssessmentUpdate(lua_State* L);
    static int processKillList(lua_State* L);
    static int updateMyProgressBar(lua_State* L);
    static int buildingSpotterUpdate(lua_State* L);
};
}