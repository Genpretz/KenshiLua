#pragma once

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
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int collisionUpdate(lua_State* L);
    static int areTherePeopleInMyWay(lua_State* L);
    static int disable(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}