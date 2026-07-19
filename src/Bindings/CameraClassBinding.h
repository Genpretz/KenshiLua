#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class CameraClassBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CameraClass"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int reset(lua_State* L);
    static int update(lua_State* L);
    static int updateOptionSettings(lua_State* L);
    static int teleport(lua_State* L);
    static int stopFollowing(lua_State* L);
    static int manuallySetOrientationAndZoom(lua_State* L);
    static int getFacingDirection(lua_State* L);
    static int getCenter(lua_State* L);
    static int getCameraPos(lua_State* L);
    static int isInitialised(lua_State* L);
    static int isFreeCameraMode(lua_State* L);
    static int setFreeCameraMode(lua_State* L);
    static int updateFreeCamera(lua_State* L);
    static int move(lua_State* L);
    static int zoom(lua_State* L);
    static int toGround(lua_State* L);
    static int setZoomDist(lua_State* L);
    static int rotate(lua_State* L);
    static int rotationUpdate(lua_State* L);
    static int updateAudio(lua_State* L);
};
}
