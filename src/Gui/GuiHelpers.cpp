#include "pch.h"
#include "Gui/GuiHelpers.h"
#include "Logger.h"

namespace KenshiLua
{

    // ---------------------------------------------------------------------------
    // GuiHelpers Implementation
    // ---------------------------------------------------------------------------
    namespace GuiHelpers
    {
        MyGUI::WidgetPtr FindWidget(MyGUI::EnumeratorWidgetPtr enumerator, const std::string& name)
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

        MyGUI::Window* createWindow(
            const std::string& skin,
            int x, int y, int w, int h,
            const std::string& name,
            const std::string& caption)
        {
            MyGUI::Gui* gui = MyGUI::Gui::getInstancePtr();
            if (!gui) return nullptr;

            MyGUI::Window* window = gui->createWidget<MyGUI::Window>(
                skin, x, y, w, h,
                MyGUI::Align::Default,
                "Window",
                name);

            if (window)
            {
                window->setCaption(caption);
                window->setVisible(false);
            }
            return window;
        }

        MyGUI::Button* createButton(
            MyGUI::Widget* parent,
            int x, int y, int w, int h,
            const std::string& skin,
            const std::string& caption,
            const std::string& name,
            MyGUI::delegates::CDelegate1<MyGUI::Widget*>::IDelegate* handler)
        {
            if (!parent) return nullptr;

            MyGUI::Button* b = parent->createWidget<MyGUI::Button>(
                skin, x, y, w, h,
                MyGUI::Align::Left | MyGUI::Align::Top,
                name);

            if (b)
            {
                b->setCaption(caption);
                if (handler)
                    b->eventMouseButtonClick += handler;
            }
            return b;
        }

        MyGUI::EditBox* createEditBox(
            MyGUI::Widget* parent,
            int x, int y, int w, int h,
            const std::string& skin,
            const std::string& name,
            bool multiLine,
            bool readOnly)
        {
            if (!parent) return nullptr;

            MyGUI::EditBox* eb = parent->createWidget<MyGUI::EditBox>(
                skin, x, y, w, h,
                MyGUI::Align::Stretch,
                name);

            if (eb)
            {
                eb->setEditMultiLine(multiLine);
                eb->setEditReadOnly(readOnly);
                if (multiLine)
                {
                    eb->setVisibleVScroll(true);
                    eb->setVisibleHScroll(true);
                    eb->setMaxTextLength(MyGUI::ITEM_NONE);
                }
            }
            return eb;
        }
    } // namespace GuiHelpers

} // namespace KenshiLua
