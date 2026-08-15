#include "pch.h"
#include "kenshi\gui\SquadManagementScreen.h"
#include "PortraitSquadCellViewBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
typedef SquadManagementScreen::PortraitSquadCellView PortraitSquadCellView;


static PortraitSquadCellView* getInstance(lua_State* L, int idx)
{
    return checkObject<PortraitSquadCellView>(L, idx, PortraitSquadCellViewBinding::getMetatableName());
}

// --- Getters for PortraitSquadCellView ---
static int PortraitSquadCellView_get_characterHandle(lua_State* L)
{
    PortraitSquadCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitSquadCellView is nil");
    return HandBinding::push(L, instance->characterHandle);
}

static int PortraitSquadCellView_get_name(lua_State* L)
{
    PortraitSquadCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitSquadCellView is nil");
    lua_pushstring(L, instance->name.c_str());
    return 1;
}

static int PortraitSquadCellView_get_border(lua_State* L)
{
    PortraitSquadCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitSquadCellView is nil");
    lua_pushlightuserdata(L, (void*)instance->border);
    return 1;
}

static int PortraitSquadCellView_get_imgBoxPortrait(lua_State* L)
{
    PortraitSquadCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitSquadCellView is nil");
    lua_pushlightuserdata(L, (void*)instance->imgBoxPortrait);
    return 1;
}

static int PortraitSquadCellView_get_txtName(lua_State* L)
{
    PortraitSquadCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitSquadCellView is nil");
    lua_pushlightuserdata(L, (void*)instance->txtName);
    return 1;
}

// --- Setters for PortraitSquadCellView ---
static int PortraitSquadCellView_set_characterHandle(lua_State* L)
{
    PortraitSquadCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitSquadCellView is nil");
    instance->characterHandle = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int PortraitSquadCellView_set_name(lua_State* L)
{
    PortraitSquadCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitSquadCellView is nil");
    instance->name = luaL_checkstring(L, 2);
    return 0;
}

int PortraitSquadCellViewBinding::resize(lua_State* L)
{
    PortraitSquadCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitSquadCellView is nil");

    instance->resize();
    return 0;
}

int PortraitSquadCellViewBinding::setName(lua_State* L)
{
    PortraitSquadCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitSquadCellView is nil");

    const std::string newName = luaL_checkstring(L, 2);
    instance->setName(newName);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 81: void update(...) - unsupported arg type
  line 82: void getCellDimension(...) - static method
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - PortraitSquadCellView_get_border: MyGUI::Button* (unbound pointer)
  - PortraitSquadCellView_get_imgBoxPortrait: MyGUI::ImageBox* (unbound pointer)
  - PortraitSquadCellView_get_txtName: MyGUI::TextBox* (unbound pointer)
*/

int PortraitSquadCellViewBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int PortraitSquadCellViewBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.PortraitSquadCellView object");
    return 1;
}

void PortraitSquadCellViewBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       PortraitSquadCellViewBinding::gc },
        { "__tostring", PortraitSquadCellViewBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "resize", PortraitSquadCellViewBinding::resize },
        { "setName", PortraitSquadCellViewBinding::setName },
        { 0, 0 }
    };

    registerClass(
        L, 
        PortraitSquadCellViewBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, PortraitSquadCellViewBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "characterHandle", PortraitSquadCellView_get_characterHandle);
    registerGetter(L, "name", PortraitSquadCellView_get_name);
    registerGetter(L, "border", PortraitSquadCellView_get_border);
    registerGetter(L, "imgBoxPortrait", PortraitSquadCellView_get_imgBoxPortrait);
    registerGetter(L, "txtName", PortraitSquadCellView_get_txtName);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "characterHandle", PortraitSquadCellView_set_characterHandle);
    registerSetter(L, "name", PortraitSquadCellView_set_name);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseCellView<PortraitData*>
    // setMetatableParent(L, PortraitSquadCellViewBinding::getMetatableName(), wraps::BaseCellView<PortraitData*>Binding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua