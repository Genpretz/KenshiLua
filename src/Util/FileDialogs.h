#pragma once
#include <string>

namespace KenshiLua
{
    namespace FileDialogs
    {

        std::string openFileDialog(
            const std::string& title,
            const char* filter,
            const std::string& defaultExt,
            const std::string& currentPath = "");

        std::string saveFileDialog(
            const std::string& title,
            const char* filter,
            const std::string& defaultExt,
            const std::string& defaultFilename = "",
            const std::string& currentPath = "");
    }
}