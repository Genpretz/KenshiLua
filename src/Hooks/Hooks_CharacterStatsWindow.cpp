#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/gui/CharacterStatsWindow.h>

// ---------------------------------------------------------------------------
// Hooks for CharacterStatsWindow.h
//
// Non-virtual members and the _NV_ bodies of virtual members. Events fire after
// the original call unless noted; getters pass the original result as
// defaultVal and accept an override from Lua.
//
// Not hooked:
//   CharacterStatsWindow::Stat::_CONSTRUCTOR(const CharacterStatsWindow::Stat&)
//     overloaded; overloads are not hooked
//   CharacterStatsWindow::Stat::_CONSTRUCTOR()
//     overloaded; overloads are not hooked
//   CharacterStatsWindow::Stat::_CONSTRUCTOR(StatsEnumerated, const std::string&, const std::string&, bool, const std::string&)
//     overloaded; overloads are not hooked
//   CharacterStatsWindow::StatGroup::_CONSTRUCTOR(const CharacterStatsWindow::StatGroup&)
//     overloaded; overloads are not hooked
//   CharacterStatsWindow::StatGroup::_CONSTRUCTOR(CharacterStatsWindow::StatGroup::Group, const std::string&)
//     overloaded; overloads are not hooked
//   CharacterStatsWindow::StatGroup::_CONSTRUCTOR()
//     overloaded; overloads are not hooked
// ---------------------------------------------------------------------------

static void (*CharacterStatsWindow_Stat_DESTRUCTOR_orig)(CharacterStatsWindow::Stat*) = NULL;
static void CharacterStatsWindow_Stat_DESTRUCTOR_hook(CharacterStatsWindow::Stat* thisptr)
{
    CallCharacterStatsWindowStatDestructorCallbacks(thisptr);
    CharacterStatsWindow_Stat_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterStatsWindow_Stat_DESTRUCTOR,
    "CharacterStatsWindow::Stat::_DESTRUCTOR",
    KenshiLib::GetRealAddress(&CharacterStatsWindow::Stat::_DESTRUCTOR),
    CharacterStatsWindow_Stat_DESTRUCTOR_hook, CharacterStatsWindow_Stat_DESTRUCTOR_orig)

static CharacterStatsWindow::Stat& (*CharacterStatsWindow_Stat_operator_assign_orig)(CharacterStatsWindow::Stat*, const CharacterStatsWindow::Stat&) = NULL;
static CharacterStatsWindow::Stat& CharacterStatsWindow_Stat_operator_assign_hook(CharacterStatsWindow::Stat* thisptr, const CharacterStatsWindow::Stat& that)
{
    CharacterStatsWindow::Stat& res = CharacterStatsWindow_Stat_operator_assign_orig(thisptr, that);
    CallCharacterStatsWindowStatAssignCallbacks(thisptr, const_cast<CharacterStatsWindow::Stat*>(&that));
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterStatsWindow_Stat_operator_assign,
    "CharacterStatsWindow::Stat::operator=",
    KenshiLib::GetRealAddress(&CharacterStatsWindow::Stat::operator=),
    CharacterStatsWindow_Stat_operator_assign_hook, CharacterStatsWindow_Stat_operator_assign_orig)

static void (*CharacterStatsWindow_StatGroup_DESTRUCTOR_orig)(CharacterStatsWindow::StatGroup*) = NULL;
static void CharacterStatsWindow_StatGroup_DESTRUCTOR_hook(CharacterStatsWindow::StatGroup* thisptr)
{
    CallCharacterStatsWindowStatGroupDestructorCallbacks(thisptr);
    CharacterStatsWindow_StatGroup_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterStatsWindow_StatGroup_DESTRUCTOR,
    "CharacterStatsWindow::StatGroup::_DESTRUCTOR",
    KenshiLib::GetRealAddress(&CharacterStatsWindow::StatGroup::_DESTRUCTOR),
    CharacterStatsWindow_StatGroup_DESTRUCTOR_hook, CharacterStatsWindow_StatGroup_DESTRUCTOR_orig)

static CharacterStatsWindow* (*CharacterStatsWindow_CONSTRUCTOR_orig)(CharacterStatsWindow*, const hand&) = NULL;
static CharacterStatsWindow* CharacterStatsWindow_CONSTRUCTOR_hook(CharacterStatsWindow* thisptr, const hand& charHandle)
{
    CharacterStatsWindow* res = CharacterStatsWindow_CONSTRUCTOR_orig(thisptr, charHandle);
    CallCharacterStatsWindowConstructedCallbacks(thisptr, charHandle);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterStatsWindow_CONSTRUCTOR,
    "CharacterStatsWindow::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&CharacterStatsWindow::_CONSTRUCTOR),
    CharacterStatsWindow_CONSTRUCTOR_hook, CharacterStatsWindow_CONSTRUCTOR_orig)

static void (*CharacterStatsWindow_DESTRUCTOR_orig)(CharacterStatsWindow*) = NULL;
static void CharacterStatsWindow_DESTRUCTOR_hook(CharacterStatsWindow* thisptr)
{
    CallCharacterStatsWindowDestructorCallbacks(thisptr);
    CharacterStatsWindow_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterStatsWindow_DESTRUCTOR,
    "CharacterStatsWindow::_DESTRUCTOR",
    KenshiLib::GetRealAddress(&CharacterStatsWindow::_DESTRUCTOR),
    CharacterStatsWindow_DESTRUCTOR_hook, CharacterStatsWindow_DESTRUCTOR_orig)

static void (*CharacterStatsWindow_NV_clear_orig)(CharacterStatsWindow*) = NULL;
static void CharacterStatsWindow_NV_clear_hook(CharacterStatsWindow* thisptr)
{
    CharacterStatsWindow_NV_clear_orig(thisptr);
    CallCharacterStatsWindowClearCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterStatsWindow_NV_clear,
    "CharacterStatsWindow::_NV_clear",
    KenshiLib::GetRealAddress(&CharacterStatsWindow::_NV_clear),
    CharacterStatsWindow_NV_clear_hook, CharacterStatsWindow_NV_clear_orig)

static void (*CharacterStatsWindow_NV_create_orig)(CharacterStatsWindow*) = NULL;
static void CharacterStatsWindow_NV_create_hook(CharacterStatsWindow* thisptr)
{
    CharacterStatsWindow_NV_create_orig(thisptr);
    CallCharacterStatsWindowCreateCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterStatsWindow_NV_create,
    "CharacterStatsWindow::_NV_create",
    KenshiLib::GetRealAddress(&CharacterStatsWindow::_NV_create),
    CharacterStatsWindow_NV_create_hook, CharacterStatsWindow_NV_create_orig)

static void (*CharacterStatsWindow_NV_update_orig)(CharacterStatsWindow*) = NULL;
static void CharacterStatsWindow_NV_update_hook(CharacterStatsWindow* thisptr)
{
    CharacterStatsWindow_NV_update_orig(thisptr);
    CallCharacterStatsWindowUpdateCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterStatsWindow_NV_update,
    "CharacterStatsWindow::_NV_update",
    KenshiLib::GetRealAddress(&CharacterStatsWindow::_NV_update),
    CharacterStatsWindow_NV_update_hook, CharacterStatsWindow_NV_update_orig)

static void (*CharacterStatsWindow_NV_show_orig)(CharacterStatsWindow*, bool) = NULL;
static void CharacterStatsWindow_NV_show_hook(CharacterStatsWindow* thisptr, bool on)
{
    CharacterStatsWindow_NV_show_orig(thisptr, on);
    CallCharacterStatsWindowShowCallbacks(thisptr, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterStatsWindow_NV_show,
    "CharacterStatsWindow::_NV_show",
    KenshiLib::GetRealAddress(&CharacterStatsWindow::_NV_show),
    CharacterStatsWindow_NV_show_hook, CharacterStatsWindow_NV_show_orig)

static bool (*CharacterStatsWindow_NV_isVisible_orig)(const CharacterStatsWindow*) = NULL;
static bool CharacterStatsWindow_NV_isVisible_hook(const CharacterStatsWindow* thisptr)
{
    bool res = CharacterStatsWindow_NV_isVisible_orig(thisptr);
    return CallCharacterStatsWindowIsVisibleCallbacks(const_cast<CharacterStatsWindow*>(thisptr), res);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterStatsWindow_NV_isVisible,
    "CharacterStatsWindow::_NV_isVisible",
    KenshiLib::GetRealAddress(&CharacterStatsWindow::_NV_isVisible),
    CharacterStatsWindow_NV_isVisible_hook, CharacterStatsWindow_NV_isVisible_orig)

static void (*CharacterStatsWindow_NV_autoChangeSelectedObject_orig)(CharacterStatsWindow*, const hand&) = NULL;
static void CharacterStatsWindow_NV_autoChangeSelectedObject_hook(CharacterStatsWindow* thisptr, const hand& obj)
{
    CharacterStatsWindow_NV_autoChangeSelectedObject_orig(thisptr, obj);
    CallCharacterStatsWindowAutoChangeSelectedObjectCallbacks(thisptr, obj);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterStatsWindow_NV_autoChangeSelectedObject,
    "CharacterStatsWindow::_NV_autoChangeSelectedObject",
    KenshiLib::GetRealAddress(&CharacterStatsWindow::_NV_autoChangeSelectedObject),
    CharacterStatsWindow_NV_autoChangeSelectedObject_hook, CharacterStatsWindow_NV_autoChangeSelectedObject_orig)

static void (*CharacterStatsWindow_setAutoUpdateMode_orig)(CharacterStatsWindow*, bool) = NULL;
static void CharacterStatsWindow_setAutoUpdateMode_hook(CharacterStatsWindow* thisptr, bool on)
{
    CharacterStatsWindow_setAutoUpdateMode_orig(thisptr, on);
    CallCharacterStatsWindowSetAutoUpdateModeCallbacks(thisptr, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterStatsWindow_setAutoUpdateMode,
    "CharacterStatsWindow::setAutoUpdateMode",
    KenshiLib::GetRealAddress(&CharacterStatsWindow::setAutoUpdateMode),
    CharacterStatsWindow_setAutoUpdateMode_hook, CharacterStatsWindow_setAutoUpdateMode_orig)

static void (*CharacterStatsWindow_setupStats_orig)(CharacterStatsWindow*) = NULL;
static void CharacterStatsWindow_setupStats_hook(CharacterStatsWindow* thisptr)
{
    CharacterStatsWindow_setupStats_orig(thisptr);
    CallCharacterStatsWindowSetupStatsCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterStatsWindow_setupStats,
    "CharacterStatsWindow::setupStats",
    KenshiLib::GetRealAddress(&CharacterStatsWindow::setupStats),
    CharacterStatsWindow_setupStats_hook, CharacterStatsWindow_setupStats_orig)

static void (*CharacterStatsWindow_updateStats_orig)(CharacterStatsWindow*) = NULL;
static void CharacterStatsWindow_updateStats_hook(CharacterStatsWindow* thisptr)
{
    CharacterStatsWindow_updateStats_orig(thisptr);
    CallCharacterStatsWindowUpdateStatsCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterStatsWindow_updateStats,
    "CharacterStatsWindow::updateStats",
    KenshiLib::GetRealAddress(&CharacterStatsWindow::updateStats),
    CharacterStatsWindow_updateStats_hook, CharacterStatsWindow_updateStats_orig)

static void (*CharacterStatsWindow_clearDesctiption_orig)(CharacterStatsWindow*) = NULL;
static void CharacterStatsWindow_clearDesctiption_hook(CharacterStatsWindow* thisptr)
{
    CharacterStatsWindow_clearDesctiption_orig(thisptr);
    CallCharacterStatsWindowClearDesctiptionCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterStatsWindow_clearDesctiption,
    "CharacterStatsWindow::clearDesctiption",
    KenshiLib::GetRealAddress(&CharacterStatsWindow::clearDesctiption),
    CharacterStatsWindow_clearDesctiption_hook, CharacterStatsWindow_clearDesctiption_orig)

static int (*CharacterStatsWindow_sumStats_orig)(const CharacterStatsWindow*) = NULL;
static int CharacterStatsWindow_sumStats_hook(const CharacterStatsWindow* thisptr)
{
    int res = CharacterStatsWindow_sumStats_orig(thisptr);
    return CallCharacterStatsWindowSumStatsCallbacks(const_cast<CharacterStatsWindow*>(thisptr), res);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterStatsWindow_sumStats,
    "CharacterStatsWindow::sumStats",
    KenshiLib::GetRealAddress(&CharacterStatsWindow::sumStats),
    CharacterStatsWindow_sumStats_hook, CharacterStatsWindow_sumStats_orig)

static void (*CharacterStatsWindow_closeWindow_orig)(CharacterStatsWindow*, MyGUI::Window*, const std::string&) = NULL;
static void CharacterStatsWindow_closeWindow_hook(CharacterStatsWindow* thisptr, MyGUI::Window* sender, const std::string& name)
{
    CallCharacterStatsWindowCloseWindowCallbacks(thisptr, sender, name);
    CharacterStatsWindow_closeWindow_orig(thisptr, sender, name);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterStatsWindow_closeWindow,
    "CharacterStatsWindow::closeWindow",
    KenshiLib::GetRealAddress(&CharacterStatsWindow::closeWindow),
    CharacterStatsWindow_closeWindow_hook, CharacterStatsWindow_closeWindow_orig)

static void (*CharacterStatsWindow_statMouseOver_orig)(CharacterStatsWindow*, MyGUI::Widget*, int, int) = NULL;
static void CharacterStatsWindow_statMouseOver_hook(CharacterStatsWindow* thisptr, MyGUI::Widget* sender, int arg2, int arg3)
{
    CharacterStatsWindow_statMouseOver_orig(thisptr, sender, arg2, arg3);
    CallCharacterStatsWindowStatMouseOverCallbacks(thisptr, sender, arg2, arg3);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterStatsWindow_statMouseOver,
    "CharacterStatsWindow::statMouseOver",
    KenshiLib::GetRealAddress(&CharacterStatsWindow::statMouseOver),
    CharacterStatsWindow_statMouseOver_hook, CharacterStatsWindow_statMouseOver_orig)

static DatapanelGUI* (*CharacterStatsWindow_getStatsPanel_orig)(CharacterStatsWindow*, CharacterStatsWindow::StatGroup::Group) = NULL;
static DatapanelGUI* CharacterStatsWindow_getStatsPanel_hook(CharacterStatsWindow* thisptr, CharacterStatsWindow::StatGroup::Group group)
{
    DatapanelGUI* res = CharacterStatsWindow_getStatsPanel_orig(thisptr, group);
    DatapanelGUI* overrideRes = CallCharacterStatsWindowGetStatsPanelCallbacks(thisptr, static_cast<int>(group), res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterStatsWindow_getStatsPanel,
    "CharacterStatsWindow::getStatsPanel",
    KenshiLib::GetRealAddress(&CharacterStatsWindow::getStatsPanel),
    CharacterStatsWindow_getStatsPanel_hook, CharacterStatsWindow_getStatsPanel_orig)

static void (*CharacterStatsWindow_addStat_orig)(StatsEnumerated, const std::string&, const std::string&, bool, const std::string&) = NULL;
static void CharacterStatsWindow_addStat_hook(StatsEnumerated type, const std::string& id, const std::string& name, bool active, const std::string& description)
{
    CharacterStatsWindow_addStat_orig(type, id, name, active, description);
    CallCharacterStatsWindowAddStatCallbacks(static_cast<int>(type), id, name, active, description);
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterStatsWindow_addStat,
    "CharacterStatsWindow::addStat",
    KenshiLib::GetRealAddress(&CharacterStatsWindow::addStat),
    CharacterStatsWindow_addStat_hook, CharacterStatsWindow_addStat_orig)

static CharacterStatsWindow::Stat* (*CharacterStatsWindow_getStat_orig)(StatsEnumerated) = NULL;
static CharacterStatsWindow::Stat* CharacterStatsWindow_getStat_hook(StatsEnumerated type)
{
    CharacterStatsWindow::Stat* res = CharacterStatsWindow_getStat_orig(type);
    CharacterStatsWindow::Stat* overrideRes = CallCharacterStatsWindowGetStatCallbacks(static_cast<int>(type), res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterStatsWindow_getStat,
    "CharacterStatsWindow::getStat",
    KenshiLib::GetRealAddress(&CharacterStatsWindow::getStat),
    CharacterStatsWindow_getStat_hook, CharacterStatsWindow_getStat_orig)

static CharacterStatsWindow::Stat* (*CharacterStatsWindow_getStatById_orig)(const std::string&) = NULL;
static CharacterStatsWindow::Stat* CharacterStatsWindow_getStatById_hook(const std::string& id)
{
    CharacterStatsWindow::Stat* res = CharacterStatsWindow_getStatById_orig(id);
    CharacterStatsWindow::Stat* overrideRes = CallCharacterStatsWindowGetStatByIdCallbacks(id, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterStatsWindow_getStatById,
    "CharacterStatsWindow::getStatById",
    KenshiLib::GetRealAddress(&CharacterStatsWindow::getStatById),
    CharacterStatsWindow_getStatById_hook, CharacterStatsWindow_getStatById_orig)

static void (*CharacterStatsWindow_BuildStats_orig)() = NULL;
static void CharacterStatsWindow_BuildStats_hook()
{
    CharacterStatsWindow_BuildStats_orig();
    CallCharacterStatsWindowBuildStatsCallbacks();
}
DEFINE_HOOK_INSTALLER(InstallHook_CharacterStatsWindow_BuildStats,
    "CharacterStatsWindow::BuildStats",
    KenshiLib::GetRealAddress(&CharacterStatsWindow::BuildStats),
    CharacterStatsWindow_BuildStats_hook, CharacterStatsWindow_BuildStats_orig)
