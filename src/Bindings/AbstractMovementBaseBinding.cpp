#include "pch.h"
#include "kenshi\CharMovement.h"
#include "AbstractMovementBaseBinding.h"
#include "Lua/BindingHelpers.h"

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
    // TODO: Unsupported type for speedGroup (Ogre::SharedPtr<SpeedGroup>)
    lua_pushnil(L);
    return 1;
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
    // TODO: Unsupported type for positionSmoother (MedianFilter2DVector)
    lua_pushnil(L);
    return 1;
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
    lua_pushnil(L);
    return 1;
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
    return luaL_error(L, "Read-only or unsupported setter type for speedGroup");
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
    return luaL_error(L, "Read-only or unsupported setter type for positionSmoother");
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

/*
Skipped methods needing manual binding:
  line 142: AbstractMovementBase* _CONSTRUCTOR(...) - unsupported return type
  line 146: hand getHandle(...) - unsupported return type
  line 147: hand _NV_getHandle(...) - unsupported return type
  line 156: const Ogre::Vector3& getPosition(...) - reference return type
  line 157: const Ogre::Vector3& _NV_getPosition(...) - reference return type
  line 158: const Ogre::Vector3& getFacingDirection(...) - reference return type
  line 173: void setDestination(...) - overloaded method
  line 174: void _NV_setDestination(...) - overloaded method
  line 175: void setDestination(...) - overloaded method
  line 176: void _NV_setDestination(...) - overloaded method
  line 177: void setDestination(...) - overloaded method
  line 178: void _NV_setDestination(...) - overloaded method
  line 179: void setDestination(...) - overloaded method
  line 180: void _NV_setDestination(...) - overloaded method
  line 185: RoadFollower* extractRoadFollower(...) - unsupported return type
  line 186: void setCurrentRoadFollower(...) - unsupported arg type
  line 187: void setPatrolInput(...) - unsupported arg type
  line 188: void _NV_setPatrolInput(...) - unsupported arg type
  line 189: void setDesiredSpeed(...) - overloaded method
  line 191: void setDesiredSpeed(...) - overloaded method
  line 192: void setDesiredSpeedOrders(...) - overloaded method
  line 193: void setDesiredSpeedOrders(...) - overloaded method
  line 222: NxControllerAction onShapeHit(...) - unsupported return type
  line 223: NxControllerAction _NV_onShapeHit(...) - unsupported return type
  line 224: NxControllerAction onControllerHit(...) - unsupported return type
  line 225: NxControllerAction _NV_onControllerHit(...) - unsupported return type
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