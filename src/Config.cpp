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

static const std::map<std::string, OIS::KeyCode>& getKeyMap()
{
    static std::map<std::string, OIS::KeyCode> keyMap;
    if (keyMap.empty())
    {
        keyMap["kc_escape"] = OIS::KC_ESCAPE;           keyMap["escape"] = OIS::KC_ESCAPE;
        keyMap["kc_1"] = OIS::KC_1;                     keyMap["1"] = OIS::KC_1;
        keyMap["kc_2"] = OIS::KC_2;                     keyMap["2"] = OIS::KC_2;
        keyMap["kc_3"] = OIS::KC_3;                     keyMap["3"] = OIS::KC_3;
        keyMap["kc_4"] = OIS::KC_4;                     keyMap["4"] = OIS::KC_4;
        keyMap["kc_5"] = OIS::KC_5;                     keyMap["5"] = OIS::KC_5;
        keyMap["kc_6"] = OIS::KC_6;                     keyMap["6"] = OIS::KC_6;
        keyMap["kc_7"] = OIS::KC_7;                     keyMap["7"] = OIS::KC_7;
        keyMap["kc_8"] = OIS::KC_8;                     keyMap["8"] = OIS::KC_8;
        keyMap["kc_9"] = OIS::KC_9;                     keyMap["9"] = OIS::KC_9;
        keyMap["kc_0"] = OIS::KC_0;                     keyMap["0"] = OIS::KC_0;
        keyMap["kc_minus"] = OIS::KC_MINUS;             keyMap["minus"] = OIS::KC_MINUS;
        keyMap["kc_equals"] = OIS::KC_EQUALS;           keyMap["equals"] = OIS::KC_EQUALS;
        keyMap["kc_back"] = OIS::KC_BACK;               keyMap["back"] = OIS::KC_BACK;
        keyMap["kc_tab"] = OIS::KC_TAB;                 keyMap["tab"] = OIS::KC_TAB;
        
        keyMap["kc_q"] = OIS::KC_Q;                     keyMap["q"] = OIS::KC_Q;
        keyMap["kc_w"] = OIS::KC_W;                     keyMap["w"] = OIS::KC_W;
        keyMap["kc_e"] = OIS::KC_E;                     keyMap["e"] = OIS::KC_E;
        keyMap["kc_r"] = OIS::KC_R;                     keyMap["r"] = OIS::KC_R;
        keyMap["kc_t"] = OIS::KC_T;                     keyMap["t"] = OIS::KC_T;
        keyMap["kc_y"] = OIS::KC_Y;                     keyMap["y"] = OIS::KC_Y;
        keyMap["kc_u"] = OIS::KC_U;                     keyMap["u"] = OIS::KC_U;
        keyMap["kc_i"] = OIS::KC_I;                     keyMap["i"] = OIS::KC_I;
        keyMap["kc_o"] = OIS::KC_O;                     keyMap["o"] = OIS::KC_O;
        keyMap["kc_p"] = OIS::KC_P;                     keyMap["p"] = OIS::KC_P;
        
        keyMap["kc_lbracket"] = OIS::KC_LBRACKET;       keyMap["lbracket"] = OIS::KC_LBRACKET;
        keyMap["kc_rbracket"] = OIS::KC_RBRACKET;       keyMap["rbracket"] = OIS::KC_RBRACKET;
        keyMap["kc_return"] = OIS::KC_RETURN;           keyMap["return"] = OIS::KC_RETURN;
        keyMap["kc_lcontrol"] = OIS::KC_LCONTROL;       keyMap["lcontrol"] = OIS::KC_LCONTROL;
        
        keyMap["kc_a"] = OIS::KC_A;                     keyMap["a"] = OIS::KC_A;
        keyMap["kc_s"] = OIS::KC_S;                     keyMap["s"] = OIS::KC_S;
        keyMap["kc_d"] = OIS::KC_D;                     keyMap["d"] = OIS::KC_D;
        keyMap["kc_f"] = OIS::KC_F;                     keyMap["f"] = OIS::KC_F;
        keyMap["kc_g"] = OIS::KC_G;                     keyMap["g"] = OIS::KC_G;
        keyMap["kc_h"] = OIS::KC_H;                     keyMap["h"] = OIS::KC_H;
        keyMap["kc_j"] = OIS::KC_J;                     keyMap["j"] = OIS::KC_J;
        keyMap["kc_k"] = OIS::KC_K;                     keyMap["k"] = OIS::KC_K;
        keyMap["kc_l"] = OIS::KC_L;                     keyMap["l"] = OIS::KC_L;
        
        keyMap["kc_semicolon"] = OIS::KC_SEMICOLON;     keyMap["semicolon"] = OIS::KC_SEMICOLON;
        keyMap["kc_apostrophe"] = OIS::KC_APOSTROPHE;   keyMap["apostrophe"] = OIS::KC_APOSTROPHE;
        keyMap["kc_grave"] = OIS::KC_GRAVE;             keyMap["grave"] = OIS::KC_GRAVE;
        keyMap["kc_lshift"] = OIS::KC_LSHIFT;           keyMap["lshift"] = OIS::KC_LSHIFT;
        keyMap["kc_backslash"] = OIS::KC_BACKSLASH;     keyMap["backslash"] = OIS::KC_BACKSLASH;
        
        keyMap["kc_z"] = OIS::KC_Z;                     keyMap["z"] = OIS::KC_Z;
        keyMap["kc_x"] = OIS::KC_X;                     keyMap["x"] = OIS::KC_X;
        keyMap["kc_c"] = OIS::KC_C;                     keyMap["c"] = OIS::KC_C;
        keyMap["kc_v"] = OIS::KC_V;                     keyMap["v"] = OIS::KC_V;
        keyMap["kc_b"] = OIS::KC_B;                     keyMap["b"] = OIS::KC_B;
        keyMap["kc_n"] = OIS::KC_N;                     keyMap["n"] = OIS::KC_N;
        keyMap["kc_m"] = OIS::KC_M;                     keyMap["m"] = OIS::KC_M;
        
        keyMap["kc_comma"] = OIS::KC_COMMA;             keyMap["comma"] = OIS::KC_COMMA;
        keyMap["kc_period"] = OIS::KC_PERIOD;           keyMap["period"] = OIS::KC_PERIOD;
        keyMap["kc_slash"] = OIS::KC_SLASH;             keyMap["slash"] = OIS::KC_SLASH;
        keyMap["kc_rshift"] = OIS::KC_RSHIFT;           keyMap["rshift"] = OIS::KC_RSHIFT;
        keyMap["kc_multiply"] = OIS::KC_MULTIPLY;       keyMap["multiply"] = OIS::KC_MULTIPLY;
        keyMap["kc_lmenu"] = OIS::KC_LMENU;             keyMap["lmenu"] = OIS::KC_LMENU;
        keyMap["kc_space"] = OIS::KC_SPACE;             keyMap["space"] = OIS::KC_SPACE;
        keyMap["kc_capital"] = OIS::KC_CAPITAL;         keyMap["capital"] = OIS::KC_CAPITAL;
        
        keyMap["kc_f1"] = OIS::KC_F1;                   keyMap["f1"] = OIS::KC_F1;
        keyMap["kc_f2"] = OIS::KC_F2;                   keyMap["f2"] = OIS::KC_F2;
        keyMap["kc_f3"] = OIS::KC_F3;                   keyMap["f3"] = OIS::KC_F3;
        keyMap["kc_f4"] = OIS::KC_F4;                   keyMap["f4"] = OIS::KC_F4;
        keyMap["kc_f5"] = OIS::KC_F5;                   keyMap["f5"] = OIS::KC_F5;
        keyMap["kc_f6"] = OIS::KC_F6;                   keyMap["f6"] = OIS::KC_F6;
        keyMap["kc_f7"] = OIS::KC_F7;                   keyMap["f7"] = OIS::KC_F7;
        keyMap["kc_f8"] = OIS::KC_F8;                   keyMap["f8"] = OIS::KC_F8;
        keyMap["kc_f9"] = OIS::KC_F9;                   keyMap["f9"] = OIS::KC_F9;
        keyMap["kc_f10"] = OIS::KC_F10;                 keyMap["f10"] = OIS::KC_F10;
        keyMap["kc_f11"] = OIS::KC_F11;                 keyMap["f11"] = OIS::KC_F11;
        keyMap["kc_f12"] = OIS::KC_F12;                 keyMap["f12"] = OIS::KC_F12;
        
        keyMap["kc_numlock"] = OIS::KC_NUMLOCK;         keyMap["numlock"] = OIS::KC_NUMLOCK;
        keyMap["kc_scroll"] = OIS::KC_SCROLL;           keyMap["scroll"] = OIS::KC_SCROLL;
        keyMap["kc_decimal"] = OIS::KC_DECIMAL;         keyMap["decimal"] = OIS::KC_DECIMAL;
        keyMap["kc_add"] = OIS::KC_ADD;                 keyMap["add"] = OIS::KC_ADD;
        keyMap["kc_subtract"] = OIS::KC_SUBTRACT;       keyMap["subtract"] = OIS::KC_SUBTRACT;
        keyMap["kc_numpad1"] = OIS::KC_NUMPAD1;         keyMap["numpad1"] = OIS::KC_NUMPAD1;
        keyMap["kc_numpad2"] = OIS::KC_NUMPAD2;         keyMap["numpad2"] = OIS::KC_NUMPAD2;
        keyMap["kc_numpad3"] = OIS::KC_NUMPAD3;         keyMap["numpad3"] = OIS::KC_NUMPAD3;
        keyMap["kc_numpad4"] = OIS::KC_NUMPAD4;         keyMap["numpad4"] = OIS::KC_NUMPAD4;
        keyMap["kc_numpad5"] = OIS::KC_NUMPAD5;         keyMap["numpad5"] = OIS::KC_NUMPAD5;
        keyMap["kc_numpad6"] = OIS::KC_NUMPAD6;         keyMap["numpad6"] = OIS::KC_NUMPAD6;
        keyMap["kc_numpad7"] = OIS::KC_NUMPAD7;         keyMap["numpad7"] = OIS::KC_NUMPAD7;
        keyMap["kc_numpad8"] = OIS::KC_NUMPAD8;         keyMap["numpad8"] = OIS::KC_NUMPAD8;
        keyMap["kc_numpad9"] = OIS::KC_NUMPAD9;         keyMap["numpad9"] = OIS::KC_NUMPAD9;
        keyMap["kc_numpad0"] = OIS::KC_NUMPAD0;         keyMap["numpad0"] = OIS::KC_NUMPAD0;
    }
    return keyMap;
}

static OIS::KeyCode parseKeyCode(const std::string& keyStr)
{
    const auto& keyMap = getKeyMap();
    auto it = keyMap.find(keyStr);
    if (it != keyMap.end())
    {
        return it->second;
    }

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
    const std::map<std::string, OIS::KeyCode>& keyMap = getKeyMap();
    std::string bestMatch = "KC_UNASSIGNED";
    for (std::map<std::string, OIS::KeyCode>::const_iterator it = keyMap.begin(); it != keyMap.end(); ++it)
    {
        if (it->second == code)
        {
            if (it->first.rfind("kc_", 0) == 0)
            {
                std::string upperStr = it->first;
                std::transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
                return upperStr;
            }
            else if (bestMatch == "KC_UNASSIGNED")
            {
                bestMatch = it->first;
                std::transform(bestMatch.begin(), bestMatch.end(), bestMatch.begin(), ::toupper);
            }
        }
    }
    return bestMatch;
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
    file << "start_minimized=" << (m_startMinimized ? "true" : "false") << "\n";

    file.close();
    logToFile("Config: Saved configuration to " + m_configPath);
}

} // namespace KenshiLua
