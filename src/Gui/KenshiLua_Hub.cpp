#include "pch.h"
#include "KenshiLua_Hub.h"
#include "KenshiLua_ScriptEditor.h"
#include "KenshiLua_Console.h"
#include "KenshiLua_LogViewer.h"
#include "KenshiLua_ScriptManager.h"
#include "KenshiLua_Settings.h"
#include "Gui/GuiHelpers.h"
#include "Plugin.h"
#include "Logger.h"

namespace KenshiLua
{

	KenshiLua_Hub::KenshiLua_Hub(MyGUI::Widget* _parent)
	{
		initialiseByAttributes(this, _parent);
		mKenshiLua_HubRootWindow = mMainWidget->castType<MyGUI::Window>(false);
		logToFileDebugf("Hub initialization: mMainWidget=%p, mKenshiLua_HubRootWindow=%p", mMainWidget, mKenshiLua_HubRootWindow);

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
		// if (mHubBtn_StopAllButton)
		// 	mHubBtn_StopAllButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_Hub::onBtnStopAll);
		// if (mHubBtn_RestartAllButton)
		// 	mHubBtn_RestartAllButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_Hub::onBtnRestartAll);

		if (mKenshiLua_HubRootWindow)
			mKenshiLua_HubRootWindow->eventWindowButtonPressed += MyGUI::newDelegate(this, &KenshiLua_Hub::onWindowButtonPressed);

		//if (mHubVersionLabelTextBox)
		//	mHubVersionLabelTextBox->setCaption("KENSHILUA Version: " KENSHELUA_VERSION);

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
				//updateStatus("Ready.");
			}
		}
	}

	bool KenshiLua_Hub::getVisible()
	{
		return mKenshiLua_HubRootWindow ? mKenshiLua_HubRootWindow->getVisible() : false;
	}

	// void KenshiLua_Hub::updateStatus(const std::string& status)
	// {
	// 	if (mHubStatusLabelTextBox)
	// 		mHubStatusLabelTextBox->setCaption(status);
	// }

	void KenshiLua_Hub::onBtnScriptEditor(MyGUI::Widget* sender)
	{
		logToFileDebug("Hub: SCRIPT EDITOR button clicked.");
		auto editor = ScriptEditor::get().getEditor();
		logToFileDebugf("Hub: SCRIPT EDITOR pointer = %p", editor);
		if (editor)
		{
			bool vis = editor->getVisible();
			logToFileDebugf("Hub: SCRIPT EDITOR current visibility = %d, setting to = %d", vis, !vis);
			editor->setVisible(!vis);
		}
	}

	void KenshiLua_Hub::onBtnConsole(MyGUI::Widget* sender)
	{
		logToFileDebug("Hub: CONSOLE button clicked.");
		auto console = ScriptEditor::get().getConsole();
		logToFileDebugf("Hub: CONSOLE pointer = %p", console);
		if (console)
		{
			bool vis = console->getVisible();
			logToFileDebugf("Hub: CONSOLE current visibility = %d, setting to = %d", vis, !vis);
			console->setVisible(!vis);
		}
	}

	void KenshiLua_Hub::onBtnLogViewer(MyGUI::Widget* sender)
	{
		logToFileDebug("Hub: LOG VIEWER button clicked.");
		auto viewer = ScriptEditor::get().getLogViewer();
		logToFileDebugf("Hub: LOG VIEWER pointer = %p", viewer);
		if (viewer)
		{
			bool vis = viewer->getVisible();
			logToFileDebugf("Hub: LOG VIEWER current visibility = %d, setting to = %d", vis, !vis);
			viewer->setVisible(!vis);
		}
	}

	void KenshiLua_Hub::onBtnScriptManager(MyGUI::Widget* sender)
	{
		logToFileDebug("Hub: SCRIPT MANAGER button clicked.");
		auto manager = ScriptEditor::get().getScriptManager();
		logToFileDebugf("Hub: SCRIPT MANAGER pointer = %p", manager);
		if (manager)
		{
			bool vis = manager->getVisible();
			logToFileDebugf("Hub: SCRIPT MANAGER current visibility = %d, setting to = %d", vis, !vis);
			manager->setVisible(!vis);
		}
	}

	void KenshiLua_Hub::onBtnSettings(MyGUI::Widget* sender)
	{
		logToFileDebug("Hub: SETTINGS button clicked.");
		auto settings = ScriptEditor::get().getSettings();
		logToFileDebugf("Hub: SETTINGS pointer = %p", settings);
		if (settings)
		{
			bool vis = settings->getVisible();
			logToFileDebugf("Hub: SETTINGS current visibility = %d, setting to = %d", vis, !vis);
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

	// void KenshiLua_Hub::onBtnStopAll(MyGUI::Widget* sender)
	// {
	// 	logToFile("Stopping KenshiLua runtime...");
	// 	Plugin::get().shutdown();
	// }

	// void KenshiLua_Hub::onBtnRestartAll(MyGUI::Widget* sender)
	// {
	// 	logToFile("Restarting KenshiLua runtime...");
	// 	void* hModule = Plugin::get().getDllModule();
	// 	Plugin::get().shutdown();
	// 	Plugin::get().initialize(hModule);
	// 	Plugin::get().start();

	// 	// Reshow the newly constructed Hub
	// 	auto hub = ScriptEditor::get().getHub();
	// 	if (hub)
	// 	{
	// 		hub->setVisible(true);
	// 		hub->updateStatus("Restarted Lua runtime successfully.");
	// 	}
	// }

} // KenshiLua
