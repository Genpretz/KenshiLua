#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

class Building;

namespace KenshiLua
{

class BuildingBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Building"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    // Reads
    static int getName(lua_State* L);
    static int getPosition(lua_State* L);
    static int getBuildingDesignation(lua_State* L);
    static int getBuildingClass(lua_State* L);
    static int getSpecialFunction(lua_State* L);
    static int getBuildState(lua_State* L);
    static int getConstructionProgress(lua_State* L);
    static int isPublic(lua_State* L);
    static int isAShop(lua_State* L);
    static int isForSale(lua_State* L);
    static int isAWall(lua_State* L);
    static int isDamaged(lua_State* L);
    static int isDestroyed(lua_State* L);
    static int isBroken(lua_State* L);
    static int isPowerOn(lua_State* L);
    static int getScale(lua_State* L);
    static int getMiningResourceLevel(lua_State* L);
    static int isValid(lua_State* L);

    // Writes
    static int setDesignation(lua_State* L);
    static int setBroken(lua_State* L);
    static int setDestroyed(lua_State* L);
    static int setConstructionProgress(lua_State* L);
    static int setVisible(lua_State* L);
    static int switchPowerOn(lua_State* L);
    static int togglePublic(lua_State* L);
};

} // namespace KenshiLua
