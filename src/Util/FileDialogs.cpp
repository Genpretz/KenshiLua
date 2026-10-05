#include "pch.h"
#include "Util/FileDialogs.h"
#include <commdlg.h>

namespace KenshiLua
{
    namespace FileDialogs
    {

        static ULONGLONG s_lastFileDialogClosedTime = 0;
        static const ULONGLONG FILE_DIALOG_DEBOUNCE_MS = 350;

        std::string openFileDialog(
            const std::string& title,
            const char* filter,
            const std::string& defaultExt,
            const std::string& currentPath)
        {
            ULONGLONG now = GetTickCount64();
            if (now - s_lastFileDialogClosedTime < FILE_DIALOG_DEBOUNCE_MS)
            {
                return "";
            }

            char filename[MAX_PATH] = "";
            if (!currentPath.empty())
            {
                strncpy_s(filename, currentPath.c_str(), MAX_PATH - 1);
            }

            OPENFILENAMEA ofn = {};
            ofn.lStructSize = sizeof(ofn);
            ofn.lpstrFilter = filter;
            ofn.lpstrFile = filename;
            ofn.nMaxFile = MAX_PATH;
            ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR;
            ofn.lpstrDefExt = defaultExt.c_str();
            ofn.lpstrTitle = title.c_str();

            BOOL result = GetOpenFileNameA(&ofn);
            s_lastFileDialogClosedTime = GetTickCount64();

            return result ? std::string(filename) : "";
        }

        std::string saveFileDialog(
            const std::string& title,
            const char* filter,
            const std::string& defaultExt,
            const std::string& defaultFilename,
            const std::string& currentPath)
        {
            ULONGLONG now = GetTickCount64();
            if (now - s_lastFileDialogClosedTime < FILE_DIALOG_DEBOUNCE_MS)
            {
                return "";
            }

            char filename[MAX_PATH] = "";
            if (!defaultFilename.empty())
            {
                strncpy_s(filename, defaultFilename.c_str(), MAX_PATH - 1);
            }
            else if (!currentPath.empty())
            {
                strncpy_s(filename, currentPath.c_str(), MAX_PATH - 1);
            }

            OPENFILENAMEA ofn = {};
            ofn.lStructSize = sizeof(ofn);
            ofn.lpstrFilter = filter;
            ofn.lpstrFile = filename;
            ofn.nMaxFile = MAX_PATH;
            ofn.Flags = OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR;
            ofn.lpstrDefExt = defaultExt.c_str();
            ofn.lpstrTitle = title.c_str();

            BOOL result = GetSaveFileNameA(&ofn);
            s_lastFileDialogClosedTime = GetTickCount64();

            return result ? std::string(filename) : "";
        }
    }
}