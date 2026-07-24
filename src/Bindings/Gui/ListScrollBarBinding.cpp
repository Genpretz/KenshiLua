#include "pch.h"
#include "kenshi\gui\MyGUI_ListScrollBar.h"
#include "ListScrollBarBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
typedef MyGUI::ListScrollBar ListScrollBar;


static ListScrollBar* getInstance(lua_State* L, int idx)
{
    return checkObject<ListScrollBar>(L, idx, ListScrollBarBinding::getMetatableName());
}

// --- Getters for ListScrollBar ---
static int ListScrollBar_get_disableEvents(lua_State* L)
{
    ListScrollBar* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ListScrollBar is nil");
    lua_pushboolean(L, instance->disableEvents ? 1 : 0);
    return 1;
}

static int ListScrollBar_get_mListName(lua_State* L)
{
    ListScrollBar* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ListScrollBar is nil");
    lua_pushlightuserdata(L, (void*)instance->mListName);
    return 1;
}

static int ListScrollBar_get_mListValue(lua_State* L)
{
    ListScrollBar* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ListScrollBar is nil");
    lua_pushlightuserdata(L, (void*)instance->mListValue);
    return 1;
}

static int ListScrollBar_get_mListIndex(lua_State* L)
{
    ListScrollBar* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ListScrollBar is nil");
    lua_pushlightuserdata(L, (void*)instance->mListIndex);
    return 1;
}

// --- Setters for ListScrollBar ---
static int ListScrollBar_set_disableEvents(lua_State* L)
{
    ListScrollBar* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ListScrollBar is nil");
    instance->disableEvents = lua_toboolean(L, 2) != 0;
    return 0;
}

int ListScrollBarBinding::setEnabled(lua_State* L)
{
    ListScrollBar* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ListScrollBar is nil");

    bool _a1 = lua_toboolean(L, 2) != 0;
    instance->setEnabled(_a1);
    return 0;
}

int ListScrollBarBinding::initialiseOverride(lua_State* L)
{
    ListScrollBar* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ListScrollBar is nil");

    instance->initialiseOverride();
    return 0;
}

int ListScrollBarBinding::shutdownOverride(lua_State* L)
{
    ListScrollBar* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ListScrollBar is nil");

    instance->shutdownOverride();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 16: const std::string& getTypeName(...) - reference return type
  line 19: bool isType(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - ListScrollBar_get_mListName: MyGUI::TextBox* (unbound pointer)
  - ListScrollBar_get_mListValue: MyGUI::TextBox* (unbound pointer)
  - ListScrollBar_get_mListIndex: MyGUI::TextBox* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 30: eventValueChange (MyGUI::delegates::CMultiDelegate3<MyGUI::ListScrollBar*, std::string const&, int>) - unsupported type
  line 38: mValues (std::vector<std::string, std::allocator<std::string > >) - unsupported type
*/

int ListScrollBarBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ListScrollBarBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ListScrollBar object");
    return 1;
}

void ListScrollBarBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ListScrollBarBinding::gc },
        { "__tostring", ListScrollBarBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setEnabled", ListScrollBarBinding::setEnabled },
        { "initialiseOverride", ListScrollBarBinding::initialiseOverride },
        { "shutdownOverride", ListScrollBarBinding::shutdownOverride },
        { 0, 0 }
    };

    registerClass(
        L, 
        ListScrollBarBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ListScrollBarBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "disableEvents", ListScrollBar_get_disableEvents);
    registerGetter(L, "mListName", ListScrollBar_get_mListName);
    registerGetter(L, "mListValue", ListScrollBar_get_mListValue);
    registerGetter(L, "mListIndex", ListScrollBar_get_mListIndex);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "disableEvents", ListScrollBar_set_disableEvents);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ScrollBar
    // setMetatableParent(L, ListScrollBarBinding::getMetatableName(), ScrollBarBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua