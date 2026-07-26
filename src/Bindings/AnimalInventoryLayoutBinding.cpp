#include "pch.h"
#include "kenshi\CharacterAnimal.h"
#include "AnimalInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/Gui/InventoryGUIBinding.h"
#include "Bindings/Gui/InventoryLayoutBinding.h"

namespace KenshiLua
{

static AnimalInventoryLayout* getInstance(lua_State* L, int idx)
{
    return checkObject<AnimalInventoryLayout>(L, idx, AnimalInventoryLayoutBinding::getMetatableName());
}

// --- Getters for AnimalInventoryLayout ---
// --- Setters for AnimalInventoryLayout ---
int AnimalInventoryLayoutBinding::_CONSTRUCTOR(lua_State* L)
{
    AnimalInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimalInventoryLayout is nil");

    AnimalInventoryLayout* result = instance->_CONSTRUCTOR();
    return pushObject<AnimalInventoryLayout>(L, result, AnimalInventoryLayoutBinding::getMetatableName());
}

int AnimalInventoryLayoutBinding::_DESTRUCTOR(lua_State* L)
{
    AnimalInventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimalInventoryLayout is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 16: void setupSections(...) - unsupported arg type
  line 17: void _NV_setupSections(...) - unsupported arg type
*/

int AnimalInventoryLayoutBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int AnimalInventoryLayoutBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AnimalInventoryLayout object");
    return 1;
}

void AnimalInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AnimalInventoryLayoutBinding::gc },
        { "__tostring", AnimalInventoryLayoutBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", AnimalInventoryLayoutBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", AnimalInventoryLayoutBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        AnimalInventoryLayoutBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AnimalInventoryLayoutBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to InventoryLayout
    setMetatableParent(L, AnimalInventoryLayoutBinding::getMetatableName(), InventoryLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua