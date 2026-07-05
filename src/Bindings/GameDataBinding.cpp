#include "pch.h"
#include "kenshi\GameData.h"
#include "GameDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Util/LektorBinding.h"

namespace KenshiLua
{

static GameData* getB(lua_State* L, int idx)
{
    return checkObject<GameData>(L, idx, GameDataBinding::getMetatableName());
}

// --- Getters for GameData ---
static int GameData_get_validity(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    lua_pushinteger(L, b->validity);
    return 1;
}

static int GameData_get_sourceContainer(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    // TODO: Unsupported type for sourceContainer (GameDataContainer*)
    return luaL_error(L, "Unsupported property 'sourceContainer' (type: GameDataContainer*)");
}

static int GameData_get_isStandalone(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    lua_pushboolean(L, b->isStandalone ? 1 : 0);
    return 1;
}

static int GameData_get_id(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    lua_pushinteger(L, b->id);
    return 1;
}

static int GameData_get_readOnly(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    lua_pushboolean(L, b->readOnly ? 1 : 0);
    return 1;
}

static int GameData_get_name(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    lua_pushstring(L, b->name.c_str());
    return 1;
}

static int GameData_get_type(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    lua_pushinteger(L, (lua_Integer)b->type);
    return 1;
}

static int GameData_get_stringID(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    lua_pushstring(L, b->stringID.c_str());
    return 1;
}

static int GameData_get_isFromActiveFile(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    lua_pushboolean(L, b->isFromActiveFile ? 1 : 0);
    return 1;
}

static int GameData_get_instances(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    // TODO: Unsupported type for instances (std::map<std::string, GameData::ObjectInstance, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData::ObjectInstance>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'instances' (type: std::map<std::string, GameData::ObjectInstance, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData::ObjectInstance>, Ogre::GeneralAllocPolicy > >)");
}

static int GameData_get_currentID(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    lua_pushinteger(L, b->currentID);
    return 1;
}

static int GameData_get_activeValues(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    // TODO: Unsupported type for activeValues (boost::unordered::unordered_map<std::string, bool, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, bool>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'activeValues' (type: boost::unordered::unordered_map<std::string, bool, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, bool>, Ogre::GeneralAllocPolicy > >)");
}

static int GameData_get_bdata(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    // TODO: Unsupported type for bdata (boost::unordered::unordered_map<std::string, bool, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, bool>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'bdata' (type: boost::unordered::unordered_map<std::string, bool, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, bool>, Ogre::GeneralAllocPolicy > >)");
}

static int GameData_get_sdata(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    // TODO: Unsupported type for sdata (boost::unordered::unordered_map<std::string, std::string, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, std::string >, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'sdata' (type: boost::unordered::unordered_map<std::string, std::string, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, std::string >, Ogre::GeneralAllocPolicy > >)");
}

static int GameData_get_idata(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    // TODO: Unsupported type for idata (boost::unordered::unordered_map<std::string, int, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, int>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'idata' (type: boost::unordered::unordered_map<std::string, int, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, int>, Ogre::GeneralAllocPolicy > >)");
}

static int GameData_get_fdata(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    // TODO: Unsupported type for fdata (boost::unordered::unordered_map<std::string, float, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, float>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'fdata' (type: boost::unordered::unordered_map<std::string, float, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, float>, Ogre::GeneralAllocPolicy > >)");
}

static int GameData_get_filesdata(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    // TODO: Unsupported type for filesdata (boost::unordered::unordered_map<std::string, std::string, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, std::string >, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'filesdata' (type: boost::unordered::unordered_map<std::string, std::string, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, std::string >, Ogre::GeneralAllocPolicy > >)");
}

static int GameData_get_vecdata(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    // TODO: Unsupported type for vecdata (boost::unordered::unordered_map<std::string, Ogre::Vector3, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::Vector3>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'vecdata' (type: boost::unordered::unordered_map<std::string, Ogre::Vector3, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::Vector3>, Ogre::GeneralAllocPolicy > >)");
}

static int GameData_get_quatdata(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    // TODO: Unsupported type for quatdata (boost::unordered::unordered_map<std::string, Ogre::Quaternion, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::Quaternion>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'quatdata' (type: boost::unordered::unordered_map<std::string, Ogre::Quaternion, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::Quaternion>, Ogre::GeneralAllocPolicy > >)");
}

static int GameData_get_objectReferences(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    // TODO: Unsupported type for objectReferences (boost::unordered::unordered_map<std::string, Ogre::vector<GameDataReference>::type, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::vector<GameDataReference>::type >, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'objectReferences' (type: boost::unordered::unordered_map<std::string, Ogre::vector<GameDataReference>::type, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::vector<GameDataReference>::type >, Ogre::GeneralAllocPolicy > >)");
}

static int GameData_get_createdIndex(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    lua_pushinteger(L, b->createdIndex);
    return 1;
}

// --- Setters for GameData ---
static int GameData_set_validity(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    b->validity = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int GameData_set_sourceContainer(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for sourceContainer");
}

static int GameData_set_isStandalone(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    b->isStandalone = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameData_set_id(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    b->id = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int GameData_set_readOnly(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    b->readOnly = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameData_set_name(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    b->name = luaL_checkstring(L, 2);
    return 0;
}

static int GameData_set_type(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    b->type = (itemType)luaL_checkinteger(L, 2);
    return 0;
}

static int GameData_set_stringID(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    b->stringID = luaL_checkstring(L, 2);
    return 0;
}

static int GameData_set_isFromActiveFile(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    b->isFromActiveFile = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameData_set_instances(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for instances");
}

static int GameData_set_currentID(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    b->currentID = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int GameData_set_activeValues(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for activeValues");
}

static int GameData_set_bdata(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for bdata");
}

static int GameData_set_sdata(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for sdata");
}

static int GameData_set_idata(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for idata");
}

static int GameData_set_fdata(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for fdata");
}

static int GameData_set_filesdata(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for filesdata");
}

static int GameData_set_vecdata(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for vecdata");
}

static int GameData_set_quatdata(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for quatdata");
}

static int GameData_set_objectReferences(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    return luaL_error(L, "Read-only or unsupported setter type for objectReferences");
}

static int GameData_set_createdIndex(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    b->createdIndex = (unsigned short)luaL_checkinteger(L, 2);
    return 0;
}

// --- Methods for GameData ---
int GameDataBinding::_DESTRUCTOR(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    b->_DESTRUCTOR();
    return 0;
}

int GameDataBinding::_CONSTRUCTOR(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    GameData* result = b->_CONSTRUCTOR();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int GameDataBinding::isValid(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    bool result = b->isValid();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::destroy(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    b->destroy();
    return 0;
}

int GameDataBinding::initialise(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    itemType t = (itemType)luaL_checkinteger(L, 2);
    bool isActive = lua_toboolean(L, 3) != 0;
    b->initialise(t, isActive);
    return 0;
}

int GameDataBinding::loadFromFile(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string path = luaL_checkstring(L, 2);
    itemType _type = (itemType)luaL_checkinteger(L, 3);
    bool result = b->loadFromFile(path, _type);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::saveToFile(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string path = luaL_checkstring(L, 2);
    bool result = b->saveToFile(path);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::isValueActive(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string v = luaL_checkstring(L, 2);
    bool result = b->isValueActive(v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::isRefActive(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string v = luaL_checkstring(L, 2);
    bool result = b->isRefActive(v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::addFileName(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string n = luaL_checkstring(L, 2);
    std::string v = luaL_checkstring(L, 3);
    std::string filestype = luaL_checkstring(L, 4);
    std::string category = luaL_checkstring(L, 5);
    bool vis = lua_toboolean(L, 6) != 0;
    b->addFileName(n, v, filestype, category, vis);
    return 0;
}

int GameDataBinding::addString(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string n = luaL_checkstring(L, 2);
    std::string v = luaL_checkstring(L, 3);
    std::string category = luaL_checkstring(L, 4);
    bool vis = lua_toboolean(L, 5) != 0;
    b->addString(n, v, category, vis);
    return 0;
}

int GameDataBinding::addToList(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string list = luaL_checkstring(L, 2);
    std::string id = luaL_checkstring(L, 3);
    int val = (int)luaL_checkinteger(L, 4);
    int val2 = (int)luaL_checkinteger(L, 5);
    int val3 = (int)luaL_checkinteger(L, 6);
    b->addToList(list, id, val, val2, val3);
    return 0;
}

int GameDataBinding::findInList(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string list = luaL_checkstring(L, 2);
    std::string SID = luaL_checkstring(L, 3);
    bool result = b->findInList(list, SID);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::clearList(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string n = luaL_checkstring(L, 2);
    b->clearList(n);
    return 0;
}

int GameDataBinding::clearEverything(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    b->clearEverything();
    return 0;
}

int GameDataBinding::clearInstances(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    b->clearInstances();
    return 0;
}

int GameDataBinding::getListSize(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string n = luaL_checkstring(L, 2);
    int result = b->getListSize(n);
    lua_pushinteger(L, result);
    return 1;
}

int GameDataBinding::listExists(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string n = luaL_checkstring(L, 2);
    bool result = b->listExists(n);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::listExistsAndNotEmpty(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string n = luaL_checkstring(L, 2);
    bool result = b->listExistsAndNotEmpty(n);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::deleteInstancedObject(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string id = luaL_checkstring(L, 2);
    int modIndex = (int)luaL_checkinteger(L, 3);
    b->deleteInstancedObject(id, modIndex);
    return 0;
}

int GameDataBinding::getNewID(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    int result = b->getNewID();
    lua_pushinteger(L, result);
    return 1;
}

int GameDataBinding::getColorVec(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string name = luaL_checkstring(L, 2);
    Ogre::Vector3 result = b->getColorVec(name);
    pushVector3(L, result);
    return 1;
}

int GameDataBinding::addDeletedInstance(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string instanceID = luaL_checkstring(L, 2);
    b->addDeletedInstance(instanceID);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 57: GameDataContainer* getSourceContainer(...) - unsupported return type
  line 97: void storeHandleList(...) - overloaded method
  line 98: void storeHandleList(...) - overloaded method
  line 99: void getHandleList(...) - overloaded method
  line 100: void getHandleList(...) - overloaded method
  line 101: void storeHandle(...) - unsupported arg type
  line 102: bool getHandle(...) - unsupported arg type
  line 103: bool updateFrom(...) - unsupported arg type
  line 110: void add(...) - overloaded method
  line 111: void add(...) - overloaded method
  line 112: void add(...) - overloaded method
  line 113: void add(...) - overloaded method
  line 114: void add(...) - overloaded method
  line 115: GameDataReference* getGameDataReferenceObject(...) - unsupported return type
  line 117: void removeFromList(...) - overloaded method
  line 118: void removeFromList(...) - overloaded method
  line 124: const std::string& getFromList(...) - reference return type
  line 125: const std::string& getFromList_random(...) - reference return type
  line 129: void getAllFromList(...) - unsupported arg type
  line 130: const Ogre::vector<GameDataReference>::type* getReferenceList(...) - unsupported return type
  line 131: const Ogre::vector<GameDataReference>::type* getReferenceListIfExists(...) - unsupported return type
  line 132: Ogre::vector<GameDataReference>::type* _getReferenceList_nonConst(...) - unsupported return type
  line 133: void getAllFromListAsDatas(...) - unsupported arg type
  line 134: GameData* getFromListAsData(...) - unsupported arg type
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
        { "destroy", GameDataBinding::destroy },
        { "initialise", GameDataBinding::initialise },
        { "loadFromFile", GameDataBinding::loadFromFile },
        { "saveToFile", GameDataBinding::saveToFile },
        { "isValueActive", GameDataBinding::isValueActive },
        { "isRefActive", GameDataBinding::isRefActive },
        { "addFileName", GameDataBinding::addFileName },
        { "addString", GameDataBinding::addString },
        { "addToList", GameDataBinding::addToList },
        { "findInList", GameDataBinding::findInList },
        { "clearList", GameDataBinding::clearList },
        { "clearEverything", GameDataBinding::clearEverything },
        { "clearInstances", GameDataBinding::clearInstances },
        { "getListSize", GameDataBinding::getListSize },
        { "listExists", GameDataBinding::listExists },
        { "listExistsAndNotEmpty", GameDataBinding::listExistsAndNotEmpty },
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
    lua_pushcfunction(L, GameData_get_validity);
    lua_setfield(L, -2, "validity");
    lua_pushcfunction(L, GameData_get_sourceContainer);
    lua_setfield(L, -2, "sourceContainer");
    lua_pushcfunction(L, GameData_get_isStandalone);
    lua_setfield(L, -2, "isStandalone");
    lua_pushcfunction(L, GameData_get_id);
    lua_setfield(L, -2, "id");
    lua_pushcfunction(L, GameData_get_readOnly);
    lua_setfield(L, -2, "readOnly");
    lua_pushcfunction(L, GameData_get_name);
    lua_setfield(L, -2, "name");
    lua_pushcfunction(L, GameData_get_type);
    lua_setfield(L, -2, "type");
    lua_pushcfunction(L, GameData_get_stringID);
    lua_setfield(L, -2, "stringID");
    lua_pushcfunction(L, GameData_get_isFromActiveFile);
    lua_setfield(L, -2, "isFromActiveFile");
    lua_pushcfunction(L, GameData_get_instances);
    lua_setfield(L, -2, "instances");
    lua_pushcfunction(L, GameData_get_currentID);
    lua_setfield(L, -2, "currentID");
    lua_pushcfunction(L, GameData_get_activeValues);
    lua_setfield(L, -2, "activeValues");
    lua_pushcfunction(L, GameData_get_bdata);
    lua_setfield(L, -2, "bdata");
    lua_pushcfunction(L, GameData_get_sdata);
    lua_setfield(L, -2, "sdata");
    lua_pushcfunction(L, GameData_get_idata);
    lua_setfield(L, -2, "idata");
    lua_pushcfunction(L, GameData_get_fdata);
    lua_setfield(L, -2, "fdata");
    lua_pushcfunction(L, GameData_get_filesdata);
    lua_setfield(L, -2, "filesdata");
    lua_pushcfunction(L, GameData_get_vecdata);
    lua_setfield(L, -2, "vecdata");
    lua_pushcfunction(L, GameData_get_quatdata);
    lua_setfield(L, -2, "quatdata");
    lua_pushcfunction(L, GameData_get_objectReferences);
    lua_setfield(L, -2, "objectReferences");
    lua_pushcfunction(L, GameData_get_createdIndex);
    lua_setfield(L, -2, "createdIndex");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, GameData_set_validity);
    lua_setfield(L, -2, "validity");
    lua_pushcfunction(L, GameData_set_sourceContainer);
    lua_setfield(L, -2, "sourceContainer");
    lua_pushcfunction(L, GameData_set_isStandalone);
    lua_setfield(L, -2, "isStandalone");
    lua_pushcfunction(L, GameData_set_id);
    lua_setfield(L, -2, "id");
    lua_pushcfunction(L, GameData_set_readOnly);
    lua_setfield(L, -2, "readOnly");
    lua_pushcfunction(L, GameData_set_name);
    lua_setfield(L, -2, "name");
    lua_pushcfunction(L, GameData_set_type);
    lua_setfield(L, -2, "type");
    lua_pushcfunction(L, GameData_set_stringID);
    lua_setfield(L, -2, "stringID");
    lua_pushcfunction(L, GameData_set_isFromActiveFile);
    lua_setfield(L, -2, "isFromActiveFile");
    lua_pushcfunction(L, GameData_set_instances);
    lua_setfield(L, -2, "instances");
    lua_pushcfunction(L, GameData_set_currentID);
    lua_setfield(L, -2, "currentID");
    lua_pushcfunction(L, GameData_set_activeValues);
    lua_setfield(L, -2, "activeValues");
    lua_pushcfunction(L, GameData_set_bdata);
    lua_setfield(L, -2, "bdata");
    lua_pushcfunction(L, GameData_set_sdata);
    lua_setfield(L, -2, "sdata");
    lua_pushcfunction(L, GameData_set_idata);
    lua_setfield(L, -2, "idata");
    lua_pushcfunction(L, GameData_set_fdata);
    lua_setfield(L, -2, "fdata");
    lua_pushcfunction(L, GameData_set_filesdata);
    lua_setfield(L, -2, "filesdata");
    lua_pushcfunction(L, GameData_set_vecdata);
    lua_setfield(L, -2, "vecdata");
    lua_pushcfunction(L, GameData_set_quatdata);
    lua_setfield(L, -2, "quatdata");
    lua_pushcfunction(L, GameData_set_objectReferences);
    lua_setfield(L, -2, "objectReferences");
    lua_pushcfunction(L, GameData_set_createdIndex);
    lua_setfield(L, -2, "createdIndex");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    LektorPtrBinding<GameData*>::registerBinding(L, "lektor<GameData*>", GameDataBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua