#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class Contract_UntilOutOfDangerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Contract_UntilOutOfDanger"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int activateAndSetup(lua_State* L);
    static int _NV_activateAndSetup(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int _NV_periodicUpdate(lua_State* L);
    static int getDesiredTravelSpeed(lua_State* L);
    static int _NV_getDesiredTravelSpeed(lua_State* L);
    static int signalEnd(lua_State* L);
    static int _NV_signalEnd(lua_State* L);
};
}
