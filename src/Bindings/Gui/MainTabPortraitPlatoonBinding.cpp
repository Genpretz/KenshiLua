#include "pch.h"
#include "Bindings/ActivePlatoonBinding.h"

#include <kenshi/gui/MainBarGUI.h>
#include "MainTabPortraitPlatoonBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static MainTabPortraitPlatoon* getInstance(lua_State* L, int idx)
{
    return checkObject<MainTabPortraitPlatoon>(L, idx, MainTabPortraitPlatoonBinding::getMetatableName());
}

// --- Getters for MainTabPortraitPlatoon ---
static int MainTabPortraitPlatoon_get_portraitBox(lua_State* L)
{
    MainTabPortraitPlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainTabPortraitPlatoon is nil");
    lua_pushlightuserdata(L, (void*)instance->portraitBox);
    return 1;
}

static int MainTabPortraitPlatoon_get_platoon(lua_State* L)
{
    MainTabPortraitPlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainTabPortraitPlatoon is nil");
    return pushObject<ActivePlatoon>(L, instance->platoon, ActivePlatoonBinding::getMetatableName());
}

static int MainTabPortraitPlatoon_get_tab(lua_State* L)
{
    MainTabPortraitPlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainTabPortraitPlatoon is nil");
    lua_pushlightuserdata(L, (void*)instance->tab);
    return 1;
}

static int MainTabPortraitPlatoon_get_tabIndex(lua_State* L)
{
    MainTabPortraitPlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainTabPortraitPlatoon is nil");
    lua_pushinteger(L, instance->tabIndex);
    return 1;
}

static int MainTabPortraitPlatoon_get_flashImage(lua_State* L)
{
    MainTabPortraitPlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainTabPortraitPlatoon is nil");
    lua_pushlightuserdata(L, (void*)instance->flashImage);
    return 1;
}

static int MainTabPortraitPlatoon_get_flashing(lua_State* L)
{
    MainTabPortraitPlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainTabPortraitPlatoon is nil");
    lua_pushinteger(L, instance->flashing);
    return 1;
}

static int MainTabPortraitPlatoon_get_animationTime(lua_State* L)
{
    MainTabPortraitPlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainTabPortraitPlatoon is nil");
    lua_pushnumber(L, instance->animationTime);
    return 1;
}

static int MainTabPortraitPlatoon_get_currentAlpha(lua_State* L)
{
    MainTabPortraitPlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainTabPortraitPlatoon is nil");
    lua_pushnumber(L, instance->currentAlpha);
    return 1;
}

static int MainTabPortraitPlatoon_get_mainbar(lua_State* L)
{
    MainTabPortraitPlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainTabPortraitPlatoon is nil");
    lua_pushlightuserdata(L, (void*)instance->mainbar);
    return 1;
}

// --- Setters for MainTabPortraitPlatoon ---
static int MainTabPortraitPlatoon_set_tabIndex(lua_State* L)
{
    MainTabPortraitPlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainTabPortraitPlatoon is nil");
    instance->tabIndex = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int MainTabPortraitPlatoon_set_flashing(lua_State* L)
{
    MainTabPortraitPlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainTabPortraitPlatoon is nil");
    instance->flashing = (char)luaL_checkinteger(L, 2);
    return 0;
}

static int MainTabPortraitPlatoon_set_animationTime(lua_State* L)
{
    MainTabPortraitPlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainTabPortraitPlatoon is nil");
    instance->animationTime = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MainTabPortraitPlatoon_set_currentAlpha(lua_State* L)
{
    MainTabPortraitPlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainTabPortraitPlatoon is nil");
    instance->currentAlpha = (float)luaL_checknumber(L, 2);
    return 0;
}

int MainTabPortraitPlatoonBinding::detach(lua_State* L)
{
    MainTabPortraitPlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainTabPortraitPlatoon is nil");

    instance->detach();
    return 0;
}

int MainTabPortraitPlatoonBinding::setFlash(lua_State* L)
{
    MainTabPortraitPlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainTabPortraitPlatoon is nil");

    bool flash = lua_toboolean(L, 2) != 0;
    instance->setFlash(flash);
    return 0;
}

int MainTabPortraitPlatoonBinding::update(lua_State* L)
{
    MainTabPortraitPlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainTabPortraitPlatoon is nil");

    instance->update();
    return 0;
}

int MainTabPortraitPlatoonBinding::_DESTRUCTOR(lua_State* L)
{
    MainTabPortraitPlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainTabPortraitPlatoon is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 22: MainTabPortraitPlatoon* _CONSTRUCTOR(...) - overloaded method
  line 24: MainTabPortraitPlatoon* _CONSTRUCTOR(...) - overloaded method
  line 25: void addTab(...) - unsupported arg type
*/

int MainTabPortraitPlatoonBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int MainTabPortraitPlatoonBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MainTabPortraitPlatoon object");
    return 1;
}

void MainTabPortraitPlatoonBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       MainTabPortraitPlatoonBinding::gc },
        { "__tostring", MainTabPortraitPlatoonBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "detach", MainTabPortraitPlatoonBinding::detach },
        { "setFlash", MainTabPortraitPlatoonBinding::setFlash },
        { "update", MainTabPortraitPlatoonBinding::update },
        { "_DESTRUCTOR", MainTabPortraitPlatoonBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        MainTabPortraitPlatoonBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, MainTabPortraitPlatoonBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, MainTabPortraitPlatoon_get_portraitBox);
    lua_setfield(L, -2, "portraitBox");
    lua_pushcfunction(L, MainTabPortraitPlatoon_get_platoon);
    lua_setfield(L, -2, "platoon");
    lua_pushcfunction(L, MainTabPortraitPlatoon_get_tab);
    lua_setfield(L, -2, "tab");
    lua_pushcfunction(L, MainTabPortraitPlatoon_get_tabIndex);
    lua_setfield(L, -2, "tabIndex");
    lua_pushcfunction(L, MainTabPortraitPlatoon_get_flashImage);
    lua_setfield(L, -2, "flashImage");
    lua_pushcfunction(L, MainTabPortraitPlatoon_get_flashing);
    lua_setfield(L, -2, "flashing");
    lua_pushcfunction(L, MainTabPortraitPlatoon_get_animationTime);
    lua_setfield(L, -2, "animationTime");
    lua_pushcfunction(L, MainTabPortraitPlatoon_get_currentAlpha);
    lua_setfield(L, -2, "currentAlpha");
    lua_pushcfunction(L, MainTabPortraitPlatoon_get_mainbar);
    lua_setfield(L, -2, "mainbar");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, MainTabPortraitPlatoon_set_tabIndex);
    lua_setfield(L, -2, "tabIndex");
    lua_pushcfunction(L, MainTabPortraitPlatoon_set_flashing);
    lua_setfield(L, -2, "flashing");
    lua_pushcfunction(L, MainTabPortraitPlatoon_set_animationTime);
    lua_setfield(L, -2, "animationTime");
    lua_pushcfunction(L, MainTabPortraitPlatoon_set_currentAlpha);
    lua_setfield(L, -2, "currentAlpha");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // // // // // // // // // setMetatableParent(L, MainTabPortraitPlatoonBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua