#pragma once

#include <string>
#include <cstdint>

namespace KenshiLua
{
    std::string getDllDirectory(void* hModule = nullptr);
    void normalizePathSlashes(std::string& path);
    bool endsWithCaseInsensitive(const std::string& s, const std::string& suffix);
    uint64_t getFileLastWriteTime(const std::string& path);
}
