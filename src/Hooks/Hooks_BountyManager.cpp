#include "pch.h"
#include "Hooks_Common.h"

// ---------------------------------------------------------------------------
// Hooks for BountyManager.h
// ---------------------------------------------------------------------------

static void (*BountyManager_notifyCrimeWitnessed_orig)(BountyManager*, Faction*, const hand&, int, CrimeEnum) = NULL;

static void BountyManager_notifyCrimeWitnessed_hook(BountyManager* thisptr, Faction* against, const hand& againstWho, int expiryTime, CrimeEnum crimeType)
{
    BountyManager_notifyCrimeWitnessed_orig(thisptr, against, againstWho, expiryTime, crimeType);
    CallCrimeWitnessedCallbacks(thisptr, against, againstWho, expiryTime, static_cast<int>(crimeType));
}

DEFINE_HOOK_INSTALLER(InstallHook_BountyManager_NotifyCrimeWitnessed,
    "BountyManager::notifyCrimeWitnessed",
    KenshiLib::GetRealAddress(&BountyManager::notifyCrimeWitnessed),
    BountyManager_notifyCrimeWitnessed_hook, BountyManager_notifyCrimeWitnessed_orig)

static BountyManager* (*BountyManager_CONSTRUCTOR_orig)(BountyManager*, Character*) = NULL;
static BountyManager* BountyManager_CONSTRUCTOR_hook(BountyManager* thisptr, Character* character)
{
    BountyManager* res = BountyManager_CONSTRUCTOR_orig(thisptr, character);
    BountyManager* overrideRes = CallBountyManagerConstructedCallbacks(thisptr, character, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_BountyManager_CONSTRUCTOR,
    "BountyManager::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&BountyManager::_CONSTRUCTOR),
    BountyManager_CONSTRUCTOR_hook, BountyManager_CONSTRUCTOR_orig)
