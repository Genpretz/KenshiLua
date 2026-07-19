#include "pch.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"

#include <kenshi/gui/MainBarGUI.h>
#include "MainBarGUIBinding.h"
#include "GUIWindowBinding.h"
#include "Lua/BindingHelpers.h"

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
    lua_pushlightuserdata(L, (void*)instance->bountyPanel);
    return 1;
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
    lua_pushlightuserdata(L, (void*)instance->portraitsTabPanel);
    return 1;
}

static int MainBarGUI_get_floorDownButton(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->floorDownButton);
    return 1;
}

static int MainBarGUI_get_floorUpButton(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->floorUpButton);
    return 1;
}

static int MainBarGUI_get_floorText(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->floorText);
    return 1;
}

static int MainBarGUI_get_dayText(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->dayText);
    return 1;
}

static int MainBarGUI_get_moneyLabel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->moneyLabel);
    return 1;
}

static int MainBarGUI_get_moneyText(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->moneyText);
    return 1;
}

static int MainBarGUI_get_timeText(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->timeText);
    return 1;
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
    lua_pushlightuserdata(L, (void*)instance->ordersDataPanel);
    return 1;
}

static int MainBarGUI_get_extendInfoPanelButton(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->extendInfoPanelButton);
    return 1;
}

static int MainBarGUI_get_extendedInfoPanel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->extendedInfoPanel);
    return 1;
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
    lua_pushlightuserdata(L, (void*)instance->biomePanel);
    return 1;
}

static int MainBarGUI_get_biomePanelText(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->biomePanelText);
    return 1;
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
    lua_pushlightuserdata(L, (void*)instance->toolTip);
    return 1;
}

static int MainBarGUI_get_pausePanel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->pausePanel);
    return 1;
}

static int MainBarGUI_get_loadingPanel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    lua_pushlightuserdata(L, (void*)instance->loadingPanel);
    return 1;
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
    instance->portraitSelectedContextIndex = (char)luaL_checkinteger(L, 2);
    return 0;
}

static int MainBarGUI_set_portraitsUpdating(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");
    instance->portraitsUpdating = lua_toboolean(L, 2) != 0;
    return 0;
}

int MainBarGUIBinding::_CONSTRUCTOR(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    MainBarGUI* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
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

int MainBarGUIBinding::getPausePanel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    MyGUI::Widget* result = instance->getPausePanel();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int MainBarGUIBinding::getLoadingPanel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    MyGUI::Widget* result = instance->getLoadingPanel();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
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
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int MainBarGUIBinding::_NV_getToolTip(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    ToolTip* result = instance->_NV_getToolTip();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int MainBarGUIBinding::getDatapanel(lua_State* L)
{
    MainBarGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainBarGUI is nil");

    std::string id = luaL_checkstring(L, 2);
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

    std::string name = luaL_checkstring(L, 2);
    MyGUI::Widget* result = instance->_getWidget(name);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 66: void autoChangeSelectedObject(...) - unsupported arg type
  line 67: void _NV_autoChangeSelectedObject(...) - unsupported arg type
  line 73: PortraitData* getPortrait(...) - overloaded method
  line 74: PortraitData* getPortrait(...) - overloaded method
  line 75: void updatePortrait(...) - unsupported arg type
  line 76: void platoonUpdated(...) - unsupported arg type
  line 80: void updatePortraitSize(...) - unsupported arg type
  line 81: void closeMapWindow(...) - unsupported arg type
  line 82: void toggleMapWindow(...) - unsupported arg type
  line 83: void toggleFactionWindow(...) - unsupported arg type
  line 84: void toggleTechWindow(...) - unsupported arg type
  line 85: void toggleCraftWindow(...) - unsupported arg type
  line 86: void toggleSquadWindow(...) - unsupported arg type
  line 87: void changeFloorButtonUp(...) - unsupported arg type
  line 88: void changeFloorButtonDown(...) - unsupported arg type
  line 92: void ordersPanelFill(...) - unsupported arg type
  line 97: const MyGUI::types::TPoint<int>& getBuildingInventoryPosition(...) - reference return type
  line 99: void serialise(...) - unsupported arg type
  line 100: void loadFromSerialise(...) - unsupported arg type
  line 101: const MainTabPortraitPlatoon& getTabPlatoonPortrait(...) - overloaded method
  line 102: const MainTabPortraitPlatoon& getTabPlatoonPortrait(...) - overloaded method
  line 103: void portraitChangeSelection(...) - unsupported arg type
  line 104: void portraitSelectItemAccept(...) - unsupported arg type
  line 105: void portraitNotifyItem(...) - unsupported arg type
  line 106: void tabPlatoonChange(...) - unsupported arg type
  line 108: void extendInfoPanel(...) - unsupported arg type
  line 109: void toggleInventory(...) - unsupported arg type
  line 110: void toggleStatsWindow(...) - unsupported arg type
  line 111: void toggleHelpWindow(...) - unsupported arg type
  line 112: void changeSpeed(...) - unsupported arg type
  line 113: void buildButton(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 118: datapanels (boost::unordered::unordered_map<std::string, DatapanelGUI*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, DatapanelGUI*>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 126: speedButtons (Ogre::FastArray<MyGUI::Button*>) - unsupported type
  line 135: extendedInfoPanelShow (MyGUI::types::TPoint<int>) - unsupported type
  line 136: extendedInfoPanelHide (MyGUI::types::TPoint<int>) - unsupported type
  line 146: portraitContextMenuTarget (hand) - unsupported type
  line 148: tabPortraits (Ogre::FastArray<MainTabPortraitPlatoon>) - unsupported type
  line 150: portraits (ogre_unordered_map<hand, PortraitData*>::type) - unsupported type
  line 151: portraitsIndices (boost::unordered::unordered_map<PortraitData*, std::pair<PortraitMainItemBox*, unsigned char>, boost::hash<PortraitData*>, std::equal_to<PortraitData*>, Ogre::STLAllocator<std::pair<PortraitData*const, std::pair<PortraitMainItemBox*, unsigned char> >, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 154: toolTipBasePosition (MyGUI::types::TPoint<int>) - unsupported type
  line 157: buildingInventoryPosition (MyGUI::types::TPoint<int>) - unsupported type
  line 158: messagePosition (MyGUI::types::TPoint<int>) - unsupported type
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
        { "updatePotraitsPlatoon", MainBarGUIBinding::updatePotraitsPlatoon },
        { "updatePortraits", MainBarGUIBinding::updatePortraits },
        { "refreshPortraitTabs", MainBarGUIBinding::refreshPortraitTabs },
        { "getPausePanel", MainBarGUIBinding::getPausePanel },
        { "getLoadingPanel", MainBarGUIBinding::getLoadingPanel },
        { "getMedicalPanel", MainBarGUIBinding::getMedicalPanel },
        { "ordersPanelClear", MainBarGUIBinding::ordersPanelClear },
        { "getToolTip", MainBarGUIBinding::getToolTip },
        { "_NV_getToolTip", MainBarGUIBinding::_NV_getToolTip },
        { "getDatapanel", MainBarGUIBinding::getDatapanel },
        { "setMessagePosition", MainBarGUIBinding::setMessagePosition },
        { "setExtendInfoPanelEnabled", MainBarGUIBinding::setExtendInfoPanelEnabled },
        { "_getWidget", MainBarGUIBinding::_getWidget },
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
    lua_pushcfunction(L, MainBarGUI_get_closeManagerWindowMsg);
    lua_setfield(L, -2, "closeManagerWindowMsg");
    lua_pushcfunction(L, MainBarGUI_get_isLevelEditMode);
    lua_setfield(L, -2, "isLevelEditMode");
    lua_pushcfunction(L, MainBarGUI_get_isInteriorLevelEditMode);
    lua_setfield(L, -2, "isInteriorLevelEditMode");
    lua_pushcfunction(L, MainBarGUI_get_bountyPanel);
    lua_setfield(L, -2, "bountyPanel");
    lua_pushcfunction(L, MainBarGUI_get_bountyDatapanel);
    lua_setfield(L, -2, "bountyDatapanel");
    lua_pushcfunction(L, MainBarGUI_get_townPanel);
    lua_setfield(L, -2, "townPanel");
    lua_pushcfunction(L, MainBarGUI_get_portraitsTabPanel);
    lua_setfield(L, -2, "portraitsTabPanel");
    lua_pushcfunction(L, MainBarGUI_get_floorDownButton);
    lua_setfield(L, -2, "floorDownButton");
    lua_pushcfunction(L, MainBarGUI_get_floorUpButton);
    lua_setfield(L, -2, "floorUpButton");
    lua_pushcfunction(L, MainBarGUI_get_floorText);
    lua_setfield(L, -2, "floorText");
    lua_pushcfunction(L, MainBarGUI_get_dayText);
    lua_setfield(L, -2, "dayText");
    lua_pushcfunction(L, MainBarGUI_get_moneyLabel);
    lua_setfield(L, -2, "moneyLabel");
    lua_pushcfunction(L, MainBarGUI_get_moneyText);
    lua_setfield(L, -2, "moneyText");
    lua_pushcfunction(L, MainBarGUI_get_timeText);
    lua_setfield(L, -2, "timeText");
    lua_pushcfunction(L, MainBarGUI_get_medicalPanel);
    lua_setfield(L, -2, "medicalPanel");
    lua_pushcfunction(L, MainBarGUI_get_ordersDataPanel);
    lua_setfield(L, -2, "ordersDataPanel");
    lua_pushcfunction(L, MainBarGUI_get_extendInfoPanelButton);
    lua_setfield(L, -2, "extendInfoPanelButton");
    lua_pushcfunction(L, MainBarGUI_get_extendedInfoPanel);
    lua_setfield(L, -2, "extendedInfoPanel");
    lua_pushcfunction(L, MainBarGUI_get_extendedInfoPanelDuration);
    lua_setfield(L, -2, "extendedInfoPanelDuration");
    lua_pushcfunction(L, MainBarGUI_get_infoPanelEnabled);
    lua_setfield(L, -2, "infoPanelEnabled");
    lua_pushcfunction(L, MainBarGUI_get_infoPanelExtended);
    lua_setfield(L, -2, "infoPanelExtended");
    lua_pushcfunction(L, MainBarGUI_get_biomePanel);
    lua_setfield(L, -2, "biomePanel");
    lua_pushcfunction(L, MainBarGUI_get_biomePanelText);
    lua_setfield(L, -2, "biomePanelText");
    lua_pushcfunction(L, MainBarGUI_get_biomePanelVisibleTimer);
    lua_setfield(L, -2, "biomePanelVisibleTimer");
    lua_pushcfunction(L, MainBarGUI_get_biomeTimer);
    lua_setfield(L, -2, "biomeTimer");
    lua_pushcfunction(L, MainBarGUI_get_lastFrameBiomeGroup);
    lua_setfield(L, -2, "lastFrameBiomeGroup");
    lua_pushcfunction(L, MainBarGUI_get_rememberlastBiomeGroup);
    lua_setfield(L, -2, "rememberlastBiomeGroup");
    lua_pushcfunction(L, MainBarGUI_get_portraitContextMenuTimer);
    lua_setfield(L, -2, "portraitContextMenuTimer");
    lua_pushcfunction(L, MainBarGUI_get_portraitSelectedContextIndex);
    lua_setfield(L, -2, "portraitSelectedContextIndex");
    lua_pushcfunction(L, MainBarGUI_get_portraitsUpdating);
    lua_setfield(L, -2, "portraitsUpdating");
    lua_pushcfunction(L, MainBarGUI_get_toolTip);
    lua_setfield(L, -2, "toolTip");
    lua_pushcfunction(L, MainBarGUI_get_pausePanel);
    lua_setfield(L, -2, "pausePanel");
    lua_pushcfunction(L, MainBarGUI_get_loadingPanel);
    lua_setfield(L, -2, "loadingPanel");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, MainBarGUI_set_closeManagerWindowMsg);
    lua_setfield(L, -2, "closeManagerWindowMsg");
    lua_pushcfunction(L, MainBarGUI_set_isLevelEditMode);
    lua_setfield(L, -2, "isLevelEditMode");
    lua_pushcfunction(L, MainBarGUI_set_isInteriorLevelEditMode);
    lua_setfield(L, -2, "isInteriorLevelEditMode");
    lua_pushcfunction(L, MainBarGUI_set_extendedInfoPanelDuration);
    lua_setfield(L, -2, "extendedInfoPanelDuration");
    lua_pushcfunction(L, MainBarGUI_set_infoPanelEnabled);
    lua_setfield(L, -2, "infoPanelEnabled");
    lua_pushcfunction(L, MainBarGUI_set_infoPanelExtended);
    lua_setfield(L, -2, "infoPanelExtended");
    lua_pushcfunction(L, MainBarGUI_set_biomePanelVisibleTimer);
    lua_setfield(L, -2, "biomePanelVisibleTimer");
    lua_pushcfunction(L, MainBarGUI_set_biomeTimer);
    lua_setfield(L, -2, "biomeTimer");
    lua_pushcfunction(L, MainBarGUI_set_portraitContextMenuTimer);
    lua_setfield(L, -2, "portraitContextMenuTimer");
    lua_pushcfunction(L, MainBarGUI_set_portraitSelectedContextIndex);
    lua_setfield(L, -2, "portraitSelectedContextIndex");
    lua_pushcfunction(L, MainBarGUI_set_portraitsUpdating);
    lua_setfield(L, -2, "portraitsUpdating");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to GUIWindow
    // setMetatableParent(L, MainBarGUIBinding::getMetatableName(), GUIWindowBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
