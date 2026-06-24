#include "pch.h"
#include "kenshi\Dialogue.h"
#include "DialogChoiceListBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static DialogChoiceList* getB(lua_State* L, int idx)
{
    return checkObject<DialogChoiceList>(L, idx, DialogChoiceListBinding::getMetatableName());
}

// --- Getters for DialogChoiceList ---
static int DialogChoiceList_get_conversationChoices(lua_State* L)
{
    DialogChoiceList* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogChoiceList is nil");
    // TODO: Unsupported type for conversationChoices (lektor<DialogLineData*>)
    lua_pushnil(L);
    return 1;
}

// --- Setters for DialogChoiceList ---
static int DialogChoiceList_set_conversationChoices(lua_State* L)
{
    DialogChoiceList* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogChoiceList is nil");
    return luaL_error(L, "Read-only or unsupported setter type for conversationChoices");
}

int DialogChoiceListBinding::_CONSTRUCTOR(lua_State* L)
{
    DialogChoiceList* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogChoiceList is nil");

    DialogChoiceList* result = b->_CONSTRUCTOR();
    return pushObject<DialogChoiceList>(L, result, DialogChoiceListBinding::getMetatableName());
}

int DialogChoiceListBinding::_DESTRUCTOR(lua_State* L)
{
    DialogChoiceList* b = getB(L, 1);
    if (!b) return luaL_error(L, "DialogChoiceList is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 268: void add(...) - unsupported arg type
*/

int DialogChoiceListBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DialogChoiceListBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DialogChoiceList object");
    return 1;
}

void DialogChoiceListBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DialogChoiceListBinding::gc },
        { "__tostring", DialogChoiceListBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", DialogChoiceListBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", DialogChoiceListBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        DialogChoiceListBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DialogChoiceListBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, DialogChoiceList_get_conversationChoices);
    lua_setfield(L, -2, "conversationChoices");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, DialogChoiceList_set_conversationChoices);
    lua_setfield(L, -2, "conversationChoices");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua