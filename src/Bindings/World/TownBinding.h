#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

class TownBase;
class Town;

namespace KenshiLua
{

class TownBaseBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TownBase"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    // Polymorphic helpers
    static int pushTownBase(lua_State* L, TownBase* t);
    static TownBase* getTownBase(lua_State* L, int idx);
    static TownBase* checkTownBase(lua_State* L, int idx);

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
    static int isMyTown(lua_State* L);
};

class TownBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Town"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    // Polymorphic helpers
    static int pushTown(lua_State* L, Town* t);
    static Town* getTown(lua_State* L, int idx);
    static Town* checkTown(lua_State* L, int idx);

    static int getPowerStats(lua_State* L);
};

} // namespace KenshiLua
