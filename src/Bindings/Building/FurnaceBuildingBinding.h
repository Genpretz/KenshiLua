#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class FurnaceBuildingBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.FurnaceBuilding"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int createInventoryLayout(lua_State* L);
    static int _NV_createInventoryLayout(lua_State* L);
    static int setupFromData(lua_State* L);
    static int _NV_setupFromData(lua_State* L);
    static int getInputValueTotal(lua_State* L);
    static int getDefaultTask(lua_State* L);
    static int _NV_getDefaultTask(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int updateInputs(lua_State* L);
    static int _NV_updateInputs(lua_State* L);
    static int updateOutput(lua_State* L);
    static int _NV_updateOutput(lua_State* L);
};
}