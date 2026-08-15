#include "pch.h"
#include <kenshi/PlayerInterface.h>
#include "Bindings/Gui/ContextMenuBinding.h"
#include "Bindings/Gui/ContextMenuGUIBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/Util/LektorBinding.h"

namespace KenshiLua
{

static ContextMenu* getInstance(lua_State* L, int idx)
{
    return checkObject<ContextMenu>(L, idx, ContextMenuBinding::getMetatableName());
}

// --- Getters for ContextMenu ---
static int ContextMenu_get_rightMouseActivated(lua_State* L)
{
    ContextMenu* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenu is nil");
    lua_pushboolean(L, instance->rightMouseActivated ? 1 : 0);
    return 1;
}

static int ContextMenu_get_orders(lua_State* L)
{
    ContextMenu* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenu is nil");
    return LektorIntBinding<int>::push(L, &instance->orders);
}

static int ContextMenu_get_contextMenuName(lua_State* L)
{
    ContextMenu* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenu is nil");
    lua_pushstring(L, instance->contextMenuName.c_str());
    return 1;
}

static int ContextMenu_get_menuGUI(lua_State* L)
{
    ContextMenu* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenu is nil");
    return pushObject<ContextMenuGUI>(L, instance->menuGUI, ContextMenuGUIBinding::getMetatableName());
}

static int ContextMenu_get_menuGUI2(lua_State* L)
{
    ContextMenu* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenu is nil");
    return pushObject<ContextMenuGUI>(L, instance->menuGUI2, ContextMenuGUIBinding::getMetatableName());
}

static int ContextMenu_get_delayedDestroyFlag(lua_State* L)
{
    ContextMenu* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenu is nil");
    lua_pushboolean(L, instance->delayedDestroyFlag ? 1 : 0);
    return 1;
}

// --- Setters for ContextMenu ---
static int ContextMenu_set_rightMouseActivated(lua_State* L)
{
    ContextMenu* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenu is nil");
    instance->rightMouseActivated = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ContextMenu_set_orders(lua_State* L)
{
    ContextMenu* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenu is nil");
    auto* val = LektorIntBinding<int>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'orders' must be lektor<int>");
    instance->orders = *val;
    return 0;
}

static int ContextMenu_set_contextMenuName(lua_State* L)
{
    ContextMenu* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenu is nil");
    instance->contextMenuName = luaL_checkstring(L, 2);
    return 0;
}

static int ContextMenu_set_menuGUI(lua_State* L)
{
    ContextMenu* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenu is nil");
    instance->menuGUI = lua_isnoneornil(L, 2) ? nullptr : checkObject<ContextMenuGUI>(L, 2, ContextMenuGUIBinding::getMetatableName());
    return 0;
}

static int ContextMenu_set_menuGUI2(lua_State* L)
{
    ContextMenu* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenu is nil");
    instance->menuGUI2 = lua_isnoneornil(L, 2) ? nullptr : checkObject<ContextMenuGUI>(L, 2, ContextMenuGUIBinding::getMetatableName());
    return 0;
}

static int ContextMenu_set_delayedDestroyFlag(lua_State* L)
{
    ContextMenu* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenu is nil");
    instance->delayedDestroyFlag = lua_toboolean(L, 2) != 0;
    return 0;
}

// --- Methods for ContextMenu ---
int ContextMenuBinding::_CONSTRUCTOR(lua_State* L)
{
    ContextMenu* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenu is nil");

    ContextMenu* result = instance->_CONSTRUCTOR();
    return pushObject<ContextMenu>(L, result, ContextMenuBinding::getMetatableName());
}

int ContextMenuBinding::_DESTRUCTOR(lua_State* L)
{
    ContextMenu* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenu is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ContextMenuBinding::showContextMenu(lua_State* L)
{
    ContextMenu* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenu is nil");

    bool on = lua_toboolean(L, 2) != 0;
    RootObject* what = lua_isnoneornil(L, 3) ? nullptr : checkObject<RootObject>(L, 3, RootObjectBinding::getMetatableName());
    instance->showContextMenu(on, what);
    return 0;
}

int ContextMenuBinding::isVisible(lua_State* L)
{
    ContextMenu* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenu is nil");

    bool result = instance->isVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ContextMenuBinding::update(lua_State* L)
{
    ContextMenu* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenu is nil");

    instance->update();
    return 0;
}

int ContextMenuBinding::_destroyMenuGUICheck(lua_State* L)
{
    ContextMenu* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenu is nil");

    instance->_destroyMenuGUICheck();
    return 0;
}

int ContextMenuBinding::gc(lua_State* L)
{
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
        { "_CONSTRUCTOR", ContextMenuBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", ContextMenuBinding::_DESTRUCTOR },
        { "showContextMenu", ContextMenuBinding::showContextMenu },
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
    registerGetter(L, "rightMouseActivated", ContextMenu_get_rightMouseActivated);
    registerGetter(L, "orders", ContextMenu_get_orders);
    registerGetter(L, "contextMenuName", ContextMenu_get_contextMenuName);
    registerGetter(L, "menuGUI", ContextMenu_get_menuGUI);
    registerGetter(L, "menuGUI2", ContextMenu_get_menuGUI2);
    registerGetter(L, "delayedDestroyFlag", ContextMenu_get_delayedDestroyFlag);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "rightMouseActivated", ContextMenu_set_rightMouseActivated);
    registerSetter(L, "orders", ContextMenu_set_orders);
    registerSetter(L, "contextMenuName", ContextMenu_set_contextMenuName);
    registerSetter(L, "menuGUI", ContextMenu_set_menuGUI);
    registerSetter(L, "menuGUI2", ContextMenu_set_menuGUI2);
    registerSetter(L, "delayedDestroyFlag", ContextMenu_set_delayedDestroyFlag);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
