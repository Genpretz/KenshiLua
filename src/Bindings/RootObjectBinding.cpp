#include "pch.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/BuildingBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/TownBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/RootObject.h>
#include <kenshi/Character.h>
#include <kenshi/Building/Building.h>
#include <kenshi/Item.h>
#include <kenshi/Town.h>

#include <ogre/OgreVector3.h>
#include <ogre/OgreQuaternion.h>

#include <cstdio>
#include <cstring>

namespace KenshiLua
{

static RootObject* getRO(lua_State* L, int idx)
{
    // Try other related metatables first since they also derive from RootObject,
    // so we can accept Character/Item/Building objects directly in RootObject methods!
    RootObject* r = testObject<RootObject>(L, idx, RootObjectBinding::getMetatableName());
    if (r) return r;
    r = (RootObject*)testObject<Character>(L, idx, CharacterBinding::getMetatableName());
    if (r) return r;
    r = (RootObject*)testObject<Building>(L, idx, BuildingBinding::getMetatableName());
    if (r) return r;
    r = (RootObject*)InventoryItemBaseBinding::getItem(L, idx);
    return r;
}

int RootObjectBinding::pushRootObject(lua_State* L, RootObject* obj)
{
    if (obj == 0)
    {
        lua_pushnil(L);
        return 1;
    }
    // Polymorphic routing based on class type
    itemType t = obj->getDataType();
    if (t == CHARACTER)
    {
        return pushObject<Character>(L, (Character*)obj, CharacterBinding::getMetatableName());
    }
    else if (t == BUILDING)
    {
        return pushObject<Building>(L, (Building*)obj, BuildingBinding::getMetatableName());
    }
    else if (t == ITEM || t == WEAPON || t == ARMOUR || t == CONTAINER || t == CROSSBOW)
    {
        return ItemBinding::pushItem(L, (Item*)obj);
    }
    return pushObject<RootObject>(L, obj, RootObjectBinding::getMetatableName());
}

int RootObjectBinding::gc(lua_State* L) { return noopGc(L); }

int RootObjectBinding::tostring(lua_State* L)
{
    RootObject* r = getRO(L, 1);
    if (r == 0) { lua_pushstring(L, "RootObject:nil"); return 1; }
    char buf[160];
    _snprintf(buf, sizeof(buf), "RootObject:%s(%p)", r->getName().c_str(), (void*)r);
    lua_pushstring(L, buf);
    return 1;
}

int RootObjectBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, RootObjectBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    RootObject* r = getRO(L, 1);
    if (r == 0) { lua_pushnil(L); return 1; }

    // --- boolean members ---
    if (strcmp(key, "visible") == 0) { lua_pushboolean(L, r->getVisible() ? 1 : 0); return 1; }

    // --- integer members ---
    if (strcmp(key, "classType") == 0) { lua_pushinteger(L, (int)r->getDataType()); return 1; }
    if (strcmp(key, "money") == 0) { lua_pushinteger(L, r->getMoney()); return 1; }

    // --- string members ---
    if (strcmp(key, "name") == 0) { lua_pushstring(L, r->getName().c_str()); return 1; }
    if (strcmp(key, "modelName") == 0) {
        Item* item = dynamic_cast<Item*>(r);
        if (item != 0) lua_pushstring(L, item->getModelName().c_str());
        else lua_pushnil(L);
        return 1;
    }

    // --- unique object members ---
    if (strcmp(key, "position") == 0) { pushVector3(L, r->getPosition()); return 1; }
    if (strcmp(key, "rotation") == 0)
    {
        Ogre::Quaternion q = r->getOrientation();
        lua_createtable(L, 0, 4);
        lua_pushnumber(L, q.w); lua_setfield(L, -2, "w");
        lua_pushnumber(L, q.x); lua_setfield(L, -2, "x");
        lua_pushnumber(L, q.y); lua_setfield(L, -2, "y");
        lua_pushnumber(L, q.z); lua_setfield(L, -2, "z");
        return 1;
    }
    if (strcmp(key, "town") == 0)
    {
        return pushObject<TownBase>(L, r->getCurrentTownLocation(), TownBinding::getMetatableName());
    }
    if (strcmp(key, "inventory") == 0)
    {
        Inventory* inv = r->getInventory();
        if (inv != 0) lua_pushlightuserdata(L, (void*)inv);
        else     lua_pushnil(L);
        return 1;
    }

    lua_pushnil(L);
    return 1;
}

int RootObjectBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    RootObject* r = getRO(L, 1);
    if (r == 0) return luaL_error(L, "RootObject is nil");

    if (strcmp(key, "visible") == 0)
    {
        r->setVisible(lua_toboolean(L, 3) != 0);
        return 0;
    }

    return luaL_error(L, "RootObject: field '%s' is read-only or does not exist", key);
}

int RootObjectBinding::getName(lua_State* L)
{
    RootObject* r = getRO(L, 1);
    if (r != 0) lua_pushstring(L, r->getName().c_str()); else lua_pushnil(L);
    return 1;
}

int RootObjectBinding::getPosition(lua_State* L)
{
    RootObject* r = getRO(L, 1);
    if (r == 0) { lua_pushnil(L); return 1; }
    pushVector3(L, r->getPosition());
    return 1;
}

int RootObjectBinding::getRotation(lua_State* L)
{
    RootObject* r = getRO(L, 1);
    if (r == 0) { lua_pushnil(L); return 1; }
    Ogre::Quaternion q = r->getOrientation();
    lua_createtable(L, 0, 4);
    lua_pushnumber(L, q.w); lua_setfield(L, -2, "w");
    lua_pushnumber(L, q.x); lua_setfield(L, -2, "x");
    lua_pushnumber(L, q.y); lua_setfield(L, -2, "y");
    lua_pushnumber(L, q.z); lua_setfield(L, -2, "z");
    return 1;
}

int RootObjectBinding::getVisible(lua_State* L)
{
    RootObject* r = getRO(L, 1);
    lua_pushboolean(L, r && r->getVisible() ? 1 : 0);
    return 1;
}

int RootObjectBinding::getModelName(lua_State* L)
{
    RootObject* r = getRO(L, 1);
    if (r != 0)
    {
        Item* item = dynamic_cast<Item*>(r);
        if (item != 0) lua_pushstring(L, item->getModelName().c_str());
        else lua_pushnil(L);
    }
    else
    {
        lua_pushnil(L);
    }
    return 1;
}

int RootObjectBinding::getMoney(lua_State* L)
{
    RootObject* r = getRO(L, 1);
    if (r != 0) lua_pushinteger(L, r->getMoney()); else lua_pushinteger(L, 0);
    return 1;
}

int RootObjectBinding::getTown(lua_State* L)
{
    RootObject* r = getRO(L, 1);
    if (r == 0) { lua_pushnil(L); return 1; }
    return pushObject<TownBase>(L, r->getCurrentTownLocation(), TownBinding::getMetatableName());
}

int RootObjectBinding::getInventory(lua_State* L)
{
    RootObject* r = getRO(L, 1);
    if (r == 0) { lua_pushnil(L); return 1; }
    Inventory* inv = r->getInventory();
    if (inv != 0) lua_pushlightuserdata(L, (void*)inv);
    else     lua_pushnil(L);
    return 1;
}

int RootObjectBinding::setVisible(lua_State* L)
{
    RootObject* r = getRO(L, 1);
    if (r == 0) return luaL_error(L, "RootObject is nil");
    r->setVisible(lua_toboolean(L, 2) != 0);
    return 0;
}

int RootObjectBinding::takeMoney(lua_State* L)
{
    RootObject* r = getRO(L, 1);
    if (r == 0) return luaL_error(L, "RootObject is nil");
    int amount = (int)luaL_checkinteger(L, 2);
    lua_pushboolean(L, r->takeMoney(amount) ? 1 : 0);
    return 1;
}

int RootObjectBinding::say(lua_State* L)
{
    RootObject* r = getRO(L, 1);
    if (r == 0) return luaL_error(L, "RootObject is nil");
    const char* text = luaL_checkstring(L, 2);
    r->say(text);
    return 0;
}

void RootObjectBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RootObjectBinding::gc },
        { "__tostring", RootObjectBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getName",         RootObjectBinding::getName },
        { "getPosition",     RootObjectBinding::getPosition },
        { "getRotation",     RootObjectBinding::getRotation },
        { "getVisible",      RootObjectBinding::getVisible },
        { "getModelName",    RootObjectBinding::getModelName },
        { "getMoney",        RootObjectBinding::getMoney },
        { "getTown",         RootObjectBinding::getTown },
        { "getInventory",    RootObjectBinding::getInventory },
        { "setVisible",      RootObjectBinding::setVisible },
        { "takeMoney",       RootObjectBinding::takeMoney },
        { "say",             RootObjectBinding::say },
        { 0, 0 }
    };
    registerClass(L, RootObjectBinding::getMetatableName(), meta, methods, RootObjectBinding::index, RootObjectBinding::newindex);
}

} // namespace KenshiLua
