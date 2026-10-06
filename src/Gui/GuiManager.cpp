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
#include <kenshi/InputHandler.h>
#include <MyGUI.h>
#include <algorithm>
#include <vector>


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
		, m_hubHomeLeft(0)
		, m_hubHomeTop(0)
		, m_hubHomeWidth(0)
		, m_hubHomeHeight(0)
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

			if (MyGUI::Window* hubWindow = m_hub->getWindow())
			{
				const MyGUI::IntCoord home = hubWindow->getAbsoluteCoord();
				m_hubHomeLeft = home.left;
				m_hubHomeTop = home.top;
				m_hubHomeWidth = home.width;
				m_hubHomeHeight = home.height;
			}
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
			// Use the window's actual visibility rather than m_visible: the Hub's close
			// button hides the window without updating m_visible, which made the next
			// shortcut press hide an already hidden window.
			bool visible = m_hub->getVisible();

			// An edge-hidden Hub is visible but tucked mostly off-screen. Bring it out
			// instead of hiding it: the edge-hide controller slides a window onto the
			// screen while it has keyboard focus, which setVisible(true) gives it.
			MyGUI::Window* window = m_hub->getWindow();
			if (visible && window && m_hub->isEdgeHideEnabled())
			{
				const MyGUI::IntCoord coord = window->getAbsoluteCoord();
				const MyGUI::IntSize view = MyGUI::RenderManager::getInstance().getViewSize();
				bool partlyOffScreen = coord.left < 0 || coord.top < 0 ||
					coord.right() > view.width || coord.bottom() > view.height;
				if (partlyOffScreen)
				{
					setVisible(true);
					return;
				}
			}

			setVisible(!visible);
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

	void GuiManager::placeWindow(MyGUI::Window* target)
	{
		if (!target || m_hubHomeWidth <= 0)
			return;

		const MyGUI::IntSize view = MyGUI::RenderManager::getInstance().getViewSize();
		const MyGUI::IntSize size = target->getSize();

		// Everything the new window must not cover: the Hub, and every other open window.
		// Open windows are clipped to the screen, so an edge-hidden window only blocks the
		// sliver that is still showing.
		std::vector<MyGUI::IntCoord> taken;
		taken.push_back(MyGUI::IntCoord(m_hubHomeLeft, m_hubHomeTop, m_hubHomeWidth, m_hubHomeHeight));

		MyGUI::Window* others[5] = {
			m_editor ? m_editor->getWindow() : nullptr,
			m_console ? m_console->getWindow() : nullptr,
			m_logViewer ? m_logViewer->getWindow() : nullptr,
			m_scriptManager ? m_scriptManager->getWindow() : nullptr,
			m_settings ? m_settings->getWindow() : nullptr
		};
		for (int i = 0; i < 5; ++i)
		{
			if (!others[i] || others[i] == target || !others[i]->getVisible())
				continue;

			const MyGUI::IntCoord c = others[i]->getAbsoluteCoord();
			const int left = std::max(c.left, 0);
			const int top = std::max(c.top, 0);
			const int right = std::min(c.right(), view.width);
			const int bottom = std::min(c.bottom(), view.height);
			if (right > left && bottom > top)
				taken.push_back(MyGUI::IntCoord(left, top, right - left, bottom - top));
		}

		// Candidate corners: the Hub's right edge, then for each taken rectangle the spot
		// against its right edge, the spot below it, and the spot below it next to the Hub.
		// The topmost, then leftmost, candidate that fits is used, which fills a row from
		// left to right before starting the next one.
		const int homeRight = m_hubHomeLeft + m_hubHomeWidth;
		std::vector<MyGUI::IntPoint> candidates;
		candidates.push_back(MyGUI::IntPoint(homeRight, m_hubHomeTop));
		for (size_t i = 0; i < taken.size(); ++i)
		{
			candidates.push_back(MyGUI::IntPoint(taken[i].right(), taken[i].top));
			candidates.push_back(MyGUI::IntPoint(taken[i].left, taken[i].bottom()));
			candidates.push_back(MyGUI::IntPoint(homeRight, taken[i].bottom()));
		}

		bool found = false;
		MyGUI::IntPoint best(homeRight, m_hubHomeTop);
		for (size_t i = 0; i < candidates.size(); ++i)
		{
			const MyGUI::IntPoint& p = candidates[i];
			if (p.left < 0 || p.top < 0 || p.left + size.width > view.width || p.top + size.height > view.height)
				continue;

			bool overlaps = false;
			for (size_t j = 0; j < taken.size(); ++j)
			{
				const MyGUI::IntCoord& t = taken[j];
				if (p.left < t.right() && p.left + size.width > t.left &&
					p.top < t.bottom() && p.top + size.height > t.top)
				{
					overlaps = true;
					break;
				}
			}
			if (overlaps)
				continue;

			if (!found || p.top < best.top || (p.top == best.top && p.left < best.left))
			{
				best = p;
				found = true;
			}
		}

		// With no free spot the window opens against the Hub, on top of the others.
		target->setPosition(best);
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
