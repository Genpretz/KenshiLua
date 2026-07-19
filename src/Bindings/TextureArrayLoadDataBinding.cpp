#include "pch.h"
#include "kenshi\ResourceLoader.h"
#include "TextureArrayLoadDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "TextureLoadDataBinding.h"

namespace KenshiLua
{
typedef ResourceLoader::TextureArrayLoadData TextureArrayLoadData;

static TextureArrayLoadData* getInstance(lua_State* L, int idx)
{
    return checkObject<TextureArrayLoadData>(L, idx, TextureArrayLoadDataBinding::getMetatableName());
}

// --- Getters for TextureArrayLoadData ---
// --- Setters for TextureArrayLoadData ---
int TextureArrayLoadDataBinding::_DESTRUCTOR(lua_State* L)
{
    TextureArrayLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TextureArrayLoadData is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int TextureArrayLoadDataBinding::loadImage(lua_State* L)
{
    TextureArrayLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TextureArrayLoadData is nil");

    instance->loadImage();
    return 0;
}

int TextureArrayLoadDataBinding::_NV_loadImage(lua_State* L)
{
    TextureArrayLoadData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TextureArrayLoadData is nil");

    instance->_NV_loadImage();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 123: TextureArrayLoadData* _CONSTRUCTOR(...) - unsupported arg type
  line 128: Ogre::SharedPtr<Ogre::Texture> getTexture(...) - unsupported return type
  line 129: Ogre::SharedPtr<Ogre::Texture> _NV_getTexture(...) - unsupported return type
*/

/*
Skipped properties needing manual binding:
  line 119: filesNames (Ogre::vector<std::string>::type) - unsupported type
  line 120: images (Ogre::vector<Ogre::Image>::type) - unsupported type
*/

int TextureArrayLoadDataBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TextureArrayLoadDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TextureArrayLoadData object");
    return 1;
}

void TextureArrayLoadDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TextureArrayLoadDataBinding::gc },
        { "__tostring", TextureArrayLoadDataBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", TextureArrayLoadDataBinding::_DESTRUCTOR },
        { "loadImage", TextureArrayLoadDataBinding::loadImage },
        { "_NV_loadImage", TextureArrayLoadDataBinding::_NV_loadImage },
        { 0, 0 }
    };

    registerClass(
        L, 
        TextureArrayLoadDataBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TextureArrayLoadDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to TextureLoadData
    // setMetatableParent(L, TextureArrayLoadDataBinding::getMetatableName(), TextureLoadDataBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
