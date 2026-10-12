Events.on("CppDemo_OnCharacterSelected", function(character, baseBonus)
    local nativeBonus = CppDemo_CalculateBonus(character)
    CppDemo_PrintCharacter(character)
    print(string.format(
        "[CppDemo Lua] %s selected; base bonus %.1f, native bonus %.1f",
        character:getName(), baseBonus, nativeBonus))
end)
