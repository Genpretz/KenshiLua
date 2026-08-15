#include "pch.h"
#include "kenshi\gui\PortraitManager.h"
#include "PortraitMainCellViewBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/PortraitDataBinding.h"

namespace KenshiLua
{

static PortraitMainCellView* getInstance(lua_State* L, int idx)
{
    return checkObject<PortraitMainCellView>(L, idx, PortraitMainCellViewBinding::getMetatableName());
}

// --- Getters for PortraitMainCellView ---
static int PortraitMainCellView_get_characterHandle(lua_State* L)
{
    PortraitMainCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitMainCellView is nil");
    return HandBinding::push(L, instance->characterHandle);
}

static int PortraitMainCellView_get_name(lua_State* L)
{
    PortraitMainCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitMainCellView is nil");
    lua_pushstring(L, instance->name.c_str());
    return 1;
}

static int PortraitMainCellView_get_border(lua_State* L)
{
    PortraitMainCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitMainCellView is nil");
    lua_pushlightuserdata(L, (void*)instance->border);
    return 1;
}

static int PortraitMainCellView_get_imageBackground(lua_State* L)
{
    PortraitMainCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitMainCellView is nil");
    lua_pushlightuserdata(L, (void*)instance->imageBackground);
    return 1;
}

static int PortraitMainCellView_get_imagePortrait(lua_State* L)
{
    PortraitMainCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitMainCellView is nil");
    lua_pushlightuserdata(L, (void*)instance->imagePortrait);
    return 1;
}

static int PortraitMainCellView_get_imageOverlayBack(lua_State* L)
{
    PortraitMainCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitMainCellView is nil");
    lua_pushlightuserdata(L, (void*)instance->imageOverlayBack);
    return 1;
}

static int PortraitMainCellView_get_imageOverlayFront(lua_State* L)
{
    PortraitMainCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitMainCellView is nil");
    lua_pushlightuserdata(L, (void*)instance->imageOverlayFront);
    return 1;
}

static int PortraitMainCellView_get_textName(lua_State* L)
{
    PortraitMainCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitMainCellView is nil");
    lua_pushlightuserdata(L, (void*)instance->textName);
    return 1;
}

// --- Setters for PortraitMainCellView ---
static int PortraitMainCellView_set_characterHandle(lua_State* L)
{
    PortraitMainCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitMainCellView is nil");
    instance->characterHandle = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int PortraitMainCellView_set_name(lua_State* L)
{
    PortraitMainCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitMainCellView is nil");
    instance->name = luaL_checkstring(L, 2);
    return 0;
}

int PortraitMainCellViewBinding::resize(lua_State* L)
{
    PortraitMainCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitMainCellView is nil");

    int size = (int)luaL_checkinteger(L, 2);
    instance->resize(size);
    return 0;
}

int PortraitMainCellViewBinding::setName(lua_State* L)
{
    PortraitMainCellView* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitMainCellView is nil");

    const std::string newName = luaL_checkstring(L, 2);
    instance->setName(newName);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 86: void update(...) - unsupported arg type
  line 87: void getCellDimension(...) - static method
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - PortraitMainCellView_get_border: MyGUI::Button* (unbound pointer)
  - PortraitMainCellView_get_imageBackground: MyGUI::ImageBox* (unbound pointer)
  - PortraitMainCellView_get_imagePortrait: MyGUI::ImageBox* (unbound pointer)
  - PortraitMainCellView_get_imageOverlayBack: MyGUI::ImageBox* (unbound pointer)
  - PortraitMainCellView_get_imageOverlayFront: MyGUI::ImageBox* (unbound pointer)
  - PortraitMainCellView_get_textName: MyGUI::TextBox* (unbound pointer)
*/

int PortraitMainCellViewBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int PortraitMainCellViewBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.PortraitMainCellView object");
    return 1;
}

void PortraitMainCellViewBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       PortraitMainCellViewBinding::gc },
        { "__tostring", PortraitMainCellViewBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "resize", PortraitMainCellViewBinding::resize },
        { "setName", PortraitMainCellViewBinding::setName },
        { 0, 0 }
    };

    registerClass(
        L, 
        PortraitMainCellViewBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, PortraitMainCellViewBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "characterHandle", PortraitMainCellView_get_characterHandle);
    registerGetter(L, "name", PortraitMainCellView_get_name);
    registerGetter(L, "border", PortraitMainCellView_get_border);
    registerGetter(L, "imageBackground", PortraitMainCellView_get_imageBackground);
    registerGetter(L, "imagePortrait", PortraitMainCellView_get_imagePortrait);
    registerGetter(L, "imageOverlayBack", PortraitMainCellView_get_imageOverlayBack);
    registerGetter(L, "imageOverlayFront", PortraitMainCellView_get_imageOverlayFront);
    registerGetter(L, "textName", PortraitMainCellView_get_textName);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "characterHandle", PortraitMainCellView_set_characterHandle);
    registerSetter(L, "name", PortraitMainCellView_set_name);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseCellView<PortraitData*>
    // setMetatableParent(L, PortraitMainCellViewBinding::getMetatableName(), wraps::BaseCellView<PortraitData*>Binding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua