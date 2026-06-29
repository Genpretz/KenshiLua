#include "pch.h"
#include "Gui/ScriptEditor.h"
#include "Lua/LuaState.h"
#include "Logger.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <commdlg.h>

#include <MyGUI.h>
#include <fstream>
#include <sstream>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

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
    : m_luaState(0)
    , m_visible(false)
    , m_window(0)
    , m_codePane(0)
    , m_outputBox(0)
{
}

ScriptEditor::~ScriptEditor()
{
}

void ScriptEditor::initialize(LuaState* luaState)
{
    if (m_window != nullptr)
    {
        logToFile("ScriptEditor: Already initialized - skipping");
        return;
    }
    m_luaState = luaState;

    if (m_luaState)
    {
        lua_State* L = m_luaState->getState();
        lua_pushcfunction(L, lua_customPrint);
        lua_setglobal(L, "print");
    }

    MyGUI::Gui* gui = MyGUI::Gui::getInstancePtr();
    if (!gui)
        return;

    const int W     = 800;
    const int H     = 600;
    const int PAD   = 4;
    const int BTN_H = 30;
    const int BTN_W = 80;
    const int OUT_H = 200;

    m_window = gui->createWidget<MyGUI::Window>(
        "Kenshi_WindowCX",
        50, 50, W, H,
        MyGUI::Align::Default,
        "Window",
        "KenshiLuaEditor");

    m_window->setCaption("KenshiLua Script Editor");
    m_window->setVisible(false);
    m_window->eventWindowButtonPressed += MyGUI::newDelegate(this, &ScriptEditor::onWindowButtonPressed);

    MyGUI::Widget* client = m_window->getClientWidget();

    const int clientW = client->getWidth();
    const int clientH = client->getHeight();

    int btnX = PAD;
    const int btnY = PAD;

    struct ButtonFactory
    {
        static MyGUI::Button* Create(
            MyGUI::Widget* client,
            int& btnX,
            int btnY,
            int BTN_W,
            int BTN_H,
            int PAD,
            const std::string& caption,
            const std::string& name,
            MyGUI::delegates::CDelegate1<MyGUI::Widget*>::IDelegate* handler)
        {
            MyGUI::Button* b = client->createWidget<MyGUI::Button>(
                "Kenshi_Button1",
                btnX, btnY, BTN_W, BTN_H,
                MyGUI::Align::Left | MyGUI::Align::Top,
                name);

            b->setCaption(caption);
            b->eventMouseButtonClick += handler;

            btnX += BTN_W + PAD;
            return b;
        }
    };

    ButtonFactory::Create(client, btnX, btnY, BTN_W, BTN_H, PAD, "Run",   "RunButton",   MyGUI::newDelegate(this, &ScriptEditor::onRunClicked));
    ButtonFactory::Create(client, btnX, btnY, BTN_W, BTN_H, PAD, "Open",  "OpenButton",  MyGUI::newDelegate(this, &ScriptEditor::onOpenClicked));
    ButtonFactory::Create(client, btnX, btnY, BTN_W, BTN_H, PAD, "Save",  "SaveButton",  MyGUI::newDelegate(this, &ScriptEditor::onSaveClicked));
    ButtonFactory::Create(client, btnX, btnY, BTN_W + 30, BTN_H, PAD, "Save As", "SaveAsButton", MyGUI::newDelegate(this, &ScriptEditor::onSaveAsClicked));
    ButtonFactory::Create(client, btnX, btnY, BTN_W, BTN_H, PAD, "Clear", "ClearButton", MyGUI::newDelegate(this, &ScriptEditor::onClearClicked));

    std::string editBoxSkin = "Kenshi_ScriptEditor_EditBox";

    MyGUI::ResourceManager* res = MyGUI::ResourceManager::getInstancePtr();
    if (!res->load("Kenshi_ScriptEditor_EditBox.xml"))
        logToFile("Kenshi_ScriptEditor_EditBox.xml not found.");

    const int editorY = BTN_H + PAD * 2;
    const int editorH = clientH - editorY - OUT_H - PAD * 3;

    // input editbox
    m_codePane = client->createWidget<MyGUI::EditBox>(
        editBoxSkin,
        PAD, editorY,
        clientW - PAD * 2,
        editorH,
        MyGUI::Align::Stretch,
        "KenshiLuaCode");

    m_codePane->setEditMultiLine(true);
    m_codePane->setVisibleVScroll(true);
    m_codePane->setVisibleHScroll(true);
    m_codePane->setMaxTextLength(MyGUI::ITEM_NONE);

    const int outputY = editorY + editorH + PAD;

    // output editbox
    m_outputBox = client->createWidget<MyGUI::EditBox>(
        editBoxSkin,
        PAD, outputY,
        clientW - PAD * 2,
        OUT_H,
        MyGUI::Align::Stretch,
        "KenshiLuaOutput");

    m_outputBox->setEditMultiLine(true);
    m_outputBox->setEditReadOnly(true);

    m_outputBox->setNeedMouseFocus(true);
    m_outputBox->setNeedKeyFocus(true);

    m_outputBox->setVisibleVScroll(true);
    m_outputBox->setVisibleHScroll(true);
    m_outputBox->setMaxTextLength(MyGUI::ITEM_NONE);

    logToFile("ScriptEditor: initialized.");
}

void ScriptEditor::shutdown()
{
    m_window = 0;
}

void ScriptEditor::toggle()
{
    if (!m_window)
        return;

    bool visible = !m_window->getVisible();
    m_window->setVisible(visible);
    m_visible = visible;

    if (visible && m_codePane)
        MyGUI::InputManager::getInstance().setKeyFocusWidget(m_codePane);
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

void ScriptEditor::onWindowButtonPressed(MyGUI::Window* sender, const std::string& name)
{
    if (name == "close")
    {
        sender->setVisible(false);
        m_visible = false;
        MyGUI::InputManager::getInstance().resetKeyFocusWidget();
        return;
    }
}

} // namespace KenshiLua
