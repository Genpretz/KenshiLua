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

namespace KenshiLua
{

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

int InventoryGUIBinding::_CONSTRUCTOR(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    Inventory* inv = checkObject<Inventory>(L, 2, InventoryBinding::getMetatableName());
    InventoryLayout* layout = checkObject<InventoryLayout>(L, 3, InventoryLayoutBinding::getMetatableName());
    RootObject* callback = checkObject<RootObject>(L, 4, RootObjectBinding::getMetatableName());
    InventoryGUI* result = instance->_CONSTRUCTOR(inv, layout, callback);
    return pushObject<InventoryGUI>(L, result, InventoryGUIBinding::getMetatableName());
}

int InventoryGUIBinding::_DESTRUCTOR(lua_State* L)
{
    InventoryGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryGUI is nil");

    instance->_DESTRUCTOR();
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
    return pushObject<iVector2>(L, &result, iVector2Binding::getMetatableName());
}

/*
Skipped methods needing manual binding:
  line 118: bool lockedItemCheck(...) - static method
  line 119: void setTradingTown(...) - static method
  line 120: Town* getTradingTown(...) - static method
  line 121: void addTradePartner(...) - static method
  line 122: void removeTradePartner(...) - static method
  line 123: void clearTradePartners(...) - static method
  line 124: bool canDropMouseItemWithoutPaying(...) - static method
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
  line 157: Character* getNPCTrader(...) - static method
  line 158: RootObject* isTradingForMoney_static(...) - static method
  line 159: RootObject* isTradingAndStealing_static(...) - static method
  line 160: float getTraderPriceMultiplier(...) - static method
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

/*
Skipped properties needing manual binding:
  line 218: inventorySections (std::map<std::string, InventorySectionGUI*, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, InventorySectionGUI*>, Ogre::GeneralAllocPolicy > >) - unsupported type
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
        { "_CONSTRUCTOR", InventoryGUIBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", InventoryGUIBinding::_DESTRUCTOR },
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
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "layoutMgr", InventoryGUI_set_layoutMgr);
    registerSetter(L, "ownerInventory", InventoryGUI_set_ownerInventory);
    registerSetter(L, "childInventory", InventoryGUI_set_childInventory);
    registerSetter(L, "mouseFocus", InventoryGUI_set_mouseFocus);
    registerSetter(L, "callbackObject", InventoryGUI_set_callbackObject);
    registerSetter(L, "needItemsUpdate", InventoryGUI_set_needItemsUpdate);
    registerSetter(L, "visible", InventoryGUI_set_visible);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to GUIWindow
    // setMetatableParent(L, InventoryGUIBinding::getMetatableName(), GUIWindowBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua