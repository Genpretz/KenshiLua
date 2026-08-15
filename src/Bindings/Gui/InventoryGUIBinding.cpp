#include "pch.h"
#include "kenshi\gui\InventoryGUI.h"
#include "InventoryGUIBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/ContainerItemBinding.h"
#include "Bindings/Gui/GUIWindowBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/Gui/InventoryIconBinding.h"
#include "Bindings/Gui/InventoryLayoutBinding.h"
#include "Bindings/InventorySectionBinding.h"
#include "Bindings/Gui/InventorySectionGUIBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/LockedArmourBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/TownBinding.h"
#include "Bindings/Util/iVector2Binding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/StdMapBinding.h"

namespace KenshiLua
{

typedef StdMapBinding<std::string, InventorySectionGUI*> InventorySectionsMapBinding;

static InventoryGUI* getInstance(lua_State* L, int idx)
{
    return checkObject<InventoryGUI>(L, idx, InventoryGUIBinding::getMetatableName());
}

// --- Getters for InventoryGUI ---
static int InventoryGUI_get_layoutMgr(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");
    return pushObject<InventoryLayout>(L, instance->layoutMgr, InventoryLayoutBinding::getMetatableName());
}

static int InventoryGUI_get_ownerInventory(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");
    return pushObject<InventoryGUI>(L, instance->ownerInventory, InventoryGUIBinding::getMetatableName());
}

static int InventoryGUI_get_childInventory(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");
    return pushObject<InventoryGUI>(L, instance->childInventory, InventoryGUIBinding::getMetatableName());
}

static int InventoryGUI_get_mouseFocus(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");
    lua_pushboolean(L, instance->mouseFocus ? 1 : 0);
    return 1;
}

static int InventoryGUI_get_callbackObject(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");
    return pushObject<RootObject>(L, instance->callbackObject, RootObjectBinding::getMetatableName());
}

static int InventoryGUI_get_needItemsUpdate(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");
    lua_pushboolean(L, instance->needItemsUpdate ? 1 : 0);
    return 1;
}

static int InventoryGUI_get_visible(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");
    lua_pushboolean(L, instance->visible ? 1 : 0);
    return 1;
}

// --- Setters for InventoryGUI ---
static int InventoryGUI_set_layoutMgr(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");
    instance->layoutMgr = lua_isnoneornil(L, 2) ? nullptr : checkObject<InventoryLayout>(L, 2, InventoryLayoutBinding::getMetatableName());
    return 0;
}

static int InventoryGUI_set_ownerInventory(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");
    instance->ownerInventory = lua_isnoneornil(L, 2) ? nullptr : checkObject<InventoryGUI>(L, 2, InventoryGUIBinding::getMetatableName());
    return 0;
}

static int InventoryGUI_set_childInventory(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");
    instance->childInventory = lua_isnoneornil(L, 2) ? nullptr : checkObject<InventoryGUI>(L, 2, InventoryGUIBinding::getMetatableName());
    return 0;
}

static int InventoryGUI_set_mouseFocus(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");
    instance->mouseFocus = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InventoryGUI_set_callbackObject(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");
    instance->callbackObject = lua_isnoneornil(L, 2) ? nullptr : checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    return 0;
}

static int InventoryGUI_set_needItemsUpdate(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");
    instance->needItemsUpdate = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InventoryGUI_set_visible(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");
    instance->visible = lua_toboolean(L, 2) != 0;
    return 0;
}

static int InventoryGUI_get_inventorySections(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");
    return pushObject<InventorySectionsMapBinding::MapType>(L, &instance->inventorySections, InventorySectionsMapBinding::getMetatableName());
}

static int InventoryGUI_set_inventorySections(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");
    auto* val = checkObject<InventorySectionsMapBinding::MapType>(L, 2, InventorySectionsMapBinding::getMetatableName());
    if (val) instance->inventorySections = *val;
    return 0;
}

int InventoryGUIBinding::update(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    instance->update();
    return 0;
}

int InventoryGUIBinding::_NV_update(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    instance->_NV_update();
    return 0;
}

int InventoryGUIBinding::show(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->show(on);
    return 0;
}

int InventoryGUIBinding::_NV_show(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_show(on);
    return 0;
}

int InventoryGUIBinding::setPositionReal(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    float x = (float)luaL_checknumber(L, 2);
    float y = (float)luaL_checknumber(L, 3);
    instance->setPositionReal(x, y);
    return 0;
}

int InventoryGUIBinding::_NV_setPositionReal(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    float x = (float)luaL_checknumber(L, 2);
    float y = (float)luaL_checknumber(L, 3);
    instance->_NV_setPositionReal(x, y);
    return 0;
}

int InventoryGUIBinding::isVisible(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    bool result = instance->isVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryGUIBinding::_NV_isVisible(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    bool result = instance->_NV_isVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryGUIBinding::_NV_refreshSection(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    InventorySection* section = checkObject<InventorySection>(L, 2, InventorySectionBinding::getMetatableName());
    instance->_NV_refreshSection(section);
    return 0;
}

int InventoryGUIBinding::showBackpack(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->showBackpack(on);
    return 0;
}

int InventoryGUIBinding::getBackpack(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    ContainerItem* result = instance->getBackpack();
    return pushObject<ContainerItem>(L, result, ContainerItemBinding::getMetatableName());
}

int InventoryGUIBinding::getInventory(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    Inventory* result = instance->getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int InventoryGUIBinding::_NV_getInventory(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    Inventory* result = instance->_NV_getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int InventoryGUIBinding::hasSameOwner(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    const InventoryGUI* other = checkObject<InventoryGUI>(L, 2, InventoryGUIBinding::getMetatableName());
    bool result = instance->hasSameOwner(other);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryGUIBinding::getCallbackCharacter(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    Character* result = instance->getCallbackCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int InventoryGUIBinding::_NV_getCallbackCharacter(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    Character* result = instance->_NV_getCallbackCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int InventoryGUIBinding::getCallbackObject(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    RootObject* result = instance->getCallbackObject();
    return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
}

int InventoryGUIBinding::_NV_getCallbackObject(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    RootObject* result = instance->_NV_getCallbackObject();
    return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
}

int InventoryGUIBinding::getSelectedItem(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    const std::string sectionName = luaL_checkstring(L, 2);
    Item* result = instance->getSelectedItem(sectionName);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventoryGUIBinding::stealingGUIInfoUpdate(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    instance->stealingGUIInfoUpdate();
    return 0;
}

int InventoryGUIBinding::pickupItemToMouse(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    const std::string sectionName = luaL_checkstring(L, 2);
    bool result = instance->pickupItemToMouse(sectionName);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryGUIBinding::getMouseItem(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    Item* result = instance->getMouseItem();
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventoryGUIBinding::takeCertainAmountFrom(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    Item* baseItem = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    int amount = (int)luaL_checkinteger(L, 3);
    Item* result = instance->takeCertainAmountFrom(baseItem, amount);
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int InventoryGUIBinding::RClickAutoTrade(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    const std::string invSectionName = luaL_checkstring(L, 2);
    int x = (int)luaL_checkinteger(L, 3);
    int y = (int)luaL_checkinteger(L, 4);
    InventoryGUI* sendingTo = checkObject<InventoryGUI>(L, 5, InventoryGUIBinding::getMetatableName());
    bool thieveryChecks = lua_toboolean(L, 6) != 0;
    bool first = lua_toboolean(L, 7) != 0;
    InventoryGUI::TradeResult result = instance->RClickAutoTrade(invSectionName, x, y, sendingTo, thieveryChecks, first);
    lua_pushinteger(L, (lua_Integer)result.value);
    return 1;
}

int InventoryGUIBinding::RClickAutoTradeAll(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    const std::string invSectionName = luaL_checkstring(L, 2);
    int x = (int)luaL_checkinteger(L, 3);
    int y = (int)luaL_checkinteger(L, 4);
    InventoryGUI* sendingTo = checkObject<InventoryGUI>(L, 5, InventoryGUIBinding::getMetatableName());
    bool thieveryChecks = lua_toboolean(L, 6) != 0;
    bool first = lua_toboolean(L, 7) != 0;
    InventoryGUI::TradeResult result = instance->RClickAutoTradeAll(invSectionName, x, y, sendingTo, thieveryChecks, first);
    lua_pushinteger(L, (lua_Integer)result.value);
    return 1;
}

int InventoryGUIBinding::isTradingForMoney(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    InventoryGUI* cameFrom = checkObject<InventoryGUI>(L, 2, InventoryGUIBinding::getMetatableName());
    bool result = instance->isTradingForMoney(cameFrom);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryGUIBinding::isStealing(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    InventoryGUI* cameFrom = checkObject<InventoryGUI>(L, 2, InventoryGUIBinding::getMetatableName());
    bool result = instance->isStealing(cameFrom);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryGUIBinding::isWithinRangeToTrade(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    RootObject* otherOwner = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool stealing = lua_toboolean(L, 3) != 0;
    bool result = instance->isWithinRangeToTrade(otherOwner, stealing);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryGUIBinding::setItemToPlayerPortrait(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    Character* character = checkObject<Character>(L, 3, CharacterBinding::getMetatableName());
    bool result = instance->setItemToPlayerPortrait(item, character);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryGUIBinding::playSound(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    const std::string eventId = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    instance->playSound(eventId.c_str(), item);
    return 0;
}

int InventoryGUIBinding::fencingConfirmationCallback(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    int b = (int)luaL_checkinteger(L, 2);
    instance->fencingConfirmationCallback(b);
    return 0;
}

int InventoryGUIBinding::getPlayerTradeCharacter(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    RootObject* result = instance->getPlayerTradeCharacter();
    return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
}

int InventoryGUIBinding::refreshAllSections(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    instance->refreshAllSections();
    return 0;
}

int InventoryGUIBinding::updateDatapanel(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    instance->updateDatapanel();
    return 0;
}

int InventoryGUIBinding::rightClickAutoEquipping(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    instance->rightClickAutoEquipping();
    return 0;
}

int InventoryGUIBinding::tryToEquip(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool replace = lua_toboolean(L, 3) != 0;
    bool result = instance->tryToEquip(item, replace);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryGUIBinding::returnItem(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    const std::string sectionName = luaL_checkstring(L, 3);
    instance->returnItem(item, sectionName);
    return 0;
}

int InventoryGUIBinding::hasMouse(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    bool result = instance->hasMouse();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryGUIBinding::getSectionWithMouseLocal(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    std::string result = instance->getSectionWithMouseLocal();
    lua_pushstring(L, result.c_str());
    return 1;
}

int InventoryGUIBinding::getSlotWithMouse(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    iVector2 result = instance->getSlotWithMouse();
    return pushValue<iVector2>(L, result, iVector2Binding::getMetatableName());
}

int InventoryGUIBinding::setTradingTown(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    hand* town = checkObject<hand>(L, idx, HandBinding::getMetatableName());
    if (!town) return luaL_error(L, "Argument to setTradingTown must be hand");
    InventoryGUI::setTradingTown(*town);
    return 0;
}

int InventoryGUIBinding::getTradingTown(lua_State* L)
{
    Town* result = InventoryGUI::getTradingTown();
    return pushObject<Town>(L, result, TownBinding::getMetatableName());
}

int InventoryGUIBinding::clearTradePartners(lua_State* L)
{
    InventoryGUI::clearTradePartners();
    return 0;
}

int InventoryGUIBinding::getNPCTrader(lua_State* L)
{
    Character* result = InventoryGUI::getNPCTrader();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int InventoryGUIBinding::isTradingForMoney_static(lua_State* L)
{
    RootObject* result = InventoryGUI::isTradingForMoney_static();
    return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
}

int InventoryGUIBinding::isTradingAndStealing_static(lua_State* L)
{
    RootObject* result = InventoryGUI::isTradingAndStealing_static();
    return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
}

int InventoryGUIBinding::getTraderPriceMultiplier(lua_State* L)
{
    float result = InventoryGUI::getTraderPriceMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

int InventoryGUIBinding::canDropMouseItemWithoutPaying(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    InventoryGUI* cameFrom = checkObject<InventoryGUI>(L, idx, InventoryGUIBinding::getMetatableName());
    bool result = InventoryGUI::canDropMouseItemWithoutPaying(cameFrom);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int InventoryGUIBinding::removeTradePartner(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    InventoryGUI* tradewith = checkObject<InventoryGUI>(L, idx, InventoryGUIBinding::getMetatableName());
    InventoryGUI::removeTradePartner(tradewith);
    return 0;
}

int InventoryGUIBinding::addTradePartner(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    InventoryGUI* tradewith = checkObject<InventoryGUI>(L, idx, InventoryGUIBinding::getMetatableName());
    bool payment = lua_toboolean(L, idx + 1) != 0;
    bool canDrop = lua_toboolean(L, idx + 2) != 0;
    bool isPlayer = lua_toboolean(L, idx + 3) != 0;
    hand* who = checkObject<hand>(L, idx + 4, HandBinding::getMetatableName());
    if (!who) return luaL_error(L, "Argument who to addTradePartner must be hand");
    InventoryGUI::addTradePartner(tradewith, payment, canDrop, isPlayer, *who);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 118: bool lockedItemCheck(...) - static method
  line 125: void autoChangeSelectedObject(...) - non-string reference arg
  line 126: void _NV_autoChangeSelectedObject(...) - non-string reference arg
  line 135: void refreshSection(...) - overloaded method
  line 137: void refreshSection(...) - overloaded method
  line 138: void autoArrangeButton(...) - unsupported arg type
  line 139: void openBackpackButton(...) - unsupported arg type
  line 140: void openLimbsInterface(...) - unsupported arg type
  line 143: void windowButtonPressed(...) - unsupported arg type
  line 153: MyGUI::types::TCoord<int> getWindowCoord(...) - unsupported return type
  line 156: void getTrader1Trader2(...) - non-string reference arg
  line 169: bool placeItemFromMouse(...) - unsupported arg type
  line 193: bool fencingConfirmation(...) - unsupported arg type
  line 201: InventorySection* getSection(...) - overloaded method
  line 202: InventorySection* getSection(...) - overloaded method
  line 206: void sectionMouseButtonPressed(...) - unsupported arg type
  line 207: void sectionMouseButtonReleased(...) - unsupported arg type
  line 208: void onWindowFocus(...) - unsupported arg type
  line 209: void windowMoved(...) - unsupported arg type
  line 210: InventoryIcon* makeIconForItem(...) - static method
*/

int InventoryGUIBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int InventoryGUIBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.InventoryGUI object");
    return 1;
}

void InventoryGUIBinding::registerBinding(lua_State* L)
{
    InventorySectionsMapBinding::registerBinding(L, "std::map<std::string, InventorySectionGUI*>", nullptr, InventorySectionGUIBinding::getMetatableName());

    static const luaL_Reg meta[] = {
        { "__gc",       InventoryGUIBinding::gc },
        { "__tostring", InventoryGUIBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "update", InventoryGUIBinding::update },
        { "_NV_update", InventoryGUIBinding::_NV_update },
        { "show", InventoryGUIBinding::show },
        { "_NV_show", InventoryGUIBinding::_NV_show },
        { "setPositionReal", InventoryGUIBinding::setPositionReal },
        { "_NV_setPositionReal", InventoryGUIBinding::_NV_setPositionReal },
        { "isVisible", InventoryGUIBinding::isVisible },
        { "_NV_isVisible", InventoryGUIBinding::_NV_isVisible },
        { "_NV_refreshSection", InventoryGUIBinding::_NV_refreshSection },
        { "showBackpack", InventoryGUIBinding::showBackpack },
        { "getBackpack", InventoryGUIBinding::getBackpack },
        { "getInventory", InventoryGUIBinding::getInventory },
        { "_NV_getInventory", InventoryGUIBinding::_NV_getInventory },
        { "hasSameOwner", InventoryGUIBinding::hasSameOwner },
        { "getCallbackCharacter", InventoryGUIBinding::getCallbackCharacter },
        { "_NV_getCallbackCharacter", InventoryGUIBinding::_NV_getCallbackCharacter },
        { "getCallbackObject", InventoryGUIBinding::getCallbackObject },
        { "_NV_getCallbackObject", InventoryGUIBinding::_NV_getCallbackObject },
        { "getSelectedItem", InventoryGUIBinding::getSelectedItem },
        { "stealingGUIInfoUpdate", InventoryGUIBinding::stealingGUIInfoUpdate },
        { "pickupItemToMouse", InventoryGUIBinding::pickupItemToMouse },
        { "getMouseItem", InventoryGUIBinding::getMouseItem },
        { "takeCertainAmountFrom", InventoryGUIBinding::takeCertainAmountFrom },
        { "RClickAutoTrade", InventoryGUIBinding::RClickAutoTrade },
        { "RClickAutoTradeAll", InventoryGUIBinding::RClickAutoTradeAll },
        { "isTradingForMoney", InventoryGUIBinding::isTradingForMoney },
        { "isStealing", InventoryGUIBinding::isStealing },
        { "isWithinRangeToTrade", InventoryGUIBinding::isWithinRangeToTrade },
        { "setItemToPlayerPortrait", InventoryGUIBinding::setItemToPlayerPortrait },
        { "playSound", InventoryGUIBinding::playSound },
        { "fencingConfirmationCallback", InventoryGUIBinding::fencingConfirmationCallback },
        { "getPlayerTradeCharacter", InventoryGUIBinding::getPlayerTradeCharacter },
        { "refreshAllSections", InventoryGUIBinding::refreshAllSections },
        { "updateDatapanel", InventoryGUIBinding::updateDatapanel },
        { "rightClickAutoEquipping", InventoryGUIBinding::rightClickAutoEquipping },
        { "tryToEquip", InventoryGUIBinding::tryToEquip },
        { "returnItem", InventoryGUIBinding::returnItem },
        { "hasMouse", InventoryGUIBinding::hasMouse },
        { "getSectionWithMouseLocal", InventoryGUIBinding::getSectionWithMouseLocal },
        { "getSlotWithMouse", InventoryGUIBinding::getSlotWithMouse },
        { "setTradingTown", InventoryGUIBinding::setTradingTown },
        { "getTradingTown", InventoryGUIBinding::getTradingTown },
        { "clearTradePartners", InventoryGUIBinding::clearTradePartners },
        { "getNPCTrader", InventoryGUIBinding::getNPCTrader },
        { "isTradingForMoney_static", InventoryGUIBinding::isTradingForMoney_static },
        { "isTradingAndStealing_static", InventoryGUIBinding::isTradingAndStealing_static },
        { "getTraderPriceMultiplier", InventoryGUIBinding::getTraderPriceMultiplier },
        { "canDropMouseItemWithoutPaying", InventoryGUIBinding::canDropMouseItemWithoutPaying },
        { "removeTradePartner", InventoryGUIBinding::removeTradePartner },
        { "addTradePartner", InventoryGUIBinding::addTradePartner },
        { 0, 0 }
    };

    registerClass(
        L, 
        InventoryGUIBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, InventoryGUIBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "layoutMgr", InventoryGUI_get_layoutMgr);
    registerGetter(L, "ownerInventory", InventoryGUI_get_ownerInventory);
    registerGetter(L, "childInventory", InventoryGUI_get_childInventory);
    registerGetter(L, "mouseFocus", InventoryGUI_get_mouseFocus);
    registerGetter(L, "callbackObject", InventoryGUI_get_callbackObject);
    registerGetter(L, "needItemsUpdate", InventoryGUI_get_needItemsUpdate);
    registerGetter(L, "visible", InventoryGUI_get_visible);
    registerGetter(L, "inventorySections", InventoryGUI_get_inventorySections);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "layoutMgr", InventoryGUI_set_layoutMgr);
    registerSetter(L, "ownerInventory", InventoryGUI_set_ownerInventory);
    registerSetter(L, "childInventory", InventoryGUI_set_childInventory);
    registerSetter(L, "mouseFocus", InventoryGUI_set_mouseFocus);
    registerSetter(L, "callbackObject", InventoryGUI_set_callbackObject);
    registerSetter(L, "needItemsUpdate", InventoryGUI_set_needItemsUpdate);
    registerSetter(L, "visible", InventoryGUI_set_visible);
    registerSetter(L, "inventorySections", InventoryGUI_set_inventorySections);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up static methods on global table
    registerStaticMethod(L, "setTradingTown", InventoryGUIBinding::setTradingTown);
    registerStaticMethod(L, "getTradingTown", InventoryGUIBinding::getTradingTown);
    registerStaticMethod(L, "clearTradePartners", InventoryGUIBinding::clearTradePartners);
    registerStaticMethod(L, "getNPCTrader", InventoryGUIBinding::getNPCTrader);
    registerStaticMethod(L, "isTradingForMoney_static", InventoryGUIBinding::isTradingForMoney_static);
    registerStaticMethod(L, "isTradingAndStealing_static", InventoryGUIBinding::isTradingAndStealing_static);
    registerStaticMethod(L, "getTraderPriceMultiplier", InventoryGUIBinding::getTraderPriceMultiplier);
    registerStaticMethod(L, "canDropMouseItemWithoutPaying", InventoryGUIBinding::canDropMouseItemWithoutPaying);
    registerStaticMethod(L, "removeTradePartner", InventoryGUIBinding::removeTradePartner);
    registerStaticMethod(L, "addTradePartner", InventoryGUIBinding::addTradePartner);

    // Wire up inheritance to GUIWindow
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, InventoryGUIBinding::getMetatableName(), GUIWindowBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua