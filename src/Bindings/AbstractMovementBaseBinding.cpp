#include "pch.h"
#include "kenshi\CharMovement.h"
#include "AbstractMovementBaseBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/MedianFilter2DVectorBinding.h"
#include "Bindings/NxUserControllerHitReportBinding.h"
#include "Bindings/RootObjectBaseBinding.h"
#include "Bindings/SpeedGroupBinding.h"

namespace KenshiLua
{

static AbstractMovementBase* getInstance(lua_State* L, int idx)
{
    return checkObject<AbstractMovementBase>(L, idx, AbstractMovementBaseBinding::getMetatableName());
}

// --- Getters for AbstractMovementBase ---
static int AbstractMovementBase_get_officiallyStopped(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    lua_pushboolean(L, instance->officiallyStopped ? 1 : 0);
    return 1;
}

static int AbstractMovementBase_get_speedOrders(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    lua_pushinteger(L, (lua_Integer)instance->speedOrders);
    return 1;
}

static int AbstractMovementBase_get_currentlyMoving(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    lua_pushboolean(L, instance->currentlyMoving ? 1 : 0);
    return 1;
}

static int AbstractMovementBase_get_positionSmoother(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    return pushObject<MedianFilter2DVector>(L, &instance->positionSmoother, MedianFilter2DVectorBinding::getMetatableName());
}

static int AbstractMovementBase_get_currentMotion(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    pushVector3(L, instance->currentMotion);
    return 1;
}

static int AbstractMovementBase_get_maxSpeed(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    lua_pushnumber(L, instance->maxSpeed);
    return 1;
}

static int AbstractMovementBase_get_currentSpeed(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    lua_pushnumber(L, instance->currentSpeed);
    return 1;
}

static int AbstractMovementBase_get_desiredSpeed(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    lua_pushnumber(L, instance->desiredSpeed);
    return 1;
}

static int AbstractMovementBase_get_walkSpeed(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    lua_pushnumber(L, instance->walkSpeed);
    return 1;
}

static int AbstractMovementBase_get_pos(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    pushVector3(L, instance->pos);
    return 1;
}

static int AbstractMovementBase_get_direction(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    pushVector3(L, instance->direction);
    return 1;
}

static int AbstractMovementBase_get_destination(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    pushVector3(L, instance->destination);
    return 1;
}

static int AbstractMovementBase_get_pathDestination(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    pushVector3(L, instance->pathDestination);
    return 1;
}

static int AbstractMovementBase_get_roadFollower(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    lua_pushlightuserdata(L, (void*)instance->roadFollower);
    return 1;
}

static int AbstractMovementBase_get_roadWeight(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    lua_pushnumber(L, instance->roadWeight);
    return 1;
}

static int AbstractMovementBase_get_speedGroup(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    if (!instance->speedGroup.get()) {
        lua_pushnil(L);
        return 1;
    }
    return pushObject<SpeedGroup>(L, instance->speedGroup.get(), SpeedGroupBinding::getMetatableName());
}

// --- Setters for AbstractMovementBase ---
static int AbstractMovementBase_set_officiallyStopped(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    instance->officiallyStopped = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AbstractMovementBase_set_speedOrders(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    instance->speedOrders = (MoveSpeed)luaL_checkinteger(L, 2);
    return 0;
}

static int AbstractMovementBase_set_currentlyMoving(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    instance->currentlyMoving = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AbstractMovementBase_set_positionSmoother(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    instance->positionSmoother = *checkObject<MedianFilter2DVector>(L, 2, MedianFilter2DVectorBinding::getMetatableName());
    return 0;
}

static int AbstractMovementBase_set_currentMotion(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    readVector3(L, 2, instance->currentMotion);
    return 0;
}

static int AbstractMovementBase_set_maxSpeed(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    instance->maxSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AbstractMovementBase_set_currentSpeed(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    instance->currentSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AbstractMovementBase_set_desiredSpeed(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    instance->desiredSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AbstractMovementBase_set_walkSpeed(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    instance->walkSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AbstractMovementBase_set_pos(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    readVector3(L, 2, instance->pos);
    return 0;
}

static int AbstractMovementBase_set_direction(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    readVector3(L, 2, instance->direction);
    return 0;
}

static int AbstractMovementBase_set_destination(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    readVector3(L, 2, instance->destination);
    return 0;
}

static int AbstractMovementBase_set_pathDestination(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    readVector3(L, 2, instance->pathDestination);
    return 0;
}

static int AbstractMovementBase_set_roadWeight(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    instance->roadWeight = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AbstractMovementBase_set_speedGroup(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");
    SpeedGroup* ptr = lua_isnoneornil(L, 2) ? nullptr : checkObject<SpeedGroup>(L, 2, SpeedGroupBinding::getMetatableName());
    instance->speedGroup = Ogre::SharedPtr<SpeedGroup>(ptr);
    return 0;
}

int AbstractMovementBaseBinding::_CONSTRUCTOR(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    AbstractMovementBase* result = instance->_CONSTRUCTOR();
    return pushObject<AbstractMovementBase>(L, result, AbstractMovementBaseBinding::getMetatableName());
}

int AbstractMovementBaseBinding::_DESTRUCTOR(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int AbstractMovementBaseBinding::create(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 _pos;
    readVector3(L, 2, _pos);
    instance->create(_pos);
    return 0;
}

int AbstractMovementBaseBinding::getHandle(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    hand result = instance->getHandle();
    return HandBinding::push(L, result);
}

int AbstractMovementBaseBinding::_NV_getHandle(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    hand result = instance->_NV_getHandle();
    return HandBinding::push(L, result);
}

int AbstractMovementBaseBinding::_setPositionAndTeleport(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    int floor = (int)luaL_checkinteger(L, 3);
    instance->_setPositionAndTeleport(p, floor);
    return 0;
}

int AbstractMovementBaseBinding::_NV__setPositionAndTeleport(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    int floor = (int)luaL_checkinteger(L, 3);
    instance->_NV__setPositionAndTeleport(p, floor);
    return 0;
}

int AbstractMovementBaseBinding::_setPositionSimple(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    instance->_setPositionSimple(p);
    return 0;
}

int AbstractMovementBaseBinding::_NV__setPositionSimple(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    instance->_NV__setPositionSimple(p);
    return 0;
}

int AbstractMovementBaseBinding::faceDirection(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 dir;
    readVector3(L, 2, dir);
    instance->faceDirection(dir);
    return 0;
}

int AbstractMovementBaseBinding::_NV_faceDirection(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 dir;
    readVector3(L, 2, dir);
    instance->_NV_faceDirection(dir);
    return 0;
}

int AbstractMovementBaseBinding::lookatPosition(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    instance->lookatPosition(pos);
    return 0;
}

int AbstractMovementBaseBinding::_NV_lookatPosition(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    instance->_NV_lookatPosition(pos);
    return 0;
}

int AbstractMovementBaseBinding::getDestination(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 result = instance->getDestination();
    pushVector3(L, result);
    return 1;
}

int AbstractMovementBaseBinding::isProbablyStuck(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    bool result = instance->isProbablyStuck();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AbstractMovementBaseBinding::pathOk(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    bool result = instance->pathOk();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AbstractMovementBaseBinding::_NV_pathOk(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    bool result = instance->_NV_pathOk();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AbstractMovementBaseBinding::pathFailed(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    bool result = instance->pathFailed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AbstractMovementBaseBinding::_NV_pathFailed(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    bool result = instance->_NV_pathFailed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AbstractMovementBaseBinding::update(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    float _TIME = (float)luaL_checknumber(L, 2);
    instance->update(_TIME);
    return 0;
}

int AbstractMovementBaseBinding::_NV_update(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    float _TIME = (float)luaL_checknumber(L, 2);
    instance->_NV_update(_TIME);
    return 0;
}

int AbstractMovementBaseBinding::isDestinationReached(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    bool result = instance->isDestinationReached();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AbstractMovementBaseBinding::_NV_isDestinationReached(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    bool result = instance->_NV_isDestinationReached();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AbstractMovementBaseBinding::amInsideTownWalls(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    int result = instance->amInsideTownWalls();
    lua_pushinteger(L, result);
    return 1;
}

int AbstractMovementBaseBinding::_NV_amInsideTownWalls(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    int result = instance->_NV_amInsideTownWalls();
    lua_pushinteger(L, result);
    return 1;
}

int AbstractMovementBaseBinding::manualMovement(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 desiredMotion;
    readVector3(L, 2, desiredMotion);
    instance->manualMovement(desiredMotion);
    return 0;
}

int AbstractMovementBaseBinding::_NV_manualMovement(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 desiredMotion;
    readVector3(L, 2, desiredMotion);
    instance->_NV_manualMovement(desiredMotion);
    return 0;
}

int AbstractMovementBaseBinding::halt(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    instance->halt();
    return 0;
}

int AbstractMovementBaseBinding::_NV_halt(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    instance->_NV_halt();
    return 0;
}

int AbstractMovementBaseBinding::setRoadDestination(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 dest;
    readVector3(L, 2, dest);
    bool result = instance->setRoadDestination(dest);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AbstractMovementBaseBinding::setRoadPreference(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    float w = (float)luaL_checknumber(L, 2);
    instance->setRoadPreference(w);
    return 0;
}

int AbstractMovementBaseBinding::extractRoadFollower(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    RoadFollower* result = instance->extractRoadFollower();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int AbstractMovementBaseBinding::_NV_setDesiredSpeed(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    MoveSpeed speed = (MoveSpeed)luaL_checkinteger(L, 2);
    instance->_NV_setDesiredSpeed(speed);
    return 0;
}

int AbstractMovementBaseBinding::setStandardWalkSpeed(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    float s = (float)luaL_checknumber(L, 2);
    instance->setStandardWalkSpeed(s);
    return 0;
}

int AbstractMovementBaseBinding::getStandardWalkSpeed(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    float result = instance->getStandardWalkSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int AbstractMovementBaseBinding::restoreDesiredSpeed(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    instance->restoreDesiredSpeed();
    return 0;
}

int AbstractMovementBaseBinding::setMaxSpeed(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    float ms = (float)luaL_checknumber(L, 2);
    instance->setMaxSpeed(ms);
    return 0;
}

int AbstractMovementBaseBinding::getMaxSpeed(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    float result = instance->getMaxSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int AbstractMovementBaseBinding::isCurrentlyMoving(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    bool result = instance->isCurrentlyMoving();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AbstractMovementBaseBinding::getCurrentSpeed(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    float result = instance->getCurrentSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int AbstractMovementBaseBinding::getCurrentMotion(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 result = instance->getCurrentMotion();
    pushVector3(L, result);
    return 1;
}

int AbstractMovementBaseBinding::getCurrentSpeedRelativeToMax01(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    float result = instance->getCurrentSpeedRelativeToMax01();
    lua_pushnumber(L, result);
    return 1;
}

int AbstractMovementBaseBinding::getSpeedOrders(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    MoveSpeed result = instance->getSpeedOrders();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int AbstractMovementBaseBinding::leaveSpeedGroup(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    instance->leaveSpeedGroup();
    return 0;
}

int AbstractMovementBaseBinding::getPosition(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    pushVector3(L, instance->getPosition());
    return 1;
}

int AbstractMovementBaseBinding::_NV_getPosition(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    pushVector3(L, instance->_NV_getPosition());
    return 1;
}

int AbstractMovementBaseBinding::getFacingDirection(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    pushVector3(L, instance->getFacingDirection());
    return 1;
}

int AbstractMovementBaseBinding::setDestination(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    if (Character* who = testObject<Character>(L, 2, CharacterBinding::getMetatableName())) {
        UpdatePriority pri = (UpdatePriority)luaL_optinteger(L, 3, 0);
        instance->setDestination(who, pri);
        return 0;
    }
    if (Building* who = testObject<Building>(L, 2, BuildingBinding::getMetatableName())) {
        UpdatePriority pri = (UpdatePriority)luaL_optinteger(L, 3, 0);
        instance->setDestination(who, pri);
        return 0;
    }
    if (RootObjectBase* target = testObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName())) {
        UpdatePriority pri = (UpdatePriority)luaL_optinteger(L, 3, 0);
        instance->setDestination(target, pri);
        return 0;
    }
    if (lua_istable(L, 2)) {
        Ogre::Vector3 dest;
        readVector3(L, 2, dest);
        UpdatePriority pri = (UpdatePriority)luaL_optinteger(L, 3, 0);
        bool notVertical = lua_toboolean(L, 4) != 0;
        instance->setDestination(dest, pri, notVertical);
        return 0;
    }

    return luaL_error(L, "Argument 2 to setDestination must be a Vector3 table, Character, Building, or RootObjectBase, got %s", luaL_typename(L, 2));
}

int AbstractMovementBaseBinding::_NV_setDestination(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    if (Character* who = testObject<Character>(L, 2, CharacterBinding::getMetatableName())) {
        UpdatePriority pri = (UpdatePriority)luaL_optinteger(L, 3, 0);
        instance->_NV_setDestination(who, pri);
        return 0;
    }
    if (Building* who = testObject<Building>(L, 2, BuildingBinding::getMetatableName())) {
        UpdatePriority pri = (UpdatePriority)luaL_optinteger(L, 3, 0);
        instance->_NV_setDestination(who, pri);
        return 0;
    }
    if (RootObjectBase* target = testObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName())) {
        UpdatePriority pri = (UpdatePriority)luaL_optinteger(L, 3, 0);
        instance->_NV_setDestination(target, pri);
        return 0;
    }
    if (lua_istable(L, 2)) {
        Ogre::Vector3 dest;
        readVector3(L, 2, dest);
        UpdatePriority pri = (UpdatePriority)luaL_optinteger(L, 3, 0);
        bool notVertical = lua_toboolean(L, 4) != 0;
        instance->_NV_setDestination(dest, pri, notVertical);
        return 0;
    }

    return luaL_error(L, "Argument 2 to _NV_setDestination must be a Vector3 table, Character, Building, or RootObjectBase, got %s", luaL_typename(L, 2));
}

int AbstractMovementBaseBinding::setCurrentRoadFollower(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 d;
    readVector3(L, 2, d);
    RoadFollower* r = (RoadFollower*)lua_touserdata(L, 3);
    instance->setCurrentRoadFollower(d, r);
    return 0;
}

int AbstractMovementBaseBinding::setPatrolInput(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    PatrolInfo* patrol = (PatrolInfo*)lua_touserdata(L, 2);
    if (!patrol) return luaL_error(L, "Argument 2 to setPatrolInput must be PatrolInfo lightuserdata");
    instance->setPatrolInput(*patrol);
    return 0;
}

int AbstractMovementBaseBinding::_NV_setPatrolInput(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    PatrolInfo* patrol = (PatrolInfo*)lua_touserdata(L, 2);
    if (!patrol) return luaL_error(L, "Argument 2 to _NV_setPatrolInput must be PatrolInfo lightuserdata");
    instance->_NV_setPatrolInput(*patrol);
    return 0;
}

int AbstractMovementBaseBinding::setDesiredSpeed(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    if (!lua_isnumber(L, 2))
        return luaL_error(L, "Argument 2 to setDesiredSpeed must be MoveSpeed (enum) or float speed, got %s", luaL_typename(L, 2));

    lua_Number n = lua_tonumber(L, 2);
    lua_Integer i = lua_tointeger(L, 2);
    if (lua_isinteger(L, 2) && i >= 0 && i <= 4)
    {
        instance->setDesiredSpeed((MoveSpeed)i);
    }
    else
    {
        instance->setDesiredSpeed((float)n);
    }
    return 0;
}

int AbstractMovementBaseBinding::setDesiredSpeedOrders(lua_State* L)
{
    AbstractMovementBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AbstractMovementBase is nil");

    if (!lua_isnumber(L, 2))
        return luaL_error(L, "Argument 2 to setDesiredSpeedOrders must be MoveSpeed (enum) or float speed, got %s", luaL_typename(L, 2));

    lua_Number n = lua_tonumber(L, 2);
    lua_Integer i = lua_tointeger(L, 2);
    if (lua_isinteger(L, 2) && i >= 0 && i <= 4)
    {
        instance->setDesiredSpeedOrders((MoveSpeed)i);
    }
    else
    {
        instance->setDesiredSpeedOrders((float)n);
    }
    return 0;
}

/*
Skipped methods needing manual binding:
  line 222: NxControllerAction onShapeHit(...) - protected access
  line 223: NxControllerAction _NV_onShapeHit(...) - protected access
  line 224: NxControllerAction onControllerHit(...) - protected access
  line 225: NxControllerAction _NV_onControllerHit(...) - protected access
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - AbstractMovementBase_get_roadFollower: RoadFollower* (unbound pointer)
  - AbstractMovementBaseBinding::extractRoadFollower: RoadFollower* (unbound pointer)
  - AbstractMovementBaseBinding::setCurrentRoadFollower: RoadFollower* (unbound pointer)
  - AbstractMovementBaseBinding::setPatrolInput: PatrolInfo* (unbound pointer reference)
  - AbstractMovementBaseBinding::_NV_setPatrolInput: PatrolInfo* (unbound pointer reference)
*/

int AbstractMovementBaseBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int AbstractMovementBaseBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AbstractMovementBase object");
    return 1;
}

void AbstractMovementBaseBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AbstractMovementBaseBinding::gc },
        { "__tostring", AbstractMovementBaseBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", AbstractMovementBaseBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", AbstractMovementBaseBinding::_DESTRUCTOR },
        { "create", AbstractMovementBaseBinding::create },
        { "getHandle", AbstractMovementBaseBinding::getHandle },
        { "_NV_getHandle", AbstractMovementBaseBinding::_NV_getHandle },
        { "_setPositionAndTeleport", AbstractMovementBaseBinding::_setPositionAndTeleport },
        { "_NV__setPositionAndTeleport", AbstractMovementBaseBinding::_NV__setPositionAndTeleport },
        { "_setPositionSimple", AbstractMovementBaseBinding::_setPositionSimple },
        { "_NV__setPositionSimple", AbstractMovementBaseBinding::_NV__setPositionSimple },
        { "faceDirection", AbstractMovementBaseBinding::faceDirection },
        { "_NV_faceDirection", AbstractMovementBaseBinding::_NV_faceDirection },
        { "lookatPosition", AbstractMovementBaseBinding::lookatPosition },
        { "_NV_lookatPosition", AbstractMovementBaseBinding::_NV_lookatPosition },
        { "getDestination", AbstractMovementBaseBinding::getDestination },
        { "isProbablyStuck", AbstractMovementBaseBinding::isProbablyStuck },
        { "pathOk", AbstractMovementBaseBinding::pathOk },
        { "_NV_pathOk", AbstractMovementBaseBinding::_NV_pathOk },
        { "pathFailed", AbstractMovementBaseBinding::pathFailed },
        { "_NV_pathFailed", AbstractMovementBaseBinding::_NV_pathFailed },
        { "update", AbstractMovementBaseBinding::update },
        { "_NV_update", AbstractMovementBaseBinding::_NV_update },
        { "isDestinationReached", AbstractMovementBaseBinding::isDestinationReached },
        { "_NV_isDestinationReached", AbstractMovementBaseBinding::_NV_isDestinationReached },
        { "amInsideTownWalls", AbstractMovementBaseBinding::amInsideTownWalls },
        { "_NV_amInsideTownWalls", AbstractMovementBaseBinding::_NV_amInsideTownWalls },
        { "manualMovement", AbstractMovementBaseBinding::manualMovement },
        { "_NV_manualMovement", AbstractMovementBaseBinding::_NV_manualMovement },
        { "halt", AbstractMovementBaseBinding::halt },
        { "_NV_halt", AbstractMovementBaseBinding::_NV_halt },
        { "setRoadDestination", AbstractMovementBaseBinding::setRoadDestination },
        { "setRoadPreference", AbstractMovementBaseBinding::setRoadPreference },
        { "extractRoadFollower", AbstractMovementBaseBinding::extractRoadFollower },
        { "_NV_setDesiredSpeed", AbstractMovementBaseBinding::_NV_setDesiredSpeed },
        { "setStandardWalkSpeed", AbstractMovementBaseBinding::setStandardWalkSpeed },
        { "getStandardWalkSpeed", AbstractMovementBaseBinding::getStandardWalkSpeed },
        { "restoreDesiredSpeed", AbstractMovementBaseBinding::restoreDesiredSpeed },
        { "setMaxSpeed", AbstractMovementBaseBinding::setMaxSpeed },
        { "getMaxSpeed", AbstractMovementBaseBinding::getMaxSpeed },
        { "isCurrentlyMoving", AbstractMovementBaseBinding::isCurrentlyMoving },
        { "getCurrentSpeed", AbstractMovementBaseBinding::getCurrentSpeed },
        { "getCurrentMotion", AbstractMovementBaseBinding::getCurrentMotion },
        { "getCurrentSpeedRelativeToMax01", AbstractMovementBaseBinding::getCurrentSpeedRelativeToMax01 },
        { "getSpeedOrders", AbstractMovementBaseBinding::getSpeedOrders },
        { "leaveSpeedGroup", AbstractMovementBaseBinding::leaveSpeedGroup },
        { "getPosition", AbstractMovementBaseBinding::getPosition },
        { "_NV_getPosition", AbstractMovementBaseBinding::_NV_getPosition },
        { "getFacingDirection", AbstractMovementBaseBinding::getFacingDirection },
        { "setDestination", AbstractMovementBaseBinding::setDestination },
        { "_NV_setDestination", AbstractMovementBaseBinding::_NV_setDestination },
        { "setCurrentRoadFollower", AbstractMovementBaseBinding::setCurrentRoadFollower },
        { "setPatrolInput", AbstractMovementBaseBinding::setPatrolInput },
        { "_NV_setPatrolInput", AbstractMovementBaseBinding::_NV_setPatrolInput },
        { "setDesiredSpeed", AbstractMovementBaseBinding::setDesiredSpeed },
        { "setDesiredSpeedOrders", AbstractMovementBaseBinding::setDesiredSpeedOrders },
        { 0, 0 }
    };

    registerClass(
        L, 
        AbstractMovementBaseBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AbstractMovementBaseBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "officiallyStopped", AbstractMovementBase_get_officiallyStopped);
    registerGetter(L, "speedOrders", AbstractMovementBase_get_speedOrders);
    registerGetter(L, "speedGroup", AbstractMovementBase_get_speedGroup);
    registerGetter(L, "currentlyMoving", AbstractMovementBase_get_currentlyMoving);
    registerGetter(L, "positionSmoother", AbstractMovementBase_get_positionSmoother);
    registerGetter(L, "currentMotion", AbstractMovementBase_get_currentMotion);
    registerGetter(L, "maxSpeed", AbstractMovementBase_get_maxSpeed);
    registerGetter(L, "currentSpeed", AbstractMovementBase_get_currentSpeed);
    registerGetter(L, "desiredSpeed", AbstractMovementBase_get_desiredSpeed);
    registerGetter(L, "walkSpeed", AbstractMovementBase_get_walkSpeed);
    registerGetter(L, "pos", AbstractMovementBase_get_pos);
    registerGetter(L, "direction", AbstractMovementBase_get_direction);
    registerGetter(L, "destination", AbstractMovementBase_get_destination);
    registerGetter(L, "pathDestination", AbstractMovementBase_get_pathDestination);
    registerGetter(L, "roadFollower", AbstractMovementBase_get_roadFollower);
    registerGetter(L, "roadWeight", AbstractMovementBase_get_roadWeight);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "officiallyStopped", AbstractMovementBase_set_officiallyStopped);
    registerSetter(L, "speedOrders", AbstractMovementBase_set_speedOrders);
    registerSetter(L, "speedGroup", AbstractMovementBase_set_speedGroup);
    registerSetter(L, "currentlyMoving", AbstractMovementBase_set_currentlyMoving);
    registerSetter(L, "positionSmoother", AbstractMovementBase_set_positionSmoother);
    registerSetter(L, "currentMotion", AbstractMovementBase_set_currentMotion);
    registerSetter(L, "maxSpeed", AbstractMovementBase_set_maxSpeed);
    registerSetter(L, "currentSpeed", AbstractMovementBase_set_currentSpeed);
    registerSetter(L, "desiredSpeed", AbstractMovementBase_set_desiredSpeed);
    registerSetter(L, "walkSpeed", AbstractMovementBase_set_walkSpeed);
    registerSetter(L, "pos", AbstractMovementBase_set_pos);
    registerSetter(L, "direction", AbstractMovementBase_set_direction);
    registerSetter(L, "destination", AbstractMovementBase_set_destination);
    registerSetter(L, "pathDestination", AbstractMovementBase_set_pathDestination);
    registerSetter(L, "roadWeight", AbstractMovementBase_set_roadWeight);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to NxUserControllerHitReport
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, AbstractMovementBaseBinding::getMetatableName(), NxUserControllerHitReportBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua