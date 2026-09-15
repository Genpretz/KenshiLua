#include "pch.h"
#include "kenshi\gui\MessageBoxManager.h"
#include "MessageBoxManagerBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/MyGUI/WindowBinding.h"
#include "BoxBinding.h"

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
  line 30: MyGUI::Window* createMessageBox(...) - symbol too long in kenshilib MASM export (unexported in KenshiLib.lib)
*/
#if 0
int MessageBoxManagerBinding::createMessageBox(lua_State* L)
{
    int idx = (lua_gettop(L) >= 2 && testObject<MessageBoxManager>(L, 1, MessageBoxManagerBinding::getMetatableName())) ? 2 : 1;
    std::string title = luaL_checkstring(L, idx);
    std::string message = luaL_checkstring(L, idx + 1);

    std::vector<std::pair<std::string, int>, Ogre::STLAllocator<std::pair<std::string, int>, Ogre::GeneralAllocPolicy>> buttons;
    if (lua_istable(L, idx + 2))
    {
        int tIdx = idx + 2;
        int len = (int)lua_objlen(L, tIdx);
        if (len > 0)
        {
            for (int i = 1; i <= len; ++i)
            {
                lua_rawgeti(L, tIdx, i);
                if (lua_istable(L, -1))
                {
                    lua_rawgeti(L, -1, 1);
                    std::string btnText = luaL_optstring(L, -1, "");
                    lua_pop(L, 1);
                    lua_rawgeti(L, -1, 2);
                    int btnVal = (int)luaL_optinteger(L, -1, i);
                    lua_pop(L, 1);
                    buttons.push_back(std::make_pair(btnText, btnVal));
                }
                else if (lua_isstring(L, -1))
                {
                    std::string btnText = lua_tostring(L, -1);
                    buttons.push_back(std::make_pair(btnText, i));
                }
                lua_pop(L, 1);
            }
        }
        else
        {
            lua_pushnil(L);
            while (lua_next(L, tIdx) != 0)
            {
                if (lua_isstring(L, -2) && lua_isnumber(L, -1))
                {
                    std::string btnText = lua_tostring(L, -2);
                    int btnVal = (int)lua_tointeger(L, -1);
                    buttons.push_back(std::make_pair(btnText, btnVal));
                }
                lua_pop(L, 1);
            }
        }
    }

    bool modal = lua_toboolean(L, idx + 3) != 0;
    MyGUI::delegates::IDelegate1<int>* callback = nullptr;

    MyGUI::Window* result = MessageBoxManager::createMessageBox(title, message, buttons, modal, callback);
    if (!result)
    {
        lua_pushnil(L);
        return 1;
    }
    return pushObject<MyGUI::Window>(L, result, WindowBinding::getMetatableName());
}
#endif

int MessageBoxManagerBinding::removeMessageBox(lua_State* L)
{
    int idx = (lua_gettop(L) >= 3 && testObject<MessageBoxManager>(L, 1, MessageBoxManagerBinding::getMetatableName())) ? 2 : 1;
    MessageBoxManager::Box* box = checkObject<MessageBoxManager::Box>(L, idx, BoxBinding::getMetatableName());
    if (!box) return luaL_error(L, "Argument 1 must be MessageBoxManager.Box");
    int button = (int)luaL_checkinteger(L, idx + 1);
    MessageBoxManager::removeMessageBox(box, button);
    return 0;
}

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
        // { "createMessageBox", MessageBoxManagerBinding::createMessageBox },
        { "removeMessageBox", MessageBoxManagerBinding::removeMessageBox },
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
    pushGlobalTable(L, "MessageBoxManager");
    registerStaticMethod(L, "hideMessageBox", MessageBoxManagerBinding::hideMessageBox);
    registerStaticMethod(L, "hasModalMessage", MessageBoxManagerBinding::hasModalMessage);
    // registerStaticMethod(L, "createMessageBox", MessageBoxManagerBinding::createMessageBox);
    registerStaticMethod(L, "removeMessageBox", MessageBoxManagerBinding::removeMessageBox);
    lua_setglobal(L, "MessageBoxManager");
}

} // namespace KenshiLua