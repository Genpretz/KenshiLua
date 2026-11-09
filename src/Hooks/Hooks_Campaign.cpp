#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/Campaign.h>

// ---------------------------------------------------------------------------
// Hooks for Campaign.h
// ---------------------------------------------------------------------------

static void (*CampaignInstance_changePhase_orig)(CampaignInstance*, Phase) = NULL;
static void CampaignInstance_changePhase_hook(CampaignInstance* thisptr, Phase p)
{
    CampaignInstance_changePhase_orig(thisptr, p);
    CallCampaignChangePhaseCallbacks(thisptr, static_cast<int>(p));
}
DEFINE_HOOK_INSTALLER(InstallHook_CampaignInstance_changePhase,
    "CampaignInstance::changePhase",
    KenshiLib::GetRealAddress(&CampaignInstance::changePhase),
    CampaignInstance_changePhase_hook, CampaignInstance_changePhase_orig)

static void (*CampaignInstance_NV_victoryEvent_orig)(CampaignInstance*) = NULL;
static void CampaignInstance_NV_victoryEvent_hook(CampaignInstance* thisptr)
{
    CampaignInstance_NV_victoryEvent_orig(thisptr);
    CallCampaignVictoryCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_CampaignInstance_NV_victoryEvent,
    "CampaignInstance::_NV_victoryEvent",
    KenshiLib::GetRealAddress(&CampaignInstance::_NV_victoryEvent),
    CampaignInstance_NV_victoryEvent_hook, CampaignInstance_NV_victoryEvent_orig)

static void (*CampaignInstance_NV_lossEvent_orig)(CampaignInstance*) = NULL;
static void CampaignInstance_NV_lossEvent_hook(CampaignInstance* thisptr)
{
    CampaignInstance_NV_lossEvent_orig(thisptr);
    CallCampaignLossCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_CampaignInstance_NV_lossEvent,
    "CampaignInstance::_NV_lossEvent",
    KenshiLib::GetRealAddress(&CampaignInstance::_NV_lossEvent),
    CampaignInstance_NV_lossEvent_hook, CampaignInstance_NV_lossEvent_orig)

static void (*CampaignInstance_NV_addToCampaign_orig)(CampaignInstance*, Platoon*, bool) = NULL;
static void CampaignInstance_NV_addToCampaign_hook(CampaignInstance* thisptr, Platoon* who, bool forceLeader)
{
    CampaignInstance_NV_addToCampaign_orig(thisptr, who, forceLeader);
    CallCampaignAddPlatoonCallbacks(thisptr, who, forceLeader);
}
DEFINE_HOOK_INSTALLER(InstallHook_CampaignInstance_NV_addToCampaign,
    "CampaignInstance::_NV_addToCampaign",
    KenshiLib::GetRealAddress(&CampaignInstance::_NV_addToCampaign),
    CampaignInstance_NV_addToCampaign_hook, CampaignInstance_NV_addToCampaign_orig)

static void (*CampaignInstance_NV_removeFromCampaign_orig)(CampaignInstance*, Platoon*) = NULL;
static void CampaignInstance_NV_removeFromCampaign_hook(CampaignInstance* thisptr, Platoon* who)
{
    CampaignInstance_NV_removeFromCampaign_orig(thisptr, who);
    CallCampaignRemovePlatoonCallbacks(thisptr, who);
}
DEFINE_HOOK_INSTALLER(InstallHook_CampaignInstance_NV_removeFromCampaign,
    "CampaignInstance::_NV_removeFromCampaign",
    KenshiLib::GetRealAddress(&CampaignInstance::_NV_removeFromCampaign),
    CampaignInstance_NV_removeFromCampaign_hook, CampaignInstance_NV_removeFromCampaign_orig)
