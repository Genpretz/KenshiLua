#pragma once

#include "kenshi/util/Array2d.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class BadSizeBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.BadSize"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

};
}