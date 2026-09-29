#include "pch.h"
#include "kenshi\gui\SquadManagementScreen.h"
#include "SquadCellViewBinding.h"
#include "PortraitSquadItemBoxBinding.h"
#include "SquadDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/EditBoxBinding.h" 
#include "Bindings/MyGUI/TypesBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"

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
int SquadCellViewBinding::updateSquadSize(lua_State* L)
{
    SquadCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadCellView is nil");

    instance->updateSquadSize();
    return 0;
}

int SquadCellViewBinding::getCellDimension(lua_State* L)
{
    int idx = (lua_gettop(L) >= 3 && testObject<SquadCellView>(L, 1, SquadCellViewBinding::getMetatableName())) ? 2 : 1;
    MyGUI::Widget* sender = WidgetBinding::getWidget(L, idx);
    MyGUI::IntCoord coord(0, 0, 0, 0);
    bool drop = false;
    if (lua_gettop(L) >= idx + 2)
    {
        if (MyGUI::IntCoord* c = testObject<MyGUI::IntCoord>(L, idx + 1, IntCoordBinding::getMetatableName()))
        {
            coord = *c;
            drop = lua_toboolean(L, idx + 2) != 0;
            SquadCellView::getCellDimension(sender, coord, drop);
            *c = coord;
            return pushValue<MyGUI::IntCoord>(L, coord, IntCoordBinding::getMetatableName());
        }
        else
        {
            coord = MyGUIBindings::readIntCoord(L, idx + 1);
            drop = lua_toboolean(L, idx + 2) != 0;
            SquadCellView::getCellDimension(sender, coord, drop);
            return pushValue<MyGUI::IntCoord>(L, coord, IntCoordBinding::getMetatableName());
        }
    }
    else
    {
        drop = lua_toboolean(L, idx + 1) != 0;
        SquadCellView::getCellDimension(sender, coord, drop);
        return pushValue<MyGUI::IntCoord>(L, coord, IntCoordBinding::getMetatableName());
    }
}

/*
Skipped methods needing manual binding:
  line 121: void update(...) - unsupported arg type
*/

int SquadCellViewBinding::onNameChanged(lua_State* L)
{
    SquadCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadCellView is nil");

    MyGUI::EditBox* editBox = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::EditBox>(L, 2, EditBoxBinding::getMetatableName());
    instance->onNameChanged(editBox);
    return 0;
}

int SquadCellViewBinding::onRemove(lua_State* L)
{
    SquadCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SquadCellView is nil");

    MyGUI::Widget* widget = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, WidgetBinding::getMetatableName());
    instance->onRemove(widget);
    return 0;
}


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
        { "updateSquadSize", SquadCellViewBinding::updateSquadSize },
        { "getCellDimension", SquadCellViewBinding::getCellDimension },
        { "onNameChanged", SquadCellViewBinding::onNameChanged },
        { "onRemove", SquadCellViewBinding::onRemove },
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

    // Register global class table for static methods
    pushGlobalTable(L, "SquadCellView");
    registerStaticMethod(L, "getCellDimension", SquadCellViewBinding::getCellDimension);
    lua_setglobal(L, "SquadCellView");
}

} // namespace KenshiLua