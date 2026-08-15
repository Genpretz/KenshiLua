#include "pch.h"
#include "kenshi\gui\LevelEditor.h"
#include "SquadListWindowBinding.h"
#include "GamedataSelectionListBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{
typedef LevelEditor::SquadListWindow SquadListWindow;

static SquadListWindow* getInstance(lua_State* L, int idx)
{
    return checkObject<SquadListWindow>(L, idx, SquadListWindowBinding::getMetatableName());
}

// --- Getters for SquadListWindow ---
// --- Setters for SquadListWindow ---
int SquadListWindowBinding::refresh(lua_State* L)
{
    SquadListWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadListWindow is nil");

    GameData* faction = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->refresh(faction);
    return 0;
}

int SquadListWindowBinding::itemSelected(lua_State* L)
{
    SquadListWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadListWindow is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->itemSelected(item);
    return 0;
}

int SquadListWindowBinding::_NV_itemSelected(lua_State* L)
{
    SquadListWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadListWindow is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_NV_itemSelected(item);
    return 0;
}


int SquadListWindowBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SquadListWindowBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SquadListWindow object");
    return 1;
}

void SquadListWindowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SquadListWindowBinding::gc },
        { "__tostring", SquadListWindowBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "refresh", SquadListWindowBinding::refresh },
        { "itemSelected", SquadListWindowBinding::itemSelected },
        { "_NV_itemSelected", SquadListWindowBinding::_NV_itemSelected },
        { 0, 0 }
    };

    registerClass(
        L, 
        SquadListWindowBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SquadListWindowBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to LevelEditor::GamedataSelectionList
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, SquadListWindowBinding::getMetatableName(), KenshiLua::GamedataSelectionListBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua