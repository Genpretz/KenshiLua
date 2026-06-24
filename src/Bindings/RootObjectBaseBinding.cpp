#include "pch.h"
#include "kenshi\RootObjectBase.h"
#include "RootObjectBaseBinding.h"
#include "GameDataBinding.h"
#include "FactionBinding.h"
#include "OwnershipsBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static RootObjectBase* getB(lua_State* L, int idx)
{
    return checkObject<RootObjectBase>(L, idx, RootObjectBaseBinding::getMetatableName());
}

// --- Getters for RootObjectBase ---
static int RootObjectBase_get_validKey(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");
    lua_pushinteger(L, b->validKey);
    return 1;
}

static int RootObjectBase_get_owner(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");
    return pushObject<Faction>(L, b->owner, FactionBinding::getMetatableName());
}

static int RootObjectBase_get_displayName(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");
    lua_pushstring(L, b->displayName.c_str());
    return 1;
}

static int RootObjectBase_get_data(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");
    return pushObject<GameData>(L, b->data, GameDataBinding::getMetatableName());
}

static int RootObjectBase_get_pos(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");
    pushVector3(L, b->pos);
    return 1;
}

static int RootObjectBase_get_handle(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");
    // TODO: Unsupported type for handle (hand)
    lua_pushnil(L);
    return 1;
}

