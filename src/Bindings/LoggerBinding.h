#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class LoggerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Logger"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int init(lua_State* L);
    static int close(lua_State* L);
    static int logMessage(lua_State* L);
    static int logMessageDebug(lua_State* L);
    static int logHeader(lua_State* L);
};
}