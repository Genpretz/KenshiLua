#include "pch.h"
#include "kenshi/KingOfRenderThread.h"
#include "KingOfRenderThreadBinding.h"
#include "RendererBinding.h"
#include "CameraClassBinding.h"
#include "TerrainBinding.h"
#include "Gui/TitleScreenBinding.h"
#include "GameDataBinding.h"
#include "MeshDataLookupBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/Kenshi/Util/iVector2Binding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(offsetof(KingOfRenderThread, TIME) == 0x0, "KingOfRenderThread::TIME offset mismatch");
static_assert(offsetof(KingOfRenderThread, render) == 0x8, "KingOfRenderThread::render offset mismatch");
static_assert(offsetof(KingOfRenderThread, camera) == 0x10, "KingOfRenderThread::camera offset mismatch");
static_assert(offsetof(KingOfRenderThread, terrain) == 0x18, "KingOfRenderThread::terrain offset mismatch");
static_assert(offsetof(KingOfRenderThread, titleScreen) == 0x20, "KingOfRenderThread::titleScreen offset mismatch");

static KingOfRenderThread* getInstance(lua_State* L, int idx)
{
    return checkObject<KingOfRenderThread>(L, idx, KingOfRenderThreadBinding::getMetatableName());
}

static int KingOfRenderThread_get_TIME(lua_State* L)
{
    KingOfRenderThread* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "KingOfRenderThread is nil");
    lua_pushnumber(L, (lua_Number)instance->TIME);
    return 1;
}

static int KingOfRenderThread_set_TIME(lua_State* L)
{
    KingOfRenderThread* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "KingOfRenderThread is nil");
    instance->TIME = (float)luaL_checknumber(L, 2);
    return 0;
}

static int KingOfRenderThread_get_render(lua_State* L)
{
    KingOfRenderThread* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "KingOfRenderThread is nil");
    if (!instance->render) { lua_pushnil(L); return 1; }
    return pushObject<Renderer>(L, instance->render, RendererBinding::getMetatableName());
}

static int KingOfRenderThread_set_render(lua_State* L)
{
    KingOfRenderThread* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "KingOfRenderThread is nil");
    instance->render = lua_isnoneornil(L, 2) ? nullptr : checkObject<Renderer>(L, 2, RendererBinding::getMetatableName());
    return 0;
}

static int KingOfRenderThread_get_camera(lua_State* L)
{
    KingOfRenderThread* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "KingOfRenderThread is nil");
    if (!instance->camera) { lua_pushnil(L); return 1; }
    return pushObject<CameraClass>(L, instance->camera, CameraClassBinding::getMetatableName());
}

static int KingOfRenderThread_set_camera(lua_State* L)
{
    KingOfRenderThread* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "KingOfRenderThread is nil");
    instance->camera = lua_isnoneornil(L, 2) ? nullptr : checkObject<CameraClass>(L, 2, CameraClassBinding::getMetatableName());
    return 0;
}

static int KingOfRenderThread_get_terrain(lua_State* L)
{
    KingOfRenderThread* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "KingOfRenderThread is nil");
    if (!instance->terrain) { lua_pushnil(L); return 1; }
    return pushObject<Terrain>(L, instance->terrain, TerrainBinding::getMetatableName());
}

static int KingOfRenderThread_set_terrain(lua_State* L)
{
    KingOfRenderThread* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "KingOfRenderThread is nil");
    instance->terrain = lua_isnoneornil(L, 2) ? nullptr : checkObject<Terrain>(L, 2, TerrainBinding::getMetatableName());
    return 0;
}

static int KingOfRenderThread_get_titleScreen(lua_State* L)
{
    KingOfRenderThread* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "KingOfRenderThread is nil");
    if (!instance->titleScreen) { lua_pushnil(L); return 1; }
    return pushObject<TitleScreen>(L, instance->titleScreen, TitleScreenBinding::getMetatableName());
}

static int KingOfRenderThread_set_titleScreen(lua_State* L)
{
    KingOfRenderThread* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "KingOfRenderThread is nil");
    instance->titleScreen = lua_isnoneornil(L, 2) ? nullptr : checkObject<TitleScreen>(L, 2, TitleScreenBinding::getMetatableName());
    return 0;
}

int KingOfRenderThreadBinding::startup(lua_State* L)
{
    KingOfRenderThread* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "KingOfRenderThread is nil");
    instance->startup();
    return 0;
}

int KingOfRenderThreadBinding::initialisation(lua_State* L)
{
    KingOfRenderThread* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "KingOfRenderThread is nil");
    instance->initialisation();
    return 0;
}

int KingOfRenderThreadBinding::mainloop(lua_State* L)
{
    KingOfRenderThread* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "KingOfRenderThread is nil");
    float time = (float)luaL_checknumber(L, 2);
    instance->mainloop(time);
    return 0;
}

int KingOfRenderThreadBinding::newGame(lua_State* L)
{
    KingOfRenderThread* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "KingOfRenderThread is nil");
    MyGUI::Widget* w = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, WidgetBinding::getMetatableName());
    instance->newGame(w);
    return 0;
}

int KingOfRenderThreadBinding::newGameWithCharEdit(lua_State* L)
{
    KingOfRenderThread* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "KingOfRenderThread is nil");
    GameData* starter = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->newGameWithCharEdit(starter);
    return 0;
}

int KingOfRenderThreadBinding::error(lua_State* L)
{
    KingOfRenderThread* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "KingOfRenderThread is nil");
    const char* msg = luaL_checkstring(L, 2);
    instance->error(msg ? msg : "");
    return 0;
}

int KingOfRenderThreadBinding::errorD(lua_State* L)
{
    KingOfRenderThread* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "KingOfRenderThread is nil");
    const char* msg = luaL_checkstring(L, 2);
    instance->errorD(msg ? msg : "");
    return 0;
}

int KingOfRenderThreadBinding::loadTerrain(lua_State* L)
{
    KingOfRenderThread* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "KingOfRenderThread is nil");
    const char* name = luaL_checkstring(L, 2);
    instance->loadTerrain(name ? name : "");
    return 0;
}

int KingOfRenderThreadBinding::analyseModel(lua_State* L)
{
    KingOfRenderThread* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "KingOfRenderThread is nil");
    const char* name = luaL_checkstring(L, 2);
    Ogre::Entity* model = (Ogre::Entity*)lua_touserdata(L, 3);
    instance->analyseModel(name ? name : "", model);
    return 0;
}

int KingOfRenderThreadBinding::getBonesVertices(lua_State* L)
{
    KingOfRenderThread* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "KingOfRenderThread is nil");
    const char* modelName = luaL_checkstring(L, 2);
    const char* boneName = luaL_checkstring(L, 3);
    MeshDataLookup::Dir facing = (MeshDataLookup::Dir)luaL_checkinteger(L, 4);
    const lektor<int>& res = instance->getBonesVertices(modelName ? modelName : "", boneName ? boneName : "", facing);
    return pushObject<lektor<int>>(L, const_cast<lektor<int>*>(&res), "lektor<int>");
}

int KingOfRenderThreadBinding::getMeshData(lua_State* L)
{
    KingOfRenderThread* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "KingOfRenderThread is nil");
    const char* meshName = luaL_checkstring(L, 2);
    MeshDataLookup* res = instance->getMeshData(meshName ? meshName : "");
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<MeshDataLookup>(L, res, MeshDataLookupBinding::getMetatableName());
}

int KingOfRenderThreadBinding::addTerrainBloodSplat(lua_State* L)
{
    KingOfRenderThread* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "KingOfRenderThread is nil");
    float x = (float)luaL_checknumber(L, 2);
    float z = (float)luaL_checknumber(L, 3);
    float rad = (float)luaL_checknumber(L, 4);
    float angle = (float)luaL_checknumber(L, 5);
    iVector2* uvOffset = checkObject<iVector2>(L, 6, iVector2Binding::getMetatableName());
    if (!uvOffset) return luaL_error(L, "Argument 5 must be iVector2");
    const char* mat = luaL_checkstring(L, 7);
    bool slow = lua_toboolean(L, 8) != 0;
    instance->addTerrainBloodSplat(x, z, rad, Ogre::Radian(angle), *uvOffset, mat ? mat : "", slow);
    return 0;
}

int KingOfRenderThreadBinding::deleteTitleScreen(lua_State* L)
{
    KingOfRenderThread* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "KingOfRenderThread is nil");
    instance->deleteTitleScreen();
    return 0;
}

int KingOfRenderThreadBinding::gc(lua_State* L)
{
    return 0;
}

int KingOfRenderThreadBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.KingOfRenderThread object");
    return 1;
}

void KingOfRenderThreadBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       KingOfRenderThreadBinding::gc },
        { "__tostring", KingOfRenderThreadBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "startup", KingOfRenderThreadBinding::startup },
        { "initialisation", KingOfRenderThreadBinding::initialisation },
        { "mainloop", KingOfRenderThreadBinding::mainloop },
        { "newGame", KingOfRenderThreadBinding::newGame },
        { "newGameWithCharEdit", KingOfRenderThreadBinding::newGameWithCharEdit },
        { "error", KingOfRenderThreadBinding::error },
        { "errorD", KingOfRenderThreadBinding::errorD },
        { "loadTerrain", KingOfRenderThreadBinding::loadTerrain },
        { "analyseModel", KingOfRenderThreadBinding::analyseModel },
        { "getBonesVertices", KingOfRenderThreadBinding::getBonesVertices },
        { "getMeshData", KingOfRenderThreadBinding::getMeshData },
        { "addTerrainBloodSplat", KingOfRenderThreadBinding::addTerrainBloodSplat },
        { "deleteTitleScreen", KingOfRenderThreadBinding::deleteTitleScreen },
        { 0, 0 }
    };

    registerClass(
        L,
        KingOfRenderThreadBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, KingOfRenderThreadBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "TIME", KingOfRenderThread_get_TIME);
    registerGetter(L, "render", KingOfRenderThread_get_render);
    registerGetter(L, "camera", KingOfRenderThread_get_camera);
    registerGetter(L, "terrain", KingOfRenderThread_get_terrain);
    registerGetter(L, "titleScreen", KingOfRenderThread_get_titleScreen);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "TIME", KingOfRenderThread_set_TIME);
    registerSetter(L, "render", KingOfRenderThread_set_render);
    registerSetter(L, "camera", KingOfRenderThread_set_camera);
    registerSetter(L, "terrain", KingOfRenderThread_set_terrain);
    registerSetter(L, "titleScreen", KingOfRenderThread_set_titleScreen);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua

