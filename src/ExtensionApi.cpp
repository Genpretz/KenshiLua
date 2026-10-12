#include "pch.h"

#define KENSHILUA_BUILDING_DLL
#include "../include/KenshiLua.h"

#include "Plugin.h"
#include "Logger.h"
#include "Version.h"
#include "Lua/LuaState.h"
#include "Lua/BindingHelpers.h"
#include "ScriptLoader.h"
#include "EventSystem.h"

#include <cstring>
#include <new>
#include <string>

namespace
{
    void clearBuffer(char* buffer, size_t bufferSize)
    {
        if (buffer && bufferSize)
            buffer[0] = '\0';
    }

    void copyBuffer(const std::string& value, char* buffer, size_t bufferSize)
    {
        if (!buffer || bufferSize == 0)
            return;

        size_t length = value.size();
        if (length >= bufferSize)
            length = bufferSize - 1;
        if (length)
            std::memcpy(buffer, value.data(), length);
        buffer[length] = '\0';
    }

    int validateRuntime(lua_State** outState, char* error, size_t errorSize)
    {
        if (!KenshiLua::Plugin::get().isInitialized() ||
            !KenshiLua::g_luaState || !KenshiLua::g_luaState->isValid())
        {
            copyBuffer("KenshiLua is not initialized", error, errorSize);
            return KENSHILUA_STATUS_NOT_INITIALIZED;
        }
        if (!KenshiLua::Plugin::get().isLuaThread())
        {
            copyBuffer("KenshiLua Lua API called from the wrong thread", error, errorSize);
            return KENSHILUA_STATUS_WRONG_THREAD;
        }
        if (outState)
            *outState = KenshiLua::g_luaState->getState();
        return KENSHILUA_STATUS_OK;
    }

    class StackTopRestorer
    {
    public:
        explicit StackTopRestorer(lua_State* state)
            : m_state(state), m_target(state ? lua_gettop(state) : 0) {}

        ~StackTopRestorer()
        {
            if (m_state)
                lua_settop(m_state, m_target);
        }

        void setTarget(int target) { m_target = target; }

    private:
        StackTopRestorer(const StackTopRestorer&);
        StackTopRestorer& operator=(const StackTopRestorer&);

        lua_State* m_state;
        int m_target;
    };

    int unexpectedFailure(const char* operation, char* error, size_t errorSize)
    {
        std::string message = operation ? operation : "KenshiLua extension API";
        message += " failed with an unexpected native exception";
        copyBuffer(message, error, errorSize);
        KenshiLua::logToFileError(message);
        return KENSHILUA_STATUS_UNKNOWN_ERROR;
    }

    int memoryFailure(const char* operation, char* error, size_t errorSize)
    {
        std::string message = operation ? operation : "KenshiLua extension API";
        message += " failed because native memory allocation failed";
        copyBuffer(message, error, errorSize);
        KenshiLua::logToFileError(message);
        return KENSHILUA_STATUS_LUA_MEMORY_ERROR;
    }

    int KENSHILUA_CALL apiIsInitialized()
    {
        try
        {
            return KenshiLua::Plugin::get().isInitialized() &&
                KenshiLua::g_luaState && KenshiLua::g_luaState->isValid() ? 1 : 0;
        }
        catch (...)
        {
            return 0;
        }
    }

    lua_State* KENSHILUA_CALL apiGetState()
    {
        try
        {
            lua_State* state = NULL;
            return validateRuntime(&state, NULL, 0) == KENSHILUA_STATUS_OK ? state : NULL;
        }
        catch (...)
        {
            return NULL;
        }
    }

    const char* KENSHILUA_CALL apiGetVersion() { return KENSHILUA_VERSION_STRING; }
    int KENSHILUA_CALL apiGetVersionMajor() { return KENSHILUA_VERSION_MAJOR; }
    int KENSHILUA_CALL apiGetVersionMinor() { return KENSHILUA_VERSION_MINOR; }
    int KENSHILUA_CALL apiGetVersionPatch() { return KENSHILUA_VERSION_PATCH; }

