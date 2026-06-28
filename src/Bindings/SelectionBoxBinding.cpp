#include "pch.h"
#include "E:\Kenshi\dev\projects\KenshiLua\extern\KenshiLib\Include\kenshi\PlayerInterface.h"
#include "SelectionBoxBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static SelectionBox* getB(lua_State* L, int idx)
{
    return checkObject<SelectionBox>(L, idx, SelectionBoxBinding::getMetatableName());
}

// --- Getters for SelectionBox ---
static int SelectionBox_get_startPos(lua_State* L)
{
    SelectionBox* b = getB(L, 1);
    if (!b) return luaL_error(L, "SelectionBox is nil");
    // TODO: Unsupported type for startPos (Ogre::Vector2)
    return luaL_error(L, "Unsupported property 'startPos' (type: Ogre::Vector2)");
}

static int SelectionBox_get_volume(lua_State* L)
{
    SelectionBox* b = getB(L, 1);
    if (!b) return luaL_error(L, "SelectionBox is nil");
    // TODO: Unsupported type for volume (Ogre::PlaneBoundedVolume)
    return luaL_error(L, "Unsupported property 'volume' (type: Ogre::PlaneBoundedVolume)");
}

static int SelectionBox_get_widget(lua_State* L)
{
    SelectionBox* b = getB(L, 1);
    if (!b) return luaL_error(L, "SelectionBox is nil");
    lua_pushinteger(L, (lua_Integer)b->widget);
    return 1;
}

static int SelectionBox_get_active(lua_State* L)
{
    SelectionBox* b = getB(L, 1);
    if (!b) return luaL_error(L, "SelectionBox is nil");
    lua_pushboolean(L, b->active ? 1 : 0);
    return 1;
}

// --- Setters for SelectionBox ---
static int SelectionBox_set_startPos(lua_State* L)
{
    SelectionBox* b = getB(L, 1);
    if (!b) return luaL_error(L, "SelectionBox is nil");
    return luaL_error(L, "Read-only or unsupported setter type for startPos");
}

static int SelectionBox_set_volume(lua_State* L)
{
    SelectionBox* b = getB(L, 1);
    if (!b) return luaL_error(L, "SelectionBox is nil");
    return luaL_error(L, "Read-only or unsupported setter type for volume");
}

static int SelectionBox_set_widget(lua_State* L)
{
    SelectionBox* b = getB(L, 1);
    if (!b) return luaL_error(L, "SelectionBox is nil");
    return luaL_error(L, "Read-only or unsupported setter type for widget");
}

static int SelectionBox_set_active(lua_State* L)
{
    SelectionBox* b = getB(L, 1);
    if (!b) return luaL_error(L, "SelectionBox is nil");
    b->active = lua_toboolean(L, 2) != 0;
    return 0;
}

int SelectionBoxBinding::cancel(lua_State* L)
{
    SelectionBox* b = getB(L, 1);
    if (!b) return luaL_error(L, "SelectionBox is nil");

    b->cancel();
    return 0;
}

int SelectionBoxBinding::isActive(lua_State* L)
{
    SelectionBox* b = getB(L, 1);
    if (!b) return luaL_error(L, "SelectionBox is nil");

    bool result = b->isActive();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SelectionBoxBinding::_DESTRUCTOR(lua_State* L)
{
    SelectionBox* b = getB(L, 1);
    if (!b) return luaL_error(L, "SelectionBox is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 64: void start(...) - unsupported arg type
  line 65: void update(...) - unsupported arg type
  line 68: bool contains(...) - overloaded method
  line 69: bool contains(...) - overloaded method
  line 70: bool contains(...) - overloaded method
  line 73: SelectionBox* _CONSTRUCTOR(...) - unsupported return type
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

void SelectionBoxBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SelectionBoxBinding::gc },
        { "__tostring", SelectionBoxBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "cancel", SelectionBoxBinding::cancel },
        { "isActive", SelectionBoxBinding::isActive },
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
    lua_pushcfunction(L, SelectionBox_get_startPos);
    lua_setfield(L, -2, "startPos");
    lua_pushcfunction(L, SelectionBox_get_volume);
    lua_setfield(L, -2, "volume");
    lua_pushcfunction(L, SelectionBox_get_widget);
    lua_setfield(L, -2, "widget");
    lua_pushcfunction(L, SelectionBox_get_active);
    lua_setfield(L, -2, "active");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, SelectionBox_set_startPos);
    lua_setfield(L, -2, "startPos");
    lua_pushcfunction(L, SelectionBox_set_volume);
    lua_setfield(L, -2, "volume");
    lua_pushcfunction(L, SelectionBox_set_widget);
    lua_setfield(L, -2, "widget");
    lua_pushcfunction(L, SelectionBox_set_active);
    lua_setfield(L, -2, "active");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua