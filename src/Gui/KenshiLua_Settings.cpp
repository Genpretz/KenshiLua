#include "pch.h"
#include "KenshiLua_Settings.h"
#include "Gui/GuiManager.h"
#include "Logger.h"
#include "Config.h"
#include <kenshi/Globals.h>
#include <kenshi/InputHandler.h>

namespace KenshiLua
{
	static std::string formatKeybind(bool ctrl, bool shift, bool alt, OIS::KeyCode key)
	{
		std::string str;
		if (ctrl) str += "Ctrl + ";
		if (shift) str += "Shift + ";
		if (alt) str += "Alt + ";

		if (::key)
		{
			std::string keyName = ::key->keyString(static_cast<int>(key), false);
			if (keyName.rfind("KC_", 0) == 0)
			{
				keyName = keyName.substr(3);
			}
			str += keyName;
		}
		else
		{
			str += "L";
		}
		return str;
	}

	KenshiLua_Settings::KenshiLua_Settings(MyGUI::Widget* _parent)
		: m_tempToggleCtrl(true)
		, m_tempToggleShift(true)
		, m_tempToggleAlt(false)
		, m_tempToggleKey(OIS::KC_L)
		, m_isCapturingKeybind(false)
	{
		initialiseByAttributes(this, _parent);
		mKenshiLua_SettingsRootWindow = mMainWidget->castType<MyGUI::Window>(false);

		if (mSettings_CancelButtonButton)
			mSettings_CancelButtonButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_Settings::onCancelClicked);

		if (mSettings_SaveButtonButton)
			mSettings_SaveButtonButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_Settings::onSaveClicked);

		if (mSettings_DefaultsButtonButton)
			mSettings_DefaultsButtonButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_Settings::onDefaultsClicked);

		if (mKeyBind_ButtonButton)
		{
			mKeyBind_ButtonButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_Settings::onKeyBindClicked);
			mKeyBind_ButtonButton->eventKeyButtonPressed += MyGUI::newDelegate(this, &KenshiLua_Settings::onKeyButtonPressed);
		}

		if (mStartMinimized_TickBoxButton)
			mStartMinimized_TickBoxButton->eventMouseButtonClick += MyGUI::newDelegate(this, &KenshiLua_Settings::onStartMinimizedClicked);

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
			{
				MyGUI::LayerManager::getInstance().upLayerItem(mKenshiLua_SettingsRootWindow);

				// Populate fields from config
				Config& conf = Config::get();
				m_tempToggleCtrl = conf.isToggleGuiCtrl();
				m_tempToggleShift = conf.isToggleGuiShift();
				m_tempToggleAlt = conf.isToggleGuiAlt();
				m_tempToggleKey = conf.getToggleGuiKey();
				m_isCapturingKeybind = false;

				if (mKeyBind_ButtonButton)
				{
					mKeyBind_ButtonButton->setCaption(formatKeybind(m_tempToggleCtrl, m_tempToggleShift, m_tempToggleAlt, m_tempToggleKey));
				}

				if (mLogLevel_ComboBoxComboBox)
				{
					int index = 0;
					switch (conf.getLogLevel())
					{
						case LogLevel_Log: index = 0; break;
						case LogLevel_Warn: index = 1; break;
						case LogLevel_Error: index = 2; break;
						case LogLevel_Debug: index = 3; break;
					}
					mLogLevel_ComboBoxComboBox->setIndexSelected(index);
				}

				if (mStartMinimized_TickBoxButton)
				{
					mStartMinimized_TickBoxButton->setStateSelected(conf.isStartMinimized());
				}
			}
			else
			{
				if (m_isCapturingKeybind)
				{
					m_isCapturingKeybind = false;
					MyGUI::InputManager::getInstance().resetKeyFocusWidget();
				}
			}
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

	void KenshiLua_Settings::onSaveClicked(MyGUI::Widget* sender)
	{
		Config& conf = Config::get();
		conf.setToggleGuiCtrl(m_tempToggleCtrl);
		conf.setToggleGuiShift(m_tempToggleShift);
		conf.setToggleGuiAlt(m_tempToggleAlt);
		conf.setToggleGuiKey(m_tempToggleKey);

		size_t index = mLogLevel_ComboBoxComboBox ? mLogLevel_ComboBoxComboBox->getIndexSelected() : 0;
		LogLevel level = LogLevel_Log;
		if (index == 1) level = LogLevel_Warn;
		else if (index == 2) level = LogLevel_Error;
		else if (index == 3) level = LogLevel_Debug;
		conf.setLogLevel(level);

		if (mStartMinimized_TickBoxButton)
		{
			conf.setStartMinimized(mStartMinimized_TickBoxButton->getStateSelected());
		}

		conf.save();
		setVisible(false);
	}

	void KenshiLua_Settings::onDefaultsClicked(MyGUI::Widget* sender)
	{
		m_tempToggleCtrl = true;
		m_tempToggleShift = true;
		m_tempToggleAlt = false;
		m_tempToggleKey = OIS::KC_L;

		if (mKeyBind_ButtonButton)
		{
			mKeyBind_ButtonButton->setCaption(formatKeybind(m_tempToggleCtrl, m_tempToggleShift, m_tempToggleAlt, m_tempToggleKey));
		}

		if (mLogLevel_ComboBoxComboBox)
		{
			mLogLevel_ComboBoxComboBox->setIndexSelected(0);
		}

		if (mStartMinimized_TickBoxButton)
		{
			mStartMinimized_TickBoxButton->setStateSelected(true);
		}
	}

	void KenshiLua_Settings::onKeyBindClicked(MyGUI::Widget* sender)
	{
		m_isCapturingKeybind = true;
		if (mKeyBind_ButtonButton)
		{
			mKeyBind_ButtonButton->setCaption("[ Press Keys ]");
			MyGUI::InputManager::getInstance().setKeyFocusWidget(mKeyBind_ButtonButton);
		}
	}

	void KenshiLua_Settings::onKeyButtonPressed(MyGUI::Widget* sender, MyGUI::KeyCode key, MyGUI::Char ch)
	{
		if (!m_isCapturingKeybind)
			return;

		bool isMod = (key.getValue() == OIS::KC_LCONTROL || key.getValue() == OIS::KC_RCONTROL ||
					  key.getValue() == OIS::KC_LSHIFT || key.getValue() == OIS::KC_RSHIFT ||
					  key.getValue() == OIS::KC_LMENU || key.getValue() == OIS::KC_RMENU);

		if (isMod)
		{
			bool ctrl = MyGUI::InputManager::getInstance().isControlPressed() ||
						(key.getValue() == OIS::KC_LCONTROL || key.getValue() == OIS::KC_RCONTROL);
			bool shift = MyGUI::InputManager::getInstance().isShiftPressed() ||
						 (key.getValue() == OIS::KC_LSHIFT || key.getValue() == OIS::KC_RSHIFT);
			bool alt = (::key && ::key->alt) ||
					   (key.getValue() == OIS::KC_LMENU || key.getValue() == OIS::KC_RMENU);

			std::string cap;
			if (ctrl) cap += "Ctrl + ";
			if (shift) cap += "Shift + ";
			if (alt) cap += "Alt + ";
			cap += "...";
			if (mKeyBind_ButtonButton)
			{
				mKeyBind_ButtonButton->setCaption(cap);
			}
			return;
		}

		if (key.getValue() == OIS::KC_ESCAPE)
		{
			m_isCapturingKeybind = false;
			if (mKeyBind_ButtonButton)
			{
				mKeyBind_ButtonButton->setCaption(formatKeybind(m_tempToggleCtrl, m_tempToggleShift, m_tempToggleAlt, m_tempToggleKey));
				MyGUI::InputManager::getInstance().resetKeyFocusWidget();
			}
			return;
		}

		m_tempToggleCtrl = MyGUI::InputManager::getInstance().isControlPressed();
		m_tempToggleShift = MyGUI::InputManager::getInstance().isShiftPressed();
		m_tempToggleAlt = (::key && ::key->alt);
		m_tempToggleKey = static_cast<OIS::KeyCode>(key.getValue());

		m_isCapturingKeybind = false;
		if (mKeyBind_ButtonButton)
		{
			mKeyBind_ButtonButton->setCaption(formatKeybind(m_tempToggleCtrl, m_tempToggleShift, m_tempToggleAlt, m_tempToggleKey));
			MyGUI::InputManager::getInstance().resetKeyFocusWidget();
		}
	}

	void KenshiLua_Settings::onStartMinimizedClicked(MyGUI::Widget* sender)
	{
		MyGUI::Button* btn = sender->castType<MyGUI::Button>(false);
		if (btn)
		{
			btn->setStateSelected(!btn->getStateSelected());
		}
	}

} // KenshiLua
