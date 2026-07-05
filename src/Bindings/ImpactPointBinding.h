#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ImpactPointBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ImpactPoint"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};
}