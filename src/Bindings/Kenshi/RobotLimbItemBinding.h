#pragma once

#include "kenshi/Gear.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class RobotLimbItemBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.RobotLimbItem"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getStatMult(lua_State* L);
    static int _serialise(lua_State* L);
    static int _NV__serialise(lua_State* L);
    static int _loadFromSerialise(lua_State* L);
    static int _NV__loadFromSerialise(lua_State* L);
    static int getCraftTime(lua_State* L);
    static int _NV_getCraftTime(lua_State* L);
    static int getTooltipData1(lua_State* L);
    static int _NV_getTooltipData1(lua_State* L);
    static int getTooltipData2(lua_State* L);
    static int _NV_getTooltipData2(lua_State* L);
};
}
