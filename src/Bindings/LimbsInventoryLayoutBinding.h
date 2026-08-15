#pragma once

#include "kenshi/Character.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class LimbsInventoryLayoutBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.LimbsInventoryLayout"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

};
}
