#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class RootObjectContainerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.RootObjectContainer"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int getThing(lua_State* L);
    static int getNumThings(lua_State* L);
    static int getThings(lua_State* L);
    static int getSelectedObjects(lua_State* L);
    static int _NV_getSelectedObjects(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int addActiveObject(lua_State* L);
    static int _NV_addActiveObject(lua_State* L);
    static int removeObject(lua_State* L);
    static int _NV_removeObject(lua_State* L);
    static int serialiseThings(lua_State* L);
    static int loadToReality(lua_State* L);
    static int _NV_loadToReality(lua_State* L);
    static int loadInstance(lua_State* L);
    static int _NV_loadInstance(lua_State* L);
};
}
