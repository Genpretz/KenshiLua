#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class NavMeshGeneratorBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.NavMeshGenerator"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int isGenerating(lua_State* L);
    static int threadProc(lua_State* L);
    static int _NV_threadProc(lua_State* L);
    static int updateBT(lua_State* L);
    static int generateTaskBT(lua_State* L);
    static int validateBuildingStates(lua_State* L);
    static int carve(lua_State* L);
    static int splice(lua_State* L);
    static int stitchInterior(lua_State* L);
    static int stitchExterior(lua_State* L);
    static int revertSettings(lua_State* L);
    static int unlockTask(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int hasJob(lua_State* L);
    static int update(lua_State* L);
};
}