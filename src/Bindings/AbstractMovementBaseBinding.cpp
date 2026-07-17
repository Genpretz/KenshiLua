#include "pch.h"
#include "kenshi\CharMovement.h"
#include "AbstractMovementBaseBinding.h"
#include "Lua/BindingHelpers.h"
#include "SpeedGroupBinding.h"
#include "MedianFilter2DVectorBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/RootObjectBaseBinding.h"

namespace KenshiLua
{

static AbstractMovementBase* getB(lua_State* L, int idx)
{
    return checkObject<AbstractMovementBase>(L, idx, AbstractMovementBaseBinding::getMetatableName());
}

// --- Getters for AbstractMovementBase ---
static int AbstractMovementBase_get_officiallyStopped(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    lua_pushboolean(L, b->officiallyStopped ? 1 : 0);
    return 1;
}

static int AbstractMovementBase_get_speedGroup(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    return pushObject<SpeedGroup>(L, b->speedGroup.get(), SpeedGroupBinding::getMetatableName());
}

static int AbstractMovementBase_get_speedOrders(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    lua_pushinteger(L, (lua_Integer)b->speedOrders);
    return 1;
}

static int AbstractMovementBase_get_currentlyMoving(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    lua_pushboolean(L, b->currentlyMoving ? 1 : 0);
    return 1;
}

static int AbstractMovementBase_get_positionSmoother(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    return pushObject<MedianFilter2DVector>(L, &b->positionSmoother, MedianFilter2DVectorBinding::getMetatableName());
}

static int AbstractMovementBase_get_currentMotion(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    pushVector3(L, b->currentMotion);
    return 1;
}

static int AbstractMovementBase_get_maxSpeed(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    lua_pushnumber(L, b->maxSpeed);
    return 1;
}

static int AbstractMovementBase_get_currentSpeed(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    lua_pushnumber(L, b->currentSpeed);
    return 1;
}

static int AbstractMovementBase_get_desiredSpeed(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    lua_pushnumber(L, b->desiredSpeed);
    return 1;
}

static int AbstractMovementBase_get_walkSpeed(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    lua_pushnumber(L, b->walkSpeed);
    return 1;
}

static int AbstractMovementBase_get_pos(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    pushVector3(L, b->pos);
    return 1;
}

static int AbstractMovementBase_get_direction(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    pushVector3(L, b->direction);
    return 1;
}

static int AbstractMovementBase_get_destination(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    pushVector3(L, b->destination);
    return 1;
}

static int AbstractMovementBase_get_pathDestination(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    pushVector3(L, b->pathDestination);
    return 1;
}

static int AbstractMovementBase_get_roadFollower(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    // TODO: Unsupported type for roadFollower (RoadFollower*)
    return luaL_error(L, "Unsupported property 'roadFollower' (type: RoadFollower*)");
}

static int AbstractMovementBase_get_roadWeight(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    lua_pushnumber(L, b->roadWeight);
    return 1;
}

// --- Setters for AbstractMovementBase ---
static int AbstractMovementBase_set_officiallyStopped(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    b->officiallyStopped = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AbstractMovementBase_set_speedGroup(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    if (lua_isnil(L, 2)) {
        b->speedGroup.setNull();
    } else {
        SpeedGroup* sg = checkObject<SpeedGroup>(L, 2, SpeedGroupBinding::getMetatableName());
        b->speedGroup = Ogre::SharedPtr<SpeedGroup>(sg);
    }
    return 0;
}

static int AbstractMovementBase_set_speedOrders(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    b->speedOrders = (MoveSpeed)luaL_checkinteger(L, 2);
    return 0;
}

static int AbstractMovementBase_set_currentlyMoving(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    b->currentlyMoving = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AbstractMovementBase_set_positionSmoother(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    MedianFilter2DVector* mf = checkObject<MedianFilter2DVector>(L, 2, MedianFilter2DVectorBinding::getMetatableName());
    b->positionSmoother = *mf;
    return 0;
}

static int AbstractMovementBase_set_currentMotion(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    readVector3(L, 2, b->currentMotion);
    return 0;
}

static int AbstractMovementBase_set_maxSpeed(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    b->maxSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AbstractMovementBase_set_currentSpeed(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    b->currentSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AbstractMovementBase_set_desiredSpeed(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    b->desiredSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AbstractMovementBase_set_walkSpeed(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    b->walkSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AbstractMovementBase_set_pos(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    readVector3(L, 2, b->pos);
    return 0;
}

static int AbstractMovementBase_set_direction(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    readVector3(L, 2, b->direction);
    return 0;
}

static int AbstractMovementBase_set_destination(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    readVector3(L, 2, b->destination);
    return 0;
}

static int AbstractMovementBase_set_pathDestination(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    readVector3(L, 2, b->pathDestination);
    return 0;
}

static int AbstractMovementBase_set_roadFollower(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for roadFollower");
}

static int AbstractMovementBase_set_roadWeight(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    b->roadWeight = (float)luaL_checknumber(L, 2);
    return 0;
}

// --- Methods for AbstractMovementBase ---
int AbstractMovementBaseBinding::_DESTRUCTOR(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    b->_DESTRUCTOR();
    return 0;
}

int AbstractMovementBaseBinding::create(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 _pos;
    readVector3(L, 2, _pos);
    b->create(_pos);
    return 0;
}

int AbstractMovementBaseBinding::_setPositionAndTeleport(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    int floor = (int)luaL_checkinteger(L, 3);
    b->_setPositionAndTeleport(p, floor);
    return 0;
}

int AbstractMovementBaseBinding::_NV__setPositionAndTeleport(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    int floor = (int)luaL_checkinteger(L, 3);
    b->_NV__setPositionAndTeleport(p, floor);
    return 0;
}

int AbstractMovementBaseBinding::_setPositionSimple(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    b->_setPositionSimple(p);
    return 0;
}

int AbstractMovementBaseBinding::_NV__setPositionSimple(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    b->_NV__setPositionSimple(p);
    return 0;
}

int AbstractMovementBaseBinding::faceDirection(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 dir;
    readVector3(L, 2, dir);
    b->faceDirection(dir);
    return 0;
}

int AbstractMovementBaseBinding::_NV_faceDirection(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 dir;
    readVector3(L, 2, dir);
    b->_NV_faceDirection(dir);
    return 0;
}

int AbstractMovementBaseBinding::lookatPosition(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    b->lookatPosition(pos);
    return 0;
}

int AbstractMovementBaseBinding::_NV_lookatPosition(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    b->_NV_lookatPosition(pos);
    return 0;
}

int AbstractMovementBaseBinding::getDestination(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 result = b->getDestination();
    pushVector3(L, result);
    return 1;
}

int AbstractMovementBaseBinding::isProbablyStuck(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    bool result = b->isProbablyStuck();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AbstractMovementBaseBinding::pathOk(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    bool result = b->pathOk();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AbstractMovementBaseBinding::_NV_pathOk(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    bool result = b->_NV_pathOk();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AbstractMovementBaseBinding::pathFailed(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    bool result = b->pathFailed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AbstractMovementBaseBinding::_NV_pathFailed(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    bool result = b->_NV_pathFailed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AbstractMovementBaseBinding::update(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    float _TIME = (float)luaL_checknumber(L, 2);
    b->update(_TIME);
    return 0;
}

int AbstractMovementBaseBinding::_NV_update(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    float _TIME = (float)luaL_checknumber(L, 2);
    b->_NV_update(_TIME);
    return 0;
}

int AbstractMovementBaseBinding::isDestinationReached(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    bool result = b->isDestinationReached();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AbstractMovementBaseBinding::_NV_isDestinationReached(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    bool result = b->_NV_isDestinationReached();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AbstractMovementBaseBinding::amInsideTownWalls(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    int result = b->amInsideTownWalls();
    lua_pushinteger(L, result);
    return 1;
}

int AbstractMovementBaseBinding::_NV_amInsideTownWalls(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    int result = b->_NV_amInsideTownWalls();
    lua_pushinteger(L, result);
    return 1;
}

int AbstractMovementBaseBinding::manualMovement(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 desiredMotion;
    readVector3(L, 2, desiredMotion);
    b->manualMovement(desiredMotion);
    return 0;
}

int AbstractMovementBaseBinding::_NV_manualMovement(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 desiredMotion;
    readVector3(L, 2, desiredMotion);
    b->_NV_manualMovement(desiredMotion);
    return 0;
}

int AbstractMovementBaseBinding::halt(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    b->halt();
    return 0;
}

int AbstractMovementBaseBinding::_NV_halt(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    b->_NV_halt();
    return 0;
}

int AbstractMovementBaseBinding::setRoadDestination(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 dest;
    readVector3(L, 2, dest);
    bool result = b->setRoadDestination(dest);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AbstractMovementBaseBinding::setRoadPreference(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    float w = (float)luaL_checknumber(L, 2);
    b->setRoadPreference(w);
    return 0;
}

int AbstractMovementBaseBinding::setDestination(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    if (lua_istable(L, 2)) {
        Ogre::Vector3 dest;
        readVector3(L, 2, dest);
        UpdatePriority pri = (UpdatePriority)luaL_checkinteger(L, 3);
        bool _a3 = lua_toboolean(L, 4) != 0;
        b->setDestination(dest, pri, _a3);
        return 0;
    }
    else {
        UpdatePriority pri = (UpdatePriority)luaL_checkinteger(L, 3);
        if (Character* who = testObject<Character>(L, 2, CharacterBinding::getMetatableName())) {
            b->setDestination(who, pri);
            return 0;
        }
        else if (Building* building = testObject<Building>(L, 2, BuildingBinding::getMetatableName())) {
            b->setDestination(building, pri);
            return 0;
        }
        else if (RootObjectBase* target = testObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName())) {
            b->setDestination(target, pri);
            return 0;
        }
        else {
            return luaL_error(L, "Invalid arguments to setDestination: expected Vector3 table, Character, Building, or RootObjectBase at parameter 2");
        }
    }
}

int AbstractMovementBaseBinding::_NV_setDestination(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    if (lua_istable(L, 2)) {
        Ogre::Vector3 dest;
        readVector3(L, 2, dest);
        UpdatePriority pri = (UpdatePriority)luaL_checkinteger(L, 3);
        bool _a3 = lua_toboolean(L, 4) != 0;
        b->_NV_setDestination(dest, pri, _a3);
        return 0;
    }
    else {
        UpdatePriority pri = (UpdatePriority)luaL_checkinteger(L, 3);
        if (Character* who = testObject<Character>(L, 2, CharacterBinding::getMetatableName())) {
            b->_NV_setDestination(who, pri);
            return 0;
        }
        else if (Building* building = testObject<Building>(L, 2, BuildingBinding::getMetatableName())) {
            b->_NV_setDestination(building, pri);
            return 0;
        }
        else if (RootObjectBase* target = testObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName())) {
            b->_NV_setDestination(target, pri);
            return 0;
        }
        else {
            return luaL_error(L, "Invalid arguments to _NV_setDestination: expected Vector3 table, Character, Building, or RootObjectBase at parameter 2");
        }
    }
}

int AbstractMovementBaseBinding::setDesiredSpeed(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    double val = luaL_checknumber(L, 2);
    if (val >= 0.0 && val <= 4.0 && val == (int)val) {
        b->setDesiredSpeed((MoveSpeed)(int)val);
    }
    else {
        b->setDesiredSpeed((float)val);
    }
    return 0;
}

int AbstractMovementBaseBinding::setDesiredSpeedOrders(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    double val = luaL_checknumber(L, 2);
    if (val >= 0.0 && val <= 4.0 && val == (int)val) {
        b->setDesiredSpeedOrders((MoveSpeed)(int)val);
    }
    else {
        b->setDesiredSpeedOrders((float)val);
    }
    return 0;
}


int AbstractMovementBaseBinding::_NV_setDesiredSpeed(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    MoveSpeed speed = (MoveSpeed)luaL_checkinteger(L, 2);
    b->_NV_setDesiredSpeed(speed);
    return 0;
}

int AbstractMovementBaseBinding::setStandardWalkSpeed(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    float s = (float)luaL_checknumber(L, 2);
    b->setStandardWalkSpeed(s);
    return 0;
}

int AbstractMovementBaseBinding::getStandardWalkSpeed(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    float result = b->getStandardWalkSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int AbstractMovementBaseBinding::restoreDesiredSpeed(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    b->restoreDesiredSpeed();
    return 0;
}

int AbstractMovementBaseBinding::setMaxSpeed(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    float ms = (float)luaL_checknumber(L, 2);
    b->setMaxSpeed(ms);
    return 0;
}

int AbstractMovementBaseBinding::getMaxSpeed(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    float result = b->getMaxSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int AbstractMovementBaseBinding::isCurrentlyMoving(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    bool result = b->isCurrentlyMoving();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AbstractMovementBaseBinding::getCurrentSpeed(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    float result = b->getCurrentSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int AbstractMovementBaseBinding::getCurrentMotion(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    Ogre::Vector3 result = b->getCurrentMotion();
    pushVector3(L, result);
    return 1;
}

int AbstractMovementBaseBinding::getCurrentSpeedRelativeToMax01(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    float result = b->getCurrentSpeedRelativeToMax01();
    lua_pushnumber(L, result);
    return 1;
}

int AbstractMovementBaseBinding::getSpeedOrders(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    MoveSpeed result = b->getSpeedOrders();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int AbstractMovementBaseBinding::leaveSpeedGroup(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");

    b->leaveSpeedGroup();
    return 0;
}

static int AbstractMovementBase_getHandle(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    hand result = b->getHandle();
    handBinding::push(L, result);
    return 1;
}

static int AbstractMovementBase__NV_getHandle(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    hand result = b->_NV_getHandle();
    handBinding::push(L, result);
    return 1;
}

static int AbstractMovementBase_getPosition(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    const Ogre::Vector3& result = b->getPosition();
    pushVector3(L, result);
    return 1;
}

static int AbstractMovementBase__NV_getPosition(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    const Ogre::Vector3& result = b->_NV_getPosition();
    pushVector3(L, result);
    return 1;
}

static int AbstractMovementBase_getFacingDirection(lua_State* L)
{
    AbstractMovementBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "AbstractMovementBase is nil");
    const Ogre::Vector3& result = b->getFacingDirection();
    pushVector3(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 142: AbstractMovementBase* _CONSTRUCTOR(...) - unsupported return type
  line 185: RoadFollower* extractRoadFollower(...) - unsupported return type
  line 186: void setCurrentRoadFollower(...) - unsupported arg type
  line 187: void setPatrolInput(...) - unsupported arg type
  line 188: void _NV_setPatrolInput(...) - unsupported arg type
  line 222: NxControllerAction onShapeHit(...) - unsupported return type
  line 223: NxControllerAction _NV_onShapeHit(...) - unsupported return type
  line 224: NxControllerAction onControllerHit(...) - unsupported return type
  line 225: NxControllerAction _NV_onControllerHit(...) - unsupported return type
*/

int AbstractMovementBaseBinding::gc(lua_State* L)
{
    // None needed as this is a raw pointer container without lua-owned GC for this wrapper pattern usually
    return 0;
}

int AbstractMovementBaseBinding::tostring(lua_State* L)
{
    char buf[64];
    _snprintf(buf, sizeof(buf), "%s: %p", getMetatableName(), getB(L, 1));
    lua_pushstring(L, buf);
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
        { "_DESTRUCTOR", AbstractMovementBaseBinding::_DESTRUCTOR },
        { "create", AbstractMovementBaseBinding::create },
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
        { "setDestination", AbstractMovementBaseBinding::setDestination },
        { "_NV_setDestination", AbstractMovementBaseBinding::_NV_setDestination },
        { "setDesiredSpeed", AbstractMovementBaseBinding::setDesiredSpeed },
        { "setDesiredSpeedOrders", AbstractMovementBaseBinding::setDesiredSpeedOrders },
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
        { "getHandle", AbstractMovementBase_getHandle },
        { "_NV_getHandle", AbstractMovementBase__NV_getHandle },
        { "getPosition", AbstractMovementBase_getPosition },
        { "_NV_getPosition", AbstractMovementBase__NV_getPosition },
        { "getFacingDirection", AbstractMovementBase_getFacingDirection },
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
    lua_pushcfunction(L, AbstractMovementBase_get_officiallyStopped);
    lua_setfield(L, -2, "officiallyStopped");
    lua_pushcfunction(L, AbstractMovementBase_get_speedGroup);
    lua_setfield(L, -2, "speedGroup");
    lua_pushcfunction(L, AbstractMovementBase_get_speedOrders);
    lua_setfield(L, -2, "speedOrders");
    lua_pushcfunction(L, AbstractMovementBase_get_currentlyMoving);
    lua_setfield(L, -2, "currentlyMoving");
    lua_pushcfunction(L, AbstractMovementBase_get_positionSmoother);
    lua_setfield(L, -2, "positionSmoother");
    lua_pushcfunction(L, AbstractMovementBase_get_currentMotion);
    lua_setfield(L, -2, "currentMotion");
    lua_pushcfunction(L, AbstractMovementBase_get_maxSpeed);
    lua_setfield(L, -2, "maxSpeed");
    lua_pushcfunction(L, AbstractMovementBase_get_currentSpeed);
    lua_setfield(L, -2, "currentSpeed");
    lua_pushcfunction(L, AbstractMovementBase_get_desiredSpeed);
    lua_setfield(L, -2, "desiredSpeed");
    lua_pushcfunction(L, AbstractMovementBase_get_walkSpeed);
    lua_setfield(L, -2, "walkSpeed");
    lua_pushcfunction(L, AbstractMovementBase_get_pos);
    lua_setfield(L, -2, "pos");
    lua_pushcfunction(L, AbstractMovementBase_get_direction);
    lua_setfield(L, -2, "direction");
    lua_pushcfunction(L, AbstractMovementBase_get_destination);
    lua_setfield(L, -2, "destination");
    lua_pushcfunction(L, AbstractMovementBase_get_pathDestination);
    lua_setfield(L, -2, "pathDestination");
    lua_pushcfunction(L, AbstractMovementBase_get_roadFollower);
    lua_setfield(L, -2, "roadFollower");
    lua_pushcfunction(L, AbstractMovementBase_get_roadWeight);
    lua_setfield(L, -2, "roadWeight");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, AbstractMovementBase_set_officiallyStopped);
    lua_setfield(L, -2, "officiallyStopped");
    lua_pushcfunction(L, AbstractMovementBase_set_speedGroup);
    lua_setfield(L, -2, "speedGroup");
    lua_pushcfunction(L, AbstractMovementBase_set_speedOrders);
    lua_setfield(L, -2, "speedOrders");
    lua_pushcfunction(L, AbstractMovementBase_set_currentlyMoving);
    lua_setfield(L, -2, "currentlyMoving");
    lua_pushcfunction(L, AbstractMovementBase_set_positionSmoother);
    lua_setfield(L, -2, "positionSmoother");
    lua_pushcfunction(L, AbstractMovementBase_set_currentMotion);
    lua_setfield(L, -2, "currentMotion");
    lua_pushcfunction(L, AbstractMovementBase_set_maxSpeed);
    lua_setfield(L, -2, "maxSpeed");
    lua_pushcfunction(L, AbstractMovementBase_set_currentSpeed);
    lua_setfield(L, -2, "currentSpeed");
    lua_pushcfunction(L, AbstractMovementBase_set_desiredSpeed);
    lua_setfield(L, -2, "desiredSpeed");
    lua_pushcfunction(L, AbstractMovementBase_set_walkSpeed);
    lua_setfield(L, -2, "walkSpeed");
    lua_pushcfunction(L, AbstractMovementBase_set_pos);
    lua_setfield(L, -2, "pos");
    lua_pushcfunction(L, AbstractMovementBase_set_direction);
    lua_setfield(L, -2, "direction");
    lua_pushcfunction(L, AbstractMovementBase_set_destination);
    lua_setfield(L, -2, "destination");
    lua_pushcfunction(L, AbstractMovementBase_set_pathDestination);
    lua_setfield(L, -2, "pathDestination");
    lua_pushcfunction(L, AbstractMovementBase_set_roadFollower);
    lua_setfield(L, -2, "roadFollower");
    lua_pushcfunction(L, AbstractMovementBase_set_roadWeight);
    lua_setfield(L, -2, "roadWeight");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua