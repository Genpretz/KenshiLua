#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class hkMemoryAllocatorBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.hkMemoryAllocator"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int blockAlloc(lua_State* L);
    static int resetPeakMemoryStatistics(lua_State* L);
    static int _NV_resetPeakMemoryStatistics(lua_State* L);
    static int getExtendedInterface(lua_State* L);
    static int _NV_getExtendedInterface(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
};
}