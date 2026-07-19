#include "pch.h"
#include "kenshi\Character.h"
#include "CharacterInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/Gui/InventoryGUIBinding.h"
#include "Bindings/Gui/InventoryLayoutBinding.h"

namespace KenshiLua
{

static CharacterInventoryLayout* getInstance(lua_State* L, int idx)
{
    return checkObject<CharacterInventoryLayout>(L, idx, CharacterInventoryLayoutBinding::getMetatableName());
}

// --- Getters for CharacterInventoryLayout ---
// --- Setters for CharacterInventoryLayout ---
int CharacterInventoryLayoutBinding::_CONSTRUCTOR(lua_State* L)
{
    CharacterInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterInventoryLayout is nil");

    CharacterInventoryLayout* result = instance->_CONSTRUCTOR();
    return pushObject<CharacterInventoryLayout>(L, result, CharacterInventoryLayoutBinding::getMetatableName());
}

int CharacterInventoryLayoutBinding::_DESTRUCTOR(lua_State* L)
{
    CharacterInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterInventoryLayout is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 171: void setupSections(...) - unsupported arg type
  line 172: void _NV_setupSections(...) - unsupported arg type
*/

int CharacterInventoryLayoutBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CharacterInventoryLayoutBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CharacterInventoryLayout object");
    return 1;
}

void CharacterInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CharacterInventoryLayoutBinding::gc },
        { "__tostring", CharacterInventoryLayoutBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", CharacterInventoryLayoutBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", CharacterInventoryLayoutBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        CharacterInventoryLayoutBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CharacterInventoryLayoutBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to InventoryLayout
    // setMetatableParent(L, CharacterInventoryLayoutBinding::getMetatableName(), InventoryLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua