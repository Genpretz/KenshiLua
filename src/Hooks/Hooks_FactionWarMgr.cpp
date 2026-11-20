#include "pch.h"
#include "Hooks_Common.h"

#include <kenshi/FactionWarMgr.h>

static FactionWarMgr* (*FactionWarMgr_CONSTRUCTOR_orig)(FactionWarMgr*, Faction*) = NULL;
static FactionWarMgr* FactionWarMgr_CONSTRUCTOR_hook(FactionWarMgr* thisptr, Faction* faction)
{
    FactionWarMgr* res = FactionWarMgr_CONSTRUCTOR_orig(thisptr, faction);
    FactionWarMgr* overrideRes = CallFactionWarMgrConstructedCallbacks(thisptr, faction, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionWarMgr_CONSTRUCTOR,
    "FactionWarMgr::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&FactionWarMgr::_CONSTRUCTOR),
    FactionWarMgr_CONSTRUCTOR_hook, FactionWarMgr_CONSTRUCTOR_orig)

static CampaignInstance* (*FactionWarMgr_triggerCampaign_orig)(FactionWarMgr*, RootObjectBase*, CampaignData*, TownBase*) = NULL;
static CampaignInstance* FactionWarMgr_triggerCampaign_hook(FactionWarMgr* thisptr, RootObjectBase* targetTown, CampaignData* data, TownBase* home)
{
    CampaignInstance* campaign = FactionWarMgr_triggerCampaign_orig(thisptr, targetTown, data, home);
    CallFactionWarMgrCampaignStartedCallbacks(thisptr, targetTown, data, home, campaign);
    return campaign;
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionWarMgr_triggerCampaign,
    "FactionWarMgr::triggerCampaign",
    KenshiLib::GetRealAddress(static_cast<CampaignInstance* (FactionWarMgr::*)(RootObjectBase*, CampaignData*, TownBase*)>(&FactionWarMgr::triggerCampaign)),
    FactionWarMgr_triggerCampaign_hook, FactionWarMgr_triggerCampaign_orig)

static void (*FactionWarMgr_endCampaign_orig)(FactionWarMgr*, CampaignInstance*) = NULL;
static void FactionWarMgr_endCampaign_hook(FactionWarMgr* thisptr, CampaignInstance* campaign)
{
    CallFactionWarMgrCampaignEndingCallbacks(thisptr, campaign);
    FactionWarMgr_endCampaign_orig(thisptr, campaign);
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionWarMgr_endCampaign,
    "FactionWarMgr::endCampaign",
    KenshiLib::GetRealAddress(&FactionWarMgr::endCampaign),
    FactionWarMgr_endCampaign_hook, FactionWarMgr_endCampaign_orig)
