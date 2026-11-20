#include "pch.h"

#include "EventSystem.h"
#include "Logger.h"
#include "Plugin.h"
#include "Hooks/Hooks_Common.h"
#include "Compatibility/LegacyCompat.h"

#include <lua.hpp>
#include "Lua/BindingHelpers.h"
#include "Lua/LuaLock.h"
#include "Lua/LuaState.h"

#include <cstring>


namespace KenshiLua
{

    namespace
    {
        class HandlerReferenceSnapshot
        {
        public:
            explicit HandlerReferenceSnapshot(lua_State* state) : m_state(state) {}

            ~HandlerReferenceSnapshot()
            {
                for (size_t i = 0; i < m_references.size(); ++i)
                    luaL_unref(m_state, LUA_REGISTRYINDEX, m_references[i]);
            }

            void add(int reference)
            {
                // Reserve the vector slot before creating a Lua registry
                // reference so a native allocation failure cannot leak it.
                m_references.push_back(LUA_NOREF);
                lua_rawgeti(m_state, LUA_REGISTRYINDEX, reference);
                if (!lua_isfunction(m_state, -1))
                {
                    lua_pop(m_state, 1);
                    m_references.pop_back();
                    return;
                }
                m_references.back() = luaL_ref(m_state, LUA_REGISTRYINDEX);
            }

            size_t size() const { return m_references.size(); }
            bool empty() const { return m_references.empty(); }

            void push(size_t index) const
            {
                lua_rawgeti(m_state, LUA_REGISTRYINDEX, m_references[index]);
            }

        private:
            HandlerReferenceSnapshot(const HandlerReferenceSnapshot&);
            HandlerReferenceSnapshot& operator=(const HandlerReferenceSnapshot&);

            lua_State* m_state;
            std::vector<int> m_references;
        };

        template <class HandlerBuckets>
        void snapshotHandlers(const HandlerBuckets& buckets, const char* eventName,
            bool workerThreadOnly, HandlerReferenceSnapshot& snapshot)
        {
            for (size_t i = 0; i < buckets.size(); ++i)
            {
                if (buckets[i].first == eventName)
                {
                    for (size_t j = 0; j < buckets[i].second.size(); ++j)
                    {
                        if (!workerThreadOnly || buckets[i].second[j].workerThread)
                            snapshot.add(buckets[i].second[j].luaRef);
                    }
                    break;
                }
            }
        }

        void countHandler(const char* eventName, bool workerThread, long delta)
        {
            EventDispatchState* state = FindEventDispatchState(eventName);
            if (!state)
                return;
            InterlockedExchangeAdd(&state->handlerCount, delta);
            if (workerThread)
                InterlockedExchangeAdd(&state->workerHandlerCount, delta);
        }

        // How long a worker thread waits for the Lua owner thread to leave Lua
        // before it skips the event's handlers.
        const unsigned long kWorkerLockTimeoutMs = 2000;

        void logWorkerSkipOnce(EventDispatchState* state, const char* eventName)
        {
            if (InterlockedCompareExchange(&state->workerSkipLogged, 1, 0) != 0)
                return;
            if (state->workerDispatch)
                logToFileWarnf("'%s' was raised on a game worker thread, where only handlers registered with "
                    "{ workerThread = true } run; none is registered. Reported once per event.", eventName);
            else
                logToFileWarnf("'%s' was raised on a game worker thread, where this event does not run Lua handlers. "
                    "Reported once per event.", eventName);
        }

        // Holds the Lua lock for one dispatch. On the Lua owner thread it always
        // takes the lock. On a game worker thread it takes it only for an event
        // the registry marks WorkerDispatch that has a handler registered with
        // { workerThread = true }, and only if the lock frees up in time.
        class DispatchScope
        {
        public:
            DispatchScope(lua_State* L, const char* eventName)
                : m_locked(false), m_workerThread(false)
            {
                Plugin& plugin = Plugin::get();
                if (!L || !plugin.isInitialized())
                    return;
                if (plugin.isLuaThread())
                {
                    LuaLock::acquire();
                    m_locked = true;
                    return;
                }

                m_workerThread = true;
                EventDispatchState* state = FindEventDispatchState(eventName);
                if (!state)
                    return;
                if (!state->workerDispatch || state->workerHandlerCount == 0)
                {
                    if (state->handlerCount > 0)
                        logWorkerSkipOnce(state, eventName);
                    return;
                }
                if (!LuaLock::tryAcquireFor(kWorkerLockTimeoutMs, eventName))
                    return;
                if (!plugin.isInitialized())
                {
                    LuaLock::release();
                    return;
                }
                m_locked = true;
            }

            ~DispatchScope()
            {
                if (m_locked)
                    LuaLock::release();
            }

            bool locked() const { return m_locked; }
            bool workerThread() const { return m_workerThread; }

        private:
            DispatchScope(const DispatchScope&);
            DispatchScope& operator=(const DispatchScope&);

            bool m_locked;
            bool m_workerThread;
        };
    }

    static EventSystem* g_eventSystem = NULL;

    EventSystem::EventSystem()
        : m_L(NULL)
        , m_nextHandlerId(1)
    {
    }

    EventSystem::~EventSystem()
    {
        // clear() requires m_L; only call if we were ever initialized.
        if (m_L)
            clear();
    }

    EventSystem::EventSystem(const EventSystem&)
        : m_L(NULL)
        , m_nextHandlerId(1)
    {
    }

    EventSystem& EventSystem::operator=(const EventSystem&)
    {
        return *this;
    }

    EventSystem& EventSystem::get()
    {
        if (!g_eventSystem)
        {
            static EventSystem instance;
            g_eventSystem = &instance;
        }
        return *g_eventSystem;
    }

    const char* EventSystem::resolveCanonicalEventName(const char* eventName, const char* source)
    {
        if (!eventName || !eventName[0])
            return "";

        // Fast path: if this is already a known canonical event name, return directly without LegacyCompat
        if (IsKnownEvent(eventName))
            return eventName;

        // Fallback: check LegacyCompat for deprecated aliases
        return LegacyCompat::ResolveEventName(eventName, source);
    }

    bool EventSystem::initialize(lua_State* L)
    {
        m_L = L;

        // Legacy global functions
        lua_pushcfunction(L, luaRegisterHandler);
        lua_setglobal(L, "registerHandler");

        lua_pushcfunction(L, luaUnregisterHandler);
        lua_setglobal(L, "unregisterHandler");

        // Unified Events table
        lua_newtable(L);
        lua_pushcfunction(L, luaEventsOn);
        lua_setfield(L, -2, "on");
        lua_pushcfunction(L, luaEventsOff);
        lua_setfield(L, -2, "off");
        lua_setglobal(L, "Events");

        return true;
    }

    int EventSystem::registerHandler(const char* rawEventName, int luaRef, const char* source, bool workerThread)
    {
        const char* eventName = resolveCanonicalEventName(rawEventName, source);

        if (workerThread)
        {
            EventDispatchState* state = FindEventDispatchState(eventName);
            if (!state || !state->workerDispatch)
            {
                logToFileWarnf("Events.on in %s: '%s' does not run handlers on game worker threads; "
                    "the handler is registered without { workerThread = true }.",
                    source && source[0] ? source : "?", eventName);
                workerThread = false;
            }
        }

        HandlerInfo info;
        info.id = m_nextHandlerId++;
        info.luaRef = luaRef;
        info.source = source ? source : "";
        info.workerThread = workerThread;
        countHandler(eventName, workerThread, 1);

        for (size_t i = 0; i < m_handlers.size(); ++i)
        {
            if (m_handlers[i].first == eventName)
            {
                m_handlers[i].second.push_back(info);
                return info.id;
            }
        }

        // No bucket yet - create one.
        std::vector<HandlerInfo> newList;
        newList.push_back(info);
        m_handlers.push_back(std::make_pair(std::string(eventName), newList));

        InstallHookForEvent(eventName);

        return info.id;
    }

    void EventSystem::unregisterHandler(int handlerId)
    {
        for (size_t i = 0; i < m_handlers.size(); ++i)
        {
            std::vector<HandlerInfo>& handlers = m_handlers[i].second;
            for (size_t j = 0; j < handlers.size(); ++j)
            {
                if (handlers[j].id == handlerId)
                {
                    countHandler(m_handlers[i].first.c_str(), handlers[j].workerThread, -1);
                    if (handlers[j].luaRef != LUA_REFNIL && m_L)
                        luaL_unref(m_L, LUA_REGISTRYINDEX, handlers[j].luaRef);
                    handlers.erase(handlers.begin() + j);
                    return;
                }
            }
        }
    }

    void EventSystem::unregisterHandlersBySource(const std::string& source)
    {
        if (source.empty())
            return;

        for (size_t i = 0; i < m_handlers.size(); ++i)
        {
            std::vector<HandlerInfo>& handlers = m_handlers[i].second;
            for (auto it = handlers.begin(); it != handlers.end(); )
            {
                if (sourceMatches(it->source, source))
                {
                    countHandler(m_handlers[i].first.c_str(), it->workerThread, -1);
                    if (it->luaRef != LUA_REFNIL && m_L)
                        luaL_unref(m_L, LUA_REGISTRYINDEX, it->luaRef);
                    it = handlers.erase(it);
                }
                else
                {
                    ++it;
                }
            }
        }
    }

    // ---------------------------------------------------------------------------
    // callHandlers
    // ---------------------------------------------------------------------------

    int EventSystem::callHandlers(const char* eventName, IArgPusher* pusher,
        std::string* outError)
    {
        DispatchScope dispatch(m_L, eventName);
        if (!dispatch.locked() || !m_L)
            return 0;

        // Snapshot the handler list so that handlers which call
        // unregisterHandler during their own execution don't corrupt iteration.
        HandlerReferenceSnapshot snapshot(m_L);
        snapshotHandlers(m_handlers, eventName, dispatch.workerThread(), snapshot);

        if (snapshot.empty())
            return 0;

        int result = 0;
        for (size_t i = 0; i < snapshot.size(); ++i)
        {
            snapshot.push(i);

            int nargs = 0;
            if (pusher)
                nargs = pusher->push(m_L);

            if (executeHandler(eventName, nargs, outError))
            {
                // A handler returning false consumes the event and stops
                // subsequent handlers from running.
                if (lua_isboolean(m_L, -1) && !lua_toboolean(m_L, -1))
                    result = -1;
                lua_pop(m_L, 1);
            }

            if (result == -1)
                break;
        }

        return result;
    }

    std::string EventSystem::callHandlersString(const char* eventName, IArgPusher* pusher)
    {
        DispatchScope dispatch(m_L, eventName);
        if (!dispatch.locked() || !m_L)
            return "";

        HandlerReferenceSnapshot snapshot(m_L);
        snapshotHandlers(m_handlers, eventName, dispatch.workerThread(), snapshot);

        if (snapshot.empty())
            return "";

        std::string result = "";
        for (size_t i = 0; i < snapshot.size(); ++i)
        {
            snapshot.push(i);

            int nargs = 0;
            if (pusher)
                nargs = pusher->push(m_L);

            if (executeHandler(eventName, nargs))
            {
                if (lua_isstring(m_L, -1))
                {
                    result = lua_tostring(m_L, -1);
                }
                lua_pop(m_L, 1);
            }

            if (!result.empty())
                break;
        }

        return result;
    }

    void* EventSystem::callHandlersObject(const char* eventName, const char* metatableName, IArgPusher* pusher)
    {
        DispatchScope dispatch(m_L, eventName);
        if (!dispatch.locked() || !m_L)
            return NULL;

        HandlerReferenceSnapshot snapshot(m_L);
        snapshotHandlers(m_handlers, eventName, dispatch.workerThread(), snapshot);

        if (snapshot.empty())
            return NULL;

        void* result = NULL;
        for (size_t i = 0; i < snapshot.size(); ++i)
        {
            snapshot.push(i);

            int nargs = 0;
            if (pusher)
                nargs = pusher->push(m_L);

            if (executeHandler(eventName, nargs))
            {
                // Use testObject to safely check if it matches the expected type
                result = testObject<void>(m_L, -1, metatableName);
                lua_pop(m_L, 1);
            }

            if (result)
                break;
        }

        return result;
    }

    bool EventSystem::callHandlersBool(const char* eventName, IArgPusher* pusher, bool defaultVal)
    {
        DispatchScope dispatch(m_L, eventName);
        if (!dispatch.locked() || !m_L)
            return defaultVal;

        HandlerReferenceSnapshot snapshot(m_L);
        snapshotHandlers(m_handlers, eventName, dispatch.workerThread(), snapshot);

        if (snapshot.empty())
            return defaultVal;

        bool hasResult = false;
        bool result = defaultVal;
        for (size_t i = 0; i < snapshot.size(); ++i)
        {
            snapshot.push(i);

            int nargs = 0;
            if (pusher)
                nargs = pusher->push(m_L);

            if (executeHandler(eventName, nargs))
            {
                if (lua_isboolean(m_L, -1))
                {
                    result = lua_toboolean(m_L, -1) != 0;
                    hasResult = true;
                }
                lua_pop(m_L, 1);
            }

            if (hasResult)
                break;
        }

        return result;
    }

    double EventSystem::callHandlersNumber(const char* eventName, IArgPusher* pusher, double defaultVal)
    {
        DispatchScope dispatch(m_L, eventName);
        if (!dispatch.locked() || !m_L)
            return defaultVal;

        HandlerReferenceSnapshot snapshot(m_L);
        snapshotHandlers(m_handlers, eventName, dispatch.workerThread(), snapshot);

        if (snapshot.empty())
            return defaultVal;

        bool hasResult = false;
        double result = defaultVal;
        for (size_t i = 0; i < snapshot.size(); ++i)
        {
            snapshot.push(i);

            int nargs = 0;
            if (pusher)
                nargs = pusher->push(m_L);

            if (executeHandler(eventName, nargs))
            {
                if (lua_isnumber(m_L, -1))
                {
                    result = (double)lua_tonumber(m_L, -1);
                    hasResult = true;
                }
                lua_pop(m_L, 1);
            }

            if (hasResult)
                break;
        }

        return result;
    }

    bool EventSystem::executeHandler(const char* eventName, int nargs, std::string* outError)
    {
        std::string pcallErr;
        if (LuaState::pcallWithTraceback(m_L, nargs, 1, &pcallErr))
        {
            return true;
        }
        else
        {
            if (outError && outError->empty())
                *outError = pcallErr;
            logToFileErrorf("Lua error in '%s' handler: %s",
                eventName,
                pcallErr.c_str());
            return false;
        }
    }

    void EventSystem::clear()
    {
        for (size_t i = 0; i < m_handlers.size(); ++i)
        {
            std::vector<HandlerInfo>& handlers = m_handlers[i].second;
            for (size_t j = 0; j < handlers.size(); ++j)
            {
                countHandler(m_handlers[i].first.c_str(), handlers[j].workerThread, -1);
                if (handlers[j].luaRef != LUA_REFNIL)
                    luaL_unref(m_L, LUA_REGISTRYINDEX, handlers[j].luaRef);
            }
            handlers.clear();
        }
        m_handlers.clear();
        m_L = NULL;
    }

    std::vector<EventSystem::RegisteredCallbackInfo> EventSystem::getRegisteredCallbacks() const
    {
        std::vector<RegisteredCallbackInfo> result;
        for (size_t i = 0; i < m_handlers.size(); ++i)
        {
            const std::string& name = m_handlers[i].first;
            const std::vector<HandlerInfo>& list = m_handlers[i].second;
            for (size_t j = 0; j < list.size(); ++j)
            {
                RegisteredCallbackInfo info;
                info.eventName = name;
                info.handlerId = list[j].id;
                result.push_back(info);
            }
        }
        return result;
    }

    // Shared by Events.on and the deprecated registration names. Only Events.on
    // reads the options table; the deprecated names keep ignoring extra arguments.
    static int registerFromLua(lua_State* L, bool acceptOptions)
    {
        const char* eventName = luaL_checkstring(L, 1);

        if (!lua_isfunction(L, 2))
            return luaL_error(L, "registerHandler: second argument must be a function");

        bool workerThread = false;
        if (acceptOptions && !lua_isnoneornil(L, 3))
        {
            luaL_checktype(L, 3, LUA_TTABLE);
            lua_pushnil(L);
            while (lua_next(L, 3) != 0)
            {
                if (lua_type(L, -2) != LUA_TSTRING)
                    return luaL_error(L, "Events.on: option names must be strings, got %s", luaL_typename(L, -2));
                const char* option = lua_tostring(L, -2);
                if (std::strcmp(option, "workerThread") != 0)
                    return luaL_error(L, "Events.on: unknown option '%s'", option);
                if (!lua_isboolean(L, -1))
                    return luaL_error(L, "Events.on: option 'workerThread' must be a boolean, got %s", luaL_typename(L, -1));
                workerThread = lua_toboolean(L, -1) != 0;
                lua_pop(L, 1);
            }
        }

        // Determine the source of the caller
        std::string source = "";
        lua_Debug ar;
        if (lua_getstack(L, 1, &ar))
        {
            if (lua_getinfo(L, "S", &ar))
            {
                if (ar.source)
                {
                    source = ar.source;
                }
            }
        }

        lua_pushvalue(L, 2);
        int ref = luaL_ref(L, LUA_REGISTRYINDEX);

        int handlerId = EventSystem::get().registerHandler(eventName, ref, source.c_str(), workerThread);
        lua_pushinteger(L, handlerId);
        return 1;
    }

    int luaRegisterHandler(lua_State* L)
    {
        return registerFromLua(L, false);
    }

    int luaUnregisterHandler(lua_State* L)
    {
        int handlerId = (int)luaL_checkinteger(L, 1);
        EventSystem::get().unregisterHandler(handlerId);
        return 0;
    }

    int luaEventsOn(lua_State* L)
    {
        return registerFromLua(L, true);
    }

    int luaEventsOff(lua_State* L)
    {
        return luaUnregisterHandler(L);
    }
}
