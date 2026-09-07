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

// Validates if a skin or template exists in SkinManager or ResourceManager, logging a warning if not found
void validateWidgetSkin(const std::string& type, const std::string& skin);

// Polymorphic widget pusher: detects RTTI type and attaches the exact derived metatable
int pushWidget(lua_State* L, MyGUI::Widget* widget);

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
