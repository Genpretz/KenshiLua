#include "pch.h"
#include "kenshi\navmesh.h"
#include "NavMeshBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/ZoneMapBinding.h"
#include "Bindings/NavMeshGeneratorBinding.h"
#include "Bindings/Util/iVector2Binding.h"

namespace KenshiLua
{

static NavMesh* getInstance(lua_State* L, int idx)
{
    return checkObject<NavMesh>(L, idx, NavMeshBinding::getMetatableName());
}

// --- Getters for NavMesh ---
static int NavMesh_get_world(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");
    lua_pushlightuserdata(L, (void*)instance->world);
    return 1;
}

static int NavMesh_get_shiftMutex(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");
    lua_pushlightuserdata(L, &instance->shiftMutex);
    return 1;
}

static int NavMesh_get_worldShiftEnabled(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");
    lua_pushboolean(L, instance->worldShiftEnabled ? 1 : 0);
    return 1;
}

static int NavMesh_get_running(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");
    lua_pushboolean(L, instance->running ? 1 : 0);
    return 1;
}

static int NavMesh_get_worldX(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");
    lua_pushnumber(L, instance->worldX);
    return 1;
}

static int NavMesh_get_worldY(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");
    lua_pushnumber(L, instance->worldY);
    return 1;
}

static int NavMesh_get_cellSize(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");
    lua_pushnumber(L, instance->cellSize);
    return 1;
}

static int NavMesh_get_worldShift(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");
    lua_pushlightuserdata(L, (void*)instance->worldShift);
    return 1;
}

static int NavMesh_get_mutex(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");
    lua_pushlightuserdata(L, &instance->mutex);
    return 1;
}

static int NavMesh_get_changeMutex(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");
    lua_pushlightuserdata(L, &instance->changeMutex);
    return 1;
}

static int NavMesh_get_edgeFilter(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");
    lua_pushlightuserdata(L, (void*)instance->edgeFilter);
    return 1;
}

static int NavMesh_get_generator(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");
    return pushObject<NavMeshGenerator>(L, instance->generator, NavMeshGeneratorBinding::getMetatableName());
}

// --- Setters for NavMesh ---
static int NavMesh_set_shiftMutex(lua_State* L)
{
    return luaL_error(L, "Property 'shiftMutex' is read-only");
}

static int NavMesh_set_worldShiftEnabled(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");
    instance->worldShiftEnabled = lua_toboolean(L, 2) != 0;
    return 0;
}

static int NavMesh_set_running(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");
    instance->running = lua_toboolean(L, 2) != 0;
    return 0;
}

static int NavMesh_set_worldX(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");
    instance->worldX = (float)luaL_checknumber(L, 2);
    return 0;
}

static int NavMesh_set_worldY(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");
    instance->worldY = (float)luaL_checknumber(L, 2);
    return 0;
}

static int NavMesh_set_cellSize(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");
    instance->cellSize = (float)luaL_checknumber(L, 2);
    return 0;
}

static int NavMesh_set_mutex(lua_State* L)
{
    return luaL_error(L, "Property 'mutex' is read-only");
}

static int NavMesh_set_changeMutex(lua_State* L)
{
    return luaL_error(L, "Property 'changeMutex' is read-only");
}

int NavMeshBinding::initialise(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");

    instance->initialise();
    return 0;
}

int NavMeshBinding::shutdown(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");

    instance->shutdown();
    return 0;
}

int NavMeshBinding::create(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");

    ZoneMap* zone = checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    instance->create(zone);
    return 0;
}

int NavMeshBinding::unload(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");

    ZoneMap* zone = checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    instance->unload(zone);
    return 0;
}

int NavMeshBinding::destroy(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");

    Building* b = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    instance->destroy(b);
    return 0;
}

int NavMeshBinding::getZoneEdge(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");

    Ogre::Vector3 start;
    readVector3(L, 2, start);
    Ogre::Vector3 target;
    readVector3(L, 3, target);
    float offset = (float)luaL_checknumber(L, 4);
    Ogre::Vector3 result = instance->getZoneEdge(start, target, offset);
    pushVector3(L, result);
    return 1;
}

int NavMeshBinding::getClosestExteriorPoint(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");

    Ogre::Vector3 point;
    readVector3(L, 2, point);
    float radius = (float)luaL_checknumber(L, 3);
    float inset = (float)luaL_checknumber(L, 4);
    Ogre::Vector3 out;
    readVector3(L, 5, out);
    int result = instance->getClosestExteriorPoint(point, radius, inset, out);
    lua_pushinteger(L, result);
    return 1;
}

int NavMeshBinding::setDoorState(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");

    Building* door = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    bool open = lua_toboolean(L, 3) != 0;
    instance->setDoorState(door, open);
    return 0;
}

int NavMeshBinding::isInterior(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");

    unsigned int key = (unsigned int)luaL_checkinteger(L, 2);
    bool result = instance->isInterior(key);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int NavMeshBinding::getPositionValid(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");

    Ogre::Vector3 point;
    readVector3(L, 2, point);
    bool result = instance->getPositionValid(point);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int NavMeshBinding::processCompletedCharacterMessages(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");

    instance->processCompletedCharacterMessages();
    return 0;
}

int NavMeshBinding::processDoorRequests(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");

    instance->processDoorRequests();
    return 0;
}

int NavMeshBinding::getPolygonID(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    std::string result = instance->getPolygonID(p);
    lua_pushstring(L, result.c_str());
    return 1;
}

int NavMeshBinding::validateFaceKey(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");

    unsigned int key = (unsigned int)luaL_checkinteger(L, 2);
    bool result = instance->validateFaceKey(key);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int NavMeshBinding::isGenerating(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");

    bool result = instance->isGenerating();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int NavMeshBinding::getWorldShift(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");

    Ogre::Vector3 result = instance->getWorldShift();
    pushVector3(L, result);
    return 1;
}

int NavMeshBinding::threadProc(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");

    unsigned long result = instance->threadProc();
    lua_pushinteger(L, result);
    return 1;
}

int NavMeshBinding::_NV_threadProc(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");

    unsigned long result = instance->_NV_threadProc();
    lua_pushinteger(L, result);
    return 1;
}

int NavMeshBinding::update(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");

    bool result = instance->update();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int NavMeshBinding::setupHavok(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");

    instance->setupHavok();
    return 0;
}

int NavMeshBinding::shutdownHavok(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");

    instance->shutdownHavok();
    return 0;
}

int NavMeshBinding::loadZone(lua_State* L)
{
    return luaL_error(L, "NavMesh::loadZone is not available (not exported by Kenshi)");
}

int NavMeshBinding::unloadZone(lua_State* L)
{
    return luaL_error(L, "NavMesh::unloadZone is not available (not exported by Kenshi)");
}

int NavMeshBinding::unloadBuilding(lua_State* L)
{
    NavMesh* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMesh is nil");

    hand h = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    instance->unloadBuilding(h);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 75: void generate(...) - overloaded method
  line 76: void generate(...) - overloaded method
  line 77: void generate(...) - overloaded method
  line 79: bool isLoaded(...) - overloaded method
  line 80: bool isLoaded(...) - overloaded method
  line 82: int getClosestPoint(...) - overloaded method
  line 83: int getClosestPoint(...) - overloaded method
  line 84: int getClosestPoint(...) - overloaded method
  line 87: int getGateCode(...) - overloaded method
  line 88: int getGateCode(...) - overloaded method
  line 90: const hand& getHandle(...) - reference return type
  line 91: unsigned int getFaceKey(...) - overloaded method
  line 92: unsigned int getFaceKey(...) - overloaded method
  line 94: int getClosestBoundary(...) - unsupported arg type
  line 95: int projectToNavMesh(...) - unsupported arg type
  line 96: int getEdgesAroundPoint(...) - unsupported arg type
  line 97: int areEdgesConnected(...) - unsupported arg type
  line 98: int checkLineOfSight(...) - overloaded method
  line 99: int checkLineOfSight(...) - overloaded method
  line 100: int checkCollision(...) - unsupported arg type
  line 101: bool pathExists(...) - overloaded method
  line 102: int pathExists(...) - overloaded method
  line 104: int fillEdgeCache(...) - unsupported arg type
  line 105: int isWater(...) - unsupported arg type
  line 106: bool isCharacterStuck(...) - unsupported arg type
  line 107: void postMessage(...) - unsupported arg type
  line 108: void cancelMessage(...) - unsupported arg type
  line 114: NavMeshSeeds& getSeedData(...) - reference return type
  line 178: std::string getFilename(...) - static method
  line 180: int saveZone(...) - unsupported arg type
  line 181: bool createZoneInstance(...) - unsupported arg type
  line 182: void deleteMesh(...) - overloaded method
  line 183: void deleteMesh(...) - overloaded method
  line 184: int createZone(...) - unsupported arg type
  line 188: NavMeshSector* getSector(...) - overloaded method
  line 189: NavMeshSector* getSector(...) - overloaded method
  line 190: NavInstance* getInterior(...) - non-string reference arg
  line 191: bool removeSector(...) - unsupported arg type
  line 192: int getSectors(...) - unsupported arg type
  line 193: void createInstance(...) - unsupported arg type
  line 194: void deleteInstance(...) - unsupported arg type
  line 195: int countInteriors(...) - non-string reference arg
  line 196: unsigned int getUID(...) - static method
  line 197: unsigned int getUID(...) - static method
  line 198: unsigned int hashBuilding(...) - static method
  line 199: unsigned int hashInterior(...) - static method
  line 200: unsigned int hashZone(...) - static method
  line 201: void shiftWorld(...) - unsupported arg type
  line 203: void changeDoorState(...) - unsupported arg type
  line 204: bool validateStreamingData(...) - unsupported arg type
  line 205: void shiftEdgePath(...) - unsupported arg type
  line 206: bool directPath(...) - unsupported arg type
  line 207: bool findPath(...) - unsupported arg type
  line 208: unsigned int resolvePoint(...) - unsupported arg type
  line 209: int createEdgePath(...) - unsupported arg type
  line 210: int getClearance(...) - non-string reference arg
  line 212: int findEdges(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - NavMesh_get_world: hkaiWorld* (unbound pointer)
  - NavMesh_get_worldShift: hkVector4f* (unbound pointer)
  - NavMesh_get_edgeFilter: hkaiAstarEdgeFilter* (unbound pointer)
  - NavMesh_get_generator: NavMeshGenerator* (unbound pointer)
  - NavMeshBinding::loadZone: NavMeshSector* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 166: characterMessages (MessageQueue<HavokCharacterMessage*>) - unsupported type
  line 167: completedMessages (MessageQueue<HavokCharacterMessage*>) - unsupported type
  line 168: navMessages (MessageQueue<NavMesh::NavMeshMessage*>) - unsupported type
  line 169: doorRequests (MessageQueue<ZoneMap*>) - unsupported type
  line 170: pathRequests (hkArray<HavokCharacterMessage*, hkContainerHeapAllocator>) - unsupported type
  line 220: sectors (std::map<iVector2, NavMeshSector*, std::less<iVector2>, Ogre::STLAllocator<std::pair<iVector2 const, NavMeshSector*>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 221: interiors (std::map<hand, NavInstance*, std::less<hand>, Ogre::STLAllocator<std::pair<hand const, NavInstance*>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 222: addList (lektor<NavInstance*>) - unsupported type
  line 225: deferredList (lektor<ZoneMap*>) - unsupported type
  line 226: removed (hkArray<int, hkContainerHeapAllocator>) - unsupported type
*/

int NavMeshBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int NavMeshBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.NavMesh object");
    return 1;
}

void NavMeshBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       NavMeshBinding::gc },
        { "__tostring", NavMeshBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "initialise", NavMeshBinding::initialise },
        { "shutdown", NavMeshBinding::shutdown },
        { "create", NavMeshBinding::create },
        { "unload", NavMeshBinding::unload },
        { "destroy", NavMeshBinding::destroy },
        { "getZoneEdge", NavMeshBinding::getZoneEdge },
        { "getClosestExteriorPoint", NavMeshBinding::getClosestExteriorPoint },
        { "setDoorState", NavMeshBinding::setDoorState },
        { "isInterior", NavMeshBinding::isInterior },
        { "getPositionValid", NavMeshBinding::getPositionValid },
        { "processCompletedCharacterMessages", NavMeshBinding::processCompletedCharacterMessages },
        { "processDoorRequests", NavMeshBinding::processDoorRequests },
        { "getPolygonID", NavMeshBinding::getPolygonID },
        { "validateFaceKey", NavMeshBinding::validateFaceKey },
        { "isGenerating", NavMeshBinding::isGenerating },
        { "getWorldShift", NavMeshBinding::getWorldShift },
        { "threadProc", NavMeshBinding::threadProc },
        { "_NV_threadProc", NavMeshBinding::_NV_threadProc },
        { "update", NavMeshBinding::update },
        { "setupHavok", NavMeshBinding::setupHavok },
        { "shutdownHavok", NavMeshBinding::shutdownHavok },
        { "loadZone", NavMeshBinding::loadZone },
        { "unloadZone", NavMeshBinding::unloadZone },
        { "unloadBuilding", NavMeshBinding::unloadBuilding },
        { 0, 0 }
    };

    registerClass(
        L, 
        NavMeshBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, NavMeshBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "world", NavMesh_get_world);
    registerGetter(L, "shiftMutex", NavMesh_get_shiftMutex);
    registerGetter(L, "worldShiftEnabled", NavMesh_get_worldShiftEnabled);
    registerGetter(L, "running", NavMesh_get_running);
    registerGetter(L, "worldX", NavMesh_get_worldX);
    registerGetter(L, "worldY", NavMesh_get_worldY);
    registerGetter(L, "cellSize", NavMesh_get_cellSize);
    registerGetter(L, "worldShift", NavMesh_get_worldShift);
    registerGetter(L, "mutex", NavMesh_get_mutex);
    registerGetter(L, "changeMutex", NavMesh_get_changeMutex);
    registerGetter(L, "edgeFilter", NavMesh_get_edgeFilter);
    registerGetter(L, "generator", NavMesh_get_generator);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "shiftMutex", NavMesh_set_shiftMutex);
    registerSetter(L, "worldShiftEnabled", NavMesh_set_worldShiftEnabled);
    registerSetter(L, "running", NavMesh_set_running);
    registerSetter(L, "worldX", NavMesh_set_worldX);
    registerSetter(L, "worldY", NavMesh_set_worldY);
    registerSetter(L, "cellSize", NavMesh_set_cellSize);
    registerSetter(L, "mutex", NavMesh_set_mutex);
    registerSetter(L, "changeMutex", NavMesh_set_changeMutex);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ThreadClass
    // setMetatableParent(L, NavMeshBinding::getMetatableName(), ThreadClassBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua