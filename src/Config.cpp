#include "pch.h"
#include "Config.h"
#include "Logger.h"
#include <windows.h>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <map>
#include <kenshi/Globals.h>
#include <kenshi/InputHandler.h>

namespace KenshiLua
{

Config& Config::get()
{
    static Config instance;
    return instance;
}

static OIS::KeyCode parseKeyCode(const std::string& keyStr)
{
    if (::key)
    {
        return static_cast<OIS::KeyCode>(::key->parseKey(keyStr));
    }
    return OIS::KC_UNASSIGNED;
}

Config::Config()
    : m_benchmarkEnabled(false)
    , m_debugLoggingEnabled(false)
    , m_logLevel(LogLevel_Log)
    , m_startMinimized(true)
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
    char modulePath[MAX_PATH] = {0};
    if (hModule) {
        GetModuleFileNameA((HMODULE)hModule, modulePath, MAX_PATH);
    } else {
        HMODULE hMod = GetModuleHandleA("KenshiLua.dll");
        if (hMod) {
            GetModuleFileNameA(hMod, modulePath, MAX_PATH);
        }
    }

    std::string dllPath(modulePath);
    size_t pos = dllPath.find_last_of("\\/");
    if (pos != std::string::npos) {
        dllPath = dllPath.substr(0, pos);
    } else {
        dllPath = ".";
    }

    std::string configPath = dllPath + "\\config.txt";
    m_configPath = configPath;
    std::ifstream file(configPath.c_str());
    if (!file.is_open()) {
        logToFile("Config: config.txt not found, using default values");
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

void Config::setLogLevel(int level)
{
    m_logLevel = level;
    m_debugLoggingEnabled = (level == LogLevel_Debug);
}

void Config::setStartMinimized(bool minimized)
{
    m_startMinimized = minimized;
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

static std::string keyCodeToString(OIS::KeyCode code)
{
    switch (code)
    {
        case OIS::KC_ESCAPE: return "KC_ESCAPE";
        case OIS::KC_1: return "KC_1";
        case OIS::KC_2: return "KC_2";
        case OIS::KC_3: return "KC_3";
        case OIS::KC_4: return "KC_4";
        case OIS::KC_5: return "KC_5";
        case OIS::KC_6: return "KC_6";
        case OIS::KC_7: return "KC_7";
        case OIS::KC_8: return "KC_8";
        case OIS::KC_9: return "KC_9";
        case OIS::KC_0: return "KC_0";
        case OIS::KC_MINUS: return "KC_MINUS";
        case OIS::KC_EQUALS: return "KC_EQUALS";
        case OIS::KC_BACK: return "KC_BACK";
        case OIS::KC_TAB: return "KC_TAB";
        case OIS::KC_Q: return "KC_Q";
        case OIS::KC_W: return "KC_W";
        case OIS::KC_E: return "KC_E";
        case OIS::KC_R: return "KC_R";
        case OIS::KC_T: return "KC_T";
        case OIS::KC_Y: return "KC_Y";
        case OIS::KC_U: return "KC_U";
        case OIS::KC_I: return "KC_I";
        case OIS::KC_O: return "KC_O";
        case OIS::KC_P: return "KC_P";
        case OIS::KC_LBRACKET: return "KC_LBRACKET";
        case OIS::KC_RBRACKET: return "KC_RBRACKET";
        case OIS::KC_RETURN: return "KC_RETURN";
        case OIS::KC_LCONTROL: return "KC_LCONTROL";
        case OIS::KC_A: return "KC_A";
        case OIS::KC_S: return "KC_S";
        case OIS::KC_D: return "KC_D";
        case OIS::KC_F: return "KC_F";
        case OIS::KC_G: return "KC_G";
        case OIS::KC_H: return "KC_H";
        case OIS::KC_J: return "KC_J";
        case OIS::KC_K: return "KC_K";
        case OIS::KC_L: return "KC_L";
        case OIS::KC_SEMICOLON: return "KC_SEMICOLON";
        case OIS::KC_APOSTROPHE: return "KC_APOSTROPHE";
        case OIS::KC_GRAVE: return "KC_GRAVE";
        case OIS::KC_LSHIFT: return "KC_LSHIFT";
        case OIS::KC_BACKSLASH: return "KC_BACKSLASH";
        case OIS::KC_Z: return "KC_Z";
        case OIS::KC_X: return "KC_X";
        case OIS::KC_C: return "KC_C";
        case OIS::KC_V: return "KC_V";
        case OIS::KC_B: return "KC_B";
        case OIS::KC_N: return "KC_N";
        case OIS::KC_M: return "KC_M";
        case OIS::KC_COMMA: return "KC_COMMA";
        case OIS::KC_PERIOD: return "KC_PERIOD";
        case OIS::KC_SLASH: return "KC_SLASH";
        case OIS::KC_RSHIFT: return "KC_RSHIFT";
        case OIS::KC_MULTIPLY: return "KC_MULTIPLY";
        case OIS::KC_LMENU: return "KC_LMENU";
        case OIS::KC_SPACE: return "KC_SPACE";
        case OIS::KC_CAPITAL: return "KC_CAPITAL";
        case OIS::KC_F1: return "KC_F1";
        case OIS::KC_F2: return "KC_F2";
        case OIS::KC_F3: return "KC_F3";
        case OIS::KC_F4: return "KC_F4";
        case OIS::KC_F5: return "KC_F5";
        case OIS::KC_F6: return "KC_F6";
        case OIS::KC_F7: return "KC_F7";
        case OIS::KC_F8: return "KC_F8";
        case OIS::KC_F9: return "KC_F9";
        case OIS::KC_F10: return "KC_F10";
        case OIS::KC_NUMLOCK: return "KC_NUMLOCK";
        case OIS::KC_SCROLL: return "KC_SCROLL";
        case OIS::KC_NUMPAD7: return "KC_NUMPAD7";
        case OIS::KC_NUMPAD8: return "KC_NUMPAD8";
        case OIS::KC_NUMPAD9: return "KC_NUMPAD9";
        case OIS::KC_SUBTRACT: return "KC_SUBTRACT";
        case OIS::KC_NUMPAD4: return "KC_NUMPAD4";
        case OIS::KC_NUMPAD5: return "KC_NUMPAD5";
        case OIS::KC_NUMPAD6: return "KC_NUMPAD6";
        case OIS::KC_ADD: return "KC_ADD";
        case OIS::KC_NUMPAD1: return "KC_NUMPAD1";
        case OIS::KC_NUMPAD2: return "KC_NUMPAD2";
        case OIS::KC_NUMPAD3: return "KC_NUMPAD3";
        case OIS::KC_NUMPAD0: return "KC_NUMPAD0";
        case OIS::KC_DECIMAL: return "KC_DECIMAL";
        case OIS::KC_F11: return "KC_F11";
        case OIS::KC_F12: return "KC_F12";
        default: return "KC_UNASSIGNED";
    }
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
        logToFile("Config: Cannot save config, path is empty");
        return;
    }

    std::ofstream file(m_configPath.c_str());
    if (!file.is_open()) {
        logToFile("Config: Failed to open config.txt for writing");
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
    file << "start_minimized=" << (m_startMinimized ? "true" : "false") << "\n";

    file.close();
    logToFile("Config: Saved configuration to " + m_configPath);
}

} // namespace KenshiLua
