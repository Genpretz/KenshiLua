#include "pch.h"
#include "Hooks_Common.h"

// ---------------------------------------------------------------------------
// Hooks for PlayerInterface.h
// ---------------------------------------------------------------------------

static bool (*PlayerInterface_recruit_orig)(PlayerInterface*, Character*, bool) = NULL;
static bool PlayerInterface_recruit_hook(PlayerInterface* thisptr, Character* character, bool editor)
{
    bool res = PlayerInterface_recruit_orig(thisptr, character, editor);
    CallPlayerRecruitCallbacks(thisptr, character, editor);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_PlayerInterface_Recruit,
    "PlayerInterface::recruit",
    KenshiLib::GetRealAddress(static_cast<bool (PlayerInterface::*)(Character*, bool)>(&PlayerInterface::recruit)),
    PlayerInterface_recruit_hook, PlayerInterface_recruit_orig)

static void (*PlayerInterface_selectObject_orig)(PlayerInterface*, RootObject*, bool) = NULL;
static void PlayerInterface_selectObject_hook(PlayerInterface* thisptr, RootObject* obj, bool modifier)
{
    PlayerInterface_selectObject_orig(thisptr, obj, modifier);
    CallPlayerSelectCallbacks(thisptr, obj, modifier);
}
DEFINE_HOOK_INSTALLER(InstallHook_PlayerInterface_SelectObject,
    "PlayerInterface::selectObject",
    KenshiLib::GetRealAddress(&PlayerInterface::selectObject),
    PlayerInterface_selectObject_hook, PlayerInterface_selectObject_orig)

static void (*PlayerInterface_newPlayerTaskSelectedCharacters_orig)(PlayerInterface*, TaskType, const hand&, Building*, const Ogre::Vector3&, bool) = NULL;
static void PlayerInterface_newPlayerTaskSelectedCharacters_hook(PlayerInterface* thisptr, TaskType t, const hand& targetH, Building* destinationIndoors, const Ogre::Vector3& clickpos, bool addDontClear)
{
    PlayerInterface_newPlayerTaskSelectedCharacters_orig(thisptr, t, targetH, destinationIndoors, clickpos, addDontClear);
    CallPlayerOrderGivenCallbacks(thisptr, static_cast<int>(t), targetH, destinationIndoors, clickpos, addDontClear);
}
DEFINE_HOOK_INSTALLER(InstallHook_PlayerInterface_NewPlayerTaskSelectedCharacters,
    "PlayerInterface::newPlayerTaskSelectedCharacters",
    KenshiLib::GetRealAddress(&PlayerInterface::newPlayerTaskSelectedCharacters),
    PlayerInterface_newPlayerTaskSelectedCharacters_hook, PlayerInterface_newPlayerTaskSelectedCharacters_orig)

static void (*PlayerInterface_addJobSelectedCharacters_orig)(PlayerInterface*, TaskType, RootObject*, bool, bool, const Ogre::Vector3&) = NULL;
static void PlayerInterface_addJobSelectedCharacters_hook(PlayerInterface* thisptr, TaskType task, RootObject* subject, bool shift, bool add, const Ogre::Vector3& location)
{
    PlayerInterface_addJobSelectedCharacters_orig(thisptr, task, subject, shift, add, location);
    CallPlayerInterfaceAddJobSelectedCharactersCallbacks(thisptr, static_cast<int>(task), subject, shift, add, location);
}
DEFINE_HOOK_INSTALLER(InstallHook_PlayerInterface_addJobSelectedCharacters,
    "PlayerInterface::addJobSelectedCharacters",
    KenshiLib::GetRealAddress(&PlayerInterface::addJobSelectedCharacters),
    PlayerInterface_addJobSelectedCharacters_hook, PlayerInterface_addJobSelectedCharacters_orig)

static void (*PlayerInterface_addOrderSelectedCharacters_orig)(PlayerInterface*, Building*, TaskType, RootObject*, bool, bool, const Ogre::Vector3&) = NULL;
static void PlayerInterface_addOrderSelectedCharacters_hook(PlayerInterface* thisptr, Building* destinationIndoors, TaskType task, RootObject* subject, bool shift, bool addDontClear, const Ogre::Vector3& location)
{
    PlayerInterface_addOrderSelectedCharacters_orig(thisptr, destinationIndoors, task, subject, shift, addDontClear, location);
    CallPlayerInterfaceAddOrderSelectedCharactersCallbacks(thisptr, destinationIndoors, static_cast<int>(task), subject, shift, addDontClear, location);
}
DEFINE_HOOK_INSTALLER(InstallHook_PlayerInterface_addOrderSelectedCharacters,
    "PlayerInterface::addOrderSelectedCharacters",
    KenshiLib::GetRealAddress(&PlayerInterface::addOrderSelectedCharacters),
    PlayerInterface_addOrderSelectedCharacters_hook, PlayerInterface_addOrderSelectedCharacters_orig)

static void (*PlayerInterface_activateCharacterEditMode_orig)(PlayerInterface*, Character*) = NULL;
static void PlayerInterface_activateCharacterEditMode_hook(PlayerInterface* thisptr, Character* character)
{
    PlayerInterface_activateCharacterEditMode_orig(thisptr, character);
    CallPlayerActivateCharacterEditModeCallbacks(thisptr, character);
}
DEFINE_HOOK_INSTALLER(InstallHook_PlayerInterface_activateCharacterEditMode,
    "PlayerInterface::activateCharacterEditMode",
    KenshiLib::GetRealAddress(&PlayerInterface::activateCharacterEditMode),
    PlayerInterface_activateCharacterEditMode_hook, PlayerInterface_activateCharacterEditMode_orig)

static ActivePlatoon* (*PlayerInterface_createSquad_orig)(PlayerInterface*) = NULL;
static ActivePlatoon* PlayerInterface_createSquad_hook(PlayerInterface* thisptr)
{
    ActivePlatoon* newSquad = PlayerInterface_createSquad_orig(thisptr);
    CallPlayerCreateSquadCallbacks(thisptr, newSquad);
    return newSquad;
}
DEFINE_HOOK_INSTALLER(InstallHook_PlayerInterface_createSquad,
    "PlayerInterface::createSquad",
    KenshiLib::GetRealAddress(&PlayerInterface::createSquad),
    PlayerInterface_createSquad_hook, PlayerInterface_createSquad_orig)

static void (*PlayerInterface_encounterFaction_orig)(PlayerInterface*, Faction*) = NULL;
static void PlayerInterface_encounterFaction_hook(PlayerInterface* thisptr, Faction* faction)
{
    PlayerInterface_encounterFaction_orig(thisptr, faction);
    CallPlayerEncounterFactionCallbacks(thisptr, faction);
}
DEFINE_HOOK_INSTALLER(InstallHook_PlayerInterface_encounterFaction,
    "PlayerInterface::encounterFaction",
    KenshiLib::GetRealAddress(&PlayerInterface::encounterFaction),
    PlayerInterface_encounterFaction_hook, PlayerInterface_encounterFaction_orig)

static void (*PlayerInterface_serialise_orig)(PlayerInterface*, GameData*) = NULL;
static void PlayerInterface_serialise_hook(PlayerInterface* thisptr, GameData* data)
{
    PlayerInterface_serialise_orig(thisptr, data);
    CallPlayerInterfaceSerialiseCallbacks(thisptr, data);
}
DEFINE_HOOK_INSTALLER(InstallHook_PlayerInterface_serialise,
    "PlayerInterface::serialise",
    KenshiLib::GetRealAddress(&PlayerInterface::serialise),
    PlayerInterface_serialise_hook, PlayerInterface_serialise_orig)

static void (*PlayerInterface_loadFromSerialise_orig)(PlayerInterface*, GameData*) = NULL;
static void PlayerInterface_loadFromSerialise_hook(PlayerInterface* thisptr, GameData* data)
{
    PlayerInterface_loadFromSerialise_orig(thisptr, data);
    CallPlayerInterfaceLoadFromSerialiseCallbacks(thisptr, data);
}
DEFINE_HOOK_INSTALLER(InstallHook_PlayerInterface_loadFromSerialise,
    "PlayerInterface::loadFromSerialise",
    KenshiLib::GetRealAddress(&PlayerInterface::loadFromSerialise),
    PlayerInterface_loadFromSerialise_hook, PlayerInterface_loadFromSerialise_orig)
