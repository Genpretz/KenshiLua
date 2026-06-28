#include "pch.h"
#include "kenshi\PlayerInterface.h"
#include "ContextMenuBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static ContextMenu* getB(lua_State* L, int idx)
{
    return checkObject<ContextMenu>(L, idx, ContextMenuBinding::getMetatableName());
}

// --- Getters for ContextMenu ---
static int ContextMenu_get_rightMouseActivated(lua_State* L)
{
    ContextMenu* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContextMenu is nil");
    lua_pushboolean(L, b->rightMouseActivated ? 1 : 0);
    return 1;
}

static int ContextMenu_get_orders(lua_State* L)
{
    ContextMenu* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContextMenu is nil");
    // TODO: Unsupported type for orders (lektor<int>)
    return luaL_error(L, "Unsupported property 'orders' (type: lektor<int>)");
}

static int ContextMenu_get_contextMenuName(lua_State* L)
{
    ContextMenu* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContextMenu is nil");
    lua_pushstring(L, b->contextMenuName.c_str());
    return 1;
}

static int ContextMenu_get_menuGUI(lua_State* L)
{
    ContextMenu* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContextMenu is nil");
    // TODO: Unsupported type for menuGUI (ContextMenuGUI*)
    return luaL_error(L, "Unsupported property 'menuGUI' (type: ContextMenuGUI*)");
}

static int ContextMenu_get_menuGUI2(lua_State* L)
{
    ContextMenu* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContextMenu is nil");
    // TODO: Unsupported type for menuGUI2 (ContextMenuGUI*)
    return luaL_error(L, "Unsupported property 'menuGUI2' (type: ContextMenuGUI*)");
}

static int ContextMenu_get_delayedDestroyFlag(lua_State* L)
{
    ContextMenu* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContextMenu is nil");
    lua_pushboolean(L, b->delayedDestroyFlag ? 1 : 0);
    return 1;
}

// --- Setters for ContextMenu ---
static int ContextMenu_set_rightMouseActivated(lua_State* L)
{
    ContextMenu* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContextMenu is nil");
    b->rightMouseActivated = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ContextMenu_set_orders(lua_State* L)
{
    ContextMenu* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContextMenu is nil");
    return luaL_error(L, "Read-only or unsupported setter type for orders");
}

static int ContextMenu_set_contextMenuName(lua_State* L)
{
    ContextMenu* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContextMenu is nil");
    b->contextMenuName = luaL_checkstring(L, 2);
    return 0;
}

static int ContextMenu_set_menuGUI(lua_State* L)
{
    ContextMenu* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContextMenu is nil");
    return luaL_error(L, "Read-only or unsupported setter type for menuGUI");
}

static int ContextMenu_set_menuGUI2(lua_State* L)
{
    ContextMenu* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContextMenu is nil");
    return luaL_error(L, "Read-only or unsupported setter type for menuGUI2");
}

static int ContextMenu_set_delayedDestroyFlag(lua_State* L)
{
    ContextMenu* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContextMenu is nil");
    b->delayedDestroyFlag = lua_toboolean(L, 2) != 0;
    return 0;
}

int ContextMenuBinding::_DESTRUCTOR(lua_State* L)
{
    ContextMenu* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContextMenu is nil");

    b->_DESTRUCTOR();
    return 0;
}

int ContextMenuBinding::isVisible(lua_State* L)
{
    ContextMenu* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContextMenu is nil");

    bool result = b->isVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ContextMenuBinding::update(lua_State* L)
{
    ContextMenu* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContextMenu is nil");

    b->update();
    return 0;
}

int ContextMenuBinding::_destroyMenuGUICheck(lua_State* L)
{
    ContextMenu* b = getB(L, 1);
    if (!b) return luaL_error(L, "ContextMenu is nil");

    b->_destroyMenuGUICheck();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 38: ContextMenu* _CONSTRUCTOR(...) - unsupported return type
  line 41: void showContextMenu(...) - unsupported arg type
*/

int ContextMenuBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ContextMenuBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ContextMenu object");
    return 1;
}

void ContextMenuBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ContextMenuBinding::gc },
        { "__tostring", ContextMenuBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", ContextMenuBinding::_DESTRUCTOR },
        { "isVisible", ContextMenuBinding::isVisible },
        { "update", ContextMenuBinding::update },
        { "_destroyMenuGUICheck", ContextMenuBinding::_destroyMenuGUICheck },
        { 0, 0 }
    };

    registerClass(
        L, 
        ContextMenuBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ContextMenuBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, ContextMenu_get_rightMouseActivated);
    lua_setfield(L, -2, "rightMouseActivated");
    lua_pushcfunction(L, ContextMenu_get_orders);
    lua_setfield(L, -2, "orders");
    lua_pushcfunction(L, ContextMenu_get_contextMenuName);
    lua_setfield(L, -2, "contextMenuName");
    lua_pushcfunction(L, ContextMenu_get_menuGUI);
    lua_setfield(L, -2, "menuGUI");
    lua_pushcfunction(L, ContextMenu_get_menuGUI2);
    lua_setfield(L, -2, "menuGUI2");
    lua_pushcfunction(L, ContextMenu_get_delayedDestroyFlag);
    lua_setfield(L, -2, "delayedDestroyFlag");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, ContextMenu_set_rightMouseActivated);
    lua_setfield(L, -2, "rightMouseActivated");
    lua_pushcfunction(L, ContextMenu_set_orders);
    lua_setfield(L, -2, "orders");
    lua_pushcfunction(L, ContextMenu_set_contextMenuName);
    lua_setfield(L, -2, "contextMenuName");
    lua_pushcfunction(L, ContextMenu_set_menuGUI);
    lua_setfield(L, -2, "menuGUI");
    lua_pushcfunction(L, ContextMenu_set_menuGUI2);
    lua_setfield(L, -2, "menuGUI2");
    lua_pushcfunction(L, ContextMenu_set_delayedDestroyFlag);
    lua_setfield(L, -2, "delayedDestroyFlag");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua