#include "pch.h"
#include <kenshi/Building/Building.h>
#include "FootprintBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{
typedef PreviewBuilding::Footprint Footprint;

static Footprint* getInstance(lua_State* L, int idx)
{
    return checkObject<Footprint>(L, idx, FootprintBinding::getMetatableName());
}

// --- Getters for Footprint ---
static int Footprint_get_wantsAboveGround(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    lua_pushboolean(L, instance->wantsAboveGround ? 1 : 0);
    return 1;
}

static int Footprint_get_lower(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    lua_pushnumber(L, instance->lower);
    return 1;
}

static int Footprint_get_space(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    lua_pushnumber(L, instance->space);
    return 1;
}

static int Footprint_get_scale(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    lua_pushnumber(L, instance->scale);
    return 1;
}

static int Footprint_get_ent(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    // TODO: Unsupported type for ent (Ogre::Entity*)
    lua_pushnil(L);
    return 1;
}

static int Footprint_get_box(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    // TODO: Unsupported type for box (NxBox)
    lua_pushnil(L);
    return 1;
}

static int Footprint_get_pos(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    pushVector3(L, instance->pos);
    return 1;
}

static int Footprint_get_rot(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    pushQuaternion(L, instance->rot);
    return 1;
}

static int Footprint_get_groundType(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    lua_pushinteger(L, (lua_Integer)instance->groundType);
    return 1;
}

static int Footprint_get_valid(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    lua_pushboolean(L, instance->valid ? 1 : 0);
    return 1;
}

static int Footprint_get_parent(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    // TODO: Unsupported type for parent (PreviewBuilding*)
    lua_pushnil(L);
    return 1;
}

static int Footprint_get_corners(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    // TODO: Unsupported type for corners (Ogre::vector<Ogre::Vector3>::type)
    lua_pushnil(L);
    return 1;
}

// --- Setters for Footprint ---
static int Footprint_set_wantsAboveGround(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    instance->wantsAboveGround = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Footprint_set_lower(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    instance->lower = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Footprint_set_space(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    instance->space = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Footprint_set_scale(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    instance->scale = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Footprint_set_ent(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    return luaL_error(L, "Read-only or unsupported setter type for ent");
}

static int Footprint_set_box(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    return luaL_error(L, "Read-only or unsupported setter type for box");
}

static int Footprint_set_pos(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    readVector3(L, 2, instance->pos);
    return 0;
}

static int Footprint_set_rot(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    readQuaternion(L, 2, instance->rot);
    return 0;
}

static int Footprint_set_groundType(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    instance->groundType = (BuildingPlacementGroundType::Enum)luaL_checkinteger(L, 2);
    return 0;
}

static int Footprint_set_valid(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    instance->valid = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Footprint_set_parent(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    return luaL_error(L, "Read-only or unsupported setter type for parent");
}

static int Footprint_set_corners(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");
    return luaL_error(L, "Read-only or unsupported setter type for corners");
}

int FootprintBinding::_DESTRUCTOR(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int FootprintBinding::getSpace(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");

    float result = instance->getSpace();
    lua_pushnumber(L, result);
    return 1;
}

int FootprintBinding::getMarker(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");

    float result = instance->getMarker();
    lua_pushnumber(L, result);
    return 1;
}

int FootprintBinding::setValid(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->setValid(value);
    return 0;
}

int FootprintBinding::getValid(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");

    bool result = instance->getValid();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FootprintBinding::validate(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");

    bool result = instance->validate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FootprintBinding::fakeOppositeValidate(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");

    float gap = (float)luaL_checknumber(L, 2);
    bool result = instance->fakeOppositeValidate(gap);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FootprintBinding::collisionTestCharacters(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");

    bool result = instance->collisionTestCharacters();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FootprintBinding::validFloorTest(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");

    bool result = instance->validFloorTest();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FootprintBinding::isGroundValid(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");

    bool result = instance->isGroundValid();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FootprintBinding::getWorldCorner(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");

    int corner = (int)luaL_checkinteger(L, 2);
    Ogre::Vector3 result = instance->getWorldCorner(corner);
    pushVector3(L, result);
    return 1;
}

int FootprintBinding::updateBox(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");

    instance->updateBox();
    return 0;
}

int FootprintBinding::_NV_updateBox(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");

    instance->_NV_updateBox();
    return 0;
}

int FootprintBinding::getGroundHeight(lua_State* L)
{
    Footprint* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Footprint is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    float result = instance->getGroundHeight(pos);
    lua_pushnumber(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 518: Footprint* _CONSTRUCTOR(...) - overloaded method
  line 520: Footprint* _CONSTRUCTOR(...) - overloaded method
  line 523: const Ogre::Aabb getWorldAABB(...) - unsupported return type
  line 524: const Ogre::Aabb _NV_getWorldAABB(...) - unsupported return type
  line 525: const Ogre::Aabb getLocalAABB(...) - unsupported return type
  line 526: const Ogre::Aabb _NV_getLocalAABB(...) - unsupported return type
  line 533: bool collisionTestOK(...) - unsupported arg type
  line 534: bool _NV_collisionTestOK(...) - unsupported arg type
  line 535: bool collisionTestBuildings(...) - unsupported arg type
  line 538: bool isIndoorsOK(...) - unsupported arg type
  line 539: bool blocksAnyBuildingTest(...) - unsupported arg type
  line 557: PreviewBuilding::Footprint& operator=(...) - operator
*/

int FootprintBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int FootprintBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Footprint object");
    return 1;
}

void FootprintBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FootprintBinding::gc },
        { "__tostring", FootprintBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", FootprintBinding::_DESTRUCTOR },
        { "getSpace", FootprintBinding::getSpace },
        { "getMarker", FootprintBinding::getMarker },
        { "setValid", FootprintBinding::setValid },
        { "getValid", FootprintBinding::getValid },
        { "validate", FootprintBinding::validate },
        { "fakeOppositeValidate", FootprintBinding::fakeOppositeValidate },
        { "collisionTestCharacters", FootprintBinding::collisionTestCharacters },
        { "validFloorTest", FootprintBinding::validFloorTest },
        { "isGroundValid", FootprintBinding::isGroundValid },
        { "getWorldCorner", FootprintBinding::getWorldCorner },
        { "updateBox", FootprintBinding::updateBox },
        { "_NV_updateBox", FootprintBinding::_NV_updateBox },
        { "getGroundHeight", FootprintBinding::getGroundHeight },
        { 0, 0 }
    };

    registerClass(
        L, 
        FootprintBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FootprintBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, Footprint_get_wantsAboveGround);
    lua_setfield(L, -2, "wantsAboveGround");
    lua_pushcfunction(L, Footprint_get_lower);
    lua_setfield(L, -2, "lower");
    lua_pushcfunction(L, Footprint_get_space);
    lua_setfield(L, -2, "space");
    lua_pushcfunction(L, Footprint_get_scale);
    lua_setfield(L, -2, "scale");
    lua_pushcfunction(L, Footprint_get_ent);
    lua_setfield(L, -2, "ent");
    lua_pushcfunction(L, Footprint_get_box);
    lua_setfield(L, -2, "box");
    lua_pushcfunction(L, Footprint_get_pos);
    lua_setfield(L, -2, "pos");
    lua_pushcfunction(L, Footprint_get_rot);
    lua_setfield(L, -2, "rot");
    lua_pushcfunction(L, Footprint_get_groundType);
    lua_setfield(L, -2, "groundType");
    lua_pushcfunction(L, Footprint_get_valid);
    lua_setfield(L, -2, "valid");
    lua_pushcfunction(L, Footprint_get_parent);
    lua_setfield(L, -2, "parent");
    lua_pushcfunction(L, Footprint_get_corners);
    lua_setfield(L, -2, "corners");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, Footprint_set_wantsAboveGround);
    lua_setfield(L, -2, "wantsAboveGround");
    lua_pushcfunction(L, Footprint_set_lower);
    lua_setfield(L, -2, "lower");
    lua_pushcfunction(L, Footprint_set_space);
    lua_setfield(L, -2, "space");
    lua_pushcfunction(L, Footprint_set_scale);
    lua_setfield(L, -2, "scale");
    lua_pushcfunction(L, Footprint_set_ent);
    lua_setfield(L, -2, "ent");
    lua_pushcfunction(L, Footprint_set_box);
    lua_setfield(L, -2, "box");
    lua_pushcfunction(L, Footprint_set_pos);
    lua_setfield(L, -2, "pos");
    lua_pushcfunction(L, Footprint_set_rot);
    lua_setfield(L, -2, "rot");
    lua_pushcfunction(L, Footprint_set_groundType);
    lua_setfield(L, -2, "groundType");
    lua_pushcfunction(L, Footprint_set_valid);
    lua_setfield(L, -2, "valid");
    lua_pushcfunction(L, Footprint_set_parent);
    lua_setfield(L, -2, "parent");
    lua_pushcfunction(L, Footprint_set_corners);
    lua_setfield(L, -2, "corners");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}
}