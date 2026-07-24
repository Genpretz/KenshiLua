#include "pch.h"
#include "KenshiLua_ScriptEditor.h"
#include "Gui/GuiManager.h"
#include "Logger.h"
#include "Config.h"
#include "Lua/LuaState.h"
#include <fstream>
#include <sstream>
#include "Plugin.h"


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
		: m_lastInputVScrollPos(0), m_lastOutputVScrollPos(0)
		, mEdgeHideEnabled(false)
	{
		initialiseByAttributes(this, _parent);
		mKenshiLua_ScriptEditorWindow = mMainWidget->castType<MyGUI::Window>(false);

		if (mScriptEditor_RunButtonButton)
			mScriptEditor_RunButtonButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_ScriptEditor::onRunClicked);
		if (mScriptEditor_StopButtonButton)
			mScriptEditor_StopButtonButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_ScriptEditor::onStopClicked);
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

		if (mScriptEditor_InputGutterEditBox)
		{
			mScriptEditor_InputGutterEditBox->setMaxTextLength(MyGUI::ITEM_NONE);
			mScriptEditor_InputGutterEditBox->setEditMultiLine(true);
			mScriptEditor_InputGutterEditBox->setEditReadOnly(true);
			mScriptEditor_InputGutterEditBox->setTextAlign(MyGUI::Align::Right | MyGUI::Align::Top);
		}
		if (mScriptEditor_OutputGutterEditBox)
		{
			mScriptEditor_OutputGutterEditBox->setMaxTextLength(MyGUI::ITEM_NONE);
			mScriptEditor_OutputGutterEditBox->setEditMultiLine(true);
			mScriptEditor_OutputGutterEditBox->setEditReadOnly(true);
			mScriptEditor_OutputGutterEditBox->setTextAlign(MyGUI::Align::Right | MyGUI::Align::Top);
		}

		if (mScriptEditor_InputBoxEditBox)
		{
			mScriptEditor_InputBoxEditBox->setMaxTextLength(MyGUI::ITEM_NONE);
			mScriptEditor_InputBoxEditBox->setEditMultiLine(true);
			mScriptEditor_InputBoxEditBox->eventEditTextChange += MyGUI::newDelegate(this, &KenshiLua_ScriptEditor::onInputTextChanged);
		}
		if (mScriptEditor_OutputBoxEditBox)
		{
			mScriptEditor_OutputBoxEditBox->setMaxTextLength(MyGUI::ITEM_NONE);
			mScriptEditor_OutputBoxEditBox->setEditMultiLine(true);
		}

		MyGUI::Gui* gui = MyGUI::Gui::getInstancePtr();
		if (gui)
		{
			gui->eventFrameStart += MyGUI::newDelegate(this, &KenshiLua_ScriptEditor::onFrameStart);
		}

		updateInputGutter();
		updateOutputGutter();

		setVisible(false);
	}

	KenshiLua_ScriptEditor::~KenshiLua_ScriptEditor()
	{
		MyGUI::Gui* gui = MyGUI::Gui::getInstancePtr();
		if (gui)
		{
			gui->eventFrameStart -= MyGUI::newDelegate(this, &KenshiLua_ScriptEditor::onFrameStart);
		}
	}

	void KenshiLua_ScriptEditor::onFrameStart(float)
	{
		if (!getVisible())
			return;

		if (mScriptEditor_InputBoxEditBox && mScriptEditor_InputGutterEditBox)
		{
			size_t currentPos = mScriptEditor_InputBoxEditBox->getVScrollPosition();
			if (currentPos != m_lastInputVScrollPos)
			{
				m_lastInputVScrollPos = currentPos;
				mScriptEditor_InputGutterEditBox->setVScrollPosition(currentPos);
			}
		}

		if (mScriptEditor_OutputBoxEditBox && mScriptEditor_OutputGutterEditBox)
		{
			size_t currentPos = mScriptEditor_OutputBoxEditBox->getVScrollPosition();
			if (currentPos != m_lastOutputVScrollPos)
			{
				m_lastOutputVScrollPos = currentPos;
				mScriptEditor_OutputGutterEditBox->setVScrollPosition(currentPos);
			}
		}
	}

	void KenshiLua_ScriptEditor::updateInputGutter()
	{
		if (!mScriptEditor_InputBoxEditBox || !mScriptEditor_InputGutterEditBox)
		{
			return;
		}

		std::string text = mScriptEditor_InputBoxEditBox->getCaption().asUTF8();
		size_t lineCount = 1;
		for (size_t i = 0; i < text.size(); ++i)
		{
			if (text[i] == '\n') ++lineCount;
		}

		std::ostringstream ss;
		for (size_t i = 1; i <= lineCount; ++i)
		{
			ss << i << "\n";
		}

		std::string resultStr = ss.str();
		mScriptEditor_InputGutterEditBox->setCaption(MyGUI::UString(resultStr));
		mScriptEditor_InputGutterEditBox->setVScrollPosition(mScriptEditor_InputBoxEditBox->getVScrollPosition());
	}

	void KenshiLua_ScriptEditor::updateOutputGutter()
	{
		if (!mScriptEditor_OutputBoxEditBox || !mScriptEditor_OutputGutterEditBox)
		{
			return;
		}

		std::string text = mScriptEditor_OutputBoxEditBox->getCaption().asUTF8();
		size_t lineCount = 1;
		for (size_t i = 0; i < text.size(); ++i)
		{
			if (text[i] == '\n') ++lineCount;
		}

		std::ostringstream ss;
		for (size_t i = 1; i <= lineCount; ++i)
		{
			ss << i << "\n";
		}

		std::string resultStr = ss.str();
		mScriptEditor_OutputGutterEditBox->setCaption(MyGUI::UString(resultStr));
		mScriptEditor_OutputGutterEditBox->setVScrollPosition(mScriptEditor_OutputBoxEditBox->getVScrollPosition());
	}

	void KenshiLua_ScriptEditor::onInputTextChanged(MyGUI::EditBox*)
	{
		updateInputGutter();
	}

	void KenshiLua_ScriptEditor::setVisible(bool visible)
	{
		if (mKenshiLua_ScriptEditorWindow)
		{
			mKenshiLua_ScriptEditorWindow->setVisible(visible);
			if (visible)
			{
				MyGUI::LayerManager::getInstance().upLayerItem(mKenshiLua_ScriptEditorWindow);
				if (mScriptEditor_InputBoxEditBox)
					MyGUI::InputManager::getInstance().setKeyFocusWidget(mScriptEditor_InputBoxEditBox);
				updateInputGutter();
				updateOutputGutter();
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
		updateOutputGutter();
	}

	void KenshiLua_ScriptEditor::clearOutput()
	{
		if (mScriptEditor_OutputBoxEditBox)
			mScriptEditor_OutputBoxEditBox->setCaption("");
		updateOutputGutter();
	}

	void KenshiLua_ScriptEditor::onWindowButtonPressed(MyGUI::Window* sender, const std::string& name)
	{
		if (name == "close")
		{
			setVisible(false);
			MyGUI::InputManager::getInstance().resetKeyFocusWidget();
		}
		else if (name == "minimize")
		{
			mEdgeHideEnabled = !mEdgeHideEnabled;
			MyGUI::ControllerManager::getInstance().removeItem(sender);
			if (mEdgeHideEnabled)
			{
				MyGUI::ControllerItem* item = MyGUI::ControllerManager::getInstance().createItem("ControllerEdgeHide");
				if (item)
				{
					MyGUI::ControllerManager::getInstance().addItem(sender, item);
				}
			}
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
				logToFileError("Lua error: " + e);
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

	void KenshiLua_ScriptEditor::onStopClicked(MyGUI::Widget*)
	{
		appendOutput("=== Stopping Scripts (Restarting Lua Runtime) ===\n");
		logToFile("ScriptEditor: Restarting KenshiLua runtime to unload scripts...");

		void* hModule = Plugin::get().getDllModule();
		Plugin::get().shutdown();
		Plugin::get().initialize(hModule);
		Plugin::get().start();

		auto editor = GuiManager::get().getEditor();
		if (editor)
		{
			editor->setVisible(true);
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

		updateInputGutter();
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
		updateInputGutter();
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

