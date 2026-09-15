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
    static int anyIsSet(lua_State* L);
    static int getMask(lua_State* L);
    static int getMaskForComponent(lua_State* L);
    static int set(lua_State* L);
    static int setAnd(lua_State* L);
    static int setAndNot(lua_State* L);
    static int setXor(lua_State* L);
    static int setOr(lua_State* L);
    static int setNot(lua_State* L);
    static int setSelect(lua_State* L);
    static int create(lua_State* L);
};
}