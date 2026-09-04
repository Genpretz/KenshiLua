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
