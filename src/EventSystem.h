#pragma once

#include <vector>
#include <string>

extern "C" {
#include <lua.h>
}

namespace KenshiLua
{

    // ---------------------------------------------------------------------------
    // IArgPusher
    //
    // Abstract base for pushing event arguments onto the Lua stack before a
    // handler call.  Subclass this (stack-allocate at the call site) for each
    // distinct event signature.  Replaces std::function / lambdas so the code
    // remains compatible with MSVC 2010.
    //
    // Implementors must push their arguments and return the count pushed.
    // ---------------------------------------------------------------------------
    struct IArgPusher
    {
        virtual int push(lua_State* L) const = 0;
        virtual ~IArgPusher() {}
    };

    // ---------------------------------------------------------------------------
    // EventSystem
    //
    // Singleton that owns the Lua state reference and all registered event
    // handlers.  Scripts register named handlers via the KenshiLua_registerHandler
    // and KenshiLua_unregisterHandler globals.  C++ code fires events by calling
    // callHandlers with an optional IArgPusher for event arguments.
    //
    // Handler storage uses a flat vector of (eventName, handlers) pairs rather
    // than std::map to stay compatible with MSVC 2010 and avoid iterator-
    // invalidation surprises during iteration.
    // ---------------------------------------------------------------------------
    class EventSystem
    {
    public:
        static EventSystem& get();

        // Must be called once after the Lua state is created.
        // Registers registerHandler and unregisterHandler
        // as Lua globals.
        bool initialize(lua_State* L);

        // Pin a Lua function ref under eventName and return a handler ID.
        int registerHandler(const char* eventName, int luaRef);

        // Remove a previously registered handler by its ID (no-op if not found).
        void unregisterHandler(int handlerId);

        // Fire all handlers registered under eventName.
        // If pusher is non-NULL, pusher->push(L) is called before each pcall
        // to put event arguments on the stack.
        // Returns 0 normally, or -1 if any handler returned false (consumed).
        int callHandlers(const char* eventName, IArgPusher* pusher = NULL);
        std::string callHandlersString(const char* eventName, IArgPusher* pusher = NULL);
        void* callHandlersObject(const char* eventName, const char* metatableName, IArgPusher* pusher = NULL);
        bool callHandlersBool(const char* eventName, IArgPusher* pusher = NULL, bool defaultVal = false);
        double callHandlersNumber(const char* eventName, IArgPusher* pusher = NULL, double defaultVal = 0.0);

        // Unref all registered Lua functions and clear all handler lists.
        // Must be called before destroying the Lua state.
        void clear();

        struct RegisteredCallbackInfo
        {
            std::string eventName;
            int handlerId;
        };

        std::vector<RegisteredCallbackInfo> getRegisteredCallbacks() const;

    private:
        EventSystem();
        ~EventSystem();

        bool executeHandler(const char* eventName, int nargs);

        // Non-copyable
        EventSystem(const EventSystem&);
        EventSystem& operator=(const EventSystem&);

        struct HandlerInfo
        {
            int id;
            int luaRef;
        };

        lua_State* m_L;
        std::vector< std::pair< std::string, std::vector<HandlerInfo> > > m_handlers;
        int m_nextHandlerId;
    };

    // ---------------------------------------------------------------------------
    // Lua-callable C functions registered as globals by EventSystem::initialize
    // ---------------------------------------------------------------------------
    int luaRegisterHandler(lua_State* L);
    int luaUnregisterHandler(lua_State* L);

} // namespace KenshiLua