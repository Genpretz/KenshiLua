#pragma once
#include "kenshi/GunClass.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class GunClassTurretBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.GunClassTurret"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int isOutOfPower(lua_State* L);
    static int _NV_isOutOfPower(lua_State* L);
    static int clearEntitesPtr(lua_State* L);
};
}
