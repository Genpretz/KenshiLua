#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class DoorStuffBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.DoorStuff"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int setupPhysicalUT(lua_State* L);
    static int getFaction(lua_State* L);
    static int _NV_getFaction(lua_State* L);
    static int _getPhysActorUT(lua_State* L);
    static int needsUpdate(lua_State* L);
    static int _NV_needsUpdate(lua_State* L);
    static int getGateCode(lua_State* L);
    static int setGateCode(lua_State* L);
    static int isGate(lua_State* L);
    static int _NV_isGate(lua_State* L);
    static int isPublic(lua_State* L);
    static int _NV_isPublic(lua_State* L);
    static int getMouseCursor(lua_State* L);
    static int _NV_getMouseCursor(lua_State* L);
    static int getDefaultTask(lua_State* L);
    static int _NV_getDefaultTask(lua_State* L);
    static int getReachRange(lua_State* L);
    static int _NV_getReachRange(lua_State* L);
    static int getDoor(lua_State* L);
    static int _NV_getDoor(lua_State* L);
    static int getName(lua_State* L);
    static int _NV_getName(lua_State* L);
    static int getDoorLock(lua_State* L);
    static int _NV_getDoorLock(lua_State* L);
    static int hasDoorLock(lua_State* L);
    static int _NV_hasDoorLock(lua_State* L);
    static int updateGateCodeState(lua_State* L);
    static int onBuildingLoaded(lua_State* L);
    static int _NV_onBuildingLoaded(lua_State* L);
    static int setDoorOpenAmount(lua_State* L);
    static int isBroken(lua_State* L);
    static int _NV_isBroken(lua_State* L);
    static int setBroken(lua_State* L);
    static int _NV_setBroken(lua_State* L);
    static int isDisabled(lua_State* L);
    static int _NV_isDisabled(lua_State* L);
    static int isLocked(lua_State* L);
    static int lockDoor(lua_State* L);
    static int unlockDoor(lua_State* L);
    static int getDoorOpenAmount(lua_State* L);
    static int setDoorState(lua_State* L);
    static int getDoorState(lua_State* L);
    static int openDoor(lua_State* L);
    static int closeDoor(lua_State* L);
    static int _forceDoorClosedUT(lua_State* L);
    static int _forceDoorOpenUT(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int getDoorPosOutside_extraFarOut(lua_State* L);
    static int getDoorPosInside_extraFarIn(lua_State* L);
    static int isOpen(lua_State* L);
    static int doorStuff(lua_State* L);
    static int _NV_doorStuff(lua_State* L);
    static int doorParentBuilding(lua_State* L);
    static int _NV_doorParentBuilding(lua_State* L);
};
}