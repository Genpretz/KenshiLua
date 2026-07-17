#include "pch.h"
// Touch to trigger build on Lua 5.5 branch
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

// For generic mod workload
static int generic_mod_handler(lua_State* L) {
    // Simulate: get a field, set a field, return something
    // We assume arg 1 is a mock object
    if (lua_istable(L, 1)) {
        lua_getfield(L, 1, "value");
        int val = (int)lua_tointeger(L, -1);
        lua_pop(L, 1);
        lua_pushinteger(L, val + 1);
        lua_setfield(L, 1, "value");
    }
    lua_pushboolean(L, 1); // change return value
    return 1;
}

static int mock_primitive_return(lua_State* L) {
    lua_pushinteger(L, 100);
    return 1;
}

static int mock_string_return(lua_State* L) {
    lua_pushstring(L, "hello");
    return 1;
}

static int mock_object_return(lua_State* L) {
    void* ud = lua_newuserdata(L, sizeof(int));
    *(int*)ud = 100;
    return 1;
}

static int mock_setter(lua_State* L) {
    return 0;
}

static int mock_lua_c_call(lua_State* L) {
    return 0;
}

class MockClass {
public:
    void nonVirtualMethod() {}
    virtual void virtualMethod() {}
};
static MockClass g_mockObj;

static int mock_non_virtual(lua_State* L) {
    g_mockObj.nonVirtualMethod();
    return 0;
}
static int mock_virtual(lua_State* L) {
    g_mockObj.virtualMethod();
    return 0;
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

int luaKenshiRunBenchmark(lua_State* L)
{
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

    double avg_state = total_state_creation / runs;
    double avg_bind = total_binding_registration / runs;
    double avg_total = avg_state + avg_bind;

    ss << "Startup Simulation (Avg of 5 runs):\n";
    ss << "  State Creation   : " << std::fixed << std::setprecision(3) << avg_state << " ms\n";
    ss << "  Register Bindings: " << avg_bind << " ms\n";
    ss << "  Total Startup Sim: " << avg_total << " ms\n";
    ss << "----------------------------------------\n";

    // Micro-benchmarks setup
    lua_pushcfunction(L, mock_lua_c_call); lua_setglobal(L, "mock_lua_c_call");
    lua_pushcfunction(L, mock_primitive_return); lua_setglobal(L, "mock_primitive_return");
    lua_pushcfunction(L, mock_string_return); lua_setglobal(L, "mock_string_return");
    lua_pushcfunction(L, mock_object_return); lua_setglobal(L, "mock_object_return");
    lua_pushcfunction(L, mock_setter); lua_setglobal(L, "mock_setter");
    lua_pushcfunction(L, mock_non_virtual); lua_setglobal(L, "mock_non_virtual");
    lua_pushcfunction(L, mock_virtual); lua_setglobal(L, "mock_virtual");

    // 2. Pure Lua Loop
    const char* pure_lua_code =
        "local x = 0\n"
        "for i = 1, 10000000 do\n"
        "    x = x + 1\n"
        "end\n";
    double pure_time = time_lua_code(L, pure_lua_code);
    ss << "Core Language Features:\n";
    ss << "  Pure Lua Loop (10M): " << pure_time << " ms\n";

    // Table Access & Allocation
    const char* table_access_code =
        "local t = {}\n"
        "for i = 1, 1000 do t[i] = i end\n"
        "local x = 0\n"
        "for i = 1, 1000000 do x = x + t[(i % 1000) + 1] end\n";
    ss << "  Table Access (1M)  : " << time_lua_code(L, table_access_code) << " ms\n";

    const char* table_alloc_code =
        "local t\n"
        "for i = 1, 100000 do t = { a=1, b=2, c=3 } end\n";
    ss << "  Table Alloc (100K) : " << time_lua_code(L, table_alloc_code) << " ms\n";

    // Script Loading and Compilation
    const char* script_code = "return function() local x = 1 + 1 return x end";
    HighResTimer load_timer;
    for (int i = 0; i < 10000; ++i) {
        luaL_loadstring(L, script_code);
        lua_pop(L, 1);
    }
    ss << "  Load/Compile String (10K): " << load_timer.elapsed_ms() << " ms\n";

    // require performance
    const char* require_code =
        "for i = 1, 10000 do\n"
        "    package.loaded['math'] = nil\n"
        "    require('math')\n"
        "end\n";
    ss << "  require() overhead (10K) : " << time_lua_code(L, require_code) << " ms\n";

    // pcall performance
    const char* pcall_code =
        "local function noop() end\n"
        "for i = 1, 1000000 do pcall(noop) end\n";
    ss << "  pcall overhead (1M)      : " << time_lua_code(L, pcall_code) << " ms\n";
    
    // Garbage collection pauses
    HighResTimer gc_timer;
    lua_gc(L, LUA_GCCOLLECT, 0);
    ss << "  Forced GC Pause          : " << gc_timer.elapsed_ms() << " ms\n";
    ss << "----------------------------------------\n";

    // 4. API Transitions
    ss << "API Transitions (1M calls):\n";
    ss << "  C++ call from Lua (0 args) : " << time_lua_code(L, "for i=1, 1000000 do mock_lua_c_call() end") << " ms\n";
    ss << "  Return primitive from C++  : " << time_lua_code(L, "local x; for i=1, 1000000 do x = mock_primitive_return() end") << " ms\n";
    ss << "  Return string from C++     : " << time_lua_code(L, "local x; for i=1, 1000000 do x = mock_string_return() end") << " ms\n";
    ss << "  Return new userdata        : " << time_lua_code(L, "local x; for i=1, 1000000 do x = mock_object_return() end") << " ms\n";
    ss << "  Property setter mock       : " << time_lua_code(L, "for i=1, 1000000 do mock_setter(1) end") << " ms\n";
    ss << "  C++ Non-Virtual Method     : " << time_lua_code(L, "for i=1, 1000000 do mock_non_virtual() end") << " ms\n";
    ss << "  C++ Virtual Method         : " << time_lua_code(L, "for i=1, 1000000 do mock_virtual() end") << " ms\n";

    lua_getglobal(L, "ou");
    bool has_ou = !lua_isnil(L, -1);
    lua_pop(L, 1);
    if (has_ou) {
        ss << "  ou:isPaused() Method Call  : " << time_lua_code(L, "for i=1,1000000 do ou:isPaused() end") << " ms\n";
        ss << "  ou.isPaused Property Access: " << time_lua_code(L, "local x; for i=1,1000000 do x = ou.isPaused end") << " ms\n";
    }
    ss << "----------------------------------------\n";

    // 5. Event System Dispatch & Callbacks
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
    double t0 = cb0.elapsed_ms();
    
    cb1.reset(); for (int i=0; i<100000; ++i) EventSystem::get().callHandlers("benchEvent1", &p1); 
    double t1 = cb1.elapsed_ms();
    
    cb2.reset(); for (int i=0; i<100000; ++i) EventSystem::get().callHandlers("benchEvent2", &p2); 
    double t2 = cb2.elapsed_ms();
    
    cb5.reset(); for (int i=0; i<100000; ++i) EventSystem::get().callHandlers("benchEvent5", &p5); 
    double t5 = cb5.elapsed_ms();

    EventSystem::get().unregisterHandler(handler0);
    EventSystem::get().unregisterHandler(handler1);
    EventSystem::get().unregisterHandler(handler2);
    EventSystem::get().unregisterHandler(handler5);

    ss << "  0 Args Callback : " << t0 << " ms\n";
    ss << "  1 Arg  Callback : " << t1 << " ms\n";
    ss << "  2 Args Callback : " << t2 << " ms\n";
    ss << "  5 Args Callback : " << t5 << " ms\n";

    // Generic Mod Workload & High-Frequency Multi-listener
    ss << "----------------------------------------\n";
    ss << "High-Frequency Hook vs Getters/Setters (100K iter):\n";
    
    // Setup generic mod handler
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
    for (int i=0; i<100000; ++i) { // 100k frames simulated
        EventSystem::get().callHandlers("onFrameUpdate", &mod_pusher);
    }
    double mod_time = mod_timer.elapsed_ms();

    // Compare with pure getter/setter equivalent in C++
    HighResTimer gs_timer;
    volatile int dummy_val = 0;
    for (int i=0; i<100000; ++i) {
        // simulating 200 mods getting and setting a field directly
        for(int m=0; m<200; ++m) {
            int v = dummy_val;
            dummy_val = v + 1;
        }
    }
    double gs_time = gs_timer.elapsed_ms();

    for (size_t i = 0; i < mod_handlers.size(); ++i) {
        EventSystem::get().unregisterHandler(mod_handlers[i]);
    }
    luaL_unref(L, LUA_REGISTRYINDEX, mod_ref);
    luaL_unref(L, LUA_REGISTRYINDEX, dummy_ref);

    ss << "  Simulated C++ Getter/Setter (200x)  : " << gs_time << " ms\n";
    ss << "  Simulated Generic Mod Hook (200 lis): " << mod_time << " ms\n";
    ss << "  Overhead factor                     : " << std::fixed << std::setprecision(2) << (gs_time > 0 ? (mod_time / gs_time) : 0.0) << "x\n";

    ss << "========================================\n";

    std::string results = ss.str();
    logBenchmark(results);

    lua_pushstring(L, results.c_str());
    return 1;
}

bool isBenchmarkEnabled()
{
    return Config::get().isBenchmarkEnabled();
}

void runBenchmarkOnStartup(lua_State* L)
{
    logBenchmark("--- Running Startup Benchmark ---");
    luaKenshiRunBenchmark(L);
    lua_pop(L, 1);
    logBenchmark("--- Startup Benchmark Complete ---");
}

} // namespace KenshiLua
