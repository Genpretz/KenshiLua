#include "pch.h"
#include "kenshi\gamedatamanager.h"
#include "GameDataContainerBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{

static GameDataContainer* getInstance(lua_State* L, int idx)
{
    return checkObject<GameDataContainer>(L, idx, GameDataContainerBinding::getMetatableName());
}

// --- Getters for GameDataContainer ---
static int GameDataContainer_get_currentID(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");
    lua_pushinteger(L, instance->currentID);
    return 1;
}

static int GameDataContainer_get_name(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");
    lua_pushstring(L, instance->name.c_str());
    return 1;
}

static int GameDataContainer_get_isBaseDatafile(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");
    lua_pushboolean(L, instance->isBaseDatafile ? 1 : 0);
    return 1;
}

static int GameDataContainer_get_readOnly(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");
    lua_pushboolean(L, instance->readOnly ? 1 : 0);
    return 1;
}

// --- Setters for GameDataContainer ---
static int GameDataContainer_set_currentID(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");
    instance->currentID = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int GameDataContainer_set_name(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");
    instance->name = luaL_checkstring(L, 2);
    return 0;
}

static int GameDataContainer_set_isBaseDatafile(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");
    instance->isBaseDatafile = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameDataContainer_set_readOnly(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");
    instance->readOnly = lua_toboolean(L, 2) != 0;
    return 0;
}

int GameDataContainerBinding::_CONSTRUCTOR(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    GameDataContainer* result = instance->_CONSTRUCTOR();
    return pushObject<GameDataContainer>(L, result, GameDataContainerBinding::getMetatableName());
}

int GameDataContainerBinding::_DESTRUCTOR(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int GameDataContainerBinding::createNewData(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    itemType type = (itemType)luaL_checkinteger(L, 2);
    const std::string forceID = luaL_checkstring(L, 3);
    const std::string name = luaL_checkstring(L, 4);
    GameData* result = instance->createNewData(type, forceID, name);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int GameDataContainerBinding::getDataByName(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    const std::string dataName = luaL_checkstring(L, 2);
    itemType category = (itemType)luaL_checkinteger(L, 3);
    GameData* result = instance->getDataByName(dataName, category);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int GameDataContainerBinding::renameData(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    const std::string n = luaL_checkstring(L, 3);
    instance->renameData(data, n);
    return 0;
}

int GameDataContainerBinding::removeData(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    GameData* dat = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->removeData(dat);
    return 0;
}

int GameDataContainerBinding::removeDuplicatesOf(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    GameData* dat = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->removeDuplicatesOf(dat);
    return 0;
}

int GameDataContainerBinding::removeAllDataOfType(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    itemType type = (itemType)luaL_checkinteger(L, 2);
    instance->removeAllDataOfType(type);
    return 0;
}

int GameDataContainerBinding::clearInstances(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    instance->clearInstances();
    return 0;
}

int GameDataContainerBinding::clearButDontDestroy(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    instance->clearButDontDestroy();
    return 0;
}

int GameDataContainerBinding::clearButDontDestroyPlatoons(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    instance->clearButDontDestroyPlatoons();
    return 0;
}

int GameDataContainerBinding::clearAndDestroy(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    instance->clearAndDestroy();
    return 0;
}

int GameDataContainerBinding::getNewID(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    int result = instance->getNewID();
    lua_pushinteger(L, result);
    return 1;
}

int GameDataContainerBinding::destroyData(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    GameData* dat = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->destroyData(dat);
    return 0;
}

int GameDataContainerBinding::preLoadAllReferencePtrs(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    instance->preLoadAllReferencePtrs();
    return 0;
}

int GameDataContainerBinding::clearAllReferencePtrs(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    instance->clearAllReferencePtrs();
    return 0;
}

int GameDataContainerBinding::setName(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    const std::string name = luaL_checkstring(L, 2);
    instance->setName(name);
    return 0;
}

int GameDataContainerBinding::checkForDuplicates(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    GameData* dat = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->checkForDuplicates(dat);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 19: void addNewData(...) - overloaded method
  line 20: void addNewData(...) - overloaded method
  line 27: GameData* getData(...) - overloaded method
  line 28: GameData* getData(...) - overloaded method
  line 29: GameData* getData(...) - overloaded method
  line 31: void getDataOfType(...) - unsupported arg type
  line 32: const ogre_unordered_map<int, GameData*>::type& _getAllData(...) - reference return type
  line 38: bool loadGameDataReturn(...) - unsupported arg type
  line 39: bool load(...) - unsupported arg type
  line 40: bool save(...) - unsupported arg type
  line 46: void flushKillList(...) - static method
  line 47: void destroyHomelessData(...) - static method
  line 52: void findAllDataThatReferencesThis(...) - unsupported arg type
  line 56: void _addToKillList(...) - static method
*/

/*
Skipped properties needing manual binding:
  line 57: gamedataCatName (boost::unordered::unordered_map<int, boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::GeneralAllocPolicy > >, boost::hash<int>, std::equal_to<int>, Ogre::STLAllocator<std::pair<int const, boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::GeneralAllocPolicy > > >, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 58: gamedataID (ogre_unordered_map<int, GameData*>::type) - unsupported type
  line 59: gamedataCatSID (boost::unordered::unordered_map<int, boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::GeneralAllocPolicy > >, boost::hash<int>, std::equal_to<int>, Ogre::STLAllocator<std::pair<int const, boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::GeneralAllocPolicy > > >, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 60: gamedataSID (boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 61: mainList (ogre_unordered_set<GameData*>::type) - unsupported type
*/

int GameDataContainerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int GameDataContainerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.GameDataContainer object");
    return 1;
}

void GameDataContainerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GameDataContainerBinding::gc },
        { "__tostring", GameDataContainerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", GameDataContainerBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", GameDataContainerBinding::_DESTRUCTOR },
        { "createNewData", GameDataContainerBinding::createNewData },
        { "getDataByName", GameDataContainerBinding::getDataByName },
        { "renameData", GameDataContainerBinding::renameData },
        { "removeData", GameDataContainerBinding::removeData },
        { "removeDuplicatesOf", GameDataContainerBinding::removeDuplicatesOf },
        { "removeAllDataOfType", GameDataContainerBinding::removeAllDataOfType },
        { "clearInstances", GameDataContainerBinding::clearInstances },
        { "clearButDontDestroy", GameDataContainerBinding::clearButDontDestroy },
        { "clearButDontDestroyPlatoons", GameDataContainerBinding::clearButDontDestroyPlatoons },
        { "clearAndDestroy", GameDataContainerBinding::clearAndDestroy },
        { "getNewID", GameDataContainerBinding::getNewID },
        { "destroyData", GameDataContainerBinding::destroyData },
        { "preLoadAllReferencePtrs", GameDataContainerBinding::preLoadAllReferencePtrs },
        { "clearAllReferencePtrs", GameDataContainerBinding::clearAllReferencePtrs },
        { "setName", GameDataContainerBinding::setName },
        { "checkForDuplicates", GameDataContainerBinding::checkForDuplicates },
        { 0, 0 }
    };

    registerClass(
        L, 
        GameDataContainerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GameDataContainerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "currentID", GameDataContainer_get_currentID);
    registerGetter(L, "name", GameDataContainer_get_name);
    registerGetter(L, "isBaseDatafile", GameDataContainer_get_isBaseDatafile);
    registerGetter(L, "readOnly", GameDataContainer_get_readOnly);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "currentID", GameDataContainer_set_currentID);
    registerSetter(L, "name", GameDataContainer_set_name);
    registerSetter(L, "isBaseDatafile", GameDataContainer_set_isBaseDatafile);
    registerSetter(L, "readOnly", GameDataContainer_set_readOnly);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, GameDataContainerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua