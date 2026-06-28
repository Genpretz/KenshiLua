#include "pch.h"
#include "Lua/Benchmark.h"
#include "Lua/LuaBindings.h"
#include "Lua/LuaUtils.h"
#include "Lua/Logger.h"
#include "EventSystem.h"
#include <windows.h>
#include <sstream>
#include <iomanip>
#include <fstream>

namespace KenshiLua
{
    void logBenchmark(const std::string& message);

    class HighResTimer {
        LARGE_INTEGER start_time;
        LARGE_INTEGER frequency;
    public:
        HighResTimer() {
            QueryPerformanceFrequency(&frequency);
            reset();
        }
        void reset() {
            QueryPerformanceCounter(&start_time);
        }
        double elapsed_ms() const {
            LARGE_INTEGER now;
            QueryPerformanceCounter(&now);
            return (double)(now.QuadPart - start_time.QuadPart) * 1000.0 / (double)frequency.QuadPart;
        }
    };

    static double time_lua_code(lua_State* L, const char* code) {
        HighResTimer t;
        if (luaL_dostring(L, code) != LUA_OK) {
            const char* err = lua_tostring(L, -1);
            logToFile(std::string("Benchmark error: ") + (err ? err : "unknown"));
            lua_pop(L, 1);
            return -1.0;
        }
        return t.elapsed_ms();
    }

    static int dummy_handler(lua_State* L) {
        return 0;
    }

    struct BenchmarkArgPusher : public IArgPusher {
        int push(lua_State* L) const {
            lua_pushinteger(L, 42);
            return 1;
        }
    };

    int luaKenshiRunBenchmark(lua_State* L)
    {
        std::stringstream ss;
        ss << "========================================\n";
        ss << "       KenshiLua Benchmark Results      \n";
        ss << "========================================\n";
        // Determine Lua Engine at runtime
        const char* engine = "Lua 5.x";
        lua_getglobal(L, "jit");
        if (lua_istable(L, -1)) {
            lua_getfield(L, -1, "version");
            const char* v = lua_tostring(L, -1);
            if (v) engine = v;
            lua_pop(L, 1);
        }
        lua_pop(L, 1);
        ss << "Engine type: " << engine << "\n";
        ss << "----------------------------------------\n";
        
        // 1. Startup Simulation (Avg of 5 runs)
        double total_state_creation = 0;
        double total_binding_registration = 0;
        const int runs = 5;
        for (int i = 0; i < runs; ++i) {
            HighResTimer t_state;
            lua_State* L_temp = luaL_newstate();
            if (L_temp) {
                luaL_openlibs(L_temp);
                double state_time = t_state.elapsed_ms();
                total_state_creation += state_time;
                HighResTimer t_bind;
                LuaBindings::registerAll(L_temp);
                
                // Mock EventSystem registration
                lua_getglobal(L_temp, "KenshiLua");
                if (lua_istable(L_temp, -1)) {
                    lua_pushcfunction(L_temp, luaRegisterHandler);
                    lua_setfield(L_temp, -2, "registerHandler");
                    lua_pushcfunction(L_temp, luaUnregisterHandler);
                    lua_setfield(L_temp, -2, "unregisterHandler");
                }
                lua_pop(L_temp, 1);
                double bind_time = t_bind.elapsed_ms();
                total_binding_registration += bind_time;
                lua_close(L_temp);
            }
        }
        double avg_state = total_state_creation / runs;
        double avg_bind = total_binding_registration / runs;
        double avg_total = avg_state + avg_bind;
        ss << "Startup Simulation (Avg of 5 runs):\n";
        ss << "  State Creation   : " << std::fixed << std::setprecision(3) << avg_state << " ms\n";
        ss << "  Register Bindings: " << avg_bind << " ms\n";
        ss << "  Total Startup Sim: " << avg_total << " ms\n";
        ss << "----------------------------------------\n";
        
        // 2. Pure Lua Loop
        const char* pure_lua_code =
            "local x = 0\n"
            "for i = 1, 10000000 do\n"
            "    x = x + 1\n"
            "end\n";
        double pure_time = time_lua_code(L, pure_lua_code);
        ss << "Micro-benchmarks:\n";
        ss << "  Pure Lua Loop (10M): " << pure_time << " ms\n";
        
        // 3. Table Access
        const char* table_code =
            "local t = {}\n"
            "for i = 1, 1000 do\n"
            "    t[i] = i\n"
            "end\n"
            "local x = 0\n"
            "for i = 1, 1000000 do\n"
            "    x = x + t[(i % 1000) + 1]\n"
            "end\n";
        double table_time = time_lua_code(L, table_code);
        ss << "  Table Access (1M)  : " << table_time << " ms\n";
        ss << "----------------------------------------\n";
        
        // 4. API Transitions
        ss << "API Transitions (1M):\n";
        // Check if GameWorld (ou) is available
        lua_getglobal(L, "ou");
        bool has_ou = !lua_isnil(L, -1);
        lua_pop(L, 1);
        if (has_ou) {
            const char* api_call_code =
                "for i = 1, 1000000 do\n"
                "    ou:isPaused()\n"
                "end\n";
            double api_call_time = time_lua_code(L, api_call_code);
            ss << "  Method Call (ou:isPaused()): " << api_call_time << " ms\n";
            const char* api_prop_code =
                "local x\n"
                "for i = 1, 1000000 do\n"
                "    x = ou.isPaused\n"
                "end\n";
            double api_prop_time = time_lua_code(L, api_prop_code);
            ss << "  Property Access (ou.isPaused): " << api_prop_time << " ms\n";
        } else {
            ss << "  Method Call (ou:isPaused()): N/A (GameWorld 'ou' not available)\n";
            ss << "  Property Access (ou.isPaused): N/A (GameWorld 'ou' not available)\n";
        }
        ss << "----------------------------------------\n";
        
        // 5. Event System Dispatch
        lua_pushcfunction(L, dummy_handler);
        int ref = luaL_ref(L, LUA_REGISTRYINDEX);
        int handlerId = EventSystem::get().registerHandler("onBenchmarkEvent", ref);
        HighResTimer event_timer;
        BenchmarkArgPusher pusher;
        for (int i = 0; i < 100000; ++i) {
            EventSystem::get().callHandlers("onBenchmarkEvent", &pusher);
        }
        double event_time = event_timer.elapsed_ms();
        EventSystem::get().unregisterHandler(handlerId);
        luaL_unref(L, LUA_REGISTRYINDEX, ref);
        ss << "Event System (100K):\n";
        ss << "  Dispatch with 1 Arg: " << event_time << " ms\n";
        ss << "========================================\n";
        
        std::string results = ss.str();
        logBenchmark(results);
        lua_pushstring(L, results.c_str());
        return 1;
    }

    static bool readConfigBenchmarkEnabled()
    {
        HMODULE hMod = GetModuleHandleA("KenshiLua.dll");
        char modulePath[MAX_PATH] = {0};
        GetModuleFileNameA(hMod, modulePath, MAX_PATH);
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
            return false;
        }
        std::string line;
        while (std::getline(file, line)) {
            if (line.find("enable_benchmark=true") != std::string::npos ||
                line.find("enable_benchmark=1") != std::string::npos) {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }

    bool isBenchmarkEnabled()
    {
        return readConfigBenchmarkEnabled();
    }

    void runBenchmarkOnStartup(lua_State* L)
    {
        logBenchmark("--- Running Startup Benchmark ---");
        luaKenshiRunBenchmark(L);
        lua_pop(L, 1);
        logBenchmark("--- Startup Benchmark Complete ---");
    }
} // namespace KenshiLua
