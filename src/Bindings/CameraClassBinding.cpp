#include "pch.h"
#include "kenshi\CameraClass.h"
#include "CameraClassBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/Util/HandBinding.h"

namespace KenshiLua
{

static CameraClass* getInstance(lua_State* L, int idx)
{
    return checkObject<CameraClass>(L, idx, CameraClassBinding::getMetatableName());
}

// --- Getters for CameraClass ---
static int CameraClass_get_isRotating(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    lua_pushboolean(L, instance->isRotating ? 1 : 0);
    return 1;
}

static int CameraClass_get_rotationMarker(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    lua_pushlightuserdata(L, (void*)instance->rotationMarker);
    return 1;
}

static int CameraClass_get_yaw(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    lua_pushnumber(L, instance->yaw);
    return 1;
}

static int CameraClass_get_pitch(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    lua_pushnumber(L, instance->pitch);
    return 1;
}

static int CameraClass_get_initialised(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    lua_pushboolean(L, instance->initialised ? 1 : 0);
    return 1;
}

static int CameraClass_get_terrainLoaded(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    lua_pushboolean(L, instance->terrainLoaded ? 1 : 0);
    return 1;
}

static int CameraClass_get_objectCurrentlyFollowing(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    return HandBinding::push(L, instance->objectCurrentlyFollowing);
}

static int CameraClass_get_objectCurrentlyFollowingOffset(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    pushVector3(L, instance->objectCurrentlyFollowingOffset);
    return 1;
}

static int CameraClass_get_center(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    lua_pushlightuserdata(L, (void*)instance->center);
    return 1;
}

static int CameraClass_get_altitude(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    lua_pushnumber(L, instance->altitude);
    return 1;
}

static int CameraClass_get_camera(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    lua_pushlightuserdata(L, (void*)instance->camera);
    return 1;
}

static int CameraClass_get_node(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    lua_pushlightuserdata(L, (void*)instance->node);
    return 1;
}

static int CameraClass_get_currentMusic(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    lua_pushinteger(L, instance->currentMusic);
    return 1;
}

static int CameraClass_get_inBuilding(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    return HandBinding::push(L, instance->inBuilding);
}

static int CameraClass_get_timeInGame(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    lua_pushnumber(L, instance->timeInGame);
    return 1;
}

static int CameraClass_get_targetPositionY(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    lua_pushnumber(L, instance->targetPositionY);
    return 1;
}

static int CameraClass_get_speedY(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    lua_pushnumber(L, instance->speedY);
    return 1;
}

static int CameraClass_get_centerBuilding(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    return pushObject<Building>(L, instance->centerBuilding, BuildingBinding::getMetatableName());
}

static int CameraClass_get_centerBuildingY(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    lua_pushnumber(L, instance->centerBuildingY);
    return 1;
}

static int CameraClass_get_currentCollisionGroup(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    lua_pushinteger(L, instance->currentCollisionGroup);
    return 1;
}

static int CameraClass_get_currentFloor(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    lua_pushinteger(L, instance->currentFloor);
    return 1;
}

static int CameraClass_get_freeCameraMode(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    lua_pushboolean(L, instance->freeCameraMode ? 1 : 0);
    return 1;
}

// --- Setters for CameraClass ---
static int CameraClass_set_isRotating(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    instance->isRotating = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CameraClass_set_yaw(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    instance->yaw = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CameraClass_set_pitch(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    instance->pitch = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CameraClass_set_initialised(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    instance->initialised = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CameraClass_set_terrainLoaded(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    instance->terrainLoaded = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CameraClass_set_objectCurrentlyFollowing(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    instance->objectCurrentlyFollowing = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int CameraClass_set_objectCurrentlyFollowingOffset(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    readVector3(L, 2, instance->objectCurrentlyFollowingOffset);
    return 0;
}

static int CameraClass_set_altitude(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    instance->altitude = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CameraClass_set_currentMusic(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    instance->currentMusic = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CameraClass_set_inBuilding(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    instance->inBuilding = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int CameraClass_set_timeInGame(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    instance->timeInGame = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CameraClass_set_targetPositionY(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    instance->targetPositionY = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CameraClass_set_speedY(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    instance->speedY = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CameraClass_set_centerBuilding(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    instance->centerBuilding = lua_isnoneornil(L, 2) ? nullptr : checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    return 0;
}

static int CameraClass_set_centerBuildingY(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    instance->centerBuildingY = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CameraClass_set_currentCollisionGroup(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    instance->currentCollisionGroup = (unsigned short)luaL_checkinteger(L, 2);
    return 0;
}

static int CameraClass_set_currentFloor(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    instance->currentFloor = (unsigned char)luaL_checkinteger(L, 2);
    return 0;
}

static int CameraClass_set_freeCameraMode(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");
    instance->freeCameraMode = lua_toboolean(L, 2) != 0;
    return 0;
}

int CameraClassBinding::reset(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    instance->reset();
    return 0;
}

int CameraClassBinding::update(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    bool controlEnabled = lua_toboolean(L, 2) != 0;
    instance->update(controlEnabled);
    return 0;
}

int CameraClassBinding::focusCameraOnObject(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    RootObject* object = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    Ogre::Vector3 offset;
    readVector3(L, 3, offset);
    bool nearZoom = lua_toboolean(L, 4) != 0;
    instance->focusCameraOnObject(object, offset, nearZoom);
    return 0;
}

int CameraClassBinding::updateOptionSettings(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    instance->updateOptionSettings();
    return 0;
}

int CameraClassBinding::save(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->save(data);
    return 0;
}

int CameraClassBinding::load(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->load(data);
    return 0;
}

int CameraClassBinding::teleport(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    instance->teleport(pos);
    return 0;
}

int CameraClassBinding::stopFollowing(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    instance->stopFollowing();
    return 0;
}

int CameraClassBinding::manuallySetOrientationAndZoom(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    Ogre::Quaternion rot;
    readQuaternion(L, 2, rot);
    float zoom = (float)luaL_checknumber(L, 3);
    instance->manuallySetOrientationAndZoom(rot, zoom);
    return 0;
}

int CameraClassBinding::getFacingDirection(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    Ogre::Vector3 result = instance->getFacingDirection();
    pushVector3(L, result);
    return 1;
}

int CameraClassBinding::getCenter(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    const Ogre::Vector3 result = instance->getCenter();
    pushVector3(L, result);
    return 1;
}

int CameraClassBinding::getCameraPos(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    const Ogre::Vector3 result = instance->getCameraPos();
    pushVector3(L, result);
    return 1;
}

int CameraClassBinding::getCenterNode(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    Ogre::SceneNode* result = instance->getCenterNode();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int CameraClassBinding::getCameraNode(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    Ogre::SceneNode* result = instance->getCameraNode();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int CameraClassBinding::isInitialised(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    bool result = instance->isInitialised();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CameraClassBinding::isFreeCameraMode(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    bool result = instance->isFreeCameraMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CameraClassBinding::setFreeCameraMode(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setFreeCameraMode(on);
    return 0;
}

int CameraClassBinding::updateFreeCamera(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    instance->updateFreeCamera();
    return 0;
}

int CameraClassBinding::move(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    Ogre::Vector3 dir;
    readVector3(L, 2, dir);
    instance->move(dir);
    return 0;
}

int CameraClassBinding::zoom(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    instance->zoom();
    return 0;
}

int CameraClassBinding::toGround(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    bool smooth = lua_toboolean(L, 2) != 0;
    instance->toGround(smooth);
    return 0;
}

int CameraClassBinding::setZoomDist(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    float dist = (float)luaL_checknumber(L, 2);
    instance->setZoomDist(dist);
    return 0;
}

int CameraClassBinding::rotate(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    float _yaw = (float)luaL_checknumber(L, 2);
    float _pitch = (float)luaL_checknumber(L, 3);
    instance->rotate(_yaw, _pitch);
    return 0;
}

int CameraClassBinding::rotationUpdate(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    instance->rotationUpdate();
    return 0;
}

int CameraClassBinding::updateAudio(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    instance->updateAudio();
    return 0;
}

int CameraClassBinding::followObject(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Expected hand");
    instance->followObject(*h);
    return 0;
}

int CameraClassBinding::getFollowObject(lua_State* L)
{
    CameraClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CameraClass is nil");

    return HandBinding::push(L, instance->getFollowObject());
}

/*
Skipped methods needing manual binding:
  line 16: CameraClass* _CONSTRUCTOR(...) - unsupported arg type
  line 23: bool isVisible(...) - overloaded method
  line 24: bool isVisible(...) - overloaded method
  line 25: int intersectScreenEdge(...) - non-string reference arg
  line 37: void restrictPosition(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - CameraClass_get_rotationMarker: Ogre::Entity* (unbound pointer)
  - CameraClass_get_center: Ogre::SceneNode* (unbound pointer)
  - CameraClass_get_camera: Ogre::Camera* (unbound pointer)
  - CameraClass_get_node: Ogre::SceneNode* (unbound pointer)
  - CameraClassBinding::getCenterNode: Ogre::SceneNode* (unbound pointer)
  - CameraClassBinding::getCameraNode: Ogre::SceneNode* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 49: lastMousePos (tagPOINT) - unsupported type
*/

int CameraClassBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CameraClassBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CameraClass object");
    return 1;
}

void CameraClassBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CameraClassBinding::gc },
        { "__tostring", CameraClassBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "reset", CameraClassBinding::reset },
        { "update", CameraClassBinding::update },
        { "focusCameraOnObject", CameraClassBinding::focusCameraOnObject },
        { "updateOptionSettings", CameraClassBinding::updateOptionSettings },
        { "save", CameraClassBinding::save },
        { "load", CameraClassBinding::load },
        { "teleport", CameraClassBinding::teleport },
        { "stopFollowing", CameraClassBinding::stopFollowing },
        { "manuallySetOrientationAndZoom", CameraClassBinding::manuallySetOrientationAndZoom },
        { "getFacingDirection", CameraClassBinding::getFacingDirection },
        { "getCenter", CameraClassBinding::getCenter },
        { "getCameraPos", CameraClassBinding::getCameraPos },
        { "getCenterNode", CameraClassBinding::getCenterNode },
        { "getCameraNode", CameraClassBinding::getCameraNode },
        { "isInitialised", CameraClassBinding::isInitialised },
        { "isFreeCameraMode", CameraClassBinding::isFreeCameraMode },
        { "setFreeCameraMode", CameraClassBinding::setFreeCameraMode },
        { "updateFreeCamera", CameraClassBinding::updateFreeCamera },
        { "move", CameraClassBinding::move },
        { "zoom", CameraClassBinding::zoom },
        { "toGround", CameraClassBinding::toGround },
        { "setZoomDist", CameraClassBinding::setZoomDist },
        { "rotate", CameraClassBinding::rotate },
        { "rotationUpdate", CameraClassBinding::rotationUpdate },
        { "updateAudio", CameraClassBinding::updateAudio },
        { "followObject", CameraClassBinding::followObject },
        { "getFollowObject", CameraClassBinding::getFollowObject },
        { 0, 0 }
    };

    registerClass(
        L, 
        CameraClassBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CameraClassBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "isRotating", CameraClass_get_isRotating);
    registerGetter(L, "rotationMarker", CameraClass_get_rotationMarker);
    registerGetter(L, "yaw", CameraClass_get_yaw);
    registerGetter(L, "pitch", CameraClass_get_pitch);
    registerGetter(L, "initialised", CameraClass_get_initialised);
    registerGetter(L, "terrainLoaded", CameraClass_get_terrainLoaded);
    registerGetter(L, "objectCurrentlyFollowing", CameraClass_get_objectCurrentlyFollowing);
    registerGetter(L, "objectCurrentlyFollowingOffset", CameraClass_get_objectCurrentlyFollowingOffset);
    registerGetter(L, "center", CameraClass_get_center);
    registerGetter(L, "altitude", CameraClass_get_altitude);
    registerGetter(L, "camera", CameraClass_get_camera);
    registerGetter(L, "node", CameraClass_get_node);
    registerGetter(L, "currentMusic", CameraClass_get_currentMusic);
    registerGetter(L, "inBuilding", CameraClass_get_inBuilding);
    registerGetter(L, "timeInGame", CameraClass_get_timeInGame);
    registerGetter(L, "targetPositionY", CameraClass_get_targetPositionY);
    registerGetter(L, "speedY", CameraClass_get_speedY);
    registerGetter(L, "centerBuilding", CameraClass_get_centerBuilding);
    registerGetter(L, "centerBuildingY", CameraClass_get_centerBuildingY);
    registerGetter(L, "currentCollisionGroup", CameraClass_get_currentCollisionGroup);
    registerGetter(L, "currentFloor", CameraClass_get_currentFloor);
    registerGetter(L, "freeCameraMode", CameraClass_get_freeCameraMode);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "isRotating", CameraClass_set_isRotating);
    registerSetter(L, "yaw", CameraClass_set_yaw);
    registerSetter(L, "pitch", CameraClass_set_pitch);
    registerSetter(L, "initialised", CameraClass_set_initialised);
    registerSetter(L, "terrainLoaded", CameraClass_set_terrainLoaded);
    registerSetter(L, "objectCurrentlyFollowing", CameraClass_set_objectCurrentlyFollowing);
    registerSetter(L, "objectCurrentlyFollowingOffset", CameraClass_set_objectCurrentlyFollowingOffset);
    registerSetter(L, "altitude", CameraClass_set_altitude);
    registerSetter(L, "currentMusic", CameraClass_set_currentMusic);
    registerSetter(L, "inBuilding", CameraClass_set_inBuilding);
    registerSetter(L, "timeInGame", CameraClass_set_timeInGame);
    registerSetter(L, "targetPositionY", CameraClass_set_targetPositionY);
    registerSetter(L, "speedY", CameraClass_set_speedY);
    registerSetter(L, "centerBuilding", CameraClass_set_centerBuilding);
    registerSetter(L, "centerBuildingY", CameraClass_set_centerBuildingY);
    registerSetter(L, "currentCollisionGroup", CameraClass_set_currentCollisionGroup);
    registerSetter(L, "currentFloor", CameraClass_set_currentFloor);
    registerSetter(L, "freeCameraMode", CameraClass_set_freeCameraMode);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua