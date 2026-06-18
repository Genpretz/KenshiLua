#pragma once

#include <string>

namespace MyGUI
{
    class Widget;
    class Window;
    class EditBox;
    class Button;
}

namespace KenshiLua
{
    class LuaState;

    class ScriptEditor
    {
    public:
        static ScriptEditor& get();

        void initialize(LuaState* luaState);
        void shutdown();
        void toggle();
        bool isVisible() const { return m_visible; }

        void appendOutput(const std::string& text);
        void clearOutput();

    private:
        ScriptEditor();
        ~ScriptEditor();
        ScriptEditor(const ScriptEditor&);
        ScriptEditor& operator=(const ScriptEditor&);

        void onRunClicked(MyGUI::Widget* sender);
        void onOpenClicked(MyGUI::Widget* sender);
        void onSaveClicked(MyGUI::Widget* sender);
        void onSaveAsClicked(MyGUI::Widget* sender);
        void onClearClicked(MyGUI::Widget* sender);
        void onWindowButtonPressed(MyGUI::Window* sender, const std::string& name);

        bool saveToFile(const std::string& path);

        LuaState*           m_luaState;
        bool                m_visible;

        MyGUI::Window*      m_window;
        MyGUI::EditBox*     m_codePane;
        MyGUI::EditBox*     m_outputBox;
        std::string         m_currentFilePath;
    };

} // namespace KenshiLua
