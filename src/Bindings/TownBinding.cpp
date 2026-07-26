#include "pch.h"
#include "kenshi\Town.h"
#include "TownBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/Building/GatewayBuildingBinding.h"
#include "Bindings/InstanceIDBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/TradeCultureBinding.h"
#include "Bindings/Building/UseableStuffBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"

namespace KenshiLua
{

static Town* getInstance(lua_State* L, int idx)
{
    return checkObject<Town>(L, idx, TownBinding::getMetatableName());
}

// --- Getters for Town ---
static int Town_get_replacementTown(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    return pushObject<GameData>(L, instance->replacementTown, GameDataBinding::getMetatableName());
}

static int Town_get_isAccessible(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lua_pushboolean(L, instance->isAccessible ? 1 : 0);
    return 1;
}

static int Town_get_alarms(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lua_pushlightuserdata(L, (void*)instance->alarms);
    return 1;
}

static int Town_get_instanceID(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    return pushObject<InstanceID>(L, &instance->instanceID, InstanceIDBinding::getMetatableName());
}

static int Town_get_openToPublic(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lua_pushboolean(L, instance->openToPublic ? 1 : 0);
    return 1;
}

static int Town_get_minFoliageRange(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lua_pushnumber(L, instance->minFoliageRange);
    return 1;
}

static int Town_get_playerTownLevel(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lua_pushinteger(L, instance->playerTownLevel);
    return 1;
}

static int Town_get_playerHasBuildingsInThisTown(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lua_pushboolean(L, instance->playerHasBuildingsInThisTown ? 1 : 0);
    return 1;
}

static int Town_get_batteryMode(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lua_pushboolean(L, instance->batteryMode ? 1 : 0);
    return 1;
}

static int Town_get_power_Stat(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lua_pushnumber(L, instance->power_Stat);
    return 1;
}

static int Town_get_maxPower_Stat(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lua_pushnumber(L, instance->maxPower_Stat);
    return 1;
}

static int Town_get_neededPowerTotal_Stat(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lua_pushnumber(L, instance->neededPowerTotal_Stat);
    return 1;
}

static int Town_get_batteryPowerTotal_Stat(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lua_pushnumber(L, instance->batteryPowerTotal_Stat);
    return 1;
}

static int Town_get_batteryDrain_Stat(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lua_pushnumber(L, instance->batteryDrain_Stat);
    return 1;
}

static int Town_get_batteryChargingupTotal(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lua_pushnumber(L, instance->batteryChargingupTotal);
    return 1;
}

static int Town_get_batteryCharge_Stat(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lua_pushnumber(L, instance->batteryCharge_Stat);
    return 1;
}

static int Town_get_batteryChargeMax_Stat(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lua_pushnumber(L, instance->batteryChargeMax_Stat);
    return 1;
}

static int Town_get_tradeCulture(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    return pushObject<TradeCulture>(L, instance->tradeCulture, TradeCultureBinding::getMetatableName());
}

static int Town_get_buildingMaterial(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    return pushObject<GameData>(L, instance->buildingMaterial, GameDataBinding::getMetatableName());
}

static int Town_get_distantTown(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lua_pushlightuserdata(L, (void*)instance->distantTown);
    return 1;
}

static int Town_get_nestsLoaded(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lua_pushboolean(L, instance->nestsLoaded ? 1 : 0);
    return 1;
}

static int Town_get_overrideRange(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lua_pushnumber(L, instance->overrideRange);
    return 1;
}

static int Town_get_townRangeMultiplier(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lua_pushnumber(L, instance->townRangeMultiplier);
    return 1;
}

// --- Setters for Town ---
static int Town_set_replacementTown(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->replacementTown = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int Town_set_isAccessible(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->isAccessible = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Town_set_instanceID(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->instanceID = *checkObject<InstanceID>(L, 2, InstanceIDBinding::getMetatableName());
    return 0;
}

static int Town_set_openToPublic(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->openToPublic = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Town_set_minFoliageRange(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->minFoliageRange = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Town_set_playerTownLevel(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->playerTownLevel = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Town_set_playerHasBuildingsInThisTown(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->playerHasBuildingsInThisTown = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Town_set_batteryMode(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->batteryMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Town_set_power_Stat(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->power_Stat = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Town_set_maxPower_Stat(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->maxPower_Stat = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Town_set_neededPowerTotal_Stat(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->neededPowerTotal_Stat = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Town_set_batteryPowerTotal_Stat(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->batteryPowerTotal_Stat = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Town_set_batteryDrain_Stat(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->batteryDrain_Stat = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Town_set_batteryChargingupTotal(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->batteryChargingupTotal = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Town_set_batteryCharge_Stat(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->batteryCharge_Stat = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Town_set_batteryChargeMax_Stat(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->batteryChargeMax_Stat = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Town_set_tradeCulture(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->tradeCulture = lua_isnoneornil(L, 2) ? nullptr : checkObject<TradeCulture>(L, 2, TradeCultureBinding::getMetatableName());
    return 0;
}

static int Town_set_buildingMaterial(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->buildingMaterial = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int Town_set_nestsLoaded(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->nestsLoaded = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Town_set_overrideRange(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->overrideRange = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Town_set_townRangeMultiplier(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->townRangeMultiplier = (float)luaL_checknumber(L, 2);
    return 0;
}

int TownBinding::_CONSTRUCTOR(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Town* result = instance->_CONSTRUCTOR(d);
    return pushObject<Town>(L, result, TownBinding::getMetatableName());
}

int TownBinding::_DESTRUCTOR(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int TownBinding::initialiseResidentData(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    instance->initialiseResidentData();
    return 0;
}

int TownBinding::getGameData(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    GameData* result = instance->getGameData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int TownBinding::_NV_getGameData(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    GameData* result = instance->_NV_getGameData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int TownBinding::getOriginalGameData(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    GameData* result = instance->getOriginalGameData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int TownBinding::notifyRepopulation(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    GameData* newTowndata = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->notifyRepopulation(newTowndata);
    return 0;
}

int TownBinding::isMyOldHomeTownStillValid(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    GameData* myHomeTown = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->isMyOldHomeTownStillValid(myHomeTown);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::setup(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    GameData* _town = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Ogre::Vector3 _pos;
    readVector3(L, 3, _pos);
    hand h = *checkObject<hand>(L, 4, handBinding::getMetatableName());
    instance->setup(_town, _pos, h);
    return 0;
}

int TownBinding::_NV_setup(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    GameData* _town = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Ogre::Vector3 _pos;
    readVector3(L, 3, _pos);
    hand h = *checkObject<hand>(L, 4, handBinding::getMetatableName());
    instance->_NV_setup(_town, _pos, h);
    return 0;
}

int TownBinding::_reset(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    instance->_reset();
    return 0;
}

int TownBinding::_NV__reset(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    instance->_NV__reset();
    return 0;
}

int TownBinding::getDataType(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    itemType result = instance->getDataType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TownBinding::_NV_getDataType(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    itemType result = instance->_NV_getDataType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TownBinding::reassessTownPosition(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    instance->reassessTownPosition();
    return 0;
}

int TownBinding::_NV_reassessTownPosition(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    instance->_NV_reassessTownPosition();
    return 0;
}

int TownBinding::showDistantTown(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    bool vis = lua_toboolean(L, 2) != 0;
    instance->showDistantTown(vis);
    return 0;
}

int TownBinding::getAlarmMgr(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    AlarmManager* result = instance->getAlarmMgr();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TownBinding::_NV_getAlarmMgr(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    AlarmManager* result = instance->_NV_getAlarmMgr();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TownBinding::isOutpost(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    bool result = instance->isOutpost();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::_setMainResident(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    Building* building = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    GameData* residents = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    bool forceForGates = lua_toboolean(L, 4) != 0;
    bool result = instance->_setMainResident(building, residents, forceForGates);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::spawnTheBarFlies(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    instance->spawnTheBarFlies();
    return 0;
}

int TownBinding::townLoadedEvent(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    bool newGameFirstTime = lua_toboolean(L, 2) != 0;
    instance->townLoadedEvent(newGameFirstTime);
    return 0;
}

int TownBinding::notifyUnloading(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    instance->notifyUnloading();
    return 0;
}

int TownBinding::getBuildingMaterial(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    GameData* result = instance->getBuildingMaterial();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int TownBinding::getLocalTradePriceMult(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    float result = instance->getLocalTradePriceMult(item);
    lua_pushnumber(L, result);
    return 1;
}

int TownBinding::getFactionTradeCultureMult(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    float result = instance->getFactionTradeCultureMult(item);
    lua_pushnumber(L, result);
    return 1;
}

int TownBinding::isTown(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    Town* result = instance->isTown();
    return pushObject<Town>(L, result, TownBinding::getMetatableName());
}

int TownBinding::_NV_isTown(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    Town* result = instance->_NV_isTown();
    return pushObject<Town>(L, result, TownBinding::getMetatableName());
}

int TownBinding::isNest(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    Nest* result = instance->isNest();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TownBinding::_NV_isNest(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    Nest* result = instance->_NV_isNest();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TownBinding::isPublic(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    bool result = instance->isPublic();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::_NV_isPublic(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    bool result = instance->_NV_isPublic();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::getGUIData(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIData(panel, category);
    return 0;
}

int TownBinding::_NV_getGUIData(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIData(panel, category);
    return 0;
}

int TownBinding::saveState(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->saveState(state);
    return 0;
}

int TownBinding::_NV_saveState(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_NV_saveState(state);
    return 0;
}

int TownBinding::loadState(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->loadState(state);
    return 0;
}

int TownBinding::_NV_loadState(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_NV_loadState(state);
    return 0;
}

int TownBinding::loadFromSerialise(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->loadFromSerialise(state);
    return 0;
}

int TownBinding::_NV_loadFromSerialise(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->_NV_loadFromSerialise(state);
    return 0;
}

int TownBinding::needsSaving(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    const std::string mod = luaL_checkstring(L, 2);
    bool result = instance->needsSaving(mod);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::_NV_needsSaving(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    const std::string mod = luaL_checkstring(L, 2);
    bool result = instance->_NV_needsSaving(mod);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::setPosition(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    instance->setPosition(p);
    return 0;
}

int TownBinding::saveStateEditor(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->saveStateEditor(state);
    return 0;
}

int TownBinding::_NV_saveStateEditor(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_NV_saveStateEditor(state);
    return 0;
}

int TownBinding::loadStateEditor(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->loadStateEditor(state);
    return 0;
}

int TownBinding::_NV_loadStateEditor(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_NV_loadStateEditor(state);
    return 0;
}

int TownBinding::getRadius(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    float result = instance->getRadius();
    lua_pushnumber(L, result);
    return 1;
}

int TownBinding::_NV_getRadius(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    float result = instance->_NV_getRadius();
    lua_pushnumber(L, result);
    return 1;
}

int TownBinding::isActive(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    bool result = instance->isActive();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::_NV_isActive(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    bool result = instance->_NV_isActive();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::update(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    instance->update();
    return 0;
}

int TownBinding::_NV_update(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    instance->_NV_update();
    return 0;
}

int TownBinding::periodicUpdate(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    instance->periodicUpdate();
    return 0;
}

int TownBinding::_NV_periodicUpdate(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    instance->_NV_periodicUpdate();
    return 0;
}

int TownBinding::updatePowerGrid(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    instance->updatePowerGrid();
    return 0;
}

int TownBinding::_NV_updatePowerGrid(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    instance->_NV_updatePowerGrid();
    return 0;
}

int TownBinding::hasResidentHQ(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    bool result = instance->hasResidentHQ(f);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::_NV_hasResidentHQ(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    bool result = instance->_NV_hasResidentHQ(f);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::gatesAllClosed(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    bool result = instance->gatesAllClosed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::_NV_gatesAllClosed(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    bool result = instance->_NV_gatesAllClosed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::hasGates(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    bool result = instance->hasGates();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::_NV_hasGates(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    bool result = instance->_NV_hasGates();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::notifyAccesibility(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    bool accessible = lua_toboolean(L, 2) != 0;
    instance->notifyAccesibility(accessible);
    return 0;
}

int TownBinding::getNearestGate(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    Ogre::Vector3 to;
    readVector3(L, 2, to);
    GatewayBuilding* result = instance->getNearestGate(to);
    return pushObject<GatewayBuilding>(L, result, GatewayBuildingBinding::getMetatableName());
}

int TownBinding::_NV_getNearestGate(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    Ogre::Vector3 to;
    readVector3(L, 2, to);
    GatewayBuilding* result = instance->_NV_getNearestGate(to);
    return pushObject<GatewayBuilding>(L, result, GatewayBuildingBinding::getMetatableName());
}

int TownBinding::getPositionOutsideTownGates(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    float dist = (float)luaL_checknumber(L, 2);
    Ogre::Vector3 result = instance->getPositionOutsideTownGates(dist);
    pushVector3(L, result);
    return 1;
}

int TownBinding::_NV_getPositionOutsideTownGates(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    float dist = (float)luaL_checknumber(L, 2);
    Ogre::Vector3 result = instance->_NV_getPositionOutsideTownGates(dist);
    pushVector3(L, result);
    return 1;
}

int TownBinding::addBuilding(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    UseableStuff* b = checkObject<UseableStuff>(L, 2, UseableStuffBinding::getMetatableName());
    bool powerIn = lua_toboolean(L, 3) != 0;
    bool powerOut = lua_toboolean(L, 4) != 0;
    bool battery = lua_toboolean(L, 5) != 0;
    instance->addBuilding(b, powerIn, powerOut, battery);
    return 0;
}

int TownBinding::removeBuilding(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    UseableStuff* b = checkObject<UseableStuff>(L, 2, UseableStuffBinding::getMetatableName());
    instance->removeBuilding(b);
    return 0;
}

int TownBinding::isPlayerBuildingsInThisTown(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    bool result = instance->isPlayerBuildingsInThisTown();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::setPlayerBuildingsInThisTown(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    instance->setPlayerBuildingsInThisTown();
    return 0;
}

int TownBinding::getRequiredPower(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    float result = instance->getRequiredPower();
    lua_pushnumber(L, result);
    return 1;
}

int TownBinding::getTotalPower(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    float result = instance->getTotalPower();
    lua_pushnumber(L, result);
    return 1;
}

int TownBinding::hasSparePower(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    bool result = instance->hasSparePower();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::getBatteryDrain(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    float result = instance->getBatteryDrain();
    lua_pushnumber(L, result);
    return 1;
}

int TownBinding::getBatteryChargeMax(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    float result = instance->getBatteryChargeMax();
    lua_pushnumber(L, result);
    return 1;
}

int TownBinding::getBatteryCharge(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    float result = instance->getBatteryCharge();
    lua_pushnumber(L, result);
    return 1;
}

int TownBinding::getBatteryCharge01(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    float result = instance->getBatteryCharge01();
    lua_pushnumber(L, result);
    return 1;
}

int TownBinding::getBatteryChargingUpAmount(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    float result = instance->getBatteryChargingUpAmount();
    lua_pushnumber(L, result);
    return 1;
}

int TownBinding::getBatteryPowerTotal(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    float result = instance->getBatteryPowerTotal();
    lua_pushnumber(L, result);
    return 1;
}

int TownBinding::isBatteryMode(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    bool result = instance->isBatteryMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::addNest(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    GameData* nestInfo = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Ogre::Vector3 pos;
    readVector3(L, 3, pos);
    Building* keepInside = checkObject<Building>(L, 4, BuildingBinding::getMetatableName());
    instance->addNest(nestInfo, pos, keepInside);
    return 0;
}

int TownBinding::removeNest(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    Building* b = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    bool result = instance->removeNest(b);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::clearNests(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    instance->clearNests();
    return 0;
}

int TownBinding::getMapMarker(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    std::string result = instance->getMapMarker();
    lua_pushstring(L, result.c_str());
    return 1;
}

int TownBinding::_NV_getMapMarker(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    std::string result = instance->_NV_getMapMarker();
    lua_pushstring(L, result.c_str());
    return 1;
}

int TownBinding::getMapMarkerZoomLevel(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    MapZoomLevel result = instance->getMapMarkerZoomLevel();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TownBinding::_NV_getMapMarkerZoomLevel(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    MapZoomLevel result = instance->_NV_getMapMarkerZoomLevel();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TownBinding::recalculatePlayerTownLevel(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    instance->recalculatePlayerTownLevel();
    return 0;
}

int TownBinding::deActivationCheck(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    instance->deActivationCheck();
    return 0;
}

int TownBinding::_initialiseResidentData(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");

    GameData* residentSourceData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_initialiseResidentData(residentSourceData);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 367: void chooseResidents(...) - unsupported arg type
  line 369: Building* chooseBuildingForResident(...) - unsupported arg type
  line 372: void setHandle(...) - non-string reference arg
  line 373: void _NV_setHandle(...) - non-string reference arg
  line 390: GameSaveState serialise(...) - unsupported arg type
  line 391: GameSaveState _NV_serialise(...) - unsupported arg type
  line 413: void addGate(...) - non-string reference arg
  line 414: void _NV_addGate(...) - non-string reference arg
  line 452: TownType getPlayerTownTypeEnum(...) - unsupported return type
  line 453: TagsClass<BuildingDesignation> facilitesWeHaveHere(...) - unsupported return type
  line 455: bool powerBuilding(...) - non-string reference arg
  line 456: bool drainBattery(...) - non-string reference arg
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - Town_get_alarms: AlarmManager* (unbound pointer)
  - Town_get_distantTown: DistantTown* (unbound pointer)
  - TownBinding::getAlarmMgr: AlarmManager* (unbound pointer)
  - TownBinding::_NV_getAlarmMgr: AlarmManager* (unbound pointer)
  - TownBinding::isNest: Nest* (unbound pointer)
  - TownBinding::_NV_isNest: Nest* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 457: gates (ogre_unordered_set<hand>::type) - unsupported type
  line 459: powerInList (Ogre::FastArray<hand>) - unsupported type
  line 460: powerOutList (ogre_unordered_set<hand>::type) - unsupported type
  line 461: batteryList (ogre_unordered_set<hand>::type) - unsupported type
  line 471: _facilitesWeHaveHere (TagsClass<BuildingDesignation>) - unsupported type
  line 474: tradeGoodsMults (ogre_unordered_map<GameData*, float>::type) - unsupported type
  line 488: nestSpots (lektor<Town::NestSpot>) - unsupported type
*/

int TownBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TownBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Town object");
    return 1;
}



static int Town_addBuilding(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    UseableStuff* building = checkObject<UseableStuff>(L, 2, UseableStuffBinding::getMetatableName());
    bool powerIn = lua_toboolean(L, 3) != 0;
    bool powerOut = lua_toboolean(L, 4) != 0;
    bool battery = lua_toboolean(L, 5) != 0;
    instance->addBuilding(building, powerIn, powerOut, battery);
    return 0;
}


static int Town_get__facilitesWeHaveHere(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lua_pushinteger(L, (lua_Integer)instance->_facilitesWeHaveHere.flags);
    return 1;
}


static int Town_get_batteryList(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    return pushObject<ogre_unordered_set<hand>::type>(L, &instance->batteryList, OgreUnorderedSetBinding<hand>::getMetatableName());
}


static int Town_get_gates(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    return pushObject<ogre_unordered_set<hand>::type>(L, &instance->gates, OgreUnorderedSetBinding<hand>::getMetatableName());
}


static int Town_get_nestSpots(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lua_newtable(L);
    for (unsigned int i = 0; i < instance->nestSpots.size(); ++i) {
        lua_newtable(L);
        pushVector3(L, instance->nestSpots[i].pos);
        lua_setfield(L, -2, "pos");
        pushObject<GameData>(L, instance->nestSpots[i].data, GameDataBinding::getMetatableName());
        lua_setfield(L, -2, "data");
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}


static int Town_get_powerInList(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lua_newtable(L);
    for (size_t i = 0; i < instance->powerInList.size(); ++i) {
        handBinding::push(L, instance->powerInList[i]);
        lua_rawseti(L, -2, (int)(i + 1));
    }
    return 1;
}


static int Town_get_powerOutList(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    return pushObject<ogre_unordered_set<hand>::type>(L, &instance->powerOutList, OgreUnorderedSetBinding<hand>::getMetatableName());
}


static int Town_get_tradeGoodsMults(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    return pushObject<ogre_unordered_map<GameData*, float>::type>(L, &instance->tradeGoodsMults, OgreUnorderedMapBinding<GameData*, float>::getMetatableName());
}


static int Town_removeBuilding(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    UseableStuff* building = checkObject<UseableStuff>(L, 2, UseableStuffBinding::getMetatableName());
    instance->removeBuilding(building);
    return 0;
}


static int Town_set__facilitesWeHaveHere(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->_facilitesWeHaveHere.flags = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}


static int Town_set_alarms(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->alarms = (AlarmManager*)lua_touserdata(L, 2);
    return 0;
}


static int Town_set_batteryList(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->batteryList = *checkObject<ogre_unordered_set<hand>::type>(L, 2, OgreUnorderedSetBinding<hand>::getMetatableName());
    return 0;
}


static int Town_set_distantTown(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->distantTown = (DistantTown*)lua_touserdata(L, 2);
    return 0;
}


static int Town_set_gates(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->gates = *checkObject<ogre_unordered_set<hand>::type>(L, 2, OgreUnorderedSetBinding<hand>::getMetatableName());
    return 0;
}


static int Town_set_nestSpots(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    if (!lua_istable(L, 2)) return luaL_error(L, "Expected table for nestSpots");
    instance->nestSpots.clear();
    lua_pushnil(L);
    while (lua_next(L, 2) != 0) {
        if (!lua_istable(L, -1)) return luaL_error(L, "Expected table entry in nestSpots list");
        Town::NestSpot spot;
        lua_getfield(L, -1, "pos");
        readVector3(L, -1, spot.pos);
        lua_pop(L, 1);
        lua_getfield(L, -1, "data");
        spot.data = lua_isnoneornil(L, -1) ? nullptr : checkObject<GameData>(L, -1, GameDataBinding::getMetatableName());
        lua_pop(L, 1);
        lektor_push_back(instance->nestSpots, spot);
        lua_pop(L, 1);
    }
    return 0;
}


static int Town_set_powerInList(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    if (!lua_istable(L, 2)) return luaL_error(L, "Expected table for powerInList");
    instance->powerInList.clear();
    lua_pushnil(L);
    while (lua_next(L, 2) != 0) {
        hand* h = checkObject<hand>(L, -1, handBinding::getMetatableName());
        instance->powerInList.push_back(*h);
        lua_pop(L, 1);
    }
    return 0;
}


static int Town_set_powerOutList(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->powerOutList = *checkObject<ogre_unordered_set<hand>::type>(L, 2, OgreUnorderedSetBinding<hand>::getMetatableName());
    return 0;
}


static int Town_set_tradeGoodsMults(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    instance->tradeGoodsMults = *checkObject<ogre_unordered_map<GameData*, float>::type>(L, 2, OgreUnorderedMapBinding<GameData*, float>::getMetatableName());
    return 0;
}


int TownBinding::chooseBuildingForResident(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lektor<Building*>* buildings = LektorPtrBinding<Building*>::get(L, 2);
    TownBase::ResidentData* resident = checkObject<TownBase::ResidentData>(L, 3, "KenshiLua.ResidentData");
    Building* result = instance->chooseBuildingForResident(*buildings, resident);
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}


int TownBinding::chooseResidents(lua_State* L)
{
    Town* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Town is nil");
    lektor<Building*>* buildings = LektorPtrBinding<Building*>::get(L, 2);
    instance->chooseResidents(*buildings);
    return 0;
}


void TownBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TownBinding::gc },
        { "__tostring", TownBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", TownBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", TownBinding::_DESTRUCTOR },
        { "initialiseResidentData", TownBinding::initialiseResidentData },
        { "getGameData", TownBinding::getGameData },
        { "_NV_getGameData", TownBinding::_NV_getGameData },
        { "getOriginalGameData", TownBinding::getOriginalGameData },
        { "notifyRepopulation", TownBinding::notifyRepopulation },
        { "isMyOldHomeTownStillValid", TownBinding::isMyOldHomeTownStillValid },
        { "setup", TownBinding::setup },
        { "_NV_setup", TownBinding::_NV_setup },
        { "_reset", TownBinding::_reset },
        { "_NV__reset", TownBinding::_NV__reset },
        { "getDataType", TownBinding::getDataType },
        { "_NV_getDataType", TownBinding::_NV_getDataType },
        { "reassessTownPosition", TownBinding::reassessTownPosition },
        { "_NV_reassessTownPosition", TownBinding::_NV_reassessTownPosition },
        { "showDistantTown", TownBinding::showDistantTown },
        { "getAlarmMgr", TownBinding::getAlarmMgr },
        { "_NV_getAlarmMgr", TownBinding::_NV_getAlarmMgr },
        { "isOutpost", TownBinding::isOutpost },
        { "_setMainResident", TownBinding::_setMainResident },
        { "spawnTheBarFlies", TownBinding::spawnTheBarFlies },
        { "townLoadedEvent", TownBinding::townLoadedEvent },
        { "notifyUnloading", TownBinding::notifyUnloading },
        { "getBuildingMaterial", TownBinding::getBuildingMaterial },
        { "getLocalTradePriceMult", TownBinding::getLocalTradePriceMult },
        { "getFactionTradeCultureMult", TownBinding::getFactionTradeCultureMult },
        { "isTown", TownBinding::isTown },
        { "_NV_isTown", TownBinding::_NV_isTown },
        { "isNest", TownBinding::isNest },
        { "_NV_isNest", TownBinding::_NV_isNest },
        { "isPublic", TownBinding::isPublic },
        { "_NV_isPublic", TownBinding::_NV_isPublic },
        { "getGUIData", TownBinding::getGUIData },
        { "_NV_getGUIData", TownBinding::_NV_getGUIData },
        { "saveState", TownBinding::saveState },
        { "_NV_saveState", TownBinding::_NV_saveState },
        { "loadState", TownBinding::loadState },
        { "_NV_loadState", TownBinding::_NV_loadState },
        { "loadFromSerialise", TownBinding::loadFromSerialise },
        { "_NV_loadFromSerialise", TownBinding::_NV_loadFromSerialise },
        { "needsSaving", TownBinding::needsSaving },
        { "_NV_needsSaving", TownBinding::_NV_needsSaving },
        { "setPosition", TownBinding::setPosition },
        { "saveStateEditor", TownBinding::saveStateEditor },
        { "_NV_saveStateEditor", TownBinding::_NV_saveStateEditor },
        { "loadStateEditor", TownBinding::loadStateEditor },
        { "_NV_loadStateEditor", TownBinding::_NV_loadStateEditor },
        { "getRadius", TownBinding::getRadius },
        { "_NV_getRadius", TownBinding::_NV_getRadius },
        { "isActive", TownBinding::isActive },
        { "_NV_isActive", TownBinding::_NV_isActive },
        { "update", TownBinding::update },
        { "_NV_update", TownBinding::_NV_update },
        { "periodicUpdate", TownBinding::periodicUpdate },
        { "_NV_periodicUpdate", TownBinding::_NV_periodicUpdate },
        { "updatePowerGrid", TownBinding::updatePowerGrid },
        { "_NV_updatePowerGrid", TownBinding::_NV_updatePowerGrid },
        { "hasResidentHQ", TownBinding::hasResidentHQ },
        { "_NV_hasResidentHQ", TownBinding::_NV_hasResidentHQ },
        { "gatesAllClosed", TownBinding::gatesAllClosed },
        { "_NV_gatesAllClosed", TownBinding::_NV_gatesAllClosed },
        { "hasGates", TownBinding::hasGates },
        { "_NV_hasGates", TownBinding::_NV_hasGates },
        { "notifyAccesibility", TownBinding::notifyAccesibility },
        { "getNearestGate", TownBinding::getNearestGate },
        { "_NV_getNearestGate", TownBinding::_NV_getNearestGate },
        { "getPositionOutsideTownGates", TownBinding::getPositionOutsideTownGates },
        { "_NV_getPositionOutsideTownGates", TownBinding::_NV_getPositionOutsideTownGates },
        { "addBuilding", TownBinding::addBuilding },
        { "removeBuilding", TownBinding::removeBuilding },
        { "isPlayerBuildingsInThisTown", TownBinding::isPlayerBuildingsInThisTown },
        { "setPlayerBuildingsInThisTown", TownBinding::setPlayerBuildingsInThisTown },
        { "getRequiredPower", TownBinding::getRequiredPower },
        { "getTotalPower", TownBinding::getTotalPower },
        { "hasSparePower", TownBinding::hasSparePower },
        { "getBatteryDrain", TownBinding::getBatteryDrain },
        { "getBatteryChargeMax", TownBinding::getBatteryChargeMax },
        { "getBatteryCharge", TownBinding::getBatteryCharge },
        { "getBatteryCharge01", TownBinding::getBatteryCharge01 },
        { "getBatteryChargingUpAmount", TownBinding::getBatteryChargingUpAmount },
        { "getBatteryPowerTotal", TownBinding::getBatteryPowerTotal },
        { "isBatteryMode", TownBinding::isBatteryMode },
        { "addNest", TownBinding::addNest },
        { "removeNest", TownBinding::removeNest },
        { "clearNests", TownBinding::clearNests },
        { "getMapMarker", TownBinding::getMapMarker },
        { "_NV_getMapMarker", TownBinding::_NV_getMapMarker },
        { "getMapMarkerZoomLevel", TownBinding::getMapMarkerZoomLevel },
        { "_NV_getMapMarkerZoomLevel", TownBinding::_NV_getMapMarkerZoomLevel },
        { "recalculatePlayerTownLevel", TownBinding::recalculatePlayerTownLevel },
        { "deActivationCheck", TownBinding::deActivationCheck },
        { "_initialiseResidentData", TownBinding::_initialiseResidentData },
                { "chooseResidents", TownBinding::chooseResidents },
        { "chooseBuildingForResident", TownBinding::chooseBuildingForResident },
        { 0, 0 }
    };

    registerClass(
        L, 
        TownBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TownBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "replacementTown", Town_get_replacementTown);
    registerGetter(L, "isAccessible", Town_get_isAccessible);
    registerGetter(L, "alarms", Town_get_alarms);
    registerGetter(L, "instanceID", Town_get_instanceID);
    registerGetter(L, "openToPublic", Town_get_openToPublic);
    registerGetter(L, "minFoliageRange", Town_get_minFoliageRange);
    registerGetter(L, "playerTownLevel", Town_get_playerTownLevel);
    registerGetter(L, "playerHasBuildingsInThisTown", Town_get_playerHasBuildingsInThisTown);
    registerGetter(L, "batteryMode", Town_get_batteryMode);
    registerGetter(L, "power_Stat", Town_get_power_Stat);
    registerGetter(L, "maxPower_Stat", Town_get_maxPower_Stat);
    registerGetter(L, "neededPowerTotal_Stat", Town_get_neededPowerTotal_Stat);
    registerGetter(L, "batteryPowerTotal_Stat", Town_get_batteryPowerTotal_Stat);
    registerGetter(L, "batteryDrain_Stat", Town_get_batteryDrain_Stat);
    registerGetter(L, "batteryChargingupTotal", Town_get_batteryChargingupTotal);
    registerGetter(L, "batteryCharge_Stat", Town_get_batteryCharge_Stat);
    registerGetter(L, "batteryChargeMax_Stat", Town_get_batteryChargeMax_Stat);
    registerGetter(L, "tradeCulture", Town_get_tradeCulture);
    registerGetter(L, "buildingMaterial", Town_get_buildingMaterial);
    registerGetter(L, "distantTown", Town_get_distantTown);
    registerGetter(L, "nestsLoaded", Town_get_nestsLoaded);
    registerGetter(L, "overrideRange", Town_get_overrideRange);
    registerGetter(L, "townRangeMultiplier", Town_get_townRangeMultiplier);
    registerGetter(L, "_facilitesWeHaveHere", Town_get__facilitesWeHaveHere);
    registerGetter(L, "batteryList", Town_get_batteryList);
    registerGetter(L, "gates", Town_get_gates);
    registerGetter(L, "nestSpots", Town_get_nestSpots);
    registerGetter(L, "powerInList", Town_get_powerInList);
    registerGetter(L, "powerOutList", Town_get_powerOutList);
    registerGetter(L, "tradeGoodsMults", Town_get_tradeGoodsMults);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "replacementTown", Town_set_replacementTown);
    registerSetter(L, "isAccessible", Town_set_isAccessible);
    registerSetter(L, "instanceID", Town_set_instanceID);
    registerSetter(L, "openToPublic", Town_set_openToPublic);
    registerSetter(L, "minFoliageRange", Town_set_minFoliageRange);
    registerSetter(L, "playerTownLevel", Town_set_playerTownLevel);
    registerSetter(L, "playerHasBuildingsInThisTown", Town_set_playerHasBuildingsInThisTown);
    registerSetter(L, "batteryMode", Town_set_batteryMode);
    registerSetter(L, "power_Stat", Town_set_power_Stat);
    registerSetter(L, "maxPower_Stat", Town_set_maxPower_Stat);
    registerSetter(L, "neededPowerTotal_Stat", Town_set_neededPowerTotal_Stat);
    registerSetter(L, "batteryPowerTotal_Stat", Town_set_batteryPowerTotal_Stat);
    registerSetter(L, "batteryDrain_Stat", Town_set_batteryDrain_Stat);
    registerSetter(L, "batteryChargingupTotal", Town_set_batteryChargingupTotal);
    registerSetter(L, "batteryCharge_Stat", Town_set_batteryCharge_Stat);
    registerSetter(L, "batteryChargeMax_Stat", Town_set_batteryChargeMax_Stat);
    registerSetter(L, "tradeCulture", Town_set_tradeCulture);
    registerSetter(L, "buildingMaterial", Town_set_buildingMaterial);
    registerSetter(L, "nestsLoaded", Town_set_nestsLoaded);
    registerSetter(L, "overrideRange", Town_set_overrideRange);
    registerSetter(L, "townRangeMultiplier", Town_set_townRangeMultiplier);
    registerSetter(L, "_facilitesWeHaveHere", Town_set__facilitesWeHaveHere);
    registerSetter(L, "alarms", Town_set_alarms);
    registerSetter(L, "batteryList", Town_set_batteryList);
    registerSetter(L, "distantTown", Town_set_distantTown);
    registerSetter(L, "gates", Town_set_gates);
    registerSetter(L, "nestSpots", Town_set_nestSpots);
    registerSetter(L, "powerInList", Town_set_powerInList);
    registerSetter(L, "powerOutList", Town_set_powerOutList);
    registerSetter(L, "tradeGoodsMults", Town_set_tradeGoodsMults);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to TownBase
    setMetatableParent(L, TownBinding::getMetatableName(), TownBaseBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua