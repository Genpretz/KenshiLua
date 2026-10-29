#pragma once

#include "kenshi/StateBroadcastData.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class StateBroadcastDataBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.StateBroadcastData"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int save(lua_State* L);
    static int load(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int setSlaveState(lua_State* L);
    static int getSlaveState(lua_State* L);
    static int getSlaveStateHoursRemaining(lua_State* L);
    static int notifyDisguiseBlown(lua_State* L);
    static int isDisguiseBlown(lua_State* L);
    static int isDisguised(lua_State* L);
    static int isHiddenIdentitySlave(lua_State* L);
    static int getApparentFaction(lua_State* L);
};
}
