#pragma once

#include "kenshi/CharMovement.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class CombatMovementControllerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CombatMovementController"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int collisionUpdate(lua_State* L);
    static int chasingModeCheck(lua_State* L);
    static int create(lua_State* L);
    static int areTherePeopleInMyWay(lua_State* L);
    static int addACharacterObstruction(lua_State* L);
    static int setupCombatMovementVariables(lua_State* L);
    static int combatMovementUpdate(lua_State* L);
    static int combatMovementUpdate_crippleMode(lua_State* L);
    static int getUrgentVelocities(lua_State* L);
    static int checkWeDontCollideWithCharacters(lua_State* L);
    static int checkCharacterCollision(lua_State* L);
    static int setForcedWP(lua_State* L);
    static int getGUIData(lua_State* L);
    static int disable(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}