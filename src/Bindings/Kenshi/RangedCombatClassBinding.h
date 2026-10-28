#pragma once
#include "kenshi/combat/RangedCombatClass.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class RangedCombatClassBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.RangedCombatClass"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int setState(lua_State* L);
    static int setup(lua_State* L);
    static int getGun(lua_State* L);
    static int isInRangedCombatMode(lua_State* L);
    static int updateT(lua_State* L);
    static int updateMT(lua_State* L);
    static int end(lua_State* L);
    static int _getAttackTarget(lua_State* L);
    static int scoreTargetRange(lua_State* L);
    static int printGUIState(lua_State* L);
    static int isInRange(lua_State* L);
    static int getGunRange(lua_State* L);
};
}
