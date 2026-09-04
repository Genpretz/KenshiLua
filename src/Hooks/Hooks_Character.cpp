#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/Character.h>
#include <kenshi/CharacterHuman.h>
#include <kenshi/CharacterAnimal.h>
#include <kenshi/CharBody.h>
#include <kenshi/Faction.h>

// ---------------------------------------------------------------------------
// Hooks for Character.h
// ---------------------------------------------------------------------------

static void (*Character_say_orig)(Character*, const std::string&) = NULL;
static void Character_say_hook(Character* thisptr, const std::string& message)
{
    Character_say_orig(thisptr, message);
    CallCharacterSayCallbacks(thisptr, message);
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_Say,
    "Character::_NV_say",
    KenshiLib::GetRealAddress(&Character::_NV_say),
    Character_say_hook, Character_say_orig)

static void (*Character_select_orig)(Character*) = NULL;
static void Character_select_hook(Character* thisptr)
{
    Character_select_orig(thisptr);
    CallCharacterSelectCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_Select,
    "Character::_NV_select",
    KenshiLib::GetRealAddress(&Character::_NV_select),
    Character_select_hook, Character_select_orig)

static void (*Character_unselect_orig)(Character* thisptr) = NULL;
static void Character_unselect_hook(Character* thisptr)
{
    Character_unselect_orig(thisptr);
    CallCharacterUnselectCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_Unselect,
    "Character::_NV_unselect",
    KenshiLib::GetRealAddress(&Character::_NV_unselect),
    Character_unselect_hook, Character_unselect_orig)

static void (*Character_declareDead_orig)(Character*) = NULL;
static void Character_declareDead_hook(Character* thisptr)
{
    Character_declareDead_orig(thisptr);
    CallCharacterDeclareDeadCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_DeclareDead,
    "Character::declareDead",
    KenshiLib::GetRealAddress(&Character::declareDead),
    Character_declareDead_hook, Character_declareDead_orig)

static void (*Character_pickupObject_orig)(Character* thisptr, Character* character) = NULL;
static void Character_pickupObject_hook(Character* thisptr, Character* character)
{
    Character_pickupObject_orig(thisptr, character);
    CallCharacterPickupObjectCallbacks(thisptr, character);
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_PickupObject,
    "Character::pickupObject",
    KenshiLib::GetRealAddress(&Character::pickupObject),
    Character_pickupObject_hook, Character_pickupObject_orig)

static void (*Character_getPickedUp_orig)(Character* thisptr, Character* byWhom) = NULL;
static void Character_getPickedUp_hook(Character* thisptr, Character* byWhom)
{
    Character_getPickedUp_orig(thisptr, byWhom);
    CallCharacterGetPickedUpCallbacks(thisptr, byWhom);
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_GetPickedUp,
    "Character::getPickedUp",
    KenshiLib::GetRealAddress(&Character::getPickedUp),
    Character_getPickedUp_hook, Character_getPickedUp_orig)

static bool (*Character_takeMoney_orig)(Character*, int) = NULL;
static bool Character_takeMoney_hook(Character* thisptr, int amount)
{
    bool res = Character_takeMoney_orig(thisptr, amount);
    CallCharacterTakeMoneyCallbacks(thisptr, amount);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_TakeMoney,
    "Character::_NV_takeMoney",
    KenshiLib::GetRealAddress(&Character::_NV_takeMoney),
    Character_takeMoney_hook, Character_takeMoney_orig)

static bool (*Character_eatItem_orig)(Character*, Item*, Inventory*) = NULL;
static bool Character_eatItem_hook(Character* thisptr, Item* food, Inventory* from)
{
    bool res = Character_eatItem_orig(thisptr, food, from);
    CallCharacterEatCallbacks(thisptr, food, from);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_EatItem,
    "Character::eatItem",
    KenshiLib::GetRealAddress(&Character::eatItem),
    Character_eatItem_hook, Character_eatItem_orig)

static HitMaterialType (*Character_hitByMeleeAttack_orig)(Character*, CutDirection, Damages&, Character*, CombatTechniqueData*, int) = NULL;
static HitMaterialType Character_hitByMeleeAttack_hook(Character* thisptr, CutDirection dir, Damages& damage, Character* who, CombatTechniqueData* attack, int comboID)
{
    HitMaterialType res = Character_hitByMeleeAttack_orig(thisptr, dir, damage, who, attack, comboID);
    CallCharacterHitByMeleeCallbacks(thisptr, static_cast<int>(dir), &damage, who, attack, comboID);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_HitByMeleeAttack,
    "Character::_NV_hitByMeleeAttack",
    KenshiLib::GetRealAddress(&Character::_NV_hitByMeleeAttack),
    Character_hitByMeleeAttack_hook, Character_hitByMeleeAttack_orig)

static bool (*Character_gettingEaten_orig)(Character*, float, Character*) = NULL;
static bool Character_gettingEaten_hook(Character* thisptr, float amount, Character* eater)
{
    bool res = Character_gettingEaten_orig(thisptr, amount, eater);
    CallCharacterGettingEatenCallbacks(thisptr, amount, eater);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_GettingEaten,
    "Character::_NV_gettingEaten",
    KenshiLib::GetRealAddress(&Character::_NV_gettingEaten),
    Character_gettingEaten_hook, Character_gettingEaten_orig)

static void (*Character_setStandingOrder_orig)(Character*, int, bool) = NULL;
static void Character_setStandingOrder_hook(Character* thisptr, int orderID, bool on)
{
    Character_setStandingOrder_orig(thisptr, orderID, on);
    CallCharacterStandingOrderChangedCallbacks(thisptr, orderID, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_SetStandingOrder,
    "Character::_NV_setStandingOrder",
    KenshiLib::GetRealAddress(&Character::_NV_setStandingOrder),
    Character_setStandingOrder_hook, Character_setStandingOrder_orig)

static void (*Character_setFaction_orig)(Character*, Faction*, ActivePlatoon*) = NULL;
static void Character_setFaction_hook(Character* thisptr, Faction* faction, ActivePlatoon* platoon)
{
    Character_setFaction_orig(thisptr, faction, platoon);
    CallCharacterFactionChangedCallbacks(thisptr, faction, platoon);
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_SetFaction,
    "Character::_NV_setFaction",
    KenshiLib::GetRealAddress(&Character::_NV_setFaction),
    Character_setFaction_hook, Character_setFaction_orig)

static void (*Character_equipItem_orig)(Character*, const std::string&, Item*) = NULL;
static void Character_equipItem_hook(Character* thisptr, const std::string& sectionName, Item* item)
{
    Character_equipItem_orig(thisptr, sectionName, item);
    CallCharacterEquipCallbacks(thisptr, sectionName, item);
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_EquipItem,
    "Character::_NV_equipItem",
    KenshiLib::GetRealAddress(&Character::_NV_equipItem),
    Character_equipItem_hook, Character_equipItem_orig)

static void (*Character_unequipItem_orig)(Character*, const std::string&, Item*) = NULL;
static void Character_unequipItem_hook(Character* thisptr, const std::string& sectionName, Item* item)
{
    Character_unequipItem_orig(thisptr, sectionName, item);
    CallCharacterUnequipCallbacks(thisptr, sectionName, item);
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_UnequipItem,
    "Character::_NV_unequipItem",
    KenshiLib::GetRealAddress(&Character::_NV_unequipItem),
    Character_unequipItem_hook, Character_unequipItem_orig)

static bool (*Character_ImStealingDoYouNotice_orig)(Character*, RootObject*, Item*) = NULL;
static bool Character_ImStealingDoYouNotice_hook(Character* thisptr, RootObject* stealFrom, Item* item)
{
    bool noticed = Character_ImStealingDoYouNotice_orig(thisptr, stealFrom, item);
    CallCharacterStealNoticeCallbacks(thisptr, stealFrom, item);
    return noticed;
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_ImStealingDoYouNotice,
    "Character::_NV_ImStealingDoYouNotice",
    KenshiLib::GetRealAddress(&Character::_NV_ImStealingDoYouNotice),
    Character_ImStealingDoYouNotice_hook, Character_ImStealingDoYouNotice_orig)

static YesNoMaybe (*Character_smugglingTradeCheck_orig)(Character*, Item*, Character*) = NULL;
static YesNoMaybe Character_smugglingTradeCheck_hook(Character* thisptr, Item* item, Character* who)
{
    YesNoMaybe res = Character_smugglingTradeCheck_orig(thisptr, item, who);
    CallCharacterSmugglingCheckCallbacks(thisptr, item, who);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_SmugglingTradeCheck,
    "Character::_NV_smugglingTradeCheck",
    KenshiLib::GetRealAddress(&Character::_NV_smugglingTradeCheck),
    Character_smugglingTradeCheck_hook, Character_smugglingTradeCheck_orig)

static void (*Character_NV_init_orig)(Character*) = NULL;
static void Character_NV_init_hook(Character* thisptr)
{
    Character_NV_init_orig(thisptr);
    CallCharacterInitCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_NV_init,
    "Character::_NV_init",
    KenshiLib::GetRealAddress(&Character::_NV_init),
    Character_NV_init_hook, Character_NV_init_orig)

static bool (*Character_isItOkForMeToLoot_orig)(Character*, RootObject*, Item*) = NULL;
static bool Character_isItOkForMeToLoot_hook(Character* thisptr, RootObject* victim, Item* item)
{
    bool current = Character_isItOkForMeToLoot_orig(thisptr, victim, item);
    return CallCharacterIsItOkForMeToLootCallbacks(thisptr, victim, item, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_isItOkForMeToLoot,
    "Character::isItOkForMeToLoot",
    KenshiLib::GetRealAddress(&Character::isItOkForMeToLoot),
    Character_isItOkForMeToLoot_hook, Character_isItOkForMeToLoot_orig)

static float (*Character_getFencingSuccessChance_orig)(Character*, Item*, RootObject*) = NULL;
static float Character_getFencingSuccessChance_hook(Character* thisptr, Item* item, RootObject* thief)
{
    float current = Character_getFencingSuccessChance_orig(thisptr, item, thief);
    return CallCharacterGetFencingSuccessChanceCallbacks(thisptr, item, thief, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_getFencingSuccessChance,
    "Character::getFencingSuccessChance",
    KenshiLib::GetRealAddress(&Character::getFencingSuccessChance),
    Character_getFencingSuccessChance_hook, Character_getFencingSuccessChance_orig)

static void (*Character_changeSlaveOwner_orig)(Character*, const hand&) = NULL;
static void Character_changeSlaveOwner_hook(Character* thisptr, const hand& newOwner)
{
    Character_changeSlaveOwner_orig(thisptr, newOwner);
    CallCharacterSlaveOwnerChangedCallbacks(thisptr, newOwner);
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_changeSlaveOwner,
    "Character::changeSlaveOwner",
    KenshiLib::GetRealAddress(&Character::changeSlaveOwner),
    Character_changeSlaveOwner_hook, Character_changeSlaveOwner_orig)

static void (*Character_setChainedMode_orig)(Character*, bool, const hand&) = NULL;
static void Character_setChainedMode_hook(Character* thisptr, bool on, const hand& owner)
{
    Character_setChainedMode_orig(thisptr, on, owner);
    CallCharacterChainedModeChangedCallbacks(thisptr, on, owner);
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_setChainedMode,
    "Character::setChainedMode",
    KenshiLib::GetRealAddress(&Character::setChainedMode),
    Character_setChainedMode_hook, Character_setChainedMode_orig)

static void (*Character_addGoal_orig)(Character*, TaskType, RootObjectBase*) = NULL;
static void Character_addGoal_hook(Character* thisptr, TaskType t, RootObjectBase* subject)
{
    Character_addGoal_orig(thisptr, t, subject);
    CallCharacterAddGoalCallbacks(thisptr, static_cast<int>(t), static_cast<RootObject*>(subject));
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_addGoal,
    "Character::addGoal",
    KenshiLib::GetRealAddress(&Character::addGoal),
    Character_addGoal_hook, Character_addGoal_orig)

static void (*Character_addJob_orig)(Character*, TaskType, RootObject*, bool, bool, const Ogre::Vector3&) = NULL;
static void Character_addJob_hook(Character* thisptr, TaskType t, RootObject* subject, bool shift, bool addDontClear, const Ogre::Vector3& location)
{
    Character_addJob_orig(thisptr, t, subject, shift, addDontClear, location);
    CallCharacterAddJobCallbacks(thisptr, static_cast<int>(t), subject, shift, addDontClear, location);
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_addJob,
    "Character::addJob",
    KenshiLib::GetRealAddress(&Character::addJob),
    Character_addJob_hook, Character_addJob_orig)

static void (*Character_addOrder_orig)(Character*, Building*, TaskType, RootObject*, bool, bool, const Ogre::Vector3&) = NULL;
static void Character_addOrder_hook(Character* thisptr, Building* dest, TaskType t, RootObject* subject, bool shift, bool clear, const Ogre::Vector3& location)
{
    Character_addOrder_orig(thisptr, dest, t, subject, shift, clear, location);
    CallCharacterAddOrderCallbacks(thisptr, dest, static_cast<int>(t), subject, shift, clear, location);
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_addOrder,
    "Character::addOrder",
    KenshiLib::GetRealAddress(&Character::addOrder),
    Character_addOrder_hook, Character_addOrder_orig)

static void (*Character_removeJob_orig)(Character*, TaskType) = NULL;
static void Character_removeJob_hook(Character* thisptr, TaskType t)
{
    Character_removeJob_orig(thisptr, t);
    CallCharacterRemoveJobCallbacks(thisptr, static_cast<int>(t));
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_removeJob,
    "Character::removeJob",
    KenshiLib::GetRealAddress(&Character::removeJob),
    Character_removeJob_hook, Character_removeJob_orig)

static GameSaveState (*Character_NV_serialise_orig)(Character*, GameDataContainer*, GameData*, PosRotPair*) = NULL;
static GameSaveState Character_NV_serialise_hook(Character* thisptr, GameDataContainer* container, GameData* refList, PosRotPair* offsetPosToSubtract)
{
    GameSaveState res = Character_NV_serialise_orig(thisptr, container, refList, offsetPosToSubtract);
    CallCharacterSerialiseCallbacks(thisptr, container, refList);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_NV_serialise,
    "Character::_NV_serialise",
    KenshiLib::GetRealAddress(&Character::_NV_serialise),
    Character_NV_serialise_hook, Character_NV_serialise_orig)

static void (*Character_NV_loadFromSerialise_orig)(Character*, GameSaveState*) = NULL;
static void Character_NV_loadFromSerialise_hook(Character* thisptr, GameSaveState* state)
{
    Character_NV_loadFromSerialise_orig(thisptr, state);
    CallCharacterLoadFromSerialiseCallbacks(thisptr, state);
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_NV_loadFromSerialise,
    "Character::_NV_loadFromSerialise",
    KenshiLib::GetRealAddress(&Character::_NV_loadFromSerialise),
    Character_NV_loadFromSerialise_hook, Character_NV_loadFromSerialise_orig)

static void (*Character_NV_loadFromSerialisePostCreationStage_orig)(Character*, GameSaveState*) = NULL;
static void Character_NV_loadFromSerialisePostCreationStage_hook(Character* thisptr, GameSaveState* gd)
{
    Character_NV_loadFromSerialisePostCreationStage_orig(thisptr, gd);
    CallCharacterLoadFromSerialisePostCreationStageCallbacks(thisptr, gd);
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_NV_loadFromSerialisePostCreationStage,
    "Character::_NV_loadFromSerialisePostCreationStage",
    KenshiLib::GetRealAddress(&Character::_NV_loadFromSerialisePostCreationStage),
    Character_NV_loadFromSerialisePostCreationStage_hook, Character_NV_loadFromSerialisePostCreationStage_orig)

static Character* (*Character_CONSTRUCTOR_orig)(Character*, GameData*, Faction*, const hand&) = NULL;
static Character* Character_CONSTRUCTOR_hook(Character* thisptr, GameData* dat, Faction* own, const hand& _handle)
{
    Character* res = Character_CONSTRUCTOR_orig(thisptr, dat, own, _handle);
    Character* overrideRes = CallCharacterConstructedCallbacks(thisptr, dat, own, _handle, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Character_CONSTRUCTOR,
    "Character::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&Character::_CONSTRUCTOR),
    Character_CONSTRUCTOR_hook, Character_CONSTRUCTOR_orig)

static CharacterHuman* (*CharacterHuman_CONSTRUCTOR_orig)(CharacterHuman*, GameData*, Faction*, hand) = NULL;
static CharacterHuman* CharacterHuman_CONSTRUCTOR_hook(CharacterHuman* thisptr, GameData* d, Faction* f, hand _handle)
{
    CharacterHuman* res = CharacterHuman_CONSTRUCTOR_orig(thisptr, d, f, _handle);
    CharacterHuman* overrideRes = CallCharacterHumanConstructedCallbacks(thisptr, d, f, _handle, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterHuman_CONSTRUCTOR,
    "CharacterHuman::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&CharacterHuman::_CONSTRUCTOR),
    CharacterHuman_CONSTRUCTOR_hook, CharacterHuman_CONSTRUCTOR_orig)

static CharacterAnimal* (*CharacterAnimal_CONSTRUCTOR_orig)(CharacterAnimal*, GameData*, Faction*, hand) = NULL;
static CharacterAnimal* CharacterAnimal_CONSTRUCTOR_hook(CharacterAnimal* thisptr, GameData* d, Faction* f, hand _handle)
{
    CharacterAnimal* res = CharacterAnimal_CONSTRUCTOR_orig(thisptr, d, f, _handle);
    CharacterAnimal* overrideRes = CallCharacterAnimalConstructedCallbacks(thisptr, d, f, _handle, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterAnimal_CONSTRUCTOR,
    "CharacterAnimal::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&CharacterAnimal::_CONSTRUCTOR),
    CharacterAnimal_CONSTRUCTOR_hook, CharacterAnimal_CONSTRUCTOR_orig)

static CharBody* (*CharBody_CONSTRUCTOR_orig)(CharBody*) = NULL;
static CharBody* CharBody_CONSTRUCTOR_hook(CharBody* thisptr)
{
    CharBody* res = CharBody_CONSTRUCTOR_orig(thisptr);
    CharBody* overrideRes = CallCharBodyConstructedCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_CharBody_CONSTRUCTOR,
    "CharBody::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&CharBody::_CONSTRUCTOR),
    CharBody_CONSTRUCTOR_hook, CharBody_CONSTRUCTOR_orig)


