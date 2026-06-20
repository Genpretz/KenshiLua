#include "pch.h"
#include "Bindings/DoorStuffBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/DoorStuff.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static DoorStuff* getS(lua_State* L, int idx)
{
    return checkObject<DoorStuff>(L, idx, DoorStuffBinding::getMetatableName());
}

int DoorStuffBinding::gc(lua_State* L) { return noopGc(L); }

int DoorStuffBinding::tostring(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int DoorStuffBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, DoorStuffBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    DoorStuff* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "isSetupComplete") == 0) { lua_pushboolean(L, s->isSetupComplete ? 1 : 0); return 1; }
    if (strcmp(key, "parent") == 0) { return pushObject<Building>(L, s->parent, BuildingBinding::getMetatableName()); }
    // TODO DoorLock* doorLock; unsupported __index type from header line 73
    if (strcmp(key, "gateCode") == 0) { lua_pushinteger(L, s->gateCode); return 1; }
    if (strcmp(key, "doorOpenAmount") == 0) { lua_pushnumber(L, s->doorOpenAmount); return 1; }
    // TODO DoorState state; unsupported __index type from header line 76
    if (strcmp(key, "wantsToLock") == 0) { lua_pushboolean(L, s->wantsToLock ? 1 : 0); return 1; }
    if (strcmp(key, "doorSpeed") == 0) { lua_pushnumber(L, s->doorSpeed); return 1; }
    if (strcmp(key, "doorDistance") == 0) { lua_pushnumber(L, s->doorDistance); return 1; }
    if (strcmp(key, "doorMoveAxis") == 0) { lua_pushinteger(L, s->doorMoveAxis); return 1; }
    if (strcmp(key, "doorComesOut") == 0) { lua_pushnumber(L, s->doorComesOut); return 1; }
    // TODO const Ogre::Vector3 nodeClosedPosition; unsupported __index type from header line 82
    // TODO Ogre::Vector3 actorClosedPosition; unsupported __index type from header line 83
    // TODO Ogre::Vector3 doorClosedPosition; unsupported __index type from header line 84
    // TODO Ogre::Vector3 doorClosedPositionOut; unsupported __index type from header line 85
    // TODO Ogre::Vector3 doorClosedPositionIn; unsupported __index type from header line 86
    // TODO Ogre::Vector3 axisH; unsupported __index type from header line 87
    // TODO Ogre::Vector3 axisF; unsupported __index type from header line 88
    if (strcmp(key, "_isBroken") == 0) { lua_pushboolean(L, s->_isBroken ? 1 : 0); return 1; }

    lua_pushnil(L);
    return 1;
}

int DoorStuffBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    if (strcmp(key, "isSetupComplete") == 0) { s->isSetupComplete = lua_toboolean(L, 3) != 0; return 0; }
    // TODO Building* parent; unsupported __newindex type from header line 72
    // TODO DoorLock* doorLock; unsupported __newindex type from header line 73
    if (strcmp(key, "gateCode") == 0) { s->gateCode = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "doorOpenAmount") == 0) { s->doorOpenAmount = (float)luaL_checknumber(L, 3); return 0; }
    // TODO DoorState state; unsupported __newindex type from header line 76
    if (strcmp(key, "wantsToLock") == 0) { s->wantsToLock = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "doorSpeed") == 0) { s->doorSpeed = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "doorDistance") == 0) { s->doorDistance = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "doorMoveAxis") == 0) { s->doorMoveAxis = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "doorComesOut") == 0) { s->doorComesOut = (float)luaL_checknumber(L, 3); return 0; }
    // TODO const Ogre::Vector3 nodeClosedPosition; unsupported __newindex type from header line 82
    // TODO Ogre::Vector3 actorClosedPosition; unsupported __newindex type from header line 83
    // TODO Ogre::Vector3 doorClosedPosition; unsupported __newindex type from header line 84
    // TODO Ogre::Vector3 doorClosedPositionOut; unsupported __newindex type from header line 85
    // TODO Ogre::Vector3 doorClosedPositionIn; unsupported __newindex type from header line 86
    // TODO Ogre::Vector3 axisH; unsupported __newindex type from header line 87
    // TODO Ogre::Vector3 axisF; unsupported __newindex type from header line 88
    if (strcmp(key, "_isBroken") == 0) { s->_isBroken = lua_toboolean(L, 3) != 0; return 0; }

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int DoorStuffBinding::_DESTRUCTOR(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    s->_DESTRUCTOR();
    return 0;
}

int DoorStuffBinding::setupPhysicalUT(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    bool result = s->setupPhysicalUT();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::getFaction(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    Faction result = s->getFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int DoorStuffBinding::_NV_getFaction(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    Faction result = s->_NV_getFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int DoorStuffBinding::needsUpdate(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    bool result = s->needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::_NV_needsUpdate(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    bool result = s->_NV_needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::getGateCode(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    unsigned short result = s->getGateCode();
    lua_pushinteger(L, result);
    return 1;
}

int DoorStuffBinding::setGateCode(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    int code = (int)luaL_checkinteger(L, 2);
    s->setGateCode(code);
    return 0;
}

int DoorStuffBinding::isPublic(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    bool result = s->isPublic();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::_NV_isPublic(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    bool result = s->_NV_isPublic();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::getReachRange(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    float result = s->getReachRange();
    lua_pushnumber(L, result);
    return 1;
}

int DoorStuffBinding::_NV_getReachRange(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    float result = s->_NV_getReachRange();
    lua_pushnumber(L, result);
    return 1;
}

int DoorStuffBinding::getName(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    std::string result = s->getName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int DoorStuffBinding::_NV_getName(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    std::string result = s->_NV_getName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int DoorStuffBinding::hasDoorLock(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    bool result = s->hasDoorLock();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::_NV_hasDoorLock(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    bool result = s->_NV_hasDoorLock();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::updateGateCodeState(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    s->updateGateCodeState();
    return 0;
}

int DoorStuffBinding::onBuildingLoaded(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    s->onBuildingLoaded();
    return 0;
}

int DoorStuffBinding::_NV_onBuildingLoaded(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    s->_NV_onBuildingLoaded();
    return 0;
}

int DoorStuffBinding::setDoorOpenAmount(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    float amount = (float)luaL_checknumber(L, 2);
    bool forceUnsafe = lua_toboolean(L, 3) != 0;
    s->setDoorOpenAmount(amount, forceUnsafe);
    return 0;
}

int DoorStuffBinding::isBroken(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    bool result = s->isBroken();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::_NV_isBroken(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    bool result = s->_NV_isBroken();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::setBroken(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    bool on = lua_toboolean(L, 2) != 0;
    s->setBroken(on);
    return 0;
}

int DoorStuffBinding::_NV_setBroken(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    bool on = lua_toboolean(L, 2) != 0;
    s->_NV_setBroken(on);
    return 0;
}

int DoorStuffBinding::isDisabled(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    bool result = s->isDisabled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::_NV_isDisabled(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    bool result = s->_NV_isDisabled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::isLocked(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    bool result = s->isLocked();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::lockDoor(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    s->lockDoor();
    return 0;
}

int DoorStuffBinding::unlockDoor(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    s->unlockDoor();
    return 0;
}

int DoorStuffBinding::getDoorOpenAmount(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    float result = s->getDoorOpenAmount();
    lua_pushnumber(L, result);
    return 1;
}

int DoorStuffBinding::openDoor(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    bool result = s->openDoor();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::closeDoor(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    bool result = s->closeDoor();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::_forceDoorClosedUT(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    bool result = s->_forceDoorClosedUT();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::_forceDoorOpenUT(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    bool result = s->_forceDoorOpenUT();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::update(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    s->update();
    return 0;
}

int DoorStuffBinding::_NV_update(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    s->_NV_update();
    return 0;
}

int DoorStuffBinding::isOpen(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    bool result = s->isOpen();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int DoorStuffBinding::doorParentBuilding(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    Building result = s->doorParentBuilding();
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}

int DoorStuffBinding::_NV_doorParentBuilding(lua_State* L)
{
    DoorStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "DoorStuff is nil");

    Building result = s->_NV_doorParentBuilding();
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}

/*
Skipped methods needing manual binding:
  line 32: DoorStuff* _CONSTRUCTOR(...) - unsupported return type
  line 38: NxActor* _getPhysActorUT(...) - unsupported return type
  line 39: void getGUIData(...) - unsupported arg type
  line 40: void _NV_getGUIData(...) - unsupported arg type
  line 45: GatewayBuilding* isGate(...) - unsupported return type
  line 46: GatewayBuilding* _NV_isGate(...) - unsupported return type
  line 49: CursorType getMouseCursor(...) - unsupported return type
  line 50: CursorType _NV_getMouseCursor(...) - unsupported return type
  line 51: TaskType getDefaultTask(...) - unsupported return type
  line 52: TaskType _NV_getDefaultTask(...) - unsupported return type
  line 53: void setHandle(...) - unsupported arg type
  line 54: void _NV_setHandle(...) - unsupported arg type
  line 57: DoorStuff* getDoor(...) - unsupported return type
  line 58: DoorStuff* _NV_getDoor(...) - unsupported return type
  line 61: DoorLock* getDoorLock(...) - unsupported return type
  line 62: DoorLock* _NV_getDoorLock(...) - unsupported return type
  line 65: HitMaterialType hitByMeleeAttack(...) - unsupported return type
  line 66: HitMaterialType _NV_hitByMeleeAttack(...) - unsupported return type
  line 67: const Ogre::Vector3& getActorClosedPosition(...) - reference return type
  line 101: void setDoorState(...) - unsupported arg type
  line 102: DoorState getDoorState(...) - unsupported return type
  line 109: const Ogre::Vector3& getDoorPosition(...) - reference return type
  line 110: const Ogre::Vector3& getDoorPosOutside(...) - reference return type
  line 111: Ogre::Vector3 getDoorPosOutside_extraFarOut(...) - unsupported return type
  line 112: const Ogre::Vector3& getDoorPosInside(...) - reference return type
  line 113: Ogre::Vector3 getDoorPosInside_extraFarIn(...) - unsupported return type
  line 115: void openButton(...) - unsupported arg type
  line 116: void lockButton(...) - unsupported arg type
  line 117: void _serialise(...) - unsupported arg type
  line 118: void _NV__serialise(...) - unsupported arg type
  line 119: void _loadFromSerialise(...) - unsupported arg type
  line 120: void _NV__loadFromSerialise(...) - unsupported arg type
  line 121: DoorStuff* doorStuff(...) - unsupported return type
  line 122: DoorStuff* _NV_doorStuff(...) - unsupported return type
*/

void DoorStuffBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DoorStuffBinding::gc },
        { "__tostring", DoorStuffBinding::tostring },
        { "__index",    DoorStuffBinding::index },
        { "__newindex", DoorStuffBinding::newindex },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", DoorStuffBinding::_DESTRUCTOR },
        { "setupPhysicalUT", DoorStuffBinding::setupPhysicalUT },
        { "getFaction", DoorStuffBinding::getFaction },
        { "_NV_getFaction", DoorStuffBinding::_NV_getFaction },
        { "needsUpdate", DoorStuffBinding::needsUpdate },
        { "_NV_needsUpdate", DoorStuffBinding::_NV_needsUpdate },
        { "getGateCode", DoorStuffBinding::getGateCode },
        { "setGateCode", DoorStuffBinding::setGateCode },
        { "isPublic", DoorStuffBinding::isPublic },
        { "_NV_isPublic", DoorStuffBinding::_NV_isPublic },
        { "getReachRange", DoorStuffBinding::getReachRange },
        { "_NV_getReachRange", DoorStuffBinding::_NV_getReachRange },
        { "getName", DoorStuffBinding::getName },
        { "_NV_getName", DoorStuffBinding::_NV_getName },
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
        { "openDoor", DoorStuffBinding::openDoor },
        { "closeDoor", DoorStuffBinding::closeDoor },
        { "_forceDoorClosedUT", DoorStuffBinding::_forceDoorClosedUT },
        { "_forceDoorOpenUT", DoorStuffBinding::_forceDoorOpenUT },
        { "update", DoorStuffBinding::update },
        { "_NV_update", DoorStuffBinding::_NV_update },
        { "isOpen", DoorStuffBinding::isOpen },
        { "doorParentBuilding", DoorStuffBinding::doorParentBuilding },
        { "_NV_doorParentBuilding", DoorStuffBinding::_NV_doorParentBuilding },
        { 0, 0 }
    };
    registerClass(L, DoorStuffBinding::getMetatableName(), meta, methods);
}

} // namespace KenshiLua