// --- Setters for RootObjectBase ---
static int RootObjectBase_set_validKey(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");
    b->validKey = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int RootObjectBase_set_owner(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for owner");
}

static int RootObjectBase_set_displayName(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");
    b->displayName = luaL_checkstring(L, 2);
    return 0;
}

static int RootObjectBase_set_data(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for data");
}

static int RootObjectBase_set_pos(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");
    readVector3(L, 2, b->pos);
    return 0;
}

static int RootObjectBase_set_handle(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");
    return luaL_error(L, "Read-only or unsupported setter type for handle");
}

int RootObjectBaseBinding::_DESTRUCTOR(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    b->_DESTRUCTOR();
    return 0;
}

int RootObjectBaseBinding::isValid(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    bool result = b->isValid();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBaseBinding::getName(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    std::string result = b->getName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int RootObjectBaseBinding::_NV_getName(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    std::string result = b->_NV_getName();
    lua_pushstring(L, result.c_str());
    return 1;
}

int RootObjectBaseBinding::setName(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    std::string name = luaL_checkstring(L, 2);
    b->setName(name);
    return 0;
}

int RootObjectBaseBinding::_NV_setName(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    std::string name = luaL_checkstring(L, 2);
    b->_NV_setName(name);
    return 0;
}

int RootObjectBaseBinding::getGameData(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    GameData* result = b->getGameData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int RootObjectBaseBinding::_NV_getGameData(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    GameData* result = b->_NV_getGameData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int RootObjectBaseBinding::getDataType(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    itemType result = b->getDataType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int RootObjectBaseBinding::_NV_getDataType(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    itemType result = b->_NV_getDataType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int RootObjectBaseBinding::typeIsAnItem(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    bool result = b->typeIsAnItem();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBaseBinding::_NV_typeIsAnItem(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    bool result = b->_NV_typeIsAnItem();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBaseBinding::isUnconcious(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    bool result = b->isUnconcious();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBaseBinding::_NV_isUnconcious(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    bool result = b->_NV_isUnconcious();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBaseBinding::getPositionForWaypoint(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    Ogre::Vector3 from;
    readVector3(L, 2, from);
    Ogre::Vector3 result = b->getPositionForWaypoint(from);
    pushVector3(L, result);
    return 1;
}

int RootObjectBaseBinding::_NV_getPositionForWaypoint(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    Ogre::Vector3 from;
    readVector3(L, 2, from);
    Ogre::Vector3 result = b->_NV_getPositionForWaypoint(from);
    pushVector3(L, result);
    return 1;
}

int RootObjectBaseBinding::getPosition(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    Ogre::Vector3 result = b->getPosition();
    pushVector3(L, result);
    return 1;
}

int RootObjectBaseBinding::_NV_getPosition(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    Ogre::Vector3 result = b->_NV_getPosition();
    pushVector3(L, result);
    return 1;
}

int RootObjectBaseBinding::getMovementSpeed(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    float result = b->getMovementSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int RootObjectBaseBinding::_NV_getMovementSpeed(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    float result = b->_NV_getMovementSpeed();
    lua_pushnumber(L, result);
    return 1;
}

int RootObjectBaseBinding::getMovementDirection(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    Ogre::Vector3 result = b->getMovementDirection();
    pushVector3(L, result);
    return 1;
}

int RootObjectBaseBinding::_NV_getMovementDirection(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    Ogre::Vector3 result = b->_NV_getMovementDirection();
    pushVector3(L, result);
    return 1;
}

int RootObjectBaseBinding::getFaction(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    Faction* result = b->getFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int RootObjectBaseBinding::_NV_getFaction(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    Faction* result = b->_NV_getFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int RootObjectBaseBinding::hasFaction(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    bool result = b->hasFaction();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectBaseBinding::getFloor(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    int result = b->getFloor();
    lua_pushinteger(L, result);
    return 1;
}

int RootObjectBaseBinding::_NV_getFloor(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    int result = b->_NV_getFloor();
    lua_pushinteger(L, result);
    return 1;
}

int RootObjectBaseBinding::getOwnerships(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    Ownerships* result = b->getOwnerships();
    return pushObject<Ownerships>(L, result, OwnershipsBinding::getMetatableName());
}

int RootObjectBaseBinding::_NV_getOwnerships(lua_State* L)
{
    RootObjectBase* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectBase is nil");

    Ownerships* result = b->_NV_getOwnerships();
    return pushObject<Ownerships>(L, result, OwnershipsBinding::getMetatableName());
}

/*
Skipped methods needing manual binding:
  line 28: RootObjectBase* _CONSTRUCTOR(...) - unsupported arg type
  line 57: SensoryData* getSensoryData(...) - unsupported return type
  line 58: SensoryData* _NV_getSensoryData(...) - unsupported return type
  line 59: StateBroadcastData* getStateBroadcast(...) - unsupported return type
  line 60: StateBroadcastData* _NV_getStateBroadcast(...) - unsupported return type
  line 61: TownBase* getCurrentTownLocation(...) - unsupported return type
  line 62: TownBase* _NV_getCurrentTownLocation(...) - unsupported return type
  line 63: const hand& getHandle(...) - reference return type
  line 64: void setHandle(...) - unsupported arg type
  line 65: void _NV_setHandle(...) - unsupported arg type
  line 66: GameSaveState serialise(...) - unsupported return type
  line 67: void loadFromSerialise(...) - unsupported arg type
  line 73: void setFaction(...) - unsupported arg type
  line 74: void _NV_setFaction(...) - unsupported arg type
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

void RootObjectBaseBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RootObjectBaseBinding::gc },
        { "__tostring", RootObjectBaseBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
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
        { "getOwnerships", RootObjectBaseBinding::getOwnerships },
        { "_NV_getOwnerships", RootObjectBaseBinding::_NV_getOwnerships },
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
    lua_pushcfunction(L, RootObjectBase_get_validKey);
    lua_setfield(L, -2, "validKey");
    lua_pushcfunction(L, RootObjectBase_get_owner);
    lua_setfield(L, -2, "owner");
    lua_pushcfunction(L, RootObjectBase_get_displayName);
    lua_setfield(L, -2, "displayName");
    lua_pushcfunction(L, RootObjectBase_get_data);
    lua_setfield(L, -2, "data");
    lua_pushcfunction(L, RootObjectBase_get_pos);
    lua_setfield(L, -2, "pos");
    lua_pushcfunction(L, RootObjectBase_get_handle);
    lua_setfield(L, -2, "handle");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, RootObjectBase_set_validKey);
    lua_setfield(L, -2, "validKey");
    lua_pushcfunction(L, RootObjectBase_set_owner);
    lua_setfield(L, -2, "owner");
    lua_pushcfunction(L, RootObjectBase_set_displayName);
    lua_setfield(L, -2, "displayName");
    lua_pushcfunction(L, RootObjectBase_set_data);
    lua_setfield(L, -2, "data");
    lua_pushcfunction(L, RootObjectBase_set_pos);
    lua_setfield(L, -2, "pos");
    lua_pushcfunction(L, RootObjectBase_set_handle);
    lua_setfield(L, -2, "handle");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua