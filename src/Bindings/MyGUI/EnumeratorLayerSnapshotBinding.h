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

// The layers a MyGUI::LayerManager::EnumeratorLayer walked when getEnumerator was
// called. MyGUI's enumerator holds iterators into the manager's live layer vector,
// which Lua could keep past a change to it. Unlike widgets, MyGUI reports no layer
// destruction, so a layer destroyed after the copy was made is not detected; the
// same applies to an ILayer kept from LayerManager:getLayer.
struct EnumeratorLayerSnapshot
{
    MyGUI::LayerManager::VectorLayer layers;
    size_t current;
    bool first;
};

// Pushes an owned Lua enumerator over a copy of the enumerator's layers.
int pushLayerEnumerator(lua_State* L, MyGUI::LayerManager::EnumeratorLayer enumerator);

} // namespace MyGUIBindings

class EnumeratorLayerSnapshotBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.EnumeratorLayerSnapshot"; }
    static void registerBinding(lua_State* L);

    static int next(lua_State* L);
    static int current(lua_State* L);
};

} // namespace KenshiLua
