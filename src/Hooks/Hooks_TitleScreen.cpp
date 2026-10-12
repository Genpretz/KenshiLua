#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/gui/TitleScreen.h>

// ---------------------------------------------------------------------------
// Hooks for TitleScreen.h
//
// Virtual entries are represented only by their address-bearing _NV_ bodies.
// Singleton and boolean results accept Lua overrides.
// ---------------------------------------------------------------------------

#define TITLE_VOID0(method, Callback) \
    static void (*TitleScreen_##method##_orig)(TitleScreen*) = NULL; \
    static void TitleScreen_##method##_hook(TitleScreen* thisptr) \
    { \
        TitleScreen_##method##_orig(thisptr); \
        Callback(thisptr); \
    } \
    DEFINE_HOOK_INSTALLER(InstallHook_TitleScreen_##method, \
        "TitleScreen::" #method, KenshiLib::GetRealAddress(&TitleScreen::method), \
        TitleScreen_##method##_hook, TitleScreen_##method##_orig)

#define TITLE_WIDGET(method, Callback) \
    static void (*TitleScreen_##method##_orig)(TitleScreen*, MyGUI::Widget*) = NULL; \
    static void TitleScreen_##method##_hook(TitleScreen* thisptr, MyGUI::Widget* sender) \
    { \
        TitleScreen_##method##_orig(thisptr, sender); \
        Callback(thisptr, sender); \
    } \
    DEFINE_HOOK_INSTALLER(InstallHook_TitleScreen_##method, \
        "TitleScreen::" #method, KenshiLib::GetRealAddress(&TitleScreen::method), \
        TitleScreen_##method##_hook, TitleScreen_##method##_orig)

static TitleScreen* (*TitleScreen_getSingleton_orig)() = NULL;
static TitleScreen* TitleScreen_getSingleton_hook()
{
    TitleScreen* result = TitleScreen_getSingleton_orig();
    TitleScreen* overrideResult = CallTitleScreenGetSingletonCallbacks(result);
    return overrideResult ? overrideResult : result;
}
DEFINE_HOOK_INSTALLER(InstallHook_TitleScreen_static_getSingleton,
    "TitleScreen::getSingleton", KenshiLib::GetRealAddress(&TitleScreen::getSingleton),
    TitleScreen_getSingleton_hook, TitleScreen_getSingleton_orig)

static TitleScreen* (*TitleScreen_CONSTRUCTOR_orig)(TitleScreen*) = NULL;
static TitleScreen* TitleScreen_CONSTRUCTOR_hook(TitleScreen* thisptr)
{
    TitleScreen* result = TitleScreen_CONSTRUCTOR_orig(thisptr);
    CallTitleScreenConstructedCallbacks(thisptr);
    return result;
}
DEFINE_HOOK_INSTALLER(InstallHook_TitleScreen_CONSTRUCTOR,
    "TitleScreen::_CONSTRUCTOR", KenshiLib::GetRealAddress(&TitleScreen::_CONSTRUCTOR),
    TitleScreen_CONSTRUCTOR_hook, TitleScreen_CONSTRUCTOR_orig)

static void (*TitleScreen_DESTRUCTOR_orig)(TitleScreen*) = NULL;
static void TitleScreen_DESTRUCTOR_hook(TitleScreen* thisptr)
{
    CallTitleScreenDestructorCallbacks(thisptr);
    TitleScreen_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_TitleScreen_DESTRUCTOR,
    "TitleScreen::_DESTRUCTOR", KenshiLib::GetRealAddress(&TitleScreen::_DESTRUCTOR),
    TitleScreen_DESTRUCTOR_hook, TitleScreen_DESTRUCTOR_orig)

TITLE_VOID0(_NV_clear, CallTitleScreenNVClearCallbacks)

static void (*TitleScreen__NV_show_orig)(TitleScreen*, bool) = NULL;
static void TitleScreen__NV_show_hook(TitleScreen* thisptr, bool on)
{
    TitleScreen__NV_show_orig(thisptr, on);
    CallTitleScreenNVShowCallbacks(thisptr, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_TitleScreen__NV_show,
    "TitleScreen::_NV_show", KenshiLib::GetRealAddress(&TitleScreen::_NV_show),
    TitleScreen__NV_show_hook, TitleScreen__NV_show_orig)

TITLE_VOID0(_NV_update, CallTitleScreenNVUpdateCallbacks)

static bool (*TitleScreen_closeTheOtherBits_orig)(TitleScreen*) = NULL;
static bool TitleScreen_closeTheOtherBits_hook(TitleScreen* thisptr)
{
    bool result = TitleScreen_closeTheOtherBits_orig(thisptr);
    return CallTitleScreenCloseTheOtherBitsCallbacks(thisptr, result);
}
DEFINE_HOOK_INSTALLER(InstallHook_TitleScreen_closeTheOtherBits,
    "TitleScreen::closeTheOtherBits", KenshiLib::GetRealAddress(&TitleScreen::closeTheOtherBits),
    TitleScreen_closeTheOtherBits_hook, TitleScreen_closeTheOtherBits_orig)

TITLE_WIDGET(loadGame, CallTitleScreenLoadGameCallbacks)
TITLE_WIDGET(importGame, CallTitleScreenImportGameCallbacks)
TITLE_WIDGET(showOptions, CallTitleScreenShowOptionsCallbacks)
TITLE_WIDGET(credits, CallTitleScreenCreditsCallbacks)
TITLE_WIDGET(exitGame, CallTitleScreenExitGameCallbacks)
TITLE_WIDGET(continueGame, CallTitleScreenContinueGameCallbacks)

static void (*TitleScreen_hover_orig)(TitleScreen*, MyGUI::Widget*, MyGUI::Widget*) = NULL;
static void TitleScreen_hover_hook(TitleScreen* thisptr, MyGUI::Widget* sender, MyGUI::Widget* other)
{
    TitleScreen_hover_orig(thisptr, sender, other);
    CallTitleScreenHoverCallbacks(thisptr, sender, other);
}
DEFINE_HOOK_INSTALLER(InstallHook_TitleScreen_hover,
    "TitleScreen::hover", KenshiLib::GetRealAddress(&TitleScreen::hover),
    TitleScreen_hover_hook, TitleScreen_hover_orig)

static void (*TitleScreen_setCreditsVisible_orig)(TitleScreen*, bool) = NULL;
static void TitleScreen_setCreditsVisible_hook(TitleScreen* thisptr, bool value)
{
    TitleScreen_setCreditsVisible_orig(thisptr, value);
    CallTitleScreenSetCreditsVisibleCallbacks(thisptr, value);
}
DEFINE_HOOK_INSTALLER(InstallHook_TitleScreen_setCreditsVisible,
    "TitleScreen::setCreditsVisible", KenshiLib::GetRealAddress(&TitleScreen::setCreditsVisible),
    TitleScreen_setCreditsVisible_hook, TitleScreen_setCreditsVisible_orig)

#undef TITLE_WIDGET
#undef TITLE_VOID0
