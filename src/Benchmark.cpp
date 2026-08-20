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

// Arg pusher for event dispatch scaling: pushes a reusable table { value = 0 }
struct ScalingArgPusher : public IArgPusher {
    int tableRef;
    ScalingArgPusher(lua_State* L) : tableRef(LUA_NOREF) {
        lua_newtable(L);
        lua_pushinteger(L, 0);
        lua_setfield(L, -2, "value");
        tableRef = luaL_ref(L, LUA_REGISTRYINDEX);
    }
    void cleanup(lua_State* L) {
        if (tableRef != LUA_NOREF && tableRef != LUA_REFNIL) {
            luaL_unref(L, LUA_REGISTRYINDEX, tableRef);
            tableRef = LUA_NOREF;
        }
    }
    int push(lua_State* L) const {
        lua_rawgeti(L, LUA_REGISTRYINDEX, tableRef);
        return 1;
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

// Handler counts tested for event dispatch scaling
static const int HANDLER_COUNTS[] = {1, 10, 50, 100, 200};
static const int NUM_HANDLER_COUNTS = 5;
static const int DISPATCH_ITERATIONS = 2000;

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

    // GC
    double gc_workload_create_ms;
    double gc_memory_kb;
    double gc_full_collect_ms;
    double gc_incremental_step_ms;

    // Real bindings (runtime only, -1.0 if N/A)
    double enum_lookup_ms;
    double metatable_method_ms;
    double property_getter_ms;
    double tostring_metamethod_ms;

    // Event dispatch scaling (indexed by NUM_HANDLER_COUNTS)
    double dispatch_total_ms[5];
    double dispatch_per_call_us[5];
};

static const char* CSV_HEADER =
    "timestamp,engine,"
    "state_creation_ms,binding_registration_ms,total_startup_ms,"
    "pure_lua_loop_ms,table_access_ms,table_alloc_ms,load_compile_ms,"
    "require_overhead_ms,pcall_overhead_ms,"
    "gc_workload_create_ms,gc_memory_kb,gc_full_collect_ms,gc_incremental_step_ms,"
    "enum_lookup_ms,metatable_method_ms,property_getter_ms,tostring_metamethod_ms,"
    "dispatch_1h_ms,dispatch_10h_ms,dispatch_50h_ms,dispatch_100h_ms,dispatch_200h_ms,"
    "per_call_1h_us,per_call_10h_us,per_call_50h_us,per_call_100h_us,per_call_200h_us";

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
         << r.gc_workload_create_ms << "," << std::setprecision(0) << r.gc_memory_kb << ","
         << std::setprecision(3) << r.gc_full_collect_ms << "," << r.gc_incremental_step_ms << ","
         << r.enum_lookup_ms << "," << r.metatable_method_ms << "," << r.property_getter_ms << ","
         << r.tostring_metamethod_ms;

    for (int i = 0; i < NUM_HANDLER_COUNTS; ++i) {
        file << "," << r.dispatch_total_ms[i];
    }
    for (int i = 0; i < NUM_HANDLER_COUNTS; ++i) {
        file << "," << std::setprecision(1) << r.dispatch_per_call_us[i];
    }
    file << "\n";

    file.close();
}

// ---------------------------------------------------------------------------
// Main benchmark
// ---------------------------------------------------------------------------

int luaKenshiRunBenchmarkEx(lua_State* L, const std::string& csvFilename, const std::string& logFilename)
{
    BenchmarkResults results;
    results.timestamp = getTimestampISO();
    results.metatable_method_ms = -1.0;
    results.property_getter_ms = -1.0;
    for (int i = 0; i < NUM_HANDLER_COUNTS; ++i) {
        results.dispatch_total_ms[i] = 0.0;
        results.dispatch_per_call_us[i] = 0.0;
    }

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
    ss << "Engine: " << engine << "\n";
    ss << "----------------------------------------\n";

    // =====================================================================
    // 1. Startup Simulation (Avg of 5 runs)
    // =====================================================================
    // Measures the cost of creating a fresh Lua state and registering all
    // KenshiLua bindings.  Does NOT touch the EventSystem singleton to avoid
    // corrupting the live state pointer.
    double total_state_creation = 0;
    double total_binding_registration = 0;
    const int startup_runs = 5;

    for (int i = 0; i < startup_runs; ++i) {
        HighResTimer t_state;
        lua_State* L_temp = luaL_newstate();
        if (L_temp) {
            luaL_openlibs(L_temp);
            total_state_creation += t_state.elapsed_ms();

            HighResTimer t_bind;
            LuaBindings::registerAll(L_temp);
            total_binding_registration += t_bind.elapsed_ms();

            lua_close(L_temp);
        }
    }

    results.state_creation_ms = total_state_creation / startup_runs;
    results.binding_registration_ms = total_binding_registration / startup_runs;
    results.total_startup_ms = results.state_creation_ms + results.binding_registration_ms;

    ss << "Startup Simulation (Avg of " << startup_runs << " runs):\n";
    ss << std::fixed << std::setprecision(3);
    ss << "  State Creation   : " << results.state_creation_ms << " ms\n";
    ss << "  Register Bindings: " << results.binding_registration_ms << " ms\n";
    ss << "  Total Startup    : " << results.total_startup_ms << " ms\n";
    ss << "----------------------------------------\n";

    // =====================================================================
    // 2. Core Language Features
    // =====================================================================
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
    ss << "----------------------------------------\n";

    // =====================================================================
    // 3. Garbage Collection Under Load
    // =====================================================================
    // Creates a controlled working set that simulates mod data structures,
    // then measures GC costs against a known quantity of live objects.
    ss << "Garbage Collection:\n";

    // Collect any garbage from prior tests to get a clean baseline
    lua_gc(L, LUA_GCCOLLECT, 0);
    double mem_before = (double)lua_gc(L, LUA_GCCOUNT, 0);

    // Create 10K tables with 5 fields each (simulates mod data structures)
    const char* gc_workload_code =
        "local store = {}\n"
        "for i = 1, 10000 do\n"
        "    store[i] = { hp=100, x=i*0.5, y=i*0.3, name='unit_'..i, alive=true }\n"
        "end\n"
        "_benchGcStore = store\n";
    results.gc_workload_create_ms = time_lua_code(L, gc_workload_code);

    double mem_after = (double)lua_gc(L, LUA_GCCOUNT, 0);
    results.gc_memory_kb = mem_after - mem_before;

    ss << "  Working set (10K tables x5 fields): " << results.gc_workload_create_ms << " ms\n";
    ss << "  Working set memory                : " << std::setprecision(0) << results.gc_memory_kb << " KB\n";
    ss << std::setprecision(3);

    // Full GC collect with the working set still alive (measures mark/sweep
    // cost over a realistic heap, not just leftover benchmark garbage)
    HighResTimer gc_full_timer;
    lua_gc(L, LUA_GCCOLLECT, 0);
    results.gc_full_collect_ms = gc_full_timer.elapsed_ms();
    ss << "  Full GC collect                   : " << results.gc_full_collect_ms << " ms\n";

    // Incremental GC steps: generate some garbage, then measure step cost.
    // This represents the per-frame GC overhead when using incremental mode.
    time_lua_code(L, "for i=1,5000 do local t={a=1,b=2,c=3} end");
    HighResTimer gc_step_timer;
    for (int i = 0; i < 1000; ++i) {
        lua_gc(L, LUA_GCSTEP, 1);
    }
    results.gc_incremental_step_ms = gc_step_timer.elapsed_ms();
    ss << "  Incremental GC (1K steps)         : " << results.gc_incremental_step_ms << " ms\n";

    // Clean up the anchored working set
    lua_pushnil(L);
    lua_setglobal(L, "_benchGcStore");
    lua_gc(L, LUA_GCCOLLECT, 0);
    ss << "----------------------------------------\n";

    // =====================================================================
    // 4. Real Binding Benchmarks (1M iterations)
    // =====================================================================
    ss << "Real Binding Benchmarks (1M iterations):\n";

    // Enum table lookup - itemType is a real global enum table
    const char* enum_code =
        "local x\n"
        "for i = 1, 1000000 do\n"
        "    x = itemType.ARMOUR\n"
        "end\n";
    results.enum_lookup_ms = time_lua_code(L, enum_code);
    ss << "  Enum Lookup (itemType.ARMOUR)    : " << results.enum_lookup_ms << " ms\n";

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

    // Metatable method resolution and property getter dispatch require a live
    // bound userdata.  GameWorld only exists after the game world is loaded,
    // so these are runtime-only metrics.
    lua_getglobal(L, "GameWorld");
    bool has_gameworld = !lua_isnil(L, -1);
    lua_pop(L, 1);

    if (has_gameworld) {
        const char* metatable_method_code =
            "local fn = GameWorld.isPaused\n"
            "if type(fn) == 'function' then\n"
            "    for i = 1, 1000000 do\n"
            "        fn(GameWorld)\n"
            "    end\n"
            "end\n";
        results.metatable_method_ms = time_lua_code(L, metatable_method_code);
        ss << "  Metatable Method (GameWorld)     : " << results.metatable_method_ms << " ms\n";

        const char* getter_code =
            "local gw = GameWorld\n"
            "local x\n"
            "for i = 1, 1000000 do\n"
            "    x = gw.isPaused\n"
            "end\n";
        results.property_getter_ms = time_lua_code(L, getter_code);
        ss << "  Property Getter (GameWorld)      : " << results.property_getter_ms << " ms\n";
    } else {
        ss << "  Metatable Method / Property      : N/A (runtime only)\n";
    }
    ss << "----------------------------------------\n";

    // =====================================================================
    // 5. Event Dispatch Scaling
    // =====================================================================
    // The core scalability test.  Measures how per-dispatch cost grows as
    // more Lua handlers are registered on a single event.  Uses real Lua
    // function closures (not C functions) to match actual mod workloads.
    // Each handler reads a table field, increments it, and writes it back --
    // a minimal but representative mod operation.
    //
    // The source string passed to registerHandler is a realistic path so
    // that the HandlerInfo snapshot copy cost (which includes std::string
    // copies of the source field) reflects real-world usage.
    ss << "Event Dispatch Scaling (" << DISPATCH_ITERATIONS << " dispatches):\n";
    ss << "  Lua handler body: data.value = data.value + 1\n";

    ScalingArgPusher scaling_pusher(L);

    for (int t = 0; t < NUM_HANDLER_COUNTS; ++t) {
        int handlerCount = HANDLER_COUNTS[t];
        std::vector<int> handlerIds;

        // Create N distinct Lua closures and register them as handlers.
        // Each closure is a separate object, matching real mods where each
        // script file creates its own handler function.
        for (int h = 0; h < handlerCount; ++h) {
            if (luaL_dostring(L,
                "return function(data)\n"
                "    if data then\n"
                "        data.value = (data.value or 0) + 1\n"
                "    end\n"
                "    return true\n"
                "end\n") != LUA_OK) {
                lua_pop(L, 1);
                continue;
            }
            int ref = luaL_ref(L, LUA_REGISTRYINDEX);
            int id = EventSystem::get().registerHandler(
                "benchScaling", ref, "mods/benchmark_test/main.lua");
            handlerIds.push_back(id);
        }

        // Dispatch loop
        HighResTimer dispatch_timer;
        for (int i = 0; i < DISPATCH_ITERATIONS; ++i) {
            EventSystem::get().callHandlers("benchScaling", &scaling_pusher);
        }
        double total_ms = dispatch_timer.elapsed_ms();
        double per_call_us = (total_ms / DISPATCH_ITERATIONS) * 1000.0;

        results.dispatch_total_ms[t] = total_ms;
        results.dispatch_per_call_us[t] = per_call_us;

        ss << "  " << std::setw(3) << handlerCount << " handlers: "
           << std::setw(9) << total_ms << " ms total, "
           << std::setprecision(1) << std::setw(9) << per_call_us
           << std::setprecision(3) << " us/dispatch\n";

        // Cleanup: unregister all handlers for this round.
        // unregisterHandler calls luaL_unref internally, so no manual unref needed.
        for (size_t i = 0; i < handlerIds.size(); ++i) {
            EventSystem::get().unregisterHandler(handlerIds[i]);
        }
        lua_gc(L, LUA_GCCOLLECT, 0);
    }
    scaling_pusher.cleanup(L);

    // Contextualize the worst case against a 30 FPS frame budget (~33.3 ms)
    double worst_per_call_us = results.dispatch_per_call_us[NUM_HANDLER_COUNTS - 1];
    double worst_per_call_ms = worst_per_call_us / 1000.0;
    double frame_budget_ms = 33.3;
    double pct_of_frame = (worst_per_call_ms / frame_budget_ms) * 100.0;
    ss << "  ---\n";
    ss << "  " << HANDLER_COUNTS[NUM_HANDLER_COUNTS - 1]
       << " handlers @ 30 FPS = "
       << std::setprecision(2) << worst_per_call_ms << " ms/frame ("
       << std::setprecision(1) << pct_of_frame << "% of 33.3ms budget)\n";
    ss << std::setprecision(3);

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
