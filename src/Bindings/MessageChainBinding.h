#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class MessageChainBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MessageChain"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int flush(lua_State* L);
};
}