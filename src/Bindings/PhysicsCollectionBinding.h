#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class PhysicsCollectionBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.PhysicsCollection"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int findRotatingEnt(lua_State* L);
    static int getWindRotationPower(lua_State* L);
    static int getWindMillPart(lua_State* L);
    static int isLoaded(lua_State* L);
    static int setVisible(lua_State* L);
    static int update(lua_State* L);
    static int updateAimingType(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
};
}