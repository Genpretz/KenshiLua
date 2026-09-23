#include "pch.h"
#include "kenshi\gui\MessageBoxManager.h"
#include "BoxBinding.h"
#include "BaseLayoutBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static MessageBoxManager::Box* getInstance(lua_State* L, int idx)
{
    return checkObject<MessageBoxManager::Box>(L, idx, BoxBinding::getMetatableName());
}

// --- Getters for Box ---
static int Box_get_modal(lua_State* L)
{
    MessageBoxManager::Box* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Box is nil");
    lua_pushboolean(L, instance->modal ? 1 : 0);
    return 1;
}

static int Box_get_callback(lua_State* L)
{
    MessageBoxManager::Box* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Box is nil");
    lua_pushlightuserdata(L, (void*)instance->callback);
    return 1;
}

// --- Setters for Box ---
static int Box_set_modal(lua_State* L)
{
    MessageBoxManager::Box* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Box is nil");
    instance->modal = lua_toboolean(L, 2) != 0;
    return 0;
}

/*
Skipped methods needing manual binding:
  line 22: void buttonClick(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - Box_get_callback: MyGUI::delegates::IDelegate1<int>* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 23: buttons (Ogre::vector<MyGUI::Button*>::type) - unsupported type
*/

int BoxBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int BoxBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Box object");
    return 1;
}

void BoxBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BoxBinding::gc },
        { "__tostring", BoxBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        BoxBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, BoxBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "modal", Box_get_modal);
    registerGetter(L, "callback", Box_get_callback);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "modal", Box_set_modal);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseLayout
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, BoxBinding::getMetatableName(), wraps::BaseLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua