#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/gui/ForgottenGUI.h>

// ---------------------------------------------------------------------------
// Hooks for ForgottenGUI.h
//
// Non-virtual members and the _NV_ bodies of virtual members. Events fire after
// the original call unless noted; getters pass the original result as
// defaultVal and accept an override from Lua.
//
// Not hooked:
//   ForgottenGUI::destroy(ScreenLabelInterface*)
//     overloaded; overloads are not hooked
//   ForgottenGUI::destroy(DatapanelGUI*)
//     overloaded; overloads are not hooked
//   ForgottenGUI::destroy(GUIWindow*)
//     overloaded; overloads are not hooked
//   ForgottenGUI::createDatapanel(const std::string&, MyGUI::Widget*, bool)
//     overloaded; overloads are not hooked
//   ForgottenGUI::createDatapanel(float, float, float, float, bool, std::string, bool)
//     overloaded; overloads are not hooked
//   ForgottenGUI::isVisible()
//     RVA 0xDEDD0 lies outside the class code; possibly an identical-code-folded copy shared with other functions (unverified)
//   ForgottenGUI::isCharacterEditorMode()
//     RVA 0x47A180 lies outside the class code; possibly an identical-code-folded copy shared with other functions (unverified)
//   ForgottenGUI::characterStatsWindowVisible()
//     RVA 0x91BEE0 lies outside the class code; possibly an identical-code-folded copy shared with other functions (unverified)
//   ForgottenGUI::getSelectedObject() const
//     RVA 0x569BE0 lies outside the class code; possibly an identical-code-folded copy shared with other functions (unverified)
//   ForgottenGUI::getSelectedPlayerCharacter() const
//     RVA 0x32D8F0 lies outside the class code; possibly an identical-code-folded copy shared with other functions (unverified)
//   ForgottenGUI::destroyWidgets(MyGUI::Enumerator<std::vector<MyGUI::Widget*> >&)
//     overloaded; overloads are not hooked
//   ForgottenGUI::destroyWidgets(const std::vector<MyGUI::Widget*>&)
//     overloaded; overloads are not hooked
//   ForgottenGUI::changeMouseCursor(CursorType, const hand&, const hand&)
//     overloaded; overloads are not hooked
//   ForgottenGUI::changeMouseCursor(CursorType)
//     overloaded; overloads are not hooked
//   ForgottenGUI::getGuiManager()
//     RVA 0x6EE0D0 lies outside the class code; possibly an identical-code-folded copy shared with other functions (unverified)
//   ForgottenGUI::createInventoryWindow(const hand&, Inventory*, InventoryLayout*, RootObject*)
//     overloaded; overloads are not hooked
//   ForgottenGUI::createInventoryWindow(const hand&, InventoryLayout*)
//     overloaded; overloads are not hooked
//   ForgottenGUI::createLabel(MyGUI::Widget*, float, float, float, float, const std::string&, const std::string&)
//     overloaded; overloads are not hooked
//   ForgottenGUI::createLabel(MyGUI::Widget*, float, float, float, float, const std::string&, MyGUI::Align)
//     overloaded; overloads are not hooked
//   ForgottenGUI::createLabelAbs(MyGUI::Widget*, int, int, int, int, const std::string&, MyGUI::Align)
//     overloaded; overloads are not hooked
//   ForgottenGUI::createLabelAbs(MyGUI::Widget*, int, int, int, int, const std::string&, const std::string&)
//     overloaded; overloads are not hooked
//   ForgottenGUI::createEditBox(MyGUI::Widget*, float, float, float, float, const std::string&, const std::string&, bool)
//     overloaded; overloads are not hooked
//   ForgottenGUI::createEditBox(MyGUI::Widget*, float, float, float, float, const std::string&, bool)
//     overloaded; overloads are not hooked
//   ForgottenGUI::createEditBoxAbs(MyGUI::Widget*, int, int, int, int, const std::string&, const std::string&, bool)
//     overloaded; overloads are not hooked
//   ForgottenGUI::createEditBoxAbs(MyGUI::Widget*, int, int, int, int, const std::string&, bool)
//     overloaded; overloads are not hooked
// ---------------------------------------------------------------------------

static ForgottenGUI* (*ForgottenGUI_CONSTRUCTOR_orig)(ForgottenGUI*) = NULL;
static ForgottenGUI* ForgottenGUI_CONSTRUCTOR_hook(ForgottenGUI* thisptr)
{
    ForgottenGUI* res = ForgottenGUI_CONSTRUCTOR_orig(thisptr);
    CallForgottenGUIConstructedCallbacks(thisptr);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_CONSTRUCTOR,
    "ForgottenGUI::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&ForgottenGUI::_CONSTRUCTOR),
    ForgottenGUI_CONSTRUCTOR_hook, ForgottenGUI_CONSTRUCTOR_orig)

static void (*ForgottenGUI_DESTRUCTOR_orig)(ForgottenGUI*) = NULL;
static void ForgottenGUI_DESTRUCTOR_hook(ForgottenGUI* thisptr)
{
    CallForgottenGUIDestructorCallbacks(thisptr);
    ForgottenGUI_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_DESTRUCTOR,
    "ForgottenGUI::_DESTRUCTOR",
    KenshiLib::GetRealAddress(&ForgottenGUI::_DESTRUCTOR),
    ForgottenGUI_DESTRUCTOR_hook, ForgottenGUI_DESTRUCTOR_orig)

static void (*ForgottenGUI_clearGUI_orig)(ForgottenGUI*) = NULL;
static void ForgottenGUI_clearGUI_hook(ForgottenGUI* thisptr)
{
    ForgottenGUI_clearGUI_orig(thisptr);
    CallForgottenGUIClearGUICallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_clearGUI,
    "ForgottenGUI::clearGUI",
    KenshiLib::GetRealAddress(&ForgottenGUI::clearGUI),
    ForgottenGUI_clearGUI_hook, ForgottenGUI_clearGUI_orig)

static void (*ForgottenGUI_shutDown_orig)(ForgottenGUI*) = NULL;
static void ForgottenGUI_shutDown_hook(ForgottenGUI* thisptr)
{
    CallForgottenGUIShutDownCallbacks(thisptr);
    ForgottenGUI_shutDown_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_shutDown,
    "ForgottenGUI::shutDown",
    KenshiLib::GetRealAddress(&ForgottenGUI::shutDown),
    ForgottenGUI_shutDown_hook, ForgottenGUI_shutDown_orig)

static void (*ForgottenGUI_restart_orig)(ForgottenGUI*) = NULL;
static void ForgottenGUI_restart_hook(ForgottenGUI* thisptr)
{
    ForgottenGUI_restart_orig(thisptr);
    CallForgottenGUIRestartCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_restart,
    "ForgottenGUI::restart",
    KenshiLib::GetRealAddress(&ForgottenGUI::restart),
    ForgottenGUI_restart_hook, ForgottenGUI_restart_orig)

static void (*ForgottenGUI_changeFontSize_orig)() = NULL;
static void ForgottenGUI_changeFontSize_hook()
{
    ForgottenGUI_changeFontSize_orig();
    CallForgottenGUIChangeFontSizeCallbacks();
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_changeFontSize,
    "ForgottenGUI::changeFontSize",
    KenshiLib::GetRealAddress(&ForgottenGUI::changeFontSize),
    ForgottenGUI_changeFontSize_hook, ForgottenGUI_changeFontSize_orig)

static void (*ForgottenGUI_setupGuiScaling_orig)(ForgottenGUI*) = NULL;
static void ForgottenGUI_setupGuiScaling_hook(ForgottenGUI* thisptr)
{
    ForgottenGUI_setupGuiScaling_orig(thisptr);
    CallForgottenGUISetupGuiScalingCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_setupGuiScaling,
    "ForgottenGUI::setupGuiScaling",
    KenshiLib::GetRealAddress(&ForgottenGUI::setupGuiScaling),
    ForgottenGUI_setupGuiScaling_hook, ForgottenGUI_setupGuiScaling_orig)

static void (*ForgottenGUI_init_orig)(ForgottenGUI*) = NULL;
static void ForgottenGUI_init_hook(ForgottenGUI* thisptr)
{
    ForgottenGUI_init_orig(thisptr);
    CallForgottenGUIInitCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_init,
    "ForgottenGUI::init",
    KenshiLib::GetRealAddress(&ForgottenGUI::init),
    ForgottenGUI_init_hook, ForgottenGUI_init_orig)

static float (*ForgottenGUI_getTopOfScreenMessagePosition_orig)(ForgottenGUI*) = NULL;
static float ForgottenGUI_getTopOfScreenMessagePosition_hook(ForgottenGUI* thisptr)
{
    float res = ForgottenGUI_getTopOfScreenMessagePosition_orig(thisptr);
    return CallForgottenGUIGetTopOfScreenMessagePositionCallbacks(thisptr, res);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_getTopOfScreenMessagePosition,
    "ForgottenGUI::getTopOfScreenMessagePosition",
    KenshiLib::GetRealAddress(&ForgottenGUI::getTopOfScreenMessagePosition),
    ForgottenGUI_getTopOfScreenMessagePosition_hook, ForgottenGUI_getTopOfScreenMessagePosition_orig)

static void (*ForgottenGUI_showLoadingMessage_orig)(ForgottenGUI*, bool) = NULL;
static void ForgottenGUI_showLoadingMessage_hook(ForgottenGUI* thisptr, bool on)
{
    ForgottenGUI_showLoadingMessage_orig(thisptr, on);
    CallForgottenGUIShowLoadingMessageCallbacks(thisptr, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_showLoadingMessage,
    "ForgottenGUI::showLoadingMessage",
    KenshiLib::GetRealAddress(&ForgottenGUI::showLoadingMessage),
    ForgottenGUI_showLoadingMessage_hook, ForgottenGUI_showLoadingMessage_orig)

static bool (*ForgottenGUI_isLoadingMessageVisible_orig)(ForgottenGUI*) = NULL;
static bool ForgottenGUI_isLoadingMessageVisible_hook(ForgottenGUI* thisptr)
{
    bool res = ForgottenGUI_isLoadingMessageVisible_orig(thisptr);
    return CallForgottenGUIIsLoadingMessageVisibleCallbacks(thisptr, res);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_isLoadingMessageVisible,
    "ForgottenGUI::isLoadingMessageVisible",
    KenshiLib::GetRealAddress(&ForgottenGUI::isLoadingMessageVisible),
    ForgottenGUI_isLoadingMessageVisible_hook, ForgottenGUI_isLoadingMessageVisible_orig)

static void (*ForgottenGUI_showPauseMessage_orig)(ForgottenGUI*, bool) = NULL;
static void ForgottenGUI_showPauseMessage_hook(ForgottenGUI* thisptr, bool on)
{
    ForgottenGUI_showPauseMessage_orig(thisptr, on);
    CallForgottenGUIShowPauseMessageCallbacks(thisptr, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_showPauseMessage,
    "ForgottenGUI::showPauseMessage",
    KenshiLib::GetRealAddress(&ForgottenGUI::showPauseMessage),
    ForgottenGUI_showPauseMessage_hook, ForgottenGUI_showPauseMessage_orig)

static bool (*ForgottenGUI_isLoading_orig)(const ForgottenGUI*) = NULL;
static bool ForgottenGUI_isLoading_hook(const ForgottenGUI* thisptr)
{
    bool res = ForgottenGUI_isLoading_orig(thisptr);
    return CallForgottenGUIIsLoadingCallbacks(const_cast<ForgottenGUI*>(thisptr), res);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_isLoading,
    "ForgottenGUI::isLoading",
    KenshiLib::GetRealAddress(&ForgottenGUI::isLoading),
    ForgottenGUI_isLoading_hook, ForgottenGUI_isLoading_orig)

static void (*ForgottenGUI_setLoading_orig)(ForgottenGUI*, bool) = NULL;
static void ForgottenGUI_setLoading_hook(ForgottenGUI* thisptr, bool value)
{
    ForgottenGUI_setLoading_orig(thisptr, value);
    CallForgottenGUISetLoadingCallbacks(thisptr, value);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_setLoading,
    "ForgottenGUI::setLoading",
    KenshiLib::GetRealAddress(&ForgottenGUI::setLoading),
    ForgottenGUI_setLoading_hook, ForgottenGUI_setLoading_orig)

static bool (*ForgottenGUI_isPaused_orig)(const ForgottenGUI*) = NULL;
static bool ForgottenGUI_isPaused_hook(const ForgottenGUI* thisptr)
{
    bool res = ForgottenGUI_isPaused_orig(thisptr);
    return CallForgottenGUIIsPausedCallbacks(const_cast<ForgottenGUI*>(thisptr), res);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_isPaused,
    "ForgottenGUI::isPaused",
    KenshiLib::GetRealAddress(&ForgottenGUI::isPaused),
    ForgottenGUI_isPaused_hook, ForgottenGUI_isPaused_orig)

static bool (*ForgottenGUI_inDialogue_orig)(const ForgottenGUI*) = NULL;
static bool ForgottenGUI_inDialogue_hook(const ForgottenGUI* thisptr)
{
    bool res = ForgottenGUI_inDialogue_orig(thisptr);
    return CallForgottenGUIInDialogueCallbacks(const_cast<ForgottenGUI*>(thisptr), res);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_inDialogue,
    "ForgottenGUI::inDialogue",
    KenshiLib::GetRealAddress(&ForgottenGUI::inDialogue),
    ForgottenGUI_inDialogue_hook, ForgottenGUI_inDialogue_orig)

static MyGUI::Window* (*ForgottenGUI_messageBox_orig)(ForgottenGUI*, const std::string&, const std::string&, int, bool, MyGUI::delegates::IDelegate1<int>*) = NULL;
static MyGUI::Window* ForgottenGUI_messageBox_hook(ForgottenGUI* thisptr, const std::string& title, const std::string& message, int btn, bool modal, MyGUI::delegates::IDelegate1<int>* callback)
{
    MyGUI::Window* res = ForgottenGUI_messageBox_orig(thisptr, title, message, btn, modal, callback);
    CallForgottenGUIMessageBoxCallbacks(thisptr, title, message, btn, modal, (void*)callback, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_messageBox,
    "ForgottenGUI::messageBox",
    KenshiLib::GetRealAddress(&ForgottenGUI::messageBox),
    ForgottenGUI_messageBox_hook, ForgottenGUI_messageBox_orig)

static bool (*ForgottenGUI_hideMessageBox_orig)(ForgottenGUI*, bool) = NULL;
static bool ForgottenGUI_hideMessageBox_hook(ForgottenGUI* thisptr, bool enter)
{
    bool res = ForgottenGUI_hideMessageBox_orig(thisptr, enter);
    CallForgottenGUIHideMessageBoxCallbacks(thisptr, enter, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_hideMessageBox,
    "ForgottenGUI::hideMessageBox",
    KenshiLib::GetRealAddress(&ForgottenGUI::hideMessageBox),
    ForgottenGUI_hideMessageBox_hook, ForgottenGUI_hideMessageBox_orig)

static bool (*ForgottenGUI_hasModalMessage_orig)(const ForgottenGUI*) = NULL;
static bool ForgottenGUI_hasModalMessage_hook(const ForgottenGUI* thisptr)
{
    bool res = ForgottenGUI_hasModalMessage_orig(thisptr);
    return CallForgottenGUIHasModalMessageCallbacks(const_cast<ForgottenGUI*>(thisptr), res);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_hasModalMessage,
    "ForgottenGUI::hasModalMessage",
    KenshiLib::GetRealAddress(&ForgottenGUI::hasModalMessage),
    ForgottenGUI_hasModalMessage_hook, ForgottenGUI_hasModalMessage_orig)

static void (*ForgottenGUI_showMainbar_orig)(ForgottenGUI*, bool) = NULL;
static void ForgottenGUI_showMainbar_hook(ForgottenGUI* thisptr, bool on)
{
    ForgottenGUI_showMainbar_orig(thisptr, on);
    CallForgottenGUIShowMainbarCallbacks(thisptr, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_showMainbar,
    "ForgottenGUI::showMainbar",
    KenshiLib::GetRealAddress(&ForgottenGUI::showMainbar),
    ForgottenGUI_showMainbar_hook, ForgottenGUI_showMainbar_orig)

static void (*ForgottenGUI_updateBountyPanelVisibility_orig)(ForgottenGUI*) = NULL;
static void ForgottenGUI_updateBountyPanelVisibility_hook(ForgottenGUI* thisptr)
{
    ForgottenGUI_updateBountyPanelVisibility_orig(thisptr);
    CallForgottenGUIUpdateBountyPanelVisibilityCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_updateBountyPanelVisibility,
    "ForgottenGUI::updateBountyPanelVisibility",
    KenshiLib::GetRealAddress(&ForgottenGUI::updateBountyPanelVisibility),
    ForgottenGUI_updateBountyPanelVisibility_hook, ForgottenGUI_updateBountyPanelVisibility_orig)

static bool (*ForgottenGUI_getInDialogue_orig)(const ForgottenGUI*) = NULL;
static bool ForgottenGUI_getInDialogue_hook(const ForgottenGUI* thisptr)
{
    bool res = ForgottenGUI_getInDialogue_orig(thisptr);
    return CallForgottenGUIGetInDialogueCallbacks(const_cast<ForgottenGUI*>(thisptr), res);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_getInDialogue,
    "ForgottenGUI::getInDialogue",
    KenshiLib::GetRealAddress(&ForgottenGUI::getInDialogue),
    ForgottenGUI_getInDialogue_hook, ForgottenGUI_getInDialogue_orig)

static ToolTip* (*ForgottenGUI_getToolTip_orig)(ForgottenGUI*) = NULL;
static ToolTip* ForgottenGUI_getToolTip_hook(ForgottenGUI* thisptr)
{
    ToolTip* res = ForgottenGUI_getToolTip_orig(thisptr);
    ToolTip* overrideRes = CallForgottenGUIGetToolTipCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_getToolTip,
    "ForgottenGUI::getToolTip",
    KenshiLib::GetRealAddress(&ForgottenGUI::getToolTip),
    ForgottenGUI_getToolTip_hook, ForgottenGUI_getToolTip_orig)

static void (*ForgottenGUI_toggle_orig)(ForgottenGUI*) = NULL;
static void ForgottenGUI_toggle_hook(ForgottenGUI* thisptr)
{
    ForgottenGUI_toggle_orig(thisptr);
    CallForgottenGUIToggleCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_toggle,
    "ForgottenGUI::toggle",
    KenshiLib::GetRealAddress(&ForgottenGUI::toggle),
    ForgottenGUI_toggle_hook, ForgottenGUI_toggle_orig)

static void (*ForgottenGUI_showNames_orig)(ForgottenGUI*, bool) = NULL;
static void ForgottenGUI_showNames_hook(ForgottenGUI* thisptr, bool on)
{
    ForgottenGUI_showNames_orig(thisptr, on);
    CallForgottenGUIShowNamesCallbacks(thisptr, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_showNames,
    "ForgottenGUI::showNames",
    KenshiLib::GetRealAddress(&ForgottenGUI::showNames),
    ForgottenGUI_showNames_hook, ForgottenGUI_showNames_orig)

static void (*ForgottenGUI_showPrintOutput_orig)(ForgottenGUI*, bool) = NULL;
static void ForgottenGUI_showPrintOutput_hook(ForgottenGUI* thisptr, bool v)
{
    ForgottenGUI_showPrintOutput_orig(thisptr, v);
    CallForgottenGUIShowPrintOutputCallbacks(thisptr, v);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_showPrintOutput,
    "ForgottenGUI::showPrintOutput",
    KenshiLib::GetRealAddress(&ForgottenGUI::showPrintOutput),
    ForgottenGUI_showPrintOutput_hook, ForgottenGUI_showPrintOutput_orig)

static void (*ForgottenGUI_showCharacterEditor_orig)(ForgottenGUI*, const lektor<Character*>, CharacterEditMode, const Ogre::vector<GameDataReference>::type*) = NULL;
static void ForgottenGUI_showCharacterEditor_hook(ForgottenGUI* thisptr, const lektor<Character*> characters, CharacterEditMode mode, const Ogre::vector<GameDataReference>::type* races)
{
    CallForgottenGUIShowCharacterEditorCallbacks(thisptr, characters, static_cast<int>(mode), races);
    ForgottenGUI_showCharacterEditor_orig(thisptr, characters, mode, races);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_showCharacterEditor,
    "ForgottenGUI::showCharacterEditor",
    KenshiLib::GetRealAddress(&ForgottenGUI::showCharacterEditor),
    ForgottenGUI_showCharacterEditor_hook, ForgottenGUI_showCharacterEditor_orig)

static void (*ForgottenGUI_closeCharacterEditor_orig)(ForgottenGUI*) = NULL;
static void ForgottenGUI_closeCharacterEditor_hook(ForgottenGUI* thisptr)
{
    ForgottenGUI_closeCharacterEditor_orig(thisptr);
    CallForgottenGUICloseCharacterEditorCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_closeCharacterEditor,
    "ForgottenGUI::closeCharacterEditor",
    KenshiLib::GetRealAddress(&ForgottenGUI::closeCharacterEditor),
    ForgottenGUI_closeCharacterEditor_hook, ForgottenGUI_closeCharacterEditor_orig)

static void (*ForgottenGUI_showCharacterStatsWindow_orig)(ForgottenGUI*, const hand&) = NULL;
static void ForgottenGUI_showCharacterStatsWindow_hook(ForgottenGUI* thisptr, const hand& owner)
{
    ForgottenGUI_showCharacterStatsWindow_orig(thisptr, owner);
    CallForgottenGUIShowCharacterStatsWindowCallbacks(thisptr, owner);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_showCharacterStatsWindow,
    "ForgottenGUI::showCharacterStatsWindow",
    KenshiLib::GetRealAddress(&ForgottenGUI::showCharacterStatsWindow),
    ForgottenGUI_showCharacterStatsWindow_hook, ForgottenGUI_showCharacterStatsWindow_orig)

static void (*ForgottenGUI_closeCharacterStatsWindow_orig)(ForgottenGUI*, const hand&) = NULL;
static void ForgottenGUI_closeCharacterStatsWindow_hook(ForgottenGUI* thisptr, const hand& owner)
{
    ForgottenGUI_closeCharacterStatsWindow_orig(thisptr, owner);
    CallForgottenGUICloseCharacterStatsWindowCallbacks(thisptr, owner);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_closeCharacterStatsWindow,
    "ForgottenGUI::closeCharacterStatsWindow",
    KenshiLib::GetRealAddress(&ForgottenGUI::closeCharacterStatsWindow),
    ForgottenGUI_closeCharacterStatsWindow_hook, ForgottenGUI_closeCharacterStatsWindow_orig)

static void (*ForgottenGUI_closeAllCharacterStatsWindows_orig)(ForgottenGUI*) = NULL;
static void ForgottenGUI_closeAllCharacterStatsWindows_hook(ForgottenGUI* thisptr)
{
    ForgottenGUI_closeAllCharacterStatsWindows_orig(thisptr);
    CallForgottenGUICloseAllCharacterStatsWindowsCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_closeAllCharacterStatsWindows,
    "ForgottenGUI::closeAllCharacterStatsWindows",
    KenshiLib::GetRealAddress(&ForgottenGUI::closeAllCharacterStatsWindows),
    ForgottenGUI_closeAllCharacterStatsWindows_hook, ForgottenGUI_closeAllCharacterStatsWindows_orig)

static bool (*ForgottenGUI_isStatsWindowOpen_orig)(const ForgottenGUI*) = NULL;
static bool ForgottenGUI_isStatsWindowOpen_hook(const ForgottenGUI* thisptr)
{
    bool res = ForgottenGUI_isStatsWindowOpen_orig(thisptr);
    return CallForgottenGUIIsStatsWindowOpenCallbacks(const_cast<ForgottenGUI*>(thisptr), res);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_isStatsWindowOpen,
    "ForgottenGUI::isStatsWindowOpen",
    KenshiLib::GetRealAddress(&ForgottenGUI::isStatsWindowOpen),
    ForgottenGUI_isStatsWindowOpen_hook, ForgottenGUI_isStatsWindowOpen_orig)

static void (*ForgottenGUI_toggleStatsWindow_orig)(ForgottenGUI*, const hand&) = NULL;
static void ForgottenGUI_toggleStatsWindow_hook(ForgottenGUI* thisptr, const hand& owner)
{
    ForgottenGUI_toggleStatsWindow_orig(thisptr, owner);
    CallForgottenGUIToggleStatsWindowCallbacks(thisptr, owner);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_toggleStatsWindow,
    "ForgottenGUI::toggleStatsWindow",
    KenshiLib::GetRealAddress(&ForgottenGUI::toggleStatsWindow),
    ForgottenGUI_toggleStatsWindow_hook, ForgottenGUI_toggleStatsWindow_orig)

static void (*ForgottenGUI_toggleCharacterStatsWindowPermanent_orig)(ForgottenGUI*, const hand&) = NULL;
static void ForgottenGUI_toggleCharacterStatsWindowPermanent_hook(ForgottenGUI* thisptr, const hand& owner)
{
    ForgottenGUI_toggleCharacterStatsWindowPermanent_orig(thisptr, owner);
    CallForgottenGUIToggleCharacterStatsWindowPermanentCallbacks(thisptr, owner);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_toggleCharacterStatsWindowPermanent,
    "ForgottenGUI::toggleCharacterStatsWindowPermanent",
    KenshiLib::GetRealAddress(&ForgottenGUI::toggleCharacterStatsWindowPermanent),
    ForgottenGUI_toggleCharacterStatsWindowPermanent_hook, ForgottenGUI_toggleCharacterStatsWindowPermanent_orig)

static void (*ForgottenGUI_selectedObjectsChanged_orig)(ForgottenGUI*) = NULL;
static void ForgottenGUI_selectedObjectsChanged_hook(ForgottenGUI* thisptr)
{
    ForgottenGUI_selectedObjectsChanged_orig(thisptr);
    CallForgottenGUISelectedObjectsChangedCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_selectedObjectsChanged,
    "ForgottenGUI::selectedObjectsChanged",
    KenshiLib::GetRealAddress(&ForgottenGUI::selectedObjectsChanged),
    ForgottenGUI_selectedObjectsChanged_hook, ForgottenGUI_selectedObjectsChanged_orig)

static void (*ForgottenGUI_updateToOrdersPanel_orig)(ForgottenGUI*) = NULL;
static void ForgottenGUI_updateToOrdersPanel_hook(ForgottenGUI* thisptr)
{
    ForgottenGUI_updateToOrdersPanel_orig(thisptr);
    CallForgottenGUIUpdateToOrdersPanelCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_updateToOrdersPanel,
    "ForgottenGUI::updateToOrdersPanel",
    KenshiLib::GetRealAddress(&ForgottenGUI::updateToOrdersPanel),
    ForgottenGUI_updateToOrdersPanel_hook, ForgottenGUI_updateToOrdersPanel_orig)

static void (*ForgottenGUI_notifyTownDeleted_orig)(ForgottenGUI*, Town*) = NULL;
static void ForgottenGUI_notifyTownDeleted_hook(ForgottenGUI* thisptr, Town* t)
{
    ForgottenGUI_notifyTownDeleted_orig(thisptr, t);
    CallForgottenGUINotifyTownDeletedCallbacks(thisptr, t);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_notifyTownDeleted,
    "ForgottenGUI::notifyTownDeleted",
    KenshiLib::GetRealAddress(&ForgottenGUI::notifyTownDeleted),
    ForgottenGUI_notifyTownDeleted_hook, ForgottenGUI_notifyTownDeleted_orig)

static void (*ForgottenGUI_update_orig)(ForgottenGUI*) = NULL;
static void ForgottenGUI_update_hook(ForgottenGUI* thisptr)
{
    ForgottenGUI_update_orig(thisptr);
    CallForgottenGUIUpdateCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_update,
    "ForgottenGUI::update",
    KenshiLib::GetRealAddress(&ForgottenGUI::update),
    ForgottenGUI_update_hook, ForgottenGUI_update_orig)

static void (*ForgottenGUI_showTradeWindow_orig)(ForgottenGUI*, const hand&, const hand&, TradeWindowType) = NULL;
static void ForgottenGUI_showTradeWindow_hook(ForgottenGUI* thisptr, const hand& a, const hand& b, TradeWindowType type)
{
    ForgottenGUI_showTradeWindow_orig(thisptr, a, b, type);
    CallForgottenGUIShowTradeWindowCallbacks(thisptr, a, b, static_cast<int>(type));
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_showTradeWindow,
    "ForgottenGUI::showTradeWindow",
    KenshiLib::GetRealAddress(&ForgottenGUI::showTradeWindow),
    ForgottenGUI_showTradeWindow_hook, ForgottenGUI_showTradeWindow_orig)

static void (*ForgottenGUI_closeTradeWindow_orig)(ForgottenGUI*) = NULL;
static void ForgottenGUI_closeTradeWindow_hook(ForgottenGUI* thisptr)
{
    ForgottenGUI_closeTradeWindow_orig(thisptr);
    CallForgottenGUICloseTradeWindowCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_closeTradeWindow,
    "ForgottenGUI::closeTradeWindow",
    KenshiLib::GetRealAddress(&ForgottenGUI::closeTradeWindow),
    ForgottenGUI_closeTradeWindow_hook, ForgottenGUI_closeTradeWindow_orig)

static InventoryGUI* (*ForgottenGUI_showInventory_orig)(ForgottenGUI*, const hand&, bool, float, float) = NULL;
static InventoryGUI* ForgottenGUI_showInventory_hook(ForgottenGUI* thisptr, const hand& owner, bool autoPosition, float x, float y)
{
    InventoryGUI* res = ForgottenGUI_showInventory_orig(thisptr, owner, autoPosition, x, y);
    CallForgottenGUIShowInventoryCallbacks(thisptr, owner, autoPosition, x, y, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_showInventory,
    "ForgottenGUI::showInventory",
    KenshiLib::GetRealAddress(&ForgottenGUI::showInventory),
    ForgottenGUI_showInventory_hook, ForgottenGUI_showInventory_orig)

static InventoryGUI* (*ForgottenGUI_showTraderInventory_orig)(ForgottenGUI*, const hand&) = NULL;
static InventoryGUI* ForgottenGUI_showTraderInventory_hook(ForgottenGUI* thisptr, const hand& owner)
{
    InventoryGUI* res = ForgottenGUI_showTraderInventory_orig(thisptr, owner);
    CallForgottenGUIShowTraderInventoryCallbacks(thisptr, owner, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_showTraderInventory,
    "ForgottenGUI::showTraderInventory",
    KenshiLib::GetRealAddress(&ForgottenGUI::showTraderInventory),
    ForgottenGUI_showTraderInventory_hook, ForgottenGUI_showTraderInventory_orig)

static InventoryGUI* (*ForgottenGUI_showInventoryBuilding_orig)(ForgottenGUI*, const hand&) = NULL;
static InventoryGUI* ForgottenGUI_showInventoryBuilding_hook(ForgottenGUI* thisptr, const hand& owner)
{
    InventoryGUI* res = ForgottenGUI_showInventoryBuilding_orig(thisptr, owner);
    CallForgottenGUIShowInventoryBuildingCallbacks(thisptr, owner, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_showInventoryBuilding,
    "ForgottenGUI::showInventoryBuilding",
    KenshiLib::GetRealAddress(&ForgottenGUI::showInventoryBuilding),
    ForgottenGUI_showInventoryBuilding_hook, ForgottenGUI_showInventoryBuilding_orig)

static InventoryGUI* (*ForgottenGUI_showInventoryNPC_orig)(ForgottenGUI*, const hand&) = NULL;
static InventoryGUI* ForgottenGUI_showInventoryNPC_hook(ForgottenGUI* thisptr, const hand& owner)
{
    InventoryGUI* res = ForgottenGUI_showInventoryNPC_orig(thisptr, owner);
    CallForgottenGUIShowInventoryNPCCallbacks(thisptr, owner, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_showInventoryNPC,
    "ForgottenGUI::showInventoryNPC",
    KenshiLib::GetRealAddress(&ForgottenGUI::showInventoryNPC),
    ForgottenGUI_showInventoryNPC_hook, ForgottenGUI_showInventoryNPC_orig)

static void (*ForgottenGUI_closeInventory_orig)(ForgottenGUI*, const hand&) = NULL;
static void ForgottenGUI_closeInventory_hook(ForgottenGUI* thisptr, const hand& owner)
{
    ForgottenGUI_closeInventory_orig(thisptr, owner);
    CallForgottenGUICloseInventoryCallbacks(thisptr, owner);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_closeInventory,
    "ForgottenGUI::closeInventory",
    KenshiLib::GetRealAddress(&ForgottenGUI::closeInventory),
    ForgottenGUI_closeInventory_hook, ForgottenGUI_closeInventory_orig)

static void (*ForgottenGUI_closeInventoryBuilding_orig)(ForgottenGUI*) = NULL;
static void ForgottenGUI_closeInventoryBuilding_hook(ForgottenGUI* thisptr)
{
    ForgottenGUI_closeInventoryBuilding_orig(thisptr);
    CallForgottenGUICloseInventoryBuildingCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_closeInventoryBuilding,
    "ForgottenGUI::closeInventoryBuilding",
    KenshiLib::GetRealAddress(&ForgottenGUI::closeInventoryBuilding),
    ForgottenGUI_closeInventoryBuilding_hook, ForgottenGUI_closeInventoryBuilding_orig)

static void (*ForgottenGUI_closeAllInventories_orig)(ForgottenGUI*) = NULL;
static void ForgottenGUI_closeAllInventories_hook(ForgottenGUI* thisptr)
{
    ForgottenGUI_closeAllInventories_orig(thisptr);
    CallForgottenGUICloseAllInventoriesCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_closeAllInventories,
    "ForgottenGUI::closeAllInventories",
    KenshiLib::GetRealAddress(&ForgottenGUI::closeAllInventories),
    ForgottenGUI_closeAllInventories_hook, ForgottenGUI_closeAllInventories_orig)

static void (*ForgottenGUI_closeAllWindows_orig)(ForgottenGUI*) = NULL;
static void ForgottenGUI_closeAllWindows_hook(ForgottenGUI* thisptr)
{
    ForgottenGUI_closeAllWindows_orig(thisptr);
    CallForgottenGUICloseAllWindowsCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_closeAllWindows,
    "ForgottenGUI::closeAllWindows",
    KenshiLib::GetRealAddress(&ForgottenGUI::closeAllWindows),
    ForgottenGUI_closeAllWindows_hook, ForgottenGUI_closeAllWindows_orig)

static InventoryGUI* (*ForgottenGUI_getInventoryWindow_orig)(ForgottenGUI*, const hand&) = NULL;
static InventoryGUI* ForgottenGUI_getInventoryWindow_hook(ForgottenGUI* thisptr, const hand& who)
{
    InventoryGUI* res = ForgottenGUI_getInventoryWindow_orig(thisptr, who);
    InventoryGUI* overrideRes = CallForgottenGUIGetInventoryWindowCallbacks(thisptr, who, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_getInventoryWindow,
    "ForgottenGUI::getInventoryWindow",
    KenshiLib::GetRealAddress(&ForgottenGUI::getInventoryWindow),
    ForgottenGUI_getInventoryWindow_hook, ForgottenGUI_getInventoryWindow_orig)

static InventoryGUI* (*ForgottenGUI_toggleInventory_orig)(ForgottenGUI*, const hand&, InventoryGUI*, bool) = NULL;
static InventoryGUI* ForgottenGUI_toggleInventory_hook(ForgottenGUI* thisptr, const hand& owner, InventoryGUI* parentInv, bool attached)
{
    InventoryGUI* res = ForgottenGUI_toggleInventory_orig(thisptr, owner, parentInv, attached);
    CallForgottenGUIToggleInventoryCallbacks(thisptr, owner, parentInv, attached, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_toggleInventory,
    "ForgottenGUI::toggleInventory",
    KenshiLib::GetRealAddress(&ForgottenGUI::toggleInventory),
    ForgottenGUI_toggleInventory_hook, ForgottenGUI_toggleInventory_orig)

static int (*ForgottenGUI_getNumOpenInventoryWindows_orig)(const ForgottenGUI*) = NULL;
static int ForgottenGUI_getNumOpenInventoryWindows_hook(const ForgottenGUI* thisptr)
{
    int res = ForgottenGUI_getNumOpenInventoryWindows_orig(thisptr);
    return CallForgottenGUIGetNumOpenInventoryWindowsCallbacks(const_cast<ForgottenGUI*>(thisptr), res);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_getNumOpenInventoryWindows,
    "ForgottenGUI::getNumOpenInventoryWindows",
    KenshiLib::GetRealAddress(&ForgottenGUI::getNumOpenInventoryWindows),
    ForgottenGUI_getNumOpenInventoryWindows_hook, ForgottenGUI_getNumOpenInventoryWindows_orig)

static InventoryGUI* (*ForgottenGUI_getInventoryWindowWithMouse_orig)(ForgottenGUI*) = NULL;
static InventoryGUI* ForgottenGUI_getInventoryWindowWithMouse_hook(ForgottenGUI* thisptr)
{
    InventoryGUI* res = ForgottenGUI_getInventoryWindowWithMouse_orig(thisptr);
    InventoryGUI* overrideRes = CallForgottenGUIGetInventoryWindowWithMouseCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_getInventoryWindowWithMouse,
    "ForgottenGUI::getInventoryWindowWithMouse",
    KenshiLib::GetRealAddress(&ForgottenGUI::getInventoryWindowWithMouse),
    ForgottenGUI_getInventoryWindowWithMouse_hook, ForgottenGUI_getInventoryWindowWithMouse_orig)

static bool (*ForgottenGUI_hasInventoryWindowOpen_orig)(ForgottenGUI*, const hand&) = NULL;
static bool ForgottenGUI_hasInventoryWindowOpen_hook(ForgottenGUI* thisptr, const hand& obj)
{
    bool res = ForgottenGUI_hasInventoryWindowOpen_orig(thisptr, obj);
    return CallForgottenGUIHasInventoryWindowOpenCallbacks(thisptr, obj, res);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_hasInventoryWindowOpen,
    "ForgottenGUI::hasInventoryWindowOpen",
    KenshiLib::GetRealAddress(&ForgottenGUI::hasInventoryWindowOpen),
    ForgottenGUI_hasInventoryWindowOpen_hook, ForgottenGUI_hasInventoryWindowOpen_orig)

static bool (*ForgottenGUI_isAnyInventoryWindowOpen_orig)(ForgottenGUI*) = NULL;
static bool ForgottenGUI_isAnyInventoryWindowOpen_hook(ForgottenGUI* thisptr)
{
    bool res = ForgottenGUI_isAnyInventoryWindowOpen_orig(thisptr);
    return CallForgottenGUIIsAnyInventoryWindowOpenCallbacks(thisptr, res);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_isAnyInventoryWindowOpen,
    "ForgottenGUI::isAnyInventoryWindowOpen",
    KenshiLib::GetRealAddress(&ForgottenGUI::isAnyInventoryWindowOpen),
    ForgottenGUI_isAnyInventoryWindowOpen_hook, ForgottenGUI_isAnyInventoryWindowOpen_orig)

static void (*ForgottenGUI_toggleInventoryWindowPermanent_orig)(ForgottenGUI*, const hand&) = NULL;
static void ForgottenGUI_toggleInventoryWindowPermanent_hook(ForgottenGUI* thisptr, const hand& owner)
{
    ForgottenGUI_toggleInventoryWindowPermanent_orig(thisptr, owner);
    CallForgottenGUIToggleInventoryWindowPermanentCallbacks(thisptr, owner);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_toggleInventoryWindowPermanent,
    "ForgottenGUI::toggleInventoryWindowPermanent",
    KenshiLib::GetRealAddress(&ForgottenGUI::toggleInventoryWindowPermanent),
    ForgottenGUI_toggleInventoryWindowPermanent_hook, ForgottenGUI_toggleInventoryWindowPermanent_orig)

static void (*ForgottenGUI_toggleHelpWindow_orig)(ForgottenGUI*) = NULL;
static void ForgottenGUI_toggleHelpWindow_hook(ForgottenGUI* thisptr)
{
    ForgottenGUI_toggleHelpWindow_orig(thisptr);
    CallForgottenGUIToggleHelpWindowCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_toggleHelpWindow,
    "ForgottenGUI::toggleHelpWindow",
    KenshiLib::GetRealAddress(&ForgottenGUI::toggleHelpWindow),
    ForgottenGUI_toggleHelpWindow_hook, ForgottenGUI_toggleHelpWindow_orig)

static void (*ForgottenGUI_addWindowToUpdateList_orig)(ForgottenGUI*, GUIWindow*) = NULL;
static void ForgottenGUI_addWindowToUpdateList_hook(ForgottenGUI* thisptr, GUIWindow* win)
{
    ForgottenGUI_addWindowToUpdateList_orig(thisptr, win);
    CallForgottenGUIAddWindowToUpdateListCallbacks(thisptr, win);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_addWindowToUpdateList,
    "ForgottenGUI::addWindowToUpdateList",
    KenshiLib::GetRealAddress(&ForgottenGUI::addWindowToUpdateList),
    ForgottenGUI_addWindowToUpdateList_hook, ForgottenGUI_addWindowToUpdateList_orig)

static void (*ForgottenGUI_removeWindowFromUpdateList_orig)(ForgottenGUI*, GUIWindow*) = NULL;
static void ForgottenGUI_removeWindowFromUpdateList_hook(ForgottenGUI* thisptr, GUIWindow* win)
{
    ForgottenGUI_removeWindowFromUpdateList_orig(thisptr, win);
    CallForgottenGUIRemoveWindowFromUpdateListCallbacks(thisptr, win);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_removeWindowFromUpdateList,
    "ForgottenGUI::removeWindowFromUpdateList",
    KenshiLib::GetRealAddress(&ForgottenGUI::removeWindowFromUpdateList),
    ForgottenGUI_removeWindowFromUpdateList_hook, ForgottenGUI_removeWindowFromUpdateList_orig)

static void (*ForgottenGUI_addScreenLabel_orig)(ForgottenGUI*, ScreenLabelInterface*) = NULL;
static void ForgottenGUI_addScreenLabel_hook(ForgottenGUI* thisptr, ScreenLabelInterface* label)
{
    ForgottenGUI_addScreenLabel_orig(thisptr, label);
    CallForgottenGUIAddScreenLabelCallbacks(thisptr, label);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_addScreenLabel,
    "ForgottenGUI::addScreenLabel",
    KenshiLib::GetRealAddress(&ForgottenGUI::addScreenLabel),
    ForgottenGUI_addScreenLabel_hook, ForgottenGUI_addScreenLabel_orig)

static void (*ForgottenGUI_addDatapanelToUpdateList_orig)(ForgottenGUI*, DatapanelGUI*) = NULL;
static void ForgottenGUI_addDatapanelToUpdateList_hook(ForgottenGUI* thisptr, DatapanelGUI* datapanel)
{
    ForgottenGUI_addDatapanelToUpdateList_orig(thisptr, datapanel);
    CallForgottenGUIAddDatapanelToUpdateListCallbacks(thisptr, datapanel);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_addDatapanelToUpdateList,
    "ForgottenGUI::addDatapanelToUpdateList",
    KenshiLib::GetRealAddress(&ForgottenGUI::addDatapanelToUpdateList),
    ForgottenGUI_addDatapanelToUpdateList_hook, ForgottenGUI_addDatapanelToUpdateList_orig)

static void (*ForgottenGUI_removeDatapanelFromUpdateList_orig)(ForgottenGUI*, DatapanelGUI*) = NULL;
static void ForgottenGUI_removeDatapanelFromUpdateList_hook(ForgottenGUI* thisptr, DatapanelGUI* datapanel)
{
    ForgottenGUI_removeDatapanelFromUpdateList_orig(thisptr, datapanel);
    CallForgottenGUIRemoveDatapanelFromUpdateListCallbacks(thisptr, datapanel);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_removeDatapanelFromUpdateList,
    "ForgottenGUI::removeDatapanelFromUpdateList",
    KenshiLib::GetRealAddress(&ForgottenGUI::removeDatapanelFromUpdateList),
    ForgottenGUI_removeDatapanelFromUpdateList_hook, ForgottenGUI_removeDatapanelFromUpdateList_orig)

static void (*ForgottenGUI_destroyWidget_orig)(ForgottenGUI*, MyGUI::Widget*) = NULL;
static void ForgottenGUI_destroyWidget_hook(ForgottenGUI* thisptr, MyGUI::Widget* widget)
{
    CallForgottenGUIDestroyWidgetCallbacks(thisptr, widget);
    ForgottenGUI_destroyWidget_orig(thisptr, widget);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_destroyWidget,
    "ForgottenGUI::destroyWidget",
    KenshiLib::GetRealAddress(&ForgottenGUI::destroyWidget),
    ForgottenGUI_destroyWidget_hook, ForgottenGUI_destroyWidget_orig)

static bool (*ForgottenGUI_widgetHasMouse_orig)(ForgottenGUI*, MyGUI::Widget*) = NULL;
static bool ForgottenGUI_widgetHasMouse_hook(ForgottenGUI* thisptr, MyGUI::Widget* w)
{
    bool res = ForgottenGUI_widgetHasMouse_orig(thisptr, w);
    return CallForgottenGUIWidgetHasMouseCallbacks(thisptr, w, res);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_widgetHasMouse,
    "ForgottenGUI::widgetHasMouse",
    KenshiLib::GetRealAddress(&ForgottenGUI::widgetHasMouse),
    ForgottenGUI_widgetHasMouse_hook, ForgottenGUI_widgetHasMouse_orig)

static void (*ForgottenGUI_setup_orig)(ForgottenGUI*, Ogre::Root*, Ogre::RenderWindow*) = NULL;
static void ForgottenGUI_setup_hook(ForgottenGUI* thisptr, Ogre::Root* mRoot, Ogre::RenderWindow* window)
{
    ForgottenGUI_setup_orig(thisptr, mRoot, window);
    CallForgottenGUISetupCallbacks(thisptr, (void*)mRoot, (void*)window);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_setup,
    "ForgottenGUI::setup",
    KenshiLib::GetRealAddress(&ForgottenGUI::setup),
    ForgottenGUI_setup_hook, ForgottenGUI_setup_orig)

static void (*ForgottenGUI_setMouseCursorVisible_orig)(ForgottenGUI*, bool) = NULL;
static void ForgottenGUI_setMouseCursorVisible_hook(ForgottenGUI* thisptr, bool visible)
{
    ForgottenGUI_setMouseCursorVisible_orig(thisptr, visible);
    CallForgottenGUISetMouseCursorVisibleCallbacks(thisptr, visible);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_setMouseCursorVisible,
    "ForgottenGUI::setMouseCursorVisible",
    KenshiLib::GetRealAddress(&ForgottenGUI::setMouseCursorVisible),
    ForgottenGUI_setMouseCursorVisible_hook, ForgottenGUI_setMouseCursorVisible_orig)

static void (*ForgottenGUI__showTradeWindow_orig)(ForgottenGUI*, RootObject*, RootObject*, TradeWindowType) = NULL;
static void ForgottenGUI__showTradeWindow_hook(ForgottenGUI* thisptr, RootObject* a, RootObject* b, TradeWindowType tradeType)
{
    ForgottenGUI__showTradeWindow_orig(thisptr, a, b, tradeType);
    CallForgottenGUI_showTradeWindowCallbacks(thisptr, a, b, static_cast<int>(tradeType));
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI__showTradeWindow,
    "ForgottenGUI::_showTradeWindow",
    KenshiLib::GetRealAddress(&ForgottenGUI::_showTradeWindow),
    ForgottenGUI__showTradeWindow_hook, ForgottenGUI__showTradeWindow_orig)

static void (*ForgottenGUI_setInventoryPosition_orig)(ForgottenGUI*, const hand&, InventoryGUI*) = NULL;
static void ForgottenGUI_setInventoryPosition_hook(ForgottenGUI* thisptr, const hand& owner, InventoryGUI* inventory)
{
    ForgottenGUI_setInventoryPosition_orig(thisptr, owner, inventory);
    CallForgottenGUISetInventoryPositionCallbacks(thisptr, owner, inventory);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_setInventoryPosition,
    "ForgottenGUI::setInventoryPosition",
    KenshiLib::GetRealAddress(&ForgottenGUI::setInventoryPosition),
    ForgottenGUI_setInventoryPosition_hook, ForgottenGUI_setInventoryPosition_orig)

static void (*ForgottenGUI_inventoriesSelectedObjectUpdate_orig)(ForgottenGUI*, const hand&) = NULL;
static void ForgottenGUI_inventoriesSelectedObjectUpdate_hook(ForgottenGUI* thisptr, const hand& selectedObject)
{
    ForgottenGUI_inventoriesSelectedObjectUpdate_orig(thisptr, selectedObject);
    CallForgottenGUIInventoriesSelectedObjectUpdateCallbacks(thisptr, selectedObject);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_inventoriesSelectedObjectUpdate,
    "ForgottenGUI::inventoriesSelectedObjectUpdate",
    KenshiLib::GetRealAddress(&ForgottenGUI::inventoriesSelectedObjectUpdate),
    ForgottenGUI_inventoriesSelectedObjectUpdate_hook, ForgottenGUI_inventoriesSelectedObjectUpdate_orig)

static void (*ForgottenGUI_keepWindownOnScreen_orig)(ForgottenGUI*, MyGUI::Widget*) = NULL;
static void ForgottenGUI_keepWindownOnScreen_hook(ForgottenGUI* thisptr, MyGUI::Widget* win)
{
    ForgottenGUI_keepWindownOnScreen_orig(thisptr, win);
    CallForgottenGUIKeepWindownOnScreenCallbacks(thisptr, win);
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_keepWindownOnScreen,
    "ForgottenGUI::keepWindownOnScreen",
    KenshiLib::GetRealAddress(&ForgottenGUI::keepWindownOnScreen),
    ForgottenGUI_keepWindownOnScreen_hook, ForgottenGUI_keepWindownOnScreen_orig)

static const std::string& (*ForgottenGUI_getDataLineColor_orig)(const ForgottenGUI*, int, int) = NULL;
static const std::string& ForgottenGUI_getDataLineColor_hook(const ForgottenGUI* thisptr, int actualVal, int normalVal)
{
    const std::string& res = ForgottenGUI_getDataLineColor_orig(thisptr, actualVal, normalVal);
    CallForgottenGUIGetDataLineColorCallbacks(const_cast<ForgottenGUI*>(thisptr), actualVal, normalVal, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_getDataLineColor,
    "ForgottenGUI::getDataLineColor",
    KenshiLib::GetRealAddress(&ForgottenGUI::getDataLineColor),
    ForgottenGUI_getDataLineColor_hook, ForgottenGUI_getDataLineColor_orig)

static MyGUI::Window* (*ForgottenGUI_createPanel_orig)(ForgottenGUI*, const std::string&, float, float, float, float, std::string, std::string) = NULL;
static MyGUI::Window* ForgottenGUI_createPanel_hook(ForgottenGUI* thisptr, const std::string& name, float top, float left, float width, float height, std::string layer, std::string skin)
{
    MyGUI::Window* res = ForgottenGUI_createPanel_orig(thisptr, name, top, left, width, height, layer, skin);
    CallForgottenGUICreatePanelCallbacks(thisptr, name, top, left, width, height, layer, skin, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_createPanel,
    "ForgottenGUI::createPanel",
    KenshiLib::GetRealAddress(&ForgottenGUI::createPanel),
    ForgottenGUI_createPanel_hook, ForgottenGUI_createPanel_orig)

static MyGUI::Window* (*ForgottenGUI_createPanelAbs_orig)(ForgottenGUI*, const std::string&, float, float, float, float, std::string, std::string) = NULL;
static MyGUI::Window* ForgottenGUI_createPanelAbs_hook(ForgottenGUI* thisptr, const std::string& name, float top, float left, float width, float height, std::string layer, std::string skin)
{
    MyGUI::Window* res = ForgottenGUI_createPanelAbs_orig(thisptr, name, top, left, width, height, layer, skin);
    CallForgottenGUICreatePanelAbsCallbacks(thisptr, name, top, left, width, height, layer, skin, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_createPanelAbs,
    "ForgottenGUI::createPanelAbs",
    KenshiLib::GetRealAddress(&ForgottenGUI::createPanelAbs),
    ForgottenGUI_createPanelAbs_hook, ForgottenGUI_createPanelAbs_orig)

static MyGUI::ImageBox* (*ForgottenGUI_createImage_orig)(ForgottenGUI*, MyGUI::Widget*, float, float, float, float, const std::string&) = NULL;
static MyGUI::ImageBox* ForgottenGUI_createImage_hook(ForgottenGUI* thisptr, MyGUI::Widget* parent, float top, float left, float width, float height, const std::string& image)
{
    MyGUI::ImageBox* res = ForgottenGUI_createImage_orig(thisptr, parent, top, left, width, height, image);
    CallForgottenGUICreateImageCallbacks(thisptr, parent, top, left, width, height, image, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_createImage,
    "ForgottenGUI::createImage",
    KenshiLib::GetRealAddress(&ForgottenGUI::createImage),
    ForgottenGUI_createImage_hook, ForgottenGUI_createImage_orig)

static MyGUI::ImageBox* (*ForgottenGUI_createImageAbs_orig)(ForgottenGUI*, MyGUI::Widget*, int, int, int, int, const std::string&) = NULL;
static MyGUI::ImageBox* ForgottenGUI_createImageAbs_hook(ForgottenGUI* thisptr, MyGUI::Widget* parent, int top, int left, int width, int height, const std::string& image)
{
    MyGUI::ImageBox* res = ForgottenGUI_createImageAbs_orig(thisptr, parent, top, left, width, height, image);
    CallForgottenGUICreateImageAbsCallbacks(thisptr, parent, top, left, width, height, image, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_createImageAbs,
    "ForgottenGUI::createImageAbs",
    KenshiLib::GetRealAddress(&ForgottenGUI::createImageAbs),
    ForgottenGUI_createImageAbs_hook, ForgottenGUI_createImageAbs_orig)

static MyGUI::ImageBox* (*ForgottenGUI_createRotatableImageAbs_orig)(ForgottenGUI*, MyGUI::Widget*, int, int, int, int, const std::string&) = NULL;
static MyGUI::ImageBox* ForgottenGUI_createRotatableImageAbs_hook(ForgottenGUI* thisptr, MyGUI::Widget* parent, int top, int left, int width, int height, const std::string& image)
{
    MyGUI::ImageBox* res = ForgottenGUI_createRotatableImageAbs_orig(thisptr, parent, top, left, width, height, image);
    CallForgottenGUICreateRotatableImageAbsCallbacks(thisptr, parent, top, left, width, height, image, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_createRotatableImageAbs,
    "ForgottenGUI::createRotatableImageAbs",
    KenshiLib::GetRealAddress(&ForgottenGUI::createRotatableImageAbs),
    ForgottenGUI_createRotatableImageAbs_hook, ForgottenGUI_createRotatableImageAbs_orig)

static MyGUI::TabControl* (*ForgottenGUI_createTabPanel_orig)(ForgottenGUI*, const std::string&, float, float, float, float, const std::string&, const std::string&) = NULL;
static MyGUI::TabControl* ForgottenGUI_createTabPanel_hook(ForgottenGUI* thisptr, const std::string& name, float top, float left, float width, float height, const std::string& layer, const std::string& skin)
{
    MyGUI::TabControl* res = ForgottenGUI_createTabPanel_orig(thisptr, name, top, left, width, height, layer, skin);
    CallForgottenGUICreateTabPanelCallbacks(thisptr, name, top, left, width, height, layer, skin, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_createTabPanel,
    "ForgottenGUI::createTabPanel",
    KenshiLib::GetRealAddress(&ForgottenGUI::createTabPanel),
    ForgottenGUI_createTabPanel_hook, ForgottenGUI_createTabPanel_orig)

static MyGUI::Button* (*ForgottenGUI_createButtonAbs_orig)(ForgottenGUI*, MyGUI::Widget*, int, int, int, int, const std::string&, const std::string&, const std::string&) = NULL;
static MyGUI::Button* ForgottenGUI_createButtonAbs_hook(ForgottenGUI* thisptr, MyGUI::Widget* parent, int top, int left, int width, int height, const std::string& name, const std::string& text, const std::string& skin)
{
    MyGUI::Button* res = ForgottenGUI_createButtonAbs_orig(thisptr, parent, top, left, width, height, name, text, skin);
    CallForgottenGUICreateButtonAbsCallbacks(thisptr, parent, top, left, width, height, name, text, skin, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_createButtonAbs,
    "ForgottenGUI::createButtonAbs",
    KenshiLib::GetRealAddress(&ForgottenGUI::createButtonAbs),
    ForgottenGUI_createButtonAbs_hook, ForgottenGUI_createButtonAbs_orig)

static MyGUI::Button* (*ForgottenGUI_createButton_orig)(ForgottenGUI*, MyGUI::Widget*, float, float, float, float, const std::string&, const std::string&, const std::string&) = NULL;
static MyGUI::Button* ForgottenGUI_createButton_hook(ForgottenGUI* thisptr, MyGUI::Widget* parent, float top, float left, float width, float height, const std::string& name, const std::string& text, const std::string& skin)
{
    MyGUI::Button* res = ForgottenGUI_createButton_orig(thisptr, parent, top, left, width, height, name, text, skin);
    CallForgottenGUICreateButtonCallbacks(thisptr, parent, top, left, width, height, name, text, skin, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_createButton,
    "ForgottenGUI::createButton",
    KenshiLib::GetRealAddress(&ForgottenGUI::createButton),
    ForgottenGUI_createButton_hook, ForgottenGUI_createButton_orig)

static MyGUI::ComboBox* (*ForgottenGUI_createDropBox_orig)(ForgottenGUI*, MyGUI::Widget*, const std::string&, float, float, float, float) = NULL;
static MyGUI::ComboBox* ForgottenGUI_createDropBox_hook(ForgottenGUI* thisptr, MyGUI::Widget* parent, const std::string& name, float top, float left, float width, float height)
{
    MyGUI::ComboBox* res = ForgottenGUI_createDropBox_orig(thisptr, parent, name, top, left, width, height);
    CallForgottenGUICreateDropBoxCallbacks(thisptr, parent, name, top, left, width, height, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_createDropBox,
    "ForgottenGUI::createDropBox",
    KenshiLib::GetRealAddress(&ForgottenGUI::createDropBox),
    ForgottenGUI_createDropBox_hook, ForgottenGUI_createDropBox_orig)

static MyGUI::ComboBox* (*ForgottenGUI_createDropBoxAbs_orig)(ForgottenGUI*, MyGUI::Widget*, const std::string&, int, int, int, int) = NULL;
static MyGUI::ComboBox* ForgottenGUI_createDropBoxAbs_hook(ForgottenGUI* thisptr, MyGUI::Widget* parent, const std::string& name, int top, int left, int width, int height)
{
    MyGUI::ComboBox* res = ForgottenGUI_createDropBoxAbs_orig(thisptr, parent, name, top, left, width, height);
    CallForgottenGUICreateDropBoxAbsCallbacks(thisptr, parent, name, top, left, width, height, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_createDropBoxAbs,
    "ForgottenGUI::createDropBoxAbs",
    KenshiLib::GetRealAddress(&ForgottenGUI::createDropBoxAbs),
    ForgottenGUI_createDropBoxAbs_hook, ForgottenGUI_createDropBoxAbs_orig)

static MyGUI::ProgressBar* (*ForgottenGUI_createProgressBar_orig)(ForgottenGUI*, MyGUI::Widget*, float, float, float, float, const std::string&) = NULL;
static MyGUI::ProgressBar* ForgottenGUI_createProgressBar_hook(ForgottenGUI* thisptr, MyGUI::Widget* parent, float top, float left, float width, float height, const std::string& type)
{
    MyGUI::ProgressBar* res = ForgottenGUI_createProgressBar_orig(thisptr, parent, top, left, width, height, type);
    CallForgottenGUICreateProgressBarCallbacks(thisptr, parent, top, left, width, height, type, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_createProgressBar,
    "ForgottenGUI::createProgressBar",
    KenshiLib::GetRealAddress(&ForgottenGUI::createProgressBar),
    ForgottenGUI_createProgressBar_hook, ForgottenGUI_createProgressBar_orig)

static MyGUI::ProgressBar* (*ForgottenGUI_createProgressBarAbs_orig)(ForgottenGUI*, MyGUI::Widget*, float, float, float, float, const std::string&) = NULL;
static MyGUI::ProgressBar* ForgottenGUI_createProgressBarAbs_hook(ForgottenGUI* thisptr, MyGUI::Widget* parent, float top, float left, float width, float height, const std::string& type)
{
    MyGUI::ProgressBar* res = ForgottenGUI_createProgressBarAbs_orig(thisptr, parent, top, left, width, height, type);
    CallForgottenGUICreateProgressBarAbsCallbacks(thisptr, parent, top, left, width, height, type, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_createProgressBarAbs,
    "ForgottenGUI::createProgressBarAbs",
    KenshiLib::GetRealAddress(&ForgottenGUI::createProgressBarAbs),
    ForgottenGUI_createProgressBarAbs_hook, ForgottenGUI_createProgressBarAbs_orig)

static MyGUI::Window* (*ForgottenGUI_createFloatingLabel_orig)(ForgottenGUI*, float, float, float, float, const std::string&, MyGUI::Align, std::string) = NULL;
static MyGUI::Window* ForgottenGUI_createFloatingLabel_hook(ForgottenGUI* thisptr, float top, float left, float width, float height, const std::string& text, MyGUI::Align a, std::string layer)
{
    MyGUI::Window* res = ForgottenGUI_createFloatingLabel_orig(thisptr, top, left, width, height, text, a, layer);
    CallForgottenGUICreateFloatingLabelCallbacks(thisptr, top, left, width, height, text, a.getValue(), layer, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_createFloatingLabel,
    "ForgottenGUI::createFloatingLabel",
    KenshiLib::GetRealAddress(&ForgottenGUI::createFloatingLabel),
    ForgottenGUI_createFloatingLabel_hook, ForgottenGUI_createFloatingLabel_orig)

static MyGUI::EditBox* (*ForgottenGUI_createValueEdit_orig)(ForgottenGUI*, MyGUI::Widget*, float, float, float, float, const std::string&) = NULL;
static MyGUI::EditBox* ForgottenGUI_createValueEdit_hook(ForgottenGUI* thisptr, MyGUI::Widget* parent, float top, float left, float width, float height, const std::string& name)
{
    MyGUI::EditBox* res = ForgottenGUI_createValueEdit_orig(thisptr, parent, top, left, width, height, name);
    CallForgottenGUICreateValueEditCallbacks(thisptr, parent, top, left, width, height, name, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_createValueEdit,
    "ForgottenGUI::createValueEdit",
    KenshiLib::GetRealAddress(&ForgottenGUI::createValueEdit),
    ForgottenGUI_createValueEdit_hook, ForgottenGUI_createValueEdit_orig)

static MyGUI::ScrollBar* (*ForgottenGUI_createScrollBarAbs_orig)(ForgottenGUI*, MyGUI::Widget*, int, int, int, int, int, int) = NULL;
static MyGUI::ScrollBar* ForgottenGUI_createScrollBarAbs_hook(ForgottenGUI* thisptr, MyGUI::Widget* parent, int top, int left, int width, int height, int range, int value)
{
    MyGUI::ScrollBar* res = ForgottenGUI_createScrollBarAbs_orig(thisptr, parent, top, left, width, height, range, value);
    CallForgottenGUICreateScrollBarAbsCallbacks(thisptr, parent, top, left, width, height, range, value, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_createScrollBarAbs,
    "ForgottenGUI::createScrollBarAbs",
    KenshiLib::GetRealAddress(&ForgottenGUI::createScrollBarAbs),
    ForgottenGUI_createScrollBarAbs_hook, ForgottenGUI_createScrollBarAbs_orig)

static MyGUI::Button* (*ForgottenGUI_createCheckbox_orig)(ForgottenGUI*, MyGUI::Widget*, int, int, int, int, const std::string&) = NULL;
static MyGUI::Button* ForgottenGUI_createCheckbox_hook(ForgottenGUI* thisptr, MyGUI::Widget* parent, int left, int top, int width, int height, const std::string& caption)
{
    MyGUI::Button* res = ForgottenGUI_createCheckbox_orig(thisptr, parent, left, top, width, height, caption);
    CallForgottenGUICreateCheckboxCallbacks(thisptr, parent, left, top, width, height, caption, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_createCheckbox,
    "ForgottenGUI::createCheckbox",
    KenshiLib::GetRealAddress(&ForgottenGUI::createCheckbox),
    ForgottenGUI_createCheckbox_hook, ForgottenGUI_createCheckbox_orig)

static MyGUI::EditBox* (*ForgottenGUI_createValueEditTransparent_orig)(ForgottenGUI*, MyGUI::Widget*, float, float, float, float, const std::string&) = NULL;
static MyGUI::EditBox* ForgottenGUI_createValueEditTransparent_hook(ForgottenGUI* thisptr, MyGUI::Widget* parent, float top, float left, float width, float height, const std::string& name)
{
    MyGUI::EditBox* res = ForgottenGUI_createValueEditTransparent_orig(thisptr, parent, top, left, width, height, name);
    CallForgottenGUICreateValueEditTransparentCallbacks(thisptr, parent, top, left, width, height, name, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_createValueEditTransparent,
    "ForgottenGUI::createValueEditTransparent",
    KenshiLib::GetRealAddress(&ForgottenGUI::createValueEditTransparent),
    ForgottenGUI_createValueEditTransparent_hook, ForgottenGUI_createValueEditTransparent_orig)

static MyGUI::ListBox* (*ForgottenGUI_createListbox_orig)(ForgottenGUI*, MyGUI::Window*, float, float, float, float) = NULL;
static MyGUI::ListBox* ForgottenGUI_createListbox_hook(ForgottenGUI* thisptr, MyGUI::Window* parent, float top, float left, float width, float height)
{
    MyGUI::ListBox* res = ForgottenGUI_createListbox_orig(thisptr, parent, top, left, width, height);
    CallForgottenGUICreateListboxCallbacks(thisptr, parent, top, left, width, height, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_createListbox,
    "ForgottenGUI::createListbox",
    KenshiLib::GetRealAddress(&ForgottenGUI::createListbox),
    ForgottenGUI_createListbox_hook, ForgottenGUI_createListbox_orig)

static MyGUI::Window* (*ForgottenGUI_createFloatingImage_orig)(ForgottenGUI*, const std::string&, float, float, float, float, std::string) = NULL;
static MyGUI::Window* ForgottenGUI_createFloatingImage_hook(ForgottenGUI* thisptr, const std::string& image, float top, float left, float width, float height, std::string layer)
{
    MyGUI::Window* res = ForgottenGUI_createFloatingImage_orig(thisptr, image, top, left, width, height, layer);
    CallForgottenGUICreateFloatingImageCallbacks(thisptr, image, top, left, width, height, layer, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_createFloatingImage,
    "ForgottenGUI::createFloatingImage",
    KenshiLib::GetRealAddress(&ForgottenGUI::createFloatingImage),
    ForgottenGUI_createFloatingImage_hook, ForgottenGUI_createFloatingImage_orig)

static MyGUI::Window* (*ForgottenGUI_createFloatingImageAbs_orig)(ForgottenGUI*, const std::string&, float, float, float, float, std::string) = NULL;
static MyGUI::Window* ForgottenGUI_createFloatingImageAbs_hook(ForgottenGUI* thisptr, const std::string& image, float top, float left, float width, float height, std::string layer)
{
    MyGUI::Window* res = ForgottenGUI_createFloatingImageAbs_orig(thisptr, image, top, left, width, height, layer);
    CallForgottenGUICreateFloatingImageAbsCallbacks(thisptr, image, top, left, width, height, layer, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_createFloatingImageAbs,
    "ForgottenGUI::createFloatingImageAbs",
    KenshiLib::GetRealAddress(&ForgottenGUI::createFloatingImageAbs),
    ForgottenGUI_createFloatingImageAbs_hook, ForgottenGUI_createFloatingImageAbs_orig)

static FloatingProgressBar* (*ForgottenGUI_createFloatingProgressBar_orig)(ForgottenGUI*) = NULL;
static FloatingProgressBar* ForgottenGUI_createFloatingProgressBar_hook(ForgottenGUI* thisptr)
{
    FloatingProgressBar* res = ForgottenGUI_createFloatingProgressBar_orig(thisptr);
    CallForgottenGUICreateFloatingProgressBarCallbacks(thisptr, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_createFloatingProgressBar,
    "ForgottenGUI::createFloatingProgressBar",
    KenshiLib::GetRealAddress(&ForgottenGUI::createFloatingProgressBar),
    ForgottenGUI_createFloatingProgressBar_hook, ForgottenGUI_createFloatingProgressBar_orig)

static ScreenLabel* (*ForgottenGUI_createScreenLabel_orig)(ForgottenGUI*, const std::string&, const MyGUI::Colour&, ScreenLabel::LabelSize, ScreenLabel::RisingSpeed) = NULL;
static ScreenLabel* ForgottenGUI_createScreenLabel_hook(ForgottenGUI* thisptr, const std::string& text, const MyGUI::Colour& textColour, ScreenLabel::LabelSize textSize, ScreenLabel::RisingSpeed risingSpeed)
{
    ScreenLabel* res = ForgottenGUI_createScreenLabel_orig(thisptr, text, textColour, textSize, risingSpeed);
    CallForgottenGUICreateScreenLabelCallbacks(thisptr, text, textColour, static_cast<int>(textSize), static_cast<int>(risingSpeed), res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_createScreenLabel,
    "ForgottenGUI::createScreenLabel",
    KenshiLib::GetRealAddress(&ForgottenGUI::createScreenLabel),
    ForgottenGUI_createScreenLabel_hook, ForgottenGUI_createScreenLabel_orig)

static ScreenLabelDebug* (*ForgottenGUI_createScreenLabelD_orig)(ForgottenGUI*, const std::string&, float) = NULL;
static ScreenLabelDebug* ForgottenGUI_createScreenLabelD_hook(ForgottenGUI* thisptr, const std::string& text, float time)
{
    ScreenLabelDebug* res = ForgottenGUI_createScreenLabelD_orig(thisptr, text, time);
    CallForgottenGUICreateScreenLabelDCallbacks(thisptr, text, time, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ForgottenGUI_createScreenLabelD,
    "ForgottenGUI::createScreenLabelD",
    KenshiLib::GetRealAddress(&ForgottenGUI::createScreenLabelD),
    ForgottenGUI_createScreenLabelD_hook, ForgottenGUI_createScreenLabelD_orig)
