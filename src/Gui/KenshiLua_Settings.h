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
	//%LE Widget_Declaration list start
		MyGUI::Window* mKenshiLua_SettingsRootWindow;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_Settings, mSettings_DefaultsButtonButton, "Settings_DefaultsButton");
		MyGUI::Button* mSettings_DefaultsButtonButton;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_Settings, mSettings_CancelButtonButton, "Settings_CancelButton");
		MyGUI::Button* mSettings_CancelButtonButton;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_Settings, mSettings_SaveButtonButton, "Settings_SaveButton");
		MyGUI::Button* mSettings_SaveButtonButton;
	//%LE Widget_Declaration list end
	};

} // namespace KenshiLua

#endif // _KENSHI_LUA__SETTINGS_H_
