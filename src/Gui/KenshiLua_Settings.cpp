#include "pch.h"
#include "KenshiLua_Settings.h"
#include "Gui/GuiHelpers.h"
#include "Logger.h"

namespace KenshiLua
{

	KenshiLua_Settings::KenshiLua_Settings(MyGUI::Widget* _parent)
	{
		initialiseByAttributes(this, _parent);
		mKenshiLua_SettingsRootWindow = mMainWidget->castType<MyGUI::Window>(false);
		logToFileDebugf("Settings initialization: mMainWidget=%p, mKenshiLua_SettingsRootWindow=%p", mMainWidget, mKenshiLua_SettingsRootWindow);

		if (mSettings_CancelButtonButton)
			mSettings_CancelButtonButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_Settings::onCancelClicked);

		if (mKenshiLua_SettingsRootWindow)
			mKenshiLua_SettingsRootWindow->eventWindowButtonPressed += MyGUI::newDelegate(this, &KenshiLua_Settings::onWindowButtonPressed);

		setVisible(false);
	}

	KenshiLua_Settings::~KenshiLua_Settings()
	{
	}

	void KenshiLua_Settings::setVisible(bool visible)
	{
		if (mKenshiLua_SettingsRootWindow)
		{
			mKenshiLua_SettingsRootWindow->setVisible(visible);
			if (visible)
				MyGUI::LayerManager::getInstance().upLayerItem(mKenshiLua_SettingsRootWindow);
		}
	}

	bool KenshiLua_Settings::getVisible()
	{
		return mKenshiLua_SettingsRootWindow ? mKenshiLua_SettingsRootWindow->getVisible() : false;
	}

	void KenshiLua_Settings::onCancelClicked(MyGUI::Widget* sender)
	{
		setVisible(false);
	}

	void KenshiLua_Settings::onWindowButtonPressed(MyGUI::Window*, const std::string& name)
	{
		if (name == "close")
		{
			setVisible(false);
		}
	}

} // KenshiLua
