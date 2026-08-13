#include "pch.h"
#include "KenshiLua_Console.h"
#include "Gui/GuiManager.h"
#include "Logger.h"
#include "Lua/LuaState.h"

#include <lua.hpp>

namespace KenshiLua
{

	KenshiLua_Console::KenshiLua_Console(MyGUI::Widget* _parent)
		: mEdgeHideEnabled(false)
	{
		initialiseByAttributes(this, _parent);
		mKenshiLua_ConsoleRootWindow = mMainWidget->castType<MyGUI::Window>(false);

		if (mConsole_RunButtonButton)
			mConsole_RunButtonButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_Console::onRunClicked);
		if (mConsole_ClearButtonButton)
			mConsole_ClearButtonButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_Console::onClearClicked);

		if (mConsole_InputBoxEditBox)
			mConsole_InputBoxEditBox->eventEditSelectAccept += MyGUI::newDelegate(this, &KenshiLua_Console::onEditSelectAccept);

		if (mKenshiLua_ConsoleRootWindow)
			mKenshiLua_ConsoleRootWindow->eventWindowButtonPressed += MyGUI::newDelegate(this, &KenshiLua_Console::onWindowButtonPressed);

		if (mConsole_InputBoxEditBox)
			mConsole_InputBoxEditBox->setMaxTextLength(MyGUI::ITEM_NONE);
		if (mConsole_OutputBoxEditBox)
			mConsole_OutputBoxEditBox->setMaxTextLength(MyGUI::ITEM_NONE);

		setVisible(false);
	}

	KenshiLua_Console::~KenshiLua_Console()
	{
	}

	void KenshiLua_Console::setVisible(bool visible)
	{
		if (mKenshiLua_ConsoleRootWindow)
		{
			mKenshiLua_ConsoleRootWindow->setVisible(visible);
			if (visible)
			{
				MyGUI::LayerManager::getInstance().upLayerItem(mKenshiLua_ConsoleRootWindow);
				if (mConsole_InputBoxEditBox)
					MyGUI::InputManager::getInstance().setKeyFocusWidget(mConsole_InputBoxEditBox);
			}
		}
	}

	bool KenshiLua_Console::getVisible()
	{
		return mKenshiLua_ConsoleRootWindow ? mKenshiLua_ConsoleRootWindow->getVisible() : false;
	}

	void KenshiLua_Console::appendOutput(const std::string& text)
	{
		if (!mConsole_OutputBoxEditBox)
			return;

		mConsole_OutputBoxEditBox->addText(MyGUI::UString(GuiHelpers::EscapeMyGuiColourTags(text)));
		size_t length = mConsole_OutputBoxEditBox->getTextLength();
		mConsole_OutputBoxEditBox->setTextCursor(length);
	}

	void KenshiLua_Console::onEditSelectAccept(MyGUI::EditBox* sender)
	{
		onRunClicked(sender);
	}

	void KenshiLua_Console::clear()
	{
		if (mConsole_OutputBoxEditBox)
			mConsole_OutputBoxEditBox->setCaption("");
	}

	void KenshiLua_Console::onClearClicked(MyGUI::Widget* sender)
	{
		clear();
	}

	void KenshiLua_Console::onWindowButtonPressed(MyGUI::Window* sender, const std::string& name)
	{
		GuiHelpers::handleWindowButton(sender, name, mEdgeHideEnabled, mKenshiLua_ConsoleRootWindow);
	}

	void KenshiLua_Console::onRunClicked(MyGUI::Widget* sender)
	{
		if (!mConsole_InputBoxEditBox)
			return;

		std::string code = mConsole_InputBoxEditBox->getOnlyText().asUTF8();
		if (code.empty())
			return;

		GuiManager::get().setActiveOutputTarget(this);

		// Echo command to console output
		appendOutput("> " + code + "\n");
		mConsole_InputBoxEditBox->setCaption("");

		if (g_luaState)
		{
			lua_State* L = g_luaState->getState();
			int top = lua_gettop(L);

			// 1. Try running as "return [statement]" first
			std::string evalCode = "return " + code;
			if (luaL_loadbuffer(L, evalCode.c_str(), evalCode.size(), "<console>") == LUA_OK)
			{
				int preTop = lua_gettop(L) - 1;
				if (LuaState::pcallWithTraceback(L, 0, LUA_MULTRET, NULL))
				{
					int nres = lua_gettop(L) - preTop;
					for (int i = 1; i <= nres; ++i)
					{
						size_t len = 0;
						const char* res = luaL_tolstring(L, preTop + i, &len);
						if (res)
						{
							appendOutput(std::string(res, len) + "\n");
						}
						lua_pop(L, 1); // pop result of luaL_tolstring
					}
					lua_settop(L, top);
					GuiManager::get().setActiveOutputTarget(nullptr);
					return;
				}
			}

			// 2. If eval failed, fallback to normal block execution
			lua_settop(L, top);

			if (luaL_loadbuffer(L, code.c_str(), code.size(), "<console>") != LUA_OK)
			{
				const char* err = lua_tostring(L, -1);
				std::string e = err ? err : "(error)";
				appendOutput("ERROR: " + e + "\n");
				logToFileError("Lua console error: " + e);
			}
			else
			{
				int preTop = lua_gettop(L) - 1;
				std::string pcallErr;
				if (!LuaState::pcallWithTraceback(L, 0, LUA_MULTRET, &pcallErr))
				{
					appendOutput("ERROR: " + pcallErr + "\n");
					logToFileError("Lua console error: " + pcallErr);
				}
				else
				{
					int nres = lua_gettop(L) - preTop;
					for (int i = 1; i <= nres; ++i)
					{
						size_t len = 0;
						const char* res = luaL_tolstring(L, preTop + i, &len);
						if (res)
						{
							appendOutput(std::string(res, len) + "\n");
						}
						lua_pop(L, 1);
					}
				}
			}
			lua_settop(L, top);
		}
		else
		{
			appendOutput("ERROR: LuaState not initialized\n");
		}

		GuiManager::get().setActiveOutputTarget(nullptr);
	}

} // KenshiLua
