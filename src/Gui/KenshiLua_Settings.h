#ifndef _KENSHI_LUA__SETTINGS_H_
#define _KENSHI_LUA__SETTINGS_H_

#include <mygui/common/baselayout/BaseLayout.h>

namespace KenshiLua
{

	ATTRIBUTE_CLASS_LAYOUT(KenshiLua_Settings, "KenshiLua_Settings.layout");
	class KenshiLua_Settings :
		public wraps::BaseLayout
	{
	public:
		KenshiLua_Settings(MyGUI::Widget* _parent = nullptr);
		virtual ~KenshiLua_Settings();

		void setVisible(bool visible);
		bool getVisible();

	private:
		void onCancelClicked(MyGUI::Widget* sender);
		void onWindowButtonPressed(MyGUI::Window* sender, const std::string& name);
		void onSaveClicked(MyGUI::Widget* sender);
		void onDefaultsClicked(MyGUI::Widget* sender);
		void onKeyBindClicked(MyGUI::Widget* sender);
		void onKeyButtonPressed(MyGUI::Widget* sender, MyGUI::KeyCode key, MyGUI::Char ch);
		void onStartMinimizedClicked(MyGUI::Widget* sender);

		bool m_tempToggleCtrl;
		bool m_tempToggleShift;
		bool m_tempToggleAlt;
		OIS::KeyCode m_tempToggleKey;
		bool m_isCapturingKeybind;

	//%LE Widget_Declaration list start
		MyGUI::Window* mKenshiLua_SettingsRootWindow;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_Settings, mSettings_DefaultsButtonButton, "Settings_DefaultsButton");
		MyGUI::Button* mSettings_DefaultsButtonButton;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_Settings, mSettings_CancelButtonButton, "Settings_CancelButton");
		MyGUI::Button* mSettings_CancelButtonButton;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_Settings, mSettings_SaveButtonButton, "Settings_SaveButton");
		MyGUI::Button* mSettings_SaveButtonButton;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_Settings, mKeyBind_ButtonButton, "KeyBind_Button");
		MyGUI::Button* mKeyBind_ButtonButton;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_Settings, mLogLevel_ComboBoxComboBox, "LogLevel_ComboBox");
		MyGUI::ComboBox* mLogLevel_ComboBoxComboBox;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_Settings, mStartMinimized_TickBoxButton, "StartMinimized_TickBox");
		MyGUI::Button* mStartMinimized_TickBoxButton;
	//%LE Widget_Declaration list end
	};

} // namespace KenshiLua

#endif // _KENSHI_LUA__SETTINGS_H_
