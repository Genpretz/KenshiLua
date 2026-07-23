#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ProsperityManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ProsperityManager"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int setup(lua_State* L);
    static int load(lua_State* L);
    static int save(lua_State* L);
    static int getProsperityMultiplier(lua_State* L);
    static int getGUIData(lua_State* L);
    static int update(lua_State* L);
    static int notifySquadDefeated(lua_State* L);
    static int notifySpecialNPCDead(lua_State* L);
};
}