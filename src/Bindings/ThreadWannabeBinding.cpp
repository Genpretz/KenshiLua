#include "pch.h"
#include "kenshi\physicsactual.h"
#include "ThreadWannabeBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static ThreadWannabe* getInstance(lua_State* L, int idx)
{
    return checkObject<ThreadWannabe>(L, idx, ThreadWannabeBinding::getMetatableName());
}

// --- Getters for ThreadWannabe ---
static int ThreadWannabe_get_mute(lua_State* L)
{
    ThreadWannabe* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadWannabe is nil");
    lua_pushlightuserdata(L, &instance->mute);
    return 1;
}

static int ThreadWannabe_get_paused(lua_State* L)
{
    ThreadWannabe* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadWannabe is nil");
    lua_pushboolean(L, instance->paused ? 1 : 0);
    return 1;
}

static int ThreadWannabe_get_speedMult(lua_State* L)
{
    ThreadWannabe* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadWannabe is nil");
    lua_pushnumber(L, instance->speedMult);
    return 1;
}

static int ThreadWannabe_get_haltEverythingMutex(lua_State* L)
{
    ThreadWannabe* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadWannabe is nil");
    lua_pushlightuserdata(L, &instance->haltEverythingMutex);
    return 1;
}

// --- Setters for ThreadWannabe ---
static int ThreadWannabe_set_mute(lua_State* L)
{
    return luaL_error(L, "Property 'mute' is read-only");
}

static int ThreadWannabe_set_paused(lua_State* L)
{
    ThreadWannabe* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadWannabe is nil");
    instance->paused = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ThreadWannabe_set_speedMult(lua_State* L)
{
    ThreadWannabe* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadWannabe is nil");
    instance->speedMult = (double)luaL_checknumber(L, 2);
    return 0;
}

static int ThreadWannabe_set_haltEverythingMutex(lua_State* L)
{
    return luaL_error(L, "Property 'haltEverythingMutex' is read-only");
}

int ThreadWannabeBinding::_CONSTRUCTOR(lua_State* L)
{
    ThreadWannabe* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadWannabe is nil");

    const std::string threadname = luaL_checkstring(L, 2);
    ThreadWannabe* result = instance->_CONSTRUCTOR(threadname);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ThreadWannabeBinding::backThreadUpdate(lua_State* L)
{
    ThreadWannabe* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadWannabe is nil");

    float _a1 = (float)luaL_checknumber(L, 2);
    bool _a2 = lua_toboolean(L, 3) != 0;
    instance->backThreadUpdate(_a1, _a2);
    return 0;
}

int ThreadWannabeBinding::isPaused(lua_State* L)
{
    ThreadWannabe* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadWannabe is nil");

    bool result = instance->isPaused();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ThreadWannabeBinding::setPaused(lua_State* L)
{
    ThreadWannabe* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadWannabe is nil");

    bool on = lua_toboolean(L, 2) != 0;
    float _speedMult = (float)luaL_checknumber(L, 3);
    instance->setPaused(on, _speedMult);
    return 0;
}

int ThreadWannabeBinding::threadProc(lua_State* L)
{
    ThreadWannabe* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadWannabe is nil");

    unsigned long result = instance->threadProc();
    lua_pushinteger(L, result);
    return 1;
}

int ThreadWannabeBinding::_NV_threadProc(lua_State* L)
{
    ThreadWannabe* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadWannabe is nil");

    unsigned long result = instance->_NV_threadProc();
    lua_pushinteger(L, result);
    return 1;
}

int ThreadWannabeBinding::forceLoopMT(lua_State* L)
{
    ThreadWannabe* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadWannabe is nil");

    instance->forceLoopMT();
    return 0;
}

int ThreadWannabeBinding::_NV_forceLoopMT(lua_State* L)
{
    ThreadWannabe* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadWannabe is nil");

    instance->_NV_forceLoopMT();
    return 0;
}

int ThreadWannabeBinding::_DESTRUCTOR(lua_State* L)
{
    ThreadWannabe* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadWannabe is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - ThreadWannabeBinding::_CONSTRUCTOR: ThreadWannabe* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 108: timer (CPerfTimer) - unsupported type
*/

int ThreadWannabeBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ThreadWannabeBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ThreadWannabe object");
    return 1;
}

void ThreadWannabeBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ThreadWannabeBinding::gc },
        { "__tostring", ThreadWannabeBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", ThreadWannabeBinding::_CONSTRUCTOR },
        { "backThreadUpdate", ThreadWannabeBinding::backThreadUpdate },
        { "isPaused", ThreadWannabeBinding::isPaused },
        { "setPaused", ThreadWannabeBinding::setPaused },
        { "threadProc", ThreadWannabeBinding::threadProc },
        { "_NV_threadProc", ThreadWannabeBinding::_NV_threadProc },
        { "forceLoopMT", ThreadWannabeBinding::forceLoopMT },
        { "_NV_forceLoopMT", ThreadWannabeBinding::_NV_forceLoopMT },
        { "_DESTRUCTOR", ThreadWannabeBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        ThreadWannabeBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ThreadWannabeBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "mute", ThreadWannabe_get_mute);
    registerGetter(L, "paused", ThreadWannabe_get_paused);
    registerGetter(L, "speedMult", ThreadWannabe_get_speedMult);
    registerGetter(L, "haltEverythingMutex", ThreadWannabe_get_haltEverythingMutex);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "mute", ThreadWannabe_set_mute);
    registerSetter(L, "paused", ThreadWannabe_set_paused);
    registerSetter(L, "speedMult", ThreadWannabe_set_speedMult);
    registerSetter(L, "haltEverythingMutex", ThreadWannabe_set_haltEverythingMutex);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ThreadClass
    // setMetatableParent(L, ThreadWannabeBinding::getMetatableName(), ThreadClassBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua