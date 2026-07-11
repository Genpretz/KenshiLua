#ifndef _KENSHI_LUA__LOG_VIEWER_H_
#define _KENSHI_LUA__LOG_VIEWER_H_

#include <mygui/common/baselayout/BaseLayout.h>

namespace KenshiLua
{

	ATTRIBUTE_CLASS_LAYOUT(KenshiLua_LogViewer, "KenshiLua_LogViewer.layout");
	class KenshiLua_LogViewer :
		public wraps::BaseLayout
	{
	public:
		KenshiLua_LogViewer(MyGUI::Widget* _parent = nullptr);
		virtual ~KenshiLua_LogViewer();

		void setVisible(bool visible);
		bool getVisible();
		void refreshLog();

	private:
		void onClearClicked(MyGUI::Widget* sender);
		void onSaveLogClicked(MyGUI::Widget* sender);
		void onFilterChanged(MyGUI::EditBox* sender);
		void onWindowButtonPressed(MyGUI::Window* sender, const std::string& name);
	//%LE Widget_Declaration list start
		MyGUI::Window* mKenshiLua_LogViewerRootWindow;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_LogViewer, mLogViewer_FilterLabelTextBox, "LogViewer_FilterLabel");
		MyGUI::TextBox* mLogViewer_FilterLabelTextBox;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_LogViewer, mLogViewer_FilterBoxEditBox, "LogViewer_FilterBox");
		MyGUI::EditBox* mLogViewer_FilterBoxEditBox;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_LogViewer, mLogViewer_ClearButtonButton, "LogViewer_ClearButton");
		MyGUI::Button* mLogViewer_ClearButtonButton;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_LogViewer, mLogViewer_OutputBoxEditBox, "LogViewer_OutputBox");
		MyGUI::EditBox* mLogViewer_OutputBoxEditBox;

		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_LogViewer, mLogViewer_AutoScrollToggleButton, "LogViewer_AutoScrollToggle");
		MyGUI::Button* mLogViewer_AutoScrollToggleButton;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_LogViewer, mLogViewer_SaveLogButtonButton, "LogViewer_SaveLogButton");
		MyGUI::Button* mLogViewer_SaveLogButtonButton;
	//%LE Widget_Declaration list end
	};

} // namespace KenshiLua

#endif // _KENSHI_LUA__LOG_VIEWER_H_
