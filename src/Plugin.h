#pragma once

namespace KenshiLua
{

class Plugin
{
public:
    static Plugin& get();

    bool initialize(void* hModule);
    void shutdown();
    void start();

    void* getDllModule() const { return m_dllModule; }
    bool isInitialized() const { return m_initialized; }
    unsigned long getLuaThreadId() const { return m_luaThreadId; }
    bool isLuaThread() const;

private:
    Plugin();
    ~Plugin();
    Plugin(const Plugin&);
    Plugin& operator=(const Plugin&);

    void* m_dllModule;
    bool m_initialized;
    bool m_isInitialStartup;
    unsigned long m_luaThreadId;
};

} // namespace KenshiLua
