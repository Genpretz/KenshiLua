#pragma once

#include <string>

extern "C" {
#include <lua.h>
}

namespace KenshiLua
{
    int luaKenshiProfileStart(lua_State* L);
    int luaKenshiProfileStop(lua_State* L);
    int luaKenshiProfileDump(lua_State* L);

    bool isProfilerRunning();
    std::string formatProfileReport();
}
