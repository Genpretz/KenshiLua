#include "pch.h"
#include "Bindings/MyGUI/EnumeratorWidgetPtrSnapshotBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Lua/BindingHelpers.h"
#include <algorithm>

namespace KenshiLua
{
namespace MyGUIBindings
{

// Enumerators that next() has not yet run to the end. An exhausted enumerator has no
// current widget left to clear, so it is removed here before Lua collects it.
static std::unordered_set<EnumeratorWidgetPtrSnapshot*> g_liveEnumerators;

static void releaseEnumerator(EnumeratorWidgetPtrSnapshot* snapshot)
{
    g_liveEnumerators.erase(snapshot);
    MyGUI::VectorWidgetPtr().swap(snapshot->widgets);
}

void unlinkWidgetFromEnumerators(MyGUI::Widget* widget)
{
    std::unordered_set<EnumeratorWidgetPtrSnapshot*>::iterator it = g_liveEnumerators.begin();
    for (; it != g_liveEnumerators.end(); ++it)
    {
        MyGUI::VectorWidgetPtr& widgets = (*it)->widgets;
        std::replace(widgets.begin(), widgets.end(), widget, (MyGUI::Widget*)nullptr);
    }
}

static int enumeratorGc(lua_State* L)
{
    void** ud = (void**)lua_touserdata(L, 1);
    if (ud && *ud)
    {
        EnumeratorWidgetPtrSnapshot* snapshot = static_cast<EnumeratorWidgetPtrSnapshot*>(*ud);
        g_liveEnumerators.erase(snapshot);
        delete snapshot;
        *ud = nullptr;
    }
    return 0;
}

int pushWidgetEnumerator(lua_State* L, MyGUI::EnumeratorWidgetPtr enumerator)
{
    // Without the unlinker, a widget destroyed during the walk would stay in the copy.
    ensureWidgetUnlinkerRegistered();

    EnumeratorWidgetPtrSnapshot* snapshot = new EnumeratorWidgetPtrSnapshot();
    snapshot->current = 0;
    snapshot->first = true;
    while (enumerator.next())
    {
        snapshot->widgets.push_back(enumerator.current());
    }
    g_liveEnumerators.insert(snapshot);

    return pushObjectOwnedCustom<EnumeratorWidgetPtrSnapshot, enumeratorGc>(
        L, snapshot, EnumeratorWidgetPtrSnapshotBinding::getMetatableName());
}

} // namespace MyGUIBindings

static MyGUIBindings::EnumeratorWidgetPtrSnapshot* getInstance(lua_State* L, int idx)
{
    return checkObject<MyGUIBindings::EnumeratorWidgetPtrSnapshot>(
        L, idx, EnumeratorWidgetPtrSnapshotBinding::getMetatableName());
}

// Mirrors MyGUI::Enumerator::next: the first call moves onto the first widget.
int EnumeratorWidgetPtrSnapshotBinding::next(lua_State* L)
{
    MyGUIBindings::EnumeratorWidgetPtrSnapshot* e = getInstance(L, 1);
    bool advanced = false;
    if (e->current < e->widgets.size())
    {
        if (e->first)
        {
            e->first = false;
            advanced = true;
        }
        else
        {
            ++e->current;
            advanced = e->current < e->widgets.size();
        }
    }
    if (!advanced)
    {
        // Drop the copy and stop receiving destruction notifications. As at the end of
        // MyGUI's enumerator, next() keeps returning false and there is no current widget.
        MyGUIBindings::releaseEnumerator(e);
        e->current = 0;
        e->first = false;
    }
    lua_pushboolean(L, advanced ? 1 : 0);
    return 1;
}

int EnumeratorWidgetPtrSnapshotBinding::current(lua_State* L)
{
    MyGUIBindings::EnumeratorWidgetPtrSnapshot* e = getInstance(L, 1);
    if (e->current >= e->widgets.size())
    {
        return luaL_error(L, "EnumeratorWidgetPtr:current: the enumerator has no current widget; "
            "call current() only after next() returns true");
    }
    // nil when the widget was destroyed after getEnumerator copied it.
    return MyGUIBindings::pushWidget(L, e->widgets[e->current]);
}

void EnumeratorWidgetPtrSnapshotBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc", noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "next",    next },
        { "current", current },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);
}

} // namespace KenshiLua
