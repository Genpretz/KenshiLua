#include "pch.h"
#include "kenshi/Town.h"
#include "TownListBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/FactionBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/GameDataContainerBinding.h"
#include "Bindings/Kenshi/RootObjectBinding.h"
#include "Bindings/Kenshi/RootObjectContainerBinding.h"
#include "Bindings/Kenshi/SerialisableBinding.h"
#include "Bindings/Kenshi/TownBinding.h"
#include "Bindings/Kenshi/TownBaseBinding.h"
#include "Bindings/Kenshi/Util/iVector2Binding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"

namespace KenshiLua
{

static_assert(offsetof(TownList, uniqueTowns) == 0x68, "TownList::uniqueTowns offset mismatch");
static_assert(offsetof(TownList, nests) == 0x80, "TownList::nests offset mismatch");
static_assert(offsetof(TownList, deletedTowns) == 0x98, "TownList::deletedTowns offset mismatch");
static_assert(offsetof(TownList, newTownsDiscovered) == 0xB0, "TownList::newTownsDiscovered offset mismatch");
static_assert(offsetof(TownList, noTown) == 0x180F8, "TownList::noTown offset mismatch");

static TownList* getInstance(lua_State* L, int idx)
{
    return checkObject<TownList>(L, idx, TownListBinding::getMetatableName());
}

static int TownList_get_newTownsDiscovered(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    lua_pushboolean(L, instance->newTownsDiscovered ? 1 : 0);
    return 1;
}

static int TownList_set_newTownsDiscovered(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    instance->newTownsDiscovered = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TownList_get_noTown(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    lua_pushlightuserdata(L, (void*)instance->noTown);
    return 1;
}

static int TownList_get_uniqueTowns(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    return pushObject<lektor<RootObject*>>(L, &instance->uniqueTowns, LektorPtrBinding<RootObject*>::metaName);
}

static int TownList_get_nests(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    return pushObject<lektor<RootObject*>>(L, &instance->nests, LektorPtrBinding<RootObject*>::metaName);
}

static int TownList_get_deletedTowns(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    return pushObject<lektor<Town*>>(L, &instance->deletedTowns, LektorPtrBinding<Town*>::metaName);
}

int TownListBinding::addActiveObject(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    RootObject* b = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = instance->addActiveObject(b);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownListBinding::_NV_addActiveObject(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    RootObject* b = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = instance->_NV_addActiveObject(b);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownListBinding::updateTownCoverage(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    TownBase* n = checkObject<TownBase>(L, 2, TownBaseBinding::getMetatableName());
    instance->updateTownCoverage(n);
    return 0;
}

int TownListBinding::_clearAll(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    instance->_clearAll();
    return 0;
}

int TownListBinding::_resetGame(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    instance->_resetGame();
    return 0;
}

int TownListBinding::destroyAllTheNests(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    instance->destroyAllTheNests();
    return 0;
}

int TownListBinding::destroy(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    TownBase* t = checkObject<TownBase>(L, 2, TownBaseBinding::getMetatableName());
    instance->destroy(t);
    return 0;
}

int TownListBinding::getTown(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    std::string instanceID = luaL_checkstring(L, 2);
    Town* result = instance->getTown(instanceID);
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<Town>(L, result, TownBinding::getMetatableName());
}

int TownListBinding::getTownBySID(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    std::string name = luaL_checkstring(L, 2);
    Town* result = instance->getTownBySID(name);
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<Town>(L, result, TownBinding::getMetatableName());
}

int TownListBinding::getNearestPlayerTown(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    Ogre::Vector3 position;
    if (!readVector3(L, 2, position)) return luaL_error(L, "Argument 2 to getNearestPlayerTown must be Vector3");
    bool includePlayerResidenceTowns = lua_toboolean(L, 3) != 0;
    float maxDistance = (float)luaL_checknumber(L, 4);
    Town* result = instance->getNearestPlayerTown(position, includePlayerResidenceTowns, maxDistance);
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<Town>(L, result, TownBinding::getMetatableName());
}

int TownListBinding::getNearestTown(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    Ogre::Vector3 pos;
    if (!readVector3(L, 2, pos)) return luaL_error(L, "Argument 2 to getNearestTown must be Vector3");
    Faction* townOwner = lua_isnoneornil(L, 3) ? nullptr : checkObject<Faction>(L, 3, FactionBinding::getMetatableName());
    Town* except = lua_isnoneornil(L, 4) ? nullptr : checkObject<Town>(L, 4, TownBinding::getMetatableName());
    Faction* myFaction = lua_isnoneornil(L, 5) ? nullptr : checkObject<Faction>(L, 5, FactionBinding::getMetatableName());
    TownType type = (TownType)luaL_checkinteger(L, 6);
    Town* result = instance->getNearestTown(pos, townOwner, except, myFaction, type);
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<Town>(L, result, TownBinding::getMetatableName());
}

int TownListBinding::getNearestTownWithBuildingDesignation(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    BuildingDesignation what = (BuildingDesignation)luaL_checkinteger(L, 2);
    Ogre::Vector3 pos;
    if (!readVector3(L, 3, pos)) return luaL_error(L, "Argument 3 to getNearestTownWithBuildingDesignation must be Vector3");
    Faction* townFactionWanted = lua_isnoneornil(L, 4) ? nullptr : checkObject<Faction>(L, 4, FactionBinding::getMetatableName());
    Town* except = lua_isnoneornil(L, 5) ? nullptr : checkObject<Town>(L, 5, TownBinding::getMetatableName());
    Faction* notEnemiesOf = lua_isnoneornil(L, 6) ? nullptr : checkObject<Faction>(L, 6, FactionBinding::getMetatableName());
    TownType type = (TownType)luaL_checkinteger(L, 7);
    float maxDistanceSquared = (float)luaL_checknumber(L, 8);
    Town* result = instance->getNearestTownWithBuildingDesignation(what, pos, townFactionWanted, except, notEnemiesOf, type, maxDistanceSquared);
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<Town>(L, result, TownBinding::getMetatableName());
}

int TownListBinding::getNearestNest(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    Ogre::Vector3 pos;
    if (!readVector3(L, 2, pos)) return luaL_error(L, "Argument 2 to getNearestNest must be Vector3");
    Faction* f = lua_isnoneornil(L, 3) ? nullptr : checkObject<Faction>(L, 3, FactionBinding::getMetatableName());
    TownBase* except = lua_isnoneornil(L, 4) ? nullptr : checkObject<TownBase>(L, 4, TownBaseBinding::getMetatableName());
    Nest* result = instance->getNearestNest(pos, f, except);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TownListBinding::getNearest(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    Ogre::Vector3 pos;
    if (!readVector3(L, 2, pos)) return luaL_error(L, "Argument 2 to getNearest must be Vector3");
    Faction* f = lua_isnoneornil(L, 3) ? nullptr : checkObject<Faction>(L, 3, FactionBinding::getMetatableName());
    TownBase* except = lua_isnoneornil(L, 4) ? nullptr : checkObject<TownBase>(L, 4, TownBaseBinding::getMetatableName());
    TownBase* result = instance->getNearest(pos, f, except);
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int TownListBinding::getNearestWithinItsRadius(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    Ogre::Vector3 position;
    if (!readVector3(L, 2, position)) return luaL_error(L, "Argument 2 to getNearestWithinItsRadius must be Vector3");
    bool skipPlayerTowns = lua_toboolean(L, 3) != 0;
    TownBase* result = instance->getNearestWithinItsRadius(position, skipPlayerTowns);
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int TownListBinding::getRetreatTown(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    Ogre::Vector3 pos;
    if (!readVector3(L, 2, pos)) return luaL_error(L, "Argument 2 to getRetreatTown must be Vector3");
    Faction* owner = lua_isnoneornil(L, 3) ? nullptr : checkObject<Faction>(L, 3, FactionBinding::getMetatableName());
    Town* except = lua_isnoneornil(L, 4) ? nullptr : checkObject<Town>(L, 4, TownBinding::getMetatableName());
    Town* result = instance->getRetreatTown(pos, owner, except);
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<Town>(L, result, TownBinding::getMetatableName());
}

int TownListBinding::createNewPlayerTown(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    Ogre::Vector3 pos;
    if (!readVector3(L, 2, pos)) return luaL_error(L, "Argument 2 to createNewPlayerTown must be Vector3");
    Town* result = instance->createNewPlayerTown(pos);
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<Town>(L, result, TownBinding::getMetatableName());
}

int TownListBinding::getDistToNearestTown(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    Ogre::Vector3 pos;
    if (!readVector3(L, 2, pos)) return luaL_error(L, "Argument 2 to getDistToNearestTown must be Vector3");
    Town* except = lua_isnoneornil(L, 3) ? nullptr : checkObject<Town>(L, 3, TownBinding::getMetatableName());
    float result = instance->getDistToNearestTown(pos, except);
    lua_pushnumber(L, result);
    return 1;
}

int TownListBinding::getSquaredDistToNearestTown(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    Ogre::Vector3 pos;
    if (!readVector3(L, 2, pos)) return luaL_error(L, "Argument 2 to getSquaredDistToNearestTown must be Vector3");
    Town* except = lua_isnoneornil(L, 3) ? nullptr : checkObject<Town>(L, 3, TownBinding::getMetatableName());
    float result = instance->getSquaredDistToNearestTown(pos, except);
    lua_pushnumber(L, result);
    return 1;
}

int TownListBinding::getNearishTown(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    Faction* myFaction = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    Ogre::Vector3 pos;
    if (!readVector3(L, 3, pos)) return luaL_error(L, "Argument 3 to getNearishTown must be Vector3");
    Faction* owner = lua_isnoneornil(L, 4) ? nullptr : checkObject<Faction>(L, 4, FactionBinding::getMetatableName());
    TownBase* except = lua_isnoneornil(L, 5) ? nullptr : checkObject<TownBase>(L, 5, TownBaseBinding::getMetatableName());
    bool publicOnly = lua_toboolean(L, 6) != 0;
    unsigned int types = (unsigned int)luaL_checkinteger(L, 7);
    Town* result = instance->getNearishTown(myFaction, pos, owner, except, publicOnly, types);
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<Town>(L, result, TownBinding::getMetatableName());
}

int TownListBinding::getAllTowns(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    return pushObject<lektor<RootObject*>>(L, &instance->getAllTowns(), LektorPtrBinding<RootObject*>::metaName);
}

int TownListBinding::getNullTown(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    TownBase* result = instance->getNullTown();
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int TownListBinding::update(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    bool result = instance->update();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownListBinding::_NV_update(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    bool result = instance->_NV_update();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownListBinding::updateTownsDiscovery(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    instance->updateTownsDiscovery();
    return 0;
}

int TownListBinding::setAllTownsDebugVisible(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    bool on = lua_toboolean(L, 2) != 0;
    instance->setAllTownsDebugVisible(on);
    return 0;
}

int TownListBinding::saveToDisk(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    bool levelEditor = lua_toboolean(L, 2) != 0;
    std::string forceFilename = luaL_checkstring(L, 3);
    instance->saveToDisk(levelEditor, forceFilename);
    return 0;
}

int TownListBinding::_NV_saveToDisk(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    bool levelEditor = lua_toboolean(L, 2) != 0;
    std::string forceFilename = luaL_checkstring(L, 3);
    instance->_NV_saveToDisk(levelEditor, forceFilename);
    return 0;
}

int TownListBinding::loadFromDisk(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    bool force = lua_toboolean(L, 2) != 0;
    Serialisable* extra = lua_isnoneornil(L, 3) ? nullptr : checkObject<Serialisable>(L, 3, SerialisableBinding::getMetatableName());
    bool result = instance->loadFromDisk(force, extra);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownListBinding::_NV_loadFromDisk(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    bool force = lua_toboolean(L, 2) != 0;
    Serialisable* extra = lua_isnoneornil(L, 3) ? nullptr : checkObject<Serialisable>(L, 3, SerialisableBinding::getMetatableName());
    bool result = instance->_NV_loadFromDisk(force, extra);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TownListBinding::saveState(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    instance->saveState(container);
    return 0;
}

int TownListBinding::loadState(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    bool isImportSoPlayerOnly = lua_toboolean(L, 3) != 0;
    instance->loadState(container, isImportSoPlayerOnly);
    return 0;
}

int TownListBinding::loadStateDiscovery(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    bool importOverride = lua_toboolean(L, 3) != 0;
    instance->loadStateDiscovery(container, importOverride);
    return 0;
}

int TownListBinding::loadLevelData(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    bool newGame = lua_toboolean(L, 2) != 0;
    instance->loadLevelData(newGame);
    return 0;
}

int TownListBinding::_saveLevelData(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    std::string mod = luaL_checkstring(L, 3);
    instance->_saveLevelData(container, mod);
    return 0;
}

int TownListBinding::saveUniqueTownsAndNests(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    instance->saveUniqueTownsAndNests(container);
    return 0;
}

int TownListBinding::listUniqueTownsFromPlayerOwnership(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    instance->listUniqueTownsFromPlayerOwnership();
    return 0;
}

int TownListBinding::loadAllTowns_worldInit(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    GameDataContainer* saveSource = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    instance->loadAllTowns_worldInit(saveSource);
    return 0;
}

int TownListBinding::addNest(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    RootObject* n = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->addNest(n);
    return 0;
}

int TownListBinding::reassessTownPositions(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    TownBase* t = checkObject<TownBase>(L, 2, TownBaseBinding::getMetatableName());
    instance->reassessTownPositions(t);
    return 0;
}

int TownListBinding::mergePlayerTowns(lua_State* L)
{
    TownList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownList is nil");
    Town* a = checkObject<Town>(L, 2, TownBinding::getMetatableName());
    Town* b = checkObject<Town>(L, 3, TownBinding::getMetatableName());
    instance->mergePlayerTowns(a, b);
    return 0;
}

int TownListBinding::gc(lua_State* L)
{
    return 0;
}

int TownListBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TownList object");
    return 1;
}

void TownListBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TownListBinding::gc },
        { "__tostring", TownListBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "addActiveObject", TownListBinding::addActiveObject },
        { "_NV_addActiveObject", TownListBinding::_NV_addActiveObject },
        { "updateTownCoverage", TownListBinding::updateTownCoverage },
        { "_clearAll", TownListBinding::_clearAll },
        { "_resetGame", TownListBinding::_resetGame },
        { "destroyAllTheNests", TownListBinding::destroyAllTheNests },
        { "destroy", TownListBinding::destroy },
        { "getTown", TownListBinding::getTown },
        { "getTownBySID", TownListBinding::getTownBySID },
        { "getNearestPlayerTown", TownListBinding::getNearestPlayerTown },
        { "getNearestTown", TownListBinding::getNearestTown },
        { "getNearestTownWithBuildingDesignation", TownListBinding::getNearestTownWithBuildingDesignation },
        { "getNearestNest", TownListBinding::getNearestNest },
        { "getNearest", TownListBinding::getNearest },
        { "getNearestWithinItsRadius", TownListBinding::getNearestWithinItsRadius },
        { "getRetreatTown", TownListBinding::getRetreatTown },
        { "createNewPlayerTown", TownListBinding::createNewPlayerTown },
        { "getDistToNearestTown", TownListBinding::getDistToNearestTown },
        { "getSquaredDistToNearestTown", TownListBinding::getSquaredDistToNearestTown },
        { "getNearishTown", TownListBinding::getNearishTown },
        { "getAllTowns", TownListBinding::getAllTowns },
        { "getNullTown", TownListBinding::getNullTown },
        { "update", TownListBinding::update },
        { "_NV_update", TownListBinding::_NV_update },
        { "updateTownsDiscovery", TownListBinding::updateTownsDiscovery },
        { "setAllTownsDebugVisible", TownListBinding::setAllTownsDebugVisible },
        { "saveToDisk", TownListBinding::saveToDisk },
        { "_NV_saveToDisk", TownListBinding::_NV_saveToDisk },
        { "loadFromDisk", TownListBinding::loadFromDisk },
        { "_NV_loadFromDisk", TownListBinding::_NV_loadFromDisk },
        { "saveState", TownListBinding::saveState },
        { "loadState", TownListBinding::loadState },
        { "loadStateDiscovery", TownListBinding::loadStateDiscovery },
        { "loadLevelData", TownListBinding::loadLevelData },
        { "_saveLevelData", TownListBinding::_saveLevelData },
        { "saveUniqueTownsAndNests", TownListBinding::saveUniqueTownsAndNests },
        { "listUniqueTownsFromPlayerOwnership", TownListBinding::listUniqueTownsFromPlayerOwnership },
        { "loadAllTowns_worldInit", TownListBinding::loadAllTowns_worldInit },
        { "addNest", TownListBinding::addNest },
        { "reassessTownPositions", TownListBinding::reassessTownPositions },
        { "mergePlayerTowns", TownListBinding::mergePlayerTowns },
        { 0, 0 }
    };

    registerClass(
        L, 
        TownListBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TownListBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "newTownsDiscovered", TownList_get_newTownsDiscovered);
    registerGetter(L, "noTown", TownList_get_noTown);
    registerGetter(L, "uniqueTowns", TownList_get_uniqueTowns);
    registerGetter(L, "nests", TownList_get_nests);
    registerGetter(L, "deletedTowns", TownList_get_deletedTowns);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "newTownsDiscovered", TownList_set_newTownsDiscovered);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
