#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class GameDataContainerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.GameDataContainer"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int createNewData(lua_State* L);
    static int getDataByName(lua_State* L);
    static int removeAllDataOfType(lua_State* L);
    static int clearInstances(lua_State* L);
    static int clearButDontDestroy(lua_State* L);
    static int clearButDontDestroyPlatoons(lua_State* L);
    static int clearAndDestroy(lua_State* L);
    static int getNewID(lua_State* L);
    static int preLoadAllReferencePtrs(lua_State* L);
    static int clearAllReferencePtrs(lua_State* L);
    static int setName(lua_State* L);
};
}