#include "pch.h"
#include "Bindings/MyGUI/MyGuiCallbacks.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/ButtonBinding.h"
#include "Bindings/MyGUI/WindowBinding.h"
#include "Bindings/MyGUI/EditBoxBinding.h"
#include "Bindings/MyGUI/ListBoxBinding.h"
#include "Bindings/MyGUI/ComboBoxBinding.h"
#include "Bindings/MyGUI/TabControlBinding.h"
#include "Bindings/MyGUI/ScrollBarBinding.h"
#include "Bindings/MyGUI/MenuItemBinding.h"
#include "Lua/BindingHelpers.h"
#include "Lua/LuaState.h"
#include "Logger.h"

namespace KenshiLua
{
namespace MyGUIBindings
{

void LuaWidgetCallbackManager::setLuaState(lua_State* L)
{
    m_L = L;
}

lua_State* LuaWidgetCallbackManager::getLuaState() const
{
    if (g_luaState && g_luaState->isValid())
    {
        return g_luaState->getState();
    }
    return m_L;
}

int LuaWidgetCallbackManager::registerCallback(MyGUI::Widget* widget, EventType type, int luaRef)
{
    CallbackKey key = { widget, type };
    auto it = m_callbacks.find(key);
    int id = m_nextCallbackId++;

    if (it != m_callbacks.end())
    {
        lua_State* L = getLuaState();
        if (L && it->second.luaRef != LUA_NOREF)
        {
            luaL_unref(L, LUA_REGISTRYINDEX, it->second.luaRef);
        }
        m_idToKey.erase(it->second.id);
        it->second.id = id;
        it->second.luaRef = luaRef;
        m_idToKey[id] = key;
        return id;
    }
    else
    {
        CallbackValue val;
        val.id = id;
        val.luaRef = luaRef;
        m_callbacks[key] = val;
        m_idToKey[id] = key;
        if (type == OnClick)
        {
            widget->eventMouseButtonClick += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onMouseButtonClick);
        }
        else if (type == OnTextChanged)
        {
            MyGUI::EditBox* editBox = widget->castType<MyGUI::EditBox>(false);
            if (editBox)
            {
                editBox->eventEditTextChange += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onEditTextChange);
            }
        }
        else if (type == OnWindowButtonPressed)
        {
            MyGUI::Window* window = widget->castType<MyGUI::Window>(false);
            if (window)
            {
                window->eventWindowButtonPressed += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onWindowButtonPressed);
            }
        }
        else if (type == OnMouseButtonPressed)
        {
            widget->eventMouseButtonPressed += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onMouseButtonPressed);
        }
        else if (type == OnMouseButtonReleased)
        {
            widget->eventMouseButtonReleased += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onMouseButtonReleased);
        }
        else if (type == OnMouseSetFocus)
        {
            widget->eventMouseSetFocus += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onMouseSetFocus);
        }
        else if (type == OnMouseLostFocus)
        {
            widget->eventMouseLostFocus += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onMouseLostFocus);
        }
        else if (type == OnMouseMove)
        {
            widget->eventMouseMove += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onMouseMove);
        }
        else if (type == OnMouseWheel)
        {
            widget->eventMouseWheel += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onMouseWheel);
        }
        else if (type == OnKeyButtonPressed)
        {
            widget->eventKeyButtonPressed += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onKeyButtonPressed);
        }
        else if (type == OnKeyButtonReleased)
        {
            widget->eventKeyButtonReleased += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onKeyButtonReleased);
        }
        else if (type == OnComboAccept)
        {
            MyGUI::ComboBox* comboBox = widget->castType<MyGUI::ComboBox>(false);
            if (comboBox)
            {
                comboBox->eventComboAccept += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onComboAccept);
            }
        }
        else if (type == OnComboChangePosition)
        {
            MyGUI::ComboBox* comboBox = widget->castType<MyGUI::ComboBox>(false);
            if (comboBox)
            {
                comboBox->eventComboChangePosition += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onComboChangePosition);
            }
        }
        else if (type == OnListSelectAccept)
        {
            MyGUI::ListBox* listBox = widget->castType<MyGUI::ListBox>(false);
            if (listBox)
            {
                listBox->eventListSelectAccept += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onListSelectAccept);
            }
        }
        else if (type == OnListChangePosition)
        {
            MyGUI::ListBox* listBox = widget->castType<MyGUI::ListBox>(false);
            if (listBox)
            {
                listBox->eventListChangePosition += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onListChangePosition);
            }
        }
        else if (type == OnWindowChangeCoord)
        {
            MyGUI::Window* window = widget->castType<MyGUI::Window>(false);
            if (window)
            {
                window->eventWindowChangeCoord += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onWindowChangeCoord);
            }
        }
        else if (type == OnScrollChangePosition)
        {
            MyGUI::ScrollBar* scrollBar = widget->castType<MyGUI::ScrollBar>(false);
            if (scrollBar)
            {
                scrollBar->eventScrollChangePosition += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onScrollChangePosition);
            }
        }
        else if (type == OnTabChangeSelect)
        {
            MyGUI::TabControl* tabControl = widget->castType<MyGUI::TabControl>(false);
            if (tabControl)
            {
                tabControl->eventTabChangeSelect += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onTabChangeSelect);
            }
        }
        else if (type == OnMenuAccept)
        {
            MyGUI::MenuControl* menu = widget->castType<MyGUI::MenuControl>(false);
            if (menu)
            {
                menu->eventMenuCtrlAccept += MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onMenuAccept);
            }
        }
    }
    return id;
}

bool LuaWidgetCallbackManager::unregisterCallback(int callbackId)
{
    auto it = m_idToKey.find(callbackId);
    if (it == m_idToKey.end()) return false;

    CallbackKey key = it->second;
    m_idToKey.erase(it);

    auto cbIt = m_callbacks.find(key);
    if (cbIt != m_callbacks.end())
    {
        lua_State* L = getLuaState();
        if (L && cbIt->second.luaRef != LUA_NOREF)
        {
            luaL_unref(L, LUA_REGISTRYINDEX, cbIt->second.luaRef);
        }
        m_callbacks.erase(cbIt);
    }
    return true;
}

bool LuaWidgetCallbackManager::unregisterCallback(MyGUI::Widget* widget, EventType type)
{
    CallbackKey key = { widget, type };
    auto cbIt = m_callbacks.find(key);
    if (cbIt == m_callbacks.end()) return false;

    m_idToKey.erase(cbIt->second.id);
    lua_State* L = getLuaState();
    if (L && cbIt->second.luaRef != LUA_NOREF)
    {
        luaL_unref(L, LUA_REGISTRYINDEX, cbIt->second.luaRef);
    }
    m_callbacks.erase(cbIt);
    return true;
}

void LuaWidgetCallbackManager::unregisterAll(MyGUI::Widget* widget)
{
    lua_State* L = getLuaState();
    for (int type = 0; type < EventType_Count; ++type)
    {
        CallbackKey key = { widget, (EventType)type };
        auto it = m_callbacks.find(key);
        if (it != m_callbacks.end())
        {
            if (L && it->second.luaRef != LUA_NOREF)
            {
                luaL_unref(L, LUA_REGISTRYINDEX, it->second.luaRef);
            }
            m_idToKey.erase(it->second.id);
            m_callbacks.erase(it);
        }
    }
}

void LuaWidgetCallbackManager::clear()
{
    lua_State* L = getLuaState();
    if (L)
    {
        for (std::map<CallbackKey, CallbackValue>::iterator it = m_callbacks.begin(); it != m_callbacks.end(); ++it)
        {
            if (it->second.luaRef != LUA_NOREF)
            {
                luaL_unref(L, LUA_REGISTRYINDEX, it->second.luaRef);
            }
        }
    }
    m_callbacks.clear();
    m_idToKey.clear();
}

