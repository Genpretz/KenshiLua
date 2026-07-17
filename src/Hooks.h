#pragma once

#include <string>

// ---------------------------------------------------------------------------
// Hooks
//
// Installs all KenshiLib function hooks needed by the event system.
// Call once during DLL initialisation, after the Lua state and EventSystem
// have been set up (so that any callbacks fired immediately are safe to
// dispatch).
//
// Returns true if every hook was installed successfully.
// Returns false if any hook failed; partial installation is possible —
// check the log for details on which hook(s) failed.
//
// It is safe to call InstallHooks() more than once; each individual hook
// function guards against double-installation and will return true without
// re-hooking if already installed.
// ---------------------------------------------------------------------------
namespace KenshiLua
{
    bool InstallHookForEvent(const std::string& eventName);
}

