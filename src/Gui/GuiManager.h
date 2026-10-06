#pragma once

#include <string>

class InputHandler;
enum OIS::KeyCode;

namespace MyGUI { class Window; }

namespace KenshiLua
{
    class LuaState;
    class KenshiLua_Hub;
    class KenshiLua_ScriptEditor;
    class KenshiLua_Console;
    class KenshiLua_LogViewer;
    class KenshiLua_ScriptManager;
    class KenshiLua_Settings;

    class GuiManager
    {
    public:
        static GuiManager& get();

        void requestInitialize(LuaState* luaState);
        void updateLuaState(LuaState* luaState);
        void shutdown();
        void toggle();
        void setVisible(bool visible);
        bool isInitialized() const;
        void checkKeyboardShortcut(OIS::KeyCode key, InputHandler* thisptr);

        // Moves a window that is about to be shown to the first free spot beside the Hub:
        // against the right edge of the windows already open, wrapping below them when a
        // row is full.
        void placeWindow(MyGUI::Window* target);

        void* getActiveOutputTarget() const { return m_activeOutputTarget; }
        void setActiveOutputTarget(void* target) { m_activeOutputTarget = target; }

        void appendOutput(const std::string& text);
        void clearOutput();

        KenshiLua_Hub* getHub() const { return m_hub; }
        KenshiLua_ScriptEditor* getEditor() const { return m_editor; }
        KenshiLua_Console* getConsole() const { return m_console; }
        KenshiLua_LogViewer* getLogViewer() const { return m_logViewer; }
        KenshiLua_ScriptManager* getScriptManager() const { return m_scriptManager; }
        KenshiLua_Settings* getSettings() const { return m_settings; }

    private:
        GuiManager();
        ~GuiManager();
        GuiManager(const GuiManager&);
        GuiManager& operator=(const GuiManager&);

        void initFrameHandler(float frameTime);
        void onFrameStart(float frameTime);

        LuaState*           m_luaState;
        LuaState*           m_pendingLuaState;
        bool                m_initialized;
        bool                m_visible;
        void*               m_activeOutputTarget;

        // The Hub's position when it was created. The Hub cannot be moved, but edge hide
        // slides it off screen, so windows are placed against this rectangle instead.
        int                 m_hubHomeLeft;
        int                 m_hubHomeTop;
        int                 m_hubHomeWidth;
        int                 m_hubHomeHeight;

        KenshiLua_Hub*           m_hub;
        KenshiLua_ScriptEditor*  m_editor;
        KenshiLua_Console*       m_console;
        KenshiLua_LogViewer*     m_logViewer;
        KenshiLua_ScriptManager* m_scriptManager;
        KenshiLua_Settings*      m_settings;
    };
} // namespace KenshiLua