    int KENSHILUA_CALL apiRunScript(const char* scriptPath, char* error, size_t errorSize)
    {
        clearBuffer(error, errorSize);
        try
        {
            lua_State* state = NULL;
            int validation = validateRuntime(&state, error, errorSize);
            if (validation != KENSHILUA_STATUS_OK)
                return validation;
            StackTopRestorer restoreStack(state);
            if (!scriptPath || !*scriptPath)
            {
                copyBuffer("Script path must not be empty", error, errorSize);
                return KENSHILUA_STATUS_INVALID_ARGUMENT;
            }

            std::string resolved = KenshiLua::ScriptLoader::get().resolveScriptPath(scriptPath);
            if (resolved.empty())
            {
                copyBuffer("Script file was not found in an active mod: " +
                    std::string(scriptPath), error, errorSize);
                return KENSHILUA_STATUS_FILE_NOT_FOUND;
            }

            KenshiLua::ScriptLoader::RunScriptStatus runStatus =
                KenshiLua::ScriptLoader::RUN_SCRIPT_OK;
            std::string runError;
            if (!KenshiLua::ScriptLoader::get().runScriptSandboxed(
                    state, resolved, "@" + std::string(scriptPath), &runError, &runStatus))
            {
                copyBuffer(runError, error, errorSize);
                switch (runStatus)
                {
                case KenshiLua::ScriptLoader::RUN_SCRIPT_FILE_ERROR:
                    return KENSHILUA_STATUS_FILE_NOT_FOUND;
                case KenshiLua::ScriptLoader::RUN_SCRIPT_SYNTAX_ERROR:
                    return KENSHILUA_STATUS_LUA_SYNTAX_ERROR;
                case KenshiLua::ScriptLoader::RUN_SCRIPT_MEMORY_ERROR:
                    return KENSHILUA_STATUS_LUA_MEMORY_ERROR;
                default:
                    return KENSHILUA_STATUS_LUA_RUNTIME_ERROR;
                }
            }
            return KENSHILUA_STATUS_OK;
        }
        catch (const std::bad_alloc&)
        {
            return memoryFailure("RunScript", error, errorSize);
        }
        catch (...)
        {
            return unexpectedFailure("RunScript", error, errorSize);
        }
    }

    int KENSHILUA_CALL apiRunString(const char* code, const char* chunkName,
        char* error, size_t errorSize)
    {
        clearBuffer(error, errorSize);
        try
        {
            lua_State* state = NULL;
            int validation = validateRuntime(&state, error, errorSize);
            if (validation != KENSHILUA_STATUS_OK)
                return validation;
            StackTopRestorer restoreStack(state);
            if (!code)
            {
                copyBuffer("Lua source must not be null", error, errorSize);
                return KENSHILUA_STATUS_INVALID_ARGUMENT;
            }

            const char* effectiveChunk = chunkName && *chunkName ? chunkName : "eval";
            int loadStatus = luaL_loadbuffer(state, code, std::strlen(code), effectiveChunk);
            if (loadStatus != LUA_OK)
            {
                const char* message = lua_tostring(state, -1);
                copyBuffer(message ? message : "Lua compilation failed", error, errorSize);
                return loadStatus == LUA_ERRMEM ? KENSHILUA_STATUS_LUA_MEMORY_ERROR :
                    KENSHILUA_STATUS_LUA_SYNTAX_ERROR;
            }

            std::string callError;
            int callStatus = LUA_OK;
            if (!KenshiLua::LuaState::pcallWithTraceback(
                    state, 0, 0, &callError, &callStatus))
            {
                copyBuffer(callError, error, errorSize);
                return callStatus == LUA_ERRMEM ? KENSHILUA_STATUS_LUA_MEMORY_ERROR :
                    KENSHILUA_STATUS_LUA_RUNTIME_ERROR;
            }

            return KENSHILUA_STATUS_OK;
        }
        catch (const std::bad_alloc&)
        {
            return memoryFailure("DoString", error, errorSize);
        }
        catch (...)
        {
            return unexpectedFailure("DoString", error, errorSize);
        }
    }

    struct StackArgumentPusher : public KenshiLua::IArgPusher
    {
        StackArgumentPusher(int startIndex, int count)
            : m_startIndex(startIndex), m_count(count) {}

        virtual int push(lua_State* state) const
        {
            for (int i = 0; i < m_count; ++i)
                lua_pushvalue(state, m_startIndex + i);
            return m_count;
        }

        int m_startIndex;
        int m_count;
    };

    int KENSHILUA_CALL apiDispatchEvent(const char* eventName, int argumentCount,
        char* error, size_t errorSize)
    {
        clearBuffer(error, errorSize);
        try
        {
            lua_State* state = NULL;
            int validation = validateRuntime(&state, error, errorSize);
            if (validation != KENSHILUA_STATUS_OK)
                return validation;
            StackTopRestorer restoreStack(state);
            if (!eventName || !*eventName || argumentCount < 0)
            {
                copyBuffer("Event name and argument count are invalid", error, errorSize);
                return KENSHILUA_STATUS_INVALID_ARGUMENT;
            }

            int originalTop = lua_gettop(state);
            if (argumentCount > originalTop)
            {
                copyBuffer("Event argument count exceeds the Lua stack height", error, errorSize);
                return KENSHILUA_STATUS_INVALID_ARGUMENT;
            }
            restoreStack.setTarget(originalTop - argumentCount);

            std::string dispatchError;
            if (argumentCount == 0)
            {
                KenshiLua::EventSystem::get().callHandlers(eventName, NULL, &dispatchError);
            }
            else
            {
                StackArgumentPusher pusher(originalTop - argumentCount + 1, argumentCount);
                KenshiLua::EventSystem::get().callHandlers(eventName, &pusher, &dispatchError);
            }
            if (!dispatchError.empty())
            {
                copyBuffer(dispatchError, error, errorSize);
                return KENSHILUA_STATUS_LUA_RUNTIME_ERROR;
            }
            return KENSHILUA_STATUS_OK;
        }
        catch (const std::bad_alloc&)
        {
            return memoryFailure("DispatchEvent", error, errorSize);
        }
        catch (...)
        {
            return unexpectedFailure("DispatchEvent", error, errorSize);
        }
    }

    int KENSHILUA_CALL apiRegisterFunction(const char* name, lua_CFunction function,
        char* error, size_t errorSize)
    {
        clearBuffer(error, errorSize);
        try
        {
            lua_State* state = NULL;
            int validation = validateRuntime(&state, error, errorSize);
            if (validation != KENSHILUA_STATUS_OK)
                return validation;
            StackTopRestorer restoreStack(state);
            if (!name || !*name || !function)
            {
                copyBuffer("Global name and native function are required", error, errorSize);
                return KENSHILUA_STATUS_INVALID_ARGUMENT;
            }

            lua_pushcfunction(state, function);
            lua_setglobal(state, name);
            return KENSHILUA_STATUS_OK;
        }
        catch (const std::bad_alloc&)
        {
            return memoryFailure("RegisterFunction", error, errorSize);
        }
        catch (...)
        {
            return unexpectedFailure("RegisterFunction", error, errorSize);
        }
    }

    int KENSHILUA_CALL apiRegisterModule(const char* name, lua_CFunction openFunction,
        char* error, size_t errorSize)
    {
        clearBuffer(error, errorSize);
        try
        {
            lua_State* state = NULL;
            int validation = validateRuntime(&state, error, errorSize);
            if (validation != KENSHILUA_STATUS_OK)
                return validation;
            StackTopRestorer restoreStack(state);
            if (!name || !*name || !openFunction)
            {
                copyBuffer("Module name and open function are required", error, errorSize);
                return KENSHILUA_STATUS_INVALID_ARGUMENT;
            }

            lua_getglobal(state, "package");
            if (!lua_istable(state, -1))
            {
                copyBuffer("Lua package table is unavailable", error, errorSize);
                return KENSHILUA_STATUS_LUA_RUNTIME_ERROR;
            }
            lua_getfield(state, -1, "preload");
            if (!lua_istable(state, -1))
            {
                copyBuffer("Lua package.preload table is unavailable", error, errorSize);
                return KENSHILUA_STATUS_LUA_RUNTIME_ERROR;
            }

            lua_pushcfunction(state, openFunction);
            lua_setfield(state, -2, name);
            return KENSHILUA_STATUS_OK;
        }
        catch (const std::bad_alloc&)
        {
            return memoryFailure("RegisterModule", error, errorSize);
        }
        catch (...)
        {
            return unexpectedFailure("RegisterModule", error, errorSize);
        }
    }

    int KENSHILUA_CALL apiPushObject(lua_State* state, void* pointer,
        const char* metatableName)
    {
        try
        {
            lua_State* runtimeState = NULL;
            int validation = validateRuntime(&runtimeState, NULL, 0);
            if (validation != KENSHILUA_STATUS_OK)
                return validation;
            if (!state || state != runtimeState || !metatableName || !*metatableName)
                return KENSHILUA_STATUS_INVALID_ARGUMENT;
            if (!pointer)
            {
                lua_pushnil(state);
                return KENSHILUA_STATUS_OK;
            }

            void** userdata = static_cast<void**>(lua_newuserdata(state, sizeof(void*)));
            *userdata = pointer;
            luaL_getmetatable(state, metatableName);
            if (lua_isnil(state, -1))
            {
                lua_pop(state, 2);
                return KENSHILUA_STATUS_INVALID_ARGUMENT;
            }
            lua_setmetatable(state, -2);
            return KENSHILUA_STATUS_OK;
        }
        catch (const std::bad_alloc&)
        {
            return KENSHILUA_STATUS_LUA_MEMORY_ERROR;
        }
        catch (...)
        {
            return KENSHILUA_STATUS_UNKNOWN_ERROR;
        }
    }

    void* KENSHILUA_CALL apiCheckObject(lua_State* state, int index,
        const char* metatableName)
    {
        lua_State* runtimeState = NULL;
        if (validateRuntime(&runtimeState, NULL, 0) != KENSHILUA_STATUS_OK ||
            !state || state != runtimeState || !metatableName || !*metatableName)
            return NULL;
        return KenshiLua::checkObject<void>(state, index, metatableName);
    }

    void* KENSHILUA_CALL apiTestObject(lua_State* state, int index,
        const char* metatableName)
    {
        try
        {
            lua_State* runtimeState = NULL;
            if (validateRuntime(&runtimeState, NULL, 0) != KENSHILUA_STATUS_OK ||
                !state || state != runtimeState || !metatableName || !*metatableName)
                return NULL;
            return KenshiLua::testObject<void>(state, index, metatableName);
        }
        catch (...)
        {
            return NULL;
        }
    }

    int KENSHILUA_CALL apiResolveScriptPath(const char* scriptPath,
        char* output, size_t outputSize)
    {
        clearBuffer(output, outputSize);
        try
        {
            int validation = validateRuntime(NULL, NULL, 0);
            if (validation != KENSHILUA_STATUS_OK)
                return validation;
            if (!scriptPath || !*scriptPath || !output || outputSize == 0)
                return KENSHILUA_STATUS_INVALID_ARGUMENT;
            std::string resolved = KenshiLua::ScriptLoader::get().resolveScriptPath(scriptPath);
            if (resolved.empty())
                return KENSHILUA_STATUS_FILE_NOT_FOUND;
            copyBuffer(resolved, output, outputSize);
            return KENSHILUA_STATUS_OK;
        }
        catch (const std::bad_alloc&)
        {
            return KENSHILUA_STATUS_LUA_MEMORY_ERROR;
        }
        catch (...)
        {
            return KENSHILUA_STATUS_UNKNOWN_ERROR;
        }
    }

    void KENSHILUA_CALL apiLogInfo(const char* message)
    {
        try { if (message) KenshiLua::logToFile(message); } catch (...) {}
    }

    void KENSHILUA_CALL apiLogWarning(const char* message)
    {
        try { if (message) KenshiLua::logToFileWarn(message); } catch (...) {}
    }

    void KENSHILUA_CALL apiLogError(const char* message)
    {
        try { if (message) KenshiLua::logToFileError(message); } catch (...) {}
    }

    void KENSHILUA_CALL apiLogDebug(const char* message)
    {
        try { if (message) KenshiLua::logToFileDebug(message); } catch (...) {}
    }

    bool validLuaAccess(lua_State* state)
    {
        lua_State* runtimeState = NULL;
        return state && validateRuntime(&runtimeState, NULL, 0) == KENSHILUA_STATUS_OK &&
            state == runtimeState;
    }

    void KENSHILUA_CALL apiPushNil(lua_State* state) { if (validLuaAccess(state)) lua_pushnil(state); }
    void KENSHILUA_CALL apiPushNumber(lua_State* state, double value) { if (validLuaAccess(state)) lua_pushnumber(state, value); }
    void KENSHILUA_CALL apiPushInteger(lua_State* state, ptrdiff_t value) { if (validLuaAccess(state)) lua_pushinteger(state, value); }
    void KENSHILUA_CALL apiPushString(lua_State* state, const char* value) { if (validLuaAccess(state)) lua_pushstring(state, value); }
    void KENSHILUA_CALL apiPushLString(lua_State* state, const char* value, size_t length) { if (validLuaAccess(state)) lua_pushlstring(state, value, length); }
    void KENSHILUA_CALL apiPushBoolean(lua_State* state, int value) { if (validLuaAccess(state)) lua_pushboolean(state, value); }
    double KENSHILUA_CALL apiToNumber(lua_State* state, int index) { return validLuaAccess(state) ? lua_tonumber(state, index) : 0.0; }
    ptrdiff_t KENSHILUA_CALL apiToInteger(lua_State* state, int index) { return validLuaAccess(state) ? lua_tointeger(state, index) : 0; }
    int KENSHILUA_CALL apiToBoolean(lua_State* state, int index) { return validLuaAccess(state) ? lua_toboolean(state, index) : 0; }
    const char* KENSHILUA_CALL apiToLString(lua_State* state, int index, size_t* length) { return validLuaAccess(state) ? lua_tolstring(state, index, length) : NULL; }
    int KENSHILUA_CALL apiType(lua_State* state, int index) { return validLuaAccess(state) ? lua_type(state, index) : LUA_TNONE; }
    int KENSHILUA_CALL apiGetTop(lua_State* state) { return validLuaAccess(state) ? lua_gettop(state) : 0; }
    void KENSHILUA_CALL apiSetTop(lua_State* state, int index) { if (validLuaAccess(state)) lua_settop(state, index); }
    void KENSHILUA_CALL apiNewTable(lua_State* state) { if (validLuaAccess(state)) lua_newtable(state); }
    void KENSHILUA_CALL apiPushCFunction(lua_State* state, lua_CFunction function) { if (validLuaAccess(state) && function) lua_pushcfunction(state, function); }
    void KENSHILUA_CALL apiPushValue(lua_State* state, int index) { if (validLuaAccess(state)) lua_pushvalue(state, index); }
    void KENSHILUA_CALL apiGetField(lua_State* state, int index, const char* name) { if (validLuaAccess(state) && name) lua_getfield(state, index, name); }
    void KENSHILUA_CALL apiSetField(lua_State* state, int index, const char* name) { if (validLuaAccess(state) && name) lua_setfield(state, index, name); }
    void KENSHILUA_CALL apiGetGlobal(lua_State* state, const char* name) { if (validLuaAccess(state) && name) lua_getglobal(state, name); }
    void KENSHILUA_CALL apiSetGlobal(lua_State* state, const char* name) { if (validLuaAccess(state) && name) lua_setglobal(state, name); }

