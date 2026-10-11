#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/gui/OptionsWindow.h>

// ---------------------------------------------------------------------------
// Hooks for OptionsWindow.h
//
// Virtual entries are represented only by their address-bearing _NV_ bodies.
// Scalar and singleton results accept Lua overrides.
// ---------------------------------------------------------------------------

#define OPTIONS_VOID0(method, Callback) \
    static void (*OptionsWindow_##method##_orig)(OptionsWindow*) = NULL; \
    static void OptionsWindow_##method##_hook(OptionsWindow* thisptr) \
    { \
        OptionsWindow_##method##_orig(thisptr); \
        Callback(thisptr); \
    } \
    DEFINE_HOOK_INSTALLER(InstallHook_OptionsWindow_##method, \
        "OptionsWindow::" #method, KenshiLib::GetRealAddress(&OptionsWindow::method), \
        OptionsWindow_##method##_hook, OptionsWindow_##method##_orig)

#define OPTIONS_LINE(method, Callback) \
    static void (*OptionsWindow_##method##_orig)(OptionsWindow*, DataPanelLine*) = NULL; \
    static void OptionsWindow_##method##_hook(OptionsWindow* thisptr, DataPanelLine* line) \
    { \
        OptionsWindow_##method##_orig(thisptr, line); \
        Callback(thisptr, line); \
    } \
    DEFINE_HOOK_INSTALLER(InstallHook_OptionsWindow_##method, \
        "OptionsWindow::" #method, KenshiLib::GetRealAddress(&OptionsWindow::method), \
        OptionsWindow_##method##_hook, OptionsWindow_##method##_orig)

static OptionsWindow* (*OptionsWindow_getSingleton_orig)() = NULL;
static OptionsWindow* OptionsWindow_getSingleton_hook()
{
    OptionsWindow* result = OptionsWindow_getSingleton_orig();
    OptionsWindow* overrideResult = CallOptionsWindowGetSingletonCallbacks(result);
    return overrideResult ? overrideResult : result;
}
DEFINE_HOOK_INSTALLER(InstallHook_OptionsWindow_static_getSingleton,
    "OptionsWindow::getSingleton", KenshiLib::GetRealAddress(&OptionsWindow::getSingleton),
    OptionsWindow_getSingleton_hook, OptionsWindow_getSingleton_orig)

static void (*OptionsWindow__NV_show_orig)(OptionsWindow*, bool) = NULL;
static void OptionsWindow__NV_show_hook(OptionsWindow* thisptr, bool value)
{
    OptionsWindow__NV_show_orig(thisptr, value);
    CallOptionsWindowNVShowCallbacks(thisptr, value);
}
DEFINE_HOOK_INSTALLER(InstallHook_OptionsWindow__NV_show,
    "OptionsWindow::_NV_show", KenshiLib::GetRealAddress(&OptionsWindow::_NV_show),
    OptionsWindow__NV_show_hook, OptionsWindow__NV_show_orig)

static void (*OptionsWindow_show_orig)(OptionsWindow*) = NULL;
static void OptionsWindow_show_hook(OptionsWindow* thisptr)
{
    OptionsWindow_show_orig(thisptr);
    CallOptionsWindowShowCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_OptionsWindow_show,
    "OptionsWindow::show",
    KenshiLib::GetRealAddress(static_cast<void (OptionsWindow::*)()>(&OptionsWindow::show)),
    OptionsWindow_show_hook, OptionsWindow_show_orig)
OPTIONS_VOID0(hide, CallOptionsWindowHideCallbacks)
OPTIONS_VOID0(toggle, CallOptionsWindowToggleCallbacks)

#define OPTIONS_BOOL(method, Callback) \
    static bool (*OptionsWindow_##method##_orig)(OptionsWindow*) = NULL; \
    static bool OptionsWindow_##method##_hook(OptionsWindow* thisptr) \
    { \
        bool result = OptionsWindow_##method##_orig(thisptr); \
        return Callback(thisptr, result); \
    } \
    DEFINE_HOOK_INSTALLER(InstallHook_OptionsWindow_##method, \
        "OptionsWindow::" #method, KenshiLib::GetRealAddress(&OptionsWindow::method), \
        OptionsWindow_##method##_hook, OptionsWindow_##method##_orig)

OPTIONS_BOOL(isVisible, CallOptionsWindowIsVisibleCallbacks)
OPTIONS_BOOL(waitingForKey, CallOptionsWindowWaitingForKeyCallbacks)

static void (*OptionsWindow_setKey_orig)(OptionsWindow*, const OIS::KeyCode&) = NULL;
static void OptionsWindow_setKey_hook(OptionsWindow* thisptr, const OIS::KeyCode& code)
{
    OptionsWindow_setKey_orig(thisptr, code);
    CallOptionsWindowSetKeyCallbacks(thisptr, static_cast<int>(code));
}
DEFINE_HOOK_INSTALLER(InstallHook_OptionsWindow_setKey,
    "OptionsWindow::setKey", KenshiLib::GetRealAddress(&OptionsWindow::setKey),
    OptionsWindow_setKey_hook, OptionsWindow_setKey_orig)

OPTIONS_VOID0(_NV_update, CallOptionsWindowNVUpdateCallbacks)

static OptionsWindow* (*OptionsWindow_CONSTRUCTOR_orig)(OptionsWindow*) = NULL;
static OptionsWindow* OptionsWindow_CONSTRUCTOR_hook(OptionsWindow* thisptr)
{
    OptionsWindow* result = OptionsWindow_CONSTRUCTOR_orig(thisptr);
    CallOptionsWindowConstructedCallbacks(thisptr);
    return result;
}
DEFINE_HOOK_INSTALLER(InstallHook_OptionsWindow_CONSTRUCTOR,
    "OptionsWindow::_CONSTRUCTOR", KenshiLib::GetRealAddress(&OptionsWindow::_CONSTRUCTOR),
    OptionsWindow_CONSTRUCTOR_hook, OptionsWindow_CONSTRUCTOR_orig)

static void (*OptionsWindow_DESTRUCTOR_orig)(OptionsWindow*) = NULL;
static void OptionsWindow_DESTRUCTOR_hook(OptionsWindow* thisptr)
{
    CallOptionsWindowDestructorCallbacks(thisptr);
    OptionsWindow_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_OptionsWindow_DESTRUCTOR,
    "OptionsWindow::_DESTRUCTOR", KenshiLib::GetRealAddress(&OptionsWindow::_DESTRUCTOR),
    OptionsWindow_DESTRUCTOR_hook, OptionsWindow_DESTRUCTOR_orig)

OPTIONS_LINE(saveLocationChanged, CallOptionsWindowSaveLocationChangedCallbacks)
OPTIONS_LINE(changeFontSize, CallOptionsWindowChangeFontSizeCallbacks)
OPTIONS_LINE(changeVolume, CallOptionsWindowChangeVolumeCallbacks)
OPTIONS_LINE(toggleNames, CallOptionsWindowToggleNamesCallbacks)
OPTIONS_LINE(resetTutorials, CallOptionsWindowResetTutorialsCallbacks)
OPTIONS_LINE(toggleTutorials, CallOptionsWindowToggleTutorialsCallbacks)
OPTIONS_LINE(changeDistances, CallOptionsWindowChangeDistancesCallbacks)
OPTIONS_LINE(toggleCompositor, CallOptionsWindowToggleCompositorCallbacks)
OPTIONS_LINE(resetAllKeys, CallOptionsWindowResetAllKeysCallbacks)
OPTIONS_VOID0(saveOptions, CallOptionsWindowSaveOptionsCallbacks)
OPTIONS_VOID0(create, CallOptionsWindowCreateCallbacks)
OPTIONS_VOID0(updateResolutions, CallOptionsWindowUpdateResolutionsCallbacks)

static void (*OptionsWindow_closeButton_orig)(OptionsWindow*, MyGUI::Widget*) = NULL;
static void OptionsWindow_closeButton_hook(OptionsWindow* thisptr, MyGUI::Widget* sender)
{
    OptionsWindow_closeButton_orig(thisptr, sender);
    CallOptionsWindowCloseButtonCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_OptionsWindow_closeButton,
    "OptionsWindow::closeButton", KenshiLib::GetRealAddress(&OptionsWindow::closeButton),
    OptionsWindow_closeButton_hook, OptionsWindow_closeButton_orig)

#undef OPTIONS_BOOL
#undef OPTIONS_LINE
#undef OPTIONS_VOID0
