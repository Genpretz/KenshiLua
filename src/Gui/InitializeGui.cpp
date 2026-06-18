#include "pch.h"
#include "Gui/InitializeGui.h"
#include "Gui/ScriptEditor.h"
#include "Lua/Logger.h"

#include <MyGUI.h>

namespace KenshiLua
{

    KenshiLuaGui& KenshiLuaGui::get()
    {
        static KenshiLuaGui inst;
        return inst;
    }

    KenshiLuaGui::KenshiLuaGui()
        : m_pendingLuaState(0)
        , m_initialized(false)
    {
    }

    KenshiLuaGui::~KenshiLuaGui()
    {
    }

    void KenshiLuaGui::requestInitialize(LuaState* luaState)
    {
        if (m_initialized || m_pendingLuaState != nullptr)
        {
            logToFile("InitializeGui: Already initialized or initialization pending - ignoring request");
            return;
        }
        m_pendingLuaState = luaState;

        MyGUI::Gui* gui = MyGUI::Gui::getInstancePtr();
        if (gui)
        {
            gui->eventFrameStart += MyGUI::newDelegate(this, &KenshiLuaGui::initFrameHandler);
            logToFile("InitializeGui: Subscribed to eventFrameStart");
        }
        else
        {
            logToFile("InitializeGui: MyGUI singleton not yet available in requestInitialize");
        }
    }

    //copied from RE_Kenshi
    MyGUI::WidgetPtr FindWidget(MyGUI::EnumeratorWidgetPtr enumerator, std::string name)
    {
        while (enumerator.next())
        {
            std::string widgetName = enumerator.current()->getName();
            size_t splitPos = widgetName.find('_');

            if (splitPos != std::string::npos && widgetName.substr(splitPos + 1) == name)
                return enumerator.current();
            if (enumerator.current()->getChildCount() > 0)
            {
                MyGUI::WidgetPtr childFoundWidget = FindWidget(enumerator.current()->getEnumerator(), name);
                if (childFoundWidget != nullptr)
                    return childFoundWidget;
            }
        }
        return nullptr;
    }
    //copied from RE_Kenshi
    void WaitForMainMenu()
    {
        MyGUI::Gui* gui = nullptr;
        while (gui == nullptr)
        {
            gui = MyGUI::Gui::getInstancePtr();
            Sleep(10);
        }
        MyGUI::WidgetPtr versionText = nullptr;
        while (versionText == nullptr)
        {
            versionText = FindWidget(gui->getEnumerator(), "VersionText");
            Sleep(10);
        }
    }

    void KenshiLuaGui::initFrameHandler(float)
    {
        if (m_initialized)
            return;

        MyGUI::Gui* gui = MyGUI::Gui::getInstancePtr();
        if (!gui)
            return;

        MyGUI::WidgetPtr versionText = FindWidget(gui->getEnumerator(), "VersionText");
        if (versionText == nullptr)
            return;

        gui->eventFrameStart -=
            MyGUI::newDelegate(this, &KenshiLuaGui::initFrameHandler);

        logToFile("Initializing ScriptEditor");

        ScriptEditor::get().initialize(m_pendingLuaState);

        m_initialized = true;
    }

    void KenshiLuaGui::shutdown()
    {
        m_initialized = false;
        ScriptEditor::get().shutdown();
    }

    void KenshiLuaGui::toggle()
    {
        if (m_initialized)
        {
            ScriptEditor::get().toggle();
        }
    }

    bool KenshiLuaGui::isInitialized() const
    {
        return m_initialized;
    }

} // namespace KenshiLua
