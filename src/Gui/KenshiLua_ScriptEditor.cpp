#include "pch.h"
#include "KenshiLua_ScriptEditor.h"
#include "Gui/GuiManager.h"
#include "Logger.h"
#include "Config.h"
#include "Lua/LuaState.h"
#include <fstream>
#include <sstream>


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

			lua_pushcfunction(L, LuaState::genericTraceback);
			int tracebackIdx = lua_gettop(L);

			if (luaL_loadbuffer(L, code.c_str(), code.size(), chunkName.c_str()) != LUA_OK ||
				lua_pcall(L, 0, LUA_MULTRET, tracebackIdx) != LUA_OK)
			{
				const char* err = lua_tostring(L, -1);
				std::string e = err ? err : "(error)";
				appendOutput("ERROR: " + e + "\n");
				logToFile("Lua error: " + e);
			}
			else
			{
				int nres = lua_gettop(L) - tracebackIdx;
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
		std::string path = GuiHelpers::openFileDialog("Open Lua Script", "Lua Files (*.lua)\0*.lua\0All Files (*.*)\0*.*\0", "lua", m_currentFilePath);
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
			? GuiHelpers::saveFileDialog("Save Lua Script", "Lua Files (*.lua)\0*.lua\0All Files (*.*)\0*.*\0", "lua", "", m_currentFilePath)
			: m_currentFilePath;

		if (path.empty())
			return;

		saveToFile(path);
	}

	void KenshiLua_ScriptEditor::onSaveAsClicked(MyGUI::Widget*)
	{
		if (!mScriptEditor_InputBoxEditBox)
			return;

		std::string path = GuiHelpers::saveFileDialog("Save Lua Script", "Lua Files (*.lua)\0*.lua\0All Files (*.*)\0*.*\0", "lua", "", m_currentFilePath);

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

} // KenshiLua

