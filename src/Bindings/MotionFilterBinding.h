#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class MotionFilterBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MotionFilter"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int SetHistoryBufferLength(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}
