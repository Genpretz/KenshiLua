#include "pch.h"
#include "Hooks_Common.h"
#include <MyGUI.h>
#include <kenshi/gui/ContextMenu.h>

// ---------------------------------------------------------------------------
// Hooks for mygui/common/baselayout/BaseLayout.h
// ---------------------------------------------------------------------------

static void (*BaseLayout_initialise_orig)(wraps::BaseLayout*, const std::string&, MyGUI::Widget*, bool, bool) = NULL;
static void BaseLayout_initialise_hook(wraps::BaseLayout* thisptr, const std::string& layout, MyGUI::Widget* parent, bool throwException, bool createChildren)
{
    BaseLayout_initialise_orig(thisptr, layout, parent, throwException, createChildren);
    CallBaseLayoutInitialiseCallbacks(thisptr, layout);
}
bool InstallHook_BaseLayout_initialise()
{
    if (BaseLayout_initialise_orig)
        return true;

    HMODULE hKenshiLib = GetModuleHandleA("KenshiLib.dll");
    if (!hKenshiLib)
        hKenshiLib = GetModuleHandleA("kenshilib.dll");

    if (!hKenshiLib)
    {
        KenshiLua::logToFileErrorf("Error: KenshiLib.dll module handle not found for wraps::BaseLayout::initialise");
        return false;
    }

    void* stubAddr = (void*)GetProcAddress(hKenshiLib,
        "?initialise@BaseLayout@wraps@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAVWidget@MyGUI@@_N2@Z");
    if (!stubAddr)
    {
        KenshiLua::logToFileErrorf("Error: Failed to locate wraps::BaseLayout::initialise export in KenshiLib.dll");
        return false;
    }

    intptr_t realAddr = KenshiLib::GetRealAddress(stubAddr);
    return InstallHookT("wraps::BaseLayout::initialise", realAddr, &BaseLayout_initialise_hook, &BaseLayout_initialise_orig);
}

// ---------------------------------------------------------------------------
// Delegates for mygui/MyGUI_Gui.h
//
// Not an engine hook: subscribes to the delegate MyGUI raises from its renderer
// each frame, so no game address is involved. The subscription is kept for the
// rest of the session; with no Lua handlers the dispatch finds no bucket.
// ---------------------------------------------------------------------------

static bool g_guiFrameStartSubscribed = false;

static void Gui_eventFrameStart(float time)
{
    CallMyGUIGuiFrameStartCallbacks(time);
}

bool InstallDelegate_MyGUI_Gui_eventFrameStart()
{
    if (g_guiFrameStartSubscribed)
        return true;

    MyGUI::Gui* gui = MyGUI::Gui::getInstancePtr();
    if (!gui)
    {
        KenshiLua::logToFileErrorf("Error: MyGUI is not initialized; cannot subscribe to MyGUI::Gui::eventFrameStart");
        return false;
    }

    gui->eventFrameStart += MyGUI::newDelegate(Gui_eventFrameStart);
    g_guiFrameStartSubscribed = true;
    KenshiLua::logToFileDebugf("Delegate subscribed: MyGUI::Gui::eventFrameStart");
    return true;
}

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
// Hooks for ContextMenu.h
// ---------------------------------------------------------------------------

static void (*ContextMenu_showContextMenu_orig)(ContextMenu*, bool, RootObject*) = NULL;
static void ContextMenu_showContextMenu_hook(ContextMenu* thisptr, bool on, RootObject* what)
{
    ContextMenu_showContextMenu_orig(thisptr, on, what);
    CallContextMenuShowContextMenuCallbacks(thisptr, on, what);
}
DEFINE_HOOK_INSTALLER(InstallHook_ContextMenu_showContextMenu,
    "ContextMenu::showContextMenu",
    KenshiLib::GetRealAddress(&ContextMenu::showContextMenu),
    ContextMenu_showContextMenu_hook, ContextMenu_showContextMenu_orig)

static void (*ContextMenuGUI_show_orig)(ContextMenuGUI*, const lektor<int>&, const std::string&, bool) = NULL;
static void ContextMenuGUI_show_hook(ContextMenuGUI* thisptr, const lektor<int>& ordersList, const std::string& name, bool offset)
{
    ContextMenuGUI_show_orig(thisptr, ordersList, name, offset);
    CallContextMenuGUIShowCallbacks(thisptr, ordersList, name, offset);
}
DEFINE_HOOK_INSTALLER(InstallHook_ContextMenuGUI_show,
    "ContextMenuGUI::show",
    KenshiLib::GetRealAddress(&ContextMenuGUI::show),
    ContextMenuGUI_show_hook, ContextMenuGUI_show_orig)
