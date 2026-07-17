#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class iVector2Binding
{
public:
    static const char* getMetatableName() { return "KenshiLua.iVector2"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getLinearValue(lua_State* L);
    static int getAsString(lua_State* L);
};
}