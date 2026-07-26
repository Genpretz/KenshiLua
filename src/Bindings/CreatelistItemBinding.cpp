#include "pch.h"
#include "kenshi\RootObjectFactory.h"
#include "CreatelistItemBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/FactoryCallbackInterfaceBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/RootObjectContainerBinding.h"
#include "FactionBinding.h"
#include "GameDataBinding.h"
#include "RootObjectContainerBinding.h"

namespace KenshiLua
{

static CreatelistItem* getInstance(lua_State* L, int idx)
{
    return checkObject<CreatelistItem>(L, idx, CreatelistItemBinding::getMetatableName());
}

// --- Getters for CreatelistItem ---
static int CreatelistItem_get_container(lua_State* L)
{
    CreatelistItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CreatelistItem is nil");
    return pushObject<RootObjectContainer>(L, instance->container, RootObjectContainerBinding::getMetatableName());
}

static int CreatelistItem_get_homeBuilding(lua_State* L)
{
    CreatelistItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CreatelistItem is nil");
    return pushObject<Building>(L, instance->homeBuilding, BuildingBinding::getMetatableName());
}

static int CreatelistItem_get_faction(lua_State* L)
{
    CreatelistItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CreatelistItem is nil");
    return pushObject<Faction>(L, instance->faction, FactionBinding::getMetatableName());
}

static int CreatelistItem_get_data(lua_State* L)
{
    CreatelistItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CreatelistItem is nil");
    return pushObject<GameData>(L, instance->data, GameDataBinding::getMetatableName());
}

static int CreatelistItem_get_position(lua_State* L)
{
    CreatelistItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CreatelistItem is nil");
    pushVector3(L, instance->position);
    return 1;
}

static int CreatelistItem_get_isFromActiveLevelMod(lua_State* L)
{
    CreatelistItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CreatelistItem is nil");
    lua_pushboolean(L, instance->isFromActiveLevelMod ? 1 : 0);
    return 1;
}

static int CreatelistItem_get_rotation(lua_State* L)
{
    CreatelistItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CreatelistItem is nil");
    pushQuaternion(L, instance->rotation);
    return 1;
}

static int CreatelistItem_get_callbackObject(lua_State* L)
{
    CreatelistItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CreatelistItem is nil");
    return pushObject<FactoryCallbackInterface>(L, instance->callbackObject, FactoryCallbackInterfaceBinding::getMetatableName());
}

static int CreatelistItem_get_saveState(lua_State* L)
{
    CreatelistItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CreatelistItem is nil");
    return pushObject<GameSaveState>(L, instance->saveState, GameSaveStateBinding::getMetatableName());
}

static int CreatelistItem_get_age(lua_State* L)
{
    CreatelistItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CreatelistItem is nil");
    lua_pushnumber(L, instance->age);
    return 1;
}

// --- Setters for CreatelistItem ---
static int CreatelistItem_set_container(lua_State* L)
{
    CreatelistItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CreatelistItem is nil");
    instance->container = lua_isnoneornil(L, 2) ? nullptr : checkObject<RootObjectContainer>(L, 2, RootObjectContainerBinding::getMetatableName());
    return 0;
}

static int CreatelistItem_set_homeBuilding(lua_State* L)
{
    CreatelistItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CreatelistItem is nil");
    instance->homeBuilding = lua_isnoneornil(L, 2) ? nullptr : checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    return 0;
}

static int CreatelistItem_set_faction(lua_State* L)
{
    CreatelistItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CreatelistItem is nil");
    instance->faction = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

static int CreatelistItem_set_data(lua_State* L)
{
    CreatelistItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CreatelistItem is nil");
    instance->data = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int CreatelistItem_set_position(lua_State* L)
{
    CreatelistItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CreatelistItem is nil");
    readVector3(L, 2, instance->position);
    return 0;
}

static int CreatelistItem_set_isFromActiveLevelMod(lua_State* L)
{
    CreatelistItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CreatelistItem is nil");
    instance->isFromActiveLevelMod = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CreatelistItem_set_rotation(lua_State* L)
{
    CreatelistItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CreatelistItem is nil");
    readQuaternion(L, 2, instance->rotation);
    return 0;
}

static int CreatelistItem_set_callbackObject(lua_State* L)
{
    CreatelistItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CreatelistItem is nil");
    instance->callbackObject = lua_isnoneornil(L, 2) ? nullptr : checkObject<FactoryCallbackInterface>(L, 2, FactoryCallbackInterfaceBinding::getMetatableName());
    return 0;
}

static int CreatelistItem_set_saveState(lua_State* L)
{
    CreatelistItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CreatelistItem is nil");
    instance->saveState = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    return 0;
}

static int CreatelistItem_set_age(lua_State* L)
{
    CreatelistItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CreatelistItem is nil");
    instance->age = (float)luaL_checknumber(L, 2);
    return 0;
}

int CreatelistItemBinding::_CONSTRUCTOR(lua_State* L)
{
    CreatelistItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CreatelistItem is nil");

    GameData* _data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Ogre::Vector3 _position;
    readVector3(L, 3, _position);
    bool _isFromActiveLevelMod = lua_toboolean(L, 4) != 0;
    Faction* _owner = checkObject<Faction>(L, 5, FactionBinding::getMetatableName());
    Ogre::Quaternion _rotation;
    readQuaternion(L, 6, _rotation);
    FactoryCallbackInterface* _callbackObject = checkObject<FactoryCallbackInterface>(L, 7, FactoryCallbackInterfaceBinding::getMetatableName());
    GameSaveState* _saveStateDataSource = checkObject<GameSaveState>(L, 8, GameSaveStateBinding::getMetatableName());
    RootObjectContainer* certainContainer = checkObject<RootObjectContainer>(L, 9, RootObjectContainerBinding::getMetatableName());
    Building* home = checkObject<Building>(L, 10, BuildingBinding::getMetatableName());
    float _age = (float)luaL_checknumber(L, 11);
    CreatelistItem* result = instance->_CONSTRUCTOR(_data, _position, _isFromActiveLevelMod, _owner, _rotation, _callbackObject, _saveStateDataSource, certainContainer, home, _age);
    return pushObject<CreatelistItem>(L, result, CreatelistItemBinding::getMetatableName());
}

int CreatelistItemBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CreatelistItemBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CreatelistItem object");
    return 1;
}

void CreatelistItemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CreatelistItemBinding::gc },
        { "__tostring", CreatelistItemBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", CreatelistItemBinding::_CONSTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        CreatelistItemBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CreatelistItemBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "container", CreatelistItem_get_container);
    registerGetter(L, "homeBuilding", CreatelistItem_get_homeBuilding);
    registerGetter(L, "faction", CreatelistItem_get_faction);
    registerGetter(L, "data", CreatelistItem_get_data);
    registerGetter(L, "position", CreatelistItem_get_position);
    registerGetter(L, "isFromActiveLevelMod", CreatelistItem_get_isFromActiveLevelMod);
    registerGetter(L, "rotation", CreatelistItem_get_rotation);
    registerGetter(L, "callbackObject", CreatelistItem_get_callbackObject);
    registerGetter(L, "saveState", CreatelistItem_get_saveState);
    registerGetter(L, "age", CreatelistItem_get_age);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "container", CreatelistItem_set_container);
    registerSetter(L, "homeBuilding", CreatelistItem_set_homeBuilding);
    registerSetter(L, "faction", CreatelistItem_set_faction);
    registerSetter(L, "data", CreatelistItem_set_data);
    registerSetter(L, "position", CreatelistItem_set_position);
    registerSetter(L, "isFromActiveLevelMod", CreatelistItem_set_isFromActiveLevelMod);
    registerSetter(L, "rotation", CreatelistItem_set_rotation);
    registerSetter(L, "callbackObject", CreatelistItem_set_callbackObject);
    registerSetter(L, "saveState", CreatelistItem_set_saveState);
    registerSetter(L, "age", CreatelistItem_set_age);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua