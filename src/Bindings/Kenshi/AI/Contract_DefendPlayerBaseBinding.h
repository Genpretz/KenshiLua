#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class Contract_DefendPlayerBaseBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Contract_DefendPlayerBase"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getGUIData(lua_State* L);
    static int _NV_getGUIData(lua_State* L);
    static int getMyTarget(lua_State* L);
    static int _NV_getMyTarget(lua_State* L);
    static int getDesiredTravelSpeed(lua_State* L);
    static int _NV_getDesiredTravelSpeed(lua_State* L);
    static int activateAndSetup(lua_State* L);
    static int _NV_activateAndSetup(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int _NV_periodicUpdate(lua_State* L);
    static int assessNeutral(lua_State* L);
    static int _NV_assessNeutral(lua_State* L);
};
}
