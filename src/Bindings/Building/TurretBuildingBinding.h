#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class TurretBuildingBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.TurretBuilding"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int setup(lua_State* L);
    static int _NV_setup(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int needsUpdate(lua_State* L);
    static int _NV_needsUpdate(lua_State* L);
    static int getProductionMultForGUI(lua_State* L);
    static int _NV_getProductionMultForGUI(lua_State* L);
    static int setVisible(lua_State* L);
    static int _NV_setVisible(lua_State* L);
    static int amInsideTownWalls(lua_State* L);
    static int _NV_amInsideTownWalls(lua_State* L);
    static int notifyConstructionComplete(lua_State* L);
    static int _NV_notifyConstructionComplete(lua_State* L);
    static int createPhysical(lua_State* L);
    static int _NV_createPhysical(lua_State* L);
    static int destroyPhysical(lua_State* L);
    static int _NV_destroyPhysical(lua_State* L);
    static int onBuildingLoaded(lua_State* L);
    static int _NV_onBuildingLoaded(lua_State* L);
    static int calculatePowerMult(lua_State* L);
    static int clearTownBuildingsManagerPtr(lua_State* L);
    static int _NV_clearTownBuildingsManagerPtr(lua_State* L);
};
}