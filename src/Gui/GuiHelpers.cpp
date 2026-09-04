#include "pch.h"
#include "Gui/GuiHelpers.h"

#include <Windows.h>
#include <commdlg.h>
#include <cstring>

namespace KenshiLua
{
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

        static ULONGLONG s_lastFileDialogClosedTime = 0;
        static const ULONGLONG FILE_DIALOG_DEBOUNCE_MS = 350;

        std::string openFileDialog(
            const std::string& title,
            const char* filter,
            const std::string& defaultExt,
            const std::string& currentPath)
        {
            ULONGLONG now = GetTickCount64();
            if (now - s_lastFileDialogClosedTime < FILE_DIALOG_DEBOUNCE_MS)
            {
                return "";
            }

            char filename[MAX_PATH] = "";
            if (!currentPath.empty())
            {
                strncpy_s(filename, currentPath.c_str(), MAX_PATH - 1);
            }

            OPENFILENAMEA ofn = {};
            ofn.lStructSize = sizeof(ofn);
            ofn.lpstrFilter = filter;
            ofn.lpstrFile = filename;
            ofn.nMaxFile = MAX_PATH;
            ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR;
            ofn.lpstrDefExt = defaultExt.c_str();
            ofn.lpstrTitle = title.c_str();

            BOOL result = GetOpenFileNameA(&ofn);
            s_lastFileDialogClosedTime = GetTickCount64();

            return result ? std::string(filename) : "";
        }

        std::string saveFileDialog(
            const std::string& title,
            const char* filter,
            const std::string& defaultExt,
            const std::string& defaultFilename,
            const std::string& currentPath)
        {
            ULONGLONG now = GetTickCount64();
            if (now - s_lastFileDialogClosedTime < FILE_DIALOG_DEBOUNCE_MS)
            {
                return "";
            }

            char filename[MAX_PATH] = "";
            if (!defaultFilename.empty())
            {
                strncpy_s(filename, defaultFilename.c_str(), MAX_PATH - 1);
            }
            else if (!currentPath.empty())
            {
                strncpy_s(filename, currentPath.c_str(), MAX_PATH - 1);
            }

            OPENFILENAMEA ofn = {};
            ofn.lStructSize = sizeof(ofn);
            ofn.lpstrFilter = filter;
            ofn.lpstrFile = filename;
            ofn.nMaxFile = MAX_PATH;
            ofn.Flags = OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR;
            ofn.lpstrDefExt = defaultExt.c_str();
            ofn.lpstrTitle = title.c_str();

            BOOL result = GetSaveFileNameA(&ofn);
            s_lastFileDialogClosedTime = GetTickCount64();

            return result ? std::string(filename) : "";
        }

        std::string EscapeMyGuiColourTags(const std::string& text)
        {
            // MyGUI parses "#rrggbb" as an inline colour tag in any caption, including
            // ones set programmatically. "##" is MyGUI's own escape for a literal '#',
            // so double every '#' before handing loaded file content to setCaption().
            std::string out;
            out.reserve(text.size());
            for (size_t i = 0; i < text.size(); ++i)
            {
                out += text[i];
                if (text[i] == '#')
                    out += '#';
            }
            return out;
        }

        void handleWindowButton(MyGUI::Window* sender, const std::string& name,
            bool& edgeHideEnabled, MyGUI::Window* rootWindow)
        {
            if (name == "close")
            {
                if (rootWindow)
                    rootWindow->setVisible(false);
                MyGUI::InputManager::getInstance().resetKeyFocusWidget();
            }
            else if (name == "minimize")
            {
                edgeHideEnabled = !edgeHideEnabled;
                MyGUI::ControllerManager::getInstance().removeItem(sender);
                if (edgeHideEnabled)
                {
                    MyGUI::ControllerItem* item = MyGUI::ControllerManager::getInstance().createItem("ControllerEdgeHide");
                    if (item)
                    {
                        MyGUI::ControllerManager::getInstance().addItem(sender, item);
                    }
                }
            }
        }

    } // namespace GuiHelpers
} // namespace KenshiLua
