#include "pch.h"
#include "Config.h"
#include "Logger.h"
#include <windows.h>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <map>

namespace KenshiLua
{

Config& Config::get()
{
    static Config instance;
    return instance;
}

static OIS::KeyCode parseKeyCode(const std::string& keyStr)
{
    static std::map<std::string, OIS::KeyCode> s_keyMap;
    if (s_keyMap.empty())
    {
        s_keyMap["kc_unassigned"] = OIS::KC_UNASSIGNED;
        s_keyMap["kc_escape"] = OIS::KC_ESCAPE;
        s_keyMap["escape"] = OIS::KC_ESCAPE;
        s_keyMap["kc_1"] = OIS::KC_1;
        s_keyMap["1"] = OIS::KC_1;
        s_keyMap["kc_2"] = OIS::KC_2;
        s_keyMap["2"] = OIS::KC_2;
        s_keyMap["kc_3"] = OIS::KC_3;
        s_keyMap["3"] = OIS::KC_3;
        s_keyMap["kc_4"] = OIS::KC_4;
        s_keyMap["4"] = OIS::KC_4;
        s_keyMap["kc_5"] = OIS::KC_5;
        s_keyMap["5"] = OIS::KC_5;
        s_keyMap["kc_6"] = OIS::KC_6;
        s_keyMap["6"] = OIS::KC_6;
        s_keyMap["kc_7"] = OIS::KC_7;
        s_keyMap["7"] = OIS::KC_7;
        s_keyMap["kc_8"] = OIS::KC_8;
        s_keyMap["8"] = OIS::KC_8;
        s_keyMap["kc_9"] = OIS::KC_9;
        s_keyMap["9"] = OIS::KC_9;
        s_keyMap["kc_0"] = OIS::KC_0;
        s_keyMap["0"] = OIS::KC_0;
        s_keyMap["kc_minus"] = OIS::KC_MINUS;
        s_keyMap["minus"] = OIS::KC_MINUS;
        s_keyMap["kc_equals"] = OIS::KC_EQUALS;
        s_keyMap["equals"] = OIS::KC_EQUALS;
        s_keyMap["kc_back"] = OIS::KC_BACK;
        s_keyMap["back"] = OIS::KC_BACK;
        s_keyMap["kc_tab"] = OIS::KC_TAB;
        s_keyMap["tab"] = OIS::KC_TAB;
        s_keyMap["kc_q"] = OIS::KC_Q;
        s_keyMap["q"] = OIS::KC_Q;
        s_keyMap["kc_w"] = OIS::KC_W;
        s_keyMap["w"] = OIS::KC_W;
        s_keyMap["kc_e"] = OIS::KC_E;
        s_keyMap["e"] = OIS::KC_E;
        s_keyMap["kc_r"] = OIS::KC_R;
        s_keyMap["r"] = OIS::KC_R;
        s_keyMap["kc_t"] = OIS::KC_T;
        s_keyMap["t"] = OIS::KC_T;
        s_keyMap["kc_y"] = OIS::KC_Y;
        s_keyMap["y"] = OIS::KC_Y;
        s_keyMap["kc_u"] = OIS::KC_U;
        s_keyMap["u"] = OIS::KC_U;
        s_keyMap["kc_i"] = OIS::KC_I;
        s_keyMap["i"] = OIS::KC_I;
        s_keyMap["kc_o"] = OIS::KC_O;
        s_keyMap["o"] = OIS::KC_O;
        s_keyMap["kc_p"] = OIS::KC_P;
        s_keyMap["p"] = OIS::KC_P;
        s_keyMap["kc_lbracket"] = OIS::KC_LBRACKET;
        s_keyMap["lbracket"] = OIS::KC_LBRACKET;
        s_keyMap["kc_rbracket"] = OIS::KC_RBRACKET;
        s_keyMap["rbracket"] = OIS::KC_RBRACKET;
        s_keyMap["kc_return"] = OIS::KC_RETURN;
        s_keyMap["return"] = OIS::KC_RETURN;
        s_keyMap["kc_lcontrol"] = OIS::KC_LCONTROL;
        s_keyMap["lcontrol"] = OIS::KC_LCONTROL;
        s_keyMap["kc_a"] = OIS::KC_A;
        s_keyMap["a"] = OIS::KC_A;
        s_keyMap["kc_s"] = OIS::KC_S;
        s_keyMap["s"] = OIS::KC_S;
        s_keyMap["kc_d"] = OIS::KC_D;
        s_keyMap["d"] = OIS::KC_D;
        s_keyMap["kc_f"] = OIS::KC_F;
        s_keyMap["f"] = OIS::KC_F;
        s_keyMap["kc_g"] = OIS::KC_G;
        s_keyMap["g"] = OIS::KC_G;
        s_keyMap["kc_h"] = OIS::KC_H;
        s_keyMap["h"] = OIS::KC_H;
        s_keyMap["kc_j"] = OIS::KC_J;
        s_keyMap["j"] = OIS::KC_J;
        s_keyMap["kc_k"] = OIS::KC_K;
        s_keyMap["k"] = OIS::KC_K;
        s_keyMap["kc_l"] = OIS::KC_L;
        s_keyMap["l"] = OIS::KC_L;
        s_keyMap["kc_semicolon"] = OIS::KC_SEMICOLON;
        s_keyMap["semicolon"] = OIS::KC_SEMICOLON;
        s_keyMap["kc_apostrophe"] = OIS::KC_APOSTROPHE;
        s_keyMap["apostrophe"] = OIS::KC_APOSTROPHE;
        s_keyMap["kc_grave"] = OIS::KC_GRAVE;
        s_keyMap["grave"] = OIS::KC_GRAVE;
        s_keyMap["kc_lshift"] = OIS::KC_LSHIFT;
        s_keyMap["lshift"] = OIS::KC_LSHIFT;
        s_keyMap["kc_backslash"] = OIS::KC_BACKSLASH;
        s_keyMap["backslash"] = OIS::KC_BACKSLASH;
        s_keyMap["kc_z"] = OIS::KC_Z;
        s_keyMap["z"] = OIS::KC_Z;
        s_keyMap["kc_x"] = OIS::KC_X;
        s_keyMap["x"] = OIS::KC_X;
        s_keyMap["kc_c"] = OIS::KC_C;
        s_keyMap["c"] = OIS::KC_C;
        s_keyMap["kc_v"] = OIS::KC_V;
        s_keyMap["v"] = OIS::KC_V;
        s_keyMap["kc_b"] = OIS::KC_B;
        s_keyMap["b"] = OIS::KC_B;
        s_keyMap["kc_n"] = OIS::KC_N;
        s_keyMap["n"] = OIS::KC_N;
        s_keyMap["kc_m"] = OIS::KC_M;
        s_keyMap["m"] = OIS::KC_M;
        s_keyMap["kc_comma"] = OIS::KC_COMMA;
        s_keyMap["comma"] = OIS::KC_COMMA;
        s_keyMap["kc_period"] = OIS::KC_PERIOD;
        s_keyMap["period"] = OIS::KC_PERIOD;
        s_keyMap["kc_slash"] = OIS::KC_SLASH;
        s_keyMap["slash"] = OIS::KC_SLASH;
        s_keyMap["kc_rshift"] = OIS::KC_RSHIFT;
        s_keyMap["rshift"] = OIS::KC_RSHIFT;
        s_keyMap["kc_multiply"] = OIS::KC_MULTIPLY;
        s_keyMap["multiply"] = OIS::KC_MULTIPLY;
        s_keyMap["kc_lmenu"] = OIS::KC_LMENU;
        s_keyMap["lmenu"] = OIS::KC_LMENU;
        s_keyMap["kc_space"] = OIS::KC_SPACE;
        s_keyMap["space"] = OIS::KC_SPACE;
        s_keyMap["kc_capital"] = OIS::KC_CAPITAL;
        s_keyMap["capital"] = OIS::KC_CAPITAL;
        s_keyMap["kc_f1"] = OIS::KC_F1;
        s_keyMap["f1"] = OIS::KC_F1;
        s_keyMap["kc_f2"] = OIS::KC_F2;
        s_keyMap["f2"] = OIS::KC_F2;
        s_keyMap["kc_f3"] = OIS::KC_F3;
        s_keyMap["f3"] = OIS::KC_F3;
        s_keyMap["kc_f4"] = OIS::KC_F4;
        s_keyMap["f4"] = OIS::KC_F4;
        s_keyMap["kc_f5"] = OIS::KC_F5;
        s_keyMap["f5"] = OIS::KC_F5;
        s_keyMap["kc_f6"] = OIS::KC_F6;
        s_keyMap["f6"] = OIS::KC_F6;
        s_keyMap["kc_f7"] = OIS::KC_F7;
        s_keyMap["f7"] = OIS::KC_F7;
        s_keyMap["kc_f8"] = OIS::KC_F8;
        s_keyMap["f8"] = OIS::KC_F8;
        s_keyMap["kc_f9"] = OIS::KC_F9;
        s_keyMap["f9"] = OIS::KC_F9;
        s_keyMap["kc_f10"] = OIS::KC_F10;
        s_keyMap["f10"] = OIS::KC_F10;
        s_keyMap["kc_numlock"] = OIS::KC_NUMLOCK;
        s_keyMap["numlock"] = OIS::KC_NUMLOCK;
        s_keyMap["kc_scroll"] = OIS::KC_SCROLL;
        s_keyMap["scroll"] = OIS::KC_SCROLL;
        s_keyMap["kc_numpad7"] = OIS::KC_NUMPAD7;
        s_keyMap["numpad7"] = OIS::KC_NUMPAD7;
        s_keyMap["kc_numpad8"] = OIS::KC_NUMPAD8;
        s_keyMap["numpad8"] = OIS::KC_NUMPAD8;
        s_keyMap["kc_numpad9"] = OIS::KC_NUMPAD9;
        s_keyMap["numpad9"] = OIS::KC_NUMPAD9;
        s_keyMap["kc_subtract"] = OIS::KC_SUBTRACT;
        s_keyMap["subtract"] = OIS::KC_SUBTRACT;
        s_keyMap["kc_numpad4"] = OIS::KC_NUMPAD4;
        s_keyMap["numpad4"] = OIS::KC_NUMPAD4;
        s_keyMap["kc_numpad5"] = OIS::KC_NUMPAD5;
        s_keyMap["numpad5"] = OIS::KC_NUMPAD5;
        s_keyMap["kc_numpad6"] = OIS::KC_NUMPAD6;
        s_keyMap["numpad6"] = OIS::KC_NUMPAD6;
        s_keyMap["kc_add"] = OIS::KC_ADD;
        s_keyMap["add"] = OIS::KC_ADD;
        s_keyMap["kc_numpad1"] = OIS::KC_NUMPAD1;
        s_keyMap["numpad1"] = OIS::KC_NUMPAD1;
        s_keyMap["kc_numpad2"] = OIS::KC_NUMPAD2;
        s_keyMap["numpad2"] = OIS::KC_NUMPAD2;
        s_keyMap["kc_numpad3"] = OIS::KC_NUMPAD3;
        s_keyMap["numpad3"] = OIS::KC_NUMPAD3;
        s_keyMap["kc_numpad0"] = OIS::KC_NUMPAD0;
        s_keyMap["numpad0"] = OIS::KC_NUMPAD0;
        s_keyMap["kc_decimal"] = OIS::KC_DECIMAL;
        s_keyMap["decimal"] = OIS::KC_DECIMAL;
        s_keyMap["kc_f11"] = OIS::KC_F11;
        s_keyMap["f11"] = OIS::KC_F11;
        s_keyMap["kc_f12"] = OIS::KC_F12;
        s_keyMap["f12"] = OIS::KC_F12;
    }
    std::string lowerStr = keyStr;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    std::map<std::string, OIS::KeyCode>::const_iterator it = s_keyMap.find(lowerStr);
    if (it != s_keyMap.end())
    {
        return it->second;
    }
    return OIS::KC_UNASSIGNED;
}

Config::Config()
    : m_benchmarkEnabled(false)
    , m_debugLoggingEnabled(false)
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
    return m_debugLoggingEnabled;
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

} // namespace KenshiLua
