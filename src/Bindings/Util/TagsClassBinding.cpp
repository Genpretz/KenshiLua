#include "pch.h"
#include "kenshi\util\TagsClass.h"
#include "TagsClassBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static TagsClass* getInstance(lua_State* L, int idx)
{
    return checkObject<TagsClass>(L, idx, TagsClassBinding::getMetatableName());
}

// --- Getters for TagsClass ---
static int TagsClass_get_flags(lua_State* L)
{
    TagsClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TagsClass is nil");
    lua_pushinteger(L, instance->flags);
    return 1;
}

// --- Setters for TagsClass ---
static int TagsClass_set_flags(lua_State* L)
{
    TagsClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TagsClass is nil");
    instance->flags = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

int TagsClassBinding::_CONSTRUCTOR(lua_State* L)
{
    TagsClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TagsClass is nil");

    TagsClass<T>* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TagsClassBinding::clearAll(lua_State* L)
{
    TagsClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TagsClass is nil");

    instance->clearAll();
    return 0;
}

int TagsClassBinding::hasNONEOfTheseBitsSet(lua_State* L)
{
    TagsClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TagsClass is nil");

    unsigned int flagsToTest = (unsigned int)luaL_checkinteger(L, 2);
    bool result = instance->hasNONEOfTheseBitsSet(flagsToTest);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TagsClassBinding::hasANYOfTheseBitsSet(lua_State* L)
{
    TagsClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TagsClass is nil");

    unsigned int flagsToTest = (unsigned int)luaL_checkinteger(L, 2);
    bool result = instance->hasANYOfTheseBitsSet(flagsToTest);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 12: void setTag(...) - unsupported arg type
  line 13: void _NV_setTag(...) - unsupported arg type
  line 14: void clearTag(...) - unsupported arg type
  line 16: bool getTag(...) - unsupported arg type
  line 17: bool _NV_getTag(...) - unsupported arg type
  line 18: bool has(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - TagsClassBinding::_CONSTRUCTOR: TagsClass<T>* (unbound pointer)
*/

int TagsClassBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TagsClassBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TagsClass object");
    return 1;
}

void TagsClassBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TagsClassBinding::gc },
        { "__tostring", TagsClassBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", TagsClassBinding::_CONSTRUCTOR },
        { "clearAll", TagsClassBinding::clearAll },
        { "hasNONEOfTheseBitsSet", TagsClassBinding::hasNONEOfTheseBitsSet },
        { "hasANYOfTheseBitsSet", TagsClassBinding::hasANYOfTheseBitsSet },
        { 0, 0 }
    };

    registerClass(
        L, 
        TagsClassBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TagsClassBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "flags", TagsClass_get_flags);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "flags", TagsClass_set_flags);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua