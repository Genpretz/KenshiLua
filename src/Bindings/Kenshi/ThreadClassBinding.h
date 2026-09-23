#pragma once

#include "kenshi/ThreadClass.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ThreadClassBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ThreadClass"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int stopRunning(lua_State* L);
    static int canIRun(lua_State* L);
    static int startRunning(lua_State* L);
    static int isRunning(lua_State* L);
    static int waitForRunningStop_Blocking(lua_State* L);
    static int setup(lua_State* L);
    static int beginThread(lua_State* L);
    static int setThreadName(lua_State* L);
    static int endThread(lua_State* L);
    static int setName(lua_State* L);
    static int threadProc(lua_State* L);
};
}