#pragma once

#include "kenshi/util/TripleInt.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TripleIntBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TripleInt"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

};
}