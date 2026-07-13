#include "pch.h"
#include "KenshiLua_Hub.h"
#include "KenshiLua_ScriptEditor.h"
#include "KenshiLua_Console.h"
#include "KenshiLua_LogViewer.h"
#include "KenshiLua_ScriptManager.h"
#include "KenshiLua_Settings.h"
#include "Gui/GuiManager.h"
#include "Plugin.h"
#include "Logger.h"

namespace KenshiLua
{

	KenshiLua_Hub::KenshiLua_Hub(MyGUI::Widget* _parent)
	{
		initialiseByAttributes(this, _parent);
		mKenshiLua_HubRootWindow = mMainWidget->castType<MyGUI::Window>(false);

		if (mHubBtn_ScriptEditorButton)
			mHubBtn_ScriptEditorButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_Hub::onBtnScriptEditor);
		if (mHubBtn_ConsoleButton)
			mHubBtn_ConsoleButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_Hub::onBtnConsole);
		if (mHubBtn_LogViewerButton)
			mHubBtn_LogViewerButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_Hub::onBtnLogViewer);
		if (mHubBtn_ScriptManagerButton)
			mHubBtn_ScriptManagerButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_Hub::onBtnScriptManager);
		if (mHubBtn_SettingsButton)
			mHubBtn_SettingsButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_Hub::onBtnSettings);
		if (mKenshiLua_HubRootWindow)
			mKenshiLua_HubRootWindow->eventWindowButtonPressed += MyGUI::newDelegate(this, &KenshiLua_Hub::onWindowButtonPressed);

		setVisible(false);
	}

	KenshiLua_Hub::~KenshiLua_Hub()
	{
	}

	void KenshiLua_Hub::setVisible(bool visible)
	{
		if (mKenshiLua_HubRootWindow)
		{
			mKenshiLua_HubRootWindow->setVisible(visible);
			if (visible)
			{
				MyGUI::LayerManager::getInstance().upLayerItem(mKenshiLua_HubRootWindow);
			}
		}
	}

	bool KenshiLua_Hub::getVisible()
	{
		return mKenshiLua_HubRootWindow ? mKenshiLua_HubRootWindow->getVisible() : false;
	}

	void KenshiLua_Hub::onBtnScriptEditor(MyGUI::Widget* sender)
	{
		auto editor = GuiManager::get().getEditor();
		if (editor)
		{
			bool vis = editor->getVisible();
			editor->setVisible(!vis);
		}
	}

	void KenshiLua_Hub::onBtnConsole(MyGUI::Widget* sender)
	{
		auto console = GuiManager::get().getConsole();
		if (console)
		{
			bool vis = console->getVisible();
			console->setVisible(!vis);
		}
	}

	void KenshiLua_Hub::onBtnLogViewer(MyGUI::Widget* sender)
	{
		auto viewer = GuiManager::get().getLogViewer();
		if (viewer)
		{
			bool vis = viewer->getVisible();
			viewer->setVisible(!vis);
		}
	}

	void KenshiLua_Hub::onBtnScriptManager(MyGUI::Widget* sender)
	{
		auto manager = GuiManager::get().getScriptManager();
		if (manager)
		{
			bool vis = manager->getVisible();
			manager->setVisible(!vis);
		}
	}

	void KenshiLua_Hub::onBtnSettings(MyGUI::Widget* sender)
	{
		auto settings = GuiManager::get().getSettings();
		if (settings)
		{
			bool vis = settings->getVisible();
			settings->setVisible(!vis);
		}
	}

	void KenshiLua_Hub::onWindowButtonPressed(MyGUI::Window* sender, const std::string& name)
	{
		if (name == "close")
		{
			setVisible(false);
		}
	}
} // KenshiLua
