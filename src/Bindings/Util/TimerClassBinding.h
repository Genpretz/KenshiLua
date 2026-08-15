#pragma once

#include "kenshi/util/PerfTimer.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TimerClassBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TimerClass"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

};
}