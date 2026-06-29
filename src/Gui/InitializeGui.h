#pragma once

namespace KenshiLua
{

class LuaState;

class KenshiLuaGui
{
public:
    static KenshiLuaGui& get();

    void requestInitialize(LuaState* luaState);
    void shutdown();
    void toggle();
    bool isInitialized() const;
    void checkKeyboardShortcut(OIS::KeyCode key, InputHandler* thisptr);

private:
    KenshiLuaGui();
    ~KenshiLuaGui();
    KenshiLuaGui(const KenshiLuaGui&);
    KenshiLuaGui& operator=(const KenshiLuaGui&);

    void initFrameHandler(float frameTime);

    LuaState* m_pendingLuaState;
    bool m_initialized;
};

} // namespace KenshiLua
