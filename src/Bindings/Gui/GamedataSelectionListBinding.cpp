#include "pch.h"
#include "kenshi\gui\LevelEditor.h"
#include "GamedataSelectionListBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Gui/LevelEditorBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/MyGuiBinding.h"

namespace KenshiLua
{
typedef LevelEditor::GamedataSelectionList GamedataSelectionList;

static GamedataSelectionList* getInstance(lua_State* L, int idx)
{
    return checkObject<GamedataSelectionList>(L, idx, GamedataSelectionListBinding::getMetatableName());
}

// --- Getters for GamedataSelectionList ---
static int GamedataSelectionList_get_win(lua_State* L)
{
    GamedataSelectionList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GamedataSelectionList is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->win, MyGuiBinding::getMetatableName());
}

static int GamedataSelectionList_get_list(lua_State* L)
{
    GamedataSelectionList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GamedataSelectionList is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->list, MyGuiBinding::getMetatableName());
}

static int GamedataSelectionList_get_items(lua_State* L)
{
    GamedataSelectionList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GamedataSelectionList is nil");
    return pushObject<lektor<GameData*>>(L, &instance->items, LektorPtrBinding<GameData*>::getMetatableName());
}

static int GamedataSelectionList_get_levelEditor(lua_State* L)
{
    GamedataSelectionList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GamedataSelectionList is nil");
    return pushObject<LevelEditor>(L, instance->levelEditor, LevelEditorBinding::getMetatableName());
}

static int GamedataSelectionList_get_lastItem(lua_State* L)
{
    GamedataSelectionList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GamedataSelectionList is nil");
    lua_pushinteger(L, (lua_Integer)instance->lastItem);
    return 1;
}

// --- Setters for GamedataSelectionList ---
static int GamedataSelectionList_set_lastItem(lua_State* L)
{
    GamedataSelectionList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GamedataSelectionList is nil");
    instance->lastItem = (unsigned __int64)luaL_checkinteger(L, 2);
    return 0;
}

int GamedataSelectionListBinding::_CONSTRUCTOR(lua_State* L)
{
    GamedataSelectionList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GamedataSelectionList is nil");

    LevelEditor* ed = checkObject<LevelEditor>(L, 2, LevelEditorBinding::getMetatableName());
    itemType type = (itemType)luaL_checkinteger(L, 3);
    float top = (float)luaL_checknumber(L, 4);
    float left = (float)luaL_checknumber(L, 5);
    float w = (float)luaL_checknumber(L, 6);
    float h = (float)luaL_checknumber(L, 7);

    GamedataSelectionList* result = instance->_CONSTRUCTOR(ed, type, top, left, w, h);
    return pushObject<GamedataSelectionList>(L, result, GamedataSelectionListBinding::getMetatableName());
}

int GamedataSelectionListBinding::_DESTRUCTOR(lua_State* L)
{
    GamedataSelectionList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GamedataSelectionList is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int GamedataSelectionListBinding::deselectItem(lua_State* L)
{
    GamedataSelectionList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GamedataSelectionList is nil");

    instance->deselectItem();
    return 0;
}

int GamedataSelectionListBinding::selectItem(lua_State* L)
{
    GamedataSelectionList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GamedataSelectionList is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool res = instance->selectItem(item);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int GamedataSelectionListBinding::getSelectedItem(lua_State* L)
{
    GamedataSelectionList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GamedataSelectionList is nil");

    GameData* res = instance->getSelectedItem();
    return pushObject<GameData>(L, res, GameDataBinding::getMetatableName());
}

int GamedataSelectionListBinding::itemSelected(lua_State* L)
{
    GamedataSelectionList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GamedataSelectionList is nil");

    GameData* item = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->itemSelected(item);
    return 0;
}

int GamedataSelectionListBinding::formatItem(lua_State* L)
{
    GamedataSelectionList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GamedataSelectionList is nil");

    GameData* o = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    std::string res = instance->formatItem(o);
    lua_pushstring(L, res.c_str());
    return 1;
}

int GamedataSelectionListBinding::_NV_formatItem(lua_State* L)
{
    GamedataSelectionList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GamedataSelectionList is nil");

    GameData* o = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    std::string res = instance->_NV_formatItem(o);
    lua_pushstring(L, res.c_str());
    return 1;
}

int GamedataSelectionListBinding::listItemSelected(lua_State* L)
{
    GamedataSelectionList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GamedataSelectionList is nil");

    MyGUI::Widget* _sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    unsigned __int64 _index = (unsigned __int64)luaL_checkinteger(L, 3);
    instance->listItemSelected((MyGUI::ListBox*)_sender, _index);
    return 0;
}

int GamedataSelectionListBinding::changeFilter(lua_State* L)
{
    GamedataSelectionList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GamedataSelectionList is nil");

    MyGUI::Widget* e = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    instance->changeFilter((MyGUI::EditBox*)e);
    return 0;
}

int GamedataSelectionListBinding::gc(lua_State* L) { return 0; }
int GamedataSelectionListBinding::tostring(lua_State* L) { lua_pushstring(L, "KenshiLua.GamedataSelectionList object"); return 1; }

void GamedataSelectionListBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc", GamedataSelectionListBinding::gc },
        { "__tostring", GamedataSelectionListBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", GamedataSelectionListBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", GamedataSelectionListBinding::_DESTRUCTOR },
        { "deselectItem", GamedataSelectionListBinding::deselectItem },
        { "selectItem", GamedataSelectionListBinding::selectItem },
        { "getSelectedItem", GamedataSelectionListBinding::getSelectedItem },
        { "itemSelected", GamedataSelectionListBinding::itemSelected },
        { "formatItem", GamedataSelectionListBinding::formatItem },
        { "_NV_formatItem", GamedataSelectionListBinding::_NV_formatItem },
        { "listItemSelected", GamedataSelectionListBinding::listItemSelected },
        { "changeFilter", GamedataSelectionListBinding::changeFilter },
        { 0, 0 }
    };
    registerClass(L, GamedataSelectionListBinding::getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, GamedataSelectionListBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "win", GamedataSelectionList_get_win);
    registerGetter(L, "list", GamedataSelectionList_get_list);
    registerGetter(L, "items", GamedataSelectionList_get_items);
    registerGetter(L, "levelEditor", GamedataSelectionList_get_levelEditor);
    registerGetter(L, "lastItem", GamedataSelectionList_get_lastItem);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "lastItem", GamedataSelectionList_set_lastItem);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
