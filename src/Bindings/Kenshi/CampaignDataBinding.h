#pragma once

// Tasker.h must come before AI.h (included by Campaign.h); see TaskDataBinding.cpp.
#include "kenshi/Tasker.h"
#include "kenshi/Campaign.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class CampaignDataBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CampaignData"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _setupPackages(lua_State* L);
    static int _addDataFrom(lua_State* L);
    static int reset(lua_State* L);
    static int key(lua_State* L);
    static int isHostile(lua_State* L);
    static int getDisplayName(lua_State* L);
    static int isTriggersRandomly(lua_State* L);
    static int chooseTarget(lua_State* L);
    static int _NV_chooseTarget(lua_State* L);
    static int territorialTriggerScore(lua_State* L);
    static int _NV_territorialTriggerScore(lua_State* L);
    static int canStart(lua_State* L);
    static int _NV_canStart(lua_State* L);
    static int numForcesNeeded(lua_State* L);
    static int ignoresMults(lua_State* L);
    static int canUseThisSquad(lua_State* L);
};
}
