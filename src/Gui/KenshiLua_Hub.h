#ifndef _KENSHI_LUA__HUB_H_
#define _KENSHI_LUA__HUB_H_

#include "mygui/common/baselayout/BaseLayout.h"

namespace KenshiLua
{

	ATTRIBUTE_CLASS_LAYOUT(KenshiLua_Hub, "KenshiLua_Hub.layout");
	class KenshiLua_Hub :
		public wraps::BaseLayout
	{
	public:
		KenshiLua_Hub(MyGUI::Widget* _parent = nullptr);
		virtual ~KenshiLua_Hub();

		void setVisible(bool visible);
		bool getVisible();

	private:
		void onBtnScriptEditor(MyGUI::Widget* sender);
		void onBtnConsole(MyGUI::Widget* sender);
		void onBtnLogViewer(MyGUI::Widget* sender);
		void onBtnScriptManager(MyGUI::Widget* sender);
		void onBtnSettings(MyGUI::Widget* sender);
		void onWindowButtonPressed(MyGUI::Window* sender, const std::string& name);

	//%LE Widget_Declaration list start
		MyGUI::Window* mKenshiLua_HubRootWindow;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_Hub, mHubVersionLabelTextBox, "HubVersionLabel");
		MyGUI::TextBox* mHubVersionLabelTextBox;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_Hub, mHubBtn_ScriptManagerButton, "HubBtn_ScriptManager");
		MyGUI::Button* mHubBtn_ScriptManagerButton;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_Hub, mHubBtn_ScriptEditorButton, "HubBtn_ScriptEditor");
		MyGUI::Button* mHubBtn_ScriptEditorButton;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_Hub, mHubBtn_ConsoleButton, "HubBtn_Console");
		MyGUI::Button* mHubBtn_ConsoleButton;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_Hub, mHubBtn_LogViewerButton, "HubBtn_LogViewer");
		MyGUI::Button* mHubBtn_LogViewerButton;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_Hub, mHubBtn_SettingsButton, "HubBtn_Settings");
		MyGUI::Button* mHubBtn_SettingsButton;
	//%LE Widget_Declaration list end
	};

} // namespace KenshiLua

#endif // _KENSHI_LUA__HUB_H_
