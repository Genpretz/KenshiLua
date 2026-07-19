#include "pch.h"
#include <kenshi/Building/UseableStuff.h>
#include "UseableStuffBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/Util/HandBinding.h"

namespace KenshiLua
{

static UseableStuff* getInstance(lua_State* L, int idx)
{
    return checkObject<UseableStuff>(L, idx, UseableStuffBinding::getMetatableName());
}

// --- Getters for UseableStuff ---
static int UseableStuff_get_shopOwner(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    return handBinding::push(L, instance->shopOwner);
}

static int UseableStuff_get_callbackOwner(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    return handBinding::push(L, instance->callbackOwner);
}

static int UseableStuff_get_hasProgressBarWhenUsed(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    lua_pushboolean(L, instance->hasProgressBarWhenUsed ? 1 : 0);
    return 1;
}

static int UseableStuff_get_progressBarLevel(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    lua_pushnumber(L, instance->progressBarLevel);
    return 1;
}

static int UseableStuff_get_occupantSelection(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    lua_pushboolean(L, instance->occupantSelection ? 1 : 0);
    return 1;
}

static int UseableStuff_get_needsOperating(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    lua_pushboolean(L, instance->needsOperating ? 1 : 0);
    return 1;
}

static int UseableStuff_get_numOperatorsMax(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    lua_pushinteger(L, instance->numOperatorsMax);
    return 1;
}

static int UseableStuff_get_hungerRate(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    lua_pushnumber(L, instance->hungerRate);
    return 1;
}

static int UseableStuff_get__recievesBatteryPower(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    lua_pushboolean(L, instance->_recievesBatteryPower ? 1 : 0);
    return 1;
}

static int UseableStuff_get_powerOn(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    lua_pushboolean(L, instance->powerOn ? 1 : 0);
    return 1;
}

static int UseableStuff_get__isBroken(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    lua_pushboolean(L, instance->_isBroken ? 1 : 0);
    return 1;
}

static int UseableStuff_get_batteryOutputStat(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    lua_pushnumber(L, instance->batteryOutputStat);
    return 1;
}

static int UseableStuff_get__powerOutputMax(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    lua_pushnumber(L, instance->_powerOutputMax);
    return 1;
}

static int UseableStuff_get_currentPower(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    lua_pushnumber(L, instance->currentPower);
    return 1;
}

static int UseableStuff_get_powerTimeStored(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    lua_pushnumber(L, instance->powerTimeStored);
    return 1;
}

static int UseableStuff_get__powerTimeStoreMax(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    lua_pushnumber(L, instance->_powerTimeStoreMax);
    return 1;
}

static int UseableStuff_get_currentOperators(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    // TODO: Unsupported type for currentOperators (std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'currentOperators' (type: std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy > >)");
}

static int UseableStuff_get_usesStat(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    lua_pushinteger(L, (lua_Integer)instance->usesStat);
    return 1;
}

static int UseableStuff_get_functionalityData(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    return pushObject<GameData>(L, instance->functionalityData, GameDataBinding::getMetatableName());
}

static int UseableStuff_get_animation(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    return pushObject<GameData>(L, instance->animation, GameDataBinding::getMetatableName());
}

static int UseableStuff_get_animationKO(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    return pushObject<GameData>(L, instance->animationKO, GameDataBinding::getMetatableName());
}

static int UseableStuff_get_animationDazed(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    return pushObject<GameData>(L, instance->animationDazed, GameDataBinding::getMetatableName());
}

static int UseableStuff_get_maxUseRange(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    lua_pushnumber(L, instance->maxUseRange);
    return 1;
}

static int UseableStuff_get_sfxTime(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    lua_newtable(L);
    lua_pushnumber(L, instance->sfxTime[0]);
    lua_rawseti(L, -2, 1);
    lua_pushnumber(L, instance->sfxTime[1]);
    lua_rawseti(L, -2, 2);
    return 1;
}

static int UseableStuff_get_inventory(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    return pushObject<Inventory>(L, instance->inventory, InventoryBinding::getMetatableName());
}

static int UseableStuff_get_doorLock(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    lua_pushlightuserdata(L, (void*)instance->doorLock);
    return 1;
}

// --- Setters for UseableStuff ---
static int UseableStuff_set_shopOwner(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    instance->shopOwner = *val;
    return 0;
}

static int UseableStuff_set_callbackOwner(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    instance->callbackOwner = *val;
    return 0;
}

static int UseableStuff_set_hasProgressBarWhenUsed(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    instance->hasProgressBarWhenUsed = lua_toboolean(L, 2) != 0;
    return 0;
}

static int UseableStuff_set_progressBarLevel(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    instance->progressBarLevel = (float)luaL_checknumber(L, 2);
    return 0;
}

static int UseableStuff_set_occupantSelection(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    instance->occupantSelection = lua_toboolean(L, 2) != 0;
    return 0;
}

static int UseableStuff_set_needsOperating(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    instance->needsOperating = lua_toboolean(L, 2) != 0;
    return 0;
}

static int UseableStuff_set_numOperatorsMax(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    instance->numOperatorsMax = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int UseableStuff_set_hungerRate(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    instance->hungerRate = (float)luaL_checknumber(L, 2);
    return 0;
}

static int UseableStuff_set__recievesBatteryPower(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    instance->_recievesBatteryPower = lua_toboolean(L, 2) != 0;
    return 0;
}

static int UseableStuff_set_powerOn(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    instance->powerOn = lua_toboolean(L, 2) != 0;
    return 0;
}

static int UseableStuff_set__isBroken(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    instance->_isBroken = lua_toboolean(L, 2) != 0;
    return 0;
}

static int UseableStuff_set_batteryOutputStat(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    instance->batteryOutputStat = (float)luaL_checknumber(L, 2);
    return 0;
}

static int UseableStuff_set__powerOutputMax(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    instance->_powerOutputMax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int UseableStuff_set_currentPower(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    instance->currentPower = (float)luaL_checknumber(L, 2);
    return 0;
}

static int UseableStuff_set_powerTimeStored(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    instance->powerTimeStored = (float)luaL_checknumber(L, 2);
    return 0;
}

static int UseableStuff_set__powerTimeStoreMax(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    instance->_powerTimeStoreMax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int UseableStuff_set_currentOperators(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    return luaL_error(L, "Read-only or unsupported setter type for currentOperators");
}

static int UseableStuff_set_usesStat(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    instance->usesStat = (StatsEnumerated)luaL_checkinteger(L, 2);
    return 0;
}

static int UseableStuff_set_functionalityData(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    return luaL_error(L, "Read-only or unsupported setter type for functionalityData");
}

static int UseableStuff_set_animation(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    return luaL_error(L, "Read-only or unsupported setter type for animation");
}

static int UseableStuff_set_animationKO(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    return luaL_error(L, "Read-only or unsupported setter type for animationKO");
}

static int UseableStuff_set_animationDazed(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    return luaL_error(L, "Read-only or unsupported setter type for animationDazed");
}

static int UseableStuff_set_maxUseRange(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    instance->maxUseRange = (float)luaL_checknumber(L, 2);
    return 0;
}

static int UseableStuff_set_sfxTime(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    if (lua_istable(L, 2)) {
        lua_rawgeti(L, 2, 1);
        instance->sfxTime[0] = (float)lua_tonumber(L, -1);
        lua_pop(L, 1);
        lua_rawgeti(L, 2, 2);
        instance->sfxTime[1] = (float)lua_tonumber(L, -1);
        lua_pop(L, 1);
    }
    return 0;
}

static int UseableStuff_set_inventory(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    return luaL_error(L, "Read-only or unsupported setter type for inventory");
}

static int UseableStuff_set_doorLock(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");
    return luaL_error(L, "Read-only or unsupported setter type for doorLock");
}

int UseableStuffBinding::_DESTRUCTOR(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int UseableStuffBinding::getUseableStuff(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    UseableStuff* result = instance->getUseableStuff();
    return pushObject<UseableStuff>(L, result, UseableStuffBinding::getMetatableName());
}

int UseableStuffBinding::_NV_getUseableStuff(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    UseableStuff* result = instance->_NV_getUseableStuff();
    return pushObject<UseableStuff>(L, result, UseableStuffBinding::getMetatableName());
}

int UseableStuffBinding::createInventoryLayout(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    InventoryLayout* result = instance->createInventoryLayout();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int UseableStuffBinding::_NV_createInventoryLayout(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    InventoryLayout* result = instance->_NV_createInventoryLayout();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int UseableStuffBinding::takeMoney(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    int n = (int)luaL_checkinteger(L, 2);
    bool result = instance->takeMoney(n);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::_NV_takeMoney(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    int n = (int)luaL_checkinteger(L, 2);
    bool result = instance->_NV_takeMoney(n);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::getMoney(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    int result = instance->getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int UseableStuffBinding::_NV_getMoney(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    int result = instance->_NV_getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int UseableStuffBinding::getInventory(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    Inventory* result = instance->getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int UseableStuffBinding::_NV_getInventory(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    Inventory* result = instance->_NV_getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int UseableStuffBinding::isAnyInputsEmpty(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool result = instance->isAnyInputsEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::_NV_isAnyInputsEmpty(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool result = instance->_NV_isAnyInputsEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::needsUpdate(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool result = instance->needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::_NV_needsUpdate(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool result = instance->_NV_needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::threadedUpdate(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    instance->threadedUpdate();
    return 0;
}

int UseableStuffBinding::_NV_threadedUpdate(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    instance->_NV_threadedUpdate();
    return 0;
}

int UseableStuffBinding::calculateEfficiencyMult(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    float result = instance->calculateEfficiencyMult();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::_NV_calculateEfficiencyMult(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    float result = instance->_NV_calculateEfficiencyMult();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::isOutOfPower(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    float result = instance->isOutOfPower();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::_NV_isOutOfPower(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    float result = instance->_NV_isOutOfPower();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::isBroken(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool result = instance->isBroken();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::_NV_isBroken(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool result = instance->_NV_isBroken();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::setBroken(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setBroken(on);
    return 0;
}

int UseableStuffBinding::_NV_setBroken(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_setBroken(on);
    return 0;
}

int UseableStuffBinding::isDisabled(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool result = instance->isDisabled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::_NV_isDisabled(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool result = instance->_NV_isDisabled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::getMouseCursor(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    CursorType result = instance->getMouseCursor();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int UseableStuffBinding::_NV_getMouseCursor(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    CursorType result = instance->_NV_getMouseCursor();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int UseableStuffBinding::getDefaultTask(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    TaskType result = instance->getDefaultTask();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int UseableStuffBinding::_NV_getDefaultTask(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    TaskType result = instance->_NV_getDefaultTask();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int UseableStuffBinding::getReachRange(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    float result = instance->getReachRange();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::_NV_getReachRange(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    float result = instance->_NV_getReachRange();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::dontNeedWorkRightNow(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool result = instance->dontNeedWorkRightNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::_NV_dontNeedWorkRightNow(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool result = instance->_NV_dontNeedWorkRightNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::isForSale(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool result = instance->isForSale();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::_NV_isForSale(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool result = instance->_NV_isForSale();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::takePowerFrom(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    float amount = (float)luaL_checknumber(L, 2);
    float frameTime = (float)luaL_checknumber(L, 3);
    float result = instance->takePowerFrom(amount, frameTime);
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::howMuchPowerDoYouWantMax(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    float result = instance->howMuchPowerDoYouWantMax();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::howMuchPowerDoYouWantForSortingFunction(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    float result = instance->howMuchPowerDoYouWantForSortingFunction();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::_NV_howMuchPowerDoYouWantForSortingFunction(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    float result = instance->_NV_howMuchPowerDoYouWantForSortingFunction();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::howMuchPowerDoYouWantNow(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    float result = instance->howMuchPowerDoYouWantNow();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::needPowerRightNow(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool result = instance->needPowerRightNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::_NV_needPowerRightNow(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool result = instance->_NV_needPowerRightNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::givePower(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    float amount = (float)luaL_checknumber(L, 2);
    instance->givePower(amount);
    return 0;
}

int UseableStuffBinding::_NV_givePower(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    float amount = (float)luaL_checknumber(L, 2);
    instance->_NV_givePower(amount);
    return 0;
}

int UseableStuffBinding::resetPower(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    instance->resetPower();
    return 0;
}

int UseableStuffBinding::getMaxPower(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    float result = instance->getMaxPower();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::getPowerOutput(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    float result = instance->getPowerOutput();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::_NV_getPowerOutput(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    float result = instance->_NV_getPowerOutput();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::getFuelConsumptionRate(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    float result = instance->getFuelConsumptionRate();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::_NV_getFuelConsumptionRate(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    float result = instance->_NV_getFuelConsumptionRate();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::isBattery(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool result = instance->isBattery();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::isGenerator(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool result = instance->isGenerator();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::getBatteryCharge(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    float result = instance->getBatteryCharge();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::getBatteryChargeMax(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    float result = instance->getBatteryChargeMax();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::setupFromData(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    instance->setupFromData();
    return 0;
}

int UseableStuffBinding::_NV_setupFromData(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    instance->_NV_setupFromData();
    return 0;
}

int UseableStuffBinding::switchPowerOn(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->switchPowerOn(on);
    return 0;
}

int UseableStuffBinding::_NV_switchPowerOn(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_switchPowerOn(on);
    return 0;
}

int UseableStuffBinding::hasPower(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool result = instance->hasPower();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::isPowerOn(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool result = instance->isPowerOn();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::_NV_isPowerOn(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool result = instance->_NV_isPowerOn();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::isRecievesBatteryPower(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool result = instance->isRecievesBatteryPower();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::getStatUsed(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    StatsEnumerated result = instance->getStatUsed();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int UseableStuffBinding::getDoorLock(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    DoorLock* result = instance->getDoorLock();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int UseableStuffBinding::_NV_getDoorLock(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    DoorLock* result = instance->_NV_getDoorLock();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int UseableStuffBinding::hasDoorLock(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool result = instance->hasDoorLock();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::_NV_hasDoorLock(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    bool result = instance->_NV_hasDoorLock();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int UseableStuffBinding::getFunctionalityData(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    GameData* result = instance->getFunctionalityData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int UseableStuffBinding::setup(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    instance->setup();
    return 0;
}

int UseableStuffBinding::_NV_setup(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    instance->_NV_setup();
    return 0;
}

int UseableStuffBinding::getOutputBasedRotationSpeedMult(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    float result = instance->getOutputBasedRotationSpeedMult();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::_NV_getOutputBasedRotationSpeedMult(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    float result = instance->_NV_getOutputBasedRotationSpeedMult();
    lua_pushnumber(L, result);
    return 1;
}

int UseableStuffBinding::getGUIPowerEfficiencyToolTipString(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    std::string result = instance->getGUIPowerEfficiencyToolTipString();
    lua_pushstring(L, result.c_str());
    return 1;
}

int UseableStuffBinding::_NV_getGUIPowerEfficiencyToolTipString(lua_State* L)
{
    UseableStuff* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UseableStuff is nil");

    std::string result = instance->_NV_getGUIPowerEfficiencyToolTipString();
    lua_pushstring(L, result.c_str());
    return 1;
}

/*
Skipped methods needing manual binding:
  line 30: UseableStuff* _CONSTRUCTOR(...) - unsupported arg type
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
  line 83: HitMaterialType hitByMeleeAttack(...) - unsupported arg type
  line 84: HitMaterialType _NV_hitByMeleeAttack(...) - unsupported arg type
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
*/

int UseableStuffBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int UseableStuffBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.UseableStuff object");
    return 1;
}

void UseableStuffBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       UseableStuffBinding::gc },
        { "__tostring", UseableStuffBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", UseableStuffBinding::_DESTRUCTOR },
        { "getUseableStuff", UseableStuffBinding::getUseableStuff },
        { "_NV_getUseableStuff", UseableStuffBinding::_NV_getUseableStuff },
        { "createInventoryLayout", UseableStuffBinding::createInventoryLayout },
        { "_NV_createInventoryLayout", UseableStuffBinding::_NV_createInventoryLayout },
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
        { "getMouseCursor", UseableStuffBinding::getMouseCursor },
        { "_NV_getMouseCursor", UseableStuffBinding::_NV_getMouseCursor },
        { "getDefaultTask", UseableStuffBinding::getDefaultTask },
        { "_NV_getDefaultTask", UseableStuffBinding::_NV_getDefaultTask },
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
        { "getStatUsed", UseableStuffBinding::getStatUsed },
        { "getDoorLock", UseableStuffBinding::getDoorLock },
        { "_NV_getDoorLock", UseableStuffBinding::_NV_getDoorLock },
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

    registerClass(
        L, 
        UseableStuffBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, UseableStuffBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, UseableStuff_get_shopOwner);
    lua_setfield(L, -2, "shopOwner");
    lua_pushcfunction(L, UseableStuff_get_callbackOwner);
    lua_setfield(L, -2, "callbackOwner");
    lua_pushcfunction(L, UseableStuff_get_hasProgressBarWhenUsed);
    lua_setfield(L, -2, "hasProgressBarWhenUsed");
    lua_pushcfunction(L, UseableStuff_get_progressBarLevel);
    lua_setfield(L, -2, "progressBarLevel");
    lua_pushcfunction(L, UseableStuff_get_occupantSelection);
    lua_setfield(L, -2, "occupantSelection");
    lua_pushcfunction(L, UseableStuff_get_needsOperating);
    lua_setfield(L, -2, "needsOperating");
    lua_pushcfunction(L, UseableStuff_get_numOperatorsMax);
    lua_setfield(L, -2, "numOperatorsMax");
    lua_pushcfunction(L, UseableStuff_get_hungerRate);
    lua_setfield(L, -2, "hungerRate");
    lua_pushcfunction(L, UseableStuff_get__recievesBatteryPower);
    lua_setfield(L, -2, "_recievesBatteryPower");
    lua_pushcfunction(L, UseableStuff_get_powerOn);
    lua_setfield(L, -2, "powerOn");
    lua_pushcfunction(L, UseableStuff_get__isBroken);
    lua_setfield(L, -2, "_isBroken");
    lua_pushcfunction(L, UseableStuff_get_batteryOutputStat);
    lua_setfield(L, -2, "batteryOutputStat");
    lua_pushcfunction(L, UseableStuff_get__powerOutputMax);
    lua_setfield(L, -2, "_powerOutputMax");
    lua_pushcfunction(L, UseableStuff_get_currentPower);
    lua_setfield(L, -2, "currentPower");
    lua_pushcfunction(L, UseableStuff_get_powerTimeStored);
    lua_setfield(L, -2, "powerTimeStored");
    lua_pushcfunction(L, UseableStuff_get__powerTimeStoreMax);
    lua_setfield(L, -2, "_powerTimeStoreMax");
    lua_pushcfunction(L, UseableStuff_get_currentOperators);
    lua_setfield(L, -2, "currentOperators");
    lua_pushcfunction(L, UseableStuff_get_usesStat);
    lua_setfield(L, -2, "usesStat");
    lua_pushcfunction(L, UseableStuff_get_functionalityData);
    lua_setfield(L, -2, "functionalityData");
    lua_pushcfunction(L, UseableStuff_get_animation);
    lua_setfield(L, -2, "animation");
    lua_pushcfunction(L, UseableStuff_get_animationKO);
    lua_setfield(L, -2, "animationKO");
    lua_pushcfunction(L, UseableStuff_get_animationDazed);
    lua_setfield(L, -2, "animationDazed");
    lua_pushcfunction(L, UseableStuff_get_maxUseRange);
    lua_setfield(L, -2, "maxUseRange");
    lua_pushcfunction(L, UseableStuff_get_sfxTime);
    lua_setfield(L, -2, "sfxTime");
    lua_pushcfunction(L, UseableStuff_get_inventory);
    lua_setfield(L, -2, "inventory");
    lua_pushcfunction(L, UseableStuff_get_doorLock);
    lua_setfield(L, -2, "doorLock");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, UseableStuff_set_shopOwner);
    lua_setfield(L, -2, "shopOwner");
    lua_pushcfunction(L, UseableStuff_set_callbackOwner);
    lua_setfield(L, -2, "callbackOwner");
    lua_pushcfunction(L, UseableStuff_set_hasProgressBarWhenUsed);
    lua_setfield(L, -2, "hasProgressBarWhenUsed");
    lua_pushcfunction(L, UseableStuff_set_progressBarLevel);
    lua_setfield(L, -2, "progressBarLevel");
    lua_pushcfunction(L, UseableStuff_set_occupantSelection);
    lua_setfield(L, -2, "occupantSelection");
    lua_pushcfunction(L, UseableStuff_set_needsOperating);
    lua_setfield(L, -2, "needsOperating");
    lua_pushcfunction(L, UseableStuff_set_numOperatorsMax);
    lua_setfield(L, -2, "numOperatorsMax");
    lua_pushcfunction(L, UseableStuff_set_hungerRate);
    lua_setfield(L, -2, "hungerRate");
    lua_pushcfunction(L, UseableStuff_set__recievesBatteryPower);
    lua_setfield(L, -2, "_recievesBatteryPower");
    lua_pushcfunction(L, UseableStuff_set_powerOn);
    lua_setfield(L, -2, "powerOn");
    lua_pushcfunction(L, UseableStuff_set__isBroken);
    lua_setfield(L, -2, "_isBroken");
    lua_pushcfunction(L, UseableStuff_set_batteryOutputStat);
    lua_setfield(L, -2, "batteryOutputStat");
    lua_pushcfunction(L, UseableStuff_set__powerOutputMax);
    lua_setfield(L, -2, "_powerOutputMax");
    lua_pushcfunction(L, UseableStuff_set_currentPower);
    lua_setfield(L, -2, "currentPower");
    lua_pushcfunction(L, UseableStuff_set_powerTimeStored);
    lua_setfield(L, -2, "powerTimeStored");
    lua_pushcfunction(L, UseableStuff_set__powerTimeStoreMax);
    lua_setfield(L, -2, "_powerTimeStoreMax");
    lua_pushcfunction(L, UseableStuff_set_currentOperators);
    lua_setfield(L, -2, "currentOperators");
    lua_pushcfunction(L, UseableStuff_set_usesStat);
    lua_setfield(L, -2, "usesStat");
    lua_pushcfunction(L, UseableStuff_set_functionalityData);
    lua_setfield(L, -2, "functionalityData");
    lua_pushcfunction(L, UseableStuff_set_animation);
    lua_setfield(L, -2, "animation");
    lua_pushcfunction(L, UseableStuff_set_animationKO);
    lua_setfield(L, -2, "animationKO");
    lua_pushcfunction(L, UseableStuff_set_animationDazed);
    lua_setfield(L, -2, "animationDazed");
    lua_pushcfunction(L, UseableStuff_set_maxUseRange);
    lua_setfield(L, -2, "maxUseRange");
    lua_pushcfunction(L, UseableStuff_set_sfxTime);
    lua_setfield(L, -2, "sfxTime");
    lua_pushcfunction(L, UseableStuff_set_inventory);
    lua_setfield(L, -2, "inventory");
    lua_pushcfunction(L, UseableStuff_set_doorLock);
    lua_setfield(L, -2, "doorLock");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Building
    // setMetatableParent(L, UseableStuffBinding::getMetatableName(), BuildingBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
