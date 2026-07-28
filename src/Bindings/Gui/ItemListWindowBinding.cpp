#include "pch.h"
#include "kenshi\gui\LevelEditor.h"
#include "ItemListWindowBinding.h"
#include "GamedataSelectionListBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{
typedef LevelEditor::ItemListWindow ItemListWindow;


static ItemListWindow* getInstance(lua_State* L, int idx)
{
    return checkObject<ItemListWindow>(L, idx, ItemListWindowBinding::getMetatableName());
}

// --- Getters for ItemListWindow ---
// --- Setters for ItemListWindow ---
int ItemListWindowBinding::_DESTRUCTOR(lua_State* L)
{
    ItemListWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ItemListWindow is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ItemListWindowBinding::itemSelected(lua_State* L)
{
    ItemListWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ItemListWindow is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->itemSelected(item);
    return 0;
}

int ItemListWindowBinding::_NV_itemSelected(lua_State* L)
{
    ItemListWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ItemListWindow is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_NV_itemSelected(item);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 165: ItemListWindow* _CONSTRUCTOR(...) - unsupported arg type
*/

int ItemListWindowBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ItemListWindowBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ItemListWindow object");
    return 1;
}

void ItemListWindowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ItemListWindowBinding::gc },
        { "__tostring", ItemListWindowBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", ItemListWindowBinding::_DESTRUCTOR },
        { "itemSelected", ItemListWindowBinding::itemSelected },
        { "_NV_itemSelected", ItemListWindowBinding::_NV_itemSelected },
        { 0, 0 }
    };

    registerClass(
        L, 
        ItemListWindowBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ItemListWindowBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to LevelEditor::GamedataSelectionList
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, ItemListWindowBinding::getMetatableName(), KenshiLua::GamedataSelectionListBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua