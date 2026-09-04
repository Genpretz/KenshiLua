#pragma once

#include "pch.h"
#include <MyGUI.h>
#include <map>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
namespace MyGUIBindings
{

class LuaWidgetCallbackManager
{
public:
    enum EventType
    {
        OnClick,
        OnTextChanged,
        OnWindowButtonPressed,
        OnMouseButtonPressed,
        OnMouseButtonReleased,
        OnMouseSetFocus,
        OnMouseLostFocus,
        OnMouseMove,
        OnMouseWheel,
        OnKeyButtonPressed,
        OnKeyButtonReleased,
        OnComboAccept,
        OnComboChangePosition,
        OnListSelectAccept,
        OnListChangePosition,
        OnWindowChangeCoord,
        OnScrollChangePosition,
        OnTabChangeSelect,
        OnMenuAccept,
        EventType_Count
    };

    struct CallbackKey
    {
        MyGUI::Widget* widget;
        EventType type;

        bool operator<(const CallbackKey& o) const
        {
            if (widget != o.widget) return widget < o.widget;
            return type < o.type;
        }
    };

    static LuaWidgetCallbackManager& get()
    {
        static LuaWidgetCallbackManager s_instance;
        return s_instance;
    }

    void setLuaState(lua_State* L);
    lua_State* getLuaState() const;

    void registerCallback(MyGUI::Widget* widget, EventType type, int luaRef);
    void unregisterAll(MyGUI::Widget* widget);
    void clear();

    // Delegate implementations
    void onMouseButtonClick(MyGUI::Widget* sender);
    void onEditTextChange(MyGUI::EditBox* sender);
    void onWindowButtonPressed(MyGUI::Window* sender, const std::string& name);
    void onMouseButtonPressed(MyGUI::Widget* sender, int left, int top, MyGUI::MouseButton id);
    void onMouseButtonReleased(MyGUI::Widget* sender, int left, int top, MyGUI::MouseButton id);
    void onMouseSetFocus(MyGUI::Widget* sender, MyGUI::Widget* oldWidget);
    void onMouseLostFocus(MyGUI::Widget* sender, MyGUI::Widget* newWidget);
    void onMouseMove(MyGUI::Widget* sender, int left, int top);
    void onMouseWheel(MyGUI::Widget* sender, int rel);
    void onKeyButtonPressed(MyGUI::Widget* sender, MyGUI::KeyCode key, MyGUI::Char ch);
    void onKeyButtonReleased(MyGUI::Widget* sender, MyGUI::KeyCode key);
    void onComboAccept(MyGUI::ComboBox* sender, size_t index);
    void onComboChangePosition(MyGUI::ComboBox* sender, size_t index);
    void onListSelectAccept(MyGUI::ListBox* sender, size_t index);
    void onListChangePosition(MyGUI::ListBox* sender, size_t index);
    void onWindowChangeCoord(MyGUI::Window* sender);
    void onScrollChangePosition(MyGUI::ScrollBar* sender, size_t position);
    void onTabChangeSelect(MyGUI::TabControl* sender, size_t index);
    void onMenuAccept(MyGUI::MenuControl* sender, MyGUI::MenuItem* item);

private:
    LuaWidgetCallbackManager() : m_L(nullptr) {}
    std::map<CallbackKey, int> m_callbacks;
    lua_State* m_L;
};

int widget_registerCallback(lua_State* L);

} // namespace MyGUIBindings
} // namespace KenshiLua
