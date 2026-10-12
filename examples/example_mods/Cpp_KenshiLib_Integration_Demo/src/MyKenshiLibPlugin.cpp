#include <windows.h>

#include <sstream>
#include <string>

#include <kenshi/Character.h>
#include <kenshi/CharStats.h>
#include <core/Functions.h>
#include <Debug.h>

#include <KenshiLua.h>

namespace
{
    bool g_registered = false;

    int CalculateBonus(lua_State* state)
    {
        Character* character = KenshiLua::Check<Character>(state, 1);
        float bonus = 15.5f;
        if (character && character->stats)
            bonus += character->stats->combatSpeedMultiplier * 5.0f;
        KenshiLua::Push(state, bonus);
        return 1;
    }

    int PrintCharacter(lua_State* state)
    {
        Character* character = KenshiLua::Test<Character>(state, 1);
        if (!character)
        {
            KenshiLua::LogWarning("[CppDemo] PrintCharacter received an invalid Character");
            return 0;
        }

        std::ostringstream message;
        message << "[CppDemo] Character selected: " << character->getName()
                << " (player=" << (character->isPlayerCharacter() ? "true" : "false") << ")";
        KenshiLua::LogInfo(message.str());
        return 0;
    }

    int DescribeCharacter(lua_State* state)
    {
        Character* character = KenshiLua::Test<Character>(state, 1);
        std::string description = character ? character->getName() : "invalid character";
        KenshiLua::Push(state, description);
        return 1;
    }

    const KenshiLua::Reg NativeModuleFunctions[] = {
        { "describeCharacter", DescribeCharacter },
        { NULL, NULL }
    };

    int OpenNativeModule(lua_State* state)
    {
        KenshiLua::NewTable(state);
        KenshiLua::RegisterFunctions(state, NativeModuleFunctions);
        return 1;
    }

    bool ensureRegistered()
    {
        if (g_registered) return true;
        if (!KenshiLua::IsAvailable()) return false;

        std::string error;
        if (KenshiLua::RegisterFunction("CppDemo_CalculateBonus", CalculateBonus, &error) !=
                KenshiLua::STATUS_OK ||
            KenshiLua::RegisterFunction("CppDemo_PrintCharacter", PrintCharacter, &error) !=
                KenshiLua::STATUS_OK ||
            KenshiLua::RegisterModule("CppDemoNative", OpenNativeModule, &error) !=
                KenshiLua::STATUS_OK)
        {
            KenshiLua::LogError("[CppDemo] Native registration failed: " + error);
            return false;
        }

        KenshiLua::Status scriptStatus = KenshiLua::RunScript(
            "Cpp_KenshiLib_Integration_Demo/scripts/modules/combat_ai.lua", &error);
        if (scriptStatus != KenshiLua::STATUS_OK)
            KenshiLua::LogWarning("[CppDemo] Private script failed: " + error);

        g_registered = true;
        KenshiLua::LogInfo("[CppDemo] Native functions and module registered");
        return true;
    }

    void (*CharacterSelectOriginal)(Character*) = NULL;

    void CharacterSelectHook(Character* character)
    {
        if (CharacterSelectOriginal)
            CharacterSelectOriginal(character);
        if (!character || !ensureRegistered())
            return;

        lua_State* state = KenshiLua::GetState();
        if (!state || KenshiLua::Push(state, character) != KenshiLua::STATUS_OK)
            return;
        KenshiLua::Push(state, 25.0f);

        std::string error;
        KenshiLua::Status status = KenshiLua::DispatchEvent(
            "CppDemo_OnCharacterSelected", 2, &error);
        if (status != KenshiLua::STATUS_OK)
            KenshiLua::LogError("[CppDemo] Event dispatch failed: " + error);

        status = KenshiLua::DoString(
            "print('[CppDemo inline] native event dispatch completed')",
            "CppDemo_InlineExample", &error);
        if (status != KenshiLua::STATUS_OK)
            KenshiLua::LogError("[CppDemo] Inline Lua failed: " + error);
    }
}

__declspec(dllexport) void startPlugin()
{
    if (KenshiLib::SUCCESS != KenshiLib::AddHook(
            KenshiLib::GetRealAddress(&Character::_NV_select),
            &CharacterSelectHook,
            &CharacterSelectOriginal))
    {
        ErrorLog("[CppDemo] Failed to hook Character::_NV_select");
        return;
    }

    ensureRegistered();
}
