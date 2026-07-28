#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class UtilityTBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.UtilityT"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int perlinNoise_2D(lua_State* L);
    static int getTerrainHeightFastWithNormal(lua_State* L);
    static int getTerrainSlopeFast(lua_State* L);
    static int profilesClear(lua_State* L);
    static int profilesPrint(lua_State* L);
    static int profileGet(lua_State* L);
    static int flushMarkerQueue(lua_State* L);
    static int removeMarkers(lua_State* L);
    static int folderExists(lua_State* L);
    static int fileExistsASCII(lua_State* L);
    static int createFile(lua_State* L);
    static int writeFile(lua_State* L);
    static int isFile(lua_State* L);
    static int isDirectory(lua_State* L);
    static int deleteFilesInFolder(lua_State* L);
    static int deleteFolder(lua_State* L);
    static int deleteFile(lua_State* L);
    static int moveFile(lua_State* L);
    static int copyFile(lua_State* L);
    static int copyFilesInFolder(lua_State* L);
};
}