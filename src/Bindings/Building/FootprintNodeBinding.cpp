#include "pch.h"
#include <kenshi/Building/Building.h>
#include "FootprintNodeBinding.h"
#include "FootprintBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/FootprintBinding.h"

namespace KenshiLua
{
typedef PreviewBuilding::FootprintNode FootprintNode;

static FootprintNode* getInstance(lua_State* L, int idx)
{
    return checkObject<FootprintNode>(L, idx, FootprintNodeBinding::getMetatableName());
}

// --- Getters for FootprintNode ---
static int FootprintNode_get_aabb(lua_State* L)
{
    FootprintNode* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FootprintNode is nil");
    // TODO: Unsupported type for aabb (Ogre::Aabb)
    lua_pushnil(L);
    return 1;
}

static int FootprintNode_get_nodeId(lua_State* L)
{
    FootprintNode* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FootprintNode is nil");
    lua_pushstring(L, instance->nodeId.c_str());
    return 1;
}

static int FootprintNode_get_enabled(lua_State* L)
{
    FootprintNode* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FootprintNode is nil");
    lua_pushboolean(L, instance->enabled ? 1 : 0);
    return 1;
}

// --- Setters for FootprintNode ---
static int FootprintNode_set_aabb(lua_State* L)
{
    FootprintNode* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FootprintNode is nil");
    return luaL_error(L, "Read-only or unsupported setter type for aabb");
}

static int FootprintNode_set_nodeId(lua_State* L)
{
    FootprintNode* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FootprintNode is nil");
    instance->nodeId = luaL_checkstring(L, 2);
    return 0;
}

static int FootprintNode_set_enabled(lua_State* L)
{
    FootprintNode* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FootprintNode is nil");
    instance->enabled = lua_toboolean(L, 2) != 0;
    return 0;
}

int FootprintNodeBinding::updateBox(lua_State* L)
{
    FootprintNode* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FootprintNode is nil");

    instance->updateBox();
    return 0;
}

int FootprintNodeBinding::_NV_updateBox(lua_State* L)
{
    FootprintNode* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FootprintNode is nil");

    instance->_NV_updateBox();
    return 0;
}

int FootprintNodeBinding::setEnabled(lua_State* L)
{
    FootprintNode* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FootprintNode is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->setEnabled(value);
    return 0;
}

int FootprintNodeBinding::_DESTRUCTOR(lua_State* L)
{
    FootprintNode* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FootprintNode is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 566: FootprintNode* _CONSTRUCTOR(...) - overloaded method
  line 568: FootprintNode* _CONSTRUCTOR(...) - overloaded method
  line 569: const Ogre::Aabb getWorldAABB(...) - unsupported return type
  line 570: const Ogre::Aabb _NV_getWorldAABB(...) - unsupported return type
  line 571: const Ogre::Aabb getLocalAABB(...) - unsupported return type
  line 572: const Ogre::Aabb _NV_getLocalAABB(...) - unsupported return type
  line 575: const std::string& getNodeId(...) - reference return type
  line 576: bool collisionTestOK(...) - unsupported arg type
  line 577: bool _NV_collisionTestOK(...) - unsupported arg type
  line 584: PreviewBuilding::FootprintNode& operator=(...) - operator
*/

int FootprintNodeBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int FootprintNodeBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FootprintNode object");
    return 1;
}

void FootprintNodeBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FootprintNodeBinding::gc },
        { "__tostring", FootprintNodeBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "updateBox", FootprintNodeBinding::updateBox },
        { "_NV_updateBox", FootprintNodeBinding::_NV_updateBox },
        { "setEnabled", FootprintNodeBinding::setEnabled },
        { "_DESTRUCTOR", FootprintNodeBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        FootprintNodeBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FootprintNodeBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, FootprintNode_get_aabb);
    lua_setfield(L, -2, "aabb");
    lua_pushcfunction(L, FootprintNode_get_nodeId);
    lua_setfield(L, -2, "nodeId");
    lua_pushcfunction(L, FootprintNode_get_enabled);
    lua_setfield(L, -2, "enabled");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, FootprintNode_set_aabb);
    lua_setfield(L, -2, "aabb");
    lua_pushcfunction(L, FootprintNode_set_nodeId);
    lua_setfield(L, -2, "nodeId");
    lua_pushcfunction(L, FootprintNode_set_enabled);
    lua_setfield(L, -2, "enabled");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to PreviewBuilding::Footprint
    setMetatableParent(L, FootprintNodeBinding::getMetatableName(), FootprintBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}
}