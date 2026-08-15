#include "pch.h"
#include "kenshi\gui\LevelEditor.h"
#include "TownListWindowBinding.h"
#include "NpcListWindowBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{
typedef LevelEditor::TownListWindow TownListWindow;


static TownListWindow* getInstance(lua_State* L, int idx)
{
    return checkObject<TownListWindow>(L, idx, TownListWindowBinding::getMetatableName());
}

// --- Getters for TownListWindow ---
// --- Setters for TownListWindow ---
int TownListWindowBinding::formatItem(lua_State* L)
{
    TownListWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownListWindow is nil");

    GameData* o = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    std::string result = instance->formatItem(o);
    lua_pushstring(L, result.c_str());
    return 1;
}

int TownListWindowBinding::_NV_formatItem(lua_State* L)
{
    TownListWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownListWindow is nil");

    GameData* o = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    std::string result = instance->_NV_formatItem(o);
    lua_pushstring(L, result.c_str());
    return 1;
}


int TownListWindowBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TownListWindowBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TownListWindow object");
    return 1;
}

void TownListWindowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TownListWindowBinding::gc },
        { "__tostring", TownListWindowBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "formatItem", TownListWindowBinding::formatItem },
        { "_NV_formatItem", TownListWindowBinding::_NV_formatItem },
        { 0, 0 }
    };

    registerClass(
        L, 
        TownListWindowBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TownListWindowBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to LevelEditor::NpcListWindow
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, TownListWindowBinding::getMetatableName(), KenshiLua::NpcListWindowBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua