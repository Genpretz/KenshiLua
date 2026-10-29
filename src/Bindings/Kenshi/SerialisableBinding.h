#pragma once

#include "kenshi/HandleManager.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class SerialisableBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Serialisable"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};
}
