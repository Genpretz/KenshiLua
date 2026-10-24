#pragma once

#include "kenshi/Tasker.h"
#include "kenshi/AI/AI.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class AI_AIResultsCacherBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AI_AIResultsCacher"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int resetAllCaches(lua_State* L);
    static int cacheResult_reqs(lua_State* L);
    static int getCacheResult_reqs(lua_State* L);
    static int hasCacheResult_reqs(lua_State* L);
    static int cacheResult_results(lua_State* L);
    static int getCacheResult_results(lua_State* L);
    static int hasCacheResult_results(lua_State* L);
    static int resetSpecificTargetFinderCache(lua_State* L);
    static int getResourceSource(lua_State* L);
    static int cacheResult_targetFinder(lua_State* L);
};
}
