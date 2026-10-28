#include "pch.h"
#include "kenshi/ZoneMapContent.h"
#include "ZoneMapContentBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Building/BuildingBinding.h"
#include "Bindings/Kenshi/FoliageSystemBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/GameDataContainerBinding.h"
#include "Bindings/Kenshi/GameSaveStateBinding.h"
#include "Bindings/Kenshi/ItemBinding.h"
#include "Bindings/Kenshi/RootObjectBinding.h"
#include "Bindings/Kenshi/TownBinding.h"
#include "Bindings/Kenshi/ZoneMapBinding.h"
#include "Bindings/Kenshi/HandleListBinding.h"
#include "Bindings/Kenshi/ZoneMapContent_HandleDummyBinding.h"
#include "Bindings/Kenshi/Util/iVector2Binding.h"

namespace KenshiLua
{

static_assert(offsetof(ZoneMapContent, periodicUpdateIndex) == 0x68, "ZoneMapContent::periodicUpdateIndex offset mismatch");
static_assert(offsetof(ZoneMapContent, myHandles) == 0x98, "ZoneMapContent::myHandles offset mismatch");
static_assert(offsetof(ZoneMapContent, handleDummy) == 0xA0, "ZoneMapContent::handleDummy offset mismatch");
static_assert(offsetof(ZoneMapContent, newGameFirstTimeLoaded) == 0xA8, "ZoneMapContent::newGameFirstTimeLoaded offset mismatch");
static_assert(offsetof(ZoneMapContent, toUpdateList) == 0xB8, "ZoneMapContent::toUpdateList offset mismatch");
static_assert(offsetof(ZoneMapContent, zoneMap) == 0xD0, "ZoneMapContent::zoneMap offset mismatch");
static_assert(offsetof(ZoneMapContent, loaded) == 0xD8, "ZoneMapContent::loaded offset mismatch");
static_assert(offsetof(ZoneMapContent, foliageSystem) == 0x100, "ZoneMapContent::foliageSystem offset mismatch");
static_assert(offsetof(ZoneMapContent, activationFlag) == 0x108, "ZoneMapContent::activationFlag offset mismatch");
static_assert(offsetof(ZoneMapContent, items) == 0x110, "ZoneMapContent::items offset mismatch");

static ZoneMapContent* getInstance(lua_State* L, int idx)
{
    return checkObject<ZoneMapContent>(L, idx, ZoneMapContentBinding::getMetatableName());
}

static int ZoneMapContent_get_periodicUpdateIndex(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    lua_pushinteger(L, instance->periodicUpdateIndex);
    return 1;
}

static int ZoneMapContent_set_periodicUpdateIndex(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    instance->periodicUpdateIndex = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int ZoneMapContent_get_myHandles(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    if (!instance->myHandles) { lua_pushnil(L); return 1; }
    return pushObject<HandleList>(L, instance->myHandles, HandleListBinding::getMetatableName());
}

static int ZoneMapContent_set_myHandles(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    instance->myHandles = lua_isnoneornil(L, 2) ? nullptr : checkObject<HandleList>(L, 2, HandleListBinding::getMetatableName());
    return 0;
}

static int ZoneMapContent_get_handleDummy(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    if (!instance->handleDummy) { lua_pushnil(L); return 1; }
    return pushObject<ZoneMapContent::HandleDummy>(L, instance->handleDummy, ZoneMapContent_HandleDummyBinding::getMetatableName());
}

static int ZoneMapContent_set_handleDummy(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    instance->handleDummy = lua_isnoneornil(L, 2) ? nullptr : checkObject<ZoneMapContent::HandleDummy>(L, 2, ZoneMapContent_HandleDummyBinding::getMetatableName());
    return 0;
}

static int ZoneMapContent_get_newGameFirstTimeLoaded(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    lua_pushboolean(L, instance->newGameFirstTimeLoaded ? 1 : 0);
    return 1;
}

static int ZoneMapContent_set_newGameFirstTimeLoaded(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    instance->newGameFirstTimeLoaded = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ZoneMapContent_get_toUpdateList(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    return pushObject<lektor<RootObject*>>(L, &instance->toUpdateList, "lektor<RootObject*>");
}

static int ZoneMapContent_get_zoneMap(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    if (!instance->zoneMap) { lua_pushnil(L); return 1; }
    return pushObject<ZoneMap>(L, instance->zoneMap, ZoneMapBinding::getMetatableName());
}

static int ZoneMapContent_set_zoneMap(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    instance->zoneMap = lua_isnoneornil(L, 2) ? nullptr : checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    return 0;
}

static int ZoneMapContent_get_loaded(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    lua_pushboolean(L, instance->loaded ? 1 : 0);
    return 1;
}

static int ZoneMapContent_set_loaded(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    instance->loaded = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ZoneMapContent_get_foliageSystem(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    if (!instance->foliageSystem) { lua_pushnil(L); return 1; }
    return pushObject<FoliageSystem>(L, instance->foliageSystem, FoliageSystemBinding::getMetatableName());
}

static int ZoneMapContent_set_foliageSystem(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    instance->foliageSystem = lua_isnoneornil(L, 2) ? nullptr : checkObject<FoliageSystem>(L, 2, FoliageSystemBinding::getMetatableName());
    return 0;
}

static int ZoneMapContent_get_activationFlag(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    lua_pushboolean(L, instance->activationFlag ? 1 : 0);
    return 1;
}

static int ZoneMapContent_set_activationFlag(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    instance->activationFlag = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ZoneMapContent_get_items(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    return pushObject<ogre_unordered_set<hand>::type>(L, &instance->items, "ogre_unordered_set<hand>");
}

int ZoneMapContentBinding::isLoadedT(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    bool result = instance->isLoadedT();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneMapContentBinding::update(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    bool result = instance->update();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneMapContentBinding::_NV_update(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    bool result = instance->_NV_update();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneMapContentBinding::threadedUpdate(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    instance->threadedUpdate();
    return 0;
}

int ZoneMapContentBinding::addToUpdateList(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    RootObject* b = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->addToUpdateList(b);
    return 0;
}

int ZoneMapContentBinding::_reloadAllFoliage(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    instance->_reloadAllFoliage();
    return 0;
}

int ZoneMapContentBinding::getOverlayPixelCoord(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    iVector2 result = instance->getOverlayPixelCoord();
    return pushValue<iVector2>(L, result, iVector2Binding::getMetatableName());
}

int ZoneMapContentBinding::clearOverlay(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    int channel = (int)luaL_checkinteger(L, 2);
    instance->clearOverlay(channel);
    return 0;
}

int ZoneMapContentBinding::generateDirtMap(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    int channel = (int)luaL_checkinteger(L, 2);
    int result = instance->generateDirtMap(channel);
    lua_pushinteger(L, result);
    return 1;
}

int ZoneMapContentBinding::addLoadedBuilding(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    GameSaveState* buildingInstanceData = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    bool isActiveLevelFile = lua_toboolean(L, 3) != 0;
    instance->addLoadedBuilding(buildingInstanceData, isActiveLevelFile);
    return 0;
}

int ZoneMapContentBinding::loadItems(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    GameDataContainer* source = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    bool result = instance->loadItems(source);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneMapContentBinding::saveItems(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    GameDataContainer* dest = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    bool allItems = lua_toboolean(L, 3) != 0;
    instance->saveItems(dest, allItems);
    return 0;
}

int ZoneMapContentBinding::saveLevelData(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    bool all = lua_toboolean(L, 2) != 0;
    std::string modName = luaL_checkstring(L, 3);
    std::string pathOverride = luaL_checkstring(L, 4);
    instance->saveLevelData(all, modName, pathOverride);
    return 0;
}

int ZoneMapContentBinding::saveToDisk(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    std::string path = luaL_checkstring(L, 2);
    instance->saveToDisk(path);
    return 0;
}

int ZoneMapContentBinding::activate(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    instance->activate();
    return 0;
}

int ZoneMapContentBinding::deactivate(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    bool saveZoneState = lua_toboolean(L, 2) != 0;
    instance->deactivate(saveZoneState);
    return 0;
}

int ZoneMapContentBinding::reFactionBuildingsFromTown(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    instance->reFactionBuildingsFromTown();
    return 0;
}

int ZoneMapContentBinding::updateItemsVisibility(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    instance->updateItemsVisibility();
    return 0;
}

int ZoneMapContentBinding::_setEnabledStaticGeometry(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    bool enable = lua_toboolean(L, 2) != 0;
    instance->_setEnabledStaticGeometry(enable);
    return 0;
}

int ZoneMapContentBinding::findBuildingTypePublic(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    Town* t = checkObject<Town>(L, 2, TownBinding::getMetatableName());
    Building* result = instance->findBuildingTypePublic(t);
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}

int ZoneMapContentBinding::findBuildingByDataPosition(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    float x = (float)luaL_checknumber(L, 3);
    float z = (float)luaL_checknumber(L, 4);
    Building* result = instance->findBuildingByDataPosition(data, x, z);
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}

int ZoneMapContentBinding::_populateTownsOnNewGame(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    instance->_populateTownsOnNewGame();
    return 0;
}

int ZoneMapContentBinding::forceLoadAllTheBuildingInteriorVisuals(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    instance->forceLoadAllTheBuildingInteriorVisuals();
    return 0;
}

int ZoneMapContentBinding::addItem(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    instance->addItem(item);
    return 0;
}

int ZoneMapContentBinding::removeItem(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    instance->removeItem(item);
    return 0;
}

int ZoneMapContentBinding::changeItemZone(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    ZoneMap* moveTo = checkObject<ZoneMap>(L, 3, ZoneMapBinding::getMetatableName());
    bool result = instance->changeItemZone(item, moveTo);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneMapContentBinding::removeObject(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = instance->removeObject(obj);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneMapContentBinding::_NV_removeObject(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = instance->_NV_removeObject(obj);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneMapContentBinding::getFoliageSystem(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    const FoliageSystem* result = instance->getFoliageSystem();
    return pushObject<FoliageSystem>(L, const_cast<FoliageSystem*>(result), FoliageSystemBinding::getMetatableName());
}

int ZoneMapContentBinding::_activate(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    instance->_activate();
    return 0;
}

int ZoneMapContentBinding::createLoadedItems(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    instance->createLoadedItems();
    return 0;
}

int ZoneMapContentBinding::setLoadedT(lua_State* L)
{
    ZoneMapContent* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneMapContent is nil");
    bool t = lua_toboolean(L, 2) != 0;
    instance->setLoadedT(t);
    return 0;
}

int ZoneMapContentBinding::gc(lua_State* L)
{
    return 0;
}

int ZoneMapContentBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ZoneMapContent object");
    return 1;
}

void ZoneMapContentBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ZoneMapContentBinding::gc },
        { "__tostring", ZoneMapContentBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "isLoadedT", ZoneMapContentBinding::isLoadedT },
        { "update", ZoneMapContentBinding::update },
        { "_NV_update", ZoneMapContentBinding::_NV_update },
        { "threadedUpdate", ZoneMapContentBinding::threadedUpdate },
        { "addToUpdateList", ZoneMapContentBinding::addToUpdateList },
        { "_reloadAllFoliage", ZoneMapContentBinding::_reloadAllFoliage },
        { "getOverlayPixelCoord", ZoneMapContentBinding::getOverlayPixelCoord },
        { "clearOverlay", ZoneMapContentBinding::clearOverlay },
        { "generateDirtMap", ZoneMapContentBinding::generateDirtMap },
        { "addLoadedBuilding", ZoneMapContentBinding::addLoadedBuilding },
        { "loadItems", ZoneMapContentBinding::loadItems },
        { "saveItems", ZoneMapContentBinding::saveItems },
        { "saveLevelData", ZoneMapContentBinding::saveLevelData },
        { "saveToDisk", ZoneMapContentBinding::saveToDisk },
        { "activate", ZoneMapContentBinding::activate },
        { "deactivate", ZoneMapContentBinding::deactivate },
        { "reFactionBuildingsFromTown", ZoneMapContentBinding::reFactionBuildingsFromTown },
        { "updateItemsVisibility", ZoneMapContentBinding::updateItemsVisibility },
        { "_setEnabledStaticGeometry", ZoneMapContentBinding::_setEnabledStaticGeometry },
        { "findBuildingTypePublic", ZoneMapContentBinding::findBuildingTypePublic },
        { "findBuildingByDataPosition", ZoneMapContentBinding::findBuildingByDataPosition },
        { "_populateTownsOnNewGame", ZoneMapContentBinding::_populateTownsOnNewGame },
        { "forceLoadAllTheBuildingInteriorVisuals", ZoneMapContentBinding::forceLoadAllTheBuildingInteriorVisuals },
        { "addItem", ZoneMapContentBinding::addItem },
        { "removeItem", ZoneMapContentBinding::removeItem },
        { "changeItemZone", ZoneMapContentBinding::changeItemZone },
        { "removeObject", ZoneMapContentBinding::removeObject },
        { "_NV_removeObject", ZoneMapContentBinding::_NV_removeObject },
        { "getFoliageSystem", ZoneMapContentBinding::getFoliageSystem },
        { "_activate", ZoneMapContentBinding::_activate },
        { "createLoadedItems", ZoneMapContentBinding::createLoadedItems },
        { "setLoadedT", ZoneMapContentBinding::setLoadedT },
        { 0, 0 }
    };

    registerClass(
        L,
        ZoneMapContentBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ZoneMapContentBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "periodicUpdateIndex", ZoneMapContent_get_periodicUpdateIndex);
    registerGetter(L, "myHandles", ZoneMapContent_get_myHandles);
    registerGetter(L, "handleDummy", ZoneMapContent_get_handleDummy);
    registerGetter(L, "newGameFirstTimeLoaded", ZoneMapContent_get_newGameFirstTimeLoaded);
    registerGetter(L, "toUpdateList", ZoneMapContent_get_toUpdateList);
    registerGetter(L, "zoneMap", ZoneMapContent_get_zoneMap);
    registerGetter(L, "loaded", ZoneMapContent_get_loaded);
    registerGetter(L, "foliageSystem", ZoneMapContent_get_foliageSystem);
    registerGetter(L, "activationFlag", ZoneMapContent_get_activationFlag);
    registerGetter(L, "items", ZoneMapContent_get_items);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "periodicUpdateIndex", ZoneMapContent_set_periodicUpdateIndex);
    registerSetter(L, "myHandles", ZoneMapContent_set_myHandles);
    registerSetter(L, "handleDummy", ZoneMapContent_set_handleDummy);
    registerSetter(L, "newGameFirstTimeLoaded", ZoneMapContent_set_newGameFirstTimeLoaded);
    registerSetter(L, "zoneMap", ZoneMapContent_set_zoneMap);
    registerSetter(L, "loaded", ZoneMapContent_set_loaded);
    registerSetter(L, "foliageSystem", ZoneMapContent_set_foliageSystem);
    registerSetter(L, "activationFlag", ZoneMapContent_set_activationFlag);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
