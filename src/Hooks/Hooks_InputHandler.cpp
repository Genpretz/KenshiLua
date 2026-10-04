#include "pch.h"
#include "Hooks_Common.h"

// ---------------------------------------------------------------------------
// Hooks for InputHandler.h
// ---------------------------------------------------------------------------

static void (*InputHandler_keyDownEvent_orig)(InputHandler* thisptr, OIS::KeyCode key) = NULL;
static void InputHandler_keyDownEvent_hook(InputHandler* thisptr, OIS::KeyCode key)
{
    InputHandler_keyDownEvent_orig(thisptr, key);
    KenshiLua::GuiManager::get().checkKeyboardShortcut(key, thisptr);
    CallKeyDownCallbacks(thisptr, static_cast<int>(key));
}
DEFINE_HOOK_INSTALLER(InstallHook_InputHandler_KeyDown,
    "InputHandler::keyDownEvent",
    KenshiLib::GetRealAddress(&InputHandler::keyDownEvent),
    InputHandler_keyDownEvent_hook, InputHandler_keyDownEvent_orig)

static InputHandler* (*InputHandler_CONSTRUCTOR_orig)(InputHandler*) = NULL;
static InputHandler* InputHandler_CONSTRUCTOR_hook(InputHandler* thisptr)
{
    InputHandler* res = InputHandler_CONSTRUCTOR_orig(thisptr);
    InputHandler* overrideRes = CallInputHandlerConstructedCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InputHandler_CONSTRUCTOR,
    "InputHandler::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&InputHandler::_CONSTRUCTOR),
    InputHandler_CONSTRUCTOR_hook, InputHandler_CONSTRUCTOR_orig)
