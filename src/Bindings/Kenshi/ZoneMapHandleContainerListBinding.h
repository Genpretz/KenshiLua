#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class ZoneMapHandleContainerListBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ZoneMapHandleContainerList"; }
    static void registerBinding(lua_State* L);

    static int getZoneMap(lua_State* L);
    static int getObject(lua_State* L);
    static int setUnloaded(lua_State* L);
    static int _NV_setUnloaded(lua_State* L);
    static int destroy(lua_State* L);
    static int _NV_destroy(lua_State* L);
    static int getCorrectHandleList(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};

} // namespace KenshiLua

