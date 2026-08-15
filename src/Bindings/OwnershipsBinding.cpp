#include "pch.h"
#include "kenshi\Platoon.h"
#include "OwnershipsBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/Util/StdSetBinding.h"

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
    return HandBinding::push(L, instance->_homeBuilding);
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
    instance->_homeBuilding = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
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

int OwnershipsBinding::addOwnedObject(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    hand* what = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!what) return luaL_error(L, "Argument 2 to addOwnedObject must be a hand");
    instance->addOwnedObject(*what);
    return 0;
}

int OwnershipsBinding::removeOwnedObject(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    hand* what = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!what) return luaL_error(L, "Argument 2 to removeOwnedObject must be a hand");
    instance->removeOwnedObject(*what);
    return 0;
}

int OwnershipsBinding::isOwned(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    hand* what = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!what) return luaL_error(L, "Argument 2 to isOwned must be a hand");
    bool result = instance->isOwned(*what);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int OwnershipsBinding::setHomeBuilding(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 2 to setHomeBuilding must be a hand");
    SquadType t = (SquadType)luaL_checkinteger(L, 3);
    instance->setHomeBuilding(*h, t);
    return 0;
}

int OwnershipsBinding::getOwnedBuildingsH(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    lektor<hand>* out = LektorValueBinding<hand>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to getOwnedBuildingsH must be lektor<hand>");
    instance->getOwnedBuildingsH(*out);
    return 0;
}

int OwnershipsBinding::getOwnedBuildingPtrs(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    lektor<Building*>* out = LektorPtrBinding<Building*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to getOwnedBuildingPtrs must be lektor<Building*>");
    TownBase* town = lua_isnoneornil(L, 3) ? nullptr : checkObject<TownBase>(L, 3, TownBaseBinding::getMetatableName());
    instance->getOwnedBuildingPtrs(*out, town);
    return 0;
}

int OwnershipsBinding::getHomeFurnitureOfType(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    lektor<Building*>* out = LektorPtrBinding<Building*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to getHomeFurnitureOfType must be lektor<Building*>");
    BuildingFunction type = (BuildingFunction)luaL_checkinteger(L, 3);
    instance->getHomeFurnitureOfType(*out, type);
    return 0;
}

int OwnershipsBinding::getOwnedPtrs(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    lektor<RootObject*>* out = LektorPtrBinding<RootObject*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to getOwnedPtrs must be lektor<RootObject*>");
    itemType type = (itemType)luaL_checkinteger(L, 3);
    int result = instance->getOwnedPtrs(*out, type);
    lua_pushinteger(L, result);
    return 1;
}

int OwnershipsBinding::getBuildingsWithFunction(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    lektor<Building*>* out = LektorPtrBinding<Building*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to getBuildingsWithFunction must be lektor<Building*>");
    BuildingFunction bf = (BuildingFunction)luaL_checkinteger(L, 3);
    instance->getBuildingsWithFunction(*out, bf);
    return 0;
}

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
    return pushObject<std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy>>>(
        L, &instance->slaves, "std::set<hand>");
}


static int Ownerships_get_stuff(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    return pushObject<lektor<hand>>(
        L, &instance->stuff, LektorValueBinding<hand>::metaName);
}


static int Ownerships_set_slaves(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::GeneralAllocPolicy>>* src = 
        StdSetBinding<hand>::get(L, 2);
    if (!src) return luaL_error(L, "Expected std::set<hand>");
    instance->slaves = *src;
    return 0;
}


static int Ownerships_set_stuff(lua_State* L)
{
    Ownerships* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Ownerships is nil");
    lektor<hand>* src = LektorValueBinding<hand>::get(L, 2);
    if (!src) return luaL_error(L, "Expected lektor<hand>");
    instance->stuff = *src;
    return 0;
}


void OwnershipsBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       OwnershipsBinding::gc },
        { "__tostring", OwnershipsBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
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
        { "addOwnedObject", OwnershipsBinding::addOwnedObject },
        { "removeOwnedObject", OwnershipsBinding::removeOwnedObject },
        { "isOwned", OwnershipsBinding::isOwned },
        { "setHomeBuilding", OwnershipsBinding::setHomeBuilding },
        { "getOwnedBuildingsH", OwnershipsBinding::getOwnedBuildingsH },
        { "getOwnedBuildingPtrs", OwnershipsBinding::getOwnedBuildingPtrs },
        { "getHomeFurnitureOfType", OwnershipsBinding::getHomeFurnitureOfType },
        { "getOwnedPtrs", OwnershipsBinding::getOwnedPtrs },
        { "getBuildingsWithFunction", OwnershipsBinding::getBuildingsWithFunction },
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