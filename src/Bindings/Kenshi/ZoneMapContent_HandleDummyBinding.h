#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class ZoneMapContent_HandleDummyBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ZoneMapContent.HandleDummy"; }
    static void registerBinding(lua_State* L);

    static int getDataType(lua_State* L);
    static int _NV_getDataType(lua_State* L);
    static int loadFromSerialise(lua_State* L);
    static int _NV_loadFromSerialise(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};

} // namespace KenshiLua

