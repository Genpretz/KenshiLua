#pragma once

#include "kenshi/gui/LevelEditor.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class LevelEditorBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.LevelEditor"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int close(lua_State* L);
    static int update(lua_State* L);
    static int updateGizmo(lua_State* L);
    static int levelEditMode(lua_State* L);
    static int isInteriorEditMode(lua_State* L);
    static int getActiveModIndex(lua_State* L);
    static int getActiveMod(lua_State* L);
    static int isBaseActive(lua_State* L);
    static int setEditSquad(lua_State* L);
    static int repath(lua_State* L);
    static int toggleSeedMode(lua_State* L);
    static int clearSeedPoints(lua_State* L);
    static int setSeedMode(lua_State* L);
    static int toggleRoadEditor(lua_State* L);
    static int toggleFoliageRemoval(lua_State* L);
    static int clearChanges(lua_State* L);
    static int deleteDuplicateBuildings(lua_State* L);
    static int fixMountedBuildings(lua_State* L);
    static int deleteAll(lua_State* L);
    static int adjustAltitudeSpeed(lua_State* L);
    static int fixInvalidInteriorFurnitureStates(lua_State* L);
    static int fixBuildingFloorState(lua_State* L);
    static int setSelectedObject(lua_State* L);
    static int updateRoadEditor(lua_State* L);
    static int setRoadWidth(lua_State* L);
    static int setRoadHidden(lua_State* L);
    static int drawRoads(lua_State* L);
    static int eraseRoads(lua_State* L);
    static int drawAllRoads(lua_State* L);
    static int projectRoads(lua_State* L);
    static int validateRoads(lua_State* L);
    static int createRoadMarker(lua_State* L);
    static int destroyRoadMaker(lua_State* L);
    static int updateFoliageRemoval(lua_State* L);
    static int updateSeedEditor(lua_State* L);
    static int deleteObject(lua_State* L);
};
}