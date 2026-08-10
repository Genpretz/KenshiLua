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
    static int getTerrainHeight(lua_State* L);
    static int getTerrainWithWaterHeight(lua_State* L);
    static int getTerrainWithWaterHeightFromRenderer(lua_State* L);
    static int getPositionInWater(lua_State* L);
    static int getFloorHeight(lua_State* L);
    static int getBuildingGroundFloorHeight(lua_State* L);
    static int isIndoors(lua_State* L);
    static int isIndoorsFast(lua_State* L);
    static int isIndoors_forWaypoint(lua_State* L);
    static int getFloorNumber(lua_State* L);
    static int getTerrainHeightFast(lua_State* L);
    static int random(lua_State* L);
    static int randomBool(lua_State* L);
    static int randomInt(lua_State* L);
    static int seed(lua_State* L);
    static int round(lua_State* L);
    static int nlerp(lua_State* L);
    static int getNextPow2(lua_State* L);
    static int quatSetDirection(lua_State* L);
    static int getSubMapSector(lua_State* L);
    static int getSubMapSectorBounds(lua_State* L);
    static int getResourceFilePath(lua_State* L);
    static int removePathFromString(lua_State* L);
    static int removeFilenameFromPath(lua_State* L);
    static int removeFileExtensionFromString(lua_State* L);
    static int getFileExtensionFromString(lua_State* L);
    static int removeInvalidFileNameChars(lua_State* L);
    static int compareStringsCaseInsenstive(lua_State* L);
    static int makeSureGameFolderExists(lua_State* L);
    static int makeSureFolderExists(lua_State* L);
    static int getFullPath(lua_State* L);
    static int positionIsInFrontOfMe(lua_State* L);
    static int pointInPlane(lua_State* L);
    static int colorToGUIString(lua_State* L);
    static int getFilesInDir(lua_State* L);
    static int getFilesInGameDir(lua_State* L);
    static int getDirsInDir(lua_State* L);
    static int readFile(lua_State* L);
    static int roundToNearest(lua_State* L);
};
}