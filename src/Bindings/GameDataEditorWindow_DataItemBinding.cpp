#include "pch.h"
#include "Bindings/GameDataEditorWindow_DataItemBinding.h"
#include "Lua/BindingHelpers.h"
#include <kenshi/gui/GameDataEditorWindow.h>

namespace KenshiLua
{

static GameDataEditorWindow::DataItem* getInstance(lua_State* L, int idx)
{
    return checkObject<GameDataEditorWindow::DataItem>(L, idx, GameDataEditorWindow_DataItemBinding::getMetatableName());
}

static int DataItem_get_name(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "GameDataEditorWindow::DataItem is nil");
    lua_pushstring(L, inst->name.c_str());
    return 1;
}

static int DataItem_get_edit(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "GameDataEditorWindow::DataItem is nil");
    if (inst->edit) lua_pushlightuserdata(L, (void*)inst->edit);
    else lua_pushnil(L);
    return 1;
}

static int DataItem_get_label(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "GameDataEditorWindow::DataItem is nil");
    if (inst->label) lua_pushlightuserdata(L, (void*)inst->label);
    else lua_pushnil(L);
    return 1;
}

static int DataItem_set_name(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "GameDataEditorWindow::DataItem is nil");
    inst->name = luaL_checkstring(L, 2);
    return 0;
}

static int DataItem_set_edit(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "GameDataEditorWindow::DataItem is nil");
    inst->edit = (MyGUI::EditBox*)lua_touserdata(L, 2);
    return 0;
}

static int DataItem_set_label(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "GameDataEditorWindow::DataItem is nil");
    inst->label = (MyGUI::TextBox*)lua_touserdata(L, 2);
    return 0;
}

int GameDataEditorWindow_DataItemBinding::gc(lua_State* L)
{
    return 0;
}

int GameDataEditorWindow_DataItemBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.GameDataEditorWindow_DataItem object");
    return 1;
}

int GameDataEditorWindow_DataItemBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a == b) ? 1 : 0);
    return 1;
}

void GameDataEditorWindow_DataItemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       operator_eq },
        { "__gc",       gc },
        { "__tostring", tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L); // __getters
    registerGetter(L, "name", DataItem_get_name);
    registerGetter(L, "edit", DataItem_get_edit);
    registerGetter(L, "label", DataItem_get_label);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "name", DataItem_set_name);
    registerSetter(L, "edit", DataItem_set_edit);
    registerSetter(L, "label", DataItem_set_label);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}
} // namespace KenshiLua
