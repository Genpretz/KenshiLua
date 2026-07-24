#include "pch.h"
#include "kenshi\gui\PortraitManager.h"
#include "PortraitImageBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static PortraitImage* getInstance(lua_State* L, int idx)
{
    return checkObject<PortraitImage>(L, idx, PortraitImageBinding::getMetatableName());
}

// --- Getters for PortraitImage ---
static int PortraitImage_get_index(lua_State* L)
{
    PortraitImage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitImage is nil");
    lua_pushinteger(L, instance->index);
    return 1;
}

static int PortraitImage_get_created(lua_State* L)
{
    PortraitImage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitImage is nil");
    lua_pushboolean(L, instance->created ? 1 : 0);
    return 1;
}

static int PortraitImage_get_textureName(lua_State* L)
{
    PortraitImage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitImage is nil");
    lua_pushstring(L, instance->textureName.c_str());
    return 1;
}

// --- Setters for PortraitImage ---
static int PortraitImage_set_index(lua_State* L)
{
    PortraitImage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitImage is nil");
    instance->index = (unsigned short)luaL_checkinteger(L, 2);
    return 0;
}

static int PortraitImage_set_created(lua_State* L)
{
    PortraitImage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitImage is nil");
    instance->created = lua_toboolean(L, 2) != 0;
    return 0;
}

static int PortraitImage_set_textureName(lua_State* L)
{
    PortraitImage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitImage is nil");
    instance->textureName = luaL_checkstring(L, 2);
    return 0;
}

int PortraitImageBinding::_DESTRUCTOR(lua_State* L)
{
    PortraitImage* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitImage is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 20: PortraitImage* _CONSTRUCTOR(...) - unsupported arg type
  line 21: void updateImageWidget(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 25: textureRect (Ogre::TRect<float>) - unsupported type
  line 26: coords (MyGUI::types::TCoord<int>) - unsupported type
*/

int PortraitImageBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int PortraitImageBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.PortraitImage object");
    return 1;
}

void PortraitImageBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       PortraitImageBinding::gc },
        { "__tostring", PortraitImageBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", PortraitImageBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        PortraitImageBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, PortraitImageBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "index", PortraitImage_get_index);
    registerGetter(L, "created", PortraitImage_get_created);
    registerGetter(L, "textureName", PortraitImage_get_textureName);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "index", PortraitImage_set_index);
    registerSetter(L, "created", PortraitImage_set_created);
    registerSetter(L, "textureName", PortraitImage_set_textureName);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, PortraitImageBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua