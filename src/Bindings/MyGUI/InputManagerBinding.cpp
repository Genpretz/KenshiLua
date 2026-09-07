#include "pch.h"
#include "Bindings/MyGUI/InputManagerBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

int InputManagerBinding::getInstance(lua_State* L)
{
    if (MyGUI::InputManager::getInstancePtr())
    {
        return pushObject<MyGUI::InputManager>(L, MyGUI::InputManager::getInstancePtr(), getMetatableName());
    }
    lua_pushnil(L);
    return 1;
}

int InputManagerBinding::injectMouseMove(lua_State* L)
{
    int absx = (int)luaL_checkinteger(L, 1);
    int absy = (int)luaL_checkinteger(L, 2);
    int absz = (int)luaL_optinteger(L, 3, 0);
    if (MyGUI::InputManager::getInstancePtr())
    {
        bool handled = MyGUI::InputManager::getInstance().injectMouseMove(absx, absy, absz);
        lua_pushboolean(L, handled ? 1 : 0);
        return 1;
    }
    lua_pushboolean(L, 0);
    return 1;
}

int InputManagerBinding::injectMousePress(lua_State* L)
{
    int absx = (int)luaL_checkinteger(L, 1);
    int absy = (int)luaL_checkinteger(L, 2);
    int btn = (int)luaL_optinteger(L, 3, (int)MyGUI::MouseButton::Left);
    if (MyGUI::InputManager::getInstancePtr())
    {
        bool handled = MyGUI::InputManager::getInstance().injectMousePress(absx, absy, MyGUI::MouseButton((MyGUI::MouseButton::Enum)btn));
        lua_pushboolean(L, handled ? 1 : 0);
        return 1;
    }
    lua_pushboolean(L, 0);
    return 1;
}

int InputManagerBinding::injectMouseRelease(lua_State* L)
{
    int absx = (int)luaL_checkinteger(L, 1);
    int absy = (int)luaL_checkinteger(L, 2);
    int btn = (int)luaL_optinteger(L, 3, (int)MyGUI::MouseButton::Left);
    if (MyGUI::InputManager::getInstancePtr())
    {
        bool handled = MyGUI::InputManager::getInstance().injectMouseRelease(absx, absy, MyGUI::MouseButton((MyGUI::MouseButton::Enum)btn));
        lua_pushboolean(L, handled ? 1 : 0);
        return 1;
    }
    lua_pushboolean(L, 0);
    return 1;
}

int InputManagerBinding::injectKeyPress(lua_State* L)
{
    int key = (int)luaL_checkinteger(L, 1);
    int text = (int)luaL_optinteger(L, 2, 0);
    if (MyGUI::InputManager::getInstancePtr())
    {
        bool handled = MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode((MyGUI::KeyCode::Enum)key), (MyGUI::Char)text);
        lua_pushboolean(L, handled ? 1 : 0);
        return 1;
    }
    lua_pushboolean(L, 0);
    return 1;
}

int InputManagerBinding::injectKeyRelease(lua_State* L)
{
    int key = (int)luaL_checkinteger(L, 1);
    if (MyGUI::InputManager::getInstancePtr())
    {
        bool handled = MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode((MyGUI::KeyCode::Enum)key));
        lua_pushboolean(L, handled ? 1 : 0);
        return 1;
    }
    lua_pushboolean(L, 0);
    return 1;
}

int InputManagerBinding::isControlPressed(lua_State* L)
{
    if (MyGUI::InputManager::getInstancePtr())
    {
        lua_pushboolean(L, MyGUI::InputManager::getInstance().isControlPressed() ? 1 : 0);
        return 1;
    }
    lua_pushboolean(L, 0);
    return 1;
}

int InputManagerBinding::isShiftPressed(lua_State* L)
{
    if (MyGUI::InputManager::getInstancePtr())
    {
        lua_pushboolean(L, MyGUI::InputManager::getInstance().isShiftPressed() ? 1 : 0);
        return 1;
    }
    lua_pushboolean(L, 0);
    return 1;
}

int InputManagerBinding::isFocusMouse(lua_State* L)
{
    if (MyGUI::InputManager::getInstancePtr())
    {
        lua_pushboolean(L, MyGUI::InputManager::getInstance().isFocusMouse() ? 1 : 0);
        return 1;
    }
    lua_pushboolean(L, 0);
    return 1;
}

int InputManagerBinding::isFocusKey(lua_State* L)
{
    if (MyGUI::InputManager::getInstancePtr())
    {
        lua_pushboolean(L, MyGUI::InputManager::getInstance().isFocusKey() ? 1 : 0);
        return 1;
    }
    lua_pushboolean(L, 0);
    return 1;
}

int InputManagerBinding::isCaptureMouse(lua_State* L)
{
    if (MyGUI::InputManager::getInstancePtr())
    {
        lua_pushboolean(L, MyGUI::InputManager::getInstance().isCaptureMouse() ? 1 : 0);
        return 1;
    }
    lua_pushboolean(L, 0);
    return 1;
}

int InputManagerBinding::setKeyFocusWidget(lua_State* L)
{
    MyGUI::Widget* w = WidgetBinding::getWidget(L, 1);
    if (MyGUI::InputManager::getInstancePtr())
    {
        MyGUI::InputManager::getInstance().setKeyFocusWidget(w);
    }
    return 0;
}

int InputManagerBinding::resetKeyFocusWidget(lua_State* L)
{
    if (MyGUI::InputManager::getInstancePtr())
    {
        if (lua_gettop(L) >= 1 && !lua_isnil(L, 1))
        {
            MyGUI::Widget* w = WidgetBinding::getWidget(L, 1);
            if (w) MyGUI::InputManager::getInstance().resetKeyFocusWidget(w);
        }
        else
        {
            MyGUI::InputManager::getInstance().resetKeyFocusWidget();
        }
    }
    return 0;
}

int InputManagerBinding::getMouseFocusWidget(lua_State* L)
{
    if (MyGUI::InputManager::getInstancePtr())
    {
        MyGUI::Widget* w = MyGUI::InputManager::getInstance().getMouseFocusWidget();
        if (w) return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

int InputManagerBinding::getKeyFocusWidget(lua_State* L)
{
    if (MyGUI::InputManager::getInstancePtr())
    {
        MyGUI::Widget* w = MyGUI::InputManager::getInstance().getKeyFocusWidget();
        if (w) return MyGUIBindings::pushWidget(L, w);
    }
    lua_pushnil(L);
    return 1;
}

int InputManagerBinding::getMousePosition(lua_State* L)
{
    if (MyGUI::InputManager::getInstancePtr())
    {
        const MyGUI::IntPoint& pt = MyGUI::InputManager::getInstance().getMousePosition();
        lua_pushinteger(L, pt.left);
        lua_pushinteger(L, pt.top);
        return 2;
    }
    lua_pushinteger(L, 0);
    lua_pushinteger(L, 0);
    return 2;
}

int InputManagerBinding::addWidgetModal(lua_State* L)
{
    MyGUI::Widget* w = WidgetBinding::getWidget(L, 1);
    if (w && MyGUI::InputManager::getInstancePtr())
    {
        MyGUI::InputManager::getInstance().addWidgetModal(w);
    }
    return 0;
}

int InputManagerBinding::removeWidgetModal(lua_State* L)
{
    MyGUI::Widget* w = WidgetBinding::getWidget(L, 1);
    if (w && MyGUI::InputManager::getInstancePtr())
    {
        MyGUI::InputManager::getInstance().removeWidgetModal(w);
    }
    return 0;
}

int InputManagerBinding::isModalAny(lua_State* L)
{
    if (MyGUI::InputManager::getInstancePtr())
    {
        lua_pushboolean(L, MyGUI::InputManager::getInstance().isModalAny() ? 1 : 0);
        return 1;
    }
    lua_pushboolean(L, 0);
    return 1;
}

int InputManagerBinding::resetMouseCaptureWidget(lua_State* L)
{
    if (MyGUI::InputManager::getInstancePtr())
    {
        MyGUI::InputManager::getInstance().resetMouseCaptureWidget();
    }
    return 0;
}

void InputManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc", noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getInstance",            getInstance },
        { "injectMouseMove",        injectMouseMove },
        { "injectMousePress",       injectMousePress },
        { "injectMouseRelease",     injectMouseRelease },
        { "injectKeyPress",         injectKeyPress },
        { "injectKeyRelease",       injectKeyRelease },
        { "isControlPressed",       isControlPressed },
        { "isShiftPressed",         isShiftPressed },
        { "isFocusMouse",           isFocusMouse },
        { "isFocusKey",             isFocusKey },
        { "isCaptureMouse",         isCaptureMouse },
        { "setKeyFocusWidget",      setKeyFocusWidget },
        { "resetKeyFocusWidget",    resetKeyFocusWidget },
        { "getMouseFocusWidget",    getMouseFocusWidget },
        { "getKeyFocusWidget",      getKeyFocusWidget },
        { "getMousePosition",       getMousePosition },
        { "addWidgetModal",         addWidgetModal },
        { "removeWidgetModal",      removeWidgetModal },
        { "isModalAny",             isModalAny },
        { "resetMouseCaptureWidget",resetMouseCaptureWidget },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "getInstance", getInstance);
    lua_setglobal(L, "InputManager");
}

} // namespace KenshiLua
