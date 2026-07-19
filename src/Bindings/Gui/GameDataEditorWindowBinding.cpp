#include "pch.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"

#include <kenshi/gui/GameDataEditorWindow.h>
#include "GameDataEditorWindowBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static GameDataEditorWindow* getInstance(lua_State* L, int idx)
{
    return checkObject<GameDataEditorWindow>(L, idx, GameDataEditorWindowBinding::getMetatableName());
}

// --- Getters for GameDataEditorWindow ---
static int GameDataEditorWindow_get_win(lua_State* L)
{
    GameDataEditorWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataEditorWindow is nil");
    return pushObject<DatapanelGUI>(L, instance->win, DatapanelGUIBinding::getMetatableName());
}

static int GameDataEditorWindow_get_data(lua_State* L)
{
    GameDataEditorWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataEditorWindow is nil");
    return pushObject<GameData>(L, instance->data, GameDataBinding::getMetatableName());
}

// --- Setters for GameDataEditorWindow ---
int GameDataEditorWindowBinding::_DESTRUCTOR(lua_State* L)
{
    GameDataEditorWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataEditorWindow is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int GameDataEditorWindowBinding::_NV_show(lua_State* L)
{
    GameDataEditorWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataEditorWindow is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_show(on);
    return 0;
}

int GameDataEditorWindowBinding::initDataValues(lua_State* L)
{
    GameDataEditorWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataEditorWindow is nil");

    instance->initDataValues();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 18: void show(...) - overloaded method
  line 20: void show(...) - overloaded method
*/

int GameDataEditorWindowBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int GameDataEditorWindowBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.GameDataEditorWindow object");
    return 1;
}

void GameDataEditorWindowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GameDataEditorWindowBinding::gc },
        { "__tostring", GameDataEditorWindowBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", GameDataEditorWindowBinding::_DESTRUCTOR },
        { "_NV_show", GameDataEditorWindowBinding::_NV_show },
        { "initDataValues", GameDataEditorWindowBinding::initDataValues },
        { 0, 0 }
    };

    registerClass(
        L, 
        GameDataEditorWindowBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GameDataEditorWindowBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, GameDataEditorWindow_get_win);
    lua_setfield(L, -2, "win");
    lua_pushcfunction(L, GameDataEditorWindow_get_data);
    lua_setfield(L, -2, "data");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, GameDataEditorWindowBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua