#pragma once

#include <string>
#include <OISKeyboard.h>

namespace KenshiLua
{
    class Config
    {
    public:
        static Config& get();

        // Initializes the config by reading config.txt.
        // It takes the DLL module handle to find config.txt relative to the DLL path.
        void load(void* hModule);

        bool isBenchmarkEnabled() const;
        bool isDebugLoggingEnabled() const;

        OIS::KeyCode getToggleGuiKey() const;
        bool isToggleGuiCtrl() const;
        bool isToggleGuiShift() const;
        bool isToggleGuiAlt() const;

    private:
        Config();
        ~Config();

        // Non-copyable
        Config(const Config&);
        Config& operator=(const Config&);

        bool m_benchmarkEnabled;
        bool m_debugLoggingEnabled;

        OIS::KeyCode m_toggleGuiKey;
        bool m_toggleGuiCtrl;
        bool m_toggleGuiShift;
        bool m_toggleGuiAlt;
    };
}
