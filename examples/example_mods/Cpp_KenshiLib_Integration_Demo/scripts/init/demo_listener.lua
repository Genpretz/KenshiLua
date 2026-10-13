-- These globals are registered by MyKenshiLibPlugin.cpp before this script runs.
---@type fun(character: Character): number
---@diagnostic disable-next-line: undefined-field
local calculateBonus = _G.CppDemo_CalculateBonus
---@type fun(character: Character)
---@diagnostic disable-next-line: undefined-field
local printCharacter = _G.CppDemo_PrintCharacter

Events.on("CppDemo_OnCharacterSelected", function(character, baseBonus)
    local nativeBonus = calculateBonus(character)
    printCharacter(character)
    print(string.format(
        "[CppDemo Lua] %s selected; base bonus %.1f, native bonus %.1f",
        character:getName(), baseBonus, nativeBonus))
end)
