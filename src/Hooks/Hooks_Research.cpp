#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/Research.h>

// ---------------------------------------------------------------------------
// Hooks for Research.h
// ---------------------------------------------------------------------------

static bool (*Research_startResearch_orig)(Research*, GameData*) = NULL;
static bool Research_startResearch_hook(Research* thisptr, GameData* d)
{
    bool started = Research_startResearch_orig(thisptr, d);
    CallResearchStartCallbacks(thisptr, d, started);
    return started;
}
DEFINE_HOOK_INSTALLER(InstallHook_Research_startResearch,
    "Research::startResearch",
    KenshiLib::GetRealAddress(&Research::startResearch),
    Research_startResearch_hook, Research_startResearch_orig)

static void (*Research_stopResearch_orig)(Research*, GameData*) = NULL;
static void Research_stopResearch_hook(Research* thisptr, GameData* d)
{
    Research_stopResearch_orig(thisptr, d);
    CallResearchStopCallbacks(thisptr, d);
}
DEFINE_HOOK_INSTALLER(InstallHook_Research_stopResearch,
    "Research::stopResearch",
    KenshiLib::GetRealAddress(&Research::stopResearch),
    Research_stopResearch_hook, Research_stopResearch_orig)

static void (*Research_completeResearch_orig)(Research*, GameData*) = NULL;
static void Research_completeResearch_hook(Research* thisptr, GameData* d)
{
    Research_completeResearch_orig(thisptr, d);
    CallResearchCompleteCallbacks(thisptr, d);
}
DEFINE_HOOK_INSTALLER(InstallHook_Research_completeResearch,
    "Research::completeResearch",
    KenshiLib::GetRealAddress(&Research::completeResearch),
    Research_completeResearch_hook, Research_completeResearch_orig)

static void (*Research_progressResearch_orig)(Research*, float) = NULL;
static void Research_progressResearch_hook(Research* thisptr, float amount)
{
    Research_progressResearch_orig(thisptr, amount);
    CallResearchProgressCallbacks(thisptr, amount);
}
DEFINE_HOOK_INSTALLER(InstallHook_Research_progressResearch,
    "Research::progressResearch",
    KenshiLib::GetRealAddress(&Research::progressResearch),
    Research_progressResearch_hook, Research_progressResearch_orig)
