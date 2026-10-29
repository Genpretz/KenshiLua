#pragma once
#include "kenshi/GunClass.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class GunClassPersonalBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.GunClassPersonal"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int clearEntitesPtr(lua_State* L);
};
}
