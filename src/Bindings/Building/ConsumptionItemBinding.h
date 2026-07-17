#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ConsumptionItemBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ConsumptionItem"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int isFull(lua_State* L);
    static int isEmpty(lua_State* L);
};
}