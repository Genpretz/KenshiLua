#include "pch.h"
#include <kenshi\Dialogue.h>
#include "DialogChoiceListBinding.h"
#include "DialogLineDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/DialogLineDataBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Util/LektorBinding.h"


namespace KenshiLua
{

static DialogChoiceList* getInstance(lua_State* L, int idx)
{
    return checkObject<DialogChoiceList>(L, idx, DialogChoiceListBinding::getMetatableName());
}

static int DialogChoiceList_get_conversationChoices(lua_State* L)
{
    DialogChoiceList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogChoiceList is nil");
    return pushObject<lektor<DialogLineData*>>(L, &instance->conversationChoices, LektorPtrBinding<DialogLineData*>::metaName);
}

// --- Setters for DialogChoiceList ---
static int DialogChoiceList_set_conversationChoices(lua_State* L)
{
    DialogChoiceList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogChoiceList is nil");
    auto* val = checkObject<lektor<DialogLineData*>>(L, 2, LektorPtrBinding<DialogLineData*>::metaName);
    if (!val) return luaL_error(L, "Expected lektor<DialogLineData*>");
    instance->conversationChoices = *val;
    return 0;
}

int DialogChoiceListBinding::_CONSTRUCTOR(lua_State* L)
{
    DialogChoiceList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogChoiceList is nil");

    DialogChoiceList* result = instance->_CONSTRUCTOR();
    return pushObject<DialogChoiceList>(L, result, DialogChoiceListBinding::getMetatableName());
}

int DialogChoiceListBinding::_DESTRUCTOR(lua_State* L)
{
    DialogChoiceList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogChoiceList is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int DialogChoiceListBinding::add(lua_State* L)
{
    DialogChoiceList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DialogChoiceList is nil");

    GameData* conversation = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    DialogLineData* parent = checkObject<DialogLineData>(L, 3, DialogLineDataBinding::getMetatableName());
    instance->add(conversation, parent);
    return 0;
}

int DialogChoiceListBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DialogChoiceListBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DialogChoiceList object");
    return 1;
}

void DialogChoiceListBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DialogChoiceListBinding::gc },
        { "__tostring", DialogChoiceListBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", DialogChoiceListBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", DialogChoiceListBinding::_DESTRUCTOR },
        { "add", DialogChoiceListBinding::add },
        { 0, 0 }
    };

    registerClass(
        L, 
        DialogChoiceListBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DialogChoiceListBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "conversationChoices", DialogChoiceList_get_conversationChoices);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "conversationChoices", DialogChoiceList_set_conversationChoices);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    LektorPtrBinding<DialogLineData*>::registerBinding(L, "lektor<DialogLineData*>", DialogLineDataBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua