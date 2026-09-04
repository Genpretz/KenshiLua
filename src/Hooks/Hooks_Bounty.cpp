#include "pch.h"
#include "Hooks_Common.h"

// ---------------------------------------------------------------------------
// Hooks for Bounty.h
// ---------------------------------------------------------------------------

static Bounty* (*Bounty_CONSTRUCTOR_orig)(Bounty*) = NULL;
static Bounty* Bounty_CONSTRUCTOR_hook(Bounty* thisptr)
{
    Bounty* res = Bounty_CONSTRUCTOR_orig(thisptr);
    Bounty* overrideRes = CallBountyConstructedCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Bounty_CONSTRUCTOR,
    "Bounty::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&Bounty::_CONSTRUCTOR),
    Bounty_CONSTRUCTOR_hook, Bounty_CONSTRUCTOR_orig)
