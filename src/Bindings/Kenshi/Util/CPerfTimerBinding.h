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

    static int operator_assign(lua_State* L);
    static int operator_add(lua_State* L);
    static int operator_sub(lua_State* L);
    static int operator_add_assign(lua_State* L);
    static int operator_sub_assign(lua_State* L);
    static int operator_lt(lua_State* L);
    static int operator_le(lua_State* L);
    static int operator_gt(lua_State* L);
    static int operator_ge(lua_State* L);

    static int Start(lua_State* L);
    static int Stop(lua_State* L);
    static int IsRunning(lua_State* L);
    static int IsSupported(lua_State* L);
    static int Resolution(lua_State* L);
    static int Resolutionms(lua_State* L);
    static int Resolutionus(lua_State* L);
    static int Elapsed(lua_State* L);
    static int Elapsedms(lua_State* L);
    static int Elapsedus(lua_State* L);
};
}