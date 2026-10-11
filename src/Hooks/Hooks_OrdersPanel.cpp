#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/gui/OrdersPanel.h>

// ---------------------------------------------------------------------------
// Hooks for OrdersPanel.h
//
// All address-bearing non-virtual members. Events fire after the original
// call except for destructors. Mutable bool results accept Lua overrides.
// ---------------------------------------------------------------------------

#define ORDERS_VOID0(Type, Prefix, method, Callback, EventName) \
    static void (*Prefix##_##method##_orig)(Type*) = NULL; \
    static void Prefix##_##method##_hook(Type* thisptr) \
    { \
        Prefix##_##method##_orig(thisptr); \
        Callback(thisptr); \
    } \
    DEFINE_HOOK_INSTALLER(InstallHook_##Prefix##_##method, \
        EventName, KenshiLib::GetRealAddress(&Type::method), \
        Prefix##_##method##_hook, Prefix##_##method##_orig)

#define ORDERS_WIDGET(Type, Prefix, method, Callback, EventName) \
    static void (*Prefix##_##method##_orig)(Type*, MyGUI::Widget*) = NULL; \
    static void Prefix##_##method##_hook(Type* thisptr, MyGUI::Widget* sender) \
    { \
        Prefix##_##method##_orig(thisptr, sender); \
        Callback(thisptr, sender); \
    } \
    DEFINE_HOOK_INSTALLER(InstallHook_##Prefix##_##method, \
        EventName, KenshiLib::GetRealAddress(&Type::method), \
        Prefix##_##method##_hook, Prefix##_##method##_orig)

static OrderCellView* (*OrderCellView_CONSTRUCTOR_orig)(OrderCellView*, MyGUI::Widget*) = NULL;
static OrderCellView* OrderCellView_CONSTRUCTOR_hook(OrderCellView* thisptr, MyGUI::Widget* parent)
{
    OrderCellView* result = OrderCellView_CONSTRUCTOR_orig(thisptr, parent);
    CallOrderCellViewConstructedCallbacks(thisptr, parent);
    return result;
}
DEFINE_HOOK_INSTALLER(InstallHook_OrderCellView_CONSTRUCTOR,
    "OrderCellView::_CONSTRUCTOR", KenshiLib::GetRealAddress(&OrderCellView::_CONSTRUCTOR),
    OrderCellView_CONSTRUCTOR_hook, OrderCellView_CONSTRUCTOR_orig)

static void (*OrderCellView_DESTRUCTOR_orig)(OrderCellView*) = NULL;
static void OrderCellView_DESTRUCTOR_hook(OrderCellView* thisptr)
{
    CallOrderCellViewDestructorCallbacks(thisptr);
    OrderCellView_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrderCellView_DESTRUCTOR,
    "OrderCellView::_DESTRUCTOR", KenshiLib::GetRealAddress(&OrderCellView::_DESTRUCTOR),
    OrderCellView_DESTRUCTOR_hook, OrderCellView_DESTRUCTOR_orig)

static void (*OrderCellView_update_orig)(OrderCellView*, const MyGUI::IBDrawItemInfo&, OrderData*) = NULL;
static void OrderCellView_update_hook(OrderCellView* thisptr, const MyGUI::IBDrawItemInfo& info, OrderData* data)
{
    OrderCellView_update_orig(thisptr, info, data);
    CallOrderCellViewUpdateCallbacks(thisptr, const_cast<MyGUI::IBDrawItemInfo*>(&info), data);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrderCellView_update,
    "OrderCellView::update", KenshiLib::GetRealAddress(&OrderCellView::update),
    OrderCellView_update_hook, OrderCellView_update_orig)

static void (*OrderCellView_getCellDimension_orig)(MyGUI::Widget*, MyGUI::IntCoord&, bool) = NULL;
static void OrderCellView_getCellDimension_hook(MyGUI::Widget* sender, MyGUI::IntCoord& coord, bool drop)
{
    OrderCellView_getCellDimension_orig(sender, coord, drop);
    CallOrderCellViewGetCellDimensionCallbacks(sender, coord, drop);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrderCellView_static_getCellDimension,
    "OrderCellView::getCellDimension", KenshiLib::GetRealAddress(&OrderCellView::getCellDimension),
    OrderCellView_getCellDimension_hook, OrderCellView_getCellDimension_orig)

static MyGUI::Widget* (*OrderCellView_getWidget_orig)(const OrderCellView*) = NULL;
static MyGUI::Widget* OrderCellView_getWidget_hook(const OrderCellView* thisptr)
{
    MyGUI::Widget* result = OrderCellView_getWidget_orig(thisptr);
    CallOrderCellViewGetWidgetCallbacks(const_cast<OrderCellView*>(thisptr), result);
    return result;
}
DEFINE_HOOK_INSTALLER(InstallHook_OrderCellView_getWidget,
    "OrderCellView::getWidget", KenshiLib::GetRealAddress(&OrderCellView::getWidget),
    OrderCellView_getWidget_hook, OrderCellView_getWidget_orig)

ORDERS_WIDGET(OrderCellView, OrderCellView, onRemove, CallOrderCellViewOnRemoveCallbacks, "OrderCellView::onRemove")
ORDERS_VOID0(OrderCellView, OrderCellView, resize, CallOrderCellViewResizeCallbacks, "OrderCellView::resize")

static OrderData* (*OrderData_CONSTRUCTOR_orig)(OrderData*) = NULL;
static OrderData* OrderData_CONSTRUCTOR_hook(OrderData* thisptr)
{
    OrderData* result = OrderData_CONSTRUCTOR_orig(thisptr);
    CallOrderDataConstructedCallbacks(thisptr);
    return result;
}
DEFINE_HOOK_INSTALLER(InstallHook_OrderData_CONSTRUCTOR,
    "OrderData::_CONSTRUCTOR", KenshiLib::GetRealAddress(&OrderData::_CONSTRUCTOR),
    OrderData_CONSTRUCTOR_hook, OrderData_CONSTRUCTOR_orig)

static void (*OrderData_set_orig)(OrderData*, const Tasker*, int, bool) = NULL;
static void OrderData_set_hook(OrderData* thisptr, const Tasker* task, int index, bool enabled)
{
    OrderData_set_orig(thisptr, task, index, enabled);
    CallOrderDataSetCallbacks(thisptr, const_cast<Tasker*>(task), index, enabled);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrderData_set,
    "OrderData::set", KenshiLib::GetRealAddress(&OrderData::set),
    OrderData_set_hook, OrderData_set_orig)

ORDERS_VOID0(OrderData, OrderData, updateText, CallOrderDataUpdateTextCallbacks, "OrderData::updateText")

static void (*OrderData_DESTRUCTOR_orig)(OrderData*) = NULL;
static void OrderData_DESTRUCTOR_hook(OrderData* thisptr)
{
    CallOrderDataDestructorCallbacks(thisptr);
    OrderData_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrderData_DESTRUCTOR,
    "OrderData::_DESTRUCTOR", KenshiLib::GetRealAddress(&OrderData::_DESTRUCTOR),
    OrderData_DESTRUCTOR_hook, OrderData_DESTRUCTOR_orig)

static OrderData& (*OrderData_operator_assign_orig)(OrderData*, const OrderData&) = NULL;
static OrderData& OrderData_operator_assign_hook(OrderData* thisptr, const OrderData& other)
{
    OrderData& result = OrderData_operator_assign_orig(thisptr, other);
    CallOrderDataAssignCallbacks(thisptr, const_cast<OrderData*>(&other), &result);
    return result;
}
DEFINE_HOOK_INSTALLER(InstallHook_OrderData_operator_assign,
    "OrderData::operator=", KenshiLib::GetRealAddress(&OrderData::operator=),
    OrderData_operator_assign_hook, OrderData_operator_assign_orig)

static OrdersItemBox* (*OrdersItemBox_CONSTRUCTOR_orig)(OrdersItemBox*, MyGUI::Widget*) = NULL;
static OrdersItemBox* OrdersItemBox_CONSTRUCTOR_hook(OrdersItemBox* thisptr, MyGUI::Widget* parent)
{
    OrdersItemBox* result = OrdersItemBox_CONSTRUCTOR_orig(thisptr, parent);
    CallOrdersItemBoxConstructedCallbacks(thisptr, parent);
    return result;
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersItemBox_CONSTRUCTOR,
    "OrdersItemBox::_CONSTRUCTOR", KenshiLib::GetRealAddress(&OrdersItemBox::_CONSTRUCTOR),
    OrdersItemBox_CONSTRUCTOR_hook, OrdersItemBox_CONSTRUCTOR_orig)

static void (*OrdersItemBox_DESTRUCTOR_orig)(OrdersItemBox*) = NULL;
static void OrdersItemBox_DESTRUCTOR_hook(OrdersItemBox* thisptr)
{
    CallOrdersItemBoxDestructorCallbacks(thisptr);
    OrdersItemBox_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersItemBox_DESTRUCTOR,
    "OrdersItemBox::_DESTRUCTOR", KenshiLib::GetRealAddress(&OrdersItemBox::_DESTRUCTOR),
    OrdersItemBox_DESTRUCTOR_hook, OrdersItemBox_DESTRUCTOR_orig)

static OrdersPanel* (*OrdersPanel_CONSTRUCTOR_orig)(OrdersPanel*, MainBarGUI*, MyGUI::Widget*) = NULL;
static OrdersPanel* OrdersPanel_CONSTRUCTOR_hook(OrdersPanel* thisptr, MainBarGUI* mainbar, MyGUI::Widget* panel)
{
    OrdersPanel* result = OrdersPanel_CONSTRUCTOR_orig(thisptr, mainbar, panel);
    CallOrdersPanelConstructedCallbacks(thisptr, mainbar, panel);
    return result;
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_CONSTRUCTOR,
    "OrdersPanel::_CONSTRUCTOR", KenshiLib::GetRealAddress(&OrdersPanel::_CONSTRUCTOR),
    OrdersPanel_CONSTRUCTOR_hook, OrdersPanel_CONSTRUCTOR_orig)

static void (*OrdersPanel_DESTRUCTOR_orig)(OrdersPanel*) = NULL;
static void OrdersPanel_DESTRUCTOR_hook(OrdersPanel* thisptr)
{
    CallOrdersPanelDestructorCallbacks(thisptr);
    OrdersPanel_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_DESTRUCTOR,
    "OrdersPanel::_DESTRUCTOR", KenshiLib::GetRealAddress(&OrdersPanel::_DESTRUCTOR),
    OrdersPanel_DESTRUCTOR_hook, OrdersPanel_DESTRUCTOR_orig)

static void (*OrdersPanel_update_orig)(OrdersPanel*, Character*) = NULL;
static void OrdersPanel_update_hook(OrdersPanel* thisptr, Character* character)
{
    OrdersPanel_update_orig(thisptr, character);
    CallOrdersPanelUpdateCallbacks(thisptr, character);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_update,
    "OrdersPanel::update", KenshiLib::GetRealAddress(&OrdersPanel::update),
    OrdersPanel_update_hook, OrdersPanel_update_orig)

ORDERS_VOID0(OrdersPanel, OrdersPanel, clear, CallOrdersPanelClearCallbacks, "OrdersPanel::clear")
ORDERS_VOID0(OrdersPanel, OrdersPanel, refreshOrders, CallOrdersPanelRefreshOrdersCallbacks, "OrdersPanel::refreshOrders")

static void (*OrdersPanel_command_orig)(OrdersPanel*, int) = NULL;
static void OrdersPanel_command_hook(OrdersPanel* thisptr, int command)
{
    OrdersPanel_command_orig(thisptr, command);
    CallOrdersPanelCommandCallbacks(thisptr, command);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_command,
    "OrdersPanel::command", KenshiLib::GetRealAddress(&OrdersPanel::command),
    OrdersPanel_command_hook, OrdersPanel_command_orig)

static void (*OrdersPanel_moveJob_orig)(OrdersPanel*, int, int) = NULL;
static void OrdersPanel_moveJob_hook(OrdersPanel* thisptr, int orderIndex, int targetIndex)
{
    OrdersPanel_moveJob_orig(thisptr, orderIndex, targetIndex);
    CallOrdersPanelMoveJobCallbacks(thisptr, orderIndex, targetIndex);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_moveJob,
    "OrdersPanel::moveJob", KenshiLib::GetRealAddress(&OrdersPanel::moveJob),
    OrdersPanel_moveJob_hook, OrdersPanel_moveJob_orig)

static void (*OrdersPanel_removeJob_orig)(OrdersPanel*, OrderData*) = NULL;
static void OrdersPanel_removeJob_hook(OrdersPanel* thisptr, OrderData* data)
{
    OrdersPanel_removeJob_orig(thisptr, data);
    CallOrdersPanelRemoveJobCallbacks(thisptr, data);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_removeJob,
    "OrdersPanel::removeJob", KenshiLib::GetRealAddress(&OrdersPanel::removeJob),
    OrdersPanel_removeJob_hook, OrdersPanel_removeJob_orig)

#define ORDERS_DROP_BOOL(method, Callback) \
    static void (*OrdersPanel_##method##_orig)(OrdersPanel*, wraps::BaseLayout*, wraps::DDItemInfo, bool&) = NULL; \
    static void OrdersPanel_##method##_hook(OrdersPanel* thisptr, wraps::BaseLayout* sender, wraps::DDItemInfo info, bool& result) \
    { \
        OrdersPanel_##method##_orig(thisptr, sender, info, result); \
        result = Callback(thisptr, sender, &info, result); \
    } \
    DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_##method, \
        "OrdersPanel::" #method, KenshiLib::GetRealAddress(&OrdersPanel::method), \
        OrdersPanel_##method##_hook, OrdersPanel_##method##_orig)

ORDERS_DROP_BOOL(notifyStartDropOrder, CallOrdersPanelNotifyStartDropOrderCallbacks)
ORDERS_DROP_BOOL(notifyRequestDropOrder, CallOrdersPanelNotifyRequestDropOrderCallbacks)

static void (*OrdersPanel_notifyEndDropOrder_orig)(OrdersPanel*, wraps::BaseLayout*, wraps::DDItemInfo, bool) = NULL;
static void OrdersPanel_notifyEndDropOrder_hook(OrdersPanel* thisptr, wraps::BaseLayout* sender, wraps::DDItemInfo info, bool result)
{
    OrdersPanel_notifyEndDropOrder_orig(thisptr, sender, info, result);
    CallOrdersPanelNotifyEndDropOrderCallbacks(thisptr, sender, &info, result);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_notifyEndDropOrder,
    "OrdersPanel::notifyEndDropOrder", KenshiLib::GetRealAddress(&OrdersPanel::notifyEndDropOrder),
    OrdersPanel_notifyEndDropOrder_hook, OrdersPanel_notifyEndDropOrder_orig)

ORDERS_WIDGET(OrdersPanel, OrdersPanel, toggleStealth, CallOrdersPanelToggleStealthCallbacks, "OrdersPanel::toggleStealth")
ORDERS_WIDGET(OrdersPanel, OrdersPanel, toggleRanged, CallOrdersPanelToggleRangedCallbacks, "OrdersPanel::toggleRanged")

#define ORDERS_SPEED(method, Callback) \
    static void (*OrdersPanel_##method##_orig)(OrdersPanel*, MoveSpeed) = NULL; \
    static void OrdersPanel_##method##_hook(OrdersPanel* thisptr, MoveSpeed speed) \
    { \
        OrdersPanel_##method##_orig(thisptr, speed); \
        Callback(thisptr, static_cast<int>(speed)); \
    } \
    DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_##method, \
        "OrdersPanel::" #method, KenshiLib::GetRealAddress(&OrdersPanel::method), \
        OrdersPanel_##method##_hook, OrdersPanel_##method##_orig)

ORDERS_SPEED(setSpeed, CallOrdersPanelSetSpeedCallbacks)
ORDERS_SPEED(setSpeedImage, CallOrdersPanelSetSpeedImageCallbacks)
ORDERS_WIDGET(OrdersPanel, OrdersPanel, speedPrevious, CallOrdersPanelSpeedPreviousCallbacks, "OrdersPanel::speedPrevious")
ORDERS_WIDGET(OrdersPanel, OrdersPanel, speedNext, CallOrdersPanelSpeedNextCallbacks, "OrdersPanel::speedNext")
ORDERS_WIDGET(OrdersPanel, OrdersPanel, blockmodeButton, CallOrdersPanelBlockModeButtonCallbacks, "OrdersPanel::blockmodeButton")
ORDERS_WIDGET(OrdersPanel, OrdersPanel, holdButtonCallback, CallOrdersPanelHoldButtonCallbacks, "OrdersPanel::holdButtonCallback")
ORDERS_WIDGET(OrdersPanel, OrdersPanel, passiveButtonCallback, CallOrdersPanelPassiveButtonCallbacks, "OrdersPanel::passiveButtonCallback")
ORDERS_WIDGET(OrdersPanel, OrdersPanel, chaseButtonCallback, CallOrdersPanelChaseButtonCallbacks, "OrdersPanel::chaseButtonCallback")
ORDERS_WIDGET(OrdersPanel, OrdersPanel, tauntButtonCallback, CallOrdersPanelTauntButtonCallbacks, "OrdersPanel::tauntButtonCallback")
ORDERS_WIDGET(OrdersPanel, OrdersPanel, medicButton, CallOrdersPanelMedicButtonCallbacks, "OrdersPanel::medicButton")
ORDERS_WIDGET(OrdersPanel, OrdersPanel, liftButton, CallOrdersPanelLiftButtonCallbacks, "OrdersPanel::liftButton")
ORDERS_WIDGET(OrdersPanel, OrdersPanel, prospectingButton, CallOrdersPanelProspectingButtonCallbacks, "OrdersPanel::prospectingButton")

#undef ORDERS_SPEED
#undef ORDERS_DROP_BOOL
#undef ORDERS_WIDGET
#undef ORDERS_VOID0
