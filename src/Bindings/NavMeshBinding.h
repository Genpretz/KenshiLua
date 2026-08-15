#pragma once

#include "kenshi/NavMesh.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class NavMeshBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.NavMesh"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int initialise(lua_State* L);
    static int shutdown(lua_State* L);
    static int create(lua_State* L);
    static int unload(lua_State* L);
    static int destroy(lua_State* L);
    static int getZoneEdge(lua_State* L);
    static int getClosestExteriorPoint(lua_State* L);
    static int setDoorState(lua_State* L);
    static int isInterior(lua_State* L);
    static int getPositionValid(lua_State* L);
    static int processCompletedCharacterMessages(lua_State* L);
    static int processDoorRequests(lua_State* L);
    static int getPolygonID(lua_State* L);
    static int validateFaceKey(lua_State* L);
    static int isGenerating(lua_State* L);
    static int getWorldShift(lua_State* L);
    static int threadProc(lua_State* L);
    static int _NV_threadProc(lua_State* L);
    static int update(lua_State* L);
    static int setupHavok(lua_State* L);
    static int shutdownHavok(lua_State* L);
    static int loadZone(lua_State* L);
    static int unloadZone(lua_State* L);
    static int unloadBuilding(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}