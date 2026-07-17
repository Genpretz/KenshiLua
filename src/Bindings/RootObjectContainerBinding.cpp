#include "pch.h"
#include "kenshi\RootObject.h"
#include "RootObjectContainerBinding.h"
#include "RootObjectBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/Templates/LektorBinding.h"

namespace KenshiLua
{

static RootObjectContainer* getB(lua_State* L, int idx)
{
    return checkObject<RootObjectContainer>(L, idx, RootObjectContainerBinding::getMetatableName());
}

// --- Getters for RootObjectContainer ---
static int RootObjectContainer_get_things(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");
    return pushObject<lektor<RootObject*>>(L, &b->things, LektorPtrBinding<RootObject*>::metaName);
}

// --- Setters for RootObjectContainer ---
static int RootObjectContainer_set_things(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");
    return luaL_error(L, "Read-only or unsupported setter type for things");
}

int RootObjectContainerBinding::_DESTRUCTOR(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    b->_DESTRUCTOR();
    return 0;
}

int RootObjectContainerBinding::update(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    bool result = b->update();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectContainerBinding::_NV_update(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    bool result = b->_NV_update();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectContainerBinding::getThing(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    int id = (int)luaL_checkinteger(L, 2);
    RootObject* result = b->getThing(id);
    return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
}

int RootObjectContainerBinding::getNumThings(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    int result = b->getNumThings();
    lua_pushinteger(L, result);
    return 1;
}

int RootObjectContainerBinding::getThings(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    lektor<RootObject*>* result = b->getThings();
    return pushObject<lektor<RootObject*>>(L, result, LektorPtrBinding<RootObject*>::metaName);
}

int RootObjectContainerBinding::getSelectedObjects(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    lektor<RootObject*>* out = LektorPtrBinding<RootObject*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 must be a lektor<RootObject*>");

    itemType type = (itemType)luaL_checkinteger(L, 3);
    bool selectedOnly = lua_toboolean(L, 4) != 0;

    b->getSelectedObjects(*out, type, selectedOnly);
    return 0;
}

int RootObjectContainerBinding::_NV_getSelectedObjects(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    lektor<RootObject*>* out = LektorPtrBinding<RootObject*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 must be a lektor<RootObject*>");

    itemType type = (itemType)luaL_checkinteger(L, 3);
    bool selectedOnly = lua_toboolean(L, 4) != 0;

    b->_NV_getSelectedObjects(*out, type, selectedOnly);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 183: RootObjectContainer* _CONSTRUCTOR(...) - overloaded method
  line 185: RootObjectContainer* _CONSTRUCTOR(...) - overloaded method
  line 188: bool addActiveObject(...) - unsupported arg type
  line 189: bool _NV_addActiveObject(...) - unsupported arg type
  line 190: bool removeObject(...) - unsupported arg type
  line 191: bool _NV_removeObject(...) - unsupported arg type
  line 196: lektor<RootObject*>* getThings(...) - unsupported return type
  line 197: void getSelectedObjects(...) - unsupported arg type
  line 198: void _NV_getSelectedObjects(...) - unsupported arg type
  line 200: void serialiseThings(...) - overloaded method
  line 201: void serialiseThings(...) - overloaded method
  line 223: void loadToReality(...) - unsupported arg type
  line 224: void _NV_loadToReality(...) - unsupported arg type
  line 225: void loadInstance(...) - unsupported arg type
  line 226: void _NV_loadInstance(...) - unsupported arg type
*/

int RootObjectContainerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int RootObjectContainerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.RootObjectContainer object");
    return 1;
}

void RootObjectContainerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RootObjectContainerBinding::gc },
        { "__tostring", RootObjectContainerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", RootObjectContainerBinding::_DESTRUCTOR },
        { "update", RootObjectContainerBinding::update },
        { "_NV_update", RootObjectContainerBinding::_NV_update },
        { "getThing", RootObjectContainerBinding::getThing },
        { "getNumThings", RootObjectContainerBinding::getNumThings },
        { "getThings", RootObjectContainerBinding::getThings },
        { "getSelectedObjects", RootObjectContainerBinding::getSelectedObjects },
        { "_NV_getSelectedObjects", RootObjectContainerBinding::_NV_getSelectedObjects },
        { 0, 0 }
    };

    registerClass(
        L, 
        RootObjectContainerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, RootObjectContainerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, RootObjectContainer_get_things);
    lua_setfield(L, -2, "things");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, RootObjectContainer_set_things);
    lua_setfield(L, -2, "things");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua