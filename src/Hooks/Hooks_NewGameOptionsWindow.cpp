#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/gui/NewGameOptionsWindow.h>

// ---------------------------------------------------------------------------
// Hooks for NewGameOptionsWindow.h
//
// All address-bearing non-virtual members. Events fire after the original call
// except for the destructor. getVisible supplies the engine result as the Lua
// default and accepts a boolean override.
// ---------------------------------------------------------------------------

static NewGameOptionsWindow* (*NewGameOptionsWindow_CONSTRUCTOR_orig)(NewGameOptionsWindow*) = NULL;
static NewGameOptionsWindow* NewGameOptionsWindow_CONSTRUCTOR_hook(NewGameOptionsWindow* thisptr)
{
    NewGameOptionsWindow* res = NewGameOptionsWindow_CONSTRUCTOR_orig(thisptr);
    CallNewGameOptionsWindowConstructedCallbacks(thisptr);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_NewGameOptionsWindow_CONSTRUCTOR,
    "NewGameOptionsWindow::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&NewGameOptionsWindow::_CONSTRUCTOR),
    NewGameOptionsWindow_CONSTRUCTOR_hook, NewGameOptionsWindow_CONSTRUCTOR_orig)

static void (*NewGameOptionsWindow_DESTRUCTOR_orig)(NewGameOptionsWindow*) = NULL;
static void NewGameOptionsWindow_DESTRUCTOR_hook(NewGameOptionsWindow* thisptr)
{
    CallNewGameOptionsWindowDestructorCallbacks(thisptr);
    NewGameOptionsWindow_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_NewGameOptionsWindow_DESTRUCTOR,
    "NewGameOptionsWindow::_DESTRUCTOR",
    KenshiLib::GetRealAddress(&NewGameOptionsWindow::_DESTRUCTOR),
    NewGameOptionsWindow_DESTRUCTOR_hook, NewGameOptionsWindow_DESTRUCTOR_orig)

static void (*NewGameOptionsWindow_setVisible_orig)(NewGameOptionsWindow*, bool) = NULL;
static void NewGameOptionsWindow_setVisible_hook(NewGameOptionsWindow* thisptr, bool visible)
{
    NewGameOptionsWindow_setVisible_orig(thisptr, visible);
    CallNewGameOptionsWindowSetVisibleCallbacks(thisptr, visible);
}
DEFINE_HOOK_INSTALLER(InstallHook_NewGameOptionsWindow_setVisible,
    "NewGameOptionsWindow::setVisible",
    KenshiLib::GetRealAddress(&NewGameOptionsWindow::setVisible),
    NewGameOptionsWindow_setVisible_hook, NewGameOptionsWindow_setVisible_orig)

static bool (*NewGameOptionsWindow_getVisible_orig)(const NewGameOptionsWindow*) = NULL;
static bool NewGameOptionsWindow_getVisible_hook(const NewGameOptionsWindow* thisptr)
{
    bool res = NewGameOptionsWindow_getVisible_orig(thisptr);
    return CallNewGameOptionsWindowGetVisibleCallbacks(const_cast<NewGameOptionsWindow*>(thisptr), res);
}
DEFINE_HOOK_INSTALLER(InstallHook_NewGameOptionsWindow_getVisible,
    "NewGameOptionsWindow::getVisible",
    KenshiLib::GetRealAddress(&NewGameOptionsWindow::getVisible),
    NewGameOptionsWindow_getVisible_hook, NewGameOptionsWindow_getVisible_orig)

static void (*NewGameOptionsWindow_setPosition_orig)(NewGameOptionsWindow*, int, int) = NULL;
static void NewGameOptionsWindow_setPosition_hook(NewGameOptionsWindow* thisptr, int x, int y)
{
    NewGameOptionsWindow_setPosition_orig(thisptr, x, y);
    CallNewGameOptionsWindowSetPositionCallbacks(thisptr, x, y);
}
DEFINE_HOOK_INSTALLER(InstallHook_NewGameOptionsWindow_setPosition,
    "NewGameOptionsWindow::setPosition",
    KenshiLib::GetRealAddress(&NewGameOptionsWindow::setPosition),
    NewGameOptionsWindow_setPosition_hook, NewGameOptionsWindow_setPosition_orig)

static void (*NewGameOptionsWindow_update_orig)(NewGameOptionsWindow*) = NULL;
static void NewGameOptionsWindow_update_hook(NewGameOptionsWindow* thisptr)
{
    NewGameOptionsWindow_update_orig(thisptr);
    CallNewGameOptionsWindowUpdateCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_NewGameOptionsWindow_update,
    "NewGameOptionsWindow::update",
    KenshiLib::GetRealAddress(&NewGameOptionsWindow::update),
    NewGameOptionsWindow_update_hook, NewGameOptionsWindow_update_orig)

static void (*NewGameOptionsWindow_setOptions_orig)(NewGameOptionsWindow*, const GameplayOptions&) = NULL;
static void NewGameOptionsWindow_setOptions_hook(NewGameOptionsWindow* thisptr, const GameplayOptions& options)
{
    NewGameOptionsWindow_setOptions_orig(thisptr, options);
    CallNewGameOptionsWindowSetOptionsCallbacks(thisptr, options);
}
DEFINE_HOOK_INSTALLER(InstallHook_NewGameOptionsWindow_setOptions,
    "NewGameOptionsWindow::setOptions",
    KenshiLib::GetRealAddress(&NewGameOptionsWindow::setOptions),
    NewGameOptionsWindow_setOptions_hook, NewGameOptionsWindow_setOptions_orig)
