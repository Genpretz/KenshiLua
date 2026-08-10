#include "pch.h"
#include <ogre/OgreColourValue.h>
#include "kenshi\util\UtilityT.h"
#include "UtilityTBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/ZoneMapBinding.h"
#include "Bindings/Util/iVector2Binding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/physHitBinding.h"

namespace KenshiLua
{

static UtilityT* getInstance(lua_State* L, int idx)
{
    return checkObject<UtilityT>(L, idx, UtilityTBinding::getMetatableName());
}

// --- Getters for UtilityT ---
static int UtilityT_get_marker(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");
    lua_pushlightuserdata(L, (void*)instance->marker);
    return 1;
}

// --- Setters for UtilityT ---
int UtilityTBinding::_CONSTRUCTOR(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    UtilityT* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int UtilityTBinding::perlinNoise_2D(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    double x = (double)luaL_checknumber(L, 2);
    double y = (double)luaL_checknumber(L, 3);
    double zoom = (double)luaL_checknumber(L, 4);
    float dropPoint = (float)luaL_checknumber(L, 5);
    float result = instance->perlinNoise_2D(x, y, zoom, dropPoint);
    lua_pushnumber(L, result);
    return 1;
}

int UtilityTBinding::getTerrainHeightFastWithNormal(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    float x = (float)luaL_checknumber(L, 2);
    float z = (float)luaL_checknumber(L, 3);
    Ogre::Vector3 normal;
    readVector3(L, 4, normal);
    ZoneMap* map = checkObject<ZoneMap>(L, 5, ZoneMapBinding::getMetatableName());
    float result = instance->getTerrainHeightFastWithNormal(x, z, normal, map);
    lua_pushnumber(L, result);
    return 1;
}

int UtilityTBinding::getTerrainSlopeFast(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    float x = (float)luaL_checknumber(L, 2);
    float z = (float)luaL_checknumber(L, 3);
    ZoneMap* map = checkObject<ZoneMap>(L, 4, ZoneMapBinding::getMetatableName());
    float result = instance->getTerrainSlopeFast(x, z, map);
    lua_pushnumber(L, result);
    return 1;
}

int UtilityTBinding::profilesClear(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    instance->profilesClear();
    return 0;
}

int UtilityTBinding::profilesPrint(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    instance->profilesPrint();
    return 0;
}

int UtilityTBinding::profileGet(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    const std::string name = luaL_checkstring(L, 2);
    int result = instance->profileGet(name);
    lua_pushinteger(L, result);
    return 1;
}

int UtilityTBinding::flushMarkerQueue(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    instance->flushMarkerQueue();
    return 0;
}

int UtilityTBinding::removeMarkers(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    instance->removeMarkers();
    return 0;
}

int UtilityTBinding::folderExists(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    const std::string folder = luaL_checkstring(L, 2);
    bool result = instance->folderExists(folder);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UtilityTBinding::fileExistsASCII(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    const std::string file = luaL_checkstring(L, 2);
    bool result = instance->fileExistsASCII(file);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UtilityTBinding::createFile(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    const std::string path = luaL_checkstring(L, 2);
    const std::string content = luaL_checkstring(L, 3);
    bool result = instance->createFile(path, content);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UtilityTBinding::writeFile(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    const std::string path = luaL_checkstring(L, 2);
    const std::string content = luaL_checkstring(L, 3);
    bool append = lua_toboolean(L, 4) != 0;
    bool result = instance->writeFile(path, content, append);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UtilityTBinding::isFile(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    const std::string _path = luaL_checkstring(L, 2);
    bool result = instance->isFile(_path);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UtilityTBinding::isDirectory(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    const std::string _path = luaL_checkstring(L, 2);
    bool result = instance->isDirectory(_path);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UtilityTBinding::deleteFilesInFolder(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    const std::string dir = luaL_checkstring(L, 2);
    const std::string filter = luaL_checkstring(L, 3);
    bool recursive = lua_toboolean(L, 4) != 0;
    instance->deleteFilesInFolder(dir, filter, recursive);
    return 0;
}

int UtilityTBinding::deleteFolder(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    const std::string dir = luaL_checkstring(L, 2);
    instance->deleteFolder(dir);
    return 0;
}

int UtilityTBinding::deleteFile(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    const std::string dir = luaL_checkstring(L, 2);
    instance->deleteFile(dir);
    return 0;
}

int UtilityTBinding::moveFile(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    const std::string from = luaL_checkstring(L, 2);
    const std::string to = luaL_checkstring(L, 3);
    bool result = instance->moveFile(from, to);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UtilityTBinding::copyFile(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    const std::string from = luaL_checkstring(L, 2);
    const std::string to = luaL_checkstring(L, 3);
    bool result = instance->copyFile(from, to);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UtilityTBinding::copyFilesInFolder(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    const std::string from = luaL_checkstring(L, 2);
    const std::string to = luaL_checkstring(L, 3);
    const std::string filter = luaL_checkstring(L, 4);
    bool result = instance->copyFilesInFolder(from, to, filter);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UtilityTBinding::getTerrainHeight(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    float x = (float)luaL_checknumber(L, 1 + offset);
    float z = (float)luaL_checknumber(L, 2 + offset);
    float res = UtilityT::getTerrainHeight(x, z);
    lua_pushnumber(L, res);
    return 1;
}

int UtilityTBinding::getTerrainWithWaterHeight(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    float x = (float)luaL_checknumber(L, 1 + offset);
    float z = (float)luaL_checknumber(L, 2 + offset);
    float res = UtilityT::getTerrainWithWaterHeight(x, z);
    lua_pushnumber(L, res);
    return 1;
}

int UtilityTBinding::getTerrainWithWaterHeightFromRenderer(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    Ogre::Vector3 pos;
    readVector3(L, 1 + offset, pos);
    float res = UtilityT::getTerrainWithWaterHeightFromRenderer(pos);
    lua_pushnumber(L, res);
    return 1;
}

int UtilityTBinding::getPositionInWater(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    float x = (float)luaL_checknumber(L, 1 + offset);
    float z = (float)luaL_checknumber(L, 2 + offset);
    bool res = UtilityT::getPositionInWater(x, z);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int UtilityTBinding::getFloorHeight(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    Ogre::Vector3 origin;
    readVector3(L, 1 + offset, origin);
    if (lua_isnumber(L, 2 + offset))
    {
        int floorNum = (int)lua_tointeger(L, 2 + offset);
        bool withTerrain = lua_toboolean(L, 3 + offset) != 0;
        bool furniture = lua_toboolean(L, 4 + offset) != 0;
        float res = UtilityT::getFloorHeight(origin, floorNum, withTerrain, furniture);
        lua_pushnumber(L, res);
        return 1;
    }
    bool withTerrain = lua_toboolean(L, 2 + offset) != 0;
    bool furniture = lua_toboolean(L, 3 + offset) != 0;
    float res = UtilityT::getFloorHeight(origin, withTerrain, furniture);
    lua_pushnumber(L, res);
    return 1;
}

int UtilityTBinding::getBuildingGroundFloorHeight(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    Ogre::Vector3 origin;
    readVector3(L, 1 + offset, origin);
    bool withTerrain = lua_toboolean(L, 2 + offset) != 0;
    float res = UtilityT::getBuildingGroundFloorHeight(origin, withTerrain);
    lua_pushnumber(L, res);
    return 1;
}

int UtilityTBinding::isIndoors(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    Ogre::Vector3 point;
    readVector3(L, 1 + offset, point);
    Building* res = UtilityT::isIndoors(point);
    return pushObject<Building>(L, res, BuildingBinding::getMetatableName());
}

int UtilityTBinding::isIndoorsFast(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    Ogre::Vector3 point;
    readVector3(L, 1 + offset, point);
    bool res = UtilityT::isIndoorsFast(point);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int UtilityTBinding::isIndoors_forWaypoint(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    Ogre::Vector3 point;
    readVector3(L, 1 + offset, point);
    Building* res = UtilityT::isIndoors_forWaypoint(point);
    return pushObject<Building>(L, res, BuildingBinding::getMetatableName());
}

int UtilityTBinding::getFloorNumber(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    if (lua_isnumber(L, 1 + offset))
    {
        int collisionGroup = (int)lua_tointeger(L, 1 + offset);
        int res = UtilityT::getFloorNumber(collisionGroup);
        lua_pushinteger(L, res);
        return 1;
    }
    Ogre::Vector3 position;
    readVector3(L, 1 + offset, position);
    hand* hitBuilding = lua_isnoneornil(L, 2 + offset) ? nullptr : checkObject<hand>(L, 2 + offset, HandBinding::getMetatableName());
    int res = UtilityT::getFloorNumber(position, hitBuilding);
    lua_pushinteger(L, res);
    return 1;
}

int UtilityTBinding::getTerrainHeightFast(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    float x = (float)luaL_checknumber(L, 1 + offset);
    float z = (float)luaL_checknumber(L, 2 + offset);
    ZoneMap* map = checkObject<ZoneMap>(L, 3 + offset, ZoneMapBinding::getMetatableName());
    float res = UtilityT::getTerrainHeightFast(x, z, map);
    lua_pushnumber(L, res);
    return 1;
}

int UtilityTBinding::random(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    if (lua_gettop(L) >= 2 + offset)
    {
        float lo = (float)luaL_checknumber(L, 1 + offset);
        float hi = (float)luaL_checknumber(L, 2 + offset);
        float res = UtilityT::random(lo, hi);
        lua_pushnumber(L, res);
        return 1;
    }
    float res = UtilityT::random();
    lua_pushnumber(L, res);
    return 1;
}

int UtilityTBinding::randomBool(lua_State* L)
{
    bool res = UtilityT::randomBool();
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int UtilityTBinding::randomInt(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    int lo = (int)luaL_checkinteger(L, 1 + offset);
    int hi = (int)luaL_checkinteger(L, 2 + offset);
    int res = UtilityT::randomInt(lo, hi);
    lua_pushinteger(L, res);
    return 1;
}

int UtilityTBinding::seed(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    if (lua_gettop(L) >= 1 + offset && lua_isnumber(L, 1 + offset))
    {
        unsigned int s = (unsigned int)lua_tointeger(L, 1 + offset);
        UtilityT::seed(s);
        return 0;
    }
    UtilityT::seed();
    return 0;
}

int UtilityTBinding::round(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    float value = (float)luaL_checknumber(L, 1 + offset);
    int res = UtilityT::round(value);
    lua_pushinteger(L, res);
    return 1;
}

int UtilityTBinding::nlerp(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    float a = (float)luaL_checknumber(L, 1 + offset);
    float b = (float)luaL_checknumber(L, 2 + offset);
    float t = (float)luaL_checknumber(L, 3 + offset);
    float res = UtilityT::nlerp(a, b, t);
    lua_pushnumber(L, res);
    return 1;
}

int UtilityTBinding::getNextPow2(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    int value = (int)luaL_checkinteger(L, 1 + offset);
    int res = UtilityT::getNextPow2(value);
    lua_pushinteger(L, res);
    return 1;
}

int UtilityTBinding::quatSetDirection(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    Ogre::Quaternion q;
    readQuaternion(L, 1 + offset, q);
    Ogre::Vector3 targetDir;
    readVector3(L, 2 + offset, targetDir);
    Ogre::Vector3 facing;
    readVector3(L, 3 + offset, facing);
    UtilityT::quatSetDirection(q, targetDir, facing);
    pushQuaternion(L, q);
    return 1;
}

int UtilityTBinding::getSubMapSector(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    float X = (float)luaL_checknumber(L, 1 + offset);
    float Z = (float)luaL_checknumber(L, 2 + offset);
    iVector2 res = UtilityT::getSubMapSector(X, Z);
    return pushValue<iVector2>(L, res, iVector2Binding::getMetatableName());
}

int UtilityTBinding::getSubMapSectorBounds(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    iVector2 sector = *checkObject<iVector2>(L, 1 + offset, iVector2Binding::getMetatableName());
    Ogre::Vector4 res = UtilityT::getSubMapSectorBounds(sector);
    lua_createtable(L, 0, 4);
    lua_pushnumber(L, res.x); lua_setfield(L, -2, "x");
    lua_pushnumber(L, res.y); lua_setfield(L, -2, "y");
    lua_pushnumber(L, res.z); lua_setfield(L, -2, "z");
    lua_pushnumber(L, res.w); lua_setfield(L, -2, "w");
    return 1;
}

int UtilityTBinding::getResourceFilePath(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    std::string filename = luaL_checkstring(L, 1 + offset);
    std::string filepath;
    bool res = UtilityT::getResourceFilePath(filename, filepath);
    if (res)
    {
        lua_pushstring(L, filepath.c_str());
        return 1;
    }
    lua_pushnil(L);
    return 1;
}

int UtilityTBinding::removePathFromString(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    std::string s = luaL_checkstring(L, 1 + offset);
    std::string res = UtilityT::removePathFromString(s);
    lua_pushstring(L, res.c_str());
    return 1;
}

int UtilityTBinding::removeFilenameFromPath(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    std::string s = luaL_checkstring(L, 1 + offset);
    std::string res = UtilityT::removeFilenameFromPath(s);
    lua_pushstring(L, res.c_str());
    return 1;
}

int UtilityTBinding::removeFileExtensionFromString(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    std::string s = luaL_checkstring(L, 1 + offset);
    std::string res = UtilityT::removeFileExtensionFromString(s);
    lua_pushstring(L, res.c_str());
    return 1;
}

int UtilityTBinding::getFileExtensionFromString(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    std::string s = luaL_checkstring(L, 1 + offset);
    std::string res = UtilityT::getFileExtensionFromString(s);
    lua_pushstring(L, res.c_str());
    return 1;
}

int UtilityTBinding::removeInvalidFileNameChars(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    std::string str = luaL_checkstring(L, 1 + offset);
    UtilityT::removeInvalidFileNameChars(str);
    lua_pushstring(L, str.c_str());
    return 1;
}

int UtilityTBinding::compareStringsCaseInsenstive(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    std::string a = luaL_checkstring(L, 1 + offset);
    std::string b = luaL_checkstring(L, 2 + offset);
    bool res = UtilityT::compareStringsCaseInsenstive(a, b);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int UtilityTBinding::makeSureGameFolderExists(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    std::string relativefolder = luaL_checkstring(L, 1 + offset);
    UtilityT::makeSureGameFolderExists(relativefolder);
    return 0;
}

int UtilityTBinding::makeSureFolderExists(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    std::string folder = luaL_checkstring(L, 1 + offset);
    UtilityT::makeSureFolderExists(folder);
    return 0;
}

int UtilityTBinding::getFullPath(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    std::string dir = luaL_checkstring(L, 1 + offset);
    std::string res = UtilityT::getFullPath(dir);
    lua_pushstring(L, res.c_str());
    return 1;
}

int UtilityTBinding::positionIsInFrontOfMe(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    Ogre::Vector3 facingDir;
    readVector3(L, 1 + offset, facingDir);
    Ogre::Vector3 targetDir;
    readVector3(L, 2 + offset, targetDir);
    bool res = UtilityT::positionIsInFrontOfMe(facingDir, targetDir);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int UtilityTBinding::pointInPlane(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    Ogre::Vector3 norm, planepos, point;
    readVector3(L, 1 + offset, norm);
    readVector3(L, 2 + offset, planepos);
    readVector3(L, 3 + offset, point);
    bool res = UtilityT::pointInPlane(norm, planepos, point);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int UtilityTBinding::colorToGUIString(lua_State* L)
{
    int offset = lua_isuserdata(L, 1) ? 1 : 0;
    float r = (float)luaL_checknumber(L, 1 + offset);
    float g = (float)luaL_checknumber(L, 2 + offset);
    float b = (float)luaL_checknumber(L, 3 + offset);
    float a = lua_isnumber(L, 4 + offset) ? (float)lua_tonumber(L, 4 + offset) : 1.0f;
    Ogre::ColourValue col(r, g, b, a);
    std::string res = UtilityT::colorToGUIString(col);
    lua_pushstring(L, res.c_str());
    return 1;
}

int UtilityTBinding::getFilesInDir(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    lektor<std::string>* out = LektorStringBinding<std::string>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to getFilesInDir must be lektor<std::string>");

    std::string dir = luaL_checkstring(L, 3);
    std::string type = luaL_checkstring(L, 4);
    bool res = instance->getFilesInDir(*out, dir, type);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int UtilityTBinding::getFilesInGameDir(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    lektor<std::string>* out = LektorStringBinding<std::string>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to getFilesInGameDir must be lektor<std::string>");

    std::string dir = luaL_checkstring(L, 3);
    std::string type = luaL_checkstring(L, 4);
    bool res = instance->getFilesInGameDir(*out, dir, type);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int UtilityTBinding::getDirsInDir(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    lektor<std::string>* out = LektorStringBinding<std::string>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to getDirsInDir must be lektor<std::string>");

    std::string dir = luaL_checkstring(L, 3);
    instance->getDirsInDir(*out, dir);
    return 0;
}

int UtilityTBinding::readFile(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    std::string path = luaL_checkstring(L, 2);
    std::string content;
    bool res = instance->readFile(path, content);
    if (res)
    {
        lua_pushstring(L, content.c_str());
        return 1;
    }
    lua_pushnil(L);
    return 1;
}

int UtilityTBinding::roundToNearest(lua_State* L)
{
    UtilityT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UtilityT is nil");

    float input = (float)luaL_checknumber(L, 2);
    int roundTo = (int)luaL_checkinteger(L, 3);
    instance->roundToNearest(input, roundTo);
    lua_pushnumber(L, input);
    return 1;
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - UtilityT_get_marker: Ogre::Entity* (unbound pointer)
  - UtilityTBinding::_CONSTRUCTOR: UtilityT* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 52: cachedViewMatrix (Ogre::Matrix4) - unsupported type
  line 102: timer (TimerClass) - unsupported type
*/

int UtilityTBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int UtilityTBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.UtilityT object");
    return 1;
}

void UtilityTBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       UtilityTBinding::gc },
        { "__tostring", UtilityTBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", UtilityTBinding::_CONSTRUCTOR },
        { "perlinNoise_2D", UtilityTBinding::perlinNoise_2D },
        { "getTerrainHeightFastWithNormal", UtilityTBinding::getTerrainHeightFastWithNormal },
        { "getTerrainSlopeFast", UtilityTBinding::getTerrainSlopeFast },
        { "profilesClear", UtilityTBinding::profilesClear },
        { "profilesPrint", UtilityTBinding::profilesPrint },
        { "profileGet", UtilityTBinding::profileGet },
        { "flushMarkerQueue", UtilityTBinding::flushMarkerQueue },
        { "removeMarkers", UtilityTBinding::removeMarkers },
        { "folderExists", UtilityTBinding::folderExists },
        { "fileExistsASCII", UtilityTBinding::fileExistsASCII },
        { "createFile", UtilityTBinding::createFile },
        { "writeFile", UtilityTBinding::writeFile },
        { "isFile", UtilityTBinding::isFile },
        { "isDirectory", UtilityTBinding::isDirectory },
        { "deleteFilesInFolder", UtilityTBinding::deleteFilesInFolder },
        { "deleteFolder", UtilityTBinding::deleteFolder },
        { "deleteFile", UtilityTBinding::deleteFile },
        { "moveFile", UtilityTBinding::moveFile },
        { "copyFile", UtilityTBinding::copyFile },
        { "copyFilesInFolder", UtilityTBinding::copyFilesInFolder },
        { "getTerrainHeight", UtilityTBinding::getTerrainHeight },
        { "getTerrainWithWaterHeight", UtilityTBinding::getTerrainWithWaterHeight },
        { "getTerrainWithWaterHeightFromRenderer", UtilityTBinding::getTerrainWithWaterHeightFromRenderer },
        { "getPositionInWater", UtilityTBinding::getPositionInWater },
        { "getFloorHeight", UtilityTBinding::getFloorHeight },
        { "getBuildingGroundFloorHeight", UtilityTBinding::getBuildingGroundFloorHeight },
        { "isIndoors", UtilityTBinding::isIndoors },
        { "isIndoorsFast", UtilityTBinding::isIndoorsFast },
        { "isIndoors_forWaypoint", UtilityTBinding::isIndoors_forWaypoint },
        { "getFloorNumber", UtilityTBinding::getFloorNumber },
        { "getTerrainHeightFast", UtilityTBinding::getTerrainHeightFast },
        { "random", UtilityTBinding::random },
        { "randomBool", UtilityTBinding::randomBool },
        { "randomInt", UtilityTBinding::randomInt },
        { "seed", UtilityTBinding::seed },
        { "round", UtilityTBinding::round },
        { "nlerp", UtilityTBinding::nlerp },
        { "getNextPow2", UtilityTBinding::getNextPow2 },
        { "quatSetDirection", UtilityTBinding::quatSetDirection },
        { "getSubMapSector", UtilityTBinding::getSubMapSector },
        { "getSubMapSectorBounds", UtilityTBinding::getSubMapSectorBounds },
        { "getResourceFilePath", UtilityTBinding::getResourceFilePath },
        { "removePathFromString", UtilityTBinding::removePathFromString },
        { "removeFilenameFromPath", UtilityTBinding::removeFilenameFromPath },
        { "removeFileExtensionFromString", UtilityTBinding::removeFileExtensionFromString },
        { "getFileExtensionFromString", UtilityTBinding::getFileExtensionFromString },
        { "removeInvalidFileNameChars", UtilityTBinding::removeInvalidFileNameChars },
        { "compareStringsCaseInsenstive", UtilityTBinding::compareStringsCaseInsenstive },
        { "makeSureGameFolderExists", UtilityTBinding::makeSureGameFolderExists },
        { "makeSureFolderExists", UtilityTBinding::makeSureFolderExists },
        { "getFullPath", UtilityTBinding::getFullPath },
        { "positionIsInFrontOfMe", UtilityTBinding::positionIsInFrontOfMe },
        { "pointInPlane", UtilityTBinding::pointInPlane },
        { "colorToGUIString", UtilityTBinding::colorToGUIString },
        { "getFilesInDir", UtilityTBinding::getFilesInDir },
        { "getFilesInGameDir", UtilityTBinding::getFilesInGameDir },
        { "getDirsInDir", UtilityTBinding::getDirsInDir },
        { "readFile", UtilityTBinding::readFile },
        { "roundToNearest", UtilityTBinding::roundToNearest },
        { 0, 0 }
    };

    registerClass(
        L, 
        UtilityTBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, UtilityTBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "marker", UtilityT_get_marker);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua