#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/gui/DataPanelLine.h>
#include <kenshi/gui/MyGUI_Slider.h> // DataPanelLine.h only forward-declares MyGUI::Slider

// ---------------------------------------------------------------------------
// Hooks for DataPanelLine.h
//
// Non-virtual members and the _NV_ bodies of virtual members. Events fire after
// the original call unless noted; getters pass the original result as
// defaultVal and accept an override from Lua.
//
// Not hooked:
//   DataPanelLine::_CONSTRUCTOR(MyGUI::TextBox*, MyGUI::TextBox*, MyGUI::Button*, int)
//     overloaded; overloads are not hooked
//   DataPanelLine::_CONSTRUCTOR(const std::string&, const std::string&, int, const std::string&, const std::string&)
//     overloaded; overloads are not hooked
//   DataPanelLine::_CONSTRUCTOR(const std::string&, const std::string&, const std::string&, int, const std::string&, const std::string&)
//     overloaded; overloads are not hooked
//   DataPanelLine::_NV_updateValuePtr(void*)
//     RVA 0x402EE0 lies outside the class code; possibly an identical-code-folded copy shared with other functions (unverified)
//   DataPanelLine::_NV_setToolTip(const std::string&)
//     overloaded; overloads are not hooked
//   DataPanelLine::_NV_setToolTip(const std::string&, ToolTip*)
//     overloaded; overloads are not hooked
//   DataPanelLine::_NV_setToolTipMainBar(const std::string&, bool)
//     overloaded; overloads are not hooked
//   DataPanelLine::_NV_setToolTipMainBar(const lektor<StringPair>&, bool)
//     overloaded; overloads are not hooked
//   DataPanelLine::getType() const
//     RVA 0x3E6B30 lies outside the class code; possibly an identical-code-folded copy shared with other functions (unverified)
//   DataPanelLine::_NV_getUserData()
//     RVA 0x402EF0 lies outside the class code; possibly an identical-code-folded copy shared with other functions (unverified)
//   DataPanelLine::getNumWidgets() const
//     RVA 0x978B00 lies outside the class code; possibly an identical-code-folded copy shared with other functions (unverified)
//   DataPanelLine::getWidget(int) const
//     RVA 0x978B20 lies outside the class code; possibly an identical-code-folded copy shared with other functions (unverified)
//   DataPanelLine_Research::_NV_setToolTipMainBar(const std::string&, bool)
//     overloaded; overloads are not hooked
//   DataPanelLine_Research::_NV_setToolTipMainBar(const lektor<StringPair>&, bool)
//     overloaded; overloads are not hooked
//   DataPanelLine_Button::_NV_setToolTipMainBar(const std::string&, bool)
//     overloaded; overloads are not hooked
//   DataPanelLine_Button::_NV_setToolTipMainBar(const lektor<StringPair>&, bool)
//     overloaded; overloads are not hooked
//   DataPanelLine_SliderEditable::getSlider()
//     RVA 0x780920 lies outside the class code; possibly an identical-code-folded copy shared with other functions (unverified)
//   DataPanelLine_SliderEditable::getEditBox()
//     RVA 0x780930 lies outside the class code; possibly an identical-code-folded copy shared with other functions (unverified)
//   DataPanelLine_TextEditable::getEditBox()
//     RVA 0x111C70 lies outside the class code; possibly an identical-code-folded copy shared with other functions (unverified)
//   DataPanelLine_TextEditable::getNameBox()
//     RVA 0x96BC50 lies outside the class code; possibly an identical-code-folded copy shared with other functions (unverified)
//   DataPanelLine_CheckBox::getTextBox() const
//     RVA 0x911610 lies outside the class code; possibly an identical-code-folded copy shared with other functions (unverified)
//   DataPanelLine_CheckBox::getCheckBox() const
//     RVA 0x780910 lies outside the class code; possibly an identical-code-folded copy shared with other functions (unverified)
//   DataPanelLine_DropBox::getComboBox()
//     RVA 0x4A6DE0 lies outside the class code; possibly an identical-code-folded copy shared with other functions (unverified)
// ---------------------------------------------------------------------------

static void (*DataPanelLine_DESTRUCTOR_orig)(DataPanelLine*) = NULL;
static void DataPanelLine_DESTRUCTOR_hook(DataPanelLine* thisptr)
{
    CallDataPanelLineDestructorCallbacks(thisptr);
    DataPanelLine_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_DESTRUCTOR,
    "DataPanelLine::_DESTRUCTOR",
    KenshiLib::GetRealAddress(&DataPanelLine::_DESTRUCTOR),
    DataPanelLine_DESTRUCTOR_hook, DataPanelLine_DESTRUCTOR_orig)

static void (*DataPanelLine_NV_setVisible_orig)(DataPanelLine*, bool) = NULL;
static void DataPanelLine_NV_setVisible_hook(DataPanelLine* thisptr, bool on)
{
    DataPanelLine_NV_setVisible_orig(thisptr, on);
    CallDataPanelLineSetVisibleCallbacks(thisptr, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_NV_setVisible,
    "DataPanelLine::_NV_setVisible",
    KenshiLib::GetRealAddress(&DataPanelLine::_NV_setVisible),
    DataPanelLine_NV_setVisible_hook, DataPanelLine_NV_setVisible_orig)

static void (*DataPanelLine_NV_setEnabled_orig)(DataPanelLine*, bool) = NULL;
static void DataPanelLine_NV_setEnabled_hook(DataPanelLine* thisptr, bool on)
{
    DataPanelLine_NV_setEnabled_orig(thisptr, on);
    CallDataPanelLineSetEnabledCallbacks(thisptr, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_NV_setEnabled,
    "DataPanelLine::_NV_setEnabled",
    KenshiLib::GetRealAddress(&DataPanelLine::_NV_setEnabled),
    DataPanelLine_NV_setEnabled_hook, DataPanelLine_NV_setEnabled_orig)

static void (*DataPanelLine_NV_refresh_orig)(DataPanelLine*) = NULL;
static void DataPanelLine_NV_refresh_hook(DataPanelLine* thisptr)
{
    DataPanelLine_NV_refresh_orig(thisptr);
    CallDataPanelLineRefreshCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_NV_refresh,
    "DataPanelLine::_NV_refresh",
    KenshiLib::GetRealAddress(&DataPanelLine::_NV_refresh),
    DataPanelLine_NV_refresh_hook, DataPanelLine_NV_refresh_orig)

static void (*DataPanelLine_NV_createMe_orig)(DataPanelLine*, DatapanelGUI*, float, bool) = NULL;
static void DataPanelLine_NV_createMe_hook(DataPanelLine* thisptr, DatapanelGUI* parent, float top, bool lastLine)
{
    DataPanelLine_NV_createMe_orig(thisptr, parent, top, lastLine);
    CallDataPanelLineCreateMeCallbacks(thisptr, parent, top, lastLine);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_NV_createMe,
    "DataPanelLine::_NV_createMe",
    KenshiLib::GetRealAddress(&DataPanelLine::_NV_createMe),
    DataPanelLine_NV_createMe_hook, DataPanelLine_NV_createMe_orig)

static void (*DataPanelLine_NV_resize_orig)(DataPanelLine*, int, int) = NULL;
static void DataPanelLine_NV_resize_hook(DataPanelLine* thisptr, int width, int height)
{
    DataPanelLine_NV_resize_orig(thisptr, width, height);
    CallDataPanelLineResizeCallbacks(thisptr, width, height);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_NV_resize,
    "DataPanelLine::_NV_resize",
    KenshiLib::GetRealAddress(&DataPanelLine::_NV_resize),
    DataPanelLine_NV_resize_hook, DataPanelLine_NV_resize_orig)

static int (*DataPanelLine_NV_getBottom_orig)(DataPanelLine*) = NULL;
static int DataPanelLine_NV_getBottom_hook(DataPanelLine* thisptr)
{
    int res = DataPanelLine_NV_getBottom_orig(thisptr);
    return CallDataPanelLineGetBottomCallbacks(thisptr, res);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_NV_getBottom,
    "DataPanelLine::_NV_getBottom",
    KenshiLib::GetRealAddress(&DataPanelLine::_NV_getBottom),
    DataPanelLine_NV_getBottom_hook, DataPanelLine_NV_getBottom_orig)

static DataPanelLine_Faction* (*DataPanelLine_Faction_CONSTRUCTOR_orig)(DataPanelLine_Faction*, const std::string&, const std::string&, int, float, float) = NULL;
static DataPanelLine_Faction* DataPanelLine_Faction_CONSTRUCTOR_hook(DataPanelLine_Faction* thisptr, const std::string& a, const std::string& b, int cat, float vv1, float vv2)
{
    DataPanelLine_Faction* res = DataPanelLine_Faction_CONSTRUCTOR_orig(thisptr, a, b, cat, vv1, vv2);
    CallDataPanelLineFactionConstructedCallbacks(thisptr, a, b, cat, vv1, vv2);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Faction_CONSTRUCTOR,
    "DataPanelLine_Faction::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&DataPanelLine_Faction::_CONSTRUCTOR),
    DataPanelLine_Faction_CONSTRUCTOR_hook, DataPanelLine_Faction_CONSTRUCTOR_orig)

static void (*DataPanelLine_Faction_NV_createMe_orig)(DataPanelLine_Faction*, DatapanelGUI*, float, bool) = NULL;
static void DataPanelLine_Faction_NV_createMe_hook(DataPanelLine_Faction* thisptr, DatapanelGUI* parent, float top, bool lastLine)
{
    DataPanelLine_Faction_NV_createMe_orig(thisptr, parent, top, lastLine);
    CallDataPanelLineFactionCreateMeCallbacks(thisptr, parent, top, lastLine);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Faction_NV_createMe,
    "DataPanelLine_Faction::_NV_createMe",
    KenshiLib::GetRealAddress(&DataPanelLine_Faction::_NV_createMe),
    DataPanelLine_Faction_NV_createMe_hook, DataPanelLine_Faction_NV_createMe_orig)

static void (*DataPanelLine_Faction_DESTRUCTOR_orig)(DataPanelLine_Faction*) = NULL;
static void DataPanelLine_Faction_DESTRUCTOR_hook(DataPanelLine_Faction* thisptr)
{
    CallDataPanelLineFactionDestructorCallbacks(thisptr);
    DataPanelLine_Faction_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Faction_DESTRUCTOR,
    "DataPanelLine_Faction::_DESTRUCTOR",
    KenshiLib::GetRealAddress(&DataPanelLine_Faction::_DESTRUCTOR),
    DataPanelLine_Faction_DESTRUCTOR_hook, DataPanelLine_Faction_DESTRUCTOR_orig)

static DataPanelLine_Research* (*DataPanelLine_Research_CONSTRUCTOR_orig)(DataPanelLine_Research*, const std::string&, const std::string&, int, float, const std::string&, bool) = NULL;
static DataPanelLine_Research* DataPanelLine_Research_CONSTRUCTOR_hook(DataPanelLine_Research* thisptr, const std::string& a, const std::string& b, int cat, float vv1, const std::string& barColor, bool Xbut)
{
    DataPanelLine_Research* res = DataPanelLine_Research_CONSTRUCTOR_orig(thisptr, a, b, cat, vv1, barColor, Xbut);
    CallDataPanelLineResearchConstructedCallbacks(thisptr, a, b, cat, vv1, barColor, Xbut);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Research_CONSTRUCTOR,
    "DataPanelLine_Research::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&DataPanelLine_Research::_CONSTRUCTOR),
    DataPanelLine_Research_CONSTRUCTOR_hook, DataPanelLine_Research_CONSTRUCTOR_orig)

static void (*DataPanelLine_Research_NV_createMe_orig)(DataPanelLine_Research*, DatapanelGUI*, float, bool) = NULL;
static void DataPanelLine_Research_NV_createMe_hook(DataPanelLine_Research* thisptr, DatapanelGUI* parent, float top, bool lastLine)
{
    DataPanelLine_Research_NV_createMe_orig(thisptr, parent, top, lastLine);
    CallDataPanelLineResearchCreateMeCallbacks(thisptr, parent, top, lastLine);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Research_NV_createMe,
    "DataPanelLine_Research::_NV_createMe",
    KenshiLib::GetRealAddress(&DataPanelLine_Research::_NV_createMe),
    DataPanelLine_Research_NV_createMe_hook, DataPanelLine_Research_NV_createMe_orig)

static void (*DataPanelLine_Research_DESTRUCTOR_orig)(DataPanelLine_Research*) = NULL;
static void DataPanelLine_Research_DESTRUCTOR_hook(DataPanelLine_Research* thisptr)
{
    CallDataPanelLineResearchDestructorCallbacks(thisptr);
    DataPanelLine_Research_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Research_DESTRUCTOR,
    "DataPanelLine_Research::_DESTRUCTOR",
    KenshiLib::GetRealAddress(&DataPanelLine_Research::_DESTRUCTOR),
    DataPanelLine_Research_DESTRUCTOR_hook, DataPanelLine_Research_DESTRUCTOR_orig)

static DataPanelLine_Button* (*DataPanelLine_Button_CONSTRUCTOR_orig)(DataPanelLine_Button*, const std::string&, const std::string&, int, float, const std::string&) = NULL;
static DataPanelLine_Button* DataPanelLine_Button_CONSTRUCTOR_hook(DataPanelLine_Button* thisptr, const std::string& a, const std::string& b, int cat, float w, const std::string& skin)
{
    DataPanelLine_Button* res = DataPanelLine_Button_CONSTRUCTOR_orig(thisptr, a, b, cat, w, skin);
    CallDataPanelLineButtonConstructedCallbacks(thisptr, a, b, cat, w, skin);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Button_CONSTRUCTOR,
    "DataPanelLine_Button::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&DataPanelLine_Button::_CONSTRUCTOR),
    DataPanelLine_Button_CONSTRUCTOR_hook, DataPanelLine_Button_CONSTRUCTOR_orig)

static hand* (*DataPanelLine_Button_NV_getUserData_orig)(DataPanelLine_Button*, hand*) = NULL;
static hand* DataPanelLine_Button_NV_getUserData_hook(DataPanelLine_Button* thisptr, hand* ret)
{
    hand* res = DataPanelLine_Button_NV_getUserData_orig(thisptr, ret);
    CallDataPanelLineButtonGetUserDataCallbacks(thisptr, *res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Button_NV_getUserData,
    "DataPanelLine_Button::_NV_getUserData",
    KenshiLib::GetRealAddress(&DataPanelLine_Button::_NV_getUserData),
    DataPanelLine_Button_NV_getUserData_hook, DataPanelLine_Button_NV_getUserData_orig)

static void (*DataPanelLine_Button_NV_createMe_orig)(DataPanelLine_Button*, DatapanelGUI*, float, bool) = NULL;
static void DataPanelLine_Button_NV_createMe_hook(DataPanelLine_Button* thisptr, DatapanelGUI* parent, float top, bool lastLine)
{
    DataPanelLine_Button_NV_createMe_orig(thisptr, parent, top, lastLine);
    CallDataPanelLineButtonCreateMeCallbacks(thisptr, parent, top, lastLine);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Button_NV_createMe,
    "DataPanelLine_Button::_NV_createMe",
    KenshiLib::GetRealAddress(&DataPanelLine_Button::_NV_createMe),
    DataPanelLine_Button_NV_createMe_hook, DataPanelLine_Button_NV_createMe_orig)

static void (*DataPanelLine_Button_DESTRUCTOR_orig)(DataPanelLine_Button*) = NULL;
static void DataPanelLine_Button_DESTRUCTOR_hook(DataPanelLine_Button* thisptr)
{
    CallDataPanelLineButtonDestructorCallbacks(thisptr);
    DataPanelLine_Button_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Button_DESTRUCTOR,
    "DataPanelLine_Button::_DESTRUCTOR",
    KenshiLib::GetRealAddress(&DataPanelLine_Button::_DESTRUCTOR),
    DataPanelLine_Button_DESTRUCTOR_hook, DataPanelLine_Button_DESTRUCTOR_orig)

static void (*DataPanelLine_SliderEditable_setEditableValuePtr_orig)(DataPanelLine_SliderEditable*, float*, float, float) = NULL;
static void DataPanelLine_SliderEditable_setEditableValuePtr_hook(DataPanelLine_SliderEditable* thisptr, float* val, float lo, float hi)
{
    DataPanelLine_SliderEditable_setEditableValuePtr_orig(thisptr, val, lo, hi);
    CallDataPanelLineSliderEditableSetEditableValuePtrCallbacks(thisptr, (void*)val, lo, hi);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_SliderEditable_setEditableValuePtr,
    "DataPanelLine_SliderEditable::setEditableValuePtr",
    KenshiLib::GetRealAddress(&DataPanelLine_SliderEditable::setEditableValuePtr),
    DataPanelLine_SliderEditable_setEditableValuePtr_hook, DataPanelLine_SliderEditable_setEditableValuePtr_orig)

static void (*DataPanelLine_SliderEditable_NV_updateValuePtr_orig)(DataPanelLine_SliderEditable*, void*) = NULL;
static void DataPanelLine_SliderEditable_NV_updateValuePtr_hook(DataPanelLine_SliderEditable* thisptr, void* ptr)
{
    DataPanelLine_SliderEditable_NV_updateValuePtr_orig(thisptr, ptr);
    CallDataPanelLineSliderEditableUpdateValuePtrCallbacks(thisptr, (void*)ptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_SliderEditable_NV_updateValuePtr,
    "DataPanelLine_SliderEditable::_NV_updateValuePtr",
    KenshiLib::GetRealAddress(&DataPanelLine_SliderEditable::_NV_updateValuePtr),
    DataPanelLine_SliderEditable_NV_updateValuePtr_hook, DataPanelLine_SliderEditable_NV_updateValuePtr_orig)

static void (*DataPanelLine_SliderEditable_setValue_orig)(DataPanelLine_SliderEditable*, float) = NULL;
static void DataPanelLine_SliderEditable_setValue_hook(DataPanelLine_SliderEditable* thisptr, float v)
{
    DataPanelLine_SliderEditable_setValue_orig(thisptr, v);
    CallDataPanelLineSliderEditableSetValueCallbacks(thisptr, v);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_SliderEditable_setValue,
    "DataPanelLine_SliderEditable::setValue",
    KenshiLib::GetRealAddress(&DataPanelLine_SliderEditable::setValue),
    DataPanelLine_SliderEditable_setValue_hook, DataPanelLine_SliderEditable_setValue_orig)

static void (*DataPanelLine_SliderEditable_NV_refresh_orig)(DataPanelLine_SliderEditable*) = NULL;
static void DataPanelLine_SliderEditable_NV_refresh_hook(DataPanelLine_SliderEditable* thisptr)
{
    DataPanelLine_SliderEditable_NV_refresh_orig(thisptr);
    CallDataPanelLineSliderEditableRefreshCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_SliderEditable_NV_refresh,
    "DataPanelLine_SliderEditable::_NV_refresh",
    KenshiLib::GetRealAddress(&DataPanelLine_SliderEditable::_NV_refresh),
    DataPanelLine_SliderEditable_NV_refresh_hook, DataPanelLine_SliderEditable_NV_refresh_orig)

static void (*DataPanelLine_SliderEditable_setPrecision_orig)(DataPanelLine_SliderEditable*, int) = NULL;
static void DataPanelLine_SliderEditable_setPrecision_hook(DataPanelLine_SliderEditable* thisptr, int dp)
{
    DataPanelLine_SliderEditable_setPrecision_orig(thisptr, dp);
    CallDataPanelLineSliderEditableSetPrecisionCallbacks(thisptr, dp);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_SliderEditable_setPrecision,
    "DataPanelLine_SliderEditable::setPrecision",
    KenshiLib::GetRealAddress(&DataPanelLine_SliderEditable::setPrecision),
    DataPanelLine_SliderEditable_setPrecision_hook, DataPanelLine_SliderEditable_setPrecision_orig)

static DataPanelLine_SliderEditable* (*DataPanelLine_SliderEditable_CONSTRUCTOR_orig)(DataPanelLine_SliderEditable*, const std::string&, int, bool, float, float, float*) = NULL;
static DataPanelLine_SliderEditable* DataPanelLine_SliderEditable_CONSTRUCTOR_hook(DataPanelLine_SliderEditable* thisptr, const std::string& text, int category, bool showName, float min, float max, float* value)
{
    DataPanelLine_SliderEditable* res = DataPanelLine_SliderEditable_CONSTRUCTOR_orig(thisptr, text, category, showName, min, max, value);
    CallDataPanelLineSliderEditableConstructedCallbacks(thisptr, text, category, showName, min, max, (void*)value);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_SliderEditable_CONSTRUCTOR,
    "DataPanelLine_SliderEditable::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&DataPanelLine_SliderEditable::_CONSTRUCTOR),
    DataPanelLine_SliderEditable_CONSTRUCTOR_hook, DataPanelLine_SliderEditable_CONSTRUCTOR_orig)

static void (*DataPanelLine_SliderEditable_NV_createMe_orig)(DataPanelLine_SliderEditable*, DatapanelGUI*, float, bool) = NULL;
static void DataPanelLine_SliderEditable_NV_createMe_hook(DataPanelLine_SliderEditable* thisptr, DatapanelGUI* parent, float top, bool lastLine)
{
    DataPanelLine_SliderEditable_NV_createMe_orig(thisptr, parent, top, lastLine);
    CallDataPanelLineSliderEditableCreateMeCallbacks(thisptr, parent, top, lastLine);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_SliderEditable_NV_createMe,
    "DataPanelLine_SliderEditable::_NV_createMe",
    KenshiLib::GetRealAddress(&DataPanelLine_SliderEditable::_NV_createMe),
    DataPanelLine_SliderEditable_NV_createMe_hook, DataPanelLine_SliderEditable_NV_createMe_orig)

static void (*DataPanelLine_SliderEditable_editCallback_orig)(DataPanelLine_SliderEditable*, MyGUI::EditBox*) = NULL;
static void DataPanelLine_SliderEditable_editCallback_hook(DataPanelLine_SliderEditable* thisptr, MyGUI::EditBox* sender)
{
    DataPanelLine_SliderEditable_editCallback_orig(thisptr, sender);
    CallDataPanelLineSliderEditableEditCallbackCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_SliderEditable_editCallback,
    "DataPanelLine_SliderEditable::editCallback",
    KenshiLib::GetRealAddress(&DataPanelLine_SliderEditable::editCallback),
    DataPanelLine_SliderEditable_editCallback_hook, DataPanelLine_SliderEditable_editCallback_orig)

static void (*DataPanelLine_SliderEditable_sliderCallback_orig)(DataPanelLine_SliderEditable*, MyGUI::ScrollBar*, unsigned __int64) = NULL;
static void DataPanelLine_SliderEditable_sliderCallback_hook(DataPanelLine_SliderEditable* thisptr, MyGUI::ScrollBar* sender, unsigned __int64 position)
{
    DataPanelLine_SliderEditable_sliderCallback_orig(thisptr, sender, position);
    CallDataPanelLineSliderEditableSliderCallbackCallbacks(thisptr, sender, static_cast<int>(position));
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_SliderEditable_sliderCallback,
    "DataPanelLine_SliderEditable::sliderCallback",
    KenshiLib::GetRealAddress(&DataPanelLine_SliderEditable::sliderCallback),
    DataPanelLine_SliderEditable_sliderCallback_hook, DataPanelLine_SliderEditable_sliderCallback_orig)

static void (*DataPanelLine_SliderEditable_DESTRUCTOR_orig)(DataPanelLine_SliderEditable*) = NULL;
static void DataPanelLine_SliderEditable_DESTRUCTOR_hook(DataPanelLine_SliderEditable* thisptr)
{
    CallDataPanelLineSliderEditableDestructorCallbacks(thisptr);
    DataPanelLine_SliderEditable_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_SliderEditable_DESTRUCTOR,
    "DataPanelLine_SliderEditable::_DESTRUCTOR",
    KenshiLib::GetRealAddress(&DataPanelLine_SliderEditable::_DESTRUCTOR),
    DataPanelLine_SliderEditable_DESTRUCTOR_hook, DataPanelLine_SliderEditable_DESTRUCTOR_orig)

static DataPanelLine_Text* (*DataPanelLine_Text_CONSTRUCTOR_orig)(DataPanelLine_Text*, const std::string&, const std::string&, int, bool, const MyGUI::Align&) = NULL;
static DataPanelLine_Text* DataPanelLine_Text_CONSTRUCTOR_hook(DataPanelLine_Text* thisptr, const std::string& key, const std::string& text, int category, bool wordWrap, const MyGUI::Align& textAlign)
{
    DataPanelLine_Text* res = DataPanelLine_Text_CONSTRUCTOR_orig(thisptr, key, text, category, wordWrap, textAlign);
    CallDataPanelLineTextConstructedCallbacks(thisptr, key, text, category, wordWrap, textAlign.getValue());
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Text_CONSTRUCTOR,
    "DataPanelLine_Text::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&DataPanelLine_Text::_CONSTRUCTOR),
    DataPanelLine_Text_CONSTRUCTOR_hook, DataPanelLine_Text_CONSTRUCTOR_orig)

static void (*DataPanelLine_Text_NV_createMe_orig)(DataPanelLine_Text*, DatapanelGUI*, float, bool) = NULL;
static void DataPanelLine_Text_NV_createMe_hook(DataPanelLine_Text* thisptr, DatapanelGUI* parent, float top, bool lastLine)
{
    DataPanelLine_Text_NV_createMe_orig(thisptr, parent, top, lastLine);
    CallDataPanelLineTextCreateMeCallbacks(thisptr, parent, top, lastLine);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Text_NV_createMe,
    "DataPanelLine_Text::_NV_createMe",
    KenshiLib::GetRealAddress(&DataPanelLine_Text::_NV_createMe),
    DataPanelLine_Text_NV_createMe_hook, DataPanelLine_Text_NV_createMe_orig)

static void (*DataPanelLine_Text_DESTRUCTOR_orig)(DataPanelLine_Text*) = NULL;
static void DataPanelLine_Text_DESTRUCTOR_hook(DataPanelLine_Text* thisptr)
{
    CallDataPanelLineTextDestructorCallbacks(thisptr);
    DataPanelLine_Text_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Text_DESTRUCTOR,
    "DataPanelLine_Text::_DESTRUCTOR",
    KenshiLib::GetRealAddress(&DataPanelLine_Text::_DESTRUCTOR),
    DataPanelLine_Text_DESTRUCTOR_hook, DataPanelLine_Text_DESTRUCTOR_orig)

static DataPanelLine_TextEditable* (*DataPanelLine_TextEditable_CONSTRUCTOR_orig)(DataPanelLine_TextEditable*, const std::string&, const std::string&, int, bool, bool, const MyGUI::Align&, float) = NULL;
static DataPanelLine_TextEditable* DataPanelLine_TextEditable_CONSTRUCTOR_hook(DataPanelLine_TextEditable* thisptr, const std::string& key, const std::string& text, int category, bool showKey, bool multiLine, const MyGUI::Align& textAlign, float width)
{
    DataPanelLine_TextEditable* res = DataPanelLine_TextEditable_CONSTRUCTOR_orig(thisptr, key, text, category, showKey, multiLine, textAlign, width);
    CallDataPanelLineTextEditableConstructedCallbacks(thisptr, key, text, category, showKey, multiLine, textAlign.getValue(), width);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_TextEditable_CONSTRUCTOR,
    "DataPanelLine_TextEditable::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&DataPanelLine_TextEditable::_CONSTRUCTOR),
    DataPanelLine_TextEditable_CONSTRUCTOR_hook, DataPanelLine_TextEditable_CONSTRUCTOR_orig)

static void (*DataPanelLine_TextEditable_NV_createMe_orig)(DataPanelLine_TextEditable*, DatapanelGUI*, float, bool) = NULL;
static void DataPanelLine_TextEditable_NV_createMe_hook(DataPanelLine_TextEditable* thisptr, DatapanelGUI* parent, float top, bool lastLine)
{
    DataPanelLine_TextEditable_NV_createMe_orig(thisptr, parent, top, lastLine);
    CallDataPanelLineTextEditableCreateMeCallbacks(thisptr, parent, top, lastLine);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_TextEditable_NV_createMe,
    "DataPanelLine_TextEditable::_NV_createMe",
    KenshiLib::GetRealAddress(&DataPanelLine_TextEditable::_NV_createMe),
    DataPanelLine_TextEditable_NV_createMe_hook, DataPanelLine_TextEditable_NV_createMe_orig)

static void (*DataPanelLine_TextEditable_textChanged_orig)(DataPanelLine_TextEditable*, MyGUI::EditBox*) = NULL;
static void DataPanelLine_TextEditable_textChanged_hook(DataPanelLine_TextEditable* thisptr, MyGUI::EditBox* sender)
{
    DataPanelLine_TextEditable_textChanged_orig(thisptr, sender);
    CallDataPanelLineTextEditableTextChangedCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_TextEditable_textChanged,
    "DataPanelLine_TextEditable::textChanged",
    KenshiLib::GetRealAddress(&DataPanelLine_TextEditable::textChanged),
    DataPanelLine_TextEditable_textChanged_hook, DataPanelLine_TextEditable_textChanged_orig)

static void (*DataPanelLine_TextEditable_DESTRUCTOR_orig)(DataPanelLine_TextEditable*) = NULL;
static void DataPanelLine_TextEditable_DESTRUCTOR_hook(DataPanelLine_TextEditable* thisptr)
{
    CallDataPanelLineTextEditableDestructorCallbacks(thisptr);
    DataPanelLine_TextEditable_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_TextEditable_DESTRUCTOR,
    "DataPanelLine_TextEditable::_DESTRUCTOR",
    KenshiLib::GetRealAddress(&DataPanelLine_TextEditable::_DESTRUCTOR),
    DataPanelLine_TextEditable_DESTRUCTOR_hook, DataPanelLine_TextEditable_DESTRUCTOR_orig)

static DataPanelLine_Slider* (*DataPanelLine_Slider_CONSTRUCTOR_orig)(DataPanelLine_Slider*, const std::string&, const std::string&, float, float, int, float) = NULL;
static DataPanelLine_Slider* DataPanelLine_Slider_CONSTRUCTOR_hook(DataPanelLine_Slider* thisptr, const std::string& key, const std::string& text, float min, float max, int category, float scale)
{
    DataPanelLine_Slider* res = DataPanelLine_Slider_CONSTRUCTOR_orig(thisptr, key, text, min, max, category, scale);
    CallDataPanelLineSliderConstructedCallbacks(thisptr, key, text, min, max, category, scale);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Slider_CONSTRUCTOR,
    "DataPanelLine_Slider::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&DataPanelLine_Slider::_CONSTRUCTOR),
    DataPanelLine_Slider_CONSTRUCTOR_hook, DataPanelLine_Slider_CONSTRUCTOR_orig)

static void (*DataPanelLine_Slider_sliderValueChanged_orig)(DataPanelLine_Slider*, MyGUI::Slider*, int) = NULL;
static void DataPanelLine_Slider_sliderValueChanged_hook(DataPanelLine_Slider* thisptr, MyGUI::Slider* sender, int value)
{
    DataPanelLine_Slider_sliderValueChanged_orig(thisptr, sender, value);
    CallDataPanelLineSliderSliderValueChangedCallbacks(thisptr, sender, value);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Slider_sliderValueChanged,
    "DataPanelLine_Slider::sliderValueChanged",
    KenshiLib::GetRealAddress(&DataPanelLine_Slider::sliderValueChanged),
    DataPanelLine_Slider_sliderValueChanged_hook, DataPanelLine_Slider_sliderValueChanged_orig)

static void (*DataPanelLine_Slider_NV_updateValuePtr_orig)(DataPanelLine_Slider*, void*) = NULL;
static void DataPanelLine_Slider_NV_updateValuePtr_hook(DataPanelLine_Slider* thisptr, void* ptr)
{
    DataPanelLine_Slider_NV_updateValuePtr_orig(thisptr, ptr);
    CallDataPanelLineSliderUpdateValuePtrCallbacks(thisptr, (void*)ptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Slider_NV_updateValuePtr,
    "DataPanelLine_Slider::_NV_updateValuePtr",
    KenshiLib::GetRealAddress(&DataPanelLine_Slider::_NV_updateValuePtr),
    DataPanelLine_Slider_NV_updateValuePtr_hook, DataPanelLine_Slider_NV_updateValuePtr_orig)

static void (*DataPanelLine_Slider_setValue_orig)(DataPanelLine_Slider*, float) = NULL;
static void DataPanelLine_Slider_setValue_hook(DataPanelLine_Slider* thisptr, float value)
{
    DataPanelLine_Slider_setValue_orig(thisptr, value);
    CallDataPanelLineSliderSetValueCallbacks(thisptr, value);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Slider_setValue,
    "DataPanelLine_Slider::setValue",
    KenshiLib::GetRealAddress(&DataPanelLine_Slider::setValue),
    DataPanelLine_Slider_setValue_hook, DataPanelLine_Slider_setValue_orig)

static float (*DataPanelLine_Slider_getValue_orig)(const DataPanelLine_Slider*) = NULL;
static float DataPanelLine_Slider_getValue_hook(const DataPanelLine_Slider* thisptr)
{
    float res = DataPanelLine_Slider_getValue_orig(thisptr);
    return CallDataPanelLineSliderGetValueCallbacks(const_cast<DataPanelLine_Slider*>(thisptr), res);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Slider_getValue,
    "DataPanelLine_Slider::getValue",
    KenshiLib::GetRealAddress(&DataPanelLine_Slider::getValue),
    DataPanelLine_Slider_getValue_hook, DataPanelLine_Slider_getValue_orig)

static void (*DataPanelLine_Slider_NV_refresh_orig)(DataPanelLine_Slider*) = NULL;
static void DataPanelLine_Slider_NV_refresh_hook(DataPanelLine_Slider* thisptr)
{
    DataPanelLine_Slider_NV_refresh_orig(thisptr);
    CallDataPanelLineSliderRefreshCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Slider_NV_refresh,
    "DataPanelLine_Slider::_NV_refresh",
    KenshiLib::GetRealAddress(&DataPanelLine_Slider::_NV_refresh),
    DataPanelLine_Slider_NV_refresh_hook, DataPanelLine_Slider_NV_refresh_orig)

static void (*DataPanelLine_Slider_NV_createMe_orig)(DataPanelLine_Slider*, DatapanelGUI*, float, bool) = NULL;
static void DataPanelLine_Slider_NV_createMe_hook(DataPanelLine_Slider* thisptr, DatapanelGUI* parent, float top, bool lastLine)
{
    DataPanelLine_Slider_NV_createMe_orig(thisptr, parent, top, lastLine);
    CallDataPanelLineSliderCreateMeCallbacks(thisptr, parent, top, lastLine);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Slider_NV_createMe,
    "DataPanelLine_Slider::_NV_createMe",
    KenshiLib::GetRealAddress(&DataPanelLine_Slider::_NV_createMe),
    DataPanelLine_Slider_NV_createMe_hook, DataPanelLine_Slider_NV_createMe_orig)

static void (*DataPanelLine_Slider_DESTRUCTOR_orig)(DataPanelLine_Slider*) = NULL;
static void DataPanelLine_Slider_DESTRUCTOR_hook(DataPanelLine_Slider* thisptr)
{
    CallDataPanelLineSliderDestructorCallbacks(thisptr);
    DataPanelLine_Slider_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Slider_DESTRUCTOR,
    "DataPanelLine_Slider::_DESTRUCTOR",
    KenshiLib::GetRealAddress(&DataPanelLine_Slider::_DESTRUCTOR),
    DataPanelLine_Slider_DESTRUCTOR_hook, DataPanelLine_Slider_DESTRUCTOR_orig)

static void (*DataPanelLine_Progress_setProgress_orig)(DataPanelLine_Progress*, float, const std::string&) = NULL;
static void DataPanelLine_Progress_setProgress_hook(DataPanelLine_Progress* thisptr, float value, const std::string& text)
{
    DataPanelLine_Progress_setProgress_orig(thisptr, value, text);
    CallDataPanelLineProgressSetProgressCallbacks(thisptr, value, text);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Progress_setProgress,
    "DataPanelLine_Progress::setProgress",
    KenshiLib::GetRealAddress(&DataPanelLine_Progress::setProgress),
    DataPanelLine_Progress_setProgress_hook, DataPanelLine_Progress_setProgress_orig)

static DataPanelLine_Progress* (*DataPanelLine_Progress_CONSTRUCTOR_orig)(DataPanelLine_Progress*, const std::string&, int, bool) = NULL;
static DataPanelLine_Progress* DataPanelLine_Progress_CONSTRUCTOR_hook(DataPanelLine_Progress* thisptr, const std::string& key, int category, bool showKey)
{
    DataPanelLine_Progress* res = DataPanelLine_Progress_CONSTRUCTOR_orig(thisptr, key, category, showKey);
    CallDataPanelLineProgressConstructedCallbacks(thisptr, key, category, showKey);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Progress_CONSTRUCTOR,
    "DataPanelLine_Progress::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&DataPanelLine_Progress::_CONSTRUCTOR),
    DataPanelLine_Progress_CONSTRUCTOR_hook, DataPanelLine_Progress_CONSTRUCTOR_orig)

static void (*DataPanelLine_Progress_NV_createMe_orig)(DataPanelLine_Progress*, DatapanelGUI*, float, bool) = NULL;
static void DataPanelLine_Progress_NV_createMe_hook(DataPanelLine_Progress* thisptr, DatapanelGUI* parent, float top, bool lastLine)
{
    DataPanelLine_Progress_NV_createMe_orig(thisptr, parent, top, lastLine);
    CallDataPanelLineProgressCreateMeCallbacks(thisptr, parent, top, lastLine);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Progress_NV_createMe,
    "DataPanelLine_Progress::_NV_createMe",
    KenshiLib::GetRealAddress(&DataPanelLine_Progress::_NV_createMe),
    DataPanelLine_Progress_NV_createMe_hook, DataPanelLine_Progress_NV_createMe_orig)

static void (*DataPanelLine_Progress_DESTRUCTOR_orig)(DataPanelLine_Progress*) = NULL;
static void DataPanelLine_Progress_DESTRUCTOR_hook(DataPanelLine_Progress* thisptr)
{
    CallDataPanelLineProgressDestructorCallbacks(thisptr);
    DataPanelLine_Progress_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Progress_DESTRUCTOR,
    "DataPanelLine_Progress::_DESTRUCTOR",
    KenshiLib::GetRealAddress(&DataPanelLine_Progress::_DESTRUCTOR),
    DataPanelLine_Progress_DESTRUCTOR_hook, DataPanelLine_Progress_DESTRUCTOR_orig)

static void (*DataPanelLine_CheckBox_NV_updateValuePtr_orig)(DataPanelLine_CheckBox*, void*) = NULL;
static void DataPanelLine_CheckBox_NV_updateValuePtr_hook(DataPanelLine_CheckBox* thisptr, void* ptr)
{
    DataPanelLine_CheckBox_NV_updateValuePtr_orig(thisptr, ptr);
    CallDataPanelLineCheckBoxUpdateValuePtrCallbacks(thisptr, (void*)ptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_CheckBox_NV_updateValuePtr,
    "DataPanelLine_CheckBox::_NV_updateValuePtr",
    KenshiLib::GetRealAddress(&DataPanelLine_CheckBox::_NV_updateValuePtr),
    DataPanelLine_CheckBox_NV_updateValuePtr_hook, DataPanelLine_CheckBox_NV_updateValuePtr_orig)

static void (*DataPanelLine_CheckBox_NV_refresh_orig)(DataPanelLine_CheckBox*) = NULL;
static void DataPanelLine_CheckBox_NV_refresh_hook(DataPanelLine_CheckBox* thisptr)
{
    DataPanelLine_CheckBox_NV_refresh_orig(thisptr);
    CallDataPanelLineCheckBoxRefreshCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_CheckBox_NV_refresh,
    "DataPanelLine_CheckBox::_NV_refresh",
    KenshiLib::GetRealAddress(&DataPanelLine_CheckBox::_NV_refresh),
    DataPanelLine_CheckBox_NV_refresh_hook, DataPanelLine_CheckBox_NV_refresh_orig)

static void (*DataPanelLine_CheckBox_setValue_orig)(DataPanelLine_CheckBox*, bool) = NULL;
static void DataPanelLine_CheckBox_setValue_hook(DataPanelLine_CheckBox* thisptr, bool checked)
{
    DataPanelLine_CheckBox_setValue_orig(thisptr, checked);
    CallDataPanelLineCheckBoxSetValueCallbacks(thisptr, checked);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_CheckBox_setValue,
    "DataPanelLine_CheckBox::setValue",
    KenshiLib::GetRealAddress(&DataPanelLine_CheckBox::setValue),
    DataPanelLine_CheckBox_setValue_hook, DataPanelLine_CheckBox_setValue_orig)

static void (*DataPanelLine_CheckBox_setValuePtr_orig)(DataPanelLine_CheckBox*, bool*) = NULL;
static void DataPanelLine_CheckBox_setValuePtr_hook(DataPanelLine_CheckBox* thisptr, bool* valPtr)
{
    DataPanelLine_CheckBox_setValuePtr_orig(thisptr, valPtr);
    CallDataPanelLineCheckBoxSetValuePtrCallbacks(thisptr, (void*)valPtr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_CheckBox_setValuePtr,
    "DataPanelLine_CheckBox::setValuePtr",
    KenshiLib::GetRealAddress(&DataPanelLine_CheckBox::setValuePtr),
    DataPanelLine_CheckBox_setValuePtr_hook, DataPanelLine_CheckBox_setValuePtr_orig)

static DataPanelLine_CheckBox* (*DataPanelLine_CheckBox_CONSTRUCTOR_orig)(DataPanelLine_CheckBox*, const std::string&, int, bool*) = NULL;
static DataPanelLine_CheckBox* DataPanelLine_CheckBox_CONSTRUCTOR_hook(DataPanelLine_CheckBox* thisptr, const std::string& key, int cat, bool* val)
{
    DataPanelLine_CheckBox* res = DataPanelLine_CheckBox_CONSTRUCTOR_orig(thisptr, key, cat, val);
    CallDataPanelLineCheckBoxConstructedCallbacks(thisptr, key, cat, (void*)val);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_CheckBox_CONSTRUCTOR,
    "DataPanelLine_CheckBox::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&DataPanelLine_CheckBox::_CONSTRUCTOR),
    DataPanelLine_CheckBox_CONSTRUCTOR_hook, DataPanelLine_CheckBox_CONSTRUCTOR_orig)

static void (*DataPanelLine_CheckBox_notifyToggleCheck_orig)(DataPanelLine_CheckBox*, MyGUI::Widget*) = NULL;
static void DataPanelLine_CheckBox_notifyToggleCheck_hook(DataPanelLine_CheckBox* thisptr, MyGUI::Widget* sender)
{
    DataPanelLine_CheckBox_notifyToggleCheck_orig(thisptr, sender);
    CallDataPanelLineCheckBoxNotifyToggleCheckCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_CheckBox_notifyToggleCheck,
    "DataPanelLine_CheckBox::notifyToggleCheck",
    KenshiLib::GetRealAddress(&DataPanelLine_CheckBox::notifyToggleCheck),
    DataPanelLine_CheckBox_notifyToggleCheck_hook, DataPanelLine_CheckBox_notifyToggleCheck_orig)

static void (*DataPanelLine_CheckBox_NV_createMe_orig)(DataPanelLine_CheckBox*, DatapanelGUI*, float, bool) = NULL;
static void DataPanelLine_CheckBox_NV_createMe_hook(DataPanelLine_CheckBox* thisptr, DatapanelGUI* parent, float topReal, bool lastLine)
{
    DataPanelLine_CheckBox_NV_createMe_orig(thisptr, parent, topReal, lastLine);
    CallDataPanelLineCheckBoxCreateMeCallbacks(thisptr, parent, topReal, lastLine);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_CheckBox_NV_createMe,
    "DataPanelLine_CheckBox::_NV_createMe",
    KenshiLib::GetRealAddress(&DataPanelLine_CheckBox::_NV_createMe),
    DataPanelLine_CheckBox_NV_createMe_hook, DataPanelLine_CheckBox_NV_createMe_orig)

static void (*DataPanelLine_CheckBox_DESTRUCTOR_orig)(DataPanelLine_CheckBox*) = NULL;
static void DataPanelLine_CheckBox_DESTRUCTOR_hook(DataPanelLine_CheckBox* thisptr)
{
    CallDataPanelLineCheckBoxDestructorCallbacks(thisptr);
    DataPanelLine_CheckBox_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_CheckBox_DESTRUCTOR,
    "DataPanelLine_CheckBox::_DESTRUCTOR",
    KenshiLib::GetRealAddress(&DataPanelLine_CheckBox::_DESTRUCTOR),
    DataPanelLine_CheckBox_DESTRUCTOR_hook, DataPanelLine_CheckBox_DESTRUCTOR_orig)

static void (*DataPanelLine_DropBox_addAValue_orig)(DataPanelLine_DropBox*, const std::string&, int) = NULL;
static void DataPanelLine_DropBox_addAValue_hook(DataPanelLine_DropBox* thisptr, const std::string& key, int val)
{
    DataPanelLine_DropBox_addAValue_orig(thisptr, key, val);
    CallDataPanelLineDropBoxAddAValueCallbacks(thisptr, key, val);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_DropBox_addAValue,
    "DataPanelLine_DropBox::addAValue",
    KenshiLib::GetRealAddress(&DataPanelLine_DropBox::addAValue),
    DataPanelLine_DropBox_addAValue_hook, DataPanelLine_DropBox_addAValue_orig)

static int (*DataPanelLine_DropBox_getSelectedValue_orig)(DataPanelLine_DropBox*) = NULL;
static int DataPanelLine_DropBox_getSelectedValue_hook(DataPanelLine_DropBox* thisptr)
{
    int res = DataPanelLine_DropBox_getSelectedValue_orig(thisptr);
    return CallDataPanelLineDropBoxGetSelectedValueCallbacks(thisptr, res);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_DropBox_getSelectedValue,
    "DataPanelLine_DropBox::getSelectedValue",
    KenshiLib::GetRealAddress(&DataPanelLine_DropBox::getSelectedValue),
    DataPanelLine_DropBox_getSelectedValue_hook, DataPanelLine_DropBox_getSelectedValue_orig)

static void (*DataPanelLine_DropBox_setSelectedValue_orig)(DataPanelLine_DropBox*, int) = NULL;
static void DataPanelLine_DropBox_setSelectedValue_hook(DataPanelLine_DropBox* thisptr, int val)
{
    DataPanelLine_DropBox_setSelectedValue_orig(thisptr, val);
    CallDataPanelLineDropBoxSetSelectedValueCallbacks(thisptr, val);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_DropBox_setSelectedValue,
    "DataPanelLine_DropBox::setSelectedValue",
    KenshiLib::GetRealAddress(&DataPanelLine_DropBox::setSelectedValue),
    DataPanelLine_DropBox_setSelectedValue_hook, DataPanelLine_DropBox_setSelectedValue_orig)

static std::string* (*DataPanelLine_DropBox_getSelectedText_orig)(const DataPanelLine_DropBox*, std::string*) = NULL;
static std::string* DataPanelLine_DropBox_getSelectedText_hook(const DataPanelLine_DropBox* thisptr, std::string* ret)
{
    std::string* res = DataPanelLine_DropBox_getSelectedText_orig(thisptr, ret);
    CallDataPanelLineDropBoxGetSelectedTextCallbacks(const_cast<DataPanelLine_DropBox*>(thisptr), *res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_DropBox_getSelectedText,
    "DataPanelLine_DropBox::getSelectedText",
    KenshiLib::GetRealAddress(&DataPanelLine_DropBox::getSelectedText),
    DataPanelLine_DropBox_getSelectedText_hook, DataPanelLine_DropBox_getSelectedText_orig)

static void (*DataPanelLine_DropBox_clearValues_orig)(DataPanelLine_DropBox*) = NULL;
static void DataPanelLine_DropBox_clearValues_hook(DataPanelLine_DropBox* thisptr)
{
    DataPanelLine_DropBox_clearValues_orig(thisptr);
    CallDataPanelLineDropBoxClearValuesCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_DropBox_clearValues,
    "DataPanelLine_DropBox::clearValues",
    KenshiLib::GetRealAddress(&DataPanelLine_DropBox::clearValues),
    DataPanelLine_DropBox_clearValues_hook, DataPanelLine_DropBox_clearValues_orig)

static void (*DataPanelLine_DropBox_NV_createMe_orig)(DataPanelLine_DropBox*, DatapanelGUI*, float, bool) = NULL;
static void DataPanelLine_DropBox_NV_createMe_hook(DataPanelLine_DropBox* thisptr, DatapanelGUI* parent, float top, bool lastLine)
{
    DataPanelLine_DropBox_NV_createMe_orig(thisptr, parent, top, lastLine);
    CallDataPanelLineDropBoxCreateMeCallbacks(thisptr, parent, top, lastLine);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_DropBox_NV_createMe,
    "DataPanelLine_DropBox::_NV_createMe",
    KenshiLib::GetRealAddress(&DataPanelLine_DropBox::_NV_createMe),
    DataPanelLine_DropBox_NV_createMe_hook, DataPanelLine_DropBox_NV_createMe_orig)

static void (*DataPanelLine_DropBox_NV_updateValuePtr_orig)(DataPanelLine_DropBox*, void*) = NULL;
static void DataPanelLine_DropBox_NV_updateValuePtr_hook(DataPanelLine_DropBox* thisptr, void* ptr)
{
    DataPanelLine_DropBox_NV_updateValuePtr_orig(thisptr, ptr);
    CallDataPanelLineDropBoxUpdateValuePtrCallbacks(thisptr, (void*)ptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_DropBox_NV_updateValuePtr,
    "DataPanelLine_DropBox::_NV_updateValuePtr",
    KenshiLib::GetRealAddress(&DataPanelLine_DropBox::_NV_updateValuePtr),
    DataPanelLine_DropBox_NV_updateValuePtr_hook, DataPanelLine_DropBox_NV_updateValuePtr_orig)

static void (*DataPanelLine_DropBox_NV_refresh_orig)(DataPanelLine_DropBox*) = NULL;
static void DataPanelLine_DropBox_NV_refresh_hook(DataPanelLine_DropBox* thisptr)
{
    DataPanelLine_DropBox_NV_refresh_orig(thisptr);
    CallDataPanelLineDropBoxRefreshCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_DropBox_NV_refresh,
    "DataPanelLine_DropBox::_NV_refresh",
    KenshiLib::GetRealAddress(&DataPanelLine_DropBox::_NV_refresh),
    DataPanelLine_DropBox_NV_refresh_hook, DataPanelLine_DropBox_NV_refresh_orig)

static DataPanelLine_DropBox* (*DataPanelLine_DropBox_CONSTRUCTOR_orig)(DataPanelLine_DropBox*, const std::string&, int, int*, float, bool) = NULL;
static DataPanelLine_DropBox* DataPanelLine_DropBox_CONSTRUCTOR_hook(DataPanelLine_DropBox* thisptr, const std::string& text, int category, int* valuePtr, float width, bool hasGobox)
{
    DataPanelLine_DropBox* res = DataPanelLine_DropBox_CONSTRUCTOR_orig(thisptr, text, category, valuePtr, width, hasGobox);
    CallDataPanelLineDropBoxConstructedCallbacks(thisptr, text, category, (void*)valuePtr, width, hasGobox);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_DropBox_CONSTRUCTOR,
    "DataPanelLine_DropBox::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&DataPanelLine_DropBox::_CONSTRUCTOR),
    DataPanelLine_DropBox_CONSTRUCTOR_hook, DataPanelLine_DropBox_CONSTRUCTOR_orig)

static void (*DataPanelLine_DropBox_selectionChange_orig)(DataPanelLine_DropBox*, MyGUI::ComboBox*, unsigned __int64) = NULL;
static void DataPanelLine_DropBox_selectionChange_hook(DataPanelLine_DropBox* thisptr, MyGUI::ComboBox* sender, unsigned __int64 i)
{
    DataPanelLine_DropBox_selectionChange_orig(thisptr, sender, i);
    CallDataPanelLineDropBoxSelectionChangeCallbacks(thisptr, sender, static_cast<int>(i));
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_DropBox_selectionChange,
    "DataPanelLine_DropBox::selectionChange",
    KenshiLib::GetRealAddress(&DataPanelLine_DropBox::selectionChange),
    DataPanelLine_DropBox_selectionChange_hook, DataPanelLine_DropBox_selectionChange_orig)

static void (*DataPanelLine_DropBox_goPressed_orig)(DataPanelLine_DropBox*, MyGUI::Widget*) = NULL;
static void DataPanelLine_DropBox_goPressed_hook(DataPanelLine_DropBox* thisptr, MyGUI::Widget* sender)
{
    DataPanelLine_DropBox_goPressed_orig(thisptr, sender);
    CallDataPanelLineDropBoxGoPressedCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_DropBox_goPressed,
    "DataPanelLine_DropBox::goPressed",
    KenshiLib::GetRealAddress(&DataPanelLine_DropBox::goPressed),
    DataPanelLine_DropBox_goPressed_hook, DataPanelLine_DropBox_goPressed_orig)

static void (*DataPanelLine_DropBox_DESTRUCTOR_orig)(DataPanelLine_DropBox*) = NULL;
static void DataPanelLine_DropBox_DESTRUCTOR_hook(DataPanelLine_DropBox* thisptr)
{
    CallDataPanelLineDropBoxDestructorCallbacks(thisptr);
    DataPanelLine_DropBox_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_DropBox_DESTRUCTOR,
    "DataPanelLine_DropBox::_DESTRUCTOR",
    KenshiLib::GetRealAddress(&DataPanelLine_DropBox::_DESTRUCTOR),
    DataPanelLine_DropBox_DESTRUCTOR_hook, DataPanelLine_DropBox_DESTRUCTOR_orig)

static DataPanelLine_KeyConfig* (*DataPanelLine_KeyConfig_CONSTRUCTOR_orig)(DataPanelLine_KeyConfig*, const std::string&, const std::string&, int) = NULL;
static DataPanelLine_KeyConfig* DataPanelLine_KeyConfig_CONSTRUCTOR_hook(DataPanelLine_KeyConfig* thisptr, const std::string& cmd, const std::string& text, int cat)
{
    DataPanelLine_KeyConfig* res = DataPanelLine_KeyConfig_CONSTRUCTOR_orig(thisptr, cmd, text, cat);
    CallDataPanelLineKeyConfigConstructedCallbacks(thisptr, cmd, text, cat);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_KeyConfig_CONSTRUCTOR,
    "DataPanelLine_KeyConfig::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&DataPanelLine_KeyConfig::_CONSTRUCTOR),
    DataPanelLine_KeyConfig_CONSTRUCTOR_hook, DataPanelLine_KeyConfig_CONSTRUCTOR_orig)

static const std::string& (*DataPanelLine_KeyConfig_getCommand_orig)(DataPanelLine_KeyConfig*) = NULL;
static const std::string& DataPanelLine_KeyConfig_getCommand_hook(DataPanelLine_KeyConfig* thisptr)
{
    const std::string& res = DataPanelLine_KeyConfig_getCommand_orig(thisptr);
    CallDataPanelLineKeyConfigGetCommandCallbacks(thisptr, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_KeyConfig_getCommand,
    "DataPanelLine_KeyConfig::getCommand",
    KenshiLib::GetRealAddress(&DataPanelLine_KeyConfig::getCommand),
    DataPanelLine_KeyConfig_getCommand_hook, DataPanelLine_KeyConfig_getCommand_orig)

static int (*DataPanelLine_KeyConfig_oldKey_orig)(DataPanelLine_KeyConfig*) = NULL;
static int DataPanelLine_KeyConfig_oldKey_hook(DataPanelLine_KeyConfig* thisptr)
{
    int res = DataPanelLine_KeyConfig_oldKey_orig(thisptr);
    return CallDataPanelLineKeyConfigOldKeyCallbacks(thisptr, res);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_KeyConfig_oldKey,
    "DataPanelLine_KeyConfig::oldKey",
    KenshiLib::GetRealAddress(&DataPanelLine_KeyConfig::oldKey),
    DataPanelLine_KeyConfig_oldKey_hook, DataPanelLine_KeyConfig_oldKey_orig)

static void (*DataPanelLine_KeyConfig_setKey_orig)(DataPanelLine_KeyConfig*, const std::string&) = NULL;
static void DataPanelLine_KeyConfig_setKey_hook(DataPanelLine_KeyConfig* thisptr, const std::string& s)
{
    DataPanelLine_KeyConfig_setKey_orig(thisptr, s);
    CallDataPanelLineKeyConfigSetKeyCallbacks(thisptr, s);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_KeyConfig_setKey,
    "DataPanelLine_KeyConfig::setKey",
    KenshiLib::GetRealAddress(&DataPanelLine_KeyConfig::setKey),
    DataPanelLine_KeyConfig_setKey_hook, DataPanelLine_KeyConfig_setKey_orig)

static void (*DataPanelLine_KeyConfig_eraseKey_orig)(DataPanelLine_KeyConfig*, const std::string&) = NULL;
static void DataPanelLine_KeyConfig_eraseKey_hook(DataPanelLine_KeyConfig* thisptr, const std::string& key)
{
    DataPanelLine_KeyConfig_eraseKey_orig(thisptr, key);
    CallDataPanelLineKeyConfigEraseKeyCallbacks(thisptr, key);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_KeyConfig_eraseKey,
    "DataPanelLine_KeyConfig::eraseKey",
    KenshiLib::GetRealAddress(&DataPanelLine_KeyConfig::eraseKey),
    DataPanelLine_KeyConfig_eraseKey_hook, DataPanelLine_KeyConfig_eraseKey_orig)

static void (*DataPanelLine_KeyConfig_NV_refresh_orig)(DataPanelLine_KeyConfig*) = NULL;
static void DataPanelLine_KeyConfig_NV_refresh_hook(DataPanelLine_KeyConfig* thisptr)
{
    DataPanelLine_KeyConfig_NV_refresh_orig(thisptr);
    CallDataPanelLineKeyConfigRefreshCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_KeyConfig_NV_refresh,
    "DataPanelLine_KeyConfig::_NV_refresh",
    KenshiLib::GetRealAddress(&DataPanelLine_KeyConfig::_NV_refresh),
    DataPanelLine_KeyConfig_NV_refresh_hook, DataPanelLine_KeyConfig_NV_refresh_orig)

static void (*DataPanelLine_KeyConfig_cancel_orig)(DataPanelLine_KeyConfig*) = NULL;
static void DataPanelLine_KeyConfig_cancel_hook(DataPanelLine_KeyConfig* thisptr)
{
    DataPanelLine_KeyConfig_cancel_orig(thisptr);
    CallDataPanelLineKeyConfigCancelCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_KeyConfig_cancel,
    "DataPanelLine_KeyConfig::cancel",
    KenshiLib::GetRealAddress(&DataPanelLine_KeyConfig::cancel),
    DataPanelLine_KeyConfig_cancel_hook, DataPanelLine_KeyConfig_cancel_orig)

static void (*DataPanelLine_KeyConfig_NV_createMe_orig)(DataPanelLine_KeyConfig*, DatapanelGUI*, float, bool) = NULL;
static void DataPanelLine_KeyConfig_NV_createMe_hook(DataPanelLine_KeyConfig* thisptr, DatapanelGUI* p, float vpos, bool lastLine)
{
    DataPanelLine_KeyConfig_NV_createMe_orig(thisptr, p, vpos, lastLine);
    CallDataPanelLineKeyConfigCreateMeCallbacks(thisptr, p, vpos, lastLine);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_KeyConfig_NV_createMe,
    "DataPanelLine_KeyConfig::_NV_createMe",
    KenshiLib::GetRealAddress(&DataPanelLine_KeyConfig::_NV_createMe),
    DataPanelLine_KeyConfig_NV_createMe_hook, DataPanelLine_KeyConfig_NV_createMe_orig)

static void (*DataPanelLine_KeyConfig_clickButton_orig)(DataPanelLine_KeyConfig*, MyGUI::Widget*) = NULL;
static void DataPanelLine_KeyConfig_clickButton_hook(DataPanelLine_KeyConfig* thisptr, MyGUI::Widget* sender)
{
    DataPanelLine_KeyConfig_clickButton_orig(thisptr, sender);
    CallDataPanelLineKeyConfigClickButtonCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_KeyConfig_clickButton,
    "DataPanelLine_KeyConfig::clickButton",
    KenshiLib::GetRealAddress(&DataPanelLine_KeyConfig::clickButton),
    DataPanelLine_KeyConfig_clickButton_hook, DataPanelLine_KeyConfig_clickButton_orig)

static void (*DataPanelLine_KeyConfig_DESTRUCTOR_orig)(DataPanelLine_KeyConfig*) = NULL;
static void DataPanelLine_KeyConfig_DESTRUCTOR_hook(DataPanelLine_KeyConfig* thisptr)
{
    CallDataPanelLineKeyConfigDestructorCallbacks(thisptr);
    DataPanelLine_KeyConfig_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_KeyConfig_DESTRUCTOR,
    "DataPanelLine_KeyConfig::_DESTRUCTOR",
    KenshiLib::GetRealAddress(&DataPanelLine_KeyConfig::_DESTRUCTOR),
    DataPanelLine_KeyConfig_DESTRUCTOR_hook, DataPanelLine_KeyConfig_DESTRUCTOR_orig)

static void (*DataPanelLine_Button_pressCallback_orig)(DataPanelLine_Button*, MyGUI::Widget*) = NULL;
static void DataPanelLine_Button_pressCallback_hook(DataPanelLine_Button* thisptr, MyGUI::Widget* sender)
{
    DataPanelLine_Button_pressCallback_orig(thisptr, sender);
    CallDataPanelLineButtonPressCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_DataPanelLine_Button_pressCallback,
    "DataPanelLine_Button::pressCallback",
    KenshiLib::GetRealAddress(&DataPanelLine_Button::pressCallback),
    DataPanelLine_Button_pressCallback_hook, DataPanelLine_Button_pressCallback_orig)
