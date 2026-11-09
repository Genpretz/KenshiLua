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

static bool (*BountyManager_setCrime_orig)(BountyManager*, CrimeEnum, Faction*, const hand&) = NULL;
static bool BountyManager_setCrime_hook(BountyManager* thisptr, CrimeEnum crime, Faction* againstFaction, const hand& againstHandle)
{
    bool accepted = BountyManager_setCrime_orig(thisptr, crime, againstFaction, againstHandle);
    CallBountyManagerSetCrimeCallbacks(thisptr, static_cast<int>(crime), againstFaction, againstHandle, accepted);
    return accepted;
}
DEFINE_HOOK_INSTALLER(InstallHook_BountyManager_setCrime,
    "BountyManager::setCrime",
    KenshiLib::GetRealAddress(&BountyManager::setCrime),
    BountyManager_setCrime_hook, BountyManager_setCrime_orig)

static void (*BountyManager_notifyStartPrisonSentence_orig)(BountyManager*, Faction*) = NULL;
static void BountyManager_notifyStartPrisonSentence_hook(BountyManager* thisptr, Faction* lawFaction)
{
    BountyManager_notifyStartPrisonSentence_orig(thisptr, lawFaction);
    CallBountyManagerStartPrisonSentenceCallbacks(thisptr, lawFaction);
}
DEFINE_HOOK_INSTALLER(InstallHook_BountyManager_notifyStartPrisonSentence,
    "BountyManager::notifyStartPrisonSentence",
    KenshiLib::GetRealAddress(&BountyManager::notifyStartPrisonSentence),
    BountyManager_notifyStartPrisonSentence_hook, BountyManager_notifyStartPrisonSentence_orig)

static void (*BountyManager_notifyPlayerClaimBounty_orig)(BountyManager*, Faction*) = NULL;
static void BountyManager_notifyPlayerClaimBounty_hook(BountyManager* thisptr, Faction* faction)
{
    BountyManager_notifyPlayerClaimBounty_orig(thisptr, faction);
    CallBountyManagerPlayerClaimBountyCallbacks(thisptr, faction);
}
DEFINE_HOOK_INSTALLER(InstallHook_BountyManager_notifyPlayerClaimBounty,
    "BountyManager::notifyPlayerClaimBounty",
    KenshiLib::GetRealAddress(&BountyManager::notifyPlayerClaimBounty),
    BountyManager_notifyPlayerClaimBounty_hook, BountyManager_notifyPlayerClaimBounty_orig)

static void (*BountyManager_assignBountyForCrimes_orig)(BountyManager*, Faction*) = NULL;
static void BountyManager_assignBountyForCrimes_hook(BountyManager* thisptr, Faction* enforcer)
{
    BountyManager_assignBountyForCrimes_orig(thisptr, enforcer);
    CallBountyManagerAssignBountyCallbacks(thisptr, enforcer);
}
DEFINE_HOOK_INSTALLER(InstallHook_BountyManager_assignBountyForCrimes,
    "BountyManager::assignBountyForCrimes",
    KenshiLib::GetRealAddress(&BountyManager::assignBountyForCrimes),
    BountyManager_assignBountyForCrimes_hook, BountyManager_assignBountyForCrimes_orig)

static void (*BountyManager_clearBounty_orig)(BountyManager*, Faction*) = NULL;
static void BountyManager_clearBounty_hook(BountyManager* thisptr, Faction* enforcer)
{
    BountyManager_clearBounty_orig(thisptr, enforcer);
    CallBountyManagerClearBountyCallbacks(thisptr, enforcer);
}
DEFINE_HOOK_INSTALLER(InstallHook_BountyManager_clearBounty,
    "BountyManager::clearBounty",
    KenshiLib::GetRealAddress(&BountyManager::clearBounty),
    BountyManager_clearBounty_hook, BountyManager_clearBounty_orig)

static void (*BountyManager_unfairAddToBounty_orig)(BountyManager*, Faction*, int) = NULL;
static void BountyManager_unfairAddToBounty_hook(BountyManager* thisptr, Faction* enforcer, int amount)
{
    BountyManager_unfairAddToBounty_orig(thisptr, enforcer, amount);
    CallBountyManagerUnfairAddToBountyCallbacks(thisptr, enforcer, amount);
}
DEFINE_HOOK_INSTALLER(InstallHook_BountyManager_unfairAddToBounty,
    "BountyManager::unfairAddToBounty",
    KenshiLib::GetRealAddress(&BountyManager::unfairAddToBounty),
    BountyManager_unfairAddToBounty_hook, BountyManager_unfairAddToBounty_orig)
