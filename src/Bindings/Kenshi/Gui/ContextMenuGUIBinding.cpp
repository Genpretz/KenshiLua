#include "pch.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"
#include "Bindings/MyGUI/MyGUIBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Bindings/MyGUI/TextBoxBinding.h"
#include "Bindings/MyGUI/TypesBinding.h"

#include <kenshi/gui/ContextMenu.h>
#include "ContextMenuGUIBinding.h"
#include "BaseLayoutBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static ContextMenuGUI* getInstance(lua_State* L, int idx)
{
    return checkObject<ContextMenuGUI>(L, idx, ContextMenuGUIBinding::getMetatableName());
}

// --- Getters for ContextMenuGUI ---
static int ContextMenuGUI_get_contextMenuTarget(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");
    return HandBinding::push(L, instance->contextMenuTarget);
}

static int ContextMenuGUI_get_name(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");
    lua_pushstring(L, instance->name.c_str());
    return 1;
}

static int ContextMenuGUI_get_nameText(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");
    return MyGUIBindings::pushWidget(L, instance->nameText);
}

static int ContextMenuGUI_set_nameText(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");
    instance->nameText = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::TextBox>(L, 2, TextBoxBinding::getMetatableName());
    return 0;
}

static int ContextMenuGUI_get_optionsList(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");
    return MyGUIBindings::pushWidget(L, instance->optionsList);
}

static int ContextMenuGUI_set_optionsList(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");
    instance->optionsList = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    return 0;
}

static int ContextMenuGUI_get_optionCoords(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");
    return pushValue<MyGUI::IntCoord>(L, instance->optionCoords, IntCoordBinding::getMetatableName());
}

static int ContextMenuGUI_set_optionCoords(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");
    instance->optionCoords = MyGUIBindings::readIntCoord(L, 2);
    return 0;
}

static int ContextMenuGUI_get_buttonCoords(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");
    return pushValue<MyGUI::IntCoord>(L, instance->buttonCoords, IntCoordBinding::getMetatableName());
}

static int ContextMenuGUI_set_buttonCoords(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");
    instance->buttonCoords = MyGUIBindings::readIntCoord(L, 2);
    return 0;
}

static int ContextMenuGUI_get_valueCoords(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");
    return pushValue<MyGUI::IntCoord>(L, instance->valueCoords, IntCoordBinding::getMetatableName());
}

static int ContextMenuGUI_set_valueCoords(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");
    instance->valueCoords = MyGUIBindings::readIntCoord(L, 2);
    return 0;
}

// --- Setters for ContextMenuGUI ---
static int ContextMenuGUI_set_contextMenuTarget(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");
    instance->contextMenuTarget = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int ContextMenuGUI_set_name(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");
    instance->name = luaL_checkstring(L, 2);
    return 0;
}

int ContextMenuGUIBinding::getMainWidget(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");

    MyGUI::Widget* result = instance->getMainWidget();
    return MyGUIBindings::pushWidget(L, result);
}

int ContextMenuGUIBinding::getVisible(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");

    bool result = instance->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ContextMenuGUIBinding::setVisible(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->setVisible(visible);
    return 0;
}

int ContextMenuGUIBinding::show(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");

    lektor<int>* ordersList = checkObject<lektor<int>>(L, 2, LektorIntBinding<int>::metaName);
    if (!ordersList) return luaL_error(L, "Argument 2 must be lektor<int>");
    std::string name = luaL_checkstring(L, 3);
    bool offset = lua_toboolean(L, 4) != 0;
    instance->show(*ordersList, name, offset);
    return 0;
}

int ContextMenuGUIBinding::optionSelected(lua_State* L)
{
    ContextMenuGUI* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ContextMenuGUI is nil");

    MyGUI::Widget* sender = checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    int left = (int)luaL_checkinteger(L, 3);
    int top = (int)luaL_checkinteger(L, 4);
    MyGUI::MouseButton id = MyGUI::MouseButton::Enum((int)luaL_checkinteger(L, 5));
    instance->optionSelected(sender, left, top, id);
    return 0;
}

int ContextMenuGUIBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ContextMenuGUIBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ContextMenuGUI object");
    return 1;
}

void ContextMenuGUIBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ContextMenuGUIBinding::gc },
        { "__tostring", ContextMenuGUIBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getMainWidget", ContextMenuGUIBinding::getMainWidget },
        { "getVisible", ContextMenuGUIBinding::getVisible },
        { "setVisible", ContextMenuGUIBinding::setVisible },
        { "show", ContextMenuGUIBinding::show },
        { "optionSelected", ContextMenuGUIBinding::optionSelected },
        { 0, 0 }
    };

    registerClass(
        L, 
        ContextMenuGUIBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ContextMenuGUIBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "contextMenuTarget", ContextMenuGUI_get_contextMenuTarget);
    registerGetter(L, "name", ContextMenuGUI_get_name);
    registerGetter(L, "nameText", ContextMenuGUI_get_nameText);
    registerGetter(L, "optionsList", ContextMenuGUI_get_optionsList);
    registerGetter(L, "optionCoords", ContextMenuGUI_get_optionCoords);
    registerGetter(L, "buttonCoords", ContextMenuGUI_get_buttonCoords);
    registerGetter(L, "valueCoords", ContextMenuGUI_get_valueCoords);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "contextMenuTarget", ContextMenuGUI_set_contextMenuTarget);
    registerSetter(L, "name", ContextMenuGUI_set_name);
    registerSetter(L, "nameText", ContextMenuGUI_set_nameText);
    registerSetter(L, "optionsList", ContextMenuGUI_set_optionsList);
    registerSetter(L, "optionCoords", ContextMenuGUI_set_optionCoords);
    registerSetter(L, "buttonCoords", ContextMenuGUI_set_buttonCoords);
    registerSetter(L, "valueCoords", ContextMenuGUI_set_valueCoords);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua