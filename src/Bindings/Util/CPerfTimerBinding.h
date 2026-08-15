#pragma once

#include "kenshi/util/PerfTimer.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class CPerfTimerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CPerfTimer"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int Stop(lua_State* L);
    static int Resolution(lua_State* L);
    static int Resolutionms(lua_State* L);
    static int Resolutionus(lua_State* L);
    static int Elapsed(lua_State* L);
    static int Elapsedms(lua_State* L);
    static int Elapsedus(lua_State* L);
};
}