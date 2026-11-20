#pragma once

// One recursive lock guards every use of the shared lua_State. The Lua owner
// thread takes it whenever it enters Lua from native code. A game worker thread
// takes it only to run event handlers registered with { workerThread = true },
// and gives up after a timeout instead of waiting indefinitely, because the
// owner thread may be waiting for that worker inside the engine.

namespace KenshiLua
{
    namespace LuaLock
    {
        void acquire();
        // Worker-thread acquisition. Returns false after timeoutMs, or at once
        // when the current hold already made a worker time out. eventName is
        // used only in the log message.
        bool tryAcquireFor(unsigned long timeoutMs, const char* eventName);
        void release();
        bool heldByCurrentThread();
        // Logs (rate-limited) an entry into Lua made without the lock held.
        void checkHeld(const char* where);
    }

    struct ScopedLuaLock
    {
        ScopedLuaLock() { LuaLock::acquire(); }
        ~ScopedLuaLock() { LuaLock::release(); }
    private:
        ScopedLuaLock(const ScopedLuaLock&);
        ScopedLuaLock& operator=(const ScopedLuaLock&);
    };
}
