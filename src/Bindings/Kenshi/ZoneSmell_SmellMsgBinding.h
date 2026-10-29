#pragma once
#include "kenshi/ZoneSmell.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ZoneSmell_SmellMsgBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ZoneSmell_SmellMsg"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
};
}
