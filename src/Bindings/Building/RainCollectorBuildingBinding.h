#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class RainCollectorBuildingBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.RainCollectorBuilding"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int calculateEfficiencyMult(lua_State* L);
    static int _NV_calculateEfficiencyMult(lua_State* L);
    static int getRainAmount(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}