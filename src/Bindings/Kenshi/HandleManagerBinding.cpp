#include "pch.h"
#include "kenshi/HandleManager.h"
#include "HandleManagerBinding.h"
#include "SerialisableBinding.h"
#include "PlatoonHandleContainerListBinding.h"
#include "ZoneMapHandleContainerListBinding.h"
#include "TownHandleContainerListBinding.h"
#include "ItemHandleListBinding.h"
#include "HandleContainerListBinding.h"
#include "Bindings/Kenshi/RootObjectBaseBinding.h"
#include "Bindings/Kenshi/RootObjectBinding.h"
#include "Bindings/Kenshi/TownBaseBinding.h"
#include "Bindings/Kenshi/TownBinding.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/Building/BuildingBinding.h"
#include "Bindings/Kenshi/Building/UseableStuffBinding.h"
#include "Bindings/Kenshi/PlatoonBinding.h"
#include "Bindings/Kenshi/ItemBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/OgreUnorderedBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(offsetof(HandleManager, platoons) == 0x8, "HandleManager::platoons offset mismatch");
static_assert(offsetof(HandleManager, zones) == 0x20, "HandleManager::zones offset mismatch");
static_assert(offsetof(HandleManager, towns) == 0x38, "HandleManager::towns offset mismatch");
static_assert(offsetof(HandleManager, items) == 0x50, "HandleManager::items offset mismatch");
static_assert(offsetof(HandleManager, nodes) == 0xB0, "HandleManager::nodes offset mismatch");
static_assert(offsetof(HandleManager, mapfeatures) == 0x110, "HandleManager::mapfeatures offset mismatch");
static_assert(offsetof(HandleManager, redirect) == 0x128, "HandleManager::redirect offset mismatch");

typedef OgreUnorderedMapBinding<hand, hand> HandHandMapBinding;

static HandleManager* getInstance(lua_State* L, int idx)
{
    return checkObject<HandleManager>(L, idx, HandleManagerBinding::getMetatableName());
}

static int HandleManager_get_platoons(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    return pushObject<PlatoonHandleContainerList>(L, &instance->platoons, PlatoonHandleContainerListBinding::getMetatableName());
}

static int HandleManager_get_zones(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    return pushObject<ZoneMapHandleContainerList>(L, &instance->zones, ZoneMapHandleContainerListBinding::getMetatableName());
}

static int HandleManager_get_towns(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    return pushObject<TownHandleContainerList>(L, &instance->towns, TownHandleContainerListBinding::getMetatableName());
}

static int HandleManager_get_items(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    return pushObject<ItemHandleList>(L, &instance->items, ItemHandleListBinding::getMetatableName());
}

static int HandleManager_get_nodes(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    return pushObject<ItemHandleList>(L, &instance->nodes, ItemHandleListBinding::getMetatableName());
}

static int HandleManager_get_mapfeatures(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    return pushObject<HandleContainerList>(L, &instance->mapfeatures, HandleContainerListBinding::getMetatableName());
}

static int HandleManager_get_redirect(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    return pushObject<HandHandMapBinding::MapType>(L, &instance->redirect, "ogre_unordered_map<hand, hand>");
}

static int HandleManager_set_redirect(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    auto* val = HandHandMapBinding::getInstance(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set redirect must be ogre_unordered_map<hand, hand>");
    instance->redirect = *val;
    return 0;
}

int HandleManagerBinding::getRedirect(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    const hand& res = instance->getRedirect(*h);
    return HandBinding::push(L, res);
}

int HandleManagerBinding::removeRedirect(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    instance->removeRedirect(*h);
    return 0;
}

int HandleManagerBinding::clearRedirectForHandle(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    instance->clearRedirectForHandle(*h);
    return 0;
}

int HandleManagerBinding::reset(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    instance->reset();
    return 0;
}

int HandleManagerBinding::setUnloaded(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    instance->setUnloaded(*h);
    return 0;
}

int HandleManagerBinding::destroy(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    const char* reason = luaL_optstring(L, 3, "");
    instance->destroy(*h, reason);
    return 0;
}

int HandleManagerBinding::getAnything(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    bool deadOnes = lua_toboolean(L, 3) != 0;
    RootObjectBase* res = instance->getAnything(*h, deadOnes);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<RootObjectBase>(L, res, RootObjectBaseBinding::getMetatableName());
}

int HandleManagerBinding::getTownBase(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    Ogre::Vector3 backupPos = Ogre::Vector3::ZERO;
    if (!lua_isnoneornil(L, 3))
    {
        readVector3(L, 3, backupPos);
    }
    TownBase* res = instance->getTownBase(*h, backupPos);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<TownBase>(L, res, TownBaseBinding::getMetatableName());
}

int HandleManagerBinding::getTown(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    Ogre::Vector3 backupPos = Ogre::Vector3::ZERO;
    if (!lua_isnoneornil(L, 3))
    {
        readVector3(L, 3, backupPos);
    }
    Town* res = instance->getTown(*h, backupPos);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<Town>(L, res, TownBinding::getMetatableName());
}

int HandleManagerBinding::getAnythingButBase(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    bool deadOnes = lua_toboolean(L, 3) != 0;
    RootObject* res = instance->getAnythingButBase(*h, deadOnes);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<RootObject>(L, res, RootObjectBinding::getMetatableName());
}

int HandleManagerBinding::getShopTrader(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    Character* res = instance->getShopTrader(*h);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<Character>(L, res, CharacterBinding::getMetatableName());
}

int HandleManagerBinding::getBuilding(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    Building* res = instance->getBuilding(*h);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<Building>(L, res, BuildingBinding::getMetatableName());
}

int HandleManagerBinding::getBuilding_UseableStuff(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    UseableStuff* res = instance->getBuilding_UseableStuff(*h);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<UseableStuff>(L, res, UseableStuffBinding::getMetatableName());
}

int HandleManagerBinding::getCharacter(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    bool deadOnes = lua_toboolean(L, 3) != 0;
    bool redirect = lua_isnoneornil(L, 4) ? true : (lua_toboolean(L, 4) != 0);
    Character* res = instance->getCharacter(*h, deadOnes, redirect);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<Character>(L, res, CharacterBinding::getMetatableName());
}

int HandleManagerBinding::getPlatoon(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    Platoon* res = instance->getPlatoon(*h);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<Platoon>(L, res, PlatoonBinding::getMetatableName());
}

int HandleManagerBinding::getItem(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    Item* res = instance->getItem(*h);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<Item>(L, res, ItemBinding::getMetatableName());
}

int HandleManagerBinding::isPlayerFaction(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    bool res = instance->isPlayerFaction(*h);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int HandleManagerBinding::addExistingObjectHandleToZone(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    bool res = instance->addExistingObjectHandleToZone(*h);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int HandleManagerBinding::getFromDeathParade(lua_State* L)
{
    HandleManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleManager is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    Character* res = instance->getFromDeathParade(*h);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<Character>(L, res, CharacterBinding::getMetatableName());
}

int HandleManagerBinding::gc(lua_State* L)
{
    return 0;
}

int HandleManagerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.HandleManager object");
    return 1;
}

void HandleManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       HandleManagerBinding::gc },
        { "__tostring", HandleManagerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getRedirect", HandleManagerBinding::getRedirect },
        { "removeRedirect", HandleManagerBinding::removeRedirect },
        { "clearRedirectForHandle", HandleManagerBinding::clearRedirectForHandle },
        { "reset", HandleManagerBinding::reset },
        { "setUnloaded", HandleManagerBinding::setUnloaded },
        { "destroy", HandleManagerBinding::destroy },
        { "getAnything", HandleManagerBinding::getAnything },
        { "getTownBase", HandleManagerBinding::getTownBase },
        { "getTown", HandleManagerBinding::getTown },
        { "getAnythingButBase", HandleManagerBinding::getAnythingButBase },
        { "getShopTrader", HandleManagerBinding::getShopTrader },
        { "getBuilding", HandleManagerBinding::getBuilding },
        { "getBuilding_UseableStuff", HandleManagerBinding::getBuilding_UseableStuff },
        { "getCharacter", HandleManagerBinding::getCharacter },
        { "getPlatoon", HandleManagerBinding::getPlatoon },
        { "getItem", HandleManagerBinding::getItem },
        { "isPlayerFaction", HandleManagerBinding::isPlayerFaction },
        { "addExistingObjectHandleToZone", HandleManagerBinding::addExistingObjectHandleToZone },
        { "getFromDeathParade", HandleManagerBinding::getFromDeathParade },
        { 0, 0 }
    };

    registerClass(
        L,
        HandleManagerBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, HandleManagerBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "platoons", HandleManager_get_platoons);
    registerGetter(L, "zones", HandleManager_get_zones);
    registerGetter(L, "towns", HandleManager_get_towns);
    registerGetter(L, "items", HandleManager_get_items);
    registerGetter(L, "nodes", HandleManager_get_nodes);
    registerGetter(L, "mapfeatures", HandleManager_get_mapfeatures);
    registerGetter(L, "redirect", HandleManager_get_redirect);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "redirect", HandleManager_set_redirect);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);

}

} // namespace KenshiLua

