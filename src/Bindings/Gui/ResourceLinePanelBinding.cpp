#include "pch.h"
#include "kenshi\gui\ProspectingWindow.h"
#include "ResourceLinePanelBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/MyGuiBinding.h"

namespace KenshiLua
{
typedef ProspectingWindow::ResourceLinePanel ResourceLinePanel;


static ResourceLinePanel* getInstance(lua_State* L, int idx)
{
    return checkObject<ResourceLinePanel>(L, idx, ResourceLinePanelBinding::getMetatableName());
}

// --- Getters for ResourceLinePanel ---
static int ResourceLinePanel_get_button(lua_State* L)
{
    ResourceLinePanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResourceLinePanel is nil");
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->button, MyGuiBinding::getMetatableName());
}

// --- Setters for ResourceLinePanel ---
int ResourceLinePanelBinding::_DESTRUCTOR(lua_State* L)
{
    return 0;
}

int ResourceLinePanelBinding::getWidget(lua_State* L)
{
    ResourceLinePanel* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResourceLinePanel is nil");

    MyGUI::Widget* result = ((wraps::BaseLayout*)instance)->mMainWidget;
    return pushObject<MyGUI::Widget>(L, result, MyGuiBinding::getMetatableName());
}

/*
Skipped methods needing manual binding:
  line 21: ResourceLinePanel* _CONSTRUCTOR(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - ResourceLinePanel_get_button: MyGUI::Button* (unbound pointer)
  - ResourceLinePanelBinding::getWidget: MyGUI::Widget* (unbound pointer)
*/

int ResourceLinePanelBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ResourceLinePanelBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ResourceLinePanel object");
    return 1;
}

void ResourceLinePanelBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ResourceLinePanelBinding::gc },
        { "__tostring", ResourceLinePanelBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", ResourceLinePanelBinding::_DESTRUCTOR },
        { "getWidget", ResourceLinePanelBinding::getWidget },
        { 0, 0 }
    };

    registerClass(
        L, 
        ResourceLinePanelBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ResourceLinePanelBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "button", ResourceLinePanel_get_button);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseLayout
    // setMetatableParent(L, ResourceLinePanelBinding::getMetatableName(), wraps::BaseLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua