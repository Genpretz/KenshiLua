#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/gui/ManagementScreen.h>

// ---------------------------------------------------------------------------
// Hooks for ManagementScreen.h
//
// All address-bearing non-virtual concrete members. Scalar and singleton
// results accept Lua overrides. Destructors dispatch before the original.
//
// Not hooked:
//   ReorderableList<T1, T2> members
//     the header does not identify one canonical exported specialization
//   ManagementScreen::TechItemViewData::_CONSTRUCTOR overloads
//     overloaded; one canonical event cannot safely represent both ABIs
// ---------------------------------------------------------------------------

#define MANAGEMENT_VOID0(method, Callback) \
    static void (*ManagementScreen_##method##_orig)(ManagementScreen*) = NULL; \
    static void ManagementScreen_##method##_hook(ManagementScreen* thisptr) \
    { \
        ManagementScreen_##method##_orig(thisptr); \
        Callback(thisptr); \
    } \
    DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_##method, \
        "ManagementScreen::" #method, KenshiLib::GetRealAddress(&ManagementScreen::method), \
        ManagementScreen_##method##_hook, ManagementScreen_##method##_orig)

static ManagementScreen* (*ManagementScreen_getSingleton_orig)() = NULL;
static ManagementScreen* ManagementScreen_getSingleton_hook()
{
    ManagementScreen* result = ManagementScreen_getSingleton_orig();
    ManagementScreen* overrideResult = CallManagementScreenGetSingletonCallbacks(result);
    return overrideResult ? overrideResult : result;
}
DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_static_getSingleton,
    "ManagementScreen::getSingleton", KenshiLib::GetRealAddress(&ManagementScreen::getSingleton),
    ManagementScreen_getSingleton_hook, ManagementScreen_getSingleton_orig)

static void (*ManagementScreen_DESTRUCTOR_orig)(ManagementScreen*) = NULL;
static void ManagementScreen_DESTRUCTOR_hook(ManagementScreen* thisptr)
{
    CallManagementScreenDestructorCallbacks(thisptr);
    ManagementScreen_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_DESTRUCTOR,
    "ManagementScreen::_DESTRUCTOR", KenshiLib::GetRealAddress(&ManagementScreen::_DESTRUCTOR),
    ManagementScreen_DESTRUCTOR_hook, ManagementScreen_DESTRUCTOR_orig)

MANAGEMENT_VOID0(update, CallManagementScreenUpdateCallbacks)
MANAGEMENT_VOID0(clear, CallManagementScreenClearCallbacks)

static bool (*ManagementScreen_getVisible_orig)(ManagementScreen*) = NULL;
static bool ManagementScreen_getVisible_hook(ManagementScreen* thisptr)
{
    bool result = ManagementScreen_getVisible_orig(thisptr);
    return CallManagementScreenGetVisibleCallbacks(thisptr, result);
}
DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_getVisible,
    "ManagementScreen::getVisible", KenshiLib::GetRealAddress(&ManagementScreen::getVisible),
    ManagementScreen_getVisible_hook, ManagementScreen_getVisible_orig)

static void (*ManagementScreen_setVisible_orig)(ManagementScreen*, bool, int) = NULL;
static void ManagementScreen_setVisible_hook(ManagementScreen* thisptr, bool on, int tab)
{
    ManagementScreen_setVisible_orig(thisptr, on, tab);
    CallManagementScreenSetVisibleCallbacks(thisptr, on, tab);
}
DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_setVisible,
    "ManagementScreen::setVisible", KenshiLib::GetRealAddress(&ManagementScreen::setVisible),
    ManagementScreen_setVisible_hook, ManagementScreen_setVisible_orig)

static void (*ManagementScreen_closeEverythingButton_orig)(ManagementScreen*, MyGUI::Window*, const std::string&) = NULL;
static void ManagementScreen_closeEverythingButton_hook(ManagementScreen* thisptr, MyGUI::Window* widget, const std::string& name)
{
    ManagementScreen_closeEverythingButton_orig(thisptr, widget, name);
    CallManagementScreenCloseEverythingButtonCallbacks(thisptr, widget, name);
}
DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_closeEverythingButton,
    "ManagementScreen::closeEverythingButton", KenshiLib::GetRealAddress(&ManagementScreen::closeEverythingButton),
    ManagementScreen_closeEverythingButton_hook, ManagementScreen_closeEverythingButton_orig)

static void (*ManagementScreen_tabCallback_orig)(ManagementScreen*, MyGUI::TabControl*, unsigned __int64) = NULL;
static void ManagementScreen_tabCallback_hook(ManagementScreen* thisptr, MyGUI::TabControl* sender, unsigned __int64 index)
{
    ManagementScreen_tabCallback_orig(thisptr, sender, index);
    CallManagementScreenTabCallbackCallbacks(thisptr, sender, static_cast<double>(index));
}
DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_tabCallback,
    "ManagementScreen::tabCallback", KenshiLib::GetRealAddress(&ManagementScreen::tabCallback),
    ManagementScreen_tabCallback_hook, ManagementScreen_tabCallback_orig)

static int (*ManagementScreen_getCurrentTab_orig)(ManagementScreen*) = NULL;
static int ManagementScreen_getCurrentTab_hook(ManagementScreen* thisptr)
{
    int result = ManagementScreen_getCurrentTab_orig(thisptr);
    return static_cast<int>(CallManagementScreenGetCurrentTabCallbacks(thisptr, result));
}
DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_getCurrentTab,
    "ManagementScreen::getCurrentTab", KenshiLib::GetRealAddress(&ManagementScreen::getCurrentTab),
    ManagementScreen_getCurrentTab_hook, ManagementScreen_getCurrentTab_orig)

static MyGUI::TabItem* (*ManagementScreen_getTab_orig)(const ManagementScreen*, int) = NULL;
static MyGUI::TabItem* ManagementScreen_getTab_hook(const ManagementScreen* thisptr, int index)
{
    MyGUI::TabItem* result = ManagementScreen_getTab_orig(thisptr, index);
    CallManagementScreenGetTabCallbacks(const_cast<ManagementScreen*>(thisptr), index, result);
    return result;
}
DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_getTab,
    "ManagementScreen::getTab", KenshiLib::GetRealAddress(&ManagementScreen::getTab),
    ManagementScreen_getTab_hook, ManagementScreen_getTab_orig)

static MyGUI::Widget* (*ManagementScreen_getWidget_orig)(ManagementScreen*, const std::string&) = NULL;
static MyGUI::Widget* ManagementScreen_getWidget_hook(ManagementScreen* thisptr, const std::string& name)
{
    MyGUI::Widget* result = ManagementScreen_getWidget_orig(thisptr, name);
    CallManagementScreenGetWidgetCallbacks(thisptr, name, result);
    return result;
}
DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_getWidget,
    "ManagementScreen::getWidget", KenshiLib::GetRealAddress(&ManagementScreen::getWidget),
    ManagementScreen_getWidget_hook, ManagementScreen_getWidget_orig)

static void (*ManagementScreen_refresh_orig)(ManagementScreen*, GameData*, float) = NULL;
static void ManagementScreen_refresh_hook(ManagementScreen* thisptr, GameData* current, float progress)
{
    ManagementScreen_refresh_orig(thisptr, current, progress);
    CallManagementScreenRefreshCallbacks(thisptr, current, progress);
}
DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_refresh,
    "ManagementScreen::refresh", KenshiLib::GetRealAddress(&ManagementScreen::refresh),
    ManagementScreen_refresh_hook, ManagementScreen_refresh_orig)

MANAGEMENT_VOID0(refreshResearchList, CallManagementScreenRefreshResearchListCallbacks)
MANAGEMENT_VOID0(refreshResearchRate, CallManagementScreenRefreshResearchRateCallbacks)
MANAGEMENT_VOID0(refreshDiplomacy, CallManagementScreenRefreshDiplomacyCallbacks)
MANAGEMENT_VOID0(refreshSquads, CallManagementScreenRefreshSquadsCallbacks)

static void (*ManagementScreen_refreshMap_orig)(ManagementScreen*, bool) = NULL;
static void ManagementScreen_refreshMap_hook(ManagementScreen* thisptr, bool centerCamera)
{
    ManagementScreen_refreshMap_orig(thisptr, centerCamera);
    CallManagementScreenRefreshMapCallbacks(thisptr, centerCamera);
}
DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_refreshMap,
    "ManagementScreen::refreshMap", KenshiLib::GetRealAddress(&ManagementScreen::refreshMap),
    ManagementScreen_refreshMap_hook, ManagementScreen_refreshMap_orig)

static void (*ManagementScreen_showRoads_orig)(ManagementScreen*, bool) = NULL;
static void ManagementScreen_showRoads_hook(ManagementScreen* thisptr, bool value)
{
    ManagementScreen_showRoads_orig(thisptr, value);
    CallManagementScreenShowRoadsCallbacks(thisptr, value);
}
DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_showRoads,
    "ManagementScreen::showRoads", KenshiLib::GetRealAddress(&ManagementScreen::showRoads),
    ManagementScreen_showRoads_hook, ManagementScreen_showRoads_orig)

#define MANAGEMENT_SQUAD(method, Callback) \
    static void (*ManagementScreen_##method##_orig)(ManagementScreen*, Platoon*) = NULL; \
    static void ManagementScreen_##method##_hook(ManagementScreen* thisptr, Platoon* squad) \
    { \
        ManagementScreen_##method##_orig(thisptr, squad); \
        Callback(thisptr, squad); \
    } \
    DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_##method, \
        "ManagementScreen::" #method, KenshiLib::GetRealAddress(&ManagementScreen::method), \
        ManagementScreen_##method##_hook, ManagementScreen_##method##_orig)

MANAGEMENT_SQUAD(addSquadToMap, CallManagementScreenAddSquadToMapCallbacks)
MANAGEMENT_SQUAD(removeSquadFromMap, CallManagementScreenRemoveSquadFromMapCallbacks)

static void (*ManagementScreen_addMessage_orig)(ManagementScreen*, const std::string&, const std::string&, MessageLogColor) = NULL;
static void ManagementScreen_addMessage_hook(ManagementScreen* thisptr, const std::string& owner, const std::string& message, MessageLogColor color)
{
    ManagementScreen_addMessage_orig(thisptr, owner, message, color);
    CallManagementScreenAddMessageCallbacks(thisptr, owner, message, static_cast<int>(color));
}
DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_addMessage,
    "ManagementScreen::addMessage", KenshiLib::GetRealAddress(&ManagementScreen::addMessage),
    ManagementScreen_addMessage_hook, ManagementScreen_addMessage_orig)

MANAGEMENT_VOID0(resetSquads, CallManagementScreenResetSquadsCallbacks)
MANAGEMENT_VOID0(refreshMessages, CallManagementScreenRefreshMessagesCallbacks)
MANAGEMENT_VOID0(refreshAI, CallManagementScreenRefreshAICallbacks)

static void (*ManagementScreen_setCraftingBench_orig)(ManagementScreen*, const hand&) = NULL;
static void ManagementScreen_setCraftingBench_hook(ManagementScreen* thisptr, const hand& buildingHandle)
{
    ManagementScreen_setCraftingBench_orig(thisptr, buildingHandle);
    CallManagementScreenSetCraftingBenchCallbacks(thisptr, buildingHandle);
}
DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_setCraftingBench,
    "ManagementScreen::setCraftingBench", KenshiLib::GetRealAddress(&ManagementScreen::setCraftingBench),
    ManagementScreen_setCraftingBench_hook, ManagementScreen_setCraftingBench_orig)

static void (*ManagementScreen_printResearch_orig)(DatapanelGUI*, GameData*, const std::string&, const std::string&, int) = NULL;
static void ManagementScreen_printResearch_hook(DatapanelGUI* panel, GameData* data, const std::string& listName, const std::string& displayName, int category)
{
    ManagementScreen_printResearch_orig(panel, data, listName, displayName, category);
    CallManagementScreenPrintResearchCallbacks(panel, data, listName, displayName, category);
}
DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_static_printResearch,
    "ManagementScreen::printResearch", KenshiLib::GetRealAddress(&ManagementScreen::printResearch),
    ManagementScreen_printResearch_hook, ManagementScreen_printResearch_orig)

static void (*ManagementScreen_showDebugMarker_orig)(ManagementScreen*, const Ogre::Vector3&) = NULL;
static void ManagementScreen_showDebugMarker_hook(ManagementScreen* thisptr, const Ogre::Vector3& position)
{
    ManagementScreen_showDebugMarker_orig(thisptr, position);
    CallManagementScreenShowDebugMarkerCallbacks(thisptr, position);
}
DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_showDebugMarker,
    "ManagementScreen::showDebugMarker", KenshiLib::GetRealAddress(&ManagementScreen::showDebugMarker),
    ManagementScreen_showDebugMarker_hook, ManagementScreen_showDebugMarker_orig)

static ManagementScreen* (*ManagementScreen_CONSTRUCTOR_orig)(ManagementScreen*) = NULL;
static ManagementScreen* ManagementScreen_CONSTRUCTOR_hook(ManagementScreen* thisptr)
{
    ManagementScreen* result = ManagementScreen_CONSTRUCTOR_orig(thisptr);
    CallManagementScreenConstructedCallbacks(thisptr);
    return result;
}
DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_CONSTRUCTOR,
    "ManagementScreen::_CONSTRUCTOR", KenshiLib::GetRealAddress(&ManagementScreen::_CONSTRUCTOR),
    ManagementScreen_CONSTRUCTOR_hook, ManagementScreen_CONSTRUCTOR_orig)

MANAGEMENT_VOID0(updateResearchListRate, CallManagementScreenUpdateResearchListRateCallbacks)
MANAGEMENT_VOID0(refreshResearchListDescription, CallManagementScreenRefreshResearchListDescriptionCallbacks)

static void (*ManagementScreen_researchTypeSelect_orig)(ManagementScreen*, MyGUI::ListBox*, unsigned __int64) = NULL;
static void ManagementScreen_researchTypeSelect_hook(ManagementScreen* thisptr, MyGUI::ListBox* sender, unsigned __int64 index)
{
    ManagementScreen_researchTypeSelect_orig(thisptr, sender, index);
    CallManagementScreenResearchTypeSelectCallbacks(thisptr, sender, static_cast<double>(index));
}
DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_researchTypeSelect,
    "ManagementScreen::researchTypeSelect", KenshiLib::GetRealAddress(&ManagementScreen::researchTypeSelect),
    ManagementScreen_researchTypeSelect_hook, ManagementScreen_researchTypeSelect_orig)

#define MANAGEMENT_MOUSE_BUTTON(method, Callback) \
    static void (*ManagementScreen_##method##_orig)(ManagementScreen*, MyGUI::Widget*, int, int, MyGUI::MouseButton) = NULL; \
    static void ManagementScreen_##method##_hook(ManagementScreen* thisptr, MyGUI::Widget* sender, int left, int top, MyGUI::MouseButton id) \
    { \
        ManagementScreen_##method##_orig(thisptr, sender, left, top, id); \
        Callback(thisptr, sender, left, top, id.getValue()); \
    } \
    DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_##method, \
        "ManagementScreen::" #method, KenshiLib::GetRealAddress(&ManagementScreen::method), \
        ManagementScreen_##method##_hook, ManagementScreen_##method##_orig)

MANAGEMENT_MOUSE_BUTTON(addButtonPress, CallManagementScreenAddButtonPressCallbacks)
MANAGEMENT_MOUSE_BUTTON(removeButtonPress, CallManagementScreenRemoveButtonPressCallbacks)

static void (*ManagementScreen_mouseOverCallback_orig)(ManagementScreen*, MyGUI::Widget*, int, int) = NULL;
static void ManagementScreen_mouseOverCallback_hook(ManagementScreen* thisptr, MyGUI::Widget* sender, int left, int top)
{
    ManagementScreen_mouseOverCallback_orig(thisptr, sender, left, top);
    CallManagementScreenMouseOverCallbacks(thisptr, sender, left, top);
}
DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_mouseOverCallback,
    "ManagementScreen::mouseOverCallback", KenshiLib::GetRealAddress(&ManagementScreen::mouseOverCallback),
    ManagementScreen_mouseOverCallback_hook, ManagementScreen_mouseOverCallback_orig)

static const std::string& (*TechItemViewData_getName_orig)(const ManagementScreen::TechItemViewData*) = NULL;
static const std::string& TechItemViewData_getName_hook(const ManagementScreen::TechItemViewData* thisptr)
{
    const std::string& result = TechItemViewData_getName_orig(thisptr);
    CallTechItemViewDataGetNameCallbacks(const_cast<ManagementScreen::TechItemViewData*>(thisptr), result);
    return result;
}
DEFINE_HOOK_INSTALLER(InstallHook_TechItemViewData_getName,
    "ManagementScreen::TechItemViewData::getName", KenshiLib::GetRealAddress(&ManagementScreen::TechItemViewData::getName),
    TechItemViewData_getName_hook, TechItemViewData_getName_orig)

static std::string (*TechItemViewData_getValue_orig)(const ManagementScreen::TechItemViewData*) = NULL;
static std::string TechItemViewData_getValue_hook(const ManagementScreen::TechItemViewData* thisptr)
{
    std::string result = TechItemViewData_getValue_orig(thisptr);
    CallTechItemViewDataGetValueCallbacks(const_cast<ManagementScreen::TechItemViewData*>(thisptr), result);
    return result;
}
DEFINE_HOOK_INSTALLER(InstallHook_TechItemViewData_getValue,
    "ManagementScreen::TechItemViewData::getValue", KenshiLib::GetRealAddress(&ManagementScreen::TechItemViewData::getValue),
    TechItemViewData_getValue_hook, TechItemViewData_getValue_orig)

static float (*TechItemViewData_getProgress_orig)(const ManagementScreen::TechItemViewData*) = NULL;
static float TechItemViewData_getProgress_hook(const ManagementScreen::TechItemViewData* thisptr)
{
    float result = TechItemViewData_getProgress_orig(thisptr);
    return static_cast<float>(CallTechItemViewDataGetProgressCallbacks(const_cast<ManagementScreen::TechItemViewData*>(thisptr), result));
}
DEFINE_HOOK_INSTALLER(InstallHook_TechItemViewData_getProgress,
    "ManagementScreen::TechItemViewData::getProgress", KenshiLib::GetRealAddress(&ManagementScreen::TechItemViewData::getProgress),
    TechItemViewData_getProgress_hook, TechItemViewData_getProgress_orig)

static void (*TechItemViewData_setItem_orig)(ManagementScreen::TechItemViewData*, ResearchItem&) = NULL;
static void TechItemViewData_setItem_hook(ManagementScreen::TechItemViewData* thisptr, ResearchItem& item)
{
    TechItemViewData_setItem_orig(thisptr, item);
    CallTechItemViewDataSetItemCallbacks(thisptr, &item);
}
DEFINE_HOOK_INSTALLER(InstallHook_TechItemViewData_setItem,
    "ManagementScreen::TechItemViewData::setItem", KenshiLib::GetRealAddress(&ManagementScreen::TechItemViewData::setItem),
    TechItemViewData_setItem_hook, TechItemViewData_setItem_orig)

static void (*TechItemViewData_DESTRUCTOR_orig)(ManagementScreen::TechItemViewData*) = NULL;
static void TechItemViewData_DESTRUCTOR_hook(ManagementScreen::TechItemViewData* thisptr)
{
    CallTechItemViewDataDestructorCallbacks(thisptr);
    TechItemViewData_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_TechItemViewData_DESTRUCTOR,
    "ManagementScreen::TechItemViewData::_DESTRUCTOR", KenshiLib::GetRealAddress(&ManagementScreen::TechItemViewData::_DESTRUCTOR),
    TechItemViewData_DESTRUCTOR_hook, TechItemViewData_DESTRUCTOR_orig)

static void (*ManagementScreen_researchQueueTooltip_orig)(ManagementScreen*, wraps::BaseLayout*, const MyGUI::ToolTipInfo&, ManagementScreen::TechItemViewData) = NULL;
static void ManagementScreen_researchQueueTooltip_hook(ManagementScreen* thisptr, wraps::BaseLayout* layout, const MyGUI::ToolTipInfo& info, ManagementScreen::TechItemViewData data)
{
    ManagementScreen_researchQueueTooltip_orig(thisptr, layout, info, data);
    CallManagementScreenResearchQueueTooltipCallbacks(thisptr, layout, const_cast<MyGUI::ToolTipInfo*>(&info), data);
}
DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_researchQueueTooltip,
    "ManagementScreen::researchQueueTooltip", KenshiLib::GetRealAddress(&ManagementScreen::researchQueueTooltip),
    ManagementScreen_researchQueueTooltip_hook, ManagementScreen_researchQueueTooltip_orig)

static void (*ManagementScreen_researchRemoved_orig)(ManagementScreen*, int, const ManagementScreen::TechItemViewData&) = NULL;
static void ManagementScreen_researchRemoved_hook(ManagementScreen* thisptr, int index, const ManagementScreen::TechItemViewData& item)
{
    ManagementScreen_researchRemoved_orig(thisptr, index, item);
    CallManagementScreenResearchRemovedCallbacks(thisptr, index, item);
}
DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_researchRemoved,
    "ManagementScreen::researchRemoved", KenshiLib::GetRealAddress(&ManagementScreen::researchRemoved),
    ManagementScreen_researchRemoved_hook, ManagementScreen_researchRemoved_orig)

static void (*ManagementScreen_researchValidateOrder_orig)(ManagementScreen*, int, int, bool&) = NULL;
static void ManagementScreen_researchValidateOrder_hook(ManagementScreen* thisptr, int first, int second, bool& result)
{
    ManagementScreen_researchValidateOrder_orig(thisptr, first, second, result);
    result = CallManagementScreenResearchValidateOrderCallbacks(thisptr, first, second, result);
}
DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_researchValidateOrder,
    "ManagementScreen::researchValidateOrder", KenshiLib::GetRealAddress(&ManagementScreen::researchValidateOrder),
    ManagementScreen_researchValidateOrder_hook, ManagementScreen_researchValidateOrder_orig)

#undef MANAGEMENT_MOUSE_BUTTON
#undef MANAGEMENT_SQUAD
#undef MANAGEMENT_VOID0
