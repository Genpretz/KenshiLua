#include "pch.h"
#include "Logger.h"
#include "Config.h"
#include "Util/PathUtils.h"

#include <string>
#include <ctime>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>

#include <boost/thread/lock_guard.hpp>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace KenshiLua
{

Logger& Logger::get()
{
    static Logger instance;
    return instance;
}

void Logger::init(const std::string& filepath, bool append)
{
    if (!m_initialized) {
        std::ios_base::openmode mode = std::ios::out | (append ? std::ios::app : std::ios::trunc);
        m_file.open(filepath, mode);
        m_initialized = m_file.is_open();

        if (m_initialized) {
            // Lines logged before the file opened, such as messages from loading the
            // config, are held only in the ring buffer; write them to the file first.
            boost::lock_guard<boost::mutex> lk(m_ringMutex);
            for (size_t i = 0; i < m_ringSize; ++i) {
                m_file << m_ring[(m_ringStart + i) % m_ring.size()] << '\n';
            }
            m_file.flush();
        }
    }
}

bool Logger::isInitialized() const
{
    return m_initialized;
}

static int getLogLevelSeverity(int level)
{
    switch (level)
    {
        case LogLevel_Debug: return 0;
        case LogLevel_Log:   return 1;
        case LogLevel_Warn:  return 2;
        case LogLevel_Error: return 3;
        default:             return 1;
    }
}

void Logger::log(LogLevel level, const std::string& message)
{
    if (getLogLevelSeverity(level) < getLogLevelSeverity(Config::get().getLogLevel()))
    {
        return;
    }

    boost::chrono::system_clock::time_point now = boost::chrono::system_clock::now();
    time_t time = boost::chrono::system_clock::to_time_t(now);
    boost::chrono::milliseconds ms = boost::chrono::duration_cast<boost::chrono::milliseconds>(
        now.time_since_epoch()) % 1000;

    std::tm tm;
    localtime_s(&tm, &time);

    char tsBuf[32];
    std::strftime(tsBuf, sizeof(tsBuf), "%Y-%m-%d %H:%M:%S", &tm);
    char msBuf[8];
    _snprintf(msBuf, sizeof(msBuf), ".%03lld", (long long)ms.count());

    size_t end = message.size();
    while (end > 0 && (message[end - 1] == '\n' || message[end - 1] == '\r')) {
        --end;
    }

    std::string formatted;
    formatted.reserve(end + 80);
    formatted += tsBuf;
    formatted += msBuf;
    formatted += " ";

    switch (level) {
    case LogLevel_Log:   formatted += "[LOG] "; break;
    case LogLevel_Warn:  formatted += "[WARN] "; break;
    case LogLevel_Error: formatted += "[ERROR] "; break;
    case LogLevel_Debug: formatted += "[DEBUG] "; break;
    }

    formatted.append(message.data(), end);

    {
        boost::lock_guard<boost::mutex> lk(m_ringMutex);
        if (m_ringSize < m_ring.size()) {
            m_ring[(m_ringStart + m_ringSize) % m_ring.size()] = formatted;
            ++m_ringSize;
        } else {
            m_ring[m_ringStart] = formatted;
            m_ringStart = (m_ringStart + 1) % m_ring.size();
        }
        ++m_sequenceNumber;
    }

    if (m_initialized && m_file.is_open()) {
        m_file << formatted << std::endl;
        m_file.flush();
    }
}

void Logger::log(const std::string& message)
{
    log(LogLevel_Log, message);
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

size_t Logger::getSequenceNumber() const
{
    boost::lock_guard<boost::mutex> lk(m_ringMutex);
    return m_sequenceNumber;
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

std::string getLogsDirectory()
{
    // The DLL lives in <KenshiLua mod>\plugin; logs go beside it in <KenshiLua mod>\logs.
    fs::path dllDir(getDllDirectory(s_dllModule));
    fs::path modDir = dllDir.parent_path();
    if (modDir.empty()) {
        modDir = dllDir;
    }
    return (modDir / "logs").string();
}

static bool ensureLogsDirectory(const std::string& dir)
{
    boost::system::error_code ec;
    fs::create_directories(fs::path(dir), ec);
    return fs::is_directory(fs::path(dir), ec);
}

// Returns "YYYY-MM-DD_HH-MM-SS" from the timestamp that starts the first line of a
// KenshiLua log, or an empty string if the line does not start with one.
static std::string readSessionStamp(const fs::path& logPath)
{
    std::ifstream in(logPath.string().c_str());
    std::string line;
    if (!in || !std::getline(in, line) || line.size() < 19) {
        return "";
    }
    static const char pattern[] = "dddd-dd-dd dd:dd:dd";
    for (size_t i = 0; i < 19; ++i) {
        char c = line[i];
        if (pattern[i] == 'd') {
            if (c < '0' || c > '9') return "";
        } else if (c != pattern[i]) {
            return "";
        }
    }
    std::string stamp = line.substr(0, 19);
    stamp[10] = '_';
    stamp[13] = '-';
    stamp[16] = '-';
    return stamp;
}

static std::string stampFromWriteTime(const fs::path& logPath)
{
    boost::system::error_code ec;
    std::time_t t = fs::last_write_time(logPath, ec);
    if (ec) {
        t = std::time(NULL);
    }
    std::tm tm;
    localtime_s(&tm, &t);
    char buf[32];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d_%H-%M-%S", &tm);
    return buf;
}

// True for archived session logs: KenshiLua_<YYYY-MM-DD>_<HH-MM-SS>[_N].log.
static bool isArchivedSessionLog(const std::string& name)
{
    return name.size() >= 33
        && name.compare(0, 10, "KenshiLua_") == 0
        && name[10] >= '0' && name[10] <= '9'
        && endsWithCaseInsensitive(name, ".log");
}

// Renames the previous session's log to KenshiLua_<session start>.log, then deletes
// the oldest archived session logs beyond maxKept. maxKept of 0 keeps them all.
static void archivePreviousSessionLog(const fs::path& dir, const fs::path& current, int maxKept)
{
    boost::system::error_code ec;
    if (fs::exists(current, ec)) {
        std::string stamp = readSessionStamp(current);
        if (stamp.empty()) {
            stamp = stampFromWriteTime(current);
        }
        fs::path target = dir / ("KenshiLua_" + stamp + ".log");
        for (int n = 2; fs::exists(target, ec) && n < 1000; ++n) {
            char suffix[16];
            _snprintf(suffix, sizeof(suffix), "_%d", n);
            suffix[sizeof(suffix) - 1] = '\0';
            target = dir / ("KenshiLua_" + stamp + suffix + ".log");
        }
        fs::rename(current, target, ec);
    }

    if (maxKept <= 0) {
        return;
    }

    std::vector<std::string> archives;
    fs::directory_iterator end;
    for (fs::directory_iterator it(dir, ec); !ec && it != end; it.increment(ec)) {
        std::string name = it->path().filename().string();
        if (isArchivedSessionLog(name)) {
            archives.push_back(it->path().string());
        }
    }
    // Names embed the session start time, so sorting by name sorts oldest first.
    std::sort(archives.begin(), archives.end());
    size_t excess = archives.size() > (size_t)maxKept ? archives.size() - (size_t)maxKept : 0;
    for (size_t i = 0; i < excess; ++i) {
        fs::remove(fs::path(archives[i]), ec);
    }
}

void initLogger()
{
    // Config must already be loaded: keep_session_logs decides whether the previous
    // session's log is archived before this session's log replaces it.
    std::string logsDir = getLogsDirectory();
    std::string logPath;
    if (ensureLogsDirectory(logsDir)) {
        fs::path current = fs::path(logsDir) / "KenshiLua.log";
        if (Config::get().isKeepSessionLogsEnabled()) {
            archivePreviousSessionLog(fs::path(logsDir), current, Config::get().getMaxSessionLogs());
        }
        logPath = current.string();
        Logger::get().init(logPath);
    }
    if (!Logger::get().isInitialized()) {
        // Fall back to the DLL folder if the logs folder cannot be created or opened.
        logPath = getDllDirectory(s_dllModule) + "\\KenshiLua.log";
        Logger::get().init(logPath);
    }
    Logger::get().log("KenshiLua logger initialized");
    Logger::get().log("Log file: " + logPath);
}

void logToFile(const std::string& message)
{
    Logger::get().log(LogLevel_Log, message);
}

void logToFile(LogLevel level, const std::string& message)
{
    Logger::get().log(level, message);
}

void logToFileWarn(const std::string& message)
{
    Logger::get().log(LogLevel_Warn, message);
}

void logToFileError(const std::string& message)
{
    Logger::get().log(LogLevel_Error, message);
}

void logToFileDebug(const std::string& message)
{
    Logger::get().log(LogLevel_Debug, message);
}

void logBenchmark(const std::string& message, const std::string& logFilename)
{
    std::string logsDir = getLogsDirectory();
    std::string benchmarkPath = ensureLogsDirectory(logsDir)
        ? logsDir + "\\" + logFilename
        : getDllDirectory(s_dllModule) + "\\" + logFilename;
    std::ofstream file(benchmarkPath, std::ios::app);
    if (file.is_open()) {
        auto now = boost::chrono::system_clock::now();
        auto time = boost::chrono::system_clock::to_time_t(now);
        std::tm tm;
        localtime_s(&tm, &time);

        char tsBuf[32];
        std::strftime(tsBuf, sizeof(tsBuf), "%Y-%m-%d %H:%M:%S", &tm);

        size_t end = message.size();
        while (end > 0 && (message[end - 1] == '\n' || message[end - 1] == '\r')) {
            --end;
        }

        file << "[" << tsBuf << "] " << message.substr(0, end) << std::endl;
        file.close();
    }
}

void shutdownLogger()
{
    Logger::get().log("KenshiLua logger shutting down");
    Logger::get().shutdown();
}

} // namespace KenshiLua