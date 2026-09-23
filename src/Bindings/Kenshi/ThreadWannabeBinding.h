#pragma once

#include "kenshi/ThreadClass.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ThreadWannabeBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ThreadWannabe"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int backThreadUpdate(lua_State* L);
    static int isPaused(lua_State* L);
    static int setPaused(lua_State* L);
    static int threadProc(lua_State* L);
    static int _NV_threadProc(lua_State* L);
    static int forceLoopMT(lua_State* L);
    static int _NV_forceLoopMT(lua_State* L);
};
}