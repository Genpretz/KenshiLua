#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class physHitBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.physHit"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int traceWasAborted(lua_State* L);
    static int reset(lua_State* L);
    static int hitObjectUnsafePtr(lua_State* L);
    static int getBuilding(lua_State* L);
    static int group(lua_State* L);
};
}