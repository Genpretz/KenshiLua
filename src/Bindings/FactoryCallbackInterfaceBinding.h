#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class FactoryCallbackInterfaceBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.FactoryCallbackInterface"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

};
}
