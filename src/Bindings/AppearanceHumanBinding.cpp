#include "pch.h"
#include "kenshi\appearance.h"
#include "AppearanceHumanBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/AppearanceBaseBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataCopyStandaloneBinding.h"

namespace KenshiLua
{

static AppearanceHuman* getInstance(lua_State* L, int idx)
{
    return checkObject<AppearanceHuman>(L, idx, AppearanceHumanBinding::getMetatableName());
}

// --- Getters for AppearanceHuman ---
static int AppearanceHuman_get_robotLegScale(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");
    lua_pushnumber(L, instance->robotLegScale);
    return 1;
}

static int AppearanceHuman_get_lastPhysiqueStats(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");
    pushVector3(L, instance->lastPhysiqueStats);
    return 1;
}

static int AppearanceHuman_get_bulkMult(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");
    lua_pushnumber(L, instance->bulkMult);
    return 1;
}

static int AppearanceHuman_get_muscleMult(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");
    lua_pushnumber(L, instance->muscleMult);
    return 1;
}

static int AppearanceHuman_get_skinnyMult(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");
    lua_pushnumber(L, instance->skinnyMult);
    return 1;
}

static int AppearanceHuman_get_flayed(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");
    lua_pushboolean(L, instance->flayed ? 1 : 0);
    return 1;
}

static int AppearanceHuman_get_beard(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");
    return pushObject<GameData>(L, instance->beard, GameDataBinding::getMetatableName());
}

static int AppearanceHuman_get_hiddenPartsEnabled(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");
    lua_pushboolean(L, instance->hiddenPartsEnabled ? 1 : 0);
    return 1;
}

// --- Setters for AppearanceHuman ---
static int AppearanceHuman_set_robotLegScale(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");
    instance->robotLegScale = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AppearanceHuman_set_lastPhysiqueStats(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");
    readVector3(L, 2, instance->lastPhysiqueStats);
    return 0;
}

static int AppearanceHuman_set_bulkMult(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");
    instance->bulkMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AppearanceHuman_set_muscleMult(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");
    instance->muscleMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AppearanceHuman_set_skinnyMult(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");
    instance->skinnyMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AppearanceHuman_set_flayed(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");
    instance->flayed = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AppearanceHuman_set_beard(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");
    instance->beard = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int AppearanceHuman_set_hiddenPartsEnabled(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");
    instance->hiddenPartsEnabled = lua_toboolean(L, 2) != 0;
    return 0;
}

int AppearanceHumanBinding::setGender(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");

    bool female = lua_toboolean(L, 2) != 0;
    instance->setGender(female);
    return 0;
}

int AppearanceHumanBinding::_NV_setGender(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");

    bool female = lua_toboolean(L, 2) != 0;
    instance->_NV_setGender(female);
    return 0;
}

int AppearanceHumanBinding::periodicUpdate(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");

    instance->periodicUpdate();
    return 0;
}

int AppearanceHumanBinding::_NV_periodicUpdate(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");

    instance->_NV_periodicUpdate();
    return 0;
}

int AppearanceHumanBinding::setAttachmentsVisible(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->setAttachmentsVisible(visible);
    return 0;
}

int AppearanceHumanBinding::_NV_setAttachmentsVisible(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->_NV_setAttachmentsVisible(visible);
    return 0;
}

int AppearanceHumanBinding::setHiddenPartsEnabled(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");

    bool enabled = lua_toboolean(L, 2) != 0;
    instance->setHiddenPartsEnabled(enabled);
    return 0;
}

int AppearanceHumanBinding::showFace(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");

    bool show = lua_toboolean(L, 2) != 0;
    instance->showFace(show);
    return 0;
}

int AppearanceHumanBinding::setFlayed(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");

    bool f = lua_toboolean(L, 2) != 0;
    instance->setFlayed(f);
    return 0;
}

int AppearanceHumanBinding::_NV_setFlayed(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");

    bool f = lua_toboolean(L, 2) != 0;
    instance->_NV_setFlayed(f);
    return 0;
}

int AppearanceHumanBinding::isFlayed(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");

    bool result = instance->isFlayed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceHumanBinding::_NV_isFlayed(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");

    bool result = instance->_NV_isFlayed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceHumanBinding::updateProportions(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");

    instance->updateProportions();
    return 0;
}

int AppearanceHumanBinding::createBody(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");

    instance->createBody();
    return 0;
}

int AppearanceHumanBinding::_NV_createBody(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");

    instance->_NV_createBody();
    return 0;
}

int AppearanceHumanBinding::updateAppearance(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");

    instance->updateAppearance();
    return 0;
}

int AppearanceHumanBinding::_NV_updateAppearance(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");

    instance->_NV_updateAppearance();
    return 0;
}

int AppearanceHumanBinding::updateHiddenParts(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");

    instance->updateHiddenParts();
    return 0;
}

int AppearanceHumanBinding::updatePysiqueFromStats(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");

    instance->updatePysiqueFromStats();
    return 0;
}

int AppearanceHumanBinding::updatePhysiqueMuscleMults(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");

    instance->updatePhysiqueMuscleMults();
    return 0;
}

int AppearanceHumanBinding::updateCharaterTexture(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");

    instance->updateCharaterTexture();
    return 0;
}

int AppearanceHumanBinding::_NV_updateCharaterTexture(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");

    instance->_NV_updateCharaterTexture();
    return 0;
}

int AppearanceHumanBinding::setPosture(lua_State* L)
{
    AppearanceHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AppearanceHuman is nil");

    float posture = (float)luaL_checknumber(L, 2);
    float neck = (float)luaL_checknumber(L, 3);
    float shoulders = (float)luaL_checknumber(L, 4);
    instance->setPosture(posture, neck, shoulders);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 235: void setupCharacterEntityTexture(...) - unsupported arg type
  line 236: void _NV_setupCharacterEntityTexture(...) - unsupported arg type
*/

int AppearanceHumanBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int AppearanceHumanBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AppearanceHuman object");
    return 1;
}

void AppearanceHumanBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AppearanceHumanBinding::gc },
        { "__tostring", AppearanceHumanBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setGender", AppearanceHumanBinding::setGender },
        { "_NV_setGender", AppearanceHumanBinding::_NV_setGender },
        { "periodicUpdate", AppearanceHumanBinding::periodicUpdate },
        { "_NV_periodicUpdate", AppearanceHumanBinding::_NV_periodicUpdate },
        { "setAttachmentsVisible", AppearanceHumanBinding::setAttachmentsVisible },
        { "_NV_setAttachmentsVisible", AppearanceHumanBinding::_NV_setAttachmentsVisible },
        { "setHiddenPartsEnabled", AppearanceHumanBinding::setHiddenPartsEnabled },
        { "showFace", AppearanceHumanBinding::showFace },
        { "setFlayed", AppearanceHumanBinding::setFlayed },
        { "_NV_setFlayed", AppearanceHumanBinding::_NV_setFlayed },
        { "isFlayed", AppearanceHumanBinding::isFlayed },
        { "_NV_isFlayed", AppearanceHumanBinding::_NV_isFlayed },
        { "updateProportions", AppearanceHumanBinding::updateProportions },
        { "createBody", AppearanceHumanBinding::createBody },
        { "_NV_createBody", AppearanceHumanBinding::_NV_createBody },
        { "updateAppearance", AppearanceHumanBinding::updateAppearance },
        { "_NV_updateAppearance", AppearanceHumanBinding::_NV_updateAppearance },
        { "updateHiddenParts", AppearanceHumanBinding::updateHiddenParts },
        { "updatePysiqueFromStats", AppearanceHumanBinding::updatePysiqueFromStats },
        { "updatePhysiqueMuscleMults", AppearanceHumanBinding::updatePhysiqueMuscleMults },
        { "updateCharaterTexture", AppearanceHumanBinding::updateCharaterTexture },
        { "_NV_updateCharaterTexture", AppearanceHumanBinding::_NV_updateCharaterTexture },
        { "setPosture", AppearanceHumanBinding::setPosture },
        { 0, 0 }
    };

    registerClass(
        L, 
        AppearanceHumanBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AppearanceHumanBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "robotLegScale", AppearanceHuman_get_robotLegScale);
    registerGetter(L, "lastPhysiqueStats", AppearanceHuman_get_lastPhysiqueStats);
    registerGetter(L, "bulkMult", AppearanceHuman_get_bulkMult);
    registerGetter(L, "muscleMult", AppearanceHuman_get_muscleMult);
    registerGetter(L, "skinnyMult", AppearanceHuman_get_skinnyMult);
    registerGetter(L, "flayed", AppearanceHuman_get_flayed);
    registerGetter(L, "beard", AppearanceHuman_get_beard);
    registerGetter(L, "hiddenPartsEnabled", AppearanceHuman_get_hiddenPartsEnabled);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "robotLegScale", AppearanceHuman_set_robotLegScale);
    registerSetter(L, "lastPhysiqueStats", AppearanceHuman_set_lastPhysiqueStats);
    registerSetter(L, "bulkMult", AppearanceHuman_set_bulkMult);
    registerSetter(L, "muscleMult", AppearanceHuman_set_muscleMult);
    registerSetter(L, "skinnyMult", AppearanceHuman_set_skinnyMult);
    registerSetter(L, "flayed", AppearanceHuman_set_flayed);
    registerSetter(L, "beard", AppearanceHuman_set_beard);
    registerSetter(L, "hiddenPartsEnabled", AppearanceHuman_set_hiddenPartsEnabled);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to AppearanceBase
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, AppearanceHumanBinding::getMetatableName(), AppearanceBaseBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua