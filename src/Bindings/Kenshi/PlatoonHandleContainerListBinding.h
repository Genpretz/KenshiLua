#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class PlatoonHandleContainerListBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.PlatoonHandleContainerList"; }
    static void registerBinding(lua_State* L);

    static int getCharacterOrZero(lua_State* L);
    static int getCharacterOrPlatoon(lua_State* L);
    static int getActivePlatoon(lua_State* L);
    static int setUnloaded(lua_State* L);
    static int _NV_setUnloaded(lua_State* L);
    static int destroy(lua_State* L);
    static int _NV_destroy(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};

} // namespace KenshiLua

