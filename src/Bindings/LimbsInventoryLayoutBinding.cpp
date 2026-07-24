#include "pch.h"
#include "kenshi\MedicalSystem.h"
#include "LimbsInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/Gui/InventoryGUIBinding.h"
#include "Bindings/Gui/InventoryLayoutBinding.h"

namespace KenshiLua
{

static LimbsInventoryLayout* getInstance(lua_State* L, int idx)
{
    return checkObject<LimbsInventoryLayout>(L, idx, LimbsInventoryLayoutBinding::getMetatableName());
}

// --- Getters for LimbsInventoryLayout ---
static int LimbsInventoryLayout_get_character(lua_State* L)
{
    LimbsInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LimbsInventoryLayout is nil");
    return pushObject<Character>(L, instance->character, CharacterBinding::getMetatableName());
}

// --- Setters for LimbsInventoryLayout ---
static int LimbsInventoryLayout_set_character(lua_State* L)
{
    LimbsInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LimbsInventoryLayout is nil");
    instance->character = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

int LimbsInventoryLayoutBinding::_CONSTRUCTOR(lua_State* L)
{
    LimbsInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LimbsInventoryLayout is nil");

    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    LimbsInventoryLayout* result = instance->_CONSTRUCTOR(c);
    return pushObject<LimbsInventoryLayout>(L, result, LimbsInventoryLayoutBinding::getMetatableName());
}

int LimbsInventoryLayoutBinding::_DESTRUCTOR(lua_State* L)
{
    LimbsInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LimbsInventoryLayout is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 36: void setupSections(...) - unsupported arg type
  line 37: void _NV_setupSections(...) - unsupported arg type
*/

int LimbsInventoryLayoutBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int LimbsInventoryLayoutBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.LimbsInventoryLayout object");
    return 1;
}

void LimbsInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       LimbsInventoryLayoutBinding::gc },
        { "__tostring", LimbsInventoryLayoutBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", LimbsInventoryLayoutBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", LimbsInventoryLayoutBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        LimbsInventoryLayoutBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, LimbsInventoryLayoutBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, LimbsInventoryLayout_get_character);
    lua_setfield(L, -2, "character");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, LimbsInventoryLayout_set_character);
    lua_setfield(L, -2, "character");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to InventoryLayout
    setMetatableParent(L, LimbsInventoryLayoutBinding::getMetatableName(), InventoryLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
