#pragma once

extern "C" {
#include <lua.h>
}

namespace KenshiLua
{
	class GearBinding
	{
	public:
		static const char* getMetatableName() { return "KenshiLua.Gear"; }
		static void registerBinding(lua_State* L);

		static int gc(lua_State* L);
		static int tostring(lua_State* L);
		static int index(lua_State* L);
		static int newindex(lua_State* L);

		static int GearBinding::isAFactionUniform(lua_State* L);
		static int GearBinding::isPlayerCrafted(lua_State* L);
	};

	class WeaponBinding
	{
	public:
		static const char* getMetatableName() { return "KenshiLua.Weapon"; }
		static void registerBinding(lua_State* L);

		static int gc(lua_State* L);
		static int tostring(lua_State* L);
		static int index(lua_State* L);
		static int newindex(lua_State* L);

		static int WeaponBinding::is2HandedOnly(lua_State* L);
	};

	class SwordBinding
	{
	public:
		static const char* getMetatableName() { return "KenshiLua.Sword"; }
		static void registerBinding(lua_State* L);

		static int gc(lua_State* L);
		static int tostring(lua_State* L);
		static int index(lua_State* L);
		static int newindex(lua_State* L);

		static int SwordBinding::getClassType(lua_State* L);
	};

	class CrossbowBinding
	{
	public:
		static const char* getMetatableName() { return "KenshiLua.Crossbow"; }
		static void registerBinding(lua_State* L);

		static int gc(lua_State* L);
		static int tostring(lua_State* L);
		static int index(lua_State* L);
		static int newindex(lua_State* L);

		static int CrossbowBinding::getClassType(lua_State* L);
	};

	class ArmourEnumBinding
	{
		public:
			void registerArmourClass(lua_State* L);
	};

	class ArmourBinding
	{
	public:
		static const char* getMetatableName() { return "KenshiLua.Armour"; }
		static void registerBinding(lua_State* L);

		static int gc(lua_State* L);
		static int tostring(lua_State* L);
		static int index(lua_State* L);
		static int newindex(lua_State* L);

		static int ArmourBinding::getClassType(lua_State* L);
		static int ArmourBinding::isArmour(lua_State* L);
		static int ArmourBinding::getItemWeight(lua_State* L);
		static int ArmourBinding::getValueSingle(lua_State* L);
		static int ArmourBinding::hasArmourCoverage(lua_State* L);
		static int ArmourBinding::getCraftTime(lua_State* L);
		static int ArmourBinding::getWeatherProtection_simple(lua_State* L);
	};

	class LockedArmourBinding
	{
	public:
		static const char* getMetatableName() { return "KenshiLua.LockedArmour"; }
		static void registerBinding(lua_State* L);

		static int gc(lua_State* L);
		static int tostring(lua_State* L);
		static int index(lua_State* L);
		static int newindex(lua_State* L);

		static int LockedArmourBinding::isLockedArmour(lua_State* L);
	};

}