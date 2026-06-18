#include "pch.h"
#include "Bindings/GameDataBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/GameData.h>

#include <cstring>
#include <cstdio>

/*  class ItemData
    if (strcmp(key, "visible") == 0) { lua_pushboolean(L, s->visible ? 1 : 0); return 1; }
    if (strcmp(key, "category") == 0) { lua_pushstring(L, s->category.c_str()); return 1; }
    if (strcmp(key, "description") == 0) { lua_pushstring(L, s->description.c_str()); return 1; }
    if (strcmp(key, "fileTypes") == 0) { lua_pushstring(L, s->fileTypes.c_str()); return 1; }
    // TODO itemType objectType; unsupported __index type from header line 79
    if (strcmp(key, "maxSize") == 0) { lua_pushinteger(L, s->maxSize); return 1; }
    if (strcmp(key, "maxValue") == 0) { lua_pushinteger(L, s->maxValue); return 1; }
    if (strcmp(key, "minValue") == 0) { lua_pushinteger(L, s->minValue); return 1; }
    if (strcmp(key, "isSlider") == 0) { lua_pushboolean(L, s->isSlider ? 1 : 0); return 1; }

    if (strcmp(key, "visible") == 0) { s->visible = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "category") == 0) { s->category = luaL_checkstring(L, 3); return 0; }
    if (strcmp(key, "description") == 0) { s->description = luaL_checkstring(L, 3); return 0; }
    if (strcmp(key, "fileTypes") == 0) { s->fileTypes = luaL_checkstring(L, 3); return 0; }
    // TODO itemType objectType; unsupported __newindex type from header line 79
    if (strcmp(key, "maxSize") == 0) { s->maxSize = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "maxValue") == 0) { s->maxValue = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "minValue") == 0) { s->minValue = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "isSlider") == 0) { s->isSlider = lua_toboolean(L, 3) != 0; return 0; }
*/

/*  class ObjectInstance
    // TODO Ogre::Vector3 pos; unsupported __index type from header line 143
    // TODO Ogre::Quaternion rot; unsupported __index type from header line 144
    if (strcmp(key, "refID") == 0) { lua_pushstring(L, s->refID.c_str()); return 1; }
    if (strcmp(key, "created") == 0) { lua_pushinteger(L, s->created); return 1; }
    if (strcmp(key, "modified") == 0) { lua_pushinteger(L, s->modified); return 1; }
    // TODO lektor<std::string > stateIDs; unsupported __index type from header line 148

    // TODO Ogre::Vector3 pos; unsupported __newindex type from header line 143
    // TODO Ogre::Quaternion rot; unsupported __newindex type from header line 144
    if (strcmp(key, "refID") == 0) { s->refID = luaL_checkstring(L, 3); return 0; }
    if (strcmp(key, "created") == 0) { s->created = (short)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "modified") == 0) { s->modified = (short)luaL_checkinteger(L, 3); return 0; }
    // TODO lektor<std::string > stateIDs; unsupported __newindex type from header line 148
*/


namespace KenshiLua
{

static GameData* getS(lua_State* L, int idx)
{
    return checkObject<GameData>(L, idx, GameDataBinding::getMetatableName());
}

int GameDataBinding::gc(lua_State* L) { return noopGc(L); }

int GameDataBinding::tostring(lua_State* L)
{
    GameData* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int GameDataBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, GameDataBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    GameData* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "validity") == 0) { lua_pushinteger(L, s->validity); return 1; }
    // TODO GameDataContainer* sourceContainer; unsupported __index type from header line 49
    if (strcmp(key, "isStandalone") == 0) { lua_pushboolean(L, s->isStandalone ? 1 : 0); return 1; }
    if (strcmp(key, "id") == 0) { lua_pushinteger(L, s->id); return 1; }
    if (strcmp(key, "readOnly") == 0) { lua_pushboolean(L, s->readOnly ? 1 : 0); return 1; }
    if (strcmp(key, "name") == 0) { lua_pushstring(L, s->name.c_str()); return 1; }
    // TODO itemType type; unsupported __index type from header line 91
    if (strcmp(key, "stringID") == 0) { lua_pushstring(L, s->stringID.c_str()); return 1; }
    if (strcmp(key, "isFromActiveFile") == 0) { lua_pushboolean(L, s->isFromActiveFile ? 1 : 0); return 1; }

    // TODO std::map<std::string, GameData::ObjectInstance, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData::ObjectInstance>, Ogre::GeneralAllocPolicy > > instances; unsupported __index type from header line 160
    if (strcmp(key, "currentID") == 0) { lua_pushinteger(L, s->currentID); return 1; }
    // TODO boost::unordered::unordered_map<std::string, bool, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, bool>, Ogre::GeneralAllocPolicy > > activeValues; unsupported __index type from header line 163
    // TODO boost::unordered::unordered_map<std::string, bool, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, bool>, Ogre::GeneralAllocPolicy > > bdata; unsupported __index type from header line 164
    // TODO boost::unordered::unordered_map<std::string, std::string, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, std::string >, Ogre::GeneralAllocPolicy > > sdata; unsupported __index type from header line 165
    // TODO boost::unordered::unordered_map<std::string, int, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, int>, Ogre::GeneralAllocPolicy > > idata; unsupported __index type from header line 166
    // TODO boost::unordered::unordered_map<std::string, float, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, float>, Ogre::GeneralAllocPolicy > > fdata; unsupported __index type from header line 167
    // TODO boost::unordered::unordered_map<std::string, std::string, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, std::string >, Ogre::GeneralAllocPolicy > > filesdata; unsupported __index type from header line 168
    // TODO boost::unordered::unordered_map<std::string, Ogre::Vector3, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::Vector3>, Ogre::GeneralAllocPolicy > > vecdata; unsupported __index type from header line 169
    // TODO boost::unordered::unordered_map<std::string, Ogre::Quaternion, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::Quaternion>, Ogre::GeneralAllocPolicy > > quatdata; unsupported __index type from header line 170
    // TODO boost::unordered::unordered_map<std::string, Ogre::vector<GameDataReference>::type, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::vector<GameDataReference>::type >, Ogre::GeneralAllocPolicy > > objectReferences; unsupported __index type from header line 171
    if (strcmp(key, "createdIndex") == 0) { lua_pushinteger(L, s->createdIndex); return 1; }

    lua_pushnil(L);
    return 1;
}

int GameDataBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    GameData* s = getS(L, 1);
    if (!s) return luaL_error(L, "GameData is nil");

    if (strcmp(key, "validity") == 0) { s->validity = (int)luaL_checkinteger(L, 3); return 0; }
    // TODO GameDataContainer* sourceContainer; unsupported __newindex type from header line 49
    if (strcmp(key, "isStandalone") == 0) { s->isStandalone = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "id") == 0) { s->id = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "readOnly") == 0) { s->readOnly = lua_toboolean(L, 3) != 0; return 0; }
    if (strcmp(key, "name") == 0) { s->name = luaL_checkstring(L, 3); return 0; }
    // TODO itemType type; unsupported __newindex type from header line 91
    if (strcmp(key, "stringID") == 0) { s->stringID = luaL_checkstring(L, 3); return 0; }
    if (strcmp(key, "isFromActiveFile") == 0) { s->isFromActiveFile = lua_toboolean(L, 3) != 0; return 0; }
    // TODO std::map<std::string, GameData::ObjectInstance, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData::ObjectInstance>, Ogre::GeneralAllocPolicy > > instances; unsupported __newindex type from header line 160
    if (strcmp(key, "currentID") == 0) { s->currentID = (int)luaL_checkinteger(L, 3); return 0; }
    // TODO boost::unordered::unordered_map<std::string, bool, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, bool>, Ogre::GeneralAllocPolicy > > activeValues; unsupported __newindex type from header line 163
    // TODO boost::unordered::unordered_map<std::string, bool, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, bool>, Ogre::GeneralAllocPolicy > > bdata; unsupported __newindex type from header line 164
    // TODO boost::unordered::unordered_map<std::string, std::string, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, std::string >, Ogre::GeneralAllocPolicy > > sdata; unsupported __newindex type from header line 165
    // TODO boost::unordered::unordered_map<std::string, int, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, int>, Ogre::GeneralAllocPolicy > > idata; unsupported __newindex type from header line 166
    // TODO boost::unordered::unordered_map<std::string, float, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, float>, Ogre::GeneralAllocPolicy > > fdata; unsupported __newindex type from header line 167
    // TODO boost::unordered::unordered_map<std::string, std::string, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, std::string >, Ogre::GeneralAllocPolicy > > filesdata; unsupported __newindex type from header line 168
    // TODO boost::unordered::unordered_map<std::string, Ogre::Vector3, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::Vector3>, Ogre::GeneralAllocPolicy > > vecdata; unsupported __newindex type from header line 169
    // TODO boost::unordered::unordered_map<std::string, Ogre::Quaternion, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::Quaternion>, Ogre::GeneralAllocPolicy > > quatdata; unsupported __newindex type from header line 170
    // TODO boost::unordered::unordered_map<std::string, Ogre::vector<GameDataReference>::type, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::vector<GameDataReference>::type >, Ogre::GeneralAllocPolicy > > objectReferences; unsupported __newindex type from header line 171
    if (strcmp(key, "createdIndex") == 0) { s->createdIndex = (unsigned short)luaL_checkinteger(L, 3); return 0; }

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int GameDataBinding::isValid(lua_State* L)
{
    GameData* s = getS(L, 1);
    if (!s) return luaL_error(L, "GameData is nil");

    bool result = s->isValid();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::destroy(lua_State* L)
{
    GameData* s = getS(L, 1);
    if (!s) return luaL_error(L, "GameData is nil");

    s->destroy();
    return 0;
}

int GameDataBinding::saveToFile(lua_State* L)
{
    GameData* s = getS(L, 1);
    if (!s) return luaL_error(L, "GameData is nil");

    std::string path = luaL_checkstring(L, 2);
    bool result = s->saveToFile(path);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::isValueActive(lua_State* L)
{
    GameData* s = getS(L, 1);
    if (!s) return luaL_error(L, "GameData is nil");

    std::string v = luaL_checkstring(L, 2);
    bool result = s->isValueActive(v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::isRefActive(lua_State* L)
{
    GameData* s = getS(L, 1);
    if (!s) return luaL_error(L, "GameData is nil");

    std::string v = luaL_checkstring(L, 2);
    bool result = s->isRefActive(v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::addFileName(lua_State* L)
{
    GameData* s = getS(L, 1);
    if (!s) return luaL_error(L, "GameData is nil");

    std::string n = luaL_checkstring(L, 2);
    std::string v = luaL_checkstring(L, 3);
    std::string filestype = luaL_checkstring(L, 4);
    std::string category = luaL_checkstring(L, 5);
    bool vis = lua_toboolean(L, 6) != 0;
    s->addFileName(n, v, filestype, category, vis);
    return 0;
}

int GameDataBinding::addString(lua_State* L)
{
    GameData* s = getS(L, 1);
    if (!s) return luaL_error(L, "GameData is nil");

    std::string n = luaL_checkstring(L, 2);
    std::string v = luaL_checkstring(L, 3);
    std::string category = luaL_checkstring(L, 4);
    bool vis = lua_toboolean(L, 5) != 0;
    s->addString(n, v, category, vis);
    return 0;
}

int GameDataBinding::addToList(lua_State* L)
{
    GameData* s = getS(L, 1);
    if (!s) return luaL_error(L, "GameData is nil");

    std::string list = luaL_checkstring(L, 2);
    std::string id = luaL_checkstring(L, 3);
    int val = (int)luaL_checkinteger(L, 4);
    int val2 = (int)luaL_checkinteger(L, 5);
    int val3 = (int)luaL_checkinteger(L, 6);
    s->addToList(list, id, val, val2, val3);
    return 0;
}

int GameDataBinding::findInList(lua_State* L)
{
    GameData* s = getS(L, 1);
    if (!s) return luaL_error(L, "GameData is nil");

    std::string list = luaL_checkstring(L, 2);
    std::string SID = luaL_checkstring(L, 3);
    bool result = s->findInList(list, SID);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::clearList(lua_State* L)
{
    GameData* s = getS(L, 1);
    if (!s) return luaL_error(L, "GameData is nil");

    std::string n = luaL_checkstring(L, 2);
    s->clearList(n);
    return 0;
}

int GameDataBinding::clearEverything(lua_State* L)
{
    GameData* s = getS(L, 1);
    if (!s) return luaL_error(L, "GameData is nil");

    s->clearEverything();
    return 0;
}

int GameDataBinding::clearInstances(lua_State* L)
{
    GameData* s = getS(L, 1);
    if (!s) return luaL_error(L, "GameData is nil");

    s->clearInstances();
    return 0;
}

int GameDataBinding::getListSize(lua_State* L)
{
    GameData* s = getS(L, 1);
    if (!s) return luaL_error(L, "GameData is nil");

    std::string n = luaL_checkstring(L, 2);
    int result = s->getListSize(n);
    lua_pushinteger(L, result);
    return 1;
}

int GameDataBinding::listExists(lua_State* L)
{
    GameData* s = getS(L, 1);
    if (!s) return luaL_error(L, "GameData is nil");

    std::string n = luaL_checkstring(L, 2);
    bool result = s->listExists(n);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::listExistsAndNotEmpty(lua_State* L)
{
    GameData* s = getS(L, 1);
    if (!s) return luaL_error(L, "GameData is nil");

    std::string n = luaL_checkstring(L, 2);
    bool result = s->listExistsAndNotEmpty(n);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::deleteInstancedObject(lua_State* L)
{
    GameData* s = getS(L, 1);
    if (!s) return luaL_error(L, "GameData is nil");

    std::string id = luaL_checkstring(L, 2);
    int modIndex = (int)luaL_checkinteger(L, 3);
    s->deleteInstancedObject(id, modIndex);
    return 0;
}

int GameDataBinding::getNewID(lua_State* L)
{
    GameData* s = getS(L, 1);
    if (!s) return luaL_error(L, "GameData is nil");

    int result = s->getNewID();
    lua_pushinteger(L, result);
    return 1;
}

int GameDataBinding::addDeletedInstance(lua_State* L)
{
    GameData* s = getS(L, 1);
    if (!s) return luaL_error(L, "GameData is nil");

    std::string instanceID = luaL_checkstring(L, 2);
    s->addDeletedInstance(instanceID);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 51: void _DESTRUCTOR(...) - overloaded method
  line 54: GameData* _CONSTRUCTOR(...) - overloaded method
  line 57: GameDataContainer* getSourceContainer(...) - unsupported return type
  line 94: void initialise(...) - unsupported arg type
  line 95: bool loadFromFile(...) - unsupported arg type
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
  line 134: GameData* getFromListAsData(...) - unsupported return type
  line 135: const TripleInt& getValueFromList(...) - reference return type
  line 140: ObjectInstance* _CONSTRUCTOR(...) - overloaded method
  line 142: ObjectInstance* _CONSTRUCTOR(...) - overloaded method
  line 149: const GameData::ObjectInstance& operator=(...) - operator
  line 150: void updateInstancedObjectAttachedDatas(...) - unsupported arg type
  line 152: void _DESTRUCTOR(...) - overloaded method
  line 156: void addSavedInstancedObject(...) - unsupported arg type
  line 159: void getInstances(...) - unsupported arg type
  line 173: Ogre::ColourValue getColor(...) - unsupported return type
  line 174: Ogre::Vector3 getColorVec(...) - unsupported return type
  line 175: void setColor(...) - overloaded method
  line 176: void setColor(...) - overloaded method
  line 178: GameData::ObjectInstance* addANewInstancedObject(...) - overloaded method
  line 179: void addANewInstancedObject(...) - overloaded method
  line 180: void addANewInstancedObject(...) - overloaded method
  line 181: GameData::ObjectInstance* addANewInstancedObject(...) - overloaded method
*/

void GameDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GameDataBinding::gc },
        { "__tostring", GameDataBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "isValid", GameDataBinding::isValid },
        { "destroy", GameDataBinding::destroy },
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
        { "addDeletedInstance", GameDataBinding::addDeletedInstance },
        { 0, 0 }
    };
    registerClass(L, GameDataBinding::getMetatableName(),
        meta, methods,
        GameDataBinding::index,
        GameDataBinding::newindex);
}

} // namespace KenshiLua