#include "pch.h"
#include "kenshi\gui\ManagementScreen.h"
#include "ReorderableListBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static ReorderableList* getInstance(lua_State* L, int idx)
{
    return checkObject<ReorderableList>(L, idx, ReorderableListBinding::getMetatableName());
}

// --- Getters for ReorderableList ---
static int ReorderableList_get_data(lua_State* L)
{
    ReorderableList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ReorderableList is nil");
    lua_pushlightuserdata(L, (void*)instance->data);
    return 1;
}

// --- Setters for ReorderableList ---
int ReorderableListBinding::clear(lua_State* L)
{
    ReorderableList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ReorderableList is nil");

    instance->clear();
    return 0;
}

int ReorderableListBinding::refresh(lua_State* L)
{
    ReorderableList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ReorderableList is nil");

    bool force = lua_toboolean(L, 2) != 0;
    instance->refresh(force);
    return 0;
}

int ReorderableListBinding::notifyEndDrop(lua_State* L)
{
    ReorderableList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ReorderableList is nil");

    wraps::BaseLayout* sender = (wraps::BaseLayout)luaL_checkinteger(L, 2);
    wraps::DDItemInfo info = (wraps::DDItemInfo)luaL_checkinteger(L, 3);
    bool result = lua_toboolean(L, 4) != 0;
    instance->notifyEndDrop(sender, info, result);
    return 0;
}

int ReorderableListBinding::notifyRemoved(lua_State* L)
{
    ReorderableList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ReorderableList is nil");

    int index = (int)luaL_checkinteger(L, 2);
    instance->notifyRemoved(index);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 38: void setData(...) - unsupported arg type
  line 44: void notifyStartDrop(...) - non-string reference arg
  line 45: void notifyRequestDrop(...) - non-string reference arg
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - ReorderableList_get_data: T1* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 41: eventReordered (MyGUI::delegates::CDelegate2<int, int>) - unsupported type
  line 42: eventRemove (MyGUI::delegates::CDelegate2<int, T2 const&>) - unsupported type
  line 43: eventValidate (MyGUI::delegates::CDelegate3<int, int, bool&>) - unsupported type
*/

int ReorderableListBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ReorderableListBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ReorderableList object");
    return 1;
}

void ReorderableListBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ReorderableListBinding::gc },
        { "__tostring", ReorderableListBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "clear", ReorderableListBinding::clear },
        { "refresh", ReorderableListBinding::refresh },
        { "notifyEndDrop", ReorderableListBinding::notifyEndDrop },
        { "notifyRemoved", ReorderableListBinding::notifyRemoved },
        { 0, 0 }
    };

    registerClass(
        L, 
        ReorderableListBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ReorderableListBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "data", ReorderableList_get_data);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to >
    // setMetatableParent(L, ReorderableListBinding::getMetatableName(), >Binding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua