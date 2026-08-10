#include "pch.h"
#include "kenshi\gui\MyGUI_Slider.h"
#include "SliderBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/MyGuiBinding.h"

namespace KenshiLua
{
typedef MyGUI::Slider Slider;


static Slider* getInstance(lua_State* L, int idx)
{
    return checkObject<Slider>(L, idx, SliderBinding::getMetatableName());
}

// --- Getters for Slider ---
static int Slider_get_mDisableEvents(lua_State* L)
{
    Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Slider is nil");
    lua_pushboolean(L, instance->mDisableEvents ? 1 : 0);
    return 1;
}

static int Slider_get_mScrollbar(lua_State* L)
{
    Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Slider is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->mScrollbar, MyGuiBinding::getMetatableName());
}

static int Slider_get_mSliderName(lua_State* L)
{
    Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Slider is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->mSliderName, MyGuiBinding::getMetatableName());
}

static int Slider_get_mSliderValue(lua_State* L)
{
    Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Slider is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->mSliderValue, MyGuiBinding::getMetatableName());
}

static int Slider_get_mLoValue(lua_State* L)
{
    Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Slider is nil");
    lua_pushinteger(L, instance->mLoValue);
    return 1;
}

static int Slider_get_mHiValue(lua_State* L)
{
    Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Slider is nil");
    lua_pushinteger(L, instance->mHiValue);
    return 1;
}

// --- Setters for Slider ---
static int Slider_set_mDisableEvents(lua_State* L)
{
    Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Slider is nil");
    instance->mDisableEvents = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Slider_set_mLoValue(lua_State* L)
{
    Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Slider is nil");
    instance->mLoValue = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Slider_set_mHiValue(lua_State* L)
{
    Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Slider is nil");
    instance->mHiValue = (int)luaL_checkinteger(L, 2);
    return 0;
}

int SliderBinding::initialiseOverride(lua_State* L)
{
    Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Slider is nil");

    instance->initialiseOverride();
    return 0;
}

int SliderBinding::shutdownOverride(lua_State* L)
{
    Slider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Slider is nil");

    instance->shutdownOverride();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 16: const std::string& getTypeName(...) - reference return type
  line 19: bool isType(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - Slider_get_mScrollbar: ScrollBar* (unbound pointer)
  - Slider_get_mSliderName: TextBox* (unbound pointer)
  - Slider_get_mSliderValue: TextBox* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 28: eventValueChange (delegates::CMultiDelegate2<Slider*, int>) - unsupported type
*/

int SliderBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SliderBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Slider object");
    return 1;
}

void SliderBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SliderBinding::gc },
        { "__tostring", SliderBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "initialiseOverride", SliderBinding::initialiseOverride },
        { "shutdownOverride", SliderBinding::shutdownOverride },
        { 0, 0 }
    };

    registerClass(
        L, 
        SliderBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SliderBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "mDisableEvents", Slider_get_mDisableEvents);
    registerGetter(L, "mScrollbar", Slider_get_mScrollbar);
    registerGetter(L, "mSliderName", Slider_get_mSliderName);
    registerGetter(L, "mSliderValue", Slider_get_mSliderValue);
    registerGetter(L, "mLoValue", Slider_get_mLoValue);
    registerGetter(L, "mHiValue", Slider_get_mHiValue);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "mDisableEvents", Slider_set_mDisableEvents);
    registerSetter(L, "mLoValue", Slider_set_mLoValue);
    registerSetter(L, "mHiValue", Slider_set_mHiValue);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Widget
    // setMetatableParent(L, SliderBinding::getMetatableName(), WidgetBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua