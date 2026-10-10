#pragma once

#include "pch.h"
#include <MyGUI.h>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
namespace MyGUIBindings
{

void trackLuaCreatedWidget(lua_State* L, MyGUI::Widget* widget, MyGUI::Widget* parent);
void untrackLuaCreatedWidget(MyGUI::Widget* widget);
void destroyWidgetsBySource(const std::string& source);
void shutdownMyGui();
void cleanupWidgetRecursive(MyGUI::Widget* widget);

// Registers a MyGUI unlinker (once) so that widgets destroyed by the engine or by MyGUI
// itself are removed from KenshiLua's tracking tables and their Lua callbacks are released.
// Without it, a Lua-created widget parented to an engine-owned widget (for example a button
// added to the context menu) leaves a dangling pointer when the engine destroys its parent.
void ensureWidgetUnlinkerRegistered();

// Validates if a skin or template exists in SkinManager or ResourceManager, logging a warning if not found
void validateWidgetSkin(const std::string& type, const std::string& skin);

// Polymorphic widget pusher: detects RTTI type and attaches the exact derived metatable
int pushWidget(lua_State* L, MyGUI::Widget* widget);

// Returns the widget at idx, or null when the value is not a widget userdata.
MyGUI::Widget* toWidget(lua_State* L, int idx);

// Reads a widget argument whose MyGUI type is T or derives from it. Raises a Lua
// argument error for nil, a raw pointer, a non-widget, or a widget of another type.
template <class T>
T* checkWidget(lua_State* L, int idx)
{
    MyGUI::Widget* widget = toWidget(L, idx);
    T* typed = widget ? widget->castType<T>(false) : nullptr;
    if (!typed)
        luaL_argerror(L, idx, lua_pushfstring(L, "MyGUI.%s expected", T::getClassTypeName().c_str()));
    return typed;
}

// Helper to parse widget creation arguments (skin, coords, align, layer/parent, name)
struct WidgetCreateParams
{
    std::string skin;
    int left;
    int top;
    int width;
    int height;
    float relLeft;
    float relTop;
    float relWidth;
    float relHeight;
    bool isRelative;
    MyGUI::Align align;
    std::string layer;
    MyGUI::Widget* parent;
    std::string name;
};

WidgetCreateParams parseWidgetParams(lua_State* L, int startIdx, const std::string& defaultSkin, bool forceRelative = false);

// Convert Lua table or arguments to MyGUI value types
MyGUI::IntCoord readIntCoord(lua_State* L, int idx);
MyGUI::IntPoint readIntPoint(lua_State* L, int idx);
MyGUI::IntSize readIntSize(lua_State* L, int idx);
MyGUI::IntRect readIntRect(lua_State* L, int idx);
MyGUI::Colour readColour(lua_State* L, int idx);

} // namespace MyGUIBindings
} // namespace KenshiLua
