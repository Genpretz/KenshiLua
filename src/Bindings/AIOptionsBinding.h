#pragma once
#include <kenshi/PlayerInterface.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
    typedef PlayerInterface::AIOptions AIOptions;

class AIOptionsBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AIOptions"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int load(lua_State* L);
    static int save(lua_State* L);
};
}
