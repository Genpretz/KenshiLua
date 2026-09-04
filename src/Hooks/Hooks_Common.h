#pragma once

// ---------------------------------------------------------------------------
// Shared engine includes and the generic hook-installer helper used by every
// Hooks_*.cpp translation unit. Split out of the old monolithic Hooks.cpp.
// ---------------------------------------------------------------------------

#include "../Callbacks.h"
#include "../Gui/GuiManager.h"
#include "../Logger.h"
#include "../DialogueScriptBridge.h"

#include <core/Functions.h>
#include <kenshi/Character.h>
#include <kenshi/CharMovement.h>
#include <kenshi/GameWorld.h>
#include <kenshi/CharStats.h>
#include <kenshi/Platoon.h>
#include <kenshi/Item.h>
#include <kenshi/PlayerInterface.h>
#include <kenshi/Faction.h>
#include <kenshi/Damages.h>
#include <kenshi/gui/TitleScreen.h>
#include <kenshi/gui/InventoryGUI.h>
#include <kenshi/gui/BuildModeWindow.h>
#include <kenshi/gui/SquadManagementScreen.h>
#include <kenshi/gui/ManagementScreen.h>
#include <kenshi/InputHandler.h>
#include <kenshi/util/YesNoMaybe.h>
#include <kenshi/BountyManager.h>
#include <kenshi/Building/Building.h>
#include <kenshi/FactionRelations.h>
#include <kenshi/MedicalSystem.h>
#include <kenshi/gui/DialogueWindow.h>
#include <kenshi/Dialogue.h>
#include <kenshi/Enums.h>
#include <kenshi/Inventory.h>
#include <kenshi/RootObjectFactory.h>
#include <kenshi/Town.h>
#include <kenshi/GameSaveState.h>
#include <kenshi/gui/DataPanelLine.h>
#include <kenshi/gui/OrdersPanel.h>
#include <kenshi/Gear.h>
#include <kenshi/Bounty.h>

#include <cstddef>
#include <string>

// ---------------------------------------------------------------------------
// Hooks
//
// Provides on-demand hook installation for KenshiLib engine functions.
// Hooks are lazily installed when Lua scripts register corresponding event
// handlers or explicitly requested at startup (e.g. for GUI hotkeys or dialogue).
//
// Returns true if the hook for the specified event was installed successfully
// or was already installed. Returns false if no hook is mapped to the event
// name or if installation failed.
// ---------------------------------------------------------------------------
namespace KenshiLua
{
    bool InstallHookForEvent(const std::string& eventName); //definition in Hooks_Registry.cpp
}

// ---------------------------------------------------------------------------
// Generic hook installer
// ---------------------------------------------------------------------------

template <typename T>
static bool InstallHookT(const char* name, intptr_t addr, T hookFn, T* origStorage)
{
    if (*origStorage)
        return true; // already installed

    if (!addr)
    {
        KenshiLua::logToFileErrorf("Error: Could not resolve address for %s.", name);
        return false;
    }
    
    KenshiLib::HookStatus status = KenshiLib::AddHook(addr, hookFn, origStorage);
    if (status != KenshiLib::SUCCESS)
    {
        KenshiLua::logToFileErrorf("Error: AddHook failed for %s (status %d).", name, (int)status);
        return false;
    }

    KenshiLua::logToFileDebugf("Hook installed: %s", name);
    return true;
}

#define DEFINE_HOOK_INSTALLER(fnName, displayName, addrExpr, hookFn, origVar) \
    bool fnName() \
    { \
        return InstallHookT(displayName, (intptr_t)(addrExpr), &hookFn, &origVar); \
    }
