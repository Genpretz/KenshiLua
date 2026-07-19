#include "pch.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/ObjectInstanceBinding.h"
#include "Bindings/Templates/OgreUnorderedBinding.h"
#include "Bindings/InstanceIDBinding.h"

#include <kenshi/GameSaveState.h>
#include "Bindings/GameSaveStateBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

typedef OgreUnorderedMapBinding<itemType, GameData*> StatesMapBinding;

static GameSaveState* getInstance(lua_State* L, int idx)
{
    return checkObject<GameSaveState>(L, idx, GameSaveStateBinding::getMetatableName());
}

// --- Getters for GameSaveState ---
static int GameSaveState_get_baseData(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");
    return pushObject<GameData>(L, instance->baseData, GameDataBinding::getMetatableName());
}

static int GameSaveState_get_dataSource(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");
    return pushObject<GameDataContainer>(L, instance->dataSource, GameDataContainerBinding::getMetatableName());
}

static int GameSaveState_get_firstTime(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");
    lua_pushboolean(L, instance->firstTime ? 1 : 0);
    return 1;
}

static int GameSaveState_get_instance(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");
    return pushObject<GameData::ObjectInstance>(L, instance->instance, ObjectInstanceBinding::getMetatableName());
}

static int GameSaveState_get_pos(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");
    pushVector3(L, instance->pos);
    return 1;
}

static int GameSaveState_get_rot(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");
    pushQuaternion(L, instance->rot);
    return 1;
}

static int GameSaveState_get_instanceID(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");
    lua_pushstring(L, instance->instanceID.c_str());
    return 1;
}

static int GameSaveState_get_states(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");
    return pushObject<StatesMapBinding::MapType>(L, &instance->states, StatesMapBinding::getMetatableName());
}

// --- Setters for GameSaveState ---
static int GameSaveState_set_baseData(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");
    GameData* val = (lua_isnil(L, 2) || lua_isnone(L, 2)) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->baseData = val;
    return 0;
}

static int GameSaveState_set_dataSource(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");
    GameDataContainer* val = (lua_isnil(L, 2) || lua_isnone(L, 2)) ? nullptr : checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    instance->dataSource = val;
    return 0;
}

static int GameSaveState_set_firstTime(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");
    instance->firstTime = lua_toboolean(L, 2) != 0;
    return 0;
}

static int GameSaveState_set_instance(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");
    GameData::ObjectInstance* val = (lua_isnil(L, 2) || lua_isnone(L, 2)) ? nullptr : checkObject<GameData::ObjectInstance>(L, 2, ObjectInstanceBinding::getMetatableName());
    instance->instance = val;
    return 0;
}

static int GameSaveState_set_pos(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");
    readVector3(L, 2, instance->pos);
    return 0;
}

static int GameSaveState_set_rot(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");
    readQuaternion(L, 2, instance->rot);
    return 0;
}

static int GameSaveState_set_instanceID(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");
    instance->instanceID = luaL_checkstring(L, 2);
    return 0;
}

static int GameSaveState_set_states(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");
    instance->states = *checkObject<StatesMapBinding::MapType>(L, 2, StatesMapBinding::getMetatableName());
    return 0;
}

// --- Methods for GameSaveState
int GameSaveStateBinding::generateNewInstanceID(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");

    instance->generateNewInstanceID();
    return 0;
}

int GameSaveStateBinding::generateStateID(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");

    itemType type = (itemType)luaL_checkinteger(L, 2);
    std::string result = instance->generateStateID(type);
    lua_pushstring(L, result.c_str());
    return 1;
}

int GameSaveStateBinding::createState(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");

    itemType type = (itemType)luaL_checkinteger(L, 2);
    GameData* result = instance->createState(type);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int GameSaveStateBinding::hasState(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");

    itemType type = (itemType)luaL_checkinteger(L, 2);
    bool result = instance->hasState(type);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameSaveStateBinding::getState(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");

    itemType type = (itemType)luaL_checkinteger(L, 2);
    GameData* result = instance->getState(type);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int GameSaveStateBinding::numStates(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");

    int result = instance->numStates();
    lua_pushinteger(L, result);
    return 1;
}

int GameSaveStateBinding::getPos(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");

    Ogre::Vector3 result = instance->getPos();
    pushVector3(L, result);
    return 1;
}

int GameSaveStateBinding::getRot(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");

    Ogre::Quaternion result = instance->getRot();
    pushQuaternion(L, result);
    return 1;
}

int GameSaveStateBinding::getTheInstancesData(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");

    GameData* result = instance->getTheInstancesData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int GameSaveStateBinding::createFromSerialisedInstanceData(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData::ObjectInstance* inst = checkObject<GameData::ObjectInstance>(L, 3, ObjectInstanceBinding::getMetatableName());
    std::string id = luaL_checkstring(L, 4);

    instance->createFromSerialisedInstanceData(container, inst, id);
    return 0;
}

int GameSaveStateBinding::addState(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->addState(state);
    return 0;
}

int GameSaveStateBinding::getInstanceID(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");

    InstanceID result = instance->getInstanceID();
    InstanceID* p = new InstanceID(result);
    return pushObject<InstanceID>(L, p, InstanceIDBinding::getMetatableName());
}

// Commented out as this method is not exported by kenshilib:
/*
int GameSaveStateBinding::getAllStates(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");

    const ogre_unordered_map<itemType, GameData*>::type& result = instance->getAllStates();
    return pushObject<StatesMapBinding::MapType>(L, const_cast<ogre_unordered_map<itemType, GameData*>::type*>(&result), StatesMapBinding::getMetatableName());
}
*/

int GameSaveStateBinding::isValid(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    bool result = instance && instance->operator bool();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameSaveStateBinding::_DESTRUCTOR(lua_State* L)
{
    GameSaveState* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameSaveState is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 15: GameSaveState* _CONSTRUCTOR(...) - overloaded method
  line 17: GameSaveState* _CONSTRUCTOR(...) - overloaded method
  line 19: GameSaveState* _CONSTRUCTOR(...) - overloaded method
  line 37: operator bool(...) - unsupported return type (exposed as isValid)
*/

int GameSaveStateBinding::gc(lua_State* L)
{
    void** ud = (void**)lua_touserdata(L, 1);
    if (ud && *ud) {
        delete (GameSaveState*)*ud;
        *ud = nullptr;
    }
    return 0;
}

int GameSaveStateBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.GameSaveState object");
    return 1;
}

void GameSaveStateBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GameSaveStateBinding::gc },
        { "__tostring", GameSaveStateBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "generateNewInstanceID", GameSaveStateBinding::generateNewInstanceID },
        { "generateStateID", GameSaveStateBinding::generateStateID },
        { "createState", GameSaveStateBinding::createState },
        { "hasState", GameSaveStateBinding::hasState },
        { "getState", GameSaveStateBinding::getState },
        { "numStates", GameSaveStateBinding::numStates },
        { "getPos", GameSaveStateBinding::getPos },
        { "getRot", GameSaveStateBinding::getRot },
        { "getTheInstancesData", GameSaveStateBinding::getTheInstancesData },
        { "createFromSerialisedInstanceData", GameSaveStateBinding::createFromSerialisedInstanceData },
        { "addState", GameSaveStateBinding::addState },
        { "getInstanceID", GameSaveStateBinding::getInstanceID },
        // Commented out as this method is not exported by kenshilib:
        // { "getAllStates", GameSaveStateBinding::getAllStates },
        { "isValid", GameSaveStateBinding::isValid },
        { "_DESTRUCTOR", GameSaveStateBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        GameSaveStateBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GameSaveStateBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, GameSaveState_get_baseData);
    lua_setfield(L, -2, "baseData");
    lua_pushcfunction(L, GameSaveState_get_dataSource);
    lua_setfield(L, -2, "dataSource");
    lua_pushcfunction(L, GameSaveState_get_firstTime);
    lua_setfield(L, -2, "firstTime");
    lua_pushcfunction(L, GameSaveState_get_instance);
    lua_setfield(L, -2, "instance");
    lua_pushcfunction(L, GameSaveState_get_pos);
    lua_setfield(L, -2, "pos");
    lua_pushcfunction(L, GameSaveState_get_rot);
    lua_setfield(L, -2, "rot");
    lua_pushcfunction(L, GameSaveState_get_instanceID);
    lua_setfield(L, -2, "instanceID");
    lua_pushcfunction(L, GameSaveState_get_states);
    lua_setfield(L, -2, "states");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, GameSaveState_set_baseData);
    lua_setfield(L, -2, "baseData");
    lua_pushcfunction(L, GameSaveState_set_dataSource);
    lua_setfield(L, -2, "dataSource");
    lua_pushcfunction(L, GameSaveState_set_firstTime);
    lua_setfield(L, -2, "firstTime");
    lua_pushcfunction(L, GameSaveState_set_instance);
    lua_setfield(L, -2, "instance");
    lua_pushcfunction(L, GameSaveState_set_pos);
    lua_setfield(L, -2, "pos");
    lua_pushcfunction(L, GameSaveState_set_rot);
    lua_setfield(L, -2, "rot");
    lua_pushcfunction(L, GameSaveState_set_instanceID);
    lua_setfield(L, -2, "instanceID");
    lua_pushcfunction(L, GameSaveState_set_states);
    lua_setfield(L, -2, "states");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    StatesMapBinding::registerBinding(L, "ogre_unordered_map<itemType, GameData*>", nullptr, GameDataBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
