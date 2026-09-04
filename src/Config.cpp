#include "pch.h"
#include "Config.h"
#include "Logger.h"
#include "Util/KeyCodes.h"
#include "Util/PathUtils.h"
#include <windows.h>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <kenshi/Globals.h>
#include <kenshi/InputHandler.h>

namespace KenshiLua
{

Config& Config::get()
{
    static Config instance;
    return instance;
}

Config::Config()
    : m_benchmarkEnabled(false)
    , m_debugLoggingEnabled(false)
    , m_logLevel(LogLevel_Log)
    , m_startMinimized(true)
    , m_enableHotReload(false)
    , m_toggleGuiKey(OIS::KC_L)
    , m_toggleGuiCtrl(true)
    , m_toggleGuiShift(true)
    , m_toggleGuiAlt(false)
{
}

Config::~Config()
{
}

// Simple helper to trim whitespace from both ends of a string
static std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) {
        return "";
    }
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

// Convert string to lowercase
static std::string toLower(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void Config::load(void* hModule)
{
    std::string dllPath = getDllDirectory(hModule);
    std::string configPath = dllPath + "\\config.ini";
    m_configPath = configPath;
    std::ifstream file(configPath.c_str());
    if (!file.is_open()) {
        logToFile("Config: config.ini not found, using default values");
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        line = trim(line);
        if (line.empty() || line[0] == '#' || line[0] == ';') {
            continue;
        }

        size_t eqPos = line.find('=');
        if (eqPos == std::string::npos) {
            continue;
        }

        std::string key = toLower(trim(line.substr(0, eqPos)));
        std::string val = toLower(trim(line.substr(eqPos + 1)));

        if (key == "enable_benchmark") {
            m_benchmarkEnabled = (val == "true" || val == "1");
        } else if (key == "debug_logging" || key == "enable_debug") {
            m_debugLoggingEnabled = (val == "true" || val == "1");
            if (m_debugLoggingEnabled) {
                m_logLevel = LogLevel_Debug;
            }
        } else if (key == "log_level") {
            if (val == "warn" || val == "warning") {
                m_logLevel = LogLevel_Warn;
            } else if (val == "error") {
                m_logLevel = LogLevel_Error;
            } else if (val == "debug") {
                m_logLevel = LogLevel_Debug;
            } else {
                m_logLevel = LogLevel_Log;
            }
        } else if (key == "start_minimized") {
            m_startMinimized = (val == "true" || val == "1");
        } else if (key == "enable_hot_reload" || key == "hot_reload") {
            m_enableHotReload = (val == "true" || val == "1");
        } else if (key == "gui_toggle_key" || key == "toggle_gui_key") {
            OIS::KeyCode keycode = parseKeyCode(val);
            if (keycode != OIS::KC_UNASSIGNED) {
                m_toggleGuiKey = keycode;
            }
        } else if (key == "gui_toggle_ctrl" || key == "toggle_gui_ctrl") {
            m_toggleGuiCtrl = (val == "true" || val == "1");
        } else if (key == "gui_toggle_shift" || key == "toggle_gui_shift") {
            m_toggleGuiShift = (val == "true" || val == "1");
        } else if (key == "gui_toggle_alt" || key == "toggle_gui_alt") {
            m_toggleGuiAlt = (val == "true" || val == "1");
        }
    }
    file.close();
}

bool Config::isBenchmarkEnabled() const
{
    return m_benchmarkEnabled;
}

bool Config::isDebugLoggingEnabled() const
{
    return m_debugLoggingEnabled || m_logLevel == LogLevel_Debug;
}

OIS::KeyCode Config::getToggleGuiKey() const
{
    return m_toggleGuiKey;
}

bool Config::isToggleGuiCtrl() const
{
    return m_toggleGuiCtrl;
}

bool Config::isToggleGuiShift() const
{
    return m_toggleGuiShift;
}

bool Config::isToggleGuiAlt() const
{
    return m_toggleGuiAlt;
}

int Config::getLogLevel() const
{
    return m_logLevel;
}

bool Config::isStartMinimized() const
{
    return m_startMinimized;
}

bool Config::isHotReloadEnabled() const
{
    return m_enableHotReload;
}

void Config::setLogLevel(int level)
{
    m_logLevel = level;
    m_debugLoggingEnabled = (level == LogLevel_Debug);
}

void Config::setStartMinimized(bool minimized)
{
    m_startMinimized = minimized;
}

void Config::setHotReloadEnabled(bool enabled)
{
    m_enableHotReload = enabled;
}

void Config::setToggleGuiKey(OIS::KeyCode key)
{
    m_toggleGuiKey = key;
}

void Config::setToggleGuiCtrl(bool ctrl)
{
    m_toggleGuiCtrl = ctrl;
}

void Config::setToggleGuiShift(bool shift)
{
    m_toggleGuiShift = shift;
}

void Config::setToggleGuiAlt(bool alt)
{
    m_toggleGuiAlt = alt;
}

static std::string logLevelToString(int level)
{
    switch (level)
    {
        case LogLevel_Warn: return "warning";
        case LogLevel_Error: return "error";
        case LogLevel_Debug: return "debug";
        case LogLevel_Log:
        default: return "default";
    }
}

void Config::save()
{
    if (m_configPath.empty()) {
        logToFileError("Config: Cannot save config, path is empty");
        return;
    }

    std::ofstream file(m_configPath.c_str());
    if (!file.is_open()) {
        logToFileError("Config: Failed to open config.ini for writing");
        return;
    }

    file << "# KenshiLua Configuration File\n";
    file << "# ----------------------------\n\n";

    file << "# Set to true to run the benchmark system on game startup and log results to KenshiLua_Benchmark.log\n";
    file << "enable_benchmark=" << (m_benchmarkEnabled ? "true" : "false") << "\n\n";

    file << "# Global log level (default, warning, error, debug)\n";
    file << "log_level=" << logLevelToString(m_logLevel) << "\n\n";

    file << "# Keyboard shortcut to toggle the developer GUI.\n";
    file << "# Available keys: KC_A to KC_Z, KC_F1 to KC_F12, KC_1 to KC_0, escape, tab, return, space, etc.\n";
    file << "toggle_gui_key=" << keyCodeToString(m_toggleGuiKey) << "\n\n";

    file << "# GUI toggle modifier key configurations\n";
    file << "toggle_gui_ctrl=" << (m_toggleGuiCtrl ? "true" : "false") << "\n";
    file << "toggle_gui_shift=" << (m_toggleGuiShift ? "true" : "false") << "\n";
    file << "toggle_gui_alt=" << (m_toggleGuiAlt ? "true" : "false") << "\n\n";

    file << "# Start minimized (if true, toggled using keybind. if false, visible on start)\n";
    file << "start_minimized=" << (m_startMinimized ? "true" : "false") << "\n\n";

    file << "# Automatic file-watcher hot reload system (default false)\n";
    file << "enable_hot_reload=" << (m_enableHotReload ? "true" : "false") << "\n";

    file.close();
    logToFile("Config: Saved configuration to " + m_configPath);
}

} // namespace KenshiLua
