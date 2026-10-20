-- ah_open_animal_sale.lua
-- FCS dialogue script: opens the animal sale window for all eligible player animals.
--
-- Attach this file in FCS as a LUA_SCRIPT through the "run lua script" reference on
-- the dialogue line that offers to buy the player's animals. The NPC in the
-- conversation is the buyer. The window lives in scripts/ah/sales.lua.

local AH = _G.AnimalHusbandryLua
if not AH or not AH.sales or not AH.sales.open then
    print("[AnimalHusbandryLua] sale window is not loaded")
    return
end

local ok, err = pcall(AH.sales.open, currentDialogue)
if not ok then
    print("[AnimalHusbandryLua] could not open the sale window: " .. tostring(err))
end
