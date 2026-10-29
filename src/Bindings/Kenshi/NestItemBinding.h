#pragma once
#include "kenshi/Item.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class NestItemBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.NestItem"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getClassType(lua_State* L);
    static int _NV_getClassType(lua_State* L);
    static int getModelName(lua_State* L);
    static int _NV_getModelName(lua_State* L);
};
}
