#include "pch.h"
#include "kenshi\gui\MainBarGUI.h"
#include "MainBarGUIBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/Gui/GUIWindowBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Gui/MainTabPortraitPlatoonBinding.h"
#include "Bindings/Gui/OrdersPanelBinding.h"
#include "Bindings/RootObjectContainerBinding.h"
#include "Bindings/Gui/ToolTipBinding.h"
#include "Bindings/Gui/ToolTipFixedBinding.h"
#include "Bindings/MyGuiBinding.h"

namespace KenshiLua
{

static MainBarGUI* getInstance(lua_State* L, int idx)
{
    return checkObject<MainBarGUI>(L, idx, MainBarGUIBinding::getMetatableName());
}

// --- Getters for MainBarGUI ---
static int MainBarGUI_get_closeManagerWindowMsg(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushinteger(L, instance->closeManagerWindowMsg);
    return 1;
}

static int MainBarGUI_get_isLevelEditMode(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushboolean(L, instance->isLevelEditMode ? 1 : 0);
    return 1;
}

static int MainBarGUI_get_isInteriorLevelEditMode(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushboolean(L, instance->isInteriorLevelEditMode ? 1 : 0);
    return 1;
}

static int MainBarGUI_get_bountyPanel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    return pushObject<MyGUI::Widget>(L, instance->bountyPanel, MyGuiBinding::getMetatableName());
}

static int MainBarGUI_get_bountyDatapanel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    return pushObject<DatapanelGUI>(L, instance->bountyDatapanel, DatapanelGUIBinding::getMetatableName());
}

static int MainBarGUI_get_townPanel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->townPanel);
    return 1;
}

static int MainBarGUI_get_portraitsTabPanel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->portraitsTabPanel, MyGuiBinding::getMetatableName());
}

static int MainBarGUI_get_floorDownButton(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->floorDownButton, MyGuiBinding::getMetatableName());
}

static int MainBarGUI_get_floorUpButton(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->floorUpButton, MyGuiBinding::getMetatableName());
}

static int MainBarGUI_get_floorText(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->floorText, MyGuiBinding::getMetatableName());
}

static int MainBarGUI_get_dayText(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->dayText, MyGuiBinding::getMetatableName());
}

static int MainBarGUI_get_moneyLabel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->moneyLabel, MyGuiBinding::getMetatableName());
}

static int MainBarGUI_get_moneyText(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->moneyText, MyGuiBinding::getMetatableName());
}

static int MainBarGUI_get_timeText(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->timeText, MyGuiBinding::getMetatableName());
}

static int MainBarGUI_get_medicalPanel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->medicalPanel);
    return 1;
}

static int MainBarGUI_get_ordersDataPanel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    return pushObject<OrdersPanel>(L, instance->ordersDataPanel, OrdersPanelBinding::getMetatableName());
}

static int MainBarGUI_get_extendInfoPanelButton(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->extendInfoPanelButton, MyGuiBinding::getMetatableName());
}

static int MainBarGUI_get_extendedInfoPanel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    return pushObject<MyGUI::Widget>(L, instance->extendedInfoPanel, MyGuiBinding::getMetatableName());
}

static int MainBarGUI_get_extendedInfoPanelDuration(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushnumber(L, instance->extendedInfoPanelDuration);
    return 1;
}

static int MainBarGUI_get_infoPanelEnabled(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushboolean(L, instance->infoPanelEnabled ? 1 : 0);
    return 1;
}

static int MainBarGUI_get_infoPanelExtended(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushboolean(L, instance->infoPanelExtended ? 1 : 0);
    return 1;
}

static int MainBarGUI_get_biomePanel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    return pushObject<MyGUI::Widget>(L, instance->biomePanel, MyGuiBinding::getMetatableName());
}

static int MainBarGUI_get_biomePanelText(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->biomePanelText, MyGuiBinding::getMetatableName());
}

static int MainBarGUI_get_biomePanelVisibleTimer(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushnumber(L, instance->biomePanelVisibleTimer);
    return 1;
}

static int MainBarGUI_get_biomeTimer(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushnumber(L, instance->biomeTimer);
    return 1;
}

static int MainBarGUI_get_lastFrameBiomeGroup(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    return pushObject<GameData>(L, instance->lastFrameBiomeGroup, GameDataBinding::getMetatableName());
}

static int MainBarGUI_get_rememberlastBiomeGroup(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    return pushObject<GameData>(L, instance->rememberlastBiomeGroup, GameDataBinding::getMetatableName());
}

static int MainBarGUI_get_portraitContextMenuTarget(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    return handBinding::push(L, instance->portraitContextMenuTarget);
}

static int MainBarGUI_get_portraitContextMenuTimer(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushnumber(L, instance->portraitContextMenuTimer);
    return 1;
}

static int MainBarGUI_get_portraitSelectedContextIndex(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushinteger(L, instance->portraitSelectedContextIndex);
    return 1;
}

static int MainBarGUI_get_portraitsUpdating(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushboolean(L, instance->portraitsUpdating ? 1 : 0);
    return 1;
}

static int MainBarGUI_get_toolTip(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    return pushObject<ToolTipFixed>(L, instance->toolTip, ToolTipFixedBinding::getMetatableName());
}

static int MainBarGUI_get_pausePanel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    return pushObject<MyGUI::Widget>(L, instance->pausePanel, MyGuiBinding::getMetatableName());
}

static int MainBarGUI_get_loadingPanel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    return pushObject<MyGUI::Widget>(L, instance->loadingPanel, MyGuiBinding::getMetatableName());
}

// --- Setters for MainBarGUI ---
static int MainBarGUI_set_closeManagerWindowMsg(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    instance->closeManagerWindowMsg = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int MainBarGUI_set_isLevelEditMode(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    instance->isLevelEditMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MainBarGUI_set_isInteriorLevelEditMode(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    instance->isInteriorLevelEditMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MainBarGUI_set_bountyDatapanel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    instance->bountyDatapanel = lua_isnoneornil(L, 2) ? nullptr : checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    return 0;
}

static int MainBarGUI_set_ordersDataPanel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    instance->ordersDataPanel = lua_isnoneornil(L, 2) ? nullptr : checkObject<OrdersPanel>(L, 2, OrdersPanelBinding::getMetatableName());
    return 0;
}

static int MainBarGUI_set_extendedInfoPanelDuration(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    instance->extendedInfoPanelDuration = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MainBarGUI_set_infoPanelEnabled(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    instance->infoPanelEnabled = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MainBarGUI_set_infoPanelExtended(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    instance->infoPanelExtended = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MainBarGUI_set_biomePanelVisibleTimer(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    instance->biomePanelVisibleTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MainBarGUI_set_biomeTimer(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    instance->biomeTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MainBarGUI_set_lastFrameBiomeGroup(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    instance->lastFrameBiomeGroup = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int MainBarGUI_set_rememberlastBiomeGroup(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    instance->rememberlastBiomeGroup = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int MainBarGUI_set_portraitContextMenuTarget(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    instance->portraitContextMenuTarget = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int MainBarGUI_set_portraitContextMenuTimer(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    instance->portraitContextMenuTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MainBarGUI_set_portraitSelectedContextIndex(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    instance->portraitSelectedContextIndex = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int MainBarGUI_set_portraitsUpdating(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    instance->portraitsUpdating = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MainBarGUI_set_toolTip(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    instance->toolTip = lua_isnoneornil(L, 2) ? nullptr : checkObject<ToolTipFixed>(L, 2, ToolTipFixedBinding::getMetatableName());
    return 0;
}

int MainBarGUIBinding::_CONSTRUCTOR(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    MainBarGUI* result = instance->_CONSTRUCTOR();
    return pushObject<MainBarGUI>(L, result, MainBarGUIBinding::getMetatableName());
}

int MainBarGUIBinding::_DESTRUCTOR(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int MainBarGUIBinding::clear(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    instance->clear();
    return 0;
}

int MainBarGUIBinding::_NV_clear(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    instance->_NV_clear();
    return 0;
}

int MainBarGUIBinding::show(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->show(on);
    return 0;
}

int MainBarGUIBinding::_NV_show(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_show(on);
    return 0;
}

int MainBarGUIBinding::update(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    instance->update();
    return 0;
}

int MainBarGUIBinding::_NV_update(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    instance->_NV_update();
    return 0;
}

int MainBarGUIBinding::speedChanged(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    instance->speedChanged();
    return 0;
}

int MainBarGUIBinding::updateBountyPanelVisibility(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    instance->updateBountyPanelVisibility();
    return 0;
}

int MainBarGUIBinding::_NV_updateBountyPanelVisibility(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    instance->_NV_updateBountyPanelVisibility();
    return 0;
}

int MainBarGUIBinding::setLevelEditMode(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setLevelEditMode(on);
    return 0;
}

int MainBarGUIBinding::setLevelEditInteriorMode(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    bool interiorMode = lua_toboolean(L, 2) != 0;
    instance->setLevelEditInteriorMode(interiorMode);
    return 0;
}

int MainBarGUIBinding::pressedKey(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    unsigned int keycode = (unsigned int)luaL_checkinteger(L, 2);
    instance->pressedKey(keycode);
    return 0;
}

int MainBarGUIBinding::platoonUpdated(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    RootObjectContainer* platoon = checkObject<RootObjectContainer>(L, 2, RootObjectContainerBinding::getMetatableName());
    bool charAdded = lua_toboolean(L, 3) != 0;
    instance->platoonUpdated(platoon, charAdded);
    return 0;
}

int MainBarGUIBinding::updatePotraitsPlatoon(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    instance->updatePotraitsPlatoon();
    return 0;
}

int MainBarGUIBinding::updatePortraits(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    instance->updatePortraits();
    return 0;
}

int MainBarGUIBinding::refreshPortraitTabs(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    instance->refreshPortraitTabs();
    return 0;
}

int MainBarGUIBinding::updatePortraitSize(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    ActivePlatoon* platoon = checkObject<ActivePlatoon>(L, 2, ActivePlatoonBinding::getMetatableName());
    instance->updatePortraitSize(platoon);
    return 0;
}

int MainBarGUIBinding::getPausePanel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    MyGUI::Widget* result = instance->getPausePanel();
    return pushObject<MyGUI::Widget>(L, result, MyGuiBinding::getMetatableName());
}

int MainBarGUIBinding::getLoadingPanel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    MyGUI::Widget* result = instance->getLoadingPanel();
    return pushObject<MyGUI::Widget>(L, result, MyGuiBinding::getMetatableName());
}

int MainBarGUIBinding::getMedicalPanel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    MedicalDatapanel* result = instance->getMedicalPanel();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int MainBarGUIBinding::ordersPanelClear(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    instance->ordersPanelClear();
    return 0;
}

int MainBarGUIBinding::getToolTip(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    ToolTip* result = instance->getToolTip();
    return pushObject<ToolTip>(L, result, ToolTipBinding::getMetatableName());
}

int MainBarGUIBinding::_NV_getToolTip(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    ToolTip* result = instance->_NV_getToolTip();
    return pushObject<ToolTip>(L, result, ToolTipBinding::getMetatableName());
}

int MainBarGUIBinding::getDatapanel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    const std::string id = luaL_checkstring(L, 2);
    DatapanelGUI* result = instance->getDatapanel(id);
    return pushObject<DatapanelGUI>(L, result, DatapanelGUIBinding::getMetatableName());
}

int MainBarGUIBinding::setMessagePosition(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    instance->setMessagePosition();
    return 0;
}

int MainBarGUIBinding::serialise(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->serialise(data);
    return 0;
}

int MainBarGUIBinding::loadFromSerialise(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->loadFromSerialise(data);
    return 0;
}

int MainBarGUIBinding::setExtendInfoPanelEnabled(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    bool enabled = lua_toboolean(L, 2) != 0;
    instance->setExtendInfoPanelEnabled(enabled);
    return 0;
}

int MainBarGUIBinding::_getWidget(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    const std::string name = luaL_checkstring(L, 2);
    MyGUI::Widget* result = instance->_getWidget(name);
    return pushObject<MyGUI::Widget>(L, result, MyGuiBinding::getMetatableName());
}

int MainBarGUIBinding::autoChangeSelectedObject(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    hand* obj = checkObject<hand>(L, 2, handBinding::getMetatableName());
    if (!obj) return luaL_error(L, "Argument 2 to autoChangeSelectedObject must be hand");
    instance->autoChangeSelectedObject(*obj);
    return 0;
}

int MainBarGUIBinding::_NV_autoChangeSelectedObject(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    hand* obj = checkObject<hand>(L, 2, handBinding::getMetatableName());
    if (!obj) return luaL_error(L, "Argument 2 to _NV_autoChangeSelectedObject must be hand");
    instance->_NV_autoChangeSelectedObject(*obj);
    return 0;
}

int MainBarGUIBinding::getPortrait(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    if (testObject<hand>(L, 2, handBinding::getMetatableName()) != nullptr)
    {
        hand* character = checkObject<hand>(L, 2, handBinding::getMetatableName());
        PortraitData* res = instance->getPortrait(*character);
        if (res) lua_pushlightuserdata(L, (void*)res); else lua_pushnil(L);
        return 1;
    }
    else
    {
        MyGUI::types::TPoint<int> pos(0, 0);
        if (lua_istable(L, 2))
        {
            lua_getfield(L, 2, "left");
            if (lua_isnil(L, -1)) { lua_pop(L, 1); lua_getfield(L, 2, "x"); }
            pos.left = (int)lua_tointeger(L, -1);
            lua_pop(L, 1);

            lua_getfield(L, 2, "top");
            if (lua_isnil(L, -1)) { lua_pop(L, 1); lua_getfield(L, 2, "y"); }
            pos.top = (int)lua_tointeger(L, -1);
            lua_pop(L, 1);
        }
        else
        {
            pos.left = (int)luaL_checkinteger(L, 2);
            pos.top = (int)luaL_checkinteger(L, 3);
        }
        PortraitData* res = instance->getPortrait(pos);
        if (res) lua_pushlightuserdata(L, (void*)res); else lua_pushnil(L);
        return 1;
    }
}

int MainBarGUIBinding::updatePortrait(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    hand* character = checkObject<hand>(L, 2, handBinding::getMetatableName());
    if (!character) return luaL_error(L, "Argument 2 to updatePortrait must be hand");
    instance->updatePortrait(*character);
    return 0;
}

int MainBarGUIBinding::closeMapWindow(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    MyGUI::Widget* _sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    instance->closeMapWindow(_sender);
    return 0;
}

int MainBarGUIBinding::toggleMapWindow(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    MyGUI::Widget* _sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    instance->toggleMapWindow(_sender);
    return 0;
}

int MainBarGUIBinding::toggleFactionWindow(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    MyGUI::Widget* _sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    instance->toggleFactionWindow(_sender);
    return 0;
}

int MainBarGUIBinding::toggleTechWindow(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    MyGUI::Widget* _sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    instance->toggleTechWindow(_sender);
    return 0;
}

int MainBarGUIBinding::toggleCraftWindow(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    MyGUI::Widget* _sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    instance->toggleCraftWindow(_sender);
    return 0;
}

int MainBarGUIBinding::toggleSquadWindow(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    MyGUI::Widget* _sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    instance->toggleSquadWindow(_sender);
    return 0;
}

int MainBarGUIBinding::changeFloorButtonUp(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    MyGUI::Widget* _sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    instance->changeFloorButtonUp(_sender);
    return 0;
}

int MainBarGUIBinding::changeFloorButtonDown(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    MyGUI::Widget* _sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    instance->changeFloorButtonDown(_sender);
    return 0;
}

int MainBarGUIBinding::ordersPanelFill(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    hand* c = checkObject<hand>(L, 2, handBinding::getMetatableName());
    if (!c) return luaL_error(L, "Argument 2 to ordersPanelFill must be hand");
    instance->ordersPanelFill(*c);
    return 0;
}

int MainBarGUIBinding::getBuildingInventoryPosition(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    const MyGUI::types::TPoint<int>& pos = instance->getBuildingInventoryPosition();
    lua_newtable(L);
    lua_pushinteger(L, pos.left);
    lua_setfield(L, -2, "left");
    lua_pushinteger(L, pos.top);
    lua_setfield(L, -2, "top");
    lua_pushinteger(L, pos.left);
    lua_setfield(L, -2, "x");
    lua_pushinteger(L, pos.top);
    lua_setfield(L, -2, "y");
    return 1;
}

int MainBarGUIBinding::getTabPlatoonPortrait(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    if (lua_isnumber(L, 2))
    {
        int idx = (int)luaL_checkinteger(L, 2);
        const MainTabPortraitPlatoon& res = instance->getTabPlatoonPortrait(idx);
        return pushObject<MainTabPortraitPlatoon>(L, const_cast<MainTabPortraitPlatoon*>(&res), MainTabPortraitPlatoonBinding::getMetatableName());
    }
    else
    {
        ActivePlatoon* platoon = checkObject<ActivePlatoon>(L, 2, ActivePlatoonBinding::getMetatableName());
        const MainTabPortraitPlatoon& res = instance->getTabPlatoonPortrait(platoon);
        return pushObject<MainTabPortraitPlatoon>(L, const_cast<MainTabPortraitPlatoon*>(&res), MainTabPortraitPlatoonBinding::getMetatableName());
    }
}

int MainBarGUIBinding::extendInfoPanel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    MyGUI::Widget* _sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    int _a2 = (int)luaL_checkinteger(L, 3);
    int _a3 = (int)luaL_checkinteger(L, 4);
    MyGUI::MouseButton _id((MyGUI::MouseButton::Enum)luaL_checkinteger(L, 5));

    instance->extendInfoPanel(_sender, _a2, _a3, _id);
    return 0;
}

int MainBarGUIBinding::toggleInventory(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    MyGUI::Widget* _sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    instance->toggleInventory(_sender);
    return 0;
}

int MainBarGUIBinding::toggleStatsWindow(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    MyGUI::Widget* _sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    instance->toggleStatsWindow(_sender);
    return 0;
}

int MainBarGUIBinding::toggleHelpWindow(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    MyGUI::Widget* _a1 = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    instance->toggleHelpWindow(_a1);
    return 0;
}

int MainBarGUIBinding::changeSpeed(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    MyGUI::Widget* _sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    instance->changeSpeed(_sender);
    return 0;
}

int MainBarGUIBinding::buildButton(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    MyGUI::Widget* _sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    instance->buildButton(_sender);
    return 0;
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - MainBarGUI_get_townPanel: TownPanel* (unbound pointer)
  - MainBarGUI_get_medicalPanel: MedicalDatapanel* (unbound pointer)
  - MainBarGUIBinding::getMedicalPanel: MedicalDatapanel* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 120: datapanels (boost::unordered::unordered_map<std::string, DatapanelGUI*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, DatapanelGUI*>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 128: speedButtons (Ogre::FastArray<MyGUI::Button*>) - unsupported type
  line 137: extendedInfoPanelShow (MyGUI::types::TPoint<int>) - unsupported type
  line 138: extendedInfoPanelHide (MyGUI::types::TPoint<int>) - unsupported type
  line 150: tabPortraits (Ogre::FastArray<MainTabPortraitPlatoon>) - unsupported type
  line 152: portraits (ogre_unordered_map<hand, PortraitData*>::type) - unsupported type
  line 153: portraitsIndices (boost::unordered::unordered_map<PortraitData*, std::pair<PortraitMainItemBox*, unsigned char>, boost::hash<PortraitData*>, std::equal_to<PortraitData*>, Ogre::STLAllocator<std::pair<PortraitData*const, std::pair<PortraitMainItemBox*, unsigned char> >, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 156: toolTipBasePosition (MyGUI::types::TPoint<int>) - unsupported type
  line 159: buildingInventoryPosition (MyGUI::types::TPoint<int>) - unsupported type
  line 160: messagePosition (MyGUI::types::TPoint<int>) - unsupported type
*/

int MainBarGUIBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int MainBarGUIBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MainBarGUI object");
    return 1;
}

void MainBarGUIBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       MainBarGUIBinding::gc },
        { "__tostring", MainBarGUIBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", MainBarGUIBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", MainBarGUIBinding::_DESTRUCTOR },
        { "clear", MainBarGUIBinding::clear },
        { "_NV_clear", MainBarGUIBinding::_NV_clear },
        { "show", MainBarGUIBinding::show },
        { "_NV_show", MainBarGUIBinding::_NV_show },
        { "update", MainBarGUIBinding::update },
        { "_NV_update", MainBarGUIBinding::_NV_update },
        { "speedChanged", MainBarGUIBinding::speedChanged },
        { "updateBountyPanelVisibility", MainBarGUIBinding::updateBountyPanelVisibility },
        { "_NV_updateBountyPanelVisibility", MainBarGUIBinding::_NV_updateBountyPanelVisibility },
        { "setLevelEditMode", MainBarGUIBinding::setLevelEditMode },
        { "setLevelEditInteriorMode", MainBarGUIBinding::setLevelEditInteriorMode },
        { "pressedKey", MainBarGUIBinding::pressedKey },
        { "platoonUpdated", MainBarGUIBinding::platoonUpdated },
        { "updatePotraitsPlatoon", MainBarGUIBinding::updatePotraitsPlatoon },
        { "updatePortraits", MainBarGUIBinding::updatePortraits },
        { "refreshPortraitTabs", MainBarGUIBinding::refreshPortraitTabs },
        { "updatePortraitSize", MainBarGUIBinding::updatePortraitSize },
        { "getPausePanel", MainBarGUIBinding::getPausePanel },
        { "getLoadingPanel", MainBarGUIBinding::getLoadingPanel },
        { "getMedicalPanel", MainBarGUIBinding::getMedicalPanel },
        { "ordersPanelClear", MainBarGUIBinding::ordersPanelClear },
        { "getToolTip", MainBarGUIBinding::getToolTip },
        { "_NV_getToolTip", MainBarGUIBinding::_NV_getToolTip },
        { "getDatapanel", MainBarGUIBinding::getDatapanel },
        { "setMessagePosition", MainBarGUIBinding::setMessagePosition },
        { "serialise", MainBarGUIBinding::serialise },
        { "loadFromSerialise", MainBarGUIBinding::loadFromSerialise },
        { "setExtendInfoPanelEnabled", MainBarGUIBinding::setExtendInfoPanelEnabled },
        { "_getWidget", MainBarGUIBinding::_getWidget },
        { "autoChangeSelectedObject", MainBarGUIBinding::autoChangeSelectedObject },
        { "_NV_autoChangeSelectedObject", MainBarGUIBinding::_NV_autoChangeSelectedObject },
        { "getPortrait", MainBarGUIBinding::getPortrait },
        { "updatePortrait", MainBarGUIBinding::updatePortrait },
        { "closeMapWindow", MainBarGUIBinding::closeMapWindow },
        { "toggleMapWindow", MainBarGUIBinding::toggleMapWindow },
        { "toggleFactionWindow", MainBarGUIBinding::toggleFactionWindow },
        { "toggleTechWindow", MainBarGUIBinding::toggleTechWindow },
        { "toggleCraftWindow", MainBarGUIBinding::toggleCraftWindow },
        { "toggleSquadWindow", MainBarGUIBinding::toggleSquadWindow },
        { "changeFloorButtonUp", MainBarGUIBinding::changeFloorButtonUp },
        { "changeFloorButtonDown", MainBarGUIBinding::changeFloorButtonDown },
        { "ordersPanelFill", MainBarGUIBinding::ordersPanelFill },
        { "getBuildingInventoryPosition", MainBarGUIBinding::getBuildingInventoryPosition },
        { "getTabPlatoonPortrait", MainBarGUIBinding::getTabPlatoonPortrait },
        { "extendInfoPanel", MainBarGUIBinding::extendInfoPanel },
        { "toggleInventory", MainBarGUIBinding::toggleInventory },
        { "toggleStatsWindow", MainBarGUIBinding::toggleStatsWindow },
        { "toggleHelpWindow", MainBarGUIBinding::toggleHelpWindow },
        { "changeSpeed", MainBarGUIBinding::changeSpeed },
        { "buildButton", MainBarGUIBinding::buildButton },
        { 0, 0 }
    };

    registerClass(
        L, 
        MainBarGUIBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, MainBarGUIBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "closeManagerWindowMsg", MainBarGUI_get_closeManagerWindowMsg);
    registerGetter(L, "isLevelEditMode", MainBarGUI_get_isLevelEditMode);
    registerGetter(L, "isInteriorLevelEditMode", MainBarGUI_get_isInteriorLevelEditMode);
    registerGetter(L, "bountyPanel", MainBarGUI_get_bountyPanel);
    registerGetter(L, "bountyDatapanel", MainBarGUI_get_bountyDatapanel);
    registerGetter(L, "townPanel", MainBarGUI_get_townPanel);
    registerGetter(L, "portraitsTabPanel", MainBarGUI_get_portraitsTabPanel);
    registerGetter(L, "floorDownButton", MainBarGUI_get_floorDownButton);
    registerGetter(L, "floorUpButton", MainBarGUI_get_floorUpButton);
    registerGetter(L, "floorText", MainBarGUI_get_floorText);
    registerGetter(L, "dayText", MainBarGUI_get_dayText);
    registerGetter(L, "moneyLabel", MainBarGUI_get_moneyLabel);
    registerGetter(L, "moneyText", MainBarGUI_get_moneyText);
    registerGetter(L, "timeText", MainBarGUI_get_timeText);
    registerGetter(L, "medicalPanel", MainBarGUI_get_medicalPanel);
    registerGetter(L, "ordersDataPanel", MainBarGUI_get_ordersDataPanel);
    registerGetter(L, "extendInfoPanelButton", MainBarGUI_get_extendInfoPanelButton);
    registerGetter(L, "extendedInfoPanel", MainBarGUI_get_extendedInfoPanel);
    registerGetter(L, "extendedInfoPanelDuration", MainBarGUI_get_extendedInfoPanelDuration);
    registerGetter(L, "infoPanelEnabled", MainBarGUI_get_infoPanelEnabled);
    registerGetter(L, "infoPanelExtended", MainBarGUI_get_infoPanelExtended);
    registerGetter(L, "biomePanel", MainBarGUI_get_biomePanel);
    registerGetter(L, "biomePanelText", MainBarGUI_get_biomePanelText);
    registerGetter(L, "biomePanelVisibleTimer", MainBarGUI_get_biomePanelVisibleTimer);
    registerGetter(L, "biomeTimer", MainBarGUI_get_biomeTimer);
    registerGetter(L, "lastFrameBiomeGroup", MainBarGUI_get_lastFrameBiomeGroup);
    registerGetter(L, "rememberlastBiomeGroup", MainBarGUI_get_rememberlastBiomeGroup);
    registerGetter(L, "portraitContextMenuTarget", MainBarGUI_get_portraitContextMenuTarget);
    registerGetter(L, "portraitContextMenuTimer", MainBarGUI_get_portraitContextMenuTimer);
    registerGetter(L, "portraitSelectedContextIndex", MainBarGUI_get_portraitSelectedContextIndex);
    registerGetter(L, "portraitsUpdating", MainBarGUI_get_portraitsUpdating);
    registerGetter(L, "toolTip", MainBarGUI_get_toolTip);
    registerGetter(L, "pausePanel", MainBarGUI_get_pausePanel);
    registerGetter(L, "loadingPanel", MainBarGUI_get_loadingPanel);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "closeManagerWindowMsg", MainBarGUI_set_closeManagerWindowMsg);
    registerSetter(L, "isLevelEditMode", MainBarGUI_set_isLevelEditMode);
    registerSetter(L, "isInteriorLevelEditMode", MainBarGUI_set_isInteriorLevelEditMode);
    registerSetter(L, "bountyDatapanel", MainBarGUI_set_bountyDatapanel);
    registerSetter(L, "ordersDataPanel", MainBarGUI_set_ordersDataPanel);
    registerSetter(L, "extendedInfoPanelDuration", MainBarGUI_set_extendedInfoPanelDuration);
    registerSetter(L, "infoPanelEnabled", MainBarGUI_set_infoPanelEnabled);
    registerSetter(L, "infoPanelExtended", MainBarGUI_set_infoPanelExtended);
    registerSetter(L, "biomePanelVisibleTimer", MainBarGUI_set_biomePanelVisibleTimer);
    registerSetter(L, "biomeTimer", MainBarGUI_set_biomeTimer);
    registerSetter(L, "lastFrameBiomeGroup", MainBarGUI_set_lastFrameBiomeGroup);
    registerSetter(L, "rememberlastBiomeGroup", MainBarGUI_set_rememberlastBiomeGroup);
    registerSetter(L, "portraitContextMenuTarget", MainBarGUI_set_portraitContextMenuTarget);
    registerSetter(L, "portraitContextMenuTimer", MainBarGUI_set_portraitContextMenuTimer);
    registerSetter(L, "portraitSelectedContextIndex", MainBarGUI_set_portraitSelectedContextIndex);
    registerSetter(L, "portraitsUpdating", MainBarGUI_set_portraitsUpdating);
    registerSetter(L, "toolTip", MainBarGUI_set_toolTip);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to GUIWindow
    // setMetatableParent(L, MainBarGUIBinding::getMetatableName(), GUIWindowBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua