#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class ItemHandleListBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ItemHandleList"; }
    static void registerBinding(lua_State* L);

    static int setUnloaded(lua_State* L);
    static int _NV_setUnloaded(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};

} // namespace KenshiLua

