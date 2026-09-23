#pragma once

#include "kenshi/Havok.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class hkBoolBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.hkBool"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int eq(lua_State* L);

    static int isValid(lua_State* L);
    static int get(lua_State* L);
    static int set(lua_State* L);

};
}