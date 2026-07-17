#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class WhoSeesMeBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.WhoSeesMe"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

};
}