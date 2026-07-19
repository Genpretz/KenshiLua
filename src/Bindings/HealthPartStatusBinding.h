#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class HealthPartStatusBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.HealthPartStatus"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int isRobotic(lua_State* L);
    static int getData(lua_State* L);
    static int getRobotLimbEnum(lua_State* L);
    static int update(lua_State* L);
    static int updateDerivedHealths(lua_State* L);
    static int getWorstDamage(lua_State* L);
    static int getExtraBleedingAmount(lua_State* L);
    static int isDead(lua_State* L);
    static int getBloodynessMult(lua_State* L);
    static int maxHealth(lua_State* L);
    static int healthAsPercent(lua_State* L);

    static int serialise(lua_State* L);
    static int load(lua_State* L);
    static int setup(lua_State* L);
    static int applyDamage(lua_State* L);
    static int applyWearDamage(lua_State* L);
    static int getRobotLimbState(lua_State* L);
    static int setRobotLimbItem(lua_State* L);
};
}
