#include "pch.h"
#include "kenshi\gui\LevelEditor.h"
#include "FactionListWindowBinding.h"
#include "GamedataSelectionListBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{
typedef LevelEditor::FactionListWindow FactionListWindow;


static FactionListWindow* getInstance(lua_State* L, int idx)
{
    return checkObject<FactionListWindow>(L, idx, FactionListWindowBinding::getMetatableName());
}

// --- Getters for FactionListWindow ---
// --- Setters for FactionListWindow ---
int FactionListWindowBinding::itemSelected(lua_State* L)
{
    FactionListWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionListWindow is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->itemSelected(item);
    return 0;
}

int FactionListWindowBinding::_NV_itemSelected(lua_State* L)
{
    FactionListWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionListWindow is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_NV_itemSelected(item);
    return 0;
}

int FactionListWindowBinding::_DESTRUCTOR(lua_State* L)
{
    FactionListWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionListWindow is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 108: FactionListWindow* _CONSTRUCTOR(...) - unsupported arg type
*/

int FactionListWindowBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int FactionListWindowBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FactionListWindow object");
    return 1;
}

void FactionListWindowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FactionListWindowBinding::gc },
        { "__tostring", FactionListWindowBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "itemSelected", FactionListWindowBinding::itemSelected },
        { "_NV_itemSelected", FactionListWindowBinding::_NV_itemSelected },
        { "_DESTRUCTOR", FactionListWindowBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        FactionListWindowBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FactionListWindowBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to LevelEditor::GamedataSelectionList
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, FactionListWindowBinding::getMetatableName(), KenshiLua::GamedataSelectionListBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua