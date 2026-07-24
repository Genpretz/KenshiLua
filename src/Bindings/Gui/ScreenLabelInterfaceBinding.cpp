#include "pch.h"
#include "kenshi\gui\ScreenLabel.h"
#include "ScreenLabelInterfaceBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static ScreenLabelInterface* getInstance(lua_State* L, int idx)
{
    return checkObject<ScreenLabelInterface>(L, idx, ScreenLabelInterfaceBinding::getMetatableName());
}

// --- Getters for ScreenLabelInterface ---
static int ScreenLabelInterface_get_visible(lua_State* L)
{
    ScreenLabelInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabelInterface is nil");
    lua_pushboolean(L, instance->visible ? 1 : 0);
    return 1;
}

static int ScreenLabelInterface_get_position(lua_State* L)
{
    ScreenLabelInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabelInterface is nil");
    pushVector3(L, instance->position);
    return 1;
}

static int ScreenLabelInterface_get_needUpdate(lua_State* L)
{
    ScreenLabelInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabelInterface is nil");
    lua_pushboolean(L, instance->needUpdate ? 1 : 0);
    return 1;
}

// --- Setters for ScreenLabelInterface ---
static int ScreenLabelInterface_set_visible(lua_State* L)
{
    ScreenLabelInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabelInterface is nil");
    instance->visible = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ScreenLabelInterface_set_position(lua_State* L)
{
    ScreenLabelInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabelInterface is nil");
    readVector3(L, 2, instance->position);
    return 0;
}

static int ScreenLabelInterface_set_needUpdate(lua_State* L)
{
    ScreenLabelInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabelInterface is nil");
    instance->needUpdate = lua_toboolean(L, 2) != 0;
    return 0;
}

int ScreenLabelInterfaceBinding::_CONSTRUCTOR(lua_State* L)
{
    ScreenLabelInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabelInterface is nil");

    ScreenLabelInterface* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ScreenLabelInterfaceBinding::_DESTRUCTOR(lua_State* L)
{
    ScreenLabelInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabelInterface is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ScreenLabelInterfaceBinding::update(lua_State* L)
{
    ScreenLabelInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabelInterface is nil");

    instance->update();
    return 0;
}

int ScreenLabelInterfaceBinding::setVisible(lua_State* L)
{
    ScreenLabelInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabelInterface is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->setVisible(value);
    return 0;
}

int ScreenLabelInterfaceBinding::_NV_setVisible(lua_State* L)
{
    ScreenLabelInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabelInterface is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->_NV_setVisible(value);
    return 0;
}

int ScreenLabelInterfaceBinding::setPosition(lua_State* L)
{
    ScreenLabelInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabelInterface is nil");

    Ogre::Vector3 value;
    readVector3(L, 2, value);
    instance->setPosition(value);
    return 0;
}

int ScreenLabelInterfaceBinding::_NV_setPosition(lua_State* L)
{
    ScreenLabelInterface* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ScreenLabelInterface is nil");

    Ogre::Vector3 value;
    readVector3(L, 2, value);
    instance->_NV_setPosition(value);
    return 0;
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - ScreenLabelInterfaceBinding::_CONSTRUCTOR: ScreenLabelInterface* (unbound pointer)
*/

int ScreenLabelInterfaceBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ScreenLabelInterfaceBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ScreenLabelInterface object");
    return 1;
}

void ScreenLabelInterfaceBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ScreenLabelInterfaceBinding::gc },
        { "__tostring", ScreenLabelInterfaceBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", ScreenLabelInterfaceBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", ScreenLabelInterfaceBinding::_DESTRUCTOR },
        { "update", ScreenLabelInterfaceBinding::update },
        { "setVisible", ScreenLabelInterfaceBinding::setVisible },
        { "_NV_setVisible", ScreenLabelInterfaceBinding::_NV_setVisible },
        { "setPosition", ScreenLabelInterfaceBinding::setPosition },
        { "_NV_setPosition", ScreenLabelInterfaceBinding::_NV_setPosition },
        { 0, 0 }
    };

    registerClass(
        L, 
        ScreenLabelInterfaceBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ScreenLabelInterfaceBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "visible", ScreenLabelInterface_get_visible);
    registerGetter(L, "position", ScreenLabelInterface_get_position);
    registerGetter(L, "needUpdate", ScreenLabelInterface_get_needUpdate);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "visible", ScreenLabelInterface_set_visible);
    registerSetter(L, "position", ScreenLabelInterface_set_position);
    registerSetter(L, "needUpdate", ScreenLabelInterface_set_needUpdate);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, ScreenLabelInterfaceBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua