#include "pch.h"
#include "kenshi\util\UtilityT.h"
#include "UtilityTBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/ZoneMapBinding.h"
#include "Bindings/Util/iVector2Binding.h"
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

/*
Skipped methods needing manual binding:
  line 53: Ogre::Ray getMouseRay(...) - static method
  line 54: void mouseTrace(...) - static method
  line 55: void rayTrace(...) - static method
  line 56: bool ceilingTrace(...) - static method
  line 57: void traceNoActors(...) - static method
  line 58: void trace(...) - static method
  line 59: void traceFloorHeight(...) - static method
  line 60: void _trace_TEST(...) - static method
  line 61: Ogre::Vector3 tracePosOnly(...) - static method
  line 62: void sphereTrace(...) - static method
  line 63: void boxTrace(...) - static method
  line 64: void mouseTraceAll(...) - static method
  line 65: void traceAll(...) - static method
  line 66: float getTerrainHeight(...) - static method
  line 67: float getTerrainWithWaterHeight(...) - static method
  line 68: float getTerrainWithWaterHeightFromRenderer(...) - static method
  line 69: bool getPositionInWater(...) - static method
  line 70: float getFloorHeight(...) - static method
  line 71: float getFloorHeight(...) - static method
  line 72: float getBuildingGroundFloorHeight(...) - static method
  line 73: Building* isIndoors(...) - static method
  line 74: bool isIndoorsFast(...) - static method
  line 75: Building* isIndoors_forWaypoint(...) - static method
  line 76: void cascadeSetStatic(...) - static method
  line 78: int getFloorNumber(...) - static method
  line 79: int getFloorNumber(...) - static method
  line 81: float getTerrainHeightFast(...) - static method
  line 83: float random(...) - static method
  line 84: float random(...) - static method
  line 85: bool randomBool(...) - static method
  line 86: int randomInt(...) - static method
  line 87: void seed(...) - static method
  line 88: void seed(...) - static method
  line 89: int round(...) - static method
  line 90: float nlerp(...) - static method
  line 91: int getNextPow2(...) - static method
  line 92: void quatSetDirection(...) - static method
  line 93: iVector2 getSubMapSector(...) - static method
  line 94: Ogre::Vector4 getSubMapSectorBounds(...) - static method
  line 95: bool getResourceFilePath(...) - static method
  line 96: std::string removePathFromString(...) - static method
  line 97: std::string removeFilenameFromPath(...) - static method
  line 98: std::string removeFileExtensionFromString(...) - static method
  line 99: std::string getFileExtensionFromString(...) - static method
  line 100: void removeInvalidFileNameChars(...) - static method
  line 101: bool compareStringsCaseInsenstive(...) - static method
  line 106: float getTerrainHeightFromRenderer(...) - static method
  line 107: float getApproxTerrainHeightFromRenderer(...) - static method
  line 108: bool worldToScreenRel(...) - non-string reference arg
  line 109: bool worldToScreenPX(...) - non-string reference arg
  line 110: bool worldToScreenWithRadius(...) - non-string reference arg
  line 111: Ogre::Entity* placeOrientedMarker(...) - unsupported arg type
  line 112: void placeMarker(...) - overloaded method
  line 113: void placeMarker(...) - overloaded method
  line 114: void debugBox(...) - unsupported arg type
  line 115: void placeBox(...) - unsupported arg type
  line 117: void placeArrow(...) - unsupported arg type
  line 119: void placeArrowTo(...) - unsupported arg type
  line 120: void placeArrowBT(...) - unsupported arg type
  line 121: void removeArrow(...) - unsupported arg type
  line 122: void placeSphere(...) - unsupported arg type
  line 123: void placeAxis(...) - overloaded method
  line 124: void placeAxis(...) - overloaded method
  line 125: rendHit ogreTrace(...) - unsupported return type
  line 126: Ogre::SharedPtr<Ogre::Material> getDebugMaterial(...) - unsupported return type
  line 130: bool fileExists(...) - unsupported arg type
  line 134: bool readFile(...) - non-string reference arg
  line 137: void makeSureGameFolderExists(...) - static method
  line 138: void makeSureFolderExists(...) - static method
  line 139: std::string getFullPath(...) - static method
  line 140: bool getRelativePath(...) - static method
  line 141: bool getFilesInDir(...) - unsupported arg type
  line 142: bool getFilesInGameDir(...) - unsupported arg type
  line 143: void getDirsInDir(...) - unsupported arg type
  line 144: std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> > getCurrentDir(...) - unsupported return type
  line 145: void setCurrentDir(...) - unsupported arg type
  line 152: bool positionIsInFrontOfMe(...) - static method
  line 153: bool pointInPlane(...) - static method
  line 154: bool OBBCollision(...) - static method
  line 155: std::string colorToGUIString(...) - static method
  line 157: void roundToNearest(...) - non-string reference arg
*/

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