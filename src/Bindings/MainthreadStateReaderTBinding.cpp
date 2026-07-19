#include "pch.h"
#include <kenshi/ZoneManager.h>
#include "MainthreadStateReaderTBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static MainthreadStateReaderT* getInstance(lua_State* L, int idx)
{
    return checkObject<MainthreadStateReaderT>(L, idx, MainthreadStateReaderTBinding::getMetatableName());
}

// --- Getters for MainthreadStateReaderT ---

// --- Setters for MainthreadStateReaderT ---

int MainthreadStateReaderTBinding::_CONSTRUCTOR(lua_State* L)
{
    return 0;
}

int MainthreadStateReaderTBinding::_DESTRUCTOR(lua_State* L)
{
    MainthreadStateReaderT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainthreadStateReaderT is nil");

    instance->~MainthreadStateReaderT();
    return 0;
}

int MainthreadStateReaderTBinding::updateBackDataCheck(lua_State* L)
{
    MainthreadStateReaderT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainthreadStateReaderT is nil");

    bool result = instance->updateBackDataCheck();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MainthreadStateReaderTBinding::_NV_updateBackDataCheck(lua_State* L)
{
    MainthreadStateReaderT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainthreadStateReaderT is nil");

    bool result = instance->updateBackDataCheck();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 181: T& getMainData(...) - overloaded method
  line 182: const T& getMainData(...) - overloaded method
  line 183: const T& getBackData(...) - reference return type
*/

/*
Skipped properties needing manual binding:
  line 185: mainThreadData (T) - unsupported type
  line 186: backThreadData (T) - unsupported type
*/

int MainthreadStateReaderTBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int MainthreadStateReaderTBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MainthreadStateReaderT object");
    return 1;
}

void MainthreadStateReaderTBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       MainthreadStateReaderTBinding::gc },
        { "__tostring", MainthreadStateReaderTBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        // { "_CONSTRUCTOR", MainthreadStateReaderTBinding::_CONSTRUCTOR },
        // { "_DESTRUCTOR", MainthreadStateReaderTBinding::_DESTRUCTOR },
        { "updateBackDataCheck", MainthreadStateReaderTBinding::updateBackDataCheck },
        // { "_NV_updateBackDataCheck", MainthreadStateReaderTBinding::_NV_updateBackDataCheck },
        { 0, 0 }
    };

    registerClass(
        L, 
        MainthreadStateReaderTBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, MainthreadStateReaderTBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, MainthreadStateReaderTBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
