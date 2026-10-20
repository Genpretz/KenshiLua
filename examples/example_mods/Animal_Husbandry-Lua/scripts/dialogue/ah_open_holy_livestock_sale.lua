-- ah_open_holy_livestock_sale.lua
-- FCS dialogue script: opens the animal sale window for selected Holy Nation livestock.
-- Attach this file in FCS as a LUA_SCRIPT through the dialogue line's
-- "run lua script" reference, in place of ah_open_animal_sale.lua.

local AH = _G.AnimalHusbandryLua
if not AH or not AH.sales or not AH.sales.open then
    print("[AnimalHusbandryLua] sale window is not loaded")
    return
end

-- Match ANIMAL_CHARACTER record IDs so renamed animals remain eligible.
local ACCEPTED_TEMPLATES = {
    ["3986-gamedata.base"] = true, -- Wild Bull
    ["3993-gamedata.base"] = true, -- Goat
    ["3999-gamedata.base"] = true, -- Pack Beast
    ["3979-gamedata.base"] = true, -- Bonedog
    ["43949-rebirth.mod"] = true, -- Domesticated Bull
    ["42201-rebirth.mod"] = true, -- Garru
    ["47929-rebirth.mod"] = true, -- Pack Bull
}

local function isAccepted(entry)
    return ACCEPTED_TEMPLATES[entry.templateID] == true
end

local ok, err = pcall(AH.sales.open, currentDialogue, isAccepted)
if not ok then
    print("[AnimalHusbandryLua] could not open the livestock sale window: " .. tostring(err))
end
