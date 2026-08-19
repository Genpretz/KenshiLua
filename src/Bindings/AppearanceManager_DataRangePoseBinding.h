#pragma once
#include "kenshi/AppearanceManager.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class AppearanceManager_DataRangePoseBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AppearanceManager_DataRangePose"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);

    static int clamp(lua_State* L);
};
} // namespace KenshiLua
