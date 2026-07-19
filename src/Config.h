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

        void setLogLevel(int level);
        void setStartMinimized(bool minimized);
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

        OIS::KeyCode m_toggleGuiKey;
        bool m_toggleGuiCtrl;
        bool m_toggleGuiShift;
        bool m_toggleGuiAlt;

        std::string m_configPath;
    };
}
