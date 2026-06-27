#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <cstdio>

#include <boost/thread/mutex.hpp>
#include <boost/array.hpp>
#include "Config.h"

namespace KenshiLua
{

    // ---------------------------------------------------------------------------
    // Logger
    //
    // Thread-safe, timestamped file logger with an in-memory ring buffer for
    // display in the GUI console.
    // ---------------------------------------------------------------------------
    class Logger
    {
    public:
        static Logger& get();

        void init(const std::string& filepath);
        void log(const std::string& message);
        void snapshot(std::vector<std::string>& out, size_t maxLines = 0) const;
        void shutdown();

    private:
        Logger()
            : m_initialized(false)
            , m_ringStart(0)
            , m_ringSize(0)
        {
        }

        // Non-copyable
        Logger(const Logger&);
        Logger& operator=(const Logger&);

        bool                        m_initialized;
        std::ofstream               m_file;
        mutable boost::mutex        m_ringMutex;
        boost::array<std::string, 512> m_ring;
        size_t                      m_ringStart;
        size_t                      m_ringSize;
    };

    // ---------------------------------------------------------------------------
    // Free helpers
    // ---------------------------------------------------------------------------

    void setLoggerDllModule(void* hModule);
    void initLogger();
    void shutdownLogger();

    // Single-string overload - use when you already have a formatted string.
    void logToFile(const std::string& message);

    // ---------------------------------------------------------------------------
    // logToFilef
    //
    // printf-style overload.  Formats into a fixed-size stack buffer then
    // forwards to logToFile(std::string).  Safe for MSVC 2010 (no variadic
    // templates needed - plain C varargs).
    //
    // Usage:
    //   logToFilef("AddHook failed (status %d).", (int)status);
    //   logToFilef("Hook installed: %s", name);
    // ---------------------------------------------------------------------------
    inline void logToFilef(const char* fmt, ...)
    {
        char buf[1024];
        va_list args;
        va_start(args, fmt);
        _vsnprintf(buf, sizeof(buf) - 1, fmt, args);
        va_end(args);
        buf[sizeof(buf) - 1] = '\0';
        logToFile(std::string(buf));
    }

    // ---------------------------------------------------------------------------
    // logToFileDebug
    //
    // Logs a message only if debug logging is enabled in the configuration.
    // ---------------------------------------------------------------------------
    void logToFileDebug(const std::string& message);

    // ---------------------------------------------------------------------------
    // logToFileDebugf
    //
    // printf-style overload that only logs when debug logging is enabled.
    // ---------------------------------------------------------------------------
    inline void logToFileDebugf(const char* fmt, ...)
    {
        if (!KenshiLua::Config::get().isDebugLoggingEnabled()) return;

        char buf[1024];
        va_list args;
        va_start(args, fmt);
        _vsnprintf(buf, sizeof(buf) - 1, fmt, args);
        va_end(args);
        buf[sizeof(buf) - 1] = '\0';
        logToFile(std::string(buf));
    }

} // namespace KenshiLua
