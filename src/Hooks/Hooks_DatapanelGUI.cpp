#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/gui/DatapanelGUI.h>

// ---------------------------------------------------------------------------
// Hooks for DatapanelGUI.h
//
// Non-virtual members and the _NV_ bodies of virtual members. Events fire after
// the original call unless noted; getters pass the original result as
// defaultVal and accept an override from Lua.
//
// Not hooked:
//   DatapanelGUI::setFrequentUpdateMode()
//     RVA 0x43FDC0 lies outside the class code; possibly an identical-code-folded copy shared with other functions (unverified)
//   DatapanelGUI::setLine(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, int)
//     overloaded; overloads are not hooked
//   DatapanelGUI::setLine(const std::string&, const std::string&, const std::string&, int, bool, bool)
//     overloaded; overloads are not hooked
//   DatapanelGUI::setLine(const std::string&, const std::string&, const std::string&, const std::string&, int)
//     overloaded; overloads are not hooked
//   DatapanelGUI::setLine(const std::string&, const std::string&, float, int)
//     overloaded; overloads are not hooked
//   DatapanelGUI::setLine(const std::string&, const std::string&, int, bool, bool)
//     overloaded; overloads are not hooked
//   DatapanelGUI::setLineResearch(const std::string&, const std::string&, int, float, const std::string&, bool)
//     overloaded; overloads are not hooked
//   DatapanelGUI::setLineResearch(const std::string&, const std::string&, const std::string&, int, float, const std::string&, bool)
//     overloaded; overloads are not hooked
//   DatapanelGUI::_NV_getCurrentCategory() const
//     RVA 0x70B6E0 lies outside the class code; possibly an identical-code-folded copy shared with other functions (unverified)
//   DatapanelGUI::_NV_getObject() const
//     RVA 0x70B6F0 lies outside the class code; possibly an identical-code-folded copy shared with other functions (unverified)
//   DatapanelGUI::_NV_setMouseOverCallback(function*, void*)
//     SDK declares function* evt, but KenshiLib exports void (*)(std::string, void*); the declaration cannot be linked
//   DatapanelGUI::getContentHeight(int) const
//     KenshiLib::AddHook fails on the GOG 1.0.65 executable (RE_Kenshi: "Error enabling hook: 8"); the function cannot be hooked
//   DatapanelGUI::_CONSTRUCTOR(const std::string&, MyGUI::Widget*, bool)
//     overloaded; overloads are not hooked
//   DatapanelGUI::_CONSTRUCTOR(float, float, float, float, bool, const std::string&)
//     overloaded; overloads are not hooked
// ---------------------------------------------------------------------------

static void (*DatapanelGUI_NV_setPositionReal_orig)(DatapanelGUI*, float, float) = NULL;
static void DatapanelGUI_NV_setPositionReal_hook(DatapanelGUI* thisptr, float x, float y)
{
    DatapanelGUI_NV_setPositionReal_orig(thisptr, x, y);
    CallDatapanelGUISetPositionRealCallbacks(thisptr, x, y);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_NV_setPositionReal,
    "DatapanelGUI::_NV_setPositionReal",
    KenshiLib::GetRealAddress(&DatapanelGUI::_NV_setPositionReal),
    DatapanelGUI_NV_setPositionReal_hook, DatapanelGUI_NV_setPositionReal_orig)

static void (*DatapanelGUI_NV_setPosition_orig)(DatapanelGUI*, int, int) = NULL;
static void DatapanelGUI_NV_setPosition_hook(DatapanelGUI* thisptr, int x, int y)
{
    DatapanelGUI_NV_setPosition_orig(thisptr, x, y);
    CallDatapanelGUISetPositionCallbacks(thisptr, x, y);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_NV_setPosition,
    "DatapanelGUI::_NV_setPosition",
    KenshiLib::GetRealAddress(&DatapanelGUI::_NV_setPosition),
    DatapanelGUI_NV_setPosition_hook, DatapanelGUI_NV_setPosition_orig)

static void (*DatapanelGUI_NV_resize_orig)(DatapanelGUI*, int, int) = NULL;
static void DatapanelGUI_NV_resize_hook(DatapanelGUI* thisptr, int w, int h)
{
    DatapanelGUI_NV_resize_orig(thisptr, w, h);
    CallDatapanelGUIResizeCallbacks(thisptr, w, h);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_NV_resize,
    "DatapanelGUI::_NV_resize",
    KenshiLib::GetRealAddress(&DatapanelGUI::_NV_resize),
    DatapanelGUI_NV_resize_hook, DatapanelGUI_NV_resize_orig)

static void (*DatapanelGUI_NV_clear_orig)(DatapanelGUI*) = NULL;
static void DatapanelGUI_NV_clear_hook(DatapanelGUI* thisptr)
{
    DatapanelGUI_NV_clear_orig(thisptr);
    CallDatapanelGUIClearCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_NV_clear,
    "DatapanelGUI::_NV_clear",
    KenshiLib::GetRealAddress(&DatapanelGUI::_NV_clear),
    DatapanelGUI_NV_clear_hook, DatapanelGUI_NV_clear_orig)

static void (*DatapanelGUI_NV_clearPage_orig)(DatapanelGUI*, int) = NULL;
static void DatapanelGUI_NV_clearPage_hook(DatapanelGUI* thisptr, int cat)
{
    DatapanelGUI_NV_clearPage_orig(thisptr, cat);
    CallDatapanelGUIClearPageCallbacks(thisptr, cat);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_NV_clearPage,
    "DatapanelGUI::_NV_clearPage",
    KenshiLib::GetRealAddress(&DatapanelGUI::_NV_clearPage),
    DatapanelGUI_NV_clearPage_hook, DatapanelGUI_NV_clearPage_orig)

static void (*DatapanelGUI_NV_hideAllWidgets_orig)(DatapanelGUI*) = NULL;
static void DatapanelGUI_NV_hideAllWidgets_hook(DatapanelGUI* thisptr)
{
    DatapanelGUI_NV_hideAllWidgets_orig(thisptr);
    CallDatapanelGUIHideAllWidgetsCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_NV_hideAllWidgets,
    "DatapanelGUI::_NV_hideAllWidgets",
    KenshiLib::GetRealAddress(&DatapanelGUI::_NV_hideAllWidgets),
    DatapanelGUI_NV_hideAllWidgets_hook, DatapanelGUI_NV_hideAllWidgets_orig)

static void (*DatapanelGUI_NV_create_orig)(DatapanelGUI*) = NULL;
static void DatapanelGUI_NV_create_hook(DatapanelGUI* thisptr)
{
    DatapanelGUI_NV_create_orig(thisptr);
    CallDatapanelGUICreateCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_NV_create,
    "DatapanelGUI::_NV_create",
    KenshiLib::GetRealAddress(&DatapanelGUI::_NV_create),
    DatapanelGUI_NV_create_hook, DatapanelGUI_NV_create_orig)

