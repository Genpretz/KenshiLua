#include "pch.h"
#include "kenshi\Platoon.h"
#include "OwnershipsBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/Util/HandBinding.h"

namespace KenshiLua
{

static Ownerships* getInstance(lua_State* L, int idx)
{
    return checkObject<Ownerships>(L, idx, OwnershipsBinding::getMetatableName());
}

// --- Getters for Ownerships ---
static int Ownerships_get__homeTown(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    return pushObject<TownBase>(L, instance->_homeTown, TownBaseBinding::getMetatableName());
}

static int Ownerships_get__homeBuilding(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    return handBinding::push(L, instance->_homeBuilding);
}

static int Ownerships_get_faction(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    return pushObject<Faction>(L, instance->faction, FactionBinding::getMetatableName());
}

static int Ownerships_get_me(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    return pushObject<Platoon>(L, instance->me, PlatoonBinding::getMetatableName());
}

static int Ownerships_get_occupiedTown(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    return pushObject<TownBase>(L, instance->occupiedTown, TownBaseBinding::getMetatableName());
}

static int Ownerships_get_money(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    lua_pushinteger(L, instance->money);
    return 1;
}

// --- Setters for Ownerships ---
static int Ownerships_set__homeTown(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    instance->_homeTown = lua_isnoneornil(L, 2) ? nullptr : checkObject<TownBase>(L, 2, TownBaseBinding::getMetatableName());
    return 0;
}

static int Ownerships_set__homeBuilding(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    instance->_homeBuilding = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int Ownerships_set_faction(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    instance->faction = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

static int Ownerships_set_me(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    instance->me = lua_isnoneornil(L, 2) ? nullptr : checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    return 0;
}

static int Ownerships_set_occupiedTown(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    instance->occupiedTown = lua_isnoneornil(L, 2) ? nullptr : checkObject<TownBase>(L, 2, TownBaseBinding::getMetatableName());
    return 0;
}

static int Ownerships_set_money(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    instance->money = (int)luaL_checkinteger(L, 2);
    return 0;
}

int OwnershipsBinding::_CONSTRUCTOR(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");

    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    Platoon* p = checkObject<Platoon>(L, 3, PlatoonBinding::getMetatableName());
    Ownerships* result = instance->_CONSTRUCTOR(f, p);
    return pushObject<Ownerships>(L, result, OwnershipsBinding::getMetatableName());
}

int OwnershipsBinding::setHandle(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");

    Platoon* h = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    instance->setHandle(h);
    return 0;
}

int OwnershipsBinding::takeMoney(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");

    int val = (int)luaL_checkinteger(L, 2);
    bool result = instance->takeMoney(val);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int OwnershipsBinding::_NV_takeMoney(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");

    int val = (int)luaL_checkinteger(L, 2);
    bool result = instance->_NV_takeMoney(val);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int OwnershipsBinding::takeMoneyByForce(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");

    int val = (int)luaL_checkinteger(L, 2);
    instance->takeMoneyByForce(val);
    return 0;
}

int OwnershipsBinding::_NV_takeMoneyByForce(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");

    int val = (int)luaL_checkinteger(L, 2);
    instance->_NV_takeMoneyByForce(val);
    return 0;
}

int OwnershipsBinding::getMoney(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");

    int result = instance->getMoney();
    lua_pushinteger(L, result);
    return 1;
}

int OwnershipsBinding::addMoney(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");

    int amount = (int)luaL_checkinteger(L, 2);
    instance->addMoney(amount);
    return 0;
}

int OwnershipsBinding::setMoney(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");

    int amount = (int)luaL_checkinteger(L, 2);
    instance->setMoney(amount);
    return 0;
}

int OwnershipsBinding::setHomeBuildingDesignation(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");

    BuildingDesignation d = (BuildingDesignation)luaL_checkinteger(L, 2);
    instance->setHomeBuildingDesignation(d);
    return 0;
}

int OwnershipsBinding::copyFrom(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");

    Ownerships* other = checkObject<Ownerships>(L, 2, OwnershipsBinding::getMetatableName());
    instance->copyFrom(other);
    return 0;
}

int OwnershipsBinding::serialise(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->serialise(state);
    return 0;
}

int OwnershipsBinding::load(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    SquadType st = (SquadType)luaL_checkinteger(L, 3);
    instance->load(state, st);
    return 0;
}

int OwnershipsBinding::setHomeTown(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");

    TownBase* t = checkObject<TownBase>(L, 2, TownBaseBinding::getMetatableName());
    SquadType squadtype = (SquadType)luaL_checkinteger(L, 3);
    instance->setHomeTown(t, squadtype);
    return 0;
}

int OwnershipsBinding::isMyTown(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");

    TownBase* t = checkObject<TownBase>(L, 2, TownBaseBinding::getMetatableName());
    bool result = instance->isMyTown(t);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int OwnershipsBinding::canIUseThisBuilding(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");

    Building* b = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    Character* _me = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    bool result = instance->canIUseThisBuilding(b, _me);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int OwnershipsBinding::declareOccupiedTown(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");

    TownBase* t = checkObject<TownBase>(L, 2, TownBaseBinding::getMetatableName());
    instance->declareOccupiedTown(t);
    return 0;
}

int OwnershipsBinding::getOccupiedTownFaction(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");

    Faction* result = instance->getOccupiedTownFaction();
    return pushObject<Faction>(L, result, FactionBinding::getMetatableName());
}

int OwnershipsBinding::_DESTRUCTOR(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 42: void addOwnedObject(...) - non-string reference arg
  line 43: void removeOwnedObject(...) - non-string reference arg
  line 44: bool isOwned(...) - non-string reference arg
  line 60: void setHomeBuilding(...) - non-string reference arg
  line 61: void getOwnedBuildingsH(...) - unsupported arg type
  line 62: void getOwnedBuildingPtrs(...) - unsupported arg type
  line 64: void getHomeFurnitureOfType(...) - unsupported arg type
  line 65: int getOwnedPtrs(...) - unsupported arg type
  line 66: void getBuildingsWithFunction(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 54: slaves (std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 71: stuff (lektor<hand>) - unsupported type
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



static int Ownerships_get_slaves(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    // TODO: Unsupported type for slaves (std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'slaves' (type: std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy > >)");
}


static int Ownerships_get_stuff(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    // TODO: Unsupported type for stuff (lektor<hand>)
    return luaL_error(L, "Unsupported property 'stuff' (type: lektor<hand>)");
}


static int Ownerships_set_slaves(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    return luaL_error(L, "Read-only or unsupported setter type for slaves");
}


static int Ownerships_set_stuff(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    return luaL_error(L, "Read-only or unsupported setter type for stuff");
}


void OwnershipsBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       OwnershipsBinding::gc },
        { "__tostring", OwnershipsBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", OwnershipsBinding::_CONSTRUCTOR },
        { "setHandle", OwnershipsBinding::setHandle },
        { "takeMoney", OwnershipsBinding::takeMoney },
        { "_NV_takeMoney", OwnershipsBinding::_NV_takeMoney },
        { "takeMoneyByForce", OwnershipsBinding::takeMoneyByForce },
        { "_NV_takeMoneyByForce", OwnershipsBinding::_NV_takeMoneyByForce },
        { "getMoney", OwnershipsBinding::getMoney },
        { "addMoney", OwnershipsBinding::addMoney },
        { "setMoney", OwnershipsBinding::setMoney },
        { "setHomeBuildingDesignation", OwnershipsBinding::setHomeBuildingDesignation },
        { "copyFrom", OwnershipsBinding::copyFrom },
        { "serialise", OwnershipsBinding::serialise },
        { "load", OwnershipsBinding::load },
        { "setHomeTown", OwnershipsBinding::setHomeTown },
        { "isMyTown", OwnershipsBinding::isMyTown },
        { "canIUseThisBuilding", OwnershipsBinding::canIUseThisBuilding },
        { "declareOccupiedTown", OwnershipsBinding::declareOccupiedTown },
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
    registerGetter(L, "_homeTown", Ownerships_get__homeTown);
    registerGetter(L, "_homeBuilding", Ownerships_get__homeBuilding);
    registerGetter(L, "faction", Ownerships_get_faction);
    registerGetter(L, "me", Ownerships_get_me);
    registerGetter(L, "occupiedTown", Ownerships_get_occupiedTown);
    registerGetter(L, "money", Ownerships_get_money);
        registerGetter(L, "slaves", Ownerships_get_slaves);
        registerGetter(L, "stuff", Ownerships_get_stuff);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "_homeTown", Ownerships_set__homeTown);
    registerSetter(L, "_homeBuilding", Ownerships_set__homeBuilding);
    registerSetter(L, "faction", Ownerships_set_faction);
    registerSetter(L, "me", Ownerships_set_me);
    registerSetter(L, "occupiedTown", Ownerships_set_occupiedTown);
    registerSetter(L, "money", Ownerships_set_money);
        registerSetter(L, "slaves", Ownerships_set_slaves);
        registerSetter(L, "stuff", Ownerships_set_stuff);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua