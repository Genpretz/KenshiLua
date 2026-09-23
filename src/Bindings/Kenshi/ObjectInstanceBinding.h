#pragma once

#include "kenshi/GameData.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ObjectInstanceBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ObjectInstance"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

};
}