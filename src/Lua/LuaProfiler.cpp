#include "pch.h"
#include "Lua/LuaProfiler.h"
#include "Logger.h"

#include <map>
#include <sstream>
#include <string>
#include <cstdio>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <luajit.h>
}

namespace KenshiLua
{
    static std::map<std::string, int> g_profileSamples;
    static int g_profileTotalSamples = 0;
    static bool g_isProfiling = false;

    static void profileCallback(void* data, lua_State* L, int samples, int vmstate)
    {
        (void)data;
        (void)vmstate;
        size_t len = 0;
        const char* stackStr = luaJIT_profile_dumpstack(L, "f", 0, &len);
        if (stackStr && len > 0) {
            g_profileSamples[std::string(stackStr, len)] += samples;
        } else {
            g_profileSamples["[unknown]"] += samples;
        }
        g_profileTotalSamples += samples;
    }

    bool isProfilerRunning()
    {
        return g_isProfiling;
    }

    std::string formatProfileReport()
    {
        std::stringstream ss;
        ss << "=== LuaJIT Profile Report ===" << "\n";
        ss << "Total Samples: " << g_profileTotalSamples << "\n";
        if (g_profileTotalSamples == 0) {
            ss << "No samples recorded.\n";
            return ss.str();
        }
        for (std::map<std::string, int>::const_iterator it = g_profileSamples.begin(); it != g_profileSamples.end(); ++it) {
            double pct = (double)it->second * 100.0 / (double)g_profileTotalSamples;
            char buf[256];
            sprintf_s(buf, "  %6.2f%% (%d) : %s\n", pct, it->second, it->first.c_str());
            ss << buf;
        }
        ss << "=============================";
        return ss.str();
    }

    int luaKenshiProfileStart(lua_State* L)
    {
        const char* mode = "fi1";
        if (lua_gettop(L) >= 1 && lua_isstring(L, 1)) {
            mode = lua_tostring(L, 1);
        }
        g_profileSamples.clear();
        g_profileTotalSamples = 0;
        g_isProfiling = true;

        luaJIT_profile_start(L, mode, profileCallback, NULL);
        logToFile("LuaJIT profiler started with mode: " + std::string(mode));
        return 0;
    }

    int luaKenshiProfileDump(lua_State* L)
    {
        std::string report = formatProfileReport();
        lua_pushlstring(L, report.c_str(), report.size());
        return 1;
    }

    int luaKenshiProfileStop(lua_State* L)
    {
        if (g_isProfiling) {
            luaJIT_profile_stop(L);
            g_isProfiling = false;
            logToFile("LuaJIT profiler stopped.");
        }
        std::string report = formatProfileReport();
        logToFile(report);
        lua_pushlstring(L, report.c_str(), report.size());
        return 1;
    }
}
