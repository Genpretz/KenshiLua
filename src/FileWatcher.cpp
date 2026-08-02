#include "pch.h"
#include "FileWatcher.h"
#include "ScriptLoader.h"
#include "Config.h"
#include "Logger.h"
#include <Windows.h>

namespace KenshiLua
{

static uint64_t getFileLastWriteTime(const std::string& path)
{
    WIN32_FILE_ATTRIBUTE_DATA data;
    std::wstring wpath(path.begin(), path.end());
    if (GetFileAttributesExW(wpath.c_str(), GetFileExInfoStandard, &data))
    {
        ULARGE_INTEGER uli;
        uli.LowPart = data.ftLastWriteTime.dwLowDateTime;
        uli.HighPart = data.ftLastWriteTime.dwHighDateTime;
        return uli.QuadPart;
    }
    return 0;
}

FileWatcher& FileWatcher::get()
{
    static FileWatcher instance;
    return instance;
}

FileWatcher::FileWatcher()
    : m_enabled(false)
    , m_lastCheckTick(GetTickCount())
{
}

FileWatcher::~FileWatcher()
{
}

void FileWatcher::reset()
{
    m_fileWriteTimes.clear();
    m_lastCheckTick = GetTickCount();
}

void FileWatcher::update(lua_State* L)
{
    if ((!m_enabled && !Config::get().isHotReloadEnabled()) || !L) return;

    DWORD now = GetTickCount();
    if (now - m_lastCheckTick < 500)
    {
        return;
    }
    m_lastCheckTick = now;

    // Discover any newly created scripts in active mods
    ScriptLoader::get().discover();
    const auto& scripts = ScriptLoader::get().scripts();

    for (size_t i = 0; i < scripts.size(); ++i)
    {
        const std::string& path = scripts[i].absolutePath;
        uint64_t writeTime = getFileLastWriteTime(path);
        if (writeTime == 0) continue;

        auto it = m_fileWriteTimes.find(path);
        if (it != m_fileWriteTimes.end())
        {
            if (it->second != writeTime)
            {
                it->second = writeTime;
                logToFile("FileWatcher: Detected change in " + scripts[i].chunkName + " - triggering hot reload");
                ScriptLoader::get().reloadSingleScript(L, path);
            }
        }
        else
        {
            // Initial tracking baseline for script file
            m_fileWriteTimes[path] = writeTime;
        }
    }
}

} // namespace KenshiLua