void LuaWidgetCallbackManager::onMouseButtonClick(MyGUI::Widget* sender)
{
    lua_State* L = getLuaState();
    if (!L) return;

    CallbackKey key = { sender, OnClick };
    auto it = m_callbacks.find(key);
    if (it == m_callbacks.end()) return;

    lua_rawgeti(L, LUA_REGISTRYINDEX, it->second.luaRef);
    if (!lua_isfunction(L, -1))
    {
        lua_pop(L, 1);
        return;
    }

    pushWidget(L, sender);

    if (lua_pcall(L, 1, 0, 0) != 0)
    {
        const char* err = lua_tostring(L, -1);
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in click callback: ") + (err ? err : "unknown"));
        lua_pop(L, 1);
    }
}

void LuaWidgetCallbackManager::onEditTextChange(MyGUI::EditBox* sender)
{
    lua_State* L = getLuaState();
    if (!L) return;

    CallbackKey key = { sender, OnTextChanged };
    auto it = m_callbacks.find(key);
    if (it == m_callbacks.end()) return;

    lua_rawgeti(L, LUA_REGISTRYINDEX, it->second.luaRef);
    if (!lua_isfunction(L, -1))
    {
        lua_pop(L, 1);
        return;
    }

    pushWidget(L, sender);

    if (lua_pcall(L, 1, 0, 0) != 0)
    {
        const char* err = lua_tostring(L, -1);
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in text change callback: ") + (err ? err : "unknown"));
        lua_pop(L, 1);
    }
}

void LuaWidgetCallbackManager::onWindowButtonPressed(MyGUI::Window* sender, const std::string& name)
{
    lua_State* L = getLuaState();
    if (!L) return;

    CallbackKey key = { sender, OnWindowButtonPressed };
    auto it = m_callbacks.find(key);
    if (it == m_callbacks.end()) return;

    lua_rawgeti(L, LUA_REGISTRYINDEX, it->second.luaRef);
    if (!lua_isfunction(L, -1))
    {
        lua_pop(L, 1);
        return;
    }

    pushWidget(L, sender);
    lua_pushstring(L, name.c_str());

    if (lua_pcall(L, 2, 0, 0) != 0)
    {
        const char* err = lua_tostring(L, -1);
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in window button pressed callback: ") + (err ? err : "unknown"));
        lua_pop(L, 1);
    }
}

void LuaWidgetCallbackManager::onMouseButtonPressed(MyGUI::Widget* sender, int left, int top, MyGUI::MouseButton id)
{
    lua_State* L = getLuaState();
    if (!L) return;

    CallbackKey key = { sender, OnMouseButtonPressed };
    auto it = m_callbacks.find(key);
    if (it == m_callbacks.end()) return;

    lua_rawgeti(L, LUA_REGISTRYINDEX, it->second.luaRef);
    if (!lua_isfunction(L, -1))
    {
        lua_pop(L, 1);
        return;
    }

    pushWidget(L, sender);
    lua_pushinteger(L, left);
    lua_pushinteger(L, top);
    lua_pushinteger(L, id.getValue());

    if (lua_pcall(L, 4, 0, 0) != 0)
    {
        const char* err = lua_tostring(L, -1);
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in mouse button pressed callback: ") + (err ? err : "unknown"));
        lua_pop(L, 1);
    }
}

void LuaWidgetCallbackManager::onMouseButtonReleased(MyGUI::Widget* sender, int left, int top, MyGUI::MouseButton id)
{
    lua_State* L = getLuaState();
    if (!L) return;

    CallbackKey key = { sender, OnMouseButtonReleased };
    auto it = m_callbacks.find(key);
    if (it == m_callbacks.end()) return;

    lua_rawgeti(L, LUA_REGISTRYINDEX, it->second.luaRef);
    if (!lua_isfunction(L, -1))
    {
        lua_pop(L, 1);
        return;
    }

    pushWidget(L, sender);
    lua_pushinteger(L, left);
    lua_pushinteger(L, top);
    lua_pushinteger(L, id.getValue());

    if (lua_pcall(L, 4, 0, 0) != 0)
    {
        const char* err = lua_tostring(L, -1);
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in mouse button released callback: ") + (err ? err : "unknown"));
        lua_pop(L, 1);
    }
}

void LuaWidgetCallbackManager::onMouseSetFocus(MyGUI::Widget* sender, MyGUI::Widget* oldWidget)
{
    lua_State* L = getLuaState();
    if (!L) return;

    CallbackKey key = { sender, OnMouseSetFocus };
    auto it = m_callbacks.find(key);
    if (it == m_callbacks.end()) return;

    lua_rawgeti(L, LUA_REGISTRYINDEX, it->second.luaRef);
    if (!lua_isfunction(L, -1))
    {
        lua_pop(L, 1);
        return;
    }

    pushWidget(L, sender);
    if (oldWidget)
    {
        pushWidget(L, oldWidget);
    }
    else
    {
        lua_pushnil(L);
    }

    if (lua_pcall(L, 2, 0, 0) != 0)
    {
        const char* err = lua_tostring(L, -1);
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in mouse set focus callback: ") + (err ? err : "unknown"));
        lua_pop(L, 1);
    }
}

void LuaWidgetCallbackManager::onMouseLostFocus(MyGUI::Widget* sender, MyGUI::Widget* newWidget)
{
    lua_State* L = getLuaState();
    if (!L) return;

    CallbackKey key = { sender, OnMouseLostFocus };
    auto it = m_callbacks.find(key);
    if (it == m_callbacks.end()) return;

    lua_rawgeti(L, LUA_REGISTRYINDEX, it->second.luaRef);
    if (!lua_isfunction(L, -1))
    {
        lua_pop(L, 1);
        return;
    }

    pushWidget(L, sender);
    if (newWidget)
    {
        pushWidget(L, newWidget);
    }
    else
    {
        lua_pushnil(L);
    }

    if (lua_pcall(L, 2, 0, 0) != 0)
    {
        const char* err = lua_tostring(L, -1);
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in mouse lost focus callback: ") + (err ? err : "unknown"));
        lua_pop(L, 1);
    }
}

void LuaWidgetCallbackManager::onMouseMove(MyGUI::Widget* sender, int left, int top)
{
    lua_State* L = getLuaState();
    if (!L) return;

    CallbackKey key = { sender, OnMouseMove };
    auto it = m_callbacks.find(key);
    if (it == m_callbacks.end()) return;

    lua_rawgeti(L, LUA_REGISTRYINDEX, it->second.luaRef);
    if (!lua_isfunction(L, -1))
    {
        lua_pop(L, 1);
        return;
    }

    pushWidget(L, sender);
    lua_pushinteger(L, left);
    lua_pushinteger(L, top);

    if (lua_pcall(L, 3, 0, 0) != 0)
    {
        const char* err = lua_tostring(L, -1);
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in mouse move callback: ") + (err ? err : "unknown"));
        lua_pop(L, 1);
    }
}

void LuaWidgetCallbackManager::onMouseWheel(MyGUI::Widget* sender, int rel)
{
    lua_State* L = getLuaState();
    if (!L) return;

    CallbackKey key = { sender, OnMouseWheel };
    auto it = m_callbacks.find(key);
    if (it == m_callbacks.end()) return;

    lua_rawgeti(L, LUA_REGISTRYINDEX, it->second.luaRef);
    if (!lua_isfunction(L, -1))
    {
        lua_pop(L, 1);
        return;
    }

    pushWidget(L, sender);
    lua_pushinteger(L, rel);

    if (lua_pcall(L, 2, 0, 0) != 0)
    {
        const char* err = lua_tostring(L, -1);
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in mouse wheel callback: ") + (err ? err : "unknown"));
        lua_pop(L, 1);
    }
}

void LuaWidgetCallbackManager::onKeyButtonPressed(MyGUI::Widget* sender, MyGUI::KeyCode key, MyGUI::Char ch)
{
    lua_State* L = getLuaState();
    if (!L) return;

    CallbackKey cbKey = { sender, OnKeyButtonPressed };
    auto it = m_callbacks.find(cbKey);
    if (it == m_callbacks.end()) return;

    lua_rawgeti(L, LUA_REGISTRYINDEX, it->second.luaRef);
    if (!lua_isfunction(L, -1))
    {
        lua_pop(L, 1);
        return;
    }

    pushWidget(L, sender);
    lua_pushinteger(L, key.getValue());
    lua_pushinteger(L, ch);

    if (lua_pcall(L, 3, 0, 0) != 0)
    {
        const char* err = lua_tostring(L, -1);
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in key button pressed callback: ") + (err ? err : "unknown"));
        lua_pop(L, 1);
    }
}

void LuaWidgetCallbackManager::onKeyButtonReleased(MyGUI::Widget* sender, MyGUI::KeyCode key)
{
    lua_State* L = getLuaState();
    if (!L) return;

    CallbackKey cbKey = { sender, OnKeyButtonReleased };
    auto it = m_callbacks.find(cbKey);
    if (it == m_callbacks.end()) return;

    lua_rawgeti(L, LUA_REGISTRYINDEX, it->second.luaRef);
    if (!lua_isfunction(L, -1))
    {
        lua_pop(L, 1);
        return;
    }

    pushWidget(L, sender);
    lua_pushinteger(L, key.getValue());

    if (lua_pcall(L, 2, 0, 0) != 0)
    {
        const char* err = lua_tostring(L, -1);
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in key button released callback: ") + (err ? err : "unknown"));
        lua_pop(L, 1);
    }
}

void LuaWidgetCallbackManager::onComboAccept(MyGUI::ComboBox* sender, size_t index)
{
    lua_State* L = getLuaState();
    if (!L) return;

    CallbackKey key = { sender, OnComboAccept };
    auto it = m_callbacks.find(key);
    if (it == m_callbacks.end()) return;

    lua_rawgeti(L, LUA_REGISTRYINDEX, it->second.luaRef);
    if (!lua_isfunction(L, -1))
    {
        lua_pop(L, 1);
        return;
    }

    pushWidget(L, sender);
    lua_pushinteger(L, (lua_Integer)index);

    if (lua_pcall(L, 2, 0, 0) != 0)
    {
        const char* err = lua_tostring(L, -1);
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in combo accept callback: ") + (err ? err : "unknown"));
        lua_pop(L, 1);
    }
}

void LuaWidgetCallbackManager::onComboChangePosition(MyGUI::ComboBox* sender, size_t index)
{
    lua_State* L = getLuaState();
    if (!L) return;

    CallbackKey key = { sender, OnComboChangePosition };
    auto it = m_callbacks.find(key);
    if (it == m_callbacks.end()) return;

    lua_rawgeti(L, LUA_REGISTRYINDEX, it->second.luaRef);
    if (!lua_isfunction(L, -1))
    {
        lua_pop(L, 1);
        return;
    }

    pushWidget(L, sender);
    lua_pushinteger(L, (lua_Integer)index);

    if (lua_pcall(L, 2, 0, 0) != 0)
    {
        const char* err = lua_tostring(L, -1);
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in combo change position callback: ") + (err ? err : "unknown"));
        lua_pop(L, 1);
    }
}

void LuaWidgetCallbackManager::onListSelectAccept(MyGUI::ListBox* sender, size_t index)
{
    lua_State* L = getLuaState();
    if (!L) return;

    CallbackKey key = { sender, OnListSelectAccept };
    auto it = m_callbacks.find(key);
    if (it == m_callbacks.end()) return;

    lua_rawgeti(L, LUA_REGISTRYINDEX, it->second.luaRef);
    if (!lua_isfunction(L, -1))
    {
        lua_pop(L, 1);
        return;
    }

    pushWidget(L, sender);
    lua_pushinteger(L, (lua_Integer)index);

    if (lua_pcall(L, 2, 0, 0) != 0)
    {
        const char* err = lua_tostring(L, -1);
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in list select accept callback: ") + (err ? err : "unknown"));
        lua_pop(L, 1);
    }
}

void LuaWidgetCallbackManager::onListChangePosition(MyGUI::ListBox* sender, size_t index)
{
    lua_State* L = getLuaState();
    if (!L) return;

    CallbackKey key = { sender, OnListChangePosition };
    auto it = m_callbacks.find(key);
    if (it == m_callbacks.end()) return;

    lua_rawgeti(L, LUA_REGISTRYINDEX, it->second.luaRef);
    if (!lua_isfunction(L, -1))
    {
        lua_pop(L, 1);
        return;
    }

    pushWidget(L, sender);
    lua_pushinteger(L, (lua_Integer)index);

    if (lua_pcall(L, 2, 0, 0) != 0)
    {
        const char* err = lua_tostring(L, -1);
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in list change position callback: ") + (err ? err : "unknown"));
        lua_pop(L, 1);
    }
}

void LuaWidgetCallbackManager::onWindowChangeCoord(MyGUI::Window* sender)
{
    lua_State* L = getLuaState();
    if (!L) return;

    CallbackKey key = { sender, OnWindowChangeCoord };
    auto it = m_callbacks.find(key);
    if (it == m_callbacks.end()) return;

    lua_rawgeti(L, LUA_REGISTRYINDEX, it->second.luaRef);
    if (!lua_isfunction(L, -1))
    {
        lua_pop(L, 1);
        return;
    }

    pushWidget(L, sender);

    if (lua_pcall(L, 1, 0, 0) != 0)
    {
        const char* err = lua_tostring(L, -1);
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in window change coord callback: ") + (err ? err : "unknown"));
        lua_pop(L, 1);
    }
}

void LuaWidgetCallbackManager::onScrollChangePosition(MyGUI::ScrollBar* sender, size_t position)
{
    lua_State* L = getLuaState();
    if (!L) return;

    CallbackKey key = { sender, OnScrollChangePosition };
    auto it = m_callbacks.find(key);
    if (it == m_callbacks.end()) return;

    lua_rawgeti(L, LUA_REGISTRYINDEX, it->second.luaRef);
    if (!lua_isfunction(L, -1))
    {
        lua_pop(L, 1);
        return;
    }

    pushWidget(L, sender);
    lua_pushinteger(L, (lua_Integer)position);

    if (lua_pcall(L, 2, 0, 0) != 0)
    {
        const char* err = lua_tostring(L, -1);
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in scroll change position callback: ") + (err ? err : "unknown"));
        lua_pop(L, 1);
    }
}

void LuaWidgetCallbackManager::onTabChangeSelect(MyGUI::TabControl* sender, size_t index)
{
    lua_State* L = getLuaState();
    if (!L) return;

    CallbackKey key = { sender, OnTabChangeSelect };
    auto it = m_callbacks.find(key);
    if (it == m_callbacks.end()) return;

    lua_rawgeti(L, LUA_REGISTRYINDEX, it->second.luaRef);
    if (!lua_isfunction(L, -1))
    {
        lua_pop(L, 1);
        return;
    }

    pushWidget(L, sender);
    lua_pushinteger(L, (lua_Integer)index);

    if (lua_pcall(L, 2, 0, 0) != 0)
    {
        const char* err = lua_tostring(L, -1);
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in tab change select callback: ") + (err ? err : "unknown"));
        lua_pop(L, 1);
    }
}

void LuaWidgetCallbackManager::onMenuAccept(MyGUI::MenuControl* sender, MyGUI::MenuItem* item)
{
    lua_State* L = getLuaState();
    if (!L) return;

    CallbackKey key = { sender, OnMenuAccept };
    auto it = m_callbacks.find(key);
    if (it == m_callbacks.end()) return;

    lua_rawgeti(L, LUA_REGISTRYINDEX, it->second.luaRef);
    if (!lua_isfunction(L, -1))
    {
        lua_pop(L, 1);
        return;
    }

    pushWidget(L, sender);
    pushWidget(L, item);

    if (lua_pcall(L, 2, 0, 0) != 0)
    {
        const char* err = lua_tostring(L, -1);
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in menu accept callback: ") + (err ? err : "unknown"));
        lua_pop(L, 1);
    }
}

LuaWidgetCallbackManager::EventType LuaWidgetCallbackManager::parseEventType(const char* eventType)
{
    if (!eventType) return EventType_Count;

    if (strcmp(eventType, "MouseButtonClick") == 0 || strcmp(eventType, "mouseButtonClick") == 0 || strcmp(eventType, "click") == 0 || strcmp(eventType, "OnClick") == 0 || strcmp(eventType, "onClick") == 0)
        return OnClick;
    if (strcmp(eventType, "EditTextChange") == 0 || strcmp(eventType, "editTextChange") == 0 || strcmp(eventType, "change") == 0 || strcmp(eventType, "OnTextChanged") == 0 || strcmp(eventType, "onTextChanged") == 0)
        return OnTextChanged;
    if (strcmp(eventType, "WindowButtonPressed") == 0 || strcmp(eventType, "windowButtonPressed") == 0 || strcmp(eventType, "OnWindowButtonPressed") == 0 || strcmp(eventType, "onWindowButtonPressed") == 0)
        return OnWindowButtonPressed;
    if (strcmp(eventType, "MouseButtonPressed") == 0 || strcmp(eventType, "mouseButtonPressed") == 0 || strcmp(eventType, "mouseDown") == 0 || strcmp(eventType, "OnMouseButtonPressed") == 0 || strcmp(eventType, "onMouseButtonPressed") == 0)
        return OnMouseButtonPressed;
    if (strcmp(eventType, "MouseButtonReleased") == 0 || strcmp(eventType, "mouseButtonReleased") == 0 || strcmp(eventType, "mouseUp") == 0 || strcmp(eventType, "OnMouseButtonReleased") == 0 || strcmp(eventType, "onMouseButtonReleased") == 0)
        return OnMouseButtonReleased;
    if (strcmp(eventType, "MouseSetFocus") == 0 || strcmp(eventType, "mouseSetFocus") == 0 || strcmp(eventType, "mouseOver") == 0 || strcmp(eventType, "OnMouseSetFocus") == 0 || strcmp(eventType, "onMouseSetFocus") == 0)
        return OnMouseSetFocus;
    if (strcmp(eventType, "MouseLostFocus") == 0 || strcmp(eventType, "mouseLostFocus") == 0 || strcmp(eventType, "mouseOut") == 0 || strcmp(eventType, "OnMouseLostFocus") == 0 || strcmp(eventType, "onMouseLostFocus") == 0)
        return OnMouseLostFocus;
    if (strcmp(eventType, "MouseMove") == 0 || strcmp(eventType, "mouseMove") == 0 || strcmp(eventType, "OnMouseMove") == 0 || strcmp(eventType, "onMouseMove") == 0)
        return OnMouseMove;
    if (strcmp(eventType, "MouseWheel") == 0 || strcmp(eventType, "mouseWheel") == 0 || strcmp(eventType, "OnMouseWheel") == 0 || strcmp(eventType, "onMouseWheel") == 0)
        return OnMouseWheel;
    if (strcmp(eventType, "KeyButtonPressed") == 0 || strcmp(eventType, "keyButtonPressed") == 0 || strcmp(eventType, "keyDown") == 0 || strcmp(eventType, "OnKeyButtonPressed") == 0 || strcmp(eventType, "onKeyButtonPressed") == 0)
        return OnKeyButtonPressed;
    if (strcmp(eventType, "KeyButtonReleased") == 0 || strcmp(eventType, "keyButtonReleased") == 0 || strcmp(eventType, "keyUp") == 0 || strcmp(eventType, "OnKeyButtonReleased") == 0 || strcmp(eventType, "onKeyButtonReleased") == 0)
        return OnKeyButtonReleased;
    if (strcmp(eventType, "ComboAccept") == 0 || strcmp(eventType, "comboAccept") == 0 || strcmp(eventType, "OnComboAccept") == 0 || strcmp(eventType, "onComboAccept") == 0)
        return OnComboAccept;
    if (strcmp(eventType, "ComboChangePosition") == 0 || strcmp(eventType, "comboChangePosition") == 0 || strcmp(eventType, "OnComboChangePosition") == 0 || strcmp(eventType, "onComboChangePosition") == 0)
        return OnComboChangePosition;
    if (strcmp(eventType, "ListSelectAccept") == 0 || strcmp(eventType, "listSelectAccept") == 0 || strcmp(eventType, "OnListSelectAccept") == 0 || strcmp(eventType, "onListSelectAccept") == 0)
        return OnListSelectAccept;
    if (strcmp(eventType, "ListChangePosition") == 0 || strcmp(eventType, "listChangePosition") == 0 || strcmp(eventType, "OnListChangePosition") == 0 || strcmp(eventType, "onListChangePosition") == 0)
        return OnListChangePosition;
    if (strcmp(eventType, "WindowChangeCoord") == 0 || strcmp(eventType, "windowChangeCoord") == 0 || strcmp(eventType, "OnWindowChangeCoord") == 0 || strcmp(eventType, "onWindowChangeCoord") == 0)
        return OnWindowChangeCoord;
    if (strcmp(eventType, "ScrollChangePosition") == 0 || strcmp(eventType, "scrollChangePosition") == 0 || strcmp(eventType, "OnScrollChangePosition") == 0 || strcmp(eventType, "onScrollChangePosition") == 0)
        return OnScrollChangePosition;
    if (strcmp(eventType, "TabChangeSelect") == 0 || strcmp(eventType, "tabChangeSelect") == 0 || strcmp(eventType, "OnTabChangeSelect") == 0 || strcmp(eventType, "onTabChangeSelect") == 0)
        return OnTabChangeSelect;
    if (strcmp(eventType, "MenuAccept") == 0 || strcmp(eventType, "menuAccept") == 0 || strcmp(eventType, "MenuCtrlAccept") == 0 || strcmp(eventType, "OnMenuAccept") == 0 || strcmp(eventType, "onMenuAccept") == 0)
        return OnMenuAccept;

    return EventType_Count;
}

int widget_on(lua_State* L)
{
    MyGUI::Widget* w = testObject<MyGUI::Widget>(L, 1, WidgetBinding::getMetatableName());
    const char* eventType = luaL_checkstring(L, 2);
    luaL_checktype(L, 3, LUA_TFUNCTION);

    LuaWidgetCallbackManager::EventType type = LuaWidgetCallbackManager::parseEventType(eventType);
    if (type == LuaWidgetCallbackManager::EventType_Count)
    {
        return luaL_error(L, "Unsupported event type: %s", eventType);
    }

    lua_pushvalue(L, 3);
    int luaRef = luaL_ref(L, LUA_REGISTRYINDEX);

    int id = 0;
    if (w)
    {
        LuaWidgetCallbackManager::get().setLuaState(L);
        id = LuaWidgetCallbackManager::get().registerCallback(w, type, luaRef);
    }
    else if (luaRef != LUA_NOREF)
    {
        luaL_unref(L, LUA_REGISTRYINDEX, luaRef);
    }

    lua_pushinteger(L, id);
    return 1;
}

int widget_registerCallback(lua_State* L)
{
    return widget_on(L);
}

int widget_off(lua_State* L)
{
    MyGUI::Widget* w = testObject<MyGUI::Widget>(L, 1, WidgetBinding::getMetatableName());
    if (lua_isnumber(L, 2))
    {
        int id = (int)lua_tointeger(L, 2);
        bool ok = LuaWidgetCallbackManager::get().unregisterCallback(id);
        lua_pushboolean(L, ok ? 1 : 0);
        return 1;
    }
    else if (lua_isstring(L, 2))
    {
        const char* eventType = lua_tostring(L, 2);
        LuaWidgetCallbackManager::EventType type = LuaWidgetCallbackManager::parseEventType(eventType);
        if (type != LuaWidgetCallbackManager::EventType_Count && w)
        {
            bool ok = LuaWidgetCallbackManager::get().unregisterCallback(w, type);
            lua_pushboolean(L, ok ? 1 : 0);
            return 1;
        }
    }

    lua_pushboolean(L, 0);
    return 1;
}

} // namespace MyGUIBindings
} // namespace KenshiLua
