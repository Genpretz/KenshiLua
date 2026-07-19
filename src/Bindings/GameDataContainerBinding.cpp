#include "pch.h"
#include "kenshi\GameDataManager.h"
#include "GameDataContainerBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{

static GameDataContainer* getB(lua_State* L, int idx)
{
    return checkObject<GameDataContainer>(L, idx, GameDataContainerBinding::getMetatableName());
}

// --- Getters for GameDataContainer ---
static int GameDataContainer_get_currentID(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");
    lua_pushinteger(L, b->currentID);
    return 1;
}

static int GameDataContainer_get_gamedataCatName(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");
    // TODO: Unsupported type for gamedataCatName (boost::unordered::unordered_map<int, boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::GeneralAllocPolicy > >, boost::hash<int>, std::equal_to<int>, Ogre::STLAllocator<std::pair<int const, boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::GeneralAllocPolicy > > >, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'gamedataCatName' (type: boost::unordered::unordered_map<int, boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::GeneralAllocPolicy > >, boost::hash<int>, std::equal_to<int>, Ogre::STLAllocator<std::pair<int const, boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::GeneralAllocPolicy > > >, Ogre::GeneralAllocPolicy > >)");
}

static int GameDataContainer_get_gamedataID(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");
    // TODO: Unsupported type for gamedataID (ogre_unordered_map<int, GameData*>::type)
    return luaL_error(L, "Unsupported property 'gamedataID' (type: ogre_unordered_map<int, GameData*>::type)");
}

static int GameDataContainer_get_gamedataCatSID(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");
    // TODO: Unsupported type for gamedataCatSID (boost::unordered::unordered_map<int, boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::GeneralAllocPolicy > >, boost::hash<int>, std::equal_to<int>, Ogre::STLAllocator<std::pair<int const, boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::GeneralAllocPolicy > > >, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'gamedataCatSID' (type: boost::unordered::unordered_map<int, boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::GeneralAllocPolicy > >, boost::hash<int>, std::equal_to<int>, Ogre::STLAllocator<std::pair<int const, boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::GeneralAllocPolicy > > >, Ogre::GeneralAllocPolicy > >)");
}

static int GameDataContainer_get_gamedataSID(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");
    // TODO: Unsupported type for gamedataSID (boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'gamedataSID' (type: boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::GeneralAllocPolicy > >)");
}

static int GameDataContainer_get_mainList(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");
    // TODO: Unsupported type for mainList (ogre_unordered_set<GameData*>::type)
    return luaL_error(L, "Unsupported property 'mainList' (type: ogre_unordered_set<GameData*>::type)");
}

static int GameDataContainer_get_name(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");
    lua_pushstring(L, b->name.c_str());
    return 1;
}

static int GameDataContainer_get_isBaseDatafile(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");
    lua_pushboolean(L, b->isBaseDatafile ? 1 : 0);
    return 1;
}

static int GameDataContainer_get_readOnly(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");
    lua_pushboolean(L, b->readOnly ? 1 : 0);
    return 1;
}

// --- Setters for GameDataContainer ---
static int GameDataContainer_set_currentID(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");
    b->currentID = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int GameDataContainer_set_gamedataCatName(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");
    return luaL_error(L, "Read-only or unsupported setter type for gamedataCatName");
}

static int GameDataContainer_set_gamedataID(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");
    return luaL_error(L, "Read-only or unsupported setter type for gamedataID");
}

static int GameDataContainer_set_gamedataCatSID(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");
    return luaL_error(L, "Read-only or unsupported setter type for gamedataCatSID");
}

static int GameDataContainer_set_gamedataSID(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");
    return luaL_error(L, "Read-only or unsupported setter type for gamedataSID");
}

static int GameDataContainer_set_mainList(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");
    return luaL_error(L, "Read-only or unsupported setter type for mainList");
}

static int GameDataContainer_set_name(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");
    b->name = luaL_checkstring(L, 2);
    return 0;
}

static int GameDataContainer_set_isBaseDatafile(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");
    b->isBaseDatafile = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameDataContainer_set_readOnly(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");
    b->readOnly = lua_toboolean(L, 2) != 0;
    return 0;
}

int GameDataContainerBinding::_DESTRUCTOR(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");

    b->_DESTRUCTOR();
    return 0;
}

int GameDataContainerBinding::createNewData(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");

    itemType type = (itemType)luaL_checkinteger(L, 2);
    std::string forceID = luaL_checkstring(L, 3);
    std::string name = luaL_checkstring(L, 4);
    GameData* result = b->createNewData(type, forceID, name);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int GameDataContainerBinding::getDataByName(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");

    std::string dataName = luaL_checkstring(L, 2);
    itemType category = (itemType)luaL_checkinteger(L, 3);
    GameData* result = b->getDataByName(dataName, category);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int GameDataContainerBinding::removeAllDataOfType(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");

    itemType type = (itemType)luaL_checkinteger(L, 2);
    b->removeAllDataOfType(type);
    return 0;
}

int GameDataContainerBinding::clearInstances(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");

    b->clearInstances();
    return 0;
}

int GameDataContainerBinding::clearButDontDestroy(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");

    b->clearButDontDestroy();
    return 0;
}

int GameDataContainerBinding::clearButDontDestroyPlatoons(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");

    b->clearButDontDestroyPlatoons();
    return 0;
}

int GameDataContainerBinding::clearAndDestroy(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");

    b->clearAndDestroy();
    return 0;
}

int GameDataContainerBinding::getNewID(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");

    int result = b->getNewID();
    lua_pushinteger(L, result);
    return 1;
}

int GameDataContainerBinding::preLoadAllReferencePtrs(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");

    b->preLoadAllReferencePtrs();
    return 0;
}

int GameDataContainerBinding::clearAllReferencePtrs(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");

    b->clearAllReferencePtrs();
    return 0;
}

int GameDataContainerBinding::setName(lua_State* L)
{
    GameDataContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameDataContainer is nil");

    std::string name = luaL_checkstring(L, 2);
    b->setName(name);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 19: void addNewData(...) - overloaded method
  line 20: void addNewData(...) - overloaded method
  line 23: GameDataContainer* _CONSTRUCTOR(...) - unsupported return type
  line 27: GameData* getData(...) - overloaded method
  line 28: GameData* getData(...) - overloaded method
  line 29: GameData* getData(...) - overloaded method
  line 31: void getDataOfType(...) - unsupported arg type
  line 32: const ogre_unordered_map<int, GameData*>::type& _getAllData(...) - reference return type
  line 34: void renameData(...) - unsupported arg type
  line 35: void removeData(...) - unsupported arg type
  line 36: void removeDuplicatesOf(...) - unsupported arg type
  line 38: bool loadGameDataReturn(...) - unsupported arg type
  line 39: bool load(...) - unsupported arg type
  line 40: bool save(...) - unsupported arg type
  line 46: void flushKillList(...) - static method
  line 47: void destroyHomelessData(...) - static method
  line 48: void destroyData(...) - unsupported arg type
  line 52: void findAllDataThatReferencesThis(...) - unsupported arg type
  line 54: void checkForDuplicates(...) - unsupported arg type
  line 56: void _addToKillList(...) - static method
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
        { "_DESTRUCTOR", GameDataContainerBinding::_DESTRUCTOR },
        { "createNewData", GameDataContainerBinding::createNewData },
        { "getDataByName", GameDataContainerBinding::getDataByName },
        { "removeAllDataOfType", GameDataContainerBinding::removeAllDataOfType },
        { "clearInstances", GameDataContainerBinding::clearInstances },
        { "clearButDontDestroy", GameDataContainerBinding::clearButDontDestroy },
        { "clearButDontDestroyPlatoons", GameDataContainerBinding::clearButDontDestroyPlatoons },
        { "clearAndDestroy", GameDataContainerBinding::clearAndDestroy },
        { "getNewID", GameDataContainerBinding::getNewID },
        { "preLoadAllReferencePtrs", GameDataContainerBinding::preLoadAllReferencePtrs },
        { "clearAllReferencePtrs", GameDataContainerBinding::clearAllReferencePtrs },
        { "setName", GameDataContainerBinding::setName },
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
    lua_pushcfunction(L, GameDataContainer_get_currentID);
    lua_setfield(L, -2, "currentID");
    lua_pushcfunction(L, GameDataContainer_get_gamedataCatName);
    lua_setfield(L, -2, "gamedataCatName");
    lua_pushcfunction(L, GameDataContainer_get_gamedataID);
    lua_setfield(L, -2, "gamedataID");
    lua_pushcfunction(L, GameDataContainer_get_gamedataCatSID);
    lua_setfield(L, -2, "gamedataCatSID");
    lua_pushcfunction(L, GameDataContainer_get_gamedataSID);
    lua_setfield(L, -2, "gamedataSID");
    lua_pushcfunction(L, GameDataContainer_get_mainList);
    lua_setfield(L, -2, "mainList");
    lua_pushcfunction(L, GameDataContainer_get_name);
    lua_setfield(L, -2, "name");
    lua_pushcfunction(L, GameDataContainer_get_isBaseDatafile);
    lua_setfield(L, -2, "isBaseDatafile");
    lua_pushcfunction(L, GameDataContainer_get_readOnly);
    lua_setfield(L, -2, "readOnly");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, GameDataContainer_set_currentID);
    lua_setfield(L, -2, "currentID");
    lua_pushcfunction(L, GameDataContainer_set_gamedataCatName);
    lua_setfield(L, -2, "gamedataCatName");
    lua_pushcfunction(L, GameDataContainer_set_gamedataID);
    lua_setfield(L, -2, "gamedataID");
    lua_pushcfunction(L, GameDataContainer_set_gamedataCatSID);
    lua_setfield(L, -2, "gamedataCatSID");
    lua_pushcfunction(L, GameDataContainer_set_gamedataSID);
    lua_setfield(L, -2, "gamedataSID");
    lua_pushcfunction(L, GameDataContainer_set_mainList);
    lua_setfield(L, -2, "mainList");
    lua_pushcfunction(L, GameDataContainer_set_name);
    lua_setfield(L, -2, "name");
    lua_pushcfunction(L, GameDataContainer_set_isBaseDatafile);
    lua_setfield(L, -2, "isBaseDatafile");
    lua_pushcfunction(L, GameDataContainer_set_readOnly);
    lua_setfield(L, -2, "readOnly");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
