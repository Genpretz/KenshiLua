#pragma once

#include <string>

extern "C" {
#include <lua.h>
}

namespace KenshiLua
{
    void registerGlobals(lua_State* L);
} // namespace KenshiLua
