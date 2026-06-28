#include "pch.h"
#include "kenshi\CameraClass.h"
#include "CameraClassBinding.h"
//#include "BuildingBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/HandBinding.h"

namespace KenshiLua
{

static CameraClass* getB(lua_State* L, int idx)
{
    return checkObject<CameraClass>(L, idx, CameraClassBinding::getMetatableName());
}

// --- Getters for CameraClass ---
static int CameraClass_get_isRotating(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    lua_pushboolean(L, b->isRotating ? 1 : 0);
    return 1;
}

static int CameraClass_get_lastMousePos(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    // TODO: Unsupported type for lastMousePos (tagPOINT)
    return luaL_error(L, "Unsupported property 'lastMousePos' (type: tagPOINT)");
}

static int CameraClass_get_rotationMarker(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    // TODO: Unsupported type for rotationMarker (Ogre::Entity*)
    return luaL_error(L, "Unsupported property 'rotationMarker' (type: Ogre::Entity*)");
}

static int CameraClass_get_yaw(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    lua_pushnumber(L, b->yaw);
    return 1;
}

static int CameraClass_get_pitch(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    lua_pushnumber(L, b->pitch);
    return 1;
}

static int CameraClass_get_initialised(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    lua_pushboolean(L, b->initialised ? 1 : 0);
    return 1;
}

static int CameraClass_get_terrainLoaded(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    lua_pushboolean(L, b->terrainLoaded ? 1 : 0);
    return 1;
}

static int CameraClass_get_objectCurrentlyFollowing(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    return handBinding::push(L, b->objectCurrentlyFollowing);
}

static int CameraClass_get_objectCurrentlyFollowingOffset(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    pushVector3(L, b->objectCurrentlyFollowingOffset);
    return 1;
}

static int CameraClass_get_center(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    // TODO: Unsupported type for center (Ogre::SceneNode*)
    return luaL_error(L, "Unsupported property 'center' (type: Ogre::SceneNode*)");
}

static int CameraClass_get_altitude(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    lua_pushnumber(L, b->altitude);
    return 1;
}

static int CameraClass_get_camera(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    // TODO: Unsupported type for camera (Ogre::Camera*)
    return luaL_error(L, "Unsupported property 'camera' (type: Ogre::Camera*)");
}

static int CameraClass_get_node(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    // TODO: Unsupported type for node (Ogre::SceneNode*)
    return luaL_error(L, "Unsupported property 'node' (type: Ogre::SceneNode*)");
}

static int CameraClass_get_currentMusic(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    lua_pushinteger(L, b->currentMusic);
    return 1;
}

static int CameraClass_get_inBuilding(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    return handBinding::push(L, b->inBuilding);
}

static int CameraClass_get_timeInGame(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    lua_pushnumber(L, b->timeInGame);
    return 1;
}

static int CameraClass_get_targetPositionY(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    lua_pushnumber(L, b->targetPositionY);
    return 1;
}

static int CameraClass_get_speedY(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    lua_pushnumber(L, b->speedY);
    return 1;
}

static int CameraClass_get_centerBuilding(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    return pushObject<Building>(L, b->centerBuilding, "KenshiLua.Building");
}

static int CameraClass_get_centerBuildingY(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    lua_pushnumber(L, b->centerBuildingY);
    return 1;
}

static int CameraClass_get_currentCollisionGroup(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    lua_pushinteger(L, b->currentCollisionGroup);
    return 1;
}

static int CameraClass_get_currentFloor(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    lua_pushinteger(L, b->currentFloor);
    return 1;
}

static int CameraClass_get_freeCameraMode(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    lua_pushboolean(L, b->freeCameraMode ? 1 : 0);
    return 1;
}

// --- Setters for CameraClass ---
static int CameraClass_set_isRotating(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    b->isRotating = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CameraClass_set_lastMousePos(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    return luaL_error(L, "Read-only or unsupported setter type for lastMousePos");
}

static int CameraClass_set_rotationMarker(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    return luaL_error(L, "Read-only or unsupported setter type for rotationMarker");
}

static int CameraClass_set_yaw(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    b->yaw = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CameraClass_set_pitch(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    b->pitch = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CameraClass_set_initialised(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    b->initialised = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CameraClass_set_terrainLoaded(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    b->terrainLoaded = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CameraClass_set_objectCurrentlyFollowing(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->objectCurrentlyFollowing = *val;
    return 0;
}

static int CameraClass_set_objectCurrentlyFollowingOffset(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    readVector3(L, 2, b->objectCurrentlyFollowingOffset);
    return 0;
}

static int CameraClass_set_center(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    return luaL_error(L, "Read-only or unsupported setter type for center");
}

static int CameraClass_set_altitude(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    b->altitude = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CameraClass_set_camera(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    return luaL_error(L, "Read-only or unsupported setter type for camera");
}

static int CameraClass_set_node(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    return luaL_error(L, "Read-only or unsupported setter type for node");
}

static int CameraClass_set_currentMusic(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    b->currentMusic = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CameraClass_set_inBuilding(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    b->inBuilding = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int CameraClass_set_timeInGame(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    b->timeInGame = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CameraClass_set_targetPositionY(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    b->targetPositionY = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CameraClass_set_speedY(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    b->speedY = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CameraClass_set_centerBuilding(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    return luaL_error(L, "Read-only or unsupported setter type for centerBuilding");
}

static int CameraClass_set_centerBuildingY(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    b->centerBuildingY = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CameraClass_set_currentCollisionGroup(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    b->currentCollisionGroup = (unsigned short)luaL_checkinteger(L, 2);
    return 0;
}

static int CameraClass_set_currentFloor(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    b->currentFloor = (unsigned char)luaL_checkinteger(L, 2);
    return 0;
}

static int CameraClass_set_freeCameraMode(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");
    b->freeCameraMode = lua_toboolean(L, 2) != 0;
    return 0;
}

int CameraClassBinding::reset(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");

    b->reset();
    return 0;
}

int CameraClassBinding::update(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");

    bool controlEnabled = lua_toboolean(L, 2) != 0;
    b->update(controlEnabled);
    return 0;
}

int CameraClassBinding::updateOptionSettings(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");

    b->updateOptionSettings();
    return 0;
}

int CameraClassBinding::teleport(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    b->teleport(pos);
    return 0;
}

int CameraClassBinding::stopFollowing(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");

    b->stopFollowing();
    return 0;
}

int CameraClassBinding::manuallySetOrientationAndZoom(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");

    Ogre::Quaternion rot;
    readQuaternion(L, 2, rot);
    float zoom = (float)luaL_checknumber(L, 3);
    b->manuallySetOrientationAndZoom(rot, zoom);
    return 0;
}

int CameraClassBinding::getFacingDirection(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");

    Ogre::Vector3 result = b->getFacingDirection();
    pushVector3(L, result);
    return 1;
}

int CameraClassBinding::getCenter(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");

    Ogre::Vector3 result = b->getCenter();
    pushVector3(L, result);
    return 1;
}

int CameraClassBinding::getCameraPos(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");

    Ogre::Vector3 result = b->getCameraPos();
    pushVector3(L, result);
    return 1;
}

int CameraClassBinding::isInitialised(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");

    bool result = b->isInitialised();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CameraClassBinding::isFreeCameraMode(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");

    bool result = b->isFreeCameraMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CameraClassBinding::setFreeCameraMode(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->setFreeCameraMode(on);
    return 0;
}

int CameraClassBinding::updateFreeCamera(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");

    b->updateFreeCamera();
    return 0;
}

int CameraClassBinding::move(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");

    Ogre::Vector3 dir;
    readVector3(L, 2, dir);
    b->move(dir);
    return 0;
}

int CameraClassBinding::zoom(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");

    b->zoom();
    return 0;
}

int CameraClassBinding::toGround(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");

    bool smooth = lua_toboolean(L, 2) != 0;
    b->toGround(smooth);
    return 0;
}

int CameraClassBinding::setZoomDist(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");

    float dist = (float)luaL_checknumber(L, 2);
    b->setZoomDist(dist);
    return 0;
}

int CameraClassBinding::rotate(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");

    float _yaw = (float)luaL_checknumber(L, 2);
    float _pitch = (float)luaL_checknumber(L, 3);
    b->rotate(_yaw, _pitch);
    return 0;
}

int CameraClassBinding::rotationUpdate(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");

    b->rotationUpdate();
    return 0;
}

int CameraClassBinding::updateAudio(lua_State* L)
{
    CameraClass* b = getB(L, 1);
    if (!b) return luaL_error(L, "CameraClass is nil");

    b->updateAudio();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 16: CameraClass* _CONSTRUCTOR(...) - unsupported arg type
  line 19: void focusCameraOnObject(...) - unsupported arg type
  line 21: void save(...) - unsupported arg type
  line 22: void load(...) - unsupported arg type
  line 23: bool isVisible(...) - overloaded method
  line 24: bool isVisible(...) - overloaded method
  line 25: int intersectScreenEdge(...) - non-string reference arg
  line 27: void followObject(...) - unsupported arg type
  line 29: const hand& getFollowObject(...) - reference return type
  line 34: Ogre::SceneNode* getCenterNode(...) - unsupported return type
  line 35: Ogre::SceneNode* getCameraNode(...) - unsupported return type
  line 37: void restrictPosition(...) - unsupported arg type
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
        { "updateOptionSettings", CameraClassBinding::updateOptionSettings },
        { "teleport", CameraClassBinding::teleport },
        { "stopFollowing", CameraClassBinding::stopFollowing },
        { "manuallySetOrientationAndZoom", CameraClassBinding::manuallySetOrientationAndZoom },
        { "getFacingDirection", CameraClassBinding::getFacingDirection },
        { "getCenter", CameraClassBinding::getCenter },
        { "getCameraPos", CameraClassBinding::getCameraPos },
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
    lua_pushcfunction(L, CameraClass_get_isRotating);
    lua_setfield(L, -2, "isRotating");
    lua_pushcfunction(L, CameraClass_get_lastMousePos);
    lua_setfield(L, -2, "lastMousePos");
    lua_pushcfunction(L, CameraClass_get_rotationMarker);
    lua_setfield(L, -2, "rotationMarker");
    lua_pushcfunction(L, CameraClass_get_yaw);
    lua_setfield(L, -2, "yaw");
    lua_pushcfunction(L, CameraClass_get_pitch);
    lua_setfield(L, -2, "pitch");
    lua_pushcfunction(L, CameraClass_get_initialised);
    lua_setfield(L, -2, "initialised");
    lua_pushcfunction(L, CameraClass_get_terrainLoaded);
    lua_setfield(L, -2, "terrainLoaded");
    lua_pushcfunction(L, CameraClass_get_objectCurrentlyFollowing);
    lua_setfield(L, -2, "objectCurrentlyFollowing");
    lua_pushcfunction(L, CameraClass_get_objectCurrentlyFollowingOffset);
    lua_setfield(L, -2, "objectCurrentlyFollowingOffset");
    lua_pushcfunction(L, CameraClass_get_center);
    lua_setfield(L, -2, "center");
    lua_pushcfunction(L, CameraClass_get_altitude);
    lua_setfield(L, -2, "altitude");
    lua_pushcfunction(L, CameraClass_get_camera);
    lua_setfield(L, -2, "camera");
    lua_pushcfunction(L, CameraClass_get_node);
    lua_setfield(L, -2, "node");
    lua_pushcfunction(L, CameraClass_get_currentMusic);
    lua_setfield(L, -2, "currentMusic");
    lua_pushcfunction(L, CameraClass_get_inBuilding);
    lua_setfield(L, -2, "inBuilding");
    lua_pushcfunction(L, CameraClass_get_timeInGame);
    lua_setfield(L, -2, "timeInGame");
    lua_pushcfunction(L, CameraClass_get_targetPositionY);
    lua_setfield(L, -2, "targetPositionY");
    lua_pushcfunction(L, CameraClass_get_speedY);
    lua_setfield(L, -2, "speedY");
    lua_pushcfunction(L, CameraClass_get_centerBuilding);
    lua_setfield(L, -2, "centerBuilding");
    lua_pushcfunction(L, CameraClass_get_centerBuildingY);
    lua_setfield(L, -2, "centerBuildingY");
    lua_pushcfunction(L, CameraClass_get_currentCollisionGroup);
    lua_setfield(L, -2, "currentCollisionGroup");
    lua_pushcfunction(L, CameraClass_get_currentFloor);
    lua_setfield(L, -2, "currentFloor");
    lua_pushcfunction(L, CameraClass_get_freeCameraMode);
    lua_setfield(L, -2, "freeCameraMode");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, CameraClass_set_isRotating);
    lua_setfield(L, -2, "isRotating");
    lua_pushcfunction(L, CameraClass_set_lastMousePos);
    lua_setfield(L, -2, "lastMousePos");
    lua_pushcfunction(L, CameraClass_set_rotationMarker);
    lua_setfield(L, -2, "rotationMarker");
    lua_pushcfunction(L, CameraClass_set_yaw);
    lua_setfield(L, -2, "yaw");
    lua_pushcfunction(L, CameraClass_set_pitch);
    lua_setfield(L, -2, "pitch");
    lua_pushcfunction(L, CameraClass_set_initialised);
    lua_setfield(L, -2, "initialised");
    lua_pushcfunction(L, CameraClass_set_terrainLoaded);
    lua_setfield(L, -2, "terrainLoaded");
    lua_pushcfunction(L, CameraClass_set_objectCurrentlyFollowing);
    lua_setfield(L, -2, "objectCurrentlyFollowing");
    lua_pushcfunction(L, CameraClass_set_objectCurrentlyFollowingOffset);
    lua_setfield(L, -2, "objectCurrentlyFollowingOffset");
    lua_pushcfunction(L, CameraClass_set_center);
    lua_setfield(L, -2, "center");
    lua_pushcfunction(L, CameraClass_set_altitude);
    lua_setfield(L, -2, "altitude");
    lua_pushcfunction(L, CameraClass_set_camera);
    lua_setfield(L, -2, "camera");
    lua_pushcfunction(L, CameraClass_set_node);
    lua_setfield(L, -2, "node");
    lua_pushcfunction(L, CameraClass_set_currentMusic);
    lua_setfield(L, -2, "currentMusic");
    lua_pushcfunction(L, CameraClass_set_inBuilding);
    lua_setfield(L, -2, "inBuilding");
    lua_pushcfunction(L, CameraClass_set_timeInGame);
    lua_setfield(L, -2, "timeInGame");
    lua_pushcfunction(L, CameraClass_set_targetPositionY);
    lua_setfield(L, -2, "targetPositionY");
    lua_pushcfunction(L, CameraClass_set_speedY);
    lua_setfield(L, -2, "speedY");
    lua_pushcfunction(L, CameraClass_set_centerBuilding);
    lua_setfield(L, -2, "centerBuilding");
    lua_pushcfunction(L, CameraClass_set_centerBuildingY);
    lua_setfield(L, -2, "centerBuildingY");
    lua_pushcfunction(L, CameraClass_set_currentCollisionGroup);
    lua_setfield(L, -2, "currentCollisionGroup");
    lua_pushcfunction(L, CameraClass_set_currentFloor);
    lua_setfield(L, -2, "currentFloor");
    lua_pushcfunction(L, CameraClass_set_freeCameraMode);
    lua_setfield(L, -2, "freeCameraMode");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua