#include "pch.h"
#include "kenshi\Town.h"
#include "TownBaseBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/TownBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/EnumBinding.h"

namespace KenshiLua
{

static TownBase* getB(lua_State* L, int idx)
{
    return checkObject<TownBase>(L, idx, TownBaseBinding::getMetatableName());
}

// --- Getters for TownBase ---
static int TownBase_get_positionCacher(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    // TODO: Unsupported type for positionCacher (TownPositionCacher)
    return luaL_error(L, "Unsupported property 'positionCacher' (type: TownPositionCacher)");
}

static int TownBase_get_townType(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    lua_pushinteger(L, b->townType);
    return 1;
}

static int TownBase_get_population(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    // TODO: Unsupported type for population (BasePopulationManager*)
    return luaL_error(L, "Unsupported property 'population' (type: BasePopulationManager*)");
}

static int TownBase_get_factionsResidentHere(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    // TODO: Unsupported type for factionsResidentHere (std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'factionsResidentHere' (type: std::set<Faction*, std::less<Faction*>, Ogre::STLAllocator<Faction*, Ogre::GeneralAllocPolicy > >)");
}

static int TownBase_get_alreadyInitialisedPopulationParams(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    lua_pushboolean(L, b->alreadyInitialisedPopulationParams ? 1 : 0);
    return 1;
}

static int TownBase_get_isSecret(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    lua_pushboolean(L, b->isSecret ? 1 : 0);
    return 1;
}

static int TownBase_get_occupiers(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    // TODO: Unsupported type for occupiers (std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'occupiers' (type: std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy > >)");
}

static int TownBase_get_timeOfDeath(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    // TODO: Unsupported type for timeOfDeath (TimeOfDay)
    return luaL_error(L, "Unsupported property 'timeOfDeath' (type: TimeOfDay)");
}

static int TownBase_get_p_TIME(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    lua_pushnumber(L, b->p_TIME);
    return 1;
}

static int TownBase_get_nestBatcher(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    // TODO: Unsupported type for nestBatcher (NestBatcher*)
    return luaL_error(L, "Unsupported property 'nestBatcher' (type: NestBatcher*)");
}

static int TownBase_get_unexploredName(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    lua_pushstring(L, b->unexploredName.c_str());
    return 1;
}

static int TownBase_get_discovered(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    lua_pushboolean(L, b->discovered ? 1 : 0);
    return 1;
}

static int TownBase_get_explored(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    lua_pushboolean(L, b->explored ? 1 : 0);
    return 1;
}

static int TownBase_get_recentlyDiscovered(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    lua_pushboolean(L, b->recentlyDiscovered ? 1 : 0);
    return 1;
}

static int TownBase_get_entityMarker(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    // TODO: Unsupported type for entityMarker (Ogre::Entity*)
    return luaL_error(L, "Unsupported property 'entityMarker' (type: Ogre::Entity*)");
}

static int TownBase_get_entityLabel(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    // TODO: Unsupported type for entityLabel (ScreenLabel*)
    return luaL_error(L, "Unsupported property 'entityLabel' (type: ScreenLabel*)");
}

static int TownBase_get_clickHull(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    // TODO: Unsupported type for clickHull (PhysicsHullT*)
    return luaL_error(L, "Unsupported property 'clickHull' (type: PhysicsHullT*)");
}

static int TownBase_get_biome(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    // TODO: Unsupported type for biome (AreaBiomeGroup*)
    return luaL_error(L, "Unsupported property 'biome' (type: AreaBiomeGroup*)");
}

static int TownBase_get_alarmState(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    // TODO: Unsupported type for alarmState (TownAlarmState)
    return luaL_error(L, "Unsupported property 'alarmState' (type: TownAlarmState)");
}

static int TownBase_get_isActivated(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    lua_pushboolean(L, b->isActivated ? 1 : 0);
    return 1;
}

static int TownBase_get_myZoneCoverage(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    // TODO: Unsupported type for myZoneCoverage (ogre_unordered_set<ZoneMap*>::type)
    return luaL_error(L, "Unsupported property 'myZoneCoverage' (type: ogre_unordered_set<ZoneMap*>::type)");
}

static int TownBase_get_populatedZones(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    // TODO: Unsupported type for populatedZones (ogre_unordered_map<ZoneMap*, bool>::type)
    return luaL_error(L, "Unsupported property 'populatedZones' (type: ogre_unordered_map<ZoneMap*, bool>::type)");
}

static int TownBase_get_artifacts(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    // TODO: Unsupported type for artifacts (Ogre::FastArray<ArtifactItemData>)
    return luaL_error(L, "Unsupported property 'artifacts' (type: Ogre::FastArray<ArtifactItemData>)");
}

static int TownBase_get_currentFloorVisibility(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    lua_pushinteger(L, b->currentFloorVisibility);
    return 1;
}

static int TownBase_get_buildingsManager(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    // TODO: Unsupported type for buildingsManager (TownBuildingsManager)
    return luaL_error(L, "Unsupported property 'buildingsManager' (type: TownBuildingsManager)");
}

static int TownBase_get_residentsSpawned(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    // TODO: Unsupported type for residentsSpawned (lektor<ResidentData>)
    return luaL_error(L, "Unsupported property 'residentsSpawned' (type: lektor<ResidentData>)");
}

static int TownBase_get_residentsSpawned_BarsOrSomething(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    // TODO: Unsupported type for residentsSpawned_BarsOrSomething (lektor<ResidentData>)
    return luaL_error(L, "Unsupported property 'residentsSpawned_BarsOrSomething' (type: lektor<ResidentData>)");
}

static int TownBase_get_defaultResident(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    return pushObject<GameData>(L, b->defaultResident, GameDataBinding::getMetatableName());
}

// --- Setters for TownBase ---
static int TownBase_set_positionCacher(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for positionCacher");
}

static int TownBase_set_townType(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    TownType tt = (TownType)luaL_checkinteger(L, 2);
    b->townType = tt;
    return 0;
}

static int TownBase_set_population(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for population");
}

static int TownBase_set_factionsResidentHere(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for factionsResidentHere");
}

static int TownBase_set_alreadyInitialisedPopulationParams(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    b->alreadyInitialisedPopulationParams = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TownBase_set_isSecret(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    b->isSecret = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TownBase_set_occupiers(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for occupiers");
}

static int TownBase_set_timeOfDeath(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for timeOfDeath");
}

static int TownBase_set_p_TIME(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    b->p_TIME = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TownBase_set_nestBatcher(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for nestBatcher");
}

static int TownBase_set_unexploredName(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    b->unexploredName = luaL_checkstring(L, 2);
    return 0;
}

static int TownBase_set_discovered(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    b->discovered = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TownBase_set_explored(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    b->explored = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TownBase_set_recentlyDiscovered(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    b->recentlyDiscovered = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TownBase_set_entityMarker(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for entityMarker");
}

static int TownBase_set_entityLabel(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for entityLabel");
}

static int TownBase_set_clickHull(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for clickHull");
}

static int TownBase_set_biome(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for biome");
}

static int TownBase_set_alarmState(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for alarmState");
}

static int TownBase_set_isActivated(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    b->isActivated = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TownBase_set_myZoneCoverage(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for myZoneCoverage");
}

static int TownBase_set_populatedZones(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for populatedZones");
}

static int TownBase_set_artifacts(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for artifacts");
}

static int TownBase_set_currentFloorVisibility(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    b->currentFloorVisibility = (unsigned char)luaL_checkinteger(L, 2);
    return 0;
}

static int TownBase_set_buildingsManager(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for buildingsManager");
}

static int TownBase_set_residentsSpawned(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for residentsSpawned");
}

static int TownBase_set_residentsSpawned_BarsOrSomething(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for residentsSpawned_BarsOrSomething");
}

static int TownBase_set_defaultResident(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for defaultResident");
}

int TownBaseBinding::_DESTRUCTOR(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    b->_DESTRUCTOR();
    return 0;
}

int TownBaseBinding::isActive(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->isActive();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_isActive(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->_NV_isActive();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_reset(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    b->_reset();
    return 0;
}

int TownBaseBinding::_NV__reset(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    b->_NV__reset();
    return 0;
}

int TownBaseBinding::getKnownName(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    std::string result = b->getKnownName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int TownBaseBinding::reassessTownPosition(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    b->reassessTownPosition();
    return 0;
}

int TownBaseBinding::_NV_reassessTownPosition(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    b->_NV_reassessTownPosition();
    return 0;
}

int TownBaseBinding::isNotFriendly(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->isNotFriendly();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_isNotFriendly(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->_NV_isNotFriendly();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::isPhysical(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->isPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_isPhysical(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->_NV_isPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::setVisible(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->setVisible(on);
    return 0;
}

int TownBaseBinding::_NV_setVisible(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->_NV_setVisible(on);
    return 0;
}

int TownBaseBinding::getDataType(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    itemType result = b->getDataType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TownBaseBinding::_NV_getDataType(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    itemType result = b->_NV_getDataType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TownBaseBinding::isTown(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    Town* result = b->isTown();
    return pushObject<Town>(L, result, TownBinding::getMetatableName());
}

int TownBaseBinding::_NV_isTown(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    Town* result = b->_NV_isTown();
    return pushObject<Town>(L, result, TownBinding::getMetatableName());
}

int TownBaseBinding::isOutpost(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->isOutpost();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::withinBordersRange(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    float mult = (float)luaL_checknumber(L, 3);
    bool result = b->withinBordersRange(p, mult);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::withinDiscoveryRange(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    bool explored = lua_toboolean(L, 3) != 0;
    bool result = b->withinDiscoveryRange(p, explored);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::distanceTo(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    Ogre::Vector3 to;
    readVector3(L, 2, to);
    float result = b->distanceTo(to);
    lua_pushnumber(L, result);
    return 1;
}

int TownBaseBinding::squaredDistanceTo(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    Ogre::Vector3 to;
    readVector3(L, 2, to);
    float result = b->squaredDistanceTo(to);
    lua_pushnumber(L, result);
    return 1;
}

int TownBaseBinding::isDead(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->isDead();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_isDead(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->_NV_isDead();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::getPositionOutsideTownGates(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    float dist = (float)luaL_checknumber(L, 2);
    Ogre::Vector3 result = b->getPositionOutsideTownGates(dist);
    pushVector3(L, result);
    return 1;
}

int TownBaseBinding::_NV_getPositionOutsideTownGates(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    float dist = (float)luaL_checknumber(L, 2);
    Ogre::Vector3 result = b->_NV_getPositionOutsideTownGates(dist);
    pushVector3(L, result);
    return 1;
}

int TownBaseBinding::isPublic(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->isPublic();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_isPublic(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->_NV_isPublic();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::getRadius(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    float result = b->getRadius();
    lua_pushnumber(L, result);
    return 1;
}

int TownBaseBinding::_NV_getRadius(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    float result = b->_NV_getRadius();
    lua_pushnumber(L, result);
    return 1;
}

int TownBaseBinding::update(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    b->update();
    return 0;
}

int TownBaseBinding::_NV_update(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    b->_NV_update();
    return 0;
}

int TownBaseBinding::periodicUpdate(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    b->periodicUpdate();
    return 0;
}

int TownBaseBinding::_NV_periodicUpdate(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    b->_NV_periodicUpdate();
    return 0;
}

int TownBaseBinding::updatePowerGrid(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    b->updatePowerGrid();
    return 0;
}

int TownBaseBinding::_NV_updatePowerGrid(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    b->_NV_updatePowerGrid();
    return 0;
}

int TownBaseBinding::allBuildingsDoorsOpen(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->allBuildingsDoorsOpen();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_allBuildingsDoorsOpen(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->_NV_allBuildingsDoorsOpen();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::destroyPhysical(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    b->destroyPhysical();
    return 0;
}

int TownBaseBinding::_NV_destroyPhysical(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    b->_NV_destroyPhysical();
    return 0;
}

int TownBaseBinding::getPosition(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    Ogre::Vector3 result = b->getPosition();
    pushVector3(L, result);
    return 1;
}

int TownBaseBinding::_NV_getPosition(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    Ogre::Vector3 result = b->_NV_getPosition();
    pushVector3(L, result);
    return 1;
}

int TownBaseBinding::getPositionForWaypoint(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    Ogre::Vector3 from;
    readVector3(L, 2, from);
    Ogre::Vector3 result = b->getPositionForWaypoint(from);
    pushVector3(L, result);
    return 1;
}

int TownBaseBinding::_NV_getPositionForWaypoint(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    Ogre::Vector3 from;
    readVector3(L, 2, from);
    Ogre::Vector3 result = b->_NV_getPositionForWaypoint(from);
    pushVector3(L, result);
    return 1;
}

int TownBaseBinding::createPhysical(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_createPhysical(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->_NV_createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::hasGates(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->hasGates();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_hasGates(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->_NV_hasGates();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::gatesAllClosed(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->gatesAllClosed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_gatesAllClosed(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->_NV_gatesAllClosed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::isRecentlyDiscovered(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->isRecentlyDiscovered();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_isRecentlyDiscovered(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->_NV_isRecentlyDiscovered();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::setRecentlyDiscovered(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool value = lua_toboolean(L, 2) != 0;
    b->setRecentlyDiscovered(value);
    return 0;
}

int TownBaseBinding::_NV_setRecentlyDiscovered(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool value = lua_toboolean(L, 2) != 0;
    b->_NV_setRecentlyDiscovered(value);
    return 0;
}

int TownBaseBinding::isDiscovered(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->isDiscovered();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_isDiscovered(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->_NV_isDiscovered();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::setDiscovered(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool value = lua_toboolean(L, 2) != 0;
    b->setDiscovered(value);
    return 0;
}

int TownBaseBinding::_NV_setDiscovered(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool value = lua_toboolean(L, 2) != 0;
    b->_NV_setDiscovered(value);
    return 0;
}

int TownBaseBinding::setDead(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    b->setDead();
    return 0;
}

int TownBaseBinding::_NV_setDead(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    b->_NV_setDead();
    return 0;
}

int TownBaseBinding::isExplored(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->isExplored();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::_NV_isExplored(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->_NV_isExplored();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::setExplored(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool value = lua_toboolean(L, 2) != 0;
    b->setExplored(value);
    return 0;
}

int TownBaseBinding::_NV_setExplored(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool value = lua_toboolean(L, 2) != 0;
    b->_NV_setExplored(value);
    return 0;
}

int TownBaseBinding::getItemArtifactsMinValue(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    unsigned int result = b->getItemArtifactsMinValue();
    lua_pushinteger(L, result);
    return 1;
}

int TownBaseBinding::_NV_getItemArtifactsMinValue(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    unsigned int result = b->_NV_getItemArtifactsMinValue();
    lua_pushinteger(L, result);
    return 1;
}

int TownBaseBinding::getItemArtifactsMaxValue(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    unsigned int result = b->getItemArtifactsMaxValue();
    lua_pushinteger(L, result);
    return 1;
}

int TownBaseBinding::_NV_getItemArtifactsMaxValue(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    unsigned int result = b->_NV_getItemArtifactsMaxValue();
    lua_pushinteger(L, result);
    return 1;
}

int TownBaseBinding::getGearArtifactsMinValue(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    unsigned int result = b->getGearArtifactsMinValue();
    lua_pushinteger(L, result);
    return 1;
}

int TownBaseBinding::_NV_getGearArtifactsMinValue(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    unsigned int result = b->_NV_getGearArtifactsMinValue();
    lua_pushinteger(L, result);
    return 1;
}

int TownBaseBinding::getGearArtifactsMaxValue(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    unsigned int result = b->getGearArtifactsMaxValue();
    lua_pushinteger(L, result);
    return 1;
}

int TownBaseBinding::_NV_getGearArtifactsMaxValue(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    unsigned int result = b->_NV_getGearArtifactsMaxValue();
    lua_pushinteger(L, result);
    return 1;
}

int TownBaseBinding::resetBuildingsFloorVisibility(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    b->resetBuildingsFloorVisibility();
    return 0;
}

int TownBaseBinding::getTownFloorVisiblity(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    int result = b->getTownFloorVisiblity();
    lua_pushinteger(L, result);
    return 1;
}

int TownBaseBinding::setTownFloorVisiblity(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    int floor = (int)luaL_checkinteger(L, 2);
    bool onlyPlayerBuildings = lua_toboolean(L, 3) != 0;
    b->setTownFloorVisiblity(floor, onlyPlayerBuildings);
    return 0;
}

int TownBaseBinding::resetTownFloorVisibility(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    b->resetTownFloorVisibility();
    return 0;
}

int TownBaseBinding::getMapMarker(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    std::string result = b->getMapMarker();
    lua_pushstring(L, result.c_str());
    return 1;
}

int TownBaseBinding::_NV_getMapMarker(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    std::string result = b->_NV_getMapMarker();
    lua_pushstring(L, result.c_str());
    return 1;
}

int TownBaseBinding::getMapMarkerZoomLevel(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    MapZoomLevel result = b->getMapMarkerZoomLevel();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TownBaseBinding::_NV_getMapMarkerZoomLevel(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    MapZoomLevel result = b->_NV_getMapMarkerZoomLevel();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TownBaseBinding::isOccupied(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    bool result = b->isOccupied();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownBaseBinding::distributeArtifacts(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");

    b->distributeArtifacts();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 112: TownBase* _CONSTRUCTOR(...) - unsupported return type
  line 115: void activate(...) - unsupported arg type
  line 116: void _NV_activate(...) - unsupported arg type
  line 119: void setup(...) - unsupported arg type
  line 120: void _NV_setup(...) - unsupported arg type
  line 124: TownAlarmState getAlarmState(...) - unsupported return type
  line 125: TownAlarmState _NV_getAlarmState(...) - unsupported return type
  line 126: void setAlarmState(...) - unsupported arg type
  line 127: void _NV_setAlarmState(...) - unsupported arg type
  line 136: void setHandle(...) - unsupported arg type
  line 137: void _NV_setHandle(...) - unsupported arg type
  line 142: Nest* isNest(...) - unsupported return type
  line 143: void nestUpThisSpot(...) - unsupported arg type
  line 144: void _NV_nestUpThisSpot(...) - unsupported arg type
  line 145: GameSaveState serialise(...) - unsupported return type
  line 146: GameSaveState _NV_serialise(...) - unsupported return type
  line 147: void loadFromSerialise(...) - unsupported arg type
  line 148: void _NV_loadFromSerialise(...) - unsupported arg type
  line 152: bool isIllegal(...) - unsupported arg type
  line 153: bool _NV_isIllegal(...) - unsupported arg type
  line 160: void setFaction(...) - unsupported arg type
  line 161: void _NV_setFaction(...) - unsupported arg type
  line 166: void getGUIData(...) - unsupported arg type
  line 167: void _NV_getGUIData(...) - unsupported arg type
  line 168: void saveState(...) - unsupported arg type
  line 169: void _NV_saveState(...) - unsupported arg type
  line 170: void loadState(...) - unsupported arg type
  line 171: void _NV_loadState(...) - unsupported arg type
  line 178: bool hasResidentHQ(...) - unsupported arg type
  line 179: bool _NV_hasResidentHQ(...) - unsupported arg type
  line 180: void findAllBuildings(...) - unsupported arg type
  line 181: void _NV_findAllBuildings(...) - unsupported arg type
  line 182: lektor<Building*>* findAllBuildingsOfType(...) - unsupported return type
  line 183: lektor<Building*>* _NV_findAllBuildingsOfType(...) - unsupported return type
  line 184: lektor<Building*>* findAllBuildingsWithFunction(...) - unsupported return type
  line 185: lektor<Building*>* _NV_findAllBuildingsWithFunction(...) - unsupported return type
  line 209: AlarmManager* getAlarmMgr(...) - unsupported return type
  line 210: AlarmManager* _NV_getAlarmMgr(...) - unsupported return type
  line 213: void addGate(...) - unsupported arg type
  line 214: void _NV_addGate(...) - unsupported arg type
  line 217: GatewayBuilding* getNearestGate(...) - unsupported return type
  line 218: GatewayBuilding* _NV_getNearestGate(...) - unsupported return type
  line 219: AreaBiomeGroup* getBiome(...) - unsupported return type
  line 220: AreaBiomeGroup* _NV_getBiome(...) - unsupported return type
  line 235: const std::string& getUnexploredName(...) - reference return type
  line 236: const std::string& _NV_getUnexploredName(...) - reference return type
  line 245: void addArtifactItem(...) - unsupported arg type
  line 246: void setZonePopulated(...) - unsupported arg type
  line 247: TownBuildingsManager* getBuildingsManager(...) - unsupported return type
  line 248: int getBuildingFloorVisibility(...) - unsupported arg type
  line 249: void setBuildingsFloorVisibility(...) - unsupported arg type
  line 254: TownBase* getCurrentTownLocation(...) - unsupported return type
  line 255: TownBase* _NV_getCurrentTownLocation(...) - unsupported return type
  line 256: int delayedSpawningChecks(...) - static method
  line 257: const ogre_unordered_set<ZoneMap*>::type& getZonesCoverage(...) - reference return type
  line 258: void clearDelayedItemLoadingMessages(...) - static method
  line 269: void addOccupier(...) - unsupported arg type
  line 270: void removeOccupier(...) - unsupported arg type
  line 272: void _nestUpThisSpot(...) - unsupported arg type
  line 273: void _NV__nestUpThisSpot(...) - unsupported arg type
  line 274: void spawnDebris(...) - unsupported arg type
*/

static int TownBase_setFaction(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    ActivePlatoon* a = nullptr;
    if (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) {
        a = checkObject<ActivePlatoon>(L, 3, ActivePlatoonBinding::getMetatableName());
    }
    b->setFaction(f, a);
    return 0;
}

static int TownBase__NV_setFaction(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    ActivePlatoon* a = nullptr;
    if (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) {
        a = checkObject<ActivePlatoon>(L, 3, ActivePlatoonBinding::getMetatableName());
    }
    b->_NV_setFaction(f, a);
    return 0;
}

static int TownBase_findAllBuildingsOfType(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    BuildingDesignation func = (BuildingDesignation)luaL_checkinteger(L, 2);
    Character* me = nullptr;
    if (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) {
        me = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    }
    lektor<Building*>* result = b->findAllBuildingsOfType(func, me);
    return pushObject<lektor<Building*>>(L, result, LektorPtrBinding<Building*>::metaName);
}

static int TownBase__NV_findAllBuildingsOfType(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    BuildingDesignation func = (BuildingDesignation)luaL_checkinteger(L, 2);
    Character* me = nullptr;
    if (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) {
        me = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    }
    lektor<Building*>* result = b->_NV_findAllBuildingsOfType(func, me);
    return pushObject<lektor<Building*>>(L, result, LektorPtrBinding<Building*>::metaName);
}

static int TownBase_findAllBuildingsWithFunction(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    BuildingFunction func = (BuildingFunction)luaL_checkinteger(L, 2);
    Character* me = nullptr;
    if (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) {
        me = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    }
    lektor<Building*>* result = b->findAllBuildingsWithFunction(func, me);
    return pushObject<lektor<Building*>>(L, result, LektorPtrBinding<Building*>::metaName);
}

static int TownBase__NV_findAllBuildingsWithFunction(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    BuildingFunction func = (BuildingFunction)luaL_checkinteger(L, 2);
    Character* me = nullptr;
    if (lua_gettop(L) >= 3 && !lua_isnil(L, 3)) {
        me = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    }
    lektor<Building*>* result = b->_NV_findAllBuildingsWithFunction(func, me);
    return pushObject<lektor<Building*>>(L, result, LektorPtrBinding<Building*>::metaName);
}

static int TownBase_getCurrentTownLocation(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    TownBase* result = b->getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

static int TownBase__NV_getCurrentTownLocation(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    TownBase* result = b->_NV_getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

static int TownBase_getUnexploredName(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    const std::string& result = b->getUnexploredName();
    lua_pushstring(L, result.c_str());
    return 1;
}

static int TownBase__NV_getUnexploredName(lua_State* L)
{
    TownBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBase is nil");
    const std::string& result = b->_NV_getUnexploredName();
    lua_pushstring(L, result.c_str());
    return 1;
}

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

void TownBaseBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TownBaseBinding::gc },
        { "__tostring", TownBaseBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", TownBaseBinding::_DESTRUCTOR },
        { "isActive", TownBaseBinding::isActive },
        { "_NV_isActive", TownBaseBinding::_NV_isActive },
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
        { "isOutpost", TownBaseBinding::isOutpost },
        { "withinBordersRange", TownBaseBinding::withinBordersRange },
        { "withinDiscoveryRange", TownBaseBinding::withinDiscoveryRange },
        { "distanceTo", TownBaseBinding::distanceTo },
        { "squaredDistanceTo", TownBaseBinding::squaredDistanceTo },
        { "isDead", TownBaseBinding::isDead },
        { "_NV_isDead", TownBaseBinding::_NV_isDead },
        { "getPositionOutsideTownGates", TownBaseBinding::getPositionOutsideTownGates },
        { "_NV_getPositionOutsideTownGates", TownBaseBinding::_NV_getPositionOutsideTownGates },
        { "isPublic", TownBaseBinding::isPublic },
        { "_NV_isPublic", TownBaseBinding::_NV_isPublic },
        { "getRadius", TownBaseBinding::getRadius },
        { "_NV_getRadius", TownBaseBinding::_NV_getRadius },
        { "update", TownBaseBinding::update },
        { "_NV_update", TownBaseBinding::_NV_update },
        { "periodicUpdate", TownBaseBinding::periodicUpdate },
        { "_NV_periodicUpdate", TownBaseBinding::_NV_periodicUpdate },
        { "updatePowerGrid", TownBaseBinding::updatePowerGrid },
        { "_NV_updatePowerGrid", TownBaseBinding::_NV_updatePowerGrid },
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
        { "hasGates", TownBaseBinding::hasGates },
        { "_NV_hasGates", TownBaseBinding::_NV_hasGates },
        { "gatesAllClosed", TownBaseBinding::gatesAllClosed },
        { "_NV_gatesAllClosed", TownBaseBinding::_NV_gatesAllClosed },
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
        { "resetBuildingsFloorVisibility", TownBaseBinding::resetBuildingsFloorVisibility },
        { "getTownFloorVisiblity", TownBaseBinding::getTownFloorVisiblity },
        { "setTownFloorVisiblity", TownBaseBinding::setTownFloorVisiblity },
        { "resetTownFloorVisibility", TownBaseBinding::resetTownFloorVisibility },
        { "getMapMarker", TownBaseBinding::getMapMarker },
        { "_NV_getMapMarker", TownBaseBinding::_NV_getMapMarker },
        { "getMapMarkerZoomLevel", TownBaseBinding::getMapMarkerZoomLevel },
        { "_NV_getMapMarkerZoomLevel", TownBaseBinding::_NV_getMapMarkerZoomLevel },
        { "isOccupied", TownBaseBinding::isOccupied },
        { "distributeArtifacts", TownBaseBinding::distributeArtifacts },
        { "setFaction", TownBase_setFaction },
        { "_NV_setFaction", TownBase__NV_setFaction },
        { "findAllBuildingsOfType", TownBase_findAllBuildingsOfType },
        { "_NV_findAllBuildingsOfType", TownBase__NV_findAllBuildingsOfType },
        { "findAllBuildingsWithFunction", TownBase_findAllBuildingsWithFunction },
        { "_NV_findAllBuildingsWithFunction", TownBase__NV_findAllBuildingsWithFunction },
        { "getCurrentTownLocation", TownBase_getCurrentTownLocation },
        { "_NV_getCurrentTownLocation", TownBase__NV_getCurrentTownLocation },
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
    lua_pushcfunction(L, TownBase_get_positionCacher);
    lua_setfield(L, -2, "positionCacher");
    lua_pushcfunction(L, TownBase_get_townType);
    lua_setfield(L, -2, "townType");
    lua_pushcfunction(L, TownBase_get_population);
    lua_setfield(L, -2, "population");
    lua_pushcfunction(L, TownBase_get_factionsResidentHere);
    lua_setfield(L, -2, "factionsResidentHere");
    lua_pushcfunction(L, TownBase_get_alreadyInitialisedPopulationParams);
    lua_setfield(L, -2, "alreadyInitialisedPopulationParams");
    lua_pushcfunction(L, TownBase_get_isSecret);
    lua_setfield(L, -2, "isSecret");
    lua_pushcfunction(L, TownBase_get_occupiers);
    lua_setfield(L, -2, "occupiers");
    lua_pushcfunction(L, TownBase_get_timeOfDeath);
    lua_setfield(L, -2, "timeOfDeath");
    lua_pushcfunction(L, TownBase_get_p_TIME);
    lua_setfield(L, -2, "p_TIME");
    lua_pushcfunction(L, TownBase_get_nestBatcher);
    lua_setfield(L, -2, "nestBatcher");
    lua_pushcfunction(L, TownBase_get_unexploredName);
    lua_setfield(L, -2, "unexploredName");
    lua_pushcfunction(L, TownBase_get_discovered);
    lua_setfield(L, -2, "discovered");
    lua_pushcfunction(L, TownBase_get_explored);
    lua_setfield(L, -2, "explored");
    lua_pushcfunction(L, TownBase_get_recentlyDiscovered);
    lua_setfield(L, -2, "recentlyDiscovered");
    lua_pushcfunction(L, TownBase_get_entityMarker);
    lua_setfield(L, -2, "entityMarker");
    lua_pushcfunction(L, TownBase_get_entityLabel);
    lua_setfield(L, -2, "entityLabel");
    lua_pushcfunction(L, TownBase_get_clickHull);
    lua_setfield(L, -2, "clickHull");
    lua_pushcfunction(L, TownBase_get_biome);
    lua_setfield(L, -2, "biome");
    lua_pushcfunction(L, TownBase_get_alarmState);
    lua_setfield(L, -2, "alarmState");
    lua_pushcfunction(L, TownBase_get_isActivated);
    lua_setfield(L, -2, "isActivated");
    lua_pushcfunction(L, TownBase_get_myZoneCoverage);
    lua_setfield(L, -2, "myZoneCoverage");
    lua_pushcfunction(L, TownBase_get_populatedZones);
    lua_setfield(L, -2, "populatedZones");
    lua_pushcfunction(L, TownBase_get_artifacts);
    lua_setfield(L, -2, "artifacts");
    lua_pushcfunction(L, TownBase_get_currentFloorVisibility);
    lua_setfield(L, -2, "currentFloorVisibility");
    lua_pushcfunction(L, TownBase_get_buildingsManager);
    lua_setfield(L, -2, "buildingsManager");
    lua_pushcfunction(L, TownBase_get_residentsSpawned);
    lua_setfield(L, -2, "residentsSpawned");
    lua_pushcfunction(L, TownBase_get_residentsSpawned_BarsOrSomething);
    lua_setfield(L, -2, "residentsSpawned_BarsOrSomething");
    lua_pushcfunction(L, TownBase_get_defaultResident);
    lua_setfield(L, -2, "defaultResident");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, TownBase_set_positionCacher);
    lua_setfield(L, -2, "positionCacher");
    lua_pushcfunction(L, TownBase_set_townType);
    lua_setfield(L, -2, "townType");
    lua_pushcfunction(L, TownBase_set_population);
    lua_setfield(L, -2, "population");
    lua_pushcfunction(L, TownBase_set_factionsResidentHere);
    lua_setfield(L, -2, "factionsResidentHere");
    lua_pushcfunction(L, TownBase_set_alreadyInitialisedPopulationParams);
    lua_setfield(L, -2, "alreadyInitialisedPopulationParams");
    lua_pushcfunction(L, TownBase_set_isSecret);
    lua_setfield(L, -2, "isSecret");
    lua_pushcfunction(L, TownBase_set_occupiers);
    lua_setfield(L, -2, "occupiers");
    lua_pushcfunction(L, TownBase_set_timeOfDeath);
    lua_setfield(L, -2, "timeOfDeath");
    lua_pushcfunction(L, TownBase_set_p_TIME);
    lua_setfield(L, -2, "p_TIME");
    lua_pushcfunction(L, TownBase_set_nestBatcher);
    lua_setfield(L, -2, "nestBatcher");
    lua_pushcfunction(L, TownBase_set_unexploredName);
    lua_setfield(L, -2, "unexploredName");
    lua_pushcfunction(L, TownBase_set_discovered);
    lua_setfield(L, -2, "discovered");
    lua_pushcfunction(L, TownBase_set_explored);
    lua_setfield(L, -2, "explored");
    lua_pushcfunction(L, TownBase_set_recentlyDiscovered);
    lua_setfield(L, -2, "recentlyDiscovered");
    lua_pushcfunction(L, TownBase_set_entityMarker);
    lua_setfield(L, -2, "entityMarker");
    lua_pushcfunction(L, TownBase_set_entityLabel);
    lua_setfield(L, -2, "entityLabel");
    lua_pushcfunction(L, TownBase_set_clickHull);
    lua_setfield(L, -2, "clickHull");
    lua_pushcfunction(L, TownBase_set_biome);
    lua_setfield(L, -2, "biome");
    lua_pushcfunction(L, TownBase_set_alarmState);
    lua_setfield(L, -2, "alarmState");
    lua_pushcfunction(L, TownBase_set_isActivated);
    lua_setfield(L, -2, "isActivated");
    lua_pushcfunction(L, TownBase_set_myZoneCoverage);
    lua_setfield(L, -2, "myZoneCoverage");
    lua_pushcfunction(L, TownBase_set_populatedZones);
    lua_setfield(L, -2, "populatedZones");
    lua_pushcfunction(L, TownBase_set_artifacts);
    lua_setfield(L, -2, "artifacts");
    lua_pushcfunction(L, TownBase_set_currentFloorVisibility);
    lua_setfield(L, -2, "currentFloorVisibility");
    lua_pushcfunction(L, TownBase_set_buildingsManager);
    lua_setfield(L, -2, "buildingsManager");
    lua_pushcfunction(L, TownBase_set_residentsSpawned);
    lua_setfield(L, -2, "residentsSpawned");
    lua_pushcfunction(L, TownBase_set_residentsSpawned_BarsOrSomething);
    lua_setfield(L, -2, "residentsSpawned_BarsOrSomething");
    lua_pushcfunction(L, TownBase_set_defaultResident);
    lua_setfield(L, -2, "defaultResident");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    LektorPtrBinding<Building*>::registerBinding(L, "lektor<Building*>", BuildingBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua