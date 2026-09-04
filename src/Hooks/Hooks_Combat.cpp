#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/CombatTechniqueData.h>
#include <kenshi/CombatClass.h>

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
