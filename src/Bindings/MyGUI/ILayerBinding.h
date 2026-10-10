#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

// MyGUI::ILayer, borrowed from the LayerManager. Not bound:
//   getLayerItemByPoint - ILayerItem has no Lua binding; use
//     LayerManager:getWidgetFromPoint.
//   getEnumerator, createChildItemNode, destroyChildItemNode, upChildItemNode,
//     renderToTarget, resizeView - layer nodes and render targets have no Lua binding.
class ILayerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.ILayer"; }
    static void registerBinding(lua_State* L);

    static int getName(lua_State* L);
    static int getLayerNodeCount(lua_State* L);
    static int getSize(lua_State* L);
    static int getPosition(lua_State* L);
};

} // namespace KenshiLua
