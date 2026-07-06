#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class WallBuildingBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.WallBuilding"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int getUseableStuff(lua_State* L);
    static int _NV_getUseableStuff(lua_State* L);
    static int getReachRange(lua_State* L);
    static int _NV_getReachRange(lua_State* L);
    static int isForSale(lua_State* L);
    static int _NV_isForSale(lua_State* L);
    static int createPhysical(lua_State* L);
    static int _NV_createPhysical(lua_State* L);
    static int isDamaged(lua_State* L);
    static int _NV_isDamaged(lua_State* L);
    static int getPositionForWaypoint_outside(lua_State* L);
    static int getOutsideGateCode(lua_State* L);
    static int isAWall(lua_State* L);
    static int _NV_isAWall(lua_State* L);
    static int canUpgrade(lua_State* L);
    static int _NV_canUpgrade(lua_State* L);
    static int addConstructionProgress(lua_State* L);
    static int _NV_addConstructionProgress(lua_State* L);
    static int setConstructionProgress(lua_State* L);
    static int _NV_setConstructionProgress(lua_State* L);
    static int notifyConstructionComplete(lua_State* L);
    static int _NV_notifyConstructionComplete(lua_State* L);
    static int addDismantleProgress(lua_State* L);
    static int _NV_addDismantleProgress(lua_State* L);
    static int notifyConstructionDismantling(lua_State* L);
    static int _NV_notifyConstructionDismantling(lua_State* L);
    static int getBuildState(lua_State* L);
    static int _NV_getBuildState(lua_State* L);
    static int isALittleWallPartLikeACornerOrSomething(lua_State* L);
    static int isAShortWallPart(lua_State* L);
};
}