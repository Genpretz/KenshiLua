#include "pch.h"
#include "kenshi/Renderer.h"
#include "RendererBinding.h"
#include "RendererTBinding.h"
#include "RenderToTextureotronBinding.h"
#include "GameDataBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(offsetof(Renderer, terrainDecalManager) == 0x20, "Renderer::terrainDecalManager offset mismatch");
static_assert(offsetof(Renderer, renderToTextureIconMachine) == 0x28, "Renderer::renderToTextureIconMachine offset mismatch");
static_assert(offsetof(Renderer, preloadedPaints) == 0x30, "Renderer::preloadedPaints offset mismatch");
static_assert(offsetof(Renderer, camera) == 0x58, "Renderer::camera offset mismatch");
static_assert(offsetof(Renderer, scene) == 0x60, "Renderer::scene offset mismatch");
static_assert(offsetof(Renderer, root) == 0x68, "Renderer::root offset mismatch");
static_assert(offsetof(Renderer, viewport) == 0x70, "Renderer::viewport offset mismatch");
static_assert(offsetof(Renderer, window) == 0x78, "Renderer::window offset mismatch");
static_assert(offsetof(Renderer, mFrameListener) == 0x80, "Renderer::mFrameListener offset mismatch");
static_assert(offsetof(Renderer, workspace) == 0x88, "Renderer::workspace offset mismatch");
static_assert(offsetof(Renderer, pixelMotionBlurListener) == 0x90, "Renderer::pixelMotionBlurListener offset mismatch");

static Renderer* getInstance(lua_State* L, int idx)
{
    return checkObject<Renderer>(L, idx, RendererBinding::getMetatableName());
}

static int Renderer_get_terrainDecalManager(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    if (!instance->terrainDecalManager) { lua_pushnil(L); return 1; }
    lua_pushlightuserdata(L, (void*)instance->terrainDecalManager);
    return 1;
}

static int Renderer_get_renderToTextureIconMachine(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    if (!instance->renderToTextureIconMachine) { lua_pushnil(L); return 1; }
    return pushObject<RenderToTextureotron>(L, instance->renderToTextureIconMachine, RenderToTextureotronBinding::getMetatableName());
}

static int Renderer_set_renderToTextureIconMachine(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    instance->renderToTextureIconMachine = lua_isnoneornil(L, 2) ? nullptr : checkObject<RenderToTextureotron>(L, 2, RenderToTextureotronBinding::getMetatableName());
    return 0;
}

static int Renderer_get_camera(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    if (!instance->camera) { lua_pushnil(L); return 1; }
    lua_pushlightuserdata(L, (void*)instance->camera);
    return 1;
}

static int Renderer_get_scene(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    if (!instance->scene) { lua_pushnil(L); return 1; }
    lua_pushlightuserdata(L, (void*)instance->scene);
    return 1;
}

static int Renderer_get_root(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    if (!instance->root) { lua_pushnil(L); return 1; }
    lua_pushlightuserdata(L, (void*)instance->root);
    return 1;
}

static int Renderer_get_viewport(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    if (!instance->viewport) { lua_pushnil(L); return 1; }
    lua_pushlightuserdata(L, (void*)instance->viewport);
    return 1;
}

static int Renderer_get_window(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    if (!instance->window) { lua_pushnil(L); return 1; }
    lua_pushlightuserdata(L, (void*)instance->window);
    return 1;
}

static int Renderer_get_workspace(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    if (!instance->workspace) { lua_pushnil(L); return 1; }
    lua_pushlightuserdata(L, (void*)instance->workspace);
    return 1;
}

/*
Skipped methods/members needing manual RVA offset binding if required:
  - static std::string DefaultMaterialName (RVA = 0x1FC34E8, unexported static symbol)
*/

int RendererBinding::shutDown(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    instance->shutDown();
    return 0;
}

int RendererBinding::update(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    instance->update();
    return 0;
}

int RendererBinding::_NV_update(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    instance->_NV_update();
    return 0;
}

int RendererBinding::createLight(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    GameData* data = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool indoors = lua_toboolean(L, 3) != 0;
    int floor = (int)luaL_optinteger(L, 4, 0);
    Ogre::Light* res = instance->createLight(data, indoors, floor);
    if (!res) { lua_pushnil(L); return 1; }
    lua_pushlightuserdata(L, (void*)res);
    return 1;
}

int RendererBinding::go(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    instance->go();
    return 0;
}

int RendererBinding::initialiseScene(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    instance->initialiseScene();
    return 0;
}

int RendererBinding::createDebugBox(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    Ogre::Vector3 a = Ogre::Vector3::ZERO;
    Ogre::Vector3 b = Ogre::Vector3::ZERO;
    readVector3(L, 2, a);
    readVector3(L, 3, b);
    Ogre::Entity* res = instance->createDebugBox(a, b);
    if (!res) { lua_pushnil(L); return 1; }
    lua_pushlightuserdata(L, (void*)res);
    return 1;
}

int RendererBinding::destroy(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    void* ptr = lua_touserdata(L, 2);
    if (!ptr) return luaL_error(L, "Argument 1 must be lightuserdata pointer");
    if (lua_gettop(L) >= 3 || lua_isboolean(L, 3))
    {
        bool destroyAttached = lua_toboolean(L, 3) != 0;
        instance->destroy((Ogre::SceneNode*)ptr, destroyAttached);
    }
    else
    {
        instance->destroy((Ogre::Light*)ptr);
    }
    return 0;
}

int RendererBinding::getSceneManager(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    Ogre::SceneManager* res = instance->getSceneManager();
    if (!res) { lua_pushnil(L); return 1; }
    lua_pushlightuserdata(L, (void*)res);
    return 1;
}

int RendererBinding::getRenderSystem(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    Ogre::RenderSystem* res = instance->getRenderSystem();
    if (!res) { lua_pushnil(L); return 1; }
    lua_pushlightuserdata(L, (void*)res);
    return 1;
}

int RendererBinding::getRootSceneNode(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    Ogre::SceneNode* res = instance->getRootSceneNode();
    if (!res) { lua_pushnil(L); return 1; }
    lua_pushlightuserdata(L, (void*)res);
    return 1;
}

int RendererBinding::getCamera(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    Ogre::Camera* res = instance->getCamera();
    if (!res) { lua_pushnil(L); return 1; }
    lua_pushlightuserdata(L, (void*)res);
    return 1;
}

int RendererBinding::getViewport(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    Ogre::Viewport* res = instance->getViewport();
    if (!res) { lua_pushnil(L); return 1; }
    lua_pushlightuserdata(L, (void*)res);
    return 1;
}

int RendererBinding::getRoot(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    Ogre::Root* res = instance->getRoot();
    if (!res) { lua_pushnil(L); return 1; }
    lua_pushlightuserdata(L, (void*)res);
    return 1;
}

int RendererBinding::getScreenWidth(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    float res = instance->getScreenWidth();
    lua_pushnumber(L, (lua_Number)res);
    return 1;
}

int RendererBinding::getScreenHeight(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    float res = instance->getScreenHeight();
    lua_pushnumber(L, (lua_Number)res);
    return 1;
}

int RendererBinding::getWorkspace(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    Ogre::CompositorWorkspace* res = instance->getWorkspace();
    if (!res) { lua_pushnil(L); return 1; }
    lua_pushlightuserdata(L, (void*)res);
    return 1;
}

int RendererBinding::getSceneRelativeOrigin(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    Ogre::Vector3 res = instance->getSceneRelativeOrigin();
    pushVector3(L, res);
    return 1;
}

int RendererBinding::validateCompositor(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    const char* node = luaL_checkstring(L, 2);
    bool res = instance->validateCompositor(node ? node : "");
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int RendererBinding::setupPostProcessing(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    const char* str = luaL_checkstring(L, 2);
    instance->setupPostProcessing(Ogre::IdString(str ? str : ""));
    return 0;
}

int RendererBinding::refreshActiveCompositor(lua_State* L)
{
    Renderer* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Renderer is nil");
    instance->refreshActiveCompositor();
    return 0;
}

int RendererBinding::gc(lua_State* L)
{
    return 0;
}

int RendererBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Renderer object");
    return 1;
}

void RendererBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RendererBinding::gc },
        { "__tostring", RendererBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "shutDown", RendererBinding::shutDown },
        { "update", RendererBinding::update },
        { "_NV_update", RendererBinding::_NV_update },
        { "createLight", RendererBinding::createLight },
        { "go", RendererBinding::go },
        { "initialiseScene", RendererBinding::initialiseScene },
        { "createDebugBox", RendererBinding::createDebugBox },
        { "destroy", RendererBinding::destroy },
        { "getSceneManager", RendererBinding::getSceneManager },
        { "getRenderSystem", RendererBinding::getRenderSystem },
        { "getRootSceneNode", RendererBinding::getRootSceneNode },
        { "getCamera", RendererBinding::getCamera },
        { "getViewport", RendererBinding::getViewport },
        { "getRoot", RendererBinding::getRoot },
        { "getScreenWidth", RendererBinding::getScreenWidth },
        { "getScreenHeight", RendererBinding::getScreenHeight },
        { "getWorkspace", RendererBinding::getWorkspace },
        { "getSceneRelativeOrigin", RendererBinding::getSceneRelativeOrigin },
        { "validateCompositor", RendererBinding::validateCompositor },
        { "setupPostProcessing", RendererBinding::setupPostProcessing },
        { "refreshActiveCompositor", RendererBinding::refreshActiveCompositor },
        { 0, 0 }
    };

    registerClass(
        L,
        RendererBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, RendererBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "terrainDecalManager", Renderer_get_terrainDecalManager);
    registerGetter(L, "renderToTextureIconMachine", Renderer_get_renderToTextureIconMachine);
    registerGetter(L, "camera", Renderer_get_camera);
    registerGetter(L, "scene", Renderer_get_scene);
    registerGetter(L, "root", Renderer_get_root);
    registerGetter(L, "viewport", Renderer_get_viewport);
    registerGetter(L, "window", Renderer_get_window);
    registerGetter(L, "workspace", Renderer_get_workspace);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "renderToTextureIconMachine", Renderer_set_renderToTextureIconMachine);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua

