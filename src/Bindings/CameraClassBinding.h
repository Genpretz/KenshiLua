#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

class CameraClass;

namespace KenshiLua
{

class CameraClassBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CameraClass"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    // Methods
    static int focusCameraOnObject(lua_State* L);
    static int teleport(lua_State* L);
    static int followObject(lua_State* L);
    static int stopFollowing(lua_State* L);
    static int getFollowObject(lua_State* L);
    static int manuallySetOrientationAndZoom(lua_State* L);
    static int getFacingDirection(lua_State* L);
    static int getCenter(lua_State* L);
    static int getCameraPos(lua_State* L);
    static int updateAudio(lua_State* L);
    static int isFreeCameraMode(lua_State* L);
    static int setFreeCameraMode(lua_State* L);
    static int move(lua_State* L);
    static int zoom(lua_State* L);
    static int rotate(lua_State* L);
    static int rotationUpdate(lua_State* L);
    static int setZoomDist(lua_State* L);
    static int save(lua_State* L);
    static int load(lua_State* L);
    static int reset(lua_State* L);
    static int toGround(lua_State* L);
    static int isVisible(lua_State* L);
    static int intersectScreenEdge(lua_State* L);
    static int updateOptionSettings(lua_State* L);
    static int update(lua_State* L);
};

} // namespace KenshiLua
