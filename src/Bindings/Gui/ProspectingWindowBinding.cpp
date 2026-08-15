#include "pch.h"
#include "kenshi\gui\ProspectingWindow.h"
#include "ProspectingWindowBinding.h"
#include "BaseLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"

namespace KenshiLua
{

static ProspectingWindow* getInstance(lua_State* L, int idx)
{
    return checkObject<ProspectingWindow>(L, idx, ProspectingWindowBinding::getMetatableName());
}

// --- Getters for ProspectingWindow ---
static int ProspectingWindow_get_window(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->window);
    return 1;
}

static int ProspectingWindow_get_imgMap(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->imgMap);
    return 1;
}

static int ProspectingWindow_get_listResourcesPanel(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->listResourcesPanel);
    return 1;
}

static int ProspectingWindow_get_listResourcesSelected(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->listResourcesSelected);
    return 1;
}

static int ProspectingWindow_get_cameraMarker(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->cameraMarker);
    return 1;
}

static int ProspectingWindow_get_cameraMarkerSkin(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->cameraMarkerSkin);
    return 1;
}

static int ProspectingWindow_get_datapanelOverview1(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");
    return pushObject<DatapanelGUI>(L, instance->datapanelOverview1, DatapanelGUIBinding::getMetatableName());
}

static int ProspectingWindow_get_datapanelOverview2(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");
    return pushObject<DatapanelGUI>(L, instance->datapanelOverview2, DatapanelGUIBinding::getMetatableName());
}

static int ProspectingWindow_get_resourceImage(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->resourceImage);
    return 1;
}

static int ProspectingWindow_get_lastPos(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");
    pushVector3(L, instance->lastPos);
    return 1;
}

static int ProspectingWindow_get_lastSkill(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");
    lua_pushnumber(L, instance->lastSkill);
    return 1;
}

static int ProspectingWindow_get_lastName(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");
    lua_pushstring(L, instance->lastName.c_str());
    return 1;
}

// --- Setters for ProspectingWindow ---
static int ProspectingWindow_set_datapanelOverview1(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");
    instance->datapanelOverview1 = lua_isnoneornil(L, 2) ? nullptr : checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    return 0;
}

static int ProspectingWindow_set_datapanelOverview2(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");
    instance->datapanelOverview2 = lua_isnoneornil(L, 2) ? nullptr : checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    return 0;
}

static int ProspectingWindow_set_lastPos(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");
    readVector3(L, 2, instance->lastPos);
    return 0;
}

static int ProspectingWindow_set_lastSkill(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");
    instance->lastSkill = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ProspectingWindow_set_lastName(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");
    instance->lastName = luaL_checkstring(L, 2);
    return 0;
}

int ProspectingWindowBinding::_CONSTRUCTOR(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");

    ProspectingWindow* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ProspectingWindowBinding::_DESTRUCTOR(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ProspectingWindowBinding::showT(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    float skill = (float)luaL_checknumber(L, 3);
    const std::string name = luaL_checkstring(L, 4);
    instance->showT(pos, skill, name);
    return 0;
}

int ProspectingWindowBinding::_show(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");

    instance->_show();
    return 0;
}

int ProspectingWindowBinding::hide(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");

    instance->hide();
    return 0;
}

int ProspectingWindowBinding::getVisible(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");

    bool result = instance->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ProspectingWindowBinding::updateCameraMarker(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");

    instance->updateCameraMarker();
    return 0;
}

int ProspectingWindowBinding::updateMap(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");

    MiningResource resource = (MiningResource)luaL_checkinteger(L, 2);
    instance->updateMap(resource);
    return 0;
}

int ProspectingWindowBinding::refresh(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");

    instance->refresh();
    return 0;
}

int ProspectingWindowBinding::clear(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");

    instance->clear();
    return 0;
}

int ProspectingWindowBinding::worldToMapCoords(lua_State* L)
{
    ProspectingWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProspectingWindow is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    MyGUI::types::TPoint<int> result = instance->worldToMapCoords(pos);
    pushPoint(L, result);
    return 1;
}

int ProspectingWindowBinding::getSingleton(lua_State* L)
{
    ProspectingWindow* result = ProspectingWindow::getSingleton();
    return pushObject<ProspectingWindow>(L, result, ProspectingWindowBinding::getMetatableName());
}

/*
Skipped methods needing manual binding:
  line 39: void closeButton(...) - unsupported arg type
  line 41: void resourceSelected(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - ProspectingWindow_get_window: MyGUI::Window* (unbound pointer)
  - ProspectingWindow_get_imgMap: MyGUI::ImageBox* (unbound pointer)
  - ProspectingWindow_get_listResourcesPanel: MyGUI::Widget* (unbound pointer)
  - ProspectingWindow_get_listResourcesSelected: MyGUI::Button* (unbound pointer)
  - ProspectingWindow_get_cameraMarker: MyGUI::ImageBox* (unbound pointer)
  - ProspectingWindow_get_cameraMarkerSkin: MyGUI::RotatingSkin* (unbound pointer)
  - ProspectingWindow_get_resourceImage: RealWorldEditableImage* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 54: lines (Ogre::vector<ProspectingWindow::ResourceLinePanel*>::type) - unsupported type
*/

int ProspectingWindowBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ProspectingWindowBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ProspectingWindow object");
    return 1;
}

void ProspectingWindowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ProspectingWindowBinding::gc },
        { "__tostring", ProspectingWindowBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", ProspectingWindowBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", ProspectingWindowBinding::_DESTRUCTOR },
        { "showT", ProspectingWindowBinding::showT },
        { "_show", ProspectingWindowBinding::_show },
        { "hide", ProspectingWindowBinding::hide },
        { "getVisible", ProspectingWindowBinding::getVisible },
        { "updateCameraMarker", ProspectingWindowBinding::updateCameraMarker },
        { "updateMap", ProspectingWindowBinding::updateMap },
        { "refresh", ProspectingWindowBinding::refresh },
        { "clear", ProspectingWindowBinding::clear },
        { "worldToMapCoords", ProspectingWindowBinding::worldToMapCoords },
        { "getSingleton", ProspectingWindowBinding::getSingleton },
        { 0, 0 }
    };

    registerClass(
        L, 
        ProspectingWindowBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ProspectingWindowBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "window", ProspectingWindow_get_window);
    registerGetter(L, "imgMap", ProspectingWindow_get_imgMap);
    registerGetter(L, "listResourcesPanel", ProspectingWindow_get_listResourcesPanel);
    registerGetter(L, "listResourcesSelected", ProspectingWindow_get_listResourcesSelected);
    registerGetter(L, "cameraMarker", ProspectingWindow_get_cameraMarker);
    registerGetter(L, "cameraMarkerSkin", ProspectingWindow_get_cameraMarkerSkin);
    registerGetter(L, "datapanelOverview1", ProspectingWindow_get_datapanelOverview1);
    registerGetter(L, "datapanelOverview2", ProspectingWindow_get_datapanelOverview2);
    registerGetter(L, "resourceImage", ProspectingWindow_get_resourceImage);
    registerGetter(L, "lastPos", ProspectingWindow_get_lastPos);
    registerGetter(L, "lastSkill", ProspectingWindow_get_lastSkill);
    registerGetter(L, "lastName", ProspectingWindow_get_lastName);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "datapanelOverview1", ProspectingWindow_set_datapanelOverview1);
    registerSetter(L, "datapanelOverview2", ProspectingWindow_set_datapanelOverview2);
    registerSetter(L, "lastPos", ProspectingWindow_set_lastPos);
    registerSetter(L, "lastSkill", ProspectingWindow_set_lastSkill);
    registerSetter(L, "lastName", ProspectingWindow_set_lastName);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "getSingleton", ProspectingWindowBinding::getSingleton);
    lua_setglobal(L, "ProspectingWindow");
}

} // namespace KenshiLua