#pragma once

#include <string>
#include <MyGUI.h>
#include <OISKeyboard.h>

class InputHandler;

namespace KenshiLua
{
    // ---------------------------------------------------------------------------
    // GuiHelpers - shared widget creation utilities
    // ---------------------------------------------------------------------------
    namespace GuiHelpers
    {
        MyGUI::WidgetPtr FindWidget(MyGUI::EnumeratorWidgetPtr enumerator, const std::string& name);

        MyGUI::Window* createWindow(
            const std::string& skin,
            int x, int y, int w, int h,
            const std::string& name,
            const std::string& caption);

        MyGUI::Button* createButton(
            MyGUI::Widget* parent,
            int x, int y, int w, int h,
            const std::string& skin,
            const std::string& caption,
            const std::string& name,
            MyGUI::delegates::CDelegate1<MyGUI::Widget*>::IDelegate* handler);

        MyGUI::EditBox* createEditBox(
            MyGUI::Widget* parent,
            int x, int y, int w, int h,
            const std::string& skin,
            const std::string& name,
            bool multiLine,
            bool readOnly);
    } // namespace GuiHelpers

    class LuaState;
    class KenshiLua_Hub;
    class KenshiLua_ScriptEditor;
    class KenshiLua_Console;
    class KenshiLua_LogViewer;
    class KenshiLua_ScriptManager;
    class KenshiLua_Settings;

    class ScriptEditor
    {
    public:
        static ScriptEditor& get();

        void requestInitialize(LuaState* luaState);
        void shutdown();
        void toggle();
        void setVisible(bool visible);
        bool isInitialized() const;
        void checkKeyboardShortcut(OIS::KeyCode key, InputHandler* thisptr);

        void appendOutput(const std::string& text);
        void clearOutput();

        KenshiLua_Hub* getHub() const { return m_hub; }
        KenshiLua_ScriptEditor* getEditor() const { return m_editor; }
        KenshiLua_Console* getConsole() const { return m_console; }
        KenshiLua_LogViewer* getLogViewer() const { return m_logViewer; }
        KenshiLua_ScriptManager* getScriptManager() const { return m_scriptManager; }
        KenshiLua_Settings* getSettings() const { return m_settings; }

    private:
        ScriptEditor();
        ~ScriptEditor();
        ScriptEditor(const ScriptEditor&);
        ScriptEditor& operator=(const ScriptEditor&);

        void initFrameHandler(float frameTime);

        LuaState*           m_luaState;
        LuaState*           m_pendingLuaState;
        bool                m_initialized;
        bool                m_visible;

        KenshiLua_Hub*           m_hub;
        KenshiLua_ScriptEditor*  m_editor;
        KenshiLua_Console*       m_console;
        KenshiLua_LogViewer*     m_logViewer;
        KenshiLua_ScriptManager* m_scriptManager;
        KenshiLua_Settings*      m_settings;
    };
} // namespace KenshiLua

