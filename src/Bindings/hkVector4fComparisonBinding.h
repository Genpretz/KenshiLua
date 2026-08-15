#pragma once

#include "kenshi/Havok.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class hkVector4fComparisonBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.hkVector4fComparison"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getIndexOfLastComponentSet(lua_State* L);
    static int getIndexOfFirstComponentSet(lua_State* L);
    static int allAreSet(lua_State* L);
};
}