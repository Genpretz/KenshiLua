#include "pch.h"
#include "kenshi\gui\FogEditor.h"
#include "FogEditorBinding.h"
#include "BaseLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DataPanelLineBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"

namespace KenshiLua
{

static FogEditor* getInstance(lua_State* L, int idx)
{
    return checkObject<FogEditor>(L, idx, FogEditorBinding::getMetatableName());
}

// --- Getters for FogEditor ---
static int FogEditor_get_window(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");
    lua_pushlightuserdata(L, (void*)instance->window);
    return 1;
}

static int FogEditor_get_fogList(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");
    lua_pushlightuserdata(L, (void*)instance->fogList);
    return 1;
}

static int FogEditor_get_typeList(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");
    lua_pushlightuserdata(L, (void*)instance->typeList);
    return 1;
}

static int FogEditor_get_panel(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");
    return pushObject<DatapanelGUI>(L, instance->panel, DatapanelGUIBinding::getMetatableName());
}

static int FogEditor_get_selectedFog(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");
    lua_pushlightuserdata(L, (void*)instance->selectedFog);
    return 1;
}

static int FogEditor_get_selectedSide(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");
    lua_pushinteger(L, instance->selectedSide);
    return 1;
}

static int FogEditor_get_colour(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");
    pushVector3(L, instance->colour);
    return 1;
}

static int FogEditor_get_distance(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");
    lua_pushnumber(L, instance->distance);
    return 1;
}

static int FogEditor_get_radius(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");
    lua_pushnumber(L, instance->radius);
    return 1;
}

static int FogEditor_get_edge(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");
    lua_pushnumber(L, instance->edge);
    return 1;
}

static int FogEditor_get_editCage(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");
    lua_pushlightuserdata(L, (void*)instance->editCage);
    return 1;
}

static int FogEditor_get_editNode(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");
    lua_pushlightuserdata(L, (void*)instance->editNode);
    return 1;
}

static int FogEditor_get_editPos(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");
    pushVector3(L, instance->editPos);
    return 1;
}

static int FogEditor_get_editRot(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");
    pushQuaternion(L, instance->editRot);
    return 1;
}

// --- Setters for FogEditor ---
static int FogEditor_set_panel(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");
    instance->panel = lua_isnoneornil(L, 2) ? nullptr : checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    return 0;
}

static int FogEditor_set_selectedSide(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");
    instance->selectedSide = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int FogEditor_set_colour(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");
    readVector3(L, 2, instance->colour);
    return 0;
}

static int FogEditor_set_distance(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");
    instance->distance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FogEditor_set_radius(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");
    instance->radius = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FogEditor_set_edge(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");
    instance->edge = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FogEditor_set_editPos(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");
    readVector3(L, 2, instance->editPos);
    return 0;
}

static int FogEditor_set_editRot(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");
    readQuaternion(L, 2, instance->editRot);
    return 0;
}

int FogEditorBinding::show(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");

    instance->show();
    return 0;
}

int FogEditorBinding::close(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");

    instance->close();
    return 0;
}

int FogEditorBinding::isActive(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");

    bool result = instance->isActive();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FogEditorBinding::update(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");

    bool result = instance->update();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FogEditorBinding::save(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");

    const std::string filename = luaL_checkstring(L, 2);
    instance->save(filename);
    return 0;
}

int FogEditorBinding::updateFogName(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");

    DataPanelLine* line = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->updateFogName(line);
    return 0;
}

int FogEditorBinding::updateFogValues(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->updateFogValues(_a1);
    return 0;
}

int FogEditorBinding::selectNextEdge(lua_State* L)
{
    FogEditor* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FogEditor is nil");

    DataPanelLine* _a1 = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->selectNextEdge(_a1);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 26: void closeWindow(...) - unsupported arg type
  line 27: void addFog(...) - unsupported arg type
  line 28: void removeFog(...) - unsupported arg type
  line 29: void selectFog(...) - unsupported arg type
*/

int FogEditorBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int FogEditorBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FogEditor object");
    return 1;
}

void FogEditorBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FogEditorBinding::gc },
        { "__tostring", FogEditorBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "show", FogEditorBinding::show },
        { "close", FogEditorBinding::close },
        { "isActive", FogEditorBinding::isActive },
        { "update", FogEditorBinding::update },
        { "save", FogEditorBinding::save },
        { "updateFogName", FogEditorBinding::updateFogName },
        { "updateFogValues", FogEditorBinding::updateFogValues },
        { "selectNextEdge", FogEditorBinding::selectNextEdge },
        { 0, 0 }
    };

    registerClass(
        L, 
        FogEditorBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FogEditorBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "window", FogEditor_get_window);
    registerGetter(L, "fogList", FogEditor_get_fogList);
    registerGetter(L, "typeList", FogEditor_get_typeList);
    registerGetter(L, "panel", FogEditor_get_panel);
    registerGetter(L, "selectedFog", FogEditor_get_selectedFog);
    registerGetter(L, "selectedSide", FogEditor_get_selectedSide);
    registerGetter(L, "colour", FogEditor_get_colour);
    registerGetter(L, "distance", FogEditor_get_distance);
    registerGetter(L, "radius", FogEditor_get_radius);
    registerGetter(L, "edge", FogEditor_get_edge);
    registerGetter(L, "editCage", FogEditor_get_editCage);
    registerGetter(L, "editNode", FogEditor_get_editNode);
    registerGetter(L, "editPos", FogEditor_get_editPos);
    registerGetter(L, "editRot", FogEditor_get_editRot);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "panel", FogEditor_set_panel);
    registerSetter(L, "selectedSide", FogEditor_set_selectedSide);
    registerSetter(L, "colour", FogEditor_set_colour);
    registerSetter(L, "distance", FogEditor_set_distance);
    registerSetter(L, "radius", FogEditor_set_radius);
    registerSetter(L, "edge", FogEditor_set_edge);
    registerSetter(L, "editPos", FogEditor_set_editPos);
    registerSetter(L, "editRot", FogEditor_set_editRot);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseLayout
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, FogEditorBinding::getMetatableName(), wraps::BaseLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua