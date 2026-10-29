#pragma once
#include "kenshi/Item.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class MoneyItemBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MoneyItem"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getValueSingle(lua_State* L);
    static int _NV_getValueSingle(lua_State* L);
    static int consume(lua_State* L);
};
}
