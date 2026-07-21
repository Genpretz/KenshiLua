#pragma once

extern "C" {
#include <lua.h>
}

namespace KenshiLua
{
    int luaKenshiRunBenchmark(lua_State* L);
    bool isBenchmarkEnabled();
    void runBenchmarkOnStartup(lua_State* L, bool isInitialStartup = true);
}
