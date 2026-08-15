#pragma once

#include "kenshi/gui/MapScreen.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class MapScreenBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MapScreen"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int clear(lua_State* L);
    static int getVisible(lua_State* L);
    static int centerCamera(lua_State* L);
    static int clearTempMarkers(lua_State* L);
    static int refresh(lua_State* L);
    static int update(lua_State* L);
    static int addSquad(lua_State* L);
    static int removeSquad(lua_State* L);
    static int hide(lua_State* L);
    static int setMovementMarker(lua_State* L);
    static int showRoads(lua_State* L);
    static int updateZoom(lua_State* L);
    static int updateCameraMarker(lua_State* L);
    static int refreshTowns(lua_State* L);
    static int refreshSquads(lua_State* L);
    static int updateCharacterMarker(lua_State* L);
    static int getMouseWorldPosition(lua_State* L);
    static int setupRoads(lua_State* L);
    static int updateRoads(lua_State* L);
    static int updatePlayerTownMapMarker(lua_State* L);
    static int worldToMapCoords(lua_State* L);
    static int mapCoordsToWorld(lua_State* L);
};
}