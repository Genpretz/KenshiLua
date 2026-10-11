#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/gui/InventoryGUI.h>

// ---------------------------------------------------------------------------
// Hooks for InventoryGUI.h
//
// Non-virtual members and _NV_ bodies. Events fire after the original call
// except for destructors. Scalar and bound-pointer getters accept overrides.
//
// Not hooked:
//   InventoryGUI::InventoryTradeData::_CONSTRUCTOR overloads
//   InventoryGUI::getSection overloads
//     overloaded; overloads are not hooked
//   InventoryGUI::FenceCallbackData::_CONSTRUCTOR
//     declaration has no importable _CONSTRUCTOR export
//   BackpackInventoryLayout::_NV_setupSections
//     KenshiLib exposes only a placeholder export, not the declared member
// ---------------------------------------------------------------------------

static InventoryIcon* (*InventoryIcon_CONSTRUCTOR_orig)(InventoryIcon*, Item*, const MyGUI::types::TPoint<int>&, MyGUI::Widget*) = NULL;
static InventoryIcon* InventoryIcon_CONSTRUCTOR_hook(InventoryIcon* thisptr, Item* item, const MyGUI::types::TPoint<int>& position, MyGUI::Widget* parent)
{
    InventoryIcon* res = InventoryIcon_CONSTRUCTOR_orig(thisptr, item, position, parent);
    CallInventoryIconConstructedCallbacks(thisptr, item, position, parent);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryIcon_CONSTRUCTOR,
    "InventoryIcon::_CONSTRUCTOR", KenshiLib::GetRealAddress(&InventoryIcon::_CONSTRUCTOR),
    InventoryIcon_CONSTRUCTOR_hook, InventoryIcon_CONSTRUCTOR_orig)

static void (*InventoryIcon_setPosition_orig)(InventoryIcon*, const MyGUI::types::TPoint<int>&) = NULL;
static void InventoryIcon_setPosition_hook(InventoryIcon* thisptr, const MyGUI::types::TPoint<int>& position)
{
    InventoryIcon_setPosition_orig(thisptr, position);
    CallInventoryIconSetPositionCallbacks(thisptr, position);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryIcon_setPosition,
    "InventoryIcon::setPosition", KenshiLib::GetRealAddress(&InventoryIcon::setPosition),
    InventoryIcon_setPosition_hook, InventoryIcon_setPosition_orig)

static MyGUI::types::TSize<int> (*InventoryIcon_getSize_orig)(const InventoryIcon*) = NULL;
static MyGUI::types::TSize<int> InventoryIcon_getSize_hook(const InventoryIcon* thisptr)
{
    MyGUI::types::TSize<int> res = InventoryIcon_getSize_orig(thisptr);
    CallInventoryIconGetSizeCallbacks(const_cast<InventoryIcon*>(thisptr), res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryIcon_getSize,
    "InventoryIcon::getSize", KenshiLib::GetRealAddress(&InventoryIcon::getSize),
    InventoryIcon_getSize_hook, InventoryIcon_getSize_orig)

static void (*InventoryIcon_update_orig)(InventoryIcon*) = NULL;
static void InventoryIcon_update_hook(InventoryIcon* thisptr)
{
    InventoryIcon_update_orig(thisptr);
    CallInventoryIconUpdateCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryIcon_update,
    "InventoryIcon::update", KenshiLib::GetRealAddress(&InventoryIcon::update),
    InventoryIcon_update_hook, InventoryIcon_update_orig)

static MyGUI::Widget* (*InventoryIcon_getWidget_orig)(const InventoryIcon*) = NULL;
static MyGUI::Widget* InventoryIcon_getWidget_hook(const InventoryIcon* thisptr)
{
    MyGUI::Widget* res = InventoryIcon_getWidget_orig(thisptr);
    CallInventoryIconGetWidgetCallbacks(const_cast<InventoryIcon*>(thisptr), res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryIcon_getWidget,
    "InventoryIcon::getWidget", KenshiLib::GetRealAddress(&InventoryIcon::getWidget),
    InventoryIcon_getWidget_hook, InventoryIcon_getWidget_orig)

static void (*InventoryIcon_static_createIconImage_orig)(Item*, std::string&, iVector2&) = NULL;
static void InventoryIcon_static_createIconImage_hook(Item* item, std::string& name, iVector2& size)
{
    InventoryIcon_static_createIconImage_orig(item, name, size);
    CallInventoryIconCreateIconImageCallbacks(item, name, size);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryIcon_static_createIconImage,
    "InventoryIcon::createIconImage", KenshiLib::GetRealAddress(&InventoryIcon::createIconImage),
    InventoryIcon_static_createIconImage_hook, InventoryIcon_static_createIconImage_orig)

static MyGUI::types::TSize<int> (*InventoryIcon_static_getItemSize_orig)(GameData*) = NULL;
static MyGUI::types::TSize<int> InventoryIcon_static_getItemSize_hook(GameData* itemData)
{
    MyGUI::types::TSize<int> res = InventoryIcon_static_getItemSize_orig(itemData);
    CallInventoryIconGetItemSizeCallbacks(itemData, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryIcon_static_getItemSize,
    "InventoryIcon::getItemSize", KenshiLib::GetRealAddress(&InventoryIcon::getItemSize),
    InventoryIcon_static_getItemSize_hook, InventoryIcon_static_getItemSize_orig)

static MyGUI::types::TPoint<int> (*InventoryIcon_static_getItemPosition_orig)(int, int) = NULL;
static MyGUI::types::TPoint<int> InventoryIcon_static_getItemPosition_hook(int x, int y)
{
    MyGUI::types::TPoint<int> res = InventoryIcon_static_getItemPosition_orig(x, y);
    CallInventoryIconGetItemPositionCallbacks(x, y, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryIcon_static_getItemPosition,
    "InventoryIcon::getItemPosition", KenshiLib::GetRealAddress(&InventoryIcon::getItemPosition),
    InventoryIcon_static_getItemPosition_hook, InventoryIcon_static_getItemPosition_orig)

static void (*InventoryIcon_DESTRUCTOR_orig)(InventoryIcon*) = NULL;
static void InventoryIcon_DESTRUCTOR_hook(InventoryIcon* thisptr)
{
    CallInventoryIconDestructorCallbacks(thisptr);
    InventoryIcon_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryIcon_DESTRUCTOR,
    "InventoryIcon::_DESTRUCTOR", KenshiLib::GetRealAddress(&InventoryIcon::_DESTRUCTOR),
    InventoryIcon_DESTRUCTOR_hook, InventoryIcon_DESTRUCTOR_orig)

static InventorySectionGUI* (*InventorySectionGUI_CONSTRUCTOR_orig)(InventorySectionGUI*, MyGUI::Widget*, const std::string&) = NULL;
static InventorySectionGUI* InventorySectionGUI_CONSTRUCTOR_hook(InventorySectionGUI* thisptr, MyGUI::Widget* widget, const std::string& sectionName)
{
    InventorySectionGUI* res = InventorySectionGUI_CONSTRUCTOR_orig(thisptr, widget, sectionName);
    CallInventorySectionGUIConstructedCallbacks(thisptr, widget, sectionName);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventorySectionGUI_CONSTRUCTOR,
    "InventorySectionGUI::_CONSTRUCTOR", KenshiLib::GetRealAddress(&InventorySectionGUI::_CONSTRUCTOR),
    InventorySectionGUI_CONSTRUCTOR_hook, InventorySectionGUI_CONSTRUCTOR_orig)

static void (*InventorySectionGUI_DESTRUCTOR_orig)(InventorySectionGUI*) = NULL;
static void InventorySectionGUI_DESTRUCTOR_hook(InventorySectionGUI* thisptr)
{
    CallInventorySectionGUIDestructorCallbacks(thisptr);
    InventorySectionGUI_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventorySectionGUI_DESTRUCTOR,
    "InventorySectionGUI::_DESTRUCTOR", KenshiLib::GetRealAddress(&InventorySectionGUI::_DESTRUCTOR),
    InventorySectionGUI_DESTRUCTOR_hook, InventorySectionGUI_DESTRUCTOR_orig)

static bool (*InventorySectionGUI_hasMouse_orig)(InventorySectionGUI*) = NULL;
static bool InventorySectionGUI_hasMouse_hook(InventorySectionGUI* thisptr)
{
    bool res = InventorySectionGUI_hasMouse_orig(thisptr);
    return static_cast<bool>(CallInventorySectionGUIHasMouseCallbacks(thisptr, res));
}
DEFINE_HOOK_INSTALLER(InstallHook_InventorySectionGUI_hasMouse,
    "InventorySectionGUI::hasMouse", KenshiLib::GetRealAddress(&InventorySectionGUI::hasMouse),
    InventorySectionGUI_hasMouse_hook, InventorySectionGUI_hasMouse_orig)

static MyGUI::types::TPoint<int> (*InventorySectionGUI_getItemAbsolutePosition_orig)(InventorySectionGUI*, int, int) = NULL;
static MyGUI::types::TPoint<int> InventorySectionGUI_getItemAbsolutePosition_hook(InventorySectionGUI* thisptr, int x, int y)
{
    MyGUI::types::TPoint<int> res = InventorySectionGUI_getItemAbsolutePosition_orig(thisptr, x, y);
    CallInventorySectionGUIGetItemAbsolutePositionCallbacks(thisptr, x, y, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventorySectionGUI_getItemAbsolutePosition,
    "InventorySectionGUI::getItemAbsolutePosition", KenshiLib::GetRealAddress(&InventorySectionGUI::getItemAbsolutePosition),
    InventorySectionGUI_getItemAbsolutePosition_hook, InventorySectionGUI_getItemAbsolutePosition_orig)

static MyGUI::Widget* (*InventorySectionGUI_getWidget_orig)(InventorySectionGUI*) = NULL;
static MyGUI::Widget* InventorySectionGUI_getWidget_hook(InventorySectionGUI* thisptr)
{
    MyGUI::Widget* res = InventorySectionGUI_getWidget_orig(thisptr);
    CallInventorySectionGUIGetWidgetCallbacks(thisptr, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventorySectionGUI_getWidget,
    "InventorySectionGUI::getWidget", KenshiLib::GetRealAddress(&InventorySectionGUI::getWidget),
    InventorySectionGUI_getWidget_hook, InventorySectionGUI_getWidget_orig)

static MyGUI::types::TPoint<int> (*InventorySectionGUI_getPositionSlot_orig)(InventorySectionGUI*, const MyGUI::types::TPoint<int>&, InventorySection*, bool) = NULL;
static MyGUI::types::TPoint<int> InventorySectionGUI_getPositionSlot_hook(InventorySectionGUI* thisptr, const MyGUI::types::TPoint<int>& position, InventorySection* section, bool round)
{
    MyGUI::types::TPoint<int> res = InventorySectionGUI_getPositionSlot_orig(thisptr, position, section, round);
    CallInventorySectionGUIGetPositionSlotCallbacks(thisptr, position, section, round, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventorySectionGUI_getPositionSlot,
    "InventorySectionGUI::getPositionSlot", KenshiLib::GetRealAddress(&InventorySectionGUI::getPositionSlot),
    InventorySectionGUI_getPositionSlot_hook, InventorySectionGUI_getPositionSlot_orig)

static bool (*InventorySectionGUI_getBestPositionSlot_orig)(InventorySectionGUI*, const MyGUI::types::TPoint<int>&, InventorySection*, Item*, MyGUI::types::TPoint<int>&) = NULL;
static bool InventorySectionGUI_getBestPositionSlot_hook(InventorySectionGUI* thisptr, const MyGUI::types::TPoint<int>& position, InventorySection* section, Item* item, MyGUI::types::TPoint<int>& slot)
{
    bool res = InventorySectionGUI_getBestPositionSlot_orig(thisptr, position, section, item, slot);
    return CallInventorySectionGUIGetBestPositionSlotCallbacks(thisptr, position, section, item, slot, res);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventorySectionGUI_getBestPositionSlot,
    "InventorySectionGUI::getBestPositionSlot", KenshiLib::GetRealAddress(&InventorySectionGUI::getBestPositionSlot),
    InventorySectionGUI_getBestPositionSlot_hook, InventorySectionGUI_getBestPositionSlot_orig)

static void (*InventorySectionGUI_setEnabled_orig)(InventorySectionGUI*, bool) = NULL;
static void InventorySectionGUI_setEnabled_hook(InventorySectionGUI* thisptr, bool value)
{
    InventorySectionGUI_setEnabled_orig(thisptr, value);
    CallInventorySectionGUISetEnabledCallbacks(thisptr, value);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventorySectionGUI_setEnabled,
    "InventorySectionGUI::setEnabled", KenshiLib::GetRealAddress(&InventorySectionGUI::setEnabled),
    InventorySectionGUI_setEnabled_hook, InventorySectionGUI_setEnabled_orig)

static void (*InventorySectionGUI_refreshIcons_orig)(InventorySectionGUI*, InventorySection*) = NULL;
static void InventorySectionGUI_refreshIcons_hook(InventorySectionGUI* thisptr, InventorySection* section)
{
    InventorySectionGUI_refreshIcons_orig(thisptr, section);
    CallInventorySectionGUIRefreshIconsCallbacks(thisptr, section);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventorySectionGUI_refreshIcons,
    "InventorySectionGUI::refreshIcons", KenshiLib::GetRealAddress(&InventorySectionGUI::refreshIcons),
    InventorySectionGUI_refreshIcons_hook, InventorySectionGUI_refreshIcons_orig)

static void (*InventorySectionGUI_update_orig)(InventorySectionGUI*) = NULL;
static void InventorySectionGUI_update_hook(InventorySectionGUI* thisptr)
{
    InventorySectionGUI_update_orig(thisptr);
    CallInventorySectionGUIUpdateCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventorySectionGUI_update,
    "InventorySectionGUI::update", KenshiLib::GetRealAddress(&InventorySectionGUI::update),
    InventorySectionGUI_update_hook, InventorySectionGUI_update_orig)

static InventoryGUI::TradeResult* (*InventoryGUI_TradeResult_CONSTRUCTOR_orig)(InventoryGUI::TradeResult*, InventoryGUI::TradeResult::Enum) = NULL;
static InventoryGUI::TradeResult* InventoryGUI_TradeResult_CONSTRUCTOR_hook(InventoryGUI::TradeResult* thisptr, InventoryGUI::TradeResult::Enum value)
{
    InventoryGUI::TradeResult* res = InventoryGUI_TradeResult_CONSTRUCTOR_orig(thisptr, value);
    CallInventoryTradeResultConstructedCallbacks(thisptr, static_cast<int>(value));
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_TradeResult_CONSTRUCTOR,
    "InventoryGUI::TradeResult::_CONSTRUCTOR", KenshiLib::GetRealAddress(&InventoryGUI::TradeResult::_CONSTRUCTOR),
    InventoryGUI_TradeResult_CONSTRUCTOR_hook, InventoryGUI_TradeResult_CONSTRUCTOR_orig)

static bool (*InventoryGUI_TradeResult_operator_equals_orig)(const InventoryGUI::TradeResult*, const InventoryGUI::TradeResult&) = NULL;
static bool InventoryGUI_TradeResult_operator_equals_hook(const InventoryGUI::TradeResult* thisptr, const InventoryGUI::TradeResult& other)
{
    bool res = InventoryGUI_TradeResult_operator_equals_orig(thisptr, other);
    return static_cast<bool>(CallInventoryTradeResultEqualsCallbacks(const_cast<InventoryGUI::TradeResult*>(thisptr), const_cast<InventoryGUI::TradeResult*>(&other), res));
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_TradeResult_operator_equals,
    "InventoryGUI::TradeResult::operator==", KenshiLib::GetRealAddress(&InventoryGUI::TradeResult::operator==),
    InventoryGUI_TradeResult_operator_equals_hook, InventoryGUI_TradeResult_operator_equals_orig)

static bool (*InventoryGUI_TradeResult_operator_not_equals_orig)(const InventoryGUI::TradeResult*, const InventoryGUI::TradeResult&) = NULL;
static bool InventoryGUI_TradeResult_operator_not_equals_hook(const InventoryGUI::TradeResult* thisptr, const InventoryGUI::TradeResult& other)
{
    bool res = InventoryGUI_TradeResult_operator_not_equals_orig(thisptr, other);
    return static_cast<bool>(CallInventoryTradeResultNotEqualsCallbacks(const_cast<InventoryGUI::TradeResult*>(thisptr), const_cast<InventoryGUI::TradeResult*>(&other), res));
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_TradeResult_operator_not_equals,
    "InventoryGUI::TradeResult::operator!=", KenshiLib::GetRealAddress(&InventoryGUI::TradeResult::operator!=),
    InventoryGUI_TradeResult_operator_not_equals_hook, InventoryGUI_TradeResult_operator_not_equals_orig)

static void (*InventoryGUI_TradeResult_showMessage_orig)(InventoryGUI::TradeResult*) = NULL;
static void InventoryGUI_TradeResult_showMessage_hook(InventoryGUI::TradeResult* thisptr)
{
    InventoryGUI_TradeResult_showMessage_orig(thisptr);
    CallInventoryTradeResultShowMessageCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_TradeResult_showMessage,
    "InventoryGUI::TradeResult::showMessage", KenshiLib::GetRealAddress(&InventoryGUI::TradeResult::showMessage),
    InventoryGUI_TradeResult_showMessage_hook, InventoryGUI_TradeResult_showMessage_orig)

static void (*InventoryTradeResult_static_ShowMessage_orig)(InventoryGUI::TradeResult::Enum) = NULL;
static void InventoryTradeResult_static_ShowMessage_hook(InventoryGUI::TradeResult::Enum value)
{
    InventoryTradeResult_static_ShowMessage_orig(value);
    CallInventoryTradeResultStaticShowMessageCallbacks(static_cast<int>(value));
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryTradeResult_static_ShowMessage,
    "InventoryGUI::TradeResult::ShowMessage", KenshiLib::GetRealAddress(&InventoryGUI::TradeResult::ShowMessage),
    InventoryTradeResult_static_ShowMessage_hook, InventoryTradeResult_static_ShowMessage_orig)

static bool (*InventoryGUI_InventoryTradeData_isValid_orig)(const InventoryGUI::InventoryTradeData*) = NULL;
static bool InventoryGUI_InventoryTradeData_isValid_hook(const InventoryGUI::InventoryTradeData* thisptr)
{
    bool res = InventoryGUI_InventoryTradeData_isValid_orig(thisptr);
    return static_cast<bool>(CallInventoryTradeDataIsValidCallbacks(const_cast<InventoryGUI::InventoryTradeData*>(thisptr), res));
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_InventoryTradeData_isValid,
    "InventoryGUI::InventoryTradeData::isValid", KenshiLib::GetRealAddress(&InventoryGUI::InventoryTradeData::isValid),
    InventoryGUI_InventoryTradeData_isValid_hook, InventoryGUI_InventoryTradeData_isValid_orig)

static InventoryGUI::InventoryTradeData& (*InventoryTradeData_operator_assign_orig)(InventoryGUI::InventoryTradeData*, const InventoryGUI::InventoryTradeData&) = NULL;
static InventoryGUI::InventoryTradeData& InventoryTradeData_operator_assign_hook(InventoryGUI::InventoryTradeData* thisptr, const InventoryGUI::InventoryTradeData& that)
{
    InventoryGUI::InventoryTradeData& res = InventoryTradeData_operator_assign_orig(thisptr, that);
    CallInventoryTradeDataAssignCallbacks(thisptr, const_cast<InventoryGUI::InventoryTradeData*>(&that));
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryTradeData_operator_assign,
    "InventoryGUI::InventoryTradeData::operator=", KenshiLib::GetRealAddress(&InventoryGUI::InventoryTradeData::operator=),
    InventoryTradeData_operator_assign_hook, InventoryTradeData_operator_assign_orig)

static bool (*InventoryGUI_static_lockedItemCheck_orig)(LockedArmour*) = NULL;
static bool InventoryGUI_static_lockedItemCheck_hook(LockedArmour* item)
{
    bool res = InventoryGUI_static_lockedItemCheck_orig(item);
    return static_cast<bool>(CallInventoryGUILockedItemCheckCallbacks(item, res));
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_static_lockedItemCheck,
    "InventoryGUI::lockedItemCheck", KenshiLib::GetRealAddress(&InventoryGUI::lockedItemCheck),
    InventoryGUI_static_lockedItemCheck_hook, InventoryGUI_static_lockedItemCheck_orig)

static void (*InventoryGUI_static_setTradingTown_orig)(const hand&) = NULL;
static void InventoryGUI_static_setTradingTown_hook(const hand& town)
{
    InventoryGUI_static_setTradingTown_orig(town);
    CallInventoryGUISetTradingTownCallbacks(town);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_static_setTradingTown,
    "InventoryGUI::setTradingTown", KenshiLib::GetRealAddress(&InventoryGUI::setTradingTown),
    InventoryGUI_static_setTradingTown_hook, InventoryGUI_static_setTradingTown_orig)

static Town* (*InventoryGUI_static_getTradingTown_orig)() = NULL;
static Town* InventoryGUI_static_getTradingTown_hook()
{
    Town* res = InventoryGUI_static_getTradingTown_orig();
    Town* overrideRes = CallInventoryGUIGetTradingTownCallbacks(res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_static_getTradingTown,
    "InventoryGUI::getTradingTown", KenshiLib::GetRealAddress(&InventoryGUI::getTradingTown),
    InventoryGUI_static_getTradingTown_hook, InventoryGUI_static_getTradingTown_orig)

static void (*InventoryGUI_static_addTradePartner_orig)(InventoryGUI*, bool, bool, bool, const hand&) = NULL;
static void InventoryGUI_static_addTradePartner_hook(InventoryGUI* tradeWith, bool payment, bool canDrop, bool isPlayer, const hand& who)
{
    InventoryGUI_static_addTradePartner_orig(tradeWith, payment, canDrop, isPlayer, who);
    CallInventoryAddTradePartnerCallbacks(tradeWith, payment, canDrop, isPlayer, who);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_addTradePartner,
    "InventoryGUI::addTradePartner", KenshiLib::GetRealAddress(&InventoryGUI::addTradePartner),
    InventoryGUI_static_addTradePartner_hook, InventoryGUI_static_addTradePartner_orig)

static void (*InventoryGUI_static_removeTradePartner_orig)(InventoryGUI*) = NULL;
static void InventoryGUI_static_removeTradePartner_hook(InventoryGUI* tradeWith)
{
    InventoryGUI_static_removeTradePartner_orig(tradeWith);
    CallInventoryGUIRemoveTradePartnerCallbacks(tradeWith);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_static_removeTradePartner,
    "InventoryGUI::removeTradePartner", KenshiLib::GetRealAddress(&InventoryGUI::removeTradePartner),
    InventoryGUI_static_removeTradePartner_hook, InventoryGUI_static_removeTradePartner_orig)

static void (*InventoryGUI_static_clearTradePartners_orig)() = NULL;
static void InventoryGUI_static_clearTradePartners_hook()
{
    InventoryGUI_static_clearTradePartners_orig();
    CallInventoryGUIClearTradePartnersCallbacks();
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_static_clearTradePartners,
    "InventoryGUI::clearTradePartners", KenshiLib::GetRealAddress(&InventoryGUI::clearTradePartners),
    InventoryGUI_static_clearTradePartners_hook, InventoryGUI_static_clearTradePartners_orig)

static bool (*InventoryGUI_static_canDropMouseItemWithoutPaying_orig)(InventoryGUI*) = NULL;
static bool InventoryGUI_static_canDropMouseItemWithoutPaying_hook(InventoryGUI* cameFrom)
{
    bool res = InventoryGUI_static_canDropMouseItemWithoutPaying_orig(cameFrom);
    return static_cast<bool>(CallInventoryGUICanDropMouseItemWithoutPayingCallbacks(cameFrom, res));
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_static_canDropMouseItemWithoutPaying,
    "InventoryGUI::canDropMouseItemWithoutPaying", KenshiLib::GetRealAddress(&InventoryGUI::canDropMouseItemWithoutPaying),
    InventoryGUI_static_canDropMouseItemWithoutPaying_hook, InventoryGUI_static_canDropMouseItemWithoutPaying_orig)

static void (*InventoryGUI__NV_autoChangeSelectedObject_orig)(InventoryGUI*, const hand&) = NULL;
static void InventoryGUI__NV_autoChangeSelectedObject_hook(InventoryGUI* thisptr, const hand& obj)
{
    InventoryGUI__NV_autoChangeSelectedObject_orig(thisptr, obj);
    CallInventoryGUINVAutoChangeSelectedObjectCallbacks(thisptr, obj);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI__NV_autoChangeSelectedObject,
    "InventoryGUI::_NV_autoChangeSelectedObject", KenshiLib::GetRealAddress(&InventoryGUI::_NV_autoChangeSelectedObject),
    InventoryGUI__NV_autoChangeSelectedObject_hook, InventoryGUI__NV_autoChangeSelectedObject_orig)

static void (*InventoryGUI__NV_update_orig)(InventoryGUI*) = NULL;
static void InventoryGUI__NV_update_hook(InventoryGUI* thisptr)
{
    InventoryGUI__NV_update_orig(thisptr);
    CallInventoryGUINVUpdateCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI__NV_update,
    "InventoryGUI::_NV_update", KenshiLib::GetRealAddress(&InventoryGUI::_NV_update),
    InventoryGUI__NV_update_hook, InventoryGUI__NV_update_orig)

static void (*InventoryGUI__NV_show_orig)(InventoryGUI*, bool) = NULL;
static void InventoryGUI__NV_show_hook(InventoryGUI* thisptr, bool on)
{
    InventoryGUI__NV_show_orig(thisptr, on);
    CallInventoryGUINVShowCallbacks(thisptr, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI__NV_show,
    "InventoryGUI::_NV_show", KenshiLib::GetRealAddress(&InventoryGUI::_NV_show),
    InventoryGUI__NV_show_hook, InventoryGUI__NV_show_orig)

static void (*InventoryGUI__NV_setPositionReal_orig)(InventoryGUI*, float, float) = NULL;
static void InventoryGUI__NV_setPositionReal_hook(InventoryGUI* thisptr, float x, float y)
{
    InventoryGUI__NV_setPositionReal_orig(thisptr, x, y);
    CallInventoryGUINVSetPositionRealCallbacks(thisptr, x, y);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI__NV_setPositionReal,
    "InventoryGUI::_NV_setPositionReal", KenshiLib::GetRealAddress(&InventoryGUI::_NV_setPositionReal),
    InventoryGUI__NV_setPositionReal_hook, InventoryGUI__NV_setPositionReal_orig)

static bool (*InventoryGUI__NV_isVisible_orig)(const InventoryGUI*) = NULL;
static bool InventoryGUI__NV_isVisible_hook(const InventoryGUI* thisptr)
{
    bool res = InventoryGUI__NV_isVisible_orig(thisptr);
    return static_cast<bool>(CallInventoryGUINVIsVisibleCallbacks(const_cast<InventoryGUI*>(thisptr), res));
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI__NV_isVisible,
    "InventoryGUI::_NV_isVisible", KenshiLib::GetRealAddress(&InventoryGUI::_NV_isVisible),
    InventoryGUI__NV_isVisible_hook, InventoryGUI__NV_isVisible_orig)

static void (*InventoryGUI__NV_refreshSection_orig)(InventoryGUI*, InventorySection*) = NULL;
static void InventoryGUI__NV_refreshSection_hook(InventoryGUI* thisptr, InventorySection* section)
{
    InventoryGUI__NV_refreshSection_orig(thisptr, section);
    CallInventoryGUINVRefreshSectionCallbacks(thisptr, section);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI__NV_refreshSection,
    "InventoryGUI::_NV_refreshSection", KenshiLib::GetRealAddress(&InventoryGUI::_NV_refreshSection),
    InventoryGUI__NV_refreshSection_hook, InventoryGUI__NV_refreshSection_orig)

static void (*InventoryGUI_refreshSection_orig)(InventoryGUI*) = NULL;
static void InventoryGUI_refreshSection_hook(InventoryGUI* thisptr)
{
    InventoryGUI_refreshSection_orig(thisptr);
    CallInventoryGUIRefreshSectionCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_refreshSection,
    "InventoryGUI::refreshSection", KenshiLib::GetRealAddress(static_cast<void (InventoryGUI::*)()>(&InventoryGUI::refreshSection)),
    InventoryGUI_refreshSection_hook, InventoryGUI_refreshSection_orig)

static void (*InventoryGUI_autoArrangeButton_orig)(InventoryGUI*, MyGUI::Widget*) = NULL;
static void InventoryGUI_autoArrangeButton_hook(InventoryGUI* thisptr, MyGUI::Widget* sender)
{
    InventoryGUI_autoArrangeButton_orig(thisptr, sender);
    CallInventoryGUIAutoArrangeButtonCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_autoArrangeButton,
    "InventoryGUI::autoArrangeButton", KenshiLib::GetRealAddress(&InventoryGUI::autoArrangeButton),
    InventoryGUI_autoArrangeButton_hook, InventoryGUI_autoArrangeButton_orig)

static void (*InventoryGUI_openBackpackButton_orig)(InventoryGUI*, MyGUI::Widget*) = NULL;
static void InventoryGUI_openBackpackButton_hook(InventoryGUI* thisptr, MyGUI::Widget* sender)
{
    InventoryGUI_openBackpackButton_orig(thisptr, sender);
    CallInventoryGUIOpenBackpackButtonCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_openBackpackButton,
    "InventoryGUI::openBackpackButton", KenshiLib::GetRealAddress(&InventoryGUI::openBackpackButton),
    InventoryGUI_openBackpackButton_hook, InventoryGUI_openBackpackButton_orig)

static void (*InventoryGUI_openLimbsInterface_orig)(InventoryGUI*, MyGUI::Widget*) = NULL;
static void InventoryGUI_openLimbsInterface_hook(InventoryGUI* thisptr, MyGUI::Widget* sender)
{
    InventoryGUI_openLimbsInterface_orig(thisptr, sender);
    CallInventoryGUIOpenLimbsInterfaceCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_openLimbsInterface,
    "InventoryGUI::openLimbsInterface", KenshiLib::GetRealAddress(&InventoryGUI::openLimbsInterface),
    InventoryGUI_openLimbsInterface_hook, InventoryGUI_openLimbsInterface_orig)

static void (*InventoryGUI_showBackpack_orig)(InventoryGUI*, bool) = NULL;
static void InventoryGUI_showBackpack_hook(InventoryGUI* thisptr, bool on)
{
    InventoryGUI_showBackpack_orig(thisptr, on);
    CallInventoryGUIShowBackpackCallbacks(thisptr, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_showBackpack,
    "InventoryGUI::showBackpack", KenshiLib::GetRealAddress(&InventoryGUI::showBackpack),
    InventoryGUI_showBackpack_hook, InventoryGUI_showBackpack_orig)

static ContainerItem* (*InventoryGUI_getBackpack_orig)(InventoryGUI*) = NULL;
static ContainerItem* InventoryGUI_getBackpack_hook(InventoryGUI* thisptr)
{
    ContainerItem* res = InventoryGUI_getBackpack_orig(thisptr);
    ContainerItem* overrideRes = CallInventoryGUIGetBackpackCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_getBackpack,
    "InventoryGUI::getBackpack", KenshiLib::GetRealAddress(&InventoryGUI::getBackpack),
    InventoryGUI_getBackpack_hook, InventoryGUI_getBackpack_orig)

static void (*InventoryGUI_windowButtonPressed_orig)(InventoryGUI*, MyGUI::Window*, const std::string&) = NULL;
static void InventoryGUI_windowButtonPressed_hook(InventoryGUI* thisptr, MyGUI::Window* widget, const std::string& name)
{
    InventoryGUI_windowButtonPressed_orig(thisptr, widget, name);
    CallInventoryGUIWindowButtonPressedCallbacks(thisptr, widget, name);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_windowButtonPressed,
    "InventoryGUI::windowButtonPressed", KenshiLib::GetRealAddress(&InventoryGUI::windowButtonPressed),
    InventoryGUI_windowButtonPressed_hook, InventoryGUI_windowButtonPressed_orig)

static Inventory* (*InventoryGUI__NV_getInventory_orig)(InventoryGUI*) = NULL;
static Inventory* InventoryGUI__NV_getInventory_hook(InventoryGUI* thisptr)
{
    Inventory* res = InventoryGUI__NV_getInventory_orig(thisptr);
    Inventory* overrideRes = CallInventoryGUINVGetInventoryCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI__NV_getInventory,
    "InventoryGUI::_NV_getInventory", KenshiLib::GetRealAddress(&InventoryGUI::_NV_getInventory),
    InventoryGUI__NV_getInventory_hook, InventoryGUI__NV_getInventory_orig)

static bool (*InventoryGUI_hasSameOwner_orig)(const InventoryGUI*, const InventoryGUI*) = NULL;
static bool InventoryGUI_hasSameOwner_hook(const InventoryGUI* thisptr, const InventoryGUI* other)
{
    bool res = InventoryGUI_hasSameOwner_orig(thisptr, other);
    return static_cast<bool>(CallInventoryGUIHasSameOwnerCallbacks(const_cast<InventoryGUI*>(thisptr), const_cast<InventoryGUI*>(other), res));
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_hasSameOwner,
    "InventoryGUI::hasSameOwner", KenshiLib::GetRealAddress(&InventoryGUI::hasSameOwner),
    InventoryGUI_hasSameOwner_hook, InventoryGUI_hasSameOwner_orig)

static Character* (*InventoryGUI__NV_getCallbackCharacter_orig)(InventoryGUI*) = NULL;
static Character* InventoryGUI__NV_getCallbackCharacter_hook(InventoryGUI* thisptr)
{
    Character* res = InventoryGUI__NV_getCallbackCharacter_orig(thisptr);
    Character* overrideRes = CallInventoryGUINVGetCallbackCharacterCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI__NV_getCallbackCharacter,
    "InventoryGUI::_NV_getCallbackCharacter", KenshiLib::GetRealAddress(&InventoryGUI::_NV_getCallbackCharacter),
    InventoryGUI__NV_getCallbackCharacter_hook, InventoryGUI__NV_getCallbackCharacter_orig)

static RootObject* (*InventoryGUI__NV_getCallbackObject_orig)(const InventoryGUI*) = NULL;
static RootObject* InventoryGUI__NV_getCallbackObject_hook(const InventoryGUI* thisptr)
{
    RootObject* res = InventoryGUI__NV_getCallbackObject_orig(thisptr);
    RootObject* overrideRes = CallInventoryGUINVGetCallbackObjectCallbacks(const_cast<InventoryGUI*>(thisptr), res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI__NV_getCallbackObject,
    "InventoryGUI::_NV_getCallbackObject", KenshiLib::GetRealAddress(&InventoryGUI::_NV_getCallbackObject),
    InventoryGUI__NV_getCallbackObject_hook, InventoryGUI__NV_getCallbackObject_orig)

static Item* (*InventoryGUI_getSelectedItem_orig)(InventoryGUI*, const std::string&) = NULL;
static Item* InventoryGUI_getSelectedItem_hook(InventoryGUI* thisptr, const std::string& sectionName)
{
    Item* res = InventoryGUI_getSelectedItem_orig(thisptr, sectionName);
    Item* overrideRes = CallInventoryGUIGetSelectedItemCallbacks(thisptr, sectionName, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_getSelectedItem,
    "InventoryGUI::getSelectedItem", KenshiLib::GetRealAddress(&InventoryGUI::getSelectedItem),
    InventoryGUI_getSelectedItem_hook, InventoryGUI_getSelectedItem_orig)

static MyGUI::types::TCoord<int> (*InventoryGUI_getWindowCoord_orig)(InventoryGUI*) = NULL;
static MyGUI::types::TCoord<int> InventoryGUI_getWindowCoord_hook(InventoryGUI* thisptr)
{
    MyGUI::types::TCoord<int> res = InventoryGUI_getWindowCoord_orig(thisptr);
    CallInventoryGUIGetWindowCoordCallbacks(thisptr, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_getWindowCoord,
    "InventoryGUI::getWindowCoord", KenshiLib::GetRealAddress(&InventoryGUI::getWindowCoord),
    InventoryGUI_getWindowCoord_hook, InventoryGUI_getWindowCoord_orig)

static void (*InventoryGUI_stealingGUIInfoUpdate_orig)(InventoryGUI*) = NULL;
static void InventoryGUI_stealingGUIInfoUpdate_hook(InventoryGUI* thisptr)
{
    InventoryGUI_stealingGUIInfoUpdate_orig(thisptr);
    CallInventoryGUIStealingGUIInfoUpdateCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_stealingGUIInfoUpdate,
    "InventoryGUI::stealingGUIInfoUpdate", KenshiLib::GetRealAddress(&InventoryGUI::stealingGUIInfoUpdate),
    InventoryGUI_stealingGUIInfoUpdate_hook, InventoryGUI_stealingGUIInfoUpdate_orig)

static void (*InventoryGUI_getTrader1Trader2_orig)(InventoryGUI*, InventoryGUI*&, InventoryGUI*&) = NULL;
static void InventoryGUI_getTrader1Trader2_hook(InventoryGUI* thisptr, InventoryGUI*& trader1, InventoryGUI*& trader2)
{
    InventoryGUI_getTrader1Trader2_orig(thisptr, trader1, trader2);
    CallInventoryGUIGetTrader1Trader2Callbacks(thisptr, trader1, trader2);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_getTrader1Trader2,
    "InventoryGUI::getTrader1Trader2", KenshiLib::GetRealAddress(&InventoryGUI::getTrader1Trader2),
    InventoryGUI_getTrader1Trader2_hook, InventoryGUI_getTrader1Trader2_orig)

static Character* (*InventoryGUI_static_getNPCTrader_orig)() = NULL;
static Character* InventoryGUI_static_getNPCTrader_hook()
{
    Character* res = InventoryGUI_static_getNPCTrader_orig();
    Character* overrideRes = CallInventoryGUIGetNPCTraderCallbacks(res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_static_getNPCTrader,
    "InventoryGUI::getNPCTrader", KenshiLib::GetRealAddress(&InventoryGUI::getNPCTrader),
    InventoryGUI_static_getNPCTrader_hook, InventoryGUI_static_getNPCTrader_orig)

static RootObject* (*InventoryGUI_static_isTradingForMoney_static_orig)() = NULL;
static RootObject* InventoryGUI_static_isTradingForMoney_static_hook()
{
    RootObject* res = InventoryGUI_static_isTradingForMoney_static_orig();
    RootObject* overrideRes = CallInventoryGUIIsTradingForMoneyStaticCallbacks(res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_static_isTradingForMoney_static,
    "InventoryGUI::isTradingForMoney_static", KenshiLib::GetRealAddress(&InventoryGUI::isTradingForMoney_static),
    InventoryGUI_static_isTradingForMoney_static_hook, InventoryGUI_static_isTradingForMoney_static_orig)

static RootObject* (*InventoryGUI_static_isTradingAndStealing_static_orig)() = NULL;
static RootObject* InventoryGUI_static_isTradingAndStealing_static_hook()
{
    RootObject* res = InventoryGUI_static_isTradingAndStealing_static_orig();
    RootObject* overrideRes = CallInventoryGUIIsTradingAndStealingStaticCallbacks(res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_static_isTradingAndStealing_static,
    "InventoryGUI::isTradingAndStealing_static", KenshiLib::GetRealAddress(&InventoryGUI::isTradingAndStealing_static),
    InventoryGUI_static_isTradingAndStealing_static_hook, InventoryGUI_static_isTradingAndStealing_static_orig)

static float (*InventoryGUI_static_getTraderPriceMultiplier_orig)() = NULL;
static float InventoryGUI_static_getTraderPriceMultiplier_hook()
{
    float res = InventoryGUI_static_getTraderPriceMultiplier_orig();
    return static_cast<float>(CallInventoryGUIGetTraderPriceMultiplierCallbacks(res));
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_static_getTraderPriceMultiplier,
    "InventoryGUI::getTraderPriceMultiplier", KenshiLib::GetRealAddress(&InventoryGUI::getTraderPriceMultiplier),
    InventoryGUI_static_getTraderPriceMultiplier_hook, InventoryGUI_static_getTraderPriceMultiplier_orig)

static InventoryGUI* (*InventoryGUI_CONSTRUCTOR_orig)(InventoryGUI*, Inventory*, InventoryLayout*, RootObject*) = NULL;
static InventoryGUI* InventoryGUI_CONSTRUCTOR_hook(InventoryGUI* thisptr, Inventory* inventory, InventoryLayout* layout, RootObject* callback)
{
    InventoryGUI* res = InventoryGUI_CONSTRUCTOR_orig(thisptr, inventory, layout, callback);
    InventoryGUI* overrideRes = CallInventoryGUIConstructedCallbacks(thisptr, inventory, layout, callback, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_CONSTRUCTOR,
    "InventoryGUI::_CONSTRUCTOR", KenshiLib::GetRealAddress(&InventoryGUI::_CONSTRUCTOR),
    InventoryGUI_CONSTRUCTOR_hook, InventoryGUI_CONSTRUCTOR_orig)

static void (*InventoryGUI_DESTRUCTOR_orig)(InventoryGUI*) = NULL;
static void InventoryGUI_DESTRUCTOR_hook(InventoryGUI* thisptr)
{
    CallInventoryGUIDestructorCallbacks(thisptr);
    InventoryGUI_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_DESTRUCTOR,
    "InventoryGUI::_DESTRUCTOR", KenshiLib::GetRealAddress(&InventoryGUI::_DESTRUCTOR),
    InventoryGUI_DESTRUCTOR_hook, InventoryGUI_DESTRUCTOR_orig)

static bool (*InventoryGUI_pickupItemToMouse_orig)(InventoryGUI*, const std::string) = NULL;
static bool InventoryGUI_pickupItemToMouse_hook(InventoryGUI* thisptr, const std::string sectionName)
{
    bool res = InventoryGUI_pickupItemToMouse_orig(thisptr, sectionName);
    return static_cast<bool>(CallInventoryGUIPickupItemToMouseCallbacks(thisptr, sectionName, res));
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_pickupItemToMouse,
    "InventoryGUI::pickupItemToMouse", KenshiLib::GetRealAddress(&InventoryGUI::pickupItemToMouse),
    InventoryGUI_pickupItemToMouse_hook, InventoryGUI_pickupItemToMouse_orig)

static bool (*InventoryGUI_placeItemFromMouse_orig)(InventoryGUI*, const std::string, const MyGUI::types::TPoint<int>&) = NULL;
static bool InventoryGUI_placeItemFromMouse_hook(InventoryGUI* thisptr, const std::string sectionName, const MyGUI::types::TPoint<int>& mousePos)
{
    bool res = InventoryGUI_placeItemFromMouse_orig(thisptr, sectionName, mousePos);
    return static_cast<bool>(CallInventoryGUIPlaceItemFromMouseCallbacks(thisptr, sectionName, mousePos, res));
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_placeItemFromMouse,
    "InventoryGUI::placeItemFromMouse", KenshiLib::GetRealAddress(&InventoryGUI::placeItemFromMouse),
    InventoryGUI_placeItemFromMouse_hook, InventoryGUI_placeItemFromMouse_orig)

static Item* (*InventoryGUI_getMouseItem_orig)(InventoryGUI*) = NULL;
static Item* InventoryGUI_getMouseItem_hook(InventoryGUI* thisptr)
{
    Item* res = InventoryGUI_getMouseItem_orig(thisptr);
    Item* overrideRes = CallInventoryGUIGetMouseItemCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_getMouseItem,
    "InventoryGUI::getMouseItem", KenshiLib::GetRealAddress(&InventoryGUI::getMouseItem),
    InventoryGUI_getMouseItem_hook, InventoryGUI_getMouseItem_orig)

static Item* (*InventoryGUI_takeCertainAmountFrom_orig)(InventoryGUI*, Item*, int) = NULL;
static Item* InventoryGUI_takeCertainAmountFrom_hook(InventoryGUI* thisptr, Item* baseItem, int amount)
{
    Item* res = InventoryGUI_takeCertainAmountFrom_orig(thisptr, baseItem, amount);
    Item* overrideRes = CallInventoryGUITakeCertainAmountFromCallbacks(thisptr, baseItem, amount, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_takeCertainAmountFrom,
    "InventoryGUI::takeCertainAmountFrom", KenshiLib::GetRealAddress(&InventoryGUI::takeCertainAmountFrom),
    InventoryGUI_takeCertainAmountFrom_hook, InventoryGUI_takeCertainAmountFrom_orig)

static InventoryGUI::TradeResult (*InventoryGUI_RClickAutoTrade_orig)(InventoryGUI*, const std::string&, int, int, InventoryGUI*, bool, bool) = NULL;
static InventoryGUI::TradeResult InventoryGUI_RClickAutoTrade_hook(InventoryGUI* thisptr, const std::string& invSectionName, int x, int y, InventoryGUI* sendingTo, bool thieveryChecks, bool first)
{
    InventoryGUI::TradeResult res = InventoryGUI_RClickAutoTrade_orig(thisptr, invSectionName, x, y, sendingTo, thieveryChecks, first);
    CallInventoryGUIRClickAutoTradeCallbacks(thisptr, invSectionName, x, y, sendingTo, thieveryChecks, first, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_RClickAutoTrade,
    "InventoryGUI::RClickAutoTrade", KenshiLib::GetRealAddress(&InventoryGUI::RClickAutoTrade),
    InventoryGUI_RClickAutoTrade_hook, InventoryGUI_RClickAutoTrade_orig)

static InventoryGUI::TradeResult (*InventoryGUI_RClickAutoTradeAll_orig)(InventoryGUI*, const std::string&, int, int, InventoryGUI*, bool, bool) = NULL;
static InventoryGUI::TradeResult InventoryGUI_RClickAutoTradeAll_hook(InventoryGUI* thisptr, const std::string& invSectionName, int x, int y, InventoryGUI* sendingTo, bool thieveryChecks, bool first)
{
    InventoryGUI::TradeResult res = InventoryGUI_RClickAutoTradeAll_orig(thisptr, invSectionName, x, y, sendingTo, thieveryChecks, first);
    CallInventoryGUIRClickAutoTradeAllCallbacks(thisptr, invSectionName, x, y, sendingTo, thieveryChecks, first, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_RClickAutoTradeAll,
    "InventoryGUI::RClickAutoTradeAll", KenshiLib::GetRealAddress(&InventoryGUI::RClickAutoTradeAll),
    InventoryGUI_RClickAutoTradeAll_hook, InventoryGUI_RClickAutoTradeAll_orig)

static bool (*InventoryGUI_isTradingForMoney_orig)(InventoryGUI*, InventoryGUI*) = NULL;
static bool InventoryGUI_isTradingForMoney_hook(InventoryGUI* thisptr, InventoryGUI* cameFrom)
{
    bool res = InventoryGUI_isTradingForMoney_orig(thisptr, cameFrom);
    return static_cast<bool>(CallInventoryGUIIsTradingForMoneyCallbacks(thisptr, cameFrom, res));
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_isTradingForMoney,
    "InventoryGUI::isTradingForMoney", KenshiLib::GetRealAddress(&InventoryGUI::isTradingForMoney),
    InventoryGUI_isTradingForMoney_hook, InventoryGUI_isTradingForMoney_orig)

static bool (*InventoryGUI_isStealing_orig)(InventoryGUI*, InventoryGUI*) = NULL;
static bool InventoryGUI_isStealing_hook(InventoryGUI* thisptr, InventoryGUI* cameFrom)
{
    bool res = InventoryGUI_isStealing_orig(thisptr, cameFrom);
    return static_cast<bool>(CallInventoryGUIIsStealingCallbacks(thisptr, cameFrom, res));
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_isStealing,
    "InventoryGUI::isStealing", KenshiLib::GetRealAddress(&InventoryGUI::isStealing),
    InventoryGUI_isStealing_hook, InventoryGUI_isStealing_orig)

static bool (*InventoryGUI_isWithinRangeToTrade_orig)(InventoryGUI*, RootObject*, bool) = NULL;
static bool InventoryGUI_isWithinRangeToTrade_hook(InventoryGUI* thisptr, RootObject* otherOwner, bool stealing)
{
    bool res = InventoryGUI_isWithinRangeToTrade_orig(thisptr, otherOwner, stealing);
    return static_cast<bool>(CallInventoryGUIIsWithinRangeToTradeCallbacks(thisptr, otherOwner, stealing, res));
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_isWithinRangeToTrade,
    "InventoryGUI::isWithinRangeToTrade", KenshiLib::GetRealAddress(&InventoryGUI::isWithinRangeToTrade),
    InventoryGUI_isWithinRangeToTrade_hook, InventoryGUI_isWithinRangeToTrade_orig)

static bool (*InventoryGUI_setItemToPlayerPortrait_orig)(InventoryGUI*, Item*, Character*) = NULL;
static bool InventoryGUI_setItemToPlayerPortrait_hook(InventoryGUI* thisptr, Item* item, Character* character)
{
    bool res = InventoryGUI_setItemToPlayerPortrait_orig(thisptr, item, character);
    return static_cast<bool>(CallInventoryGUISetItemToPlayerPortraitCallbacks(thisptr, item, character, res));
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_setItemToPlayerPortrait,
    "InventoryGUI::setItemToPlayerPortrait", KenshiLib::GetRealAddress(&InventoryGUI::setItemToPlayerPortrait),
    InventoryGUI_setItemToPlayerPortrait_hook, InventoryGUI_setItemToPlayerPortrait_orig)

static void (*InventoryGUI_playSound_orig)(InventoryGUI*, const char*, Item*) = NULL;
static void InventoryGUI_playSound_hook(InventoryGUI* thisptr, const char* eventId, Item* item)
{
    InventoryGUI_playSound_orig(thisptr, eventId, item);
    CallInventoryGUIPlaySoundCallbacks(thisptr, std::string(eventId ? eventId : ""), item);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_playSound,
    "InventoryGUI::playSound", KenshiLib::GetRealAddress(&InventoryGUI::playSound),
    InventoryGUI_playSound_hook, InventoryGUI_playSound_orig)

static void (*InventoryGUI_FenceCallbackData_DESTRUCTOR_orig)(InventoryGUI::FenceCallbackData*) = NULL;
static void InventoryGUI_FenceCallbackData_DESTRUCTOR_hook(InventoryGUI::FenceCallbackData* thisptr)
{
    CallInventoryGUIFenceCallbackDataDestructorCallbacks(thisptr);
    InventoryGUI_FenceCallbackData_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_FenceCallbackData_DESTRUCTOR,
    "InventoryGUI::FenceCallbackData::_DESTRUCTOR", KenshiLib::GetRealAddress(&InventoryGUI::FenceCallbackData::_DESTRUCTOR),
    InventoryGUI_FenceCallbackData_DESTRUCTOR_hook, InventoryGUI_FenceCallbackData_DESTRUCTOR_orig)

static bool (*InventoryGUI_fencingConfirmation_orig)(InventoryGUI*, Item*, RootObject*, Character*, const std::string&, MyGUI::types::TPoint<int>) = NULL;
static bool InventoryGUI_fencingConfirmation_hook(InventoryGUI* thisptr, Item* item, RootObject* thief, Character* fence, const std::string& sectionName, MyGUI::types::TPoint<int> mouse)
{
    bool res = InventoryGUI_fencingConfirmation_orig(thisptr, item, thief, fence, sectionName, mouse);
    return static_cast<bool>(CallInventoryGUIFencingConfirmationResultCallbacks(thisptr, item, thief, fence, sectionName, mouse, res));
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_fencingConfirmation,
    "InventoryGUI::fencingConfirmation", KenshiLib::GetRealAddress(&InventoryGUI::fencingConfirmation),
    InventoryGUI_fencingConfirmation_hook, InventoryGUI_fencingConfirmation_orig)

static void (*InventoryGUI_fencingConfirmationCallback_orig)(InventoryGUI*, int) = NULL;
static void InventoryGUI_fencingConfirmationCallback_hook(InventoryGUI* thisptr, int b)
{
    InventoryGUI_fencingConfirmationCallback_orig(thisptr, b);
    CallInventoryGUIFencingConfirmationCallbacks(thisptr, b);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_fencingConfirmationCallback,
    "InventoryGUI::fencingConfirmationCallback", KenshiLib::GetRealAddress(&InventoryGUI::fencingConfirmationCallback),
    InventoryGUI_fencingConfirmationCallback_hook, InventoryGUI_fencingConfirmationCallback_orig)

static RootObject* (*InventoryGUI_getPlayerTradeCharacter_orig)(InventoryGUI*) = NULL;
static RootObject* InventoryGUI_getPlayerTradeCharacter_hook(InventoryGUI* thisptr)
{
    RootObject* res = InventoryGUI_getPlayerTradeCharacter_orig(thisptr);
    RootObject* overrideRes = CallInventoryGUIGetPlayerTradeCharacterCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_getPlayerTradeCharacter,
    "InventoryGUI::getPlayerTradeCharacter", KenshiLib::GetRealAddress(&InventoryGUI::getPlayerTradeCharacter),
    InventoryGUI_getPlayerTradeCharacter_hook, InventoryGUI_getPlayerTradeCharacter_orig)

static void (*InventoryGUI_refreshAllSections_orig)(InventoryGUI*) = NULL;
static void InventoryGUI_refreshAllSections_hook(InventoryGUI* thisptr)
{
    InventoryGUI_refreshAllSections_orig(thisptr);
    CallInventoryGUIRefreshAllSectionsCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_refreshAllSections,
    "InventoryGUI::refreshAllSections", KenshiLib::GetRealAddress(&InventoryGUI::refreshAllSections),
    InventoryGUI_refreshAllSections_hook, InventoryGUI_refreshAllSections_orig)

static void (*InventoryGUI_updateDatapanel_orig)(InventoryGUI*) = NULL;
static void InventoryGUI_updateDatapanel_hook(InventoryGUI* thisptr)
{
    InventoryGUI_updateDatapanel_orig(thisptr);
    CallInventoryGUIUpdateDatapanelCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_updateDatapanel,
    "InventoryGUI::updateDatapanel", KenshiLib::GetRealAddress(&InventoryGUI::updateDatapanel),
    InventoryGUI_updateDatapanel_hook, InventoryGUI_updateDatapanel_orig)

static void (*InventoryGUI_rightClickAutoEquipping_orig)(InventoryGUI*) = NULL;
static void InventoryGUI_rightClickAutoEquipping_hook(InventoryGUI* thisptr)
{
    InventoryGUI_rightClickAutoEquipping_orig(thisptr);
    CallInventoryGUIRightClickAutoEquippingCallbacks(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_rightClickAutoEquipping,
    "InventoryGUI::rightClickAutoEquipping", KenshiLib::GetRealAddress(&InventoryGUI::rightClickAutoEquipping),
    InventoryGUI_rightClickAutoEquipping_hook, InventoryGUI_rightClickAutoEquipping_orig)

static bool (*InventoryGUI_tryToEquip_orig)(InventoryGUI*, Item*, bool) = NULL;
static bool InventoryGUI_tryToEquip_hook(InventoryGUI* thisptr, Item* item, bool replace)
{
    bool res = InventoryGUI_tryToEquip_orig(thisptr, item, replace);
    return static_cast<bool>(CallInventoryGUITryToEquipCallbacks(thisptr, item, replace, res));
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_tryToEquip,
    "InventoryGUI::tryToEquip", KenshiLib::GetRealAddress(&InventoryGUI::tryToEquip),
    InventoryGUI_tryToEquip_hook, InventoryGUI_tryToEquip_orig)

static void (*InventoryGUI_returnItem_orig)(InventoryGUI*, Item*, const std::string&) = NULL;
static void InventoryGUI_returnItem_hook(InventoryGUI* thisptr, Item* item, const std::string& sectionName)
{
    InventoryGUI_returnItem_orig(thisptr, item, sectionName);
    CallInventoryGUIReturnItemCallbacks(thisptr, item, sectionName);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_returnItem,
    "InventoryGUI::returnItem", KenshiLib::GetRealAddress(&InventoryGUI::returnItem),
    InventoryGUI_returnItem_hook, InventoryGUI_returnItem_orig)

static bool (*InventoryGUI_hasMouse_orig)(const InventoryGUI*) = NULL;
static bool InventoryGUI_hasMouse_hook(const InventoryGUI* thisptr)
{
    bool res = InventoryGUI_hasMouse_orig(thisptr);
    return static_cast<bool>(CallInventoryGUIHasMouseCallbacks(const_cast<InventoryGUI*>(thisptr), res));
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_hasMouse,
    "InventoryGUI::hasMouse", KenshiLib::GetRealAddress(&InventoryGUI::hasMouse),
    InventoryGUI_hasMouse_hook, InventoryGUI_hasMouse_orig)

static std::string (*InventoryGUI_getSectionWithMouseLocal_orig)(InventoryGUI*) = NULL;
static std::string InventoryGUI_getSectionWithMouseLocal_hook(InventoryGUI* thisptr)
{
    std::string res = InventoryGUI_getSectionWithMouseLocal_orig(thisptr);
    CallInventoryGUIGetSectionWithMouseLocalCallbacks(thisptr, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_getSectionWithMouseLocal,
    "InventoryGUI::getSectionWithMouseLocal", KenshiLib::GetRealAddress(&InventoryGUI::getSectionWithMouseLocal),
    InventoryGUI_getSectionWithMouseLocal_hook, InventoryGUI_getSectionWithMouseLocal_orig)

static iVector2 (*InventoryGUI_getSlotWithMouse_orig)(InventoryGUI*) = NULL;
static iVector2 InventoryGUI_getSlotWithMouse_hook(InventoryGUI* thisptr)
{
    iVector2 res = InventoryGUI_getSlotWithMouse_orig(thisptr);
    CallInventoryGUIGetSlotWithMouseCallbacks(thisptr, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_getSlotWithMouse,
    "InventoryGUI::getSlotWithMouse", KenshiLib::GetRealAddress(&InventoryGUI::getSlotWithMouse),
    InventoryGUI_getSlotWithMouse_hook, InventoryGUI_getSlotWithMouse_orig)

static void (*InventoryGUI_sectionMouseButtonPressed_orig)(InventoryGUI*, MyGUI::Widget*, int, int, MyGUI::MouseButton) = NULL;
static void InventoryGUI_sectionMouseButtonPressed_hook(InventoryGUI* thisptr, MyGUI::Widget* sender, int left, int top, MyGUI::MouseButton id)
{
    InventoryGUI_sectionMouseButtonPressed_orig(thisptr, sender, left, top, id);
    CallInventoryGUISectionMouseButtonPressedCallbacks(thisptr, sender, left, top, id.getValue());
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_sectionMouseButtonPressed,
    "InventoryGUI::sectionMouseButtonPressed", KenshiLib::GetRealAddress(&InventoryGUI::sectionMouseButtonPressed),
    InventoryGUI_sectionMouseButtonPressed_hook, InventoryGUI_sectionMouseButtonPressed_orig)

static void (*InventoryGUI_sectionMouseButtonReleased_orig)(InventoryGUI*, MyGUI::Widget*, int, int, MyGUI::MouseButton) = NULL;
static void InventoryGUI_sectionMouseButtonReleased_hook(InventoryGUI* thisptr, MyGUI::Widget* sender, int left, int top, MyGUI::MouseButton id)
{
    InventoryGUI_sectionMouseButtonReleased_orig(thisptr, sender, left, top, id);
    CallInventoryGUISectionMouseButtonReleasedCallbacks(thisptr, sender, left, top, id.getValue());
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_sectionMouseButtonReleased,
    "InventoryGUI::sectionMouseButtonReleased", KenshiLib::GetRealAddress(&InventoryGUI::sectionMouseButtonReleased),
    InventoryGUI_sectionMouseButtonReleased_hook, InventoryGUI_sectionMouseButtonReleased_orig)

static void (*InventoryGUI_onWindowFocus_orig)(InventoryGUI*, MyGUI::Widget*, bool) = NULL;
static void InventoryGUI_onWindowFocus_hook(InventoryGUI* thisptr, MyGUI::Widget* sender, bool focus)
{
    InventoryGUI_onWindowFocus_orig(thisptr, sender, focus);
    CallInventoryGUIOnWindowFocusCallbacks(thisptr, sender, focus);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_onWindowFocus,
    "InventoryGUI::onWindowFocus", KenshiLib::GetRealAddress(&InventoryGUI::onWindowFocus),
    InventoryGUI_onWindowFocus_hook, InventoryGUI_onWindowFocus_orig)

static void (*InventoryGUI_windowMoved_orig)(InventoryGUI*, MyGUI::Window*) = NULL;
static void InventoryGUI_windowMoved_hook(InventoryGUI* thisptr, MyGUI::Window* sender)
{
    InventoryGUI_windowMoved_orig(thisptr, sender);
    CallInventoryGUIWindowMovedCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_windowMoved,
    "InventoryGUI::windowMoved", KenshiLib::GetRealAddress(&InventoryGUI::windowMoved),
    InventoryGUI_windowMoved_hook, InventoryGUI_windowMoved_orig)

static InventoryIcon* (*InventoryGUI_static_makeIconForItem_orig)(Item*, int, int) = NULL;
static InventoryIcon* InventoryGUI_static_makeIconForItem_hook(Item* item, int x, int y)
{
    InventoryIcon* res = InventoryGUI_static_makeIconForItem_orig(item, x, y);
    InventoryIcon* overrideRes = CallInventoryGUIMakeIconForItemCallbacks(item, x, y, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_static_makeIconForItem,
    "InventoryGUI::makeIconForItem", KenshiLib::GetRealAddress(&InventoryGUI::makeIconForItem),
    InventoryGUI_static_makeIconForItem_hook, InventoryGUI_static_makeIconForItem_orig)

static InventoryLayout* (*InventoryLayout_CONSTRUCTOR_orig)(InventoryLayout*, const std::string&) = NULL;
static InventoryLayout* InventoryLayout_CONSTRUCTOR_hook(InventoryLayout* thisptr, const std::string& file)
{
    InventoryLayout* res = InventoryLayout_CONSTRUCTOR_orig(thisptr, file);
    CallInventoryLayoutConstructedCallbacks(thisptr, file);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryLayout_CONSTRUCTOR,
    "InventoryLayout::_CONSTRUCTOR", KenshiLib::GetRealAddress(&InventoryLayout::_CONSTRUCTOR),
    InventoryLayout_CONSTRUCTOR_hook, InventoryLayout_CONSTRUCTOR_orig)

static void (*InventoryLayout_DESTRUCTOR_orig)(InventoryLayout*) = NULL;
static void InventoryLayout_DESTRUCTOR_hook(InventoryLayout* thisptr)
{
    CallInventoryLayoutDestructorCallbacks(thisptr);
    InventoryLayout_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryLayout_DESTRUCTOR,
    "InventoryLayout::_DESTRUCTOR", KenshiLib::GetRealAddress(&InventoryLayout::_DESTRUCTOR),
    InventoryLayout_DESTRUCTOR_hook, InventoryLayout_DESTRUCTOR_orig)

static MyGUI::Window* (*InventoryLayout_getWindow_orig)(const InventoryLayout*) = NULL;
static MyGUI::Window* InventoryLayout_getWindow_hook(const InventoryLayout* thisptr)
{
    MyGUI::Window* res = InventoryLayout_getWindow_orig(thisptr);
    CallInventoryLayoutGetWindowCallbacks(const_cast<InventoryLayout*>(thisptr), res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryLayout_getWindow,
    "InventoryLayout::getWindow", KenshiLib::GetRealAddress(&InventoryLayout::getWindow),
    InventoryLayout_getWindow_hook, InventoryLayout_getWindow_orig)

static MyGUI::Widget* (*InventoryLayout_getWidget_orig)(InventoryLayout*, const std::string&) = NULL;
static MyGUI::Widget* InventoryLayout_getWidget_hook(InventoryLayout* thisptr, const std::string& name)
{
    MyGUI::Widget* res = InventoryLayout_getWidget_orig(thisptr, name);
    CallInventoryLayoutGetWidgetCallbacks(thisptr, name, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryLayout_getWidget,
    "InventoryLayout::getWidget", KenshiLib::GetRealAddress(&InventoryLayout::getWidget),
    InventoryLayout_getWidget_hook, InventoryLayout_getWidget_orig)

static DatapanelGUI* (*InventoryLayout__NV_getDatapanel_orig)(const InventoryLayout*) = NULL;
static DatapanelGUI* InventoryLayout__NV_getDatapanel_hook(const InventoryLayout* thisptr)
{
    DatapanelGUI* res = InventoryLayout__NV_getDatapanel_orig(thisptr);
    DatapanelGUI* overrideRes = CallInventoryLayoutNVGetDatapanelCallbacks(const_cast<InventoryLayout*>(thisptr), res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryLayout__NV_getDatapanel,
    "InventoryLayout::_NV_getDatapanel", KenshiLib::GetRealAddress(&InventoryLayout::_NV_getDatapanel),
    InventoryLayout__NV_getDatapanel_hook, InventoryLayout__NV_getDatapanel_orig)

static void (*InventoryLayout_setupDataPanelInfos_orig)(InventoryLayout*, const std::string&) = NULL;
static void InventoryLayout_setupDataPanelInfos_hook(InventoryLayout* thisptr, const std::string& name)
{
    InventoryLayout_setupDataPanelInfos_orig(thisptr, name);
    CallInventoryLayoutSetupDataPanelInfosCallbacks(thisptr, name);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryLayout_setupDataPanelInfos,
    "InventoryLayout::setupDataPanelInfos", KenshiLib::GetRealAddress(&InventoryLayout::setupDataPanelInfos),
    InventoryLayout_setupDataPanelInfos_hook, InventoryLayout_setupDataPanelInfos_orig)

static void (*InventoryLayout_static_notifyCellSizeChanged_orig)() = NULL;
static void InventoryLayout_static_notifyCellSizeChanged_hook()
{
    InventoryLayout_static_notifyCellSizeChanged_orig();
    CallInventoryLayoutNotifyCellSizeChangedCallbacks();
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryLayout_static_notifyCellSizeChanged,
    "InventoryLayout::notifyCellSizeChanged", KenshiLib::GetRealAddress(&InventoryLayout::notifyCellSizeChanged),
    InventoryLayout_static_notifyCellSizeChanged_hook, InventoryLayout_static_notifyCellSizeChanged_orig)

static InventorySectionGUI* (*InventoryLayout_createSectionGUI_orig)(InventoryLayout*, InventorySection*) = NULL;
static InventorySectionGUI* InventoryLayout_createSectionGUI_hook(InventoryLayout* thisptr, InventorySection* section)
{
    InventorySectionGUI* res = InventoryLayout_createSectionGUI_orig(thisptr, section);
    InventorySectionGUI* overrideRes = CallInventoryLayoutCreateSectionGUICallbacks(thisptr, section, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryLayout_createSectionGUI,
    "InventoryLayout::createSectionGUI", KenshiLib::GetRealAddress(&InventoryLayout::createSectionGUI),
    InventoryLayout_createSectionGUI_hook, InventoryLayout_createSectionGUI_orig)

static void (*InventoryLayout_setSectionGUIDisabled_orig)(InventoryLayout*, const std::string&, int, int) = NULL;
static void InventoryLayout_setSectionGUIDisabled_hook(InventoryLayout* thisptr, const std::string& sectionName, int width, int height)
{
    InventoryLayout_setSectionGUIDisabled_orig(thisptr, sectionName, width, height);
    CallInventoryLayoutSetSectionGUIDisabledCallbacks(thisptr, sectionName, width, height);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryLayout_setSectionGUIDisabled,
    "InventoryLayout::setSectionGUIDisabled", KenshiLib::GetRealAddress(&InventoryLayout::setSectionGUIDisabled),
    InventoryLayout_setSectionGUIDisabled_hook, InventoryLayout_setSectionGUIDisabled_orig)

static MyGUI::types::TSize<int> (*InventoryLayout_resizeSection_orig)(InventoryLayout*, InventorySection*, InventorySectionGUI*) = NULL;
static MyGUI::types::TSize<int> InventoryLayout_resizeSection_hook(InventoryLayout* thisptr, InventorySection* section, InventorySectionGUI* sectionGUI)
{
    MyGUI::types::TSize<int> res = InventoryLayout_resizeSection_orig(thisptr, section, sectionGUI);
    CallInventoryLayoutResizeSectionCallbacks(thisptr, section, sectionGUI, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryLayout_resizeSection,
    "InventoryLayout::resizeSection", KenshiLib::GetRealAddress(&InventoryLayout::resizeSection),
    InventoryLayout_resizeSection_hook, InventoryLayout_resizeSection_orig)

static MyGUI::types::TSize<int> (*InventoryLayout_resizeSectionWidget_orig)(InventoryLayout*, int, int, MyGUI::Widget*) = NULL;
static MyGUI::types::TSize<int> InventoryLayout_resizeSectionWidget_hook(InventoryLayout* thisptr, int width, int height, MyGUI::Widget* widget)
{
    MyGUI::types::TSize<int> res = InventoryLayout_resizeSectionWidget_orig(thisptr, width, height, widget);
    CallInventoryLayoutResizeSectionWidgetCallbacks(thisptr, width, height, widget, res);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryLayout_resizeSectionWidget,
    "InventoryLayout::resizeSectionWidget", KenshiLib::GetRealAddress(&InventoryLayout::resizeSectionWidget),
    InventoryLayout_resizeSectionWidget_hook, InventoryLayout_resizeSectionWidget_orig)

static GenericFixedInventoryLayout* (*GenericFixedInventoryLayout_CONSTRUCTOR_orig)(GenericFixedInventoryLayout*) = NULL;
static GenericFixedInventoryLayout* GenericFixedInventoryLayout_CONSTRUCTOR_hook(GenericFixedInventoryLayout* thisptr)
{
    GenericFixedInventoryLayout* res = GenericFixedInventoryLayout_CONSTRUCTOR_orig(thisptr);
    GenericFixedInventoryLayout* overrideRes = CallGenericFixedInventoryLayoutConstructedCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_GenericFixedInventoryLayout_CONSTRUCTOR,
    "GenericFixedInventoryLayout::_CONSTRUCTOR", KenshiLib::GetRealAddress(&GenericFixedInventoryLayout::_CONSTRUCTOR),
    GenericFixedInventoryLayout_CONSTRUCTOR_hook, GenericFixedInventoryLayout_CONSTRUCTOR_orig)

static void (*GenericFixedInventoryLayout__NV_setSize_orig)(GenericFixedInventoryLayout*, int, int) = NULL;
static void GenericFixedInventoryLayout__NV_setSize_hook(GenericFixedInventoryLayout* thisptr, int slotsW, int slotsH)
{
    GenericFixedInventoryLayout__NV_setSize_orig(thisptr, slotsW, slotsH);
    CallGenericFixedInventoryLayoutNVSetSizeCallbacks(thisptr, slotsW, slotsH);
}
DEFINE_HOOK_INSTALLER(InstallHook_GenericFixedInventoryLayout__NV_setSize,
    "GenericFixedInventoryLayout::_NV_setSize", KenshiLib::GetRealAddress(&GenericFixedInventoryLayout::_NV_setSize),
    GenericFixedInventoryLayout__NV_setSize_hook, GenericFixedInventoryLayout__NV_setSize_orig)

static void (*GenericFixedInventoryLayout_DESTRUCTOR_orig)(GenericFixedInventoryLayout*) = NULL;
static void GenericFixedInventoryLayout_DESTRUCTOR_hook(GenericFixedInventoryLayout* thisptr)
{
    CallGenericFixedInventoryLayoutDestructorCallbacks(thisptr);
    GenericFixedInventoryLayout_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_GenericFixedInventoryLayout_DESTRUCTOR,
    "GenericFixedInventoryLayout::_DESTRUCTOR", KenshiLib::GetRealAddress(&GenericFixedInventoryLayout::_DESTRUCTOR),
    GenericFixedInventoryLayout_DESTRUCTOR_hook, GenericFixedInventoryLayout_DESTRUCTOR_orig)

static BackpackInventoryLayout* (*BackpackInventoryLayout_CONSTRUCTOR_orig)(BackpackInventoryLayout*, bool) = NULL;
static BackpackInventoryLayout* BackpackInventoryLayout_CONSTRUCTOR_hook(BackpackInventoryLayout* thisptr, bool standAlone)
{
    BackpackInventoryLayout* res = BackpackInventoryLayout_CONSTRUCTOR_orig(thisptr, standAlone);
    CallBackpackInventoryLayoutConstructedCallbacks(thisptr, standAlone);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_BackpackInventoryLayout_CONSTRUCTOR,
    "BackpackInventoryLayout::_CONSTRUCTOR", KenshiLib::GetRealAddress(&BackpackInventoryLayout::_CONSTRUCTOR),
    BackpackInventoryLayout_CONSTRUCTOR_hook, BackpackInventoryLayout_CONSTRUCTOR_orig)

static void (*BackpackInventoryLayout_DESTRUCTOR_orig)(BackpackInventoryLayout*) = NULL;
static void BackpackInventoryLayout_DESTRUCTOR_hook(BackpackInventoryLayout* thisptr)
{
    CallBackpackInventoryLayoutDestructorCallbacks(thisptr);
    BackpackInventoryLayout_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_BackpackInventoryLayout_DESTRUCTOR,
    "BackpackInventoryLayout::_DESTRUCTOR", KenshiLib::GetRealAddress(&BackpackInventoryLayout::_DESTRUCTOR),
    BackpackInventoryLayout_DESTRUCTOR_hook, BackpackInventoryLayout_DESTRUCTOR_orig)
