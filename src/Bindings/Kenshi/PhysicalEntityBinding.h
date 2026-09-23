#pragma once

#include "kenshi/physicscollection.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class PhysicalEntityBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.PhysicalEntity"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

};
}