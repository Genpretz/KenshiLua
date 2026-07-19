#include "pch.h"
#include "Bindings/FactionBinding.h"

#include <kenshi/Building/DoorStuff.h>
#include "DoorStuffBinding.h"
#include "BuildingBinding.h"
#include "GatewayBuildingBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static DoorStuff* getInstance(lua_State* L, int idx)
{
    return checkObject<DoorStuff>(L, idx, DoorStuffBinding::getMetatableName());
}

// --- Getters for DoorStuff ---
static int DoorStuff_get_isSetupComplete(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    lua_pushboolean(L, instance->isSetupComplete ? 1 : 0);
    return 1;
}

static int DoorStuff_get_parent(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    return pushObject<Building>(L, instance->parent, BuildingBinding::getMetatableName());
}

static int DoorStuff_get_doorLock(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    DoorLock* result = instance->doorLock;
    if (result) lua_pushlightuserdata(L, (void*)result); else lua_pushnil(L);
    return 1;
}

static int DoorStuff_get_gateCode(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    lua_pushinteger(L, instance->gateCode);
    return 1;
}

static int DoorStuff_get_doorOpenAmount(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    lua_pushnumber(L, instance->doorOpenAmount);
    return 1;
}

static int DoorStuff_get_state(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    lua_pushinteger(L, (lua_Integer)instance->state);
    return 1;
}

static int DoorStuff_get_wantsToLock(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    lua_pushboolean(L, instance->wantsToLock ? 1 : 0);
    return 1;
}

static int DoorStuff_get_doorSpeed(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    lua_pushnumber(L, instance->doorSpeed);
    return 1;
}

static int DoorStuff_get_doorDistance(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    lua_pushnumber(L, instance->doorDistance);
    return 1;
}

static int DoorStuff_get_doorMoveAxis(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    lua_pushinteger(L, instance->doorMoveAxis);
    return 1;
}

static int DoorStuff_get_doorComesOut(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    lua_pushnumber(L, instance->doorComesOut);
    return 1;
}

static int DoorStuff_get_nodeClosedPosition(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    pushVector3(L, instance->nodeClosedPosition);
    return 1;
}

static int DoorStuff_get_actorClosedPosition(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    pushVector3(L, instance->actorClosedPosition);
    return 1;
}

static int DoorStuff_get_doorClosedPosition(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    pushVector3(L, instance->doorClosedPosition);
    return 1;
}

static int DoorStuff_get_doorClosedPositionOut(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    pushVector3(L, instance->doorClosedPositionOut);
    return 1;
}

static int DoorStuff_get_doorClosedPositionIn(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    pushVector3(L, instance->doorClosedPositionIn);
    return 1;
}

static int DoorStuff_get_axisH(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    pushVector3(L, instance->axisH);
    return 1;
}

static int DoorStuff_get_axisF(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    pushVector3(L, instance->axisF);
    return 1;
}

static int DoorStuff_get__isBroken(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    lua_pushboolean(L, instance->_isBroken ? 1 : 0);
    return 1;
}

// --- Setters for DoorStuff ---
static int DoorStuff_set_isSetupComplete(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    instance->isSetupComplete = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DoorStuff_set_parent(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    return luaL_error(L, "Read-only or unsupported setter type for parent");
}

static int DoorStuff_set_doorLock(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    return luaL_error(L, "Read-only or unsupported setter type for doorLock");
}

static int DoorStuff_set_gateCode(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    instance->gateCode = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int DoorStuff_set_doorOpenAmount(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    instance->doorOpenAmount = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DoorStuff_set_state(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    instance->state = (DoorState)luaL_checkinteger(L, 2);
    return 0;
}

static int DoorStuff_set_wantsToLock(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    instance->wantsToLock = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DoorStuff_set_doorSpeed(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    instance->doorSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DoorStuff_set_doorDistance(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    instance->doorDistance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DoorStuff_set_doorMoveAxis(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    instance->doorMoveAxis = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int DoorStuff_set_doorComesOut(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    instance->doorComesOut = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DoorStuff_set_nodeClosedPosition(lua_State* L)
{
    return luaL_error(L, "Read-only property nodeClosedPosition");
}

static int DoorStuff_set_actorClosedPosition(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    readVector3(L, 2, instance->actorClosedPosition);
    return 0;
}

static int DoorStuff_set_doorClosedPosition(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    readVector3(L, 2, instance->doorClosedPosition);
    return 0;
}

static int DoorStuff_set_doorClosedPositionOut(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    readVector3(L, 2, instance->doorClosedPositionOut);
    return 0;
}

static int DoorStuff_set_doorClosedPositionIn(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    readVector3(L, 2, instance->doorClosedPositionIn);
    return 0;
}

static int DoorStuff_set_axisH(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    readVector3(L, 2, instance->axisH);
    return 0;
}

static int DoorStuff_set_axisF(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    readVector3(L, 2, instance->axisF);
    return 0;
}

static int DoorStuff_set__isBroken(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");
    instance->_isBroken = lua_toboolean(L, 2) != 0;
    return 0;
}

// --- Methods for DoorStuff
int DoorStuffBinding::_DESTRUCTOR(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int DoorStuffBinding::setupPhysicalUT(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    bool result = instance->setupPhysicalUT();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::getFaction(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    Faction* result = instance->getFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int DoorStuffBinding::_NV_getFaction(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    Faction* result = instance->_NV_getFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int DoorStuffBinding::_getPhysActorUT(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    NxActor* result = instance->_getPhysActorUT();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int DoorStuffBinding::needsUpdate(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    bool result = instance->needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::_NV_needsUpdate(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    bool result = instance->_NV_needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::getGateCode(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    unsigned short result = instance->getGateCode();
    lua_pushinteger(L, result);
    return 1;
}

int DoorStuffBinding::setGateCode(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    int code = (int)luaL_checkinteger(L, 2);
    instance->setGateCode(code);
    return 0;
}

int DoorStuffBinding::isGate(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    GatewayBuilding* result = instance->isGate();
    return pushObject<GatewayBuilding>(L, result, GatewayBuildingBinding::getMetatableName());
}

int DoorStuffBinding::_NV_isGate(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    GatewayBuilding* result = instance->_NV_isGate();
    return pushObject<GatewayBuilding>(L, result, GatewayBuildingBinding::getMetatableName());
}

int DoorStuffBinding::isPublic(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    bool result = instance->isPublic();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::_NV_isPublic(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    bool result = instance->_NV_isPublic();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::getMouseCursor(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    CursorType result = instance->getMouseCursor();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int DoorStuffBinding::_NV_getMouseCursor(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    CursorType result = instance->_NV_getMouseCursor();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int DoorStuffBinding::getDefaultTask(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    TaskType result = instance->getDefaultTask();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int DoorStuffBinding::_NV_getDefaultTask(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    TaskType result = instance->_NV_getDefaultTask();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int DoorStuffBinding::getReachRange(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    float result = instance->getReachRange();
    lua_pushnumber(L, result);
    return 1;
}

int DoorStuffBinding::_NV_getReachRange(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    float result = instance->_NV_getReachRange();
    lua_pushnumber(L, result);
    return 1;
}

int DoorStuffBinding::getDoor(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    DoorStuff* result = instance->getDoor();
    return pushObject<DoorStuff>(L, result, DoorStuffBinding::getMetatableName());
}

int DoorStuffBinding::_NV_getDoor(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    DoorStuff* result = instance->_NV_getDoor();
    return pushObject<DoorStuff>(L, result, DoorStuffBinding::getMetatableName());
}

int DoorStuffBinding::getName(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    std::string result = instance->getName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int DoorStuffBinding::_NV_getName(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    std::string result = instance->_NV_getName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int DoorStuffBinding::getDoorLock(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    DoorLock* result = instance->getDoorLock();
    if (result) lua_pushlightuserdata(L, (void*)result); else lua_pushnil(L);
    return 1;
}

int DoorStuffBinding::_NV_getDoorLock(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    DoorLock* result = instance->_NV_getDoorLock();
    if (result) lua_pushlightuserdata(L, (void*)result); else lua_pushnil(L);
    return 1;
}

int DoorStuffBinding::hasDoorLock(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    bool result = instance->hasDoorLock();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::_NV_hasDoorLock(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    bool result = instance->_NV_hasDoorLock();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::updateGateCodeState(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    instance->updateGateCodeState();
    return 0;
}

int DoorStuffBinding::onBuildingLoaded(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    instance->onBuildingLoaded();
    return 0;
}

int DoorStuffBinding::_NV_onBuildingLoaded(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    instance->_NV_onBuildingLoaded();
    return 0;
}

int DoorStuffBinding::setDoorOpenAmount(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool forceUnsafe = lua_toboolean(L, 3) != 0;
    instance->setDoorOpenAmount(amount, forceUnsafe);
    return 0;
}

int DoorStuffBinding::isBroken(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    bool result = instance->isBroken();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::_NV_isBroken(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    bool result = instance->_NV_isBroken();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::setBroken(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setBroken(on);
    return 0;
}

int DoorStuffBinding::_NV_setBroken(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_setBroken(on);
    return 0;
}

int DoorStuffBinding::isDisabled(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    bool result = instance->isDisabled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::_NV_isDisabled(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    bool result = instance->_NV_isDisabled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::isLocked(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    bool result = instance->isLocked();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::lockDoor(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    instance->lockDoor();
    return 0;
}

int DoorStuffBinding::unlockDoor(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    instance->unlockDoor();
    return 0;
}

int DoorStuffBinding::getDoorOpenAmount(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    float result = instance->getDoorOpenAmount();
    lua_pushnumber(L, result);
    return 1;
}

int DoorStuffBinding::setDoorState(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    DoorState what = (DoorState)luaL_checkinteger(L, 2);
    instance->setDoorState(what);
    return 0;
}

int DoorStuffBinding::getDoorState(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    DoorState result = instance->getDoorState();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int DoorStuffBinding::openDoor(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    bool result = instance->openDoor();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::closeDoor(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    bool result = instance->closeDoor();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::_forceDoorClosedUT(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    bool result = instance->_forceDoorClosedUT();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::_forceDoorOpenUT(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    bool result = instance->_forceDoorOpenUT();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::update(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    instance->update();
    return 0;
}

int DoorStuffBinding::_NV_update(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    instance->_NV_update();
    return 0;
}

int DoorStuffBinding::getDoorPosOutside_extraFarOut(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    float mult = (float)luaL_checknumber(L, 2);
    Ogre::Vector3 result = instance->getDoorPosOutside_extraFarOut(mult);
    pushVector3(L, result);
    return 1;
}

int DoorStuffBinding::getDoorPosInside_extraFarIn(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    float mult = (float)luaL_checknumber(L, 2);
    Ogre::Vector3 result = instance->getDoorPosInside_extraFarIn(mult);
    pushVector3(L, result);
    return 1;
}

int DoorStuffBinding::isOpen(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    bool result = instance->isOpen();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::doorStuff(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    DoorStuff* result = instance->doorStuff();
    return pushObject<DoorStuff>(L, result, DoorStuffBinding::getMetatableName());
}

int DoorStuffBinding::_NV_doorStuff(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    DoorStuff* result = instance->_NV_doorStuff();
    return pushObject<DoorStuff>(L, result, DoorStuffBinding::getMetatableName());
}

int DoorStuffBinding::doorParentBuilding(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    Building* result = instance->doorParentBuilding();
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}

int DoorStuffBinding::_NV_doorParentBuilding(lua_State* L)
{
    DoorStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DoorStuff is nil");

    Building* result = instance->_NV_doorParentBuilding();
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}

/*
Skipped methods needing manual binding:
  line 32: DoorStuff* _CONSTRUCTOR(...) - unsupported arg type
  line 39: void getGUIData(...) - unsupported arg type
  line 40: void _NV_getGUIData(...) - unsupported arg type
  line 53: void setHandle(...) - unsupported arg type
  line 54: void _NV_setHandle(...) - unsupported arg type
  line 65: HitMaterialType hitByMeleeAttack(...) - unsupported arg type
  line 66: HitMaterialType _NV_hitByMeleeAttack(...) - unsupported arg type
  line 67: const Ogre::Vector3& getActorClosedPosition(...) - reference return type
  line 109: const Ogre::Vector3& getDoorPosition(...) - reference return type
  line 110: const Ogre::Vector3& getDoorPosOutside(...) - reference return type
  line 112: const Ogre::Vector3& getDoorPosInside(...) - reference return type
  line 115: void openButton(...) - unsupported arg type
  line 116: void lockButton(...) - unsupported arg type
  line 117: void _serialise(...) - unsupported arg type
  line 118: void _NV__serialise(...) - unsupported arg type
  line 119: void _loadFromSerialise(...) - unsupported arg type
  line 120: void _NV__loadFromSerialise(...) - unsupported arg type
*/

int DoorStuffBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DoorStuffBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DoorStuff object");
    return 1;
}

void DoorStuffBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DoorStuffBinding::gc },
        { "__tostring", DoorStuffBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", DoorStuffBinding::_DESTRUCTOR },
        { "setupPhysicalUT", DoorStuffBinding::setupPhysicalUT },
        { "getFaction", DoorStuffBinding::getFaction },
        { "_NV_getFaction", DoorStuffBinding::_NV_getFaction },
        { "_getPhysActorUT", DoorStuffBinding::_getPhysActorUT },
        { "needsUpdate", DoorStuffBinding::needsUpdate },
        { "_NV_needsUpdate", DoorStuffBinding::_NV_needsUpdate },
        { "getGateCode", DoorStuffBinding::getGateCode },
        { "setGateCode", DoorStuffBinding::setGateCode },
        { "isGate", DoorStuffBinding::isGate },
        { "_NV_isGate", DoorStuffBinding::_NV_isGate },
        { "isPublic", DoorStuffBinding::isPublic },
        { "_NV_isPublic", DoorStuffBinding::_NV_isPublic },
        { "getMouseCursor", DoorStuffBinding::getMouseCursor },
        { "_NV_getMouseCursor", DoorStuffBinding::_NV_getMouseCursor },
        { "getDefaultTask", DoorStuffBinding::getDefaultTask },
        { "_NV_getDefaultTask", DoorStuffBinding::_NV_getDefaultTask },
        { "getReachRange", DoorStuffBinding::getReachRange },
        { "_NV_getReachRange", DoorStuffBinding::_NV_getReachRange },
        { "getDoor", DoorStuffBinding::getDoor },
        { "_NV_getDoor", DoorStuffBinding::_NV_getDoor },
        { "getName", DoorStuffBinding::getName },
        { "_NV_getName", DoorStuffBinding::_NV_getName },
        { "getDoorLock", DoorStuffBinding::getDoorLock },
        { "_NV_getDoorLock", DoorStuffBinding::_NV_getDoorLock },
        { "hasDoorLock", DoorStuffBinding::hasDoorLock },
        { "_NV_hasDoorLock", DoorStuffBinding::_NV_hasDoorLock },
        { "updateGateCodeState", DoorStuffBinding::updateGateCodeState },
        { "onBuildingLoaded", DoorStuffBinding::onBuildingLoaded },
        { "_NV_onBuildingLoaded", DoorStuffBinding::_NV_onBuildingLoaded },
        { "setDoorOpenAmount", DoorStuffBinding::setDoorOpenAmount },
        { "isBroken", DoorStuffBinding::isBroken },
        { "_NV_isBroken", DoorStuffBinding::_NV_isBroken },
        { "setBroken", DoorStuffBinding::setBroken },
        { "_NV_setBroken", DoorStuffBinding::_NV_setBroken },
        { "isDisabled", DoorStuffBinding::isDisabled },
        { "_NV_isDisabled", DoorStuffBinding::_NV_isDisabled },
        { "isLocked", DoorStuffBinding::isLocked },
        { "lockDoor", DoorStuffBinding::lockDoor },
        { "unlockDoor", DoorStuffBinding::unlockDoor },
        { "getDoorOpenAmount", DoorStuffBinding::getDoorOpenAmount },
        { "setDoorState", DoorStuffBinding::setDoorState },
        { "getDoorState", DoorStuffBinding::getDoorState },
        { "openDoor", DoorStuffBinding::openDoor },
        { "closeDoor", DoorStuffBinding::closeDoor },
        { "_forceDoorClosedUT", DoorStuffBinding::_forceDoorClosedUT },
        { "_forceDoorOpenUT", DoorStuffBinding::_forceDoorOpenUT },
        { "update", DoorStuffBinding::update },
        { "_NV_update", DoorStuffBinding::_NV_update },
        { "getDoorPosOutside_extraFarOut", DoorStuffBinding::getDoorPosOutside_extraFarOut },
        { "getDoorPosInside_extraFarIn", DoorStuffBinding::getDoorPosInside_extraFarIn },
        { "isOpen", DoorStuffBinding::isOpen },
        { "doorStuff", DoorStuffBinding::doorStuff },
        { "_NV_doorStuff", DoorStuffBinding::_NV_doorStuff },
        { "doorParentBuilding", DoorStuffBinding::doorParentBuilding },
        { "_NV_doorParentBuilding", DoorStuffBinding::_NV_doorParentBuilding },
        { 0, 0 }
    };

    registerClass(
        L, 
        DoorStuffBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DoorStuffBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, DoorStuff_get_isSetupComplete);
    lua_setfield(L, -2, "isSetupComplete");
    lua_pushcfunction(L, DoorStuff_get_parent);
    lua_setfield(L, -2, "parent");
    lua_pushcfunction(L, DoorStuff_get_doorLock);
    lua_setfield(L, -2, "doorLock");
    lua_pushcfunction(L, DoorStuff_get_gateCode);
    lua_setfield(L, -2, "gateCode");
    lua_pushcfunction(L, DoorStuff_get_doorOpenAmount);
    lua_setfield(L, -2, "doorOpenAmount");
    lua_pushcfunction(L, DoorStuff_get_state);
    lua_setfield(L, -2, "state");
    lua_pushcfunction(L, DoorStuff_get_wantsToLock);
    lua_setfield(L, -2, "wantsToLock");
    lua_pushcfunction(L, DoorStuff_get_doorSpeed);
    lua_setfield(L, -2, "doorSpeed");
    lua_pushcfunction(L, DoorStuff_get_doorDistance);
    lua_setfield(L, -2, "doorDistance");
    lua_pushcfunction(L, DoorStuff_get_doorMoveAxis);
    lua_setfield(L, -2, "doorMoveAxis");
    lua_pushcfunction(L, DoorStuff_get_doorComesOut);
    lua_setfield(L, -2, "doorComesOut");
    lua_pushcfunction(L, DoorStuff_get_nodeClosedPosition);
    lua_setfield(L, -2, "nodeClosedPosition");
    lua_pushcfunction(L, DoorStuff_get_actorClosedPosition);
    lua_setfield(L, -2, "actorClosedPosition");
    lua_pushcfunction(L, DoorStuff_get_doorClosedPosition);
    lua_setfield(L, -2, "doorClosedPosition");
    lua_pushcfunction(L, DoorStuff_get_doorClosedPositionOut);
    lua_setfield(L, -2, "doorClosedPositionOut");
    lua_pushcfunction(L, DoorStuff_get_doorClosedPositionIn);
    lua_setfield(L, -2, "doorClosedPositionIn");
    lua_pushcfunction(L, DoorStuff_get_axisH);
    lua_setfield(L, -2, "axisH");
    lua_pushcfunction(L, DoorStuff_get_axisF);
    lua_setfield(L, -2, "axisF");
    lua_pushcfunction(L, DoorStuff_get__isBroken);
    lua_setfield(L, -2, "_isBroken");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, DoorStuff_set_isSetupComplete);
    lua_setfield(L, -2, "isSetupComplete");
    lua_pushcfunction(L, DoorStuff_set_parent);
    lua_setfield(L, -2, "parent");
    lua_pushcfunction(L, DoorStuff_set_doorLock);
    lua_setfield(L, -2, "doorLock");
    lua_pushcfunction(L, DoorStuff_set_gateCode);
    lua_setfield(L, -2, "gateCode");
    lua_pushcfunction(L, DoorStuff_set_doorOpenAmount);
    lua_setfield(L, -2, "doorOpenAmount");
    lua_pushcfunction(L, DoorStuff_set_state);
    lua_setfield(L, -2, "state");
    lua_pushcfunction(L, DoorStuff_set_wantsToLock);
    lua_setfield(L, -2, "wantsToLock");
    lua_pushcfunction(L, DoorStuff_set_doorSpeed);
    lua_setfield(L, -2, "doorSpeed");
    lua_pushcfunction(L, DoorStuff_set_doorDistance);
    lua_setfield(L, -2, "doorDistance");
    lua_pushcfunction(L, DoorStuff_set_doorMoveAxis);
    lua_setfield(L, -2, "doorMoveAxis");
    lua_pushcfunction(L, DoorStuff_set_doorComesOut);
    lua_setfield(L, -2, "doorComesOut");
    lua_pushcfunction(L, DoorStuff_set_nodeClosedPosition);
    lua_setfield(L, -2, "nodeClosedPosition");
    lua_pushcfunction(L, DoorStuff_set_actorClosedPosition);
    lua_setfield(L, -2, "actorClosedPosition");
    lua_pushcfunction(L, DoorStuff_set_doorClosedPosition);
    lua_setfield(L, -2, "doorClosedPosition");
    lua_pushcfunction(L, DoorStuff_set_doorClosedPositionOut);
    lua_setfield(L, -2, "doorClosedPositionOut");
    lua_pushcfunction(L, DoorStuff_set_doorClosedPositionIn);
    lua_setfield(L, -2, "doorClosedPositionIn");
    lua_pushcfunction(L, DoorStuff_set_axisH);
    lua_setfield(L, -2, "axisH");
    lua_pushcfunction(L, DoorStuff_set_axisF);
    lua_setfield(L, -2, "axisF");
    lua_pushcfunction(L, DoorStuff_set__isBroken);
    lua_setfield(L, -2, "_isBroken");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Building
    // setMetatableParent(L, DoorStuffBinding::getMetatableName(), BuildingBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
