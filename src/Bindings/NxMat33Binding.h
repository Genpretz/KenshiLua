#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class NxMat33Binding
{
public:
    static const char* getMetatableName() { return "KenshiLua.NxMat33"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int setRowMajor(lua_State* L);
    static int getRowMajor(lua_State* L);
    static int getColumnMajor(lua_State* L);
    static int setRowMajorStride4(lua_State* L);
    static int getRowMajorStride4(lua_State* L);
    static int getColumnMajorStride4(lua_State* L);
    static int isFinite(lua_State* L);
    static int zero(lua_State* L);
    static int id(lua_State* L);
};
}