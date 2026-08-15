#include "pch.h"
#include "kenshi\physicsactual.h"
#include "PhysicsInterfaceBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/DoorStuffBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Building/PreviewBuildingBinding.h"
#include "Bindings/RootObjectBinding.h"

namespace KenshiLua
{

static PhysicsInterface* getInstance(lua_State* L, int idx)
{
    return checkObject<PhysicsInterface>(L, idx, PhysicsInterfaceBinding::getMetatableName());
}

// --- Getters for PhysicsInterface ---
static int PhysicsInterface_get_nWorld(lua_State* L)
{
    PhysicsInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsInterface is nil");
    lua_pushlightuserdata(L, (void*)instance->nWorld);
    return 1;
}

static int PhysicsInterface_get__queuesClear(lua_State* L)
{
    PhysicsInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsInterface is nil");
    lua_pushboolean(L, instance->_queuesClear ? 1 : 0);
    return 1;
}

static int PhysicsInterface_get_queuesClearMuto(lua_State* L)
{
    PhysicsInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsInterface is nil");
    lua_pushlightuserdata(L, &instance->queuesClearMuto);
    return 1;
}

// --- Setters for PhysicsInterface ---
static int PhysicsInterface_set__queuesClear(lua_State* L)
{
    PhysicsInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsInterface is nil");
    instance->_queuesClear = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PhysicsInterface_set_queuesClearMuto(lua_State* L)
{
    return luaL_error(L, "Property 'queuesClearMuto' is read-only");
}

int PhysicsInterfaceBinding::getBackthread(lua_State* L)
{
    PhysicsInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsInterface is nil");

    PhysicsActual* result = instance->getBackthread();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int PhysicsInterfaceBinding::updateUT(lua_State* L)
{
    PhysicsInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsInterface is nil");

    instance->updateUT();
    return 0;
}

int PhysicsInterfaceBinding::backThreadUpdate(lua_State* L)
{
    PhysicsInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsInterface is nil");

    float _a1 = (float)luaL_checknumber(L, 2);
    bool _a2 = lua_toboolean(L, 3) != 0;
    instance->backThreadUpdate(_a1, _a2);
    return 0;
}

int PhysicsInterfaceBinding::createTriggerHull(lua_State* L)
{
    PhysicsInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsInterface is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    Ogre::Vector3 size;
    readVector3(L, 3, size);
    RootObject* user = checkObject<RootObject>(L, 4, RootObjectBinding::getMetatableName());
    PhysicsHullT* result = instance->createTriggerHull(pos, size, user);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int PhysicsInterfaceBinding::createStaticCapsule(lua_State* L)
{
    PhysicsInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsInterface is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    float h = (float)luaL_checknumber(L, 3);
    float w = (float)luaL_checknumber(L, 4);
    SimplePhysXEntity* result = instance->createStaticCapsule(pos, h, w);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int PhysicsInterfaceBinding::doorWantsSetup(lua_State* L)
{
    PhysicsInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsInterface is nil");

    DoorStuff* t = checkObject<DoorStuff>(L, 2, DoorStuffBinding::getMetatableName());
    instance->doorWantsSetup(t);
    return 0;
}

int PhysicsInterfaceBinding::scytheInsertPreview(lua_State* L)
{
    PhysicsInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsInterface is nil");

    GameData* buildingData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    PreviewBuilding* pre = checkObject<PreviewBuilding>(L, 3, PreviewBuildingBinding::getMetatableName());
    bool result = instance->scytheInsertPreview(buildingData, pre);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PhysicsInterfaceBinding::loadScytheFileMT(lua_State* L)
{
    PhysicsInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsInterface is nil");

    RootObject* userdata = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    const std::string file = luaL_checkstring(L, 3);
    Ogre::Vector3 pos;
    readVector3(L, 4, pos);
    Ogre::Quaternion q;
    readQuaternion(L, 5, q);
    const std::string boneAttachment = luaL_checkstring(L, 6);
    GameData* itemdata = checkObject<GameData>(L, 7, GameDataBinding::getMetatableName());
    ScythePhysicsT* result = instance->loadScytheFileMT(userdata, file, pos, q, boneAttachment, itemdata);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int PhysicsInterfaceBinding::queuesAreClearMT(lua_State* L)
{
    PhysicsInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsInterface is nil");

    bool result = instance->queuesAreClearMT();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PhysicsInterfaceBinding::setQueuesAreClear(lua_State* L)
{
    PhysicsInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsInterface is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setQueuesAreClear(on);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 177: void destroy(...) - unsupported arg type
  line 178: void destroyActor(...) - unsupported arg type
  line 179: void changeGroup(...) - unsupported arg type
  line 180: void addImpulse(...) - unsupported arg type
  line 181: void addNewObject(...) - unsupported arg type
  line 183: void loadTerrain(...) - unsupported arg type
  line 185: void scytheCreateAttachmentData(...) - unsupported arg type
  line 187: ScytheRagdollPhysicsT* loadScytheRagdollFileMT(...) - unsupported arg type
  line 188: SimplePhysXEntity* createSimplePhysicsEntityMT(...) - overloaded method
  line 189: SimplePhysXEntity* createSimplePhysicsEntityMT(...) - overloaded method
  line 190: void addConstantTracerMT(...) - unsupported arg type
  line 191: void removeConstantTracerMT(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - PhysicsInterface_get_nWorld: NxScene* (unbound pointer)
  - PhysicsInterfaceBinding::getBackthread: PhysicsActual* (unbound pointer)
  - PhysicsInterfaceBinding::createTriggerHull: PhysicsHullT* (unbound pointer)
  - PhysicsInterfaceBinding::createStaticCapsule: SimplePhysXEntity* (unbound pointer)
  - PhysicsInterfaceBinding::loadScytheFileMT: ScythePhysicsT* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 193: newConstantTracers (MessageChain<ConstantTracerT*>) - unsupported type
  line 194: removeConstantTracers (MessageChain<ConstantTracerT*>) - unsupported type
  line 195: constantTracers (ogre_unordered_set<ConstantTracerT*>::type) - unsupported type
  line 196: hullsToMake (MessageChain<PhysicsThreadedBaseInterface*>) - unsupported type
  line 197: hulls (lektor<PhysicsThreadedBaseInterface*>) - unsupported type
  line 198: hullsToDestroy (MessageChain<PhysicsThreadedBaseInterface*>) - unsupported type
  line 199: hullsToChangeGroup (MessageChain<std::pair<SimplePhysXEntity*, int> >) - unsupported type
  line 200: impulse (MessageChain<boost::tuples::tuple<SimplePhysXEntity*, Ogre::Vector3, Ogre::Vector3, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type> >) - unsupported type
  line 201: actorsToDestroy (MessageChain<NxActor*>) - unsupported type
  line 202: doorsToSetup (lektor<DoorStuff*>) - unsupported type
  line 203: terrainToLoad (MessageChain<TerrainSector*>) - unsupported type
*/

int PhysicsInterfaceBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int PhysicsInterfaceBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.PhysicsInterface object");
    return 1;
}

void PhysicsInterfaceBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       PhysicsInterfaceBinding::gc },
        { "__tostring", PhysicsInterfaceBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getBackthread", PhysicsInterfaceBinding::getBackthread },
        { "updateUT", PhysicsInterfaceBinding::updateUT },
        { "backThreadUpdate", PhysicsInterfaceBinding::backThreadUpdate },
        { "createTriggerHull", PhysicsInterfaceBinding::createTriggerHull },
        { "createStaticCapsule", PhysicsInterfaceBinding::createStaticCapsule },
        { "doorWantsSetup", PhysicsInterfaceBinding::doorWantsSetup },
        { "scytheInsertPreview", PhysicsInterfaceBinding::scytheInsertPreview },
        { "loadScytheFileMT", PhysicsInterfaceBinding::loadScytheFileMT },
        { "queuesAreClearMT", PhysicsInterfaceBinding::queuesAreClearMT },
        { "setQueuesAreClear", PhysicsInterfaceBinding::setQueuesAreClear },
        { 0, 0 }
    };

    registerClass(
        L, 
        PhysicsInterfaceBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, PhysicsInterfaceBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "nWorld", PhysicsInterface_get_nWorld);
    registerGetter(L, "_queuesClear", PhysicsInterface_get__queuesClear);
    registerGetter(L, "queuesClearMuto", PhysicsInterface_get_queuesClearMuto);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "_queuesClear", PhysicsInterface_set__queuesClear);
    registerSetter(L, "queuesClearMuto", PhysicsInterface_set_queuesClearMuto);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ThreadWannabe
    // setMetatableParent(L, PhysicsInterfaceBinding::getMetatableName(), ThreadWannabeBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua