#include "pch.h"
#include "Gui.h"
#include "Lua/LuaState.h"
#include "Logger.h"
#include "Config.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <commdlg.h>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>

#include <kenshi/InputHandler.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

    // ---------------------------------------------------------------------------
    // GuiHelpers Implementation
    // ---------------------------------------------------------------------------
    namespace GuiHelpers
    {
        MyGUI::WidgetPtr FindWidget(MyGUI::EnumeratorWidgetPtr enumerator, const std::string& name)
        {
            while (enumerator.next())
            {
                std::string widgetName = enumerator.current()->getName();
                size_t splitPos = widgetName.find('_');

                if (splitPos != std::string::npos && widgetName.substr(splitPos + 1) == name)
                    return enumerator.current();
                if (enumerator.current()->getChildCount() > 0)
                {
                    MyGUI::WidgetPtr childFoundWidget = FindWidget(enumerator.current()->getEnumerator(), name);
                    if (childFoundWidget != nullptr)
                        return childFoundWidget;
                }
            }
            return nullptr;
        }

        MyGUI::Window* createWindow(
            const std::string& skin,
            int x, int y, int w, int h,
            const std::string& name,
            const std::string& caption)
        {
            MyGUI::Gui* gui = MyGUI::Gui::getInstancePtr();
            if (!gui) return nullptr;

            MyGUI::Window* window = gui->createWidget<MyGUI::Window>(
                skin, x, y, w, h,
                MyGUI::Align::Default,
                "Window",
                name);

            if (window)
            {
                window->setCaption(caption);
                window->setVisible(false);
            }
            return window;
        }

        MyGUI::Button* createButton(
            MyGUI::Widget* parent,
            int x, int y, int w, int h,
            const std::string& skin,
            const std::string& caption,
            const std::string& name,
            MyGUI::delegates::CDelegate1<MyGUI::Widget*>::IDelegate* handler)
        {
            if (!parent) return nullptr;

            MyGUI::Button* b = parent->createWidget<MyGUI::Button>(
                skin, x, y, w, h,
                MyGUI::Align::Left | MyGUI::Align::Top,
                name);

            if (b)
            {
                b->setCaption(caption);
                if (handler)
                    b->eventMouseButtonClick += handler;
            }
            return b;
        }

        MyGUI::EditBox* createEditBox(
            MyGUI::Widget* parent,
            int x, int y, int w, int h,
            const std::string& skin,
            const std::string& name,
            bool multiLine,
            bool readOnly)
        {
            if (!parent) return nullptr;

            MyGUI::EditBox* eb = parent->createWidget<MyGUI::EditBox>(
                skin, x, y, w, h,
                MyGUI::Align::Stretch,
                name);

            if (eb)
            {
                eb->setEditMultiLine(multiLine);
                eb->setEditReadOnly(readOnly);
                if (multiLine)
                {
                    eb->setVisibleVScroll(true);
                    eb->setVisibleHScroll(true);
                    eb->setMaxTextLength(MyGUI::ITEM_NONE);
                }
            }
            return eb;
        }
    } // namespace GuiHelpers


    // ---------------------------------------------------------------------------
    // ScriptEditor Implementation
    // ---------------------------------------------------------------------------
    static ScriptEditor* s_instance = 0;

    static std::string OpenFileDialog(const std::string& currentPath)
    {
        char filename[MAX_PATH] = "";
        OPENFILENAMEA ofn = {};
        ofn.lStructSize = sizeof(ofn);
        ofn.lpstrFilter = "Lua Files (*.lua)\0*.lua\0All Files (*.*)\0*.*\0";
        ofn.lpstrFile = filename;
        ofn.nMaxFile = MAX_PATH;
        ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR;
        ofn.lpstrDefExt = "lua";
        ofn.lpstrTitle = "Open Lua Script";

        return GetOpenFileNameA(&ofn) ? std::string(filename) : "";
    }

    static std::string SaveFileDialog(const std::string& currentPath)
    {
        char filename[MAX_PATH] = "";

        if (!currentPath.empty())
            strncpy_s(filename, currentPath.c_str(), MAX_PATH - 1);

        OPENFILENAMEA ofn = {};
        ofn.lStructSize = sizeof(ofn);
        ofn.lpstrFilter = "Lua Files (*.lua)\0*.lua\0All Files (*.*)\0*.*\0";
        ofn.lpstrFile = filename;
        ofn.nMaxFile = MAX_PATH;
        ofn.Flags = OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR;
        ofn.lpstrDefExt = "lua";
        ofn.lpstrTitle = "Save Lua Script";

        return GetSaveFileNameA(&ofn) ? std::string(filename) : "";
    }

    static int lua_customPrint(lua_State* L)
    {
        int n = lua_gettop(L);
        std::string msg;
        for (int i = 1; i <= n; i++) {
            if (i > 1) msg += "\t";
            size_t len = 0;
            const char* s = luaL_tolstring(L, i, &len);
            if (s) {
                msg.append(s, len);
            }
            lua_pop(L, 1);
        }
        msg += "\n";
        ScriptEditor::get().appendOutput(msg);
        return 0;
    }

    ScriptEditor& ScriptEditor::get()
    {
        static ScriptEditor inst;
        s_instance = &inst;
        return inst;
    }

    ScriptEditor::ScriptEditor()
        : m_luaState(nullptr)
        , m_pendingLuaState(nullptr)
        , m_initialized(false)
        , m_visible(false)
        , m_window(nullptr)
        , m_codePane(nullptr)
        , m_outputBox(nullptr)
    {
    }

    ScriptEditor::~ScriptEditor()
    {
    }

    void ScriptEditor::requestInitialize(LuaState* luaState)
    {
        if (m_initialized || m_pendingLuaState != nullptr)
        {
            logToFile("ScriptEditor: Already initialized or initialization pending - ignoring request");
            return;
        }
        m_pendingLuaState = luaState;

        MyGUI::Gui* gui = MyGUI::Gui::getInstancePtr();
        if (gui)
        {
            gui->eventFrameStart += MyGUI::newDelegate(this, &ScriptEditor::initFrameHandler);
            logToFile("ScriptEditor: Subscribed to eventFrameStart");
        }
        else
        {
            logToFile("ScriptEditor: MyGUI singleton not yet available in requestInitialize");
        }
    }

    void ScriptEditor::initFrameHandler(float)
    {
        if (m_initialized)
            return;

        MyGUI::Gui* gui = MyGUI::Gui::getInstancePtr();
        if (!gui)
            return;

        MyGUI::WidgetPtr versionText = GuiHelpers::FindWidget(gui->getEnumerator(), "VersionText");
        if (versionText == nullptr)
            return;

        gui->eventFrameStart -=
            MyGUI::newDelegate(this, &ScriptEditor::initFrameHandler);

        logToFile("Initializing ScriptEditor Window");

        m_luaState = m_pendingLuaState;

        if (m_luaState)
        {
            lua_State* L = m_luaState->getState();
            lua_pushcfunction(L, lua_customPrint);
            lua_setglobal(L, "print");
        }

        const int W     = 800;
        const int H     = 1000;
        const int PAD   = 4;
        const int BTN_H = 30;
        const int BTN_W = 80;
        const int OUT_H = 400;

        m_window = GuiHelpers::createWindow("Kenshi_WindowCX", 50, 50, W, H, "KenshiLuaEditor", "KenshiLua Script Editor");
        if (!m_window)
            return;

        m_window->eventWindowButtonPressed += MyGUI::newDelegate(this, &ScriptEditor::onWindowButtonPressed);

        MyGUI::Widget* client = m_window->getClientWidget();
        const int clientW = client->getWidth();
        const int clientH = client->getHeight();

        int btnX = PAD;
        const int btnY = PAD;

        GuiHelpers::createButton(client, btnX, btnY, BTN_W, BTN_H, "Kenshi_Button1", "Run", "RunButton", MyGUI::newDelegate(this, &ScriptEditor::onRunClicked));
        btnX += BTN_W + PAD;
        GuiHelpers::createButton(client, btnX, btnY, BTN_W, BTN_H, "Kenshi_Button1", "Open", "OpenButton", MyGUI::newDelegate(this, &ScriptEditor::onOpenClicked));
        btnX += BTN_W + PAD;
        GuiHelpers::createButton(client, btnX, btnY, BTN_W, BTN_H, "Kenshi_Button1", "Save", "SaveButton", MyGUI::newDelegate(this, &ScriptEditor::onSaveClicked));
        btnX += BTN_W + PAD;
        GuiHelpers::createButton(client, btnX, btnY, BTN_W + 30, BTN_H, "Kenshi_Button1", "Save As", "SaveAsButton", MyGUI::newDelegate(this, &ScriptEditor::onSaveAsClicked));
        btnX += BTN_W + 30 + PAD;
        GuiHelpers::createButton(client, btnX, btnY, BTN_W, BTN_H, "Kenshi_Button1", "Clear", "ClearButton", MyGUI::newDelegate(this, &ScriptEditor::onClearClicked));

        std::string editBoxSkin = "Kenshi_ScriptEditor_EditBox";

        MyGUI::ResourceManager* res = MyGUI::ResourceManager::getInstancePtr();
        if (!res->load("Kenshi_ScriptEditor_EditBox.xml"))
            logToFile("Kenshi_ScriptEditor_EditBox.xml not found.");

        const int editorY = BTN_H + PAD * 2;
        const int editorH = clientH - editorY - OUT_H - PAD * 3;

        // input editbox
        m_codePane = GuiHelpers::createEditBox(client, PAD, editorY, clientW - PAD * 2, editorH, editBoxSkin, "KenshiLuaCode", true, false);

        const int outputY = editorY + editorH + PAD;

        // output editbox
        m_outputBox = GuiHelpers::createEditBox(client, PAD, outputY, clientW - PAD * 2, OUT_H, editBoxSkin, "KenshiLuaOutput", true, true);
        if (m_outputBox)
        {
            m_outputBox->setNeedMouseFocus(true);
            m_outputBox->setNeedKeyFocus(true);
        }

        m_initialized = true;
        logToFile("ScriptEditor Window initialized.");
    }

    void ScriptEditor::shutdown()
    {
        m_initialized = false;
        m_window = nullptr;
    }

    void ScriptEditor::toggle()
    {
        if (m_initialized)
        {
            setVisible(!m_visible);
        }
    }

    void ScriptEditor::setVisible(bool visible)
    {
        if (m_window)
        {
            m_window->setVisible(visible);
            m_visible = visible;
            if (visible && m_codePane)
            {
                MyGUI::InputManager::getInstance().setKeyFocusWidget(m_codePane);
            }
        }
    }

    bool ScriptEditor::isInitialized() const
    {
        return m_initialized;
    }

    void ScriptEditor::checkKeyboardShortcut(OIS::KeyCode key, InputHandler* thisptr)
    {
        const Config& conf = Config::get();
        if (key == conf.getToggleGuiKey() &&
            thisptr->ctrl == conf.isToggleGuiCtrl() &&
            thisptr->shift == conf.isToggleGuiShift() &&
            thisptr->alt == conf.isToggleGuiAlt())
        {
            toggle();
        }
    }

    void ScriptEditor::appendOutput(const std::string& text)
    {
        logToFile(text);

        if (!m_outputBox)
            return;

        m_outputBox->addText(MyGUI::UString(text));
        
        size_t length = m_outputBox->getTextLength();
        m_outputBox->setTextCursor(length);
    }

    void ScriptEditor::clearOutput()
    {
        if (m_outputBox)
            m_outputBox->setCaption("");
    }



    void ScriptEditor::onWindowButtonPressed(MyGUI::Window*, const std::string& name)
    {
        if (name == "close")
        {
            setVisible(false);
            MyGUI::InputManager::getInstance().resetKeyFocusWidget();
        }
    }

    void ScriptEditor::onRunClicked(MyGUI::Widget*)
    {
        if (!m_codePane)
            return;

        std::string code = m_codePane->getCaption().asUTF8();

        if (code.empty())
        {
            appendOutput("(editor is empty)\n");
            return;
        }

        const std::string label = m_currentFilePath.empty() ? "<editor>" : m_currentFilePath;

        appendOutput("=== Running: " + label + " ===\n");
        
        if (m_luaState)
        {
            lua_State* L = m_luaState->getState();
            int top = lua_gettop(L);
            
            if (luaL_loadbuffer(L, code.c_str(), code.size(), label.c_str()) != LUA_OK ||
                lua_pcall(L, 0, LUA_MULTRET, 0) != LUA_OK)
            {
                const char* err = lua_tostring(L, -1);
                std::string e = err ? err : "(error)";
                appendOutput("ERROR: " + e + "\n");
                logToFile("Lua error: " + e);
            }
            else
            {
                int nres = lua_gettop(L) - top;
                if (nres > 0)
                {
                    for (int i = 1; i <= nres; ++i)
                    {
                        const char* res = lua_tostring(L, -i);
                        if (res)
                        {
                            appendOutput(std::string(res) + "\n");
                        }
                    }
                }
                appendOutput("=== Done ===\n\n");
            }
            lua_settop(L, top);
        }
        else
        {
            appendOutput("ERROR: LuaState not initialized\n");
        }
    }

    void ScriptEditor::onOpenClicked(MyGUI::Widget*)
    {
        std::string path = OpenFileDialog(m_currentFilePath);
        if (path.empty())
            return;

        std::ifstream f(path.c_str(), std::ios::binary);
        if (!f.is_open())
        {
            appendOutput("Failed to open: " + path + "\n");
            return;
        }

        std::ostringstream ss;
        ss << f.rdbuf();

        m_codePane->setCaption(MyGUI::UString(ss.str()));
        m_currentFilePath = path;

        appendOutput("Loaded: " + path + "\n");
    }

    void ScriptEditor::onSaveClicked(MyGUI::Widget*)
    {
        if (!m_codePane)
            return;

        std::string path = m_currentFilePath.empty()
            ? SaveFileDialog(m_currentFilePath)
            : m_currentFilePath;

        if (path.empty())
            return;

        saveToFile(path);
    }

    void ScriptEditor::onSaveAsClicked(MyGUI::Widget*)
    {
        if (!m_codePane)
            return;

        std::string path = SaveFileDialog(m_currentFilePath);

        if (path.empty())
            return;

        saveToFile(path);
    }

    void ScriptEditor::onClearClicked(MyGUI::Widget*)
    {
        if (m_codePane)
            m_codePane->setCaption("");

        m_currentFilePath.clear();
        clearOutput();
    }

    bool ScriptEditor::saveToFile(const std::string& path)
    {
        std::ofstream f(path.c_str(), std::ios::binary);
        if (!f.is_open())
        {
            appendOutput("Failed to save: " + path + "\n");
            return false;
        }

        f << m_codePane->getCaption().asUTF8();
        m_currentFilePath = path;

        appendOutput("Saved: " + path + "\n");
        return true;
    }

} // namespace KenshiLua