static void (*DatapanelGUI_NV_show_orig)(DatapanelGUI*, bool) = NULL;
static void DatapanelGUI_NV_show_hook(DatapanelGUI* thisptr, bool on)
{
    DatapanelGUI_NV_show_orig(thisptr, on);
    CallDatapanelGUIShowCallbacks(thisptr, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_NV_show,
    "DatapanelGUI::_NV_show",
    KenshiLib::GetRealAddress(&DatapanelGUI::_NV_show),
    DatapanelGUI_NV_show_hook, DatapanelGUI_NV_show_orig)

static void (*DatapanelGUI_show_NonSmooth_orig)(DatapanelGUI*, bool) = NULL;
static void DatapanelGUI_show_NonSmooth_hook(DatapanelGUI* thisptr, bool on)
{
    DatapanelGUI_show_NonSmooth_orig(thisptr, on);
    CallDatapanelGUIShow_NonSmoothCallbacks(thisptr, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_show_NonSmooth,
    "DatapanelGUI::show_NonSmooth",
    KenshiLib::GetRealAddress(&DatapanelGUI::show_NonSmooth),
    DatapanelGUI_show_NonSmooth_hook, DatapanelGUI_show_NonSmooth_orig)

static void (*DatapanelGUI_NV_update_orig)(DatapanelGUI*) = NULL;
static void DatapanelGUI_NV_update_hook(DatapanelGUI* thisptr)
{
    DatapanelGUI_NV_update_orig(thisptr);
    CallDatapanelGUIUpdateCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_NV_update,
    "DatapanelGUI::_NV_update",
    KenshiLib::GetRealAddress(&DatapanelGUI::_NV_update),
    DatapanelGUI_NV_update_hook, DatapanelGUI_NV_update_orig)

static void (*DatapanelGUI_setPanelName_orig)(DatapanelGUI*, const std::string&) = NULL;
static void DatapanelGUI_setPanelName_hook(DatapanelGUI* thisptr, const std::string& name)
{
    DatapanelGUI_setPanelName_orig(thisptr, name);
    CallDatapanelGUISetPanelNameCallbacks(thisptr, name);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_setPanelName,
    "DatapanelGUI::setPanelName",
    KenshiLib::GetRealAddress(&DatapanelGUI::setPanelName),
    DatapanelGUI_setPanelName_hook, DatapanelGUI_setPanelName_orig)

static void (*DatapanelGUI_NV_showTabs_orig)(DatapanelGUI*, bool) = NULL;
static void DatapanelGUI_NV_showTabs_hook(DatapanelGUI* thisptr, bool on)
{
    DatapanelGUI_NV_showTabs_orig(thisptr, on);
    CallDatapanelGUIShowTabsCallbacks(thisptr, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_NV_showTabs,
    "DatapanelGUI::_NV_showTabs",
    KenshiLib::GetRealAddress(&DatapanelGUI::_NV_showTabs),
    DatapanelGUI_NV_showTabs_hook, DatapanelGUI_NV_showTabs_orig)

static void (*DatapanelGUI_NV_addTab_orig)(DatapanelGUI*, int, const std::string&, const std::string&) = NULL;
static void DatapanelGUI_NV_addTab_hook(DatapanelGUI* thisptr, int id, const std::string& name, const std::string& icon)
{
    DatapanelGUI_NV_addTab_orig(thisptr, id, name, icon);
    CallDatapanelGUIAddTabCallbacks(thisptr, id, name, icon);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_NV_addTab,
    "DatapanelGUI::_NV_addTab",
    KenshiLib::GetRealAddress(&DatapanelGUI::_NV_addTab),
    DatapanelGUI_NV_addTab_hook, DatapanelGUI_NV_addTab_orig)

static void (*DatapanelGUI_NV_setTabEnabled_orig)(DatapanelGUI*, int, const bool&) = NULL;
static void DatapanelGUI_NV_setTabEnabled_hook(DatapanelGUI* thisptr, int id, const bool& enabled)
{
    DatapanelGUI_NV_setTabEnabled_orig(thisptr, id, enabled);
    CallDatapanelGUISetTabEnabledCallbacks(thisptr, id, enabled);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_NV_setTabEnabled,
    "DatapanelGUI::_NV_setTabEnabled",
    KenshiLib::GetRealAddress(&DatapanelGUI::_NV_setTabEnabled),
    DatapanelGUI_NV_setTabEnabled_hook, DatapanelGUI_NV_setTabEnabled_orig)

static void (*DatapanelGUI_NV_setTabName_orig)(DatapanelGUI*, int, const std::string&) = NULL;
static void DatapanelGUI_NV_setTabName_hook(DatapanelGUI* thisptr, int id, const std::string& name)
{
    DatapanelGUI_NV_setTabName_orig(thisptr, id, name);
    CallDatapanelGUISetTabNameCallbacks(thisptr, id, name);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_NV_setTabName,
    "DatapanelGUI::_NV_setTabName",
    KenshiLib::GetRealAddress(&DatapanelGUI::_NV_setTabName),
    DatapanelGUI_NV_setTabName_hook, DatapanelGUI_NV_setTabName_orig)

static void (*DatapanelGUI_setCaption_orig)(DatapanelGUI*, const std::string&) = NULL;
static void DatapanelGUI_setCaption_hook(DatapanelGUI* thisptr, const std::string& s)
{
    DatapanelGUI_setCaption_orig(thisptr, s);
    CallDatapanelGUISetCaptionCallbacks(thisptr, s);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_setCaption,
    "DatapanelGUI::setCaption",
    KenshiLib::GetRealAddress(&DatapanelGUI::setCaption),
    DatapanelGUI_setCaption_hook, DatapanelGUI_setCaption_orig)

static void (*DatapanelGUI_setCloseCallback_orig)(DatapanelGUI*, MyGUI::delegates::IDelegate2<MyGUI::Window*, std::string const&>*) = NULL;
static void DatapanelGUI_setCloseCallback_hook(DatapanelGUI* thisptr, MyGUI::delegates::IDelegate2<MyGUI::Window*, std::string const&>* close)
{
    DatapanelGUI_setCloseCallback_orig(thisptr, close);
    CallDatapanelGUISetCloseCallbackCallbacks(thisptr, (void*)close);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_setCloseCallback,
    "DatapanelGUI::setCloseCallback",
    KenshiLib::GetRealAddress(&DatapanelGUI::setCloseCallback),
    DatapanelGUI_setCloseCallback_hook, DatapanelGUI_setCloseCallback_orig)

static void (*DatapanelGUI_NV_setAutomaticRefresh_orig)(DatapanelGUI*, bool) = NULL;
static void DatapanelGUI_NV_setAutomaticRefresh_hook(DatapanelGUI* thisptr, bool on)
{
    DatapanelGUI_NV_setAutomaticRefresh_orig(thisptr, on);
    CallDatapanelGUISetAutomaticRefreshCallbacks(thisptr, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_NV_setAutomaticRefresh,
    "DatapanelGUI::_NV_setAutomaticRefresh",
    KenshiLib::GetRealAddress(&DatapanelGUI::_NV_setAutomaticRefresh),
    DatapanelGUI_NV_setAutomaticRefresh_hook, DatapanelGUI_NV_setAutomaticRefresh_orig)

static void (*DatapanelGUI_NV_setAutomaticTargeting_orig)(DatapanelGUI*, bool) = NULL;
static void DatapanelGUI_NV_setAutomaticTargeting_hook(DatapanelGUI* thisptr, bool on)
{
    DatapanelGUI_NV_setAutomaticTargeting_orig(thisptr, on);
    CallDatapanelGUISetAutomaticTargetingCallbacks(thisptr, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_NV_setAutomaticTargeting,
    "DatapanelGUI::_NV_setAutomaticTargeting",
    KenshiLib::GetRealAddress(&DatapanelGUI::_NV_setAutomaticTargeting),
    DatapanelGUI_NV_setAutomaticTargeting_hook, DatapanelGUI_NV_setAutomaticTargeting_orig)

static DataPanelLine* (*DatapanelGUI_NV__zeroLines_orig)(DatapanelGUI*, int) = NULL;
static DataPanelLine* DatapanelGUI_NV__zeroLines_hook(DatapanelGUI* thisptr, int cat)
{
    DataPanelLine* res = DatapanelGUI_NV__zeroLines_orig(thisptr, cat);
    CallDatapanelGUIZeroLinesCallbacks(thisptr, cat, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_NV__zeroLines,
    "DatapanelGUI::_NV__zeroLines",
    KenshiLib::GetRealAddress(&DatapanelGUI::_NV__zeroLines),
    DatapanelGUI_NV__zeroLines_hook, DatapanelGUI_NV__zeroLines_orig)

static DataPanelLine* (*DatapanelGUI_setLineStatInfo_orig)(DatapanelGUI*, const std::string&, const std::string&, int) = NULL;
static DataPanelLine* DatapanelGUI_setLineStatInfo_hook(DatapanelGUI* thisptr, const std::string& s1, const std::string& s2, int category)
{
    DataPanelLine* res = DatapanelGUI_setLineStatInfo_orig(thisptr, s1, s2, category);
    CallDatapanelGUISetLineStatInfoCallbacks(thisptr, s1, s2, category, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_setLineStatInfo,
    "DatapanelGUI::setLineStatInfo",
    KenshiLib::GetRealAddress(&DatapanelGUI::setLineStatInfo),
    DatapanelGUI_setLineStatInfo_hook, DatapanelGUI_setLineStatInfo_orig)

static DataPanelLine_Faction* (*DatapanelGUI_setLineFaction_orig)(DatapanelGUI*, const std::string&, const std::string&, int, float, float) = NULL;
static DataPanelLine_Faction* DatapanelGUI_setLineFaction_hook(DatapanelGUI* thisptr, const std::string& s1, const std::string& s2, int category, float v1, float v2)
{
    DataPanelLine_Faction* res = DatapanelGUI_setLineFaction_orig(thisptr, s1, s2, category, v1, v2);
    CallDatapanelGUISetLineFactionCallbacks(thisptr, s1, s2, category, v1, v2, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_setLineFaction,
    "DatapanelGUI::setLineFaction",
    KenshiLib::GetRealAddress(&DatapanelGUI::setLineFaction),
    DatapanelGUI_setLineFaction_hook, DatapanelGUI_setLineFaction_orig)

static DataPanelLine_Button* (*DatapanelGUI_setLineTextButton_orig)(DatapanelGUI*, const std::string&, const std::string&, int, float, const std::string&) = NULL;
static DataPanelLine_Button* DatapanelGUI_setLineTextButton_hook(DatapanelGUI* thisptr, const std::string& text, const std::string& caption, int category, float buttonWidth, const std::string& skin)
{
    DataPanelLine_Button* res = DatapanelGUI_setLineTextButton_orig(thisptr, text, caption, category, buttonWidth, skin);
    CallDatapanelGUISetLineTextButtonCallbacks(thisptr, text, caption, category, buttonWidth, skin, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_setLineTextButton,
    "DatapanelGUI::setLineTextButton",
    KenshiLib::GetRealAddress(&DatapanelGUI::setLineTextButton),
    DatapanelGUI_setLineTextButton_hook, DatapanelGUI_setLineTextButton_orig)

static DataPanelLine_Button* (*DatapanelGUI_setLineButton_orig)(DatapanelGUI*, const std::string&, const std::string&, int) = NULL;
static DataPanelLine_Button* DatapanelGUI_setLineButton_hook(DatapanelGUI* thisptr, const std::string& key, const std::string& caption, int category)
{
    DataPanelLine_Button* res = DatapanelGUI_setLineButton_orig(thisptr, key, caption, category);
    CallDatapanelGUISetLineButtonCallbacks(thisptr, key, caption, category, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_setLineButton,
    "DatapanelGUI::setLineButton",
    KenshiLib::GetRealAddress(&DatapanelGUI::setLineButton),
    DatapanelGUI_setLineButton_hook, DatapanelGUI_setLineButton_orig)

static DataPanelLine_Button* (*DatapanelGUI_setLineToggleButton_orig)(DatapanelGUI*, const std::string&, const std::string&, int) = NULL;
static DataPanelLine_Button* DatapanelGUI_setLineToggleButton_hook(DatapanelGUI* thisptr, const std::string& key, const std::string& caption, int category)
{
    DataPanelLine_Button* res = DatapanelGUI_setLineToggleButton_orig(thisptr, key, caption, category);
    CallDatapanelGUISetLineToggleButtonCallbacks(thisptr, key, caption, category, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_setLineToggleButton,
    "DatapanelGUI::setLineToggleButton",
    KenshiLib::GetRealAddress(&DatapanelGUI::setLineToggleButton),
    DatapanelGUI_setLineToggleButton_hook, DatapanelGUI_setLineToggleButton_orig)

static DataPanelLine_SliderEditable* (*DatapanelGUI_setLineSliderEditable_orig)(DatapanelGUI*, const std::string&, int, bool, float, float, float*) = NULL;
static DataPanelLine_SliderEditable* DatapanelGUI_setLineSliderEditable_hook(DatapanelGUI* thisptr, const std::string& key, int category, bool showName, float min, float max, float* value)
{
    DataPanelLine_SliderEditable* res = DatapanelGUI_setLineSliderEditable_orig(thisptr, key, category, showName, min, max, value);
    CallDatapanelGUISetLineSliderEditableCallbacks(thisptr, key, category, showName, min, max, (void*)value, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_setLineSliderEditable,
    "DatapanelGUI::setLineSliderEditable",
    KenshiLib::GetRealAddress(&DatapanelGUI::setLineSliderEditable),
    DatapanelGUI_setLineSliderEditable_hook, DatapanelGUI_setLineSliderEditable_orig)

static DataPanelLine_Text* (*DatapanelGUI_setLineText_orig)(DatapanelGUI*, const std::string&, const std::string&, int, bool, const MyGUI::Align&) = NULL;
static DataPanelLine_Text* DatapanelGUI_setLineText_hook(DatapanelGUI* thisptr, const std::string& key, const std::string& caption, int category, bool wordWrap, const MyGUI::Align& textAlign)
{
    DataPanelLine_Text* res = DatapanelGUI_setLineText_orig(thisptr, key, caption, category, wordWrap, textAlign);
    CallDatapanelGUISetLineTextCallbacks(thisptr, key, caption, category, wordWrap, textAlign.getValue(), res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_setLineText,
    "DatapanelGUI::setLineText",
    KenshiLib::GetRealAddress(&DatapanelGUI::setLineText),
    DatapanelGUI_setLineText_hook, DatapanelGUI_setLineText_orig)

static DataPanelLine_TextEditable* (*DatapanelGUI_setLineTextEditable_orig)(DatapanelGUI*, const std::string&, const std::string&, int, bool, bool, const MyGUI::Align&, float) = NULL;
static DataPanelLine_TextEditable* DatapanelGUI_setLineTextEditable_hook(DatapanelGUI* thisptr, const std::string& key, const std::string& text, int category, bool showKey, bool multiLine, const MyGUI::Align& textAlign, float width)
{
    DataPanelLine_TextEditable* res = DatapanelGUI_setLineTextEditable_orig(thisptr, key, text, category, showKey, multiLine, textAlign, width);
    CallDatapanelGUISetLineTextEditableCallbacks(thisptr, key, text, category, showKey, multiLine, textAlign.getValue(), width, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_setLineTextEditable,
    "DatapanelGUI::setLineTextEditable",
    KenshiLib::GetRealAddress(&DatapanelGUI::setLineTextEditable),
    DatapanelGUI_setLineTextEditable_hook, DatapanelGUI_setLineTextEditable_orig)

static DataPanelLine_Slider* (*DatapanelGUI_setLineSlider_orig)(DatapanelGUI*, const std::string&, const std::string&, float, float, int, float*, float) = NULL;
static DataPanelLine_Slider* DatapanelGUI_setLineSlider_hook(DatapanelGUI* thisptr, const std::string& key, const std::string& caption, float min, float max, int category, float* value, float scale)
{
    DataPanelLine_Slider* res = DatapanelGUI_setLineSlider_orig(thisptr, key, caption, min, max, category, value, scale);
    CallDatapanelGUISetLineSliderCallbacks(thisptr, key, caption, min, max, category, (void*)value, scale, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_setLineSlider,
    "DatapanelGUI::setLineSlider",
    KenshiLib::GetRealAddress(&DatapanelGUI::setLineSlider),
    DatapanelGUI_setLineSlider_hook, DatapanelGUI_setLineSlider_orig)

static DataPanelLine_Progress* (*DatapanelGUI_setLineProgress_orig)(DatapanelGUI*, const std::string&, int, float, const std::string&, bool) = NULL;
static DataPanelLine_Progress* DatapanelGUI_setLineProgress_hook(DatapanelGUI* thisptr, const std::string& key, int category, float progressValue, const std::string& progressText, bool showKey)
{
    DataPanelLine_Progress* res = DatapanelGUI_setLineProgress_orig(thisptr, key, category, progressValue, progressText, showKey);
    CallDatapanelGUISetLineProgressCallbacks(thisptr, key, category, progressValue, progressText, showKey, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_setLineProgress,
    "DatapanelGUI::setLineProgress",
    KenshiLib::GetRealAddress(&DatapanelGUI::setLineProgress),
    DatapanelGUI_setLineProgress_hook, DatapanelGUI_setLineProgress_orig)

static void (*DatapanelGUI_removeLine_orig)(DatapanelGUI*, const std::string&, int) = NULL;
static void DatapanelGUI_removeLine_hook(DatapanelGUI* thisptr, const std::string& s1, int category)
{
    DatapanelGUI_removeLine_orig(thisptr, s1, category);
    CallDatapanelGUIRemoveLineCallbacks(thisptr, s1, category);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_removeLine,
    "DatapanelGUI::removeLine",
    KenshiLib::GetRealAddress(&DatapanelGUI::removeLine),
    DatapanelGUI_removeLine_hook, DatapanelGUI_removeLine_orig)

static DataPanelLine_CheckBox* (*DatapanelGUI_setLineCheckbox_orig)(DatapanelGUI*, const std::string&, bool*, int) = NULL;
static DataPanelLine_CheckBox* DatapanelGUI_setLineCheckbox_hook(DatapanelGUI* thisptr, const std::string& s1, bool* val, int category)
{
    DataPanelLine_CheckBox* res = DatapanelGUI_setLineCheckbox_orig(thisptr, s1, val, category);
    CallDatapanelGUISetLineCheckboxCallbacks(thisptr, s1, (void*)val, category, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_setLineCheckbox,
    "DatapanelGUI::setLineCheckbox",
    KenshiLib::GetRealAddress(&DatapanelGUI::setLineCheckbox),
    DatapanelGUI_setLineCheckbox_hook, DatapanelGUI_setLineCheckbox_orig)

static DataPanelLine_DropBox* (*DatapanelGUI_setLineDropBox_orig)(DatapanelGUI*, const std::string&, int, int*, bool, float) = NULL;
static DataPanelLine_DropBox* DatapanelGUI_setLineDropBox_hook(DatapanelGUI* thisptr, const std::string& key, int category, int* valPtr, bool goBox, float width)
{
    DataPanelLine_DropBox* res = DatapanelGUI_setLineDropBox_orig(thisptr, key, category, valPtr, goBox, width);
    CallDatapanelGUISetLineDropBoxCallbacks(thisptr, key, category, (void*)valPtr, goBox, width, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_setLineDropBox,
    "DatapanelGUI::setLineDropBox",
    KenshiLib::GetRealAddress(&DatapanelGUI::setLineDropBox),
    DatapanelGUI_setLineDropBox_hook, DatapanelGUI_setLineDropBox_orig)

static void (*DatapanelGUI_addSpace_orig)(DatapanelGUI*, int, float) = NULL;
static void DatapanelGUI_addSpace_hook(DatapanelGUI* thisptr, int category, float h)
{
    DatapanelGUI_addSpace_orig(thisptr, category, h);
    CallDatapanelGUIAddSpaceCallbacks(thisptr, category, h);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_addSpace,
    "DatapanelGUI::addSpace",
    KenshiLib::GetRealAddress(&DatapanelGUI::addSpace),
    DatapanelGUI_addSpace_hook, DatapanelGUI_addSpace_orig)

static void (*DatapanelGUI_setLines_orig)(DatapanelGUI*, const lektor<StringPair>&, int) = NULL;
static void DatapanelGUI_setLines_hook(DatapanelGUI* thisptr, const lektor<StringPair>& data, int category)
{
    DatapanelGUI_setLines_orig(thisptr, data, category);
    CallDatapanelGUISetLinesCallbacks(thisptr, data, category);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_setLines,
    "DatapanelGUI::setLines",
    KenshiLib::GetRealAddress(&DatapanelGUI::setLines),
    DatapanelGUI_setLines_hook, DatapanelGUI_setLines_orig)

static void (*DatapanelGUI_NV_setCategoryIcon_orig)(DatapanelGUI*, int, const std::string&) = NULL;
static void DatapanelGUI_NV_setCategoryIcon_hook(DatapanelGUI* thisptr, int cat, const std::string& image)
{
    DatapanelGUI_NV_setCategoryIcon_orig(thisptr, cat, image);
    CallDatapanelGUISetCategoryIconCallbacks(thisptr, cat, image);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_NV_setCategoryIcon,
    "DatapanelGUI::_NV_setCategoryIcon",
    KenshiLib::GetRealAddress(&DatapanelGUI::_NV_setCategoryIcon),
    DatapanelGUI_NV_setCategoryIcon_hook, DatapanelGUI_NV_setCategoryIcon_orig)

static void (*DatapanelGUI_NV_changeCategory_orig)(DatapanelGUI*, int) = NULL;
static void DatapanelGUI_NV_changeCategory_hook(DatapanelGUI* thisptr, int cat)
{
    DatapanelGUI_NV_changeCategory_orig(thisptr, cat);
    CallDatapanelGUIChangeCategoryCallbacks(thisptr, cat);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_NV_changeCategory,
    "DatapanelGUI::_NV_changeCategory",
    KenshiLib::GetRealAddress(&DatapanelGUI::_NV_changeCategory),
    DatapanelGUI_NV_changeCategory_hook, DatapanelGUI_NV_changeCategory_orig)

static void (*DatapanelGUI_addCustomLine_orig)(DatapanelGUI*, DataPanelLine*) = NULL;
static void DatapanelGUI_addCustomLine_hook(DatapanelGUI* thisptr, DataPanelLine* line)
{
    DatapanelGUI_addCustomLine_orig(thisptr, line);
    CallDatapanelGUIAddCustomLineCallbacks(thisptr, line);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_addCustomLine,
    "DatapanelGUI::addCustomLine",
    KenshiLib::GetRealAddress(&DatapanelGUI::addCustomLine),
    DatapanelGUI_addCustomLine_hook, DatapanelGUI_addCustomLine_orig)

static void (*DatapanelGUI_NV_autoChangeSelectedObject_orig)(DatapanelGUI*, const hand&) = NULL;
static void DatapanelGUI_NV_autoChangeSelectedObject_hook(DatapanelGUI* thisptr, const hand& obj)
{
    DatapanelGUI_NV_autoChangeSelectedObject_orig(thisptr, obj);
    CallDatapanelGUIAutoChangeSelectedObjectCallbacks(thisptr, obj);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_NV_autoChangeSelectedObject,
    "DatapanelGUI::_NV_autoChangeSelectedObject",
    KenshiLib::GetRealAddress(&DatapanelGUI::_NV_autoChangeSelectedObject),
    DatapanelGUI_NV_autoChangeSelectedObject_hook, DatapanelGUI_NV_autoChangeSelectedObject_orig)

static void (*DatapanelGUI_NV_setObject_orig)(DatapanelGUI*, const hand&) = NULL;
static void DatapanelGUI_NV_setObject_hook(DatapanelGUI* thisptr, const hand& obj)
{
    DatapanelGUI_NV_setObject_orig(thisptr, obj);
    CallDatapanelGUISetObjectCallbacks(thisptr, obj);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_NV_setObject,
    "DatapanelGUI::_NV_setObject",
    KenshiLib::GetRealAddress(&DatapanelGUI::_NV_setObject),
    DatapanelGUI_NV_setObject_hook, DatapanelGUI_NV_setObject_orig)

static void (*DatapanelGUI_NV_setLineSpacing_orig)(DatapanelGUI*, float) = NULL;
static void DatapanelGUI_NV_setLineSpacing_hook(DatapanelGUI* thisptr, float numLinesPerScreen)
{
    DatapanelGUI_NV_setLineSpacing_orig(thisptr, numLinesPerScreen);
    CallDatapanelGUISetLineSpacingCallbacks(thisptr, numLinesPerScreen);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_NV_setLineSpacing,
    "DatapanelGUI::_NV_setLineSpacing",
    KenshiLib::GetRealAddress(&DatapanelGUI::_NV_setLineSpacing),
    DatapanelGUI_NV_setLineSpacing_hook, DatapanelGUI_NV_setLineSpacing_orig)

static DataPanelLine* (*DatapanelGUI_NV_getLine_orig)(DatapanelGUI*, const std::string&, int) = NULL;
static DataPanelLine* DatapanelGUI_NV_getLine_hook(DatapanelGUI* thisptr, const std::string& key, int cat)
{
    DataPanelLine* res = DatapanelGUI_NV_getLine_orig(thisptr, key, cat);
    DataPanelLine* overrideRes = CallDatapanelGUIGetLineCallbacks(thisptr, key, cat, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_NV_getLine,
    "DatapanelGUI::_NV_getLine",
    KenshiLib::GetRealAddress(&DatapanelGUI::_NV_getLine),
    DatapanelGUI_NV_getLine_hook, DatapanelGUI_NV_getLine_orig)

static bool (*DatapanelGUI_lineExists_orig)(DatapanelGUI*, const std::string&, int) = NULL;
static bool DatapanelGUI_lineExists_hook(DatapanelGUI* thisptr, const std::string& key, int cat)
{
    bool res = DatapanelGUI_lineExists_orig(thisptr, key, cat);
    return CallDatapanelGUILineExistsCallbacks(thisptr, key, cat, res);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_lineExists,
    "DatapanelGUI::lineExists",
    KenshiLib::GetRealAddress(&DatapanelGUI::lineExists),
    DatapanelGUI_lineExists_hook, DatapanelGUI_lineExists_orig)

static void (*DatapanelGUI_tabButton_orig)(DatapanelGUI*, MyGUI::Widget*, int, int, MyGUI::MouseButton) = NULL;
static void DatapanelGUI_tabButton_hook(DatapanelGUI* thisptr, MyGUI::Widget* sender, int arg2, int arg3, MyGUI::MouseButton arg4)
{
    DatapanelGUI_tabButton_orig(thisptr, sender, arg2, arg3, arg4);
    CallDatapanelGUITabButtonCallbacks(thisptr, sender, arg2, arg3, arg4.getValue());
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_tabButton,
    "DatapanelGUI::tabButton",
    KenshiLib::GetRealAddress(&DatapanelGUI::tabButton),
    DatapanelGUI_tabButton_hook, DatapanelGUI_tabButton_orig)

static int (*DatapanelGUI_getNumLines_orig)(DatapanelGUI*, int) = NULL;
static int DatapanelGUI_getNumLines_hook(DatapanelGUI* thisptr, int cat)
{
    int res = DatapanelGUI_getNumLines_orig(thisptr, cat);
    return CallDatapanelGUIGetNumLinesCallbacks(thisptr, cat, res);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_getNumLines,
    "DatapanelGUI::getNumLines",
    KenshiLib::GetRealAddress(&DatapanelGUI::getNumLines),
    DatapanelGUI_getNumLines_hook, DatapanelGUI_getNumLines_orig)

static DataPanelLine* (*DatapanelGUI_getLineByNum_orig)(DatapanelGUI*, int, int) = NULL;
static DataPanelLine* DatapanelGUI_getLineByNum_hook(DatapanelGUI* thisptr, int cat, int i)
{
    DataPanelLine* res = DatapanelGUI_getLineByNum_orig(thisptr, cat, i);
    DataPanelLine* overrideRes = CallDatapanelGUIGetLineByNumCallbacks(thisptr, cat, i, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_getLineByNum,
    "DatapanelGUI::getLineByNum",
    KenshiLib::GetRealAddress(&DatapanelGUI::getLineByNum),
    DatapanelGUI_getLineByNum_hook, DatapanelGUI_getLineByNum_orig)

static void (*DatapanelGUI_DESTRUCTOR_orig)(DatapanelGUI*) = NULL;
static void DatapanelGUI_DESTRUCTOR_hook(DatapanelGUI* thisptr)
{
    CallDatapanelGUIDestructorCallbacks(thisptr);
    DatapanelGUI_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_DESTRUCTOR,
    "DatapanelGUI::_DESTRUCTOR",
    KenshiLib::GetRealAddress(&DatapanelGUI::_DESTRUCTOR),
    DatapanelGUI_DESTRUCTOR_hook, DatapanelGUI_DESTRUCTOR_orig)

static DataPanelLine* (*DatapanelGUI_createLine_orig)(DatapanelGUI*, DataPanelLine*, int, bool) = NULL;
static DataPanelLine* DatapanelGUI_createLine_hook(DatapanelGUI* thisptr, DataPanelLine* line, int category, bool lastLine)
{
    DataPanelLine* res = DatapanelGUI_createLine_orig(thisptr, line, category, lastLine);
    CallDatapanelGUICreateLineCallbacks(thisptr, line, category, lastLine, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_createLine,
    "DatapanelGUI::createLine",
    KenshiLib::GetRealAddress(&DatapanelGUI::createLine),
    DatapanelGUI_createLine_hook, DatapanelGUI_createLine_orig)

static float (*DatapanelGUI_getNextVerticalPos_orig)(DatapanelGUI*, int) = NULL;
static float DatapanelGUI_getNextVerticalPos_hook(DatapanelGUI* thisptr, int category)
{
    float res = DatapanelGUI_getNextVerticalPos_orig(thisptr, category);
    return CallDatapanelGUIGetNextVerticalPosCallbacks(thisptr, category, res);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_getNextVerticalPos,
    "DatapanelGUI::getNextVerticalPos",
    KenshiLib::GetRealAddress(&DatapanelGUI::getNextVerticalPos),
    DatapanelGUI_getNextVerticalPos_hook, DatapanelGUI_getNextVerticalPos_orig)

static void (*DatapanelGUI_closeButtonCallback_orig)(DatapanelGUI*, MyGUI::Window*, const std::string&) = NULL;
static void DatapanelGUI_closeButtonCallback_hook(DatapanelGUI* thisptr, MyGUI::Window* arg1, const std::string& arg2)
{
    CallDatapanelGUICloseButtonCallbackCallbacks(thisptr, arg1, arg2);
    DatapanelGUI_closeButtonCallback_orig(thisptr, arg1, arg2);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_closeButtonCallback,
    "DatapanelGUI::closeButtonCallback",
    KenshiLib::GetRealAddress(&DatapanelGUI::closeButtonCallback),
    DatapanelGUI_closeButtonCallback_hook, DatapanelGUI_closeButtonCallback_orig)

static void (*DatapanelGUI_mouseOverCallback_orig)(DatapanelGUI*, MyGUI::Widget*) = NULL;
static void DatapanelGUI_mouseOverCallback_hook(DatapanelGUI* thisptr, MyGUI::Widget* sender)
{
    DatapanelGUI_mouseOverCallback_orig(thisptr, sender);
    CallDatapanelGUIMouseOverCallbackCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_mouseOverCallback,
    "DatapanelGUI::mouseOverCallback",
    KenshiLib::GetRealAddress(&DatapanelGUI::mouseOverCallback),
    DatapanelGUI_mouseOverCallback_hook, DatapanelGUI_mouseOverCallback_orig)

static void (*DatapanelGUI_notifyMouseWheel_orig)(DatapanelGUI*, MyGUI::Widget*, int) = NULL;
static void DatapanelGUI_notifyMouseWheel_hook(DatapanelGUI* thisptr, MyGUI::Widget* sender, int rel)
{
    DatapanelGUI_notifyMouseWheel_orig(thisptr, sender, rel);
    CallDatapanelGUINotifyMouseWheelCallbacks(thisptr, sender, rel);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_notifyMouseWheel,
    "DatapanelGUI::notifyMouseWheel",
    KenshiLib::GetRealAddress(&DatapanelGUI::notifyMouseWheel),
    DatapanelGUI_notifyMouseWheel_hook, DatapanelGUI_notifyMouseWheel_orig)

static MyGUI::types::TCoord<int>* (*DatapanelGUI_getCoords_orig)(DatapanelGUI*, MyGUI::types::TCoord<int>*, float, float, float, float) = NULL;
static MyGUI::types::TCoord<int>* DatapanelGUI_getCoords_hook(DatapanelGUI* thisptr, MyGUI::types::TCoord<int>* ret, float left, float top, float width, float height)
{
    MyGUI::types::TCoord<int>* res = DatapanelGUI_getCoords_orig(thisptr, ret, left, top, width, height);
    CallDatapanelGUIGetCoordsCallbacks(thisptr, left, top, width, height, *res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_getCoords,
    "DatapanelGUI::getCoords",
    KenshiLib::GetRealAddress(&DatapanelGUI::getCoords),
    DatapanelGUI_getCoords_hook, DatapanelGUI_getCoords_orig)

static bool (*DatapanelGUI_dataExists_orig)(DatapanelGUI*, int, const std::string&) = NULL;
static bool DatapanelGUI_dataExists_hook(DatapanelGUI* thisptr, int cat, const std::string& name)
{
    bool res = DatapanelGUI_dataExists_orig(thisptr, cat, name);
    return CallDatapanelGUIDataExistsCallbacks(thisptr, cat, name, res);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_dataExists,
    "DatapanelGUI::dataExists",
    KenshiLib::GetRealAddress(&DatapanelGUI::dataExists),
    DatapanelGUI_dataExists_hook, DatapanelGUI_dataExists_orig)

static void (*DatapanelGUI_clearCategoryTabs_orig)(DatapanelGUI*) = NULL;
static void DatapanelGUI_clearCategoryTabs_hook(DatapanelGUI* thisptr)
{
    DatapanelGUI_clearCategoryTabs_orig(thisptr);
    CallDatapanelGUIClearCategoryTabsCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DatapanelGUI_clearCategoryTabs,
    "DatapanelGUI::clearCategoryTabs",
    KenshiLib::GetRealAddress(&DatapanelGUI::clearCategoryTabs),
    DatapanelGUI_clearCategoryTabs_hook, DatapanelGUI_clearCategoryTabs_orig)
