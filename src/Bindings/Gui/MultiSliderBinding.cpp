#include "pch.h"
#include "kenshi\gui\MyGUI_MultiSlider.h"
#include "MultiSliderBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
typedef MyGUI::MultiSlider MultiSlider;


static MultiSlider* getInstance(lua_State* L, int idx)
{
    return checkObject<MultiSlider>(L, idx, MultiSliderBinding::getMetatableName());
}

// --- Getters for MultiSlider ---
static int MultiSlider_get_mName(lua_State* L)
{
    MultiSlider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MultiSlider is nil");
    lua_pushlightuserdata(L, (void*)instance->mName);
    return 1;
}

static int MultiSlider_get_mDisableEvents(lua_State* L)
{
    MultiSlider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MultiSlider is nil");
    lua_pushboolean(L, instance->mDisableEvents ? 1 : 0);
    return 1;
}

// --- Setters for MultiSlider ---
static int MultiSlider_set_mDisableEvents(lua_State* L)
{
    MultiSlider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MultiSlider is nil");
    instance->mDisableEvents = lua_toboolean(L, 2) != 0;
    return 0;
}

int MultiSliderBinding::initialiseOverride(lua_State* L)
{
    MultiSlider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MultiSlider is nil");

    instance->initialiseOverride();
    return 0;
}

int MultiSliderBinding::shutdownOverride(lua_State* L)
{
    MultiSlider* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MultiSlider is nil");

    instance->shutdownOverride();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 17: const std::string& getTypeName(...) - reference return type
  line 20: bool isType(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - MultiSlider_get_mName: MyGUI::TextBox* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 28: eventValueChange (delegates::CMultiDelegate4<MultiSlider*, Slider*, int, int>) - unsupported type
  line 34: mSliders (std::vector<Slider*>) - unsupported type
*/

int MultiSliderBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int MultiSliderBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MultiSlider object");
    return 1;
}

void MultiSliderBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       MultiSliderBinding::gc },
        { "__tostring", MultiSliderBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "initialiseOverride", MultiSliderBinding::initialiseOverride },
        { "shutdownOverride", MultiSliderBinding::shutdownOverride },
        { 0, 0 }
    };

    registerClass(
        L, 
        MultiSliderBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, MultiSliderBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "mName", MultiSlider_get_mName);
    registerGetter(L, "mDisableEvents", MultiSlider_get_mDisableEvents);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "mDisableEvents", MultiSlider_set_mDisableEvents);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Widget
    // setMetatableParent(L, MultiSliderBinding::getMetatableName(), WidgetBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua