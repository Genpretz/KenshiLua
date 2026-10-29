#pragma once

#include "kenshi/Tasker.h"
#include "kenshi/AI/AI.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TargetInfoBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TargetInfo"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int constructor(lua_State* L);
    static int setupType(lua_State* L);
    static int operator_assign(lua_State* L);
    static int operator_bool(lua_State* L);
    static int isTown(lua_State* L);
    static int isCharacter(lua_State* L);
    static int getTown(lua_State* L);
    static int getCharacter(lua_State* L);
    static int getPositionForWaypoint(lua_State* L);
};
}
