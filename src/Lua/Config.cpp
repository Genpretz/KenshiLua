#include "pch.h"
#include "Lua/Config.h"
#include "Lua/Logger.h"
#include <windows.h>
#include <fstream>
#include <algorithm>
#include <cctype>

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

} // namespace KenshiLua
