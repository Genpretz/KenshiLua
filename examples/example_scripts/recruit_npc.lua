-- recruit_npc.lua
-- Select any NPC (click on them) and press 'K' to move them into the player faction & active squad.

local KC_K = 37 -- OIS Keycode for 'K'

local function recruitSelectedNPC()
    -- 1. Fetch live ForgottenGUI and PlayerInterface instances
    local guiObj = getForgottenGUI() or gui
    local playerObj = getPlayerInterface() or player

    if not guiObj or not playerObj then
        KenshiLua.logWarn("[RecruitNPC] ForgottenGUI or PlayerInterface is not available.")
        return
    end

    -- 2. Retrieve the selected object handle from ForgottenGUI (selectedObject)
    local targetHand = guiObj.selectedObject
    if not targetHand or targetHand:isNull() then
        KenshiLua.log("[RecruitNPC] No target currently selected.")
        return
    end

    -- 3. Extract the Character object pointer from the hand handle
    local targetChar = targetHand:getCharacter()
    if not targetChar then
        KenshiLua.log("[RecruitNPC] Selected target is not a character.")
        return
    end

    -- 4. Get player's faction and active squad (ActivePlatoon)
    local playerFaction = playerObj.participant
    local activeSquad = nil
    if playerObj.currentPlatoon then
        activeSquad = playerObj.currentPlatoon.activePlatoon
    end

    if not playerFaction or not activeSquad then
        KenshiLua.logError("[RecruitNPC] Player faction or active squad not found.")
        return
    end

    -- 5. Check if character is already in the player faction
    if targetChar:getFaction() == playerFaction then
        KenshiLua.log("[RecruitNPC] " .. tostring(targetChar:getName()) .. " is already in your faction.")
        return
    end

    -- 6. Transfer the character into the player's faction and active squad
    targetChar:setFaction(playerFaction, activeSquad)
    KenshiLua.log("[RecruitNPC] Recruited " .. tostring(targetChar:getName()) .. " into the player faction!")
end

-- Key listener callback
local function onKeyDown(inputHandler, keyCode)
    if keyCode == KC_K then
        recruitSelectedNPC()
    end
end

-- Register the key listener
registerHandler("onKeyDown", onKeyDown)
KenshiLua.log("[RecruitNPC] Loaded! Select any NPC and press 'K' to recruit them.")
