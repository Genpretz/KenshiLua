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

static void (*FactionRelations_NV_setEnemy_orig)(FactionRelations*, Faction*) = NULL;
static void FactionRelations_NV_setEnemy_hook(FactionRelations* thisptr, Faction* faction)
{
    FactionRelations_NV_setEnemy_orig(thisptr, faction);
    CallFactionRelationsSetEnemyCallbacks(thisptr, faction);
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionRelations_NV_setEnemy,
    "FactionRelations::_NV_setEnemy",
    KenshiLib::GetRealAddress(&FactionRelations::_NV_setEnemy),
    FactionRelations_NV_setEnemy_hook, FactionRelations_NV_setEnemy_orig)

static void (*FactionRelations_setRelation_orig)(FactionRelations*, Faction*, float) = NULL;
static void FactionRelations_setRelation_hook(FactionRelations* thisptr, Faction* faction, float relation)
{
    FactionRelations_setRelation_orig(thisptr, faction, relation);
    CallFactionRelationsSetRelationCallbacks(thisptr, faction, relation);
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionRelations_setRelation,
    "FactionRelations::setRelation",
    KenshiLib::GetRealAddress(&FactionRelations::setRelation),
    FactionRelations_setRelation_hook, FactionRelations_setRelation_orig)

static void (*FactionRelations_NV_affectTrust_orig)(FactionRelations*, Faction*, float, float) = NULL;
static void FactionRelations_NV_affectTrust_hook(FactionRelations* thisptr, Faction* faction, float amount, float multiplier)
{
    FactionRelations_NV_affectTrust_orig(thisptr, faction, amount, multiplier);
    CallFactionRelationsAffectTrustCallbacks(thisptr, faction, amount, multiplier);
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionRelations_NV_affectTrust,
    "FactionRelations::_NV_affectTrust",
    KenshiLib::GetRealAddress(&FactionRelations::_NV_affectTrust),
    FactionRelations_NV_affectTrust_hook, FactionRelations_NV_affectTrust_orig)

static void (*FactionRelations_NV_setNoLongerEnemies_orig)(FactionRelations*, Faction*) = NULL;
static void FactionRelations_NV_setNoLongerEnemies_hook(FactionRelations* thisptr, Faction* faction)
{
    FactionRelations_NV_setNoLongerEnemies_orig(thisptr, faction);
    CallFactionRelationsSetNoLongerEnemiesCallbacks(thisptr, faction);
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionRelations_NV_setNoLongerEnemies,
    "FactionRelations::_NV_setNoLongerEnemies",
    KenshiLib::GetRealAddress(&FactionRelations::_NV_setNoLongerEnemies),
    FactionRelations_NV_setNoLongerEnemies_hook, FactionRelations_NV_setNoLongerEnemies_orig)

static void (*FactionRelations_NV_declareWar_orig)(FactionRelations*, Faction*) = NULL;
static void FactionRelations_NV_declareWar_hook(FactionRelations* thisptr, Faction* faction)
{
    FactionRelations_NV_declareWar_orig(thisptr, faction);
    CallFactionRelationsDeclareWarCallbacks(thisptr, faction);
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionRelations_NV_declareWar,
    "FactionRelations::_NV_declareWar",
    KenshiLib::GetRealAddress(&FactionRelations::_NV_declareWar),
    FactionRelations_NV_declareWar_hook, FactionRelations_NV_declareWar_orig)

static void (*FactionRelations_NV_affectReputation_orig)(FactionRelations*, Faction*, float) = NULL;
static void FactionRelations_NV_affectReputation_hook(FactionRelations* thisptr, Faction* faction, float amount)
{
    FactionRelations_NV_affectReputation_orig(thisptr, faction, amount);
    CallFactionRelationsAffectReputationCallbacks(thisptr, faction, amount);
}
DEFINE_HOOK_INSTALLER(InstallHook_FactionRelations_NV_affectReputation,
    "FactionRelations::_NV_affectReputation",
    KenshiLib::GetRealAddress(&FactionRelations::_NV_affectReputation),
    FactionRelations_NV_affectReputation_hook, FactionRelations_NV_affectReputation_orig)

