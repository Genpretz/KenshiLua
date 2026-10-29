#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class RendererBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Renderer"; }
    static void registerBinding(lua_State* L);

    static int shutDown(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int createLight(lua_State* L);
    static int go(lua_State* L);
    static int initialiseScene(lua_State* L);
    static int createDebugBox(lua_State* L);
    static int destroy(lua_State* L);
    static int getSceneManager(lua_State* L);
    static int getRenderSystem(lua_State* L);
    static int getRootSceneNode(lua_State* L);
    static int getCamera(lua_State* L);
    static int getViewport(lua_State* L);
    static int getRoot(lua_State* L);
    static int getScreenWidth(lua_State* L);
    static int getScreenHeight(lua_State* L);
    static int getWorkspace(lua_State* L);
    static int getSceneRelativeOrigin(lua_State* L);
    static int validateCompositor(lua_State* L);
    static int setupPostProcessing(lua_State* L);
    static int refreshActiveCompositor(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};

} // namespace KenshiLua

