#include "pch.h"
#include "Hooks_Common.h"

// ---------------------------------------------------------------------------
// Hooks for MedicalSystem.h
// ---------------------------------------------------------------------------

static void (*MedicalSystem_amputate_orig)(MedicalSystem*, RobotLimbs::Limb, bool, const Ogre::Vector3&) = NULL;
static void MedicalSystem_amputate_hook(MedicalSystem* thisptr, RobotLimbs::Limb limb, bool createSeveredItem, const Ogre::Vector3& force)
{
    MedicalSystem_amputate_orig(thisptr, limb, createSeveredItem, force);
    CallLimbAmputatedCallbacks(thisptr, static_cast<int>(limb), createSeveredItem, force);
}
DEFINE_HOOK_INSTALLER(InstallHook_MedicalSystem_Amputate,
    "MedicalSystem::amputate",
    KenshiLib::GetRealAddress(&MedicalSystem::amputate),
    MedicalSystem_amputate_hook, MedicalSystem_amputate_orig)

static void (*MedicalSystem_knockout_orig)(MedicalSystem*, float) = NULL;
static void MedicalSystem_knockout_hook(MedicalSystem* thisptr, float skill)
{
    MedicalSystem_knockout_orig(thisptr, skill);
    CallMedicalSystemKnockoutCallbacks(thisptr, skill);
}
DEFINE_HOOK_INSTALLER(InstallHook_MedicalSystem_knockout,
    "MedicalSystem::knockout",
    KenshiLib::GetRealAddress(&MedicalSystem::knockout),
    MedicalSystem_knockout_hook, MedicalSystem_knockout_orig)

static bool (*MedicalSystem_canGetUpWakeUp_orig)(MedicalSystem*) = NULL;
static bool MedicalSystem_canGetUpWakeUp_hook(MedicalSystem* thisptr)
{
    bool current = MedicalSystem_canGetUpWakeUp_orig(thisptr);
    return CallMedicalSystemCanGetUpWakeUpCallbacks(thisptr, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_MedicalSystem_canGetUpWakeUp,
    "MedicalSystem::canGetUpWakeUp",
    KenshiLib::GetRealAddress(&MedicalSystem::canGetUpWakeUp),
    MedicalSystem_canGetUpWakeUp_hook, MedicalSystem_canGetUpWakeUp_orig)

static MedicalSystem* (*MedicalSystem_CONSTRUCTOR_orig)(MedicalSystem*) = NULL;
static MedicalSystem* MedicalSystem_CONSTRUCTOR_hook(MedicalSystem* thisptr)
{
    MedicalSystem* res = MedicalSystem_CONSTRUCTOR_orig(thisptr);
    MedicalSystem* overrideRes = CallMedicalSystemConstructedCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_MedicalSystem_CONSTRUCTOR,
    "MedicalSystem::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&MedicalSystem::_CONSTRUCTOR),
    MedicalSystem_CONSTRUCTOR_hook, MedicalSystem_CONSTRUCTOR_orig)

static LimbsInventoryLayout* (*LimbsInventoryLayout_CONSTRUCTOR_orig)(LimbsInventoryLayout*, Character*) = NULL;
static LimbsInventoryLayout* LimbsInventoryLayout_CONSTRUCTOR_hook(LimbsInventoryLayout* thisptr, Character* character)
{
    LimbsInventoryLayout* res = LimbsInventoryLayout_CONSTRUCTOR_orig(thisptr, character);
    LimbsInventoryLayout* overrideRes = CallLimbsInventoryLayoutConstructedCallbacks(thisptr, character, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_LimbsInventoryLayout_CONSTRUCTOR,
    "LimbsInventoryLayout::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&LimbsInventoryLayout::_CONSTRUCTOR),
    LimbsInventoryLayout_CONSTRUCTOR_hook, LimbsInventoryLayout_CONSTRUCTOR_orig)

static RobotLimbs* (*RobotLimbs_CONSTRUCTOR_orig)(RobotLimbs*, Character*) = NULL;
static RobotLimbs* RobotLimbs_CONSTRUCTOR_hook(RobotLimbs* thisptr, Character* character)
{
    RobotLimbs* res = RobotLimbs_CONSTRUCTOR_orig(thisptr, character);
    RobotLimbs* overrideRes = CallRobotLimbsConstructedCallbacks(thisptr, character, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_RobotLimbs_CONSTRUCTOR,
    "RobotLimbs::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&RobotLimbs::_CONSTRUCTOR),
    RobotLimbs_CONSTRUCTOR_hook, RobotLimbs_CONSTRUCTOR_orig)

