#pragma once

#include "kenshi/Havok.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class hkVector4fBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.hkVector4f"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int setZero(lua_State* L);
    static int zeroComponent(lua_State* L);
    static int setInt24W(lua_State* L);
    static int getInt24W(lua_State* L);
    static int getInt16W(lua_State* L);
    static int setZero4(lua_State* L);
    static int normalize3(lua_State* L);
    static int getZero(lua_State* L);
    static int set(lua_State* L);
    static int setAll(lua_State* L);
    static int add(lua_State* L);
    static int sub(lua_State* L);
    static int mul(lua_State* L);
    static int div(lua_State* L);
    static int setAdd(lua_State* L);
    static int setSub(lua_State* L);
    static int setMul(lua_State* L);
    static int setDiv(lua_State* L);
    static int addMul(lua_State* L);
    static int setAddMul(lua_State* L);
    static int subMul(lua_State* L);
    static int setSubMul(lua_State* L);
    static int setCross(lua_State* L);
    static int setXYZ_W(lua_State* L);
    static int setW(lua_State* L);
    static int setXYZ(lua_State* L);
    static int setXYZ_0(lua_State* L);
    static int equals3(lua_State* L);
    static int setAbs(lua_State* L);
    static int setMin(lua_State* L);
    static int setMax(lua_State* L);
    static int setClamped(lua_State* L);
    static int setClampedZeroOne(lua_State* L);
    static int setReciprocal(lua_State* L);
    static int setSqrt(lua_State* L);
    static int setSqrtInverse(lua_State* L);
    static int setSelect(lua_State* L);
    static int zeroIfFalse(lua_State* L);
    static int zeroIfTrue(lua_State* L);
    static int less(lua_State* L);
    static int lessEqual(lua_State* L);
    static int greater(lua_State* L);
    static int greaterEqual(lua_State* L);
    static int equal(lua_State* L);
    static int notEqual(lua_State* L);
    static int lessZero(lua_State* L);
    static int lessEqualZero(lua_State* L);
    static int greaterZero(lua_State* L);
    static int greaterEqualZero(lua_State* L);
    static int equalZero(lua_State* L);
    static int notEqualZero(lua_State* L);
    static int isOk3(lua_State* L);
    static int isOk4(lua_State* L);
    static int create(lua_State* L);
};
}