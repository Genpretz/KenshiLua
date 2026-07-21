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


#include <Windows.h>
#include <commdlg.h>
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

        std::string openFileDialog(
            const std::string& title,
            const char* filter,
            const std::string& defaultExt,
            const std::string& currentPath)
        {
            char filename[MAX_PATH] = "";
            if (!currentPath.empty())
            {
                strncpy_s(filename, currentPath.c_str(), MAX_PATH - 1);
            }

            OPENFILENAMEA ofn = {};
            ofn.lStructSize = sizeof(ofn);
            ofn.lpstrFilter = filter;
            ofn.lpstrFile = filename;
            ofn.nMaxFile = MAX_PATH;
            ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR;
            ofn.lpstrDefExt = defaultExt.c_str();
            ofn.lpstrTitle = title.c_str();

            return GetOpenFileNameA(&ofn) ? std::string(filename) : "";
        }

        std::string saveFileDialog(
            const std::string& title,
            const char* filter,
            const std::string& defaultExt,
            const std::string& defaultFilename,
            const std::string& currentPath)
        {
            char filename[MAX_PATH] = "";
            if (!defaultFilename.empty())
            {
                strncpy_s(filename, defaultFilename.c_str(), MAX_PATH - 1);
            }
            else if (!currentPath.empty())
            {
                strncpy_s(filename, currentPath.c_str(), MAX_PATH - 1);
            }

            OPENFILENAMEA ofn = {};
            ofn.lStructSize = sizeof(ofn);
            ofn.lpstrFilter = filter;
            ofn.lpstrFile = filename;
            ofn.nMaxFile = MAX_PATH;
            ofn.Flags = OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR;
            ofn.lpstrDefExt = defaultExt.c_str();
            ofn.lpstrTitle = title.c_str();

            return GetSaveFileNameA(&ofn) ? std::string(filename) : "";
        }
    } // namespace GuiHelpers

	// ---------------------------------------------------------------------------
	// GuiManager (Singleton Manager) Implementation
	// ---------------------------------------------------------------------------

	static GuiManager* s_instance = 0;

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
		GuiManager::get().appendOutput(msg);
		return 0;
	}

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
			logToFile("GuiManager: MyGUI singleton not yet available in requestInitialize");
		}
	}

	void GuiManager::updateLuaState(LuaState* luaState)
	{
		m_luaState = luaState;
		if (m_luaState)
		{
			lua_State* L = m_luaState->getState();
			lua_pushcfunction(L, lua_customPrint);
			lua_setglobal(L, "print");
		}
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

			if (!Config::get().isStartMinimized())
			{
				setVisible(true);
			}
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

	void GuiManager::shutdown()
	{
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
			setVisible(!m_hub->getVisible());
		}
	}

	void GuiManager::setVisible(bool visible)
	{
		if (m_hub)
		{
			m_hub->setVisible(visible);
			m_visible = visible;
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

		if (m_editor && m_editor->getVisible())
			m_editor->appendOutput(text);
		if (m_console && m_console->getVisible())
			m_console->appendOutput(text);
	}

	void GuiManager::clearOutput()
	{
		if (m_editor)
			m_editor->clearOutput();
		if (m_console)
			m_console->clear();
	}

} // namespace KenshiLua
