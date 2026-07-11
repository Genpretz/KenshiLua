#include "pch.h"
#include "KenshiLua_LogViewer.h"
#include "Gui/GuiHelpers.h"
#include "Logger.h"

#include <Windows.h>
#include <commdlg.h>
#include <fstream>
#include <algorithm>

namespace KenshiLua
{

	static std::string SaveFileDialog()
	{
		char filename[MAX_PATH] = "kenshilua_log.txt";
		OPENFILENAMEA ofn = {};
		ofn.lStructSize = sizeof(ofn);
		ofn.lpstrFilter = "Text Files (*.txt)\0*.txt\0Log Files (*.log)\0*.log\0All Files (*.*)\0*.*\0";
		ofn.lpstrFile = filename;
		ofn.nMaxFile = MAX_PATH;
		ofn.Flags = OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR;
		ofn.lpstrDefExt = "txt";
		ofn.lpstrTitle = "Save Log Copy";

		return GetSaveFileNameA(&ofn) ? std::string(filename) : "";
	}

	KenshiLua_LogViewer::KenshiLua_LogViewer(MyGUI::Widget* _parent)
	{
		initialiseByAttributes(this, _parent);
		mKenshiLua_LogViewerRootWindow = mMainWidget->castType<MyGUI::Window>(false);
		logToFileDebugf("LogViewer initialization: mMainWidget=%p, mKenshiLua_LogViewerRootWindow=%p", mMainWidget, mKenshiLua_LogViewerRootWindow);

		if (mLogViewer_ClearButtonButton)
			mLogViewer_ClearButtonButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_LogViewer::onClearClicked);

		if (mLogViewer_SaveLogButtonButton)
			mLogViewer_SaveLogButtonButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_LogViewer::onSaveLogClicked);

		if (mLogViewer_FilterBoxEditBox)
			mLogViewer_FilterBoxEditBox->eventEditTextChange += MyGUI::newDelegate(this, &KenshiLua_LogViewer::onFilterChanged);

		if (mKenshiLua_LogViewerRootWindow)
			mKenshiLua_LogViewerRootWindow->eventWindowButtonPressed += MyGUI::newDelegate(this, &KenshiLua_LogViewer::onWindowButtonPressed);

		if (mLogViewer_OutputBoxEditBox)
			mLogViewer_OutputBoxEditBox->setMaxTextLength(MyGUI::ITEM_NONE);

		setVisible(false);
	}

	KenshiLua_LogViewer::~KenshiLua_LogViewer()
	{
	}

	void KenshiLua_LogViewer::setVisible(bool visible)
	{
		if (mKenshiLua_LogViewerRootWindow)
		{
			mKenshiLua_LogViewerRootWindow->setVisible(visible);
			if (visible)
			{
				MyGUI::LayerManager::getInstance().upLayerItem(mKenshiLua_LogViewerRootWindow);
				refreshLog();
			}
		}
	}

	bool KenshiLua_LogViewer::getVisible()
	{
		return mKenshiLua_LogViewerRootWindow ? mKenshiLua_LogViewerRootWindow->getVisible() : false;
	}

	void KenshiLua_LogViewer::refreshLog()
	{
		if (!mLogViewer_OutputBoxEditBox)
			return;

		std::vector<std::string> lines;
		Logger::get().snapshot(lines);

		std::string filterStr = mLogViewer_FilterBoxEditBox ? mLogViewer_FilterBoxEditBox->getCaption().asUTF8() : "";
		std::transform(filterStr.begin(), filterStr.end(), filterStr.begin(), ::tolower);

		std::string outputText;
		for (size_t i = 0; i < lines.size(); ++i)
		{
			if (!filterStr.empty())
			{
				std::string lowerLine = lines[i];
				std::transform(lowerLine.begin(), lowerLine.end(), lowerLine.begin(), ::tolower);
				if (lowerLine.find(filterStr) == std::string::npos)
					continue;
			}
			outputText += lines[i] + "\n";
		}

		mLogViewer_OutputBoxEditBox->setCaption(MyGUI::UString(outputText));

		// Scroll to bottom
		size_t length = mLogViewer_OutputBoxEditBox->getTextLength();
		mLogViewer_OutputBoxEditBox->setTextCursor(length);
	}

	void KenshiLua_LogViewer::onClearClicked(MyGUI::Widget* sender)
	{
		if (mLogViewer_OutputBoxEditBox)
			mLogViewer_OutputBoxEditBox->setCaption("");
	}

	void KenshiLua_LogViewer::onSaveLogClicked(MyGUI::Widget* sender)
	{
		if (!mLogViewer_OutputBoxEditBox)
			return;

		std::string path = SaveFileDialog();
		if (path.empty())
			return;

		std::ofstream f(path.c_str(), std::ios::binary);
		if (!f.is_open())
		{
			logToFile("LogViewer: Failed to open file for saving: " + path);
			return;
		}

		f << mLogViewer_OutputBoxEditBox->getCaption().asUTF8();
		logToFile("LogViewer: Saved copy of the log to: " + path);
	}

	void KenshiLua_LogViewer::onFilterChanged(MyGUI::EditBox* sender)
	{
		refreshLog();
	}

	void KenshiLua_LogViewer::onWindowButtonPressed(MyGUI::Window*, const std::string& name)
	{
		if (name == "close")
		{
			setVisible(false);
		}
	}

} // KenshiLua
