#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

class TownBase;

namespace KenshiLua
{

class TownBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Town"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int getName(lua_State* L);
    static int getPosition(lua_State* L);
    static int getFaction(lua_State* L);
    static int setFaction(lua_State* L);
    static int getAlarmState(lua_State* L);
    static int setAlarmState(lua_State* L);
    static int isActive(lua_State* L);
    static int isDead(lua_State* L);
    static int isOutpost(lua_State* L);
    static int isPublic(lua_State* L);
    static int hasGates(lua_State* L);
    static int isValid(lua_State* L);
    static int isNotFriendly(lua_State* L);
    static int setVisible(lua_State* L);
    static int setRecentlyDiscovered(lua_State* L);
    static int distanceTo(lua_State* L);
    static int withinBordersRange(lua_State* L);
    static int getPowerStats(lua_State* L);
    static int isMyTown(lua_State* L);
};

} // namespace KenshiLua
