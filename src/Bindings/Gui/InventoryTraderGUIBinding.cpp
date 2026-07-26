#include "pch.h"
#include "kenshi\gui\InventoryTraderGUI.h"
#include "InventoryTraderGUIBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/Gui/InventoryGUIBinding.h"
#include "Bindings/Gui/InventoryLayoutBinding.h"
#include "Bindings/InventorySectionBinding.h"
#include "Bindings/RootObjectBinding.h"

namespace KenshiLua
{

static InventoryTraderGUI* getInstance(lua_State* L, int idx)
{
    return checkObject<InventoryTraderGUI>(L, idx, InventoryTraderGUIBinding::getMetatableName());
}

// --- Getters for InventoryTraderGUI ---
static int InventoryTraderGUI_get_sectionWidth(lua_State* L)
{
    InventoryTraderGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTraderGUI is nil");
    lua_pushinteger(L, instance->sectionWidth);
    return 1;
}

static int InventoryTraderGUI_get_sectionHeight(lua_State* L)
{
    InventoryTraderGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTraderGUI is nil");
    lua_pushinteger(L, instance->sectionHeight);
    return 1;
}

// --- Setters for InventoryTraderGUI ---
static int InventoryTraderGUI_set_sectionWidth(lua_State* L)
{
    InventoryTraderGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTraderGUI is nil");
    instance->sectionWidth = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int InventoryTraderGUI_set_sectionHeight(lua_State* L)
{
    InventoryTraderGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTraderGUI is nil");
    instance->sectionHeight = (int)luaL_checkinteger(L, 2);
    return 0;
}

int InventoryTraderGUIBinding::_CONSTRUCTOR(lua_State* L)
{
    InventoryTraderGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTraderGUI is nil");

    Inventory* inv = checkObject<Inventory>(L, 2, InventoryBinding::getMetatableName());
    InventoryLayout* layout = checkObject<InventoryLayout>(L, 3, InventoryLayoutBinding::getMetatableName());
    RootObject* callback = checkObject<RootObject>(L, 4, RootObjectBinding::getMetatableName());
    InventoryTraderGUI* result = instance->_CONSTRUCTOR(inv, layout, callback);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int InventoryTraderGUIBinding::_DESTRUCTOR(lua_State* L)
{
    InventoryTraderGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTraderGUI is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int InventoryTraderGUIBinding::getInventory(lua_State* L)
{
    InventoryTraderGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTraderGUI is nil");

    Inventory* result = instance->getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int InventoryTraderGUIBinding::_NV_getInventory(lua_State* L)
{
    InventoryTraderGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTraderGUI is nil");

    Inventory* result = instance->_NV_getInventory();
    return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
}

int InventoryTraderGUIBinding::getCallbackCharacter(lua_State* L)
{
    InventoryTraderGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTraderGUI is nil");

    Character* result = instance->getCallbackCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int InventoryTraderGUIBinding::_NV_getCallbackCharacter(lua_State* L)
{
    InventoryTraderGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTraderGUI is nil");

    Character* result = instance->_NV_getCallbackCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int InventoryTraderGUIBinding::getCallbackObject(lua_State* L)
{
    InventoryTraderGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTraderGUI is nil");

    RootObject* result = instance->getCallbackObject();
    return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
}

int InventoryTraderGUIBinding::_NV_getCallbackObject(lua_State* L)
{
    InventoryTraderGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTraderGUI is nil");

    RootObject* result = instance->_NV_getCallbackObject();
    return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
}

int InventoryTraderGUIBinding::refreshSection(lua_State* L)
{
    InventoryTraderGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTraderGUI is nil");

    InventorySection* section = checkObject<InventorySection>(L, 2, InventorySectionBinding::getMetatableName());
    instance->refreshSection(section);
    return 0;
}

int InventoryTraderGUIBinding::_NV_refreshSection(lua_State* L)
{
    InventoryTraderGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryTraderGUI is nil");

    InventorySection* section = checkObject<InventorySection>(L, 2, InventorySectionBinding::getMetatableName());
    instance->_NV_refreshSection(section);
    return 0;
}

int InventoryTraderGUIBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int InventoryTraderGUIBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.InventoryTraderGUI object");
    return 1;
}

void InventoryTraderGUIBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       InventoryTraderGUIBinding::gc },
        { "__tostring", InventoryTraderGUIBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", InventoryTraderGUIBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", InventoryTraderGUIBinding::_DESTRUCTOR },
        { "getInventory", InventoryTraderGUIBinding::getInventory },
        { "_NV_getInventory", InventoryTraderGUIBinding::_NV_getInventory },
        { "getCallbackCharacter", InventoryTraderGUIBinding::getCallbackCharacter },
        { "_NV_getCallbackCharacter", InventoryTraderGUIBinding::_NV_getCallbackCharacter },
        { "getCallbackObject", InventoryTraderGUIBinding::getCallbackObject },
        { "_NV_getCallbackObject", InventoryTraderGUIBinding::_NV_getCallbackObject },
        { "refreshSection", InventoryTraderGUIBinding::refreshSection },
        { "_NV_refreshSection", InventoryTraderGUIBinding::_NV_refreshSection },
        { 0, 0 }
    };

    registerClass(
        L, 
        InventoryTraderGUIBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, InventoryTraderGUIBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "sectionWidth", InventoryTraderGUI_get_sectionWidth);
    registerGetter(L, "sectionHeight", InventoryTraderGUI_get_sectionHeight);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "sectionWidth", InventoryTraderGUI_set_sectionWidth);
    registerSetter(L, "sectionHeight", InventoryTraderGUI_set_sectionHeight);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to InventoryGUI
    setMetatableParent(L, InventoryTraderGUIBinding::getMetatableName(), InventoryGUIBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua