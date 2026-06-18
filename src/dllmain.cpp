#include "pch.h"

#include "EventSystem.h"
#include "Gui/InitializeGui.h"
#include "Hooks.h"
#include "Lua/Logger.h"
#include "Lua/LuaBindings.h"
#include "Lua/LuaState.h"
#include "ModLoader.h"
#include "ScriptQueue.h"
#include "Bindings/MyGuiBinding.h"
#include <ogre/OgreFrameListener.h>
#include <ogre/OgreRoot.h>

#include <kenshi/GameWorld.h>
#include <kenshi/Globals.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

// All KenshiLua singletons live for the lifetime of the process; cleanup is
// deferred to OS unload because the engine's own teardown order is not
// publicly documented and we cannot safely tear down MyGUI/Ogre dependents
// while engine threads may still be running.

namespace KenshiLua {
    LuaState*     g_luaState    = 0;
    ScriptQueue*  g_scriptQueue = 0;
}
static bool                     g_initialized = false;
static void*                    g_dllModule   = 0;

class ScriptQueueFrameListener : public Ogre::FrameListener
{
public:
    virtual bool frameStarted(const Ogre::FrameEvent& evt)
    {
        (void)evt;
        if (KenshiLua::g_scriptQueue && KenshiLua::g_luaState && KenshiLua::g_luaState->getState())
        {
            KenshiLua::g_scriptQueue->processQueue(KenshiLua::g_luaState->getState());
        }
        return true;
    }
};

static ScriptQueueFrameListener* g_frameListener = 0;

// Lua-callable bridge to ModLoader for `KenshiLua.reloadMods()`.
static int lua_reloadMods(lua_State* L)
{
    KenshiLua::ModLoader::get().reloadAll(L);
    lua_pushinteger(L, (lua_Integer)KenshiLua::ModLoader::get().scripts().size());
    return 1;
}

// Lua-callable bridge to toggle the GUI from within scripts.
static int lua_toggleGui(lua_State* L)
{
    KenshiLua::KenshiLuaGui::get().toggle();
    return 0;
}

static int lua_enqueueString(lua_State* L)
{
    if (!KenshiLua::g_scriptQueue) {
        lua_pushboolean(L, 0);
        return 1;
    }
    const char* code = luaL_checkstring(L, 1);
    const char* chunkname = luaL_optstring(L, 2, "=(enqueueString)");
    KenshiLua::ScriptTask task;
    task.type = KenshiLua::ScriptTask::ExecuteString;
    task.payload = code;
    task.chunkname = chunkname;
    bool res = KenshiLua::g_scriptQueue->enqueue(task);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

static int lua_enqueueFile(lua_State* L)
{
    if (!KenshiLua::g_scriptQueue) {
        lua_pushboolean(L, 0);
        return 1;
    }
    const char* filepath = luaL_checkstring(L, 1);
    KenshiLua::ScriptTask task;
    task.type = KenshiLua::ScriptTask::ExecuteFile;
    task.payload = filepath;
    bool res = KenshiLua::g_scriptQueue->enqueue(task);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

static int lua_enqueueHandler(lua_State* L)
{
    if (!KenshiLua::g_scriptQueue) {
        lua_pushboolean(L, 0);
        return 1;
    }
    const char* eventName = luaL_checkstring(L, 1);
    KenshiLua::ScriptTask task;
    task.type = KenshiLua::ScriptTask::CallHandler;
    task.eventName = eventName;
    bool res = KenshiLua::g_scriptQueue->enqueue(task);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

static void installKenshiLuaTable(lua_State* L)
{
    // KenshiLua.* namespace for management helpers.
    lua_getglobal(L, "KenshiLua");
    if (!lua_istable(L, -1)) {
        lua_pop(L, 1);
        lua_newtable(L);
    }

    lua_pushcfunction(L, lua_reloadMods);
    lua_setfield(L, -2, "reloadMods");

    lua_pushcfunction(L, lua_toggleGui);
    lua_setfield(L, -2, "toggleGui");

    // Aliases for the existing global event-handler functions.
    lua_pushcfunction(L, KenshiLua::luaRegisterHandler);
    lua_setfield(L, -2, "registerHandler");

    lua_pushcfunction(L, KenshiLua::luaUnregisterHandler);
    lua_setfield(L, -2, "unregisterHandler");

    // Version check helper.
    lua_pushcfunction(L, KenshiLua::luaKenshiVersion);
    lua_setfield(L, -2, "version");

    // Enqueue helpers
    lua_pushcfunction(L, lua_enqueueString);
    lua_setfield(L, -2, "enqueueString");

    lua_pushcfunction(L, lua_enqueueFile);
    lua_setfield(L, -2, "enqueueFile");

    lua_pushcfunction(L, lua_enqueueHandler);
    lua_setfield(L, -2, "enqueueHandler");

    lua_setglobal(L, "KenshiLua");
}

static bool initializeLua()
{
    if (g_initialized) return true;

    KenshiLua::setLoggerDllModule(g_dllModule);
    KenshiLua::initLogger();
    KenshiLua::logToFile("Initializing KenshiLua...");

    KenshiLua::g_luaState = new KenshiLua::LuaState();
    if (!KenshiLua::g_luaState->initialize()) {
        KenshiLua::logToFile("FAILED: LuaState initialization");
        return false;
    }
    KenshiLua::logToFile("LuaState initialized");

    KenshiLua::LuaBindings::registerAll(KenshiLua::g_luaState->getState());
    KenshiLua::logToFile("Lua bindings registered");

    installKenshiLuaTable(KenshiLua::g_luaState->getState());

    if (!KenshiLua::EventSystem::get().initialize(KenshiLua::g_luaState->getState())) {
        KenshiLua::logToFile("FAILED: EventSystem initialization");
        return false;
    }
    KenshiLua::logToFile("EventSystem initialized");

    KenshiLua::g_scriptQueue = new KenshiLua::ScriptQueue();
    if (!KenshiLua::g_scriptQueue->initialize(KenshiLua::ScriptQueue::DEFAULT_CAPACITY)) {
        KenshiLua::logToFile("FAILED: ScriptQueue initialization");
        return false;
    }
    KenshiLua::logToFile("ScriptQueue initialized");

    g_frameListener = new ScriptQueueFrameListener();
    Ogre::Root::getSingleton().addFrameListener(g_frameListener);

    g_initialized = true;
    KenshiLua::logToFile("KenshiLua initialization complete");
    return true;
}

static void shutdownLua()
{
    KenshiLua::logToFile("Shutting down KenshiLua...");

    KenshiLua::MyGuiBinding::shutdown();

    if (g_frameListener) {
        if (Ogre::Root::getSingletonPtr()) {
            Ogre::Root::getSingleton().removeFrameListener(g_frameListener);
        }
        delete g_frameListener;
        g_frameListener = 0;
    }

    if (KenshiLua::g_scriptQueue) {
        KenshiLua::g_scriptQueue->shutdown();
        delete KenshiLua::g_scriptQueue;
        KenshiLua::g_scriptQueue = 0;
    }

    if (KenshiLua::g_luaState) {
        KenshiLua::EventSystem::get().clear();
        KenshiLua::g_luaState->close();
        delete KenshiLua::g_luaState;
        KenshiLua::g_luaState = 0;
    }

    KenshiLua::shutdownLogger();
    g_initialized = false;
}

// --- RE_Kenshi plugin entry --------------------------------------------------
//
// RE_Kenshi invokes startPlugin() after Kenshi's main systems are live
// (MyGUI, Ogre, the ou GameWorld pointer, etc.).  We can therefore initialise
// our Lua state, discover active mods, run their scripts, and bring up the
// in-game GUI in a single call without any "wait for engine ready" polling.

_declspec(dllexport) void startPlugin()
{
    if (!initializeLua()) return;

    // Discover *.lua files under each active mod folder and execute each.
    // ModLoader is resilient: a single script failing won't abort the rest.
    KenshiLua::ModLoader::get().loadAll(KenshiLua::g_luaState->getState());

    // KenshiLua::InstallAllHooks(); // Hooks are now installed dynamically/lazily on first event registration

    // Bring up the developer GUI (hidden by default; toggled with F11).
    KenshiLua::KenshiLuaGui::get().requestInitialize(KenshiLua::g_luaState);
    KenshiLua::logToFile("startPlugin: ready");
}

// --- DllMain -----------------------------------------------------------------

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        g_dllModule = (void*)hModule;
        DisableThreadLibraryCalls(hModule);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        // Skip cleanup at process detach.  Engine threads may still be alive
        // and tearing Lua / MyGUI / Ogre down here would race with them.
        // The OS reclaims everything when the process exits.
        break;
    }
    return TRUE;
}
