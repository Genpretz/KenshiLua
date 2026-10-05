#pragma once
#include <string>

class MyGUI::Window;
class MyGUI::Button;
class MyGUI::EditBox;

namespace KenshiLua
{
	namespace GuiHelpers
	{
		MyGUI::WidgetPtr FindWidget(MyGUI::EnumeratorWidgetPtr enumerator, const std::string& name);

		MyGUI::Window* createWindow(
			const std::string& skin,
			int x, int y, int w, int h,
			const std::string& name,
			const std::string& caption);

		MyGUI::Button* createButton(
			MyGUI::Widget* parent,
			int x, int y, int w, int h,
			const std::string& skin,
			const std::string& caption,
			const std::string& name,
			MyGUI::delegates::CDelegate1<MyGUI::Widget*>::IDelegate* handler);

		MyGUI::EditBox* createEditBox(
			MyGUI::Widget* parent,
			int x, int y, int w, int h,
			const std::string& skin,
			const std::string& name,
			bool multiLine,
			bool readOnly);

		std::string EscapeMyGuiColourTags(const std::string& text);

		// Shared close/minimize handler for all KenshiLua windows.
		// Panels delegate their onWindowButtonPressed to this helper.
		void handleWindowButton(MyGUI::Window* sender, const std::string& name, bool& edgeHideEnabled, MyGUI::Window* rootWindow);

	} // namespace GuiHelpers
} // namespace KenshiLua
