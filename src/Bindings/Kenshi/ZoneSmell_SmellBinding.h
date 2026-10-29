#pragma once
#include "kenshi/ZoneSmell.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ZoneSmell_SmellBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ZoneSmell_Smell"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
};
}
