#pragma once

#include "kenshi/PhysicsActual.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class NxVec3Binding
{
public:
    static const char* getMetatableName() { return "KenshiLua.NxVec3"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int zero(lua_State* L);
    static int isZero(lua_State* L);
    static int normalize(lua_State* L);
    static int setMagnitude(lua_State* L);
    static int closestAxis(lua_State* L);
    static int isFinite(lua_State* L);
    static int magnitude(lua_State* L);
    static int magnitudeSquared(lua_State* L);
    static int dot(lua_State* L);
    static int equals(lua_State* L);
    static int multiplyAdd(lua_State* L);
    static int add(lua_State* L);
    static int subtract(lua_State* L);
    static int cross(lua_State* L);
    static int set(lua_State* L);
    static int constructor(lua_State* L);

    static int lua_add(lua_State* L);
    static int lua_sub(lua_State* L);
    static int lua_unm(lua_State* L);
    static int lua_mul(lua_State* L);
    static int lua_eq(lua_State* L);

    static int operator_assign(lua_State* L);
    static int operator_subscript(lua_State* L);
    static int operator_ne(lua_State* L);
    static int operator_add_assign(lua_State* L);
    static int operator_sub_assign(lua_State* L);
    static int operator_mul_assign(lua_State* L);
    static int operator_xor(lua_State* L);
};
}