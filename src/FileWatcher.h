#pragma once

#include <string>
#include <unordered_map>

extern "C" {
#include <lua.h>
}

namespace KenshiLua
{

class FileWatcher
{
public:
    static FileWatcher& get();

    // Enables/disables the hot reload file watcher. Enabled by default.
    void setEnabled(bool enabled) { m_enabled = enabled; }
    bool isEnabled() const { return m_enabled; }

    // Resets tracked timestamps and file states.
    void reset();

    // Checks tracked scripts for filesystem modifications and hot-reloads changed files.
    // Throttled internally to prevent high-frequency frame overhead.
    void update(lua_State* L);

private:
    FileWatcher();
    ~FileWatcher();
    FileWatcher(const FileWatcher&);
    FileWatcher& operator=(const FileWatcher&);

    bool m_enabled;
    std::unordered_map<std::string, uint64_t> m_fileWriteTimes;
    unsigned long m_lastCheckTick;
};

} // namespace KenshiLua
