#include "pch.h"

#include "EventSystem.h"
#include "Logger.h"
#include "Hooks.h"

#include <lua.hpp>
#include "Lua/BindingHelpers.h"
#include "Lua/LuaState.h"


namespace KenshiLua
{

    // ---------------------------------------------------------------------------
    // Singleton storage
    // ---------------------------------------------------------------------------

    static EventSystem* g_eventSystem = NULL;

    // ---------------------------------------------------------------------------
    // Lifecycle
    // ---------------------------------------------------------------------------

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

    // Non-copyable stubs - bodies required even for private declarations in
    // MSVC 2010 when the linker sees a copy attempt anywhere.
    EventSystem::EventSystem(const EventSystem&)
        : m_L(NULL)
        , m_nextHandlerId(1)
    {
    }

    EventSystem& EventSystem::operator=(const EventSystem&)
    {
        return *this;
    }

    // ---------------------------------------------------------------------------
    // Singleton accessor
    // ---------------------------------------------------------------------------

    EventSystem& EventSystem::get()
    {
        if (!g_eventSystem)
        {
            static EventSystem instance;
            g_eventSystem = &instance;
        }
        return *g_eventSystem;
    }

    // ---------------------------------------------------------------------------
    // initialize
    // ---------------------------------------------------------------------------

    bool EventSystem::initialize(lua_State* L)
    {
        m_L = L;

        lua_pushcfunction(L, luaRegisterHandler);
        lua_setglobal(L, "registerHandler");

        lua_pushcfunction(L, luaUnregisterHandler);
        lua_setglobal(L, "unregisterHandler");

        return true;
    }

    // ---------------------------------------------------------------------------
    // registerHandler
    // ---------------------------------------------------------------------------

    int EventSystem::registerHandler(const char* eventName, int luaRef)
    {
        HandlerInfo info;
        info.id = m_nextHandlerId++;
        info.luaRef = luaRef;

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

    // ---------------------------------------------------------------------------
    // unregisterHandler
    // ---------------------------------------------------------------------------

    void EventSystem::unregisterHandler(int handlerId)
    {
        for (size_t i = 0; i < m_handlers.size(); ++i)
        {
            std::vector<HandlerInfo>& handlers = m_handlers[i].second;
            for (size_t j = 0; j < handlers.size(); ++j)
            {
                if (handlers[j].id == handlerId)
                {
                    handlers.erase(handlers.begin() + j);
                    return;
                }
            }
        }
    }

    // ---------------------------------------------------------------------------
    // callHandlers
    // ---------------------------------------------------------------------------

    int EventSystem::callHandlers(const char* eventName, IArgPusher* pusher)
    {
        // Snapshot the handler list so that handlers which call
        // unregisterHandler during their own execution don't corrupt iteration.
        std::vector<HandlerInfo> snapshot;
        for (size_t i = 0; i < m_handlers.size(); ++i)
        {
            if (m_handlers[i].first == eventName)
            {
                snapshot = m_handlers[i].second;
                break;
            }
        }

        if (snapshot.empty())
            return 0;

        int result = 0;
        for (size_t i = 0; i < snapshot.size(); ++i)
        {
            lua_rawgeti(m_L, LUA_REGISTRYINDEX, snapshot[i].luaRef);
            if (!lua_isfunction(m_L, -1))
            {
                lua_pop(m_L, 1);
                continue;
            }

            int nargs = 0;
            if (pusher)
                nargs = pusher->push(m_L);

            std::string pcallErr;
            if (LuaState::pcallWithTraceback(m_L, nargs, 1, &pcallErr))
            {
                // A handler returning false consumes the event and stops
                // subsequent handlers from running.
                if (lua_isboolean(m_L, -1) && !lua_toboolean(m_L, -1))
                    result = -1;
                lua_pop(m_L, 1);
            }
            else
            {
                logToFilef("Lua error in '%s' handler: %s",
                    eventName,
                    pcallErr.c_str());
            }

            if (result == -1)
                break;
        }

        return result;
    }

    std::string EventSystem::callHandlersString(const char* eventName, IArgPusher* pusher)
    {
        std::vector<HandlerInfo> snapshot;
        for (size_t i = 0; i < m_handlers.size(); ++i)
        {
            if (m_handlers[i].first == eventName)
            {
                snapshot = m_handlers[i].second;
                break;
            }
        }

        if (snapshot.empty())
            return "";

        std::string result = "";
        for (size_t i = 0; i < snapshot.size(); ++i)
        {
            lua_rawgeti(m_L, LUA_REGISTRYINDEX, snapshot[i].luaRef);
            if (!lua_isfunction(m_L, -1))
            {
                lua_pop(m_L, 1);
                continue;
            }

            int nargs = 0;
            if (pusher)
                nargs = pusher->push(m_L);

            std::string pcallErr;
            if (LuaState::pcallWithTraceback(m_L, nargs, 1, &pcallErr))
            {
                if (lua_isstring(m_L, -1))
                {
                    result = lua_tostring(m_L, -1);
                }
                lua_pop(m_L, 1);
            }
            else
            {
                logToFilef("Lua error in '%s' handler: %s",
                    eventName,
                    pcallErr.c_str());
            }

            if (!result.empty())
                break;
        }

        return result;
    }

    void* EventSystem::callHandlersObject(const char* eventName, const char* metatableName, IArgPusher* pusher)
    {
        std::vector<HandlerInfo> snapshot;
        for (size_t i = 0; i < m_handlers.size(); ++i)
        {
            if (m_handlers[i].first == eventName)
            {
                snapshot = m_handlers[i].second;
                break;
            }
        }

        if (snapshot.empty())
            return NULL;

        void* result = NULL;
        for (size_t i = 0; i < snapshot.size(); ++i)
        {
            lua_rawgeti(m_L, LUA_REGISTRYINDEX, snapshot[i].luaRef);
            if (!lua_isfunction(m_L, -1))
            {
                lua_pop(m_L, 1);
                continue;
            }

            int nargs = 0;
            if (pusher)
                nargs = pusher->push(m_L);

            std::string pcallErr;
            if (LuaState::pcallWithTraceback(m_L, nargs, 1, &pcallErr))
            {
                // Use testObject to safely check if it matches the expected type
                result = testObject<void>(m_L, -1, metatableName);
                lua_pop(m_L, 1);
            }
            else
            {
                logToFilef("Lua error in '%s' handler: %s",
                    eventName,
                    pcallErr.c_str());
            }

            if (result)
                break;
        }

        return result;
    }

    bool EventSystem::callHandlersBool(const char* eventName, IArgPusher* pusher, bool defaultVal)
    {
        std::vector<HandlerInfo> snapshot;
        for (size_t i = 0; i < m_handlers.size(); ++i)
        {
            if (m_handlers[i].first == eventName)
            {
                snapshot = m_handlers[i].second;
                break;
            }
        }

        if (snapshot.empty())
            return defaultVal;

        bool hasResult = false;
        bool result = defaultVal;
        for (size_t i = 0; i < snapshot.size(); ++i)
        {
            lua_rawgeti(m_L, LUA_REGISTRYINDEX, snapshot[i].luaRef);
            if (!lua_isfunction(m_L, -1))
            {
                lua_pop(m_L, 1);
                continue;
            }

            int nargs = 0;
            if (pusher)
                nargs = pusher->push(m_L);

            std::string pcallErr;
            if (LuaState::pcallWithTraceback(m_L, nargs, 1, &pcallErr))
            {
                if (lua_isboolean(m_L, -1))
                {
                    result = lua_toboolean(m_L, -1) != 0;
                    hasResult = true;
                }
                lua_pop(m_L, 1);
            }
            else
            {
                logToFilef("Lua error in '%s' handler: %s",
                    eventName,
                    pcallErr.c_str());
            }

            if (hasResult)
                break;
        }

        return result;
    }

    double EventSystem::callHandlersNumber(const char* eventName, IArgPusher* pusher, double defaultVal)
    {
        std::vector<HandlerInfo> snapshot;
        for (size_t i = 0; i < m_handlers.size(); ++i)
        {
            if (m_handlers[i].first == eventName)
            {
                snapshot = m_handlers[i].second;
                break;
            }
        }

        if (snapshot.empty())
            return defaultVal;

        bool hasResult = false;
        double result = defaultVal;
        for (size_t i = 0; i < snapshot.size(); ++i)
        {
            lua_rawgeti(m_L, LUA_REGISTRYINDEX, snapshot[i].luaRef);
            if (!lua_isfunction(m_L, -1))
            {
                lua_pop(m_L, 1);
                continue;
            }

            int nargs = 0;
            if (pusher)
                nargs = pusher->push(m_L);

            std::string pcallErr;
            if (LuaState::pcallWithTraceback(m_L, nargs, 1, &pcallErr))
            {
                if (lua_isnumber(m_L, -1))
                {
                    result = (double)lua_tonumber(m_L, -1);
                    hasResult = true;
                }
                lua_pop(m_L, 1);
            }
            else
            {
                logToFilef("Lua error in '%s' handler: %s",
                    eventName,
                    pcallErr.c_str());
            }

            if (hasResult)
                break;
        }

        return result;
    }


    // ---------------------------------------------------------------------------
    // clear
    // ---------------------------------------------------------------------------

    void EventSystem::clear()
    {
        for (size_t i = 0; i < m_handlers.size(); ++i)
        {
            std::vector<HandlerInfo>& handlers = m_handlers[i].second;
            for (size_t j = 0; j < handlers.size(); ++j)
            {
                if (handlers[j].luaRef != LUA_REFNIL)
                    luaL_unref(m_L, LUA_REGISTRYINDEX, handlers[j].luaRef);
            }
            handlers.clear();
        }
        m_handlers.clear();
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

    // ---------------------------------------------------------------------------
    // Lua globals
    // ---------------------------------------------------------------------------

    int luaRegisterHandler(lua_State* L)
    {
        const char* eventName = luaL_checkstring(L, 1);

        if (!lua_isfunction(L, 2))
            return luaL_error(L, "registerHandler: second argument must be a function");

        lua_pushvalue(L, 2);
        int ref = luaL_ref(L, LUA_REGISTRYINDEX);

        int handlerId = EventSystem::get().registerHandler(eventName, ref);
        lua_pushinteger(L, handlerId);
        return 1;
    }

    int luaUnregisterHandler(lua_State* L)
    {
        int handlerId = (int)luaL_checkinteger(L, 1);
        EventSystem::get().unregisterHandler(handlerId);
        return 0;
    }
}