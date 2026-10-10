#include "pch.h"
#include "Bindings/MyGUI/ILayerBinding.h"
#include "Bindings/MyGUI/TypesBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static MyGUI::ILayer* getLayerInstance(lua_State* L)
{
    return checkObject<MyGUI::ILayer>(L, 1, ILayerBinding::getMetatableName());
}

int ILayerBinding::getName(lua_State* L)
{
    lua_pushstring(L, getLayerInstance(L)->getName().c_str());
    return 1;
}

int ILayerBinding::getLayerNodeCount(lua_State* L)
{
    lua_pushinteger(L, (lua_Integer)getLayerInstance(L)->getLayerNodeCount());
    return 1;
}

int ILayerBinding::getSize(lua_State* L)
{
    return pushValue<MyGUI::IntSize>(L, getLayerInstance(L)->getSize(), IntSizeBinding::getMetatableName());
}

int ILayerBinding::getPosition(lua_State* L)
{
    MyGUI::ILayer* layer = getLayerInstance(L);
    int left = (int)luaL_checkinteger(L, 2);
    int top = (int)luaL_checkinteger(L, 3);
    return pushValue<MyGUI::IntPoint>(L, layer->getPosition(left, top), IntPointBinding::getMetatableName());
}

void ILayerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc", noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getName",           getName },
        { "getLayerNodeCount", getLayerNodeCount },
        { "getSize",           getSize },
        { "getPosition",       getPosition },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);
}

} // namespace KenshiLua
