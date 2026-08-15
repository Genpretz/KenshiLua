#pragma once

#include "kenshi/MedicalSystem.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class RobotLimbsBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.RobotLimbs"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int load(lua_State* L);
    static int save(lua_State* L);
    static int getLimb(lua_State* L);
    static int getMask(lua_State* L);
    static int getInventoryInterface(lua_State* L);
    static int destroyInventoryInterface(lua_State* L);
    static int getLimbItem(lua_State* L);
    static int getState(lua_State* L);
    static int setLimb(lua_State* L);
};
}
