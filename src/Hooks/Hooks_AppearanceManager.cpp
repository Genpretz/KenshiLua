#include "pch.h"
#include "Hooks_Common.h"

#include <kenshi/AppearanceManager.h>

static AppearanceManager* (*AppearanceManager_CONSTRUCTOR_orig)(AppearanceManager*) = NULL;
static AppearanceManager* AppearanceManager_CONSTRUCTOR_hook(AppearanceManager* thisptr)
{
    AppearanceManager* res = AppearanceManager_CONSTRUCTOR_orig(thisptr);
    AppearanceManager* overrideRes = CallAppearanceManagerConstructedCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_AppearanceManager_CONSTRUCTOR,
    "AppearanceManager::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&AppearanceManager::_CONSTRUCTOR),
    AppearanceManager_CONSTRUCTOR_hook, AppearanceManager_CONSTRUCTOR_orig)
