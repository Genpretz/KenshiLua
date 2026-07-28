#include "pch.h"
#include "kenshi\gui\LoadSaveWindow.h"
#include "ImportGameMenuBinding.h"
#include "LoadSaveWindowBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static ImportGameMenu* getInstance(lua_State* L, int idx)
{
    return checkObject<ImportGameMenu>(L, idx, ImportGameMenuBinding::getMetatableName());
}

// --- Getters for ImportGameMenu ---
static int ImportGameMenu_get_newGameOptions(lua_State* L)
{
    ImportGameMenu* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ImportGameMenu is nil");
    lua_pushlightuserdata(L, (void*)instance->newGameOptions);
    return 1;
}

// --- Setters for ImportGameMenu ---
int ImportGameMenuBinding::_CONSTRUCTOR(lua_State* L)
{
    ImportGameMenu* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ImportGameMenu is nil");

    ImportGameMenu* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ImportGameMenuBinding::_DESTRUCTOR(lua_State* L)
{
    ImportGameMenu* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ImportGameMenu is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ImportGameMenuBinding::select(lua_State* L)
{
    ImportGameMenu* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ImportGameMenu is nil");

    int index = (int)luaL_checkinteger(L, 2);
    instance->select(index);
    return 0;
}

int ImportGameMenuBinding::_NV_select(lua_State* L)
{
    ImportGameMenu* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ImportGameMenu is nil");

    int index = (int)luaL_checkinteger(L, 2);
    instance->_NV_select(index);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 53: void importPress(...) - unsupported arg type
  line 54: void toggleAdvancedOptions(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - ImportGameMenu_get_newGameOptions: NewGameOptionsWindow* (unbound pointer)
  - ImportGameMenuBinding::_CONSTRUCTOR: ImportGameMenu* (unbound pointer)
*/

int ImportGameMenuBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ImportGameMenuBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ImportGameMenu object");
    return 1;
}

void ImportGameMenuBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ImportGameMenuBinding::gc },
        { "__tostring", ImportGameMenuBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", ImportGameMenuBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", ImportGameMenuBinding::_DESTRUCTOR },
        { "select", ImportGameMenuBinding::select },
        { "_NV_select", ImportGameMenuBinding::_NV_select },
        { 0, 0 }
    };

    registerClass(
        L, 
        ImportGameMenuBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ImportGameMenuBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "newGameOptions", ImportGameMenu_get_newGameOptions);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to LoadSaveWindow
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, ImportGameMenuBinding::getMetatableName(), LoadSaveWindowBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua