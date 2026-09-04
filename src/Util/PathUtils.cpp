#include "pch.h"
#include "Util/PathUtils.h"

#include <windows.h>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/replace.hpp>

namespace KenshiLua
{
    std::string getDllDirectory(void* hModule)
    {
        char modulePath[MAX_PATH] = {0};
        HMODULE hMod = (HMODULE)hModule;

        if (!hMod)
        {
            GetModuleHandleExA(
                GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                (LPCSTR)&getDllDirectory,
                &hMod);
        }

        if (!hMod)
        {
            hMod = GetModuleHandleA("KenshiLua.dll");
        }

        if (hMod)
        {
            GetModuleFileNameA(hMod, modulePath, MAX_PATH);
        }

        std::string dllPath(modulePath);
        size_t pos = dllPath.find_last_of("\\/");
        if (pos != std::string::npos)
        {
            dllPath = dllPath.substr(0, pos);
        }
        else
        {
            dllPath = ".";
        }
        return dllPath;
    }

    void normalizePathSlashes(std::string& path)
    {
        boost::algorithm::replace_all(path, "\\", "/");
    }

    bool endsWithCaseInsensitive(const std::string& s, const std::string& suffix)
    {
        return boost::algorithm::iends_with(s, suffix);
    }

    uint64_t getFileLastWriteTime(const std::string& path)
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
}
