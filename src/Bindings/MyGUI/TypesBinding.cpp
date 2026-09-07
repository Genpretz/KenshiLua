#include "pch.h"
#include "Bindings/MyGUI/TypesBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

// ============================================================================
// IntPoint Binding
// ============================================================================
static int IntPoint_index(lua_State* L)
{
    MyGUI::IntPoint* p = checkObject<MyGUI::IntPoint>(L, 1, IntPointBinding::getMetatableName());
    const char* key = luaL_checkstring(L, 2);
    if (strcmp(key, "left") == 0 || strcmp(key, "x") == 0)
    {
        lua_pushinteger(L, p->left);
        return 1;
    }
    if (strcmp(key, "top") == 0 || strcmp(key, "y") == 0)
    {
        lua_pushinteger(L, p->top);
        return 1;
    }
    return genericPropertyIndex(L);
}

static int IntPoint_newindex(lua_State* L)
{
    MyGUI::IntPoint* p = checkObject<MyGUI::IntPoint>(L, 1, IntPointBinding::getMetatableName());
    const char* key = luaL_checkstring(L, 2);
    if (strcmp(key, "left") == 0 || strcmp(key, "x") == 0)
    {
        p->left = (int)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "top") == 0 || strcmp(key, "y") == 0)
    {
        p->top = (int)luaL_checkinteger(L, 3);
        return 0;
    }
    return luaL_error(L, "Invalid property '%s' on IntPoint", key);
}

static int IntPoint_tostring(lua_State* L)
{
    MyGUI::IntPoint* p = checkObject<MyGUI::IntPoint>(L, 1, IntPointBinding::getMetatableName());
    char buf[64];
    _snprintf(buf, sizeof(buf), "IntPoint(%d, %d)", p->left, p->top);
    lua_pushstring(L, buf);
    return 1;
}

static int IntPoint_new(lua_State* L)
{
    int left = (int)luaL_optinteger(L, 1, 0);
    int top = (int)luaL_optinteger(L, 2, 0);
    MyGUI::IntPoint pt(left, top);
    return pushValue<MyGUI::IntPoint>(L, pt, IntPointBinding::getMetatableName());
}

void IntPointBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", IntPoint_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "new", IntPoint_new },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, IntPoint_index, IntPoint_newindex);

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "new", IntPoint_new);
    lua_setglobal(L, "IntPoint");
}

// ============================================================================
// IntSize Binding
// ============================================================================
static int IntSize_index(lua_State* L)
{
    MyGUI::IntSize* s = checkObject<MyGUI::IntSize>(L, 1, IntSizeBinding::getMetatableName());
    const char* key = luaL_checkstring(L, 2);
    if (strcmp(key, "width") == 0 || strcmp(key, "w") == 0)
    {
        lua_pushinteger(L, s->width);
        return 1;
    }
    if (strcmp(key, "height") == 0 || strcmp(key, "h") == 0)
    {
        lua_pushinteger(L, s->height);
        return 1;
    }
    return genericPropertyIndex(L);
}

static int IntSize_newindex(lua_State* L)
{
    MyGUI::IntSize* s = checkObject<MyGUI::IntSize>(L, 1, IntSizeBinding::getMetatableName());
    const char* key = luaL_checkstring(L, 2);
    if (strcmp(key, "width") == 0 || strcmp(key, "w") == 0)
    {
        s->width = (int)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "height") == 0 || strcmp(key, "h") == 0)
    {
        s->height = (int)luaL_checkinteger(L, 3);
        return 0;
    }
    return luaL_error(L, "Invalid property '%s' on IntSize", key);
}

static int IntSize_tostring(lua_State* L)
{
    MyGUI::IntSize* s = checkObject<MyGUI::IntSize>(L, 1, IntSizeBinding::getMetatableName());
    char buf[64];
    _snprintf(buf, sizeof(buf), "IntSize(%d, %d)", s->width, s->height);
    lua_pushstring(L, buf);
    return 1;
}

static int IntSize_new(lua_State* L)
{
    int w = (int)luaL_optinteger(L, 1, 0);
    int h = (int)luaL_optinteger(L, 2, 0);
    MyGUI::IntSize sz(w, h);
    return pushValue<MyGUI::IntSize>(L, sz, IntSizeBinding::getMetatableName());
}

void IntSizeBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", IntSize_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "new", IntSize_new },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, IntSize_index, IntSize_newindex);

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "new", IntSize_new);
    lua_setglobal(L, "IntSize");
}

// ============================================================================
// IntCoord Binding
// ============================================================================
static int IntCoord_index(lua_State* L)
{
    MyGUI::IntCoord* c = checkObject<MyGUI::IntCoord>(L, 1, IntCoordBinding::getMetatableName());
    const char* key = luaL_checkstring(L, 2);
    if (strcmp(key, "left") == 0 || strcmp(key, "x") == 0)
    {
        lua_pushinteger(L, c->left);
        return 1;
    }
    if (strcmp(key, "top") == 0 || strcmp(key, "y") == 0)
    {
        lua_pushinteger(L, c->top);
        return 1;
    }
    if (strcmp(key, "width") == 0 || strcmp(key, "w") == 0)
    {
        lua_pushinteger(L, c->width);
        return 1;
    }
    if (strcmp(key, "height") == 0 || strcmp(key, "h") == 0)
    {
        lua_pushinteger(L, c->height);
        return 1;
    }
    if (strcmp(key, "point") == 0)
    {
        return pushValue<MyGUI::IntPoint>(L, c->point(), IntPointBinding::getMetatableName());
    }
    if (strcmp(key, "size") == 0)
    {
        return pushValue<MyGUI::IntSize>(L, c->size(), IntSizeBinding::getMetatableName());
    }
    return genericPropertyIndex(L);
}

static int IntCoord_newindex(lua_State* L)
{
    MyGUI::IntCoord* c = checkObject<MyGUI::IntCoord>(L, 1, IntCoordBinding::getMetatableName());
    const char* key = luaL_checkstring(L, 2);
    if (strcmp(key, "left") == 0 || strcmp(key, "x") == 0)
    {
        c->left = (int)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "top") == 0 || strcmp(key, "y") == 0)
    {
        c->top = (int)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "width") == 0 || strcmp(key, "w") == 0)
    {
        c->width = (int)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "height") == 0 || strcmp(key, "h") == 0)
    {
        c->height = (int)luaL_checkinteger(L, 3);
        return 0;
    }
    return luaL_error(L, "Invalid property '%s' on IntCoord", key);
}

static int IntCoord_tostring(lua_State* L)
{
    MyGUI::IntCoord* c = checkObject<MyGUI::IntCoord>(L, 1, IntCoordBinding::getMetatableName());
    char buf[96];
    _snprintf(buf, sizeof(buf), "IntCoord(%d, %d, %d, %d)", c->left, c->top, c->width, c->height);
    lua_pushstring(L, buf);
    return 1;
}

static int IntCoord_new(lua_State* L)
{
    int left = (int)luaL_optinteger(L, 1, 0);
    int top = (int)luaL_optinteger(L, 2, 0);
    int width = (int)luaL_optinteger(L, 3, 0);
    int height = (int)luaL_optinteger(L, 4, 0);
    MyGUI::IntCoord coord(left, top, width, height);
    return pushValue<MyGUI::IntCoord>(L, coord, IntCoordBinding::getMetatableName());
}

void IntCoordBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", IntCoord_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "new", IntCoord_new },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, IntCoord_index, IntCoord_newindex);

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "new", IntCoord_new);
    lua_setglobal(L, "IntCoord");
}

// ============================================================================
// IntRect Binding
// ============================================================================
static int IntRect_index(lua_State* L)
{
    MyGUI::IntRect* r = checkObject<MyGUI::IntRect>(L, 1, IntRectBinding::getMetatableName());
    const char* key = luaL_checkstring(L, 2);
    if (strcmp(key, "left") == 0) { lua_pushinteger(L, r->left); return 1; }
    if (strcmp(key, "top") == 0) { lua_pushinteger(L, r->top); return 1; }
    if (strcmp(key, "right") == 0) { lua_pushinteger(L, r->right); return 1; }
    if (strcmp(key, "bottom") == 0) { lua_pushinteger(L, r->bottom); return 1; }
    if (strcmp(key, "width") == 0) { lua_pushinteger(L, r->width()); return 1; }
    if (strcmp(key, "height") == 0) { lua_pushinteger(L, r->height()); return 1; }
    return genericPropertyIndex(L);
}

static int IntRect_newindex(lua_State* L)
{
    MyGUI::IntRect* r = checkObject<MyGUI::IntRect>(L, 1, IntRectBinding::getMetatableName());
    const char* key = luaL_checkstring(L, 2);
    if (strcmp(key, "left") == 0) { r->left = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "top") == 0) { r->top = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "right") == 0) { r->right = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "bottom") == 0) { r->bottom = (int)luaL_checkinteger(L, 3); return 0; }
    return luaL_error(L, "Invalid property '%s' on IntRect", key);
}

static int IntRect_tostring(lua_State* L)
{
    MyGUI::IntRect* r = checkObject<MyGUI::IntRect>(L, 1, IntRectBinding::getMetatableName());
    char buf[96];
    _snprintf(buf, sizeof(buf), "IntRect(%d, %d, %d, %d)", r->left, r->top, r->right, r->bottom);
    lua_pushstring(L, buf);
    return 1;
}

static int IntRect_new(lua_State* L)
{
    int left = (int)luaL_optinteger(L, 1, 0);
    int top = (int)luaL_optinteger(L, 2, 0);
    int right = (int)luaL_optinteger(L, 3, 0);
    int bottom = (int)luaL_optinteger(L, 4, 0);
    MyGUI::IntRect rect(left, top, right, bottom);
    return pushValue<MyGUI::IntRect>(L, rect, IntRectBinding::getMetatableName());
}

void IntRectBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", IntRect_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "new", IntRect_new },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, IntRect_index, IntRect_newindex);

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "new", IntRect_new);
    lua_setglobal(L, "IntRect");
}

// ============================================================================
// FloatPoint Binding
// ============================================================================
static int FloatPoint_index(lua_State* L)
{
    MyGUI::FloatPoint* p = checkObject<MyGUI::FloatPoint>(L, 1, FloatPointBinding::getMetatableName());
    const char* key = luaL_checkstring(L, 2);
    if (strcmp(key, "left") == 0 || strcmp(key, "x") == 0) { lua_pushnumber(L, p->left); return 1; }
    if (strcmp(key, "top") == 0 || strcmp(key, "y") == 0) { lua_pushnumber(L, p->top); return 1; }
    return genericPropertyIndex(L);
}

static int FloatPoint_newindex(lua_State* L)
{
    MyGUI::FloatPoint* p = checkObject<MyGUI::FloatPoint>(L, 1, FloatPointBinding::getMetatableName());
    const char* key = luaL_checkstring(L, 2);
    if (strcmp(key, "left") == 0 || strcmp(key, "x") == 0) { p->left = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "top") == 0 || strcmp(key, "y") == 0) { p->top = (float)luaL_checknumber(L, 3); return 0; }
    return luaL_error(L, "Invalid property '%s' on FloatPoint", key);
}

static int FloatPoint_tostring(lua_State* L)
{
    MyGUI::FloatPoint* p = checkObject<MyGUI::FloatPoint>(L, 1, FloatPointBinding::getMetatableName());
    char buf[64];
    _snprintf(buf, sizeof(buf), "FloatPoint(%.3f, %.3f)", p->left, p->top);
    lua_pushstring(L, buf);
    return 1;
}

static int FloatPoint_new(lua_State* L)
{
    float left = (float)luaL_optnumber(L, 1, 0.0);
    float top = (float)luaL_optnumber(L, 2, 0.0);
    MyGUI::FloatPoint pt(left, top);
    return pushValue<MyGUI::FloatPoint>(L, pt, FloatPointBinding::getMetatableName());
}

void FloatPointBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", FloatPoint_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "new", FloatPoint_new },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, FloatPoint_index, FloatPoint_newindex);

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "new", FloatPoint_new);
    lua_setglobal(L, "FloatPoint");
}

// ============================================================================
// FloatSize Binding
// ============================================================================
static int FloatSize_index(lua_State* L)
{
    MyGUI::FloatSize* s = checkObject<MyGUI::FloatSize>(L, 1, FloatSizeBinding::getMetatableName());
    const char* key = luaL_checkstring(L, 2);
    if (strcmp(key, "width") == 0 || strcmp(key, "w") == 0) { lua_pushnumber(L, s->width); return 1; }
    if (strcmp(key, "height") == 0 || strcmp(key, "h") == 0) { lua_pushnumber(L, s->height); return 1; }
    return genericPropertyIndex(L);
}

static int FloatSize_newindex(lua_State* L)
{
    MyGUI::FloatSize* s = checkObject<MyGUI::FloatSize>(L, 1, FloatSizeBinding::getMetatableName());
    const char* key = luaL_checkstring(L, 2);
    if (strcmp(key, "width") == 0 || strcmp(key, "w") == 0) { s->width = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "height") == 0 || strcmp(key, "h") == 0) { s->height = (float)luaL_checknumber(L, 3); return 0; }
    return luaL_error(L, "Invalid property '%s' on FloatSize", key);
}

static int FloatSize_tostring(lua_State* L)
{
    MyGUI::FloatSize* s = checkObject<MyGUI::FloatSize>(L, 1, FloatSizeBinding::getMetatableName());
    char buf[64];
    _snprintf(buf, sizeof(buf), "FloatSize(%.3f, %.3f)", s->width, s->height);
    lua_pushstring(L, buf);
    return 1;
}

static int FloatSize_new(lua_State* L)
{
    float w = (float)luaL_optnumber(L, 1, 0.0);
    float h = (float)luaL_optnumber(L, 2, 0.0);
    MyGUI::FloatSize sz(w, h);
    return pushValue<MyGUI::FloatSize>(L, sz, FloatSizeBinding::getMetatableName());
}

void FloatSizeBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", FloatSize_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "new", FloatSize_new },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, FloatSize_index, FloatSize_newindex);

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "new", FloatSize_new);
    lua_setglobal(L, "FloatSize");
}

// ============================================================================
// FloatCoord Binding
// ============================================================================
static int FloatCoord_index(lua_State* L)
{
    MyGUI::FloatCoord* c = checkObject<MyGUI::FloatCoord>(L, 1, FloatCoordBinding::getMetatableName());
    const char* key = luaL_checkstring(L, 2);
    if (strcmp(key, "left") == 0 || strcmp(key, "x") == 0) { lua_pushnumber(L, c->left); return 1; }
    if (strcmp(key, "top") == 0 || strcmp(key, "y") == 0) { lua_pushnumber(L, c->top); return 1; }
    if (strcmp(key, "width") == 0 || strcmp(key, "w") == 0) { lua_pushnumber(L, c->width); return 1; }
    if (strcmp(key, "height") == 0 || strcmp(key, "h") == 0) { lua_pushnumber(L, c->height); return 1; }
    return genericPropertyIndex(L);
}

static int FloatCoord_newindex(lua_State* L)
{
    MyGUI::FloatCoord* c = checkObject<MyGUI::FloatCoord>(L, 1, FloatCoordBinding::getMetatableName());
    const char* key = luaL_checkstring(L, 2);
    if (strcmp(key, "left") == 0 || strcmp(key, "x") == 0) { c->left = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "top") == 0 || strcmp(key, "y") == 0) { c->top = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "width") == 0 || strcmp(key, "w") == 0) { c->width = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "height") == 0 || strcmp(key, "h") == 0) { c->height = (float)luaL_checknumber(L, 3); return 0; }
    return luaL_error(L, "Invalid property '%s' on FloatCoord", key);
}

static int FloatCoord_tostring(lua_State* L)
{
    MyGUI::FloatCoord* c = checkObject<MyGUI::FloatCoord>(L, 1, FloatCoordBinding::getMetatableName());
    char buf[96];
    _snprintf(buf, sizeof(buf), "FloatCoord(%.3f, %.3f, %.3f, %.3f)", c->left, c->top, c->width, c->height);
    lua_pushstring(L, buf);
    return 1;
}

static int FloatCoord_new(lua_State* L)
{
    float left = (float)luaL_optnumber(L, 1, 0.0);
    float top = (float)luaL_optnumber(L, 2, 0.0);
    float width = (float)luaL_optnumber(L, 3, 0.0);
    float height = (float)luaL_optnumber(L, 4, 0.0);
    MyGUI::FloatCoord coord(left, top, width, height);
    return pushValue<MyGUI::FloatCoord>(L, coord, FloatCoordBinding::getMetatableName());
}

void FloatCoordBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", FloatCoord_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "new", FloatCoord_new },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, FloatCoord_index, FloatCoord_newindex);

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "new", FloatCoord_new);
    lua_setglobal(L, "FloatCoord");
}

// ============================================================================
// FloatRect Binding
// ============================================================================
static int FloatRect_index(lua_State* L)
{
    MyGUI::FloatRect* r = checkObject<MyGUI::FloatRect>(L, 1, FloatRectBinding::getMetatableName());
    const char* key = luaL_checkstring(L, 2);
    if (strcmp(key, "left") == 0) { lua_pushnumber(L, r->left); return 1; }
    if (strcmp(key, "top") == 0) { lua_pushnumber(L, r->top); return 1; }
    if (strcmp(key, "right") == 0) { lua_pushnumber(L, r->right); return 1; }
    if (strcmp(key, "bottom") == 0) { lua_pushnumber(L, r->bottom); return 1; }
    if (strcmp(key, "width") == 0) { lua_pushnumber(L, r->width()); return 1; }
    if (strcmp(key, "height") == 0) { lua_pushnumber(L, r->height()); return 1; }
    return genericPropertyIndex(L);
}

static int FloatRect_newindex(lua_State* L)
{
    MyGUI::FloatRect* r = checkObject<MyGUI::FloatRect>(L, 1, FloatRectBinding::getMetatableName());
    const char* key = luaL_checkstring(L, 2);
    if (strcmp(key, "left") == 0) { r->left = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "top") == 0) { r->top = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "right") == 0) { r->right = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "bottom") == 0) { r->bottom = (float)luaL_checknumber(L, 3); return 0; }
    return luaL_error(L, "Invalid property '%s' on FloatRect", key);
}

static int FloatRect_tostring(lua_State* L)
{
    MyGUI::FloatRect* r = checkObject<MyGUI::FloatRect>(L, 1, FloatRectBinding::getMetatableName());
    char buf[96];
    _snprintf(buf, sizeof(buf), "FloatRect(%.3f, %.3f, %.3f, %.3f)", r->left, r->top, r->right, r->bottom);
    lua_pushstring(L, buf);
    return 1;
}

static int FloatRect_new(lua_State* L)
{
    float left = (float)luaL_optnumber(L, 1, 0.0);
    float top = (float)luaL_optnumber(L, 2, 0.0);
    float right = (float)luaL_optnumber(L, 3, 0.0);
    float bottom = (float)luaL_optnumber(L, 4, 0.0);
    MyGUI::FloatRect rect(left, top, right, bottom);
    return pushValue<MyGUI::FloatRect>(L, rect, FloatRectBinding::getMetatableName());
}

void FloatRectBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", FloatRect_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "new", FloatRect_new },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, FloatRect_index, FloatRect_newindex);

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "new", FloatRect_new);
    lua_setglobal(L, "FloatRect");
}

// ============================================================================
// Colour Binding
// ============================================================================
static int Colour_index(lua_State* L)
{
    MyGUI::Colour* c = checkObject<MyGUI::Colour>(L, 1, ColourBinding::getMetatableName());
    const char* key = luaL_checkstring(L, 2);
    if (strcmp(key, "red") == 0 || strcmp(key, "r") == 0) { lua_pushnumber(L, c->red); return 1; }
    if (strcmp(key, "green") == 0 || strcmp(key, "g") == 0) { lua_pushnumber(L, c->green); return 1; }
    if (strcmp(key, "blue") == 0 || strcmp(key, "b") == 0) { lua_pushnumber(L, c->blue); return 1; }
    if (strcmp(key, "alpha") == 0 || strcmp(key, "a") == 0) { lua_pushnumber(L, c->alpha); return 1; }
    return genericPropertyIndex(L);
}

static int Colour_newindex(lua_State* L)
{
    MyGUI::Colour* c = checkObject<MyGUI::Colour>(L, 1, ColourBinding::getMetatableName());
    const char* key = luaL_checkstring(L, 2);
    if (strcmp(key, "red") == 0 || strcmp(key, "r") == 0) { c->red = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "green") == 0 || strcmp(key, "g") == 0) { c->green = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "blue") == 0 || strcmp(key, "b") == 0) { c->blue = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "alpha") == 0 || strcmp(key, "a") == 0) { c->alpha = (float)luaL_checknumber(L, 3); return 0; }
    return luaL_error(L, "Invalid property '%s' on Colour", key);
}

static int Colour_tostring(lua_State* L)
{
    MyGUI::Colour* c = checkObject<MyGUI::Colour>(L, 1, ColourBinding::getMetatableName());
    char buf[64];
    _snprintf(buf, sizeof(buf), "Colour(%.2f, %.2f, %.2f, %.2f)", c->red, c->green, c->blue, c->alpha);
    lua_pushstring(L, buf);
    return 1;
}

static int Colour_new(lua_State* L)
{
    float r = (float)luaL_optnumber(L, 1, 1.0);
    float g = (float)luaL_optnumber(L, 2, 1.0);
    float b = (float)luaL_optnumber(L, 3, 1.0);
    float a = (float)luaL_optnumber(L, 4, 1.0);
    MyGUI::Colour col(r, g, b, a);
    return pushValue<MyGUI::Colour>(L, col, ColourBinding::getMetatableName());
}

static int Colour_parse(lua_State* L)
{
    const char* str = luaL_checkstring(L, 1);
    while (*str == ' ' || *str == '\t') ++str;

    MyGUI::Colour col(0.0f, 0.0f, 0.0f, 1.0f);

    if (*str == '#')
    {
        ++str;
        size_t len = strlen(str);
        if (len == 6)
        {
            unsigned long hex = strtoul(str, nullptr, 16);
            col.red = ((hex >> 16) & 0xFF) / 255.0f;
            col.green = ((hex >> 8) & 0xFF) / 255.0f;
            col.blue = (hex & 0xFF) / 255.0f;
            col.alpha = 1.0f;
        }
        else if (len == 8)
        {
            unsigned long hex = strtoul(str, nullptr, 16);
            col.red = ((hex >> 24) & 0xFF) / 255.0f;
            col.green = ((hex >> 16) & 0xFF) / 255.0f;
            col.blue = ((hex >> 8) & 0xFF) / 255.0f;
            col.alpha = (hex & 0xFF) / 255.0f;
        }
    }
    else
    {
        col = MyGUI::Colour::parse(str);
        if (col.red == 0.0f && col.green == 0.0f && col.blue == 0.0f && col.alpha == 0.0f)
        {
            size_t len = strlen(str);
            if (len == 6)
            {
                unsigned long hex = strtoul(str, nullptr, 16);
                col.red = ((hex >> 16) & 0xFF) / 255.0f;
                col.green = ((hex >> 8) & 0xFF) / 255.0f;
                col.blue = (hex & 0xFF) / 255.0f;
                col.alpha = 1.0f;
            }
            else if (len == 8)
            {
                unsigned long hex = strtoul(str, nullptr, 16);
                col.red = ((hex >> 24) & 0xFF) / 255.0f;
                col.green = ((hex >> 16) & 0xFF) / 255.0f;
                col.blue = ((hex >> 8) & 0xFF) / 255.0f;
                col.alpha = (hex & 0xFF) / 255.0f;
            }
        }
    }

    return pushValue<MyGUI::Colour>(L, col, ColourBinding::getMetatableName());
}

void ColourBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__tostring", Colour_tostring },
        { "__gc",       noopGc },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "new",   Colour_new },
        { "parse", Colour_parse },
        { 0, 0 }
    };
    registerClass(L, getMetatableName(), meta, methods, Colour_index, Colour_newindex);

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "new", Colour_new);
    registerStaticMethod(L, "parse", Colour_parse);
    lua_setglobal(L, "Colour");
}

} // namespace KenshiLua
