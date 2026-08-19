#pragma once
#include "kenshi/AppearanceManager.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class AppearanceManager_GenderBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AppearanceManager_Gender"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);

    static int isMale(lua_State* L);
    static int isFemale(lua_State* L);
    static int toString(lua_State* L);
    static int getValue(lua_State* L);
};
} // namespace KenshiLua
