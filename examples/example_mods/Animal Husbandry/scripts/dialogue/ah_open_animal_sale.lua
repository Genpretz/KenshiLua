-- Animal Husbandry: opens the animal sale window.
--
-- Attach this file in FCS as a LUA_SCRIPT through the "run lua script" reference on
-- the dialogue line that offers to buy the player's animals. The NPC in the
-- conversation is the buyer. The window lives in scripts/init/04_ah_sales.lua.

local AH = _G.AnimalHusbandry
if not AH or not AH.sales or not AH.sales.open then
    print("[AnimalHusbandry] sale window is not loaded")
    return
end

local ok, err = pcall(AH.sales.open, currentDialogue)
if not ok then
    AH.log("could not open the sale window: " .. tostring(err))
end
