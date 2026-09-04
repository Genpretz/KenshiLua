#include "pch.h"
#include "Hooks_Common.h"

// ---------------------------------------------------------------------------
// Hooks for mygui/common/baselayout/BaseLayout.h
// ---------------------------------------------------------------------------

static void (*BaseLayout_initialise_orig)(wraps::BaseLayout*, const std::string&, MyGUI::Widget*, bool, bool) = NULL;
static void BaseLayout_initialise_hook(wraps::BaseLayout* thisptr, const std::string& layout, MyGUI::Widget* parent, bool throwException, bool createChildren)
{
    BaseLayout_initialise_orig(thisptr, layout, parent, throwException, createChildren);
    CallBaseLayoutInitialiseCallbacks(thisptr, layout);
}
DEFINE_HOOK_INSTALLER(InstallHook_BaseLayout_initialise,
    "wraps::BaseLayout::initialise",
    KenshiLib::GetRealAddress(static_cast<void (wraps::BaseLayout::*)(const std::string&, MyGUI::Widget*, bool, bool)>(&wraps::BaseLayout::initialise)),
    BaseLayout_initialise_hook, BaseLayout_initialise_orig)

// ---------------------------------------------------------------------------
// Hooks for InventoryGUI.h
// ---------------------------------------------------------------------------

static void (*InventoryGUI_addTradePartner_orig)(InventoryGUI*, bool, bool, bool, const hand&) = NULL;
static void InventoryGUI_addTradePartner_hook(InventoryGUI* tradeWith, bool payment, bool canDrop, bool isPlayer, const hand& who)
{
    InventoryGUI_addTradePartner_orig(tradeWith, payment, canDrop, isPlayer, who);
    CallInventoryAddTradePartnerCallbacks(tradeWith, payment, canDrop, isPlayer, who);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_addTradePartner,
    "InventoryGUI::addTradePartner",
    KenshiLib::GetRealAddress(&InventoryGUI::addTradePartner),
    InventoryGUI_addTradePartner_hook, InventoryGUI_addTradePartner_orig)

static void (*InventoryGUI_fencingConfirmationCallback_orig)(InventoryGUI*, int) = NULL;
static void InventoryGUI_fencingConfirmationCallback_hook(InventoryGUI* thisptr, int b)
{
    InventoryGUI_fencingConfirmationCallback_orig(thisptr, b);
    CallInventoryGUIFencingConfirmationCallbacks(thisptr, b);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryGUI_fencingConfirmationCallback,
    "InventoryGUI::fencingConfirmationCallback",
    KenshiLib::GetRealAddress(&InventoryGUI::fencingConfirmationCallback),
    InventoryGUI_fencingConfirmationCallback_hook, InventoryGUI_fencingConfirmationCallback_orig)

// ---------------------------------------------------------------------------
// Hooks for BuildModeWindow.h
// ---------------------------------------------------------------------------

static void (*BuildModeWindow_confirm_orig)(BuildModeWindow*, MyGUI::Widget*) = NULL;
static void BuildModeWindow_confirm_hook(BuildModeWindow* thisptr, MyGUI::Widget* sender)
{
    BuildModeWindow_confirm_orig(thisptr, sender);
    CallBuildModeWindowConfirmCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_BuildModeWindow_confirm,
    "BuildModeWindow::confirm",
    KenshiLib::GetRealAddress(&BuildModeWindow::confirm),
    BuildModeWindow_confirm_hook, BuildModeWindow_confirm_orig)

// ---------------------------------------------------------------------------
// Hooks for SquadManagementScreen.h
// ---------------------------------------------------------------------------

static void (*SquadManagementScreen_removeSquad_orig)(SquadManagementScreen*, SquadManagementScreen::SquadData*) = NULL;
static void SquadManagementScreen_removeSquad_hook(SquadManagementScreen* thisptr, SquadManagementScreen::SquadData* squad)
{
    SquadManagementScreen_removeSquad_orig(thisptr, squad);
    CallSquadManagementScreenRemoveSquadCallbacks(thisptr, squad);
}
DEFINE_HOOK_INSTALLER(InstallHook_SquadManagementScreen_removeSquad,
    "SquadManagementScreen::removeSquad",
    KenshiLib::GetRealAddress(&SquadManagementScreen::removeSquad),
    SquadManagementScreen_removeSquad_hook, SquadManagementScreen_removeSquad_orig)

// ---------------------------------------------------------------------------
// Hooks for ManagementScreen.h
// ---------------------------------------------------------------------------

static void (*ManagementScreen_addMessage_orig)(ManagementScreen*, const std::string&, const std::string&, MessageLogColor) = NULL;
static void ManagementScreen_addMessage_hook(ManagementScreen* thisptr, const std::string& owner, const std::string& message, MessageLogColor isPlayer)
{
    ManagementScreen_addMessage_orig(thisptr, owner, message, isPlayer);
    CallManagementScreenAddMessageCallbacks(thisptr, owner, message, static_cast<int>(isPlayer));
}
DEFINE_HOOK_INSTALLER(InstallHook_ManagementScreen_addMessage,
    "ManagementScreen::addMessage",
    KenshiLib::GetRealAddress(&ManagementScreen::addMessage),
    ManagementScreen_addMessage_hook, ManagementScreen_addMessage_orig)

// ---------------------------------------------------------------------------
// Hooks for TitleScreen.h
// ---------------------------------------------------------------------------

static void (*TitleScreen_loadGame_orig)(TitleScreen*, MyGUI::Widget*) = NULL;
static void TitleScreen_loadGame_hook(TitleScreen* thisptr, MyGUI::Widget* sender)
{
    TitleScreen_loadGame_orig(thisptr, sender);
    CallTitleScreenLoadGameCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_TitleScreen_loadGame,
    "TitleScreen::loadGame",
    KenshiLib::GetRealAddress(&TitleScreen::loadGame),
    TitleScreen_loadGame_hook, TitleScreen_loadGame_orig)

// ---------------------------------------------------------------------------
// Hooks for DataPanelLine.h
// ---------------------------------------------------------------------------

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

// ---------------------------------------------------------------------------
// Hooks for OrdersPanel.h
// ---------------------------------------------------------------------------

static void (*OrdersPanel_blockmodeButton_orig)(OrdersPanel*, MyGUI::Widget*) = NULL;
static void OrdersPanel_blockmodeButton_hook(OrdersPanel* thisptr, MyGUI::Widget* sender)
{
    OrdersPanel_blockmodeButton_orig(thisptr, sender);
    CallOrdersPanelBlockModeButtonCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_blockmodeButton,
    "OrdersPanel::blockmodeButton",
    KenshiLib::GetRealAddress(&OrdersPanel::blockmodeButton),
    OrdersPanel_blockmodeButton_hook, OrdersPanel_blockmodeButton_orig)

static void (*OrdersPanel_holdButtonCallback_orig)(OrdersPanel*, MyGUI::Widget*) = NULL;
static void OrdersPanel_holdButtonCallback_hook(OrdersPanel* thisptr, MyGUI::Widget* sender)
{
    OrdersPanel_holdButtonCallback_orig(thisptr, sender);
    CallOrdersPanelHoldButtonCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_holdButtonCallback,
    "OrdersPanel::holdButtonCallback",
    KenshiLib::GetRealAddress(&OrdersPanel::holdButtonCallback),
    OrdersPanel_holdButtonCallback_hook, OrdersPanel_holdButtonCallback_orig)

static void (*OrdersPanel_passiveButtonCallback_orig)(OrdersPanel*, MyGUI::Widget*) = NULL;
static void OrdersPanel_passiveButtonCallback_hook(OrdersPanel* thisptr, MyGUI::Widget* sender)
{
    OrdersPanel_passiveButtonCallback_orig(thisptr, sender);
    CallOrdersPanelPassiveButtonCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_passiveButtonCallback,
    "OrdersPanel::passiveButtonCallback",
    KenshiLib::GetRealAddress(&OrdersPanel::passiveButtonCallback),
    OrdersPanel_passiveButtonCallback_hook, OrdersPanel_passiveButtonCallback_orig)

static void (*OrdersPanel_chaseButtonCallback_orig)(OrdersPanel*, MyGUI::Widget*) = NULL;
static void OrdersPanel_chaseButtonCallback_hook(OrdersPanel* thisptr, MyGUI::Widget* sender)
{
    OrdersPanel_chaseButtonCallback_orig(thisptr, sender);
    CallOrdersPanelChaseButtonCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_chaseButtonCallback,
    "OrdersPanel::chaseButtonCallback",
    KenshiLib::GetRealAddress(&OrdersPanel::chaseButtonCallback),
    OrdersPanel_chaseButtonCallback_hook, OrdersPanel_chaseButtonCallback_orig)

static void (*OrdersPanel_tauntButtonCallback_orig)(OrdersPanel*, MyGUI::Widget*) = NULL;
static void OrdersPanel_tauntButtonCallback_hook(OrdersPanel* thisptr, MyGUI::Widget* sender)
{
    OrdersPanel_tauntButtonCallback_orig(thisptr, sender);
    CallOrdersPanelTauntButtonCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_tauntButtonCallback,
    "OrdersPanel::tauntButtonCallback",
    KenshiLib::GetRealAddress(&OrdersPanel::tauntButtonCallback),
    OrdersPanel_tauntButtonCallback_hook, OrdersPanel_tauntButtonCallback_orig)

static void (*OrdersPanel_medicButton_orig)(OrdersPanel*, MyGUI::Widget*) = NULL;
static void OrdersPanel_medicButton_hook(OrdersPanel* thisptr, MyGUI::Widget* sender)
{
    OrdersPanel_medicButton_orig(thisptr, sender);
    CallOrdersPanelMedicButtonCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_medicButton,
    "OrdersPanel::medicButton",
    KenshiLib::GetRealAddress(&OrdersPanel::medicButton),
    OrdersPanel_medicButton_hook, OrdersPanel_medicButton_orig)

static void (*OrdersPanel_liftButton_orig)(OrdersPanel*, MyGUI::Widget*) = NULL;
static void OrdersPanel_liftButton_hook(OrdersPanel* thisptr, MyGUI::Widget* sender)
{
    OrdersPanel_liftButton_orig(thisptr, sender);
    CallOrdersPanelLiftButtonCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_liftButton,
    "OrdersPanel::liftButton",
    KenshiLib::GetRealAddress(&OrdersPanel::liftButton),
    OrdersPanel_liftButton_hook, OrdersPanel_liftButton_orig)

static void (*OrdersPanel_prospectingButton_orig)(OrdersPanel*, MyGUI::Widget*) = NULL;
static void OrdersPanel_prospectingButton_hook(OrdersPanel* thisptr, MyGUI::Widget* sender)
{
    OrdersPanel_prospectingButton_orig(thisptr, sender);
    CallOrdersPanelProspectingButtonCallbacks(thisptr, sender);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersPanel_prospectingButton,
    "OrdersPanel::prospectingButton",
    KenshiLib::GetRealAddress(&OrdersPanel::prospectingButton),
    OrdersPanel_prospectingButton_hook, OrdersPanel_prospectingButton_orig)
