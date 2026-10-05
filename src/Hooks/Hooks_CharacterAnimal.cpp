#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/CharacterAnimal.h>

// ---------------------------------------------------------------------------
// Hooks for CharacterAnimal.h
// ---------------------------------------------------------------------------

static CharacterAnimal* (*CharacterAnimal_NV_isAnimal_orig)(CharacterAnimal*) = NULL;
static CharacterAnimal* CharacterAnimal_NV_isAnimal_hook(CharacterAnimal* thisptr)
{
    CharacterAnimal* res = CharacterAnimal_NV_isAnimal_orig(thisptr);
    CallCharacterAnimalIsAnimalCallbacks(thisptr, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_NV_isAnimal,
    "CharacterAnimal::_NV_isAnimal",
    KenshiLib::GetRealAddress(&CharacterAnimal::_NV_isAnimal),
    CharacterAnimal_NV_isAnimal_hook, CharacterAnimal_NV_isAnimal_orig)

static void (*CharacterAnimal_NV_createAnimationClass_orig)(CharacterAnimal*) = NULL;
static void CharacterAnimal_NV_createAnimationClass_hook(CharacterAnimal* thisptr)
{
    CharacterAnimal_NV_createAnimationClass_orig(thisptr);
    CallCharacterAnimalCreateAnimationClassCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_NV_createAnimationClass,
    "CharacterAnimal::_NV_createAnimationClass",
    KenshiLib::GetRealAddress(&CharacterAnimal::_NV_createAnimationClass),
    CharacterAnimal_NV_createAnimationClass_hook, CharacterAnimal_NV_createAnimationClass_orig)

static bool (*CharacterAnimal_NV_drawWeapon_orig)(CharacterAnimal*, Item*, std::string) = NULL;
static bool CharacterAnimal_NV_drawWeapon_hook(CharacterAnimal* thisptr, Item* _a1, std::string lastSlot)
{
    bool success = CharacterAnimal_NV_drawWeapon_orig(thisptr, _a1, lastSlot);
    CallCharacterAnimalDrawWeaponCallbacks(thisptr, _a1, lastSlot, success);
    return success;
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_NV_drawWeapon,
    "CharacterAnimal::_NV_drawWeapon",
    KenshiLib::GetRealAddress(&CharacterAnimal::_NV_drawWeapon),
    CharacterAnimal_NV_drawWeapon_hook, CharacterAnimal_NV_drawWeapon_orig)

static void (*CharacterAnimal_NV_sheatheWeapon_orig)(CharacterAnimal*) = NULL;
static void CharacterAnimal_NV_sheatheWeapon_hook(CharacterAnimal* thisptr)
{
    CharacterAnimal_NV_sheatheWeapon_orig(thisptr);
    CallCharacterAnimalSheatheWeaponCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_NV_sheatheWeapon,
    "CharacterAnimal::_NV_sheatheWeapon",
    KenshiLib::GetRealAddress(&CharacterAnimal::_NV_sheatheWeapon),
    CharacterAnimal_NV_sheatheWeapon_hook, CharacterAnimal_NV_sheatheWeapon_orig)

static Weapon* (*CharacterAnimal_NV_getCurrentWeapon_orig)(CharacterAnimal*) = NULL;
static Weapon* CharacterAnimal_NV_getCurrentWeapon_hook(CharacterAnimal* thisptr)
{
    Weapon* res = CharacterAnimal_NV_getCurrentWeapon_orig(thisptr);
    Weapon* overrideRes = CallCharacterAnimalGetCurrentWeaponCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_NV_getCurrentWeapon,
    "CharacterAnimal::_NV_getCurrentWeapon",
    KenshiLib::GetRealAddress(&CharacterAnimal::_NV_getCurrentWeapon),
    CharacterAnimal_NV_getCurrentWeapon_hook, CharacterAnimal_NV_getCurrentWeapon_orig)

static Weapon* (*CharacterAnimal_NV_getThePreferredWeapon_orig)(CharacterAnimal*) = NULL;
static Weapon* CharacterAnimal_NV_getThePreferredWeapon_hook(CharacterAnimal* thisptr)
{
    Weapon* res = CharacterAnimal_NV_getThePreferredWeapon_orig(thisptr);
    Weapon* overrideRes = CallCharacterAnimalGetThePreferredWeaponCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_NV_getThePreferredWeapon,
    "CharacterAnimal::_NV_getThePreferredWeapon",
    KenshiLib::GetRealAddress(&CharacterAnimal::_NV_getThePreferredWeapon),
    CharacterAnimal_NV_getThePreferredWeapon_hook, CharacterAnimal_NV_getThePreferredWeapon_orig)

static InventoryLayout* (*CharacterAnimal_NV_createInventoryLayout_orig)(CharacterAnimal*) = NULL;
static InventoryLayout* CharacterAnimal_NV_createInventoryLayout_hook(CharacterAnimal* thisptr)
{
    InventoryLayout* res = CharacterAnimal_NV_createInventoryLayout_orig(thisptr);
    CallCharacterAnimalCreateInventoryLayoutCallbacks(thisptr, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_NV_createInventoryLayout,
    "CharacterAnimal::_NV_createInventoryLayout",
    KenshiLib::GetRealAddress(&CharacterAnimal::_NV_createInventoryLayout),
    CharacterAnimal_NV_createInventoryLayout_hook, CharacterAnimal_NV_createInventoryLayout_orig)

static bool (*CharacterAnimal_NV_giveBirth_orig)(CharacterAnimal*, GameDataCopyStandalone*, const Ogre::Vector3&, const Ogre::Quaternion&, GameSaveState*, ActivePlatoon*, Faction*) = NULL;
static bool CharacterAnimal_NV_giveBirth_hook(CharacterAnimal* thisptr, GameDataCopyStandalone* appearance, const Ogre::Vector3& position, const Ogre::Quaternion& rotation, GameSaveState* state, ActivePlatoon* tempplatoonptr, Faction* _faction)
{
    bool success = CharacterAnimal_NV_giveBirth_orig(thisptr, appearance, position, rotation, state, tempplatoonptr, _faction);
    CallCharacterAnimalGiveBirthCallbacks(thisptr, appearance, position, rotation, state, tempplatoonptr, _faction, success);
    return success;
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_NV_giveBirth,
    "CharacterAnimal::_NV_giveBirth",
    KenshiLib::GetRealAddress(&CharacterAnimal::_NV_giveBirth),
    CharacterAnimal_NV_giveBirth_hook, CharacterAnimal_NV_giveBirth_orig)

static bool (*CharacterAnimal_NV_setupInventorySections_orig)(CharacterAnimal*, GameSaveState*) = NULL;
static bool CharacterAnimal_NV_setupInventorySections_hook(CharacterAnimal* thisptr, GameSaveState* state)
{
    bool success = CharacterAnimal_NV_setupInventorySections_orig(thisptr, state);
    CallCharacterAnimalSetupInventorySectionsCallbacks(thisptr, state, success);
    return success;
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_NV_setupInventorySections,
    "CharacterAnimal::_NV_setupInventorySections",
    KenshiLib::GetRealAddress(&CharacterAnimal::_NV_setupInventorySections),
    CharacterAnimal_NV_setupInventorySections_hook, CharacterAnimal_NV_setupInventorySections_orig)

static void (*CharacterAnimal_NV_setupAudio_orig)(CharacterAnimal*) = NULL;
static void CharacterAnimal_NV_setupAudio_hook(CharacterAnimal* thisptr)
{
    CharacterAnimal_NV_setupAudio_orig(thisptr);
    CallCharacterAnimalSetupAudioCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_NV_setupAudio,
    "CharacterAnimal::_NV_setupAudio",
    KenshiLib::GetRealAddress(&CharacterAnimal::_NV_setupAudio),
    CharacterAnimal_NV_setupAudio_hook, CharacterAnimal_NV_setupAudio_orig)

static void (*CharacterAnimal_NV_periodicUpdate_orig)(CharacterAnimal*) = NULL;
static void CharacterAnimal_NV_periodicUpdate_hook(CharacterAnimal* thisptr)
{
    CharacterAnimal_NV_periodicUpdate_orig(thisptr);
    CallCharacterAnimalPeriodicUpdateCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_NV_periodicUpdate,
    "CharacterAnimal::_NV_periodicUpdate",
    KenshiLib::GetRealAddress(&CharacterAnimal::_NV_periodicUpdate),
    CharacterAnimal_NV_periodicUpdate_hook, CharacterAnimal_NV_periodicUpdate_orig)

static void (*CharacterAnimal_NV_setAge_orig)(CharacterAnimal*, float) = NULL;
static void CharacterAnimal_NV_setAge_hook(CharacterAnimal* thisptr, float zeroToOne)
{
    CharacterAnimal_NV_setAge_orig(thisptr, zeroToOne);
    CallCharacterAnimalSetAgeCallbacks(thisptr, zeroToOne);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_NV_setAge,
    "CharacterAnimal::_NV_setAge",
    KenshiLib::GetRealAddress(&CharacterAnimal::_NV_setAge),
    CharacterAnimal_NV_setAge_hook, CharacterAnimal_NV_setAge_orig)

static float (*CharacterAnimal_NV_getAge_orig)(const CharacterAnimal*) = NULL;
static float CharacterAnimal_NV_getAge_hook(const CharacterAnimal* thisptr)
{
    float current = CharacterAnimal_NV_getAge_orig(thisptr);
    return CallCharacterAnimalGetAgeCallbacks(thisptr, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_NV_getAge,
    "CharacterAnimal::_NV_getAge",
    KenshiLib::GetRealAddress(&CharacterAnimal::_NV_getAge),
    CharacterAnimal_NV_getAge_hook, CharacterAnimal_NV_getAge_orig)

static float (*CharacterAnimal_NV_getAgeInverse_orig)(const CharacterAnimal*) = NULL;
static float CharacterAnimal_NV_getAgeInverse_hook(const CharacterAnimal* thisptr)
{
    float current = CharacterAnimal_NV_getAgeInverse_orig(thisptr);
    return CallCharacterAnimalGetAgeInverseCallbacks(thisptr, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_NV_getAgeInverse,
    "CharacterAnimal::_NV_getAgeInverse",
    KenshiLib::GetRealAddress(&CharacterAnimal::_NV_getAgeInverse),
    CharacterAnimal_NV_getAgeInverse_hook, CharacterAnimal_NV_getAgeInverse_orig)

static float (*CharacterAnimal_NV_getAge0to1_orig)(const CharacterAnimal*) = NULL;
static float CharacterAnimal_NV_getAge0to1_hook(const CharacterAnimal* thisptr)
{
    float current = CharacterAnimal_NV_getAge0to1_orig(thisptr);
    return CallCharacterAnimalGetAge0to1Callbacks(thisptr, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_NV_getAge0to1,
    "CharacterAnimal::_NV_getAge0to1",
    KenshiLib::GetRealAddress(&CharacterAnimal::_NV_getAge0to1),
    CharacterAnimal_NV_getAge0to1_hook, CharacterAnimal_NV_getAge0to1_orig)

static unsigned int (*CharacterAnimal_NV_getDefaultTaskRepertoireEnum_orig)(const CharacterAnimal*) = NULL;
static unsigned int CharacterAnimal_NV_getDefaultTaskRepertoireEnum_hook(const CharacterAnimal* thisptr)
{
    unsigned int current = CharacterAnimal_NV_getDefaultTaskRepertoireEnum_orig(thisptr);
    return CallCharacterAnimalGetDefaultTaskRepertoireEnumCallbacks(thisptr, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_NV_getDefaultTaskRepertoireEnum,
    "CharacterAnimal::_NV_getDefaultTaskRepertoireEnum",
    KenshiLib::GetRealAddress(&CharacterAnimal::_NV_getDefaultTaskRepertoireEnum),
    CharacterAnimal_NV_getDefaultTaskRepertoireEnum_hook, CharacterAnimal_NV_getDefaultTaskRepertoireEnum_orig)

static bool (*CharacterAnimal_NV_canGoIndoors_orig)(const CharacterAnimal*, Building*) = NULL;
static bool CharacterAnimal_NV_canGoIndoors_hook(const CharacterAnimal* thisptr, Building* b)
{
    bool current = CharacterAnimal_NV_canGoIndoors_orig(thisptr, b);
    return CallCharacterAnimalCanGoIndoorsCallbacks(thisptr, b, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_NV_canGoIndoors,
    "CharacterAnimal::_NV_canGoIndoors",
    KenshiLib::GetRealAddress(&CharacterAnimal::_NV_canGoIndoors),
    CharacterAnimal_NV_canGoIndoors_hook, CharacterAnimal_NV_canGoIndoors_orig)

static float (*CharacterAnimal_NV_getSmellHuntingThresholdBlood_orig)(const CharacterAnimal*) = NULL;
static float CharacterAnimal_NV_getSmellHuntingThresholdBlood_hook(const CharacterAnimal* thisptr)
{
    float current = CharacterAnimal_NV_getSmellHuntingThresholdBlood_orig(thisptr);
    return CallCharacterAnimalGetSmellHuntingThresholdBloodCallbacks(thisptr, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_NV_getSmellHuntingThresholdBlood,
    "CharacterAnimal::_NV_getSmellHuntingThresholdBlood",
    KenshiLib::GetRealAddress(&CharacterAnimal::_NV_getSmellHuntingThresholdBlood),
    CharacterAnimal_NV_getSmellHuntingThresholdBlood_hook, CharacterAnimal_NV_getSmellHuntingThresholdBlood_orig)

static float (*CharacterAnimal_NV_getSmellHuntingThresholdEggs_orig)(const CharacterAnimal*) = NULL;
static float CharacterAnimal_NV_getSmellHuntingThresholdEggs_hook(const CharacterAnimal* thisptr)
{
    float current = CharacterAnimal_NV_getSmellHuntingThresholdEggs_orig(thisptr);
    return CallCharacterAnimalGetSmellHuntingThresholdEggsCallbacks(thisptr, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_NV_getSmellHuntingThresholdEggs,
    "CharacterAnimal::_NV_getSmellHuntingThresholdEggs",
    KenshiLib::GetRealAddress(&CharacterAnimal::_NV_getSmellHuntingThresholdEggs),
    CharacterAnimal_NV_getSmellHuntingThresholdEggs_hook, CharacterAnimal_NV_getSmellHuntingThresholdEggs_orig)

static float (*CharacterAnimal_NV_getHPMultiplier_orig)(const CharacterAnimal*) = NULL;
static float CharacterAnimal_NV_getHPMultiplier_hook(const CharacterAnimal* thisptr)
{
    float current = CharacterAnimal_NV_getHPMultiplier_orig(thisptr);
    return CallCharacterAnimalGetHPMultiplierCallbacks(thisptr, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_NV_getHPMultiplier,
    "CharacterAnimal::_NV_getHPMultiplier",
    KenshiLib::GetRealAddress(&CharacterAnimal::_NV_getHPMultiplier),
    CharacterAnimal_NV_getHPMultiplier_hook, CharacterAnimal_NV_getHPMultiplier_orig)

static void (*CharacterAnimal_NV_foodUpdate_orig)(CharacterAnimal*) = NULL;
static void CharacterAnimal_NV_foodUpdate_hook(CharacterAnimal* thisptr)
{
    CharacterAnimal_NV_foodUpdate_orig(thisptr);
    CallCharacterAnimalFoodUpdateCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_NV_foodUpdate,
    "CharacterAnimal::_NV_foodUpdate",
    KenshiLib::GetRealAddress(&CharacterAnimal::_NV_foodUpdate),
    CharacterAnimal_NV_foodUpdate_hook, CharacterAnimal_NV_foodUpdate_orig)

static void (*CharacterAnimal_NV_init_orig)(CharacterAnimal*) = NULL;
static void CharacterAnimal_NV_init_hook(CharacterAnimal* thisptr)
{
    CharacterAnimal_NV_init_orig(thisptr);
    CallCharacterAnimalInitCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_NV_init,
    "CharacterAnimal::_NV_init",
    KenshiLib::GetRealAddress(&CharacterAnimal::_NV_init),
    CharacterAnimal_NV_init_hook, CharacterAnimal_NV_init_orig)

static void (*CharacterAnimal_NV_dropItem_orig)(CharacterAnimal*, RootObject*) = NULL;
static void CharacterAnimal_NV_dropItem_hook(CharacterAnimal* thisptr, RootObject* itembase)
{
    CharacterAnimal_NV_dropItem_orig(thisptr, itembase);
    CallCharacterAnimalDropItemCallbacks(thisptr, itembase);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_NV_dropItem,
    "CharacterAnimal::_NV_dropItem",
    KenshiLib::GetRealAddress(&CharacterAnimal::_NV_dropItem),
    CharacterAnimal_NV_dropItem_hook, CharacterAnimal_NV_dropItem_orig)
