#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/gui/MainBarGUI.h>

// ---------------------------------------------------------------------------
// Hooks for MainBarGUI.h
//
// Non-virtual members and _NV_ bodies. Events fire after the original call
// except for destructors. Pointer/value results are observational unless the
// callback dispatcher explicitly accepts an override.
//
// Not hooked:
//   MainTabPortraitPlatoon::_CONSTRUCTOR(ActivePlatoon*, MainBarGUI*)
//   MainTabPortraitPlatoon::_CONSTRUCTOR()
//     overloaded; overloads are not hooked
//   MainBarGUI::getPortrait(const MyGUI::IntPoint&)
//   MainBarGUI::getPortrait(const hand&)
//     overloaded; overloads are not hooked
//   MainBarGUI::getTabPlatoonPortrait(int)
//   MainBarGUI::getTabPlatoonPortrait(ActivePlatoon*)
//     overloaded; overloads are not hooked
// ---------------------------------------------------------------------------

static void (*MainTabPortraitPlatoon_addTab_orig)(MainTabPortraitPlatoon*, MyGUI::TabControl*, bool) = NULL;
static void MainTabPortraitPlatoon_addTab_hook(MainTabPortraitPlatoon* thisptr, MyGUI::TabControl* tabControl, bool visible)
{
    MainTabPortraitPlatoon_addTab_orig(thisptr, tabControl, visible);
    CallMainTabPortraitPlatoonAddTabCallbacks(thisptr, tabControl, visible);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainTabPortraitPlatoon_addTab,
    "MainTabPortraitPlatoon::addTab", KenshiLib::GetRealAddress(&MainTabPortraitPlatoon::addTab),
    MainTabPortraitPlatoon_addTab_hook, MainTabPortraitPlatoon_addTab_orig)

static void (*MainTabPortraitPlatoon_detach_orig)(MainTabPortraitPlatoon*) = NULL;
static void MainTabPortraitPlatoon_detach_hook(MainTabPortraitPlatoon* thisptr)
{
    MainTabPortraitPlatoon_detach_orig(thisptr);
    CallMainTabPortraitPlatoonDetachCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainTabPortraitPlatoon_detach,
    "MainTabPortraitPlatoon::detach", KenshiLib::GetRealAddress(&MainTabPortraitPlatoon::detach),
    MainTabPortraitPlatoon_detach_hook, MainTabPortraitPlatoon_detach_orig)

static void (*MainTabPortraitPlatoon_setFlash_orig)(MainTabPortraitPlatoon*, bool) = NULL;
static void MainTabPortraitPlatoon_setFlash_hook(MainTabPortraitPlatoon* thisptr, bool flash)
{
    MainTabPortraitPlatoon_setFlash_orig(thisptr, flash);
    CallMainTabPortraitPlatoonSetFlashCallbacks(thisptr, flash);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainTabPortraitPlatoon_setFlash,
    "MainTabPortraitPlatoon::setFlash", KenshiLib::GetRealAddress(&MainTabPortraitPlatoon::setFlash),
    MainTabPortraitPlatoon_setFlash_hook, MainTabPortraitPlatoon_setFlash_orig)

static void (*MainTabPortraitPlatoon_update_orig)(MainTabPortraitPlatoon*) = NULL;
static void MainTabPortraitPlatoon_update_hook(MainTabPortraitPlatoon* thisptr)
{
    MainTabPortraitPlatoon_update_orig(thisptr);
    CallMainTabPortraitPlatoonUpdateCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainTabPortraitPlatoon_update,
    "MainTabPortraitPlatoon::update", KenshiLib::GetRealAddress(&MainTabPortraitPlatoon::update),
    MainTabPortraitPlatoon_update_hook, MainTabPortraitPlatoon_update_orig)

static void (*MainTabPortraitPlatoon_DESTRUCTOR_orig)(MainTabPortraitPlatoon*) = NULL;
static void MainTabPortraitPlatoon_DESTRUCTOR_hook(MainTabPortraitPlatoon* thisptr)
{
    CallMainTabPortraitPlatoonDestructorCallbacks(thisptr);
    MainTabPortraitPlatoon_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainTabPortraitPlatoon_DESTRUCTOR,
    "MainTabPortraitPlatoon::_DESTRUCTOR", KenshiLib::GetRealAddress(&MainTabPortraitPlatoon::_DESTRUCTOR),
    MainTabPortraitPlatoon_DESTRUCTOR_hook, MainTabPortraitPlatoon_DESTRUCTOR_orig)

static MainBarGUI* (*MainBarGUI_CONSTRUCTOR_orig)(MainBarGUI*) = NULL;
static MainBarGUI* MainBarGUI_CONSTRUCTOR_hook(MainBarGUI* thisptr)
{
    MainBarGUI* res = MainBarGUI_CONSTRUCTOR_orig(thisptr);
    CallMainBarGUIConstructedCallbacks(thisptr);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_CONSTRUCTOR,
    "MainBarGUI::_CONSTRUCTOR", KenshiLib::GetRealAddress(&MainBarGUI::_CONSTRUCTOR),
    MainBarGUI_CONSTRUCTOR_hook, MainBarGUI_CONSTRUCTOR_orig)

static void (*MainBarGUI_DESTRUCTOR_orig)(MainBarGUI*) = NULL;
static void MainBarGUI_DESTRUCTOR_hook(MainBarGUI* thisptr)
{
    CallMainBarGUIDestructorCallbacks(thisptr);
    MainBarGUI_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_DESTRUCTOR,
    "MainBarGUI::_DESTRUCTOR", KenshiLib::GetRealAddress(&MainBarGUI::_DESTRUCTOR),
    MainBarGUI_DESTRUCTOR_hook, MainBarGUI_DESTRUCTOR_orig)

static void (*MainBarGUI__NV_clear_orig)(MainBarGUI*) = NULL;
static void MainBarGUI__NV_clear_hook(MainBarGUI* thisptr)
{
    MainBarGUI__NV_clear_orig(thisptr);
    CallMainBarGUINVclearCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI__NV_clear,
    "MainBarGUI::_NV_clear", KenshiLib::GetRealAddress(&MainBarGUI::_NV_clear),
    MainBarGUI__NV_clear_hook, MainBarGUI__NV_clear_orig)

static void (*MainBarGUI__NV_update_orig)(MainBarGUI*) = NULL;
static void MainBarGUI__NV_update_hook(MainBarGUI* thisptr)
{
    MainBarGUI__NV_update_orig(thisptr);
    CallMainBarGUINVUpdateCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI__NV_update,
    "MainBarGUI::_NV_update", KenshiLib::GetRealAddress(&MainBarGUI::_NV_update),
    MainBarGUI__NV_update_hook, MainBarGUI__NV_update_orig)

static void (*MainBarGUI_speedChanged_orig)(MainBarGUI*) = NULL;
static void MainBarGUI_speedChanged_hook(MainBarGUI* thisptr)
{
    MainBarGUI_speedChanged_orig(thisptr);
    CallMainBarGUISpeedChangedCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_speedChanged,
    "MainBarGUI::speedChanged", KenshiLib::GetRealAddress(&MainBarGUI::speedChanged),
    MainBarGUI_speedChanged_hook, MainBarGUI_speedChanged_orig)

static void (*MainBarGUI__NV_updateBountyPanelVisibility_orig)(MainBarGUI*) = NULL;
static void MainBarGUI__NV_updateBountyPanelVisibility_hook(MainBarGUI* thisptr)
{
    MainBarGUI__NV_updateBountyPanelVisibility_orig(thisptr);
    CallMainBarGUINVUpdateBountyPanelVisibilityCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI__NV_updateBountyPanelVisibility,
    "MainBarGUI::_NV_updateBountyPanelVisibility", KenshiLib::GetRealAddress(&MainBarGUI::_NV_updateBountyPanelVisibility),
    MainBarGUI__NV_updateBountyPanelVisibility_hook, MainBarGUI__NV_updateBountyPanelVisibility_orig)

static void (*MainBarGUI_updatePotraitsPlatoon_orig)(MainBarGUI*) = NULL;
static void MainBarGUI_updatePotraitsPlatoon_hook(MainBarGUI* thisptr)
{
    MainBarGUI_updatePotraitsPlatoon_orig(thisptr);
    CallMainBarGUIUpdatePotraitsPlatoonCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_updatePotraitsPlatoon,
    "MainBarGUI::updatePotraitsPlatoon", KenshiLib::GetRealAddress(&MainBarGUI::updatePotraitsPlatoon),
    MainBarGUI_updatePotraitsPlatoon_hook, MainBarGUI_updatePotraitsPlatoon_orig)

static void (*MainBarGUI_updatePortraits_orig)(MainBarGUI*) = NULL;
static void MainBarGUI_updatePortraits_hook(MainBarGUI* thisptr)
{
    MainBarGUI_updatePortraits_orig(thisptr);
    CallMainBarGUIUpdatePortraitsCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_updatePortraits,
    "MainBarGUI::updatePortraits", KenshiLib::GetRealAddress(&MainBarGUI::updatePortraits),
    MainBarGUI_updatePortraits_hook, MainBarGUI_updatePortraits_orig)

static void (*MainBarGUI_refreshPortraitTabs_orig)(MainBarGUI*) = NULL;
static void MainBarGUI_refreshPortraitTabs_hook(MainBarGUI* thisptr)
{
    MainBarGUI_refreshPortraitTabs_orig(thisptr);
    CallMainBarGUIRefreshPortraitTabsCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_refreshPortraitTabs,
    "MainBarGUI::refreshPortraitTabs", KenshiLib::GetRealAddress(&MainBarGUI::refreshPortraitTabs),
    MainBarGUI_refreshPortraitTabs_hook, MainBarGUI_refreshPortraitTabs_orig)

static void (*MainBarGUI_ordersPanelClear_orig)(MainBarGUI*) = NULL;
static void MainBarGUI_ordersPanelClear_hook(MainBarGUI* thisptr)
{
    MainBarGUI_ordersPanelClear_orig(thisptr);
    CallMainBarGUIOrdersPanelClearCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_ordersPanelClear,
    "MainBarGUI::ordersPanelClear", KenshiLib::GetRealAddress(&MainBarGUI::ordersPanelClear),
    MainBarGUI_ordersPanelClear_hook, MainBarGUI_ordersPanelClear_orig)

static void (*MainBarGUI_setMessagePosition_orig)(MainBarGUI*) = NULL;
static void MainBarGUI_setMessagePosition_hook(MainBarGUI* thisptr)
{
    MainBarGUI_setMessagePosition_orig(thisptr);
    CallMainBarGUISetMessagePositionCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_setMessagePosition,
    "MainBarGUI::setMessagePosition", KenshiLib::GetRealAddress(&MainBarGUI::setMessagePosition),
    MainBarGUI_setMessagePosition_hook, MainBarGUI_setMessagePosition_orig)

static void (*MainBarGUI__NV_show_orig)(MainBarGUI*, bool) = NULL;
static void MainBarGUI__NV_show_hook(MainBarGUI* thisptr, bool on)
{
    MainBarGUI__NV_show_orig(thisptr, on);
    CallMainBarGUINVShowCallbacks(thisptr, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI__NV_show,
    "MainBarGUI::_NV_show", KenshiLib::GetRealAddress(&MainBarGUI::_NV_show),
    MainBarGUI__NV_show_hook, MainBarGUI__NV_show_orig)

static void (*MainBarGUI_setLevelEditMode_orig)(MainBarGUI*, bool) = NULL;
static void MainBarGUI_setLevelEditMode_hook(MainBarGUI* thisptr, bool on)
{
    MainBarGUI_setLevelEditMode_orig(thisptr, on);
    CallMainBarGUISetLevelEditModeCallbacks(thisptr, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_setLevelEditMode,
    "MainBarGUI::setLevelEditMode", KenshiLib::GetRealAddress(&MainBarGUI::setLevelEditMode),
    MainBarGUI_setLevelEditMode_hook, MainBarGUI_setLevelEditMode_orig)

static void (*MainBarGUI_setLevelEditInteriorMode_orig)(MainBarGUI*, bool) = NULL;
static void MainBarGUI_setLevelEditInteriorMode_hook(MainBarGUI* thisptr, bool interiorMode)
{
    MainBarGUI_setLevelEditInteriorMode_orig(thisptr, interiorMode);
    CallMainBarGUISetLevelEditInteriorModeCallbacks(thisptr, interiorMode);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_setLevelEditInteriorMode,
    "MainBarGUI::setLevelEditInteriorMode", KenshiLib::GetRealAddress(&MainBarGUI::setLevelEditInteriorMode),
    MainBarGUI_setLevelEditInteriorMode_hook, MainBarGUI_setLevelEditInteriorMode_orig)

static void (*MainBarGUI_setExtendInfoPanelEnabled_orig)(MainBarGUI*, bool) = NULL;
static void MainBarGUI_setExtendInfoPanelEnabled_hook(MainBarGUI* thisptr, bool enabled)
{
    MainBarGUI_setExtendInfoPanelEnabled_orig(thisptr, enabled);
    CallMainBarGUISetExtendInfoPanelEnabledCallbacks(thisptr, enabled);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_setExtendInfoPanelEnabled,
    "MainBarGUI::setExtendInfoPanelEnabled", KenshiLib::GetRealAddress(&MainBarGUI::setExtendInfoPanelEnabled),
    MainBarGUI_setExtendInfoPanelEnabled_hook, MainBarGUI_setExtendInfoPanelEnabled_orig)

static void (*MainBarGUI__NV_autoChangeSelectedObject_orig)(MainBarGUI*, const hand&) = NULL;
static void MainBarGUI__NV_autoChangeSelectedObject_hook(MainBarGUI* thisptr, const hand& obj)
{
    MainBarGUI__NV_autoChangeSelectedObject_orig(thisptr, obj);
    CallMainBarGUINVAutoChangeSelectedObjectCallbacks(thisptr, obj);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI__NV_autoChangeSelectedObject,
    "MainBarGUI::_NV_autoChangeSelectedObject", KenshiLib::GetRealAddress(&MainBarGUI::_NV_autoChangeSelectedObject),
    MainBarGUI__NV_autoChangeSelectedObject_hook, MainBarGUI__NV_autoChangeSelectedObject_orig)

static void (*MainBarGUI_pressedKey_orig)(MainBarGUI*, unsigned int) = NULL;
static void MainBarGUI_pressedKey_hook(MainBarGUI* thisptr, unsigned int keycode)
{
    MainBarGUI_pressedKey_orig(thisptr, keycode);
    CallMainBarGUIPressedKeyCallbacks(thisptr, static_cast<int>(keycode));
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_pressedKey,
    "MainBarGUI::pressedKey", KenshiLib::GetRealAddress(&MainBarGUI::pressedKey),
    MainBarGUI_pressedKey_hook, MainBarGUI_pressedKey_orig)

static void (*MainBarGUI_updatePortrait_orig)(MainBarGUI*, const hand&) = NULL;
static void MainBarGUI_updatePortrait_hook(MainBarGUI* thisptr, const hand& character)
{
    MainBarGUI_updatePortrait_orig(thisptr, character);
    CallMainBarGUIUpdatePortraitCallbacks(thisptr, character);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_updatePortrait,
    "MainBarGUI::updatePortrait", KenshiLib::GetRealAddress(&MainBarGUI::updatePortrait),
    MainBarGUI_updatePortrait_hook, MainBarGUI_updatePortrait_orig)

static void (*MainBarGUI_platoonUpdated_orig)(MainBarGUI*, RootObjectContainer*, bool) = NULL;
static void MainBarGUI_platoonUpdated_hook(MainBarGUI* thisptr, RootObjectContainer* platoon, bool charAdded)
{
    MainBarGUI_platoonUpdated_orig(thisptr, platoon, charAdded);
    CallMainBarGUIPlatoonUpdatedCallbacks(thisptr, platoon, charAdded);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_platoonUpdated,
    "MainBarGUI::platoonUpdated", KenshiLib::GetRealAddress(&MainBarGUI::platoonUpdated),
    MainBarGUI_platoonUpdated_hook, MainBarGUI_platoonUpdated_orig)

static void (*MainBarGUI_updatePortraitSize_orig)(MainBarGUI*, ActivePlatoon*) = NULL;
static void MainBarGUI_updatePortraitSize_hook(MainBarGUI* thisptr, ActivePlatoon* platoon)
{
    MainBarGUI_updatePortraitSize_orig(thisptr, platoon);
    CallMainBarGUIUpdatePortraitSizeCallbacks(thisptr, platoon);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_updatePortraitSize,
    "MainBarGUI::updatePortraitSize", KenshiLib::GetRealAddress(&MainBarGUI::updatePortraitSize),
    MainBarGUI_updatePortraitSize_hook, MainBarGUI_updatePortraitSize_orig)

static void (*MainBarGUI_closeMapWindow_orig)(MainBarGUI*, MyGUI::Widget*) = NULL;
static void MainBarGUI_closeMapWindow_hook(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    MainBarGUI_closeMapWindow_orig(thisptr, sender);
    CallMainBarGUICloseMapWindowCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_closeMapWindow,
    "MainBarGUI::closeMapWindow", KenshiLib::GetRealAddress(&MainBarGUI::closeMapWindow),
    MainBarGUI_closeMapWindow_hook, MainBarGUI_closeMapWindow_orig)

static void (*MainBarGUI_toggleMapWindow_orig)(MainBarGUI*, MyGUI::Widget*) = NULL;
static void MainBarGUI_toggleMapWindow_hook(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    MainBarGUI_toggleMapWindow_orig(thisptr, sender);
    CallMainBarGUIToggleMapWindowCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_toggleMapWindow,
    "MainBarGUI::toggleMapWindow", KenshiLib::GetRealAddress(&MainBarGUI::toggleMapWindow),
    MainBarGUI_toggleMapWindow_hook, MainBarGUI_toggleMapWindow_orig)

static void (*MainBarGUI_toggleFactionWindow_orig)(MainBarGUI*, MyGUI::Widget*) = NULL;
static void MainBarGUI_toggleFactionWindow_hook(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    MainBarGUI_toggleFactionWindow_orig(thisptr, sender);
    CallMainBarGUIToggleFactionWindowCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_toggleFactionWindow,
    "MainBarGUI::toggleFactionWindow", KenshiLib::GetRealAddress(&MainBarGUI::toggleFactionWindow),
    MainBarGUI_toggleFactionWindow_hook, MainBarGUI_toggleFactionWindow_orig)

static void (*MainBarGUI_toggleTechWindow_orig)(MainBarGUI*, MyGUI::Widget*) = NULL;
static void MainBarGUI_toggleTechWindow_hook(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    MainBarGUI_toggleTechWindow_orig(thisptr, sender);
    CallMainBarGUIToggleTechWindowCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_toggleTechWindow,
    "MainBarGUI::toggleTechWindow", KenshiLib::GetRealAddress(&MainBarGUI::toggleTechWindow),
    MainBarGUI_toggleTechWindow_hook, MainBarGUI_toggleTechWindow_orig)

static void (*MainBarGUI_toggleCraftWindow_orig)(MainBarGUI*, MyGUI::Widget*) = NULL;
static void MainBarGUI_toggleCraftWindow_hook(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    MainBarGUI_toggleCraftWindow_orig(thisptr, sender);
    CallMainBarGUIToggleCraftWindowCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_toggleCraftWindow,
    "MainBarGUI::toggleCraftWindow", KenshiLib::GetRealAddress(&MainBarGUI::toggleCraftWindow),
    MainBarGUI_toggleCraftWindow_hook, MainBarGUI_toggleCraftWindow_orig)

static void (*MainBarGUI_toggleSquadWindow_orig)(MainBarGUI*, MyGUI::Widget*) = NULL;
static void MainBarGUI_toggleSquadWindow_hook(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    MainBarGUI_toggleSquadWindow_orig(thisptr, sender);
    CallMainBarGUIToggleSquadWindowCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_toggleSquadWindow,
    "MainBarGUI::toggleSquadWindow", KenshiLib::GetRealAddress(&MainBarGUI::toggleSquadWindow),
    MainBarGUI_toggleSquadWindow_hook, MainBarGUI_toggleSquadWindow_orig)

static void (*MainBarGUI_changeFloorButtonUp_orig)(MainBarGUI*, MyGUI::Widget*) = NULL;
static void MainBarGUI_changeFloorButtonUp_hook(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    MainBarGUI_changeFloorButtonUp_orig(thisptr, sender);
    CallMainBarGUIChangeFloorButtonUpCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_changeFloorButtonUp,
    "MainBarGUI::changeFloorButtonUp", KenshiLib::GetRealAddress(&MainBarGUI::changeFloorButtonUp),
    MainBarGUI_changeFloorButtonUp_hook, MainBarGUI_changeFloorButtonUp_orig)

static void (*MainBarGUI_changeFloorButtonDown_orig)(MainBarGUI*, MyGUI::Widget*) = NULL;
static void MainBarGUI_changeFloorButtonDown_hook(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    MainBarGUI_changeFloorButtonDown_orig(thisptr, sender);
    CallMainBarGUIChangeFloorButtonDownCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_changeFloorButtonDown,
    "MainBarGUI::changeFloorButtonDown", KenshiLib::GetRealAddress(&MainBarGUI::changeFloorButtonDown),
    MainBarGUI_changeFloorButtonDown_hook, MainBarGUI_changeFloorButtonDown_orig)

static void (*MainBarGUI_toggleInventory_orig)(MainBarGUI*, MyGUI::Widget*) = NULL;
static void MainBarGUI_toggleInventory_hook(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    MainBarGUI_toggleInventory_orig(thisptr, sender);
    CallMainBarGUIToggleInventoryCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_toggleInventory,
    "MainBarGUI::toggleInventory", KenshiLib::GetRealAddress(&MainBarGUI::toggleInventory),
    MainBarGUI_toggleInventory_hook, MainBarGUI_toggleInventory_orig)

static void (*MainBarGUI_toggleStatsWindow_orig)(MainBarGUI*, MyGUI::Widget*) = NULL;
static void MainBarGUI_toggleStatsWindow_hook(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    MainBarGUI_toggleStatsWindow_orig(thisptr, sender);
    CallMainBarGUIToggleStatsWindowCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_toggleStatsWindow,
    "MainBarGUI::toggleStatsWindow", KenshiLib::GetRealAddress(&MainBarGUI::toggleStatsWindow),
    MainBarGUI_toggleStatsWindow_hook, MainBarGUI_toggleStatsWindow_orig)

static void (*MainBarGUI_toggleHelpWindow_orig)(MainBarGUI*, MyGUI::Widget*) = NULL;
static void MainBarGUI_toggleHelpWindow_hook(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    MainBarGUI_toggleHelpWindow_orig(thisptr, sender);
    CallMainBarGUIToggleHelpWindowCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_toggleHelpWindow,
    "MainBarGUI::toggleHelpWindow", KenshiLib::GetRealAddress(&MainBarGUI::toggleHelpWindow),
    MainBarGUI_toggleHelpWindow_hook, MainBarGUI_toggleHelpWindow_orig)

static void (*MainBarGUI_changeSpeed_orig)(MainBarGUI*, MyGUI::Widget*) = NULL;
static void MainBarGUI_changeSpeed_hook(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    MainBarGUI_changeSpeed_orig(thisptr, sender);
    CallMainBarGUIChangeSpeedCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_changeSpeed,
    "MainBarGUI::changeSpeed", KenshiLib::GetRealAddress(&MainBarGUI::changeSpeed),
    MainBarGUI_changeSpeed_hook, MainBarGUI_changeSpeed_orig)

static void (*MainBarGUI_buildButton_orig)(MainBarGUI*, MyGUI::Widget*) = NULL;
static void MainBarGUI_buildButton_hook(MainBarGUI* thisptr, MyGUI::Widget* sender)
{
    MainBarGUI_buildButton_orig(thisptr, sender);
    CallMainBarGUIBuildButtonCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_buildButton,
    "MainBarGUI::buildButton", KenshiLib::GetRealAddress(&MainBarGUI::buildButton),
    MainBarGUI_buildButton_hook, MainBarGUI_buildButton_orig)

static void (*MainBarGUI_ordersPanelFill_orig)(MainBarGUI*, const hand&) = NULL;
static void MainBarGUI_ordersPanelFill_hook(MainBarGUI* thisptr, const hand& character)
{
    MainBarGUI_ordersPanelFill_orig(thisptr, character);
    CallMainBarGUIOrdersPanelFillCallbacks(thisptr, character);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_ordersPanelFill,
    "MainBarGUI::ordersPanelFill", KenshiLib::GetRealAddress(&MainBarGUI::ordersPanelFill),
    MainBarGUI_ordersPanelFill_hook, MainBarGUI_ordersPanelFill_orig)

static void (*MainBarGUI_serialise_orig)(MainBarGUI*, GameData*) = NULL;
static void MainBarGUI_serialise_hook(MainBarGUI* thisptr, GameData* data)
{
    MainBarGUI_serialise_orig(thisptr, data);
    CallMainBarGUISerialiseCallbacks(thisptr, data);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_serialise,
    "MainBarGUI::serialise", KenshiLib::GetRealAddress(&MainBarGUI::serialise),
    MainBarGUI_serialise_hook, MainBarGUI_serialise_orig)

static void (*MainBarGUI_loadFromSerialise_orig)(MainBarGUI*, GameData*) = NULL;
static void MainBarGUI_loadFromSerialise_hook(MainBarGUI* thisptr, GameData* data)
{
    MainBarGUI_loadFromSerialise_orig(thisptr, data);
    CallMainBarGUILoadFromSerialiseCallbacks(thisptr, data);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_loadFromSerialise,
    "MainBarGUI::loadFromSerialise", KenshiLib::GetRealAddress(&MainBarGUI::loadFromSerialise),
    MainBarGUI_loadFromSerialise_hook, MainBarGUI_loadFromSerialise_orig)

static void (*MainBarGUI_portraitChangeSelection_orig)(MainBarGUI*, MyGUI::ItemBox*, unsigned __int64, bool) = NULL;
static void MainBarGUI_portraitChangeSelection_hook(MainBarGUI* thisptr, MyGUI::ItemBox* sender, unsigned __int64 index, bool follow)
{
    MainBarGUI_portraitChangeSelection_orig(thisptr, sender, index, follow);
    CallMainBarGUIPortraitChangeSelectionCallbacks(thisptr, sender, static_cast<double>(index), follow);
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_portraitChangeSelection,
    "MainBarGUI::portraitChangeSelection", KenshiLib::GetRealAddress(&MainBarGUI::portraitChangeSelection),
    MainBarGUI_portraitChangeSelection_hook, MainBarGUI_portraitChangeSelection_orig)

static void (*MainBarGUI_portraitSelectItemAccept_orig)(MainBarGUI*, MyGUI::ItemBox*, unsigned __int64) = NULL;
static void MainBarGUI_portraitSelectItemAccept_hook(MainBarGUI* thisptr, MyGUI::ItemBox* sender, unsigned __int64 index)
{
    MainBarGUI_portraitSelectItemAccept_orig(thisptr, sender, index);
    CallMainBarGUIPortraitSelectItemAcceptCallbacks(thisptr, sender, static_cast<double>(index));
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_portraitSelectItemAccept,
    "MainBarGUI::portraitSelectItemAccept", KenshiLib::GetRealAddress(&MainBarGUI::portraitSelectItemAccept),
    MainBarGUI_portraitSelectItemAccept_hook, MainBarGUI_portraitSelectItemAccept_orig)

static void (*MainBarGUI_portraitNotifyItem_orig)(MainBarGUI*, MyGUI::ItemBox*, const MyGUI::IBNotifyItemData&) = NULL;
static void MainBarGUI_portraitNotifyItem_hook(MainBarGUI* thisptr, MyGUI::ItemBox* sender, const MyGUI::IBNotifyItemData& info)
{
    MainBarGUI_portraitNotifyItem_orig(thisptr, sender, info);
    CallMainBarGUIPortraitNotifyItemCallbacks(thisptr, sender, const_cast<MyGUI::IBNotifyItemData*>(&info));
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_portraitNotifyItem,
    "MainBarGUI::portraitNotifyItem", KenshiLib::GetRealAddress(&MainBarGUI::portraitNotifyItem),
    MainBarGUI_portraitNotifyItem_hook, MainBarGUI_portraitNotifyItem_orig)

static void (*MainBarGUI_tabPlatoonChange_orig)(MainBarGUI*, MyGUI::TabControl*, unsigned __int64) = NULL;
static void MainBarGUI_tabPlatoonChange_hook(MainBarGUI* thisptr, MyGUI::TabControl* sender, unsigned __int64 index)
{
    MainBarGUI_tabPlatoonChange_orig(thisptr, sender, index);
    CallMainBarGUITabPlatoonChangeCallbacks(thisptr, sender, static_cast<double>(index));
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_tabPlatoonChange,
    "MainBarGUI::tabPlatoonChange", KenshiLib::GetRealAddress(&MainBarGUI::tabPlatoonChange),
    MainBarGUI_tabPlatoonChange_hook, MainBarGUI_tabPlatoonChange_orig)

static void (*MainBarGUI_extendInfoPanel_orig)(MainBarGUI*, MyGUI::Widget*, int, int, MyGUI::MouseButton) = NULL;
static void MainBarGUI_extendInfoPanel_hook(MainBarGUI* thisptr, MyGUI::Widget* sender, int left, int top, MyGUI::MouseButton id)
{
    MainBarGUI_extendInfoPanel_orig(thisptr, sender, left, top, id);
    CallMainBarGUIExtendInfoPanelCallbacks(thisptr, sender, left, top, id.getValue());
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_extendInfoPanel,
    "MainBarGUI::extendInfoPanel", KenshiLib::GetRealAddress(&MainBarGUI::extendInfoPanel),
    MainBarGUI_extendInfoPanel_hook, MainBarGUI_extendInfoPanel_orig)

static MyGUI::Widget* (*MainBarGUI_getPausePanel_orig)(MainBarGUI*) = NULL;
static MyGUI::Widget* MainBarGUI_getPausePanel_hook(MainBarGUI* thisptr)
{
    MyGUI::Widget* res = MainBarGUI_getPausePanel_orig(thisptr);
    CallMainBarGUIGetPausePanelCallbacks(const_cast<MainBarGUI*>(thisptr), res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_getPausePanel,
    "MainBarGUI::getPausePanel", KenshiLib::GetRealAddress(&MainBarGUI::getPausePanel),
    MainBarGUI_getPausePanel_hook, MainBarGUI_getPausePanel_orig)

static MyGUI::Widget* (*MainBarGUI_getLoadingPanel_orig)(MainBarGUI*) = NULL;
static MyGUI::Widget* MainBarGUI_getLoadingPanel_hook(MainBarGUI* thisptr)
{
    MyGUI::Widget* res = MainBarGUI_getLoadingPanel_orig(thisptr);
    CallMainBarGUIGetLoadingPanelCallbacks(const_cast<MainBarGUI*>(thisptr), res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_getLoadingPanel,
    "MainBarGUI::getLoadingPanel", KenshiLib::GetRealAddress(&MainBarGUI::getLoadingPanel),
    MainBarGUI_getLoadingPanel_hook, MainBarGUI_getLoadingPanel_orig)

static MedicalDatapanel* (*MainBarGUI_getMedicalPanel_orig)(const MainBarGUI*) = NULL;
static MedicalDatapanel* MainBarGUI_getMedicalPanel_hook(const MainBarGUI* thisptr)
{
    MedicalDatapanel* res = MainBarGUI_getMedicalPanel_orig(thisptr);
    CallMainBarGUIGetMedicalPanelCallbacks(const_cast<MainBarGUI*>(thisptr), res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_getMedicalPanel,
    "MainBarGUI::getMedicalPanel", KenshiLib::GetRealAddress(&MainBarGUI::getMedicalPanel),
    MainBarGUI_getMedicalPanel_hook, MainBarGUI_getMedicalPanel_orig)

static ToolTip* (*MainBarGUI__NV_getToolTip_orig)(MainBarGUI*) = NULL;
static ToolTip* MainBarGUI__NV_getToolTip_hook(MainBarGUI* thisptr)
{
    ToolTip* res = MainBarGUI__NV_getToolTip_orig(thisptr);
    ToolTip* overrideRes = CallMainBarGUINVGetToolTipCallbacks(const_cast<MainBarGUI*>(thisptr), res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI__NV_getToolTip,
    "MainBarGUI::_NV_getToolTip", KenshiLib::GetRealAddress(&MainBarGUI::_NV_getToolTip),
    MainBarGUI__NV_getToolTip_hook, MainBarGUI__NV_getToolTip_orig)

static DatapanelGUI* (*MainBarGUI_getDatapanel_orig)(const MainBarGUI*, const std::string&) = NULL;
static DatapanelGUI* MainBarGUI_getDatapanel_hook(const MainBarGUI* thisptr, const std::string& id)
{
    DatapanelGUI* res = MainBarGUI_getDatapanel_orig(thisptr, id);
    DatapanelGUI* overrideRes = CallMainBarGUIGetDatapanelCallbacks(const_cast<MainBarGUI*>(thisptr), id, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_getDatapanel,
    "MainBarGUI::getDatapanel", KenshiLib::GetRealAddress(&MainBarGUI::getDatapanel),
    MainBarGUI_getDatapanel_hook, MainBarGUI_getDatapanel_orig)

static const MyGUI::types::TPoint<int>& (*MainBarGUI_getBuildingInventoryPosition_orig)(const MainBarGUI*) = NULL;
static const MyGUI::types::TPoint<int>& MainBarGUI_getBuildingInventoryPosition_hook(const MainBarGUI* thisptr)
{
    const MyGUI::types::TPoint<int>& res = MainBarGUI_getBuildingInventoryPosition_orig(thisptr);
    CallMainBarGUIGetBuildingInventoryPositionCallbacks(const_cast<MainBarGUI*>(thisptr), res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI_getBuildingInventoryPosition,
    "MainBarGUI::getBuildingInventoryPosition", KenshiLib::GetRealAddress(&MainBarGUI::getBuildingInventoryPosition),
    MainBarGUI_getBuildingInventoryPosition_hook, MainBarGUI_getBuildingInventoryPosition_orig)

static MyGUI::Widget* (*MainBarGUI__getWidget_orig)(MainBarGUI*, const std::string&) = NULL;
static MyGUI::Widget* MainBarGUI__getWidget_hook(MainBarGUI* thisptr, const std::string& name)
{
    MyGUI::Widget* res = MainBarGUI__getWidget_orig(thisptr, name);
    CallMainBarGUIGetWidgetCallbacks(const_cast<MainBarGUI*>(thisptr), name, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_MainBarGUI__getWidget,
    "MainBarGUI::_getWidget", KenshiLib::GetRealAddress(&MainBarGUI::_getWidget),
    MainBarGUI__getWidget_hook, MainBarGUI__getWidget_orig)
