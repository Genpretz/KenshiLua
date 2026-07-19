#include "pch.h"
#include "kenshi\ResourceLoader.h"
#include "ResourceLoadRequestTextureBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
typedef ResourceLoader::ResourceLoadRequestTexture ResourceLoadRequestTexture;

static ResourceLoadRequestTexture* getInstance(lua_State* L, int idx)
{
    return checkObject<ResourceLoadRequestTexture>(L, idx, ResourceLoadRequestTextureBinding::getMetatableName());
}

// --- Getters for ResourceLoadRequestTexture ---
static int ResourceLoadRequestTexture_get_textureUnitState(lua_State* L)
{
    ResourceLoadRequestTexture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResourceLoadRequestTexture is nil");
    lua_pushlightuserdata(L, (void*)instance->textureUnitState);
    return 1;
}

// --- Setters for ResourceLoadRequestTexture ---
int ResourceLoadRequestTextureBinding::_DESTRUCTOR(lua_State* L)
{
    ResourceLoadRequestTexture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResourceLoadRequestTexture is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ResourceLoadRequestTextureBinding::isMaterialValid(lua_State* L)
{
    ResourceLoadRequestTexture* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResourceLoadRequestTexture is nil");

    bool result = instance->isMaterialValid();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 79: ResourceLoadRequestTexture* _CONSTRUCTOR(...) - unsupported arg type
  line 83: void setTexture(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 75: material (Ogre::SharedPtr<Ogre::Material>) - unsupported type
*/

int ResourceLoadRequestTextureBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ResourceLoadRequestTextureBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ResourceLoadRequestTexture object");
    return 1;
}

void ResourceLoadRequestTextureBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ResourceLoadRequestTextureBinding::gc },
        { "__tostring", ResourceLoadRequestTextureBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", ResourceLoadRequestTextureBinding::_DESTRUCTOR },
        { "isMaterialValid", ResourceLoadRequestTextureBinding::isMaterialValid },
        { 0, 0 }
    };

    registerClass(
        L, 
        ResourceLoadRequestTextureBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ResourceLoadRequestTextureBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, ResourceLoadRequestTexture_get_textureUnitState);
    lua_setfield(L, -2, "textureUnitState");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
