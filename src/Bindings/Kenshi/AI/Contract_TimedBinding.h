#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class Contract_TimedBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Contract_Timed"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int signalStart(lua_State* L);
    static int _NV_signalStart(lua_State* L);
    static int signalEnd(lua_State* L);
    static int _NV_signalEnd(lua_State* L);
};
}
