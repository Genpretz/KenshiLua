#ifndef _KENSHI_LUA__SCRIPT_MANAGER_H_
#define _KENSHI_LUA__SCRIPT_MANAGER_H_

#include <mygui/common/baselayout/BaseLayout.h>

namespace KenshiLua
{

	struct ScriptInfo
	{
		std::string modName;
		std::string modPath;
		std::string absolutePath;
		std::string relativePath;
		std::string chunkName;
		bool isActiveMod;
		bool isRunning;
		std::string lastError;
	};

	ATTRIBUTE_CLASS_LAYOUT(KenshiLua_ScriptManager, "KenshiLua_ScriptManager.layout");
	class KenshiLua_ScriptManager :
		public wraps::BaseLayout
	{
	public:
		KenshiLua_ScriptManager(MyGUI::Widget* _parent = nullptr);
		virtual ~KenshiLua_ScriptManager();

		void setVisible(bool visible);
		bool getVisible();

		void refreshList();
		void refreshListUI();

	private:
		void onWindowButtonPressed(MyGUI::Window* sender, const std::string& name);
		void onFilterChanged(MyGUI::EditBox* sender);
		void onListSelectChanged(MyGUI::MultiListBox* sender, size_t index);
		void onRunSelectedClicked(MyGUI::Widget* sender);
		void onStopSelectedClicked(MyGUI::Widget* sender);

		std::vector<ScriptInfo> m_scripts;
		std::vector<size_t> m_filteredIndices; // indices of m_scripts matching filter
		int m_selectedIndex; // index in m_scripts (-1 if none)

	//%LE Widget_Declaration list start
		MyGUI::Window* mKenshiLua_ScriptManagerRootWindow;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_ScriptManager, mScriptManager_FilterLabelTextBox, "ScriptManager_FilterLabel");
		MyGUI::TextBox* mScriptManager_FilterLabelTextBox;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_ScriptManager, mScriptManager_FilterEditEditBox, "ScriptManager_FilterEdit");
		MyGUI::EditBox* mScriptManager_FilterEditEditBox;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_ScriptManager, mScriptManager_ScriptListMultiList, "ScriptManager_ScriptList");
		MyGUI::MultiListBox* mScriptManager_ScriptListMultiList;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_ScriptManager, mScriptManager_CountLabelTextBox, "ScriptManager_CountLabel");
		MyGUI::TextBox* mScriptManager_CountLabelTextBox;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_ScriptManager, mScriptManager_StartButtonButton, "ScriptManager_StartButton");
		MyGUI::Button* mScriptManager_StartButtonButton;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_ScriptManager, mScriptManager_StopButtonButton, "ScriptManager_StopButton");
		MyGUI::Button* mScriptManager_StopButtonButton;
	//%LE Widget_Declaration list end
	};

} // namespace KenshiLua

#endif // _KENSHI_LUA__SCRIPT_MANAGER_H_
