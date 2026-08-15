#include "pch.h"
#include "kenshi\physicsactual.h"
#include "PhysicsActualBinding.h"
#include "Bindings/TriggerCallbackBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static PhysicsActual* getInstance(lua_State* L, int idx)
{
    return checkObject<PhysicsActual>(L, idx, PhysicsActualBinding::getMetatableName());
}

// --- Getters for PhysicsActual ---
static int PhysicsActual_get_materialConcrete(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");
    lua_pushlightuserdata(L, (void*)instance->materialConcrete);
    return 1;
}

static int PhysicsActual_get_materialMetal(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");
    lua_pushlightuserdata(L, (void*)instance->materialMetal);
    return 1;
}

static int PhysicsActual_get_materialSand(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");
    lua_pushlightuserdata(L, (void*)instance->materialSand);
    return 1;
}

static int PhysicsActual_get_materialHuman(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");
    lua_pushlightuserdata(L, (void*)instance->materialHuman);
    return 1;
}

static int PhysicsActual_get_myTriggerCallback(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");
    return pushObject<PhysicsActual::TriggerCallback>(L, &instance->myTriggerCallback, TriggerCallbackBinding::getMetatableName());
}

static int PhysicsActual_get_HW(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");
    lua_pushboolean(L, instance->HW ? 1 : 0);
    return 1;
}

static int PhysicsActual_get_debugRenderOn(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");
    lua_pushboolean(L, instance->debugRenderOn ? 1 : 0);
    return 1;
}

static int PhysicsActual_get_scytheClass(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");
    lua_pushlightuserdata(L, &instance->scytheClass);
    return 1;
}

static int PhysicsActual_get_controllerMgr(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");
    lua_pushlightuserdata(L, (void*)instance->controllerMgr);
    return 1;
}

static int PhysicsActual_get_physicsSDK(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");
    lua_pushlightuserdata(L, (void*)instance->physicsSDK);
    return 1;
}

// --- Setters for PhysicsActual ---
static int PhysicsActual_set_myTriggerCallback(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");
    PhysicsActual::TriggerCallback* val = checkObject<PhysicsActual::TriggerCallback>(L, 2, TriggerCallbackBinding::getMetatableName());
    if (!val) return luaL_error(L, "PhysicsActual::set_myTriggerCallback: expected TriggerCallback for argument 2");
    instance->myTriggerCallback = *val;
    return 0;
}

