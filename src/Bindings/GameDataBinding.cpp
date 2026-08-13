#include "pch.h"
#include "kenshi\GameData.h"
#include "GameDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/GameDataReferenceBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/Util/TripleIntBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/BoostUnorderedBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/Util/OgreVectorBinding.h"

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
    return pushObject<Ogre::vector<GameDataReference>::type>(L, const_cast<Ogre::vector<GameDataReference>::type*>(result), "KenshiLua.OgreVectorGameDataReference");
}

int GameDataBinding::getReferenceListIfExists(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string listname = luaL_checkstring(L, 2);
    const Ogre::vector<GameDataReference>::type* result = instance->getReferenceListIfExists(listname);
    return pushObject<Ogre::vector<GameDataReference>::type>(L, const_cast<Ogre::vector<GameDataReference>::type*>(result), "KenshiLua.OgreVectorGameDataReference");
}

int GameDataBinding::_getReferenceList_nonConst(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string listname = luaL_checkstring(L, 2);
    Ogre::vector<GameDataReference>::type* result = instance->_getReferenceList_nonConst(listname);
    return pushObject<Ogre::vector<GameDataReference>::type>(L, result, "KenshiLua.OgreVectorGameDataReference");
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

int GameDataBinding::storeHandleList(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    lektor<hand>* handle = LektorPtrBinding<hand>::get(L, 2);
    if (!handle) return luaL_error(L, "Argument 2 to storeHandleList must be lektor<hand>");
    const std::string name = luaL_checkstring(L, 3);
    instance->storeHandleList(*handle, name);
    return 0;
}

int GameDataBinding::storeHandle(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    const std::string name = luaL_checkstring(L, 3);
    bool redirect = lua_toboolean(L, 4) != 0;
    instance->storeHandle(*h, name, redirect);
    return 0;
}

int GameDataBinding::getHandle(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string name = luaL_checkstring(L, 2);
    hand h;
    bool result = instance->getHandle(h, name);
    if (result)
    {
        return HandBinding::push(L, h);
    }
    lua_pushnil(L);
    return 1;
}

int GameDataBinding::add(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string n = luaL_checkstring(L, 2);
    if (lua_istable(L, 3))
    {
        Ogre::Vector3 v;
        readVector3(L, 3, v);
        instance->add(n, v);
        return 0;
    }
    else if (lua_isboolean(L, 3))
    {
        bool v = lua_toboolean(L, 3) != 0;
        std::string category = luaL_optstring(L, 4, "");
        bool vis = lua_toboolean(L, 5) != 0;
        instance->add(n, v, category, vis);
        return 0;
    }
    else if (lua_isnumber(L, 3))
    {
        if (lua_isinteger(L, 3))
        {
            int v = (int)lua_tointeger(L, 3);
            std::string category = luaL_optstring(L, 4, "");
            bool vis = lua_toboolean(L, 5) != 0;
            instance->add(n, v, category, vis);
            return 0;
        }
        else
        {
            float v = (float)lua_tonumber(L, 3);
            std::string category = luaL_optstring(L, 4, "");
            bool vis = lua_toboolean(L, 5) != 0;
            bool isSlider = lua_toboolean(L, 6) != 0;
            instance->add(n, v, category, vis, isSlider);
            return 0;
        }
    }
    return luaL_error(L, "Argument 3 to add must be Vector3, boolean, int, or float");
}

int GameDataBinding::removeFromList(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string list = luaL_checkstring(L, 2);
    if (lua_isnumber(L, 3))
    {
        int id = (int)lua_tointeger(L, 3);
        instance->removeFromList(list, id);
        return 0;
    }
    else
    {
        const std::string id = luaL_checkstring(L, 3);
        instance->removeFromList(list, id);
        return 0;
    }
}

int GameDataBinding::getFromList(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string n = luaL_checkstring(L, 2);
    int index = (int)luaL_checkinteger(L, 3);
    const std::string& result = instance->getFromList(n, index);
    lua_pushstring(L, result.c_str());
    return 1;
}

int GameDataBinding::getFromList_random(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string n = luaL_checkstring(L, 2);
    const std::string& result = instance->getFromList_random(n);
    lua_pushstring(L, result.c_str());
    return 1;
}

int GameDataBinding::getAllFromList(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string n = luaL_checkstring(L, 2);
    lektor<std::string>* list = LektorPtrBinding<std::string>::get(L, 3);
    if (!list) return luaL_error(L, "Argument 3 to getAllFromList must be lektor<string>");
    instance->getAllFromList(n, *list);
    return 0;
}

int GameDataBinding::getValueFromList(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");

    const std::string list = luaL_checkstring(L, 2);
    int index = (int)luaL_checkinteger(L, 3);
    const TripleInt& result = instance->getValueFromList(list, index);
    return pushValue<TripleInt>(L, result, TripleIntBinding::getMetatableName());
}

static int GameData_get_activeValues(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    return BoostUnorderedMapBinding<std::string, bool>::push(L, &instance->activeValues);
}
static int GameData_set_activeValues(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    auto* val = BoostUnorderedMapBinding<std::string, bool>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'activeValues' must be StringBoolMap");
    instance->activeValues = *val;
    return 0;
}

static int GameData_get_bdata(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    return BoostUnorderedMapBinding<std::string, bool>::push(L, &instance->bdata);
}
static int GameData_set_bdata(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    auto* val = BoostUnorderedMapBinding<std::string, bool>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'bdata' must be StringBoolMap");
    instance->bdata = *val;
    return 0;
}

static int GameData_get_sdata(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    return BoostUnorderedMapBinding<std::string, std::string>::push(L, &instance->sdata);
}
static int GameData_set_sdata(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    auto* val = BoostUnorderedMapBinding<std::string, std::string>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'sdata' must be StringStringMap");
    instance->sdata = *val;
    return 0;
}

static int GameData_get_idata(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    return BoostUnorderedMapBinding<std::string, int>::push(L, &instance->idata);
}
static int GameData_set_idata(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    auto* val = BoostUnorderedMapBinding<std::string, int>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'idata' must be StringIntMap");
    instance->idata = *val;
    return 0;
}

static int GameData_get_fdata(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    return BoostUnorderedMapBinding<std::string, float>::push(L, &instance->fdata);
}
static int GameData_set_fdata(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    auto* val = BoostUnorderedMapBinding<std::string, float>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'fdata' must be StringFloatMap");
    instance->fdata = *val;
    return 0;
}

static int GameData_get_filesdata(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    return BoostUnorderedMapBinding<std::string, std::string>::push(L, &instance->filesdata);
}
static int GameData_set_filesdata(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    auto* val = BoostUnorderedMapBinding<std::string, std::string>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'filesdata' must be StringStringMap");
    instance->filesdata = *val;
    return 0;
}

static int GameData_get_vecdata(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    return BoostUnorderedMapBinding<std::string, Ogre::Vector3>::push(L, &instance->vecdata);
}
static int GameData_set_vecdata(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    auto* val = BoostUnorderedMapBinding<std::string, Ogre::Vector3>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'vecdata' must be StringVector3Map");
    instance->vecdata = *val;
    return 0;
}

static int GameData_get_quatdata(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    return BoostUnorderedMapBinding<std::string, Ogre::Quaternion>::push(L, &instance->quatdata);
}
static int GameData_set_quatdata(lua_State* L)
{
    GameData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameData is nil");
    auto* val = BoostUnorderedMapBinding<std::string, Ogre::Quaternion>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'quatdata' must be StringQuaternionMap");
    instance->quatdata = *val;
    return 0;
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
        { "getSourceContainer", GameDataBinding::getSourceContainer },
        { "destroy", GameDataBinding::destroy },
        { "initialise", GameDataBinding::initialise },
        { "loadFromFile", GameDataBinding::loadFromFile },
        { "saveToFile", GameDataBinding::saveToFile },
        { "storeHandleList", GameDataBinding::storeHandleList },
        { "storeHandle", GameDataBinding::storeHandle },
        { "getHandle", GameDataBinding::getHandle },
        { "updateFrom", GameDataBinding::updateFrom },
        { "isValueActive", GameDataBinding::isValueActive },
        { "isRefActive", GameDataBinding::isRefActive },
        { "addFileName", GameDataBinding::addFileName },
        { "addString", GameDataBinding::addString },
        { "add", GameDataBinding::add },
        { "getGameDataReferenceObject", GameDataBinding::getGameDataReferenceObject },
        { "addToList", GameDataBinding::addToList },
        { "removeFromList", GameDataBinding::removeFromList },
        { "findInList", GameDataBinding::findInList },
        { "clearList", GameDataBinding::clearList },
        { "clearEverything", GameDataBinding::clearEverything },
        { "clearInstances", GameDataBinding::clearInstances },
        { "getFromList", GameDataBinding::getFromList },
        { "getFromList_random", GameDataBinding::getFromList_random },
        { "getListSize", GameDataBinding::getListSize },
        { "listExists", GameDataBinding::listExists },
        { "listExistsAndNotEmpty", GameDataBinding::listExistsAndNotEmpty },
        { "getAllFromList", GameDataBinding::getAllFromList },
        { "getReferenceList", GameDataBinding::getReferenceList },
        { "getReferenceListIfExists", GameDataBinding::getReferenceListIfExists },
        { "_getReferenceList_nonConst", GameDataBinding::_getReferenceList_nonConst },
        { "getFromListAsData", GameDataBinding::getFromListAsData },
        { "getValueFromList", GameDataBinding::getValueFromList },
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
    registerGetter(L, "activeValues", GameData_get_activeValues);
    registerGetter(L, "bdata", GameData_get_bdata);
    registerGetter(L, "sdata", GameData_get_sdata);
    registerGetter(L, "idata", GameData_get_idata);
    registerGetter(L, "fdata", GameData_get_fdata);
    registerGetter(L, "filesdata", GameData_get_filesdata);
    registerGetter(L, "vecdata", GameData_get_vecdata);
    registerGetter(L, "quatdata", GameData_get_quatdata);
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
    registerSetter(L, "activeValues", GameData_set_activeValues);
    registerSetter(L, "bdata", GameData_set_bdata);
    registerSetter(L, "sdata", GameData_set_sdata);
    registerSetter(L, "idata", GameData_set_idata);
    registerSetter(L, "fdata", GameData_set_fdata);
    registerSetter(L, "filesdata", GameData_set_filesdata);
    registerSetter(L, "vecdata", GameData_set_vecdata);
    registerSetter(L, "quatdata", GameData_set_quatdata);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    OgreVectorValueBinding<GameDataReference>::registerBinding(L, "ogre_vector<GameDataReference>", GameDataReferenceBinding::getMetatableName());

    BoostUnorderedMapBinding<std::string, bool>::registerBinding(L, "boost_unordered_map<std::string, bool>");
    BoostUnorderedMapBinding<std::string, std::string>::registerBinding(L, "boost_unordered_map<std::string, std::string>");
    BoostUnorderedMapBinding<std::string, int>::registerBinding(L, "boost_unordered_map<std::string, int>");
    BoostUnorderedMapBinding<std::string, float>::registerBinding(L, "boost_unordered_map<std::string, float>");
    BoostUnorderedMapBinding<std::string, Ogre::Vector3>::registerBinding(L, "boost_unordered_map<std::string, Vector3>");
    BoostUnorderedMapBinding<std::string, Ogre::Quaternion>::registerBinding(L, "boost_unordered_map<std::string, Quaternion>");

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua