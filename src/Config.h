#pragma once

#include <string>
#include <OISKeyboard.h>

namespace KenshiLua
{
    class Config
    {
    public:
        static Config& get();

        // Initializes the config by reading config.ini.
        // It takes the DLL module handle to find config.ini relative to the DLL path.
        void load(void* hModule);

        bool isBenchmarkEnabled() const;
        bool isDebugLoggingEnabled() const;

        OIS::KeyCode getToggleGuiKey() const;
        bool isToggleGuiCtrl() const;
        bool isToggleGuiShift() const;
        bool isToggleGuiAlt() const;

        int getLogLevel() const;
        bool isStartMinimized() const;
        bool isHotReloadEnabled() const;

        // Developer logging: keep earlier sessions' logs in the logs folder instead of
        // overwriting a single log. Read at startup, before the log file opens.
        bool isKeepSessionLogsEnabled() const;
        int getMaxSessionLogs() const;

        void setLogLevel(int level);
        void setStartMinimized(bool minimized);
        void setHotReloadEnabled(bool enabled);
        void setKeepSessionLogsEnabled(bool enabled);
        void setToggleGuiKey(OIS::KeyCode key);
        void setToggleGuiCtrl(bool ctrl);
        void setToggleGuiShift(bool shift);
        void setToggleGuiAlt(bool alt);

        void save();

    private:
        Config();
        ~Config();

        // Non-copyable
        Config(const Config&);
        Config& operator=(const Config&);

        bool m_benchmarkEnabled;
        bool m_debugLoggingEnabled;
        int m_logLevel;
        bool m_startMinimized;
        bool m_enableHotReload;
        bool m_keepSessionLogs;
        int m_maxSessionLogs;

        OIS::KeyCode m_toggleGuiKey;
        bool m_toggleGuiCtrl;
        bool m_toggleGuiShift;
        bool m_toggleGuiAlt;

        std::string m_configPath;
    };
}
