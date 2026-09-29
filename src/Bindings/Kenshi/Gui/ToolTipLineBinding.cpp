#include "pch.h"
#include "kenshi\gui\Tooltip.h"
#include "ToolTipLineBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/MyGUI/MyGUIBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Bindings/MyGUI/EditBoxBinding.h"

namespace KenshiLua
{
typedef ToolTip::ToolTipLine ToolTipLine;

static ToolTipLine* getInstance(lua_State* L, int idx)
{
    return checkObject<ToolTipLine>(L, idx, ToolTipLineBinding::getMetatableName());
}

// --- Getters for ToolTipLine ---
static int ToolTipLine_get_content(lua_State* L)
{
    ToolTipLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipLine is nil");
    return MyGUIBindings::pushWidget(L, instance->content);
}

static int ToolTipLine_get_leftBox(lua_State* L)
{
    ToolTipLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipLine is nil");
    return MyGUIBindings::pushWidget(L, instance->leftBox);
}

static int ToolTipLine_get_rightBox(lua_State* L)
{
    ToolTipLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipLine is nil");
    return MyGUIBindings::pushWidget(L, instance->rightBox);
}

static int ToolTipLine_get_width(lua_State* L)
{
    ToolTipLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipLine is nil");
    lua_pushinteger(L, instance->width);
    return 1;
}

// --- Setters for ToolTipLine ---
static int ToolTipLine_set_content(lua_State* L)
{
    ToolTipLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipLine is nil");
    instance->content = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGUIBinding::getMetatableName());
    return 0;
}

static int ToolTipLine_set_leftBox(lua_State* L)
{
    ToolTipLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipLine is nil");
    instance->leftBox = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::EditBox>(L, 2, EditBoxBinding::getMetatableName());
    return 0;
}

static int ToolTipLine_set_rightBox(lua_State* L)
{
    ToolTipLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipLine is nil");
    instance->rightBox = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::EditBox>(L, 2, EditBoxBinding::getMetatableName());
    return 0;
}

static int ToolTipLine_set_width(lua_State* L)
{
    ToolTipLine* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ToolTipLine is nil");
    instance->width = (int)luaL_checkinteger(L, 2);
    return 0;
}

int ToolTipLineBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ToolTipLineBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ToolTipLine object");
    return 1;
}

void ToolTipLineBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ToolTipLineBinding::gc },
        { "__tostring", ToolTipLineBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        ToolTipLineBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ToolTipLineBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "content", ToolTipLine_get_content);
    registerGetter(L, "leftBox", ToolTipLine_get_leftBox);
    registerGetter(L, "rightBox", ToolTipLine_get_rightBox);
    registerGetter(L, "width", ToolTipLine_get_width);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "content", ToolTipLine_set_content);
    registerSetter(L, "leftBox", ToolTipLine_set_leftBox);
    registerSetter(L, "rightBox", ToolTipLine_set_rightBox);
    registerSetter(L, "width", ToolTipLine_set_width);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
