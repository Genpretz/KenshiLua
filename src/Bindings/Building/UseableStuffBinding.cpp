#include "pch.h"
#include "Bindings/UseableStuffBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/UseableStuff.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static UseableStuff* getS(lua_State* L, int idx)
{
    return checkObject<UseableStuff>(L, idx, UseableStuffBinding::getMetatableName());
}

int UseableStuffBinding::gc(lua_State* L) { return noopGc(L); }

int UseableStuffBinding::tostring(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int UseableStuffBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, UseableStuffBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    UseableStuff* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    // TODO hand shopOwner; unsupported __index type from header line 37
    // TODO hand callbackOwner; unsupported __index type from header line 38
    if (strcmp(key, "hasProgressBarWhenUsed") == 0) { lua_pushboolean(L, s->hasProgressBarWhenUsed ? 1 : 0); return 1; }
    if (strcmp(key, "progressBarLevel") == 0) { lua_pushnumber(L, s->progressBarLevel); return 1; }
    if (strcmp(key, "occupantSelection") == 0) { lua_pushboolean(L, s->occupantSelection ? 1 : 0); return 1; }
    if (strcmp(key, "needsOperating") == 0) { lua_pushboolean(L, s->needsOperating ? 1 : 0); return 1; }
    if (strcmp(key, "numOperatorsMax") == 0) { lua_pushinteger(L, s->numOperatorsMax); return 1; }
    if (strcmp(key, "hungerRate") == 0) { lua_pushnumber(L, s->hungerRate); return 1; }
    if (strcmp(key, "_recievesBatteryPower") == 0) { lua_pushboolean(L, s->_recievesBatteryPower ? 1 : 0); return 1; }
    if (strcmp(key, "powerOn") == 0) { lua_pushboolean(L, s->powerOn ? 1 : 0); return 1; }
    if (strcmp(key, "_isBroken") == 0) { lua_pushboolean(L, s->_isBroken ? 1 : 0); return 1; }
    if (strcmp(key, "batteryOutputStat") == 0) { lua_pushnumber(L, s->batteryOutputStat); return 1; }
    if (strcmp(key, "_powerOutputMax") == 0) { lua_pushnumber(L, s->_powerOutputMax); return 1; }
    if (strcmp(key, "currentPower") == 0) { lua_pushnumber(L, s->currentPower); return 1; }
    if (strcmp(key, "powerTimeStored") == 0) { lua_pushnumber(L, s->powerTimeStored); return 1; }
    if (strcmp(key, "_powerTimeStoreMax") == 0) { lua_pushnumber(L, s->_powerTimeStoreMax); return 1; }
    // TODO std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy > > currentOperators; unsupported __index type from header line 167
    // TODO StatsEnumerated usesStat; unsupported __index type from header line 168
    if (strcmp(key, "functionalityData") == 0) { return pushObject<GameData>(L, s->functionalityData, GameDataBinding::getMetatableName()); }
    if (strcmp(key, "animation") == 0) { return pushObject<GameData>(L, s->animation, GameDataBinding::getMetatableName()); }
    if (strcmp(key, "animationKO") == 0) { return pushObject<GameData>(L, s->animationKO, GameDataBinding::getMetatableName()); }
    if (strcmp(key, "animationDazed") == 0) { return pushObject<GameData>(L, s->animationDazed, GameDataBinding::getMetatableName()); }
    if (strcmp(key, "maxUseRange") == 0) { lua_pushnumber(L, s->maxUseRange); return 1; }
    if (strcmp(key, "sfxTime") == 0) { lua_pushnumber(L, s->sfxTime); return 1; }
    if (strcmp(key, "inventory") == 0) { return pushObject<Inventory>(L, s->inventory, InventoryBinding::getMetatableName()); }
    // TODO DoorLock* doorLock; unsupported __index type from header line 176

    lua_pushnil(L);
    return 1;
}

int UseableStuffBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    // TODO hand shopOwner; unsupported __newindex type from header line 37
    // TODO hand callbackOwner; unsupported __newindex type from header line 38
    if (strcmp(key, "hasProgressBarWhenUsed") == 0) { s->hasProgressBarWhenUsed = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "progressBarLevel") == 0) { s->progressBarLevel = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "occupantSelection") == 0) { s->occupantSelection = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "needsOperating") == 0) { s->needsOperating = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "numOperatorsMax") == 0) { s->numOperatorsMax = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "hungerRate") == 0) { s->hungerRate = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "_recievesBatteryPower") == 0) { s->_recievesBatteryPower = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "powerOn") == 0) { s->powerOn = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "_isBroken") == 0) { s->_isBroken = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "batteryOutputStat") == 0) { s->batteryOutputStat = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "_powerOutputMax") == 0) { s->_powerOutputMax = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "currentPower") == 0) { s->currentPower = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "powerTimeStored") == 0) { s->powerTimeStored = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "_powerTimeStoreMax") == 0) { s->_powerTimeStoreMax = (float)luaL_checknumber(L, 3); return 0; }
    // TODO std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy > > currentOperators; unsupported __newindex type from header line 167
    // TODO StatsEnumerated usesStat; unsupported __newindex type from header line 168
    // TODO GameData* functionalityData; unsupported __newindex type from header line 169
    // TODO GameData* animation; unsupported __newindex type from header line 170
    // TODO GameData* animationKO; unsupported __newindex type from header line 171
    // TODO GameData* animationDazed; unsupported __newindex type from header line 172
    if (strcmp(key, "maxUseRange") == 0) { s->maxUseRange = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "sfxTime") == 0) { s->sfxTime = (float)luaL_checknumber(L, 3); return 0; }
    // TODO Inventory* inventory; unsupported __newindex type from header line 175
    // TODO DoorLock* doorLock; unsupported __newindex type from header line 176

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int UseableStuffBinding::_DESTRUCTOR(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    s->_DESTRUCTOR();
    return 0;
}

int UseableStuffBinding::takeMoney(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    int n = (int)luaL_checkinteger(L, 2);
    bool result = s->takeMoney(n);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::_NV_takeMoney(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    int n = (int)luaL_checkinteger(L, 2);
    bool result = s->_NV_takeMoney(n);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::getMoney(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    int result = s->getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int UseableStuffBinding::_NV_getMoney(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    int result = s->_NV_getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int UseableStuffBinding::getInventory(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    Inventory result = s->getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int UseableStuffBinding::_NV_getInventory(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    Inventory result = s->_NV_getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int UseableStuffBinding::isAnyInputsEmpty(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool result = s->isAnyInputsEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::_NV_isAnyInputsEmpty(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool result = s->_NV_isAnyInputsEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::needsUpdate(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool result = s->needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::_NV_needsUpdate(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool result = s->_NV_needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::threadedUpdate(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    s->threadedUpdate();
    return 0;
}

int UseableStuffBinding::_NV_threadedUpdate(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    s->_NV_threadedUpdate();
    return 0;
}

int UseableStuffBinding::calculateEfficiencyMult(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    float result = s->calculateEfficiencyMult();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::_NV_calculateEfficiencyMult(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    float result = s->_NV_calculateEfficiencyMult();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::isOutOfPower(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    float result = s->isOutOfPower();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::_NV_isOutOfPower(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    float result = s->_NV_isOutOfPower();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::isBroken(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool result = s->isBroken();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::_NV_isBroken(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool result = s->_NV_isBroken();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::setBroken(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool on = lua_toboolean(L, 2) != 0;
    s->setBroken(on);
    return 0;
}

int UseableStuffBinding::_NV_setBroken(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool on = lua_toboolean(L, 2) != 0;
    s->_NV_setBroken(on);
    return 0;
}

int UseableStuffBinding::isDisabled(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool result = s->isDisabled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::_NV_isDisabled(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool result = s->_NV_isDisabled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::getReachRange(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    float result = s->getReachRange();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::_NV_getReachRange(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    float result = s->_NV_getReachRange();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::dontNeedWorkRightNow(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool result = s->dontNeedWorkRightNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::_NV_dontNeedWorkRightNow(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool result = s->_NV_dontNeedWorkRightNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::isForSale(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool result = s->isForSale();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::_NV_isForSale(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool result = s->_NV_isForSale();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::takePowerFrom(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    float amount = (float)luaL_checknumber(L, 2);
    float frameTime = (float)luaL_checknumber(L, 3);
    float result = s->takePowerFrom(amount, frameTime);
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::howMuchPowerDoYouWantMax(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    float result = s->howMuchPowerDoYouWantMax();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::howMuchPowerDoYouWantForSortingFunction(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    float result = s->howMuchPowerDoYouWantForSortingFunction();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::_NV_howMuchPowerDoYouWantForSortingFunction(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    float result = s->_NV_howMuchPowerDoYouWantForSortingFunction();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::howMuchPowerDoYouWantNow(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    float result = s->howMuchPowerDoYouWantNow();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::needPowerRightNow(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool result = s->needPowerRightNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::_NV_needPowerRightNow(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool result = s->_NV_needPowerRightNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::givePower(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    float amount = (float)luaL_checknumber(L, 2);
    s->givePower(amount);
    return 0;
}

int UseableStuffBinding::_NV_givePower(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    float amount = (float)luaL_checknumber(L, 2);
    s->_NV_givePower(amount);
    return 0;
}

int UseableStuffBinding::resetPower(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    s->resetPower();
    return 0;
}

int UseableStuffBinding::getMaxPower(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    float result = s->getMaxPower();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::getPowerOutput(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    float result = s->getPowerOutput();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::_NV_getPowerOutput(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    float result = s->_NV_getPowerOutput();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::getFuelConsumptionRate(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    float result = s->getFuelConsumptionRate();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::_NV_getFuelConsumptionRate(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    float result = s->_NV_getFuelConsumptionRate();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::isBattery(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool result = s->isBattery();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::isGenerator(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool result = s->isGenerator();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::getBatteryCharge(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    float result = s->getBatteryCharge();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::getBatteryChargeMax(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    float result = s->getBatteryChargeMax();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::setupFromData(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    s->setupFromData();
    return 0;
}

int UseableStuffBinding::_NV_setupFromData(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    s->_NV_setupFromData();
    return 0;
}

int UseableStuffBinding::switchPowerOn(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool on = lua_toboolean(L, 2) != 0;
    s->switchPowerOn(on);
    return 0;
}

int UseableStuffBinding::_NV_switchPowerOn(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool on = lua_toboolean(L, 2) != 0;
    s->_NV_switchPowerOn(on);
    return 0;
}

int UseableStuffBinding::hasPower(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool result = s->hasPower();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::isPowerOn(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool result = s->isPowerOn();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::_NV_isPowerOn(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool result = s->_NV_isPowerOn();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::isRecievesBatteryPower(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool result = s->isRecievesBatteryPower();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::hasDoorLock(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool result = s->hasDoorLock();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::_NV_hasDoorLock(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    bool result = s->_NV_hasDoorLock();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::getFunctionalityData(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    GameData result = s->getFunctionalityData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int UseableStuffBinding::setup(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    s->setup();
    return 0;
}

int UseableStuffBinding::_NV_setup(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    s->_NV_setup();
    return 0;
}

int UseableStuffBinding::getOutputBasedRotationSpeedMult(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    float result = s->getOutputBasedRotationSpeedMult();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::_NV_getOutputBasedRotationSpeedMult(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    float result = s->_NV_getOutputBasedRotationSpeedMult();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::getGUIPowerEfficiencyToolTipString(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    std::string result = s->getGUIPowerEfficiencyToolTipString();
    lua_pushstring(L, result.c_str());
    return 1;
}

int UseableStuffBinding::_NV_getGUIPowerEfficiencyToolTipString(lua_State* L)
{
    UseableStuff* s = getS(L, 1);
    if (!s) return luaL_error(L, "UseableStuff is nil");

    std::string result = s->_NV_getGUIPowerEfficiencyToolTipString();
    lua_pushstring(L, result.c_str());
    return 1;
}

/*
Skipped methods needing manual binding:
  line 30: UseableStuff* _CONSTRUCTOR(...) - unsupported return type
  line 33: UseableStuff* getUseableStuff(...) - unsupported return type
  line 34: UseableStuff* _NV_getUseableStuff(...) - unsupported return type
  line 35: InventoryLayout* createInventoryLayout(...) - unsupported return type
  line 36: InventoryLayout* _NV_createInventoryLayout(...) - unsupported return type
  line 39: void equipItem(...) - unsupported arg type
  line 40: void _NV_equipItem(...) - unsupported arg type
  line 41: void unequipItem(...) - unsupported arg type
  line 42: void _NV_unequipItem(...) - unsupported arg type
  line 43: void dropItem(...) - unsupported arg type
  line 44: void _NV_dropItem(...) - unsupported arg type
  line 51: bool canHaveSomeOfThese(...) - unsupported arg type
  line 52: bool _NV_canHaveSomeOfThese(...) - unsupported arg type
  line 59: void operate(...) - unsupported arg type
  line 60: void _NV_operate(...) - unsupported arg type
  line 67: int getCostToUse(...) - unsupported arg type
  line 68: int _NV_getCostToUse(...) - unsupported arg type
  line 69: void getGUIData(...) - unsupported arg type
  line 70: void _NV_getGUIData(...) - unsupported arg type
  line 71: void getGUIPower(...) - unsupported arg type
  line 72: void _NV_getGUIPower(...) - unsupported arg type
  line 73: void getGUIEfficiency(...) - unsupported arg type
  line 74: void _NV_getGUIEfficiency(...) - unsupported arg type
  line 75: void getGUIWorkers(...) - unsupported arg type
  line 76: void _NV_getGUIWorkers(...) - unsupported arg type
  line 77: void getGUIToolTipForGroundResourceEfficiency(...) - unsupported arg type
  line 78: void _NV_getGUIToolTipForGroundResourceEfficiency(...) - unsupported arg type
  line 79: GameSaveState serialise(...) - unsupported return type
  line 80: GameSaveState _NV_serialise(...) - unsupported return type
  line 81: void loadFromSerialise(...) - unsupported arg type
  line 82: void _NV_loadFromSerialise(...) - unsupported arg type
  line 83: HitMaterialType hitByMeleeAttack(...) - unsupported return type
  line 84: HitMaterialType _NV_hitByMeleeAttack(...) - unsupported return type
  line 91: CursorType getMouseCursor(...) - unsupported return type
  line 92: CursorType _NV_getMouseCursor(...) - unsupported return type
  line 93: TaskType getDefaultTask(...) - unsupported return type
  line 94: TaskType _NV_getDefaultTask(...) - unsupported return type
  line 95: const std::string& getAnimation(...) - reference return type
  line 96: const std::string& getAnimationKO(...) - reference return type
  line 97: const std::string& getAnimationDazed(...) - reference return type
  line 102: bool isFreeSlot(...) - unsupported arg type
  line 103: bool _NV_isFreeSlot(...) - unsupported arg type
  line 104: bool tryOperate(...) - unsupported arg type
  line 105: bool _NV_tryOperate(...) - unsupported arg type
  line 106: bool couldIOperate(...) - unsupported arg type
  line 107: bool _NV_couldIOperate(...) - unsupported arg type
  line 108: void stopOperating(...) - unsupported arg type
  line 109: const hand& getOccupant(...) - reference return type
  line 110: void occupantHandleChangedEvent(...) - unsupported arg type
  line 115: void togglePowerButton(...) - unsupported arg type
  line 116: void _NV_togglePowerButton(...) - unsupported arg type
  line 117: void toggleBattButton(...) - unsupported arg type
  line 118: void _NV_toggleBattButton(...) - unsupported arg type
  line 148: StatsEnumerated getStatUsed(...) - unsupported return type
  line 149: DoorLock* getDoorLock(...) - unsupported return type
  line 150: DoorLock* _NV_getDoorLock(...) - unsupported return type
*/

void UseableStuffBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       UseableStuffBinding::gc },
        { "__tostring", UseableStuffBinding::tostring },
        { "__index",    UseableStuffBinding::index },
        { "__newindex", UseableStuffBinding::newindex },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", UseableStuffBinding::_DESTRUCTOR },
        { "takeMoney", UseableStuffBinding::takeMoney },
        { "_NV_takeMoney", UseableStuffBinding::_NV_takeMoney },
        { "getMoney", UseableStuffBinding::getMoney },
        { "_NV_getMoney", UseableStuffBinding::_NV_getMoney },
        { "getInventory", UseableStuffBinding::getInventory },
        { "_NV_getInventory", UseableStuffBinding::_NV_getInventory },
        { "isAnyInputsEmpty", UseableStuffBinding::isAnyInputsEmpty },
        { "_NV_isAnyInputsEmpty", UseableStuffBinding::_NV_isAnyInputsEmpty },
        { "needsUpdate", UseableStuffBinding::needsUpdate },
        { "_NV_needsUpdate", UseableStuffBinding::_NV_needsUpdate },
        { "threadedUpdate", UseableStuffBinding::threadedUpdate },
        { "_NV_threadedUpdate", UseableStuffBinding::_NV_threadedUpdate },
        { "calculateEfficiencyMult", UseableStuffBinding::calculateEfficiencyMult },
        { "_NV_calculateEfficiencyMult", UseableStuffBinding::_NV_calculateEfficiencyMult },
        { "isOutOfPower", UseableStuffBinding::isOutOfPower },
        { "_NV_isOutOfPower", UseableStuffBinding::_NV_isOutOfPower },
        { "isBroken", UseableStuffBinding::isBroken },
        { "_NV_isBroken", UseableStuffBinding::_NV_isBroken },
        { "setBroken", UseableStuffBinding::setBroken },
        { "_NV_setBroken", UseableStuffBinding::_NV_setBroken },
        { "isDisabled", UseableStuffBinding::isDisabled },
        { "_NV_isDisabled", UseableStuffBinding::_NV_isDisabled },
        { "getReachRange", UseableStuffBinding::getReachRange },
        { "_NV_getReachRange", UseableStuffBinding::_NV_getReachRange },
        { "dontNeedWorkRightNow", UseableStuffBinding::dontNeedWorkRightNow },
        { "_NV_dontNeedWorkRightNow", UseableStuffBinding::_NV_dontNeedWorkRightNow },
        { "isForSale", UseableStuffBinding::isForSale },
        { "_NV_isForSale", UseableStuffBinding::_NV_isForSale },
        { "takePowerFrom", UseableStuffBinding::takePowerFrom },
        { "howMuchPowerDoYouWantMax", UseableStuffBinding::howMuchPowerDoYouWantMax },
        { "howMuchPowerDoYouWantForSortingFunction", UseableStuffBinding::howMuchPowerDoYouWantForSortingFunction },
        { "_NV_howMuchPowerDoYouWantForSortingFunction", UseableStuffBinding::_NV_howMuchPowerDoYouWantForSortingFunction },
        { "howMuchPowerDoYouWantNow", UseableStuffBinding::howMuchPowerDoYouWantNow },
        { "needPowerRightNow", UseableStuffBinding::needPowerRightNow },
        { "_NV_needPowerRightNow", UseableStuffBinding::_NV_needPowerRightNow },
        { "givePower", UseableStuffBinding::givePower },
        { "_NV_givePower", UseableStuffBinding::_NV_givePower },
        { "resetPower", UseableStuffBinding::resetPower },
        { "getMaxPower", UseableStuffBinding::getMaxPower },
        { "getPowerOutput", UseableStuffBinding::getPowerOutput },
        { "_NV_getPowerOutput", UseableStuffBinding::_NV_getPowerOutput },
        { "getFuelConsumptionRate", UseableStuffBinding::getFuelConsumptionRate },
        { "_NV_getFuelConsumptionRate", UseableStuffBinding::_NV_getFuelConsumptionRate },
        { "isBattery", UseableStuffBinding::isBattery },
        { "isGenerator", UseableStuffBinding::isGenerator },
        { "getBatteryCharge", UseableStuffBinding::getBatteryCharge },
        { "getBatteryChargeMax", UseableStuffBinding::getBatteryChargeMax },
        { "setupFromData", UseableStuffBinding::setupFromData },
        { "_NV_setupFromData", UseableStuffBinding::_NV_setupFromData },
        { "switchPowerOn", UseableStuffBinding::switchPowerOn },
        { "_NV_switchPowerOn", UseableStuffBinding::_NV_switchPowerOn },
        { "hasPower", UseableStuffBinding::hasPower },
        { "isPowerOn", UseableStuffBinding::isPowerOn },
        { "_NV_isPowerOn", UseableStuffBinding::_NV_isPowerOn },
        { "isRecievesBatteryPower", UseableStuffBinding::isRecievesBatteryPower },
        { "hasDoorLock", UseableStuffBinding::hasDoorLock },
        { "_NV_hasDoorLock", UseableStuffBinding::_NV_hasDoorLock },
        { "getFunctionalityData", UseableStuffBinding::getFunctionalityData },
        { "setup", UseableStuffBinding::setup },
        { "_NV_setup", UseableStuffBinding::_NV_setup },
        { "getOutputBasedRotationSpeedMult", UseableStuffBinding::getOutputBasedRotationSpeedMult },
        { "_NV_getOutputBasedRotationSpeedMult", UseableStuffBinding::_NV_getOutputBasedRotationSpeedMult },
        { "getGUIPowerEfficiencyToolTipString", UseableStuffBinding::getGUIPowerEfficiencyToolTipString },
        { "_NV_getGUIPowerEfficiencyToolTipString", UseableStuffBinding::_NV_getGUIPowerEfficiencyToolTipString },
        { 0, 0 }
    };
    registerClass(L, UseableStuffBinding::getMetatableName(), meta, methods);
}

} // namespace KenshiLua