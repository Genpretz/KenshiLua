#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
namespace MyGUIBindings
{

// The widgets a MyGUI::EnumeratorWidgetPtr walked when getEnumerator was called.
// MyGUI's enumerator holds iterators into the live child vector, which creating or
// destroying a widget invalidates, and Lua can keep an enumerator across such changes.
// The copy keeps next() and current() valid; a widget destroyed after the copy was
// made reads back as nil.
struct EnumeratorWidgetPtrSnapshot
{
    MyGUI::VectorWidgetPtr widgets;
    size_t current;
    bool first;
};

// Clears a destroyed widget from every enumerator still being walked. Called by the
// MyGUI unlinker before the widget is freed.
void unlinkWidgetFromEnumerators(MyGUI::Widget* widget);

// Pushes an owned Lua enumerator over a copy of the enumerator's widgets.
int pushWidgetEnumerator(lua_State* L, MyGUI::EnumeratorWidgetPtr enumerator);

} // namespace MyGUIBindings

class EnumeratorWidgetPtrSnapshotBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.EnumeratorWidgetPtrSnapshot"; }
    static void registerBinding(lua_State* L);

    static int next(lua_State* L);
    static int current(lua_State* L);
};

} // namespace KenshiLua
