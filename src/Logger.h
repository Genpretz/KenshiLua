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
    enum LogLevel : int
    {
        LogLevel_Log,
        LogLevel_Warn,
        LogLevel_Error,
        LogLevel_Debug
    };

    class Logger
    {
    public:
        static Logger& get();

        void init(const std::string& filepath, bool append = false);
        void log(const std::string& message);
        void log(LogLevel level, const std::string& message);
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
    void logToFile(LogLevel level, const std::string& message);
    void logToFileWarn(const std::string& message);
    void logToFileError(const std::string& message);
    void logToFileDebug(const std::string& message);
    void logBenchmark(const std::string& message, const std::string& logFilename = "KenshiLua_Benchmark.log");

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

    inline void logToFileWarnf(const char* fmt, ...)
    {
        char buf[1024];
        va_list args;
        va_start(args, fmt);
        _vsnprintf(buf, sizeof(buf) - 1, fmt, args);
        va_end(args);
        buf[sizeof(buf) - 1] = '\0';
        logToFile(LogLevel_Warn, std::string(buf));
    }

    inline void logToFileErrorf(const char* fmt, ...)
    {
        char buf[1024];
        va_list args;
        va_start(args, fmt);
        _vsnprintf(buf, sizeof(buf) - 1, fmt, args);
        va_end(args);
        buf[sizeof(buf) - 1] = '\0';
        logToFile(LogLevel_Error, std::string(buf));
    }

    inline void logToFileDebugf(const char* fmt, ...)
    {
        if (!KenshiLua::Config::get().isDebugLoggingEnabled()) return;

        char buf[1024];
        va_list args;
        va_start(args, fmt);
        _vsnprintf(buf, sizeof(buf) - 1, fmt, args);
        va_end(args);
        buf[sizeof(buf) - 1] = '\0';
        logToFile(LogLevel_Debug, std::string(buf));
    }

} // namespace KenshiLua
