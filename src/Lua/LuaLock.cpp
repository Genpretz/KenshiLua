#include "pch.h"
#include "Lua/LuaLock.h"

#include "Logger.h"
#include "Plugin.h"

#include <intrin.h>

namespace KenshiLua
{
    namespace
    {
        struct LockHolder
        {
            CRITICAL_SECTION cs;
            LockHolder() { InitializeCriticalSectionAndSpinCount(&cs, 4000); }
        };
        LockHolder g_lock;

        // Recursion depth; changed only by the thread that holds the lock.
        LONG g_depth = 0;
        // Incremented each time a thread takes the free lock, so a waiting
        // worker can tell one continuous hold from the next.
        volatile LONG g_holdSequence = 0;
        // The hold during which a worker last timed out.
        volatile LONG g_timedOutHold = -1;

        volatile LONG g_loggedTimeouts = 0;
        volatile LONG g_loggedUnlocked = 0;
        const LONG kMaxLoggedTimeouts = 20;
        const LONG kMaxLoggedUnlocked = 20;

        void markAcquired()
        {
            if (g_depth++ == 0)
                InterlockedIncrement(&g_holdSequence);
        }

        LONGLONG qpcNow()
        {
            LARGE_INTEGER value;
            QueryPerformanceCounter(&value);
            return value.QuadPart;
        }
    }

    namespace LuaLock
    {
        void acquire()
        {
            EnterCriticalSection(&g_lock.cs);
            markAcquired();
        }

        bool tryAcquireFor(unsigned long timeoutMs, const char* eventName)
        {
            if (TryEnterCriticalSection(&g_lock.cs))
            {
                markAcquired();
                return true;
            }

            // A hold that already outlasted one worker's timeout is most likely
            // waiting on a worker thread; do not stall every worker call again.
            LONG hold = g_holdSequence;
            if (hold == g_timedOutHold)
                return false;

            LARGE_INTEGER frequency;
            QueryPerformanceFrequency(&frequency);
            LONGLONG start = qpcNow();
            LONGLONG spinUntil = start + frequency.QuadPart / 20000;   // 50 us
            LONGLONG yieldUntil = start + frequency.QuadPart / 1000;   // 1 ms
            LONGLONG deadline = start + (frequency.QuadPart / 1000) * (LONGLONG)timeoutMs;
            for (;;)
            {
                if (TryEnterCriticalSection(&g_lock.cs))
                {
                    markAcquired();
                    return true;
                }
                LONGLONG now = qpcNow();
                if (now >= deadline)
                    break;
                if (now < spinUntil)
                    YieldProcessor();
                else if (now < yieldUntil)
                    SwitchToThread();
                else
                    Sleep(1);
            }

            InterlockedExchange(&g_timedOutHold, g_holdSequence);
            if (InterlockedIncrement(&g_loggedTimeouts) <= kMaxLoggedTimeouts)
            {
                logToFileWarnf("Worker thread %lu waited %lu ms for the Lua lock to run '%s' handlers and skipped them. "
                    "The Lua owner thread held the lock for the whole wait, possibly while waiting for this worker.",
                    GetCurrentThreadId(), timeoutMs, eventName ? eventName : "?");
            }
            return false;
        }

        void release()
        {
            --g_depth;
            LeaveCriticalSection(&g_lock.cs);
        }

        bool heldByCurrentThread()
        {
            return (DWORD)(DWORD_PTR)g_lock.cs.OwningThread == GetCurrentThreadId();
        }

        void checkHeld(const char* where)
        {
            if (heldByCurrentThread())
                return;
            if (InterlockedIncrement(&g_loggedUnlocked) <= kMaxLoggedUnlocked)
            {
                logToFileErrorf("Lua was entered without the Lua lock at %s (thread %lu, Lua owner thread: %s, caller %p)",
                    where, GetCurrentThreadId(), Plugin::get().isLuaThread() ? "yes" : "no", _ReturnAddress());
            }
        }
    }
}
