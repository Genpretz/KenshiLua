#include "pch.h"
#include "kenshi\PlayerInterface.h"
#include "SelectionBoxBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static SelectionBox* getInstance(lua_State* L, int idx)
{
    return checkObject<SelectionBox>(L, idx, SelectionBoxBinding::getMetatableName());
}

// --- Getters for SelectionBox ---
static int SelectionBox_get_startPos(lua_State* L)
{
    SelectionBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SelectionBox is nil");
    pushVector2(L, instance->startPos);
    return 1;
}

static int SelectionBox_get_widget(lua_State* L)
{
    SelectionBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SelectionBox is nil");
    lua_pushlightuserdata(L, (void*)instance->widget);
    return 1;
}

static int SelectionBox_get_active(lua_State* L)
{
    SelectionBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SelectionBox is nil");
    lua_pushboolean(L, instance->active ? 1 : 0);
    return 1;
}

// --- Setters for SelectionBox ---
static int SelectionBox_set_startPos(lua_State* L)
{
    SelectionBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SelectionBox is nil");
    readVector2(L, 2, instance->startPos);
    return 0;
}

static int SelectionBox_set_active(lua_State* L)
{
    SelectionBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SelectionBox is nil");
    instance->active = lua_toboolean(L, 2) != 0;
    return 0;
}

int SelectionBoxBinding::start(lua_State* L)
{
    SelectionBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SelectionBox is nil");

    Ogre::Vector2 m;
    readVector2(L, 2, m);
    instance->start(m);
    return 0;
}

int SelectionBoxBinding::update(lua_State* L)
{
    SelectionBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SelectionBox is nil");

    Ogre::Vector2 m;
    readVector2(L, 2, m);
    instance->update(m);
    return 0;
}

int SelectionBoxBinding::cancel(lua_State* L)
{
    SelectionBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SelectionBox is nil");

    instance->cancel();
    return 0;
}

int SelectionBoxBinding::isActive(lua_State* L)
{
    SelectionBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SelectionBox is nil");

    bool result = instance->isActive();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SelectionBoxBinding::_CONSTRUCTOR(lua_State* L)
{
    SelectionBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SelectionBox is nil");

    SelectionBox* result = instance->_CONSTRUCTOR();
    return pushObject<SelectionBox>(L, result, SelectionBoxBinding::getMetatableName());
}

int SelectionBoxBinding::_DESTRUCTOR(lua_State* L)
{
    SelectionBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SelectionBox is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 46: bool contains(...) - overloaded method
  line 47: bool contains(...) - overloaded method
  line 48: bool contains(...) - overloaded method
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - SelectionBox_get_widget: MyGUI::Widget* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 39: volume (Ogre::PlaneBoundedVolume) - unsupported type
*/

int SelectionBoxBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SelectionBoxBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SelectionBox object");
    return 1;
}



static int SelectionBox_get_volume(lua_State* L)
{
    SelectionBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SelectionBox is nil");
    // TODO: Unsupported type for volume (Ogre::PlaneBoundedVolume)
    return luaL_error(L, "Unsupported property 'volume' (type: Ogre::PlaneBoundedVolume)");
}


static int SelectionBox_set_volume(lua_State* L)
{
    SelectionBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SelectionBox is nil");
    return luaL_error(L, "Read-only or unsupported setter type for volume");
}


static int SelectionBox_set_widget(lua_State* L)
{
    SelectionBox* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SelectionBox is nil");
    return luaL_error(L, "Read-only or unsupported setter type for widget");
}


void SelectionBoxBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SelectionBoxBinding::gc },
        { "__tostring", SelectionBoxBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "start", SelectionBoxBinding::start },
        { "update", SelectionBoxBinding::update },
        { "cancel", SelectionBoxBinding::cancel },
        { "isActive", SelectionBoxBinding::isActive },
        { "_CONSTRUCTOR", SelectionBoxBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", SelectionBoxBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        SelectionBoxBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SelectionBoxBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "startPos", SelectionBox_get_startPos);
    registerGetter(L, "widget", SelectionBox_get_widget);
    registerGetter(L, "active", SelectionBox_get_active);
        registerGetter(L, "volume", SelectionBox_get_volume);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "startPos", SelectionBox_set_startPos);
    registerSetter(L, "active", SelectionBox_set_active);
        registerSetter(L, "volume", SelectionBox_set_volume);
        registerSetter(L, "widget", SelectionBox_set_widget);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, SelectionBoxBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua