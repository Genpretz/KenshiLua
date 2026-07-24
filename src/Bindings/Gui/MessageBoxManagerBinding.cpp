#include "pch.h"
#include "kenshi\gui\MessageBoxManager.h"
#include "MessageBoxManagerBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static MessageBoxManager* getInstance(lua_State* L, int idx)
{
    return checkObject<MessageBoxManager>(L, idx, MessageBoxManagerBinding::getMetatableName());
}

// --- Getters for MessageBoxManager ---
// --- Setters for MessageBoxManager ---
/*
Skipped methods needing manual binding:
  line 30: MyGUI::Window* createMessageBox(...) - static method
  line 31: bool hideMessageBox(...) - static method
  line 32: bool hasModalMessage(...) - static method
  line 33: void removeMessageBox(...) - static method
*/

int MessageBoxManagerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int MessageBoxManagerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MessageBoxManager object");
    return 1;
}

void MessageBoxManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       MessageBoxManagerBinding::gc },
        { "__tostring", MessageBoxManagerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { 0, 0 }
    };

    registerClass(
        L, 
        MessageBoxManagerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, MessageBoxManagerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, MessageBoxManagerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua