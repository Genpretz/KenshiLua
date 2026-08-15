#pragma once

#include "kenshi/Platoon.h"

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

    static int _CONSTRUCTOR(lua_State* L);
    static int setHandle(lua_State* L);
    static int takeMoney(lua_State* L);
    static int _NV_takeMoney(lua_State* L);
    static int takeMoneyByForce(lua_State* L);
    static int _NV_takeMoneyByForce(lua_State* L);
    static int getMoney(lua_State* L);
    static int addMoney(lua_State* L);
    static int setMoney(lua_State* L);
    static int setHomeBuildingDesignation(lua_State* L);
    static int copyFrom(lua_State* L);
    static int serialise(lua_State* L);
    static int load(lua_State* L);
    static int setHomeTown(lua_State* L);
    static int isMyTown(lua_State* L);
    static int canIUseThisBuilding(lua_State* L);
    static int declareOccupiedTown(lua_State* L);
    static int getOccupiedTownFaction(lua_State* L);
    static int addOwnedObject(lua_State* L);
    static int removeOwnedObject(lua_State* L);
    static int isOwned(lua_State* L);
    static int setHomeBuilding(lua_State* L);
    static int getOwnedBuildingsH(lua_State* L);
    static int getOwnedBuildingPtrs(lua_State* L);
    static int getHomeFurnitureOfType(lua_State* L);
    static int getOwnedPtrs(lua_State* L);
    static int getBuildingsWithFunction(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}