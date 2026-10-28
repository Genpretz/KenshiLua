#include "pch.h"
#include "kenshi/Item.h"
#include "BlueprintItemBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/Gui/DatapanelGUIBinding.h"

namespace KenshiLua
{

static_assert(offsetof(BlueprintItem, value) == 0x1E8, "BlueprintItem::value offset mismatch");

static BlueprintItem* getInstance(lua_State* L, int idx)
{
    return checkObject<BlueprintItem>(L, idx, BlueprintItemBinding::getMetatableName());
}

static int BlueprintItem_get_value(lua_State* L)
{
    BlueprintItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BlueprintItem is nil");
    lua_pushinteger(L, instance->value);
    return 1;
}

static int BlueprintItem_set_value(lua_State* L)
{
    BlueprintItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BlueprintItem is nil");
    instance->value = (int)luaL_checkinteger(L, 2);
    return 0;
}

int BlueprintItemBinding::getClassType(lua_State* L)
{
    BlueprintItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BlueprintItem is nil");
    lua_pushinteger(L, (lua_Integer)instance->getClassType());
    return 1;
}

int BlueprintItemBinding::_NV_getClassType(lua_State* L)
{
    BlueprintItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BlueprintItem is nil");
    lua_pushinteger(L, (lua_Integer)instance->_NV_getClassType());
    return 1;
}

int BlueprintItemBinding::getItemWeight(lua_State* L)
{
    BlueprintItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BlueprintItem is nil");
    lua_pushnumber(L, (lua_Number)instance->getItemWeight());
    return 1;
}

int BlueprintItemBinding::_NV_getItemWeight(lua_State* L)
{
    BlueprintItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BlueprintItem is nil");
    lua_pushnumber(L, (lua_Number)instance->_NV_getItemWeight());
    return 1;
}

int BlueprintItemBinding::getValueSingle(lua_State* L)
{
    BlueprintItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BlueprintItem is nil");
    bool isPlayer = lua_toboolean(L, 2) != 0;
    lua_pushinteger(L, (lua_Integer)instance->getValueSingle(isPlayer));
    return 1;
}

int BlueprintItemBinding::_NV_getValueSingle(lua_State* L)
{
    BlueprintItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BlueprintItem is nil");
    bool isPlayer = lua_toboolean(L, 2) != 0;
    lua_pushinteger(L, (lua_Integer)instance->_NV_getValueSingle(isPlayer));
    return 1;
}

int BlueprintItemBinding::getResearchData(lua_State* L)
{
    BlueprintItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BlueprintItem is nil");
    GameData* res = instance->getResearchData();
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<GameData>(L, res, GameDataBinding::getMetatableName());
}

int BlueprintItemBinding::learnResearch(lua_State* L)
{
    BlueprintItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BlueprintItem is nil");
    bool res = instance->learnResearch();
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

int BlueprintItemBinding::getGUIData(lua_State* L)
{
    BlueprintItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BlueprintItem is nil");
    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIData(datapanel, category);
    return 0;
}

int BlueprintItemBinding::_NV_getGUIData(lua_State* L)
{
    BlueprintItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "BlueprintItem is nil");
    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIData(datapanel, category);
    return 0;
}

int BlueprintItemBinding::gc(lua_State* L)
{
    return 0;
}

int BlueprintItemBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.BlueprintItem object");
    return 1;
}

void BlueprintItemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BlueprintItemBinding::gc },
        { "__tostring", BlueprintItemBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getClassType", BlueprintItemBinding::getClassType },
        { "_NV_getClassType", BlueprintItemBinding::_NV_getClassType },
        { "getItemWeight", BlueprintItemBinding::getItemWeight },
        { "_NV_getItemWeight", BlueprintItemBinding::_NV_getItemWeight },
        { "getValueSingle", BlueprintItemBinding::getValueSingle },
        { "_NV_getValueSingle", BlueprintItemBinding::_NV_getValueSingle },
        { "getResearchData", BlueprintItemBinding::getResearchData },
        { "learnResearch", BlueprintItemBinding::learnResearch },
        { "getGUIData", BlueprintItemBinding::getGUIData },
        { "_NV_getGUIData", BlueprintItemBinding::_NV_getGUIData },
        { 0, 0 }
    };

    registerClass(
        L, 
        BlueprintItemBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, BlueprintItemBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "value", BlueprintItem_get_value);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "value", BlueprintItem_set_value);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
