#include "pch.h"
#include "Bindings/RootObjectBaseBinding.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/OwnershipsBinding.h"
#include "Bindings/SensoryDataBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Lua/BindingHelpers.h"
#include "kenshi/GameSaveState.h"
#include "kenshi/SensoryData.h"

namespace KenshiLua
{

static RootObjectBase* getInstance(lua_State* L, int idx)
{
    return checkObject<RootObjectBase>(L, idx, RootObjectBaseBinding::getMetatableName());
}

// --- Getters for RootObjectBase ---
static int RootObjectBase_get_validKey(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");
    lua_pushinteger(L, instance->validKey);
    return 1;
}

static int RootObjectBase_get_owner(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");
    return pushObject<Faction>(L, instance->owner, FactionBinding::getMetatableName());
}

static int RootObjectBase_get_displayName(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");
    lua_pushstring(L, instance->displayName.c_str());
    return 1;
}

static int RootObjectBase_get_data(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");
    return pushObject<GameData>(L, instance->data, GameDataBinding::getMetatableName());
}

static int RootObjectBase_get_pos(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");
    pushVector3(L, instance->pos);
    return 1;
}

static int RootObjectBase_get_handle(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");
    return HandBinding::push(L, instance->handle);
}

// --- Setters for RootObjectBase ---
static int RootObjectBase_set_validKey(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");
    instance->validKey = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int RootObjectBase_set_owner(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");
    instance->owner = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

static int RootObjectBase_set_displayName(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");
    instance->displayName = luaL_checkstring(L, 2);
    return 0;
}

static int RootObjectBase_set_data(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");
    instance->data = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int RootObjectBase_set_pos(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");
    readVector3(L, 2, instance->pos);
    return 0;
}

static int RootObjectBase_set_handle(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");
    instance->handle = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

int RootObjectBaseBinding::_CONSTRUCTOR(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Faction* ownr = checkObject<Faction>(L, 3, FactionBinding::getMetatableName());
    hand h = *checkObject<hand>(L, 4, HandBinding::getMetatableName());
    RootObjectBase* result = instance->_CONSTRUCTOR(d, ownr, h);
    return pushObject<RootObjectBase>(L, result, RootObjectBaseBinding::getMetatableName());
}

int RootObjectBaseBinding::_DESTRUCTOR(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int RootObjectBaseBinding::isValid(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    bool result = instance->isValid();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBaseBinding::getName(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    std::string result = instance->getName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int RootObjectBaseBinding::_NV_getName(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    std::string result = instance->_NV_getName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int RootObjectBaseBinding::setName(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    const std::string name = luaL_checkstring(L, 2);
    instance->setName(name);
    return 0;
}

int RootObjectBaseBinding::_NV_setName(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    const std::string name = luaL_checkstring(L, 2);
    instance->_NV_setName(name);
    return 0;
}

int RootObjectBaseBinding::getGameData(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    GameData* result = instance->getGameData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int RootObjectBaseBinding::_NV_getGameData(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    GameData* result = instance->_NV_getGameData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int RootObjectBaseBinding::getDataType(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    itemType result = instance->getDataType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int RootObjectBaseBinding::_NV_getDataType(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    itemType result = instance->_NV_getDataType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int RootObjectBaseBinding::typeIsAnItem(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    bool result = instance->typeIsAnItem();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBaseBinding::_NV_typeIsAnItem(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    bool result = instance->_NV_typeIsAnItem();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBaseBinding::isUnconcious(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    bool result = instance->isUnconcious();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBaseBinding::_NV_isUnconcious(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    bool result = instance->_NV_isUnconcious();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBaseBinding::getPositionForWaypoint(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    Ogre::Vector3 from;
    readVector3(L, 2, from);
    Ogre::Vector3 result = instance->getPositionForWaypoint(from);
    pushVector3(L, result);
    return 1;
}

int RootObjectBaseBinding::_NV_getPositionForWaypoint(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    Ogre::Vector3 from;
    readVector3(L, 2, from);
    Ogre::Vector3 result = instance->_NV_getPositionForWaypoint(from);
    pushVector3(L, result);
    return 1;
}

int RootObjectBaseBinding::getPosition(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    Ogre::Vector3 result = instance->getPosition();
    pushVector3(L, result);
    return 1;
}

int RootObjectBaseBinding::_NV_getPosition(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    Ogre::Vector3 result = instance->_NV_getPosition();
    pushVector3(L, result);
    return 1;
}

int RootObjectBaseBinding::getMovementSpeed(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    float result = instance->getMovementSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int RootObjectBaseBinding::_NV_getMovementSpeed(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    float result = instance->_NV_getMovementSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int RootObjectBaseBinding::getMovementDirection(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    Ogre::Vector3 result = instance->getMovementDirection();
    pushVector3(L, result);
    return 1;
}

int RootObjectBaseBinding::_NV_getMovementDirection(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    Ogre::Vector3 result = instance->_NV_getMovementDirection();
    pushVector3(L, result);
    return 1;
}

int RootObjectBaseBinding::getFaction(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    Faction* result = instance->getFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int RootObjectBaseBinding::_NV_getFaction(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    Faction* result = instance->_NV_getFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int RootObjectBaseBinding::hasFaction(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    bool result = instance->hasFaction();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBaseBinding::getFloor(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    int result = instance->getFloor();
    lua_pushinteger(L, result);
    return 1;
}

int RootObjectBaseBinding::_NV_getFloor(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    int result = instance->_NV_getFloor();
    lua_pushinteger(L, result);
    return 1;
}

int RootObjectBaseBinding::getSensoryData(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    SensoryData* result = instance->getSensoryData();
    return pushObject<SensoryData>(L, result, SensoryDataBinding::getMetatableName());
}

int RootObjectBaseBinding::_NV_getSensoryData(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    SensoryData* result = instance->_NV_getSensoryData();
    return pushObject<SensoryData>(L, result, SensoryDataBinding::getMetatableName());
}

int RootObjectBaseBinding::getStateBroadcast(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    StateBroadcastData* result = instance->getStateBroadcast();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int RootObjectBaseBinding::_NV_getStateBroadcast(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    StateBroadcastData* result = instance->_NV_getStateBroadcast();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int RootObjectBaseBinding::getCurrentTownLocation(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    TownBase* result = instance->getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int RootObjectBaseBinding::_NV_getCurrentTownLocation(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    TownBase* result = instance->_NV_getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int RootObjectBaseBinding::loadFromSerialise(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    GameSaveState* _a1 = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->loadFromSerialise(_a1);
    return 0;
}

int RootObjectBaseBinding::getOwnerships(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    Ownerships* result = instance->getOwnerships();
    return pushObject<Ownerships>(L, result, OwnershipsBinding::getMetatableName());
}

int RootObjectBaseBinding::_NV_getOwnerships(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    Ownerships* result = instance->_NV_getOwnerships();
    return pushObject<Ownerships>(L, result, OwnershipsBinding::getMetatableName());
}

int RootObjectBaseBinding::setFaction(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    ActivePlatoon* a = checkObject<ActivePlatoon>(L, 3, ActivePlatoonBinding::getMetatableName());
    instance->setFaction(p, a);
    return 0;
}

int RootObjectBaseBinding::_NV_setFaction(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");

    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    ActivePlatoon* a = checkObject<ActivePlatoon>(L, 3, ActivePlatoonBinding::getMetatableName());
    instance->_NV_setFaction(p, a);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 63: const hand& getHandle(...) - reference return type
  line 64: void setHandle(...) - non-string reference arg
  line 65: void _NV_setHandle(...) - non-string reference arg
  line 66: GameSaveState serialise(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - RootObjectBaseBinding::getStateBroadcast: StateBroadcastData* (unbound pointer)
  - RootObjectBaseBinding::_NV_getStateBroadcast: StateBroadcastData* (unbound pointer)
*/

int RootObjectBaseBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int RootObjectBaseBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.RootObjectBase object");
    return 1;
}



int RootObjectBaseBinding::_NV_setHandle(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    instance->_NV_setHandle(*h);
    return 0;
}


int RootObjectBaseBinding::getHandle(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");
    const hand& result = instance->getHandle();
    HandBinding::push(L, result);
    return 1;
}


int RootObjectBaseBinding::serialise(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* refList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    PosRotPair* offset = (PosRotPair*)lua_touserdata(L, 4);
    GameSaveState result = instance->serialise(container, refList, offset);
    return pushValue<GameSaveState>(L, result, GameSaveStateBinding::getMetatableName());
}


int RootObjectBaseBinding::setHandle(lua_State* L)
{
    RootObjectBase* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RootObjectBase is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    instance->setHandle(*h);
    return 0;
}


void RootObjectBaseBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RootObjectBaseBinding::gc },
        { "__tostring", RootObjectBaseBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", RootObjectBaseBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", RootObjectBaseBinding::_DESTRUCTOR },
        { "isValid", RootObjectBaseBinding::isValid },
        { "getName", RootObjectBaseBinding::getName },
        { "_NV_getName", RootObjectBaseBinding::_NV_getName },
        { "setName", RootObjectBaseBinding::setName },
        { "_NV_setName", RootObjectBaseBinding::_NV_setName },
        { "getGameData", RootObjectBaseBinding::getGameData },
        { "_NV_getGameData", RootObjectBaseBinding::_NV_getGameData },
        { "getDataType", RootObjectBaseBinding::getDataType },
        { "_NV_getDataType", RootObjectBaseBinding::_NV_getDataType },
        { "typeIsAnItem", RootObjectBaseBinding::typeIsAnItem },
        { "_NV_typeIsAnItem", RootObjectBaseBinding::_NV_typeIsAnItem },
        { "isUnconcious", RootObjectBaseBinding::isUnconcious },
        { "_NV_isUnconcious", RootObjectBaseBinding::_NV_isUnconcious },
        { "getPositionForWaypoint", RootObjectBaseBinding::getPositionForWaypoint },
        { "_NV_getPositionForWaypoint", RootObjectBaseBinding::_NV_getPositionForWaypoint },
        { "getPosition", RootObjectBaseBinding::getPosition },
        { "_NV_getPosition", RootObjectBaseBinding::_NV_getPosition },
        { "getMovementSpeed", RootObjectBaseBinding::getMovementSpeed },
        { "_NV_getMovementSpeed", RootObjectBaseBinding::_NV_getMovementSpeed },
        { "getMovementDirection", RootObjectBaseBinding::getMovementDirection },
        { "_NV_getMovementDirection", RootObjectBaseBinding::_NV_getMovementDirection },
        { "getFaction", RootObjectBaseBinding::getFaction },
        { "_NV_getFaction", RootObjectBaseBinding::_NV_getFaction },
        { "hasFaction", RootObjectBaseBinding::hasFaction },
        { "getFloor", RootObjectBaseBinding::getFloor },
        { "_NV_getFloor", RootObjectBaseBinding::_NV_getFloor },
        { "getSensoryData", RootObjectBaseBinding::getSensoryData },
        { "_NV_getSensoryData", RootObjectBaseBinding::_NV_getSensoryData },
        { "getStateBroadcast", RootObjectBaseBinding::getStateBroadcast },
        { "_NV_getStateBroadcast", RootObjectBaseBinding::_NV_getStateBroadcast },
        { "getCurrentTownLocation", RootObjectBaseBinding::getCurrentTownLocation },
        { "_NV_getCurrentTownLocation", RootObjectBaseBinding::_NV_getCurrentTownLocation },
        { "loadFromSerialise", RootObjectBaseBinding::loadFromSerialise },
        { "getOwnerships", RootObjectBaseBinding::getOwnerships },
        { "_NV_getOwnerships", RootObjectBaseBinding::_NV_getOwnerships },
        { "setFaction", RootObjectBaseBinding::setFaction },
        { "_NV_setFaction", RootObjectBaseBinding::_NV_setFaction },
                { "getHandle", RootObjectBaseBinding::getHandle },
        { "setHandle", RootObjectBaseBinding::setHandle },
        { "_NV_setHandle", RootObjectBaseBinding::_NV_setHandle },
        { "serialise", RootObjectBaseBinding::serialise },
        { 0, 0 }
    };

    registerClass(
        L, 
        RootObjectBaseBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, RootObjectBaseBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "validKey", RootObjectBase_get_validKey);
    registerGetter(L, "owner", RootObjectBase_get_owner);
    registerGetter(L, "displayName", RootObjectBase_get_displayName);
    registerGetter(L, "data", RootObjectBase_get_data);
    registerGetter(L, "pos", RootObjectBase_get_pos);
    registerGetter(L, "handle", RootObjectBase_get_handle);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "validKey", RootObjectBase_set_validKey);
    registerSetter(L, "owner", RootObjectBase_set_owner);
    registerSetter(L, "displayName", RootObjectBase_set_displayName);
    registerSetter(L, "data", RootObjectBase_set_data);
    registerSetter(L, "pos", RootObjectBase_set_pos);
    registerSetter(L, "handle", RootObjectBase_set_handle);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua