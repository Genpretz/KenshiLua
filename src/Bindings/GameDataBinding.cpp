#include "pch.h"
#include "kenshi/GameData.h"
#include "GameDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/Util/OgreVectorBinding.h"
#include "Bindings/Util/StdMapBinding.h"
#include "Bindings/Util/BoostUnorderedBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/GameDataReferenceBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/ObjectInstanceBinding.h"
#include "kenshi/GameSaveState.h"
#include "kenshi/util/TripleInt.h"
#include <ogre/OgreColourValue.h>

namespace KenshiLua
{

template <>
struct LuaCodec<GameData::ObjectInstance>
{
    static void push(lua_State* L, const GameData::ObjectInstance& val, const char* meta)
    {
        pushObject<GameData::ObjectInstance>(L, const_cast<GameData::ObjectInstance*>(&val), "KenshiLua.ObjectInstance");
    }

    static GameData::ObjectInstance read(lua_State* L, int idx, const char* meta)
    {
        GameData::ObjectInstance* p = checkObject<GameData::ObjectInstance>(L, idx, "KenshiLua.ObjectInstance");
        return p ? *p : GameData::ObjectInstance();
    }
};

template <>
struct LuaCodec<Ogre::vector<GameDataReference>::type>
{
    static void push(lua_State* L, const Ogre::vector<GameDataReference>::type& val, const char* meta)
    {
        pushObject<Ogre::vector<GameDataReference>::type>(L, const_cast<Ogre::vector<GameDataReference>::type*>(&val), "Ogre::vector<GameDataReference>");
    }

    static Ogre::vector<GameDataReference>::type read(lua_State* L, int idx, const char* meta)
    {
        Ogre::vector<GameDataReference>::type* p = checkObject<Ogre::vector<GameDataReference>::type>(L, idx, "Ogre::vector<GameDataReference>");
        return p ? *p : Ogre::vector<GameDataReference>::type();
    }
};

typedef StdMapBinding<
    std::string, 
    GameData::ObjectInstance, 
    std::less<std::string>, 
    Ogre::STLAllocator<std::pair<std::string const, GameData::ObjectInstance>, Ogre::GeneralAllocPolicy>
> InstancesMapBinding;

typedef BoostUnorderedMapBinding<
    std::string, 
    bool, 
    boost::hash<std::string>, 
    std::equal_to<std::string>, 
    Ogre::STLAllocator<std::pair<std::string const, bool>, Ogre::GeneralAllocPolicy>
> ActiveValuesMapBinding;

typedef BoostUnorderedMapBinding<
    std::string, 
    std::string, 
    boost::hash<std::string>, 
    std::equal_to<std::string>, 
    Ogre::STLAllocator<std::pair<std::string const, std::string>, Ogre::GeneralAllocPolicy>
> StringMapBinding;

typedef BoostUnorderedMapBinding<
    std::string, 
    int, 
    boost::hash<std::string>, 
    std::equal_to<std::string>, 
    Ogre::STLAllocator<std::pair<std::string const, int>, Ogre::GeneralAllocPolicy>
> IntMapBinding;

typedef BoostUnorderedMapBinding<
    std::string, 
    float, 
    boost::hash<std::string>, 
    std::equal_to<std::string>, 
    Ogre::STLAllocator<std::pair<std::string const, float>, Ogre::GeneralAllocPolicy>
> FloatMapBinding;

typedef BoostUnorderedMapBinding<
    std::string, 
    Ogre::Vector3, 
    boost::hash<std::string>, 
    std::equal_to<std::string>, 
    Ogre::STLAllocator<std::pair<std::string const, Ogre::Vector3>, Ogre::GeneralAllocPolicy>
> Vector3MapBinding;

typedef BoostUnorderedMapBinding<
    std::string, 
    Ogre::Quaternion, 
    boost::hash<std::string>, 
    std::equal_to<std::string>, 
    Ogre::STLAllocator<std::pair<std::string const, Ogre::Quaternion>, Ogre::GeneralAllocPolicy>
> QuaternionMapBinding;

typedef BoostUnorderedMapBinding<
    std::string, 
    Ogre::vector<GameDataReference>::type, 
    boost::hash<std::string>, 
    std::equal_to<std::string>, 
    Ogre::STLAllocator<std::pair<std::string const, Ogre::vector<GameDataReference>::type>, Ogre::GeneralAllocPolicy>
> ObjectReferencesMapBinding;

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
    return pushObject<GameDataContainer>(L, b->sourceContainer, "KenshiLua.GameDataContainer");
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
    return pushObject<InstancesMapBinding::MapType>(L, &b->instances, "std::map<string, ObjectInstance>");
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
    return pushObject<ActiveValuesMapBinding::MapType>(L, &b->activeValues, "boost::unordered_map<string, bool>");
}

static int GameData_get_bdata(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    return pushObject<ActiveValuesMapBinding::MapType>(L, &b->bdata, "boost::unordered_map<string, bool>");
}

static int GameData_get_sdata(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    return pushObject<StringMapBinding::MapType>(L, &b->sdata, "boost::unordered_map<string, string>");
}

static int GameData_get_idata(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    return pushObject<IntMapBinding::MapType>(L, &b->idata, "boost::unordered_map<string, int>");
}

static int GameData_get_fdata(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    return pushObject<FloatMapBinding::MapType>(L, &b->fdata, "boost::unordered_map<string, float>");
}

static int GameData_get_filesdata(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    return pushObject<StringMapBinding::MapType>(L, &b->filesdata, "boost::unordered_map<string, string>");
}

static int GameData_get_vecdata(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    return pushObject<Vector3MapBinding::MapType>(L, &b->vecdata, "boost::unordered_map<string, Vector3>");
}

static int GameData_get_quatdata(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    return pushObject<QuaternionMapBinding::MapType>(L, &b->quatdata, "boost::unordered_map<string, Quaternion>");
}

static int GameData_get_objectReferences(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    return pushObject<ObjectReferencesMapBinding::MapType>(L, &b->objectReferences, "boost::unordered_map<string, OgreVector_GameDataReference>");
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
    GameDataContainer* val = (lua_isnil(L, 2) || lua_isnone(L, 2)) ? nullptr : checkObject<GameDataContainer>(L, 2, "KenshiLua.GameDataContainer");
    b->sourceContainer = val;
    return 0;
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

int GameDataBinding::getSourceContainer(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");
    GameDataContainer* result = b->getSourceContainer();
    return pushObject<GameDataContainer>(L, result, "KenshiLua.GameDataContainer");
}

int GameDataBinding::storeHandleList(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string name = luaL_checkstring(L, 3);

    if (lektor<hand>* lek = testObject<lektor<hand>>(L, 2, "lektor<hand>"))
    {
        b->storeHandleList(*lek, name);
    }
    else if (ogre_unordered_set<hand>::type* set = testObject<ogre_unordered_set<hand>::type>(L, 2, "KenshiLua.SelectedCharactersSet"))
    {
        typedef void (*StoreHandleListOgre_t)(GameData* thisPtr, const ogre_unordered_set<hand>::type& handle, const std::string& _name);
        static StoreHandleListOgre_t fn = (StoreHandleListOgre_t)((char*)GetModuleHandleA(NULL) + 0x6BC4A0);
        fn(b, *set, name);
    }
    else
    {
        return luaL_error(L, "Argument 2 to storeHandleList must be lektor<hand> or SelectedCharactersSet");
    }
    return 0;
}

int GameDataBinding::getHandleList(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string name = luaL_checkstring(L, 3);

    if (lektor<hand>* lek = testObject<lektor<hand>>(L, 2, "lektor<hand>"))
    {
        b->getHandleList(*lek, name);
    }
    else if (ogre_unordered_set<hand>::type* set = testObject<ogre_unordered_set<hand>::type>(L, 2, "KenshiLua.SelectedCharactersSet"))
    {
        typedef void (*GetHandleListOgre_t)(GameData* thisPtr, ogre_unordered_set<hand>::type& out, const std::string& _name);
        static GetHandleListOgre_t fn = (GetHandleListOgre_t)((char*)GetModuleHandleA(NULL) + 0x6BC950);
        fn(b, *set, name);
    }
    else
    {
        return luaL_error(L, "Argument 2 to getHandleList must be lektor<hand> or SelectedCharactersSet");
    }
    return 0;
}

int GameDataBinding::storeHandle(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    hand* h = checkObject<hand>(L, 2, "KenshiLua.hand");
    if (!h) return luaL_error(L, "Argument 2 to storeHandle must be a valid hand");
    std::string name = luaL_checkstring(L, 3);
    bool redirect = lua_toboolean(L, 4) != 0;

    b->storeHandle(*h, name, redirect);
    return 0;
}

int GameDataBinding::getHandle(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    hand* h = checkObject<hand>(L, 2, "KenshiLua.hand");
    if (!h) return luaL_error(L, "Argument 2 to getHandle must be a valid hand");
    std::string name = luaL_checkstring(L, 3);

    bool result = b->getHandle(*h, name);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::updateFrom(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    GameData* from = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool mod = lua_toboolean(L, 3) != 0;

    bool result = b->updateFrom(from, mod);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataBinding::add(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string n = luaL_checkstring(L, 2);

    if (lua_istable(L, 3))
    {
        Ogre::Vector3 v;
        readVector3(L, 3, v);
        b->add(n, v);
    }
    else if (lua_isboolean(L, 3))
    {
        bool v = lua_toboolean(L, 3) != 0;
        std::string category = luaL_checkstring(L, 4);
        bool vis = lua_toboolean(L, 5) != 0;
        b->add(n, v, category, vis);
    }
    else if (lua_isnumber(L, 3))
    {
        std::string category = luaL_checkstring(L, 4);
        bool vis = lua_toboolean(L, 5) != 0;

        if (lua_gettop(L) >= 6)
        {
            float v = (float)luaL_checknumber(L, 3);
            bool isSlider = lua_toboolean(L, 6) != 0;
            b->add(n, v, category, vis, isSlider);
        }
        else
        {
            lua_Number num = luaL_checknumber(L, 3);
            if (num < 0)
            {
                int v = (int)num;
                b->add(n, v, category, vis);
            }
            else
            {
                unsigned int v = (unsigned int)num;
                b->add(n, v, category, vis);
            }
        }
    }
    else
    {
        return luaL_error(L, "Invalid value type for add");
    }
    return 0;
}

int GameDataBinding::getGameDataReferenceObject(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string list = luaL_checkstring(L, 2);
    std::string id = luaL_checkstring(L, 3);

    GameDataReference* result = b->getGameDataReferenceObject(list, id);
    return pushObject<GameDataReference>(L, result, "KenshiLua.GameDataReference");
}

int GameDataBinding::removeFromList(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string list = luaL_checkstring(L, 2);
    if (lua_isnumber(L, 3))
    {
        int id = (int)luaL_checkinteger(L, 3);
        b->removeFromList(list, id);
    }
    else
    {
        std::string id = luaL_checkstring(L, 3);
        b->removeFromList(list, id);
    }
    return 0;
}

int GameDataBinding::getFromList(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string n = luaL_checkstring(L, 2);
    int index = (int)luaL_checkinteger(L, 3);

    const std::string& result = b->getFromList(n, index);
    lua_pushstring(L, result.c_str());
    return 1;
}

int GameDataBinding::getFromList_random(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string n = luaL_checkstring(L, 2);

    const std::string& result = b->getFromList_random(n);
    lua_pushstring(L, result.c_str());
    return 1;
}

int GameDataBinding::getAllFromList(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string n = luaL_checkstring(L, 2);
    lektor<std::string>* list = LektorStringBinding<std::string>::get(L, 3);
    if (!list) return luaL_error(L, "Argument 3 to getAllFromList must be a valid lektor<string>");

    b->getAllFromList(n, *list);
    return 0;
}

int GameDataBinding::getReferenceList(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string listname = luaL_checkstring(L, 2);
    const Ogre::vector<GameDataReference>::type* result = b->getReferenceList(listname);
    return pushObject<Ogre::vector<GameDataReference>::type>(L, const_cast<Ogre::vector<GameDataReference>::type*>(result), "Ogre::vector<GameDataReference>");
}

int GameDataBinding::getReferenceListIfExists(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string listname = luaL_checkstring(L, 2);
    const Ogre::vector<GameDataReference>::type* result = b->getReferenceListIfExists(listname);
    return pushObject<Ogre::vector<GameDataReference>::type>(L, const_cast<Ogre::vector<GameDataReference>::type*>(result), "Ogre::vector<GameDataReference>");
}

int GameDataBinding::_getReferenceList_nonConst(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string listname = luaL_checkstring(L, 2);
    Ogre::vector<GameDataReference>::type* result = b->_getReferenceList_nonConst(listname);
    return pushObject<Ogre::vector<GameDataReference>::type>(L, result, "Ogre::vector<GameDataReference>");
}

int GameDataBinding::getAllFromListAsDatas(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string n = luaL_checkstring(L, 2);
    lektor<GameData*>* list = LektorPtrBinding<GameData*>::get(L, 3);
    if (!list) return luaL_error(L, "Argument 3 to getAllFromListAsDatas must be a valid lektor<GameData*>");
    GameDataContainer* dataContainer = checkObject<GameDataContainer>(L, 4, "KenshiLua.GameDataContainer");
    itemType type = (itemType)luaL_checkinteger(L, 5);

    b->getAllFromListAsDatas(n, *list, dataContainer, type);
    return 0;
}

int GameDataBinding::getFromListAsData(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string n = luaL_checkstring(L, 2);
    int index = (int)luaL_checkinteger(L, 3);
    GameDataContainer* dataContainer = checkObject<GameDataContainer>(L, 4, "KenshiLua.GameDataContainer");
    itemType type = (itemType)luaL_checkinteger(L, 5);

    GameData* result = b->getFromListAsData(n, index, dataContainer, type);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int GameDataBinding::getValueFromList(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string n = luaL_checkstring(L, 2);
    int index = (int)luaL_checkinteger(L, 3);

    const TripleInt& result = b->getValueFromList(n, index);
    pushTripleInt(L, result);
    return 1;
}

int GameDataBinding::addSavedInstancedObject(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string id = luaL_checkstring(L, 2);
    std::string refID = luaL_checkstring(L, 3);
    int modIndex = (int)luaL_checkinteger(L, 4);
    Ogre::Vector3 pos;
    readVector3(L, 5, pos);
    Ogre::Quaternion rot;
    readQuaternion(L, 6, rot);
    lektor<std::string>* states = LektorStringBinding<std::string>::get(L, 7);
    if (!states) return luaL_error(L, "Argument 7 to addSavedInstancedObject must be a valid lektor<string>");

    b->addSavedInstancedObject(id, refID, modIndex, pos, rot, *states);
    return 0;
}

int GameDataBinding::getInstances(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    lektor<GameData::ObjectInstance*>* out = LektorPtrBinding<GameData::ObjectInstance*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to getInstances must be a valid lektor<GameData::ObjectInstance*>");

    b->getInstances(*out);
    return 0;
}

int GameDataBinding::getColor(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string name = luaL_checkstring(L, 2);
    Ogre::ColourValue result = b->getColor(name);
    pushColourValue(L, result);
    return 1;
}

int GameDataBinding::setColor(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    std::string name = luaL_checkstring(L, 2);
    if (!lua_istable(L, 3)) return luaL_error(L, "Argument 3 to setColor must be a table (Vector3 or ColourValue)");

    lua_getfield(L, 3, "r");
    bool hasR = !lua_isnil(L, -1);
    lua_pop(L, 1);

    if (hasR)
    {
        Ogre::ColourValue c;
        readColourValue(L, 3, c);
        b->setColor(name, c);
    }
    else
    {
        Ogre::Vector3 c;
        readVector3(L, 3, c);
        b->setColor(name, c);
    }
    return 0;
}

int GameDataBinding::addANewInstancedObject(lua_State* L)
{
    GameData* b = getB(L, 1);
    if (!b) return luaL_error(L, "GameData is nil");

    if (GameData::ObjectInstance* inst = testObject<GameData::ObjectInstance>(L, 2, "KenshiLua.ObjectInstance"))
    {
        GameData::ObjectInstance* result = b->addANewInstancedObject(inst);
        return pushObject<GameData::ObjectInstance>(L, result, "KenshiLua.ObjectInstance");
    }

    if (GameData* refObj = testObject<GameData>(L, 2, GameDataBinding::getMetatableName()))
    {
        if (lua_gettop(L) >= 3 && !lua_isnil(L, 3))
        {
            PosRotPair* posRot = (PosRotPair*)lua_touserdata(L, 3);
            if (!posRot) return luaL_error(L, "Argument 3 to addANewInstancedObject must be a valid PosRotPair pointer");
            b->addANewInstancedObject(refObj, *posRot);
            return 0;
        }
        else
        {
            b->addANewInstancedObject(refObj);
            return 0;
        }
    }

    if (GameSaveState* saveState = testObject<GameSaveState>(L, 2, "KenshiLua.GameSaveState"))
    {
        PosRotPair* pos = (PosRotPair*)lua_touserdata(L, 3);
        if (!pos) return luaL_error(L, "Argument 3 to addANewInstancedObject must be a valid PosRotPair pointer");
        PosRotPair* offset = (lua_isnil(L, 4) || lua_isnone(L, 4)) ? nullptr : (PosRotPair*)lua_touserdata(L, 4);

        GameData::ObjectInstance* result = b->addANewInstancedObject(*saveState, *pos, offset);
        return pushObject<GameData::ObjectInstance>(L, result, "KenshiLua.ObjectInstance");
    }

    return luaL_error(L, "Invalid arguments to addANewInstancedObject");
}

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

        { "getSourceContainer", GameDataBinding::getSourceContainer },
        { "storeHandleList", GameDataBinding::storeHandleList },
        { "getHandleList", GameDataBinding::getHandleList },
        { "storeHandle", GameDataBinding::storeHandle },
        { "getHandle", GameDataBinding::getHandle },
        { "updateFrom", GameDataBinding::updateFrom },
        { "add", GameDataBinding::add },
        { "getGameDataReferenceObject", GameDataBinding::getGameDataReferenceObject },
        { "removeFromList", GameDataBinding::removeFromList },
        { "getFromList", GameDataBinding::getFromList },
        { "getFromList_random", GameDataBinding::getFromList_random },
        { "getAllFromList", GameDataBinding::getAllFromList },
        { "getReferenceList", GameDataBinding::getReferenceList },
        { "getReferenceListIfExists", GameDataBinding::getReferenceListIfExists },
        { "_getReferenceList_nonConst", GameDataBinding::_getReferenceList_nonConst },
        { "getAllFromListAsDatas", GameDataBinding::getAllFromListAsDatas },
        { "getFromListAsData", GameDataBinding::getFromListAsData },
        { "getValueFromList", GameDataBinding::getValueFromList },
        { "addSavedInstancedObject", GameDataBinding::addSavedInstancedObject },
        { "getInstances", GameDataBinding::getInstances },
        { "getColor", GameDataBinding::getColor },
        { "setColor", GameDataBinding::setColor },
        { "addANewInstancedObject", GameDataBinding::addANewInstancedObject },
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

    // Register all container bindings
    InstancesMapBinding::registerBinding(L, "std::map<string, ObjectInstance>", nullptr, "KenshiLua.ObjectInstance");
    ActiveValuesMapBinding::registerBinding(L, "boost::unordered_map<string, bool>");
    StringMapBinding::registerBinding(L, "boost::unordered_map<string, string>");
    IntMapBinding::registerBinding(L, "boost::unordered_map<string, int>");
    FloatMapBinding::registerBinding(L, "boost::unordered_map<string, float>");
    Vector3MapBinding::registerBinding(L, "boost::unordered_map<string, Vector3>");
    QuaternionMapBinding::registerBinding(L, "boost::unordered_map<string, Quaternion>");
    OgreVectorValueBinding<GameDataReference>::registerBinding(L, "Ogre::vector<GameDataReference>", "KenshiLua.GameDataReference");
    ObjectReferencesMapBinding::registerBinding(L, "boost::unordered_map<string, OgreVector_GameDataReference>", nullptr, "Ogre::vector<GameDataReference>");
    
    LektorValueBinding<hand>::registerBinding(L, "lektor<hand>", "KenshiLua.hand");
    LektorPtrBinding<GameData::ObjectInstance*>::registerBinding(L, "lektor<GameData::ObjectInstance*>", "KenshiLua.ObjectInstance");
    LektorPtrBinding<GameData*>::registerBinding(L, "lektor<GameData*>", GameDataBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua