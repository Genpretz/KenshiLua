#ifndef _KENSHI_LUA__SCRIPT_EDITOR_H_
#define _KENSHI_LUA__SCRIPT_EDITOR_H_

#include <mygui/common/baselayout/BaseLayout.h>

namespace KenshiLua
{

	ATTRIBUTE_CLASS_LAYOUT(KenshiLua_ScriptEditor, "KenshiLua_ScriptEditor.layout");
	class KenshiLua_ScriptEditor :
		public wraps::BaseLayout
	{
	public:
		KenshiLua_ScriptEditor(MyGUI::Widget* _parent = nullptr);
		virtual ~KenshiLua_ScriptEditor();

		void setVisible(bool visible);
		bool getVisible();
		MyGUI::Window* getWindow() const { return mKenshiLua_ScriptEditorWindow; }
		void appendOutput(const std::string& text);
		void clearOutput();

	private:
		void onRunClicked(MyGUI::Widget* sender);
		void onStopClicked(MyGUI::Widget* sender);
		void onOpenClicked(MyGUI::Widget* sender);
		void onSaveClicked(MyGUI::Widget* sender);
		void onSaveAsClicked(MyGUI::Widget* sender);
		void onClearClicked(MyGUI::Widget* sender);
		void onWindowButtonPressed(MyGUI::Window* sender, const std::string& name);

		void onInputTextChanged(MyGUI::EditBox* sender);
		void onFrameStart(float frameTime);

		void updateInputGutter();
		void updateOutputGutter();

		bool saveToFile(const std::string& path);

		std::string m_currentFilePath;
		size_t m_lastInputVScrollPos;
		size_t m_lastOutputVScrollPos;
	//%LE Widget_Declaration list start
		MyGUI::Window* mKenshiLua_ScriptEditorWindow;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_ScriptEditor, mdatapanelWidget, "datapanel");
		MyGUI::Widget* mdatapanelWidget;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_ScriptEditor, mScriptEditor_InputGutterEditBox, "ScriptEditor_InputGutter");
		MyGUI::EditBox* mScriptEditor_InputGutterEditBox;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_ScriptEditor, mScriptEditor_InputBoxEditBox, "ScriptEditor_InputBox");
		MyGUI::EditBox* mScriptEditor_InputBoxEditBox;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_ScriptEditor, mScriptEditor_OutputGutterEditBox, "ScriptEditor_OutputGutter");
		MyGUI::EditBox* mScriptEditor_OutputGutterEditBox;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_ScriptEditor, mScriptEditor_OutputBoxEditBox, "ScriptEditor_OutputBox");
		MyGUI::EditBox* mScriptEditor_OutputBoxEditBox;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_ScriptEditor, mScriptEditor_OpenButtonButton, "ScriptEditor_OpenButton");
		MyGUI::Button* mScriptEditor_OpenButtonButton;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_ScriptEditor, mScriptEditor_SaveButtonButton, "ScriptEditor_SaveButton");
		MyGUI::Button* mScriptEditor_SaveButtonButton;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_ScriptEditor, mScriptEditor_SaveAsButtonButton, "ScriptEditor_SaveAsButton");
		MyGUI::Button* mScriptEditor_SaveAsButtonButton;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_ScriptEditor, mScriptEditor_ClearButtonButton, "ScriptEditor_ClearButton");
		MyGUI::Button* mScriptEditor_ClearButtonButton;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_ScriptEditor, mScriptEditor_RunButtonButton, "ScriptEditor_RunButton");
		MyGUI::Button* mScriptEditor_RunButtonButton;
		ATTRIBUTE_FIELD_WIDGET_NAME(KenshiLua_ScriptEditor, mScriptEditor_StopButtonButton, "ScriptEditor_StopButton");
		MyGUI::Button* mScriptEditor_StopButtonButton;
	//%LE Widget_Declaration list end
	};

} // namespace KenshiLua

#endif // _KENSHI_LUA__SCRIPT_EDITOR_H_
