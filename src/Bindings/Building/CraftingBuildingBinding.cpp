#include "pch.h"
class CraftingItem {};
class Layout {};
#include <kenshi/Building/CraftingBuilding.h>
#include "CraftingBuildingBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/Building/ProductionBuildingBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/Gui/InventoryLayoutBinding.h"
#include "Bindings/Building/GameDataGroupBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/Util/YesNoMaybeBinding.h"
#include "Bindings/Util/StdDequeBinding.h"
#include <kenshi/GameSaveState.h>

namespace KenshiLua
{
typedef StdDequeValueBinding<CraftingItem> CraftingItemDequeBinding;


static CraftingBuilding* getInstance(lua_State* L, int idx)
{
    return checkObject<CraftingBuilding>(L, idx, CraftingBuildingBinding::getMetatableName());
}

// --- Getters for CraftingBuilding ---
static int CraftingBuilding_get_maxCraftLevel(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    lua_pushinteger(L, instance->maxCraftLevel);
    return 1;
}

static int CraftingBuilding_get_crafting(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    return pushObject<CraftingItemDequeBinding::DequeType>(L, &instance->crafting, "std::deque<CraftingItem>");
}

static int CraftingBuilding_get_specialCraftItemType(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    lua_pushinteger(L, (lua_Integer)instance->specialCraftItemType);
    return 1;
}

static int CraftingBuilding_get_repeat(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    lua_pushboolean(L, instance->repeat ? 1 : 0);
    return 1;
}

static int CraftingBuilding_get_whosCrafting(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    return HandBinding::push(L, instance->whosCrafting);
}

static int CraftingBuilding_get_itemCrafted(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    lua_pushboolean(L, instance->itemCrafted ? 1 : 0);
    return 1;
}

static int CraftingBuilding_get_failiureNotified(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    lua_pushboolean(L, instance->failiureNotified ? 1 : 0);
    return 1;
}

static int CraftingBuilding_get_biggestCraftableItem(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    return pushObject<GameData>(L, instance->biggestCraftableItem, GameDataBinding::getMetatableName());
}

static int CraftingBuilding_get_outItem(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    return pushObject<Item>(L, instance->outItem, ItemBinding::getMetatableName());
}

static int CraftingBuilding_get_inItems(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    return pushObject<lektor<Item*>>(L, &instance->inItems, LektorPtrBinding<Item*>::metaName);
}

static int CraftingBuilding_get_partialItems(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    return pushObject<ogre_unordered_map<GameData*, float>::type>(
        L, &instance->partialItems, OgreUnorderedMapBinding<GameData*, float>::getMetatableName());
}

// --- Setters for CraftingBuilding ---
static int CraftingBuilding_set_maxCraftLevel(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    instance->maxCraftLevel = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int CraftingBuilding_set_crafting(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    if (lua_isnoneornil(L, 2))
    {
        instance->crafting.clear();
        return 0;
    }
    auto* src = CraftingItemDequeBinding::get(L, 2);
    if (!src) return luaL_error(L, "Argument 2 to set crafting must be std::deque<CraftingItem>");
    instance->crafting = *src;
    return 0;
}

static int CraftingBuilding_set_specialCraftItemType(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    instance->specialCraftItemType = (itemType)luaL_checkinteger(L, 2);
    return 0;
}

static int CraftingBuilding_set_repeat(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    instance->repeat = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CraftingBuilding_set_whosCrafting(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    hand* val = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    instance->whosCrafting = *val;
    return 0;
}

static int CraftingBuilding_set_itemCrafted(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    instance->itemCrafted = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CraftingBuilding_set_failiureNotified(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    instance->failiureNotified = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CraftingBuilding_set_biggestCraftableItem(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    instance->biggestCraftableItem = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int CraftingBuilding_set_outItem(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    instance->outItem = lua_isnoneornil(L, 2) ? nullptr : checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    return 0;
}

static int CraftingBuilding_set_inItems(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    lektor<Item*>* val = LektorPtrBinding<Item*>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'inItems' must be lektor<Item*>");
    instance->inItems = *val;
    return 0;
}

static int CraftingBuilding_set_partialItems(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");
    ogre_unordered_map<GameData*, float>::type* val = OgreUnorderedMapBinding<GameData*, float>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'partialItems' must be ogre_unordered_map<GameData*, float>");
    instance->partialItems = *val;
    return 0;
}

int CraftingBuildingBinding::createInventoryLayout(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    InventoryLayout* result = instance->createInventoryLayout();
    return pushObject<InventoryLayout>(L, result, InventoryLayoutBinding::getMetatableName());
}

int CraftingBuildingBinding::_NV_createInventoryLayout(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    InventoryLayout* result = instance->_NV_createInventoryLayout();
    return pushObject<InventoryLayout>(L, result, InventoryLayoutBinding::getMetatableName());
}

int CraftingBuildingBinding::update(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    instance->update();
    return 0;
}

int CraftingBuildingBinding::_NV_update(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    instance->_NV_update();
    return 0;
}

int CraftingBuildingBinding::operate(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    Character* stats = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float amount = (float)luaL_checknumber(L, 3);
    instance->operate(stats, amount);
    return 0;
}

int CraftingBuildingBinding::_NV_operate(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    Character* stats = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float amount = (float)luaL_checknumber(L, 3);
    instance->_NV_operate(stats, amount);
    return 0;
}

int CraftingBuildingBinding::givePower(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    float amount = (float)luaL_checknumber(L, 2);
    instance->givePower(amount);
    return 0;
}

int CraftingBuildingBinding::_NV_givePower(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    float amount = (float)luaL_checknumber(L, 2);
    instance->_NV_givePower(amount);
    return 0;
}

int CraftingBuildingBinding::getGUIData(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIData(datapanel, category);
    return 0;
}

int CraftingBuildingBinding::_NV_getGUIData(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIData(datapanel, category);
    return 0;
}

int CraftingBuildingBinding::serialise(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* refList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    PosRotPair* offset = (PosRotPair*)lua_touserdata(L, 4);

    GameSaveState result = instance->serialise(container, refList, offset);
    return pushValue<GameSaveState>(L, result, GameSaveStateBinding::getMetatableName());
}

int CraftingBuildingBinding::_NV_serialise(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* refList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    PosRotPair* offset = (PosRotPair*)lua_touserdata(L, 4);

    GameSaveState result = instance->_NV_serialise(container, refList, offset);
    return pushValue<GameSaveState>(L, result, GameSaveStateBinding::getMetatableName());
}

int CraftingBuildingBinding::loadFromSerialise(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    GameSaveState* wholeState = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->loadFromSerialise(wholeState);
    return 0;
}

int CraftingBuildingBinding::_NV_loadFromSerialise(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    GameSaveState* wholeState = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->_NV_loadFromSerialise(wholeState);
    return 0;
}

int CraftingBuildingBinding::hasCraftingQueued(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    bool result = instance->hasCraftingQueued();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CraftingBuildingBinding::_NV_hasCraftingQueued(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    bool result = instance->_NV_hasCraftingQueued();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CraftingBuildingBinding::isProductionFull(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    bool result = instance->isProductionFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CraftingBuildingBinding::_NV_isProductionFull(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    bool result = instance->_NV_isProductionFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CraftingBuildingBinding::getProductionItemData(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    GameData* result = instance->getProductionItemData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int CraftingBuildingBinding::_NV_getProductionItemData(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    GameData* result = instance->_NV_getProductionItemData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int CraftingBuildingBinding::getCurrentProductionQuantity(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    int result = instance->getCurrentProductionQuantity();
    lua_pushinteger(L, result);
    return 1;
}

int CraftingBuildingBinding::_NV_getCurrentProductionQuantity(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    int result = instance->_NV_getCurrentProductionQuantity();
    lua_pushinteger(L, result);
    return 1;
}

int CraftingBuildingBinding::isAnyInputsInvalidType(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    bool result = instance->isAnyInputsInvalidType();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CraftingBuildingBinding::_NV_isAnyInputsInvalidType(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    bool result = instance->_NV_isAnyInputsInvalidType();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CraftingBuildingBinding::newCraftingButton(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    MyGUI::Widget* sender = (MyGUI::Widget*)lua_touserdata(L, 2);
    instance->newCraftingButton(sender);
    return 0;
}

int CraftingBuildingBinding::_NV_newCraftingButton(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    MyGUI::Widget* sender = (MyGUI::Widget*)lua_touserdata(L, 2);
    instance->_NV_newCraftingButton(sender);
    return 0;
}

int CraftingBuildingBinding::addFinishedCraftItem(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    Item* what = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    instance->addFinishedCraftItem(what);
    return 0;
}

int CraftingBuildingBinding::notifyCraftFailiure(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    instance->notifyCraftFailiure();
    return 0;
}

int CraftingBuildingBinding::tryOperate(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool result = instance->tryOperate(*h);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CraftingBuildingBinding::_NV_tryOperate(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    bool result = instance->_NV_tryOperate(*h);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CraftingBuildingBinding::playerManufacturerData(lua_State* L)
{
    GameData* result = CraftingBuilding::playerManufacturerData();
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int CraftingBuildingBinding::getAvailableCrafts(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    lektor<GameDataGroup>* out = LektorValueReadOnlyBinding<GameDataGroup>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to getAvailableCrafts must be lektor<GameDataGroup>");
    instance->getAvailableCrafts(*out);
    return 0;
}

int CraftingBuildingBinding::_addCraft(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    GameData* basedata = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* matdata = lua_isnoneornil(L, 3) ? nullptr : checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    float progress = (float)luaL_checknumber(L, 4);
    YesNoMaybe crit = (YesNoMaybe)(int)luaL_checkinteger(L, 5);

    CraftingItem* result = instance->_addCraft(basedata, matdata, progress, crit);
    if (result) {
        lua_pushlightuserdata(L, (void*)result);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

int CraftingBuildingBinding::_removeCraft(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    int index = (int)luaL_checkinteger(L, 2);
    instance->_removeCraft(index);
    return 0;
}

int CraftingBuildingBinding::getCraft(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    int id = (int)luaL_checkinteger(L, 2);
    CraftingItem* result = instance->getCraft(id);
    if (result) {
        lua_pushlightuserdata(L, (void*)result);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

int CraftingBuildingBinding::destroyProductionItem(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    instance->destroyProductionItem();
    return 0;
}

int CraftingBuildingBinding::predictCraftersBestWeapon(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    hand* who = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    int levelcap = (int)luaL_checkinteger(L, 3);
    GameData* result = instance->predictCraftersBestWeapon(*who, levelcap);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int CraftingBuildingBinding::calculateCriticalChance(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    Character* smith = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float result = instance->calculateCriticalChance(smith);
    lua_pushnumber(L, result);
    return 1;
}

int CraftingBuildingBinding::getCriticalSuccessWeapon(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    int normalWeaponLevel = (int)luaL_checkinteger(L, 2);
    GameData* result = instance->getCriticalSuccessWeapon(normalWeaponLevel);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int CraftingBuildingBinding::getItemsWeWantRidOf(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    lektor<GameData*>* out = LektorPtrBinding<GameData*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to getItemsWeWantRidOf must be lektor<GameData*>");
    bool looting = lua_toboolean(L, 3) != 0;
    instance->getItemsWeWantRidOf(*out, looting);
    return 0;
}

int CraftingBuildingBinding::_NV_getItemsWeWantRidOf(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    lektor<GameData*>* out = LektorPtrBinding<GameData*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 to _NV_getItemsWeWantRidOf must be lektor<GameData*>");
    bool looting = lua_toboolean(L, 3) != 0;
    instance->_NV_getItemsWeWantRidOf(*out, looting);
    return 0;
}

int CraftingBuildingBinding::canHaveSomeOfThese(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    GameData* these = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->canHaveSomeOfThese(these);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CraftingBuildingBinding::_NV_canHaveSomeOfThese(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    GameData* these = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->_NV_canHaveSomeOfThese(these);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CraftingBuildingBinding::setupFromData(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    instance->setupFromData();
    return 0;
}

int CraftingBuildingBinding::_NV_setupFromData(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    instance->_NV_setupFromData();
    return 0;
}

int CraftingBuildingBinding::updateOutput(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    instance->updateOutput(rate);
    return 0;
}

int CraftingBuildingBinding::_NV_updateOutput(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    instance->_NV_updateOutput(rate);
    return 0;
}

int CraftingBuildingBinding::getPlayerCraftedWeaponLevel(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    GameData* matspec = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    float result = instance->getPlayerCraftedWeaponLevel(matspec);
    lua_pushnumber(L, result);
    return 1;
}

int CraftingBuildingBinding::getGUIState(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIState(datapanel, category);
    return 0;
}

int CraftingBuildingBinding::_NV_getGUIState(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIState(datapanel, category);
    return 0;
}

int CraftingBuildingBinding::updateInventoryWindow(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    instance->updateInventoryWindow();
    return 0;
}

int CraftingBuildingBinding::_NV_updateInventoryWindow(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    instance->_NV_updateInventoryWindow();
    return 0;
}

int CraftingBuildingBinding::setProductionItem(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    GameData* itemData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int stack = (int)luaL_checkinteger(L, 3);
    float progress01 = (float)luaL_checknumber(L, 4);
    instance->setProductionItem(itemData, stack, progress01);
    return 0;
}

int CraftingBuildingBinding::_NV_setProductionItem(lua_State* L)
{
    CraftingBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CraftingBuilding is nil");

    GameData* itemData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    int stack = (int)luaL_checkinteger(L, 3);
    float progress01 = (float)luaL_checknumber(L, 4);
    instance->_NV_setProductionItem(itemData, stack, progress01);
    return 0;
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - CraftingBuildingBinding::getCraft / CraftingBuildingBinding::_addCraft: CraftingItem* (opaque struct without metatable)
  - CraftingBuildingBinding::newCraftingButton / CraftingBuildingBinding::_NV_newCraftingButton: MyGUI::Widget* (unbound pointer)
*/

int CraftingBuildingBinding::gc(lua_State* L)
{
    return 0;
}

int CraftingBuildingBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CraftingBuilding object");
    return 1;
}

void CraftingBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CraftingBuildingBinding::gc },
        { "__tostring", CraftingBuildingBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "createInventoryLayout", CraftingBuildingBinding::createInventoryLayout },
        { "_NV_createInventoryLayout", CraftingBuildingBinding::_NV_createInventoryLayout },
        { "update", CraftingBuildingBinding::update },
        { "_NV_update", CraftingBuildingBinding::_NV_update },
        { "operate", CraftingBuildingBinding::operate },
        { "_NV_operate", CraftingBuildingBinding::_NV_operate },
        { "givePower", CraftingBuildingBinding::givePower },
        { "_NV_givePower", CraftingBuildingBinding::_NV_givePower },
        { "getGUIData", CraftingBuildingBinding::getGUIData },
        { "_NV_getGUIData", CraftingBuildingBinding::_NV_getGUIData },
        { "serialise", CraftingBuildingBinding::serialise },
        { "_NV_serialise", CraftingBuildingBinding::_NV_serialise },
        { "loadFromSerialise", CraftingBuildingBinding::loadFromSerialise },
        { "_NV_loadFromSerialise", CraftingBuildingBinding::_NV_loadFromSerialise },
        { "hasCraftingQueued", CraftingBuildingBinding::hasCraftingQueued },
        { "_NV_hasCraftingQueued", CraftingBuildingBinding::_NV_hasCraftingQueued },
        { "isProductionFull", CraftingBuildingBinding::isProductionFull },
        { "_NV_isProductionFull", CraftingBuildingBinding::_NV_isProductionFull },
        { "getProductionItemData", CraftingBuildingBinding::getProductionItemData },
        { "_NV_getProductionItemData", CraftingBuildingBinding::_NV_getProductionItemData },
        { "getCurrentProductionQuantity", CraftingBuildingBinding::getCurrentProductionQuantity },
        { "_NV_getCurrentProductionQuantity", CraftingBuildingBinding::_NV_getCurrentProductionQuantity },
        { "isAnyInputsInvalidType", CraftingBuildingBinding::isAnyInputsInvalidType },
        { "_NV_isAnyInputsInvalidType", CraftingBuildingBinding::_NV_isAnyInputsInvalidType },
        { "newCraftingButton", CraftingBuildingBinding::newCraftingButton },
        { "_NV_newCraftingButton", CraftingBuildingBinding::_NV_newCraftingButton },
        { "addFinishedCraftItem", CraftingBuildingBinding::addFinishedCraftItem },
        { "notifyCraftFailiure", CraftingBuildingBinding::notifyCraftFailiure },
        { "tryOperate", CraftingBuildingBinding::tryOperate },
        { "_NV_tryOperate", CraftingBuildingBinding::_NV_tryOperate },
        { "playerManufacturerData", CraftingBuildingBinding::playerManufacturerData },
        { "getAvailableCrafts", CraftingBuildingBinding::getAvailableCrafts },
        { "_addCraft", CraftingBuildingBinding::_addCraft },
        { "_removeCraft", CraftingBuildingBinding::_removeCraft },
        { "getCraft", CraftingBuildingBinding::getCraft },
        { "destroyProductionItem", CraftingBuildingBinding::destroyProductionItem },
        { "predictCraftersBestWeapon", CraftingBuildingBinding::predictCraftersBestWeapon },
        { "calculateCriticalChance", CraftingBuildingBinding::calculateCriticalChance },
        { "getCriticalSuccessWeapon", CraftingBuildingBinding::getCriticalSuccessWeapon },
        { "getItemsWeWantRidOf", CraftingBuildingBinding::getItemsWeWantRidOf },
        { "_NV_getItemsWeWantRidOf", CraftingBuildingBinding::_NV_getItemsWeWantRidOf },
        { "canHaveSomeOfThese", CraftingBuildingBinding::canHaveSomeOfThese },
        { "_NV_canHaveSomeOfThese", CraftingBuildingBinding::_NV_canHaveSomeOfThese },
        { "setupFromData", CraftingBuildingBinding::setupFromData },
        { "_NV_setupFromData", CraftingBuildingBinding::_NV_setupFromData },
        { "updateOutput", CraftingBuildingBinding::updateOutput },
        { "_NV_updateOutput", CraftingBuildingBinding::_NV_updateOutput },
        { "getPlayerCraftedWeaponLevel", CraftingBuildingBinding::getPlayerCraftedWeaponLevel },
        { "getGUIState", CraftingBuildingBinding::getGUIState },
        { "_NV_getGUIState", CraftingBuildingBinding::_NV_getGUIState },
        { "updateInventoryWindow", CraftingBuildingBinding::updateInventoryWindow },
        { "_NV_updateInventoryWindow", CraftingBuildingBinding::_NV_updateInventoryWindow },
        { "setProductionItem", CraftingBuildingBinding::setProductionItem },
        { "_NV_setProductionItem", CraftingBuildingBinding::_NV_setProductionItem },
        { 0, 0 }
    };

    registerClass(
        L, 
        CraftingBuildingBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CraftingBuildingBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, CraftingBuilding_get_maxCraftLevel);
    lua_setfield(L, -2, "maxCraftLevel");
    lua_pushcfunction(L, CraftingBuilding_get_crafting);
    lua_setfield(L, -2, "crafting");
    lua_pushcfunction(L, CraftingBuilding_get_specialCraftItemType);
    lua_setfield(L, -2, "specialCraftItemType");
    lua_pushcfunction(L, CraftingBuilding_get_repeat);
    lua_setfield(L, -2, "repeat");
    lua_pushcfunction(L, CraftingBuilding_get_whosCrafting);
    lua_setfield(L, -2, "whosCrafting");
    lua_pushcfunction(L, CraftingBuilding_get_itemCrafted);
    lua_setfield(L, -2, "itemCrafted");
    lua_pushcfunction(L, CraftingBuilding_get_failiureNotified);
    lua_setfield(L, -2, "failiureNotified");
    lua_pushcfunction(L, CraftingBuilding_get_biggestCraftableItem);
    lua_setfield(L, -2, "biggestCraftableItem");
    lua_pushcfunction(L, CraftingBuilding_get_outItem);
    lua_setfield(L, -2, "outItem");
    lua_pushcfunction(L, CraftingBuilding_get_inItems);
    lua_setfield(L, -2, "inItems");
    lua_pushcfunction(L, CraftingBuilding_get_partialItems);
    lua_setfield(L, -2, "partialItems");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, CraftingBuilding_set_maxCraftLevel);
    lua_setfield(L, -2, "maxCraftLevel");
    lua_pushcfunction(L, CraftingBuilding_set_crafting);
    lua_setfield(L, -2, "crafting");
    lua_pushcfunction(L, CraftingBuilding_set_specialCraftItemType);
    lua_setfield(L, -2, "specialCraftItemType");
    lua_pushcfunction(L, CraftingBuilding_set_repeat);
    lua_setfield(L, -2, "repeat");
    lua_pushcfunction(L, CraftingBuilding_set_whosCrafting);
    lua_setfield(L, -2, "whosCrafting");
    lua_pushcfunction(L, CraftingBuilding_set_itemCrafted);
    lua_setfield(L, -2, "itemCrafted");
    lua_pushcfunction(L, CraftingBuilding_set_failiureNotified);
    lua_setfield(L, -2, "failiureNotified");
    lua_pushcfunction(L, CraftingBuilding_set_biggestCraftableItem);
    lua_setfield(L, -2, "biggestCraftableItem");
    lua_pushcfunction(L, CraftingBuilding_set_outItem);
    lua_setfield(L, -2, "outItem");
    lua_pushcfunction(L, CraftingBuilding_set_inItems);
    lua_setfield(L, -2, "inItems");
    lua_pushcfunction(L, CraftingBuilding_set_partialItems);
    lua_setfield(L, -2, "partialItems");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    CraftingItemDequeBinding::registerBinding(L, "std::deque<CraftingItem>", nullptr);

    lua_pop(L, 1); // Pop the metatable off the stack

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "playerManufacturerData", CraftingBuildingBinding::playerManufacturerData);
    lua_setglobal(L, "CraftingBuilding");
}

} // namespace KenshiLua

