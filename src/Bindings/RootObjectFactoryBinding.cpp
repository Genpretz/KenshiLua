#include "pch.h"
#include "kenshi\RootObjectFactory.h"
#include "RootObjectFactoryBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/FactoryCallbackInterfaceBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataReferenceBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/OwnershipsBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/RaceDataBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/RootObjectBaseBinding.h"
#include "Bindings/RootObjectContainerBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "CreatelistItemBinding.h"
#include "Util/LektorBinding.h"
#include "Util/StdDequeBinding.h"
#include <kenshi/Building/Building.h>
#include <kenshi/Enums.h>
#include <kenshi/Faction.h>
#include <kenshi/GameSaveState.h>
#include <kenshi/Item.h>
#include <kenshi/RootObject.h>
#include <kenshi/RootObjectBase.h>
#include <kenshi/Town.h>
#include <kenshi/util/TripleInt.h>

namespace KenshiLua
{
typedef StdDequePtrBinding<RootObjectFactory::CreatelistItem*> CreatelistItemDequeBinding;

static int RootObjectFactory_get_mutex(lua_State* L) { return 0; }
static int RootObjectFactory_set_mutex(lua_State* L) { return 0; }


static RootObjectFactory* getInstance(lua_State* L, int idx)
{
    return checkObject<RootObjectFactory>(L, idx, RootObjectFactoryBinding::getMetatableName());
}

// --- Getters for RootObjectFactory ---


// --- Setters for RootObjectFactory ---


int RootObjectFactoryBinding::create(lua_State* L)
{
    RootObjectFactory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectFactory is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Ogre::Vector3 position;
    readVector3(L, 3, position);
    bool isFromActiveLevelMod = lua_toboolean(L, 4) != 0;
    Faction* owner = checkObject<Faction>(L, 5, FactionBinding::getMetatableName());
    Ogre::Quaternion rotation;
    readQuaternion(L, 6, rotation);
    FactoryCallbackInterface* callbackObject = checkObject<FactoryCallbackInterface>(L, 7, FactoryCallbackInterfaceBinding::getMetatableName());
    RootObjectContainer* certainContainer = checkObject<RootObjectContainer>(L, 8, RootObjectContainerBinding::getMetatableName());
    GameSaveState* state = checkObject<GameSaveState>(L, 9, GameSaveStateBinding::getMetatableName());
    bool invisible = lua_toboolean(L, 10) != 0;
    Building* homeBuilding = checkObject<Building>(L, 11, BuildingBinding::getMetatableName());
    float age = (float)luaL_checknumber(L, 12);
    RootObjectBase* result = instance->create(data, position, isFromActiveLevelMod, owner, rotation, callbackObject, certainContainer, state, invisible, homeBuilding, age);
    return pushObject<RootObjectBase>(L, result, RootObjectBaseBinding::getMetatableName());
}

int RootObjectFactoryBinding::createLocationNode(lua_State* L)
{
    RootObjectFactory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectFactory is nil");

    bool addToNodeListAutomatically = lua_toboolean(L, 2) != 0;
    GameData* data = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    Ogre::Vector3 position;
    readVector3(L, 4, position);
    Building* building = checkObject<Building>(L, 5, BuildingBinding::getMetatableName());
    Faction* owner = checkObject<Faction>(L, 6, FactionBinding::getMetatableName());
    Ogre::Quaternion rotation;
    readQuaternion(L, 7, rotation);
    GameSaveState* saveState = checkObject<GameSaveState>(L, 8, GameSaveStateBinding::getMetatableName());
    const std::string nodeId = luaL_checkstring(L, 9);
    LocationNode* result = instance->createLocationNode(addToNodeListAutomatically, data, position, building, owner, rotation, saveState, nodeId);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int RootObjectFactoryBinding::copyItem(lua_State* L)
{
    RootObjectFactory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectFactory is nil");

    Item* from = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    Item* result = instance->copyItem(from);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int RootObjectFactoryBinding::chooseDataFromList(lua_State* L)
{
    RootObjectFactory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectFactory is nil");

    GameData* dataList = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    const std::string listName = luaL_checkstring(L, 3);
    itemType materialDataType = (itemType)luaL_checkinteger(L, 4);
    int useVal012 = (int)luaL_checkinteger(L, 5);
    GameData* result = instance->chooseDataFromList(dataList, listName, materialDataType, useVal012);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int RootObjectFactoryBinding::chooseDataFromListWithVals(lua_State* L)
{
    RootObjectFactory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectFactory is nil");

    GameData* dataList = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    const std::string listName = luaL_checkstring(L, 3);
    itemType materialDataType = (itemType)luaL_checkinteger(L, 4);
    int useVal012 = (int)luaL_checkinteger(L, 5);
    const GameDataReference* result = instance->chooseDataFromListWithVals(dataList, listName, materialDataType, useVal012);
    return pushObject<GameDataReference>(L, const_cast<GameDataReference*>(result), GameDataReferenceBinding::getMetatableName());
}

int RootObjectFactoryBinding::createCharacterForBuilding(lua_State* L)
{
    RootObjectFactory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectFactory is nil");

    Building* b = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    instance->createCharacterForBuilding(b);
    return 0;
}

int RootObjectFactoryBinding::createRandomCharacter(lua_State* L)
{
    RootObjectFactory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectFactory is nil");

    Faction* faction = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    Ogre::Vector3 position;
    readVector3(L, 3, position);
    RootObjectContainer* owner = checkObject<RootObjectContainer>(L, 4, RootObjectContainerBinding::getMetatableName());
    GameData* characterTemplate = checkObject<GameData>(L, 5, GameDataBinding::getMetatableName());
    Building* home = checkObject<Building>(L, 6, BuildingBinding::getMetatableName());
    float age = (float)luaL_checknumber(L, 7);
    RootObject* result = instance->createRandomCharacter(faction, position, owner, characterTemplate, home, age);
    return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
}

int RootObjectFactoryBinding::mainThreadUpdate(lua_State* L)
{
    RootObjectFactory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectFactory is nil");

    instance->mainThreadUpdate();
    return 0;
}

int RootObjectFactoryBinding::populateBuilding(lua_State* L)
{
    RootObjectFactory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectFactory is nil");

    Building* building = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    instance->populateBuilding(building);
    return 0;
}

int RootObjectFactoryBinding::process(lua_State* L)
{
    RootObjectFactory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectFactory is nil");

    RootObjectFactory::CreatelistItem* o = (RootObjectFactory::CreatelistItem*)lua_touserdata(L, 2);
    RootObjectBase* result = instance->process(o);
    return pushObject<RootObjectBase>(L, result, RootObjectBaseBinding::getMetatableName());
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - RootObjectFactoryBinding::createLocationNode: LocationNode* (unbound pointer)
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

static int RootObjectFactory_get_todoList(lua_State* L)
{
    RootObjectFactory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectFactory is nil");
    return pushObject<CreatelistItemDequeBinding::DequeType>(L, &instance->todoList, "std::deque<CreatelistItem*>");
}

static int RootObjectFactory_set_todoList(lua_State* L)
{
    RootObjectFactory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectFactory is nil");
    if (lua_isnoneornil(L, 2))
    {
        instance->todoList.clear();
        return 0;
    }
    auto* src = CreatelistItemDequeBinding::get(L, 2);
    if (!src) return luaL_error(L, "Argument 2 to set todoList must be std::deque<CreatelistItem*>");
    instance->todoList = *src;
    return 0;
}


int RootObjectFactoryBinding::createBuilding(lua_State* L)
{
    RootObjectFactory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectFactory is nil");

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

    Building* result = instance->createBuilding(data, position, t, owner, rotation, callbackObject, furnitureOf, isDoorOf, saveState, isIndoorsOf, invisible, completed, isFoliage, floorNumber, isOutsideFurniture);
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}


int RootObjectFactoryBinding::createItem(lua_State* L)
{
    RootObjectFactory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectFactory is nil");

    int nargs = lua_gettop(L) - 1;
    if (nargs == 1)
    {
        GameData* itemState = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
        Item* result = instance->createItem(itemState);
        return pushObject<Item>(L, result, ItemBinding::getMetatableName());
    }
    else if (nargs == 6)
    {
        GameData* gd = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
        hand* handle = checkObject<hand>(L, 3, HandBinding::getMetatableName());
        GameData* weaponMesh = lua_isnil(L, 4) ? NULL : checkObject<GameData>(L, 4, GameDataBinding::getMetatableName());
        GameData* matData = lua_isnil(L, 5) ? NULL : checkObject<GameData>(L, 5, GameDataBinding::getMetatableName());
        int levelOverride = (int)luaL_checkinteger(L, 6);
        Faction* flagUniform = lua_isnil(L, 7) ? NULL : checkObject<Faction>(L, 7, FactionBinding::getMetatableName());

        Item* result = instance->createItem(gd, *handle, weaponMesh, matData, levelOverride, flagUniform);
        return pushObject<Item>(L, result, ItemBinding::getMetatableName());
    }

    return luaL_error(L, "Incorrect number of arguments for RootObjectFactory:createItem (expected 1 or 6)");
}


int RootObjectFactoryBinding::createRandomSquad(lua_State* L)
{
    RootObjectFactory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectFactory is nil");

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
    hand* AItarget = checkObject<hand>(L, 12, HandBinding::getMetatableName());
    TownBase* targetTown = lua_isnil(L, 13) ? NULL : checkObject<TownBase>(L, 13, TownBaseBinding::getMetatableName());
    float sizeMultiplier = (float)luaL_checknumber(L, 14);
    SquadType squadType = (SquadType)luaL_checkinteger(L, 15);
    bool isJustARefresh = lua_toboolean(L, 16) != 0;

    Platoon* result = instance->createRandomSquad(faction, position, homeTown, maxnum, home, squad, ownr, maparea, _activePlatoon, permanentsquad, *AItarget, targetTown, sizeMultiplier, squadType, isJustARefresh);
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}


int RootObjectFactoryBinding::createRandomUnloadedCharacter(lua_State* L)
{
    RootObjectFactory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectFactory is nil");

    Faction* faction = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    UnloadedPlatoon* platoon = (UnloadedPlatoon*)lua_touserdata(L, 3);
    Ogre::Vector3 position;
    readVector3(L, 4, position);
    GameData* characterTemplate = checkObject<GameData>(L, 5, GameDataBinding::getMetatableName());
    Ownerships* owns = lua_isnil(L, 6) ? NULL : checkObject<Ownerships>(L, 6, OwnershipsBinding::getMetatableName());

    GameSaveState result = instance->createRandomUnloadedCharacter(faction, platoon, position, characterTemplate, owns);
    return pushValue<GameSaveState>(L, result, GameSaveStateBinding::getMetatableName());
}


int RootObjectFactoryBinding::createRandomUnloadedSquad(lua_State* L)
{
    RootObjectFactory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectFactory is nil");

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
    hand* AItarget = checkObject<hand>(L, 11, HandBinding::getMetatableName());
    TownBase* targetTown = lua_isnil(L, 12) ? NULL : checkObject<TownBase>(L, 12, TownBaseBinding::getMetatableName());
    SquadType squadType = (SquadType)luaL_checkinteger(L, 13);

    Platoon* result = instance->createRandomUnloadedSquad(faction, position, homeTown, maxnum, home, squad, owner, maparea, permanentsquad, *AItarget, targetTown, squadType);
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}


int RootObjectFactoryBinding::getValsFromDataInList(lua_State* L)
{
    RootObjectFactory* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectFactory is nil");

    GameData* dataList = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* itemInList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    std::string listName = luaL_checkstring(L, 4);

    TripleInt result = instance->getValsFromDataInList(dataList, itemInList, listName);
    pushTripleInt(L, result);
    return 1;
}


int RootObjectFactoryBinding::_chooseClothingItemFromList(lua_State* L)
{
    int offset = 1;
    if (lua_isuserdata(L, 1))
    {
        luaL_getmetatable(L, RootObjectFactoryBinding::getMetatableName());
        if (lua_istable(L, -1))
        {
            if (lua_getmetatable(L, 1))
            {
                if (lua_rawequal(L, -1, -2)) offset = 2;
                lua_pop(L, 1);
            }
        }
        lua_pop(L, 1);
    }

    GameData* dataList = checkObject<GameData>(L, offset, GameDataBinding::getMetatableName());
    std::string listName = luaL_checkstring(L, offset + 1);
    AttachSlot slot = (AttachSlot)luaL_checkinteger(L, offset + 2);
    RaceData* race = checkObject<RaceData>(L, offset + 3, RaceDataBinding::getMetatableName());

    GameData* result = RootObjectFactory::_chooseClothingItemFromList(dataList, listName, slot, race);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}


int RootObjectFactoryBinding::chooseMyClothing(lua_State* L)
{
    int offset = 1;
    if (lua_isuserdata(L, 1))
    {
        luaL_getmetatable(L, RootObjectFactoryBinding::getMetatableName());
        if (lua_istable(L, -1))
        {
            if (lua_getmetatable(L, 1))
            {
                if (lua_rawequal(L, -1, -2)) offset = 2;
                lua_pop(L, 1);
            }
        }
        lua_pop(L, 1);
    }

    lektor<GameData*>* gear = checkObject<lektor<GameData*>>(L, offset, LektorPtrBinding<GameData*>::metaName);
    GameData* dataList = checkObject<GameData>(L, offset + 1, GameDataBinding::getMetatableName());
    std::string listName = luaL_checkstring(L, offset + 2);
    RaceData* race = checkObject<RaceData>(L, offset + 3, RaceDataBinding::getMetatableName());
    bool noShoes = lua_toboolean(L, offset + 4) != 0;

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
        { "create", RootObjectFactoryBinding::create },
        { "createLocationNode", RootObjectFactoryBinding::createLocationNode },
        { "copyItem", RootObjectFactoryBinding::copyItem },
        { "chooseDataFromList", RootObjectFactoryBinding::chooseDataFromList },
        { "chooseDataFromListWithVals", RootObjectFactoryBinding::chooseDataFromListWithVals },
        { "createCharacterForBuilding", RootObjectFactoryBinding::createCharacterForBuilding },
        { "createRandomCharacter", RootObjectFactoryBinding::createRandomCharacter },
        { "mainThreadUpdate", RootObjectFactoryBinding::mainThreadUpdate },
        { "populateBuilding", RootObjectFactoryBinding::populateBuilding },
        { "process", RootObjectFactoryBinding::process },
        { "createBuilding", RootObjectFactoryBinding::createBuilding },
        { "createItem", RootObjectFactoryBinding::createItem },
        { "getValsFromDataInList", RootObjectFactoryBinding::getValsFromDataInList },
        { "createRandomUnloadedCharacter", RootObjectFactoryBinding::createRandomUnloadedCharacter },
        { "createRandomSquad", RootObjectFactoryBinding::createRandomSquad },
        { "createRandomUnloadedSquad", RootObjectFactoryBinding::createRandomUnloadedSquad },
        { "chooseMyClothing", RootObjectFactoryBinding::chooseMyClothing },
        { "_chooseClothingItemFromList", RootObjectFactoryBinding::_chooseClothingItemFromList },
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
    
    registerGetter(L, "mutex", RootObjectFactory_get_mutex);
    registerGetter(L, "todoList", RootObjectFactory_get_todoList);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    
    registerSetter(L, "mutex", RootObjectFactory_set_mutex);
    registerSetter(L, "todoList", RootObjectFactory_set_todoList);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    CreatelistItemDequeBinding::registerBinding(L, "std::deque<CreatelistItem*>", CreatelistItemBinding::getMetatableName());

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, RootObjectFactoryBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack

    // Register class table for static methods
    lua_newtable(L);
    //registerStaticMethod(L, "_chooseClothingItemFromList", RootObjectFactoryBinding::_chooseClothingItemFromList);
    registerStaticMethod(L, "chooseClothingItemFromList", RootObjectFactoryBinding::_chooseClothingItemFromList);
    registerStaticMethod(L, "chooseMyClothing", RootObjectFactoryBinding::chooseMyClothing);
    lua_setglobal(L, "RootObjectFactory");
}

} // namespace KenshiLua