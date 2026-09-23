#pragma once

#include "kenshi/Building/FurnaceBuilding.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class FurnaceInventoryLayoutBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.FurnaceInventoryLayout"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

};
}