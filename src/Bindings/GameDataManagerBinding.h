#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class GameDataManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.GameDataManager"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int reloadGameData(lua_State* L);
    static int postProcessingTheDatas(lua_State* L);
    static int getMapSector(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}