#include "pch.h"
#include "Bindings/MyGUI/EnumeratorLayerSnapshotBinding.h"
#include "Bindings/MyGUI/ILayerBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
namespace MyGUIBindings
{

int pushLayerEnumerator(lua_State* L, MyGUI::LayerManager::EnumeratorLayer enumerator)
{
    EnumeratorLayerSnapshot snapshot;
    snapshot.current = 0;
    snapshot.first = true;
    while (enumerator.next())
    {
        snapshot.layers.push_back(enumerator.current());
    }
    return pushValue<EnumeratorLayerSnapshot>(L, snapshot, EnumeratorLayerSnapshotBinding::getMetatableName());
}

} // namespace MyGUIBindings

static MyGUIBindings::EnumeratorLayerSnapshot* getInstance(lua_State* L, int idx)
{
    return checkObject<MyGUIBindings::EnumeratorLayerSnapshot>(
        L, idx, EnumeratorLayerSnapshotBinding::getMetatableName());
}

// Mirrors MyGUI::Enumerator::next: the first call moves onto the first layer.
int EnumeratorLayerSnapshotBinding::next(lua_State* L)
{
    MyGUIBindings::EnumeratorLayerSnapshot* e = getInstance(L, 1);
    bool advanced = false;
    if (e->current < e->layers.size())
    {
        if (e->first)
        {
            e->first = false;
            advanced = true;
        }
        else
        {
            ++e->current;
            advanced = e->current < e->layers.size();
        }
    }
    if (!advanced)
    {
        // As at the end of MyGUI's enumerator, next() keeps returning false and
        // there is no current layer.
        MyGUI::LayerManager::VectorLayer().swap(e->layers);
        e->current = 0;
        e->first = false;
    }
    lua_pushboolean(L, advanced ? 1 : 0);
    return 1;
}

int EnumeratorLayerSnapshotBinding::current(lua_State* L)
{
    MyGUIBindings::EnumeratorLayerSnapshot* e = getInstance(L, 1);
    if (e->current >= e->layers.size())
    {
        return luaL_error(L, "EnumeratorLayerSnapshot:current: the enumerator has no current layer; "
            "call current() only after next() returns true");
    }
    return pushObject<MyGUI::ILayer>(L, e->layers[e->current], ILayerBinding::getMetatableName());
}

void EnumeratorLayerSnapshotBinding::registerBinding(lua_State* L)
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
