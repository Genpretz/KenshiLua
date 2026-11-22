#include "pch.h"
#include "kenshi\navmeshgenerator.h"
#include "NavMeshGeneratorBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Building/BuildingBinding.h"
#include "Bindings/Kenshi/NavInstanceBinding.h"
#include "Bindings/Kenshi/NavMeshGenerator_TaskBinding.h"
#include "Bindings/Kenshi/ZoneMapBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/iVector2Binding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"

namespace KenshiLua
{

static NavMeshGenerator* getInstance(lua_State* L, int idx)
{
    return checkObject<NavMeshGenerator>(L, idx, NavMeshGeneratorBinding::getMetatableName());
}

// --- Getters for NavMeshGenerator ---
static int NavMeshGenerator_get_queue(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");
    lua_pushlightuserdata(L, &instance->queue);
    return 1;
}

static int NavMeshGenerator_get_done(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");
    lua_pushlightuserdata(L, &instance->done);
    return 1;
}

static int NavMeshGenerator_get_current(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");
    lua_pushlightuserdata(L, (void*)instance->current);
    return 1;
}

static int NavMeshGenerator_get_navmesh(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");
    lua_pushlightuserdata(L, (void*)instance->navmesh);
    return 1;
}

static int NavMeshGenerator_get_needSave(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");
    lua_pushboolean(L, instance->needSave ? 1 : 0);
    return 1;
}

static int NavMeshGenerator_get_settings(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");
    lua_pushlightuserdata(L, (void*)instance->settings);
    return 1;
}

static int NavMeshGenerator_get_threadRunning(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");
    lua_pushboolean(L, instance->threadRunning ? 1 : 0);
    return 1;
}

static int NavMeshGenerator_get_doingStuff(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");
    lua_pushboolean(L, instance->doingStuff ? 1 : 0);
    return 1;
}

static int NavMeshGenerator_get_taskMutex(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");
    lua_pushlightuserdata(L, &instance->taskMutex);
    return 1;
}

static int NavMeshGenerator_get_lockedTask(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");
    lua_pushlightuserdata(L, (void*)instance->lockedTask);
    return 1;
}

// --- Setters for NavMeshGenerator ---
static int NavMeshGenerator_set_queue(lua_State* L)
{
    return luaL_error(L, "Property 'queue' is read-only");
}

static int NavMeshGenerator_set_done(lua_State* L)
{
    return luaL_error(L, "Property 'done' is read-only");
}

static int NavMeshGenerator_set_needSave(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");
    instance->needSave = lua_toboolean(L, 2) != 0;
    return 0;
}

static int NavMeshGenerator_set_threadRunning(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");
    instance->threadRunning = lua_toboolean(L, 2) != 0;
    return 0;
}

static int NavMeshGenerator_set_doingStuff(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");
    instance->doingStuff = lua_toboolean(L, 2) != 0;
    return 0;
}

static int NavMeshGenerator_set_taskMutex(lua_State* L)
{
    return luaL_error(L, "Property 'taskMutex' is read-only");
}

int NavMeshGeneratorBinding::isGenerating(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");

    bool result = instance->isGenerating();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int NavMeshGeneratorBinding::threadProc(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");

    unsigned long result = instance->threadProc();
    lua_pushinteger(L, result);
    return 1;
}

int NavMeshGeneratorBinding::_NV_threadProc(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");

    unsigned long result = instance->_NV_threadProc();
    lua_pushinteger(L, result);
    return 1;
}

int NavMeshGeneratorBinding::updateBT(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");

    bool result = instance->updateBT();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int NavMeshGeneratorBinding::generateTaskBT(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");

    NavMeshGenerator::Task* task = (NavMeshGenerator::Task*)lua_touserdata(L, 2);
    instance->generateTaskBT(task);
    return 0;
}

int NavMeshGeneratorBinding::validateBuildingStates(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");

    NavMeshGenerator::Task* task = (NavMeshGenerator::Task*)lua_touserdata(L, 2);
    int result = instance->validateBuildingStates(task);
    lua_pushinteger(L, result);
    return 1;
}

int NavMeshGeneratorBinding::carve(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");

    NavMeshGenerator::Task* task = (NavMeshGenerator::Task*)lua_touserdata(L, 2);
    int result = instance->carve(task);
    lua_pushinteger(L, result);
    return 1;
}

int NavMeshGeneratorBinding::splice(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");

    NavMeshGenerator::Task* t = (NavMeshGenerator::Task*)lua_touserdata(L, 2);
    int result = instance->splice(t);
    lua_pushinteger(L, result);
    return 1;
}

int NavMeshGeneratorBinding::stitchInterior(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");

    NavMeshGenerator::Task* t = (NavMeshGenerator::Task*)lua_touserdata(L, 2);
    int result = instance->stitchInterior(t);
    lua_pushinteger(L, result);
    return 1;
}

int NavMeshGeneratorBinding::stitchExterior(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");

    NavMeshGenerator::Task* t = (NavMeshGenerator::Task*)lua_touserdata(L, 2);
    int result = instance->stitchExterior(t);
    lua_pushinteger(L, result);
    return 1;
}

int NavMeshGeneratorBinding::revertSettings(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");

    instance->revertSettings();
    return 0;
}

int NavMeshGeneratorBinding::unlockTask(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");

    NavMeshGenerator::Task* task = (NavMeshGenerator::Task*)lua_touserdata(L, 2);
    instance->unlockTask(task);
    return 0;
}

int NavMeshGeneratorBinding::hasJob(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");

    ZoneMap* zone = checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    bool result = instance->hasJob(zone);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int NavMeshGeneratorBinding::update(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");

    instance->update();
    return 0;
}

int NavMeshGeneratorBinding::lockZone(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");

    iVector2* zone = checkObject<iVector2>(L, 2, iVector2Binding::getMetatableName());
    bool wait = lua_toboolean(L, 3) != 0;
    bool result = instance->lockZone(*zone, wait);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int NavMeshGeneratorBinding::unlockZone(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");

    iVector2* zone = checkObject<iVector2>(L, 2, iVector2Binding::getMetatableName());
    instance->unlockZone(*zone);
    return 0;
}

int NavMeshGeneratorBinding::stitch(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");

    NavInstance* a = checkObject<NavInstance>(L, 2, NavInstanceBinding::getMetatableName());
    NavInstance* b = checkObject<NavInstance>(L, 3, NavInstanceBinding::getMetatableName());
    int result = instance->stitch(a, b);
    lua_pushinteger(L, result);
    return 1;
}

int NavMeshGeneratorBinding::stitchUnloadedZone(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");

    NavInstance* a = checkObject<NavInstance>(L, 2, NavInstanceBinding::getMetatableName());
    int bx = (int)luaL_checkinteger(L, 3);
    int by = (int)luaL_checkinteger(L, 4);
    bool interiors = lua_toboolean(L, 5) != 0;
    int result = instance->stitchUnloadedZone(a, bx, by, interiors);
    lua_pushinteger(L, result);
    return 1;
}

int NavMeshGeneratorBinding::getSeedPointsFromAdjacentZone(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");

    ZoneMap* zone = checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    iVector2* dir = checkObject<iVector2>(L, 3, iVector2Binding::getMetatableName());
    int result = instance->getSeedPointsFromAdjacentZone(zone, *dir);
    lua_pushinteger(L, result);
    return 1;
}

int NavMeshGeneratorBinding::getCompletedTask(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");

    unsigned int uid = (unsigned int)luaL_checkinteger(L, 2);
    NavMeshGenerator::Task* task = nullptr;
    NavInstance* result = instance->getCompletedTask(uid, task);
    pushObject<NavInstance>(L, result, NavInstanceBinding::getMetatableName());
    pushObject<NavMeshGenerator::Task>(L, task, NavMeshGenerator_TaskBinding::getMetatableName());
    return 2;
}

// Overloads: addJob(ZoneMap*, lektor<Building*>, bool), addJob(ZoneMap*, hand, unsigned int),
// and addJob(ZoneMap*, unsigned int). The Ogre::Aabb overload awaits Ogre bindings.
int NavMeshGeneratorBinding::addJob(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");

    ZoneMap* zone = checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());

    if (lua_type(L, 3) == LUA_TNUMBER)
    {
        unsigned int hash = (unsigned int)luaL_checkinteger(L, 3);
        instance->addJob(zone, hash);
        return 0;
    }

    hand* building = testObject<hand>(L, 3, HandBinding::getMetatableName());
    if (building)
    {
        unsigned int hash = (unsigned int)luaL_checkinteger(L, 4);
        instance->addJob(zone, *building, hash);
        return 0;
    }

    lektor<Building*>* buildings = testObject<lektor<Building*> >(L, 3, LektorPtrBinding<Building*>::metaName);
    if (buildings)
    {
        bool splice = lua_toboolean(L, 4) != 0;
        instance->addJob(zone, *buildings, splice);
        return 0;
    }

    return luaL_argerror(L, 3, "hash number, KenshiLua.hand, or lektor<Building*> expected");
}

int NavMeshGeneratorBinding::addStitchJob(lua_State* L)
{
    NavMeshGenerator* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshGenerator is nil");

    NavInstance* s = checkObject<NavInstance>(L, 2, NavInstanceBinding::getMetatableName());
    instance->addStitchJob(s);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 103: void setup(...) - overloaded method
  line 104: void setup(...) - static method
  line 111: int shiftEdge(...) - unsupported arg type
  line 112: int shiftHole(...) - unsupported arg type
  line 118: int stitchWithInteriors(...) - unsupported arg type
  line 123: NavMeshGenerator::Task* newTask(...) - unsupported arg type
  line 144: int getCollisionShapes(...) - static method
  line 145: bool createHeightmapMesh(...) - static method
  line 146: bool addWaterPlane(...) - static method
  line 147: int generateInteriorMesh(...) - static method
  line 148: int generateBuildingMesh(...) - static method
  line 150: void getInteriorCavers(...) - static method
  line 151: int getVolumePoints(...) - static method
  line 152: void getDoorPainters(...) - static method
  line 153: int addFoliageCarvers(...) - static method
  line 154: hkaiVolume* createVolume(...) - static method
  line 155: int addGeometry(...) - static method
  line 156: int addGeometry(...) - static method
  line 157: int addGeometry(...) - static method
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - NavMeshGenerator_get_current: NavMeshGenerator::Task* (unbound pointer)
  - NavMeshGenerator_get_navmesh: NavMesh* (unbound pointer)
  - NavMeshGenerator_get_settings: hkaiNavMeshGenerationSettings* (unbound pointer)
  - NavMeshGenerator_get_lockedTask: NavMeshGenerator::Task* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 99: seedPoints (NavMeshSeeds) - unsupported type
*/

int NavMeshGeneratorBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int NavMeshGeneratorBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.NavMeshGenerator object");
    return 1;
}

void NavMeshGeneratorBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       NavMeshGeneratorBinding::gc },
        { "__tostring", NavMeshGeneratorBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "isGenerating", NavMeshGeneratorBinding::isGenerating },
        { "threadProc", NavMeshGeneratorBinding::threadProc },
        { "_NV_threadProc", NavMeshGeneratorBinding::_NV_threadProc },
        { "updateBT", NavMeshGeneratorBinding::updateBT },
        { "generateTaskBT", NavMeshGeneratorBinding::generateTaskBT },
        { "validateBuildingStates", NavMeshGeneratorBinding::validateBuildingStates },
        { "carve", NavMeshGeneratorBinding::carve },
        { "splice", NavMeshGeneratorBinding::splice },
        { "stitchInterior", NavMeshGeneratorBinding::stitchInterior },
        { "stitchExterior", NavMeshGeneratorBinding::stitchExterior },
        { "revertSettings", NavMeshGeneratorBinding::revertSettings },
        { "unlockTask", NavMeshGeneratorBinding::unlockTask },
        { "hasJob", NavMeshGeneratorBinding::hasJob },
        { "update", NavMeshGeneratorBinding::update },
        { "lockZone", NavMeshGeneratorBinding::lockZone },
        { "unlockZone", NavMeshGeneratorBinding::unlockZone },
        { "stitch", NavMeshGeneratorBinding::stitch },
        { "stitchUnloadedZone", NavMeshGeneratorBinding::stitchUnloadedZone },
        { "getSeedPointsFromAdjacentZone", NavMeshGeneratorBinding::getSeedPointsFromAdjacentZone },
        { "getCompletedTask", NavMeshGeneratorBinding::getCompletedTask },
        { "addJob", NavMeshGeneratorBinding::addJob },
        { "addStitchJob", NavMeshGeneratorBinding::addStitchJob },
        { 0, 0 }
    };

    registerClass(
        L, 
        NavMeshGeneratorBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, NavMeshGeneratorBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "queue", NavMeshGenerator_get_queue);
    registerGetter(L, "done", NavMeshGenerator_get_done);
    registerGetter(L, "current", NavMeshGenerator_get_current);
    registerGetter(L, "navmesh", NavMeshGenerator_get_navmesh);
    registerGetter(L, "needSave", NavMeshGenerator_get_needSave);
    registerGetter(L, "settings", NavMeshGenerator_get_settings);
    registerGetter(L, "threadRunning", NavMeshGenerator_get_threadRunning);
    registerGetter(L, "doingStuff", NavMeshGenerator_get_doingStuff);
    registerGetter(L, "taskMutex", NavMeshGenerator_get_taskMutex);
    registerGetter(L, "lockedTask", NavMeshGenerator_get_lockedTask);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "queue", NavMeshGenerator_set_queue);
    registerSetter(L, "done", NavMeshGenerator_set_done);
    registerSetter(L, "needSave", NavMeshGenerator_set_needSave);
    registerSetter(L, "threadRunning", NavMeshGenerator_set_threadRunning);
    registerSetter(L, "doingStuff", NavMeshGenerator_set_doingStuff);
    registerSetter(L, "taskMutex", NavMeshGenerator_set_taskMutex);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ThreadClass
    // setMetatableParent(L, NavMeshGeneratorBinding::getMetatableName(), ThreadClassBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua