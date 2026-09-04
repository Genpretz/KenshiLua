#include "pch.h"
#include <kenshi/OptionsHolder.h>
#include "OptionsHolderBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static OptionsHolder* getInstance(lua_State* L, int idx)
{
    return checkObject<OptionsHolder>(L, idx, OptionsHolderBinding::getMetatableName());
}

// --- Getters for OptionsHolder ---
static int OptionsHolder_get_CAMERA_MOVE_SPEED(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->CAMERA_MOVE_SPEED);
    return 1;
}

static int OptionsHolder_get_CAMERA_PAN_SPEED(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->CAMERA_PAN_SPEED);
    return 1;
}

static int OptionsHolder_get_CAMERA_TILT_SPEED(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->CAMERA_TILT_SPEED);
    return 1;
}

static int OptionsHolder_get_CAMERA_ZOOM_SPEED(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->CAMERA_ZOOM_SPEED);
    return 1;
}

static int OptionsHolder_get_invertX(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->invertX);
    return 1;
}

static int OptionsHolder_get_invertY(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->invertY);
    return 1;
}

static int OptionsHolder_get_VIEW_DISTANCE(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->VIEW_DISTANCE);
    return 1;
}

static int OptionsHolder_get_terrainDetail(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->terrainDetail);
    return 1;
}

static int OptionsHolder_get_terrainDistant(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->terrainDistant);
    return 1;
}

static int OptionsHolder_get_terrainThreshold(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->terrainThreshold);
    return 1;
}

static int OptionsHolder_get_terrainPatchSize(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushinteger(L, instance->terrainPatchSize);
    return 1;
}

static int OptionsHolder_get_grassRange(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->grassRange);
    return 1;
}

static int OptionsHolder_get_grassDensity(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->grassDensity);
    return 1;
}

static int OptionsHolder_get_foliageRange(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->foliageRange);
    return 1;
}

static int OptionsHolder_get_NPCRange(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->NPCRange);
    return 1;
}

static int OptionsHolder_get_smallBuildingRange(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->smallBuildingRange);
    return 1;
}

static int OptionsHolder_get_stencilsDisabled(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushboolean(L, instance->stencilsDisabled ? 1 : 0);
    return 1;
}

static int OptionsHolder_get_fancyShaders(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushboolean(L, instance->fancyShaders ? 1 : 0);
    return 1;
}

static int OptionsHolder_get_HWmouse(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushboolean(L, instance->HWmouse ? 1 : 0);
    return 1;
}

static int OptionsHolder_get_tutorials(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushboolean(L, instance->tutorials ? 1 : 0);
    return 1;
}

static int OptionsHolder_get__enabledCivilians(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushboolean(L, instance->_enabledCivilians ? 1 : 0);
    return 1;
}

static int OptionsHolder_get_populationMult(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->populationMult);
    return 1;
}

static int OptionsHolder_get_squadSizeMult(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->squadSizeMult);
    return 1;
}

static int OptionsHolder_get_raidSizeMult(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->raidSizeMult);
    return 1;
}

static int OptionsHolder_get_raidFrequencyMult(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->raidFrequencyMult);
    return 1;
}

static int OptionsHolder_get_passingAttacksOnBase(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushinteger(L, instance->passingAttacksOnBase);
    return 1;
}

static int OptionsHolder_get_shadowMode(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushinteger(L, instance->shadowMode);
    return 1;
}

static int OptionsHolder_get_shadowQuality(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushinteger(L, instance->shadowQuality);
    return 1;
}

static int OptionsHolder_get_harpoonLimit(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->harpoonLimit);
    return 1;
}

static int OptionsHolder_get_decalRange(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->decalRange);
    return 1;
}

static int OptionsHolder_get_decalResolution(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushinteger(L, instance->decalResolution);
    return 1;
}

static int OptionsHolder_get_characterMultithreading(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushboolean(L, instance->characterMultithreading ? 1 : 0);
    return 1;
}

static int OptionsHolder_get_limbLossFrequency(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushinteger(L, instance->limbLossFrequency);
    return 1;
}

static int OptionsHolder_get_showNames(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushboolean(L, instance->showNames ? 1 : 0);
    return 1;
}

static int OptionsHolder_get_edgeScrolling(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushboolean(L, instance->edgeScrolling ? 1 : 0);
    return 1;
}

static int OptionsHolder_get_damageFloaters(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushinteger(L, instance->damageFloaters);
    return 1;
}

static int OptionsHolder_get_showRotationMarker(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushboolean(L, instance->showRotationMarker ? 1 : 0);
    return 1;
}

static int OptionsHolder_get_showMoveMarker(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushboolean(L, instance->showMoveMarker ? 1 : 0);
    return 1;
}

static int OptionsHolder_get_fontSize(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->fontSize);
    return 1;
}

static int OptionsHolder_get_manyActiveZones(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushboolean(L, instance->manyActiveZones ? 1 : 0);
    return 1;
}

static int OptionsHolder_get_distantTownRange(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->distantTownRange);
    return 1;
}

static int OptionsHolder_get_featureRange(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->featureRange);
    return 1;
}

static int OptionsHolder_get_generateDistantTowns(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushboolean(L, instance->generateDistantTowns ? 1 : 0);
    return 1;
}

static int OptionsHolder_get_shadowRange(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->shadowRange);
    return 1;
}

static int OptionsHolder_get_ddsTextureMipMapGimping(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushinteger(L, instance->ddsTextureMipMapGimping);
    return 1;
}

static int OptionsHolder_get_reflectionMode(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushinteger(L, instance->reflectionMode);
    return 1;
}

static int OptionsHolder_get_reflectionDistance(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->reflectionDistance);
    return 1;
}

static int OptionsHolder_get_compositors(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    // TODO: Unsupported type for compositors (lektor<std::pair<std::string, bool> >)
    lua_pushnil(L);
    return 1;
}

static int OptionsHolder_get_musicVolume(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->musicVolume);
    return 1;
}

static int OptionsHolder_get_ambientVolume(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->ambientVolume);
    return 1;
}

static int OptionsHolder_get_footstepVolume(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->footstepVolume);
    return 1;
}

static int OptionsHolder_get_sfxVolume(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->sfxVolume);
    return 1;
}

static int OptionsHolder_get_uiVolume(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->uiVolume);
    return 1;
}

static int OptionsHolder_get_voVolume(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->voVolume);
    return 1;
}

static int OptionsHolder_get_musicFrequency(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->musicFrequency);
    return 1;
}

static int OptionsHolder_get_autosavetime(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushnumber(L, instance->autosavetime);
    return 1;
}

static int OptionsHolder_get_fullscreen(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushboolean(L, instance->fullscreen ? 1 : 0);
    return 1;
}

static int OptionsHolder_get_borderless(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushboolean(L, instance->borderless ? 1 : 0);
    return 1;
}

static int OptionsHolder_get_autosave(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushboolean(L, instance->autosave ? 1 : 0);
    return 1;
}

static int OptionsHolder_get_userSaves(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushboolean(L, instance->userSaves ? 1 : 0);
    return 1;
}

static int OptionsHolder_get_blood(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushboolean(L, instance->blood ? 1 : 0);
    return 1;
}

static int OptionsHolder_get_censorship(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    lua_pushboolean(L, instance->censorship ? 1 : 0);
    return 1;
}

// --- Setters for OptionsHolder ---
static int OptionsHolder_set_CAMERA_MOVE_SPEED(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->CAMERA_MOVE_SPEED = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_CAMERA_PAN_SPEED(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->CAMERA_PAN_SPEED = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_CAMERA_TILT_SPEED(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->CAMERA_TILT_SPEED = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_CAMERA_ZOOM_SPEED(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->CAMERA_ZOOM_SPEED = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_invertX(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->invertX = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_invertY(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->invertY = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_VIEW_DISTANCE(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->VIEW_DISTANCE = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_terrainDetail(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->terrainDetail = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_terrainDistant(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->terrainDistant = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_terrainThreshold(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->terrainThreshold = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_terrainPatchSize(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->terrainPatchSize = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int OptionsHolder_set_grassRange(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->grassRange = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_grassDensity(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->grassDensity = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_foliageRange(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->foliageRange = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_NPCRange(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->NPCRange = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_smallBuildingRange(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->smallBuildingRange = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_stencilsDisabled(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->stencilsDisabled = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OptionsHolder_set_fancyShaders(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->fancyShaders = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OptionsHolder_set_HWmouse(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->HWmouse = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OptionsHolder_set_tutorials(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->tutorials = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OptionsHolder_set__enabledCivilians(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->_enabledCivilians = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OptionsHolder_set_populationMult(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->populationMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_squadSizeMult(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->squadSizeMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_raidSizeMult(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->raidSizeMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_raidFrequencyMult(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->raidFrequencyMult = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_passingAttacksOnBase(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->passingAttacksOnBase = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int OptionsHolder_set_shadowMode(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->shadowMode = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int OptionsHolder_set_shadowQuality(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->shadowQuality = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int OptionsHolder_set_harpoonLimit(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->harpoonLimit = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_decalRange(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->decalRange = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_decalResolution(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->decalResolution = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int OptionsHolder_set_characterMultithreading(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->characterMultithreading = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OptionsHolder_set_limbLossFrequency(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->limbLossFrequency = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int OptionsHolder_set_showNames(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->showNames = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OptionsHolder_set_edgeScrolling(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->edgeScrolling = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OptionsHolder_set_damageFloaters(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->damageFloaters = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int OptionsHolder_set_showRotationMarker(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->showRotationMarker = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OptionsHolder_set_showMoveMarker(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->showMoveMarker = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OptionsHolder_set_fontSize(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->fontSize = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_manyActiveZones(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->manyActiveZones = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OptionsHolder_set_distantTownRange(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->distantTownRange = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_featureRange(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->featureRange = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_generateDistantTowns(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->generateDistantTowns = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OptionsHolder_set_shadowRange(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->shadowRange = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_ddsTextureMipMapGimping(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->ddsTextureMipMapGimping = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int OptionsHolder_set_reflectionMode(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->reflectionMode = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int OptionsHolder_set_reflectionDistance(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->reflectionDistance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_compositors(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    return luaL_error(L, "Read-only or unsupported setter type for compositors");
}

static int OptionsHolder_set_musicVolume(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->musicVolume = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_ambientVolume(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->ambientVolume = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_footstepVolume(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->footstepVolume = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_sfxVolume(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->sfxVolume = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_uiVolume(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->uiVolume = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_voVolume(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->voVolume = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_musicFrequency(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->musicFrequency = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_autosavetime(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->autosavetime = (float)luaL_checknumber(L, 2);
    return 0;
}

static int OptionsHolder_set_fullscreen(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->fullscreen = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OptionsHolder_set_borderless(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->borderless = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OptionsHolder_set_autosave(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->autosave = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OptionsHolder_set_userSaves(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->userSaves = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OptionsHolder_set_blood(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->blood = lua_toboolean(L, 2) != 0;
    return 0;
}

static int OptionsHolder_set_censorship(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");
    instance->censorship = lua_toboolean(L, 2) != 0;
    return 0;
}

// --- Methods for OptionsHolder
int OptionsHolderBinding::enabledCivilians(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");

    bool result = instance->enabledCivilians();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int OptionsHolderBinding::characterMultithreadingEnabled(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");

    bool result = instance->characterMultithreadingEnabled();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int OptionsHolderBinding::compositiorEnabled(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");

    std::string name = luaL_checkstring(L, 2);
    bool result = instance->compositiorEnabled(name);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int OptionsHolderBinding::loadCompositorSettings(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");

    instance->loadCompositorSettings();
    return 0;
}

int OptionsHolderBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int OptionsHolderBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.OptionsHolder object");
    return 1;
}

void OptionsHolderBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       OptionsHolderBinding::gc },
        { "__tostring", OptionsHolderBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "enabledCivilians", OptionsHolderBinding::enabledCivilians },
        { "characterMultithreadingEnabled", OptionsHolderBinding::characterMultithreadingEnabled },
        { "compositiorEnabled", OptionsHolderBinding::compositiorEnabled },
        { "loadCompositorSettings", OptionsHolderBinding::loadCompositorSettings },
        { 0, 0 }
    };

    registerClass(
        L, 
        OptionsHolderBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, OptionsHolderBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "CAMERA_MOVE_SPEED", OptionsHolder_get_CAMERA_MOVE_SPEED);
    registerGetter(L, "CAMERA_PAN_SPEED", OptionsHolder_get_CAMERA_PAN_SPEED);
    registerGetter(L, "CAMERA_TILT_SPEED", OptionsHolder_get_CAMERA_TILT_SPEED);
    registerGetter(L, "CAMERA_ZOOM_SPEED", OptionsHolder_get_CAMERA_ZOOM_SPEED);
    registerGetter(L, "invertX", OptionsHolder_get_invertX);
    registerGetter(L, "invertY", OptionsHolder_get_invertY);
    registerGetter(L, "VIEW_DISTANCE", OptionsHolder_get_VIEW_DISTANCE);
    registerGetter(L, "terrainDetail", OptionsHolder_get_terrainDetail);
    registerGetter(L, "terrainDistant", OptionsHolder_get_terrainDistant);
    registerGetter(L, "terrainThreshold", OptionsHolder_get_terrainThreshold);
    registerGetter(L, "terrainPatchSize", OptionsHolder_get_terrainPatchSize);
    registerGetter(L, "grassRange", OptionsHolder_get_grassRange);
    registerGetter(L, "grassDensity", OptionsHolder_get_grassDensity);
    registerGetter(L, "foliageRange", OptionsHolder_get_foliageRange);
    registerGetter(L, "NPCRange", OptionsHolder_get_NPCRange);
    registerGetter(L, "smallBuildingRange", OptionsHolder_get_smallBuildingRange);
    registerGetter(L, "stencilsDisabled", OptionsHolder_get_stencilsDisabled);
    registerGetter(L, "fancyShaders", OptionsHolder_get_fancyShaders);
    registerGetter(L, "HWmouse", OptionsHolder_get_HWmouse);
    registerGetter(L, "tutorials", OptionsHolder_get_tutorials);
    registerGetter(L, "_enabledCivilians", OptionsHolder_get__enabledCivilians);
    registerGetter(L, "populationMult", OptionsHolder_get_populationMult);
    registerGetter(L, "squadSizeMult", OptionsHolder_get_squadSizeMult);
    registerGetter(L, "raidSizeMult", OptionsHolder_get_raidSizeMult);
    registerGetter(L, "raidFrequencyMult", OptionsHolder_get_raidFrequencyMult);
    registerGetter(L, "passingAttacksOnBase", OptionsHolder_get_passingAttacksOnBase);
    registerGetter(L, "shadowMode", OptionsHolder_get_shadowMode);
    registerGetter(L, "shadowQuality", OptionsHolder_get_shadowQuality);
    registerGetter(L, "harpoonLimit", OptionsHolder_get_harpoonLimit);
    registerGetter(L, "decalRange", OptionsHolder_get_decalRange);
    registerGetter(L, "decalResolution", OptionsHolder_get_decalResolution);
    registerGetter(L, "characterMultithreading", OptionsHolder_get_characterMultithreading);
    registerGetter(L, "limbLossFrequency", OptionsHolder_get_limbLossFrequency);
    registerGetter(L, "showNames", OptionsHolder_get_showNames);
    registerGetter(L, "edgeScrolling", OptionsHolder_get_edgeScrolling);
    registerGetter(L, "damageFloaters", OptionsHolder_get_damageFloaters);
    registerGetter(L, "showRotationMarker", OptionsHolder_get_showRotationMarker);
    registerGetter(L, "showMoveMarker", OptionsHolder_get_showMoveMarker);
    registerGetter(L, "fontSize", OptionsHolder_get_fontSize);
    registerGetter(L, "manyActiveZones", OptionsHolder_get_manyActiveZones);
    registerGetter(L, "distantTownRange", OptionsHolder_get_distantTownRange);
    registerGetter(L, "featureRange", OptionsHolder_get_featureRange);
    registerGetter(L, "generateDistantTowns", OptionsHolder_get_generateDistantTowns);
    registerGetter(L, "shadowRange", OptionsHolder_get_shadowRange);
    registerGetter(L, "ddsTextureMipMapGimping", OptionsHolder_get_ddsTextureMipMapGimping);
    registerGetter(L, "reflectionMode", OptionsHolder_get_reflectionMode);
    registerGetter(L, "reflectionDistance", OptionsHolder_get_reflectionDistance);
    registerGetter(L, "compositors", OptionsHolder_get_compositors);
    registerGetter(L, "musicVolume", OptionsHolder_get_musicVolume);
    registerGetter(L, "ambientVolume", OptionsHolder_get_ambientVolume);
    registerGetter(L, "footstepVolume", OptionsHolder_get_footstepVolume);
    registerGetter(L, "sfxVolume", OptionsHolder_get_sfxVolume);
    registerGetter(L, "uiVolume", OptionsHolder_get_uiVolume);
    registerGetter(L, "voVolume", OptionsHolder_get_voVolume);
    registerGetter(L, "musicFrequency", OptionsHolder_get_musicFrequency);
    registerGetter(L, "autosavetime", OptionsHolder_get_autosavetime);
    registerGetter(L, "fullscreen", OptionsHolder_get_fullscreen);
    registerGetter(L, "borderless", OptionsHolder_get_borderless);
    registerGetter(L, "autosave", OptionsHolder_get_autosave);
    registerGetter(L, "userSaves", OptionsHolder_get_userSaves);
    registerGetter(L, "blood", OptionsHolder_get_blood);
    registerGetter(L, "censorship", OptionsHolder_get_censorship);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "CAMERA_MOVE_SPEED", OptionsHolder_set_CAMERA_MOVE_SPEED);
    registerSetter(L, "CAMERA_PAN_SPEED", OptionsHolder_set_CAMERA_PAN_SPEED);
    registerSetter(L, "CAMERA_TILT_SPEED", OptionsHolder_set_CAMERA_TILT_SPEED);
    registerSetter(L, "CAMERA_ZOOM_SPEED", OptionsHolder_set_CAMERA_ZOOM_SPEED);
    registerSetter(L, "invertX", OptionsHolder_set_invertX);
    registerSetter(L, "invertY", OptionsHolder_set_invertY);
    registerSetter(L, "VIEW_DISTANCE", OptionsHolder_set_VIEW_DISTANCE);
    registerSetter(L, "terrainDetail", OptionsHolder_set_terrainDetail);
    registerSetter(L, "terrainDistant", OptionsHolder_set_terrainDistant);
    registerSetter(L, "terrainThreshold", OptionsHolder_set_terrainThreshold);
    registerSetter(L, "terrainPatchSize", OptionsHolder_set_terrainPatchSize);
    registerSetter(L, "grassRange", OptionsHolder_set_grassRange);
    registerSetter(L, "grassDensity", OptionsHolder_set_grassDensity);
    registerSetter(L, "foliageRange", OptionsHolder_set_foliageRange);
    registerSetter(L, "NPCRange", OptionsHolder_set_NPCRange);
    registerSetter(L, "smallBuildingRange", OptionsHolder_set_smallBuildingRange);
    registerSetter(L, "stencilsDisabled", OptionsHolder_set_stencilsDisabled);
    registerSetter(L, "fancyShaders", OptionsHolder_set_fancyShaders);
    registerSetter(L, "HWmouse", OptionsHolder_set_HWmouse);
    registerSetter(L, "tutorials", OptionsHolder_set_tutorials);
    registerSetter(L, "_enabledCivilians", OptionsHolder_set__enabledCivilians);
    registerSetter(L, "populationMult", OptionsHolder_set_populationMult);
    registerSetter(L, "squadSizeMult", OptionsHolder_set_squadSizeMult);
    registerSetter(L, "raidSizeMult", OptionsHolder_set_raidSizeMult);
    registerSetter(L, "raidFrequencyMult", OptionsHolder_set_raidFrequencyMult);
    registerSetter(L, "passingAttacksOnBase", OptionsHolder_set_passingAttacksOnBase);
    registerSetter(L, "shadowMode", OptionsHolder_set_shadowMode);
    registerSetter(L, "shadowQuality", OptionsHolder_set_shadowQuality);
    registerSetter(L, "harpoonLimit", OptionsHolder_set_harpoonLimit);
    registerSetter(L, "decalRange", OptionsHolder_set_decalRange);
    registerSetter(L, "decalResolution", OptionsHolder_set_decalResolution);
    registerSetter(L, "characterMultithreading", OptionsHolder_set_characterMultithreading);
    registerSetter(L, "limbLossFrequency", OptionsHolder_set_limbLossFrequency);
    registerSetter(L, "showNames", OptionsHolder_set_showNames);
    registerSetter(L, "edgeScrolling", OptionsHolder_set_edgeScrolling);
    registerSetter(L, "damageFloaters", OptionsHolder_set_damageFloaters);
    registerSetter(L, "showRotationMarker", OptionsHolder_set_showRotationMarker);
    registerSetter(L, "showMoveMarker", OptionsHolder_set_showMoveMarker);
    registerSetter(L, "fontSize", OptionsHolder_set_fontSize);
    registerSetter(L, "manyActiveZones", OptionsHolder_set_manyActiveZones);
    registerSetter(L, "distantTownRange", OptionsHolder_set_distantTownRange);
    registerSetter(L, "featureRange", OptionsHolder_set_featureRange);
    registerSetter(L, "generateDistantTowns", OptionsHolder_set_generateDistantTowns);
    registerSetter(L, "shadowRange", OptionsHolder_set_shadowRange);
    registerSetter(L, "ddsTextureMipMapGimping", OptionsHolder_set_ddsTextureMipMapGimping);
    registerSetter(L, "reflectionMode", OptionsHolder_set_reflectionMode);
    registerSetter(L, "reflectionDistance", OptionsHolder_set_reflectionDistance);
    registerSetter(L, "compositors", OptionsHolder_set_compositors);
    registerSetter(L, "musicVolume", OptionsHolder_set_musicVolume);
    registerSetter(L, "ambientVolume", OptionsHolder_set_ambientVolume);
    registerSetter(L, "footstepVolume", OptionsHolder_set_footstepVolume);
    registerSetter(L, "sfxVolume", OptionsHolder_set_sfxVolume);
    registerSetter(L, "uiVolume", OptionsHolder_set_uiVolume);
    registerSetter(L, "voVolume", OptionsHolder_set_voVolume);
    registerSetter(L, "musicFrequency", OptionsHolder_set_musicFrequency);
    registerSetter(L, "autosavetime", OptionsHolder_set_autosavetime);
    registerSetter(L, "fullscreen", OptionsHolder_set_fullscreen);
    registerSetter(L, "borderless", OptionsHolder_set_borderless);
    registerSetter(L, "autosave", OptionsHolder_set_autosave);
    registerSetter(L, "userSaves", OptionsHolder_set_userSaves);
    registerSetter(L, "blood", OptionsHolder_set_blood);
    registerSetter(L, "censorship", OptionsHolder_set_censorship);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
