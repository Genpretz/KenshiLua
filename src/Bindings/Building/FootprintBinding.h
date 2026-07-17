#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class FootprintBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Footprint"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int getSpace(lua_State* L);
    static int getMarker(lua_State* L);
    static int setValid(lua_State* L);
    static int getValid(lua_State* L);
    static int validate(lua_State* L);
    static int fakeOppositeValidate(lua_State* L);
    static int collisionTestCharacters(lua_State* L);
    static int validFloorTest(lua_State* L);
    static int isGroundValid(lua_State* L);
    static int getWorldCorner(lua_State* L);
    static int updateBox(lua_State* L);
    static int _NV_updateBox(lua_State* L);
    static int getGroundHeight(lua_State* L);
};
}