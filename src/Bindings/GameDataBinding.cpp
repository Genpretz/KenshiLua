#include "pch.h"
#include "kenshi\GameData.h"
#include "GameDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/GameDataReferenceBinding.h"
#include "Bindings/GameSaveStateBinding.h"

namespace KenshiLua
{

static GameData* getInstance(lua_State* L, int idx)
{
    return checkObject<GameData>(L, idx, GameDataBinding::getMetatableName());
}

// --- Getters for GameData ---
static int GameData_get_validity(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    lua_pushinteger(L, instance->validity);
    return 1;
}

static int GameData_get_sourceContainer(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    return pushObject<GameDataContainer>(L, instance->sourceContainer, GameDataContainerBinding::getMetatableName());
}

static int GameData_get_isStandalone(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    lua_pushboolean(L, instance->isStandalone ? 1 : 0);
    return 1;
}

static int GameData_get_id(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    lua_pushinteger(L, instance->id);
    return 1;
}

static int GameData_get_readOnly(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    lua_pushboolean(L, instance->readOnly ? 1 : 0);
    return 1;
}

static int GameData_get_name(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    lua_pushstring(L, instance->name.c_str());
    return 1;
}

static int GameData_get_type(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    lua_pushinteger(L, (lua_Integer)instance->type);
    return 1;
}

static int GameData_get_stringID(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    lua_pushstring(L, instance->stringID.c_str());
    return 1;
}

static int GameData_get_isFromActiveFile(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    lua_pushboolean(L, instance->isFromActiveFile ? 1 : 0);
    return 1;
}

static int GameData_get_currentID(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    lua_pushinteger(L, instance->currentID);
    return 1;
}

static int GameData_get_createdIndex(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    lua_pushinteger(L, instance->createdIndex);
    return 1;
}

// --- Setters for GameData ---
static int GameData_set_validity(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    instance->validity = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int GameData_set_sourceContainer(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    instance->sourceContainer = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    return 0;
}

static int GameData_set_isStandalone(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    instance->isStandalone = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameData_set_id(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    instance->id = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int GameData_set_readOnly(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    instance->readOnly = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameData_set_name(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    instance->name = luaL_checkstring(L, 2);
    return 0;
}

static int GameData_set_type(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    instance->type = (itemType)luaL_checkinteger(L, 2);
    return 0;
}

static int GameData_set_stringID(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    instance->stringID = luaL_checkstring(L, 2);
    return 0;
}

static int GameData_set_isFromActiveFile(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    instance->isFromActiveFile = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameData_set_currentID(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    instance->currentID = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int GameData_set_createdIndex(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    instance->createdIndex = (unsigned short)luaL_checkinteger(L, 2);
    return 0;
}

int GameDataBinding::_DESTRUCTOR(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int GameDataBinding::_CONSTRUCTOR(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    GameData* result = instance->_CONSTRUCTOR();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int GameDataBinding::isValid(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    bool result = instance->isValid();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::getSourceContainer(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    GameDataContainer* result = instance->getSourceContainer();
    return pushObject<GameDataContainer>(L, result, GameDataContainerBinding::getMetatableName());
}

int GameDataBinding::destroy(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    instance->destroy();
    return 0;
}

int GameDataBinding::initialise(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    itemType t = (itemType)luaL_checkinteger(L, 2);
    bool isActive = lua_toboolean(L, 3) != 0;
    instance->initialise(t, isActive);
    return 0;
}

int GameDataBinding::loadFromFile(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string path = luaL_checkstring(L, 2);
    itemType _type = (itemType)luaL_checkinteger(L, 3);
    bool result = instance->loadFromFile(path, _type);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::saveToFile(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string path = luaL_checkstring(L, 2);
    bool result = instance->saveToFile(path);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::updateFrom(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const GameData* from = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool mod = lua_toboolean(L, 3) != 0;
    bool result = instance->updateFrom(from, mod);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::isValueActive(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string v = luaL_checkstring(L, 2);
    bool result = instance->isValueActive(v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::isRefActive(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string v = luaL_checkstring(L, 2);
    bool result = instance->isRefActive(v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::addFileName(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string n = luaL_checkstring(L, 2);
    const std::string v = luaL_checkstring(L, 3);
    std::string filestype = luaL_checkstring(L, 4);
    std::string category = luaL_checkstring(L, 5);
    bool vis = lua_toboolean(L, 6) != 0;
    instance->addFileName(n, v, filestype, category, vis);
    return 0;
}

int GameDataBinding::addString(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string n = luaL_checkstring(L, 2);
    const std::string v = luaL_checkstring(L, 3);
    std::string category = luaL_checkstring(L, 4);
    bool vis = lua_toboolean(L, 5) != 0;
    instance->addString(n, v, category, vis);
    return 0;
}

int GameDataBinding::getGameDataReferenceObject(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string list = luaL_checkstring(L, 2);
    const std::string id = luaL_checkstring(L, 3);
    GameDataReference* result = instance->getGameDataReferenceObject(list, id);
    return pushObject<GameDataReference>(L, result, GameDataReferenceBinding::getMetatableName());
}

int GameDataBinding::addToList(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string list = luaL_checkstring(L, 2);
    const std::string id = luaL_checkstring(L, 3);
    int val = (int)luaL_checkinteger(L, 4);
    int val2 = (int)luaL_checkinteger(L, 5);
    int val3 = (int)luaL_checkinteger(L, 6);
    instance->addToList(list, id, val, val2, val3);
    return 0;
}

int GameDataBinding::findInList(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string list = luaL_checkstring(L, 2);
    const std::string SID = luaL_checkstring(L, 3);
    bool result = instance->findInList(list, SID);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::clearList(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string n = luaL_checkstring(L, 2);
    instance->clearList(n);
    return 0;
}

int GameDataBinding::clearEverything(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    instance->clearEverything();
    return 0;
}

int GameDataBinding::clearInstances(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    instance->clearInstances();
    return 0;
}

int GameDataBinding::getListSize(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string n = luaL_checkstring(L, 2);
    int result = instance->getListSize(n);
    lua_pushinteger(L, result);
    return 1;
}

int GameDataBinding::listExists(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string n = luaL_checkstring(L, 2);
    bool result = instance->listExists(n);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::listExistsAndNotEmpty(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string n = luaL_checkstring(L, 2);
    bool result = instance->listExistsAndNotEmpty(n);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::getReferenceList(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string listname = luaL_checkstring(L, 2);
    const Ogre::vector<GameDataReference>::type* result = instance->getReferenceList(listname);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int GameDataBinding::getReferenceListIfExists(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string listname = luaL_checkstring(L, 2);
    const Ogre::vector<GameDataReference>::type* result = instance->getReferenceListIfExists(listname);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int GameDataBinding::_getReferenceList_nonConst(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string listname = luaL_checkstring(L, 2);
    Ogre::vector<GameDataReference>::type* result = instance->_getReferenceList_nonConst(listname);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int GameDataBinding::getFromListAsData(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string n = luaL_checkstring(L, 2);
    int index = (int)luaL_checkinteger(L, 3);
    GameDataContainer* dataContainer = checkObject<GameDataContainer>(L, 4, GameDataContainerBinding::getMetatableName());
    itemType type = (itemType)luaL_checkinteger(L, 5);
    GameData* result = instance->getFromListAsData(n, index, dataContainer, type);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int GameDataBinding::deleteInstancedObject(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string id = luaL_checkstring(L, 2);
    int modIndex = (int)luaL_checkinteger(L, 3);
    instance->deleteInstancedObject(id, modIndex);
    return 0;
}

int GameDataBinding::getNewID(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    int result = instance->getNewID();
    lua_pushinteger(L, result);
    return 1;
}

int GameDataBinding::getColorVec(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string name = luaL_checkstring(L, 2);
    Ogre::Vector3 result = instance->getColorVec(name);
    pushVector3(L, result);
    return 1;
}

int GameDataBinding::addDeletedInstance(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string instanceID = luaL_checkstring(L, 2);
    instance->addDeletedInstance(instanceID);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 97: void storeHandleList(...) - overloaded method
  line 98: void storeHandleList(...) - overloaded method
  line 99: void getHandleList(...) - overloaded method
  line 100: void getHandleList(...) - overloaded method
  line 101: void storeHandle(...) - non-string reference arg
  line 102: bool getHandle(...) - non-string reference arg
  line 110: void add(...) - overloaded method
  line 111: void add(...) - overloaded method
  line 112: void add(...) - overloaded method
  line 113: void add(...) - overloaded method
  line 114: void add(...) - overloaded method
  line 117: void removeFromList(...) - overloaded method
  line 118: void removeFromList(...) - overloaded method
  line 124: const std::string& getFromList(...) - reference return type
  line 125: const std::string& getFromList_random(...) - reference return type
  line 129: void getAllFromList(...) - unsupported arg type
  line 133: void getAllFromListAsDatas(...) - unsupported arg type
  line 135: const TripleInt& getValueFromList(...) - reference return type
  line 156: void addSavedInstancedObject(...) - unsupported arg type
  line 159: void getInstances(...) - unsupported arg type
  line 173: Ogre::ColourValue getColor(...) - unsupported return type
  line 175: void setColor(...) - overloaded method
  line 176: void setColor(...) - overloaded method
  line 178: GameData::ObjectInstance* addANewInstancedObject(...) - overloaded method
  line 179: void addANewInstancedObject(...) - overloaded method
  line 180: void addANewInstancedObject(...) - overloaded method
  line 181: GameData::ObjectInstance* addANewInstancedObject(...) - overloaded method
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - GameDataBinding::getReferenceList: const Ogre::vector<GameDataReference>::type* (unbound pointer)
  - GameDataBinding::getReferenceListIfExists: const Ogre::vector<GameDataReference>::type* (unbound pointer)
  - GameDataBinding::_getReferenceList_nonConst: Ogre::vector<GameDataReference>::type* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 160: instances (std::map<std::string, GameData::ObjectInstance, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData::ObjectInstance>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 163: activeValues (boost::unordered::unordered_map<std::string, bool, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, bool>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 164: bdata (boost::unordered::unordered_map<std::string, bool, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, bool>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 165: sdata (boost::unordered::unordered_map<std::string, std::string, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, std::string >, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 166: idata (boost::unordered::unordered_map<std::string, int, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, int>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 167: fdata (boost::unordered::unordered_map<std::string, float, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, float>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 168: filesdata (boost::unordered::unordered_map<std::string, std::string, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, std::string >, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 169: vecdata (boost::unordered::unordered_map<std::string, Ogre::Vector3, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::Vector3>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 170: quatdata (boost::unordered::unordered_map<std::string, Ogre::Quaternion, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::Quaternion>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 171: objectReferences (boost::unordered::unordered_map<std::string, Ogre::vector<GameDataReference>::type, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::vector<GameDataReference>::type >, Ogre::GeneralAllocPolicy > >) - unsupported type
*/

int GameDataBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int GameDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.GameData object");
    return 1;
}

void GameDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GameDataBinding::gc },
        { "__tostring", GameDataBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", GameDataBinding::_DESTRUCTOR },
        { "_CONSTRUCTOR", GameDataBinding::_CONSTRUCTOR },
        { "isValid", GameDataBinding::isValid },
        { "getSourceContainer", GameDataBinding::getSourceContainer },
        { "destroy", GameDataBinding::destroy },
        { "initialise", GameDataBinding::initialise },
        { "loadFromFile", GameDataBinding::loadFromFile },
        { "saveToFile", GameDataBinding::saveToFile },
        { "updateFrom", GameDataBinding::updateFrom },
        { "isValueActive", GameDataBinding::isValueActive },
        { "isRefActive", GameDataBinding::isRefActive },
        { "addFileName", GameDataBinding::addFileName },
        { "addString", GameDataBinding::addString },
        { "getGameDataReferenceObject", GameDataBinding::getGameDataReferenceObject },
        { "addToList", GameDataBinding::addToList },
        { "findInList", GameDataBinding::findInList },
        { "clearList", GameDataBinding::clearList },
        { "clearEverything", GameDataBinding::clearEverything },
        { "clearInstances", GameDataBinding::clearInstances },
        { "getListSize", GameDataBinding::getListSize },
        { "listExists", GameDataBinding::listExists },
        { "listExistsAndNotEmpty", GameDataBinding::listExistsAndNotEmpty },
        { "getReferenceList", GameDataBinding::getReferenceList },
        { "getReferenceListIfExists", GameDataBinding::getReferenceListIfExists },
        { "_getReferenceList_nonConst", GameDataBinding::_getReferenceList_nonConst },
        { "getFromListAsData", GameDataBinding::getFromListAsData },
        { "deleteInstancedObject", GameDataBinding::deleteInstancedObject },
        { "getNewID", GameDataBinding::getNewID },
        { "getColorVec", GameDataBinding::getColorVec },
        { "addDeletedInstance", GameDataBinding::addDeletedInstance },
        { 0, 0 }
    };

    registerClass(
        L, 
        GameDataBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GameDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "validity", GameData_get_validity);
    registerGetter(L, "sourceContainer", GameData_get_sourceContainer);
    registerGetter(L, "isStandalone", GameData_get_isStandalone);
    registerGetter(L, "id", GameData_get_id);
    registerGetter(L, "readOnly", GameData_get_readOnly);
    registerGetter(L, "name", GameData_get_name);
    registerGetter(L, "type", GameData_get_type);
    registerGetter(L, "stringID", GameData_get_stringID);
    registerGetter(L, "isFromActiveFile", GameData_get_isFromActiveFile);
    registerGetter(L, "currentID", GameData_get_currentID);
    registerGetter(L, "createdIndex", GameData_get_createdIndex);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "validity", GameData_set_validity);
    registerSetter(L, "sourceContainer", GameData_set_sourceContainer);
    registerSetter(L, "isStandalone", GameData_set_isStandalone);
    registerSetter(L, "id", GameData_set_id);
    registerSetter(L, "readOnly", GameData_set_readOnly);
    registerSetter(L, "name", GameData_set_name);
    registerSetter(L, "type", GameData_set_type);
    registerSetter(L, "stringID", GameData_set_stringID);
    registerSetter(L, "isFromActiveFile", GameData_set_isFromActiveFile);
    registerSetter(L, "currentID", GameData_set_currentID);
    registerSetter(L, "createdIndex", GameData_set_createdIndex);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, GameDataBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua