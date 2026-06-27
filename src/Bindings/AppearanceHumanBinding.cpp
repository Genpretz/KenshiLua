#include "pch.h"
#include "kenshi\Appearance.h"
#include "AppearanceHumanBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{

static AppearanceHuman* getB(lua_State* L, int idx)
{
    return checkObject<AppearanceHuman>(L, idx, AppearanceHumanBinding::getMetatableName());
}

// --- Getters for AppearanceHuman ---
static int AppearanceHuman_get_robotLegScale(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");
    lua_pushnumber(L, b->robotLegScale);
    return 1;
}

static int AppearanceHuman_get_lastPhysiqueStats(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");
    pushVector3(L, b->lastPhysiqueStats);
    return 1;
}

static int AppearanceHuman_get_bulkMult(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");
    lua_pushnumber(L, b->bulkMult);
    return 1;
}

static int AppearanceHuman_get_muscleMult(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");
    lua_pushnumber(L, b->muscleMult);
    return 1;
}

static int AppearanceHuman_get_skinnyMult(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");
    lua_pushnumber(L, b->skinnyMult);
    return 1;
}

static int AppearanceHuman_get_flayed(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");
    lua_pushboolean(L, b->flayed ? 1 : 0);
    return 1;
}

static int AppearanceHuman_get_beard(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");
    return pushObject<GameData>(L, b->beard, GameDataBinding::getMetatableName());
}

static int AppearanceHuman_get_hiddenPartsEnabled(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");
    lua_pushboolean(L, b->hiddenPartsEnabled ? 1 : 0);
    return 1;
}

// --- Setters for AppearanceHuman ---
static int AppearanceHuman_set_robotLegScale(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");
    b->robotLegScale = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AppearanceHuman_set_lastPhysiqueStats(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");
    readVector3(L, 2, b->lastPhysiqueStats);
    return 0;
}

static int AppearanceHuman_set_bulkMult(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");
    b->bulkMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AppearanceHuman_set_muscleMult(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");
    b->muscleMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AppearanceHuman_set_skinnyMult(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");
    b->skinnyMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AppearanceHuman_set_flayed(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");
    b->flayed = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AppearanceHuman_set_beard(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");
    return luaL_error(L, "Read-only or unsupported setter type for beard");
}

static int AppearanceHuman_set_hiddenPartsEnabled(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");
    b->hiddenPartsEnabled = lua_toboolean(L, 2) != 0;
    return 0;
}

int AppearanceHumanBinding::_DESTRUCTOR(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    b->_DESTRUCTOR();
    return 0;
}

int AppearanceHumanBinding::setGender(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    bool female = lua_toboolean(L, 2) != 0;
    b->setGender(female);
    return 0;
}

int AppearanceHumanBinding::_NV_setGender(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    bool female = lua_toboolean(L, 2) != 0;
    b->_NV_setGender(female);
    return 0;
}

int AppearanceHumanBinding::periodicUpdate(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    b->periodicUpdate();
    return 0;
}

int AppearanceHumanBinding::_NV_periodicUpdate(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    b->_NV_periodicUpdate();
    return 0;
}

int AppearanceHumanBinding::setAttachmentsVisible(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    b->setAttachmentsVisible(visible);
    return 0;
}

int AppearanceHumanBinding::_NV_setAttachmentsVisible(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    b->_NV_setAttachmentsVisible(visible);
    return 0;
}

int AppearanceHumanBinding::setHiddenPartsEnabled(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    bool enabled = lua_toboolean(L, 2) != 0;
    b->setHiddenPartsEnabled(enabled);
    return 0;
}

int AppearanceHumanBinding::showFace(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    bool show = lua_toboolean(L, 2) != 0;
    b->showFace(show);
    return 0;
}

int AppearanceHumanBinding::setFlayed(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    bool f = lua_toboolean(L, 2) != 0;
    b->setFlayed(f);
    return 0;
}

int AppearanceHumanBinding::_NV_setFlayed(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    bool f = lua_toboolean(L, 2) != 0;
    b->_NV_setFlayed(f);
    return 0;
}

int AppearanceHumanBinding::isFlayed(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    bool result = b->isFlayed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceHumanBinding::_NV_isFlayed(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    bool result = b->_NV_isFlayed();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AppearanceHumanBinding::updateProportions(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    b->updateProportions();
    return 0;
}

int AppearanceHumanBinding::createBody(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    b->createBody();
    return 0;
}

int AppearanceHumanBinding::_NV_createBody(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    b->_NV_createBody();
    return 0;
}

int AppearanceHumanBinding::updateAppearance(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    b->updateAppearance();
    return 0;
}

int AppearanceHumanBinding::_NV_updateAppearance(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    b->_NV_updateAppearance();
    return 0;
}

int AppearanceHumanBinding::updateHiddenParts(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    b->updateHiddenParts();
    return 0;
}

int AppearanceHumanBinding::updatePysiqueFromStats(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    b->updatePysiqueFromStats();
    return 0;
}

int AppearanceHumanBinding::updatePhysiqueMuscleMults(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    b->updatePhysiqueMuscleMults();
    return 0;
}

int AppearanceHumanBinding::updateCharaterTexture(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    b->updateCharaterTexture();
    return 0;
}

int AppearanceHumanBinding::_NV_updateCharaterTexture(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    b->_NV_updateCharaterTexture();
    return 0;
}

int AppearanceHumanBinding::setPosture(lua_State* L)
{
    AppearanceHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceHuman is nil");

    float posture = (float)luaL_checknumber(L, 2);
    float neck = (float)luaL_checknumber(L, 3);
    float shoulders = (float)luaL_checknumber(L, 4);
    b->setPosture(posture, neck, shoulders);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 204: AppearanceHuman* _CONSTRUCTOR(...) - unsupported return type
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
        { "_DESTRUCTOR", AppearanceHumanBinding::_DESTRUCTOR },
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
    lua_pushcfunction(L, AppearanceHuman_get_robotLegScale);
    lua_setfield(L, -2, "robotLegScale");
    lua_pushcfunction(L, AppearanceHuman_get_lastPhysiqueStats);
    lua_setfield(L, -2, "lastPhysiqueStats");
    lua_pushcfunction(L, AppearanceHuman_get_bulkMult);
    lua_setfield(L, -2, "bulkMult");
    lua_pushcfunction(L, AppearanceHuman_get_muscleMult);
    lua_setfield(L, -2, "muscleMult");
    lua_pushcfunction(L, AppearanceHuman_get_skinnyMult);
    lua_setfield(L, -2, "skinnyMult");
    lua_pushcfunction(L, AppearanceHuman_get_flayed);
    lua_setfield(L, -2, "flayed");
    lua_pushcfunction(L, AppearanceHuman_get_beard);
    lua_setfield(L, -2, "beard");
    lua_pushcfunction(L, AppearanceHuman_get_hiddenPartsEnabled);
    lua_setfield(L, -2, "hiddenPartsEnabled");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, AppearanceHuman_set_robotLegScale);
    lua_setfield(L, -2, "robotLegScale");
    lua_pushcfunction(L, AppearanceHuman_set_lastPhysiqueStats);
    lua_setfield(L, -2, "lastPhysiqueStats");
    lua_pushcfunction(L, AppearanceHuman_set_bulkMult);
    lua_setfield(L, -2, "bulkMult");
    lua_pushcfunction(L, AppearanceHuman_set_muscleMult);
    lua_setfield(L, -2, "muscleMult");
    lua_pushcfunction(L, AppearanceHuman_set_skinnyMult);
    lua_setfield(L, -2, "skinnyMult");
    lua_pushcfunction(L, AppearanceHuman_set_flayed);
    lua_setfield(L, -2, "flayed");
    lua_pushcfunction(L, AppearanceHuman_set_beard);
    lua_setfield(L, -2, "beard");
    lua_pushcfunction(L, AppearanceHuman_set_hiddenPartsEnabled);
    lua_setfield(L, -2, "hiddenPartsEnabled");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua