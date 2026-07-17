#ifndef _KENSHI_LUA__CONSOLE_H_
#define _KENSHI_LUA__CONSOLE_H_

#include "mygui/common/baselayout/BaseLayout.h"

namespace KenshiLua
{

	ATTRIBUTE_CLASS_LAYOUT(KenshiLua_Console, "KenshiLua_Console.layout");
	class KenshiLua_Console :
		public wraps::BaseLayout
	{
	public:
		KenshiLua_Console(MyGUI::Widget* _parent = nullptr);
		virtual ~KenshiLua_Console();

		void setVisible(bool visible);
		bool getVisible();
		void appendOutput(const std::string& text);
		void clear();

	private:
		void onRunClicked(MyGUI::Widget* sender);
		void onClearClicked(MyGUI::Widget* sender);
		void onEditSelectAccept(MyGUI::EditBox* sender);
		void onWindowButtonPressed(MyGUI::Window* sender, const std::string& name);
	//%LE Widget_Declaration list start
		MyGUI::Window* mKenshiLua_ConsoleRootWindow;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_Console, mConsole_ContextLabelTextBox, "Console_ContextLabel");
		MyGUI::TextBox* mConsole_ContextLabelTextBox;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_Console, mConsole_ClearButtonButton, "Console_ClearButton");
		MyGUI::Button* mConsole_ClearButtonButton;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_Console, mConsole_OutputBoxEditBox, "Console_OutputBox");
		MyGUI::EditBox* mConsole_OutputBoxEditBox;

		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_Console, mConsole_PromptLabelTextBox, "Console_PromptLabel");
		MyGUI::TextBox* mConsole_PromptLabelTextBox;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_Console, mConsole_InputBoxEditBox, "Console_InputBox");
		MyGUI::EditBox* mConsole_InputBoxEditBox;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_Console, mConsole_RunButtonButton, "Console_RunButton");
		MyGUI::Button* mConsole_RunButtonButton;
	//%LE Widget_Declaration list end
	};

} // namespace KenshiLua

#endif // _KENSHI_LUA__CONSOLE_H_
