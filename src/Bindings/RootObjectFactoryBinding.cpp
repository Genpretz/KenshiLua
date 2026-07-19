#include "pch.h"
#include "Bindings/Building/BuildingBinding.h"


// KenshiLua
#include "RootObjectFactoryBinding.h"
#include "Lua/BindingHelpers.h"
#include "GameDataBinding.h"
#include "RaceDataBinding.h"
#include "FactionBinding.h"
#include "Building/BuildingBinding.h"
#include "TownBaseBinding.h"
#include "ItemBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "GameDataReferenceBinding.h"
#include "RootObjectBinding.h"
#include "OwnershipsBinding.h"
#include "PlatoonBinding.h"
#include "RootObjectBaseBinding.h"
#include "FactoryCallbackInterfaceBinding.h"
#include "GameSaveStateBinding.h"
#include "CreatelistItemBinding.h"
#include "Templates/LektorBinding.h"

// KenshiLib
#include <kenshi/RootObjectFactory.h>
#include <kenshi/Enums.h>
#include <kenshi/util/TripleInt.h>
#include <kenshi/Building/Building.h>
#include <kenshi/Town.h>
#include <kenshi/Item.h>
#include <kenshi/RootObject.h>
#include <kenshi/RootObjectBase.h>
#include <kenshi/Faction.h>
#include <kenshi/GameSaveState.h>

