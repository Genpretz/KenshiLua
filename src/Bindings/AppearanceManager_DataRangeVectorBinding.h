#pragma once
#include "kenshi/AppearanceManager.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class AppearanceManager_DataRangeVectorBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AppearanceManager_DataRangeVector"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);

    static int addValue(lua_State* L);
    static int getValue(lua_State* L);
    static int getValueIndex(lua_State* L);
    static int size(lua_State* L);
    static int clamp(lua_State* L);
};
} // namespace KenshiLua
