#include "pch.h"
#include "Bindings/MyGUI/LayerManagerBinding.h"
#include "Bindings/MyGUI/ILayerBinding.h"
#include "Bindings/MyGUI/EnumeratorLayerSnapshotBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

// Methods can be called on the instance or on the static table; the instance is
// recognized by its metatable, since several methods take a widget first.
static int argStart(lua_State* L)
{
    return testObject<MyGUI::LayerManager>(L, 1, LayerManagerBinding::getMetatableName()) ? 2 : 1;
}

static MyGUI::LayerManager* getManager(lua_State* L)
{
    MyGUI::LayerManager* manager = MyGUI::LayerManager::getInstancePtr();
    if (!manager)
        luaL_error(L, "MyGUI is not initialized");
    return manager;
}

int LayerManagerBinding::getInstance(lua_State* L)
{
    return pushObject<MyGUI::LayerManager>(L, MyGUI::LayerManager::getInstancePtr(), getMetatableName());
}

int LayerManagerBinding::attachToLayerNode(lua_State* L)
{
    int idx = argStart(L);
    const char* name = luaL_checkstring(L, idx);
    MyGUI::Widget* widget = MyGUIBindings::checkWidget<MyGUI::Widget>(L, idx + 1);
    MyGUI::LayerManager* manager = getManager(L);
    if (!manager->isExist(name))
        return luaL_error(L, "LayerManager:attachToLayerNode: layer '%s' not found", name);

    bool failed = false;
    try
    {
        manager->attachToLayerNode(name, widget);
    }
    catch (...)
    {
        failed = true;
    }
    if (failed)
        return luaL_error(L, "LayerManager:attachToLayerNode: MyGUI could not attach the widget to layer '%s'", name);
    return 0;
}

int LayerManagerBinding::detachFromLayer(lua_State* L)
{
    int idx = argStart(L);
    MyGUI::Widget* widget = MyGUIBindings::checkWidget<MyGUI::Widget>(L, idx);
    getManager(L)->detachFromLayer(widget);
    return 0;
}

int LayerManagerBinding::upLayerItem(lua_State* L)
{
    int idx = argStart(L);
    MyGUI::Widget* widget = MyGUIBindings::checkWidget<MyGUI::Widget>(L, idx);
    getManager(L)->upLayerItem(widget);
    return 0;
}

int LayerManagerBinding::isExist(lua_State* L)
{
    int idx = argStart(L);
    const char* name = luaL_checkstring(L, idx);
    lua_pushboolean(L, getManager(L)->isExist(name) ? 1 : 0);
    return 1;
}

int LayerManagerBinding::getEnumerator(lua_State* L)
{
    return MyGUIBindings::pushLayerEnumerator(L, getManager(L)->getEnumerator());
}

// As in MyGUI, a missing layer is an error unless throw is false; then it returns nil.
int LayerManagerBinding::getByName(lua_State* L)
{
    int idx = argStart(L);
    const char* name = luaL_checkstring(L, idx);
    bool throwIfMissing = lua_isnoneornil(L, idx + 1) || lua_toboolean(L, idx + 1) != 0;
    MyGUI::ILayer* layer = getManager(L)->getByName(name, false);
    if (!layer && throwIfMissing)
        return luaL_error(L, "LayerManager:getByName: layer '%s' not found", name);
    return pushObject<MyGUI::ILayer>(L, layer, ILayerBinding::getMetatableName());
}

int LayerManagerBinding::getLayerCount(lua_State* L)
{
    lua_pushinteger(L, (lua_Integer)getManager(L)->getLayerCount());
    return 1;
}

// index is 0-based, as in MyGUI.
int LayerManagerBinding::getLayer(lua_State* L)
{
    int idx = argStart(L);
    lua_Integer index = luaL_checkinteger(L, idx);
    MyGUI::LayerManager* manager = getManager(L);
    if (index < 0 || (size_t)index >= manager->getLayerCount())
        return luaL_argerror(L, idx, "layer index out of range");
    return pushObject<MyGUI::ILayer>(L, manager->getLayer((size_t)index), ILayerBinding::getMetatableName());
}

int LayerManagerBinding::getWidgetFromPoint(lua_State* L)
{
    int idx = argStart(L);
    int left = (int)luaL_checkinteger(L, idx);
    int top = (int)luaL_checkinteger(L, idx + 1);
    return MyGUIBindings::pushWidget(L, getManager(L)->getWidgetFromPoint(left, top));
}

int LayerManagerBinding::getCategoryName(lua_State* L)
{
    lua_pushstring(L, getManager(L)->getCategoryName().c_str());
    return 1;
}

void LayerManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc", noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getInstance",        getInstance },
        { "attachToLayerNode",  attachToLayerNode },
        { "detachFromLayer",    detachFromLayer },
        { "upLayerItem",        upLayerItem },
        { "isExist",            isExist },
        { "getEnumerator",      getEnumerator },
        { "getByName",          getByName },
        { "getLayerCount",      getLayerCount },
        { "getLayer",           getLayer },
        { "getWidgetFromPoint", getWidgetFromPoint },
        { "getCategoryName",    getCategoryName },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "getInstance", getInstance);
    lua_setglobal(L, "LayerManager");
}

} // namespace KenshiLua
