#include "pch.h"
#include "kenshi\gui\MainBarGUI.h"
#include "MainTabPortraitPlatoonBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/Gui/MainBarGUIBinding.h"
#include "Bindings/MyGuiBinding.h"

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
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->tab, MyGuiBinding::getMetatableName());
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
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->flashImage, MyGuiBinding::getMetatableName());
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
    return pushObject<MainBarGUI>(L, instance->mainbar, MainBarGUIBinding::getMetatableName());
}

// --- Setters for MainTabPortraitPlatoon ---
static int MainTabPortraitPlatoon_set_platoon(lua_State* L)
{
    MainTabPortraitPlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainTabPortraitPlatoon is nil");
    instance->platoon = lua_isnoneornil(L, 2) ? nullptr : checkObject<ActivePlatoon>(L, 2, ActivePlatoonBinding::getMetatableName());
    return 0;
}

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

static int MainTabPortraitPlatoon_set_mainbar(lua_State* L)
{
    MainTabPortraitPlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainTabPortraitPlatoon is nil");
    instance->mainbar = lua_isnoneornil(L, 2) ? nullptr : checkObject<MainBarGUI>(L, 2, MainBarGUIBinding::getMetatableName());
    return 0;
}

int MainTabPortraitPlatoonBinding::_CONSTRUCTOR(lua_State* L)
{
    MainTabPortraitPlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainTabPortraitPlatoon is nil");

    if (lua_gettop(L) >= 3)
    {
        ActivePlatoon* platoon = checkObject<ActivePlatoon>(L, 2, ActivePlatoonBinding::getMetatableName());
        MainBarGUI* mainbar = checkObject<MainBarGUI>(L, 3, MainBarGUIBinding::getMetatableName());
        instance->_CONSTRUCTOR(platoon, mainbar);
    }
    else
    {
        instance->_CONSTRUCTOR();
    }
    return 0;
}

int MainTabPortraitPlatoonBinding::addTab(lua_State* L)
{
    MainTabPortraitPlatoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MainTabPortraitPlatoon is nil");

    MyGUI::Widget* tabControl = checkObject<MyGUI::Widget>(L, 2, MyGuiBinding::getMetatableName());
    if (!tabControl) return luaL_error(L, "Argument 2 to addTab must be MyGUI::Widget");
    bool visible = lua_toboolean(L, 3) != 0;

    instance->addTab((MyGUI::TabControl*)tabControl, visible);
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
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - MainTabPortraitPlatoon_get_portraitBox: PortraitMainItemBox* (unbound pointer)
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
        { "_CONSTRUCTOR", MainTabPortraitPlatoonBinding::_CONSTRUCTOR },
        { "addTab", MainTabPortraitPlatoonBinding::addTab },
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
    registerGetter(L, "portraitBox", MainTabPortraitPlatoon_get_portraitBox);
    registerGetter(L, "platoon", MainTabPortraitPlatoon_get_platoon);
    registerGetter(L, "tab", MainTabPortraitPlatoon_get_tab);
    registerGetter(L, "tabIndex", MainTabPortraitPlatoon_get_tabIndex);
    registerGetter(L, "flashImage", MainTabPortraitPlatoon_get_flashImage);
    registerGetter(L, "flashing", MainTabPortraitPlatoon_get_flashing);
    registerGetter(L, "animationTime", MainTabPortraitPlatoon_get_animationTime);
    registerGetter(L, "currentAlpha", MainTabPortraitPlatoon_get_currentAlpha);
    registerGetter(L, "mainbar", MainTabPortraitPlatoon_get_mainbar);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "platoon", MainTabPortraitPlatoon_set_platoon);
    registerSetter(L, "tabIndex", MainTabPortraitPlatoon_set_tabIndex);
    registerSetter(L, "flashing", MainTabPortraitPlatoon_set_flashing);
    registerSetter(L, "animationTime", MainTabPortraitPlatoon_set_animationTime);
    registerSetter(L, "currentAlpha", MainTabPortraitPlatoon_set_currentAlpha);
    registerSetter(L, "mainbar", MainTabPortraitPlatoon_set_mainbar);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, MainTabPortraitPlatoonBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua