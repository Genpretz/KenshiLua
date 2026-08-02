#include "pch.h"
#include "kenshi\Town.h"
#include "TownBaseBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/Building/GatewayBuildingBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/Gui/ScreenLabelBinding.h"
#include "Bindings/Util/TimeOfDayBinding.h"
#include "Bindings/TownBinding.h"
#include "Bindings/TownBuildingsManagerBinding.h"
#include "Bindings/TownPositionCacherBinding.h"
#include "Bindings/ZoneMapBinding.h"
#include "Bindings/EnumBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"

namespace KenshiLua
{

static TownBase* getInstance(lua_State* L, int idx)
{
    return checkObject<TownBase>(L, idx, TownBaseBinding::getMetatableName());
}

// --- Getters for TownBase ---
static int TownBase_get_positionCacher(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    return pushObject<TownPositionCacher>(L, &instance->positionCacher, TownPositionCacherBinding::getMetatableName());
}

static int TownBase_get_population(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    lua_pushlightuserdata(L, (void*)instance->population);
    return 1;
}

static int TownBase_get_alreadyInitialisedPopulationParams(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    lua_pushboolean(L, instance->alreadyInitialisedPopulationParams ? 1 : 0);
    return 1;
}

static int TownBase_get_isSecret(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    lua_pushboolean(L, instance->isSecret ? 1 : 0);
    return 1;
}

static int TownBase_get_timeOfDeath(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    return pushObject<TimeOfDay>(L, &instance->timeOfDeath, TimeOfDayBinding::getMetatableName());
}

static int TownBase_get_p_TIME(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    lua_pushnumber(L, instance->p_TIME);
    return 1;
}

static int TownBase_get_nestBatcher(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    lua_pushlightuserdata(L, (void*)instance->nestBatcher);
    return 1;
}

static int TownBase_get_unexploredName(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    lua_pushstring(L, instance->unexploredName.c_str());
    return 1;
}

static int TownBase_get_discovered(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    lua_pushboolean(L, instance->discovered ? 1 : 0);
    return 1;
}

static int TownBase_get_explored(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    lua_pushboolean(L, instance->explored ? 1 : 0);
    return 1;
}

static int TownBase_get_recentlyDiscovered(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    lua_pushboolean(L, instance->recentlyDiscovered ? 1 : 0);
    return 1;
}

static int TownBase_get_entityMarker(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    lua_pushlightuserdata(L, (void*)instance->entityMarker);
    return 1;
}

static int TownBase_get_entityLabel(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    return pushObject<ScreenLabel>(L, instance->entityLabel, ScreenLabelBinding::getMetatableName());
}

static int TownBase_get_clickHull(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    lua_pushlightuserdata(L, (void*)instance->clickHull);
    return 1;
}

static int TownBase_get_biome(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    lua_pushlightuserdata(L, (void*)instance->biome);
    return 1;
}

static int TownBase_get_isActivated(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    lua_pushboolean(L, instance->isActivated ? 1 : 0);
    return 1;
}

static int TownBase_get_currentFloorVisibility(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    lua_pushinteger(L, instance->currentFloorVisibility);
    return 1;
}

static int TownBase_get_buildingsManager(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    return pushObject<TownBuildingsManager>(L, &instance->buildingsManager, TownBuildingsManagerBinding::getMetatableName());
}

static int TownBase_get_defaultResident(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    return pushObject<GameData>(L, instance->defaultResident, GameDataBinding::getMetatableName());
}

// --- Setters for TownBase ---
static int TownBase_set_positionCacher(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    instance->positionCacher = *checkObject<TownPositionCacher>(L, 2, TownPositionCacherBinding::getMetatableName());
    return 0;
}

static int TownBase_set_alreadyInitialisedPopulationParams(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    instance->alreadyInitialisedPopulationParams = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TownBase_set_isSecret(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    instance->isSecret = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TownBase_set_timeOfDeath(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    instance->timeOfDeath = *checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    return 0;
}

static int TownBase_set_p_TIME(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    instance->p_TIME = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TownBase_set_unexploredName(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    instance->unexploredName = luaL_checkstring(L, 2);
    return 0;
}

static int TownBase_set_discovered(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    instance->discovered = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TownBase_set_explored(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    instance->explored = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TownBase_set_recentlyDiscovered(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    instance->recentlyDiscovered = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TownBase_set_entityLabel(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    instance->entityLabel = lua_isnoneornil(L, 2) ? nullptr : checkObject<ScreenLabel>(L, 2, ScreenLabelBinding::getMetatableName());
    return 0;
}

static int TownBase_set_isActivated(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    instance->isActivated = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TownBase_set_currentFloorVisibility(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    instance->currentFloorVisibility = (unsigned char)luaL_checkinteger(L, 2);
    return 0;
}

static int TownBase_set_buildingsManager(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    instance->buildingsManager = *checkObject<TownBuildingsManager>(L, 2, TownBuildingsManagerBinding::getMetatableName());
    return 0;
}

static int TownBase_set_defaultResident(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    instance->defaultResident = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

int TownBaseBinding::_CONSTRUCTOR(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    TownBase* result = instance->_CONSTRUCTOR(d);
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int TownBaseBinding::_DESTRUCTOR(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int TownBaseBinding::activate(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    ZoneMap* zone = checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    instance->activate(zone);
    return 0;
}

int TownBaseBinding::_NV_activate(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    ZoneMap* zone = checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    instance->_NV_activate(zone);
    return 0;
}

int TownBaseBinding::isActive(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->isActive();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_isActive(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->_NV_isActive();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::setup(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    GameData* _town = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Ogre::Vector3 _pos;
    readVector3(L, 3, _pos);
    hand h = *checkObject<hand>(L, 4, HandBinding::getMetatableName());
    instance->setup(_town, _pos, h);
    return 0;
}

int TownBaseBinding::_NV_setup(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    GameData* _town = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Ogre::Vector3 _pos;
    readVector3(L, 3, _pos);
    hand h = *checkObject<hand>(L, 4, HandBinding::getMetatableName());
    instance->_NV_setup(_town, _pos, h);
    return 0;
}

int TownBaseBinding::_reset(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    instance->_reset();
    return 0;
}

int TownBaseBinding::_NV__reset(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    instance->_NV__reset();
    return 0;
}

int TownBaseBinding::getKnownName(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    std::string result = instance->getKnownName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int TownBaseBinding::reassessTownPosition(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    instance->reassessTownPosition();
    return 0;
}

int TownBaseBinding::_NV_reassessTownPosition(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    instance->_NV_reassessTownPosition();
    return 0;
}

int TownBaseBinding::isNotFriendly(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->isNotFriendly();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_isNotFriendly(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->_NV_isNotFriendly();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::isPhysical(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->isPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_isPhysical(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->_NV_isPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::setVisible(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setVisible(on);
    return 0;
}

int TownBaseBinding::_NV_setVisible(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_setVisible(on);
    return 0;
}

int TownBaseBinding::getDataType(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    itemType result = instance->getDataType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TownBaseBinding::_NV_getDataType(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    itemType result = instance->_NV_getDataType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TownBaseBinding::isTown(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    Town* result = instance->isTown();
    return pushObject<Town>(L, result, TownBinding::getMetatableName());
}

int TownBaseBinding::_NV_isTown(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    Town* result = instance->_NV_isTown();
    return pushObject<Town>(L, result, TownBinding::getMetatableName());
}

int TownBaseBinding::isNest(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    Nest* result = instance->isNest();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TownBaseBinding::nestUpThisSpot(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    GameData* nestInfo = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Ogre::Vector3 pos;
    readVector3(L, 3, pos);
    Building* keepInside = checkObject<Building>(L, 4, BuildingBinding::getMetatableName());
    instance->nestUpThisSpot(nestInfo, pos, keepInside);
    return 0;
}

int TownBaseBinding::_NV_nestUpThisSpot(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    GameData* nestInfo = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Ogre::Vector3 pos;
    readVector3(L, 3, pos);
    Building* keepInside = checkObject<Building>(L, 4, BuildingBinding::getMetatableName());
    instance->_NV_nestUpThisSpot(nestInfo, pos, keepInside);
    return 0;
}

int TownBaseBinding::loadFromSerialise(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->loadFromSerialise(state);
    return 0;
}

int TownBaseBinding::_NV_loadFromSerialise(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->_NV_loadFromSerialise(state);
    return 0;
}

int TownBaseBinding::isOutpost(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->isOutpost();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::withinBordersRange(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    float mult = (float)luaL_checknumber(L, 3);
    bool result = instance->withinBordersRange(p, mult);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::withinDiscoveryRange(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    bool explored = lua_toboolean(L, 3) != 0;
    bool result = instance->withinDiscoveryRange(p, explored);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::isIllegal(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    Item* what = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool result = instance->isIllegal(what);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_isIllegal(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    Item* what = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool result = instance->_NV_isIllegal(what);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::distanceTo(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    Ogre::Vector3 to;
    readVector3(L, 2, to);
    float result = instance->distanceTo(to);
    lua_pushnumber(L, result);
    return 1;
}

int TownBaseBinding::squaredDistanceTo(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    Ogre::Vector3 to;
    readVector3(L, 2, to);
    float result = instance->squaredDistanceTo(to);
    lua_pushnumber(L, result);
    return 1;
}

int TownBaseBinding::isDead(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->isDead();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_isDead(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->_NV_isDead();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::getPositionOutsideTownGates(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    float dist = (float)luaL_checknumber(L, 2);
    Ogre::Vector3 result = instance->getPositionOutsideTownGates(dist);
    pushVector3(L, result);
    return 1;
}

int TownBaseBinding::_NV_getPositionOutsideTownGates(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    float dist = (float)luaL_checknumber(L, 2);
    Ogre::Vector3 result = instance->_NV_getPositionOutsideTownGates(dist);
    pushVector3(L, result);
    return 1;
}

int TownBaseBinding::setFaction(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    Faction* faction = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    ActivePlatoon* _a2 = checkObject<ActivePlatoon>(L, 3, ActivePlatoonBinding::getMetatableName());
    instance->setFaction(faction, _a2);
    return 0;
}

int TownBaseBinding::_NV_setFaction(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    Faction* faction = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    ActivePlatoon* _a2 = checkObject<ActivePlatoon>(L, 3, ActivePlatoonBinding::getMetatableName());
    instance->_NV_setFaction(faction, _a2);
    return 0;
}

int TownBaseBinding::isPublic(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->isPublic();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_isPublic(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->_NV_isPublic();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::getRadius(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    float result = instance->getRadius();
    lua_pushnumber(L, result);
    return 1;
}

int TownBaseBinding::_NV_getRadius(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    float result = instance->_NV_getRadius();
    lua_pushnumber(L, result);
    return 1;
}

int TownBaseBinding::getGUIData(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    DatapanelGUI* _a1 = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIData(_a1, category);
    return 0;
}

int TownBaseBinding::_NV_getGUIData(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    DatapanelGUI* _a1 = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIData(_a1, category);
    return 0;
}

int TownBaseBinding::saveState(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->saveState(state);
    return 0;
}

int TownBaseBinding::_NV_saveState(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_NV_saveState(state);
    return 0;
}

int TownBaseBinding::loadState(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->loadState(state);
    return 0;
}

int TownBaseBinding::_NV_loadState(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_NV_loadState(state);
    return 0;
}

int TownBaseBinding::update(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    instance->update();
    return 0;
}

int TownBaseBinding::_NV_update(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    instance->_NV_update();
    return 0;
}

int TownBaseBinding::periodicUpdate(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    instance->periodicUpdate();
    return 0;
}

int TownBaseBinding::_NV_periodicUpdate(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    instance->_NV_periodicUpdate();
    return 0;
}

int TownBaseBinding::updatePowerGrid(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    instance->updatePowerGrid();
    return 0;
}

int TownBaseBinding::_NV_updatePowerGrid(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    instance->_NV_updatePowerGrid();
    return 0;
}

int TownBaseBinding::hasResidentHQ(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    bool result = instance->hasResidentHQ(f);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_hasResidentHQ(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    bool result = instance->_NV_hasResidentHQ(f);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::findAllBuildingsOfType(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    BuildingDesignation func = (BuildingDesignation)luaL_checkinteger(L, 2);
    Character* me = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    lektor<Building*>* result = instance->findAllBuildingsOfType(func, me);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TownBaseBinding::_NV_findAllBuildingsOfType(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    BuildingDesignation func = (BuildingDesignation)luaL_checkinteger(L, 2);
    Character* me = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    lektor<Building*>* result = instance->_NV_findAllBuildingsOfType(func, me);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TownBaseBinding::findAllBuildingsWithFunction(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    BuildingFunction func = (BuildingFunction)luaL_checkinteger(L, 2);
    Character* me = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    lektor<Building*>* result = instance->findAllBuildingsWithFunction(func, me);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TownBaseBinding::_NV_findAllBuildingsWithFunction(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    BuildingFunction func = (BuildingFunction)luaL_checkinteger(L, 2);
    Character* me = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    lektor<Building*>* result = instance->_NV_findAllBuildingsWithFunction(func, me);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TownBaseBinding::allBuildingsDoorsOpen(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->allBuildingsDoorsOpen();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_allBuildingsDoorsOpen(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->_NV_allBuildingsDoorsOpen();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::destroyPhysical(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    instance->destroyPhysical();
    return 0;
}

int TownBaseBinding::_NV_destroyPhysical(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    instance->_NV_destroyPhysical();
    return 0;
}

int TownBaseBinding::getPosition(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    Ogre::Vector3 result = instance->getPosition();
    pushVector3(L, result);
    return 1;
}

int TownBaseBinding::_NV_getPosition(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    Ogre::Vector3 result = instance->_NV_getPosition();
    pushVector3(L, result);
    return 1;
}

int TownBaseBinding::getPositionForWaypoint(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    Ogre::Vector3 from;
    readVector3(L, 2, from);
    Ogre::Vector3 result = instance->getPositionForWaypoint(from);
    pushVector3(L, result);
    return 1;
}

int TownBaseBinding::_NV_getPositionForWaypoint(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    Ogre::Vector3 from;
    readVector3(L, 2, from);
    Ogre::Vector3 result = instance->_NV_getPositionForWaypoint(from);
    pushVector3(L, result);
    return 1;
}

int TownBaseBinding::createPhysical(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_createPhysical(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->_NV_createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::getAlarmMgr(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    AlarmManager* result = instance->getAlarmMgr();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TownBaseBinding::_NV_getAlarmMgr(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    AlarmManager* result = instance->_NV_getAlarmMgr();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TownBaseBinding::hasGates(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->hasGates();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_hasGates(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->_NV_hasGates();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::gatesAllClosed(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->gatesAllClosed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_gatesAllClosed(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->_NV_gatesAllClosed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::getNearestGate(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    Ogre::Vector3 to;
    readVector3(L, 2, to);
    GatewayBuilding* result = instance->getNearestGate(to);
    return pushObject<GatewayBuilding>(L, result, GatewayBuildingBinding::getMetatableName());
}

int TownBaseBinding::_NV_getNearestGate(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    Ogre::Vector3 to;
    readVector3(L, 2, to);
    GatewayBuilding* result = instance->_NV_getNearestGate(to);
    return pushObject<GatewayBuilding>(L, result, GatewayBuildingBinding::getMetatableName());
}

int TownBaseBinding::getBiome(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    AreaBiomeGroup* result = instance->getBiome();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TownBaseBinding::_NV_getBiome(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    AreaBiomeGroup* result = instance->_NV_getBiome();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TownBaseBinding::isRecentlyDiscovered(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->isRecentlyDiscovered();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_isRecentlyDiscovered(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->_NV_isRecentlyDiscovered();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::setRecentlyDiscovered(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->setRecentlyDiscovered(value);
    return 0;
}

int TownBaseBinding::_NV_setRecentlyDiscovered(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->_NV_setRecentlyDiscovered(value);
    return 0;
}

int TownBaseBinding::isDiscovered(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->isDiscovered();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_isDiscovered(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->_NV_isDiscovered();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::setDiscovered(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->setDiscovered(value);
    return 0;
}

int TownBaseBinding::_NV_setDiscovered(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->_NV_setDiscovered(value);
    return 0;
}

int TownBaseBinding::setDead(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    instance->setDead();
    return 0;
}

int TownBaseBinding::_NV_setDead(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    instance->_NV_setDead();
    return 0;
}

int TownBaseBinding::isExplored(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->isExplored();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_isExplored(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->_NV_isExplored();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::setExplored(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->setExplored(value);
    return 0;
}

int TownBaseBinding::_NV_setExplored(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->_NV_setExplored(value);
    return 0;
}

int TownBaseBinding::getItemArtifactsMinValue(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    unsigned int result = instance->getItemArtifactsMinValue();
    lua_pushinteger(L, result);
    return 1;
}

int TownBaseBinding::_NV_getItemArtifactsMinValue(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    unsigned int result = instance->_NV_getItemArtifactsMinValue();
    lua_pushinteger(L, result);
    return 1;
}

int TownBaseBinding::getItemArtifactsMaxValue(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    unsigned int result = instance->getItemArtifactsMaxValue();
    lua_pushinteger(L, result);
    return 1;
}

int TownBaseBinding::_NV_getItemArtifactsMaxValue(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    unsigned int result = instance->_NV_getItemArtifactsMaxValue();
    lua_pushinteger(L, result);
    return 1;
}

int TownBaseBinding::getGearArtifactsMinValue(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    unsigned int result = instance->getGearArtifactsMinValue();
    lua_pushinteger(L, result);
    return 1;
}

int TownBaseBinding::_NV_getGearArtifactsMinValue(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    unsigned int result = instance->_NV_getGearArtifactsMinValue();
    lua_pushinteger(L, result);
    return 1;
}

int TownBaseBinding::getGearArtifactsMaxValue(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    unsigned int result = instance->getGearArtifactsMaxValue();
    lua_pushinteger(L, result);
    return 1;
}

int TownBaseBinding::_NV_getGearArtifactsMaxValue(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    unsigned int result = instance->_NV_getGearArtifactsMaxValue();
    lua_pushinteger(L, result);
    return 1;
}

int TownBaseBinding::setZonePopulated(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    ZoneMap* zoneMap = checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    instance->setZonePopulated(zoneMap);
    return 0;
}

int TownBaseBinding::getBuildingsManager(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    TownBuildingsManager* result = instance->getBuildingsManager();
    return pushObject<TownBuildingsManager>(L, result, TownBuildingsManagerBinding::getMetatableName());
}

int TownBaseBinding::getBuildingFloorVisibility(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    Building* building = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    int result = instance->getBuildingFloorVisibility(building);
    lua_pushinteger(L, result);
    return 1;
}

int TownBaseBinding::setBuildingsFloorVisibility(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    Building* building = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    int floor = (int)luaL_checkinteger(L, 3);
    instance->setBuildingsFloorVisibility(building, floor);
    return 0;
}

int TownBaseBinding::resetBuildingsFloorVisibility(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    instance->resetBuildingsFloorVisibility();
    return 0;
}

int TownBaseBinding::getTownFloorVisiblity(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    int result = instance->getTownFloorVisiblity();
    lua_pushinteger(L, result);
    return 1;
}

int TownBaseBinding::setTownFloorVisiblity(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    int floor = (int)luaL_checkinteger(L, 2);
    bool onlyPlayerBuildings = lua_toboolean(L, 3) != 0;
    instance->setTownFloorVisiblity(floor, onlyPlayerBuildings);
    return 0;
}

int TownBaseBinding::resetTownFloorVisibility(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    instance->resetTownFloorVisibility();
    return 0;
}

int TownBaseBinding::getCurrentTownLocation(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    TownBase* result = instance->getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int TownBaseBinding::_NV_getCurrentTownLocation(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    TownBase* result = instance->_NV_getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int TownBaseBinding::getMapMarker(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    std::string result = instance->getMapMarker();
    lua_pushstring(L, result.c_str());
    return 1;
}

int TownBaseBinding::_NV_getMapMarker(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    std::string result = instance->_NV_getMapMarker();
    lua_pushstring(L, result.c_str());
    return 1;
}

int TownBaseBinding::getMapMarkerZoomLevel(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    MapZoomLevel result = instance->getMapMarkerZoomLevel();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TownBaseBinding::_NV_getMapMarkerZoomLevel(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    MapZoomLevel result = instance->_NV_getMapMarkerZoomLevel();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TownBaseBinding::isOccupied(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    bool result = instance->isOccupied();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_nestUpThisSpot(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    GameData* nestInfo = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Ogre::Vector3 pos;
    readVector3(L, 3, pos);
    Building* keepInside = checkObject<Building>(L, 4, BuildingBinding::getMetatableName());
    instance->_nestUpThisSpot(nestInfo, pos, keepInside);
    return 0;
}

int TownBaseBinding::_NV__nestUpThisSpot(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    GameData* nestInfo = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Ogre::Vector3 pos;
    readVector3(L, 3, pos);
    Building* keepInside = checkObject<Building>(L, 4, BuildingBinding::getMetatableName());
    instance->_NV__nestUpThisSpot(nestInfo, pos, keepInside);
    return 0;
}

int TownBaseBinding::distributeArtifacts(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");

    instance->distributeArtifacts();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 124: TownAlarmState getAlarmState(...) - unsupported return type
  line 125: TownAlarmState _NV_getAlarmState(...) - unsupported return type
  line 126: void setAlarmState(...) - unsupported arg type
  line 127: void _NV_setAlarmState(...) - unsupported arg type
  line 136: void setHandle(...) - non-string reference arg
  line 137: void _NV_setHandle(...) - non-string reference arg
  line 145: GameSaveState serialise(...) - unsupported arg type
  line 146: GameSaveState _NV_serialise(...) - unsupported arg type
  line 180: void findAllBuildings(...) - unsupported arg type
  line 181: void _NV_findAllBuildings(...) - unsupported arg type
  line 213: void addGate(...) - non-string reference arg
  line 214: void _NV_addGate(...) - non-string reference arg
  line 235: const std::string& getUnexploredName(...) - reference return type
  line 236: const std::string& _NV_getUnexploredName(...) - reference return type
  line 245: void addArtifactItem(...) - unsupported arg type
  line 256: int delayedSpawningChecks(...) - static method
  line 257: const ogre_unordered_set<ZoneMap*>::type& getZonesCoverage(...) - reference return type
  line 258: void clearDelayedItemLoadingMessages(...) - static method
  line 269: void addOccupier(...) - non-string reference arg
  line 270: void removeOccupier(...) - non-string reference arg
  line 274: void spawnDebris(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - TownBase_get_population: BasePopulationManager* (unbound pointer)
  - TownBase_get_nestBatcher: NestBatcher* (unbound pointer)
  - TownBase_get_entityMarker: Ogre::Entity* (unbound pointer)
  - TownBase_get_clickHull: PhysicsHullT* (unbound pointer)
  - TownBase_get_biome: AreaBiomeGroup* (unbound pointer)
  - TownBaseBinding::isNest: Nest* (unbound pointer)
  - TownBaseBinding::findAllBuildingsOfType: lektor<Building*>* (unbound pointer)
  - TownBaseBinding::_NV_findAllBuildingsOfType: lektor<Building*>* (unbound pointer)
  - TownBaseBinding::findAllBuildingsWithFunction: lektor<Building*>* (unbound pointer)
  - TownBaseBinding::_NV_findAllBuildingsWithFunction: lektor<Building*>* (unbound pointer)
  - TownBaseBinding::getAlarmMgr: AlarmManager* (unbound pointer)
  - TownBaseBinding::_NV_getAlarmMgr: AlarmManager* (unbound pointer)
  - TownBaseBinding::getBiome: AreaBiomeGroup* (unbound pointer)
  - TownBaseBinding::_NV_getBiome: AreaBiomeGroup* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 259: townType (TownType) - unsupported type
  line 261: factionsResidentHere (std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 268: occupiers (std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 287: alarmState (TownAlarmState) - unsupported type
  line 289: myZoneCoverage (ogre_unordered_set<ZoneMap*>::type) - unsupported type
  line 290: populatedZones (ogre_unordered_map<ZoneMap*, bool>::type) - unsupported type
  line 291: artifacts (Ogre::FastArray<ArtifactItemData>) - unsupported type
  line 311: residentsSpawned (lektor<ResidentData>) - unsupported type
  line 312: residentsSpawned_BarsOrSomething (lektor<ResidentData>) - unsupported type
*/

int TownBaseBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TownBaseBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TownBase object");
    return 1;
}



static int ResidentData_get_buildingsBad(lua_State* L) {
    TownBase::ResidentData* instance = checkObject<TownBase::ResidentData>(L, 1, "KenshiLua.ResidentData");
    return pushObject<ogre_unordered_set<GameData*>::type>(L, &instance->buildingsBad, "ogre_unordered_set<GameData*>");
}


static int ResidentData_get_buildingsGood(lua_State* L) {
    TownBase::ResidentData* instance = checkObject<TownBase::ResidentData>(L, 1, "KenshiLua.ResidentData");
    return pushObject<ogre_unordered_set<GameData*>::type>(L, &instance->buildingsGood, "ogre_unordered_set<GameData*>");
}


static int ResidentData_get_chance(lua_State* L) {
    TownBase::ResidentData* instance = checkObject<TownBase::ResidentData>(L, 1, "KenshiLua.ResidentData");
    lua_pushinteger(L, instance->chance);
    return 1;
}


static int ResidentData_get_count(lua_State* L) {
    TownBase::ResidentData* instance = checkObject<TownBase::ResidentData>(L, 1, "KenshiLua.ResidentData");
    lua_pushinteger(L, instance->count);
    return 1;
}


static int ResidentData_get_data(lua_State* L) {
    TownBase::ResidentData* instance = checkObject<TownBase::ResidentData>(L, 1, "KenshiLua.ResidentData");
    return pushObject<GameData>(L, instance->data, GameDataBinding::getMetatableName());
}


static int ResidentData_get_priority(lua_State* L) {
    TownBase::ResidentData* instance = checkObject<TownBase::ResidentData>(L, 1, "KenshiLua.ResidentData");
    lua_pushinteger(L, instance->priority);
    return 1;
}


static int ResidentData_set_buildingsBad(lua_State* L) {
    TownBase::ResidentData* instance = checkObject<TownBase::ResidentData>(L, 1, "KenshiLua.ResidentData");
    instance->buildingsBad = *checkObject<ogre_unordered_set<GameData*>::type>(L, 2, "ogre_unordered_set<GameData*>");
    return 0;
}


static int ResidentData_set_buildingsGood(lua_State* L) {
    TownBase::ResidentData* instance = checkObject<TownBase::ResidentData>(L, 1, "KenshiLua.ResidentData");
    instance->buildingsGood = *checkObject<ogre_unordered_set<GameData*>::type>(L, 2, "ogre_unordered_set<GameData*>");
    return 0;
}


static int ResidentData_set_chance(lua_State* L) {
    TownBase::ResidentData* instance = checkObject<TownBase::ResidentData>(L, 1, "KenshiLua.ResidentData");
    instance->chance = (int)luaL_checkinteger(L, 2);
    return 0;
}


static int ResidentData_set_count(lua_State* L) {
    TownBase::ResidentData* instance = checkObject<TownBase::ResidentData>(L, 1, "KenshiLua.ResidentData");
    instance->count = (int)luaL_checkinteger(L, 2);
    return 0;
}


static int ResidentData_set_data(lua_State* L) {
    TownBase::ResidentData* instance = checkObject<TownBase::ResidentData>(L, 1, "KenshiLua.ResidentData");
    instance->data = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}


static int ResidentData_set_priority(lua_State* L) {
    TownBase::ResidentData* instance = checkObject<TownBase::ResidentData>(L, 1, "KenshiLua.ResidentData");
    instance->priority = (int)luaL_checkinteger(L, 2);
    return 0;
}


static int TownBase__NV_findAllBuildingsOfType(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    BuildingDesignation func = (BuildingDesignation)luaL_checkinteger(L, 2);
    Character* me = nullptr;
    if (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) {
        me = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    }
    lektor<Building*>* result = instance->_NV_findAllBuildingsOfType(func, me);
    return pushObject<lektor<Building*>>(L, result, LektorPtrBinding<Building*>::metaName);
}


static int TownBase__NV_findAllBuildingsWithFunction(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    BuildingFunction func = (BuildingFunction)luaL_checkinteger(L, 2);
    Character* me = nullptr;
    if (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) {
        me = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    }
    lektor<Building*>* result = instance->_NV_findAllBuildingsWithFunction(func, me);
    return pushObject<lektor<Building*>>(L, result, LektorPtrBinding<Building*>::metaName);
}


static int TownBase__NV_getCurrentTownLocation(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    TownBase* result = instance->_NV_getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}


static int TownBase__NV_getUnexploredName(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    const std::string& result = instance->_NV_getUnexploredName();
    lua_pushstring(L, result.c_str());
    return 1;
}


static int TownBase__NV_setFaction(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    ActivePlatoon* a = nullptr;
    if (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) {
        a = checkObject<ActivePlatoon>(L, 3, ActivePlatoonBinding::getMetatableName());
    }
    instance->_NV_setFaction(f, a);
    return 0;
}


static int TownBase_findAllBuildingsOfType(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    BuildingDesignation func = (BuildingDesignation)luaL_checkinteger(L, 2);
    Character* me = nullptr;
    if (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) {
        me = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    }
    lektor<Building*>* result = instance->findAllBuildingsOfType(func, me);
    return pushObject<lektor<Building*>>(L, result, LektorPtrBinding<Building*>::metaName);
}


static int TownBase_findAllBuildingsWithFunction(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    BuildingFunction func = (BuildingFunction)luaL_checkinteger(L, 2);
    Character* me = nullptr;
    if (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) {
        me = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    }
    lektor<Building*>* result = instance->findAllBuildingsWithFunction(func, me);
    return pushObject<lektor<Building*>>(L, result, LektorPtrBinding<Building*>::metaName);
}


static int TownBase_getCurrentTownLocation(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    TownBase* result = instance->getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}


static int TownBase_getUnexploredName(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    const std::string& result = instance->getUnexploredName();
    lua_pushstring(L, result.c_str());
    return 1;
}


static int TownBase_get_alarmState(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    // TODO: Unsupported type for alarmState (TownAlarmState)
    return luaL_error(L, "Unsupported property 'alarmState' (type: TownAlarmState)");
}


static int TownBase_get_artifacts(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    // TODO: Unsupported type for artifacts (Ogre::FastArray<ArtifactItemData>)
    return luaL_error(L, "Unsupported property 'artifacts' (type: Ogre::FastArray<ArtifactItemData>)");
}


static int TownBase_get_factionsResidentHere(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    // TODO: Unsupported type for factionsResidentHere (std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'factionsResidentHere' (type: std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > >)");
}


static int TownBase_get_myZoneCoverage(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    // TODO: Unsupported type for myZoneCoverage (ogre_unordered_set<ZoneMap*>::type)
    return luaL_error(L, "Unsupported property 'myZoneCoverage' (type: ogre_unordered_set<ZoneMap*>::type)");
}


static int TownBase_get_occupiers(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    // TODO: Unsupported type for occupiers (std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'occupiers' (type: std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy > >)");
}


static int TownBase_get_populatedZones(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    // TODO: Unsupported type for populatedZones (ogre_unordered_map<ZoneMap*, bool>::type)
    return luaL_error(L, "Unsupported property 'populatedZones' (type: ogre_unordered_map<ZoneMap*, bool>::type)");
}


static int TownBase_get_residentsSpawned(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    return pushObject<lektor<TownBase::ResidentData>>(L, &instance->residentsSpawned, "lektor<ResidentData>");
}


static int TownBase_get_residentsSpawned_BarsOrSomething(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    return pushObject<lektor<TownBase::ResidentData>>(L, &instance->residentsSpawned_BarsOrSomething, "lektor<ResidentData>");
}


static int TownBase_get_townType(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    lua_pushinteger(L, instance->townType);
    return 1;
}


static int TownBase_setFaction(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    ActivePlatoon* a = nullptr;
    if (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) {
        a = checkObject<ActivePlatoon>(L, 3, ActivePlatoonBinding::getMetatableName());
    }
    instance->setFaction(f, a);
    return 0;
}


static int TownBase_set_alarmState(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for alarmState");
}


static int TownBase_set_artifacts(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for artifacts");
}


static int TownBase_set_biome(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for biome");
}


static int TownBase_set_clickHull(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for clickHull");
}


static int TownBase_set_entityMarker(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for entityMarker");
}


static int TownBase_set_factionsResidentHere(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for factionsResidentHere");
}


static int TownBase_set_myZoneCoverage(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for myZoneCoverage");
}


static int TownBase_set_nestBatcher(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for nestBatcher");
}


static int TownBase_set_occupiers(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for occupiers");
}


static int TownBase_set_populatedZones(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for populatedZones");
}


static int TownBase_set_population(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for population");
}


static int TownBase_set_residentsSpawned(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    lektor<TownBase::ResidentData>* src = LektorValueBinding<TownBase::ResidentData>::get(L, 2);
    instance->residentsSpawned = *src;
    return 0;
}


static int TownBase_set_residentsSpawned_BarsOrSomething(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    lektor<TownBase::ResidentData>* src = LektorValueBinding<TownBase::ResidentData>::get(L, 2);
    instance->residentsSpawned_BarsOrSomething = *src;
    return 0;
}


static int TownBase_set_townType(lua_State* L)
{
    TownBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBase is nil");
    TownType tt = (TownType)luaL_checkinteger(L, 2);
    instance->townType = tt;
    return 0;
}


void TownBaseBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TownBaseBinding::gc },
        { "__tostring", TownBaseBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", TownBaseBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", TownBaseBinding::_DESTRUCTOR },
        { "activate", TownBaseBinding::activate },
        { "_NV_activate", TownBaseBinding::_NV_activate },
        { "isActive", TownBaseBinding::isActive },
        { "_NV_isActive", TownBaseBinding::_NV_isActive },
        { "setup", TownBaseBinding::setup },
        { "_NV_setup", TownBaseBinding::_NV_setup },
        { "_reset", TownBaseBinding::_reset },
        { "_NV__reset", TownBaseBinding::_NV__reset },
        { "getKnownName", TownBaseBinding::getKnownName },
        { "reassessTownPosition", TownBaseBinding::reassessTownPosition },
        { "_NV_reassessTownPosition", TownBaseBinding::_NV_reassessTownPosition },
        { "isNotFriendly", TownBaseBinding::isNotFriendly },
        { "_NV_isNotFriendly", TownBaseBinding::_NV_isNotFriendly },
        { "isPhysical", TownBaseBinding::isPhysical },
        { "_NV_isPhysical", TownBaseBinding::_NV_isPhysical },
        { "setVisible", TownBaseBinding::setVisible },
        { "_NV_setVisible", TownBaseBinding::_NV_setVisible },
        { "getDataType", TownBaseBinding::getDataType },
        { "_NV_getDataType", TownBaseBinding::_NV_getDataType },
        { "isTown", TownBaseBinding::isTown },
        { "_NV_isTown", TownBaseBinding::_NV_isTown },
        { "isNest", TownBaseBinding::isNest },
        { "nestUpThisSpot", TownBaseBinding::nestUpThisSpot },
        { "_NV_nestUpThisSpot", TownBaseBinding::_NV_nestUpThisSpot },
        { "loadFromSerialise", TownBaseBinding::loadFromSerialise },
        { "_NV_loadFromSerialise", TownBaseBinding::_NV_loadFromSerialise },
        { "isOutpost", TownBaseBinding::isOutpost },
        { "withinBordersRange", TownBaseBinding::withinBordersRange },
        { "withinDiscoveryRange", TownBaseBinding::withinDiscoveryRange },
        { "isIllegal", TownBaseBinding::isIllegal },
        { "_NV_isIllegal", TownBaseBinding::_NV_isIllegal },
        { "distanceTo", TownBaseBinding::distanceTo },
        { "squaredDistanceTo", TownBaseBinding::squaredDistanceTo },
        { "isDead", TownBaseBinding::isDead },
        { "_NV_isDead", TownBaseBinding::_NV_isDead },
        { "getPositionOutsideTownGates", TownBaseBinding::getPositionOutsideTownGates },
        { "_NV_getPositionOutsideTownGates", TownBaseBinding::_NV_getPositionOutsideTownGates },
        { "setFaction", TownBaseBinding::setFaction },
        { "_NV_setFaction", TownBaseBinding::_NV_setFaction },
        { "isPublic", TownBaseBinding::isPublic },
        { "_NV_isPublic", TownBaseBinding::_NV_isPublic },
        { "getRadius", TownBaseBinding::getRadius },
        { "_NV_getRadius", TownBaseBinding::_NV_getRadius },
        { "getGUIData", TownBaseBinding::getGUIData },
        { "_NV_getGUIData", TownBaseBinding::_NV_getGUIData },
        { "saveState", TownBaseBinding::saveState },
        { "_NV_saveState", TownBaseBinding::_NV_saveState },
        { "loadState", TownBaseBinding::loadState },
        { "_NV_loadState", TownBaseBinding::_NV_loadState },
        { "update", TownBaseBinding::update },
        { "_NV_update", TownBaseBinding::_NV_update },
        { "periodicUpdate", TownBaseBinding::periodicUpdate },
        { "_NV_periodicUpdate", TownBaseBinding::_NV_periodicUpdate },
        { "updatePowerGrid", TownBaseBinding::updatePowerGrid },
        { "_NV_updatePowerGrid", TownBaseBinding::_NV_updatePowerGrid },
        { "hasResidentHQ", TownBaseBinding::hasResidentHQ },
        { "_NV_hasResidentHQ", TownBaseBinding::_NV_hasResidentHQ },
        { "findAllBuildingsOfType", TownBaseBinding::findAllBuildingsOfType },
        { "_NV_findAllBuildingsOfType", TownBaseBinding::_NV_findAllBuildingsOfType },
        { "findAllBuildingsWithFunction", TownBaseBinding::findAllBuildingsWithFunction },
        { "_NV_findAllBuildingsWithFunction", TownBaseBinding::_NV_findAllBuildingsWithFunction },
        { "allBuildingsDoorsOpen", TownBaseBinding::allBuildingsDoorsOpen },
        { "_NV_allBuildingsDoorsOpen", TownBaseBinding::_NV_allBuildingsDoorsOpen },
        { "destroyPhysical", TownBaseBinding::destroyPhysical },
        { "_NV_destroyPhysical", TownBaseBinding::_NV_destroyPhysical },
        { "getPosition", TownBaseBinding::getPosition },
        { "_NV_getPosition", TownBaseBinding::_NV_getPosition },
        { "getPositionForWaypoint", TownBaseBinding::getPositionForWaypoint },
        { "_NV_getPositionForWaypoint", TownBaseBinding::_NV_getPositionForWaypoint },
        { "createPhysical", TownBaseBinding::createPhysical },
        { "_NV_createPhysical", TownBaseBinding::_NV_createPhysical },
        { "getAlarmMgr", TownBaseBinding::getAlarmMgr },
        { "_NV_getAlarmMgr", TownBaseBinding::_NV_getAlarmMgr },
        { "hasGates", TownBaseBinding::hasGates },
        { "_NV_hasGates", TownBaseBinding::_NV_hasGates },
        { "gatesAllClosed", TownBaseBinding::gatesAllClosed },
        { "_NV_gatesAllClosed", TownBaseBinding::_NV_gatesAllClosed },
        { "getNearestGate", TownBaseBinding::getNearestGate },
        { "_NV_getNearestGate", TownBaseBinding::_NV_getNearestGate },
        { "getBiome", TownBaseBinding::getBiome },
        { "_NV_getBiome", TownBaseBinding::_NV_getBiome },
        { "isRecentlyDiscovered", TownBaseBinding::isRecentlyDiscovered },
        { "_NV_isRecentlyDiscovered", TownBaseBinding::_NV_isRecentlyDiscovered },
        { "setRecentlyDiscovered", TownBaseBinding::setRecentlyDiscovered },
        { "_NV_setRecentlyDiscovered", TownBaseBinding::_NV_setRecentlyDiscovered },
        { "isDiscovered", TownBaseBinding::isDiscovered },
        { "_NV_isDiscovered", TownBaseBinding::_NV_isDiscovered },
        { "setDiscovered", TownBaseBinding::setDiscovered },
        { "_NV_setDiscovered", TownBaseBinding::_NV_setDiscovered },
        { "setDead", TownBaseBinding::setDead },
        { "_NV_setDead", TownBaseBinding::_NV_setDead },
        { "isExplored", TownBaseBinding::isExplored },
        { "_NV_isExplored", TownBaseBinding::_NV_isExplored },
        { "setExplored", TownBaseBinding::setExplored },
        { "_NV_setExplored", TownBaseBinding::_NV_setExplored },
        { "getItemArtifactsMinValue", TownBaseBinding::getItemArtifactsMinValue },
        { "_NV_getItemArtifactsMinValue", TownBaseBinding::_NV_getItemArtifactsMinValue },
        { "getItemArtifactsMaxValue", TownBaseBinding::getItemArtifactsMaxValue },
        { "_NV_getItemArtifactsMaxValue", TownBaseBinding::_NV_getItemArtifactsMaxValue },
        { "getGearArtifactsMinValue", TownBaseBinding::getGearArtifactsMinValue },
        { "_NV_getGearArtifactsMinValue", TownBaseBinding::_NV_getGearArtifactsMinValue },
        { "getGearArtifactsMaxValue", TownBaseBinding::getGearArtifactsMaxValue },
        { "_NV_getGearArtifactsMaxValue", TownBaseBinding::_NV_getGearArtifactsMaxValue },
        { "setZonePopulated", TownBaseBinding::setZonePopulated },
        { "getBuildingsManager", TownBaseBinding::getBuildingsManager },
        { "getBuildingFloorVisibility", TownBaseBinding::getBuildingFloorVisibility },
        { "setBuildingsFloorVisibility", TownBaseBinding::setBuildingsFloorVisibility },
        { "resetBuildingsFloorVisibility", TownBaseBinding::resetBuildingsFloorVisibility },
        { "getTownFloorVisiblity", TownBaseBinding::getTownFloorVisiblity },
        { "setTownFloorVisiblity", TownBaseBinding::setTownFloorVisiblity },
        { "resetTownFloorVisibility", TownBaseBinding::resetTownFloorVisibility },
        { "getCurrentTownLocation", TownBaseBinding::getCurrentTownLocation },
        { "_NV_getCurrentTownLocation", TownBaseBinding::_NV_getCurrentTownLocation },
        { "getMapMarker", TownBaseBinding::getMapMarker },
        { "_NV_getMapMarker", TownBaseBinding::_NV_getMapMarker },
        { "getMapMarkerZoomLevel", TownBaseBinding::getMapMarkerZoomLevel },
        { "_NV_getMapMarkerZoomLevel", TownBaseBinding::_NV_getMapMarkerZoomLevel },
        { "isOccupied", TownBaseBinding::isOccupied },
        { "_nestUpThisSpot", TownBaseBinding::_nestUpThisSpot },
        { "_NV__nestUpThisSpot", TownBaseBinding::_NV__nestUpThisSpot },
        { "distributeArtifacts", TownBaseBinding::distributeArtifacts },
                { "getUnexploredName", TownBase_getUnexploredName },
        { "_NV_getUnexploredName", TownBase__NV_getUnexploredName },
        { 0, 0 }
    };

    registerClass(
        L, 
        TownBaseBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TownBaseBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "positionCacher", TownBase_get_positionCacher);
    registerGetter(L, "population", TownBase_get_population);
    registerGetter(L, "alreadyInitialisedPopulationParams", TownBase_get_alreadyInitialisedPopulationParams);
    registerGetter(L, "isSecret", TownBase_get_isSecret);
    registerGetter(L, "timeOfDeath", TownBase_get_timeOfDeath);
    registerGetter(L, "p_TIME", TownBase_get_p_TIME);
    registerGetter(L, "nestBatcher", TownBase_get_nestBatcher);
    registerGetter(L, "unexploredName", TownBase_get_unexploredName);
    registerGetter(L, "discovered", TownBase_get_discovered);
    registerGetter(L, "explored", TownBase_get_explored);
    registerGetter(L, "recentlyDiscovered", TownBase_get_recentlyDiscovered);
    registerGetter(L, "entityMarker", TownBase_get_entityMarker);
    registerGetter(L, "entityLabel", TownBase_get_entityLabel);
    registerGetter(L, "clickHull", TownBase_get_clickHull);
    registerGetter(L, "biome", TownBase_get_biome);
    registerGetter(L, "isActivated", TownBase_get_isActivated);
    registerGetter(L, "currentFloorVisibility", TownBase_get_currentFloorVisibility);
    registerGetter(L, "buildingsManager", TownBase_get_buildingsManager);
    registerGetter(L, "defaultResident", TownBase_get_defaultResident);
        registerGetter(L, "buildingsBad", ResidentData_get_buildingsBad);
        registerGetter(L, "buildingsGood", ResidentData_get_buildingsGood);
        registerGetter(L, "chance", ResidentData_get_chance);
        registerGetter(L, "count", ResidentData_get_count);
        registerGetter(L, "data", ResidentData_get_data);
        registerGetter(L, "priority", ResidentData_get_priority);
        registerGetter(L, "alarmState", TownBase_get_alarmState);
        registerGetter(L, "artifacts", TownBase_get_artifacts);
        registerGetter(L, "factionsResidentHere", TownBase_get_factionsResidentHere);
        registerGetter(L, "myZoneCoverage", TownBase_get_myZoneCoverage);
        registerGetter(L, "occupiers", TownBase_get_occupiers);
        registerGetter(L, "populatedZones", TownBase_get_populatedZones);
        registerGetter(L, "residentsSpawned", TownBase_get_residentsSpawned);
        registerGetter(L, "residentsSpawned_BarsOrSomething", TownBase_get_residentsSpawned_BarsOrSomething);
        registerGetter(L, "townType", TownBase_get_townType);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "positionCacher", TownBase_set_positionCacher);
    registerSetter(L, "alreadyInitialisedPopulationParams", TownBase_set_alreadyInitialisedPopulationParams);
    registerSetter(L, "isSecret", TownBase_set_isSecret);
    registerSetter(L, "timeOfDeath", TownBase_set_timeOfDeath);
    registerSetter(L, "p_TIME", TownBase_set_p_TIME);
    registerSetter(L, "unexploredName", TownBase_set_unexploredName);
    registerSetter(L, "discovered", TownBase_set_discovered);
    registerSetter(L, "explored", TownBase_set_explored);
    registerSetter(L, "recentlyDiscovered", TownBase_set_recentlyDiscovered);
    registerSetter(L, "entityLabel", TownBase_set_entityLabel);
    registerSetter(L, "isActivated", TownBase_set_isActivated);
    registerSetter(L, "currentFloorVisibility", TownBase_set_currentFloorVisibility);
    registerSetter(L, "buildingsManager", TownBase_set_buildingsManager);
    registerSetter(L, "defaultResident", TownBase_set_defaultResident);
        registerSetter(L, "buildingsBad", ResidentData_set_buildingsBad);
        registerSetter(L, "buildingsGood", ResidentData_set_buildingsGood);
        registerSetter(L, "chance", ResidentData_set_chance);
        registerSetter(L, "count", ResidentData_set_count);
        registerSetter(L, "data", ResidentData_set_data);
        registerSetter(L, "priority", ResidentData_set_priority);
        registerSetter(L, "alarmState", TownBase_set_alarmState);
        registerSetter(L, "artifacts", TownBase_set_artifacts);
        registerSetter(L, "biome", TownBase_set_biome);
        registerSetter(L, "clickHull", TownBase_set_clickHull);
        registerSetter(L, "entityMarker", TownBase_set_entityMarker);
        registerSetter(L, "factionsResidentHere", TownBase_set_factionsResidentHere);
        registerSetter(L, "myZoneCoverage", TownBase_set_myZoneCoverage);
        registerSetter(L, "nestBatcher", TownBase_set_nestBatcher);
        registerSetter(L, "occupiers", TownBase_set_occupiers);
        registerSetter(L, "populatedZones", TownBase_set_populatedZones);
        registerSetter(L, "population", TownBase_set_population);
        registerSetter(L, "residentsSpawned", TownBase_set_residentsSpawned);
        registerSetter(L, "residentsSpawned_BarsOrSomething", TownBase_set_residentsSpawned_BarsOrSomething);
        registerSetter(L, "townType", TownBase_set_townType);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to RootObject
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, TownBaseBinding::getMetatableName(), RootObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua