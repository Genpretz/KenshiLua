#include "pch.h"
#include "Benchmark.h"
#include "Config.h"
#include "Lua/LuaBindings.h"
#include "Logger.h"
#include "EventSystem.h"
#include <windows.h>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <ctime>
namespace KenshiLua
{

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

// For generic mod workload
static int generic_mod_handler(lua_State* L) {
    if (lua_istable(L, 1)) {
        lua_getfield(L, 1, "value");
        int val = (int)lua_tointeger(L, -1);
        lua_pop(L, 1);
        lua_pushinteger(L, val + 1);
        lua_setfield(L, 1, "value");
    }
    lua_pushboolean(L, 1);
    return 1;
}

struct BenchmarkArgPusher0 : public IArgPusher {
    int push(lua_State* L) const { return 0; }
};
struct BenchmarkArgPusher1 : public IArgPusher {
    int push(lua_State* L) const { lua_pushinteger(L, 42); return 1; }
};
struct BenchmarkArgPusher2 : public IArgPusher {
    int push(lua_State* L) const { lua_pushinteger(L, 42); lua_pushnumber(L, 3.14); return 2; }
};
struct BenchmarkArgPusher5 : public IArgPusher {
    int push(lua_State* L) const { 
        lua_pushinteger(L, 1); lua_pushinteger(L, 2); lua_pushinteger(L, 3); 
        lua_pushinteger(L, 4); lua_pushinteger(L, 5); return 5; 
    }
};

// ---------------------------------------------------------------------------
// CSV output helpers
// ---------------------------------------------------------------------------

// Get the directory where KenshiLua.dll lives
static std::string getDllDirectory()
{
    char modulePath[MAX_PATH] = {0};
    HMODULE hMod = NULL;
    // Get the HMODULE of the DLL containing this function
    GetModuleHandleExA(
        GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
        (LPCSTR)&getDllDirectory,
        &hMod);
    if (hMod) {
        GetModuleFileNameA(hMod, modulePath, MAX_PATH);
    }
    std::string dllPath(modulePath);
    size_t pos = dllPath.find_last_of("\\/");
    if (pos != std::string::npos)
        dllPath = dllPath.substr(0, pos);
    else
        dllPath = ".";
    return dllPath;
}

static std::string getTimestampISO()
{
    time_t now = time(NULL);
    std::tm tm;
#ifdef _WIN32
    localtime_s(&tm, &now);
#else
    localtime_r(&now, &tm);
#endif
    char buf[32];
    std::strftime(buf, sizeof(buf), "%Y-%m-%dT%H:%M:%S", &tm);
    return std::string(buf);
}

struct BenchmarkResults {
    std::string timestamp;
    std::string engine;

    // Startup
    double state_creation_ms;
    double binding_registration_ms;
    double total_startup_ms;

    // Core language
    double pure_lua_loop_ms;
    double table_access_ms;
    double table_alloc_ms;
    double load_compile_ms;
    double require_overhead_ms;
    double pcall_overhead_ms;
    double gc_pause_ms;

    // Real binding benchmarks
    double enum_lookup_ms;
    double metatable_method_ms;
    double property_getter_ms;
    double tostring_metamethod_ms;
    double ou_method_ms;       // -1 if not available
    double ou_property_ms;     // -1 if not available

    // Event system
    double cb_0args_ms;
    double cb_1arg_ms;
    double cb_2args_ms;
    double cb_5args_ms;

    // High-frequency hook
    double cpp_getter_setter_ms;
    double mod_hook_200_ms;
    double overhead_factor;
};

static const char* CSV_HEADER =
    "timestamp,engine,"
    "state_creation_ms,binding_registration_ms,total_startup_ms,"
    "pure_lua_loop_ms,table_access_ms,table_alloc_ms,load_compile_ms,"
    "require_overhead_ms,pcall_overhead_ms,gc_pause_ms,"
    "enum_lookup_ms,metatable_method_ms,property_getter_ms,"
    "tostring_metamethod_ms,"
    "ou_method_ms,ou_property_ms,"
    "cb_0args_ms,cb_1arg_ms,cb_2args_ms,cb_5args_ms,"
    "cpp_getter_setter_ms,mod_hook_200_ms,overhead_factor";

static void writeBenchmarkCSV(const BenchmarkResults& r, const std::string& csvFilename = "KenshiLua_Benchmark.csv")
{
    std::string csvPath = getDllDirectory() + "\\" + csvFilename;

    // Check if file exists and has content (need header?)
    bool needHeader = false;
    {
        std::ifstream check(csvPath);
        if (!check.good() || check.peek() == std::ifstream::traits_type::eof()) {
            needHeader = true;
        }
        check.close();
    }

    std::ofstream file(csvPath, std::ios::app);
    if (!file.is_open()) return;

    if (needHeader) {
        file << CSV_HEADER << "\n";
    }

    file << std::fixed << std::setprecision(3);
    file << r.timestamp << "," << r.engine << ","
         << r.state_creation_ms << "," << r.binding_registration_ms << "," << r.total_startup_ms << ","
         << r.pure_lua_loop_ms << "," << r.table_access_ms << "," << r.table_alloc_ms << ","
         << r.load_compile_ms << "," << r.require_overhead_ms << "," << r.pcall_overhead_ms << ","
         << r.gc_pause_ms << ","
         << r.enum_lookup_ms << "," << r.metatable_method_ms << "," << r.property_getter_ms << ","
         << r.tostring_metamethod_ms << ","
         << r.ou_method_ms << "," << r.ou_property_ms << ","
         << r.cb_0args_ms << "," << r.cb_1arg_ms << "," << r.cb_2args_ms << "," << r.cb_5args_ms << ","
         << r.cpp_getter_setter_ms << "," << r.mod_hook_200_ms << "," << r.overhead_factor
         << "\n";

    file.close();
}

// ---------------------------------------------------------------------------
// Main benchmark
// ---------------------------------------------------------------------------

int luaKenshiRunBenchmarkEx(lua_State* L, const std::string& csvFilename, const std::string& logFilename)
{
    BenchmarkResults results;
    results.timestamp = getTimestampISO();
    results.ou_method_ms = -1.0;
    results.ou_property_ms = -1.0;

    std::stringstream ss;
    ss << "========================================\n";
    ss << "       KenshiLua Benchmark Results      \n";
    ss << "========================================\n";

    // Determine Lua Engine
    const char* engine = "Lua 5.x";
    lua_getglobal(L, "jit");
    if (lua_istable(L, -1)) {
        lua_getfield(L, -1, "version");
        const char* v = lua_tostring(L, -1);
        if (v) engine = v;
        lua_pop(L, 1);
    }
    lua_pop(L, 1);
    results.engine = engine;
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
            
            lua_pushcfunction(L_temp, luaRegisterHandler);
            lua_setglobal(L_temp, "registerHandler");
            lua_pushcfunction(L_temp, luaUnregisterHandler);
            lua_setglobal(L_temp, "unregisterHandler");

            double bind_time = t_bind.elapsed_ms();
            total_binding_registration += bind_time;

            lua_close(L_temp);
        }
    }

    results.state_creation_ms = total_state_creation / runs;
    results.binding_registration_ms = total_binding_registration / runs;
    results.total_startup_ms = results.state_creation_ms + results.binding_registration_ms;

    ss << "Startup Simulation (Avg of 5 runs):\n";
    ss << std::fixed << std::setprecision(3);
    ss << "  State Creation   : " << results.state_creation_ms << " ms\n";
    ss << "  Register Bindings: " << results.binding_registration_ms << " ms\n";
    ss << "  Total Startup Sim: " << results.total_startup_ms << " ms\n";
    ss << "----------------------------------------\n";

    // 2. Core Language Features
    const char* pure_lua_code =
        "local x = 0\n"
        "for i = 1, 10000000 do\n"
        "    x = x + 1\n"
        "end\n";
    results.pure_lua_loop_ms = time_lua_code(L, pure_lua_code);

    ss << "Core Language Features:\n";
    ss << "  Pure Lua Loop (10M): " << results.pure_lua_loop_ms << " ms\n";

    // Table Access & Allocation
    const char* table_access_code =
        "local t = {}\n"
        "for i = 1, 1000 do t[i] = i end\n"
        "local x = 0\n"
        "for i = 1, 1000000 do x = x + t[(i % 1000) + 1] end\n";
    results.table_access_ms = time_lua_code(L, table_access_code);
    ss << "  Table Access (1M)  : " << results.table_access_ms << " ms\n";

    const char* table_alloc_code =
        "local t\n"
        "for i = 1, 100000 do t = { a=1, b=2, c=3 } end\n";
    results.table_alloc_ms = time_lua_code(L, table_alloc_code);
    ss << "  Table Alloc (100K) : " << results.table_alloc_ms << " ms\n";

    // Script Loading and Compilation
    const char* script_code = "return function() local x = 1 + 1 return x end";
    HighResTimer load_timer;
    for (int i = 0; i < 10000; ++i) {
        luaL_loadstring(L, script_code);
        lua_pop(L, 1);
    }
    results.load_compile_ms = load_timer.elapsed_ms();
    ss << "  Load/Compile String (10K): " << results.load_compile_ms << " ms\n";

    // require performance - use synthetic preload module to avoid filesystem search
    const char* require_code =
        "for i = 1, 10000 do\n"
        "    package.loaded['_benchmod'] = nil\n"
        "    package.preload['_benchmod'] = function() return {} end\n"
        "    require('_benchmod')\n"
        "end\n";
    results.require_overhead_ms = time_lua_code(L, require_code);
    ss << "  require() overhead (10K) : " << results.require_overhead_ms << " ms\n";

    // pcall performance
    const char* pcall_code =
        "local function noop() end\n"
        "for i = 1, 1000000 do pcall(noop) end\n";
    results.pcall_overhead_ms = time_lua_code(L, pcall_code);
    ss << "  pcall overhead (1M)      : " << results.pcall_overhead_ms << " ms\n";
    
    // Garbage collection pauses
    HighResTimer gc_timer;
    lua_gc(L, LUA_GCCOLLECT, 0);
    results.gc_pause_ms = gc_timer.elapsed_ms();
    ss << "  Forced GC Pause          : " << results.gc_pause_ms << " ms\n";
    ss << "----------------------------------------\n";

    // 3. Real Binding Benchmarks
    ss << "Real Binding Benchmarks (1M iterations):\n";

    // Enum table lookup - itemType is a real global enum table
    const char* enum_code =
        "local x\n"
        "for i = 1, 1000000 do\n"
        "    x = itemType.ARMOUR\n"
        "end\n";
    results.enum_lookup_ms = time_lua_code(L, enum_code);
    ss << "  Enum Lookup (itemType.ARMOUR)    : " << results.enum_lookup_ms << " ms\n";

    // Metatable method resolution - create a userdata with a real metatable and call a method
    // We use GameWorld's metatable since it has many methods registered
    const char* metatable_method_code =
        "local mt = getmetatable(gameWorld) or {}\n"
        "local fn = mt.__index and mt.__index.isPaused\n"
        "if fn then\n"
        "    for i = 1, 1000000 do\n"
        "        fn(gameWorld)\n"
        "    end\n"
        "end\n";

    // Check if gameWorld global exists
    lua_getglobal(L, "gameWorld");
    bool has_gameworld = !lua_isnil(L, -1);
    lua_pop(L, 1);

    if (has_gameworld) {
        results.metatable_method_ms = time_lua_code(L, metatable_method_code);
    } else {
        // Fallback: benchmark metatable __index resolution using KenshiLua table
        const char* fallback_method_code =
            "local kl = KenshiLua\n"
            "local x\n"
            "for i = 1, 1000000 do\n"
            "    x = kl.log\n"
            "end\n";
        results.metatable_method_ms = time_lua_code(L, fallback_method_code);
    }
    ss << "  Metatable Method Resolution     : " << results.metatable_method_ms << " ms\n";

    // Property getter dispatch - access a field on a bound userdata via __getters
    if (has_gameworld) {
        const char* getter_code =
            "local gw = gameWorld\n"
            "local x\n"
            "for i = 1, 1000000 do\n"
            "    x = gw.isPaused\n"
            "end\n";
        results.property_getter_ms = time_lua_code(L, getter_code);
    } else {
        // Fallback: table field access on KenshiLua global
        const char* fallback_getter_code =
            "local kl = KenshiLua\n"
            "local x\n"
            "for i = 1, 1000000 do\n"
            "    x = kl.version\n"
            "end\n";
        results.property_getter_ms = time_lua_code(L, fallback_getter_code);
    }
    ss << "  Property Getter Dispatch        : " << results.property_getter_ms << " ms\n";

    // tostring on enum table value - exercises __tostring metamethod if present
    const char* tostring_code =
        "local ts = tostring\n"
        "local val = itemType.ARMOUR\n"
        "local x\n"
        "for i = 1, 1000000 do\n"
        "    x = ts(val)\n"
        "end\n";
    results.tostring_metamethod_ms = time_lua_code(L, tostring_code);
    ss << "  tostring() on value (1M)        : " << results.tostring_metamethod_ms << " ms\n";

    // ou (GameWorld) method vs property - only if available at runtime
    lua_getglobal(L, "ou");
    bool has_ou = !lua_isnil(L, -1);
    lua_pop(L, 1);
    if (has_ou) {
        results.ou_method_ms = time_lua_code(L, "for i=1,1000000 do ou:isPaused() end");
        results.ou_property_ms = time_lua_code(L, "local x; for i=1,1000000 do x = ou.isPaused end");
        ss << "  ou:isPaused() Method Call       : " << results.ou_method_ms << " ms\n";
        ss << "  ou.isPaused Property Access      : " << results.ou_property_ms << " ms\n";
    } else {
        ss << "  ou:isPaused() / ou.isPaused     : N/A (no game world at startup)\n";
    }
    ss << "----------------------------------------\n";

    // 4. Event System Dispatch & Callbacks
    ss << "Event System / Callbacks (100K dispatches):\n";
    
    lua_pushcfunction(L, dummy_handler);
    int dummy_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    int handler0 = EventSystem::get().registerHandler("benchEvent0", dummy_ref);
    int handler1 = EventSystem::get().registerHandler("benchEvent1", dummy_ref);
    int handler2 = EventSystem::get().registerHandler("benchEvent2", dummy_ref);
    int handler5 = EventSystem::get().registerHandler("benchEvent5", dummy_ref);

    BenchmarkArgPusher0 p0;
    BenchmarkArgPusher1 p1;
    BenchmarkArgPusher2 p2;
    BenchmarkArgPusher5 p5;

    HighResTimer cb0, cb1, cb2, cb5;
    
    cb0.reset(); for (int i=0; i<100000; ++i) EventSystem::get().callHandlers("benchEvent0", &p0); 
    results.cb_0args_ms = cb0.elapsed_ms();
    
    cb1.reset(); for (int i=0; i<100000; ++i) EventSystem::get().callHandlers("benchEvent1", &p1); 
    results.cb_1arg_ms = cb1.elapsed_ms();
    
    cb2.reset(); for (int i=0; i<100000; ++i) EventSystem::get().callHandlers("benchEvent2", &p2); 
    results.cb_2args_ms = cb2.elapsed_ms();
    
    cb5.reset(); for (int i=0; i<100000; ++i) EventSystem::get().callHandlers("benchEvent5", &p5); 
    results.cb_5args_ms = cb5.elapsed_ms();

    EventSystem::get().unregisterHandler(handler0);
    EventSystem::get().unregisterHandler(handler1);
    EventSystem::get().unregisterHandler(handler2);
    EventSystem::get().unregisterHandler(handler5);

    ss << "  0 Args Callback : " << results.cb_0args_ms << " ms\n";
    ss << "  1 Arg  Callback : " << results.cb_1arg_ms << " ms\n";
    ss << "  2 Args Callback : " << results.cb_2args_ms << " ms\n";
    ss << "  5 Args Callback : " << results.cb_5args_ms << " ms\n";

    // 5. High-Frequency Multi-listener
    ss << "----------------------------------------\n";
    ss << "High-Frequency Hook vs Getters/Setters (100K iter):\n";
    
    lua_pushcfunction(L, generic_mod_handler);
    int mod_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    
    // Register 200 listeners
    std::vector<int> mod_handlers;
    for (int i=0; i<200; ++i) {
        mod_handlers.push_back(EventSystem::get().registerHandler("onFrameUpdate", mod_ref));
    }

    struct ModArgPusher : public IArgPusher {
        int push(lua_State* L) const {
            lua_newtable(L);
            lua_pushinteger(L, 0);
            lua_setfield(L, -2, "value");
            return 1;
        }
    };
    ModArgPusher mod_pusher;
    
    HighResTimer mod_timer;
    for (int i=0; i<100000; ++i) {
        EventSystem::get().callHandlers("onFrameUpdate", &mod_pusher);
    }
    results.mod_hook_200_ms = mod_timer.elapsed_ms();

    // Compare with pure getter/setter equivalent in C++
    HighResTimer gs_timer;
    volatile int dummy_val = 0;
    for (int i=0; i<100000; ++i) {
        for(int m=0; m<200; ++m) {
            int v = dummy_val;
            dummy_val = v + 1;
        }
    }
    results.cpp_getter_setter_ms = gs_timer.elapsed_ms();

    for (size_t i = 0; i < mod_handlers.size(); ++i) {
        EventSystem::get().unregisterHandler(mod_handlers[i]);
    }
    luaL_unref(L, LUA_REGISTRYINDEX, mod_ref);
    luaL_unref(L, LUA_REGISTRYINDEX, dummy_ref);

    results.overhead_factor = (results.cpp_getter_setter_ms > 0) ? (results.mod_hook_200_ms / results.cpp_getter_setter_ms) : 0.0;

    ss << "  Simulated C++ Getter/Setter (200x)  : " << results.cpp_getter_setter_ms << " ms\n";
    ss << "  Simulated Generic Mod Hook (200 lis): " << results.mod_hook_200_ms << " ms\n";
    ss << "  Overhead factor                     : " << std::fixed << std::setprecision(2) << results.overhead_factor << "x\n";

    ss << "========================================\n";

    std::string log_output = ss.str();
    logBenchmark(log_output, logFilename);

    // Write CSV row
    writeBenchmarkCSV(results, csvFilename);

    lua_pushstring(L, log_output.c_str());
    return 1;
}

int luaKenshiRunBenchmark(lua_State* L)
{
    std::string csvFilename = "KenshiLua_Benchmark_Runtime.csv";
    std::string logFilename = "KenshiLua_Benchmark_Runtime.log";

    if (lua_gettop(L) >= 1 && lua_isstring(L, 1)) {
        csvFilename = lua_tostring(L, 1);
    }
    if (lua_gettop(L) >= 2 && lua_isstring(L, 2)) {
        logFilename = lua_tostring(L, 2);
    }

    return luaKenshiRunBenchmarkEx(L, csvFilename, logFilename);
}

bool isBenchmarkEnabled()
{
    return Config::get().isBenchmarkEnabled();
}

void runBenchmarkOnStartup(lua_State* L, bool isInitialStartup)
{
    std::string csvFilename = isInitialStartup ? "KenshiLua_Benchmark.csv" : "KenshiLua_Benchmark_Runtime.csv";
    std::string logFilename = isInitialStartup ? "KenshiLua_Benchmark.log" : "KenshiLua_Benchmark_Runtime.log";
    std::string header = isInitialStartup ? "--- Running Startup Benchmark ---" : "--- Running Runtime Restart Benchmark ---";
    std::string footer = isInitialStartup ? "--- Startup Benchmark Complete ---" : "--- Runtime Restart Benchmark Complete ---";

    logBenchmark(header, logFilename);
    luaKenshiRunBenchmarkEx(L, csvFilename, logFilename);
    lua_pop(L, 1);
    logBenchmark(footer, logFilename);
}

} // namespace KenshiLua
