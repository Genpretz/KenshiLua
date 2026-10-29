#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class HandleContainerListBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.HandleContainerList"; }
    static void registerBinding(lua_State* L);

    static int add(lua_State* L);
    static int _NV_add(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};

} // namespace KenshiLua

