#include "pch.h"
#include "KenshiLua_ScriptManager.h"
#include "KenshiLua_ScriptEditor.h"
#include "Gui/GuiHelpers.h"
#include "Logger.h"
#include "ScriptLoader.h"
#include "Lua/LuaState.h"
#include "Plugin.h"

#include <kenshi/Globals.h>
#include <kenshi/GameWorld.h>
#include <kenshi/ModInfo.h>
#include <kenshi/util/lektor.h>

#include <shellapi.h>
#include <boost/filesystem.hpp>
#include <algorithm>
#include <set>

namespace KenshiLua
{

	static bool endsWithCaseInsensitive(const std::string& s, const std::string& suffix)
	{
		if (s.size() < suffix.size()) return false;
		for (size_t i = 0; i < suffix.size(); ++i) {
			char a = s[s.size() - suffix.size() + i];
			char b = suffix[i];
			if (a >= 'A' && a <= 'Z') a = (char)(a + ('a' - 'A'));
			if (b >= 'A' && b <= 'Z') b = (char)(b + ('a' - 'A'));
			if (a != b) return false;
		}
		return true;
	}

	KenshiLua_ScriptManager::KenshiLua_ScriptManager(MyGUI::Widget* _parent)
		: m_selectedIndex(-1)
	{
		initialiseByAttributes(this, _parent);
		mKenshiLua_ScriptManagerRootWindow = mMainWidget->castType<MyGUI::Window>(false);
		logToFileDebugf("ScriptManager initialization: mMainWidget=%p, mKenshiLua_ScriptManagerRootWindow=%p", mMainWidget, mKenshiLua_ScriptManagerRootWindow);

		// Configure MultiListBox columns
		if (mScriptManager_ScriptListMultiList)
		{
			mScriptManager_ScriptListMultiList->addColumn("Filename", 250);
			mScriptManager_ScriptListMultiList->addColumn("Location", 250);
			mScriptManager_ScriptListMultiList->addColumn("Active", 90);
			mScriptManager_ScriptListMultiList->setColumnResizingPolicyAt(0, MyGUI::ResizingPolicy::Auto);
			mScriptManager_ScriptListMultiList->setColumnResizingPolicyAt(1, MyGUI::ResizingPolicy::Auto);
			mScriptManager_ScriptListMultiList->setColumnResizingPolicyAt(2, MyGUI::ResizingPolicy::Auto);
			mScriptManager_ScriptListMultiList->eventListChangePosition += MyGUI::newDelegate(this, &KenshiLua_ScriptManager::onListSelectChanged);
			
		}

		if (mScriptManager_StartButtonButton)
			mScriptManager_StartButtonButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_ScriptManager::onRunSelectedClicked);

		if (mScriptManager_StopButtonButton)
			mScriptManager_StopButtonButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_ScriptManager::onStopSelectedClicked);

		if (mScriptManager_FilterEditEditBox)
			mScriptManager_FilterEditEditBox->eventEditTextChange += MyGUI::newDelegate(this, &KenshiLua_ScriptManager::onFilterChanged);

		if (mKenshiLua_ScriptManagerRootWindow)
			mKenshiLua_ScriptManagerRootWindow->eventWindowButtonPressed += MyGUI::newDelegate(this, &KenshiLua_ScriptManager::onWindowButtonPressed);

		setVisible(false);
	}

	KenshiLua_ScriptManager::~KenshiLua_ScriptManager()
	{
	}

	void KenshiLua_ScriptManager::setVisible(bool visible)
	{
		if (mKenshiLua_ScriptManagerRootWindow)
		{
			mKenshiLua_ScriptManagerRootWindow->setVisible(visible);
			if (visible)
			{
				MyGUI::LayerManager::getInstance().upLayerItem(mKenshiLua_ScriptManagerRootWindow);
				refreshList();
			}
		}
	}

	bool KenshiLua_ScriptManager::getVisible()
	{
		return mKenshiLua_ScriptManagerRootWindow ? mKenshiLua_ScriptManagerRootWindow->getVisible() : false;
	}

	void KenshiLua_ScriptManager::refreshList()
	{
		m_scripts.clear();
		m_selectedIndex = -1;

		if (!::ou)
		{
			logToFile("Error: ScriptManager::refreshList: GameWorld not available");
			return;
		}

		std::set<std::string> activeModNames;
		for (int i = 0; i < (int)::ou->activeMods.size(); ++i)
		{
			if (::ou->activeMods[i])
				activeModNames.insert(::ou->activeMods[i]->name);
		}

		int n = (int)::ou->availabelModsOrderedList.size();
		for (int i = 0; i < n; ++i)
		{
			ModInfo* mi = ::ou->availabelModsOrderedList[i];
			if (!mi || mi->path.empty()) continue;

			namespace fs = boost::filesystem;
			fs::path modRoot(mi->path);
			fs::path initDir = modRoot / "scripts" / "init";
			boost::system::error_code ec;
			if (!fs::exists(initDir, ec) || !fs::is_directory(initDir, ec)) continue;

			fs::recursive_directory_iterator rit(initDir, ec);
			fs::recursive_directory_iterator end;
			for (; !ec && rit != end; rit.increment(ec))
			{
				if (ec) break;
				if (!fs::is_regular_file(rit->status())) continue;

				std::string absPath = rit->path().string();
				if (!endsWithCaseInsensitive(absPath, ".lua")) continue;

				ScriptInfo script;
				script.modName = mi->name;
				script.modPath = mi->path;
				script.absolutePath = absPath;

				if (absPath.size() > mi->path.size() + 1 &&
					absPath.compare(0, mi->path.size(), mi->path) == 0)
				{
					script.relativePath = absPath.substr(mi->path.size() + 1);
				}
				else
				{
					script.relativePath = absPath;
				}

				for (size_t j = 0; j < script.relativePath.size(); ++j)
				{
					if (script.relativePath[j] == '\\') script.relativePath[j] = '/';
				}

				script.chunkName = "@" + mi->name + "/" + script.relativePath;
				script.isActiveMod = (activeModNames.find(mi->name) != activeModNames.end());
				script.isRunning = false;

				const std::vector<LoadedScript>& loadedScripts = ScriptLoader::get().scripts();
				for (size_t k = 0; k < loadedScripts.size(); ++k)
				{
					const LoadedScript& ls = loadedScripts[k];
					if (ls.absolutePath == absPath && ls.loaded)
					{
						script.isRunning = true;
						script.lastError = ls.lastError;
						break;
					}
				}

				m_scripts.push_back(script);
			}
		}

		refreshListUI();
	}

	void KenshiLua_ScriptManager::refreshListUI()
	{
		if (!mScriptManager_ScriptListMultiList) return;

		mScriptManager_ScriptListMultiList->removeAllItems();
		m_filteredIndices.clear();

		std::string filterStr = mScriptManager_FilterEditEditBox ? mScriptManager_FilterEditEditBox->getCaption().asUTF8() : "";
		std::transform(filterStr.begin(), filterStr.end(), filterStr.begin(), ::tolower);

		for (size_t i = 0; i < m_scripts.size(); ++i)
		{
			if (!filterStr.empty())
			{
				std::string nameLower = m_scripts[i].relativePath;
				std::transform(nameLower.begin(), nameLower.end(), nameLower.begin(), ::tolower);

				std::string modLower = m_scripts[i].modName;
				std::transform(modLower.begin(), modLower.end(), modLower.begin(), ::tolower);

				if (nameLower.find(filterStr) == std::string::npos &&
					modLower.find(filterStr) == std::string::npos)
				{
					continue;
				}
			}
			m_filteredIndices.push_back(i);
		}

		for (size_t fIdx = 0; fIdx < m_filteredIndices.size(); ++fIdx)
		{
			size_t realIdx = m_filteredIndices[fIdx];
			const ScriptInfo& script = m_scripts[realIdx];

			// Column 0: Filename (relativePath)
			mScriptManager_ScriptListMultiList->addItem(script.relativePath);

			// Column 1: Location (mod name)
			mScriptManager_ScriptListMultiList->setSubItemNameAt(1, fIdx, script.modName);

			// Column 2: Active status
			std::string activeText;
			if (script.isRunning)
			{
				activeText = script.lastError.empty() ? "Running" : "Error";
			}
			else
			{
				activeText = script.isActiveMod ? "Auto" : "No";
			}
			mScriptManager_ScriptListMultiList->setSubItemNameAt(2, fIdx, activeText);
		}

		// Restore selection if valid
		if (m_selectedIndex >= 0)
		{
			for (size_t fIdx = 0; fIdx < m_filteredIndices.size(); ++fIdx)
			{
				if ((int)m_filteredIndices[fIdx] == m_selectedIndex)
				{
					mScriptManager_ScriptListMultiList->setIndexSelected(fIdx);
					break;
				}
			}
		}

		if (mScriptManager_CountLabelTextBox)
		{
			mScriptManager_CountLabelTextBox->setCaption(std::to_string((long long)m_filteredIndices.size()) + " scripts");
		}
	}

	void KenshiLua_ScriptManager::onListSelectChanged(MyGUI::MultiListBox*, size_t index)
	{
		if (index == MyGUI::ITEM_NONE || index >= m_filteredIndices.size())
		{
			m_selectedIndex = -1;
			return;
		}
		m_selectedIndex = (int)m_filteredIndices[index];
	}

	void KenshiLua_ScriptManager::onFilterChanged(MyGUI::EditBox*)
	{
		refreshListUI();
	}

	void KenshiLua_ScriptManager::onRunSelectedClicked(MyGUI::Widget*)
	{
		if (m_selectedIndex < 0 || m_selectedIndex >= (int)m_scripts.size())
		{
			logToFile("ScriptManager: No script selected to run");
			return;
		}

		ScriptInfo& script = m_scripts[m_selectedIndex];
		if (g_luaState)
		{
			std::string err;
			bool success = ScriptLoader::get().runScriptSandboxed(g_luaState->getState(), script.absolutePath, script.chunkName, &err);
			if (success)
			{
				script.isRunning = true;
				script.lastError.clear();
				logToFile("ScriptManager: Successfully ran " + script.chunkName);
			}
			else
			{
				script.lastError = err;
				logToFile("ScriptManager: Error running " + script.chunkName + ": " + err);
			}
			refreshListUI();
		}
		else
		{
			logToFile("ScriptManager: Lua state not initialized");
		}
	}

	void KenshiLua_ScriptManager::onStopSelectedClicked(MyGUI::Widget*)
	{
		logToFile("ScriptManager: Restarting KenshiLua runtime to unload scripts...");
		void* hModule = Plugin::get().getDllModule();
		Plugin::get().shutdown();
		Plugin::get().initialize(hModule);
		Plugin::get().start();

		auto mgr = ScriptEditor::get().getScriptManager();
		if (mgr)
		{
			mgr->setVisible(true);
			mgr->refreshList();
		}
	}

	void KenshiLua_ScriptManager::onWindowButtonPressed(MyGUI::Window*, const std::string& name)
	{
		if (name == "close")
		{
			setVisible(false);
		}
	}

} // KenshiLua

