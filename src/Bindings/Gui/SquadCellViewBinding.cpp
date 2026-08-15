#include "pch.h"
#include "kenshi\gui\SquadManagementScreen.h"
#include "SquadCellViewBinding.h"
#include "PortraitSquadItemBoxBinding.h"
#include "SquadDataBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
typedef SquadManagementScreen::SquadCellView SquadCellView;

static SquadCellView* getInstance(lua_State* L, int idx)
{
    return checkObject<SquadCellView>(L, idx, SquadCellViewBinding::getMetatableName());
}

// --- Getters for SquadCellView ---
static int SquadCellView_get_portraitsBox(lua_State* L)
{
    SquadCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadCellView is nil");
    return pushObject<SquadManagementScreen::PortraitSquadItemBox>(L, instance->portraitsBox, PortraitSquadItemBoxBinding::getMetatableName());
}

static int SquadCellView_get_txtName(lua_State* L)
{
    SquadCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadCellView is nil");
    lua_pushlightuserdata(L, (void*)instance->txtName);
    return 1;
}

static int SquadCellView_get_txtSquadSize(lua_State* L)
{
    SquadCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadCellView is nil");
    lua_pushlightuserdata(L, (void*)instance->txtSquadSize);
    return 1;
}

static int SquadCellView_get_squad(lua_State* L)
{
    SquadCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadCellView is nil");
    return pushObject<SquadManagementScreen::SquadData>(L, instance->squad, SquadDataBinding::getMetatableName());
}

// --- Setters for SquadCellView ---
static int SquadCellView_set_portraitsBox(lua_State* L)
{
    SquadCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadCellView is nil");
    instance->portraitsBox = lua_isnoneornil(L, 2) ? nullptr : checkObject<SquadManagementScreen::PortraitSquadItemBox>(L, 2, PortraitSquadItemBoxBinding::getMetatableName());
    return 0;
}

static int SquadCellView_set_squad(lua_State* L)
{
    SquadCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadCellView is nil");
    instance->squad = lua_isnoneornil(L, 2) ? nullptr : checkObject<SquadManagementScreen::SquadData>(L, 2, SquadDataBinding::getMetatableName());
    return 0;
}
int SquadCellViewBinding::_DESTRUCTOR(lua_State* L)
{
    SquadCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadCellView is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int SquadCellViewBinding::updateSquadSize(lua_State* L)
{
    SquadCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadCellView is nil");

    instance->updateSquadSize();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 118: SquadCellView* _CONSTRUCTOR(...) - unsupported arg type
  line 121: void update(...) - unsupported arg type
  line 123: void getCellDimension(...) - static method
  line 126: void onNameChanged(...) - unsupported arg type
  line 127: void onRemove(...) - unsupported arg type
*/

int SquadCellViewBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SquadCellViewBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SquadCellView object");
    return 1;
}

void SquadCellViewBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SquadCellViewBinding::gc },
        { "__tostring", SquadCellViewBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", SquadCellViewBinding::_DESTRUCTOR },
        { "updateSquadSize", SquadCellViewBinding::updateSquadSize },
        { 0, 0 }
    };

    registerClass(
        L, 
        SquadCellViewBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SquadCellViewBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "portraitsBox", SquadCellView_get_portraitsBox);
    registerGetter(L, "txtName", SquadCellView_get_txtName);
    registerGetter(L, "txtSquadSize", SquadCellView_get_txtSquadSize);
    registerGetter(L, "squad", SquadCellView_get_squad);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "portraitsBox", SquadCellView_set_portraitsBox);
    registerSetter(L, "squad", SquadCellView_set_squad);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua