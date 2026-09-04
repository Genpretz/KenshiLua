#include "pch.h"
#include "Hooks_Common.h"

// ---------------------------------------------------------------------------
// Hooks for gui/DialogueWindow.h
// ---------------------------------------------------------------------------

static void (*DialogueWindow_show_orig)(DialogueWindow*, Dialogue*) = NULL;
static void DialogueWindow_show_hook(DialogueWindow* thisptr, Dialogue* dialogue)
{
    DialogueWindow_show_orig(thisptr, dialogue);
    CallDialogueWindowShowCallbacks(thisptr, dialogue);
}
DEFINE_HOOK_INSTALLER(InstallHook_DialogueWindow_Show,
    "DialogueWindow::show",
    KenshiLib::GetRealAddress(static_cast<void (DialogueWindow::*)(Dialogue*)>(&DialogueWindow::show)),
    DialogueWindow_show_hook, DialogueWindow_show_orig)

// ---------------------------------------------------------------------------
// Hooks for Dialogue.h
// ---------------------------------------------------------------------------

static void (*Dialogue_doActions_orig)(Dialogue*, DialogLineData*) = NULL;
static void Dialogue_doActions_hook(Dialogue* thisptr, DialogLineData* dialogLine)
{
    Dialogue_doActions_orig(thisptr, dialogLine);

    if (thisptr && dialogLine)
    {
        KenshiLua::DialogueScriptBridge(thisptr, dialogLine);
    }

    CallDialogueDoActionsCallbacks(thisptr, dialogLine);
}
DEFINE_HOOK_INSTALLER(InstallHook_Dialogue_DoActions,
    "Dialogue::_doActions",
    KenshiLib::GetRealAddress(&Dialogue::_doActions),
    Dialogue_doActions_hook, Dialogue_doActions_orig)

static void (*Dialogue_say_orig)(Dialogue*, DialogLineData*) = NULL;
static void Dialogue_say_hook(Dialogue* thisptr, DialogLineData* dialogLine)
{
    Dialogue_say_orig(thisptr, dialogLine);
    CallDialogueSayCallbacks(thisptr, dialogLine);
}
DEFINE_HOOK_INSTALLER(InstallHook_Dialogue_Say,
    "Dialogue::say",
    KenshiLib::GetRealAddress(static_cast<void (Dialogue::*)(DialogLineData*)>(&Dialogue::say)),
    Dialogue_say_hook, Dialogue_say_orig)

static void (*Dialogue_endDialogue_orig)(Dialogue*, bool) = NULL;
static void Dialogue_endDialogue_hook(Dialogue* thisptr, bool definitelyTheEnd)
{
    Dialogue_endDialogue_orig(thisptr, definitelyTheEnd);
    CallDialogueEndDialogueCallbacks(thisptr, definitelyTheEnd);
}
DEFINE_HOOK_INSTALLER(InstallHook_Dialogue_endDialogue,
    "Dialogue::endDialogue",
    KenshiLib::GetRealAddress(&Dialogue::endDialogue),
    Dialogue_endDialogue_hook, Dialogue_endDialogue_orig)

static bool (*Dialogue__checkCondition_orig)(Dialogue*, DialogConditionEnum, ComparisonEnum, int, Character*, Character*) = NULL;
static bool Dialogue__checkCondition_hook(Dialogue* thisptr, DialogConditionEnum conditionName, ComparisonEnum compareBy, int val, Character* target, Character* actualConversationTarget)
{
    bool current = Dialogue__checkCondition_orig(thisptr, conditionName, compareBy, val, target, actualConversationTarget);
    return CallDialogueCheckConditionCallbacks(thisptr, conditionName, compareBy, val, target, actualConversationTarget, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_Dialogue__checkCondition,
    "Dialogue::_checkCondition",
    KenshiLib::GetRealAddress(&Dialogue::_checkCondition),
    Dialogue__checkCondition_hook, Dialogue__checkCondition_orig)

static bool (*Dialogue_startConversation_orig)(Dialogue*, Character*, DialogLineData*, EventTriggerEnum, bool) = NULL;
static bool Dialogue_startConversation_hook(Dialogue* thisptr, Character* target, DialogLineData* _talk, EventTriggerEnum ev, bool force)
{
    bool current = Dialogue_startConversation_orig(thisptr, target, _talk, ev, force);
    return CallDialogueStartConversationCallbacks(thisptr, target, _talk, ev, force, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_Dialogue_startConversation,
    "Dialogue::startConversation",
    KenshiLib::GetRealAddress(&Dialogue::startConversation),
    Dialogue_startConversation_hook, Dialogue_startConversation_orig)

static void (*Dialogue__endPlayerConversation_orig)(Dialogue*, bool) = NULL;
static void Dialogue__endPlayerConversation_hook(Dialogue* thisptr, bool finished)
{
    Dialogue__endPlayerConversation_orig(thisptr, finished);
    CallDialogueEndPlayerConversationCallbacks(thisptr, finished);
}
DEFINE_HOOK_INSTALLER(InstallHook_Dialogue__endPlayerConversation,
    "Dialogue::_endPlayerConversation",
    KenshiLib::GetRealAddress(&Dialogue::_endPlayerConversation),
    Dialogue__endPlayerConversation_hook, Dialogue__endPlayerConversation_orig)

static bool (*Dialogue_startPlayerConversation_orig)(Dialogue*, Character*, DialogLineData*) = NULL;
static bool Dialogue_startPlayerConversation_hook(Dialogue* thisptr, Character* target, DialogLineData* _talk)
{
    bool current = Dialogue_startPlayerConversation_orig(thisptr, target, _talk);
    return CallDialogueStartPlayerConversationCallbacks(thisptr, target, _talk, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_Dialogue_startPlayerConversation,
    "Dialogue::startPlayerConversation",
    KenshiLib::GetRealAddress(&Dialogue::startPlayerConversation),
    Dialogue_startPlayerConversation_hook, Dialogue_startPlayerConversation_orig)

static bool (*Dialogue_sendEvent_orig)(Dialogue*, Character*, EventTriggerEnum) = NULL;
static bool Dialogue_sendEvent_hook(Dialogue* thisptr, Character* who, EventTriggerEnum what)
{
    bool current = Dialogue_sendEvent_orig(thisptr, who, what);
    return CallDialogueSendEventCallbacks(thisptr, who, what, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_Dialogue_sendEvent,
    "Dialogue::sendEvent",
    KenshiLib::GetRealAddress(&Dialogue::sendEvent),
    Dialogue_sendEvent_hook, Dialogue_sendEvent_orig)

static void (*Dialogue_stopEvent_orig)(Dialogue*, EventTriggerEnum) = NULL;
static void Dialogue_stopEvent_hook(Dialogue* thisptr, EventTriggerEnum what)
{
    Dialogue_stopEvent_orig(thisptr, what);
    CallDialogueStopEventCallbacks(thisptr, what);
}
DEFINE_HOOK_INSTALLER(InstallHook_Dialogue_stopEvent,
    "Dialogue::stopEvent",
    KenshiLib::GetRealAddress(&Dialogue::stopEvent),
    Dialogue_stopEvent_hook, Dialogue_stopEvent_orig)

static Dialogue* (*Dialogue_CONSTRUCTOR_orig)(Dialogue*) = NULL;
static Dialogue* Dialogue_CONSTRUCTOR_hook(Dialogue* thisptr)
{
    Dialogue* res = Dialogue_CONSTRUCTOR_orig(thisptr);
    Dialogue* overrideRes = CallDialogueConstructedCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Dialogue_CONSTRUCTOR,
    "Dialogue::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&Dialogue::_CONSTRUCTOR),
    Dialogue_CONSTRUCTOR_hook, Dialogue_CONSTRUCTOR_orig)

static DialogLineData* (*DialogLineData_CONSTRUCTOR_orig)(DialogLineData*, GameData*) = NULL;
static DialogLineData* DialogLineData_CONSTRUCTOR_hook(DialogLineData* thisptr, GameData* dat)
{
    DialogLineData* res = DialogLineData_CONSTRUCTOR_orig(thisptr, dat);
    DialogLineData* overrideRes = CallDialogLineDataConstructedCallbacks(thisptr, dat, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DialogLineData_CONSTRUCTOR,
    "DialogLineData::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&DialogLineData::_CONSTRUCTOR),
    DialogLineData_CONSTRUCTOR_hook, DialogLineData_CONSTRUCTOR_orig)

