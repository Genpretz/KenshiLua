#include "pch.h"
#include "Plugin.h"

#include "EventSystem.h"
#include "Gui/InitializeGui.h"
#include "Hooks.h"
#include "Logger.h"
#include "Config.h"
#include "Lua/LuaBindings.h"
#include "Lua/LuaState.h"
#include "ScriptLoader.h"
#include "Bindings/MyGuiBinding.h"
#include "DialogueScriptBridge.h"
#include "Benchmark.h"

namespace KenshiLua
{

Plugin::Plugin()
    : m_dllModule(0)
    , m_initialized(false)
{
}

Plugin::~Plugin()
{
    shutdown();
}

Plugin& Plugin::get()
{
    static Plugin instance;
    return instance;
}

bool Plugin::initialize(void* hModule)
{
    if (m_initialized) return true;

    m_dllModule = hModule;

    setLoggerDllModule(m_dllModule);
    initLogger();
    logToFile("Initializing KenshiLua...");

    Config::get().load(m_dllModule);
    logToFilef("Config loaded: enable_benchmark=%s, debug_logging=%s",
        Config::get().isBenchmarkEnabled() ? "true" : "false",
        Config::get().isDebugLoggingEnabled() ? "true" : "false");

    g_luaState = new LuaState();
    if (!g_luaState->initialize()) {
        logToFile("FAILED: LuaState initialization");
        return false;
    }
    logToFile("LuaState initialized");

    LuaBindings::registerAll(g_luaState->getState());
    logToFile("Lua bindings registered");

    if (!EventSystem::get().initialize(g_luaState->getState())) {
        logToFile("FAILED: EventSystem initialization");
        return false;
    }
    logToFile("EventSystem initialized");

    m_initialized = true;
    logToFile("KenshiLua initialization complete");
    return true;
}

void Plugin::shutdown()
{
    if (!m_initialized) return;

    logToFile("Shutting down KenshiLua...");

    MyGuiBinding::shutdown();



    if (g_luaState) {
        EventSystem::get().clear();
        g_luaState->close();
        delete g_luaState;
        g_luaState = 0;
    }

    shutdownLogger();
    m_initialized = false;
}

void Plugin::start()
{
    if (!m_initialized) return;

    if (isBenchmarkEnabled()) {
        runBenchmarkOnStartup(g_luaState->getState());
    }

    // Always install keydown hook so the dev GUI hotkey works by default
    InstallHookForEvent("onKeyDown");

    // Install hook for running Lua scripts from dialogue lines
    InstallHookForEvent("onDialogueDoActions");
    InstallHookForEvent("onDialogueSay");

    // Bring up the developer GUI (hidden by default, toggle with 'Ctrl+Shift+L').
    KenshiLuaGui::get().requestInitialize(g_luaState);

    // Discover *.lua files under each active mod folder and execute each.
    ScriptLoader::get().loadAll(g_luaState->getState());
}

} // namespace KenshiLua
