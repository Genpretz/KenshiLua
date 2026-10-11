#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/gui/DialogueWindow.h>

// ---------------------------------------------------------------------------
// Hooks for DialogueWindow.h
//
// All address-bearing non-virtual members and the _NV_ bodies of virtual
// members. Events fire after the original call except for the destructor.
// Scalar getters supply the engine result as defaultVal and accept overrides.
// ---------------------------------------------------------------------------

static bool (*DialogueWindow_getVisible_orig)(const DialogueWindow*) = NULL;
static bool DialogueWindow_getVisible_hook(const DialogueWindow* thisptr)
{
    bool res = DialogueWindow_getVisible_orig(thisptr);
    return CallDialogueWindowGetVisibleCallbacks(const_cast<DialogueWindow*>(thisptr), res);
}
DEFINE_HOOK_INSTALLER(InstallHook_DialogueWindow_getVisible,
    "DialogueWindow::getVisible", KenshiLib::GetRealAddress(&DialogueWindow::getVisible),
    DialogueWindow_getVisible_hook, DialogueWindow_getVisible_orig)

static void (*DialogueWindow_setVisible_orig)(DialogueWindow*, bool) = NULL;
static void DialogueWindow_setVisible_hook(DialogueWindow* thisptr, bool visible)
{
    DialogueWindow_setVisible_orig(thisptr, visible);
    CallDialogueWindowSetVisibleCallbacks(thisptr, visible);
}
DEFINE_HOOK_INSTALLER(InstallHook_DialogueWindow_setVisible,
    "DialogueWindow::setVisible", KenshiLib::GetRealAddress(&DialogueWindow::setVisible),
    DialogueWindow_setVisible_hook, DialogueWindow_setVisible_orig)

static void (*DialogueWindow_NV_show_orig)(DialogueWindow*, bool) = NULL;
static void DialogueWindow_NV_show_hook(DialogueWindow* thisptr, bool on)
{
    DialogueWindow_NV_show_orig(thisptr, on);
    CallDialogueWindowNVShowCallbacks(thisptr, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_DialogueWindow_NV_show,
    "DialogueWindow::_NV_show", KenshiLib::GetRealAddress(&DialogueWindow::_NV_show),
    DialogueWindow_NV_show_hook, DialogueWindow_NV_show_orig)

static void (*DialogueWindow_show_orig)(DialogueWindow*, Dialogue*) = NULL;
static void DialogueWindow_show_hook(DialogueWindow* thisptr, Dialogue* dialogue)
{
    DialogueWindow_show_orig(thisptr, dialogue);
    CallDialogueWindowShowCallbacks(thisptr, dialogue);
}
DEFINE_HOOK_INSTALLER(InstallHook_DialogueWindow_Show,
    "DialogueWindow::show",
    KenshiLib::GetRealAddress(static_cast<void (DialogueWindow::*)(Dialogue*)>(&DialogueWindow::show)),
    DialogueWindow_show_hook, DialogueWindow_show_orig)

static void (*DialogueWindow_hide_orig)(DialogueWindow*, Dialogue*) = NULL;
static void DialogueWindow_hide_hook(DialogueWindow* thisptr, Dialogue* dialogue)
{
    DialogueWindow_hide_orig(thisptr, dialogue);
    CallDialogueWindowHideCallbacks(thisptr, dialogue);
}
DEFINE_HOOK_INSTALLER(InstallHook_DialogueWindow_hide,
    "DialogueWindow::hide", KenshiLib::GetRealAddress(&DialogueWindow::hide),
    DialogueWindow_hide_hook, DialogueWindow_hide_orig)

static bool (*DialogueWindow_NV_isVisible_orig)(const DialogueWindow*) = NULL;
static bool DialogueWindow_NV_isVisible_hook(const DialogueWindow* thisptr)
{
    bool res = DialogueWindow_NV_isVisible_orig(thisptr);
    return CallDialogueWindowNVIsVisibleCallbacks(const_cast<DialogueWindow*>(thisptr), res);
}
DEFINE_HOOK_INSTALLER(InstallHook_DialogueWindow_NV_isVisible,
    "DialogueWindow::_NV_isVisible", KenshiLib::GetRealAddress(&DialogueWindow::_NV_isVisible),
    DialogueWindow_NV_isVisible_hook, DialogueWindow_NV_isVisible_orig)

static void (*DialogueWindow_NV_update_orig)(DialogueWindow*) = NULL;
static void DialogueWindow_NV_update_hook(DialogueWindow* thisptr)
{
    DialogueWindow_NV_update_orig(thisptr);
    CallDialogueWindowNVUpdateCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DialogueWindow_NV_update,
    "DialogueWindow::_NV_update", KenshiLib::GetRealAddress(&DialogueWindow::_NV_update),
    DialogueWindow_NV_update_hook, DialogueWindow_NV_update_orig)

static int (*DialogueWindow_getTop_orig)(const DialogueWindow*) = NULL;
static int DialogueWindow_getTop_hook(const DialogueWindow* thisptr)
{
    int res = DialogueWindow_getTop_orig(thisptr);
    return CallDialogueWindowGetTopCallbacks(const_cast<DialogueWindow*>(thisptr), res);
}
DEFINE_HOOK_INSTALLER(InstallHook_DialogueWindow_getTop,
    "DialogueWindow::getTop", KenshiLib::GetRealAddress(&DialogueWindow::getTop),
    DialogueWindow_getTop_hook, DialogueWindow_getTop_orig)

static void (*DialogueWindow_activateResponse_orig)(DialogueWindow*, int) = NULL;
static void DialogueWindow_activateResponse_hook(DialogueWindow* thisptr, int index)
{
    DialogueWindow_activateResponse_orig(thisptr, index);
    CallDialogueWindowActivateResponseCallbacks(thisptr, index);
}
DEFINE_HOOK_INSTALLER(InstallHook_DialogueWindow_activateResponse,
    "DialogueWindow::activateResponse", KenshiLib::GetRealAddress(&DialogueWindow::activateResponse),
    DialogueWindow_activateResponse_hook, DialogueWindow_activateResponse_orig)

static void (*DialogueWindow_setNPCText_orig)(DialogueWindow*, const std::string&) = NULL;
static void DialogueWindow_setNPCText_hook(DialogueWindow* thisptr, const std::string& text)
{
    DialogueWindow_setNPCText_orig(thisptr, text);
    CallDialogueWindowSetNPCTextCallbacks(thisptr, text);
}
DEFINE_HOOK_INSTALLER(InstallHook_DialogueWindow_setNPCText,
    "DialogueWindow::setNPCText", KenshiLib::GetRealAddress(&DialogueWindow::setNPCText),
    DialogueWindow_setNPCText_hook, DialogueWindow_setNPCText_orig)

static void (*DialogueWindow_setResponses_orig)(DialogueWindow*, const Ogre::vector<std::string>::type&) = NULL;
static void DialogueWindow_setResponses_hook(DialogueWindow* thisptr, const Ogre::vector<std::string>::type& responses)
{
    DialogueWindow_setResponses_orig(thisptr, responses);
    CallDialogueWindowSetResponsesCallbacks(thisptr, &responses);
}
DEFINE_HOOK_INSTALLER(InstallHook_DialogueWindow_setResponses,
    "DialogueWindow::setResponses", KenshiLib::GetRealAddress(&DialogueWindow::setResponses),
    DialogueWindow_setResponses_hook, DialogueWindow_setResponses_orig)

static void (*DialogueWindow_clearResponses_orig)(DialogueWindow*) = NULL;
static void DialogueWindow_clearResponses_hook(DialogueWindow* thisptr)
{
    DialogueWindow_clearResponses_orig(thisptr);
    CallDialogueWindowClearResponsesCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DialogueWindow_clearResponses,
    "DialogueWindow::clearResponses", KenshiLib::GetRealAddress(&DialogueWindow::clearResponses),
    DialogueWindow_clearResponses_hook, DialogueWindow_clearResponses_orig)

static void (*DialogueWindow_changePortrait_orig)(DialogueWindow*, Character*, bool) = NULL;
static void DialogueWindow_changePortrait_hook(DialogueWindow* thisptr, Character* character, bool player)
{
    DialogueWindow_changePortrait_orig(thisptr, character, player);
    CallDialogueWindowChangePortraitCallbacks(thisptr, character, player);
}
DEFINE_HOOK_INSTALLER(InstallHook_DialogueWindow_changePortrait,
    "DialogueWindow::changePortrait", KenshiLib::GetRealAddress(&DialogueWindow::changePortrait),
    DialogueWindow_changePortrait_hook, DialogueWindow_changePortrait_orig)

static DialogueWindow* (*DialogueWindow_CONSTRUCTOR_orig)(DialogueWindow*) = NULL;
static DialogueWindow* DialogueWindow_CONSTRUCTOR_hook(DialogueWindow* thisptr)
{
    DialogueWindow* res = DialogueWindow_CONSTRUCTOR_orig(thisptr);
    DialogueWindow* overrideRes = CallDialogueWindowConstructedCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DialogueWindow_CONSTRUCTOR,
    "DialogueWindow::_CONSTRUCTOR", KenshiLib::GetRealAddress(&DialogueWindow::_CONSTRUCTOR),
    DialogueWindow_CONSTRUCTOR_hook, DialogueWindow_CONSTRUCTOR_orig)

static void (*DialogueWindow_DESTRUCTOR_orig)(DialogueWindow*) = NULL;
static void DialogueWindow_DESTRUCTOR_hook(DialogueWindow* thisptr)
{
    CallDialogueWindowDestructorCallbacks(thisptr);
    DialogueWindow_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DialogueWindow_DESTRUCTOR,
    "DialogueWindow::_DESTRUCTOR", KenshiLib::GetRealAddress(&DialogueWindow::_DESTRUCTOR),
    DialogueWindow_DESTRUCTOR_hook, DialogueWindow_DESTRUCTOR_orig)

static void (*DialogueWindow_updatePanelsPosition_orig)(DialogueWindow*) = NULL;
static void DialogueWindow_updatePanelsPosition_hook(DialogueWindow* thisptr)
{
    DialogueWindow_updatePanelsPosition_orig(thisptr);
    CallDialogueWindowUpdatePanelsPositionCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DialogueWindow_updatePanelsPosition,
    "DialogueWindow::updatePanelsPosition", KenshiLib::GetRealAddress(&DialogueWindow::updatePanelsPosition),
    DialogueWindow_updatePanelsPosition_hook, DialogueWindow_updatePanelsPosition_orig)