namespace KenshiLua
{

static RootObjectFactory* getB(lua_State* L, int idx)
{
    return checkObject<RootObjectFactory>(L, idx, RootObjectFactoryBinding::getMetatableName());
}

// --- Getters for RootObjectFactory ---
static int RootObjectFactory_get_todoMutex(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");
    lua_pushnil(L);
    return 1;
}

static int RootObjectFactory_get_todoList(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");
    // TODO: Unsupported type for todoList (std::deque<RootObjectFactory::CreatelistItem*, std::allocator<RootObjectFactory::CreatelistItem*> >)
    return luaL_error(L, "Unsupported property 'todoList' (type: std::deque<RootObjectFactory::CreatelistItem*, std::allocator<RootObjectFactory::CreatelistItem*> >)");
}

// --- Setters for RootObjectFactory ---
static int RootObjectFactory_set_todoMutex(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");
    return luaL_error(L, "Read-only or unsupported setter type for todoMutex");
}

static int RootObjectFactory_set_todoList(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");
    return luaL_error(L, "Read-only or unsupported setter type for todoList");
}

int RootObjectFactoryBinding::mainThreadUpdate(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");

    b->mainThreadUpdate();
    return 0;
}

int RootObjectFactoryBinding::_DESTRUCTOR(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 76: RootObjectFactory* _CONSTRUCTOR(...) - unsupported return type
*/

int RootObjectFactoryBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int RootObjectFactoryBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.RootObjectFactory object");
    return 1;
}

int RootObjectFactoryBinding::create(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Ogre::Vector3 position;
    readVector3(L, 3, position);
    bool isFromActiveLevelMod = lua_toboolean(L, 4) != 0;
    Faction* owner = checkObject<Faction>(L, 5, FactionBinding::getMetatableName());
    Ogre::Quaternion rotation;
    readQuaternion(L, 6, rotation);
    FactoryCallbackInterface* callbackObject = lua_isnil(L, 7) ? NULL : checkObject<FactoryCallbackInterface>(L, 7, FactoryCallbackInterfaceBinding::getMetatableName());
    RootObjectContainer* certainContainer = lua_isnil(L, 8) ? NULL : checkObject<RootObjectContainer>(L, 8, "KenshiLua.RootObjectContainer");
    GameSaveState* state = lua_isnil(L, 9) ? NULL : checkObject<GameSaveState>(L, 9, GameSaveStateBinding::getMetatableName());
    bool invisible = lua_toboolean(L, 10) != 0;
    Building* homeBuilding = lua_isnil(L, 11) ? NULL : checkObject<Building>(L, 11, BuildingBinding::getMetatableName());
    float age = (float)luaL_checknumber(L, 12);

    RootObjectBase* result = b->create(data, position, isFromActiveLevelMod, owner, rotation, callbackObject, certainContainer, state, invisible, homeBuilding, age);
    return pushObject<RootObjectBase>(L, result, RootObjectBaseBinding::getMetatableName());
}

int RootObjectFactoryBinding::createBuilding(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Ogre::Vector3 position;
    readVector3(L, 3, position);
    TownBase* t = checkObject<TownBase>(L, 4, TownBaseBinding::getMetatableName());
    Faction* owner = checkObject<Faction>(L, 5, FactionBinding::getMetatableName());
    Ogre::Quaternion rotation;
    readQuaternion(L, 6, rotation);
    FactoryCallbackInterface* callbackObject = lua_isnil(L, 7) ? NULL : checkObject<FactoryCallbackInterface>(L, 7, FactoryCallbackInterfaceBinding::getMetatableName());
    Layout* furnitureOf = (Layout*)lua_touserdata(L, 8);
    Building* isDoorOf = lua_isnil(L, 9) ? NULL : checkObject<Building>(L, 9, BuildingBinding::getMetatableName());
    GameSaveState* saveState = lua_isnil(L, 10) ? NULL : checkObject<GameSaveState>(L, 10, GameSaveStateBinding::getMetatableName());
    Building* isIndoorsOf = lua_isnil(L, 11) ? NULL : checkObject<Building>(L, 11, BuildingBinding::getMetatableName());
    bool invisible = lua_toboolean(L, 12) != 0;
    bool completed = lua_toboolean(L, 13) != 0;
    bool isFoliage = lua_toboolean(L, 14) != 0;
    int floorNumber = (int)luaL_checkinteger(L, 15);
    bool isOutsideFurniture = lua_toboolean(L, 16) != 0;

    Building* result = b->createBuilding(data, position, t, owner, rotation, callbackObject, furnitureOf, isDoorOf, saveState, isIndoorsOf, invisible, completed, isFoliage, floorNumber, isOutsideFurniture);
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}

int RootObjectFactoryBinding::createLocationNode(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");

    bool addToNodeListAutomatically = lua_toboolean(L, 2) != 0;
    GameData* data = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    Ogre::Vector3 position;
    readVector3(L, 4, position);
    Building* building = lua_isnil(L, 5) ? NULL : checkObject<Building>(L, 5, BuildingBinding::getMetatableName());
    Faction* owner = checkObject<Faction>(L, 6, FactionBinding::getMetatableName());
    Ogre::Quaternion rotation;
    readQuaternion(L, 7, rotation);
    GameSaveState* saveState = lua_isnil(L, 8) ? NULL : checkObject<GameSaveState>(L, 8, GameSaveStateBinding::getMetatableName());
    std::string nodeId = luaL_checkstring(L, 9);

    LocationNode* result = b->createLocationNode(addToNodeListAutomatically, data, position, building, owner, rotation, saveState, nodeId);
    if (result)
        lua_pushlightuserdata(L, result);
    else
        lua_pushnil(L);
    return 1;
}

int RootObjectFactoryBinding::createItem(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");

    int nargs = lua_gettop(L) - 1;
    if (nargs == 1)
    {
        GameData* itemState = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
        Item* result = b->createItem(itemState);
        return pushObject<Item>(L, result, ItemBinding::getMetatableName());
    }
    else if (nargs == 6)
    {
        GameData* gd = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
        hand* handle = checkObject<hand>(L, 3, handBinding::getMetatableName());
        GameData* weaponMesh = lua_isnil(L, 4) ? NULL : checkObject<GameData>(L, 4, GameDataBinding::getMetatableName());
        GameData* matData = lua_isnil(L, 5) ? NULL : checkObject<GameData>(L, 5, GameDataBinding::getMetatableName());
        int levelOverride = (int)luaL_checkinteger(L, 6);
        Faction* flagUniform = lua_isnil(L, 7) ? NULL : checkObject<Faction>(L, 7, FactionBinding::getMetatableName());

        Item* result = b->createItem(gd, *handle, weaponMesh, matData, levelOverride, flagUniform);
        return pushObject<Item>(L, result, ItemBinding::getMetatableName());
    }

    return luaL_error(L, "Incorrect number of arguments for RootObjectFactory:createItem (expected 1 or 6)");
}

int RootObjectFactoryBinding::copyItem(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");

    Item* from = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    Item* result = b->copyItem(from);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int RootObjectFactoryBinding::chooseDataFromList(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");

    GameData* dataList = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    std::string listName = luaL_checkstring(L, 3);
    itemType materialDataType = (itemType)luaL_checkinteger(L, 4);
    int useVal012 = (int)luaL_checkinteger(L, 5);

    GameData* result = b->chooseDataFromList(dataList, listName, materialDataType, useVal012);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int RootObjectFactoryBinding::chooseDataFromListWithVals(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");

    GameData* dataList = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    std::string listName = luaL_checkstring(L, 3);
    itemType materialDataType = (itemType)luaL_checkinteger(L, 4);
    int useVal012 = (int)luaL_checkinteger(L, 5);

    const GameDataReference* result = b->chooseDataFromListWithVals(dataList, listName, materialDataType, useVal012);
    return pushObject<const GameDataReference>(L, result, GameDataReferenceBinding::getMetatableName());
}

int RootObjectFactoryBinding::getValsFromDataInList(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");

    GameData* dataList = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* itemInList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    std::string listName = luaL_checkstring(L, 4);

    TripleInt result = b->getValsFromDataInList(dataList, itemInList, listName);
    lua_newtable(L);
    lua_pushinteger(L, result.value[0]);
    lua_rawseti(L, -2, 1);
    lua_pushinteger(L, result.value[1]);
    lua_rawseti(L, -2, 2);
    lua_pushinteger(L, result.value[2]);
    lua_rawseti(L, -2, 3);
    return 1;
}

int RootObjectFactoryBinding::createCharacterForBuilding(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");

    Building* building = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    b->createCharacterForBuilding(building);
    return 0;
}

int RootObjectFactoryBinding::createRandomCharacter(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");

    Faction* faction = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    Ogre::Vector3 position;
    readVector3(L, 3, position);
    RootObjectContainer* owner = lua_isnil(L, 4) ? NULL : checkObject<RootObjectContainer>(L, 4, "KenshiLua.RootObjectContainer");
    GameData* characterTemplate = checkObject<GameData>(L, 5, GameDataBinding::getMetatableName());
    Building* home = lua_isnil(L, 6) ? NULL : checkObject<Building>(L, 6, BuildingBinding::getMetatableName());
    float age = (float)luaL_checknumber(L, 7);

    RootObject* result = b->createRandomCharacter(faction, position, owner, characterTemplate, home, age);
    return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
}

int RootObjectFactoryBinding::createRandomUnloadedCharacter(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");

    Faction* faction = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    UnloadedPlatoon* platoon = (UnloadedPlatoon*)lua_touserdata(L, 3);
    Ogre::Vector3 position;
    readVector3(L, 4, position);
    GameData* characterTemplate = checkObject<GameData>(L, 5, GameDataBinding::getMetatableName());
    Ownerships* owns = lua_isnil(L, 6) ? NULL : checkObject<Ownerships>(L, 6, OwnershipsBinding::getMetatableName());

    GameSaveState result = b->createRandomUnloadedCharacter(faction, platoon, position, characterTemplate, owns);
    GameSaveState* heapResult = new GameSaveState(result);
    return pushObject<GameSaveState>(L, heapResult, GameSaveStateBinding::getMetatableName());
}

int RootObjectFactoryBinding::createRandomSquad(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");

    Faction* faction = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    Ogre::Vector3 position;
    readVector3(L, 3, position);
    TownBase* homeTown = lua_isnil(L, 4) ? NULL : checkObject<TownBase>(L, 4, TownBaseBinding::getMetatableName());
    int maxnum = (int)luaL_checkinteger(L, 5);
    Building* home = lua_isnil(L, 6) ? NULL : checkObject<Building>(L, 6, BuildingBinding::getMetatableName());
    GameData* squad = checkObject<GameData>(L, 7, GameDataBinding::getMetatableName());
    RootObjectContainer* ownr = lua_isnil(L, 8) ? NULL : checkObject<RootObjectContainer>(L, 8, "KenshiLua.RootObjectContainer");
    AreaBiomeGroup* maparea = (AreaBiomeGroup*)lua_touserdata(L, 9);
    Platoon* _activePlatoon = lua_isnil(L, 10) ? NULL : checkObject<Platoon>(L, 10, PlatoonBinding::getMetatableName());
    bool permanentsquad = lua_toboolean(L, 11) != 0;
    hand* AItarget = checkObject<hand>(L, 12, handBinding::getMetatableName());
    TownBase* targetTown = lua_isnil(L, 13) ? NULL : checkObject<TownBase>(L, 13, TownBaseBinding::getMetatableName());
    float sizeMultiplier = (float)luaL_checknumber(L, 14);
    SquadType squadType = (SquadType)luaL_checkinteger(L, 15);
    bool isJustARefresh = lua_toboolean(L, 16) != 0;

    Platoon* result = b->createRandomSquad(faction, position, homeTown, maxnum, home, squad, ownr, maparea, _activePlatoon, permanentsquad, *AItarget, targetTown, sizeMultiplier, squadType, isJustARefresh);
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int RootObjectFactoryBinding::createRandomUnloadedSquad(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");

    Faction* faction = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    Ogre::Vector3 position;
    readVector3(L, 3, position);
    TownBase* homeTown = lua_isnil(L, 4) ? NULL : checkObject<TownBase>(L, 4, TownBaseBinding::getMetatableName());
    int maxnum = (int)luaL_checkinteger(L, 5);
    Building* home = lua_isnil(L, 6) ? NULL : checkObject<Building>(L, 6, BuildingBinding::getMetatableName());
    GameData* squad = checkObject<GameData>(L, 7, GameDataBinding::getMetatableName());
    RootObjectContainer* owner = lua_isnil(L, 8) ? NULL : checkObject<RootObjectContainer>(L, 8, "KenshiLua.RootObjectContainer");
    AreaBiomeGroup* maparea = (AreaBiomeGroup*)lua_touserdata(L, 9);
    bool permanentsquad = lua_toboolean(L, 10) != 0;
    hand* AItarget = checkObject<hand>(L, 11, handBinding::getMetatableName());
    TownBase* targetTown = lua_isnil(L, 12) ? NULL : checkObject<TownBase>(L, 12, TownBaseBinding::getMetatableName());
    SquadType squadType = (SquadType)luaL_checkinteger(L, 13);

    Platoon* result = b->createRandomUnloadedSquad(faction, position, homeTown, maxnum, home, squad, owner, maparea, permanentsquad, *AItarget, targetTown, squadType);
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int RootObjectFactoryBinding::populateBuilding(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");

    Building* building = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    b->populateBuilding(building);
    return 0;
}

int RootObjectFactoryBinding::process(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");

    RootObjectFactory::CreatelistItem* o = checkObject<RootObjectFactory::CreatelistItem>(L, 2, CreatelistItemBinding::getMetatableName());
    RootObjectBase* result = b->process(o);
    return pushObject<RootObjectBase>(L, result, RootObjectBaseBinding::getMetatableName());
}

static int lua_RootObjectFactory_chooseClothingItemFromList(lua_State* L)
{
    GameData* dataList = checkObject<GameData>(L, 1, GameDataBinding::getMetatableName());
    std::string listName = luaL_checkstring(L, 2);
    AttachSlot slot = (AttachSlot)luaL_checkinteger(L, 3);
    RaceData* race = checkObject<RaceData>(L, 4, RaceDataBinding::getMetatableName());

    GameData* result = RootObjectFactory::_chooseClothingItemFromList(dataList, listName, slot, race);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

static int lua_RootObjectFactory_chooseMyClothing(lua_State* L)
{
    lektor<GameData*>* gear = checkObject<lektor<GameData*>>(L, 1, LektorPtrBinding<GameData*>::metaName);
    GameData* dataList = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    std::string listName = luaL_checkstring(L, 3);
    RaceData* race = checkObject<RaceData>(L, 4, RaceDataBinding::getMetatableName());
    bool noShoes = lua_toboolean(L, 5) != 0;

    RootObjectFactory::chooseMyClothing(*gear, dataList, listName, race, noShoes);
    return 0;
}

void RootObjectFactoryBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RootObjectFactoryBinding::gc },
        { "__tostring", RootObjectFactoryBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "mainThreadUpdate", RootObjectFactoryBinding::mainThreadUpdate },
        { "_DESTRUCTOR", RootObjectFactoryBinding::_DESTRUCTOR },
        { "create", RootObjectFactoryBinding::create },
        { "createBuilding", RootObjectFactoryBinding::createBuilding },
        { "createLocationNode", RootObjectFactoryBinding::createLocationNode },
        { "createItem", RootObjectFactoryBinding::createItem },
        { "copyItem", RootObjectFactoryBinding::copyItem },
        { "chooseDataFromList", RootObjectFactoryBinding::chooseDataFromList },
        { "chooseDataFromListWithVals", RootObjectFactoryBinding::chooseDataFromListWithVals },
        { "getValsFromDataInList", RootObjectFactoryBinding::getValsFromDataInList },
        { "createCharacterForBuilding", RootObjectFactoryBinding::createCharacterForBuilding },
        { "createRandomCharacter", RootObjectFactoryBinding::createRandomCharacter },
        { "createRandomUnloadedCharacter", RootObjectFactoryBinding::createRandomUnloadedCharacter },
        { "createRandomSquad", RootObjectFactoryBinding::createRandomSquad },
        { "createRandomUnloadedSquad", RootObjectFactoryBinding::createRandomUnloadedSquad },
        { "populateBuilding", RootObjectFactoryBinding::populateBuilding },
        { "process", RootObjectFactoryBinding::process },
        { 0, 0 }
    };

    registerClass(
        L, 
        RootObjectFactoryBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, RootObjectFactoryBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, RootObjectFactory_get_todoMutex);
    lua_setfield(L, -2, "todoMutex");
    lua_pushcfunction(L, RootObjectFactory_get_todoList);
    lua_setfield(L, -2, "todoList");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, RootObjectFactory_set_todoMutex);
    lua_setfield(L, -2, "todoMutex");
    lua_pushcfunction(L, RootObjectFactory_set_todoList);
    lua_setfield(L, -2, "todoList");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack

    // Register class table for static methods
    lua_newtable(L);
    lua_pushcfunction(L, lua_RootObjectFactory_chooseClothingItemFromList);
    lua_setfield(L, -2, "chooseClothingItemFromList");
    lua_pushcfunction(L, lua_RootObjectFactory_chooseMyClothing);
    lua_setfield(L, -2, "chooseMyClothing");
    lua_setglobal(L, "RootObjectFactory");
}

} // namespace KenshiLua
