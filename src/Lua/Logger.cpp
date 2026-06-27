#include "pch.h"
#include "Logger.h"
#include "Config.h"
#include <string>
#include <ctime>
#include <fstream>
#include <boost/chrono.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/lock_guard.hpp>

namespace KenshiLua
{

Logger& Logger::get()
{
    static Logger instance;
    return instance;
}

void Logger::init(const std::string& filepath)
{
    if (!m_initialized) {
        m_file.open(filepath, std::ios::app);
        m_initialized = m_file.is_open();
    }
}

void Logger::log(const std::string& message)
{
    boost::chrono::system_clock::time_point now = boost::chrono::system_clock::now();
    time_t time = boost::chrono::system_clock::to_time_t(now);
    boost::chrono::milliseconds ms = boost::chrono::duration_cast<boost::chrono::milliseconds>(
        now.time_since_epoch()) % 1000;

    std::tm tm;
#ifdef _WIN32
    localtime_s(&tm, &time);
#else
    localtime_r(&time, &tm);
#endif

    char tsBuf[32];
    std::strftime(tsBuf, sizeof(tsBuf), "%Y-%m-%d %H:%M:%S", &tm);
    char msBuf[8];
    _snprintf(msBuf, sizeof(msBuf), ".%03lld", (long long)ms.count());

    std::string formatted;
    formatted.reserve(message.size() + 64);
    formatted += tsBuf;
    formatted += msBuf;
    formatted += " ";
    formatted += message;

    {
        boost::lock_guard<boost::mutex> lk(m_ringMutex);
        if (m_ringSize < m_ring.size()) {
            m_ring[(m_ringStart + m_ringSize) % m_ring.size()] = formatted;
            ++m_ringSize;
        } else {
            m_ring[m_ringStart] = formatted;
            m_ringStart = (m_ringStart + 1) % m_ring.size();
        }
    }

    if (m_initialized && m_file.is_open()) {
        m_file << formatted << std::endl;
        m_file.flush();
    }
}

void Logger::snapshot(std::vector<std::string>& out, size_t maxLines) const
{
    boost::lock_guard<boost::mutex> lk(m_ringMutex);
    out.clear();
    if (m_ring.empty() || m_ringSize == 0) {
        return;
    }
    size_t count = m_ringSize;
    if (maxLines > 0 && maxLines < count) count = maxLines;
    out.reserve(count);
    size_t firstIdx = m_ringSize - count;
    for (size_t i = 0; i < count; ++i) {
        size_t idx = (m_ringStart + firstIdx + i) % m_ring.size();
        out.push_back(m_ring[idx]);
    }
}

void Logger::shutdown()
{
    if (m_file.is_open()) {
        m_file.close();
    }
    m_initialized = false;
}

static void* s_dllModule = NULL;

void setLoggerDllModule(void* hModule)
{
    s_dllModule = hModule;
}

static std::string getLogFilepath()
{
    char modulePath[MAX_PATH] = {0};
    if (s_dllModule) {
        GetModuleFileNameA((HMODULE)s_dllModule, modulePath, MAX_PATH);
    }

    std::string dllPath(modulePath);
    size_t pos = dllPath.find_last_of("\\/");
    if (pos != std::string::npos) {
        dllPath = dllPath.substr(0, pos);
    } else {
        dllPath = ".";
    }

    auto now = boost::chrono::system_clock::now();
    auto time = boost::chrono::system_clock::to_time_t(now);
    std::tm tm;
#ifdef _WIN32
    localtime_s(&tm, &time);
#else
    localtime_r(&time, &tm);
#endif

    char buf[64];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d", &tm);
    return dllPath + "\\KenshiLua_" + buf + ".log";
}

void initLogger()
{
    Logger::get().init(getLogFilepath());
    Logger::get().log("------------------------------ Begin ------------------------------");
    Logger::get().log("KenshiLua logger initialized");
}

void logToFile(const std::string& message)
{
    Logger::get().log(message);
}

void logToFileDebug(const std::string& message)
{
    if (Config::get().isDebugLoggingEnabled()) {
        Logger::get().log(message);
    }
}

void logBenchmark(const std::string& message)
{
    char modulePath[MAX_PATH] = {0};
    if (s_dllModule) {
        GetModuleFileNameA((HMODULE)s_dllModule, modulePath, MAX_PATH);
    }

    std::string dllPath(modulePath);
    size_t pos = dllPath.find_last_of("\\/");
    if (pos != std::string::npos) {
        dllPath = dllPath.substr(0, pos);
    } else {
        dllPath = ".";
    }

    std::string benchmarkPath = dllPath + "\\KenshiLua_Benchmark.log";
    std::ofstream file(benchmarkPath, std::ios::app);
    if (file.is_open()) {
        auto now = boost::chrono::system_clock::now();
        auto time = boost::chrono::system_clock::to_time_t(now);
        std::tm tm;
#ifdef _WIN32
        localtime_s(&tm, &time);
#else
        localtime_r(&time, &tm);
#endif
        char tsBuf[32];
        std::strftime(tsBuf, sizeof(tsBuf), "%Y-%m-%d %H:%M:%S", &tm);

        file << "[" << tsBuf << "] " << message << std::endl;
        file.close();
    }
}

void shutdownLogger()
{
    Logger::get().log("KenshiLua logger shutting down");
    Logger::get().log("------------------------------  End  ------------------------------");
    Logger::get().shutdown();
}

} // namespace KenshiLua