#include "pch.h"
#include "KenshiLua_ScriptEditor.h"
#include "Gui/GuiHelpers.h"
#include "Logger.h"
#include "Config.h"
#include "Lua/LuaState.h"
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <commdlg.h>

#include <kenshi/InputHandler.h>

#include "KenshiLua_Hub.h"
#include "KenshiLua_Console.h"
#include "KenshiLua_LogViewer.h"
#include "KenshiLua_ScriptManager.h"
#include "KenshiLua_Settings.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

	// ---------------------------------------------------------------------------
	// File Dialogs (local helpers)
	// ---------------------------------------------------------------------------

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

	// ---------------------------------------------------------------------------
	// KenshiLua_ScriptEditor (UI panel) Implementation
	// ---------------------------------------------------------------------------

	KenshiLua_ScriptEditor::KenshiLua_ScriptEditor(MyGUI::Widget* _parent)
	{
		initialiseByAttributes(this, _parent);
		mKenshiLua_ScriptEditorWindow = mMainWidget->castType<MyGUI::Window>(false);
		logToFileDebugf("ScriptEditor initialization: mMainWidget=%p, mKenshiLua_ScriptEditorWindow=%p", mMainWidget, mKenshiLua_ScriptEditorWindow);

		if (mScriptEditor_RunButtonButton)
			mScriptEditor_RunButtonButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_ScriptEditor::onRunClicked);
		if (mScriptEditor_OpenButtonButton)
			mScriptEditor_OpenButtonButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_ScriptEditor::onOpenClicked);
		if (mScriptEditor_SaveButtonButton)
			mScriptEditor_SaveButtonButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_ScriptEditor::onSaveClicked);
		if (mScriptEditor_SaveAsButtonButton)
			mScriptEditor_SaveAsButtonButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_ScriptEditor::onSaveAsClicked);
		if (mScriptEditor_ClearButtonButton)
			mScriptEditor_ClearButtonButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_ScriptEditor::onClearClicked);

		if (mKenshiLua_ScriptEditorWindow)
			mKenshiLua_ScriptEditorWindow->eventWindowButtonPressed += MyGUI::newDelegate(this, &KenshiLua_ScriptEditor::onWindowButtonPressed);

		if (mScriptEditor_InputBoxEditBox)
			mScriptEditor_InputBoxEditBox->setMaxTextLength(MyGUI::ITEM_NONE);
		if (mScriptEditor_OutputBoxEditBox)
			mScriptEditor_OutputBoxEditBox->setMaxTextLength(MyGUI::ITEM_NONE);

		setVisible(false);
	}

	KenshiLua_ScriptEditor::~KenshiLua_ScriptEditor()
	{
	}

	void KenshiLua_ScriptEditor::setVisible(bool visible)
	{
		logToFileDebugf("ScriptEditor: setVisible(%d) called, mKenshiLua_ScriptEditorWindow=%p", visible, mKenshiLua_ScriptEditorWindow);
		if (mKenshiLua_ScriptEditorWindow)
		{
			mKenshiLua_ScriptEditorWindow->setVisible(visible);
			if (visible)
			{
				MyGUI::LayerManager::getInstance().upLayerItem(mKenshiLua_ScriptEditorWindow);
				if (mScriptEditor_InputBoxEditBox)
					MyGUI::InputManager::getInstance().setKeyFocusWidget(mScriptEditor_InputBoxEditBox);
			}
		}
	}

	bool KenshiLua_ScriptEditor::getVisible()
	{
		return mKenshiLua_ScriptEditorWindow ? mKenshiLua_ScriptEditorWindow->getVisible() : false;
	}

	void KenshiLua_ScriptEditor::appendOutput(const std::string& text)
	{
		if (!mScriptEditor_OutputBoxEditBox)
			return;

		mScriptEditor_OutputBoxEditBox->addText(MyGUI::UString(text));
		size_t length = mScriptEditor_OutputBoxEditBox->getTextLength();
		mScriptEditor_OutputBoxEditBox->setTextCursor(length);
	}

	void KenshiLua_ScriptEditor::clearOutput()
	{
		if (mScriptEditor_OutputBoxEditBox)
			mScriptEditor_OutputBoxEditBox->setCaption("");
	}

	void KenshiLua_ScriptEditor::onWindowButtonPressed(MyGUI::Window*, const std::string& name)
	{
		if (name == "close")
		{
			setVisible(false);
			MyGUI::InputManager::getInstance().resetKeyFocusWidget();
		}
	}

	void KenshiLua_ScriptEditor::onRunClicked(MyGUI::Widget*)
	{
		if (!mScriptEditor_InputBoxEditBox)
			return;

		std::string code = mScriptEditor_InputBoxEditBox->getCaption().asUTF8();

		if (code.empty())
		{
			appendOutput("(editor is empty)\n");
			return;
		}

		const std::string label = m_currentFilePath.empty() ? "<editor>" : m_currentFilePath;

		appendOutput("=== Running: " + label + " ===\n");
		
		if (g_luaState)
		{
			lua_State* L = g_luaState->getState();
			int top = lua_gettop(L);
			
			std::string chunkName = "<editor>";
			if (!m_currentFilePath.empty())
			{
				size_t lastSlash = m_currentFilePath.find_last_of("\\/");
				if (lastSlash != std::string::npos)
					chunkName = "@" + m_currentFilePath.substr(lastSlash + 1);
				else
					chunkName = "@" + m_currentFilePath;
			}

			if (luaL_loadbuffer(L, code.c_str(), code.size(), chunkName.c_str()) != LUA_OK ||
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

	void KenshiLua_ScriptEditor::onOpenClicked(MyGUI::Widget*)
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

		mScriptEditor_InputBoxEditBox->setCaption(MyGUI::UString(ss.str()));
		m_currentFilePath = path;

		appendOutput("Loaded: " + path + "\n");
	}

	void KenshiLua_ScriptEditor::onSaveClicked(MyGUI::Widget*)
	{
		if (!mScriptEditor_InputBoxEditBox)
			return;

		std::string path = m_currentFilePath.empty()
			? SaveFileDialog(m_currentFilePath)
			: m_currentFilePath;

		if (path.empty())
			return;

		saveToFile(path);
	}

	void KenshiLua_ScriptEditor::onSaveAsClicked(MyGUI::Widget*)
	{
		if (!mScriptEditor_InputBoxEditBox)
			return;

		std::string path = SaveFileDialog(m_currentFilePath);

		if (path.empty())
			return;

		saveToFile(path);
	}

	void KenshiLua_ScriptEditor::onClearClicked(MyGUI::Widget*)
	{
		if (mScriptEditor_InputBoxEditBox)
			mScriptEditor_InputBoxEditBox->setCaption("");

		m_currentFilePath.clear();
		clearOutput();
	}

	bool KenshiLua_ScriptEditor::saveToFile(const std::string& path)
	{
		std::ofstream f(path.c_str(), std::ios::binary);
		if (!f.is_open())
		{
			appendOutput("Failed to save: " + path + "\n");
			return false;
		}

		f << mScriptEditor_InputBoxEditBox->getCaption().asUTF8();
		m_currentFilePath = path;

		appendOutput("Saved: " + path + "\n");
		return true;
	}

	// ---------------------------------------------------------------------------
	// ScriptEditor (Singleton Manager) Implementation
	// ---------------------------------------------------------------------------

	static ScriptEditor* s_instance = 0;

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
		, m_hub(nullptr)
		, m_editor(nullptr)
		, m_console(nullptr)
		, m_logViewer(nullptr)
		, m_scriptManager(nullptr)
		, m_settings(nullptr)
	{
	}

	ScriptEditor::~ScriptEditor()
	{
		shutdown();
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

		//logToFile("Initializing Layout Editor UI Suite");

		m_luaState = m_pendingLuaState;

		if (m_luaState)
		{
			lua_State* L = m_luaState->getState();
			lua_pushcfunction(L, lua_customPrint);
			lua_setglobal(L, "print");
		}

		MyGUI::ResourceManager* res = MyGUI::ResourceManager::getInstancePtr();
		if (!res->load("Kenshi_ScriptEditor_EditBox.xml"))
			logToFile("Kenshi_ScriptEditor_EditBox.xml not found.");

		try
		{
			m_hub = new KenshiLua_Hub();
			m_editor = new KenshiLua_ScriptEditor();
			m_console = new KenshiLua_Console();
			m_logViewer = new KenshiLua_LogViewer();
			m_scriptManager = new KenshiLua_ScriptManager();
			m_settings = new KenshiLua_Settings();

			m_initialized = true;
			//logToFile("Layout Editor UI Suite successfully initialized.");
		}
		catch (const std::exception& e)
		{
			logToFilef("ERROR during UI initialization: %s", e.what());
		}
		catch (...)
		{
			logToFile("ERROR during UI initialization (unknown exception)");
		}
	}

	void ScriptEditor::shutdown()
	{
		m_initialized = false;
		delete m_hub; m_hub = nullptr;
		delete m_editor; m_editor = nullptr;
		delete m_console; m_console = nullptr;
		delete m_logViewer; m_logViewer = nullptr;
		delete m_scriptManager; m_scriptManager = nullptr;
		delete m_settings; m_settings = nullptr;
	}

	void ScriptEditor::toggle()
	{
		if (m_initialized && m_hub)
		{
			setVisible(!m_hub->getVisible());
		}
	}

	void ScriptEditor::setVisible(bool visible)
	{
		if (m_hub)
		{
			m_hub->setVisible(visible);
			m_visible = visible;
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

		if (m_editor && m_editor->getVisible())
			m_editor->appendOutput(text);
		if (m_console && m_console->getVisible())
			m_console->appendOutput(text);
	}

	void ScriptEditor::clearOutput()
	{
		if (m_editor)
			m_editor->clearOutput();
		if (m_console)
			m_console->clear();
	}

} // KenshiLua

