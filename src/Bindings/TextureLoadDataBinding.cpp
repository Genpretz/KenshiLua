#include "pch.h"
#include "kenshi\ResourceLoader.h"
#include "TextureLoadDataBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
typedef ResourceLoader::TextureLoadData TextureLoadData;

static TextureLoadData* getInstance(lua_State* L, int idx)
{
    return checkObject<TextureLoadData>(L, idx, TextureLoadDataBinding::getMetatableName());
}

// --- Getters for TextureLoadData ---
static int TextureLoadData_get_name(lua_State* L)
{
    TextureLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TextureLoadData is nil");
    lua_pushstring(L, instance->name.c_str());
    return 1;
}

static int TextureLoadData_get_group(lua_State* L)
{
    TextureLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TextureLoadData is nil");
    lua_pushstring(L, instance->group.c_str());
    return 1;
}

static int TextureLoadData_get_loaded(lua_State* L)
{
    TextureLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TextureLoadData is nil");
    lua_pushboolean(L, instance->loaded ? 1 : 0);
    return 1;
}

static int TextureLoadData_get_queued(lua_State* L)
{
    TextureLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TextureLoadData is nil");
    lua_pushboolean(L, instance->queued ? 1 : 0);
    return 1;
}

static int TextureLoadData_get_success(lua_State* L)
{
    TextureLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TextureLoadData is nil");
    lua_pushboolean(L, instance->success ? 1 : 0);
    return 1;
}

// --- Setters for TextureLoadData ---
static int TextureLoadData_set_name(lua_State* L)
{
    TextureLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TextureLoadData is nil");
    instance->name = luaL_checkstring(L, 2);
    return 0;
}

static int TextureLoadData_set_group(lua_State* L)
{
    TextureLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TextureLoadData is nil");
    instance->group = luaL_checkstring(L, 2);
    return 0;
}

static int TextureLoadData_set_loaded(lua_State* L)
{
    TextureLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TextureLoadData is nil");
    instance->loaded = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TextureLoadData_set_queued(lua_State* L)
{
    TextureLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TextureLoadData is nil");
    instance->queued = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TextureLoadData_set_success(lua_State* L)
{
    TextureLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TextureLoadData is nil");
    instance->success = lua_toboolean(L, 2) != 0;
    return 0;
}

int TextureLoadDataBinding::_CONSTRUCTOR(lua_State* L)
{
    TextureLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TextureLoadData is nil");

    std::string name = luaL_checkstring(L, 2);
    std::string group = luaL_checkstring(L, 3);
    TextureLoadData* result = instance->_CONSTRUCTOR(name, group);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TextureLoadDataBinding::_DESTRUCTOR(lua_State* L)
{
    TextureLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TextureLoadData is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int TextureLoadDataBinding::loadImage(lua_State* L)
{
    TextureLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TextureLoadData is nil");

    instance->loadImage();
    return 0;
}

int TextureLoadDataBinding::_NV_loadImage(lua_State* L)
{
    TextureLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TextureLoadData is nil");

    instance->_NV_loadImage();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 34: Ogre::SharedPtr<Ogre::Texture> getTexture(...) - unsupported return type
  line 35: Ogre::SharedPtr<Ogre::Texture> _NV_getTexture(...) - unsupported return type
*/

/*
Skipped properties needing manual binding:
  line 23: image (Ogre::Image) - unsupported type
*/

int TextureLoadDataBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TextureLoadDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TextureLoadData object");
    return 1;
}

void TextureLoadDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TextureLoadDataBinding::gc },
        { "__tostring", TextureLoadDataBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", TextureLoadDataBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", TextureLoadDataBinding::_DESTRUCTOR },
        { "loadImage", TextureLoadDataBinding::loadImage },
        { "_NV_loadImage", TextureLoadDataBinding::_NV_loadImage },
        { 0, 0 }
    };

    registerClass(
        L, 
        TextureLoadDataBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TextureLoadDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, TextureLoadData_get_name);
    lua_setfield(L, -2, "name");
    lua_pushcfunction(L, TextureLoadData_get_group);
    lua_setfield(L, -2, "group");
    lua_pushcfunction(L, TextureLoadData_get_loaded);
    lua_setfield(L, -2, "loaded");
    lua_pushcfunction(L, TextureLoadData_get_queued);
    lua_setfield(L, -2, "queued");
    lua_pushcfunction(L, TextureLoadData_get_success);
    lua_setfield(L, -2, "success");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, TextureLoadData_set_name);
    lua_setfield(L, -2, "name");
    lua_pushcfunction(L, TextureLoadData_set_group);
    lua_setfield(L, -2, "group");
    lua_pushcfunction(L, TextureLoadData_set_loaded);
    lua_setfield(L, -2, "loaded");
    lua_pushcfunction(L, TextureLoadData_set_queued);
    lua_setfield(L, -2, "queued");
    lua_pushcfunction(L, TextureLoadData_set_success);
    lua_setfield(L, -2, "success");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
