#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class AppearanceAnimalBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AppearanceAnimal"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int createBody(lua_State* L);
    static int _NV_createBody(lua_State* L);
    static int updateCharaterTexture(lua_State* L);
    static int _NV_updateCharaterTexture(lua_State* L);
};
}