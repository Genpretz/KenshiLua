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
int MessageBoxManagerBinding::hideMessageBox(lua_State* L)
{
    int idx = (lua_gettop(L) >= 2 && testObject<MessageBoxManager>(L, 1, MessageBoxManagerBinding::getMetatableName())) ? 2 : 1;
    bool enter = lua_toboolean(L, idx) != 0;
    bool result = MessageBoxManager::hideMessageBox(enter);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MessageBoxManagerBinding::hasModalMessage(lua_State* L)
{
    bool result = MessageBoxManager::hasModalMessage();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 30: MyGUI::Window* createMessageBox(...) - static method
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
        { "hideMessageBox", MessageBoxManagerBinding::hideMessageBox },
        { "hasModalMessage", MessageBoxManagerBinding::hasModalMessage },
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

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "hideMessageBox", MessageBoxManagerBinding::hideMessageBox);
    registerStaticMethod(L, "hasModalMessage", MessageBoxManagerBinding::hasModalMessage);
    lua_setglobal(L, "MessageBoxManager");
}

} // namespace KenshiLua