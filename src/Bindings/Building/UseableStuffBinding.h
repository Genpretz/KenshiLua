#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class UseableStuffBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.UseableStuff"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int getUseableStuff(lua_State* L);
    static int _NV_getUseableStuff(lua_State* L);
    static int createInventoryLayout(lua_State* L);
    static int _NV_createInventoryLayout(lua_State* L);
    static int takeMoney(lua_State* L);
    static int _NV_takeMoney(lua_State* L);
    static int getMoney(lua_State* L);
    static int _NV_getMoney(lua_State* L);
    static int getInventory(lua_State* L);
    static int _NV_getInventory(lua_State* L);
    static int isAnyInputsEmpty(lua_State* L);
    static int _NV_isAnyInputsEmpty(lua_State* L);
    static int needsUpdate(lua_State* L);
    static int _NV_needsUpdate(lua_State* L);
    static int threadedUpdate(lua_State* L);
    static int _NV_threadedUpdate(lua_State* L);
    static int calculateEfficiencyMult(lua_State* L);
    static int _NV_calculateEfficiencyMult(lua_State* L);
    static int isOutOfPower(lua_State* L);
    static int _NV_isOutOfPower(lua_State* L);
    static int isBroken(lua_State* L);
    static int _NV_isBroken(lua_State* L);
    static int setBroken(lua_State* L);
    static int _NV_setBroken(lua_State* L);
    static int isDisabled(lua_State* L);
    static int _NV_isDisabled(lua_State* L);
    static int getMouseCursor(lua_State* L);
    static int _NV_getMouseCursor(lua_State* L);
    static int getDefaultTask(lua_State* L);
    static int _NV_getDefaultTask(lua_State* L);
    static int getReachRange(lua_State* L);
    static int _NV_getReachRange(lua_State* L);
    static int dontNeedWorkRightNow(lua_State* L);
    static int _NV_dontNeedWorkRightNow(lua_State* L);
    static int isForSale(lua_State* L);
    static int _NV_isForSale(lua_State* L);
    static int takePowerFrom(lua_State* L);
    static int howMuchPowerDoYouWantMax(lua_State* L);
    static int howMuchPowerDoYouWantForSortingFunction(lua_State* L);
    static int _NV_howMuchPowerDoYouWantForSortingFunction(lua_State* L);
    static int howMuchPowerDoYouWantNow(lua_State* L);
    static int needPowerRightNow(lua_State* L);
    static int _NV_needPowerRightNow(lua_State* L);
    static int givePower(lua_State* L);
    static int _NV_givePower(lua_State* L);
    static int resetPower(lua_State* L);
    static int getMaxPower(lua_State* L);
    static int getPowerOutput(lua_State* L);
    static int _NV_getPowerOutput(lua_State* L);
    static int getFuelConsumptionRate(lua_State* L);
    static int _NV_getFuelConsumptionRate(lua_State* L);
    static int isBattery(lua_State* L);
    static int isGenerator(lua_State* L);
    static int getBatteryCharge(lua_State* L);
    static int getBatteryChargeMax(lua_State* L);
    static int setupFromData(lua_State* L);
    static int _NV_setupFromData(lua_State* L);
    static int switchPowerOn(lua_State* L);
    static int _NV_switchPowerOn(lua_State* L);
    static int hasPower(lua_State* L);
    static int isPowerOn(lua_State* L);
    static int _NV_isPowerOn(lua_State* L);
    static int isRecievesBatteryPower(lua_State* L);
    static int getStatUsed(lua_State* L);
    static int getDoorLock(lua_State* L);
    static int _NV_getDoorLock(lua_State* L);
    static int hasDoorLock(lua_State* L);
    static int _NV_hasDoorLock(lua_State* L);
    static int getFunctionalityData(lua_State* L);
    static int setup(lua_State* L);
    static int _NV_setup(lua_State* L);
    static int getOutputBasedRotationSpeedMult(lua_State* L);
    static int _NV_getOutputBasedRotationSpeedMult(lua_State* L);
    static int getGUIPowerEfficiencyToolTipString(lua_State* L);
    static int _NV_getGUIPowerEfficiencyToolTipString(lua_State* L);
};
}