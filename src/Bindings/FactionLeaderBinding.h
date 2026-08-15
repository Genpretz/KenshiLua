#pragma once

#include "kenshi/FactionLeader.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class FactionLeaderBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.FactionLeader"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int setNewLeader(lua_State* L);
    static int getEnemyMissionTargetList(lua_State* L);
    static int getGUIData(lua_State* L);
};
}