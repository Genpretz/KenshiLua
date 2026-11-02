#include "pch.h"
#include "Bindings/MyGUI/MyGUIEnumBinding.h"
#include "Lua/BindingHelpers.h"

#include <MyGUI.h>
#include <lua.hpp>

namespace KenshiLua
{
    void registerMyGUIAlign(lua_State* L)
    {
        lua_createtable(L, 0, 11);

        setEnum(L, "HCenter", MyGUI::Align::HCenter);
        setEnum(L, "VCenter", MyGUI::Align::VCenter);
        setEnum(L, "Center", MyGUI::Align::Center);
        setEnum(L, "Left", MyGUI::Align::Left);
        setEnum(L, "Right", MyGUI::Align::Right);
        setEnum(L, "HStretch", MyGUI::Align::HStretch);
        setEnum(L, "Top", MyGUI::Align::Top);
        setEnum(L, "Bottom", MyGUI::Align::Bottom);
        setEnum(L, "VStretch", MyGUI::Align::VStretch);
        setEnum(L, "Stretch", MyGUI::Align::Stretch);
        setEnum(L, "Default", MyGUI::Align::Default);

        setNestedClassTable(L, "MyGUI", "Align");
        lua_pop(L, 1);
    }

    void registerMyGUIWidgetStyle(lua_State* L)
    {
        lua_createtable(L, 0, 3);

        setEnum(L, "Child", MyGUI::WidgetStyle::Child);
        setEnum(L, "Overlapped", MyGUI::WidgetStyle::Overlapped);
        setEnum(L, "Popup", MyGUI::WidgetStyle::Popup);

        setNestedClassTable(L, "MyGUI", "WidgetStyle");
        lua_pop(L, 1);
    }

    void registerMyGUIFlowDirection(lua_State* L)
    {
        lua_createtable(L, 0, 4);

        setEnum(L, "LeftToRight", MyGUI::FlowDirection::LeftToRight);
        setEnum(L, "RightToLeft", MyGUI::FlowDirection::RightToLeft);
        setEnum(L, "TopToBottom", MyGUI::FlowDirection::TopToBottom);
        setEnum(L, "BottomToTop", MyGUI::FlowDirection::BottomToTop);

        setNestedClassTable(L, "MyGUI", "FlowDirection");
        lua_pop(L, 1);
    }

    void registerMyGUIMenuItemType(lua_State* L)
    {
        lua_createtable(L, 0, 3);

        setEnum(L, "Normal", MyGUI::MenuItemType::Normal);
        setEnum(L, "Popup", MyGUI::MenuItemType::Popup);
        setEnum(L, "Separator", MyGUI::MenuItemType::Separator);

        setNestedClassTable(L, "MyGUI", "MenuItemType");
        lua_pop(L, 1);
    }

    void registerMyGUIMouseButton(lua_State* L)
    {
        lua_createtable(L, 0, 12);

        setEnum(L, "Left", MyGUI::MouseButton::Left);
        setEnum(L, "Right", MyGUI::MouseButton::Right);
        setEnum(L, "Middle", MyGUI::MouseButton::Middle);
        setEnum(L, "Button0", MyGUI::MouseButton::Button0);
        setEnum(L, "Button1", MyGUI::MouseButton::Button1);
        setEnum(L, "Button2", MyGUI::MouseButton::Button2);
        setEnum(L, "Button3", MyGUI::MouseButton::Button3);
        setEnum(L, "Button4", MyGUI::MouseButton::Button4);
        setEnum(L, "Button5", MyGUI::MouseButton::Button5);
        setEnum(L, "Button6", MyGUI::MouseButton::Button6);
        setEnum(L, "Button7", MyGUI::MouseButton::Button7);
        setEnum(L, "None", MyGUI::MouseButton::None);

        setNestedClassTable(L, "MyGUI", "MouseButton");
        lua_pop(L, 1);
    }

    void registerMyGUIKeyCode(lua_State* L)
    {
        lua_createtable(L, 0, 17);

        setEnum(L, "None", MyGUI::KeyCode::None);
        setEnum(L, "Escape", MyGUI::KeyCode::Escape);
        setEnum(L, "Return", MyGUI::KeyCode::Return);
        setEnum(L, "Space", MyGUI::KeyCode::Space);
        setEnum(L, "Tab", MyGUI::KeyCode::Tab);
        setEnum(L, "Backspace", MyGUI::KeyCode::Backspace);
        setEnum(L, "Delete", MyGUI::KeyCode::Delete);
        setEnum(L, "LeftShift", MyGUI::KeyCode::LeftShift);
        setEnum(L, "RightShift", MyGUI::KeyCode::RightShift);
        setEnum(L, "LeftControl", MyGUI::KeyCode::LeftControl);
        setEnum(L, "RightControl", MyGUI::KeyCode::RightControl);
        setEnum(L, "LeftAlt", MyGUI::KeyCode::LeftAlt);
        setEnum(L, "RightAlt", MyGUI::KeyCode::RightAlt);
        setEnum(L, "ArrowUp", MyGUI::KeyCode::ArrowUp);
        setEnum(L, "ArrowDown", MyGUI::KeyCode::ArrowDown);
        setEnum(L, "ArrowLeft", MyGUI::KeyCode::ArrowLeft);
        setEnum(L, "ArrowRight", MyGUI::KeyCode::ArrowRight);

        setNestedClassTable(L, "MyGUI", "KeyCode");
        lua_pop(L, 1);
    }

    void registerMyGUIResizingPolicy(lua_State* L)
    {
        lua_createtable(L, 0, 3);

        setEnum(L, "Auto", MyGUI::ResizingPolicy::Auto);
        setEnum(L, "Fixed", MyGUI::ResizingPolicy::Fixed);
        setEnum(L, "Fill", MyGUI::ResizingPolicy::Fill);

        setNestedClassTable(L, "MyGUI", "ResizingPolicy");
        lua_pop(L, 1);
    }

    void registerMyGUIEnumBindings(lua_State* L)
    {
        registerMyGUIAlign(L);
        registerMyGUIWidgetStyle(L);
        registerMyGUIFlowDirection(L);
        registerMyGUIMenuItemType(L);
        registerMyGUIMouseButton(L);
        registerMyGUIKeyCode(L);
        registerMyGUIResizingPolicy(L);
    }
}