    void KENSHILUA_CALL apiRegisterFunctions(lua_State* state, const KenshiLua_Reg* functions)
    {
        if (!validLuaAccess(state) || !functions)
            return;
        for (const KenshiLua_Reg* entry = functions; entry->name && entry->function; ++entry)
        {
            lua_pushcfunction(state, entry->function);
            lua_setfield(state, -2, entry->name);
        }
    }
}

extern "C" __declspec(dllexport) int KENSHILUA_CALL KenshiLua_GetApi(
    unsigned int requestedVersion, KenshiLua_ApiV1* outApi, size_t outApiSize)
{
    if (!outApi || outApiSize < sizeof(KenshiLua_ApiV1))
        return KENSHILUA_STATUS_INVALID_ARGUMENT;
    std::memset(outApi, 0, sizeof(KenshiLua_ApiV1));
    if (requestedVersion != KENSHILUA_ABI_VERSION)
        return KENSHILUA_STATUS_UNSUPPORTED_VERSION;

    try
    {
        KenshiLua_ApiV1 api;
        std::memset(&api, 0, sizeof(api));
        api.abiVersion = KENSHILUA_ABI_VERSION;
        api.structSize = sizeof(api);

        api.isInitialized = apiIsInitialized;
        api.getState = apiGetState;
        api.getVersion = apiGetVersion;
        api.getVersionMajor = apiGetVersionMajor;
        api.getVersionMinor = apiGetVersionMinor;
        api.getVersionPatch = apiGetVersionPatch;
        api.runScript = apiRunScript;
        api.runString = apiRunString;
        api.dispatchEvent = apiDispatchEvent;
        api.registerFunction = apiRegisterFunction;
        api.registerModule = apiRegisterModule;
        api.pushObject = apiPushObject;
        api.checkObject = apiCheckObject;
        api.testObject = apiTestObject;
        api.resolveScriptPath = apiResolveScriptPath;
        api.logInfo = apiLogInfo;
        api.logWarning = apiLogWarning;
        api.logError = apiLogError;
        api.logDebug = apiLogDebug;
        api.pushNil = apiPushNil;
        api.pushNumber = apiPushNumber;
        api.pushInteger = apiPushInteger;
        api.pushString = apiPushString;
        api.pushLString = apiPushLString;
        api.pushBoolean = apiPushBoolean;
        api.toNumber = apiToNumber;
        api.toInteger = apiToInteger;
        api.toBoolean = apiToBoolean;
        api.toLString = apiToLString;
        api.type = apiType;
        api.getTop = apiGetTop;
        api.setTop = apiSetTop;
        api.newTable = apiNewTable;
        api.pushCFunction = apiPushCFunction;
        api.pushValue = apiPushValue;
        api.getField = apiGetField;
        api.setField = apiSetField;
        api.getGlobal = apiGetGlobal;
        api.setGlobal = apiSetGlobal;
        api.registerFunctions = apiRegisterFunctions;

        *outApi = api;
        return KENSHILUA_STATUS_OK;
    }
    catch (...)
    {
        return KENSHILUA_STATUS_UNKNOWN_ERROR;
    }
}
