#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

// MyGUI::LayerManager. Not bound:
//   initialise, shutdown, resizeView - engine lifecycle, called by MyGUI itself.
//   createLayerAt - creates engine layers owned by the manager.
//   renderToTarget - IRenderTarget has no Lua binding.
class LayerManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.LayerManager"; }
    static void registerBinding(lua_State* L);

    static int getInstance(lua_State* L);
    static int attachToLayerNode(lua_State* L);
    static int detachFromLayer(lua_State* L);
    static int upLayerItem(lua_State* L);
    static int isExist(lua_State* L);
    static int getEnumerator(lua_State* L);
    static int getByName(lua_State* L);
    static int getLayerCount(lua_State* L);
    static int getLayer(lua_State* L);
    static int getWidgetFromPoint(lua_State* L);
    static int getCategoryName(lua_State* L);
};

} // namespace KenshiLua
