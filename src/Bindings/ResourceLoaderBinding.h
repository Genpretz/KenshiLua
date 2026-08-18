#pragma once

#include "kenshi/ResourceLoader.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ResourceLoaderBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ResourceLoader"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int updateMT(lua_State* L);
    static int updateBT(lua_State* L);
    static int isLoading(lua_State* L);
    static int init(lua_State* L);
    static int threadProc(lua_State* L);
    static int _NV_threadProc(lua_State* L);
    static int getInstance(lua_State* L);
    static int destroy(lua_State* L);
};
}
