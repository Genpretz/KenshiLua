#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class RootObjectBaseBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.RootObjectBase"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int isValid(lua_State* L);
    static int getName(lua_State* L);
    static int _NV_getName(lua_State* L);
    static int setName(lua_State* L);
    static int _NV_setName(lua_State* L);
    static int getGameData(lua_State* L);
    static int _NV_getGameData(lua_State* L);
    static int getDataType(lua_State* L);
    static int _NV_getDataType(lua_State* L);
    static int typeIsAnItem(lua_State* L);
    static int _NV_typeIsAnItem(lua_State* L);
    static int isUnconcious(lua_State* L);
    static int _NV_isUnconcious(lua_State* L);
    static int getPositionForWaypoint(lua_State* L);
    static int _NV_getPositionForWaypoint(lua_State* L);
    static int getPosition(lua_State* L);
    static int _NV_getPosition(lua_State* L);
    static int getMovementSpeed(lua_State* L);
    static int _NV_getMovementSpeed(lua_State* L);
    static int getMovementDirection(lua_State* L);
    static int _NV_getMovementDirection(lua_State* L);
    static int getFaction(lua_State* L);
    static int _NV_getFaction(lua_State* L);
    static int hasFaction(lua_State* L);
    static int getFloor(lua_State* L);
    static int _NV_getFloor(lua_State* L);
    static int getOwnerships(lua_State* L);
    static int _NV_getOwnerships(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int getSensoryData(lua_State* L);
    static int _NV_getSensoryData(lua_State* L);
    static int getStateBroadcast(lua_State* L);
    static int _NV_getStateBroadcast(lua_State* L);
    static int setHandle(lua_State* L);
    static int _NV_setHandle(lua_State* L);
    static int serialise(lua_State* L);
    static int loadFromSerialise(lua_State* L);

    static int getHandle(lua_State* L);
    static int getCurrentTownLocation(lua_State* L);
    static int _NV_getCurrentTownLocation(lua_State* L);
    static int setFaction(lua_State* L);
    static int _NV_setFaction(lua_State* L);
};
}
