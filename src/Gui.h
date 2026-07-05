#pragma once

#include <string>
#include <MyGUI.h>
#include <OISKeyboard.h>

class InputHandler;

namespace KenshiLua
{
    class LuaState;

    namespace GuiHelpers
    {
        MyGUI::WidgetPtr FindWidget(MyGUI::EnumeratorWidgetPtr enumerator, const std::string& name);

        MyGUI::Window* createWindow(
            const std::string& skin,
            int x, int y, int w, int h,
            const std::string& name,
            const std::string& caption = "");

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
            bool readOnly = false);
    } // namespace GuiHelpers

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

    private:
        ScriptEditor();
        ~ScriptEditor();
        ScriptEditor(const ScriptEditor&);
        ScriptEditor& operator=(const ScriptEditor&);

        void initFrameHandler(float frameTime);

        void onWindowButtonPressed(MyGUI::Window* sender, const std::string& name);
        void onRunClicked(MyGUI::Widget* sender);
        void onOpenClicked(MyGUI::Widget* sender);
        void onSaveClicked(MyGUI::Widget* sender);
        void onSaveAsClicked(MyGUI::Widget* sender);
        void onClearClicked(MyGUI::Widget* sender);

        bool saveToFile(const std::string& path);

        LuaState*           m_luaState;
        LuaState*           m_pendingLuaState;
        bool                m_initialized;
        bool                m_visible;

        MyGUI::Window*      m_window;
        MyGUI::EditBox*     m_codePane;
        MyGUI::EditBox*     m_outputBox;
        std::string         m_currentFilePath;
    };
} // namespace KenshiLua
