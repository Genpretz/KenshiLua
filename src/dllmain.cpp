#include "pch.h"
#include "Plugin.h"

// --- RE_Kenshi plugin entry --------------------------------------------------

_declspec(dllexport) void startPlugin()
{
    if (KenshiLua::Plugin::get().initialize(KenshiLua::Plugin::get().getDllModule())) {
        KenshiLua::Plugin::get().start();
    }
}

// --- DllMain -----------------------------------------------------------------

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    (void)lpReserved;
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        // Cache the DLL module handle and defer main initialization to startPlugin
        KenshiLua::Plugin::get().initialize((void*)hModule);
        DisableThreadLibraryCalls(hModule);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        // Skip cleanup at process detach. Engine threads may still be alive
        // and tearing Lua / MyGUI / Ogre down here would race with them.
        // The OS reclaims everything when the process exits.
        break;
    }
    return TRUE;
}