static int PhysicsActual_set_HW(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");
    instance->HW = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PhysicsActual_set_debugRenderOn(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");
    instance->debugRenderOn = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PhysicsActual_set_scytheClass(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");
    Scythe::PhysicsClass* val = (Scythe::PhysicsClass*)lua_touserdata(L, 2);
    if (val) instance->scytheClass = *val;
    return 0;
}

int PhysicsActualBinding::_CONSTRUCTOR(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");

    PhysicsActual* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int PhysicsActualBinding::_DESTRUCTOR(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int PhysicsActualBinding::updateUT(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");

    instance->updateUT();
    return 0;
}

int PhysicsActualBinding::_NV_updateUT(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");

    instance->_NV_updateUT();
    return 0;
}

int PhysicsActualBinding::backThreadUpdate(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");

    float time = (float)luaL_checknumber(L, 2);
    bool _useOwnTimers = lua_toboolean(L, 3) != 0;
    instance->backThreadUpdate(time, _useOwnTimers);
    return 0;
}

int PhysicsActualBinding::_NV_backThreadUpdate(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");

    float time = (float)luaL_checknumber(L, 2);
    bool _useOwnTimers = lua_toboolean(L, 3) != 0;
    instance->_NV_backThreadUpdate(time, _useOwnTimers);
    return 0;
}

int PhysicsActualBinding::threadJunkPreBT(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");

    instance->threadJunkPreBT();
    return 0;
}

int PhysicsActualBinding::threadJunkPostBT(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");

    instance->threadJunkPostBT();
    return 0;
}

int PhysicsActualBinding::setup(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");

    bool result = instance->setup();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PhysicsActualBinding::scytheGetFirstModelName(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");

    const std::string filename = luaL_checkstring(L, 2);
    std::string result = instance->scytheGetFirstModelName(filename);
    lua_pushstring(L, result.c_str());
    return 1;
}

int PhysicsActualBinding::_createTriggerHull(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    Ogre::Vector3 size;
    readVector3(L, 3, size);
    NxActor* result = instance->_createTriggerHull(pos, size);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int PhysicsActualBinding::_createStaticCapsule(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    float length = (float)luaL_checknumber(L, 3);
    float radius = (float)luaL_checknumber(L, 4);
    NxActor* result = instance->_createStaticCapsule(pos, length, radius);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int PhysicsActualBinding::_createStaticBox(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    Ogre::Vector3 dimensions;
    readVector3(L, 3, dimensions);
    Ogre::Quaternion rot;
    readQuaternion(L, 4, rot);
    int group = (int)luaL_checkinteger(L, 5);
    NxActor* result = instance->_createStaticBox(pos, dimensions, rot, group);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int PhysicsActualBinding::uncookMesh(lua_State* L)
{
    PhysicsActual* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsActual is nil");

    NXU::NxTriangleMeshDesc* mesh = (NXU::NxTriangleMeshDesc*)lua_touserdata(L, 2);
    const char* cId = luaL_checkstring(L, 3);
    bool result = instance->uncookMesh(mesh, cId);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 231: bool scytheInsert(...) - unsupported arg type
  line 232: void convertXMLToBin(...) - non-string reference arg
  line 233: NxActor* loadPhysXFile(...) - unsupported arg type
  line 234: NxActor* loadPhysXFileAsATrigger(...) - unsupported arg type
  line 238: void _destroy(...) - unsupported arg type
  line 239: void setActorCollisionGroup(...) - static method
  line 240: unsigned short getActorCollisionGroup(...) - static method
  line 241: void setActorMaterial(...) - static method
  line 242: void scaleCollection(...) - non-string reference arg
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - PhysicsActual_get_materialConcrete: NxMaterial* (unbound pointer)
  - PhysicsActual_get_materialMetal: NxMaterial* (unbound pointer)
  - PhysicsActual_get_materialSand: NxMaterial* (unbound pointer)
  - PhysicsActual_get_materialHuman: NxMaterial* (unbound pointer)
  - PhysicsActual_get_controllerMgr: NxControllerManager* (unbound pointer)
  - PhysicsActual_get_physicsSDK: NxPhysicsSDK* (unbound pointer)
  - PhysicsActualBinding::_CONSTRUCTOR: PhysicsActual* (unbound pointer)
  - PhysicsActualBinding::_createTriggerHull: NxActor* (unbound pointer)
  - PhysicsActualBinding::_createStaticCapsule: NxActor* (unbound pointer)
  - PhysicsActualBinding::_createStaticBox: NxActor* (unbound pointer)
*/

int PhysicsActualBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int PhysicsActualBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.PhysicsActual object");
    return 1;
}

void PhysicsActualBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       PhysicsActualBinding::gc },
        { "__tostring", PhysicsActualBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", PhysicsActualBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", PhysicsActualBinding::_DESTRUCTOR },
        { "updateUT", PhysicsActualBinding::updateUT },
        { "_NV_updateUT", PhysicsActualBinding::_NV_updateUT },
        { "backThreadUpdate", PhysicsActualBinding::backThreadUpdate },
        { "_NV_backThreadUpdate", PhysicsActualBinding::_NV_backThreadUpdate },
        { "threadJunkPreBT", PhysicsActualBinding::threadJunkPreBT },
        { "threadJunkPostBT", PhysicsActualBinding::threadJunkPostBT },
        { "setup", PhysicsActualBinding::setup },
        { "scytheGetFirstModelName", PhysicsActualBinding::scytheGetFirstModelName },
        { "_createTriggerHull", PhysicsActualBinding::_createTriggerHull },
        { "_createStaticCapsule", PhysicsActualBinding::_createStaticCapsule },
        { "_createStaticBox", PhysicsActualBinding::_createStaticBox },
        { "uncookMesh", PhysicsActualBinding::uncookMesh },
        { 0, 0 }
    };

    registerClass(
        L, 
        PhysicsActualBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, PhysicsActualBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "materialConcrete", PhysicsActual_get_materialConcrete);
    registerGetter(L, "materialMetal", PhysicsActual_get_materialMetal);
    registerGetter(L, "materialSand", PhysicsActual_get_materialSand);
    registerGetter(L, "materialHuman", PhysicsActual_get_materialHuman);
    registerGetter(L, "myTriggerCallback", PhysicsActual_get_myTriggerCallback);
    registerGetter(L, "HW", PhysicsActual_get_HW);
    registerGetter(L, "debugRenderOn", PhysicsActual_get_debugRenderOn);
    registerGetter(L, "scytheClass", PhysicsActual_get_scytheClass);
    registerGetter(L, "controllerMgr", PhysicsActual_get_controllerMgr);
    registerGetter(L, "physicsSDK", PhysicsActual_get_physicsSDK);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "myTriggerCallback", PhysicsActual_set_myTriggerCallback);
    registerSetter(L, "HW", PhysicsActual_set_HW);
    registerSetter(L, "debugRenderOn", PhysicsActual_set_debugRenderOn);
    registerSetter(L, "scytheClass", PhysicsActual_set_scytheClass);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to PhysicsInterface
    // setMetatableParent(L, PhysicsActualBinding::getMetatableName(), PhysicsInterfaceBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua