#pragma once

#include "kenshi/util/PerfTimer.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class CPerfTimerTBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CPerfTimerT"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

};
}