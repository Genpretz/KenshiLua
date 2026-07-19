#include "pch.h"
#include <kenshi/gui/TutorialGUI.h>
#include "TutorialSubItemBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static TutorialSubItem* getInstance(lua_State* L, int idx)
{
    return checkObject<TutorialSubItem>(L, idx, TutorialSubItemBinding::getMetatableName());
}

// --- Getters for TutorialSubItem ---
static int TutorialSubItem_get_description(lua_State* L)
{
    TutorialSubItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialSubItem is nil");
    lua_pushstring(L, instance->description.c_str());
    return 1;
}

static int TutorialSubItem_get_skippeable(lua_State* L)
{
    TutorialSubItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialSubItem is nil");
    lua_pushboolean(L, instance->skippeable ? 1 : 0);
    return 1;
}

// --- Setters for TutorialSubItem ---
static int TutorialSubItem_set_description(lua_State* L)
{
    TutorialSubItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialSubItem is nil");
    instance->description = luaL_checkstring(L, 2);
    return 0;
}

static int TutorialSubItem_set_skippeable(lua_State* L)
{
    TutorialSubItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialSubItem is nil");
    instance->skippeable = lua_toboolean(L, 2) != 0;
    return 0;
}

int TutorialSubItemBinding::start(lua_State* L)
{
    TutorialSubItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialSubItem is nil");

    instance->start();
    return 0;
}

int TutorialSubItemBinding::_NV_start(lua_State* L)
{
    TutorialSubItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialSubItem is nil");

    instance->_NV_start();
    return 0;
}

int TutorialSubItemBinding::run(lua_State* L)
{
    TutorialSubItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialSubItem is nil");

    bool result = instance->run();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TutorialSubItemBinding::_NV_run(lua_State* L)
{
    TutorialSubItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialSubItem is nil");

    bool result = instance->_NV_run();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TutorialSubItemBinding::end(lua_State* L)
{
    TutorialSubItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialSubItem is nil");

    instance->end();
    return 0;
}

int TutorialSubItemBinding::_NV_end(lua_State* L)
{
    TutorialSubItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialSubItem is nil");

    instance->_NV_end();
    return 0;
}

int TutorialSubItemBinding::_DESTRUCTOR(lua_State* L)
{
    TutorialSubItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialSubItem is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 14: TutorialSubItem* _CONSTRUCTOR(...) - overloaded method
  line 16: TutorialSubItem* _CONSTRUCTOR(...) - overloaded method
*/

int TutorialSubItemBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TutorialSubItemBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TutorialSubItem object");
    return 1;
}

void TutorialSubItemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TutorialSubItemBinding::gc },
        { "__tostring", TutorialSubItemBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "start", TutorialSubItemBinding::start },
        { "_NV_start", TutorialSubItemBinding::_NV_start },
        { "run", TutorialSubItemBinding::run },
        { "_NV_run", TutorialSubItemBinding::_NV_run },
        { "end", TutorialSubItemBinding::end },
        { "_NV_end", TutorialSubItemBinding::_NV_end },
        { "_DESTRUCTOR", TutorialSubItemBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        TutorialSubItemBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TutorialSubItemBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, TutorialSubItem_get_description);
    lua_setfield(L, -2, "description");
    lua_pushcfunction(L, TutorialSubItem_get_skippeable);
    lua_setfield(L, -2, "skippeable");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, TutorialSubItem_set_description);
    lua_setfield(L, -2, "description");
    lua_pushcfunction(L, TutorialSubItem_set_skippeable);
    lua_setfield(L, -2, "skippeable");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, TutorialSubItemBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua