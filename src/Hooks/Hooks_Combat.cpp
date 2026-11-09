#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/combat/CombatTechniqueData.h>
#include <kenshi/combat/CombatClass.h>

// ---------------------------------------------------------------------------
// Hooks for CombatTechniqueData.h
// ---------------------------------------------------------------------------

static CombatTechniqueData* (*CombatTechniqueData_CONSTRUCTOR_orig)(CombatTechniqueData*, GameData*) = NULL;
static CombatTechniqueData* CombatTechniqueData_CONSTRUCTOR_hook(CombatTechniqueData* thisptr, GameData* data)
{
    CombatTechniqueData* res = CombatTechniqueData_CONSTRUCTOR_orig(thisptr, data);
    CombatTechniqueData* overrideRes = CallCombatTechniqueDataConstructedCallbacks(thisptr, data, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_CombatTechniqueData_CONSTRUCTOR,
    "CombatTechniqueData::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&CombatTechniqueData::_CONSTRUCTOR),
    CombatTechniqueData_CONSTRUCTOR_hook, CombatTechniqueData_CONSTRUCTOR_orig)

// ---------------------------------------------------------------------------
// Hooks for CombatClass.h
// ---------------------------------------------------------------------------

static CombatClass* (*CombatClass_CONSTRUCTOR_orig)(CombatClass*, CharMovement*, AI*, AnimationClass*, Character*, CharStats*, MedicalSystem*) = NULL;
static CombatClass* CombatClass_CONSTRUCTOR_hook(CombatClass* thisptr, CharMovement* m, AI* a, AnimationClass* an, Character* character, CharStats* st, MedicalSystem* _med)
{
    CombatClass* res = CombatClass_CONSTRUCTOR_orig(thisptr, m, a, an, character, st, _med);
    CombatClass* overrideRes = CallCombatClassConstructedCallbacks(thisptr, m, a, an, character, st, _med, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_CombatClass_CONSTRUCTOR,
    "CombatClass::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&CombatClass::_CONSTRUCTOR),
    CombatClass_CONSTRUCTOR_hook, CombatClass_CONSTRUCTOR_orig)

static bool (*CombatClass_NV_initCombatMode_orig)(CombatClass*, const hand&, int, bool) = NULL;
static bool CombatClass_NV_initCombatMode_hook(CombatClass* thisptr, const hand& subject, int endValue, bool focusedTarget)
{
    // CombatClassAI::initCombatMode calls this base body and discards its result,
    // so a Lua return value could not reach the engine. Notification only.
    bool result = CombatClass_NV_initCombatMode_orig(thisptr, subject, endValue, focusedTarget);
    CallCombatClassInitCombatModeCallbacks(thisptr, subject, endValue, focusedTarget, result);
    return result;
}
DEFINE_HOOK_INSTALLER(InstallHook_CombatClass_NV_initCombatMode,
    "CombatClass::_NV_initCombatMode",
    KenshiLib::GetRealAddress(&CombatClass::_NV_initCombatMode),
    CombatClass_NV_initCombatMode_hook, CombatClass_NV_initCombatMode_orig)

static void (*CombatClass_getHit_orig)(CombatClass*, CutDirection, const Damages&, RootObject*, bool) = NULL;
static void CombatClass_getHit_hook(CombatClass* thisptr, CutDirection direction, const Damages& damage, RootObject* attacker, bool stumble)
{
    CombatClass_getHit_orig(thisptr, direction, damage, attacker, stumble);
    CallCombatClassGetHitCallbacks(thisptr, static_cast<int>(direction), const_cast<Damages*>(&damage), attacker, stumble);
}
DEFINE_HOOK_INSTALLER(InstallHook_CombatClass_getHit,
    "CombatClass::_getHit",
    KenshiLib::GetRealAddress(&CombatClass::_getHit),
    CombatClass_getHit_hook, CombatClass_getHit_orig)

static void (*CombatClass_blockHit_orig)(CombatClass*, CutDirection, const Damages&, RootObject*) = NULL;
static void CombatClass_blockHit_hook(CombatClass* thisptr, CutDirection direction, const Damages& damage, RootObject* attacker)
{
    CombatClass_blockHit_orig(thisptr, direction, damage, attacker);
    CallCombatClassBlockHitCallbacks(thisptr, static_cast<int>(direction), const_cast<Damages*>(&damage), attacker);
}
DEFINE_HOOK_INSTALLER(InstallHook_CombatClass_blockHit,
    "CombatClass::_blockHit",
    KenshiLib::GetRealAddress(&CombatClass::_blockHit),
    CombatClass_blockHit_hook, CombatClass_blockHit_orig)

static bool (*CombatClass_addAttackerH_orig)(CombatClass*, Character*) = NULL;
static bool CombatClass_addAttackerH_hook(CombatClass* thisptr, Character* attacker)
{
    bool added = CombatClass_addAttackerH_orig(thisptr, attacker);
    CallCombatClassAddAttackerCallbacks(thisptr, attacker, added);
    return added;
}
DEFINE_HOOK_INSTALLER(InstallHook_CombatClass_addAttackerH,
    "CombatClass::addAttackerH",
    KenshiLib::GetRealAddress(&CombatClass::addAttackerH),
    CombatClass_addAttackerH_hook, CombatClass_addAttackerH_orig)

static bool (*CombatClass_removeAttackerH_orig)(CombatClass*, Character*) = NULL;
static bool CombatClass_removeAttackerH_hook(CombatClass* thisptr, Character* attacker)
{
    bool removed = CombatClass_removeAttackerH_orig(thisptr, attacker);
    CallCombatClassRemoveAttackerCallbacks(thisptr, attacker, removed);
    return removed;
}
DEFINE_HOOK_INSTALLER(InstallHook_CombatClass_removeAttackerH,
    "CombatClass::removeAttackerH",
    KenshiLib::GetRealAddress(&CombatClass::removeAttackerH),
    CombatClass_removeAttackerH_hook, CombatClass_removeAttackerH_orig)
