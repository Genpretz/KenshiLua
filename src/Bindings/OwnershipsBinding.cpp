#include "pch.h"
#include "kenshi\Platoon.h"
#include "OwnershipsBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/PlatoonBinding.h"

namespace KenshiLua
{

static Ownerships* getB(lua_State* L, int idx)
{
    return checkObject<Ownerships>(L, idx, OwnershipsBinding::getMetatableName());
}

// --- Getters for Ownerships ---
static int Ownerships_get_slaves(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");
    // TODO: Unsupported type for slaves (std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy > >)
    lua_pushnil(L);
    return 1;
}

static int Ownerships_get__homeTown(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");
    // TODO: Unsupported type for _homeTown (TownBase*)
    lua_pushnil(L);
    return 1;
}

static int Ownerships_get__homeBuilding(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");
    // TODO: Unsupported type for _homeBuilding (hand)
    lua_pushnil(L);
    return 1;
}

static int Ownerships_get_stuff(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");
    // TODO: Unsupported type for stuff (lektor<hand>)
    lua_pushnil(L);
    return 1;
}

static int Ownerships_get_faction(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");
    return pushObject<Faction>(L, b->faction, FactionBinding::getMetatableName());
}

static int Ownerships_get_me(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");
    return pushObject<Platoon>(L, b->me, PlatoonBinding::getMetatableName());
}

static int Ownerships_get_occupiedTown(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");
    // TODO: Unsupported type for occupiedTown (TownBase*)
    lua_pushnil(L);
    return 1;
}

static int Ownerships_get_money(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");
    lua_pushinteger(L, b->money);
    return 1;
}

// --- Setters for Ownerships ---
static int Ownerships_set_slaves(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");
    return luaL_error(L, "Read-only or unsupported setter type for slaves");
}

static int Ownerships_set__homeTown(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");
    return luaL_error(L, "Read-only or unsupported setter type for _homeTown");
}

static int Ownerships_set__homeBuilding(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");
    return luaL_error(L, "Read-only or unsupported setter type for _homeBuilding");
}

static int Ownerships_set_stuff(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");
    return luaL_error(L, "Read-only or unsupported setter type for stuff");
}

static int Ownerships_set_faction(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");
    return luaL_error(L, "Read-only or unsupported setter type for faction");
}

static int Ownerships_set_me(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");
    return luaL_error(L, "Read-only or unsupported setter type for me");
}

static int Ownerships_set_occupiedTown(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");
    return luaL_error(L, "Read-only or unsupported setter type for occupiedTown");
}

static int Ownerships_set_money(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");
    b->money = (int)luaL_checkinteger(L, 2);
    return 0;
}

int OwnershipsBinding::takeMoney(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");

    int val = (int)luaL_checkinteger(L, 2);
    bool result = b->takeMoney(val);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int OwnershipsBinding::_NV_takeMoney(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");

    int val = (int)luaL_checkinteger(L, 2);
    bool result = b->_NV_takeMoney(val);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int OwnershipsBinding::takeMoneyByForce(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");

    int val = (int)luaL_checkinteger(L, 2);
    b->takeMoneyByForce(val);
    return 0;
}

int OwnershipsBinding::_NV_takeMoneyByForce(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");

    int val = (int)luaL_checkinteger(L, 2);
    b->_NV_takeMoneyByForce(val);
    return 0;
}

int OwnershipsBinding::getMoney(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");

    int result = b->getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int OwnershipsBinding::addMoney(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");

    int amount = (int)luaL_checkinteger(L, 2);
    b->addMoney(amount);
    return 0;
}

int OwnershipsBinding::setMoney(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");

    int amount = (int)luaL_checkinteger(L, 2);
    b->setMoney(amount);
    return 0;
}

int OwnershipsBinding::setHomeBuildingDesignation(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");

    BuildingDesignation d = (BuildingDesignation)luaL_checkinteger(L, 2);
    b->setHomeBuildingDesignation(d);
    return 0;
}

int OwnershipsBinding::getOccupiedTownFaction(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");

    Faction* result = b->getOccupiedTownFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int OwnershipsBinding::_DESTRUCTOR(lua_State* L)
{
    Ownerships* b = getB(L, 1);
    if (!b) return luaL_error(L, "Ownerships is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 58: Ownerships* _CONSTRUCTOR(...) - unsupported arg type
  line 59: void setHandle(...) - unsupported arg type
  line 60: void addOwnedObject(...) - unsupported arg type
  line 61: void removeOwnedObject(...) - unsupported arg type
  line 62: bool isOwned(...) - unsupported arg type
  line 71: void copyFrom(...) - unsupported arg type
  line 73: void serialise(...) - unsupported arg type
  line 74: void load(...) - unsupported arg type
  line 77: void setHomeTown(...) - unsupported arg type
  line 78: void setHomeBuilding(...) - unsupported arg type
  line 79: void getOwnedBuildingsH(...) - unsupported arg type
  line 80: void getOwnedBuildingPtrs(...) - unsupported arg type
  line 82: void getHomeFurnitureOfType(...) - unsupported arg type
  line 83: int getOwnedPtrs(...) - unsupported arg type
  line 84: void getBuildingsWithFunction(...) - unsupported arg type
  line 85: bool isMyTown(...) - unsupported arg type
  line 86: bool canIUseThisBuilding(...) - unsupported arg type
  line 87: void declareOccupiedTown(...) - unsupported arg type
*/

int OwnershipsBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int OwnershipsBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Ownerships object");
    return 1;
}

void OwnershipsBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       OwnershipsBinding::gc },
        { "__tostring", OwnershipsBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "takeMoney", OwnershipsBinding::takeMoney },
        { "_NV_takeMoney", OwnershipsBinding::_NV_takeMoney },
        { "takeMoneyByForce", OwnershipsBinding::takeMoneyByForce },
        { "_NV_takeMoneyByForce", OwnershipsBinding::_NV_takeMoneyByForce },
        { "getMoney", OwnershipsBinding::getMoney },
        { "addMoney", OwnershipsBinding::addMoney },
        { "setMoney", OwnershipsBinding::setMoney },
        { "setHomeBuildingDesignation", OwnershipsBinding::setHomeBuildingDesignation },
        { "getOccupiedTownFaction", OwnershipsBinding::getOccupiedTownFaction },
        { "_DESTRUCTOR", OwnershipsBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        OwnershipsBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, OwnershipsBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, Ownerships_get_slaves);
    lua_setfield(L, -2, "slaves");
    lua_pushcfunction(L, Ownerships_get__homeTown);
    lua_setfield(L, -2, "_homeTown");
    lua_pushcfunction(L, Ownerships_get__homeBuilding);
    lua_setfield(L, -2, "_homeBuilding");
    lua_pushcfunction(L, Ownerships_get_stuff);
    lua_setfield(L, -2, "stuff");
    lua_pushcfunction(L, Ownerships_get_faction);
    lua_setfield(L, -2, "faction");
    lua_pushcfunction(L, Ownerships_get_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, Ownerships_get_occupiedTown);
    lua_setfield(L, -2, "occupiedTown");
    lua_pushcfunction(L, Ownerships_get_money);
    lua_setfield(L, -2, "money");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, Ownerships_set_slaves);
    lua_setfield(L, -2, "slaves");
    lua_pushcfunction(L, Ownerships_set__homeTown);
    lua_setfield(L, -2, "_homeTown");
    lua_pushcfunction(L, Ownerships_set__homeBuilding);
    lua_setfield(L, -2, "_homeBuilding");
    lua_pushcfunction(L, Ownerships_set_stuff);
    lua_setfield(L, -2, "stuff");
    lua_pushcfunction(L, Ownerships_set_faction);
    lua_setfield(L, -2, "faction");
    lua_pushcfunction(L, Ownerships_set_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, Ownerships_set_occupiedTown);
    lua_setfield(L, -2, "occupiedTown");
    lua_pushcfunction(L, Ownerships_set_money);
    lua_setfield(L, -2, "money");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua