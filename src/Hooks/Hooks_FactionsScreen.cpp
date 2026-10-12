#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/gui/FactionsScreen.h>

// ---------------------------------------------------------------------------
// Hooks for FactionsScreen.h
//
// All address-bearing non-virtual members. Events fire after the original call
// except for destructors. getVisible accepts a boolean return override.
// ---------------------------------------------------------------------------

static FactionsScreen::FactionRelationsLine* (*FactionRelationsLine_CONSTRUCTOR_orig)(FactionsScreen::FactionRelationsLine*, Faction*) = NULL;
static FactionsScreen::FactionRelationsLine* FactionRelationsLine_CONSTRUCTOR_hook(FactionsScreen::FactionRelationsLine* thisptr, Faction* faction)
{
    FactionsScreen::FactionRelationsLine* res = FactionRelationsLine_CONSTRUCTOR_orig(thisptr, faction);
    CallFactionRelationsLineConstructedCallbacks(thisptr, faction);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionRelationsLine_CONSTRUCTOR,
    "FactionsScreen::FactionRelationsLine::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&FactionsScreen::FactionRelationsLine::_CONSTRUCTOR),
    FactionRelationsLine_CONSTRUCTOR_hook, FactionRelationsLine_CONSTRUCTOR_orig)

static void (*FactionRelationsLine_attachToWidget_orig)(FactionsScreen::FactionRelationsLine*, MyGUI::Widget*) = NULL;
static void FactionRelationsLine_attachToWidget_hook(FactionsScreen::FactionRelationsLine* thisptr, MyGUI::Widget* widget)
{
    FactionRelationsLine_attachToWidget_orig(thisptr, widget);
    CallFactionRelationsLineAttachToWidgetCallbacks(thisptr, widget);
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionRelationsLine_attachToWidget,
    "FactionsScreen::FactionRelationsLine::attachToWidget",
    KenshiLib::GetRealAddress(&FactionsScreen::FactionRelationsLine::attachToWidget),
    FactionRelationsLine_attachToWidget_hook, FactionRelationsLine_attachToWidget_orig)

static void (*FactionRelationsLine_update_orig)(FactionsScreen::FactionRelationsLine*) = NULL;
static void FactionRelationsLine_update_hook(FactionsScreen::FactionRelationsLine* thisptr)
{
    FactionRelationsLine_update_orig(thisptr);
    CallFactionRelationsLineUpdateCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionRelationsLine_update,
    "FactionsScreen::FactionRelationsLine::update",
    KenshiLib::GetRealAddress(&FactionsScreen::FactionRelationsLine::update),
    FactionRelationsLine_update_hook, FactionRelationsLine_update_orig)

static void (*FactionRelationsLine_DESTRUCTOR_orig)(FactionsScreen::FactionRelationsLine*) = NULL;
static void FactionRelationsLine_DESTRUCTOR_hook(FactionsScreen::FactionRelationsLine* thisptr)
{
    CallFactionRelationsLineDestructorCallbacks(thisptr);
    FactionRelationsLine_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionRelationsLine_DESTRUCTOR,
    "FactionsScreen::FactionRelationsLine::_DESTRUCTOR",
    KenshiLib::GetRealAddress(&FactionsScreen::FactionRelationsLine::_DESTRUCTOR),
    FactionRelationsLine_DESTRUCTOR_hook, FactionRelationsLine_DESTRUCTOR_orig)

static bool (*FactionRelationsLine_LessSort_call_orig)(FactionsScreen::FactionRelationsLine::LessSort*, const FactionsScreen::FactionRelationsLine*, const FactionsScreen::FactionRelationsLine*) = NULL;
static bool FactionRelationsLine_LessSort_call_hook(FactionsScreen::FactionRelationsLine::LessSort* thisptr, const FactionsScreen::FactionRelationsLine* l1, const FactionsScreen::FactionRelationsLine* l2)
{
    bool res = FactionRelationsLine_LessSort_call_orig(thisptr, l1, l2);
    return CallFactionRelationsLineLessSortCallbacks(thisptr, const_cast<FactionsScreen::FactionRelationsLine*>(l1), const_cast<FactionsScreen::FactionRelationsLine*>(l2), res);
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionRelationsLine_LessSort_call,
    "FactionsScreen::FactionRelationsLine::LessSort::operator()",
    KenshiLib::GetRealAddress(&FactionsScreen::FactionRelationsLine::LessSort::operator()),
    FactionRelationsLine_LessSort_call_hook, FactionRelationsLine_LessSort_call_orig)

static FactionsScreen* (*FactionsScreen_CONSTRUCTOR_orig)(FactionsScreen*, ManagementScreen*) = NULL;
static FactionsScreen* FactionsScreen_CONSTRUCTOR_hook(FactionsScreen* thisptr, ManagementScreen* screen)
{
    FactionsScreen* res = FactionsScreen_CONSTRUCTOR_orig(thisptr, screen);
    CallFactionsScreenConstructedCallbacks(thisptr, screen);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionsScreen_CONSTRUCTOR,
    "FactionsScreen::_CONSTRUCTOR", KenshiLib::GetRealAddress(&FactionsScreen::_CONSTRUCTOR),
    FactionsScreen_CONSTRUCTOR_hook, FactionsScreen_CONSTRUCTOR_orig)

static void (*FactionsScreen_DESTRUCTOR_orig)(FactionsScreen*) = NULL;
static void FactionsScreen_DESTRUCTOR_hook(FactionsScreen* thisptr)
{
    CallFactionsScreenDestructorCallbacks(thisptr);
    FactionsScreen_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionsScreen_DESTRUCTOR,
    "FactionsScreen::_DESTRUCTOR", KenshiLib::GetRealAddress(&FactionsScreen::_DESTRUCTOR),
    FactionsScreen_DESTRUCTOR_hook, FactionsScreen_DESTRUCTOR_orig)

static bool (*FactionsScreen_getVisible_orig)(const FactionsScreen*) = NULL;
static bool FactionsScreen_getVisible_hook(const FactionsScreen* thisptr)
{
    bool res = FactionsScreen_getVisible_orig(thisptr);
    return CallFactionsScreenGetVisibleCallbacks(const_cast<FactionsScreen*>(thisptr), res);
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionsScreen_getVisible,
    "FactionsScreen::getVisible", KenshiLib::GetRealAddress(&FactionsScreen::getVisible),
    FactionsScreen_getVisible_hook, FactionsScreen_getVisible_orig)

#define FACTIONS_SCREEN_VOID0(method, Callback) \
    static void (*FactionsScreen_##method##_orig)(FactionsScreen*) = NULL; \
    static void FactionsScreen_##method##_hook(FactionsScreen* thisptr) \
    { \
        FactionsScreen_##method##_orig(thisptr); \
        Callback(thisptr); \
    } \
    DEFINE_HOOK_INSTALLER(InstallHook_FactionsScreen_##method, \
        "FactionsScreen::" #method, KenshiLib::GetRealAddress(&FactionsScreen::method), \
        FactionsScreen_##method##_hook, FactionsScreen_##method##_orig)

FACTIONS_SCREEN_VOID0(clear, CallFactionsScreenClearCallbacks)
FACTIONS_SCREEN_VOID0(update, CallFactionsScreenUpdateCallbacks)
FACTIONS_SCREEN_VOID0(refresh, CallFactionsScreenRefreshCallbacks)
FACTIONS_SCREEN_VOID0(updateInfo, CallFactionsScreenUpdateInfoCallbacks)

#undef FACTIONS_SCREEN_VOID0

static void (*FactionsScreen_notifyEditTextChange_orig)(FactionsScreen*, MyGUI::EditBox*) = NULL;
static void FactionsScreen_notifyEditTextChange_hook(FactionsScreen* thisptr, MyGUI::EditBox* sender)
{
    FactionsScreen_notifyEditTextChange_orig(thisptr, sender);
    CallFactionsScreenNotifyEditTextChangeCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionsScreen_notifyEditTextChange,
    "FactionsScreen::notifyEditTextChange", KenshiLib::GetRealAddress(&FactionsScreen::notifyEditTextChange),
    FactionsScreen_notifyEditTextChange_hook, FactionsScreen_notifyEditTextChange_orig)

#define FACTIONS_SCREEN_WIDGET2(method, Callback) \
    static void (*FactionsScreen_##method##_orig)(FactionsScreen*, MyGUI::Widget*, MyGUI::Widget*) = NULL; \
    static void FactionsScreen_##method##_hook(FactionsScreen* thisptr, MyGUI::Widget* first, MyGUI::Widget* second) \
    { \
        FactionsScreen_##method##_orig(thisptr, first, second); \
        Callback(thisptr, first, second); \
    } \
    DEFINE_HOOK_INSTALLER(InstallHook_FactionsScreen_##method, \
        "FactionsScreen::" #method, KenshiLib::GetRealAddress(&FactionsScreen::method), \
        FactionsScreen_##method##_hook, FactionsScreen_##method##_orig)

FACTIONS_SCREEN_WIDGET2(setFocus, CallFactionsScreenSetFocusCallbacks)
FACTIONS_SCREEN_WIDGET2(loseFocus, CallFactionsScreenLoseFocusCallbacks)

#undef FACTIONS_SCREEN_WIDGET2

static void (*FactionsScreen_factionLineSelected_orig)(FactionsScreen*, MyGUI::Widget*) = NULL;
static void FactionsScreen_factionLineSelected_hook(FactionsScreen* thisptr, MyGUI::Widget* sender)
{
    FactionsScreen_factionLineSelected_orig(thisptr, sender);
    CallFactionsScreenFactionLineSelectedCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionsScreen_factionLineSelected,
    "FactionsScreen::factionLineSelected", KenshiLib::GetRealAddress(&FactionsScreen::factionLineSelected),
    FactionsScreen_factionLineSelected_hook, FactionsScreen_factionLineSelected_orig)

static void (*FactionsScreen_notifyMouseWheel_orig)(FactionsScreen*, MyGUI::Widget*, int) = NULL;
static void FactionsScreen_notifyMouseWheel_hook(FactionsScreen* thisptr, MyGUI::Widget* sender, int rel)
{
    FactionsScreen_notifyMouseWheel_orig(thisptr, sender, rel);
    CallFactionsScreenNotifyMouseWheelCallbacks(thisptr, sender, rel);
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionsScreen_notifyMouseWheel,
    "FactionsScreen::notifyMouseWheel", KenshiLib::GetRealAddress(&FactionsScreen::notifyMouseWheel),
    FactionsScreen_notifyMouseWheel_hook, FactionsScreen_notifyMouseWheel_orig)
