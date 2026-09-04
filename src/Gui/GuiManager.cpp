#include "pch.h"
#include "Gui/GuiManager.h"
#include "Gui/KenshiLua_Hub.h"
#include "Gui/KenshiLua_ScriptEditor.h"
#include "Gui/KenshiLua_Console.h"
#include "Gui/KenshiLua_LogViewer.h"
#include "Gui/KenshiLua_ScriptManager.h"
#include "Gui/KenshiLua_Settings.h"
#include "Lua/LuaState.h"
#include "Config.h"
#include "Logger.h"


#include "Gui/GuiHelpers.h"
#include "FileWatcher.h"
#include <Windows.h>
#include <kenshi/InputHandler.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
	// ---------------------------------------------------------------------------
	// GuiManager (Singleton Manager) Implementation
	// ---------------------------------------------------------------------------

	static GuiManager* s_instance = 0;

	GuiManager& GuiManager::get()
	{
		static GuiManager inst;
		s_instance = &inst;
		return inst;
	}

	GuiManager::GuiManager()
		: m_luaState(nullptr)
		, m_pendingLuaState(nullptr)
		, m_initialized(false)
		, m_visible(false)
		, m_activeOutputTarget(nullptr)
		, m_hub(nullptr)
		, m_editor(nullptr)
		, m_console(nullptr)
		, m_logViewer(nullptr)
		, m_scriptManager(nullptr)
		, m_settings(nullptr)
	{
	}

	GuiManager::~GuiManager()
	{
		shutdown();
	}

	void GuiManager::requestInitialize(LuaState* luaState)
	{
		if (m_initialized || m_pendingLuaState != nullptr)
		{
			logToFile("GuiManager: Already initialized or initialization pending - ignoring request");
			return;
		}
		m_pendingLuaState = luaState;

		MyGUI::Gui* gui = MyGUI::Gui::getInstancePtr();
		if (gui)
		{
			gui->eventFrameStart += MyGUI::newDelegate(this, &GuiManager::initFrameHandler);
			logToFile("GuiManager: Subscribed to eventFrameStart");
		}
		else
		{
			logToFileWarn("GuiManager: MyGUI singleton not yet available in requestInitialize");
		}
	}

	void GuiManager::updateLuaState(LuaState* luaState)
	{
		m_luaState = luaState;
	}

	void GuiManager::initFrameHandler(float)
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
			MyGUI::newDelegate(this, &GuiManager::initFrameHandler);

		m_luaState = m_pendingLuaState;

		MyGUI::ResourceManager* res = MyGUI::ResourceManager::getInstancePtr();
		if (!res->load("Kenshi_ScriptEditor_EditBox.xml"))
			logToFileWarn("Kenshi_ScriptEditor_EditBox.xml not found.");

		try
		{
			m_hub = new KenshiLua_Hub();
			m_editor = new KenshiLua_ScriptEditor();
			m_console = new KenshiLua_Console();
			m_logViewer = new KenshiLua_LogViewer();
			m_scriptManager = new KenshiLua_ScriptManager();
			m_settings = new KenshiLua_Settings();

			m_initialized = true;


			if (!Config::get().isStartMinimized())
			{
				setVisible(true);
			}

			gui->eventFrameStart += MyGUI::newDelegate(this, &GuiManager::onFrameStart);
		}
		catch (const std::exception& e)
		{
			logToFileErrorf("ERROR during UI initialization: %s", e.what());
		}
		catch (...)
		{
			logToFileError("ERROR during UI initialization (unknown exception)");
		}
	}

	void GuiManager::onFrameStart(float)
	{
		if (m_luaState && m_luaState->isValid())
		{
			FileWatcher::get().update(m_luaState->getState());
		}
	}

	void GuiManager::shutdown()
	{
		MyGUI::Gui* gui = MyGUI::Gui::getInstancePtr();
		if (gui)
		{
			gui->eventFrameStart -= MyGUI::newDelegate(this, &GuiManager::onFrameStart);
		}

		m_initialized = false;
		delete m_hub; m_hub = nullptr;
		delete m_editor; m_editor = nullptr;
		delete m_console; m_console = nullptr;
		delete m_logViewer; m_logViewer = nullptr;
		delete m_scriptManager; m_scriptManager = nullptr;
		delete m_settings; m_settings = nullptr;
	}

	void GuiManager::toggle()
	{
		if (m_initialized && m_hub)
		{
			m_visible = !m_visible;
			m_hub->setVisible(m_visible);
		}
	}

	void GuiManager::setVisible(bool visible)
	{
		m_visible = visible;
		if (m_hub)
		{
			m_hub->setVisible(visible);
		}
	}

	bool GuiManager::isInitialized() const
	{
		return m_initialized;
	}

	void GuiManager::checkKeyboardShortcut(OIS::KeyCode key, InputHandler* thisptr)
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

	void GuiManager::appendOutput(const std::string& text)
	{
		logToFile(text);

		if (m_activeOutputTarget == m_editor)
		{
			if (m_editor && m_editor->getVisible())
				m_editor->appendOutput(text);
		}
		else
		{
			if (m_console && m_console->getVisible())
				m_console->appendOutput(text);
		}
	}

	void GuiManager::clearOutput()
	{
		if (m_editor)
			m_editor->clearOutput();
		if (m_console)
			m_console->clear();
	}


} // namespace KenshiLua
