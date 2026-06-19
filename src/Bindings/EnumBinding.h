#pragma once

namespace KenshiLua
{
    template<typename T>
    inline void setEnum(lua_State* L, const char* name, T value)
    {
        lua_pushinteger(L, static_cast<lua_Integer>(value));
        lua_setfield(L, -2, name);
    }

	class CharacterEnumBinding
	{
    public:
		static void registerBinding(lua_State* L);
	private:
		static void registerProneState(lua_State* L);
		static void registerWaterState(lua_State* L);
		static void registerRagdollPart(lua_State* L);
		static void registerCharacterPerceptionTagsShortTerm(lua_State* L);
		static void registerCharacterPerceptionTagsLongTerm(lua_State* L);
		static void registerSoundRange(lua_State* L);
		static void registerSquadMemberType(lua_State* L);
		static void registerCharacterMessage(lua_State* L);
	};

	class DialogueEnumBinding
	{
    public:
		static void registerBinding(lua_State* L);
	private:
		static void registerTalker(lua_State* L);
		static void registerDialogueAction(lua_State* L);
	};

    class EnumsEnumBinding
    {
    public:
		static void registerBinding(lua_State* L);
    private:
        static void registersItemType(lua_State* L);
        static void registerBuildingFunction(lua_State* L);
        static void registerCutDirection(lua_State* L);
        static void registerCutOrigination(lua_State* L);
        static void registerHitMaterialType(lua_State* L);
        static void registerWeatherAffecting(lua_State* L);
        static void registerAttachSlot(lua_State* L);
        static void registerItemFunction(lua_State* L);
        static void registerArmourType(lua_State* L);
        static void registerCharacterTypeEnum(lua_State* L);
        static void registerSlaveStateEnum(lua_State* L);
        static void registerTaskType(lua_State* L);
        static void registerWeaponCategory(lua_State* L);
        static void registerLeftRight(lua_State* L);
        static void registerMessageType(lua_State* L);
        static void registerStandingOrder(lua_State* L);
        static void registerStatsEnumerated(lua_State* L);
        static void registerEventTriggerEnum(lua_State* L);
        static void registerDialogConditionEnum(lua_State* L);
        static void registerComparisonEnum(lua_State* L);
        static void registerGroundType(lua_State* L);
        static void registerEffectType(lua_State* L);
        static void registerSquadType(lua_State* L);
        static void registerMoveSpeed(lua_State* L);
        static void registerSwordStateEnum(lua_State* L);
        static void registerMiningResource(lua_State* L);
        static void registerCursorType(lua_State* L);
        static void registerMapZoomLevel(lua_State* L);
    };

	void registerEnums(lua_State* L);
}