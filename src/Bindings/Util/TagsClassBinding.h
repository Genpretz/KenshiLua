#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TagsClassBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TagsClass"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int clearAll(lua_State* L);
    static int hasNONEOfTheseBitsSet(lua_State* L);
    static int hasANYOfTheseBitsSet(lua_State* L);
};
}