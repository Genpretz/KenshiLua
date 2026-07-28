#include "pch.h"
#include "kenshi\threadclass.h"
#include "ThreadClassBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static ThreadClass* getInstance(lua_State* L, int idx)
{
    return checkObject<ThreadClass>(L, idx, ThreadClassBinding::getMetatableName());
}

// --- Getters for ThreadClass ---
static int ThreadClass_get_threadHandle(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");
    lua_pushlightuserdata(L, (void*)instance->threadHandle);
    return 1;
}

static int ThreadClass_get_threadID(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");
    lua_pushinteger(L, instance->threadID);
    return 1;
}

static int ThreadClass_get__running(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");
    lua_pushboolean(L, instance->_running ? 1 : 0);
    return 1;
}

static int ThreadClass_get_name(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");
    lua_pushstring(L, instance->name.c_str());
    return 1;
}

static int ThreadClass_get_frameTime(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");
    lua_pushnumber(L, instance->frameTime);
    return 1;
}

static int ThreadClass_get_infiniteMode(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");
    lua_pushboolean(L, instance->infiniteMode ? 1 : 0);
    return 1;
}

static int ThreadClass_get_pretendThread(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");
    lua_pushboolean(L, instance->pretendThread ? 1 : 0);
    return 1;
}

static int ThreadClass_get_runMute(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");
    lua_pushlightuserdata(L, &instance->runMute);
    return 1;
}

static int ThreadClass_get_lockedWhileRunningMute(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");
    lua_pushlightuserdata(L, &instance->lockedWhileRunningMute);
    return 1;
}

// --- Setters for ThreadClass ---
static int ThreadClass_set_threadID(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");
    instance->threadID = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int ThreadClass_set__running(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");
    instance->_running = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ThreadClass_set_name(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");
    instance->name = luaL_checkstring(L, 2);
    return 0;
}

static int ThreadClass_set_frameTime(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");
    instance->frameTime = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ThreadClass_set_infiniteMode(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");
    instance->infiniteMode = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ThreadClass_set_pretendThread(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");
    instance->pretendThread = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ThreadClass_set_runMute(lua_State* L)
{
    return luaL_error(L, "Property 'runMute' is read-only");
}

static int ThreadClass_set_lockedWhileRunningMute(lua_State* L)
{
    return luaL_error(L, "Property 'lockedWhileRunningMute' is read-only");
}

int ThreadClassBinding::stopRunning(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");

    instance->stopRunning();
    return 0;
}

int ThreadClassBinding::canIRun(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");

    bool result = instance->canIRun();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ThreadClassBinding::startRunning(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");

    float time = (float)luaL_checknumber(L, 2);
    bool result = instance->startRunning(time);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ThreadClassBinding::isRunning(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");

    bool result = instance->isRunning();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ThreadClassBinding::waitForRunningStop_Blocking(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");

    bool result = instance->waitForRunningStop_Blocking();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ThreadClassBinding::_CONSTRUCTOR(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");

    const std::string _name = luaL_checkstring(L, 2);
    ThreadClass* result = instance->_CONSTRUCTOR(_name);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ThreadClassBinding::_DESTRUCTOR(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ThreadClassBinding::setup(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");

    float _frameTime = (float)luaL_checknumber(L, 2);
    bool infinite = lua_toboolean(L, 3) != 0;
    bool _pretendThread = lua_toboolean(L, 4) != 0;
    instance->setup(_frameTime, infinite, _pretendThread);
    return 0;
}

int ThreadClassBinding::beginThread(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");

    float _frameTime = (float)luaL_checknumber(L, 2);
    bool infinite = lua_toboolean(L, 3) != 0;
    int priority = (int)luaL_checkinteger(L, 4);
    bool result = instance->beginThread(_frameTime, infinite, priority);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ThreadClassBinding::setThreadName(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");

    const char* threadName = luaL_checkstring(L, 2);
    instance->setThreadName(threadName);
    return 0;
}

int ThreadClassBinding::endThread(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");

    instance->endThread();
    return 0;
}

int ThreadClassBinding::setName(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");

    const char* name = luaL_checkstring(L, 2);
    instance->setName(name);
    return 0;
}

int ThreadClassBinding::threadProc(lua_State* L)
{
    ThreadClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ThreadClass is nil");

    unsigned long result = instance->threadProc();
    lua_pushinteger(L, result);
    return 1;
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - ThreadClass_get_threadHandle: void* (unbound pointer)
  - ThreadClassBinding::_CONSTRUCTOR: ThreadClass* (unbound pointer)
*/

int ThreadClassBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ThreadClassBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ThreadClass object");
    return 1;
}

void ThreadClassBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ThreadClassBinding::gc },
        { "__tostring", ThreadClassBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "stopRunning", ThreadClassBinding::stopRunning },
        { "canIRun", ThreadClassBinding::canIRun },
        { "startRunning", ThreadClassBinding::startRunning },
        { "isRunning", ThreadClassBinding::isRunning },
        { "waitForRunningStop_Blocking", ThreadClassBinding::waitForRunningStop_Blocking },
        { "_CONSTRUCTOR", ThreadClassBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", ThreadClassBinding::_DESTRUCTOR },
        { "setup", ThreadClassBinding::setup },
        { "beginThread", ThreadClassBinding::beginThread },
        { "setThreadName", ThreadClassBinding::setThreadName },
        { "endThread", ThreadClassBinding::endThread },
        { "setName", ThreadClassBinding::setName },
        { "threadProc", ThreadClassBinding::threadProc },
        { 0, 0 }
    };

    registerClass(
        L, 
        ThreadClassBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ThreadClassBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "threadHandle", ThreadClass_get_threadHandle);
    registerGetter(L, "threadID", ThreadClass_get_threadID);
    registerGetter(L, "_running", ThreadClass_get__running);
    registerGetter(L, "name", ThreadClass_get_name);
    registerGetter(L, "frameTime", ThreadClass_get_frameTime);
    registerGetter(L, "infiniteMode", ThreadClass_get_infiniteMode);
    registerGetter(L, "pretendThread", ThreadClass_get_pretendThread);
    registerGetter(L, "runMute", ThreadClass_get_runMute);
    registerGetter(L, "lockedWhileRunningMute", ThreadClass_get_lockedWhileRunningMute);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "threadID", ThreadClass_set_threadID);
    registerSetter(L, "_running", ThreadClass_set__running);
    registerSetter(L, "name", ThreadClass_set_name);
    registerSetter(L, "frameTime", ThreadClass_set_frameTime);
    registerSetter(L, "infiniteMode", ThreadClass_set_infiniteMode);
    registerSetter(L, "pretendThread", ThreadClass_set_pretendThread);
    registerSetter(L, "runMute", ThreadClass_set_runMute);
    registerSetter(L, "lockedWhileRunningMute", ThreadClass_set_lockedWhileRunningMute);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua