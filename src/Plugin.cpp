#include "pch.h"
#include "Plugin.h"

#include "EventSystem.h"
#include "Gui/GuiManager.h"
#include "Hooks/Hooks_Common.h"
#include "Compatibility/LegacyCompat.h"
#include "Logger.h"
#include "Config.h"
#include "Lua/LuaBindings.h"
#include "Lua/LuaState.h"
#include "ScriptLoader.h"
#include "Bindings/MyGUI/MyGUIBinding.h"
#include "Benchmark.h"
#include <kenshi/Kenshi.h>
#include "FileWatcher.h"

#include <bcrypt.h>
#include <fstream>

namespace KenshiLua
{

// SHA-256 of a file as uppercase hex, or an empty string on failure. Test
// records identify the exact game executable by this hash.
static std::string sha256File(const wchar_t* path)
{
    std::ifstream file(path, std::ios::binary);
    if (!file) return "";

    BCRYPT_ALG_HANDLE alg = NULL;
    BCRYPT_HASH_HANDLE hash = NULL;
    std::vector<unsigned char> hashObject;
    unsigned char digest[32];
    bool ok = false;

    if (BCRYPT_SUCCESS(BCryptOpenAlgorithmProvider(&alg, BCRYPT_SHA256_ALGORITHM, NULL, 0)))
    {
        DWORD objectLength = 0;
        DWORD written = 0;
        if (BCRYPT_SUCCESS(BCryptGetProperty(alg, BCRYPT_OBJECT_LENGTH, (PUCHAR)&objectLength,
                sizeof(objectLength), &written, 0)))
        {
            hashObject.resize(objectLength);
            if (BCRYPT_SUCCESS(BCryptCreateHash(alg, &hash, &hashObject[0], objectLength, NULL, 0, 0)))
            {
                std::vector<char> buffer(1 << 20);
                ok = true;
                while (ok && file)
                {
                    file.read(&buffer[0], buffer.size());
                    std::streamsize count = file.gcount();
                    if (count > 0)
                        ok = BCRYPT_SUCCESS(BCryptHashData(hash, (PUCHAR)&buffer[0], (ULONG)count, 0));
                }
                ok = ok && file.eof() && BCRYPT_SUCCESS(BCryptFinishHash(hash, digest, sizeof(digest), 0));
                BCryptDestroyHash(hash);
            }
        }
        BCryptCloseAlgorithmProvider(alg, 0);
    }
    if (!ok) return "";

    static const char hexDigits[] = "0123456789ABCDEF";
    std::string hex;
    hex.reserve(64);
    for (int i = 0; i < 32; ++i)
    {
        hex += hexDigits[digest[i] >> 4];
        hex += hexDigits[digest[i] & 0xF];
    }
    return hex;
}

// Debug-only because hashing the ~36 MB executable adds startup time.
static void logExecutableHash()
{
    if (!Config::get().isDebugLoggingEnabled()) return;

    wchar_t path[MAX_PATH];
    DWORD length = GetModuleFileNameW(NULL, path, MAX_PATH);
    if (length == 0 || length >= MAX_PATH)
    {
        logToFileDebug("Kenshi executable SHA-256: unavailable (could not get executable path)");
        return;
    }

    std::string narrowPath;
    for (DWORD i = 0; i < length; ++i)
        narrowPath += (path[i] < 0x80) ? (char)path[i] : '?';

    std::string hash = sha256File(path);
    logToFileDebug("Kenshi executable: " + narrowPath);
    logToFileDebug("Kenshi executable SHA-256: " + (hash.empty() ? std::string("unavailable (could not read executable)") : hash));
}

Plugin::Plugin()
    : m_dllModule(0)
    , m_initialized(false)
    , m_isInitialStartup(true)
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
    // Load the config before opening the log: it decides whether the previous
    // session's log is kept. Lines logged while loading are written once the log opens.
    Config::get().load(m_dllModule);
    initLogger();
    logToFile("Initializing KenshiLua...");
    logToFile("Kenshi version: " + KenshiLib::GetKenshiVersion().ToString());
    logExecutableHash();
    logToFilef("Config loaded");

    g_luaState = new LuaState();
    if (!g_luaState->initialize()) {
        logToFileError("FAILED: LuaState initialization");
        return false;
    }
    logToFile("LuaState initialized");

    LuaBindings::registerAll(g_luaState->getState());
    logToFile("Lua bindings registered");

    if (!EventSystem::get().initialize(g_luaState->getState())) {
        logToFileError("FAILED: EventSystem initialization");
        return false;
    }
    logToFile("EventSystem initialized");

    LegacyCompat::Initialize(g_luaState->getState());
    logToFile("Legacy compatibility initialized");

    m_initialized = true;
    logToFile("KenshiLua initialization complete");
    return true;
}

void Plugin::shutdown()
{
    if (!m_initialized) return;

    logToFile("Shutting down KenshiLua...");

    MyGUIBinding::shutdown();
    ScriptLoader::get().reset();
    FileWatcher::get().reset();

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
        runBenchmarkOnStartup(g_luaState->getState(), m_isInitialStartup);
        m_isInitialStartup = false;
    }

    // Always install keydown hook so the dev GUI hotkey works by default
    InstallHookForEvent("InputHandler::keyDownEvent");

    // Install hook for running Lua scripts from dialogue lines
    InstallHookForEvent("Dialogue::_doActions");
    InstallHookForEvent("Dialogue::say");

    // initialize developer GUI (hidden by default, toggle with 'Ctrl+Shift+L' by default).
    if (GuiManager::get().isInitialized())
    {
        GuiManager::get().updateLuaState(g_luaState);
    }
    else
    {
        GuiManager::get().requestInitialize(g_luaState);
    }


    // Discover *.lua files under each active mod's ./scripts/init/ folder and execute.
    ScriptLoader::get().loadAll(g_luaState->getState());
}

} // namespace KenshiLua
