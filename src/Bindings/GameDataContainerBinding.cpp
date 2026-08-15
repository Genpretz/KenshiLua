#include "pch.h"
#include "kenshi\gamedatamanager.h"
#include "GameDataContainerBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"
#include "Bindings/Util/BoostUnorderedBinding.h"

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

typedef boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string>, std::equal_to<std::string>, Ogre::STLAllocator<std::pair<const std::string, GameData*>, Ogre::GeneralAllocPolicy> > GameDataSIDMap;

static int GameDataContainer_get_gamedataID(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");
    return pushObject<ogre_unordered_map<int, GameData*>::type>(L, &instance->gamedataID, "ogre_unordered_map<int, GameData*>");
}

static int GameDataContainer_get_gamedataSID(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");
    return pushObject<GameDataSIDMap>(L, &instance->gamedataSID, "boost_unordered_map<std::string, GameData*>");
}

static int GameDataContainer_get_mainList(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");
    return pushObject<ogre_unordered_set<GameData*>::type>(L, &instance->mainList, "ogre_unordered_set<GameData*>");
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

static int GameDataContainer_set_gamedataID(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");
    auto* val = checkObject<ogre_unordered_map<int, GameData*>::type>(L, 2, "ogre_unordered_map<int, GameData*>");
    if (val) instance->gamedataID = *val;
    return 0;
}

static int GameDataContainer_set_gamedataSID(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");
    auto* val = checkObject<GameDataSIDMap>(L, 2, "boost_unordered_map<std::string, GameData*>");
    if (val) instance->gamedataSID = *val;
    return 0;
}

static int GameDataContainer_set_mainList(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");
    auto* val = checkObject<ogre_unordered_set<GameData*>::type>(L, 2, "ogre_unordered_set<GameData*>");
    if (val) instance->mainList = *val;
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

int GameDataContainerBinding::addNewData(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    if (GameData* dat = testObject<GameData>(L, 2, GameDataBinding::getMetatableName()))
    {
        std::string forceID = lua_isstring(L, 3) ? lua_tostring(L, 3) : "";
        instance->addNewData(dat, forceID);
        return 0;
    }
    else if (lektor<GameData*>* list = LektorPtrBinding<GameData*>::get(L, 2))
    {
        instance->addNewData(*list);
        return 0;
    }
    return luaL_error(L, "Argument 2 to addNewData must be GameData or lektor<GameData*>");
}

int GameDataContainerBinding::getData(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    if (lua_isnumber(L, 2))
    {
        int id = (int)lua_tointeger(L, 2);
        GameData* res = instance->getData(id);
        return pushObject<GameData>(L, res, GameDataBinding::getMetatableName());
    }
    else if (lua_isstring(L, 2))
    {
        std::string sid = lua_tostring(L, 2);
        if (lua_isnumber(L, 3))
        {
            itemType category = (itemType)lua_tointeger(L, 3);
            GameData* res = instance->getData(sid, category);
            return pushObject<GameData>(L, res, GameDataBinding::getMetatableName());
        }
        GameData* res = instance->getData(sid);
        return pushObject<GameData>(L, res, GameDataBinding::getMetatableName());
    }
    return luaL_error(L, "Argument 2 to getData must be string SID or integer ID");
}

int GameDataContainerBinding::getDataOfType(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    lektor<GameData*>* list = LektorPtrBinding<GameData*>::get(L, 2);
    if (!list) return luaL_error(L, "Argument 2 to getDataOfType must be lektor<GameData*>");

    itemType type = (itemType)luaL_checkinteger(L, 3);
    instance->getDataOfType(*list, type);
    return 0;
}

int GameDataContainerBinding::_getAllData(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    const ogre_unordered_map<int, GameData*>::type& data = instance->_getAllData();
    return pushObject<ogre_unordered_map<int, GameData*>::type>(L, (ogre_unordered_map<int, GameData*>::type*)&data, "ogre_unordered_map<int, GameData*>");
}

int GameDataContainerBinding::loadGameDataReturn(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    std::string file = luaL_checkstring(L, 2);
    bool isActive = lua_toboolean(L, 3) != 0;
    bool readOnly = lua_toboolean(L, 4) != 0;
    Serialisable* moreData = lua_isuserdata(L, 5) ? (Serialisable*)lua_touserdata(L, 5) : nullptr;
    bool res = instance->loadGameDataReturn(file, isActive, readOnly, moreData);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int GameDataContainerBinding::load(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    std::string filename = luaL_checkstring(L, 2);
    std::string modName = luaL_checkstring(L, 3);
    int modIndex = (int)luaL_checkinteger(L, 4);
    Serialisable* moreData = lua_isuserdata(L, 5) ? (Serialisable*)lua_touserdata(L, 5) : nullptr;
    bool keepDeletedInstances = lua_isboolean(L, 6) ? (lua_toboolean(L, 6) != 0) : false;
    bool res = instance->load(filename, modName, modIndex, moreData, keepDeletedInstances);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int GameDataContainerBinding::save(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    std::string filename = luaL_checkstring(L, 2);
    Serialisable* moreData = lua_isuserdata(L, 3) ? (Serialisable*)lua_touserdata(L, 3) : nullptr;
    bool res = instance->save(filename, moreData);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int GameDataContainerBinding::flushKillList(lua_State* L)
{
    GameDataContainer::flushKillList();
    return 0;
}

int GameDataContainerBinding::destroyHomelessData(lua_State* L)
{
    GameData* dat = checkObject<GameData>(L, 1, GameDataBinding::getMetatableName());
    GameDataContainer::destroyHomelessData(dat);
    return 0;
}

int GameDataContainerBinding::findAllDataThatReferencesThis(lua_State* L)
{
    GameDataContainer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataContainer is nil");

    lektor<GameData*>* out = LektorPtrBinding<GameData*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to findAllDataThatReferencesThis must be lektor<GameData*>");

    GameData* what = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    itemType ofType = (itemType)luaL_checkinteger(L, 4);
    std::string listname = luaL_checkstring(L, 5);
    instance->findAllDataThatReferencesThis(*out, what, ofType, listname);
    return 0;
}

int GameDataContainerBinding::_addToKillList(lua_State* L)
{
    GameData* d = checkObject<GameData>(L, 1, GameDataBinding::getMetatableName());
    GameDataContainer::_addToKillList(d);
    return 0;
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - GameDataContainerBinding::loadGameDataReturn: Serialisable* parameter (unbound pointer)
  - GameDataContainerBinding::load: Serialisable* parameter (unbound pointer)
  - GameDataContainerBinding::save: Serialisable* parameter (unbound pointer)

SKIPPED PROPERTIES / CONTAINERS NEEDING MANUAL BINDING OR UNBOUND TYPES:
  - gamedataCatName (nested map boost::unordered_map<int, boost::unordered_map<std::string, GameData*>>) - unsupported nested container
  - gamedataCatSID (nested map boost::unordered_map<int, boost::unordered_map<std::string, GameData*>>) - unsupported nested container
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
        { "addNewData", GameDataContainerBinding::addNewData },
        { "getData", GameDataContainerBinding::getData },
        { "getDataOfType", GameDataContainerBinding::getDataOfType },
        { "_getAllData", GameDataContainerBinding::_getAllData },
        { "loadGameDataReturn", GameDataContainerBinding::loadGameDataReturn },
        { "load", GameDataContainerBinding::load },
        { "save", GameDataContainerBinding::save },
        { "flushKillList", GameDataContainerBinding::flushKillList },
        { "destroyHomelessData", GameDataContainerBinding::destroyHomelessData },
        { "findAllDataThatReferencesThis", GameDataContainerBinding::findAllDataThatReferencesThis },
        { "_addToKillList", GameDataContainerBinding::_addToKillList },
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
    registerGetter(L, "gamedataID", GameDataContainer_get_gamedataID);
    registerGetter(L, "gamedataSID", GameDataContainer_get_gamedataSID);
    registerGetter(L, "mainList", GameDataContainer_get_mainList);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "currentID", GameDataContainer_set_currentID);
    registerSetter(L, "name", GameDataContainer_set_name);
    registerSetter(L, "isBaseDatafile", GameDataContainer_set_isBaseDatafile);
    registerSetter(L, "readOnly", GameDataContainer_set_readOnly);
    registerSetter(L, "gamedataID", GameDataContainer_set_gamedataID);
    registerSetter(L, "gamedataSID", GameDataContainer_set_gamedataSID);
    registerSetter(L, "mainList", GameDataContainer_set_mainList);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    OgreUnorderedMapBinding<int, GameData*>::registerBinding(L, "ogre_unordered_map<int, GameData*>", nullptr, GameDataBinding::getMetatableName());
    BoostUnorderedMapBinding<std::string, GameData*, boost::hash<std::string>, std::equal_to<std::string>, Ogre::STLAllocator<std::pair<const std::string, GameData*>, Ogre::GeneralAllocPolicy>>::registerBinding(L, "boost_unordered_map<std::string, GameData*>", nullptr, GameDataBinding::getMetatableName());
    OgreUnorderedSetBinding<GameData*>::registerBinding(L, "ogre_unordered_set<GameData*>", GameDataBinding::getMetatableName());
    LektorPtrBinding<GameData*>::registerBinding(L, "lektor<GameData*>", GameDataBinding::getMetatableName());

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, GameDataContainerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua