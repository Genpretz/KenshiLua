#include "pch.h"
#include "kenshi\gui\LevelEditor.h"
#include "NpcListWindowBinding.h"
#include "GamedataSelectionListBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{
typedef LevelEditor::NpcListWindow NpcListWindow;


static NpcListWindow* getInstance(lua_State* L, int idx)
{
    return checkObject<NpcListWindow>(L, idx, NpcListWindowBinding::getMetatableName());
}

// --- Getters for NpcListWindow ---
// --- Setters for NpcListWindow ---
int NpcListWindowBinding::_DESTRUCTOR(lua_State* L)
{
    NpcListWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NpcListWindow is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int NpcListWindowBinding::itemSelected(lua_State* L)
{
    NpcListWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NpcListWindow is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->itemSelected(item);
    return 0;
}

int NpcListWindowBinding::_NV_itemSelected(lua_State* L)
{
    NpcListWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NpcListWindow is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_NV_itemSelected(item);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 137: NpcListWindow* _CONSTRUCTOR(...) - unsupported arg type
*/

int NpcListWindowBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int NpcListWindowBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.NpcListWindow object");
    return 1;
}

void NpcListWindowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       NpcListWindowBinding::gc },
        { "__tostring", NpcListWindowBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", NpcListWindowBinding::_DESTRUCTOR },
        { "itemSelected", NpcListWindowBinding::itemSelected },
        { "_NV_itemSelected", NpcListWindowBinding::_NV_itemSelected },
        { 0, 0 }
    };

    registerClass(
        L, 
        NpcListWindowBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, NpcListWindowBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to LevelEditor::GamedataSelectionList
    setMetatableParent(L, NpcListWindowBinding::getMetatableName(), KenshiLua::GamedataSelectionListBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua