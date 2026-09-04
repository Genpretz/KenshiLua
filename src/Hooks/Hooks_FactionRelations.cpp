#include "pch.h"
#include "Hooks_Common.h"

// ---------------------------------------------------------------------------
// Hooks for FactionRelations.h
// ---------------------------------------------------------------------------

static void (*FactionRelations_affectRelations_orig)(FactionRelations*, Faction*, FactionRelations::FactionEvent, float) = NULL;
static void FactionRelations_affectRelations_hook(FactionRelations* thisptr, Faction* other, FactionRelations::FactionEvent eventType, float multiplier)
{
    FactionRelations_affectRelations_orig(thisptr, other, eventType, multiplier);
    CallFactionRelationsAffectedCallbacks(thisptr, other, static_cast<int>(eventType), multiplier);
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionRelations_AffectRelations,
    "FactionRelations::affectRelations",
    KenshiLib::GetRealAddress(static_cast<void (FactionRelations::*)(Faction*, FactionRelations::FactionEvent, float)>(&FactionRelations::_NV_affectRelations)),
    FactionRelations_affectRelations_hook, FactionRelations_affectRelations_orig)

static FactionRelations* (*FactionRelations_CONSTRUCTOR_orig)(FactionRelations*) = NULL;
static FactionRelations* FactionRelations_CONSTRUCTOR_hook(FactionRelations* thisptr)
{
    FactionRelations* res = FactionRelations_CONSTRUCTOR_orig(thisptr);
    FactionRelations* overrideRes = CallFactionRelationsConstructedCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionRelations_CONSTRUCTOR,
    "FactionRelations::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&FactionRelations::_CONSTRUCTOR),
    FactionRelations_CONSTRUCTOR_hook, FactionRelations_CONSTRUCTOR_orig)

