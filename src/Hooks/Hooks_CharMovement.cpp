#include "pch.h"
#include "Hooks_Common.h"

// ---------------------------------------------------------------------------
// Hooks for CharMovement.h
// ---------------------------------------------------------------------------

static bool (*CharMovement_isRunning_orig)(CharMovement*) = NULL;
static bool CharMovement_isRunning_hook(CharMovement* thisptr)
{
    bool current = CharMovement_isRunning_orig(thisptr);
    return CallCharMovementIsRunningCallbacks(thisptr, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharMovement_isRunning,
    "CharMovement::isRunning",
    KenshiLib::GetRealAddress(&CharMovement::isRunning),
    CharMovement_isRunning_hook, CharMovement_isRunning_orig)

static bool (*CharMovement_isRunningAway_orig)(CharMovement*, const Ogre::Vector3& from) = NULL;
static bool CharMovement_isRunningAway_hook(CharMovement* thisptr, const Ogre::Vector3& from)
{
    bool current = CharMovement_isRunningAway_orig(thisptr, from);
    return CallCharMovementIsRunningAwayCallbacks(thisptr, from, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharMovement_isRunningAway,
    "CharMovement::isRunningAway",
    KenshiLib::GetRealAddress(&CharMovement::isRunningAway),
    CharMovement_isRunningAway_hook, CharMovement_isRunningAway_orig)

static CharMovement* (*CharMovement_CONSTRUCTOR_orig)(CharMovement*) = NULL;
static CharMovement* CharMovement_CONSTRUCTOR_hook(CharMovement* thisptr)
{
    CharMovement* res = CharMovement_CONSTRUCTOR_orig(thisptr);
    CharMovement* overrideRes = CallCharMovementConstructedCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_CharMovement_CONSTRUCTOR,
    "CharMovement::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&CharMovement::_CONSTRUCTOR),
    CharMovement_CONSTRUCTOR_hook, CharMovement_CONSTRUCTOR_orig)

