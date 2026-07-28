#include "pch.h"
#include "kenshi\util\array2d.h"
#include "Array2dBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static Array2d* getInstance(lua_State* L, int idx)
{
    return checkObject<Array2d>(L, idx, Array2dBinding::getMetatableName());
}

// --- Getters for Array2d ---
static int Array2d_get_nRows(lua_State* L)
{
    Array2d* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Array2d is nil");
    lua_pushinteger(L, instance->nRows);
    return 1;
}

static int Array2d_get_nCols(lua_State* L)
{
    Array2d* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Array2d is nil");
    lua_pushinteger(L, instance->nCols);
    return 1;
}

// --- Setters for Array2d ---
static int Array2d_set_nRows(lua_State* L)
{
    Array2d* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Array2d is nil");
    instance->nRows = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int Array2d_set_nCols(lua_State* L)
{
    Array2d* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Array2d is nil");
    instance->nCols = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

int Array2dBinding::resize(lua_State* L)
{
    Array2d* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Array2d is nil");

    unsigned int nrows = (unsigned int)luaL_checkinteger(L, 2);
    unsigned int ncols = (unsigned int)luaL_checkinteger(L, 3);
    bool clear = lua_toboolean(L, 4) != 0;
    instance->resize(nrows, ncols, clear);
    return 0;
}

int Array2dBinding::setToZeros(lua_State* L)
{
    Array2d* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Array2d is nil");

    instance->setToZeros();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 20: const T* operator(...) - operator
  line 21: T*& operator(...) - operator
*/

/*
Skipped properties needing manual binding:
  line 30: data (std::vector<T*, Ogre::STLAllocator<T*, Ogre::GeneralAllocPolicy > >) - unsupported type
*/

int Array2dBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int Array2dBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Array2d object");
    return 1;
}

void Array2dBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       Array2dBinding::gc },
        { "__tostring", Array2dBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "resize", Array2dBinding::resize },
        { "setToZeros", Array2dBinding::setToZeros },
        { 0, 0 }
    };

    registerClass(
        L, 
        Array2dBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, Array2dBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "nRows", Array2d_get_nRows);
    registerGetter(L, "nCols", Array2d_get_nCols);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "nRows", Array2d_set_nRows);
    registerSetter(L, "nCols", Array2d_set_nCols);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua