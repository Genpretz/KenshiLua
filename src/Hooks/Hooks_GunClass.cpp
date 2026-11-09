#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/GunClass.h>

static void (*GunClass_shoot_orig)(GunClass*, Character*, RootObject*, StatsEnumerated, const Ogre::Vector3&) = NULL;
static void GunClass_shoot_hook(GunClass* thisptr, Character* shooter, RootObject* target, StatsEnumerated stat, const Ogre::Vector3& aimPosition)
{
    GunClass_shoot_orig(thisptr, shooter, target, stat, aimPosition);
    CallGunClassShootCallbacks(thisptr, shooter, target, static_cast<int>(stat), aimPosition);
}
DEFINE_HOOK_INSTALLER(InstallHook_GunClass_shoot,
    "GunClass::shoot",
    KenshiLib::GetRealAddress(&GunClass::shoot),
    GunClass_shoot_hook, GunClass_shoot_orig)
