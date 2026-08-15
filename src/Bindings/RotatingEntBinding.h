#pragma once

#include "kenshi/PhysicsCollection.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class RotatingEntBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.RotatingEnt"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int updateAim(lua_State* L);
    static int _NV_updateAim(lua_State* L);
    static int isRotatingEnt(lua_State* L);
    static int _NV_isRotatingEnt(lua_State* L);
    static int getRotationPower(lua_State* L);
};
}