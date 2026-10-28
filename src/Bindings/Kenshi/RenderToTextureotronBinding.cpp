#include "pch.h"
#include "kenshi/RenderToTextureotron.h"
#include "RenderToTextureotronBinding.h"
#include "ItemBinding.h"
#include "GameDataBinding.h"
#include "CharacterBinding.h"
#include "Bindings/Kenshi/Util/iVector2Binding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(offsetof(RenderToTextureotron, sceneManager) == 0x0, "RenderToTextureotron::sceneManager offset mismatch");
static_assert(offsetof(RenderToTextureotron, camera) == 0x8, "RenderToTextureotron::camera offset mismatch");

static RenderToTextureotron* getInstance(lua_State* L, int idx)
{
    return checkObject<RenderToTextureotron>(L, idx, RenderToTextureotronBinding::getMetatableName());
}

static int RenderToTextureotron_get_sceneManager(lua_State* L)
{
    RenderToTextureotron* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RenderToTextureotron is nil");
    if (!instance->sceneManager) { lua_pushnil(L); return 1; }
    lua_pushlightuserdata(L, (void*)instance->sceneManager);
    return 1;
}

static int RenderToTextureotron_get_camera(lua_State* L)
{
    RenderToTextureotron* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RenderToTextureotron is nil");
    if (!instance->camera) { lua_pushnil(L); return 1; }
    lua_pushlightuserdata(L, (void*)instance->camera);
    return 1;
}

int RenderToTextureotronBinding::renderItem(lua_State* L)
{
    RenderToTextureotron* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RenderToTextureotron is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    const char* fileStr = luaL_checkstring(L, 3);
    std::string filename = fileStr ? fileStr : "";
    iVector2* size = checkObject<iVector2>(L, 4, iVector2Binding::getMetatableName());
    if (!size) return luaL_error(L, "Argument 4 must be iVector2");
    instance->renderItem(item, filename, *size);
    lua_pushstring(L, filename.c_str());
    return 1;
}

int RenderToTextureotronBinding::renderBuilding(lua_State* L)
{
    RenderToTextureotron* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RenderToTextureotron is nil");
    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    const char* fileStr = luaL_checkstring(L, 3);
    std::string filename = fileStr ? fileStr : "";
    iVector2* size = checkObject<iVector2>(L, 4, iVector2Binding::getMetatableName());
    if (!size) return luaL_error(L, "Argument 4 must be iVector2");
    float yaw = (float)luaL_checknumber(L, 5);
    float pitch = (float)luaL_checknumber(L, 6);
    instance->renderBuilding(data, filename, *size, yaw, pitch);
    lua_pushstring(L, filename.c_str());
    return 1;
}

int RenderToTextureotronBinding::renderCharacterNPC(lua_State* L)
{
    RenderToTextureotron* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RenderToTextureotron is nil");
    Character* character = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    iVector2* size = checkObject<iVector2>(L, 3, iVector2Binding::getMetatableName());
    if (!size) return luaL_error(L, "Argument 3 must be iVector2");
    float distance = (float)luaL_checknumber(L, 4);
    std::string res = instance->renderCharacterNPC(character, *size, distance);
    lua_pushstring(L, res.c_str());
    return 1;
}

int RenderToTextureotronBinding::buildAllItemsIcons(lua_State* L)
{
    RenderToTextureotron* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RenderToTextureotron is nil");
    instance->buildAllItemsIcons();
    return 0;
}

int RenderToTextureotronBinding::gc(lua_State* L)
{
    return 0;
}

int RenderToTextureotronBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.RenderToTextureotron object");
    return 1;
}

void RenderToTextureotronBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RenderToTextureotronBinding::gc },
        { "__tostring", RenderToTextureotronBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "renderItem", RenderToTextureotronBinding::renderItem },
        { "renderBuilding", RenderToTextureotronBinding::renderBuilding },
        { "renderCharacterNPC", RenderToTextureotronBinding::renderCharacterNPC },
        { "buildAllItemsIcons", RenderToTextureotronBinding::buildAllItemsIcons },
        { 0, 0 }
    };

    registerClass(
        L,
        RenderToTextureotronBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, RenderToTextureotronBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "sceneManager", RenderToTextureotron_get_sceneManager);
    registerGetter(L, "camera", RenderToTextureotron_get_camera);
    lua_setfield(L, -2, "__getters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
