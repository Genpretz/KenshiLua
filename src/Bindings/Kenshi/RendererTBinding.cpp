#include "pch.h"
#include "kenshi/Renderer.h"
#include "RendererTBinding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(offsetof(RendererT, debugEntsUpdateListT) == 0x8, "RendererT::debugEntsUpdateListT offset mismatch");

static RendererT* getInstance(lua_State* L, int idx)
{
    return checkObject<RendererT>(L, idx, RendererTBinding::getMetatableName());
}

static int RendererT_get_debugEntsUpdateListT(lua_State* L)
{
    RendererT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RendererT is nil");
    return pushObject<lektor<RenderEntityT*>>(L, &instance->debugEntsUpdateListT, "lektor<RenderEntityT*>");
}

static int RendererT_set_debugEntsUpdateListT(lua_State* L)
{
    RendererT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RendererT is nil");
    auto* val = LektorPtrBinding<RenderEntityT*>::getInstance(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set debugEntsUpdateListT must be lektor<RenderEntityT*>");
    instance->debugEntsUpdateListT = *val;
    return 0;
}

int RendererTBinding::update(lua_State* L)
{
    RendererT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RendererT is nil");
    instance->update();
    return 0;
}

int RendererTBinding::gc(lua_State* L)
{
    return 0;
}

int RendererTBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.RendererT object");
    return 1;
}

void RendererTBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RendererTBinding::gc },
        { "__tostring", RendererTBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "update", RendererTBinding::update },
        { 0, 0 }
    };

    registerClass(
        L,
        RendererTBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, RendererTBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "debugEntsUpdateListT", RendererT_get_debugEntsUpdateListT);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "debugEntsUpdateListT", RendererT_set_debugEntsUpdateListT);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);

    LektorPtrBinding<RenderEntityT*>::registerBinding(L, "lektor<RenderEntityT*>", nullptr);
}

} // namespace KenshiLua

