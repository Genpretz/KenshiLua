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
#include "Compatibility/LegacyCompat.h"

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
    // Callbacks can be attached to engine-owned widgets, so make sure their
    // entries are released when MyGUI destroys those widgets.
    ensureWidgetUnlinkerRegistered();
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
        attachDelegate(widget, type);
    }
    return id;
}

void LuaWidgetCallbackManager::attachDelegate(MyGUI::Widget* widget, EventType type)
{
    if (!widget || !MyGUI::Gui::getInstancePtr()) return;
    try
    {
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
    catch (...)
    {
    }
}

void LuaWidgetCallbackManager::detachDelegate(MyGUI::Widget* widget, EventType type)
{
    if (!widget || !MyGUI::Gui::getInstancePtr()) return;
    try
    {
        if (type == OnClick)
        {
            widget->eventMouseButtonClick -= MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onMouseButtonClick);
        }
        else if (type == OnTextChanged)
        {
            MyGUI::EditBox* editBox = widget->castType<MyGUI::EditBox>(false);
            if (editBox)
            {
                editBox->eventEditTextChange -= MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onEditTextChange);
            }
        }
        else if (type == OnWindowButtonPressed)
        {
            MyGUI::Window* window = widget->castType<MyGUI::Window>(false);
            if (window)
            {
                window->eventWindowButtonPressed -= MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onWindowButtonPressed);
            }
        }
        else if (type == OnMouseButtonPressed)
        {
            widget->eventMouseButtonPressed -= MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onMouseButtonPressed);
        }
        else if (type == OnMouseButtonReleased)
        {
            widget->eventMouseButtonReleased -= MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onMouseButtonReleased);
        }
        else if (type == OnMouseSetFocus)
        {
            widget->eventMouseSetFocus -= MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onMouseSetFocus);
        }
        else if (type == OnMouseLostFocus)
        {
            widget->eventMouseLostFocus -= MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onMouseLostFocus);
        }
        else if (type == OnMouseMove)
        {
            widget->eventMouseMove -= MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onMouseMove);
        }
        else if (type == OnMouseWheel)
        {
            widget->eventMouseWheel -= MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onMouseWheel);
        }
        else if (type == OnKeyButtonPressed)
        {
            widget->eventKeyButtonPressed -= MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onKeyButtonPressed);
        }
        else if (type == OnKeyButtonReleased)
        {
            widget->eventKeyButtonReleased -= MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onKeyButtonReleased);
        }
        else if (type == OnComboAccept)
        {
            MyGUI::ComboBox* comboBox = widget->castType<MyGUI::ComboBox>(false);
            if (comboBox)
            {
                comboBox->eventComboAccept -= MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onComboAccept);
            }
        }
        else if (type == OnComboChangePosition)
        {
            MyGUI::ComboBox* comboBox = widget->castType<MyGUI::ComboBox>(false);
            if (comboBox)
            {
                comboBox->eventComboChangePosition -= MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onComboChangePosition);
            }
        }
        else if (type == OnListSelectAccept)
        {
            MyGUI::ListBox* listBox = widget->castType<MyGUI::ListBox>(false);
            if (listBox)
            {
                listBox->eventListSelectAccept -= MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onListSelectAccept);
            }
        }
        else if (type == OnListChangePosition)
        {
            MyGUI::ListBox* listBox = widget->castType<MyGUI::ListBox>(false);
            if (listBox)
            {
                listBox->eventListChangePosition -= MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onListChangePosition);
            }
        }
        else if (type == OnWindowChangeCoord)
        {
            MyGUI::Window* window = widget->castType<MyGUI::Window>(false);
            if (window)
            {
                window->eventWindowChangeCoord -= MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onWindowChangeCoord);
            }
        }
        else if (type == OnScrollChangePosition)
        {
            MyGUI::ScrollBar* scrollBar = widget->castType<MyGUI::ScrollBar>(false);
            if (scrollBar)
            {
                scrollBar->eventScrollChangePosition -= MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onScrollChangePosition);
            }
        }
        else if (type == OnTabChangeSelect)
        {
            MyGUI::TabControl* tabControl = widget->castType<MyGUI::TabControl>(false);
            if (tabControl)
            {
                tabControl->eventTabChangeSelect -= MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onTabChangeSelect);
            }
        }
        else if (type == OnMenuAccept)
        {
            MyGUI::MenuControl* menu = widget->castType<MyGUI::MenuControl>(false);
            if (menu)
            {
                menu->eventMenuCtrlAccept -= MyGUI::newDelegate(this, &LuaWidgetCallbackManager::onMenuAccept);
            }
        }
    }
    catch (...)
    {
    }
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
        detachDelegate(key.widget, key.type);
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
    detachDelegate(widget, type);
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
    for (std::map<CallbackKey, CallbackValue>::iterator it = m_callbacks.begin(); it != m_callbacks.end(); ++it)
    {
        if (L && it->second.luaRef != LUA_NOREF)
        {
            luaL_unref(L, LUA_REGISTRYINDEX, it->second.luaRef);
        }
        detachDelegate(it->first.widget, it->first.type);
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

    std::string err;
    if (!LuaState::pcallWithTraceback(L, 1, 0, &err))
    {
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in click callback: ") + (err.empty() ? "unknown" : err));
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

    std::string err;
    if (!LuaState::pcallWithTraceback(L, 1, 0, &err))
    {
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in text change callback: ") + (err.empty() ? "unknown" : err));
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

    std::string err;
    if (!LuaState::pcallWithTraceback(L, 2, 0, &err))
    {
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in window button pressed callback: ") + (err.empty() ? "unknown" : err));
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

    std::string err;
    if (!LuaState::pcallWithTraceback(L, 4, 0, &err))
    {
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in mouse button pressed callback: ") + (err.empty() ? "unknown" : err));
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

    std::string err;
    if (!LuaState::pcallWithTraceback(L, 4, 0, &err))
    {
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in mouse button released callback: ") + (err.empty() ? "unknown" : err));
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

    std::string err;
    if (!LuaState::pcallWithTraceback(L, 2, 0, &err))
    {
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in mouse set focus callback: ") + (err.empty() ? "unknown" : err));
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

    std::string err;
    if (!LuaState::pcallWithTraceback(L, 2, 0, &err))
    {
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in mouse lost focus callback: ") + (err.empty() ? "unknown" : err));
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

    std::string err;
    if (!LuaState::pcallWithTraceback(L, 3, 0, &err))
    {
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in mouse move callback: ") + (err.empty() ? "unknown" : err));
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

    std::string err;
    if (!LuaState::pcallWithTraceback(L, 2, 0, &err))
    {
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in mouse wheel callback: ") + (err.empty() ? "unknown" : err));
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

    std::string err;
    if (!LuaState::pcallWithTraceback(L, 3, 0, &err))
    {
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in key button pressed callback: ") + (err.empty() ? "unknown" : err));
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

    std::string err;
    if (!LuaState::pcallWithTraceback(L, 2, 0, &err))
    {
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in key button released callback: ") + (err.empty() ? "unknown" : err));
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

    std::string err;
    if (!LuaState::pcallWithTraceback(L, 2, 0, &err))
    {
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in combo accept callback: ") + (err.empty() ? "unknown" : err));
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

    std::string err;
    if (!LuaState::pcallWithTraceback(L, 2, 0, &err))
    {
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in combo change position callback: ") + (err.empty() ? "unknown" : err));
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

    std::string err;
    if (!LuaState::pcallWithTraceback(L, 2, 0, &err))
    {
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in list select accept callback: ") + (err.empty() ? "unknown" : err));
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

    std::string err;
    if (!LuaState::pcallWithTraceback(L, 2, 0, &err))
    {
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in list change position callback: ") + (err.empty() ? "unknown" : err));
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

    std::string err;
    if (!LuaState::pcallWithTraceback(L, 1, 0, &err))
    {
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in window change coord callback: ") + (err.empty() ? "unknown" : err));
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

    std::string err;
    if (!LuaState::pcallWithTraceback(L, 2, 0, &err))
    {
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in scroll change position callback: ") + (err.empty() ? "unknown" : err));
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

    std::string err;
    if (!LuaState::pcallWithTraceback(L, 2, 0, &err))
    {
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in tab change select callback: ") + (err.empty() ? "unknown" : err));
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

    std::string err;
    if (!LuaState::pcallWithTraceback(L, 2, 0, &err))
    {
        Logger::get().log(LogLevel_Error, std::string("[MyGUI Callback] Error in menu accept callback: ") + (err.empty() ? "unknown" : err));
    }
}

LuaWidgetCallbackManager::EventType LuaWidgetCallbackManager::parseEventType(const char* eventType)
{
    if (!eventType) return EventType_Count;

    if (strcmp(eventType, "eventMouseButtonClick") == 0)
        return OnClick;
    if (strcmp(eventType, "eventEditTextChange") == 0)
        return OnTextChanged;
    if (strcmp(eventType, "eventWindowButtonPressed") == 0)
        return OnWindowButtonPressed;
    if (strcmp(eventType, "eventMouseButtonPressed") == 0)
        return OnMouseButtonPressed;
    if (strcmp(eventType, "eventMouseButtonReleased") == 0)
        return OnMouseButtonReleased;
    if (strcmp(eventType, "eventMouseSetFocus") == 0)
        return OnMouseSetFocus;
    if (strcmp(eventType, "eventMouseLostFocus") == 0)
        return OnMouseLostFocus;
    if (strcmp(eventType, "eventMouseMove") == 0)
        return OnMouseMove;
    if (strcmp(eventType, "eventMouseWheel") == 0)
        return OnMouseWheel;
    if (strcmp(eventType, "eventKeyButtonPressed") == 0)
        return OnKeyButtonPressed;
    if (strcmp(eventType, "eventKeyButtonReleased") == 0)
        return OnKeyButtonReleased;
    if (strcmp(eventType, "eventComboAccept") == 0)
        return OnComboAccept;
    if (strcmp(eventType, "eventComboChangePosition") == 0)
        return OnComboChangePosition;
    if (strcmp(eventType, "eventListSelectAccept") == 0)
        return OnListSelectAccept;
    if (strcmp(eventType, "eventListChangePosition") == 0)
        return OnListChangePosition;
    if (strcmp(eventType, "eventWindowChangeCoord") == 0)
        return OnWindowChangeCoord;
    if (strcmp(eventType, "eventScrollChangePosition") == 0)
        return OnScrollChangePosition;
    if (strcmp(eventType, "eventTabChangeSelect") == 0)
        return OnTabChangeSelect;
    if (strcmp(eventType, "eventMenuAccept") == 0)
        return OnMenuAccept;

    return EventType_Count;
}

int widget_on(lua_State* L)
{
    MyGUI::Widget* w = WidgetBinding::getWidget(L, 1);
    const char* rawEventType = luaL_checkstring(L, 2);
    luaL_checktype(L, 3, LUA_TFUNCTION);

    // Fast path: Try canonical C++ name first
    LuaWidgetCallbackManager::EventType type = LuaWidgetCallbackManager::parseEventType(rawEventType);

    // Fallback: If unrecognized, check LegacyCompat for deprecated aliases
    if (type == LuaWidgetCallbackManager::EventType_Count)
    {
        std::string source = "";
        lua_Debug ar;
        if (lua_getstack(L, 1, &ar) && lua_getinfo(L, "S", &ar) && ar.source)
        {
            source = ar.source;
        }

        const char* canonical = LegacyCompat::ResolveWidgetEventName(rawEventType, source.c_str());
        if (canonical != rawEventType)
        {
            type = LuaWidgetCallbackManager::parseEventType(canonical);
        }
    }

    if (type == LuaWidgetCallbackManager::EventType_Count)
    {
        return luaL_error(L, "Unsupported event type: %s", rawEventType);
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
    MyGUI::Widget* w = WidgetBinding::getWidget(L, 1);
    if (lua_isnumber(L, 2))
    {
        int id = (int)lua_tointeger(L, 2);
        bool ok = LuaWidgetCallbackManager::get().unregisterCallback(id);
        lua_pushboolean(L, ok ? 1 : 0);
        return 1;
    }
    else if (lua_isstring(L, 2))
    {
        const char* rawEventType = lua_tostring(L, 2);

        // Fast path: Try canonical C++ name first
        LuaWidgetCallbackManager::EventType type = LuaWidgetCallbackManager::parseEventType(rawEventType);

        // Fallback: If unrecognized, check LegacyCompat for deprecated aliases
        if (type == LuaWidgetCallbackManager::EventType_Count)
        {
            std::string source = "";
            lua_Debug ar;
            if (lua_getstack(L, 1, &ar) && lua_getinfo(L, "S", &ar) && ar.source)
            {
                source = ar.source;
            }

            const char* canonical = LegacyCompat::ResolveWidgetEventName(rawEventType, source.c_str());
            if (canonical != rawEventType)
            {
                type = LuaWidgetCallbackManager::parseEventType(canonical);
            }
        }

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
