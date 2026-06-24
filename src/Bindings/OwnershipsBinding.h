#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class OwnershipsBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Ownerships"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int takeMoney(lua_State* L);
    static int _NV_takeMoney(lua_State* L);
    static int takeMoneyByForce(lua_State* L);
    static int _NV_takeMoneyByForce(lua_State* L);
    static int getMoney(lua_State* L);
    static int addMoney(lua_State* L);
    static int setMoney(lua_State* L);
    static int setHomeBuildingDesignation(lua_State* L);
    static int getOccupiedTownFaction(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}