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
int OptionsHolderBinding::_CONSTRUCTOR(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");

    OptionsHolder* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

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

int OptionsHolderBinding::_DESTRUCTOR(lua_State* L)
{
    OptionsHolder* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OptionsHolder is nil");

    instance->_DESTRUCTOR();
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
        { "_CONSTRUCTOR", OptionsHolderBinding::_CONSTRUCTOR },
        { "enabledCivilians", OptionsHolderBinding::enabledCivilians },
        { "characterMultithreadingEnabled", OptionsHolderBinding::characterMultithreadingEnabled },
        { "compositiorEnabled", OptionsHolderBinding::compositiorEnabled },
        { "loadCompositorSettings", OptionsHolderBinding::loadCompositorSettings },
        { "_DESTRUCTOR", OptionsHolderBinding::_DESTRUCTOR },
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
    lua_pushcfunction(L, OptionsHolder_get_CAMERA_MOVE_SPEED);
    lua_setfield(L, -2, "CAMERA_MOVE_SPEED");
    lua_pushcfunction(L, OptionsHolder_get_CAMERA_PAN_SPEED);
    lua_setfield(L, -2, "CAMERA_PAN_SPEED");
    lua_pushcfunction(L, OptionsHolder_get_CAMERA_TILT_SPEED);
    lua_setfield(L, -2, "CAMERA_TILT_SPEED");
    lua_pushcfunction(L, OptionsHolder_get_CAMERA_ZOOM_SPEED);
    lua_setfield(L, -2, "CAMERA_ZOOM_SPEED");
    lua_pushcfunction(L, OptionsHolder_get_invertX);
    lua_setfield(L, -2, "invertX");
    lua_pushcfunction(L, OptionsHolder_get_invertY);
    lua_setfield(L, -2, "invertY");
    lua_pushcfunction(L, OptionsHolder_get_VIEW_DISTANCE);
    lua_setfield(L, -2, "VIEW_DISTANCE");
    lua_pushcfunction(L, OptionsHolder_get_terrainDetail);
    lua_setfield(L, -2, "terrainDetail");
    lua_pushcfunction(L, OptionsHolder_get_terrainDistant);
    lua_setfield(L, -2, "terrainDistant");
    lua_pushcfunction(L, OptionsHolder_get_terrainThreshold);
    lua_setfield(L, -2, "terrainThreshold");
    lua_pushcfunction(L, OptionsHolder_get_terrainPatchSize);
    lua_setfield(L, -2, "terrainPatchSize");
    lua_pushcfunction(L, OptionsHolder_get_grassRange);
    lua_setfield(L, -2, "grassRange");
    lua_pushcfunction(L, OptionsHolder_get_grassDensity);
    lua_setfield(L, -2, "grassDensity");
    lua_pushcfunction(L, OptionsHolder_get_foliageRange);
    lua_setfield(L, -2, "foliageRange");
    lua_pushcfunction(L, OptionsHolder_get_NPCRange);
    lua_setfield(L, -2, "NPCRange");
    lua_pushcfunction(L, OptionsHolder_get_smallBuildingRange);
    lua_setfield(L, -2, "smallBuildingRange");
    lua_pushcfunction(L, OptionsHolder_get_stencilsDisabled);
    lua_setfield(L, -2, "stencilsDisabled");
    lua_pushcfunction(L, OptionsHolder_get_fancyShaders);
    lua_setfield(L, -2, "fancyShaders");
    lua_pushcfunction(L, OptionsHolder_get_HWmouse);
    lua_setfield(L, -2, "HWmouse");
    lua_pushcfunction(L, OptionsHolder_get_tutorials);
    lua_setfield(L, -2, "tutorials");
    lua_pushcfunction(L, OptionsHolder_get__enabledCivilians);
    lua_setfield(L, -2, "_enabledCivilians");
    lua_pushcfunction(L, OptionsHolder_get_populationMult);
    lua_setfield(L, -2, "populationMult");
    lua_pushcfunction(L, OptionsHolder_get_squadSizeMult);
    lua_setfield(L, -2, "squadSizeMult");
    lua_pushcfunction(L, OptionsHolder_get_raidSizeMult);
    lua_setfield(L, -2, "raidSizeMult");
    lua_pushcfunction(L, OptionsHolder_get_raidFrequencyMult);
    lua_setfield(L, -2, "raidFrequencyMult");
    lua_pushcfunction(L, OptionsHolder_get_passingAttacksOnBase);
    lua_setfield(L, -2, "passingAttacksOnBase");
    lua_pushcfunction(L, OptionsHolder_get_shadowMode);
    lua_setfield(L, -2, "shadowMode");
    lua_pushcfunction(L, OptionsHolder_get_shadowQuality);
    lua_setfield(L, -2, "shadowQuality");
    lua_pushcfunction(L, OptionsHolder_get_harpoonLimit);
    lua_setfield(L, -2, "harpoonLimit");
    lua_pushcfunction(L, OptionsHolder_get_decalRange);
    lua_setfield(L, -2, "decalRange");
    lua_pushcfunction(L, OptionsHolder_get_decalResolution);
    lua_setfield(L, -2, "decalResolution");
    lua_pushcfunction(L, OptionsHolder_get_characterMultithreading);
    lua_setfield(L, -2, "characterMultithreading");
    lua_pushcfunction(L, OptionsHolder_get_limbLossFrequency);
    lua_setfield(L, -2, "limbLossFrequency");
    lua_pushcfunction(L, OptionsHolder_get_showNames);
    lua_setfield(L, -2, "showNames");
    lua_pushcfunction(L, OptionsHolder_get_edgeScrolling);
    lua_setfield(L, -2, "edgeScrolling");
    lua_pushcfunction(L, OptionsHolder_get_damageFloaters);
    lua_setfield(L, -2, "damageFloaters");
    lua_pushcfunction(L, OptionsHolder_get_showRotationMarker);
    lua_setfield(L, -2, "showRotationMarker");
    lua_pushcfunction(L, OptionsHolder_get_showMoveMarker);
    lua_setfield(L, -2, "showMoveMarker");
    lua_pushcfunction(L, OptionsHolder_get_fontSize);
    lua_setfield(L, -2, "fontSize");
    lua_pushcfunction(L, OptionsHolder_get_manyActiveZones);
    lua_setfield(L, -2, "manyActiveZones");
    lua_pushcfunction(L, OptionsHolder_get_distantTownRange);
    lua_setfield(L, -2, "distantTownRange");
    lua_pushcfunction(L, OptionsHolder_get_featureRange);
    lua_setfield(L, -2, "featureRange");
    lua_pushcfunction(L, OptionsHolder_get_generateDistantTowns);
    lua_setfield(L, -2, "generateDistantTowns");
    lua_pushcfunction(L, OptionsHolder_get_shadowRange);
    lua_setfield(L, -2, "shadowRange");
    lua_pushcfunction(L, OptionsHolder_get_ddsTextureMipMapGimping);
    lua_setfield(L, -2, "ddsTextureMipMapGimping");
    lua_pushcfunction(L, OptionsHolder_get_reflectionMode);
    lua_setfield(L, -2, "reflectionMode");
    lua_pushcfunction(L, OptionsHolder_get_reflectionDistance);
    lua_setfield(L, -2, "reflectionDistance");
    lua_pushcfunction(L, OptionsHolder_get_compositors);
    lua_setfield(L, -2, "compositors");
    lua_pushcfunction(L, OptionsHolder_get_musicVolume);
    lua_setfield(L, -2, "musicVolume");
    lua_pushcfunction(L, OptionsHolder_get_ambientVolume);
    lua_setfield(L, -2, "ambientVolume");
    lua_pushcfunction(L, OptionsHolder_get_footstepVolume);
    lua_setfield(L, -2, "footstepVolume");
    lua_pushcfunction(L, OptionsHolder_get_sfxVolume);
    lua_setfield(L, -2, "sfxVolume");
    lua_pushcfunction(L, OptionsHolder_get_uiVolume);
    lua_setfield(L, -2, "uiVolume");
    lua_pushcfunction(L, OptionsHolder_get_voVolume);
    lua_setfield(L, -2, "voVolume");
    lua_pushcfunction(L, OptionsHolder_get_musicFrequency);
    lua_setfield(L, -2, "musicFrequency");
    lua_pushcfunction(L, OptionsHolder_get_autosavetime);
    lua_setfield(L, -2, "autosavetime");
    lua_pushcfunction(L, OptionsHolder_get_fullscreen);
    lua_setfield(L, -2, "fullscreen");
    lua_pushcfunction(L, OptionsHolder_get_borderless);
    lua_setfield(L, -2, "borderless");
    lua_pushcfunction(L, OptionsHolder_get_autosave);
    lua_setfield(L, -2, "autosave");
    lua_pushcfunction(L, OptionsHolder_get_userSaves);
    lua_setfield(L, -2, "userSaves");
    lua_pushcfunction(L, OptionsHolder_get_blood);
    lua_setfield(L, -2, "blood");
    lua_pushcfunction(L, OptionsHolder_get_censorship);
    lua_setfield(L, -2, "censorship");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, OptionsHolder_set_CAMERA_MOVE_SPEED);
    lua_setfield(L, -2, "CAMERA_MOVE_SPEED");
    lua_pushcfunction(L, OptionsHolder_set_CAMERA_PAN_SPEED);
    lua_setfield(L, -2, "CAMERA_PAN_SPEED");
    lua_pushcfunction(L, OptionsHolder_set_CAMERA_TILT_SPEED);
    lua_setfield(L, -2, "CAMERA_TILT_SPEED");
    lua_pushcfunction(L, OptionsHolder_set_CAMERA_ZOOM_SPEED);
    lua_setfield(L, -2, "CAMERA_ZOOM_SPEED");
    lua_pushcfunction(L, OptionsHolder_set_invertX);
    lua_setfield(L, -2, "invertX");
    lua_pushcfunction(L, OptionsHolder_set_invertY);
    lua_setfield(L, -2, "invertY");
    lua_pushcfunction(L, OptionsHolder_set_VIEW_DISTANCE);
    lua_setfield(L, -2, "VIEW_DISTANCE");
    lua_pushcfunction(L, OptionsHolder_set_terrainDetail);
    lua_setfield(L, -2, "terrainDetail");
    lua_pushcfunction(L, OptionsHolder_set_terrainDistant);
    lua_setfield(L, -2, "terrainDistant");
    lua_pushcfunction(L, OptionsHolder_set_terrainThreshold);
    lua_setfield(L, -2, "terrainThreshold");
    lua_pushcfunction(L, OptionsHolder_set_terrainPatchSize);
    lua_setfield(L, -2, "terrainPatchSize");
    lua_pushcfunction(L, OptionsHolder_set_grassRange);
    lua_setfield(L, -2, "grassRange");
    lua_pushcfunction(L, OptionsHolder_set_grassDensity);
    lua_setfield(L, -2, "grassDensity");
    lua_pushcfunction(L, OptionsHolder_set_foliageRange);
    lua_setfield(L, -2, "foliageRange");
    lua_pushcfunction(L, OptionsHolder_set_NPCRange);
    lua_setfield(L, -2, "NPCRange");
    lua_pushcfunction(L, OptionsHolder_set_smallBuildingRange);
    lua_setfield(L, -2, "smallBuildingRange");
    lua_pushcfunction(L, OptionsHolder_set_stencilsDisabled);
    lua_setfield(L, -2, "stencilsDisabled");
    lua_pushcfunction(L, OptionsHolder_set_fancyShaders);
    lua_setfield(L, -2, "fancyShaders");
    lua_pushcfunction(L, OptionsHolder_set_HWmouse);
    lua_setfield(L, -2, "HWmouse");
    lua_pushcfunction(L, OptionsHolder_set_tutorials);
    lua_setfield(L, -2, "tutorials");
    lua_pushcfunction(L, OptionsHolder_set__enabledCivilians);
    lua_setfield(L, -2, "_enabledCivilians");
    lua_pushcfunction(L, OptionsHolder_set_populationMult);
    lua_setfield(L, -2, "populationMult");
    lua_pushcfunction(L, OptionsHolder_set_squadSizeMult);
    lua_setfield(L, -2, "squadSizeMult");
    lua_pushcfunction(L, OptionsHolder_set_raidSizeMult);
    lua_setfield(L, -2, "raidSizeMult");
    lua_pushcfunction(L, OptionsHolder_set_raidFrequencyMult);
    lua_setfield(L, -2, "raidFrequencyMult");
    lua_pushcfunction(L, OptionsHolder_set_passingAttacksOnBase);
    lua_setfield(L, -2, "passingAttacksOnBase");
    lua_pushcfunction(L, OptionsHolder_set_shadowMode);
    lua_setfield(L, -2, "shadowMode");
    lua_pushcfunction(L, OptionsHolder_set_shadowQuality);
    lua_setfield(L, -2, "shadowQuality");
    lua_pushcfunction(L, OptionsHolder_set_harpoonLimit);
    lua_setfield(L, -2, "harpoonLimit");
    lua_pushcfunction(L, OptionsHolder_set_decalRange);
    lua_setfield(L, -2, "decalRange");
    lua_pushcfunction(L, OptionsHolder_set_decalResolution);
    lua_setfield(L, -2, "decalResolution");
    lua_pushcfunction(L, OptionsHolder_set_characterMultithreading);
    lua_setfield(L, -2, "characterMultithreading");
    lua_pushcfunction(L, OptionsHolder_set_limbLossFrequency);
    lua_setfield(L, -2, "limbLossFrequency");
    lua_pushcfunction(L, OptionsHolder_set_showNames);
    lua_setfield(L, -2, "showNames");
    lua_pushcfunction(L, OptionsHolder_set_edgeScrolling);
    lua_setfield(L, -2, "edgeScrolling");
    lua_pushcfunction(L, OptionsHolder_set_damageFloaters);
    lua_setfield(L, -2, "damageFloaters");
    lua_pushcfunction(L, OptionsHolder_set_showRotationMarker);
    lua_setfield(L, -2, "showRotationMarker");
    lua_pushcfunction(L, OptionsHolder_set_showMoveMarker);
    lua_setfield(L, -2, "showMoveMarker");
    lua_pushcfunction(L, OptionsHolder_set_fontSize);
    lua_setfield(L, -2, "fontSize");
    lua_pushcfunction(L, OptionsHolder_set_manyActiveZones);
    lua_setfield(L, -2, "manyActiveZones");
    lua_pushcfunction(L, OptionsHolder_set_distantTownRange);
    lua_setfield(L, -2, "distantTownRange");
    lua_pushcfunction(L, OptionsHolder_set_featureRange);
    lua_setfield(L, -2, "featureRange");
    lua_pushcfunction(L, OptionsHolder_set_generateDistantTowns);
    lua_setfield(L, -2, "generateDistantTowns");
    lua_pushcfunction(L, OptionsHolder_set_shadowRange);
    lua_setfield(L, -2, "shadowRange");
    lua_pushcfunction(L, OptionsHolder_set_ddsTextureMipMapGimping);
    lua_setfield(L, -2, "ddsTextureMipMapGimping");
    lua_pushcfunction(L, OptionsHolder_set_reflectionMode);
    lua_setfield(L, -2, "reflectionMode");
    lua_pushcfunction(L, OptionsHolder_set_reflectionDistance);
    lua_setfield(L, -2, "reflectionDistance");
    lua_pushcfunction(L, OptionsHolder_set_compositors);
    lua_setfield(L, -2, "compositors");
    lua_pushcfunction(L, OptionsHolder_set_musicVolume);
    lua_setfield(L, -2, "musicVolume");
    lua_pushcfunction(L, OptionsHolder_set_ambientVolume);
    lua_setfield(L, -2, "ambientVolume");
    lua_pushcfunction(L, OptionsHolder_set_footstepVolume);
    lua_setfield(L, -2, "footstepVolume");
    lua_pushcfunction(L, OptionsHolder_set_sfxVolume);
    lua_setfield(L, -2, "sfxVolume");
    lua_pushcfunction(L, OptionsHolder_set_uiVolume);
    lua_setfield(L, -2, "uiVolume");
    lua_pushcfunction(L, OptionsHolder_set_voVolume);
    lua_setfield(L, -2, "voVolume");
    lua_pushcfunction(L, OptionsHolder_set_musicFrequency);
    lua_setfield(L, -2, "musicFrequency");
    lua_pushcfunction(L, OptionsHolder_set_autosavetime);
    lua_setfield(L, -2, "autosavetime");
    lua_pushcfunction(L, OptionsHolder_set_fullscreen);
    lua_setfield(L, -2, "fullscreen");
    lua_pushcfunction(L, OptionsHolder_set_borderless);
    lua_setfield(L, -2, "borderless");
    lua_pushcfunction(L, OptionsHolder_set_autosave);
    lua_setfield(L, -2, "autosave");
    lua_pushcfunction(L, OptionsHolder_set_userSaves);
    lua_setfield(L, -2, "userSaves");
    lua_pushcfunction(L, OptionsHolder_set_blood);
    lua_setfield(L, -2, "blood");
    lua_pushcfunction(L, OptionsHolder_set_censorship);
    lua_setfield(L, -2, "censorship");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua