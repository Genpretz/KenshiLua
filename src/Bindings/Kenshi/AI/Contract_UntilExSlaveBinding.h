#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class Contract_UntilExSlaveBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Contract_UntilExSlave"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getDesiredTravelSpeed(lua_State* L);
    static int _NV_getDesiredTravelSpeed(lua_State* L);
    static int signalEnd(lua_State* L);
    static int _NV_signalEnd(lua_State* L);
};
}
