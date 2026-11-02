#include "pch.h"
#include "kenshi/Animation/AnimationClass.h"
#include "AnimationChoicesBinding.h"
#include "AnimationDataBinding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(offsetof(AnimationChoices, anims) == 0x0, "AnimationChoices::anims offset mismatch");
static_assert(offsetof(AnimationChoices, weights) == 0x18, "AnimationChoices::weights offset mismatch");

static AnimationChoices* getInstance(lua_State* L, int idx)
{
    return checkObject<AnimationChoices>(L, idx, AnimationChoicesBinding::getMetatableName());
}

static int AnimationChoices_get_anims(lua_State* L)
{
    AnimationChoices* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationChoices is nil");
    return pushObject<lektor<AnimationData*>>(L, &instance->anims, "lektor<AnimationData*>");
}

static int AnimationChoices_set_anims(lua_State* L)
{
    AnimationChoices* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationChoices is nil");
    auto* val = LektorPtrBinding<AnimationData*>::getInstance(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'anims' must be lektor<AnimationData*>");
    instance->anims = *val;
    return 0;
}

static int AnimationChoices_get_weights(lua_State* L)
{
    AnimationChoices* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationChoices is nil");
    return pushObject<lektor<float>>(L, &instance->weights, "lektor<float>");
}

static int AnimationChoices_set_weights(lua_State* L)
{
    AnimationChoices* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationChoices is nil");
    auto* val = LektorValueBinding<float>::getInstance(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'weights' must be lektor<float>");
    instance->weights = *val;
    return 0;
}

int AnimationChoicesBinding::normaliseWeights(lua_State* L)
{
    AnimationChoices* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationChoices is nil");
    instance->normaliseWeights();
    return 0;
}

int AnimationChoicesBinding::calculateSpeedOfMoveAnims(lua_State* L)
{
    AnimationChoices* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationChoices is nil");
    float travelSpeed = (float)luaL_checknumber(L, 2);
    float characterHeight = (float)luaL_checknumber(L, 3);
    float result = instance->calculateSpeedOfMoveAnims(travelSpeed, characterHeight);
    lua_pushnumber(L, (lua_Number)result);
    return 1;
}

int AnimationChoicesBinding::chooseHighestScore(lua_State* L)
{
    AnimationChoices* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimationChoices is nil");
    AnimationData* result = instance->chooseHighestScore();
    if (!result) { lua_pushnil(L); return 1; }
    return pushObject<AnimationData>(L, result, AnimationDataBinding::getMetatableName());
}

int AnimationChoicesBinding::gc(lua_State* L)
{
    return 0;
}

int AnimationChoicesBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AnimationChoices object");
    return 1;
}

void AnimationChoicesBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AnimationChoicesBinding::gc },
        { "__tostring", AnimationChoicesBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "normaliseWeights", AnimationChoicesBinding::normaliseWeights },
        { "calculateSpeedOfMoveAnims", AnimationChoicesBinding::calculateSpeedOfMoveAnims },
        { "chooseHighestScore", AnimationChoicesBinding::chooseHighestScore },
        { 0, 0 }
    };

    registerClass(
        L,
        AnimationChoicesBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AnimationChoicesBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "anims", AnimationChoices_get_anims);
    registerGetter(L, "weights", AnimationChoices_get_weights);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "anims", AnimationChoices_set_anims);
    registerSetter(L, "weights", AnimationChoices_set_weights);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);

}

} // namespace KenshiLua

