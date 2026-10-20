-- ah_open_goat_sale.lua
-- FCS dialogue script: opens the animal sale window for goats only.
-- Attach this file in FCS as a LUA_SCRIPT through the dialogue line's
-- "run lua script" reference, in place of ah_open_animal_sale.lua.

local AH = _G.AnimalHusbandryLua
if not AH or not AH.sales or not AH.sales.open then
    print("[AnimalHusbandryLua] sale window is not loaded")
    return
end

-- The Goat ANIMAL_CHARACTER record used by this mod. Character names are editable,
-- so match the FCS record ID rather than the animal's displayed name.
local GOAT_TEMPLATE_ID = "3993-gamedata.base"
local function isGoat(entry)
    return entry.templateID == GOAT_TEMPLATE_ID
end

local ok, err = pcall(AH.sales.open, currentDialogue, isGoat)
if not ok then
    print("[AnimalHusbandryLua] could not open the goat sale window: " .. tostring(err))
end
