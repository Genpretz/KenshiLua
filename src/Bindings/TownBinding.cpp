#include "pch.h"
#include "kenshi\Town.h"
#include "TownBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/Building/UseableStuffBinding.h"
#include "Bindings/Templates/LektorBinding.h"
#include "Bindings/Templates/OgreUnorderedBinding.h"
#include "Bindings/TradeCultureBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/InstanceIDBinding.h"

namespace KenshiLua
{

static Town* getB(lua_State* L, int idx)
{
    return checkObject<Town>(L, idx, TownBinding::getMetatableName());
}

// --- Getters for Town ---
static int Town_get_replacementTown(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    return pushObject<GameData>(L, b->replacementTown, GameDataBinding::getMetatableName());
}

static int Town_get_isAccessible(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lua_pushboolean(L, b->isAccessible ? 1 : 0);
    return 1;
}

static int Town_get_alarms(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lua_pushlightuserdata(L, (void*)b->alarms);
    return 1;
}

static int Town_get_instanceID(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    return pushObject<InstanceID>(L, &b->instanceID, InstanceIDBinding::getMetatableName());
}

static int Town_get_openToPublic(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lua_pushboolean(L, b->openToPublic ? 1 : 0);
    return 1;
}

static int Town_get_minFoliageRange(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lua_pushnumber(L, b->minFoliageRange);
    return 1;
}

static int Town_get_playerTownLevel(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lua_pushinteger(L, b->playerTownLevel);
    return 1;
}

static int Town_get_gates(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    return pushObject<ogre_unordered_set<hand>::type>(L, &b->gates, OgreUnorderedSetBinding<hand>::getMetatableName());
}

static int Town_get_playerHasBuildingsInThisTown(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lua_pushboolean(L, b->playerHasBuildingsInThisTown ? 1 : 0);
    return 1;
}

static int Town_get_powerInList(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lua_newtable(L);
    for (size_t i = 0; i < b->powerInList.size(); ++i) {
        handBinding::push(L, b->powerInList[i]);
        lua_rawseti(L, -2, (int)(i + 1));
    }
    return 1;
}

static int Town_get_powerOutList(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    return pushObject<ogre_unordered_set<hand>::type>(L, &b->powerOutList, OgreUnorderedSetBinding<hand>::getMetatableName());
}

static int Town_get_batteryList(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    return pushObject<ogre_unordered_set<hand>::type>(L, &b->batteryList, OgreUnorderedSetBinding<hand>::getMetatableName());
}

static int Town_get_batteryMode(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lua_pushboolean(L, b->batteryMode ? 1 : 0);
    return 1;
}

static int Town_get_power_Stat(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lua_pushnumber(L, b->power_Stat);
    return 1;
}

static int Town_get_maxPower_Stat(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lua_pushnumber(L, b->maxPower_Stat);
    return 1;
}

static int Town_get_neededPowerTotal_Stat(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lua_pushnumber(L, b->neededPowerTotal_Stat);
    return 1;
}

static int Town_get_batteryPowerTotal_Stat(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lua_pushnumber(L, b->batteryPowerTotal_Stat);
    return 1;
}

static int Town_get_batteryDrain_Stat(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lua_pushnumber(L, b->batteryDrain_Stat);
    return 1;
}

static int Town_get_batteryChargingupTotal(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lua_pushnumber(L, b->batteryChargingupTotal);
    return 1;
}

static int Town_get_batteryCharge_Stat(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lua_pushnumber(L, b->batteryCharge_Stat);
    return 1;
}

static int Town_get_batteryChargeMax_Stat(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lua_pushnumber(L, b->batteryChargeMax_Stat);
    return 1;
}

static int Town_get__facilitesWeHaveHere(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lua_pushinteger(L, (lua_Integer)b->_facilitesWeHaveHere.flags);
    return 1;
}

static int Town_get_tradeCulture(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    return pushObject<TradeCulture>(L, b->tradeCulture, TradeCultureBinding::getMetatableName());
}

static int Town_get_tradeGoodsMults(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    return pushObject<ogre_unordered_map<GameData*, float>::type>(L, &b->tradeGoodsMults, OgreUnorderedMapBinding<GameData*, float>::getMetatableName());
}

static int Town_get_buildingMaterial(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    return pushObject<GameData>(L, b->buildingMaterial, GameDataBinding::getMetatableName());
}

static int Town_get_distantTown(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lua_pushlightuserdata(L, (void*)b->distantTown);
    return 1;
}

static int Town_get_nestSpots(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lua_newtable(L);
    for (unsigned int i = 0; i < b->nestSpots.size(); ++i) {
        lua_newtable(L);
        pushVector3(L, b->nestSpots[i].pos);
        lua_setfield(L, -2, "pos");
        pushObject<GameData>(L, b->nestSpots[i].data, GameDataBinding::getMetatableName());
        lua_setfield(L, -2, "data");
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

static int Town_get_nestsLoaded(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lua_pushboolean(L, b->nestsLoaded ? 1 : 0);
    return 1;
}

static int Town_get_overrideRange(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lua_pushnumber(L, b->overrideRange);
    return 1;
}

static int Town_get_townRangeMultiplier(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lua_pushnumber(L, b->townRangeMultiplier);
    return 1;
}


// --- Setters for Town ---
static int Town_set_replacementTown(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    return luaL_error(L, "Read-only or unsupported setter type for replacementTown");
}

static int Town_set_isAccessible(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->isAccessible = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Town_set_alarms(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->alarms = (AlarmManager*)lua_touserdata(L, 2);
    return 0;
}

static int Town_set_instanceID(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    InstanceID* val = checkObject<InstanceID>(L, 2, InstanceIDBinding::getMetatableName());
    b->instanceID = *val;
    return 0;
}

static int Town_set_openToPublic(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->openToPublic = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Town_set_minFoliageRange(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->minFoliageRange = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Town_set_playerTownLevel(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->playerTownLevel = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Town_set_gates(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->gates = *checkObject<ogre_unordered_set<hand>::type>(L, 2, OgreUnorderedSetBinding<hand>::getMetatableName());
    return 0;
}

static int Town_set_playerHasBuildingsInThisTown(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->playerHasBuildingsInThisTown = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Town_set_powerInList(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    if (!lua_istable(L, 2)) return luaL_error(L, "Expected table for powerInList");
    b->powerInList.clear();
    lua_pushnil(L);
    while (lua_next(L, 2) != 0) {
        hand* h = checkObject<hand>(L, -1, handBinding::getMetatableName());
        b->powerInList.push_back(*h);
        lua_pop(L, 1);
    }
    return 0;
}

static int Town_set_powerOutList(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->powerOutList = *checkObject<ogre_unordered_set<hand>::type>(L, 2, OgreUnorderedSetBinding<hand>::getMetatableName());
    return 0;
}

static int Town_set_batteryList(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->batteryList = *checkObject<ogre_unordered_set<hand>::type>(L, 2, OgreUnorderedSetBinding<hand>::getMetatableName());
    return 0;
}

static int Town_set_batteryMode(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->batteryMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Town_set_power_Stat(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->power_Stat = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Town_set_maxPower_Stat(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->maxPower_Stat = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Town_set_neededPowerTotal_Stat(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->neededPowerTotal_Stat = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Town_set_batteryPowerTotal_Stat(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->batteryPowerTotal_Stat = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Town_set_batteryDrain_Stat(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->batteryDrain_Stat = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Town_set_batteryChargingupTotal(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->batteryChargingupTotal = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Town_set_batteryCharge_Stat(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->batteryCharge_Stat = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Town_set_batteryChargeMax_Stat(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->batteryChargeMax_Stat = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Town_set__facilitesWeHaveHere(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->_facilitesWeHaveHere.flags = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int Town_set_tradeCulture(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->tradeCulture = lua_isnoneornil(L, 2) ? nullptr : checkObject<TradeCulture>(L, 2, TradeCultureBinding::getMetatableName());
    return 0;
}

static int Town_set_tradeGoodsMults(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->tradeGoodsMults = *checkObject<ogre_unordered_map<GameData*, float>::type>(L, 2, OgreUnorderedMapBinding<GameData*, float>::getMetatableName());
    return 0;
}

static int Town_set_buildingMaterial(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->buildingMaterial = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int Town_set_distantTown(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->distantTown = (DistantTown*)lua_touserdata(L, 2);
    return 0;
}

static int Town_set_nestSpots(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    if (!lua_istable(L, 2)) return luaL_error(L, "Expected table for nestSpots");
    b->nestSpots.clear();
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
        lektor_push_back(b->nestSpots, spot);
        lua_pop(L, 1);
    }
    return 0;
}

static int Town_set_nestsLoaded(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->nestsLoaded = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Town_set_overrideRange(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->overrideRange = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Town_set_townRangeMultiplier(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    b->townRangeMultiplier = (float)luaL_checknumber(L, 2);
    return 0;
}

int TownBinding::_DESTRUCTOR(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    b->_DESTRUCTOR();
    return 0;
}

int TownBinding::initialiseResidentData(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    b->initialiseResidentData();
    return 0;
}

int TownBinding::getGameData(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    GameData* result = b->getGameData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int TownBinding::_NV_getGameData(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    GameData* result = b->_NV_getGameData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int TownBinding::getOriginalGameData(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    GameData* result = b->getOriginalGameData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int TownBinding::_reset(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    b->_reset();
    return 0;
}

int TownBinding::_NV__reset(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    b->_NV__reset();
    return 0;
}

int TownBinding::getDataType(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    itemType result = b->getDataType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TownBinding::_NV_getDataType(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    itemType result = b->_NV_getDataType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TownBinding::reassessTownPosition(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    b->reassessTownPosition();
    return 0;
}

int TownBinding::_NV_reassessTownPosition(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    b->_NV_reassessTownPosition();
    return 0;
}

int TownBinding::showDistantTown(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    bool vis = lua_toboolean(L, 2) != 0;
    b->showDistantTown(vis);
    return 0;
}

int TownBinding::isOutpost(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    bool result = b->isOutpost();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::spawnTheBarFlies(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    b->spawnTheBarFlies();
    return 0;
}

int TownBinding::townLoadedEvent(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    bool newGameFirstTime = lua_toboolean(L, 2) != 0;
    b->townLoadedEvent(newGameFirstTime);
    return 0;
}

int TownBinding::notifyUnloading(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    b->notifyUnloading();
    return 0;
}

int TownBinding::getBuildingMaterial(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    GameData* result = b->getBuildingMaterial();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int TownBinding::isTown(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    Town* result = b->isTown();
    return pushObject<Town>(L, result, TownBinding::getMetatableName());
}

int TownBinding::_NV_isTown(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    Town* result = b->_NV_isTown();
    return pushObject<Town>(L, result, TownBinding::getMetatableName());
}

int TownBinding::isPublic(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    bool result = b->isPublic();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::_NV_isPublic(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    bool result = b->_NV_isPublic();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::needsSaving(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    std::string mod = luaL_checkstring(L, 2);
    bool result = b->needsSaving(mod);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::_NV_needsSaving(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    std::string mod = luaL_checkstring(L, 2);
    bool result = b->_NV_needsSaving(mod);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::setPosition(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    b->setPosition(p);
    return 0;
}

int TownBinding::getRadius(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    float result = b->getRadius();
    lua_pushnumber(L, result);
    return 1;
}

int TownBinding::_NV_getRadius(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    float result = b->_NV_getRadius();
    lua_pushnumber(L, result);
    return 1;
}

int TownBinding::isActive(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    bool result = b->isActive();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::_NV_isActive(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    bool result = b->_NV_isActive();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::update(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    b->update();
    return 0;
}

int TownBinding::_NV_update(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    b->_NV_update();
    return 0;
}

int TownBinding::periodicUpdate(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    b->periodicUpdate();
    return 0;
}

int TownBinding::_NV_periodicUpdate(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    b->_NV_periodicUpdate();
    return 0;
}

int TownBinding::updatePowerGrid(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    b->updatePowerGrid();
    return 0;
}

int TownBinding::_NV_updatePowerGrid(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    b->_NV_updatePowerGrid();
    return 0;
}

int TownBinding::gatesAllClosed(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    bool result = b->gatesAllClosed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::_NV_gatesAllClosed(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    bool result = b->_NV_gatesAllClosed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::hasGates(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    bool result = b->hasGates();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::_NV_hasGates(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    bool result = b->_NV_hasGates();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::notifyAccesibility(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    bool accessible = lua_toboolean(L, 2) != 0;
    b->notifyAccesibility(accessible);
    return 0;
}

int TownBinding::getPositionOutsideTownGates(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    float dist = (float)luaL_checknumber(L, 2);
    Ogre::Vector3 result = b->getPositionOutsideTownGates(dist);
    pushVector3(L, result);
    return 1;
}

int TownBinding::_NV_getPositionOutsideTownGates(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    float dist = (float)luaL_checknumber(L, 2);
    Ogre::Vector3 result = b->_NV_getPositionOutsideTownGates(dist);
    pushVector3(L, result);
    return 1;
}

int TownBinding::isPlayerBuildingsInThisTown(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    bool result = b->isPlayerBuildingsInThisTown();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::setPlayerBuildingsInThisTown(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    b->setPlayerBuildingsInThisTown();
    return 0;
}

int TownBinding::getRequiredPower(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    float result = b->getRequiredPower();
    lua_pushnumber(L, result);
    return 1;
}

int TownBinding::getTotalPower(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    float result = b->getTotalPower();
    lua_pushnumber(L, result);
    return 1;
}

int TownBinding::hasSparePower(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    bool result = b->hasSparePower();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::getBatteryDrain(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    float result = b->getBatteryDrain();
    lua_pushnumber(L, result);
    return 1;
}

int TownBinding::getBatteryChargeMax(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    float result = b->getBatteryChargeMax();
    lua_pushnumber(L, result);
    return 1;
}

int TownBinding::getBatteryCharge(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    float result = b->getBatteryCharge();
    lua_pushnumber(L, result);
    return 1;
}

int TownBinding::getBatteryCharge01(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    float result = b->getBatteryCharge01();
    lua_pushnumber(L, result);
    return 1;
}

int TownBinding::getBatteryChargingUpAmount(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    float result = b->getBatteryChargingUpAmount();
    lua_pushnumber(L, result);
    return 1;
}

int TownBinding::getBatteryPowerTotal(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    float result = b->getBatteryPowerTotal();
    lua_pushnumber(L, result);
    return 1;
}

int TownBinding::isBatteryMode(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    bool result = b->isBatteryMode();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::clearNests(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    b->clearNests();
    return 0;
}

int TownBinding::getMapMarker(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    std::string result = b->getMapMarker();
    lua_pushstring(L, result.c_str());
    return 1;
}

int TownBinding::_NV_getMapMarker(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    std::string result = b->_NV_getMapMarker();
    lua_pushstring(L, result.c_str());
    return 1;
}

int TownBinding::getMapMarkerZoomLevel(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    MapZoomLevel result = b->getMapMarkerZoomLevel();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TownBinding::_NV_getMapMarkerZoomLevel(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    MapZoomLevel result = b->_NV_getMapMarkerZoomLevel();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TownBinding::recalculatePlayerTownLevel(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    b->recalculatePlayerTownLevel();
    return 0;
}

int TownBinding::deActivationCheck(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");

    b->deActivationCheck();
    return 0;
}

int TownBinding::_CONSTRUCTOR(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    GameData* data = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Town* result = b->_CONSTRUCTOR(data);
    return pushObject<Town>(L, result, TownBinding::getMetatableName());
}

int TownBinding::notifyRepopulation(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    GameData* other = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    b->notifyRepopulation(other);
    return 0;
}

int TownBinding::isMyOldHomeTownStillValid(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    GameData* other = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = b->isMyOldHomeTownStillValid(other);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::setup(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    GameData* town = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Ogre::Vector3 pos;
    readVector3(L, 3, pos);
    hand* h = checkObject<hand>(L, 4, handBinding::getMetatableName());
    if (!h) return luaL_error(L, "hand is nil");
    b->setup(town, pos, *h);
    return 0;
}

int TownBinding::_NV_setup(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    GameData* town = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Ogre::Vector3 pos;
    readVector3(L, 3, pos);
    hand* h = checkObject<hand>(L, 4, handBinding::getMetatableName());
    if (!h) return luaL_error(L, "hand is nil");
    b->_NV_setup(town, pos, *h);
    return 0;
}

int TownBinding::getAlarmMgr(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    AlarmManager* result = b->getAlarmMgr();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TownBinding::_NV_getAlarmMgr(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    AlarmManager* result = b->_NV_getAlarmMgr();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TownBinding::_setMainResident(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    Building* building = lua_isnoneornil(L, 2) ? nullptr : checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    GameData* residents = lua_isnoneornil(L, 3) ? nullptr : checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    bool forceForGates = lua_toboolean(L, 4) != 0;
    bool result = b->_setMainResident(building, residents, forceForGates);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBinding::chooseResidents(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lektor<Building*>* buildings = LektorPtrBinding<Building*>::get(L, 2);
    b->chooseResidents(*buildings);
    return 0;
}

int TownBinding::chooseBuildingForResident(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    lektor<Building*>* buildings = LektorPtrBinding<Building*>::get(L, 2);
    TownBase::ResidentData* resident = checkObject<TownBase::ResidentData>(L, 3, "KenshiLua.ResidentData");
    Building* result = b->chooseBuildingForResident(*buildings, resident);
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}

/*
Skipped methods needing manual binding:
  line 372: void setHandle(...) - unsupported arg type
  line 373: void _NV_setHandle(...) - unsupported arg type
  line 375: float getLocalTradePriceMult(...) - unsupported arg type
  line 376: float getFactionTradeCultureMult(...) - unsupported arg type
  line 380: Nest* isNest(...) - unsupported return type
  line 381: Nest* _NV_isNest(...) - unsupported return type
  line 384: void getGUIData(...) - unsupported arg type
  line 385: void _NV_getGUIData(...) - unsupported arg type
  line 386: void saveState(...) - unsupported arg type
  line 387: void _NV_saveState(...) - unsupported arg type
  line 388: void loadState(...) - unsupported arg type
  line 389: void _NV_loadState(...) - unsupported arg type
  line 390: GameSaveState serialise(...) - unsupported return type
  line 391: GameSaveState _NV_serialise(...) - unsupported return type
  line 392: void loadFromSerialise(...) - unsupported arg type
  line 393: void _NV_loadFromSerialise(...) - unsupported arg type
  line 397: void saveStateEditor(...) - unsupported arg type
  line 398: void _NV_saveStateEditor(...) - unsupported arg type
  line 399: void loadStateEditor(...) - unsupported arg type
  line 400: void _NV_loadStateEditor(...) - unsupported arg type
  line 411: bool hasResidentHQ(...) - unsupported arg type
  line 412: bool _NV_hasResidentHQ(...) - unsupported arg type
  line 413: void addGate(...) - unsupported arg type
  line 414: void _NV_addGate(...) - unsupported arg type
  line 421: GatewayBuilding* getNearestGate(...) - unsupported return type
  line 422: GatewayBuilding* _NV_getNearestGate(...) - unsupported return type
  line 439: void addNest(...) - unsupported arg type
  line 440: bool removeNest(...) - unsupported arg type
  line 452: TownType getPlayerTownTypeEnum(...) - unsupported return type
  line 453: TagsClass<BuildingDesignation> facilitesWeHaveHere(...) - unsupported return type
  line 456: bool drainBattery(...) - unsupported arg type
  line 472: void _initialiseResidentData(...) - unsupported arg type
*/

static int Town_addBuilding(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    UseableStuff* building = checkObject<UseableStuff>(L, 2, UseableStuffBinding::getMetatableName());
    bool powerIn = lua_toboolean(L, 3) != 0;
    bool powerOut = lua_toboolean(L, 4) != 0;
    bool battery = lua_toboolean(L, 5) != 0;
    b->addBuilding(building, powerIn, powerOut, battery);
    return 0;
}

static int Town_removeBuilding(lua_State* L)
{
    Town* b = getB(L, 1);
    if (!b) return luaL_error(L, "Town is nil");
    UseableStuff* building = checkObject<UseableStuff>(L, 2, UseableStuffBinding::getMetatableName());
    b->removeBuilding(building);
    return 0;
}

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

void TownBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TownBinding::gc },
        { "__tostring", TownBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", TownBinding::_DESTRUCTOR },
        { "initialiseResidentData", TownBinding::initialiseResidentData },
        { "getGameData", TownBinding::getGameData },
        { "_NV_getGameData", TownBinding::_NV_getGameData },
        { "getOriginalGameData", TownBinding::getOriginalGameData },
        { "_reset", TownBinding::_reset },
        { "_NV__reset", TownBinding::_NV__reset },
        { "getDataType", TownBinding::getDataType },
        { "_NV_getDataType", TownBinding::_NV_getDataType },
        { "reassessTownPosition", TownBinding::reassessTownPosition },
        { "_NV_reassessTownPosition", TownBinding::_NV_reassessTownPosition },
        { "showDistantTown", TownBinding::showDistantTown },
        { "isOutpost", TownBinding::isOutpost },
        { "spawnTheBarFlies", TownBinding::spawnTheBarFlies },
        { "townLoadedEvent", TownBinding::townLoadedEvent },
        { "notifyUnloading", TownBinding::notifyUnloading },
        { "getBuildingMaterial", TownBinding::getBuildingMaterial },
        { "isTown", TownBinding::isTown },
        { "_NV_isTown", TownBinding::_NV_isTown },
        { "isPublic", TownBinding::isPublic },
        { "_NV_isPublic", TownBinding::_NV_isPublic },
        { "needsSaving", TownBinding::needsSaving },
        { "_NV_needsSaving", TownBinding::_NV_needsSaving },
        { "setPosition", TownBinding::setPosition },
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
        { "gatesAllClosed", TownBinding::gatesAllClosed },
        { "_NV_gatesAllClosed", TownBinding::_NV_gatesAllClosed },
        { "hasGates", TownBinding::hasGates },
        { "_NV_hasGates", TownBinding::_NV_hasGates },
        { "notifyAccesibility", TownBinding::notifyAccesibility },
        { "getPositionOutsideTownGates", TownBinding::getPositionOutsideTownGates },
        { "_NV_getPositionOutsideTownGates", TownBinding::_NV_getPositionOutsideTownGates },
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
        { "clearNests", TownBinding::clearNests },
        { "getMapMarker", TownBinding::getMapMarker },
        { "_NV_getMapMarker", TownBinding::_NV_getMapMarker },
        { "getMapMarkerZoomLevel", TownBinding::getMapMarkerZoomLevel },
        { "_NV_getMapMarkerZoomLevel", TownBinding::_NV_getMapMarkerZoomLevel },
        { "recalculatePlayerTownLevel", TownBinding::recalculatePlayerTownLevel },
        { "deActivationCheck", TownBinding::deActivationCheck },
        { "addBuilding", Town_addBuilding },
        { "removeBuilding", Town_removeBuilding },
        { "_CONSTRUCTOR", TownBinding::_CONSTRUCTOR },
        { "notifyRepopulation", TownBinding::notifyRepopulation },
        { "isMyOldHomeTownStillValid", TownBinding::isMyOldHomeTownStillValid },
        { "setup", TownBinding::setup },
        { "_NV_setup", TownBinding::_NV_setup },
        { "getAlarmMgr", TownBinding::getAlarmMgr },
        { "_NV_getAlarmMgr", TownBinding::_NV_getAlarmMgr },
        { "_setMainResident", TownBinding::_setMainResident },
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
    lua_pushcfunction(L, Town_get_replacementTown);
    lua_setfield(L, -2, "replacementTown");
    lua_pushcfunction(L, Town_get_isAccessible);
    lua_setfield(L, -2, "isAccessible");
    lua_pushcfunction(L, Town_get_alarms);
    lua_setfield(L, -2, "alarms");
    lua_pushcfunction(L, Town_get_instanceID);
    lua_setfield(L, -2, "instanceID");
    lua_pushcfunction(L, Town_get_openToPublic);
    lua_setfield(L, -2, "openToPublic");
    lua_pushcfunction(L, Town_get_minFoliageRange);
    lua_setfield(L, -2, "minFoliageRange");
    lua_pushcfunction(L, Town_get_playerTownLevel);
    lua_setfield(L, -2, "playerTownLevel");
    lua_pushcfunction(L, Town_get_gates);
    lua_setfield(L, -2, "gates");
    lua_pushcfunction(L, Town_get_playerHasBuildingsInThisTown);
    lua_setfield(L, -2, "playerHasBuildingsInThisTown");
    lua_pushcfunction(L, Town_get_powerInList);
    lua_setfield(L, -2, "powerInList");
    lua_pushcfunction(L, Town_get_powerOutList);
    lua_setfield(L, -2, "powerOutList");
    lua_pushcfunction(L, Town_get_batteryList);
    lua_setfield(L, -2, "batteryList");
    lua_pushcfunction(L, Town_get_batteryMode);
    lua_setfield(L, -2, "batteryMode");
    lua_pushcfunction(L, Town_get_power_Stat);
    lua_setfield(L, -2, "power_Stat");
    lua_pushcfunction(L, Town_get_maxPower_Stat);
    lua_setfield(L, -2, "maxPower_Stat");
    lua_pushcfunction(L, Town_get_neededPowerTotal_Stat);
    lua_setfield(L, -2, "neededPowerTotal_Stat");
    lua_pushcfunction(L, Town_get_batteryPowerTotal_Stat);
    lua_setfield(L, -2, "batteryPowerTotal_Stat");
    lua_pushcfunction(L, Town_get_batteryDrain_Stat);
    lua_setfield(L, -2, "batteryDrain_Stat");
    lua_pushcfunction(L, Town_get_batteryChargingupTotal);
    lua_setfield(L, -2, "batteryChargingupTotal");
    lua_pushcfunction(L, Town_get_batteryCharge_Stat);
    lua_setfield(L, -2, "batteryCharge_Stat");
    lua_pushcfunction(L, Town_get_batteryChargeMax_Stat);
    lua_setfield(L, -2, "batteryChargeMax_Stat");
    lua_pushcfunction(L, Town_get__facilitesWeHaveHere);
    lua_setfield(L, -2, "_facilitesWeHaveHere");
    lua_pushcfunction(L, Town_get_tradeCulture);
    lua_setfield(L, -2, "tradeCulture");
    lua_pushcfunction(L, Town_get_tradeGoodsMults);
    lua_setfield(L, -2, "tradeGoodsMults");
    lua_pushcfunction(L, Town_get_buildingMaterial);
    lua_setfield(L, -2, "buildingMaterial");
    lua_pushcfunction(L, Town_get_distantTown);
    lua_setfield(L, -2, "distantTown");
    lua_pushcfunction(L, Town_get_nestSpots);
    lua_setfield(L, -2, "nestSpots");
    lua_pushcfunction(L, Town_get_nestsLoaded);
    lua_setfield(L, -2, "nestsLoaded");
    lua_pushcfunction(L, Town_get_overrideRange);
    lua_setfield(L, -2, "overrideRange");
    lua_pushcfunction(L, Town_get_townRangeMultiplier);
    lua_setfield(L, -2, "townRangeMultiplier");
    lua_pushcfunction(L, Town_get_alarms);
    lua_setfield(L, -2, "alarms");
    lua_pushcfunction(L, Town_get_instanceID);
    lua_setfield(L, -2, "instanceID");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, Town_set_replacementTown);
    lua_setfield(L, -2, "replacementTown");
    lua_pushcfunction(L, Town_set_isAccessible);
    lua_setfield(L, -2, "isAccessible");
    lua_pushcfunction(L, Town_set_alarms);
    lua_setfield(L, -2, "alarms");
    lua_pushcfunction(L, Town_set_instanceID);
    lua_setfield(L, -2, "instanceID");
    lua_pushcfunction(L, Town_set_openToPublic);
    lua_setfield(L, -2, "openToPublic");
    lua_pushcfunction(L, Town_set_minFoliageRange);
    lua_setfield(L, -2, "minFoliageRange");
    lua_pushcfunction(L, Town_set_playerTownLevel);
    lua_setfield(L, -2, "playerTownLevel");
    lua_pushcfunction(L, Town_set_gates);
    lua_setfield(L, -2, "gates");
    lua_pushcfunction(L, Town_set_playerHasBuildingsInThisTown);
    lua_setfield(L, -2, "playerHasBuildingsInThisTown");
    lua_pushcfunction(L, Town_set_powerInList);
    lua_setfield(L, -2, "powerInList");
    lua_pushcfunction(L, Town_set_powerOutList);
    lua_setfield(L, -2, "powerOutList");
    lua_pushcfunction(L, Town_set_batteryList);
    lua_setfield(L, -2, "batteryList");
    lua_pushcfunction(L, Town_set_batteryMode);
    lua_setfield(L, -2, "batteryMode");
    lua_pushcfunction(L, Town_set_power_Stat);
    lua_setfield(L, -2, "power_Stat");
    lua_pushcfunction(L, Town_set_maxPower_Stat);
    lua_setfield(L, -2, "maxPower_Stat");
    lua_pushcfunction(L, Town_set_neededPowerTotal_Stat);
    lua_setfield(L, -2, "neededPowerTotal_Stat");
    lua_pushcfunction(L, Town_set_batteryPowerTotal_Stat);
    lua_setfield(L, -2, "batteryPowerTotal_Stat");
    lua_pushcfunction(L, Town_set_batteryDrain_Stat);
    lua_setfield(L, -2, "batteryDrain_Stat");
    lua_pushcfunction(L, Town_set_batteryChargingupTotal);
    lua_setfield(L, -2, "batteryChargingupTotal");
    lua_pushcfunction(L, Town_set_batteryCharge_Stat);
    lua_setfield(L, -2, "batteryCharge_Stat");
    lua_pushcfunction(L, Town_set_batteryChargeMax_Stat);
    lua_setfield(L, -2, "batteryChargeMax_Stat");
    lua_pushcfunction(L, Town_set__facilitesWeHaveHere);
    lua_setfield(L, -2, "_facilitesWeHaveHere");
    lua_pushcfunction(L, Town_set_tradeCulture);
    lua_setfield(L, -2, "tradeCulture");
    lua_pushcfunction(L, Town_set_tradeGoodsMults);
    lua_setfield(L, -2, "tradeGoodsMults");
    lua_pushcfunction(L, Town_set_buildingMaterial);
    lua_setfield(L, -2, "buildingMaterial");
    lua_pushcfunction(L, Town_set_distantTown);
    lua_setfield(L, -2, "distantTown");
    lua_pushcfunction(L, Town_set_nestSpots);
    lua_setfield(L, -2, "nestSpots");
    lua_pushcfunction(L, Town_set_nestsLoaded);
    lua_setfield(L, -2, "nestsLoaded");
    lua_pushcfunction(L, Town_set_overrideRange);
    lua_setfield(L, -2, "overrideRange");
    lua_pushcfunction(L, Town_set_townRangeMultiplier);
    lua_setfield(L, -2, "townRangeMultiplier");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
