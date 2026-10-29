#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class ZoneMapContent_ZoneMapContentOrderLoaderBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ZoneMapContent.ZoneMapContentOrderLoader"; }
    static void registerBinding(lua_State* L);

    static int shouldSkip(lua_State* L);
    static int _NV_shouldSkip(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};

} // namespace KenshiLua

